// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_area.cpp
// Functions: 144
// ============================================================

#include "game\server\nav_area.h"

//------------------------------------------------------------------------------
// Address: 0x100EF1B0
// Name: public: void CTSListWithFreeList<class CBaseHandle>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSListWithFreeList<CBaseHandle>::RemoveAll(CTSListWithFreeList<CBaseHandle> *this)
{
  TSLNodeBase_t *v2; // edi
  CTSListBase *p_m_FreeList; // esi
  TSLNodeBase_t *Next; // [esp-Ch] [ebp-18h]
  TSLNodeBase_t *v5; // [esp-Ch] [ebp-18h]
  int DepthAndSequence; // [esp-8h] [ebp-14h]
  int v7; // [esp-8h] [ebp-14h]
  CTSListWithFreeList<CBaseHandle>::Node_t *pNext; // [esp+8h] [ebp-4h]

  v2 = CTSListBase::Detach(this);
  if ( v2 != nullptr )
  {
    p_m_FreeList = &this->m_FreeList;
    do
    {
      DepthAndSequence = p_m_FreeList->m_Head.value32.DepthAndSequence;
      pNext = (CTSListWithFreeList<CBaseHandle>::Node_t *)v2->Next;
      Next = p_m_FreeList->m_Head.value.Next;
      v2->Next = p_m_FreeList->m_Head.value.Next;
      if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                              a1: p_m_FreeList,
                              a2: v2,
                              a3: DepthAndSequence + 65537,
                              a4: Next,
                              a5: DepthAndSequence) == 0 )
      {
        do
        {
          _mm_pause();
          v7 = p_m_FreeList->m_Head.value32.DepthAndSequence;
          v5 = p_m_FreeList->m_Head.value.Next;
          v2->Next = p_m_FreeList->m_Head.value.Next;
        }
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: p_m_FreeList, a2: v2, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
      }
      v2 = pNext;
    }
    while ( pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF900
// Name: public: CTSListWithFreeList<struct CNavArea::AreaBindInfo>::~CTSListWithFreeList<struct CNavArea::AreaBindInfo>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSListWithFreeList<CNavArea::AreaBindInfo>::~CTSListWithFreeList<CNavArea::AreaBindInfo>(
        CTSListWithFreeList<CBaseHandle> *this)
{
  TSLNodeBase_t *v2; // eax
  TSLNodeBase_t *Next; // esi
  TSLNodeBase_t *v4; // eax
  TSLNodeBase_t *v5; // esi

  v2 = CTSListBase::Detach(this);
  if ( v2 != nullptr )
  {
    do
    {
      Next = v2->Next;
      free(pMem: v2);
      v2 = Next;
    }
    while ( Next != nullptr );
  }
  v4 = CTSListBase::Detach(this: &this->m_FreeList);
  if ( v4 != nullptr )
  {
    do
    {
      v5 = v4->Next;
      free(pMem: v4);
      v4 = v5;
    }
    while ( v5 != nullptr );
  }
  CTSListBase::Detach(this: &this->m_FreeList);
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F12B0
// Name: private: void CParallelProcessor<struct QueryCacheUpdateRecord_t,class CFuncJobItemProcessor<struct QueryCacheUpdateRecord_t>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::DoExecute(
        CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  QueryCacheUpdateRecord_t *m_pLimit; // ecx
  unsigned int v4; // edx
  QueryCacheUpdateRecord_t *v5; // esi
  QueryCacheUpdateRecord_t *v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  QueryCacheUpdateRecord_t *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 16 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (QueryCacheUpdateRecord_t *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (QueryCacheUpdateRecord_t *)((char *)v5 + v4);
      if ( m_pLimit < (QueryCacheUpdateRecord_t *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1750
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<class CNavArea __near *,class CFuncJobItemProcessor<class CNavArea __near *>,1> __near *,void (CParallelProcessor<class CNavArea __near *,class CFuncJobItemProcessor<class CNavArea __near *>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> *,void (__thiscall CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> *,void (__thiscall CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x101F1860
// Name: public: void CParallelProcessor<struct QueryCacheUpdateRecord_t,class CFuncJobItemProcessor<struct QueryCacheUpdateRecord_t>,1>::Run(struct QueryCacheUpdateRecord_t __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::Run(
        CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> *this,
        QueryCacheUpdateRecord_t *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  QueryCacheUpdateRecord_t *v9; // edx
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    this->m_pLimit = v9;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)operator new(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> *,void (__thiscall CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> *,void (__thiscall CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DEBC0
// Name: public: int CUtlVectorUltraConservative<class HidingSpot __near *,class CUtlVectorUltraConservativeAllocator>::AddToTail(class HidingSpot __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::AddToTail(
        CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator> *this,
        HidingSpot *const *src)
{
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx
  int m_Size; // edi
  int v5; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v6; // eax
  signed int v7; // ebx

  m_pData = this->m_pData;
  m_Size = m_pData->m_Size;
  v5 = m_pData->m_Size + 1;
  if ( v5 > m_pData->m_Size )
  {
    if ( m_pData == (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      v6 = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v5 + 4);
      this->m_pData = v6;
      v6->m_Size = 0;
    }
    else
    {
      v7 = 4 * v5 + 4;
      if ( v7 > (int)_msize(pMem: m_pData) )
        this->m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_pData, size: v7);
    }
  }
  this->m_pData->m_Elements[m_Size] = *src;
  ++this->m_pData->m_Size;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102DEC30
// Name: public: void CUtlVectorUltraConservative<struct NavConnect,class CUtlVectorUltraConservativeAllocator>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::EnsureCapacity(
        CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *this,
        int num)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v3; // eax
  signed int v4; // edi

  if ( num > this->m_pData->m_Size )
  {
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    if ( this->m_pData == (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      v3 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 8 * num + 4);
      this->m_pData = v3;
      v3->m_Size = 0;
    }
    else
    {
      v4 = 8 * num + 4;
      if ( v4 > (int)_msize(pMem: this->m_pData) )
        this->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_pData, size: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DECB0
// Name: public: int CUtlVectorUltraConservative<union NavLadderConnect,class CUtlVectorUltraConservativeAllocator>::AddToTail(union NavLadderConnect const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::AddToTail(
        CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *this,
        const NavLadderConnect *src)
{
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx
  int m_Size; // edi
  int v5; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v6; // eax
  signed int v7; // ebx

  m_pData = this->m_pData;
  m_Size = m_pData->m_Size;
  v5 = m_pData->m_Size + 1;
  if ( v5 > m_pData->m_Size )
  {
    if ( m_pData == (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      v6 = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v5 + 4);
      this->m_pData = v6;
      v6->m_Size = 0;
    }
    else
    {
      v7 = 4 * v5 + 4;
      if ( v7 > (int)_msize(pMem: m_pData) )
        this->m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_pData, size: v7);
    }
  }
  this->m_pData->m_Elements[m_Size] = (NavLadderConnect)src->id;
  ++this->m_pData->m_Size;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102F4050
// Name: enum NavDirType OppositeDirection(enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
NavDirType __cdecl OppositeDirection(NavDirType dir)
{
  NavDirType result; // eax

  switch ( dir )
  {
    case NORTH:
      result = SOUTH;
      break;
    case EAST:
      result = WEST;
      break;
    case WEST:
      result = EAST;
      break;
    default:
      result = NORTH;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4090
// Name: public: static void CNavVectorNoEditAllocator::Reset(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CNavVectorNoEditAllocator::Reset()
{
  CMemoryStack::FreeAll(this: &CNavVectorNoEditAllocator::m_memory, bDecommit: true);
  CNavVectorNoEditAllocator::m_pCurrent = nullptr;
  CNavVectorNoEditAllocator::m_nBytesCurrent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F40B0
// Name: public: void CNavArea::GetExtent(struct Extent __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::GetExtent(CNavArea *this, Extent *extent)
{
  float z; // xmm0_4
  float m_neZ; // xmm0_4
  float m_swZ; // xmm1_4

  extent->lo.x = this->m_nwCorner.x;
  extent->lo.y = this->m_nwCorner.y;
  extent->lo.z = this->m_nwCorner.z;
  extent->hi = this->m_seCorner;
  z = extent->lo.z;
  if ( this->m_nwCorner.z <= z )
    z = this->m_nwCorner.z;
  extent->lo.z = z;
  if ( this->m_seCorner.z <= z )
    z = this->m_seCorner.z;
  extent->lo.z = z;
  if ( this->m_neZ <= z )
    z = this->m_neZ;
  extent->lo.z = z;
  if ( this->m_swZ <= z )
    z = this->m_swZ;
  extent->lo.z = z;
  m_neZ = extent->hi.z;
  if ( m_neZ <= this->m_nwCorner.z )
    m_neZ = this->m_nwCorner.z;
  extent->hi.z = m_neZ;
  if ( m_neZ <= this->m_seCorner.z )
    m_neZ = this->m_seCorner.z;
  extent->hi.z = m_neZ;
  if ( m_neZ <= this->m_neZ )
    m_neZ = this->m_neZ;
  extent->hi.z = m_neZ;
  m_swZ = this->m_swZ;
  if ( m_neZ <= m_swZ )
    extent->hi.z = m_swZ;
  else
    extent->hi.z = m_neZ;
}

//------------------------------------------------------------------------------
// Address: 0x102F4180
// Name: private: void CNavArea::ResetNodes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ResetNodes(CNavArea *this)
{
  this->m_node[0] = nullptr;
  this->m_node[1] = nullptr;
  this->m_node[2] = nullptr;
  this->m_node[3] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102F41A0
// Name: public: bool CNavArea::HasNodes(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::HasNodes(CNavArea *this)
{
  int v1; // eax
  CNavNode **i; // ecx

  v1 = 0;
  for ( i = this->m_node; *i == nullptr; ++i )
  {
    if ( ++v1 >= 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F41C0
// Name: private: void CNavArea::AssignNodes(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::AssignNodes(CNavArea *this, CNavArea *area)
{
  CNavNode *v2; // edx
  CNavNode *i; // esi
  CNavNode *j; // eax

  v2 = this->m_node[1];
  for ( i = this->m_node[0]; i != this->m_node[3]; v2 = v2->m_to[2] )
  {
    for ( j = i; j != v2; j = j->m_to[1] )
      j->m_area = area;
    i = i->m_to[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4210
// Name: public: virtual void CNavArea::InheritAttributes(class CNavArea __near *,class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CNavArea::InheritAttributes(CNavArea *this, CNavArea *first, CNavArea *second)
{
  int m_attributeFlags; // eax
  unsigned int m_place; // eax
  IUniformRandomStream *v6; // ecx

  if ( first != nullptr )
  {
    m_attributeFlags = first->m_attributeFlags;
    if ( second != nullptr )
    {
      this->m_attributeFlags = second->m_attributeFlags | m_attributeFlags;
      m_place = first->m_place;
      v6 = (IUniformRandomStream *)second->m_place;
      if ( (IUniformRandomStream *)m_place == v6 )
      {
LABEL_6:
        this->m_place = m_place;
        return;
      }
      if ( m_place == 0 )
        goto LABEL_11;
      if ( v6 == nullptr )
        goto LABEL_6;
      if ( _RandomInt(this: v6, a2: 0, a3: 100) >= 50 )
      {
        this->m_place = second->m_place;
        return;
      }
    }
    else
    {
      this->m_attributeFlags |= m_attributeFlags;
      if ( this->m_place != 0 )
        return;
    }
    v6 = (IUniformRandomStream *)first->m_place;
LABEL_11:
    this->m_place = (unsigned int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F42A0
// Name: public: bool CNavArea::IsRoughlySquare(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsRoughlySquare(CNavArea *this)
{
  float v1; // xmm0_4

  v1 = (float)(this->m_seCorner.x - this->m_nwCorner.x) / (float)(this->m_seCorner.y - this->m_nwCorner.y);
  return v1 >= 0.33222592 && v1 <= 3.01;
}

//------------------------------------------------------------------------------
// Address: 0x102F42E0
// Name: public: bool CNavArea::IsOverlapping(class Vector const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsOverlapping(CNavArea *this, const Vector *pos, float tolerance)
{
  return (float)(pos->x + tolerance) >= this->m_nwCorner.x
      && this->m_seCorner.x >= (float)(pos->x - tolerance)
      && (float)(pos->y + tolerance) >= this->m_nwCorner.y
      && this->m_seCorner.y >= (float)(pos->y - tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x102F4340
// Name: public: bool CNavArea::IsOverlapping(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsOverlapping(CNavArea *this, const CNavArea *area)
{
  return this->m_seCorner.x > area->m_nwCorner.x
      && area->m_seCorner.x > this->m_nwCorner.x
      && this->m_seCorner.y > area->m_nwCorner.y
      && area->m_seCorner.y > this->m_nwCorner.y;
}

//------------------------------------------------------------------------------
// Address: 0x102F4380
// Name: public: bool CNavArea::IsOverlapping(struct Extent const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNavArea::IsOverlapping(CNavArea *this, const Extent *extent)
{
  return this->m_seCorner.x > extent->lo.x
      && extent->hi.x > this->m_nwCorner.x
      && this->m_seCorner.y > extent->lo.y
      && extent->hi.y > this->m_nwCorner.y;
}

//------------------------------------------------------------------------------
// Address: 0x102F43C0
// Name: public: bool CNavArea::Contains(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNavArea::Contains(CNavArea *this, const CNavArea *area)
{
  return area->m_nwCorner.x >= this->m_nwCorner.x
      && this->m_seCorner.x >= area->m_seCorner.x
      && area->m_nwCorner.y >= this->m_nwCorner.y
      && this->m_seCorner.y >= area->m_seCorner.y
      && area->m_nwCorner.z >= this->m_nwCorner.z
      && this->m_seCorner.z >= area->m_seCorner.z;
}

//------------------------------------------------------------------------------
// Address: 0x102F4420
// Name: public: void CNavArea::ComputeNormal(class Vector __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ComputeNormal(CNavArea *this, Vector *normal, bool alternate)
{
  float v3; // xmm3_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  if ( normal != nullptr )
  {
    if ( alternate )
    {
      v3 = this->m_nwCorner.x - this->m_seCorner.x;
      v4 = this->m_swZ - this->m_seCorner.z;
      v5 = this->m_nwCorner.y - this->m_seCorner.y;
      v6 = this->m_neZ - this->m_seCorner.z;
    }
    else
    {
      v3 = this->m_seCorner.x - this->m_nwCorner.x;
      v4 = this->m_neZ - this->m_nwCorner.z;
      v5 = this->m_seCorner.y - this->m_nwCorner.y;
      v6 = this->m_swZ - this->m_nwCorner.z;
    }
    normal->x = (float)(v6 * 0.0) - (float)(v5 * v4);
    normal->y = (float)(v4 * 0.0) - (float)(v6 * v3);
    normal->z = v5 * v3;
    VectorNormalize(vec: normal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F44D0
// Name: public: float CNavArea::GetZ(float,float)const restrict
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNavArea::GetZ(CNavArea *this, float x, float y)
{
  float m_invDxCorners; // xmm1_4
  float m_invDyCorners; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float northZ; // [esp+0h] [ebp-4h]
  float u; // [esp+Ch] [ebp+8h]
  float v; // [esp+10h] [ebp+Ch]

  m_invDxCorners = this->m_invDxCorners;
  if ( m_invDxCorners == 0.0 )
    return this->m_neZ;
  m_invDyCorners = this->m_invDyCorners;
  if ( m_invDyCorners == 0.0 )
    return this->m_neZ;
  v5 = (float)(x - this->m_nwCorner.x) * m_invDxCorners;
  v6 = (float)(y - this->m_nwCorner.y) * m_invDyCorners;
  u = v5;
  v = v6;
  if ( v5 < 0.0 )
  {
    v5 = 0.0;
    u = 0.0;
  }
  if ( (float)(v5 - 1.0) >= 0.0 )
  {
    v5 = 1.0;
    u = 1.0;
  }
  if ( v6 < 0.0 )
  {
    v6 = 0.0;
    v = 0.0;
  }
  if ( (float)(v6 - 1.0) >= 0.0 )
    v = 1.0;
  northZ = (float)((float)(this->m_neZ - this->m_nwCorner.z) * v5) + this->m_nwCorner.z;
  return northZ + (this->m_swZ + (this->m_seCorner.z - this->m_swZ) * u - northZ) * v;
}

//------------------------------------------------------------------------------
// Address: 0x102F45B0
// Name: public: void CNavArea::GetClosestPointOnArea(class Vector const restrict __near *,class Vector __near *)const restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::GetClosestPointOnArea(CNavArea *this, const Vector *pPos, Vector *close)
{
  float x; // xmm2_4
  float y; // xmm0_4
  double v5; // st7
  int v6; // edx

  if ( (float)(pPos->x - this->m_nwCorner.x) < 0.0 )
    x = this->m_nwCorner.x;
  else
    x = pPos->x;
  if ( (float)(x - this->m_seCorner.x) >= 0.0 )
    x = this->m_seCorner.x;
  y = pPos->y;
  if ( (float)(y - this->m_nwCorner.y) < 0.0 )
    y = this->m_nwCorner.y;
  if ( (float)(y - this->m_seCorner.y) >= 0.0 )
    y = this->m_seCorner.y;
  close->x = x;
  close->y = y;
  v5 = CNavArea::GetZ(this, x, y);
  *(float *)(v6 + 8) = v5;
}

//------------------------------------------------------------------------------
// Address: 0x102F4640
// Name: public: void CNavArea::ComputePortal(class CNavArea const __near *,enum NavDirType,class Vector __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ComputePortal(
        CNavArea *this,
        const CNavArea *to,
        NavDirType dir,
        Vector *center,
        float *halfWidth)
{
  Vector *v5; // edx
  double x; // st7
  float y; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  double v11; // st7
  float v12; // xmm3_4
  float v13; // xmm2_4
  double v14; // st7
  int v15; // edx

  if ( dir != NORTH )
  {
    if ( dir != SOUTH )
    {
      v5 = center;
      if ( dir == WEST )
        x = this->m_nwCorner.x;
      else
        x = this->m_seCorner.x;
      center->x = x;
      y = this->m_nwCorner.y;
      v8 = to->m_nwCorner.y;
      if ( y > v8 )
        v8 = this->m_nwCorner.y;
      v9 = this->m_seCorner.y;
      v10 = to->m_seCorner.y;
      if ( v10 > v9 )
        v10 = this->m_seCorner.y;
      if ( y <= v8 )
      {
        if ( v8 > v9 )
          v8 = this->m_seCorner.y;
      }
      else
      {
        v8 = this->m_nwCorner.y;
      }
      if ( y <= v10 )
      {
        if ( v10 > v9 )
          v10 = this->m_seCorner.y;
      }
      else
      {
        v10 = this->m_nwCorner.y;
      }
      center->y = (float)(v10 + v8) * 0.5;
      goto LABEL_34;
    }
    v11 = this->m_seCorner.y;
  }
  else
  {
    v11 = this->m_nwCorner.y;
  }
  v5 = center;
  center->y = v11;
  v12 = this->m_nwCorner.x;
  v8 = to->m_nwCorner.x;
  if ( v12 > v8 )
    v8 = this->m_nwCorner.x;
  v13 = this->m_seCorner.x;
  v10 = to->m_seCorner.x;
  if ( v10 > v13 )
    v10 = this->m_seCorner.x;
  if ( v12 <= v8 )
  {
    if ( v8 > v13 )
      v8 = this->m_seCorner.x;
  }
  else
  {
    v8 = this->m_nwCorner.x;
  }
  if ( v12 <= v10 )
  {
    if ( v10 > v13 )
      v10 = this->m_seCorner.x;
  }
  else
  {
    v10 = this->m_nwCorner.x;
  }
  center->x = (float)(v10 + v8) * 0.5;
LABEL_34:
  *halfWidth = (float)(v10 - v8) * 0.5;
  v14 = CNavArea::GetZ(this, x: v5->x, y: v5->y);
  *(float *)(v15 + 8) = v14;
}

//------------------------------------------------------------------------------
// Address: 0x102F4770
// Name: public: enum NavDirType CNavArea::ComputeLargestPortal(class CNavArea const __near *,class Vector __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNavArea::ComputeLargestPortal(CNavArea *this, const CNavArea *to, Vector *center, float *halfWidth)
{
  const CNavArea *v4; // edi
  float v5; // xmm7_4
  float v6; // xmm0_4
  int v7; // ebx
  float v8; // xmm5_4
  NavDirType v9; // esi
  bool v10; // cf
  float *v11; // ecx
  float centerDir_4; // [esp+4h] [ebp-20h]
  Vector testCenter; // [esp+Ch] [ebp-18h] BYREF
  Vector bestCenter; // [esp+18h] [ebp-Ch]

  v4 = to;
  v5 = to->m_center.x - this->m_center.x;
  *(_QWORD *)&bestCenter.x = *(_QWORD *)&vec3_origin.x;
  v6 = to->m_center.y - this->m_center.y;
  v7 = 4;
  bestCenter.z = vec3_origin.z;
  v8 = 0.0;
  centerDir_4 = v6;
  v9 = NORTH;
  while ( 2 )
  {
    switch ( v9 )
    {
      case NORTH:
        v10 = v6 < 0.0;
        goto LABEL_7;
      case EAST:
        v10 = v5 > 0.0;
        goto LABEL_7;
      case SOUTH:
        v10 = v6 > 0.0;
        goto LABEL_7;
      case WEST:
        v10 = v5 < 0.0;
LABEL_7:
        if ( v10 )
          goto LABEL_8;
        goto LABEL_11;
      default:
LABEL_8:
        CNavArea::ComputePortal(this, to: v4, dir: v9, center: &testCenter, halfWidth: (float *)&to);
        if ( *(float *)&to > v8 )
        {
          bestCenter = testCenter;
          v7 = v9;
          v8 = *(float *)&to;
        }
        v6 = centerDir_4;
LABEL_11:
        if ( ++v9 < NUM_DIRECTIONS )
          continue;
        v11 = halfWidth;
        *center = bestCenter;
        *v11 = v8;
        return v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4860
// Name: public: void CNavArea::AddToOpenList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::AddToOpenList(CNavArea *this)
{
  CNavArea *m_nextOpen; // eax
  CNavArea *v2; // edx
  CNavArea *m_prevOpen; // edx

  if ( this->m_openMarker != CNavArea::m_masterMarker )
  {
    this->m_openMarker = CNavArea::m_masterMarker;
    m_nextOpen = CNavArea::m_openList;
    if ( CNavArea::m_openList != nullptr )
    {
      while ( SLODWORD(this->m_totalCost) >= SLODWORD(m_nextOpen->m_totalCost) )
      {
        v2 = m_nextOpen;
        m_nextOpen = m_nextOpen->m_nextOpen;
        if ( m_nextOpen == nullptr )
        {
          v2->m_nextOpen = this;
          this->m_prevOpen = v2;
          this->m_nextOpen = nullptr;
          CNavArea::m_openListTail = this;
          return;
        }
      }
      m_prevOpen = m_nextOpen->m_prevOpen;
      this->m_prevOpen = m_prevOpen;
      if ( m_prevOpen != nullptr )
        m_prevOpen->m_nextOpen = this;
      else
        CNavArea::m_openList = this;
      this->m_nextOpen = m_nextOpen;
      m_nextOpen->m_prevOpen = this;
    }
    else
    {
      CNavArea::m_openList = this;
      CNavArea::m_openListTail = this;
      this->m_prevOpen = nullptr;
      this->m_nextOpen = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F48E0
// Name: public: void CNavArea::UpdateOnOpenList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::UpdateOnOpenList(CNavArea *this)
{
  CNavArea *m_prevOpen; // eax
  CNavArea *v2; // edx
  CNavArea *m_nextOpen; // esi

  while ( this->m_prevOpen != nullptr )
  {
    m_prevOpen = this->m_prevOpen;
    if ( m_prevOpen->m_totalCost <= this->m_totalCost )
      break;
    v2 = m_prevOpen->m_prevOpen;
    m_nextOpen = this->m_nextOpen;
    this->m_nextOpen = m_prevOpen;
    this->m_prevOpen = v2;
    m_prevOpen->m_prevOpen = this;
    m_prevOpen->m_nextOpen = m_nextOpen;
    if ( v2 != nullptr )
      v2->m_nextOpen = this;
    else
      CNavArea::m_openList = this;
    if ( m_nextOpen != nullptr )
      m_nextOpen->m_prevOpen = m_prevOpen;
    else
      CNavArea::m_openListTail = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4940
// Name: public: void CNavArea::RemoveFromOpenList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::RemoveFromOpenList(CNavArea *this)
{
  CNavArea *m_prevOpen; // eax
  CNavArea *m_nextOpen; // eax

  if ( this->m_openMarker != 0 )
  {
    m_prevOpen = this->m_prevOpen;
    if ( m_prevOpen != nullptr )
      m_prevOpen->m_nextOpen = this->m_nextOpen;
    else
      CNavArea::m_openList = this->m_nextOpen;
    m_nextOpen = this->m_nextOpen;
    if ( m_nextOpen != nullptr )
      m_nextOpen->m_prevOpen = this->m_prevOpen;
    else
      CNavArea::m_openListTail = this->m_prevOpen;
    this->m_openMarker = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4990
// Name: public: static void CNavArea::ClearSearchLists(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CNavArea::ClearSearchLists()
{
  if ( ++CNavArea::m_masterMarker == 0 )
    CNavArea::m_masterMarker = 1;
  CNavArea::m_openListTail = nullptr;
  CNavArea::m_openList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102F49B0
// Name: private: void CNavArea::DecayDanger(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::DecayDanger(CNavArea *this)
{
  float *m_danger; // esi
  int i; // ebx
  float v4; // xmm0_4
  float decayAmount; // [esp+Ch] [ebp-4h]
  float decayAmounta; // [esp+Ch] [ebp-4h]

  m_danger = this->m_danger;
  for ( i = 2; i != 0; --i )
  {
    decayAmount = gpGlobals->curtime - m_danger[2];
    decayAmounta = ((double (__thiscall *)(CNavArea *))this->GetDangerDecayRate)(a1: this) * decayAmount;
    v4 = *m_danger - decayAmounta;
    *m_danger = v4;
    if ( v4 < 0.0 )
      *m_danger = 0.0;
    ++m_danger;
    m_danger[1] = gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4A20
// Name: public: void CNavArea::IncreaseDanger(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::IncreaseDanger(CNavArea *this, int teamID, float amount)
{
  int v4; // eax

  CNavArea::DecayDanger(this);
  v4 = teamID % 2;
  this->m_danger[v4] = this->m_danger[v4] + amount;
  this->m_dangerTimestamp[v4] = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102F4A70
// Name: public: float CNavArea::GetDanger(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNavArea::GetDanger(CNavArea *this, int teamID)
{
  CNavArea::DecayDanger(this);
  return this->m_danger[teamID % 2];
}

//------------------------------------------------------------------------------
// Address: 0x102F4AA0
// Name: float FindGroundZFromPoint(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __usercall FindGroundZFromPoint@<st0>(float a1@<ebp>, const Vector *end, const Vector *start)
{
  float y; // xmm1_4
  float x; // xmm2_4
  float v5; // xmm4_4
  float z; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v16; // [esp-Ch] [ebp-28h]
  float v17; // [esp-8h] [ebp-24h]
  Vector step; // [esp+0h] [ebp-1Ch] BYREF
  Vector point; // [esp+Ch] [ebp-10h] BYREF
  float retaddr; // [esp+1Ch] [ebp+0h]

  point.y = a1;
  point.z = retaddr;
  y = start->y;
  x = end->x;
  v5 = end->y;
  v16 = 0.0;
  v17 = 0.0;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(end->x - start->x) & _mask__AbsFloat_) <= COERCE_FLOAT(
                                                                                    COERCE_UNSIGNED_INT(v5 - y)
                                                                                  & _mask__AbsFloat_) )
  {
    v17 = 25.0;
    if ( y > v5 )
      v17 = -25.0;
  }
  else
  {
    v16 = 25.0;
    if ( start->x > x )
      v16 = -25.0;
  }
  z = start->z;
  *(_QWORD *)&step.x = *(_QWORD *)&start->x;
  v7 = step.x;
  v8 = step.x - x;
  v9 = step.y;
  step.z = z;
  v10 = fsqrt((float)(v8 * v8) + (float)((float)(step.y - v5) * (float)(step.y - v5)));
  v11 = z;
  if ( v10 > 25.0 )
  {
    do
    {
      step.x = v7 + v16;
      step.y = v9 + v17;
      step.z = v11 + 18.0;
      point.x = v11 + 18.0;
      if ( CNavMesh::GetGroundHeight(this: TheNavMesh, pos: &step, height: &point.x, normal: nullptr) )
        v11 = point.x;
      else
        v11 = step.z - 18.0;
      v7 = step.x;
      v9 = step.y;
      v12 = (float)((float)(step.x - end->x) * (float)(step.x - end->x))
          + (float)((float)(step.y - end->y) * (float)(step.y - end->y));
      step.z = v11;
    }
    while ( fsqrt(v12) > 25.0 );
  }
  step.x = end->x;
  v13 = end->y;
  point.x = v11 + 18.0;
  step.y = v13;
  step.z = v11 + 18.0;
  if ( CNavMesh::GetGroundHeight(this: TheNavMesh, pos: &step, height: &point.x, normal: nullptr) )
    v14 = point.x;
  else
    v14 = step.z - 18.0;
  step.z = v14;
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x102F4CA0
// Name: public: void CNavArea::Shift(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Shift(CNavArea *this, const Vector *shift)
{
  this->m_nwCorner.x = this->m_nwCorner.x + shift->x;
  this->m_nwCorner.y = shift->y + this->m_nwCorner.y;
  this->m_nwCorner.z = shift->z + this->m_nwCorner.z;
  this->m_seCorner.x = this->m_seCorner.x + shift->x;
  this->m_seCorner.y = shift->y + this->m_seCorner.y;
  this->m_seCorner.z = shift->z + this->m_seCorner.z;
  this->m_center.x = this->m_center.x + shift->x;
  this->m_center.y = shift->y + this->m_center.y;
  this->m_center.z = shift->z + this->m_center.z;
}

//------------------------------------------------------------------------------
// Address: 0x102F4D30
// Name: public: virtual bool CNavArea::IsBlocked(int,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsBlocked(CNavArea *this, int teamID, bool ignoreNavBlockers)
{
  if ( ignoreNavBlockers && this->m_attributeFlags < 0 )
    return false;
  if ( teamID == -1 )
    return this->m_isBlocked[0] || this->m_isBlocked[1];
  return this->m_isBlocked[teamID % 2];
}

//------------------------------------------------------------------------------
// Address: 0x102F4D70
// Name: public: void CNavArea::MarkObstacleToAvoid(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::MarkObstacleToAvoid(CNavArea *this, float obstructionHeight)
{
  float m_avoidanceObstacleHeight; // xmm0_4

  m_avoidanceObstacleHeight = this->m_avoidanceObstacleHeight;
  if ( obstructionHeight > m_avoidanceObstacleHeight )
  {
    if ( m_avoidanceObstacleHeight == 0.0 )
      TheNavMesh->OnAvoidanceObstacleEnteredArea(this: TheNavMesh, a2: this);
    this->m_avoidanceObstacleHeight = obstructionHeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4DC0
// Name: public: void CNavArea::CheckWaterLevel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::CheckWaterLevel(CNavArea *this)
{
  float z; // eax
  Vector pos; // [esp+4h] [ebp-Ch] BYREF

  z = this->m_center.z;
  *(_QWORD *)&pos.x = *(_QWORD *)&this->m_center.x;
  pos.z = z;
  if ( CNavMesh::GetGroundHeight(this: TheNavMesh, &pos, height: &pos.z, normal: nullptr) )
  {
    pos.z = pos.z + 1.0;
    this->m_isUnderwater = (enginetrace->GetPointContents(this: enginetrace, a2: &pos, a3: -1, a4: nullptr) & 0x4030) != 0;
  }
  else
  {
    this->m_isUnderwater = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4E40
// Name: SelectedSetColorChaged
// Source: json
//------------------------------------------------------------------------------
void __cdecl SelectedSetColorChaged(int var)
{
  int v1; // edi
  const char *v2; // eax
  Color *v3; // esi
  const char *v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  ConVarRef colorVar; // [esp+8h] [ebp-14h] BYREF
  int a; // [esp+10h] [ebp-Ch] BYREF
  int b; // [esp+14h] [ebp-8h] BYREF
  int g; // [esp+18h] [ebp-4h] BYREF

  v1 = var;
  v2 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)var + 16))(a1: var);
  ConVarRef::ConVarRef(this: &colorVar, pName: v2);
  v3 = &s_selectedSetColor;
  v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v1 + 16))(a1: v1);
  if ( v4 == "nav_selected_set_border_color" || _V_stricmp(s1: v4, s2: "nav_selected_set_border_color") == 0 )
    v3 = &s_selectedSetBorderColor;
  v5 = v3->_color[3];
  var = v3->_color[0];
  g = var;
  v6 = v3->_color[2];
  a = v5;
  b = v6;
  v7 = sscanf(string: colorVar.m_pConVarState->m_Value.m_pszString, format: "%d %d %d %d", &var, &g, &b, &a);
  v8 = g;
  v3->_color[0] = var;
  v9 = b;
  v3->_color[1] = v8;
  v3->_color[2] = v9;
  if ( v7 > 3 )
    v3->_color[3] = a;
}

//------------------------------------------------------------------------------
// Address: 0x102F4EF0
// Name: public: bool CNavArea::IsConnected(class CNavLadder const __near *,enum CNavLadder::LadderDirectionType)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsConnected(CNavArea *this, const CNavLadder *ladder, CNavLadder::LadderDirectionType dir)
{
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // edx
  int m_Size; // ecx
  int v5; // eax
  const CNavLadder **i; // edx

  m_pData = this->m_ladder[dir].m_pData;
  m_Size = m_pData->m_Size;
  v5 = 0;
  if ( m_pData->m_Size <= 0 )
    return 0;
  for ( i = (const CNavLadder **)m_pData->m_Elements; ladder != *i; ++i )
  {
    if ( ++v5 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F4F30
// Name: public: bool CNavArea::IsConnected(class CNavArea const __near *,enum NavDirType)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsConnected(CNavArea *this, const CNavArea *area, NavDirType dir)
{
  CNavArea *v3; // ebx
  int v5; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // edi
  int m_Size; // edx
  int v8; // eax
  const CNavArea **m_Elements; // esi
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v11; // edi
  int v12; // edx
  const CNavArea ***v13; // esi
  const CNavArea **v14; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v15; // edx
  int v16; // ecx
  int v17; // eax
  NavLadderConnect *i; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v19; // edx
  int v20; // ecx
  int v21; // eax
  const CNavArea **j; // edx

  v3 = this;
  if ( area == this )
    return 1;
  if ( dir == NUM_DIRECTIONS )
  {
    v5 = 0;
    m_connect = v3->m_connect;
    do
    {
      m_Size = m_connect->m_pData->m_Size;
      v8 = 0;
      if ( m_Size > 0 )
      {
        m_Elements = (const CNavArea **)m_connect->m_pData->m_Elements;
        while ( area != *m_Elements )
        {
          ++v8;
          m_Elements += 2;
          if ( v8 >= m_Size )
          {
            v3 = this;
            goto LABEL_10;
          }
        }
        return 1;
      }
LABEL_10:
      ++v5;
      ++m_connect;
    }
    while ( v5 < 4 );
    m_pData = v3->m_ladder[0].m_pData;
    v11 = m_pData->m_Size;
    v12 = 0;
    if ( m_pData->m_Size <= 0 )
    {
LABEL_18:
      v15 = v3->m_ladder[1].m_pData;
      v16 = v15->m_Size;
      v17 = 0;
      if ( v15->m_Size <= 0 )
        return 0;
      for ( i = v15->m_Elements; *(const CNavArea **)(i->id + 48) != area; ++i )
      {
        if ( ++v17 >= v16 )
          return 0;
      }
    }
    else
    {
      v13 = (const CNavArea ***)m_pData->m_Elements;
      while ( 1 )
      {
        v14 = *v13;
        if ( (*v13)[11] == area || v14[8] == area || v14[9] == area || v14[10] == area )
          break;
        ++v12;
        ++v13;
        if ( v12 >= v11 )
          goto LABEL_18;
      }
    }
  }
  else
  {
    v19 = this->m_connect[dir].m_pData;
    v20 = v19->m_Size;
    v21 = 0;
    if ( v19->m_Size <= 0 )
      return 0;
    for ( j = (const CNavArea **)v19->m_Elements; area != *j; j += 2 )
    {
      if ( ++v21 >= v20 )
        return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F5030
// Name: public: float CNavArea::ComputeGroundHeightChange(class CNavArea const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNavArea::ComputeGroundHeightChange(CNavArea *this, CNavArea *area)
{
  float x; // xmm7_4
  float y; // xmm6_4
  int v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  CVProfile *v9; // ecx
  bool SimpleGroundHeight; // al
  float closeFrom_8; // [esp+28h] [ebp-28h]
  float closeTo_8; // [esp+34h] [ebp-1Ch]
  Vector pos; // [esp+38h] [ebp-18h] BYREF
  float fromZ; // [esp+44h] [ebp-Ch] BYREF
  float toZ; // [esp+48h] [ebp-8h] BYREF
  float v17; // [esp+4Ch] [ebp-4h]
  const CNavArea *areaa; // [esp+58h] [ebp+8h]
  float areab; // [esp+58h] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavArea::ComputeHeightChange",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( (float)(this->m_center.x - area->m_nwCorner.x) < 0.0 )
    x = area->m_nwCorner.x;
  else
    x = this->m_center.x;
  if ( (float)(x - area->m_seCorner.x) >= 0.0 )
    x = area->m_seCorner.x;
  if ( (float)(this->m_center.y - area->m_nwCorner.y) < 0.0 )
    y = area->m_nwCorner.y;
  else
    y = this->m_center.y;
  if ( (float)(y - area->m_seCorner.y) >= 0.0 )
    y = area->m_seCorner.y;
  closeTo_8 = CNavArea::GetZ(this: area, x, y);
  v6 = this->m_nwCorner.x;
  if ( (float)(*(float *)(v5 + 44) - v6) >= 0.0 )
    v6 = *(float *)(v5 + 44);
  areaa = (const CNavArea *)LODWORD(v6);
  if ( (float)(v6 - this->m_seCorner.x) >= 0.0 )
  {
    v6 = this->m_seCorner.x;
    areaa = (const CNavArea *)LODWORD(v6);
  }
  v7 = *(float *)(v5 + 48);
  if ( (float)(v7 - this->m_nwCorner.y) < 0.0 )
    v7 = this->m_nwCorner.y;
  v8 = this->m_seCorner.y;
  v17 = v7;
  if ( (float)(v7 - v8) >= 0.0 )
  {
    v7 = v8;
    v17 = v8;
  }
  closeFrom_8 = CNavArea::GetZ(this, x: v6, y: v7);
  pos.x = x;
  pos.y = y;
  pos.z = closeTo_8 + 18.0;
  if ( !CNavMesh::GetSimpleGroundHeight(this: TheNavMesh, &pos, height: &toZ, normal: nullptr) )
  {
    v9 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
LABEL_21:
    CVProfile::ExitScope(this: v9);
    return 0.0;
  }
  LODWORD(pos.x) = areaa;
  pos.y = v17;
  pos.z = closeFrom_8 + 18.0;
  SimpleGroundHeight = CNavMesh::GetSimpleGroundHeight(this: TheNavMesh, &pos, height: &fromZ, normal: nullptr);
  v9 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  if ( !SimpleGroundHeight )
    goto LABEL_21;
  areab = toZ - fromZ;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return areab;
}

//------------------------------------------------------------------------------
// Address: 0x102F5210
// Name: private: void CNavArea::CalcDebugID(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::CalcDebugID(CNavArea *this)
{
  int x; // ecx
  int y; // edx
  int z; // eax
  int v5; // eax
  int coord[6]; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int pulCRC; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_debugid == 0 )
  {
    x = (int)this->m_seCorner.x;
    y = (int)this->m_seCorner.y;
    coord[0] = (int)this->m_nwCorner.x;
    coord[1] = coord[0];
    z = (int)this->m_nwCorner.z;
    coord[3] = x;
    coord[2] = z;
    v5 = (int)this->m_seCorner.z;
    coord[4] = y;
    coord[5] = v5;
    CRC32_Init(&pulCRC);
    CRC32_ProcessBuffer(&pulCRC, pBuffer: coord, nBuffer: 24);
    CRC32_Final(&pulCRC);
    this->m_debugid = pulCRC;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5280
// Name: public: bool CNavArea::IsFlat(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsFlat(CNavArea *this)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  CNavNode *v10; // eax
  float m_fValue; // xmm0_4
  CNavNode *v12; // eax
  CNavNode *v13; // eax
  CNavNode *v14; // esi
  Vector normal; // [esp+4h] [ebp-18h] BYREF
  Vector otherNormal; // [esp+10h] [ebp-Ch] BYREF

  v2 = this->m_seCorner.y - this->m_nwCorner.y;
  v3 = this->m_neZ - this->m_nwCorner.z;
  v4 = this->m_swZ - this->m_nwCorner.z;
  v5 = this->m_seCorner.x - this->m_nwCorner.x;
  normal.x = (float)(v4 * 0.0) - (float)(v2 * v3);
  normal.y = (float)(v3 * 0.0) - (float)(v4 * v5);
  normal.z = v2 * v5;
  VectorNormalize(vec: &normal);
  v6 = this->m_nwCorner.y - this->m_seCorner.y;
  v7 = this->m_swZ - this->m_seCorner.z;
  v8 = this->m_neZ - this->m_seCorner.z;
  v9 = this->m_nwCorner.x - this->m_seCorner.x;
  otherNormal.x = (float)(v8 * 0.0) - (float)(v6 * v7);
  otherNormal.y = (float)(v7 * 0.0) - (float)(v8 * v9);
  otherNormal.z = v6 * v9;
  VectorNormalize(vec: &otherNormal);
  v10 = this->m_node[0];
  m_fValue = nav_coplanar_slope_limit.m_pParent->m_Value.m_fValue;
  if ( v10 != nullptr && v10->m_isOnDisplacement
    || (v12 = this->m_node[1]) != nullptr && v12->m_isOnDisplacement
    || (v13 = this->m_node[2]) != nullptr && v13->m_isOnDisplacement
    || (v14 = this->m_node[3]) != nullptr && v14->m_isOnDisplacement )
  {
    m_fValue = nav_coplanar_slope_limit_displacement.m_pParent->m_Value.m_fValue;
  }
  return (float)((float)((float)(otherNormal.y * normal.y) + (float)(otherNormal.x * normal.x))
               + (float)(otherNormal.z * normal.z)) > m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x102F5400
// Name: public: bool CNavArea::IsCoplanar(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsCoplanar(CNavArea *this, CNavArea *area)
{
  CNavNode *v3; // eax
  CNavNode *v4; // eax
  CNavNode *v5; // eax
  CNavNode *v6; // eax
  bool result; // al
  CNavNode *v8; // eax
  CNavNode *v9; // eax
  CNavNode *v10; // eax
  CNavNode *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  CNavNode *v20; // eax
  float m_fValue; // xmm0_4
  CNavNode *v22; // eax
  CNavNode *v23; // eax
  CNavNode *v24; // esi
  Vector normal; // [esp+4h] [ebp-18h] BYREF
  Vector otherNormal; // [esp+10h] [ebp-Ch] BYREF

  v3 = this->m_node[0];
  if ( v3 != nullptr && v3->m_isOnDisplacement
    || (v4 = this->m_node[1]) != nullptr && v4->m_isOnDisplacement
    || (v5 = this->m_node[2]) != nullptr && v5->m_isOnDisplacement
    || (v6 = this->m_node[3]) != nullptr && v6->m_isOnDisplacement
    || (result = CNavArea::IsFlat(this)) )
  {
    v8 = area->m_node[0];
    if ( v8 == nullptr || !v8->m_isOnDisplacement )
    {
      v9 = area->m_node[1];
      if ( v9 == nullptr || !v9->m_isOnDisplacement )
      {
        v10 = area->m_node[2];
        if ( v10 == nullptr || !v10->m_isOnDisplacement )
        {
          v11 = area->m_node[3];
          if ( (v11 == nullptr || !v11->m_isOnDisplacement) && !CNavArea::IsFlat(this: area) )
            return false;
        }
      }
    }
    v12 = this->m_seCorner.y - this->m_nwCorner.y;
    v13 = this->m_neZ - this->m_nwCorner.z;
    v14 = this->m_swZ - this->m_nwCorner.z;
    v15 = this->m_seCorner.x - this->m_nwCorner.x;
    normal.x = (float)(v14 * 0.0) - (float)(v12 * v13);
    normal.y = (float)(v13 * 0.0) - (float)(v14 * v15);
    normal.z = v12 * v15;
    VectorNormalize(vec: &normal);
    v16 = area->m_seCorner.y - area->m_nwCorner.y;
    v17 = area->m_neZ - area->m_nwCorner.z;
    v18 = area->m_swZ - area->m_nwCorner.z;
    v19 = area->m_seCorner.x - area->m_nwCorner.x;
    otherNormal.x = (float)(v18 * 0.0) - (float)(v16 * v17);
    otherNormal.y = (float)(v17 * 0.0) - (float)(v18 * v19);
    otherNormal.z = v16 * v19;
    VectorNormalize(vec: &otherNormal);
    v20 = this->m_node[0];
    m_fValue = nav_coplanar_slope_limit.m_pParent->m_Value.m_fValue;
    if ( v20 != nullptr && v20->m_isOnDisplacement
      || (v22 = this->m_node[1]) != nullptr && v22->m_isOnDisplacement
      || (v23 = this->m_node[2]) != nullptr && v23->m_isOnDisplacement
      || (v24 = this->m_node[3]) != nullptr && v24->m_isOnDisplacement )
    {
      m_fValue = nav_coplanar_slope_limit_displacement.m_pParent->m_Value.m_fValue;
    }
    return (float)((float)((float)(otherNormal.y * normal.y) + (float)(otherNormal.x * normal.x))
                 + (float)(otherNormal.z * normal.z)) > m_fValue;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5640
// Name: public: float CNavArea::GetDistanceSquaredToPoint(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNavArea::GetDistanceSquaredToPoint(CNavArea *this, const Vector *pos)
{
  float x; // xmm1_4
  double v4; // st7
  double v5; // st6
  double z; // st5
  double v7; // st5
  double v9; // st6
  double m_swZ; // st5
  double v11; // rt1
  float y; // xmm0_4
  double v13; // st7
  int v14; // edx
  float v15; // [esp+Ch] [ebp-8h]
  float v16; // [esp+Ch] [ebp-8h]
  float v17; // [esp+10h] [ebp-4h]
  float posa; // [esp+1Ch] [ebp+8h]

  x = pos->x;
  v17 = pos->x;
  v15 = this->m_nwCorner.x;
  if ( v15 > pos->x )
  {
    v4 = v15 - v17;
    posa = pos->y;
    if ( this->m_nwCorner.y > posa )
    {
      v5 = this->m_nwCorner.y - posa;
      z = this->m_nwCorner.z;
LABEL_4:
      v7 = z - pos->z;
      return v7 * v7 + v5 * v5 + v4 * v4;
    }
    if ( posa > this->m_seCorner.y )
    {
      v9 = this->m_seCorner.y - posa;
      m_swZ = this->m_swZ;
LABEL_7:
      v11 = m_swZ - pos->z;
      return v4 * v4 + v9 * v9 + v11 * v11;
    }
    return v4 * v4;
  }
  v16 = this->m_seCorner.x;
  y = pos->y;
  if ( x <= v16 )
  {
    if ( this->m_nwCorner.y > y )
      return (this->m_nwCorner.y - y) * (this->m_nwCorner.y - y);
    if ( y > this->m_seCorner.y )
      return (y - this->m_seCorner.y) * (y - this->m_seCorner.y);
    v13 = CNavArea::GetZ(this, x, y);
    v4 = v13 - *(float *)(v14 + 8);
    return v4 * v4;
  }
  if ( this->m_nwCorner.y > y )
  {
    v4 = v16 - v17;
    v9 = this->m_nwCorner.y - y;
    m_swZ = this->m_neZ;
    goto LABEL_7;
  }
  if ( y > this->m_seCorner.y )
  {
    v4 = v16 - v17;
    v5 = this->m_seCorner.y - y;
    z = this->m_seCorner.z;
    goto LABEL_4;
  }
  return (v17 - v16) * (v17 - v16);
}

//------------------------------------------------------------------------------
// Address: 0x102F5790
// Name: public: bool CNavArea::IsContiguous(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsContiguous(CNavArea *this, CNavArea *other)
{
  CNavArea *v3; // ebx
  NavDirType i; // esi
  NavDirType v6; // eax
  bool v7; // bl
  Vector otherEdge; // [esp+Ch] [ebp-18h] BYREF
  Vector myEdge; // [esp+18h] [ebp-Ch] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavArea::IsContiguous",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  v3 = other;
  for ( i = NORTH; i < NUM_DIRECTIONS; ++i )
  {
    if ( CNavArea::IsConnected(this, area: v3, dir: i) != 0 )
      break;
  }
  if ( i == NUM_DIRECTIONS )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return false;
  }
  else
  {
    CNavArea::ComputePortal(this, to: v3, dir: i, center: &myEdge, halfWidth: (float *)&other);
    switch ( i )
    {
      case NORTH:
        v6 = SOUTH;
        break;
      case EAST:
        v6 = WEST;
        break;
      case WEST:
        v6 = EAST;
        break;
      default:
        v6 = NORTH;
        break;
    }
    CNavArea::ComputePortal(this: v3, to: this, dir: v6, center: &otherEdge, halfWidth: (float *)&other);
    v7 = (float)((float)((float)((float)(myEdge.x - otherEdge.x) * (float)(myEdge.x - otherEdge.x))
                       + (float)((float)(myEdge.y - otherEdge.y) * (float)(myEdge.y - otherEdge.y)))
               + (float)((float)(myEdge.z - otherEdge.z) * (float)(myEdge.z - otherEdge.z))) < 324.0;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F58A0
// Name: public: bool CNavArea::IsEdge(enum NavDirType)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsEdge(CNavArea *this, NavDirType dir)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // esi
  int m_Size; // ebx
  int v4; // edi
  CNavArea **i; // esi
  NavDirType dira; // [esp+20h] [ebp+8h]

  m_pData = this->m_connect[dir].m_pData;
  m_Size = m_pData->m_Size;
  v4 = 0;
  if ( m_pData->m_Size <= 0 )
    return 1;
  dira = OppositeDirection(dir);
  for ( i = (CNavArea **)m_pData->m_Elements; CNavArea::IsConnected(this: *i, area: this, dir: dira) == 0; i += 2 )
  {
    if ( ++v4 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F5910
// Name: public: virtual void CNavArea::DrawFilled(int,int,int,int,float,bool,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::DrawFilled(
        CNavArea *this,
        int r,
        int g,
        int b,
        int a,
        float deltaT,
        bool noDepthTest,
        float margin)
{
  float z; // eax
  float y; // xmm2_4
  float m_neZ; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float m_swZ; // xmm4_4
  Vector sw; // [esp+10h] [ebp-3Ch] BYREF
  Vector ne; // [esp+1Ch] [ebp-30h] BYREF
  Vector se; // [esp+28h] [ebp-24h] BYREF
  Vector nw; // [esp+34h] [ebp-18h] BYREF
  __int64 v18; // [esp+40h] [ebp-Ch]
  float v19; // [esp+48h] [ebp-4h]

  z = this->m_nwCorner.z;
  y = this->m_nwCorner.y;
  m_neZ = this->m_neZ;
  v18 = *(_QWORD *)&this->m_nwCorner.x;
  nw.x = *(float *)&v18 + margin;
  nw.y = *((float *)&v18 + 1) + margin;
  v19 = z;
  nw.z = z;
  ne.y = y + margin;
  v11 = this->m_nwCorner.x + margin;
  v12 = COERCE_FLOAT(LODWORD(margin) ^ _mask__NegFloat_) + this->m_seCorner.x;
  sw.y = COERCE_FLOAT(LODWORD(margin) ^ _mask__NegFloat_) + this->m_seCorner.y;
  v18 = *(_QWORD *)&this->m_seCorner.x;
  ne.z = m_neZ;
  m_swZ = this->m_swZ;
  v19 = this->m_seCorner.z;
  se.y = COERCE_FLOAT(LODWORD(margin) ^ _mask__NegFloat_) + *((float *)&v18 + 1);
  se.z = v19;
  ne.x = v12;
  sw.x = v11;
  sw.z = m_swZ;
  se.x = COERCE_FLOAT(LODWORD(margin) ^ _mask__NegFloat_) + *(float *)&v18;
  NDebugOverlay::Triangle(p1: &nw, p2: &se, p3: &ne, r, g, b, a, noDepthTest, duration: deltaT);
  NDebugOverlay::Triangle(p1: &se, p2: &nw, p3: &sw, r, g, b, a, noDepthTest, duration: deltaT);
}

//------------------------------------------------------------------------------
// Address: 0x102F5A40
// Name: public: virtual void CNavArea::DrawSelectedSet(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::DrawSelectedSet(CNavArea *this, const Vector *shift)
{
  int v2; // esi
  int v3; // edi
  float z; // eax
  float x; // xmm0_4
  int v6; // ebx
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  float v11; // xmm6_4
  __int64 v12; // xmm3_8
  float v13; // ecx
  int v14; // ebx
  int v15; // edi
  int v16; // esi
  Vector ne; // [esp+1Ch] [ebp-34h] BYREF
  Vector sw; // [esp+28h] [ebp-28h] BYREF
  Vector se; // [esp+34h] [ebp-1Ch] BYREF
  Vector nw; // [esp+40h] [ebp-10h] BYREF
  int a; // [esp+4Ch] [ebp-4h]

  v2 = s_selectedSetColor._color[0];
  v3 = s_selectedSetColor._color[1];
  z = this->m_nwCorner.z;
  *(_QWORD *)&ne.x = *(_QWORD *)&this->m_nwCorner.x;
  ne.z = z;
  x = shift->x;
  v6 = s_selectedSetColor._color[2];
  nw.x = shift->x + ne.x;
  y = shift->y;
  nw.y = y + ne.y;
  v8 = shift->z;
  nw.z = v8 + z;
  ne.y = y + this->m_nwCorner.y;
  ne.z = v8 + this->m_neZ;
  v9 = x + this->m_seCorner.x;
  sw.y = y + this->m_seCorner.y;
  v10 = v8 + this->m_swZ;
  ne.x = v9;
  v11 = x + this->m_nwCorner.x;
  sw.z = v10;
  v12 = *(_QWORD *)&this->m_seCorner.x;
  v13 = this->m_seCorner.z;
  se.x = x + *(float *)&v12;
  a = s_selectedSetColor._color[3];
  sw.x = v11;
  se.y = y + *((float *)&v12 + 1);
  se.z = v8 + v13;
  NDebugOverlay::Triangle(
    p1: &nw,
    p2: &se,
    p3: &ne,
    r: s_selectedSetColor._color[0],
    g: s_selectedSetColor._color[1],
    b: s_selectedSetColor._color[2],
    a: s_selectedSetColor._color[3],
    noDepthTest: true,
    duration: 0.01023);
  NDebugOverlay::Triangle(p1: &se, p2: &nw, p3: &sw, r: v2, g: v3, b: v6, a, noDepthTest: true, duration: 0.01023);
  v14 = s_selectedSetBorderColor._color[2];
  v15 = s_selectedSetBorderColor._color[1];
  v16 = s_selectedSetBorderColor._color[0];
  NDebugOverlay::Line(
    origin: &nw,
    target: &ne,
    r: s_selectedSetBorderColor._color[0],
    g: s_selectedSetBorderColor._color[1],
    b: s_selectedSetBorderColor._color[2],
    noDepthTest: true,
    duration: 0.01023);
  NDebugOverlay::Line(origin: &nw, target: &sw, r: v16, g: v15, b: v14, noDepthTest: true, duration: 0.01023);
  NDebugOverlay::Line(origin: &sw, target: &se, r: v16, g: v15, b: v14, noDepthTest: true, duration: 0.01023);
  NDebugOverlay::Line(origin: &se, target: &ne, r: v16, g: v15, b: v14, noDepthTest: true, duration: 0.01023);
}

//------------------------------------------------------------------------------
// Address: 0x102F5C20
// Name: public: void CNavArea::DrawDragSelectionSet(class Color __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::DrawDragSelectionSet(CNavArea *this, Color *dragSelectionSetColor)
{
  float z; // edx
  int v3; // ebx
  int v4; // esi
  float m_swZ; // xmm0_4
  int v6; // edi
  int v7; // eax
  float v8; // edx
  __int64 v9; // xmm0_8
  float v10; // ecx
  int v11; // ebx
  int v12; // edi
  int v13; // esi
  Vector ne; // [esp+10h] [ebp-30h] BYREF
  Vector sw; // [esp+1Ch] [ebp-24h] BYREF
  Vector se; // [esp+28h] [ebp-18h] BYREF
  Vector nw; // [esp+34h] [ebp-Ch] BYREF
  int a; // [esp+48h] [ebp+8h]

  z = this->m_nwCorner.z;
  *(_QWORD *)&nw.x = *(_QWORD *)&this->m_nwCorner.x;
  se.x = this->m_seCorner.x;
  se.y = this->m_nwCorner.y;
  se.z = this->m_neZ;
  *(_QWORD *)&ne.x = *(_QWORD *)&se.x;
  v3 = dragSelectionSetColor->_color[2];
  se.x = this->m_nwCorner.x;
  v4 = dragSelectionSetColor->_color[0];
  se.y = this->m_seCorner.y;
  m_swZ = this->m_swZ;
  v6 = dragSelectionSetColor->_color[1];
  v7 = dragSelectionSetColor->_color[3];
  nw.z = z;
  v8 = se.z;
  se.z = m_swZ;
  *(_QWORD *)&sw.x = *(_QWORD *)&se.x;
  v9 = *(_QWORD *)&this->m_seCorner.x;
  v10 = this->m_seCorner.z;
  *(_QWORD *)&se.x = v9;
  ne.z = v8;
  sw.z = se.z;
  a = v7;
  se.z = v10;
  NDebugOverlay::Triangle(p1: &nw, p2: &se, p3: &ne, r: v4, g: v6, b: v3, a: v7, noDepthTest: true, duration: 0.01023);
  NDebugOverlay::Triangle(p1: &se, p2: &nw, p3: &sw, r: v4, g: v6, b: v3, a, noDepthTest: true, duration: 0.01023);
  v11 = s_dragSelectionSetBorderColor._color[2];
  v12 = s_dragSelectionSetBorderColor._color[1];
  v13 = s_dragSelectionSetBorderColor._color[0];
  NDebugOverlay::Line(
    origin: &nw,
    target: &ne,
    r: s_dragSelectionSetBorderColor._color[0],
    g: s_dragSelectionSetBorderColor._color[1],
    b: s_dragSelectionSetBorderColor._color[2],
    noDepthTest: true,
    duration: 0.01023);
  NDebugOverlay::Line(origin: &nw, target: &sw, r: v13, g: v12, b: v11, noDepthTest: true, duration: 0.01023);
  NDebugOverlay::Line(origin: &sw, target: &se, r: v13, g: v12, b: v11, noDepthTest: true, duration: 0.01023);
  NDebugOverlay::Line(origin: &se, target: &ne, r: v13, g: v12, b: v11, noDepthTest: true, duration: 0.01023);
}

//------------------------------------------------------------------------------
// Address: 0x102F5DB0
// Name: public: void CNavArea::DrawHidingSpots(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::DrawHidingSpots(CNavArea *this)
{
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int i; // esi
  HidingSpot *v4; // edx
  unsigned __int8 m_flags; // al
  NavEditColor v6; // ecx
  Vector to; // [esp+8h] [ebp-Ch] BYREF

  m_pData = this->m_hidingSpots.m_pData;
  for ( i = 0; i < m_pData->m_Size; ++i )
  {
    v4 = m_pData->m_Elements[i];
    m_flags = v4->m_flags;
    if ( (m_flags & 4) != 0 )
    {
      v6 = NavIdealSniperColor;
    }
    else if ( (m_flags & 2) != 0 )
    {
      v6 = NavGoodSniperColor;
    }
    else
    {
      v6 = 14 - ((m_flags & 1) != 0);
    }
    to.x = v4->m_pos.x;
    to.y = v4->m_pos.y;
    to.z = v4->m_pos.z + 50.0;
    NavDrawLine(from: &v4->m_pos, &to, navColor: v6);
    m_pData = this->m_hidingSpots.m_pData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5E40
// Name: public: void CNavArea::DrawConnectedAreas(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::DrawConnectedAreas(CNavArea *this)
{
  void (__thiscall *Draw)(CNavArea *); // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int i; // ebx
  CNavLadder *ladder; // esi
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v6; // eax
  int j; // ebx
  CNavLadder *v8; // esi
  NavDirType v9; // ebx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v10; // esi
  int v11; // edx
  int v12; // eax
  CNavArea *area; // esi
  CNavArea *v14; // ecx
  float y; // xmm0_4
  float v16; // xmm2_4
  float x; // xmm1_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float m_invDxCorners; // xmm4_4
  float m_invDyCorners; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float m_neZ; // xmm2_4
  float v26; // xmm7_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  NavDirType v34; // eax
  NavEditColor v35; // [esp-Ch] [ebp-4Ch]
  Vector drawTo; // [esp+4h] [ebp-3Ch] BYREF
  Vector hookPos; // [esp+10h] [ebp-30h] BYREF
  Vector to; // [esp+1Ch] [ebp-24h]
  Vector from; // [esp+28h] [ebp-18h] BYREF
  float halfWidth; // [esp+34h] [ebp-Ch] BYREF
  int count; // [esp+38h] [ebp-8h]
  int a; // [esp+3Ch] [ebp-4h]

  if ( UTIL_GetListenServerHost() != nullptr )
  {
    Draw = this->Draw;
    if ( TheNavMesh->m_editMode == PLACE_PAINTING )
    {
      Draw(this);
    }
    else
    {
      Draw(this);
      CNavArea::DrawHidingSpots(this);
    }
    m_pData = this->m_ladder[0].m_pData;
    for ( i = 0; i < m_pData->m_Size; ++i )
    {
      ladder = m_pData->m_Elements[i].ladder;
      CNavLadder::DrawLadder(this: ladder);
      if ( !CNavLadder::IsConnected(this: ladder, area: this, dir: LADDER_DOWN) )
      {
        drawTo.x = ladder->m_bottom.x;
        drawTo.y = ladder->m_bottom.y;
        drawTo.z = ladder->m_bottom.z + 25.0;
        NavDrawLine(from: &this->m_center, to: &drawTo, navColor: NavConnectedOneWayColor);
      }
      m_pData = this->m_ladder[0].m_pData;
    }
    v6 = this->m_ladder[1].m_pData;
    for ( j = 0; j < v6->m_Size; ++j )
    {
      v8 = v6->m_Elements[j].ladder;
      CNavLadder::DrawLadder(this: v8);
      if ( !CNavLadder::IsConnected(this: v8, area: this, dir: LADDER_UP) )
        NavDrawLine(from: &this->m_center, to: &v8->m_top, navColor: NavConnectedOneWayColor);
      v6 = this->m_ladder[1].m_pData;
    }
    v9 = NORTH;
    while ( 1 )
    {
      count = this->m_connect[v9].m_pData->m_Size;
      a = 0;
      if ( count > 0 )
        break;
LABEL_71:
      if ( ++v9 >= NUM_DIRECTIONS )
        return;
    }
    while ( 1 )
    {
      v10 = this->m_connect[v9].m_pData;
      v11 = a;
      v12 = 0;
      if ( v10->m_Size <= 0 )
      {
LABEL_18:
        area = nullptr;
      }
      else
      {
        while ( v11 != 0 )
        {
          ++v12;
          --v11;
          if ( v12 >= v10->m_Size )
            goto LABEL_18;
        }
        area = v10->m_Elements[v12].area;
      }
      area->Draw(this: area);
      if ( TheNavMesh->m_editMode == PLACE_PAINTING )
        goto LABEL_70;
      CNavArea::DrawHidingSpots(this: area);
      CNavArea::ComputePortal(this, to: area, dir: v9, center: &hookPos, &halfWidth);
      switch ( v9 )
      {
        case NORTH:
          y = hookPos.y + 5.0;
          v16 = hookPos.y - 5.0;
          goto LABEL_23;
        case EAST:
          x = hookPos.x - 5.0;
          y = hookPos.y;
          v18 = hookPos.x + 5.0;
          v19 = hookPos.y;
          goto LABEL_24;
        case SOUTH:
          y = hookPos.y - 5.0;
          v16 = hookPos.y + 5.0;
LABEL_23:
          x = hookPos.x;
          v18 = hookPos.x;
          v19 = v16;
          goto LABEL_24;
        case WEST:
          x = hookPos.x + 5.0;
          y = hookPos.y;
          v18 = hookPos.x - 5.0;
          v19 = hookPos.y;
LABEL_24:
          from.y = y;
          from.x = x;
          to.x = v18;
          to.y = v19;
          break;
        default:
          y = from.y;
          x = from.x;
          v19 = to.y;
          v18 = to.x;
          break;
      }
      m_invDxCorners = this->m_invDxCorners;
      if ( m_invDxCorners == 0.0 || (m_invDyCorners = this->m_invDyCorners) == 0.0 )
      {
        m_neZ = this->m_neZ;
      }
      else
      {
        v22 = (float)(x - this->m_nwCorner.x) * m_invDxCorners;
        v23 = (float)(y - this->m_nwCorner.y) * m_invDyCorners;
        if ( v22 < 0.0 )
          v22 = 0.0;
        if ( (float)(v22 - 1.0) >= 0.0 )
          v22 = 1.0;
        if ( v23 < 0.0 )
          v23 = 0.0;
        if ( (float)(v23 - 1.0) >= 0.0 )
          v23 = 1.0;
        v24 = (float)((float)(this->m_neZ - this->m_nwCorner.z) * v22) + this->m_nwCorner.z;
        m_neZ = (float)((float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v22) + this->m_swZ) - v24)
                      * v23)
              + v24;
      }
      v26 = area->m_nwCorner.x;
      from.z = m_neZ;
      if ( (float)(v18 - v26) < 0.0 )
        v18 = v26;
      if ( (float)(v18 - area->m_seCorner.x) >= 0.0 )
        v18 = area->m_seCorner.x;
      v27 = area->m_nwCorner.y;
      if ( (float)(v19 - v27) < 0.0 )
        v19 = area->m_nwCorner.y;
      if ( (float)(v19 - area->m_seCorner.y) >= 0.0 )
        v19 = area->m_seCorner.y;
      v28 = area->m_invDxCorners;
      if ( v28 == 0.0 || (v29 = area->m_invDyCorners) == 0.0 )
      {
        v33 = area->m_neZ;
      }
      else
      {
        v30 = (float)(v18 - v26) * v28;
        v31 = (float)(v19 - v27) * v29;
        if ( v30 < 0.0 )
          v30 = 0.0;
        if ( (float)(v30 - 1.0) >= 0.0 )
          v30 = 1.0;
        if ( v31 < 0.0 )
          v31 = 0.0;
        if ( (float)(v31 - 1.0) >= 0.0 )
          v31 = 1.0;
        v32 = (float)((float)(area->m_neZ - area->m_nwCorner.z) * v30) + area->m_nwCorner.z;
        v33 = (float)((float)((float)((float)((float)(area->m_seCorner.z - area->m_swZ) * v30) + area->m_swZ) - v32)
                    * v31)
            + v32;
      }
      drawTo.x = v18;
      drawTo.y = v19;
      drawTo.z = v33;
      if ( nav_show_contiguous.m_pParent != nullptr && nav_show_contiguous.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( CNavArea::IsContiguous(this: v14, other: area) )
        {
          v35 = NavConnectedContiguous;
LABEL_69:
          NavDrawLine(&from, to: &drawTo, navColor: v35);
          goto LABEL_70;
        }
        NavDrawLine(&from, to: &drawTo, navColor: NavConnectedNonContiguous);
      }
      else
      {
        v34 = OppositeDirection(dir: v9);
        if ( CNavArea::IsConnected(this: area, area: this, dir: v34) == 0 )
        {
          v35 = NavConnectedOneWayColor;
          goto LABEL_69;
        }
        NavDrawLine(&from, to: &drawTo, navColor: NavConnectedTwoWaysColor);
      }
LABEL_70:
      if ( ++a >= count )
        goto LABEL_71;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F62A0
// Name: FindPositionInArea
// Source: json
//------------------------------------------------------------------------------
Vector *__usercall FindPositionInArea@<eax>(CNavArea *area@<edi>, NavCornerType corner@<ecx>, float *a3@<esi>)
{
  int v3; // ebx
  float x; // xmm6_4
  float v5; // xmm7_4
  float z; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float y; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  bool v17; // cf
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v25; // [esp+8h] [ebp-28h]
  Vector cornerPos; // [esp+10h] [ebp-20h] BYREF
  float v27; // [esp+1Ch] [ebp-14h]
  float v28; // [esp+20h] [ebp-10h]
  float v29; // [esp+24h] [ebp-Ch]
  int multY; // [esp+28h] [ebp-8h]
  float v31; // [esp+2Ch] [ebp-4h]

  v3 = 1;
  multY = 1;
  switch ( corner )
  {
    case NORTH_EAST:
      v3 = -1;
      break;
    case SOUTH_EAST:
      v3 = -1;
      *(float *)&multY = NAN;
      break;
    case SOUTH_WEST:
      *(float *)&multY = NAN;
      break;
    default:
      break;
  }
  CNavArea::GetCorner(this: area, result: &cornerPos, corner);
  x = cornerPos.x;
  v5 = area->m_nwCorner.x;
  z = cornerPos.z;
  v7 = (float)v3;
  v29 = (float)multY;
  v8 = (float)multY * 12.5;
  v9 = cornerPos.x + (float)((float)v3 * 12.5);
  v10 = cornerPos.y + v8;
  *a3 = v9;
  a3[1] = v10;
  a3[2] = z;
  if ( v9 < v5 || area->m_seCorner.x < v9 || v10 < area->m_nwCorner.y || area->m_seCorner.y < v10 )
  {
    y = area->m_nwCorner.y;
    v12 = cornerPos.y;
    multY = SLODWORD(area->m_seCorner.y);
    v13 = (float)((float)(*(float *)&multY - y) * 0.5) * v29;
    v31 = y;
    v25 = v13 + cornerPos.y;
    a3[1] = v13 + cornerPos.y;
    v14 = (float)((float)v3 * 12.5) + x;
    a3[2] = z;
    v15 = area->m_nwCorner.x;
    *a3 = v14;
    v27 = v15;
    if ( v14 < v15 || area->m_seCorner.x < v14 || v25 < v31 || *(float *)&multY < v25 )
    {
      v16 = (float)((float)((float)(area->m_seCorner.x - area->m_nwCorner.x) * 0.5) * v7) + x;
      v17 = v16 < area->m_nwCorner.x;
      v18 = v8 + v12;
      *a3 = v16;
      a3[1] = v18;
      a3[2] = z;
      if ( v17 || area->m_seCorner.x < v16 || v18 < v31 || *(float *)&multY < v18 )
      {
        v28 = area->m_seCorner.x;
        v19 = (float)((float)((float)(v28 - area->m_nwCorner.x) * 0.5) * v7) + x;
        v17 = v19 < area->m_nwCorner.x;
        v20 = v13 + v12;
        *a3 = v19;
        a3[1] = v20;
        a3[2] = z;
        if ( v17 || v28 < v19 || v20 < v31 || *(float *)&multY < v20 )
        {
          v21 = v7 + x;
          v17 = v21 < v27;
          v22 = v29 + v12;
          *a3 = v21;
          a3[1] = v22;
          a3[2] = z;
          if ( v17 || v28 < v21 || v22 < v31 || *(float *)&multY < v22 )
          {
            v23 = cornerPos.z;
            *a3 = x;
            a3[1] = v12;
            a3[2] = v23;
          }
        }
      }
    }
  }
  return (Vector *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x102F64D0
// Name: public: struct SpotEncounter __near * CNavArea::GetSpotEncounter(class CNavArea const __near *,class CNavArea const __near *)
// Source: json
//------------------------------------------------------------------------------
SpotEncounter *__thiscall CNavArea::GetSpotEncounter(CNavArea *this, const CNavArea *from, const CNavArea *to)
{
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int m_Size; // esi
  int v5; // edx
  SpotEncounter **i; // ecx
  SpotEncounter *result; // eax

  if ( from == nullptr )
    return nullptr;
  if ( to == nullptr )
    return nullptr;
  m_pData = this->m_spotEncounters.m_pData;
  m_Size = m_pData->m_Size;
  v5 = 0;
  if ( m_pData->m_Size <= 0 )
    return nullptr;
  for ( i = m_pData->m_Elements; ; ++i )
  {
    result = *i;
    if ( (*i)->from.area == from && result->to.area == to )
      break;
    if ( ++v5 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F6520
// Name: public: virtual bool CNavArea::ComputeLighting(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::ComputeLighting(CNavArea *this)
{
  Vector pos; // [esp+10h] [ebp-10h] BYREF
  float height; // [esp+1Ch] [ebp-4h] BYREF

  if ( engine->IsDedicatedServer(this: engine) )
  {
    this->m_lightIntensity[0] = 1.0;
    this->m_lightIntensity[1] = 1.0;
    this->m_lightIntensity[2] = 1.0;
    this->m_lightIntensity[3] = 1.0;
    return 1;
  }
  else
  {
    FindPositionInArea(area: this, corner: NORTH_WEST, a3: &pos.x);
    pos.z = CNavArea::GetZ(this, x: pos.x, y: pos.y) + 35.5 - 18.0;
    CNavMesh::GetGroundHeight(this: TheNavMesh, &pos, &height, normal: nullptr);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F65C0
// Name: public: void CNavArea::MarkAsBlocked(int,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::MarkAsBlocked(CNavArea *this, int teamID, CBaseEntity *blocker, int bGenerateEvent)
{
  char v5; // cl
  bool *m_isBlocked; // eax
  int i; // edx
  IGameEvent *v8; // esi
  edict_t *m_pPev; // eax
  const char *DebugName; // eax
  edict_t *v11; // eax
  unsigned int v12; // edi
  const char *v13; // eax
  edict_t *v14; // [esp-8h] [ebp-10h]
  edict_t *v15; // [esp-8h] [ebp-10h]
  unsigned int m_id; // [esp-4h] [ebp-Ch]
  unsigned int v17; // [esp-4h] [ebp-Ch]
  unsigned int v18; // [esp-4h] [ebp-Ch]

  if ( blocker != nullptr
    && (blocker->m_iClassname.pszValue == "func_nav_blocker"
     || CBaseEntity::ClassMatchesComplex(this: blocker, pszClassOrWildcard: "func_nav_blocker") != 0) )
  {
    this->m_attributeFlags |= 0x80000000;
  }
  v5 = 0;
  if ( teamID == -1 )
  {
    m_isBlocked = this->m_isBlocked;
    for ( i = 2; i != 0; --i )
    {
      v5 |= *m_isBlocked;
      *m_isBlocked++ = true;
    }
  }
  else
  {
    v5 = this->m_isBlocked[teamID % 2];
    this->m_isBlocked[teamID % 2] = true;
  }
  if ( v5 == 0 )
  {
    if ( (_BYTE)bGenerateEvent != 0 )
    {
      v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "nav_blocked", a3: 0, a4: 0);
      if ( v8 != nullptr )
      {
        v8->SetInt(this: v8, a2: "area", a3: this->m_id);
        v8->SetInt(this: v8, a2: "blocked", a3: 1);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
      }
    }
    if ( nav_debug_blocked.m_pParent != nullptr && nav_debug_blocked.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( blocker != nullptr )
      {
        m_pPev = blocker->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        m_id = this->m_id;
        v14 = m_pPev;
        bGenerateEvent = -8323328;
        DebugName = CBaseEntity::GetDebugName(this: blocker);
        ConColorMsg(a1: (const struct Color *)&bGenerateEvent, a2: "%s %d blocked area %d\n", DebugName, v14, m_id);
        TheNavMesh->OnAreaBlocked(this: TheNavMesh, a2: this);
        return;
      }
      v17 = this->m_id;
      bGenerateEvent = -8323328;
      ConColorMsg(a1: (const struct Color *)&bGenerateEvent, a2: "non-entity blocked area %d\n", v17);
    }
    TheNavMesh->OnAreaBlocked(this: TheNavMesh, a2: this);
    return;
  }
  if ( nav_debug_blocked.m_pParent != nullptr && nav_debug_blocked.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( blocker != nullptr )
    {
      v11 = blocker->m_Network.m_pPev;
      v12 = this->m_id;
      if ( v11 != nullptr )
        v11 -= (int)gpGlobals->pEdicts;
      v15 = v11;
      bGenerateEvent = -8323328;
      v13 = CBaseEntity::GetDebugName(this: blocker);
      ConColorMsg(a1: (const struct Color *)&bGenerateEvent, a2: "DUPE: %s %d blocked area %d\n", v13, v15, v12);
    }
    else
    {
      v18 = this->m_id;
      bGenerateEvent = -8323328;
      ConColorMsg(a1: (const struct Color *)&bGenerateEvent, a2: "DUPE: non-entity blocked area %d\n", v18);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F67A0
// Name: private: void CNavArea::UpdateBlockedFromNavBlockers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::UpdateBlockedFromNavBlockers(CNavArea *this)
{
  char v2; // bl
  int v3; // eax
  bool *m_isBlocked; // esi
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // al
  IGameEvent *v7; // esi
  unsigned int m_id; // [esp-4h] [ebp-2Ch]
  unsigned int v9; // [esp-4h] [ebp-2Ch]
  Extent bounds; // [esp+Ch] [ebp-1Ch] BYREF
  int oldBlocked; // [esp+24h] [ebp-4h] BYREF

  CNavArea::GetExtent(this, extent: &bounds);
  this->m_attributeFlags &= ~0x80000000;
  v2 = 0;
  v3 = 0;
  m_isBlocked = this->m_isBlocked;
  do
  {
    v5 = m_isBlocked[v3];
    *((_BYTE *)&oldBlocked + v3) = v5;
    if ( v2 != 0 || v5 != 0 )
      v2 = 1;
    m_isBlocked[v3++] = false;
  }
  while ( v3 < 2 );
  v6 = CFuncNavBlocker::CalculateBlocked(pResultByTeam: this->m_isBlocked, vecMins: &bounds.lo, vecMaxs: &bounds.hi);
  HIBYTE(oldBlocked) = v6;
  if ( v6 != 0 )
    this->m_attributeFlags |= 0x80000000;
  if ( v2 != v6 )
  {
    v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "nav_blocked", a3: 0, a4: 0);
    if ( v7 != nullptr )
    {
      v7->SetInt(this: v7, a2: "area", a3: this->m_id);
      v7->SetInt(this: v7, a2: "blocked", a3: HIBYTE(oldBlocked));
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
    }
    if ( HIBYTE(oldBlocked) != 0 )
    {
      if ( nav_debug_blocked.m_pParent != nullptr && nav_debug_blocked.m_pParent->m_Value.m_nValue != 0 )
      {
        m_id = this->m_id;
        oldBlocked = -8323328;
        ConColorMsg(a1: (const struct Color *)&oldBlocked, a2: "area %d is blocked by a nav blocker\n", m_id);
      }
      TheNavMesh->OnAreaBlocked(this: TheNavMesh, a2: this);
    }
    else
    {
      if ( nav_debug_blocked.m_pParent != nullptr && nav_debug_blocked.m_pParent->m_Value.m_nValue != 0 )
      {
        v9 = this->m_id;
        oldBlocked = -32768;
        ConColorMsg(a1: (const struct Color *)&oldBlocked, a2: "area %d is unblocked by a nav blocker\n", v9);
      }
      TheNavMesh->OnAreaUnblocked(this: TheNavMesh, a2: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F68F0
// Name: public: void CNavArea::SetupPVS(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::SetupPVS(CNavArea *this)
{
  void (__thiscall *ResetPVS)(IVEngineServer *, unsigned __int8 *, int); // edx
  float v3; // xmm0_4
  float y; // xmm5_4
  float x; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float z; // eax
  float m_invDxCorners; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float m_invDyCorners; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float m_neZ; // xmm0_4
  bool v17; // cf
  float v18; // xmm1_4
  Vector testPos; // [esp+4h] [ebp-24h] BYREF
  __int64 v20; // [esp+10h] [ebp-18h]
  float v21; // [esp+18h] [ebp-10h]
  Vector shift; // [esp+1Ch] [ebp-Ch]

  ResetPVS = engine->ResetPVS;
  m_nPVSSize = 0x2000;
  ResetPVS(this: engine, a2: m_PVS, a3: 0x2000);
  v3 = (float)(this->m_seCorner.y - this->m_nwCorner.y) - 12.5;
  y = 12.5;
  shift.y = 12.5;
  if ( v3 >= 12.5 )
  {
    x = this->m_nwCorner.x;
    v6 = (float)(this->m_seCorner.x - x) - 12.5;
    do
    {
      v7 = 12.5;
      shift.x = 12.5;
      if ( v6 >= 12.5 )
      {
        do
        {
          z = this->m_nwCorner.z;
          m_invDxCorners = this->m_invDxCorners;
          v20 = *(_QWORD *)&this->m_nwCorner.x;
          v21 = z;
          v10 = *(float *)&v20 + v7;
          v11 = *((float *)&v20 + 1) + y;
          testPos.x = v10;
          testPos.y = *((float *)&v20 + 1) + y;
          if ( m_invDxCorners == 0.0 || (m_invDyCorners = this->m_invDyCorners) == 0.0 )
          {
            m_neZ = this->m_neZ;
          }
          else
          {
            v13 = (float)(v10 - x) * m_invDxCorners;
            v14 = (float)(v11 - this->m_nwCorner.y) * m_invDyCorners;
            if ( v13 < 0.0 )
              v13 = 0.0;
            if ( (float)(v13 - 1.0) >= 0.0 )
              v13 = 1.0;
            if ( v14 < 0.0 )
              v14 = 0.0;
            if ( (float)(v14 - 1.0) >= 0.0 )
              v14 = 1.0;
            v15 = (float)((float)(this->m_neZ - this->m_nwCorner.z) * v13) + this->m_nwCorner.z;
            m_neZ = (float)((float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v13) + this->m_swZ) - v15)
                          * v14)
                  + v15;
          }
          testPos.z = m_neZ + 53.25;
          engine->AddOriginToPVS(this: engine, a2: &testPos);
          x = this->m_nwCorner.x;
          y = shift.y;
          v7 = shift.x + 25.0;
          v6 = (float)(this->m_seCorner.x - x) - 12.5;
          v17 = v6 < (float)(shift.x + 25.0);
          shift.x = shift.x + 25.0;
        }
        while ( !v17 );
      }
      y = y + 25.0;
      v18 = (float)(this->m_seCorner.y - this->m_nwCorner.y) - 12.5;
      shift.y = y;
    }
    while ( v18 >= y );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F6AE0
// Name: public: virtual bool CNavArea::IsPotentiallyVisibleToTeam(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsPotentiallyVisibleToTeam(CNavArea *this, int teamIndex)
{
  CTeam *GlobalTeam; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavArea::IsPotentiallyVisibleToTeam",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  GlobalTeam = GetGlobalTeam(iIndex: teamIndex);
  v4 = 0;
  if ( GlobalTeam->GetNumPlayers(this: GlobalTeam) <= 0 )
  {
LABEL_6:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = (int)GlobalTeam->GetPlayer(this: GlobalTeam, a2: v4);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 272))(a1: v5) != 0 )
      {
        v6 = (int)GlobalTeam->GetPlayer(this: GlobalTeam, a2: v4);
        v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 1320))(a1: v6);
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CNavArea *))(*(_DWORD *)v7 + 128))(a1: v7, a2: this) != 0 )
        {
          break;
        }
      }
      if ( ++v4 >= GlobalTeam->GetNumPlayers(this: GlobalTeam) )
        goto LABEL_6;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F6BB0
// Name: public: virtual bool CNavArea::IsCompletelyVisibleToTeam(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsCompletelyVisibleToTeam(CNavArea *this, int teamIndex)
{
  CTeam *GlobalTeam; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavArea::IsCompletelyVisibleToTeam",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  GlobalTeam = GetGlobalTeam(iIndex: teamIndex);
  v4 = 0;
  if ( GlobalTeam->GetNumPlayers(this: GlobalTeam) <= 0 )
  {
LABEL_6:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = (int)GlobalTeam->GetPlayer(this: GlobalTeam, a2: v4);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 272))(a1: v5) != 0 )
      {
        v6 = (int)GlobalTeam->GetPlayer(this: GlobalTeam, a2: v4);
        v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 1320))(a1: v6);
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CNavArea *))(*(_DWORD *)v7 + 136))(a1: v7, a2: this) != 0 )
        {
          break;
        }
      }
      if ( ++v4 >= GlobalTeam->GetNumPlayers(this: GlobalTeam) )
        goto LABEL_6;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F7330
// Name: private: void CParallelProcessor<class CNavArea __near *,class CFuncJobItemProcessor<class CNavArea __near *>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::DoExecute(
        CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  CNavArea **m_pLimit; // ecx
  unsigned int v4; // edx
  CNavArea **v5; // esi
  CNavArea **v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  CNavArea **pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (CNavArea **)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CNavArea **)((char *)v5 + v4);
      if ( m_pLimit < (CNavArea **)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F73E0
// Name: bool IsEntityWalkable(class CBaseEntity __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsEntityWalkable(CBaseEntity *entity, char flags)
{
  CBaseEntity_vtbl *v3; // eax
  char *v4; // eax

  if ( entity != nullptr )
  {
    if ( entity->m_iClassname.pszValue == "worldspawn"
      || CBaseEntity::ClassMatchesComplex(this: entity, pszClassOrWildcard: "worldspawn") != 0
      || entity->m_iClassname.pszValue == "player"
      || CBaseEntity::ClassMatchesComplex(this: entity, pszClassOrWildcard: "player") != 0 )
    {
      return 0;
    }
    if ( entity->m_iClassname.pszValue == "func_door*"
      || CBaseEntity::ClassMatchesComplex(this: entity, pszClassOrWildcard: "func_door*") != 0 )
    {
      return (flags & 2) != 0;
    }
    if ( entity->m_iClassname.pszValue == "prop_door*"
      || CBaseEntity::ClassMatchesComplex(this: entity, pszClassOrWildcard: "prop_door*") != 0 )
    {
      return flags & 1;
    }
  }
  if ( FClassnameIs(pEntity: entity, szClassname: "func_brush") )
  {
    v3 = entity[1].__vftable;
    if ( v3 == nullptr )
      return (flags & 8) != 0;
    v4 = (char *)&v3[-1].RunVScripts + 3;
    if ( v4 == nullptr )
      return 1;
    if ( v4 == (char *)1 )
      return 0;
  }
  if ( FClassnameIs(pEntity: entity, szClassname: "func_breakable")
    && entity->m_iHealth.m_Value != 0
    && entity->m_takedamage.m_Value == 2
    || FClassnameIs(pEntity: entity, szClassname: "func_breakable_surf") && entity->m_takedamage.m_Value == 2 )
  {
    return (flags & 4) != 0;
  }
  return FClassnameIs(pEntity: entity, szClassname: "func_playerinfected_clip")
      || nav_solid_props.m_pParent != nullptr
      && nav_solid_props.m_pParent->m_Value.m_nValue != 0
      && FClassnameIs(pEntity: entity, szClassname: "prop_*");
}

//------------------------------------------------------------------------------
// Address: 0x102F7530
// Name: public: virtual bool CTraceFilterWalkableEntities::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterWalkableEntities::ShouldHitEntity(
        CTraceFilterWalkableEntities *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  CBaseEntity *v4; // eax

  if ( !CTraceFilterNoNPCsOrPlayer::ShouldHitEntity(this, pHandleEntity: pServerEntity, contentsMask) )
    return false;
  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pServerEntity) )
    v4 = nullptr;
  else
    v4 = (CBaseEntity *)pServerEntity->__vftable[1].GetRefEHandle(this: pServerEntity);
  return IsEntityWalkable(entity: v4, flags: this->m_flags) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F7590
// Name: public: static void CNavArea::CompressIDs(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CNavArea::CompressIDs()
{
  int v0; // edi
  CNavArea *v1; // esi

  v0 = 0;
  for ( CNavArea::m_nextID = 1; v0 < TheNavAreas.m_Size; ++v0 )
  {
    v1 = TheNavAreas.m_Memory.m_pMemory[v0];
    v1->m_id = CNavArea::m_nextID++;
    TheNavMesh->RemoveNavArea(this: TheNavMesh, a2: v1);
    CNavMesh::AddNavArea(this: TheNavMesh, area: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F7600
// Name: public: void CNavArea::Build(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Build(CNavArea *this, const Vector *corner, const Vector *otherCorner)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4

  x = corner->x;
  if ( otherCorner->x <= corner->x )
  {
    this->m_seCorner.x = x;
    this->m_nwCorner.x = otherCorner->x;
  }
  else
  {
    this->m_nwCorner.x = x;
    this->m_seCorner.x = otherCorner->x;
  }
  y = corner->y;
  if ( otherCorner->y <= y )
  {
    this->m_seCorner.y = y;
    this->m_nwCorner.y = otherCorner->y;
  }
  else
  {
    this->m_nwCorner.y = y;
    this->m_seCorner.y = otherCorner->y;
  }
  v5 = this->m_seCorner.x;
  this->m_nwCorner.z = corner->z;
  v6 = this->m_nwCorner.x;
  v7 = this->m_nwCorner.y;
  this->m_seCorner.z = corner->z;
  v8 = 0.0;
  v9 = v6 + v5;
  v10 = v5 - this->m_nwCorner.x;
  this->m_center.x = v9 * 0.5;
  v11 = this->m_seCorner.y;
  this->m_center.y = (float)(v7 + v11) * 0.5;
  this->m_center.z = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
  if ( v10 <= 0.0 || (v12 = v11 - v7) <= 0.0 )
  {
    this->m_invDxCorners = 0.0;
  }
  else
  {
    this->m_invDxCorners = 1.0 / v10;
    v8 = 1.0 / v12;
  }
  this->m_invDyCorners = v8;
  this->m_neZ = corner->z;
  this->m_swZ = otherCorner->z;
  CNavArea::CalcDebugID(this);
}

//------------------------------------------------------------------------------
// Address: 0x102F7700
// Name: public: void CNavArea::Build(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Build(
        CNavArea *this,
        const Vector *nwCorner,
        const Vector *neCorner,
        const Vector *seCorner,
        const Vector *swCorner)
{
  float x; // xmm0_4
  float y; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm1_4

  this->m_nwCorner = *nwCorner;
  this->m_seCorner = *seCorner;
  x = this->m_seCorner.x;
  y = this->m_nwCorner.y;
  v7 = this->m_nwCorner.x + x;
  v8 = x - this->m_nwCorner.x;
  this->m_center.x = v7 * 0.5;
  v9 = this->m_seCorner.y;
  this->m_center.y = (float)(y + v9) * 0.5;
  this->m_center.z = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
  this->m_neZ = neCorner->z;
  this->m_swZ = swCorner->z;
  if ( v8 <= 0.0 || (v10 = v9 - y) <= 0.0 )
  {
    this->m_invDxCorners = 0.0;
    this->m_invDyCorners = 0.0;
    CNavArea::CalcDebugID(this);
  }
  else
  {
    this->m_invDxCorners = 1.0 / v8;
    this->m_invDyCorners = 1.0 / v10;
    CNavArea::CalcDebugID(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F77E0
// Name: public: void CNavArea::Build(class CNavNode __near *,class CNavNode __near *,class CNavNode __near *,class CNavNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Build(CNavArea *this, CNavNode *nwNode, CNavNode *neNode, CNavNode *seNode, CNavNode *swNode)
{
  float x; // xmm0_4
  float y; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  double z; // st7
  float v11; // xmm1_4
  CNavArea *v12; // ecx
  CNavArea *v13; // ecx

  this->m_nwCorner.x = nwNode->m_pos.x;
  this->m_nwCorner.y = nwNode->m_pos.y;
  this->m_nwCorner.z = nwNode->m_pos.z;
  this->m_seCorner = seNode->m_pos;
  x = this->m_seCorner.x;
  y = this->m_nwCorner.y;
  v7 = this->m_nwCorner.x + x;
  v8 = x - this->m_nwCorner.x;
  this->m_center.x = v7 * 0.5;
  v9 = this->m_seCorner.y;
  this->m_center.y = (float)(y + v9) * 0.5;
  this->m_center.z = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
  this->m_neZ = neNode->m_pos.z;
  z = swNode->m_pos.z;
  this->m_node[3] = swNode;
  this->m_swZ = z;
  this->m_node[1] = neNode;
  this->m_node[0] = nwNode;
  this->m_node[2] = seNode;
  if ( v8 <= 0.0 || (v11 = v9 - y) <= 0.0 )
  {
    this->m_invDxCorners = 0.0;
    this->m_invDyCorners = 0.0;
    CNavArea::AssignNodes(this, area: this);
    CNavArea::CalcDebugID(this: v13);
  }
  else
  {
    this->m_invDxCorners = 1.0 / v8;
    this->m_invDyCorners = 1.0 / v11;
    CNavArea::AssignNodes(this, area: this);
    CNavArea::CalcDebugID(this: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F78E0
// Name: public: bool CNavArea::Contains(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::Contains(CNavArea *this, const Vector *pos)
{
  float x; // xmm1_4
  float v3; // xmm0_4
  CNavArea *v5; // ecx
  double v6; // st7
  int v7; // edx
  const Vector *v8; // edx
  float v9; // xmm0_4
  CNavArea *v10; // ecx
  float y; // [esp+4h] [ebp-28h]
  Extent areaExtent; // [esp+8h] [ebp-24h] BYREF
  COverlapCheck overlap; // [esp+20h] [ebp-Ch] BYREF

  x = pos->x;
  if ( pos->x < this->m_nwCorner.x )
    return false;
  if ( this->m_seCorner.x < x )
    return false;
  v3 = pos->y;
  if ( v3 < this->m_nwCorner.y )
    return false;
  if ( this->m_seCorner.y < v3 )
    return false;
  v6 = CNavArea::GetZ(this, x, y: pos->y);
  if ( v6 - 18.0 > *(float *)(v7 + 8) )
    return false;
  CNavArea::GetExtent(this: v5, extent: &areaExtent);
  y = v8->y;
  v9 = v8->x;
  overlap.m_pos = v8;
  overlap.m_me = v10;
  overlap.m_myZ = CNavArea::GetZ(this: v10, x: v9, y);
  return CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>(this: TheNavMesh, func: &overlap, extent: &areaExtent);
}

//------------------------------------------------------------------------------
// Address: 0x102F7990
// Name: public: void CNavArea::ComputeClosestPointInPortal(class CNavArea const __near *,enum NavDirType,class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ComputeClosestPointInPortal(
        CNavArea *this,
        CNavArea *to,
        NavDirType dir,
        const Vector *fromPos,
        Vector *closePos)
{
  Vector *v6; // edi
  double x; // st7
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float y; // xmm0_4
  double v13; // st7
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float bottom; // [esp+1Ch] [ebp+8h]
  float bottoma; // [esp+1Ch] [ebp+8h]
  float top; // [esp+28h] [ebp+14h]
  float topa; // [esp+28h] [ebp+14h]

  if ( dir != NORTH )
  {
    if ( dir != SOUTH )
    {
      v6 = closePos;
      if ( dir == WEST )
        x = this->m_nwCorner.x;
      else
        x = this->m_seCorner.x;
      closePos->x = x;
      if ( this->m_nwCorner.y <= to->m_nwCorner.y )
        top = to->m_nwCorner.y;
      else
        top = this->m_nwCorner.y;
      if ( to->m_seCorner.y <= this->m_seCorner.y )
        bottom = to->m_seCorner.y;
      else
        bottom = this->m_seCorner.y;
      v9 = top;
      if ( CNavArea::IsEdge(this: to, dir: NORTH) != 0 )
        v9 = top + 25.0;
      v10 = bottom;
      if ( CNavArea::IsEdge(this: to, dir: SOUTH) != 0 )
        v10 = bottom - 25.0;
      v11 = v9;
      if ( v9 > v10 )
      {
        v11 = (float)(bottom + top) * 0.5;
        v10 = v11;
      }
      y = fromPos->y;
      if ( v11 <= y )
      {
        if ( y <= v10 )
          v6->y = y;
        else
          v6->y = v10;
      }
      else
      {
        v6->y = v11;
      }
      goto LABEL_42;
    }
    v13 = this->m_seCorner.y;
  }
  else
  {
    v13 = this->m_nwCorner.y;
  }
  v6 = closePos;
  closePos->y = v13;
  if ( this->m_nwCorner.x <= to->m_nwCorner.x )
    topa = to->m_nwCorner.x;
  else
    topa = this->m_nwCorner.x;
  if ( to->m_seCorner.x <= this->m_seCorner.x )
    bottoma = to->m_seCorner.x;
  else
    bottoma = this->m_seCorner.x;
  v15 = topa;
  if ( CNavArea::IsEdge(this: to, dir: WEST) != 0 )
    v15 = topa + 25.0;
  v16 = bottoma;
  if ( CNavArea::IsEdge(this: to, dir: EAST) != 0 )
    v16 = bottoma - 25.0;
  v17 = v15;
  if ( v15 > v16 )
  {
    v17 = (float)(bottoma + topa) * 0.5;
    v16 = v17;
  }
  v18 = fromPos->x;
  if ( v17 <= fromPos->x )
  {
    if ( v18 <= v16 )
      v6->x = v18;
    else
      v6->x = v16;
  }
  else
  {
    v6->x = v17;
  }
LABEL_42:
  v6->z = CNavArea::GetZ(this, x: v6->x, y: v6->y);
}

//------------------------------------------------------------------------------
// Address: 0x102F7B70
// Name: public: bool CNavArea::GetCornerHotspot(enum NavCornerType,class Vector __near * const)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CNavArea::GetCornerHotspot@<al>(
        CNavArea *this@<ecx>,
        float a2@<ebp>,
        NavCornerType corner,
        Vector *hotspot)
{
  float x; // xmm1_4
  float z; // eax
  float v6; // edx
  float y; // xmm3_4
  float v8; // xmm5_4
  float m_neZ; // xmm6_4
  __int64 v10; // xmm2_8
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  Vector *v15; // esi
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  Vector *v20; // edi
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  Vector *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm1_4
  float *p_z; // edx
  float m_invDxCorners; // xmm2_4
  float m_invDyCorners; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  bool result; // al
  float v41[3]; // [esp-Ch] [ebp-8Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-80h] BYREF
  float m_swZ; // [esp+50h] [ebp-30h]
  Vector eyeForward; // [esp+54h] [ebp-2Ch] BYREF
  Vector eyePos; // [esp+60h] [ebp-20h]
  Vector nw; // [esp+6Ch] [ebp-14h]
  void *v47; // [esp+78h] [ebp-8h]
  void *retaddr; // [esp+80h] [ebp+0h]

  nw.z = a2;
  v47 = retaddr;
  x = this->m_seCorner.x;
  z = this->m_nwCorner.z;
  v6 = this->m_seCorner.z;
  y = this->m_seCorner.y;
  v8 = this->m_nwCorner.y;
  m_neZ = this->m_neZ;
  v10 = *(_QWORD *)&this->m_nwCorner.x;
  *(_QWORD *)&eyePos.x = v10;
  m_swZ = this->m_swZ;
  v11 = x;
  *(_QWORD *)&eyeForward.x = *(_QWORD *)&this->m_seCorner.x;
  v12 = 9.0;
  v13 = (float)(x - *(float *)&v10) * 0.33333334;
  eyePos.z = z;
  *(float *)(&ray.m_IsSwept + 7) = y;
  eyeForward.z = v6;
  if ( v13 <= 9.0 )
    v12 = v13;
  v14 = (float)(y - this->m_nwCorner.y) * 0.33333334;
  if ( v14 <= v12 )
    v12 = v14;
  switch ( corner )
  {
    case NORTH_WEST:
      v15 = hotspot;
      v16 = eyePos.x;
      v17 = eyePos.y;
      v18 = eyePos.z;
      *hotspot = eyePos;
      goto LABEL_10;
    case NORTH_EAST:
      v15 = hotspot;
      hotspot->x = v11;
      hotspot->y = v8;
      hotspot->z = m_neZ;
      hotspot[1].y = v8;
      hotspot[1].z = m_neZ;
      hotspot[1].x = COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_) + v11;
      v19 = hotspot->z;
      v20 = hotspot + 2;
      v21 = hotspot->y + v12;
      hotspot[2].x = hotspot->x + COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_);
      hotspot[2].y = v21;
      goto LABEL_11;
    case SOUTH_EAST:
      v15 = hotspot;
      v16 = eyeForward.x;
      v17 = eyeForward.y;
      v18 = eyeForward.z;
      *hotspot = eyeForward;
      LODWORD(v12) ^= _mask__NegFloat_;
LABEL_10:
      v15[1].x = v16 + v12;
      v15[1].y = v17;
      v15[1].z = v18;
      v19 = v15->z;
      v20 = v15 + 2;
      v29 = v15->y + v12;
      v15[2].x = v15->x + v12;
      v15[2].y = v29;
LABEL_11:
      v20->z = v19;
      v26 = v15->x;
      v30 = v15->y + v12;
      v28 = v15 + 3;
      v15[3].z = v15->z;
      v15[3].y = v30;
      goto LABEL_12;
    case SOUTH_WEST:
      v15 = hotspot;
      v22 = *(float *)(&ray.m_IsSwept + 7);
      v23 = m_swZ;
      LODWORD(hotspot->x) = v10;
      hotspot->y = v22;
      hotspot->z = v23;
      hotspot[1].y = v22;
      hotspot[1].z = v23;
      hotspot[1].x = *(float *)&v10 + v12;
      v24 = hotspot->z;
      v25 = hotspot->x + v12;
      hotspot[2].y = hotspot->y + COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_);
      v20 = hotspot + 2;
      hotspot[2].x = v25;
      hotspot[2].z = v24;
      v26 = hotspot->x;
      v27 = hotspot->z;
      v28 = hotspot + 3;
      hotspot[3].y = hotspot->y + COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_);
      hotspot[3].z = v27;
LABEL_12:
      v28->x = v26;
      LODWORD(nw.y) = v28;
      p_z = &v15[1].z;
      LODWORD(nw.x) = 3;
      do
      {
        m_invDxCorners = this->m_invDxCorners;
        if ( m_invDxCorners == 0.0 || (m_invDyCorners = this->m_invDyCorners) == 0.0 )
        {
          v37 = this->m_neZ;
        }
        else
        {
          v34 = (float)(*(p_z - 2) - this->m_nwCorner.x) * m_invDxCorners;
          v35 = (float)(*(p_z - 1) - this->m_nwCorner.y) * m_invDyCorners;
          if ( v34 < 0.0 )
            v34 = 0.0;
          if ( (float)(v34 - 1.0) >= 0.0 )
            v34 = 1.0;
          if ( v35 < 0.0 )
            v35 = 0.0;
          if ( (float)(v35 - 1.0) >= 0.0 )
            v35 = 1.0;
          v36 = (float)((float)(this->m_neZ - this->m_nwCorner.z) * v34) + this->m_nwCorner.z;
          v37 = (float)((float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v34) + this->m_swZ) - v36)
                      * v35)
              + v36;
        }
        *p_z = v37;
        p_z += 3;
        --LODWORD(nw.x);
      }
      while ( LODWORD(nw.x) != 0 );
      CNavMesh::GetEditVectors(this: TheNavMesh, pos: &eyeForward, forward: (Vector *)(&ray.m_IsSwept + 3));
      ray.m_Start.z = (float)(eyeForward.y + (float)(*(float *)(&ray.m_IsSwept + 7) * 10000.0)) - eyeForward.y;
      ray.m_Start.y = (float)((float)(*(float *)(&ray.m_IsSwept + 3) * 10000.0) + eyeForward.x) - eyeForward.x;
      ray.m_Start.w = (float)(eyeForward.z + (float)(m_swZ * 10000.0)) - eyeForward.z;
      ray.m_Extents.y = 0.0;
      BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                             + (float)(ray.m_Start.y * ray.m_Start.y))
                                     + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
      memset(&ray.m_StartOffset.y, 0, 12);
      v38 = (float)(vec3_origin.z * 2.0) * 0.5;
      v39 = (float)(vec3_origin.y * 2.0) * 0.5;
      v41[0] = (float)((float)(vec3_origin.x * 2.0) * 0.5) + eyeForward.x;
      v41[2] = eyeForward.z + v38;
      LOBYTE(ray.m_Extents.z) = 1;
      v41[1] = v39 + eyeForward.y;
      ray.m_Delta.y = (float)((float)(vec3_origin.x * 2.0) * 0.5) * -1.0;
      ray.m_Delta.z = v39 * -1.0;
      ray.m_Delta.w = v38 * -1.0;
      if ( IntersectRayWithTriangle(ray: (const Ray_t *)v41, v1: v15, v2: v15 + 1, v3: v20, oneSided: false) <= 0.0
        && IntersectRayWithTriangle(
             ray: (const Ray_t *)v41,
             v1: v20,
             v2: (const Vector *)LODWORD(nw.y),
             v3: v15,
             oneSided: false) <= 0.0 )
      {
        goto LABEL_29;
      }
      result = true;
      break;
    default:
LABEL_29:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F8010
// Name: public: enum NavCornerType CNavArea::GetCornerUnderCursor(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNavArea::GetCornerUnderCursor(CNavArea *this)
{
  NavCornerType v2; // esi
  Vector hotspot[4]; // [esp+8h] [ebp-48h] BYREF
  Vector eyePos; // [esp+38h] [ebp-18h] BYREF
  Vector eyeForward; // [esp+44h] [ebp-Ch] BYREF
  int savedregs; // [esp+50h] [ebp+0h] BYREF

  CNavMesh::GetEditVectors(this: TheNavMesh, pos: &eyePos, forward: &eyeForward);
  v2 = NORTH_WEST;
  while ( !CNavArea::GetCornerHotspot(this, a2: COERCE_FLOAT(&savedregs), corner: v2, hotspot) )
  {
    if ( ++v2 >= NUM_CORNERS )
      return 4;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102F8060
// Name: bool IsHidingSpotInCover(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsHidingSpotInCover(const Vector *spot)
{
  float z; // eax
  int v2; // esi
  __m128 v4; // xmm0
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm1_8
  CGameTrace v8; // [esp+0h] [ebp-78h] BYREF
  float v9; // [esp+54h] [ebp-24h]
  Vector to; // [esp+60h] [ebp-18h] BYREF
  Vector from; // [esp+6Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+78h] [ebp+0h] BYREF
  float angle; // [esp+80h] [ebp+8h]

  z = spot->z;
  v2 = 0;
  *(_QWORD *)&from.x = *(_QWORD *)&spot->x;
  from.z = z + 35.5;
  *(_QWORD *)&to.x = *(_QWORD *)&from.x;
  to.z = (float)(z + 35.5) + 20.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: 0,
    vecAbsStart: &from,
    vecAbsEnd: &to,
    mask: 0x2400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &v8);
  if ( v8.fraction != 1.0 )
    return true;
  v4 = 0;
  angle = 0.0;
  to.z = from.z + 35.5;
  do
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
    *(float *)&v5 = v5;
    v9 = *(float *)&v5 * 100.0;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(angle)));
    *(float *)&v6 = v6;
    to.x = v9 + from.x;
    to.y = (float)(*(float *)&v6 * 100.0) + from.y;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: v2,
      vecAbsStart: &from,
      vecAbsEnd: &to,
      mask: 0x2400Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &v8);
    if ( v8.fraction != 1.0 )
      ++v2;
    v4 = (__m128)LODWORD(angle);
    v4.m128_f32[0] = angle + 0.39269909;
    v7 = (float)(angle + 0.39269909);
    angle = angle + 0.39269909;
  }
  while ( v7 < 6.283185307179586 );
  return v2 >= 8;
}

//------------------------------------------------------------------------------
// Address: 0x102F81B0
// Name: void ClassifySniperSpot(class HidingSpot __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall ClassifySniperSpot(float a1@<ebp>, HidingSpot *spot)
{
  float z; // ecx
  CNavArea *NavArea; // eax
  float v4; // xmm0_4
  int v5; // edi
  float v6; // xmm7_4
  CNavArea *v7; // esi
  float y; // xmm4_4
  float x; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float m_invDxCorners; // xmm4_4
  float m_invDyCorners; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float m_neZ; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  Vector v22; // [esp+24h] [ebp-11Ch] BYREF
  CGameTrace result; // [esp+30h] [ebp-110h] BYREF
  Extent areaExtent; // [esp+98h] [ebp-A8h] BYREF
  float v25; // [esp+B4h] [ebp-8Ch]
  float v26; // [esp+B8h] [ebp-88h]
  float v27; // [esp+BCh] [ebp-84h]
  int v28; // [esp+C4h] [ebp-7Ch]
  int v29; // [esp+C8h] [ebp-78h]
  int v30; // [esp+CCh] [ebp-74h]
  int v31; // [esp+D4h] [ebp-6Ch]
  int v32; // [esp+D8h] [ebp-68h]
  int v33; // [esp+DCh] [ebp-64h]
  int v34; // [esp+E4h] [ebp-5Ch]
  char v35; // [esp+E8h] [ebp-58h]
  bool v36; // [esp+E9h] [ebp-57h]
  float i; // [esp+F4h] [ebp-4Ch]
  float v38; // [esp+F8h] [ebp-48h]
  float v39; // [esp+FCh] [ebp-44h]
  float v40; // [esp+100h] [ebp-40h]
  Extent sniperExtent; // [esp+108h] [ebp-38h]
  __int128 walkable; // [esp+120h] [ebp-20h] OVERLAPPED
  Vector eye; // [esp+130h] [ebp-10h]
  float retaddr; // [esp+140h] [ebp+0h]

  eye.y = a1;
  eye.z = retaddr;
  z = spot->m_pos.z;
  *(_QWORD *)((char *)&walkable + 4) = *(_QWORD *)&spot->m_pos.x;
  *((float *)&walkable + 3) = z;
  NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &spot->m_pos, beneathLimit: 120.0);
  if ( NavArea != nullptr && (NavArea->m_attributeFlags & 0x400) != 0 )
    v4 = *((float *)&walkable + 3) + 62.0;
  else
    v4 = *((float *)&walkable + 3) + 37.0;
  v5 = 0;
  v6 = 0.0;
  *((float *)&walkable + 3) = v4;
  LODWORD(walkable) = 0;
  HIBYTE(eye.x) = 0;
  v39 = 0.0;
  v40 = 0.0;
  sniperExtent.lo.x = 0.0;
  sniperExtent.lo.y = 0.0;
  if ( TheNavAreas.m_Size > 0 )
  {
    do
    {
      v7 = TheNavAreas.m_Memory.m_pMemory[v5];
      y = v7->m_seCorner.y;
      x = v7->m_seCorner.x;
      v10 = v7->m_nwCorner.x;
      v11 = v7->m_nwCorner.y + 12.5;
      areaExtent.lo.x = x;
      areaExtent.lo.y = y;
      sniperExtent.hi.y = v11;
      if ( y > v11 )
      {
        v38 = v10 + 12.5;
        do
        {
          v12 = v38;
          sniperExtent.hi.x = v38;
          if ( x > v38 )
          {
            v13 = v11 - *((float *)&walkable + 2);
            for ( i = v11 - *((float *)&walkable + 2); ; v13 = i )
            {
              m_invDxCorners = v7->m_invDxCorners;
              if ( m_invDxCorners == 0.0 || (m_invDyCorners = v7->m_invDyCorners) == 0.0 )
              {
                m_neZ = v7->m_neZ;
              }
              else
              {
                v16 = (float)(v12 - v7->m_nwCorner.x) * m_invDxCorners;
                v17 = (float)(v11 - v7->m_nwCorner.y) * m_invDyCorners;
                if ( v16 < 0.0 )
                  v16 = 0.0;
                if ( (float)(v16 - 1.0) >= 0.0 )
                  v16 = 1.0;
                if ( v17 < 0.0 )
                  v17 = 0.0;
                if ( (float)(v17 - 1.0) >= 0.0 )
                  v17 = 1.0;
                v18 = (float)((float)(v7->m_neZ - v7->m_nwCorner.z) * v16) + v7->m_nwCorner.z;
                m_neZ = (float)((float)((float)((float)((float)(v7->m_seCorner.z - v7->m_swZ) * v16) + v7->m_swZ) - v18)
                              * v17)
                      + v18;
              }
              sniperExtent.hi.z = m_neZ + 35.5;
              v26 = v13;
              v25 = v12 - *((float *)&walkable + 1);
              v27 = (float)(m_neZ + 35.5) - *((float *)&walkable + 3);
              v36 = (float)((float)((float)(v13 * v13) + (float)(v25 * v25)) + (float)(v27 * v27)) != 0.0;
              v34 = 0;
              v33 = 0;
              v32 = 0;
              v31 = 0;
              v35 = 1;
              v30 = 0;
              v29 = 0;
              v28 = 0;
              areaExtent.hi = *(Vector *)((char *)&walkable + 4);
              CTraceFilterSimple::CTraceFilterSimple(
                this: (CTraceFilterSimple *)&result.m_pEnt,
                passedict: nullptr,
                collisionGroup: 0,
                pExtraShouldHitFunc: nullptr);
              enginetrace->TraceRay(
                this: enginetrace,
                a2: (const Ray_t *)&areaExtent.hi,
                a3: 81921u,
                a4: (ITraceFilter *)&result.m_pEnt,
                a5: (CGameTrace *)&v22);
              if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                DebugDrawLine(
                  vecAbsStart: &v22,
                  vecAbsEnd: &result.startpos,
                  r: 255,
                  g: 0,
                  b: 0,
                  test: true,
                  duration: -1.0);
              if ( result.plane.normal.z != 1.0 || result.plane.pad[1] != 0 )
              {
                v11 = sniperExtent.hi.y;
                v20 = sniperExtent.hi.x;
              }
              else
              {
                v20 = sniperExtent.hi.x;
                v11 = sniperExtent.hi.y;
                v21 = (float)((float)((float)(*((float *)&walkable + 2) - v11) * (float)(*((float *)&walkable + 2) - v11))
                            + (float)((float)(*((float *)&walkable + 1) - v20) * (float)(*((float *)&walkable + 1) - v20)))
                    + (float)((float)(*((float *)&walkable + 3) - sniperExtent.hi.z)
                            * (float)(*((float *)&walkable + 3) - sniperExtent.hi.z));
                if ( v21 > *(float *)&walkable )
                {
                  *(float *)&walkable = (float)((float)((float)(*((float *)&walkable + 2) - sniperExtent.hi.y)
                                                      * (float)(*((float *)&walkable + 2) - sniperExtent.hi.y))
                                              + (float)((float)(*((float *)&walkable + 1) - sniperExtent.hi.x)
                                                      * (float)(*((float *)&walkable + 1) - sniperExtent.hi.x)))
                                      + (float)((float)(*((float *)&walkable + 3) - sniperExtent.hi.z)
                                              * (float)(*((float *)&walkable + 3) - sniperExtent.hi.z));
                  if ( v21 >= 1000000.0 )
                  {
                    if ( HIBYTE(eye.x) != 0 )
                    {
                      if ( v39 > sniperExtent.hi.x )
                        v39 = sniperExtent.hi.x;
                      if ( sniperExtent.hi.x > sniperExtent.lo.x )
                        sniperExtent.lo.x = sniperExtent.hi.x;
                      if ( v40 > sniperExtent.hi.y )
                        v40 = sniperExtent.hi.y;
                      if ( sniperExtent.hi.y > sniperExtent.lo.y )
                        sniperExtent.lo.y = sniperExtent.hi.y;
                    }
                    else
                    {
                      v39 = sniperExtent.hi.x;
                      v40 = sniperExtent.hi.y;
                      sniperExtent.lo.x = sniperExtent.hi.x;
                      sniperExtent.lo.y = sniperExtent.hi.y;
                      HIBYTE(eye.x) = 1;
                    }
                  }
                }
              }
              x = areaExtent.lo.x;
              v12 = v20 + 25.0;
              sniperExtent.hi.x = v20 + 25.0;
              if ( areaExtent.lo.x <= (float)(v20 + 25.0) )
                break;
            }
            y = areaExtent.lo.y;
          }
          v11 = v11 + 25.0;
          sniperExtent.hi.y = v11;
        }
        while ( y > v11 );
        v6 = sniperExtent.lo.y;
      }
      ++v5;
    }
    while ( v5 < TheNavAreas.m_Size );
    if ( HIBYTE(eye.x) != 0 )
    {
      if ( (float)((float)(v6 - v40) * (float)(sniperExtent.lo.x - v39)) >= 40000.0 || *(float *)&walkable >= 2250000.0 )
        spot->m_flags |= 4u;
      else
        spot->m_flags |= 2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F8620
// Name: public: virtual void CNavArea::ComputeSniperSpots(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNavArea::ComputeSniperSpots(CNavArea *this@<ecx>, float a2@<ebp>)
{
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int i; // esi

  if ( nav_quicksave.m_pParent == nullptr || nav_quicksave.m_pParent->m_Value.m_nValue == 0 )
  {
    m_pData = this->m_hidingSpots.m_pData;
    for ( i = 0; i < m_pData->m_Size; ++i )
    {
      ClassifySniperSpot(a1: a2, spot: m_pData->m_Elements[i]);
      m_pData = this->m_hidingSpots.m_pData;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F8660
// Name: nav_update_lighting
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_update_lighting(const CCommand *args)
{
  int v1; // edi
  unsigned int v2; // eax
  CNavArea *NavAreaByID; // eax
  int i; // esi

  v1 = 0;
  if ( args->m_nArgc == 2 )
  {
    v2 = atoi(nptr: args->m_ppArgv[1]);
    NavAreaByID = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v2);
    if ( NavAreaByID != nullptr )
      v1 = NavAreaByID->ComputeLighting(this: NavAreaByID);
  }
  else
  {
    for ( i = 0; i < TheNavAreas.m_Size; ++i )
    {
      if ( TheNavAreas.m_Memory.m_pMemory[i]->ComputeLighting(this: TheNavAreas.m_Memory.m_pMemory[i]) )
        ++v1;
    }
  }
  DevMsg(a1: "Computed lighting for %d/%d areas\n", v1, TheNavAreas.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x102F86F0
// Name: public: void CNavArea::RaiseCorner(enum NavCornerType,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNavArea::RaiseCorner(
        CNavArea *this@<ecx>,
        int a2@<ebp>,
        NavCornerType corner,
        int amount,
        bool raiseAdjacentCorners)
{
  NavCornerType v5; // eax
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  CNavMesh *v13; // edx
  float v14; // xmm1_4
  float v15; // xmm0_4
  int v16; // eax
  int m_gridSizeX; // ecx
  int v18; // esi
  int m_gridSizeY; // ecx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v20; // edi
  float v21; // ecx
  int v22; // esi
  float v23; // eax
  float v24; // ecx
  CNavArea *v25; // edi
  NavCornerType i; // esi
  Vector *v27; // eax
  Vector v28; // [esp-18h] [ebp-44h] BYREF
  Vector v29; // [esp-Ch] [ebp-38h] BYREF
  Vector cornerPos; // [esp+0h] [ebp-2Ch]
  float m_fValue; // [esp+Ch] [ebp-20h]
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *areas; // [esp+10h] [ebp-1Ch]
  int v33; // [esp+14h] [ebp-18h]
  float tolerance; // [esp+18h] [ebp-14h]
  int x; // [esp+1Ch] [ebp-10h]
  int y; // [esp+20h] [ebp-Ch]
  int it; // [esp+24h] [ebp-8h]
  int retaddr; // [esp+2Ch] [ebp+0h]

  y = a2;
  it = retaddr;
  v5 = corner;
  if ( corner == NUM_CORNERS )
  {
    CNavArea::RaiseCorner(this, corner: NORTH_WEST, amount, raiseAdjacentCorners);
    CNavArea::RaiseCorner(this, corner: NORTH_EAST, amount, raiseAdjacentCorners);
    CNavArea::RaiseCorner(this, corner: SOUTH_WEST, amount, raiseAdjacentCorners);
    v5 = SOUTH_EAST;
  }
  switch ( v5 )
  {
    case NORTH_WEST:
      this->m_nwCorner.z = (float)amount + this->m_nwCorner.z;
      break;
    case NORTH_EAST:
      this->m_neZ = (float)amount + this->m_neZ;
      break;
    case SOUTH_EAST:
      this->m_seCorner.z = (float)amount + this->m_seCorner.z;
      break;
    case SOUTH_WEST:
      this->m_swZ = (float)amount + this->m_swZ;
      break;
    default:
      break;
  }
  v7 = this->m_seCorner.x;
  v8 = this->m_nwCorner.y;
  v9 = this->m_nwCorner.x + v7;
  v10 = v7 - this->m_nwCorner.x;
  this->m_center.x = v9 * 0.5;
  v11 = this->m_seCorner.y;
  this->m_center.y = (float)(v8 + v11) * 0.5;
  this->m_center.z = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
  if ( v10 <= 0.0 || (v12 = v11 - v8) <= 0.0 )
  {
    this->m_invDyCorners = 0.0;
    this->m_invDxCorners = 0.0;
  }
  else
  {
    this->m_invDxCorners = 1.0 / v10;
    this->m_invDyCorners = 1.0 / v12;
  }
  if ( raiseAdjacentCorners && nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue > 0.0 )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    this->m_marker = CNavArea::m_masterMarker;
    m_fValue = nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue;
    CNavArea::GetCorner(this, result: &v29, corner: v5);
    v13 = TheNavMesh;
    cornerPos.z = (float)amount;
    v14 = v29.x - TheNavMesh->m_minX;
    v29.z = v29.z - (float)amount;
    v15 = 1.0 / TheNavMesh->m_gridCellSize;
    v16 = (int)(float)(v14 * v15);
    if ( v16 >= 0 )
    {
      m_gridSizeX = TheNavMesh->m_gridSizeX;
      if ( v16 >= m_gridSizeX )
        v16 = m_gridSizeX - 1;
    }
    else
    {
      v16 = 0;
    }
    v18 = (int)(float)((float)(v29.y - TheNavMesh->m_minY) * v15);
    x = v18;
    if ( v18 >= 0 )
    {
      m_gridSizeY = TheNavMesh->m_gridSizeY;
      if ( v18 >= m_gridSizeY )
        x = m_gridSizeY - 1;
    }
    else
    {
      x = 0;
    }
    v20 = (CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *)(v16 - 1);
    LODWORD(v21) = v16 + 1;
    areas = (CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *)(v16 - 1);
    LODWORD(cornerPos.x) = v16 + 1;
    if ( !__OFSUB__(v16 - 1, v16 + 1) || v16 - 1 == v16 + 1 )
    {
      do
      {
        if ( (int)v20 >= 0 && (int)v20 < v13->m_gridSizeX )
        {
          v22 = x - 1;
          v33 = x - 1;
          if ( x - 1 <= x + 1 )
          {
            do
            {
              if ( v22 >= 0 && v22 < v13->m_gridSizeY )
              {
                LODWORD(v23) = &v13->m_grid.m_Memory.m_pMemory[(int)v20 + v22 * v13->m_gridSizeX];
                v24 = 0.0;
                cornerPos.y = v23;
                tolerance = 0.0;
                if ( *(int *)(LODWORD(v23) + 12) > 0 )
                {
                  do
                  {
                    v25 = *(CNavArea **)(*(_DWORD *)LODWORD(v23) + 4 * LODWORD(v24));
                    if ( v25->m_marker != CNavArea::m_masterMarker )
                    {
                      v25->m_marker = CNavArea::m_masterMarker;
                      for ( i = NORTH_WEST; i < NUM_CORNERS; ++i )
                      {
                        v27 = CNavArea::GetCorner(this: v25, result: &v28, corner: i);
                        if ( m_fValue > fsqrt(
                                          (float)((float)((float)(v27->y - v29.y) * (float)(v27->y - v29.y))
                                                + (float)((float)(v27->x - v29.x) * (float)(v27->x - v29.x)))
                                        + (float)((float)(v27->z - v29.z) * (float)(v27->z - v29.z))) )
                          CNavArea::RaiseCorner(
                            this: v25,
                            corner: i,
                            amount: (int)(float)((float)(cornerPos.z + v29.z) - v27->z),
                            raiseAdjacentCorners: false);
                      }
                      v24 = tolerance;
                      v22 = v33;
                      v23 = cornerPos.y;
                    }
                    ++LODWORD(v24);
                    tolerance = v24;
                  }
                  while ( SLODWORD(v24) < *(_DWORD *)(LODWORD(v23) + 12) );
                  v13 = TheNavMesh;
                  v20 = areas;
                }
              }
              v33 = ++v22;
            }
            while ( v22 <= x + 1 );
            v21 = cornerPos.x;
          }
        }
        v20 = (CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *)((char *)v20 + 1);
        areas = v20;
      }
      while ( (int)v20 <= SLODWORD(v21) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F8A70
// Name: public: void CNavArea::PlaceOnGround(enum NavCornerType,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNavArea::PlaceOnGround(CNavArea *this@<ecx>, int a2@<ebp>, NavCornerType corner, float inset)
{
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float m_swZ; // xmm0_4
  double GroundZFromPoint; // st7
  float v11; // xmm0_4
  float y; // xmm5_4
  float v13; // xmm0_4
  float x; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  int v18; // eax
  float z; // xmm0_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  float v23; // xmm2_4
  CNavArea *v24; // eax
  float v25; // edx
  CNavMesh *v26; // ecx
  float v27; // xmm0_4
  int v28; // eax
  int m_gridSizeX; // edx
  float v30; // edx
  int m_gridSizeY; // esi
  unsigned int v32; // esi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *m_pMemory; // edx
  bool v34; // cc
  CNavArea *v35; // edi
  NavCornerType j; // esi
  Vector *v37; // eax
  double v38; // st7
  float v39; // xmm0_4
  float v40; // xmm5_4
  CNavArea *v41; // eax
  float v42; // xmm1_4
  float v43; // xmm4_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm6_4
  float v49; // xmm1_4
  CNavArea *v50; // eax
  float m_neZ; // xmm1_4
  CNavMesh *v52; // ecx
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  int v56; // eax
  int v57; // edx
  float v58; // edx
  int v59; // esi
  unsigned int v60; // esi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v61; // edx
  CNavArea *v62; // edi
  NavCornerType m; // esi
  Vector *v64; // eax
  double v65; // st7
  float v66; // xmm0_4
  float v67; // xmm5_4
  CNavArea *v68; // eax
  float v69; // xmm1_4
  float v70; // xmm4_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm6_4
  float v76; // xmm1_4
  CNavArea *v77; // eax
  float v78; // xmm1_4
  CNavMesh *v79; // ecx
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm0_4
  int v83; // eax
  int v84; // edx
  float v85; // edx
  int v86; // esi
  unsigned int v87; // esi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v88; // edx
  CNavArea *v89; // edi
  NavCornerType n; // esi
  Vector *v91; // eax
  double v92; // st7
  float v93; // xmm0_4
  float v94; // xmm6_4
  CNavArea *v95; // eax
  float v96; // xmm1_4
  float v97; // xmm5_4
  float v98; // xmm2_4
  float v99; // xmm1_4
  float v100; // xmm2_4
  float v101; // xmm0_4
  float v102; // xmm7_4
  float v103; // xmm2_4
  float v104; // edx
  CNavMesh *v105; // ecx
  float v106; // xmm0_4
  int v107; // eax
  int v108; // edx
  float v109; // edx
  int v110; // esi
  int v111; // edx
  unsigned int v112; // esi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v113; // edx
  CNavArea *v114; // edi
  NavCornerType ii; // esi
  Vector *v116; // eax
  Vector v117; // [esp-18h] [ebp-78h] BYREF
  Vector v118; // [esp-Ch] [ebp-6Ch] BYREF
  Vector se; // [esp+0h] [ebp-60h] BYREF
  Vector sw; // [esp+Ch] [ebp-54h] BYREF
  Vector ne; // [esp+18h] [ebp-48h] BYREF
  Vector nw; // [esp+24h] [ebp-3Ch]
  float m_fValue; // [esp+30h] [ebp-30h]
  float v124; // [esp+34h] [ebp-2Ch]
  int m_fValue_low; // [esp+38h] [ebp-28h]
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v126; // [esp+3Ch] [ebp-24h]
  int v127; // [esp+40h] [ebp-20h]
  int v128; // [esp+44h] [ebp-1Ch]
  int k; // [esp+48h] [ebp-18h]
  int i; // [esp+4Ch] [ebp-14h]
  CNavArea *v131; // [esp+50h] [ebp-10h]
  _DWORD v132[3]; // [esp+54h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  v132[0] = a2;
  v132[1] = retaddr;
  v131 = this;
  v5 = this->m_nwCorner.y + inset;
  v6 = inset + this->m_nwCorner.x;
  v7 = this->m_seCorner.y + COERCE_FLOAT(LODWORD(inset) ^ _mask__NegFloat_);
  ne.z = this->m_nwCorner.z;
  v8 = this->m_seCorner.x + COERCE_FLOAT(LODWORD(inset) ^ _mask__NegFloat_);
  v118.z = this->m_seCorner.z;
  sw.z = this->m_neZ;
  m_swZ = this->m_swZ;
  ne.x = v6;
  ne.y = v5;
  v118.x = v8;
  v118.y = v7;
  sw.x = v8;
  sw.y = v5;
  se.x = v6;
  se.y = v7;
  se.z = m_swZ;
  if ( corner == NORTH_WEST || corner == NUM_CORNERS )
  {
    *(float *)&v128 = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &ne, start: &sw);
    GroundZFromPoint = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &ne, start: &se);
    *(float *)&v126 = GroundZFromPoint;
    v11 = *(float *)&v128;
    if ( fabs(*(float *)&v128 - GroundZFromPoint) > 18.0 && fabs(ne.z - *(float *)&v128) > fabs(ne.z - *(float *)&v126) )
      v11 = *(float *)&v126;
    y = this->m_nwCorner.y;
    v13 = v11 - ne.z;
    x = this->m_seCorner.x;
    v15 = this->m_nwCorner.x + x;
    v16 = x - this->m_nwCorner.x;
    this->m_center.x = v15 * 0.5;
    v17 = this->m_seCorner.y;
    v18 = (int)v13;
    z = this->m_nwCorner.z;
    this->m_center.y = (float)(y + v17) * 0.5;
    v20 = (float)v18;
    v21 = z + (float)v18;
    v22 = (float)(this->m_seCorner.z + v21) * 0.5;
    v124 = (float)v18;
    this->m_nwCorner.z = v21;
    this->m_center.z = v22;
    if ( v16 <= 0.0 || (v23 = v17 - y) <= 0.0 )
    {
      this->m_invDyCorners = 0.0;
      this->m_invDxCorners = 0.0;
    }
    else
    {
      this->m_invDxCorners = 1.0 / v16;
      this->m_invDyCorners = 1.0 / v23;
    }
    if ( nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue > 0.0 )
    {
      if ( ++CNavArea::m_masterMarker == 0 )
        CNavArea::m_masterMarker = 1;
      v24 = v131;
      v131->m_marker = CNavArea::m_masterMarker;
      v25 = v24->m_nwCorner.z;
      v26 = TheNavMesh;
      v27 = 1.0 / TheNavMesh->m_gridCellSize;
      m_fValue_low = SLODWORD(nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue);
      *(_QWORD *)&nw.x = *(_QWORD *)&v24->m_nwCorner.x;
      nw.z = v25 - v20;
      v28 = (int)(float)((float)(nw.x - TheNavMesh->m_minX) * v27);
      if ( v28 >= 0 )
      {
        m_gridSizeX = TheNavMesh->m_gridSizeX;
        if ( v28 >= m_gridSizeX )
          v28 = m_gridSizeX - 1;
      }
      else
      {
        v28 = 0;
      }
      LODWORD(v30) = (int)(float)((float)(nw.y - TheNavMesh->m_minY) * v27);
      *(float *)&v128 = v30;
      if ( v30 >= 0.0 )
      {
        m_gridSizeY = TheNavMesh->m_gridSizeY;
        if ( SLODWORD(v30) >= m_gridSizeY )
          v128 = m_gridSizeY - 1;
      }
      else
      {
        *(float *)&v128 = 0.0;
      }
      k = v28 - 1;
      LODWORD(m_fValue) = v28 + 1;
      if ( v28 - 1 <= v28 + 1 )
      {
        v32 = CNavArea::m_masterMarker;
        do
        {
          if ( k >= 0 && k < v26->m_gridSizeX )
          {
            for ( i = v128 - 1; i <= v128 + 1; ++i )
            {
              if ( i >= 0 && i < v26->m_gridSizeY )
              {
                m_pMemory = v26->m_grid.m_Memory.m_pMemory;
                v34 = m_pMemory[k + i * v26->m_gridSizeX].m_Size <= 0;
                v126 = &m_pMemory[k + i * v26->m_gridSizeX];
                *(float *)&v127 = 0.0;
                if ( !v34 )
                {
                  do
                  {
                    v35 = v126->m_Memory.m_pMemory[v127];
                    if ( v35->m_marker != v32 )
                    {
                      v35->m_marker = v32;
                      for ( j = NORTH_WEST; j < NUM_CORNERS; ++j )
                      {
                        v37 = CNavArea::GetCorner(this: v35, result: &v117, corner: j);
                        if ( *(float *)&m_fValue_low > fsqrt(
                                                         (float)((float)((float)(v37->y - nw.y) * (float)(v37->y - nw.y))
                                                               + (float)((float)(v37->z - nw.z) * (float)(v37->z - nw.z)))
                                                       + (float)((float)(v37->x - nw.x) * (float)(v37->x - nw.x))) )
                          CNavArea::RaiseCorner(
                            this: v35,
                            a2: (int)v132,
                            corner: j,
                            amount: (int)(float)((float)(v124 + nw.z) - v37->z),
                            raiseAdjacentCorners: false);
                      }
                      v32 = CNavArea::m_masterMarker;
                    }
                    ++v127;
                  }
                  while ( v127 < v126->m_Size );
                  v26 = TheNavMesh;
                }
              }
            }
          }
          ++k;
        }
        while ( k <= SLODWORD(m_fValue) );
      }
    }
  }
  if ( corner == NORTH_EAST || corner == NUM_CORNERS )
  {
    *(float *)&v127 = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &sw, start: &ne);
    v38 = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &sw, start: &v118);
    m_fValue = v38;
    v39 = *(float *)&v127;
    if ( fabs(*(float *)&v127 - v38) > 18.0 && fabs(sw.z - *(float *)&v127) > fabs(sw.z - m_fValue) )
      v39 = m_fValue;
    v40 = (float)(int)(float)(v39 - sw.z);
    v41 = v131;
    v42 = v131->m_nwCorner.x;
    v43 = v131->m_nwCorner.y;
    v131->m_neZ = v40 + v131->m_neZ;
    v44 = v41->m_seCorner.x;
    v45 = v42 + v44;
    v46 = v44 - v41->m_nwCorner.x;
    v41->m_center.x = v45 * 0.5;
    v47 = v41->m_seCorner.y;
    v41->m_center.y = (float)(v43 + v47) * 0.5;
    v48 = (float)(v41->m_seCorner.z + v41->m_nwCorner.z) * 0.5;
    v124 = v40;
    v41->m_center.z = v48;
    if ( v46 <= 0.0 || (v49 = v47 - v43) <= 0.0 )
    {
      v41->m_invDyCorners = 0.0;
      v41->m_invDxCorners = 0.0;
    }
    else
    {
      v41->m_invDxCorners = 1.0 / v46;
      v41->m_invDyCorners = 1.0 / v49;
    }
    if ( nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue > 0.0 )
    {
      if ( ++CNavArea::m_masterMarker == 0 )
        CNavArea::m_masterMarker = 1;
      v50 = v131;
      m_neZ = v131->m_neZ;
      v131->m_marker = CNavArea::m_masterMarker;
      v52 = TheNavMesh;
      m_fValue = nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue;
      v53 = v50->m_seCorner.x;
      v117.z = m_neZ;
      v117.x = v53;
      v117.y = v50->m_nwCorner.y;
      *(_QWORD *)&nw.x = *(_QWORD *)&v117.x;
      nw.z = m_neZ - v40;
      v54 = v53;
      v55 = 1.0 / TheNavMesh->m_gridCellSize;
      v56 = (int)(float)((float)(v54 - TheNavMesh->m_minX) * v55);
      if ( v56 >= 0 )
      {
        v57 = TheNavMesh->m_gridSizeX;
        if ( v56 >= v57 )
          v56 = v57 - 1;
      }
      else
      {
        v56 = 0;
      }
      LODWORD(v58) = (int)(float)((float)(nw.y - TheNavMesh->m_minY) * v55);
      *(float *)&v128 = v58;
      if ( v58 >= 0.0 )
      {
        v59 = TheNavMesh->m_gridSizeY;
        if ( SLODWORD(v58) >= v59 )
          v128 = v59 - 1;
      }
      else
      {
        *(float *)&v128 = 0.0;
      }
      i = v56 - 1;
      m_fValue_low = v56 + 1;
      if ( v56 - 1 <= v56 + 1 )
      {
        v60 = CNavArea::m_masterMarker;
        do
        {
          if ( i >= 0 && i < v52->m_gridSizeX )
          {
            for ( k = v128 - 1; k <= v128 + 1; ++k )
            {
              if ( k >= 0 && k < v52->m_gridSizeY )
              {
                v61 = v52->m_grid.m_Memory.m_pMemory;
                v34 = v61[i + k * v52->m_gridSizeX].m_Size <= 0;
                v126 = &v61[i + k * v52->m_gridSizeX];
                *(float *)&v127 = 0.0;
                if ( !v34 )
                {
                  do
                  {
                    v62 = v126->m_Memory.m_pMemory[v127];
                    if ( v62->m_marker != v60 )
                    {
                      v62->m_marker = v60;
                      for ( m = NORTH_WEST; m < NUM_CORNERS; ++m )
                      {
                        v64 = CNavArea::GetCorner(this: v62, result: &v117, corner: m);
                        if ( m_fValue > fsqrt(
                                          (float)((float)((float)(v64->y - nw.y) * (float)(v64->y - nw.y))
                                                + (float)((float)(v64->z - nw.z) * (float)(v64->z - nw.z)))
                                        + (float)((float)(v64->x - nw.x) * (float)(v64->x - nw.x))) )
                          CNavArea::RaiseCorner(
                            this: v62,
                            a2: (int)v132,
                            corner: m,
                            amount: (int)(float)((float)(v124 + nw.z) - v64->z),
                            raiseAdjacentCorners: false);
                      }
                      v60 = CNavArea::m_masterMarker;
                    }
                    ++v127;
                  }
                  while ( v127 < v126->m_Size );
                  v52 = TheNavMesh;
                }
              }
            }
          }
          ++i;
        }
        while ( i <= m_fValue_low );
      }
    }
  }
  if ( corner == SOUTH_WEST || corner == NUM_CORNERS )
  {
    *(float *)&v127 = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &se, start: &ne);
    v65 = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &se, start: &v118);
    m_fValue = v65;
    v66 = *(float *)&v127;
    if ( fabs(*(float *)&v127 - v65) > 18.0 && fabs(se.z - *(float *)&v127) > fabs(se.z - m_fValue) )
      v66 = m_fValue;
    v67 = (float)(int)(float)(v66 - se.z);
    v68 = v131;
    v69 = v131->m_nwCorner.x;
    v70 = v131->m_nwCorner.y;
    v131->m_swZ = v67 + v131->m_swZ;
    v71 = v68->m_seCorner.x;
    v72 = v69 + v71;
    v73 = v71 - v68->m_nwCorner.x;
    v68->m_center.x = v72 * 0.5;
    v74 = v68->m_seCorner.y;
    v68->m_center.y = (float)(v70 + v74) * 0.5;
    v75 = (float)(v68->m_seCorner.z + v68->m_nwCorner.z) * 0.5;
    v124 = v67;
    v68->m_center.z = v75;
    if ( v73 <= 0.0 || (v76 = v74 - v70) <= 0.0 )
    {
      v68->m_invDyCorners = 0.0;
      v68->m_invDxCorners = 0.0;
    }
    else
    {
      v68->m_invDxCorners = 1.0 / v73;
      v68->m_invDyCorners = 1.0 / v76;
    }
    if ( nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue > 0.0 )
    {
      if ( ++CNavArea::m_masterMarker == 0 )
        CNavArea::m_masterMarker = 1;
      v77 = v131;
      v78 = v131->m_swZ;
      v131->m_marker = CNavArea::m_masterMarker;
      v79 = TheNavMesh;
      m_fValue = nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue;
      v80 = v77->m_nwCorner.x;
      v117.z = v78;
      v117.x = v80;
      v117.y = v77->m_seCorner.y;
      *(_QWORD *)&ne.x = *(_QWORD *)&v117.x;
      ne.z = v78 - v67;
      v81 = v80;
      v82 = 1.0 / TheNavMesh->m_gridCellSize;
      v83 = (int)(float)((float)(v81 - TheNavMesh->m_minX) * v82);
      if ( v83 >= 0 )
      {
        v84 = TheNavMesh->m_gridSizeX;
        if ( v83 >= v84 )
          v83 = v84 - 1;
      }
      else
      {
        v83 = 0;
      }
      LODWORD(v85) = (int)(float)((float)(ne.y - TheNavMesh->m_minY) * v82);
      *(float *)&v128 = v85;
      if ( v85 >= 0.0 )
      {
        v86 = TheNavMesh->m_gridSizeY;
        if ( SLODWORD(v85) >= v86 )
          v128 = v86 - 1;
      }
      else
      {
        *(float *)&v128 = 0.0;
      }
      i = v83 - 1;
      m_fValue_low = v83 + 1;
      if ( v83 - 1 <= v83 + 1 )
      {
        v87 = CNavArea::m_masterMarker;
        do
        {
          if ( i >= 0 && i < v79->m_gridSizeX )
          {
            for ( k = v128 - 1; k <= v128 + 1; ++k )
            {
              if ( k >= 0 && k < v79->m_gridSizeY )
              {
                v88 = v79->m_grid.m_Memory.m_pMemory;
                v34 = v88[i + k * v79->m_gridSizeX].m_Size <= 0;
                v126 = &v88[i + k * v79->m_gridSizeX];
                *(float *)&v127 = 0.0;
                if ( !v34 )
                {
                  do
                  {
                    v89 = v126->m_Memory.m_pMemory[v127];
                    if ( v89->m_marker != v87 )
                    {
                      v89->m_marker = v87;
                      for ( n = NORTH_WEST; n < NUM_CORNERS; ++n )
                      {
                        v91 = CNavArea::GetCorner(this: v89, result: &v117, corner: n);
                        if ( m_fValue > fsqrt(
                                          (float)((float)((float)(v91->y - ne.y) * (float)(v91->y - ne.y))
                                                + (float)((float)(v91->z - ne.z) * (float)(v91->z - ne.z)))
                                        + (float)((float)(v91->x - ne.x) * (float)(v91->x - ne.x))) )
                          CNavArea::RaiseCorner(
                            this: v89,
                            a2: (int)v132,
                            corner: n,
                            amount: (int)(float)((float)(ne.z + v124) - v91->z),
                            raiseAdjacentCorners: false);
                      }
                      v87 = CNavArea::m_masterMarker;
                    }
                    ++v127;
                  }
                  while ( v127 < v126->m_Size );
                  v79 = TheNavMesh;
                }
              }
            }
          }
          ++i;
        }
        while ( i <= m_fValue_low );
      }
    }
  }
  if ( corner == SOUTH_EAST || corner == NUM_CORNERS )
  {
    *(float *)&v127 = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &v118, start: &sw);
    v92 = FindGroundZFromPoint(a1: COERCE_FLOAT(v132), end: &v118, start: &se);
    m_fValue = v92;
    v93 = *(float *)&v127;
    if ( fabs(*(float *)&v127 - v92) > 18.0 && fabs(v118.z - *(float *)&v127) > fabs(v118.z - m_fValue) )
      v93 = m_fValue;
    v94 = (float)(int)(float)(v93 - v118.z);
    v95 = v131;
    v96 = v131->m_seCorner.x;
    v97 = v131->m_nwCorner.y;
    v98 = v131->m_nwCorner.x + v96;
    v99 = v96 - v131->m_nwCorner.x;
    v131->m_center.x = v98 * 0.5;
    v100 = v95->m_seCorner.y;
    v95->m_center.y = (float)(v97 + v100) * 0.5;
    v101 = v94 + v95->m_seCorner.z;
    v102 = (float)(v95->m_nwCorner.z + v101) * 0.5;
    v124 = v94;
    v95->m_seCorner.z = v101;
    v95->m_center.z = v102;
    if ( v99 <= 0.0 || (v103 = v100 - v97) <= 0.0 )
    {
      v95->m_invDyCorners = 0.0;
      v95->m_invDxCorners = 0.0;
    }
    else
    {
      v95->m_invDxCorners = 1.0 / v99;
      v95->m_invDyCorners = 1.0 / v103;
    }
    if ( nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue > 0.0 )
    {
      if ( ++CNavArea::m_masterMarker == 0 )
        CNavArea::m_masterMarker = 1;
      v95->m_marker = CNavArea::m_masterMarker;
      v104 = v95->m_seCorner.z;
      v105 = TheNavMesh;
      v106 = 1.0 / TheNavMesh->m_gridCellSize;
      m_fValue = nav_corner_adjust_adjacent.m_pParent->m_Value.m_fValue;
      *(_QWORD *)&v118.x = *(_QWORD *)&v95->m_seCorner.x;
      v118.z = v104 - v94;
      v107 = (int)(float)((float)(v118.x - TheNavMesh->m_minX) * v106);
      if ( v107 >= 0 )
      {
        v108 = TheNavMesh->m_gridSizeX;
        if ( v107 >= v108 )
          v107 = v108 - 1;
      }
      else
      {
        v107 = 0;
      }
      LODWORD(v109) = (int)(float)((float)(v118.y - TheNavMesh->m_minY) * v106);
      *(float *)&v128 = v109;
      if ( v109 >= 0.0 )
      {
        v110 = TheNavMesh->m_gridSizeY;
        if ( SLODWORD(v109) >= v110 )
          v128 = v110 - 1;
      }
      else
      {
        *(float *)&v128 = 0.0;
      }
      v111 = v107 - 1;
      i = v107 - 1;
      m_fValue_low = v107 + 1;
      if ( v107 - 1 <= v107 + 1 )
      {
        v112 = CNavArea::m_masterMarker;
        while ( 1 )
        {
          if ( v111 >= 0 && i < v105->m_gridSizeX )
          {
            for ( k = v128 - 1; k <= v128 + 1; ++k )
            {
              if ( k >= 0 && k < v105->m_gridSizeY )
              {
                v113 = v105->m_grid.m_Memory.m_pMemory;
                v34 = v113[i + k * v105->m_gridSizeX].m_Size <= 0;
                v126 = &v113[i + k * v105->m_gridSizeX];
                *(float *)&v127 = 0.0;
                if ( !v34 )
                {
                  do
                  {
                    v114 = v126->m_Memory.m_pMemory[v127];
                    if ( v114->m_marker != v112 )
                    {
                      v114->m_marker = v112;
                      for ( ii = NORTH_WEST; ii < NUM_CORNERS; ++ii )
                      {
                        v116 = CNavArea::GetCorner(this: v114, result: &v117, corner: ii);
                        if ( m_fValue > fsqrt(
                                          (float)((float)((float)(v116->x - v118.x) * (float)(v116->x - v118.x))
                                                + (float)((float)(v116->y - v118.y) * (float)(v116->y - v118.y)))
                                        + (float)((float)(v116->z - v118.z) * (float)(v116->z - v118.z))) )
                          CNavArea::RaiseCorner(
                            this: v114,
                            a2: (int)v132,
                            corner: ii,
                            amount: (int)(float)((float)(v118.z + v124) - v116->z),
                            raiseAdjacentCorners: false);
                      }
                      v112 = CNavArea::m_masterMarker;
                    }
                    ++v127;
                  }
                  while ( v127 < v126->m_Size );
                  v105 = TheNavMesh;
                }
              }
            }
          }
          if ( ++i > m_fValue_low )
            break;
          v111 = i;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F98C0
// Name: CommandNavUpdateBlocked
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavUpdateBlocked()
{
  CNavArea *MarkedArea; // esi
  CFmtStrN<256> *v1; // eax
  int v2; // ebx
  float *i; // edi
  CNavArea *v4; // esi
  CFmtStrN<256> *v5; // eax
  double v6; // st7
  CBasePlayer *ListenServerHost; // eax
  CBaseEntity *v8; // esi
  CFmtStrN<256> v9; // [esp+34h] [ebp-11Ch] BYREF
  Vector origin; // [esp+140h] [ebp-10h] BYREF
  float start; // [esp+14Ch] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( CNavMesh::GetMarkedArea(this: TheNavMesh) != nullptr )
    {
      MarkedArea = CNavMesh::GetMarkedArea(this: TheNavMesh);
      MarkedArea->UpdateBlocked(this: MarkedArea, a2: true, a3: -1);
      if ( MarkedArea->IsBlocked(this: MarkedArea, a2: -1, a3: false) )
      {
        v1 = CFmtStrN<256>::CFmtStrN<256>(
               this: &v9,
               pszFormat: "(%f, %f, %f)",
               MarkedArea->m_center.x,
               MarkedArea->m_center.y,
               (float)(MarkedArea->m_center.z + 35.5));
        DevMsg(a1: "Area #%d %s is blocked\n", MarkedArea->m_id, v1->m_szBuf);
      }
    }
    else
    {
      start = _Plat_FloatTime();
      v2 = 0;
      for ( i = nullptr; v2 < TheNavAreas.m_Size; ++v2 )
      {
        v4 = TheNavAreas.m_Memory.m_pMemory[v2];
        v4->UpdateBlocked(this: v4, a2: true, a3: -1);
        if ( v4->IsBlocked(this: v4, a2: -1, a3: false) )
        {
          v5 = CFmtStrN<256>::CFmtStrN<256>(
                 this: &v9,
                 pszFormat: "(%f, %f, %f)",
                 v4->m_center.x,
                 v4->m_center.y,
                 (float)(v4->m_center.z + 35.5));
          DevMsg(a1: "Area #%d %s is blocked\n", v4->m_id, v5->m_szBuf);
          if ( i == nullptr )
            i = (float *)v4;
        }
      }
      v6 = _Plat_FloatTime();
      DevMsg(a1: "nav_update_blocked took %2.2f ms\n", (v6 - start) * 1000.0);
      if ( i != nullptr )
      {
        ListenServerHost = UTIL_GetListenServerHost();
        v8 = ListenServerHost;
        if ( ListenServerHost != nullptr
          && (CBasePlayer::IsDead(this: ListenServerHost) || ((int)v8[3].m_iParent.pszValue & 8) != 0)
          && ((int (__thiscall *)(CBaseEntity *))v8->__vftable[2].TestCollision)(a1: v8) == 6 )
        {
          origin.x = i[11];
          origin.y = i[12];
          origin.z = i[13] + 53.25;
          UTIL_SetOrigin(entity: v8, vecOrigin: &origin, bFireTriggers: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F9AE0
// Name: public: void CNavArea::CheckFloor(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::CheckFloor(CNavArea *this, CBaseEntity *ignore)
{
  float z; // eax
  CGameTrace tr; // [esp+4h] [ebp-78h] BYREF
  Vector mins; // [esp+58h] [ebp-24h] BYREF
  Vector maxs; // [esp+64h] [ebp-18h] BYREF
  Vector origin; // [esp+70h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+7Ch] [ebp+0h] BYREF

  if ( !this->IsBlocked(this, a2: -1, a3: false) )
  {
    z = this->m_center.z;
    *(_QWORD *)&origin.x = *(_QWORD *)&this->m_center.x;
    origin.z = z - 58.0;
    mins.x = -12.5;
    mins.y = -12.5;
    mins.z = 0.0;
    maxs.x = 12.5;
    maxs.y = 12.5;
    maxs.z = 68.0;
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &origin,
      vecAbsEnd: &origin,
      hullMin: &mins,
      hullMax: &maxs,
      mask: 0x2400Bu,
      ignore,
      collisionGroup: 8,
      ptr: &tr);
    if ( !tr.startsolid )
      CNavArea::MarkAsBlocked(this, teamID: -1, blocker: nullptr, bGenerateEvent: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F9BA0
// Name: CommandNavCheckFloor
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavCheckFloor()
{
  CNavArea *MarkedArea; // esi
  CFmtStrN<256> *v1; // eax
  int i; // edi
  CNavArea *v3; // esi
  CFmtStrN<256> *v4; // eax
  double v5; // st7
  CFmtStrN<256> v6; // [esp+2Ch] [ebp-110h] BYREF
  float start; // [esp+138h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( CNavMesh::GetMarkedArea(this: TheNavMesh) != nullptr )
    {
      MarkedArea = CNavMesh::GetMarkedArea(this: TheNavMesh);
      CNavArea::CheckFloor(this: MarkedArea, ignore: nullptr);
      if ( MarkedArea->IsBlocked(this: MarkedArea, a2: -1, a3: false) )
      {
        v1 = CFmtStrN<256>::CFmtStrN<256>(
               this: &v6,
               pszFormat: "(%f, %f, %f)",
               MarkedArea->m_center.x,
               MarkedArea->m_center.y,
               (float)(MarkedArea->m_center.z + 35.5));
        DevMsg(a1: "Area #%d %s is blocked\n", MarkedArea->m_id, v1->m_szBuf);
      }
    }
    else
    {
      start = _Plat_FloatTime();
      for ( i = 0; i < TheNavAreas.m_Size; ++i )
      {
        v3 = TheNavAreas.m_Memory.m_pMemory[i];
        CNavArea::CheckFloor(this: v3, ignore: nullptr);
        if ( v3->IsBlocked(this: v3, a2: -1, a3: false) )
        {
          v4 = CFmtStrN<256>::CFmtStrN<256>(
                 this: &v6,
                 pszFormat: "(%f, %f, %f)",
                 v3->m_center.x,
                 v3->m_center.y,
                 (float)(v3->m_center.z + 35.5));
          DevMsg(a1: "Area #%d %s is blocked\n", v3->m_id, v4->m_szBuf);
        }
      }
      v5 = _Plat_FloatTime();
      DevMsg(a1: "nav_check_floor took %2.2f ms\n", (v5 - start) * 1000.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F9D40
// Name: CommandNavSelectOverlapping
// Source: json
//------------------------------------------------------------------------------
void __fastcall CommandNavSelectOverlapping(int a1)
{
  int SelecteSetSize; // eax
  SelectOverlappingAreas overlapCheck; // [esp+1h] [ebp-1h] BYREF

  overlapCheck = (SelectOverlappingAreas)HIBYTE(a1);
  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CNavMesh::ClearSelectedSet(this: TheNavMesh);
    CNavMesh::ForAllAreas<SelectOverlappingAreas>(this: TheNavMesh, func: &overlapCheck);
    SelecteSetSize = CNavMesh::GetSelecteSetSize(this: TheNavMesh);
    _Msg(a1: "%d overlapping areas selected\n", SelecteSetSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F9D90
// Name: public: enum CNavArea::VisibilityType CNavArea::ComputeVisibility(class CNavArea const __near *,bool,bool,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CNavArea::VisibilityType __userpurge CNavArea::ComputeVisibility@<eax>(
        CNavArea *this@<ecx>,
        float a2@<ebp>,
        CNavArea *area,
        bool isPVSValid,
        bool bCheckPVS,
        bool *pOutsidePVS)
{
  float v7; // xmm1_4
  float v8; // xmm0_4
  float m_fValue; // xmm1_4
  float v10; // xmm0_4
  float x; // xmm2_4
  float z; // ecx
  float y; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm1_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // edx
  float v28; // xmm1_4
  CNavArea::VisibilityType result; // eax
  float v30; // ecx
  float v31; // edx
  float v32; // xmm4_4
  float v33; // xmm6_4
  float v34; // xmm3_4
  float m_swZ; // xmm2_4
  float v36; // xmm7_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm0_4
  float v48; // edx
  float v49; // eax
  float v50; // xmm0_4
  __int64 v51; // xmm0_8
  __int64 v52; // xmm0_8
  float v53; // xmm1_4
  float v54; // xmm2_4
  bool (__thiscall *IsPartiallyVisible)(CNavArea *, const Vector *, CBaseEntity *); // edx
  bool v56; // al
  float v57; // xmm0_4
  float v58; // xmm0_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm5_4
  float v62; // xmm0_4
  float v63; // edx
  float v64; // xmm4_4
  float v65; // xmm5_4
  float m_invDxCorners; // xmm2_4
  float m_invDyCorners; // xmm6_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm3_4
  float m_neZ; // xmm0_4
  float v72; // xmm0_4
  float v73; // xmm5_4
  float v74; // xmm0_4
  bool v75; // cf
  float v76; // xmm0_4
  Vector v77; // [esp+2Ch] [ebp-154h] BYREF
  CGameTrace tr; // [esp+38h] [ebp-148h] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+90h] [ebp-F0h] BYREF
  float v80; // [esp+A4h] [ebp-DCh]
  float v81; // [esp+A8h] [ebp-D8h]
  float v82; // [esp+ACh] [ebp-D4h]
  float v83; // [esp+B4h] [ebp-CCh]
  float v84; // [esp+B8h] [ebp-C8h]
  float v85; // [esp+BCh] [ebp-C4h]
  float v86; // [esp+C4h] [ebp-BCh]
  float v87; // [esp+C8h] [ebp-B8h]
  float v88; // [esp+CCh] [ebp-B4h]
  int v89; // [esp+D4h] [ebp-ACh]
  bool v90; // [esp+D8h] [ebp-A8h]
  bool v91; // [esp+D9h] [ebp-A7h]
  Vector v92; // [esp+F0h] [ebp-90h] BYREF
  Vector vOtherMaxs; // [esp+FCh] [ebp-84h] BYREF
  Vector vOtherMins; // [esp+108h] [ebp-78h] BYREF
  float angleTolerance; // [esp+114h] [ebp-6Ch]
  float distanceSq; // [esp+118h] [ebp-68h]
  Vector vTarget; // [esp+11Ch] [ebp-64h] BYREF
  Vector eyeToCenter; // [esp+128h] [ebp-58h] BYREF
  Vector testPos; // [esp+134h] [ebp-4Ch] BYREF
  Vector vThisCenter; // [esp+140h] [ebp-40h]
  Vector vTraceMins; // [esp+14Ch] [ebp-34h] BYREF
  unsigned __int64 v102; // [esp+158h] [ebp-28h] BYREF
  float v103; // [esp+160h] [ebp-20h]
  Vector vThisSE; // [esp+164h] [ebp-1Ch]
  Vector eyeToCorner; // [esp+170h] [ebp-10h]
  float retaddr; // [esp+180h] [ebp+0h]

  eyeToCorner.y = a2;
  eyeToCorner.z = retaddr;
  v7 = area->m_center.x - this->m_center.x;
  v8 = (float)((float)(area->m_center.y - this->m_center.y) * (float)(area->m_center.y - this->m_center.y))
     + (float)(v7 * v7);
  m_fValue = nav_max_view_distance.m_pParent->m_Value.m_fValue;
  v10 = v8 + (float)((float)(area->m_center.z - this->m_center.z) * (float)(area->m_center.z - this->m_center.z));
  vOtherMins.y = v10;
  if ( m_fValue > 0.0000099999997 && v10 > (float)(m_fValue * m_fValue) )
    return NOT_VISIBLE;
  if ( !isPVSValid )
    CNavArea::SetupPVS(this);
  if ( bCheckPVS )
  {
    x = area->m_center.x;
    z = area->m_nwCorner.z;
    y = area->m_center.y;
    v14 = area->m_center.z;
    *(_QWORD *)&vThisSE.x = *(_QWORD *)&area->m_nwCorner.x;
    v15 = v14 + 53.25;
    vThisSE.z = z;
    v16 = x;
    v102 = __PAIR64__(LODWORD(y), LODWORD(x));
    v103 = v15;
    vTraceMins.x = x;
    vTraceMins.y = y;
    vTraceMins.z = v15;
    v17 = z + 53.25;
    if ( x <= vThisSE.x )
    {
      if ( vThisSE.x > x )
        *(float *)&v102 = vThisSE.x;
    }
    else
    {
      v16 = vThisSE.x;
      vTraceMins.x = vThisSE.x;
    }
    if ( y <= vThisSE.y )
    {
      if ( vThisSE.y > y )
        HIDWORD(v102) = LODWORD(vThisSE.y);
    }
    else
    {
      vTraceMins.y = vThisSE.y;
    }
    if ( v15 <= v17 )
    {
      if ( v17 > v15 )
        v103 = z + 53.25;
    }
    else
    {
      vTraceMins.z = z + 53.25;
    }
    v18 = area->m_seCorner.x;
    v19 = area->m_nwCorner.y;
    v20 = *(float *)&v102;
    v21 = area->m_neZ + 53.25;
    if ( v16 <= v18 )
    {
      if ( v18 > *(float *)&v102 )
      {
        v20 = area->m_seCorner.x;
        *(float *)&v102 = v20;
      }
    }
    else
    {
      v16 = area->m_seCorner.x;
      vTraceMins.x = v16;
    }
    if ( vTraceMins.y <= v19 )
    {
      if ( v19 > *((float *)&v102 + 1) )
        *((float *)&v102 + 1) = v19;
    }
    else
    {
      vTraceMins.y = v19;
    }
    v22 = vTraceMins.z;
    v23 = v103;
    if ( vTraceMins.z <= v21 )
    {
      if ( v21 > v103 )
      {
        v23 = v21;
        v103 = v21;
      }
    }
    else
    {
      v22 = v21;
      vTraceMins.z = v21;
    }
    v24 = area->m_nwCorner.x;
    v25 = area->m_seCorner.y;
    v26 = area->m_swZ + 53.25;
    if ( v16 <= v24 )
    {
      if ( v24 > v20 )
      {
        v20 = area->m_nwCorner.x;
        *(float *)&v102 = v20;
      }
    }
    else
    {
      v16 = area->m_nwCorner.x;
      vTraceMins.x = v16;
    }
    if ( vTraceMins.y <= v25 )
    {
      if ( v25 > *((float *)&v102 + 1) )
        *((float *)&v102 + 1) = v25;
    }
    else
    {
      vTraceMins.y = v25;
    }
    if ( v22 <= v26 )
    {
      if ( v26 > v23 )
      {
        v23 = v26;
        v103 = v26;
      }
    }
    else
    {
      v22 = v26;
      vTraceMins.z = v26;
    }
    v27 = area->m_seCorner.z;
    *(_QWORD *)&vThisSE.x = *(_QWORD *)&area->m_seCorner.x;
    vThisSE.z = v27;
    v28 = v27 + 53.25;
    if ( v16 <= vThisSE.x )
    {
      if ( vThisSE.x > v20 )
        *(float *)&v102 = vThisSE.x;
    }
    else
    {
      vTraceMins.x = vThisSE.x;
    }
    if ( vTraceMins.y <= vThisSE.y )
    {
      if ( vThisSE.y > *((float *)&v102 + 1) )
        HIDWORD(v102) = LODWORD(vThisSE.y);
    }
    else
    {
      vTraceMins.y = vThisSE.y;
    }
    if ( v22 <= v28 )
    {
      if ( v28 > v23 )
        v103 = v27 + 53.25;
    }
    else
    {
      vTraceMins.z = v27 + 53.25;
    }
    if ( !engine->CheckBoxInPVS(this: engine, a2: &vTraceMins, a3: (const Vector *)&v102, a4: m_PVS, a5: m_nPVSSize) )
    {
      if ( pOutsidePVS != nullptr )
        *pOutsidePVS = true;
      return NOT_VISIBLE;
    }
    if ( pOutsidePVS != nullptr )
      *pOutsidePVS = false;
  }
  v30 = this->m_nwCorner.z;
  v31 = this->m_seCorner.z;
  v32 = this->m_center.z;
  v33 = this->m_center.x;
  v34 = this->m_neZ + 53.25;
  m_swZ = this->m_swZ;
  *(_QWORD *)&vThisSE.x = *(_QWORD *)&this->m_nwCorner.x;
  *(_QWORD *)&eyeToCenter.x = *(_QWORD *)&vThisSE.x;
  v36 = m_swZ + 53.25;
  *(_QWORD *)&vThisSE.x = *(_QWORD *)&this->m_seCorner.x;
  v37 = v30 + 53.25;
  vThisSE.z = v31;
  v102 = *(_QWORD *)&vThisSE.x;
  v38 = v31 + 53.25;
  v39 = v32 + 53.25;
  eyeToCenter.z = v30 + 53.25;
  v40 = this->m_center.y;
  v103 = v31 + 53.25;
  *(_QWORD *)&vThisCenter.x = *(_QWORD *)&eyeToCenter.x;
  testPos.x = v33;
  testPos.y = v40;
  testPos.z = v39;
  vThisCenter.z = v30 + 53.25;
  vThisSE.z = v31 + 53.25;
  if ( v34 <= (float)(v30 + 53.25) )
    v41 = v34;
  else
    v41 = v30 + 53.25;
  if ( v38 <= v41 )
  {
    v42 = v31 + 53.25;
  }
  else if ( v34 <= v37 )
  {
    v42 = v34;
  }
  else
  {
    v42 = v30 + 53.25;
  }
  if ( v36 <= v42 )
  {
    v44 = v36;
  }
  else
  {
    if ( v34 <= v37 )
      v43 = v34;
    else
      v43 = v30 + 53.25;
    if ( v38 <= v43 )
    {
      v44 = v31 + 53.25;
    }
    else if ( v34 <= v37 )
    {
      v44 = v34;
    }
    else
    {
      v44 = v30 + 53.25;
    }
  }
  if ( v37 <= v34 )
    v45 = v34;
  else
    v45 = v30 + 53.25;
  if ( v45 <= v38 )
  {
    v46 = v31 + 53.25;
  }
  else if ( v37 <= v34 )
  {
    v46 = v34;
  }
  else
  {
    v46 = v30 + 53.25;
  }
  if ( v46 <= v36 )
  {
    v37 = v36;
  }
  else
  {
    if ( v37 <= v34 )
      v47 = v34;
    else
      v47 = v30 + 53.25;
    if ( v47 <= v38 )
    {
      v37 = v31 + 53.25;
    }
    else if ( v37 <= v34 )
    {
      v37 = v34;
    }
  }
  v48 = area->m_nwCorner.z;
  v49 = area->m_seCorner.z;
  vThisCenter.x = vThisCenter.x - v33;
  vThisCenter.y = vThisCenter.y - testPos.y;
  v50 = v37 + 0.1;
  vOtherMaxs.z = v48;
  v92.z = v49;
  vThisSE.z = v50 - v39;
  v51 = *(_QWORD *)&area->m_nwCorner.x;
  vThisSE.x = vThisSE.x - v33;
  *(_QWORD *)&vOtherMaxs.x = v51;
  v52 = *(_QWORD *)&area->m_seCorner.x;
  vThisCenter.z = v44 - v39;
  vThisSE.y = vThisSE.y - testPos.y;
  *(_QWORD *)&v92.x = v52;
  CalcClosestPointOnAABB(mins: &vOtherMaxs, maxs: &v92, point: &testPos, closestOut: (Vector *)&vOtherMins.z);
  distanceSq = CNavArea::GetZ(this: area, x: vOtherMins.z, y: angleTolerance) + 53.25;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&tr.m_pEnt,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  v81 = angleTolerance - testPos.y;
  v80 = vOtherMins.z - testPos.x;
  v82 = distanceSq - testPos.z;
  tr.m_pEnt = (CBaseEntity *)&CTraceFilterNoNPCsOrPlayer::`vftable';
  v89 = 0;
  v91 = (float)((float)((float)(v81 * v81) + (float)(v80 * v80)) + (float)(v82 * v82)) != 0.0;
  v86 = (float)(vThisSE.x - vThisCenter.x) * 0.5;
  v87 = (float)(vThisSE.y - vThisCenter.y) * 0.5;
  v88 = (float)(vThisSE.z - vThisCenter.z) * 0.5;
  v90 = (float)((float)((float)(v87 * v87) + (float)(v86 * v86)) + (float)(v88 * v88)) < 0.000001;
  v53 = (float)(vThisSE.x + vThisCenter.x) * 0.5;
  v54 = (float)(vThisSE.y + vThisCenter.y) * 0.5;
  *(float *)&v52 = 0.5 * (float)(vThisSE.z + vThisCenter.z);
  *(float *)&traceFilter.m_pPassEnt = v53 + testPos.x;
  *(float *)&traceFilter.m_pExtraShouldHitCheckFunction = testPos.z + *(float *)&v52;
  *(float *)&traceFilter.m_collisionGroup = testPos.y + v54;
  v83 = v53 * -1.0;
  v84 = v54 * -1.0;
  v85 = *(float *)&v52 * -1.0;
  enginetrace->TraceRay(
    this: enginetrace,
    a2: (const Ray_t *)&traceFilter.m_pPassEnt,
    a3: 33579073u,
    a4: (ITraceFilter *)&tr.m_pEnt,
    a5: (CGameTrace *)&v77);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v77, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  if ( tr.plane.normal.z == 1.0
    || tr.startpos.x > vOtherMaxs.x && v92.x > tr.startpos.x && tr.startpos.y > vOtherMaxs.y && v92.y > tr.startpos.y )
  {
    return COMPLETELY_VISIBLE;
  }
  IsPartiallyVisible = area->IsPartiallyVisible;
  v102 = *(_QWORD *)&this->m_center.x;
  v103 = this->m_center.z + 53.25;
  v56 = IsPartiallyVisible(this: area, a2: (const Vector *)&v102, a3: nullptr);
  vTarget.x = this->m_center.x - area->m_center.x;
  v57 = this->m_center.y - area->m_center.y;
  HIBYTE(eyeToCorner.x) = v56 ? 3 : 0;
  vTarget.y = v57;
  vTarget.z = this->m_center.z - area->m_center.z;
  VectorNormalize(vec: &vTarget);
  vOtherMins.x = nav_potentially_visible_dot_tolerance.m_pParent->m_Value.m_fValue;
  v58 = (float)(this->m_seCorner.y - this->m_nwCorner.y) - 12.5;
  v59 = 12.5;
  vThisCenter.y = 12.5;
  if ( v58 < 12.5 )
    return HIBYTE(eyeToCorner.x);
  while ( 1 )
  {
    v60 = this->m_nwCorner.x;
    v61 = (float)(this->m_seCorner.x - v60) - 12.5;
    v62 = 12.5;
    vThisCenter.x = 12.5;
    if ( v61 >= 12.5 )
      break;
LABEL_124:
    v59 = v59 + 25.0;
    v76 = (float)(this->m_seCorner.y - this->m_nwCorner.y) - 12.5;
    vThisCenter.y = v59;
    if ( v76 < v59 )
      return HIBYTE(eyeToCorner.x);
  }
  while ( 1 )
  {
    result = POTENTIALLY_VISIBLE;
    if ( HIBYTE(eyeToCorner.x) == 1 )
      return result;
    v63 = this->m_nwCorner.z;
    v102 = *(_QWORD *)&this->m_nwCorner.x;
    v64 = *(float *)&v102 + v62;
    v65 = *((float *)&v102 + 1) + v59;
    m_invDxCorners = this->m_invDxCorners;
    v103 = v63;
    eyeToCenter.x = *(float *)&v102 + v62;
    eyeToCenter.y = v65;
    if ( m_invDxCorners == 0.0 || (m_invDyCorners = this->m_invDyCorners) == 0.0 )
    {
      m_neZ = this->m_neZ;
    }
    else
    {
      v68 = (float)(v64 - v60) * m_invDxCorners;
      v69 = (float)(v65 - this->m_nwCorner.y) * m_invDyCorners;
      if ( v68 < 0.0 )
        v68 = 0.0;
      if ( (float)(v68 - 1.0) >= 0.0 )
        v68 = 1.0;
      if ( v69 < 0.0 )
        v69 = 0.0;
      if ( (float)(v69 - 1.0) >= 0.0 )
        v69 = 1.0;
      v70 = (float)((float)(this->m_neZ - this->m_nwCorner.z) * v68) + this->m_nwCorner.z;
      m_neZ = (float)((float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v68) + this->m_swZ) - v70)
                    * v69)
            + v70;
    }
    v72 = m_neZ + 53.25;
    eyeToCenter.z = v72;
    if ( vOtherMins.y <= 1000000.0
      || (v73 = v65 - this->m_center.y,
          v74 = v72 - (float)(this->m_center.z + 53.25),
          vThisSE.x = v64 - this->m_center.x,
          vThisSE.y = v73,
          VectorNormalize(vec: (Vector *)LODWORD(v74)),
          (float)((float)((float)(vThisSE.x * vTarget.x) + (float)(vThisSE.y * vTarget.y))
                + (float)(vThisSE.z * vTarget.z)) < vOtherMins.x) )
    {
      if ( area->IsPartiallyVisible(this: area, a2: &eyeToCenter, a3: nullptr) )
        HIBYTE(eyeToCorner.x) |= 1u;
      else
        HIBYTE(eyeToCorner.x) &= ~2u;
    }
    v60 = this->m_nwCorner.x;
    v62 = vThisCenter.x + 25.0;
    v75 = (float)((float)(this->m_seCorner.x - v60) - 12.5) < (float)(vThisCenter.x + 25.0);
    v59 = vThisCenter.y;
    vThisCenter.x = vThisCenter.x + 25.0;
    if ( v75 )
      goto LABEL_124;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FA7C0
// Name: public: virtual bool CNavArea::IsEntirelyVisible(class Vector const __near &,class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNavArea::IsEntirelyVisible@<al>(
        CNavArea *this@<ecx>,
        int a2@<esi>,
        const Vector *eye,
        CBaseEntity *ignore)
{
  float v5; // xmm0_4
  NavCornerType v7; // esi
  Vector *Corner; // eax
  float y; // xmm2_4
  float v10; // xmm0_4
  CGameTrace v11; // [esp+8h] [ebp-7Ch] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+5Ch] [ebp-28h] BYREF
  Vector v13; // [esp+6Ch] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+78h] [ebp-Ch] BYREF
  int savedregs; // [esp+84h] [ebp+0h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: ignore,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  vecAbsEnd.x = this->m_center.x;
  vecAbsEnd.y = this->m_center.y;
  v5 = this->m_center.z + 53.25;
  traceFilter.__vftable = (CTraceFilterNoNPCsOrPlayer_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable';
  vecAbsEnd.z = v5;
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2,
    vecAbsStart: eye,
    &vecAbsEnd,
    mask: 0x2006041u,
    pFilter: &traceFilter,
    ptr: &v11);
  if ( v11.fraction < 1.0 )
    return 0;
  v7 = NORTH_WEST;
  while ( 1 )
  {
    Corner = CNavArea::GetCorner(this, result: &v13, corner: v7);
    y = Corner->y;
    v10 = Corner->z + 53.25;
    vecAbsEnd.x = Corner->x;
    vecAbsEnd.y = y;
    vecAbsEnd.z = v10;
    UTIL_TraceLine(
      a1: (int)&savedregs,
      a2: v7,
      vecAbsStart: eye,
      &vecAbsEnd,
      mask: 0x2006041u,
      pFilter: &traceFilter,
      ptr: &v11);
    if ( v11.fraction < 1.0 )
      break;
    if ( ++v7 >= NUM_CORNERS )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102FA8C0
// Name: public: virtual bool CNavArea::IsPartiallyVisible(class Vector const __near &,class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsPartiallyVisible(CNavArea *this, const Vector *eye, CBaseEntity *ignore)
{
  float v4; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  NavCornerType v8; // ebx
  Vector *Corner; // eax
  float y; // xmm2_4
  float z; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  CGameTrace v15; // [esp+8h] [ebp-A0h] BYREF
  Vector v16; // [esp+5Ch] [ebp-4Ch] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+68h] [ebp-40h] BYREF
  Vector v18; // [esp+78h] [ebp-30h] BYREF
  Vector eyeToCorner; // [esp+84h] [ebp-24h] BYREF
  Vector eyeToCenter; // [esp+90h] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+9Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+A8h] [ebp+0h] BYREF
  float angleTolerance; // [esp+B4h] [ebp+Ch]

  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: ignore,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  vecAbsEnd.x = this->m_center.x;
  vecAbsEnd.y = this->m_center.y;
  v4 = this->m_center.z + 53.25;
  traceFilter.__vftable = (CTraceFilterNoNPCsOrPlayer_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable';
  vecAbsEnd.z = v4;
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)eye,
    vecAbsStart: eye,
    &vecAbsEnd,
    mask: 0x2006041u,
    pFilter: &traceFilter,
    ptr: &v15);
  if ( v15.fraction >= 1.0 )
    return 1;
  v6 = this->m_center.y - eye->y;
  v7 = (float)(this->m_center.z + 53.25) - eye->z;
  eyeToCenter.x = this->m_center.x - eye->x;
  eyeToCenter.y = v6;
  eyeToCenter.z = v7;
  VectorNormalize(vec: &eyeToCenter);
  angleTolerance = nav_potentially_visible_dot_tolerance.m_pParent->m_Value.m_fValue;
  v8 = NORTH_WEST;
  while ( 1 )
  {
    Corner = CNavArea::GetCorner(this, result: &v16, corner: v8);
    y = Corner->y;
    z = Corner->z;
    vecAbsEnd.x = Corner->x;
    v12 = vecAbsEnd.x - eye->x;
    vecAbsEnd.y = y;
    v13 = y - eye->y;
    vecAbsEnd.z = z + 53.25;
    v14 = (float)(z + 53.25) - eye->z;
    eyeToCorner.x = v12;
    eyeToCorner.y = v13;
    eyeToCorner.z = v14;
    VectorNormalize(vec: &eyeToCorner);
    if ( (float)((float)((float)(eyeToCorner.y * eyeToCenter.y) + (float)(eyeToCorner.x * eyeToCenter.x))
               + (float)(eyeToCorner.z * eyeToCenter.z)) < angleTolerance )
    {
      v18.x = vecAbsEnd.x;
      v18.y = vecAbsEnd.y;
      v18.z = vecAbsEnd.z + 53.25;
      UTIL_TraceLine(
        a1: (int)&savedregs,
        a2: (int)eye,
        vecAbsStart: eye,
        vecAbsEnd: &v18,
        mask: 0x2006041u,
        pFilter: &traceFilter,
        ptr: &v15);
      if ( v15.fraction >= 1.0 )
        break;
    }
    if ( ++v8 >= NUM_CORNERS )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FAA90
// Name: public: void CUtlVectorUltraConservative<class HidingSpot __near *,class CUtlVectorUltraConservativeAllocator>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::PurgeAndDeleteElements(
        CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator> *this)
{
  int i; // edi
  HidingSpot *v3; // ecx

  if ( this->m_pData != (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    for ( i = 0; i < this->m_pData->m_Size; ++i )
    {
      v3 = this->m_pData->m_Elements[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(HidingSpot *, int))v3->dtr_HidingSpot)(a1: v3, a2: 1);
    }
    if ( this->m_pData != (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: this->m_pData);
      this->m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FAAE0
// Name: public: void CUtlVectorUltraConservative<struct NavConnect,class CUtlVectorUltraConservativeAllocator>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Remove(
        CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *this,
        int elem)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx

  m_pData = this->m_pData;
  if ( m_pData->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &m_pData->m_Elements[elem],
      src: &m_pData->m_Elements[elem + 1],
      count: 8 * (m_pData->m_Size - elem - 1));
  if ( --this->m_pData->m_Size == 0 )
  {
    free(pMem: this->m_pData);
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    this->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FAC50
// Name: public: virtual void CNavArea::OnServerActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::OnServerActivate(CNavArea *this)
{
  this->m_attributeFlags &= ~0x40000000u;
  this->m_elevator = nullptr;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  if ( this->m_elevatorAreas.m_pData != (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: this->m_elevatorAreas.m_pData);
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    this->m_elevatorAreas.m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
  this->m_damagingTickCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102FACB0
// Name: public: virtual void CNavArea::OnDestroyNotify(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::OnDestroyNotify(CNavArea *this, CNavArea *dead)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_incomingConnect; // esi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // edx
  int m_Size; // ecx
  int v5; // eax
  CNavArea **m_Elements; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v7; // edx
  int *p_m_Size; // edi
  int v9; // eax
  int v10; // ecx
  CNavArea **v11; // edx
  int v12; // eax
  int i; // [esp+Ch] [ebp-4h]

  m_incomingConnect = this->m_incomingConnect;
  for ( i = 4; i != 0; --i )
  {
    m_pData = m_incomingConnect[-37].m_pData;
    m_Size = m_pData->m_Size;
    v5 = 0;
    if ( m_pData->m_Size > 0 )
    {
      m_Elements = (CNavArea **)m_pData->m_Elements;
      while ( *m_Elements != dead )
      {
        ++v5;
        m_Elements += 2;
        if ( v5 >= m_Size )
          goto LABEL_14;
      }
      if ( v5 != -1 )
      {
        v7 = m_incomingConnect[-37].m_pData;
        if ( v7->m_Size - v5 - 1 > 0 )
          _V_memmove(dest: &v7->m_Elements[v5], src: &v7->m_Elements[v5 + 1], count: 8 * (v7->m_Size - v5 - 1));
        if ( --m_incomingConnect[-37].m_pData->m_Size == 0 )
        {
          free(pMem: m_incomingConnect[-37].m_pData);
          if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
              & 1) == 0 )
            `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
          m_incomingConnect[-37].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
        }
      }
    }
LABEL_14:
    p_m_Size = &m_incomingConnect->m_pData->m_Size;
    v9 = m_incomingConnect->m_pData->m_Size;
    v10 = 0;
    if ( v9 > 0 )
    {
      v11 = (CNavArea **)(p_m_Size + 1);
      while ( *v11 != dead )
      {
        ++v10;
        v11 += 2;
        if ( v10 >= v9 )
          goto LABEL_26;
      }
      if ( v10 != -1 )
      {
        v12 = v9 - v10 - 1;
        if ( v12 > 0 )
          _V_memmove(dest: &p_m_Size[2 * v10 + 1], src: &p_m_Size[2 * v10 + 3], count: 8 * v12);
        if ( --m_incomingConnect->m_pData->m_Size == 0 )
        {
          free(pMem: m_incomingConnect->m_pData);
          if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
              & 1) == 0 )
            `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
          m_incomingConnect->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
        }
      }
    }
LABEL_26:
    ++m_incomingConnect;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FADE0
// Name: public: void CNavArea::Disconnect(class CNavLadder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Disconnect(CNavArea *this, CNavLadder *ladder)
{
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // esi
  int *p_m_Size; // edi
  int m_Size; // eax
  int v5; // ecx
  CNavLadder **v6; // edx
  int v7; // eax
  int i; // [esp+Ch] [ebp-4h]

  m_ladder = this->m_ladder;
  for ( i = 2; i != 0; --i )
  {
    p_m_Size = &m_ladder->m_pData->m_Size;
    m_Size = m_ladder->m_pData->m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      v6 = (CNavLadder **)(p_m_Size + 1);
      while ( *v6 != ladder )
      {
        ++v5;
        ++v6;
        if ( v5 >= m_Size )
          goto LABEL_12;
      }
      if ( v5 != -1 )
      {
        v7 = m_Size - v5 - 1;
        if ( v7 > 0 )
          _V_memmove(dest: &p_m_Size[v5 + 1], src: &p_m_Size[v5 + 2], count: 4 * v7);
        if ( --m_ladder->m_pData->m_Size == 0 )
        {
          free(pMem: m_ladder->m_pData);
          m_ladder->m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
        }
      }
    }
LABEL_12:
    ++m_ladder;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FAE60
// Name: public: void CNavArea::AddLadderUp(class CNavLadder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::AddLadderUp(CNavArea *this, CNavLadder *ladder)
{
  CNavLadder *v2; // edi

  v2 = ladder;
  CNavArea::Disconnect(this, ladder);
  ladder = v2;
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::AddToTail(
    this: this->m_ladder,
    src: (const NavLadderConnect *)&ladder);
}

//------------------------------------------------------------------------------
// Address: 0x102FAE90
// Name: public: void CNavArea::AddLadderDown(class CNavLadder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::AddLadderDown(CNavArea *this, CNavLadder *ladder)
{
  CNavLadder *v2; // edi

  v2 = ladder;
  CNavArea::Disconnect(this, ladder);
  ladder = v2;
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::AddToTail(
    this: &this->m_ladder[1],
    src: (const NavLadderConnect *)&ladder);
}

//------------------------------------------------------------------------------
// Address: 0x102FAED0
// Name: public: virtual void CNavArea::Draw(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Draw(CNavArea *this)
{
  unsigned int m_place; // eax
  NavEditColor v3; // ebx
  double v4; // st7
  const char *v5; // eax
  float v6; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float x; // xmm2_4
  float m_neZ; // xmm1_4
  float m_swZ; // xmm0_4
  NavCornerType i; // edi
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  char *m_pszString; // eax
  int v24; // eax
  int v25; // edi
  int v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  bool v31; // zf
  NavCornerType CornerUnderCursor; // eax
  int m_attributeFlags; // eax
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm3_4
  float v42; // eax
  float v43; // xmm3_4
  float v44; // ecx
  float v45; // xmm1_4
  __int64 v46; // xmm5_8
  __int64 v47; // xmm4_8
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm7_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm5_4
  float v56; // xmm0_4
  float v57; // xmm3_4
  float v58; // xmm1_4
  float v59; // xmm3_4
  float v60; // xmm2_4
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm3_4
  float v65; // xmm1_4
  float v66; // xmm1_4
  float m_invDxCorners; // xmm6_4
  float v68; // xmm5_4
  float m_invDyCorners; // xmm0_4
  float v70; // xmm2_4
  float v71; // xmm5_4
  float v72; // xmm0_4
  float v73; // xmm3_4
  float v74; // xmm1_4
  float v75; // xmm1_4
  float v76; // xmm3_4
  float v77; // xmm2_4
  float v78; // xmm1_4
  float v79; // xmm3_4
  float v80; // xmm3_4
  float v81; // xmm2_4
  float v82; // xmm4_4
  float v83; // xmm2_4
  float v84; // xmm3_4
  float v85; // xmm3_4
  float v86; // xmm2_4
  float v87; // xmm4_4
  float v88; // xmm2_4
  float v89; // xmm3_4
  float v90; // xmm1_4
  float v91; // xmm3_4
  float v92; // xmm2_4
  float v93; // xmm4_4
  float v94; // xmm2_4
  float v95; // xmm3_4
  float v96; // xmm1_4
  float v97; // xmm3_4
  float v98; // xmm2_4
  float v99; // xmm4_4
  float v100; // xmm2_4
  float v101; // xmm3_4
  float v102; // xmm0_4
  float v103; // xmm4_4
  float v104; // xmm0_4
  float v105; // xmm4_4
  float v106; // xmm0_4
  float v107; // xmm2_4
  float v108; // xmm0_4
  float v109; // xmm1_4
  float v110; // xmm2_4
  float v111; // xmm3_4
  float v112; // xmm0_4
  NavEditColor v113; // esi
  unsigned int m_id; // [esp+0h] [ebp-C8h]
  Vector p[4]; // [esp+18h] [ebp-B0h] BYREF
  float v116; // [esp+48h] [ebp-80h]
  float y; // [esp+4Ch] [ebp-7Ch]
  int bgcolor[4]; // [esp+50h] [ebp-78h] BYREF
  Vector ne; // [esp+60h] [ebp-68h] BYREF
  Vector sw; // [esp+6Ch] [ebp-5Ch] BYREF
  Vector nw; // [esp+78h] [ebp-50h] BYREF
  Vector se; // [esp+84h] [ebp-44h] BYREF
  float t; // [esp+90h] [ebp-38h]
  Vector end; // [esp+94h] [ebp-34h] BYREF
  Vector up; // [esp+A0h] [ebp-28h] BYREF
  Vector start; // [esp+ACh] [ebp-1Ch] BYREF
  Vector down; // [esp+B8h] [ebp-10h] BYREF
  bool useAttributeColors; // [esp+C7h] [ebp-1h]
  int savedregs; // [esp+C8h] [ebp+0h] BYREF

  useAttributeColors = true;
  if ( TheNavMesh->m_editMode == PLACE_PAINTING )
  {
    m_place = this->m_place;
    useAttributeColors = false;
    if ( m_place != 0 )
      v3 = (TheNavMesh->m_navPlace != m_place) + 2;
    else
      v3 = NavNoPlaceColor;
  }
  else if ( this == CNavMesh::GetMarkedArea(this: TheNavMesh) )
  {
    useAttributeColors = false;
    v3 = NavMarkedColor;
  }
  else
  {
    v3 = 2 * (this != TheNavMesh->m_selectedArea) + 5;
  }
  if ( this->m_nwCorner.x >= this->m_seCorner.x || this->m_nwCorner.y >= this->m_seCorner.y )
  {
    if ( (_S2_306 & 1) == 0 )
    {
      _S2_306 |= 1u;
      blink.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
      blink.m_timestamp.m_Value = -1.0;
      CNavMesh::SaveCustomData(this: (vgui::TreeView *)&blink, itemIndex: (int)&blink.m_timestamp);
    }
    if ( blink.m_timestamp.m_Value <= 0.0
      || (t = IntervalTimer::Now(this: (CEffectsServer *)&blink) - blink.m_timestamp.m_Value) > 1.0 )
    {
      v4 = IntervalTimer::Now(this: (CEffectsServer *)&blink);
      t = v4;
      if ( blink.m_timestamp.m_Value != v4 )
      {
        blink.NetworkStateChanged(this: &blink, a2: &blink.m_timestamp);
        blink.m_timestamp.m_Value = t;
      }
      blinkOn = !blinkOn;
    }
    m_id = this->m_id;
    useAttributeColors = false;
    v3 = !blinkOn;
    v5 = UTIL_VarArgs(format: "Degenerate area %d", m_id);
    NDebugOverlay::Text(origin: &this->m_center, text: v5, bViewCheck: true, duration: 0.01023);
  }
  v6 = this->m_nwCorner.y;
  z = this->m_nwCorner.z;
  v8 = this->m_seCorner.y;
  v9 = this->m_seCorner.z;
  nw.x = this->m_nwCorner.x;
  nw.y = v6;
  nw.z = z;
  x = this->m_seCorner.x;
  ne.y = v6;
  m_neZ = this->m_neZ;
  sw.x = nw.x;
  m_swZ = this->m_swZ;
  se.x = x;
  se.y = v8;
  se.z = v9;
  ne.x = x;
  ne.z = m_neZ;
  sw.y = v8;
  sw.z = m_swZ;
  if ( nav_show_light_intensity.m_pParent != nullptr && nav_show_light_intensity.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = NORTH_WEST; i < NUM_CORNERS; ++i )
    {
      CNavArea::GetCorner(this, result: &start, corner: i);
      v14 = start.x;
      *(_QWORD *)&down.x = *(_QWORD *)&start.x;
      v15 = this->m_nwCorner.x;
      down.z = start.z;
      if ( v15 > start.x || (v15 = this->m_seCorner.x, start.x > v15) )
        v14 = v15;
      v16 = this->m_nwCorner.y;
      if ( v16 <= start.y )
      {
        v16 = this->m_seCorner.y;
        if ( start.y <= v16 )
          v16 = start.y;
      }
      v17 = (float)(v14 - this->m_nwCorner.x) / (float)(this->m_seCorner.x - this->m_nwCorner.x);
      v18 = (float)(v16 - this->m_nwCorner.y) / (float)(this->m_seCorner.y - this->m_nwCorner.y);
      v19 = (float)(1.0 - v17) * this->m_lightIntensity[0];
      v20 = (float)((float)(this->m_lightIntensity[3] * (float)(1.0 - v17)) + (float)(v17 * this->m_lightIntensity[2]))
          * v18;
      v21 = (float)((float)((float)((float)(v17 * this->m_lightIntensity[1]) + v19) * (float)(1.0 - v18)) + v20) * 255.0;
      down.z = (float)((float)((float)((float)((float)(v17 * this->m_lightIntensity[1]) + v19) * (float)(1.0 - v18))
                             + v20)
                     * 71.0)
             + start.z;
      v22 = 192.0;
      if ( v21 >= 192.0 )
        v22 = v21;
      NDebugOverlay::Line(
        origin: &down,
        target: &start,
        r: (int)v21,
        g: (int)v21,
        b: (int)v22,
        noDepthTest: true,
        duration: 0.01023);
    }
  }
  if ( (nav_area_bgcolor.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = nav_area_bgcolor.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  if ( sscanf(string: m_pszString, format: "%d %d %d %d", bgcolor, &bgcolor[1], &bgcolor[2], &bgcolor[3]) == 4 )
  {
    v24 = bgcolor[0];
    if ( bgcolor[0] >= 0 )
    {
      if ( bgcolor[0] > 255 )
        v24 = 255;
    }
    else
    {
      v24 = 0;
    }
    v25 = v24;
    v26 = bgcolor[1];
    bgcolor[0] = v25;
    if ( bgcolor[1] >= 0 )
    {
      if ( bgcolor[1] > 255 )
        v26 = 255;
    }
    else
    {
      v26 = 0;
    }
    v27 = v26;
    v28 = bgcolor[2];
    bgcolor[1] = v27;
    if ( bgcolor[2] >= 0 )
    {
      if ( bgcolor[2] > 255 )
        v28 = 255;
    }
    else
    {
      v28 = 0;
    }
    v29 = v28;
    v30 = bgcolor[3];
    bgcolor[2] = v29;
    if ( bgcolor[3] >= 0 )
    {
      if ( bgcolor[3] > 255 )
        v30 = 255;
    }
    else
    {
      v30 = 0;
    }
    bgcolor[3] = v30;
    if ( v30 > 0 )
    {
      down.x = ne.x;
      down.y = ne.y;
      down.z = ne.z + 0.80000001;
      up.x = se.x;
      up.y = se.y;
      up.z = se.z + 0.80000001;
      start.x = nw.x;
      start.y = nw.y;
      start.z = nw.z + 0.80000001;
      NDebugOverlay::Triangle(
        p1: &start,
        p2: &up,
        p3: &down,
        r: v25,
        g: v27,
        b: v29,
        a: v30,
        noDepthTest: true,
        duration: 0.01023);
      down.x = sw.x;
      down.y = sw.y;
      down.z = sw.z + 0.80000001;
      up.x = nw.x;
      up.y = nw.y;
      up.z = nw.z + 0.80000001;
      start.x = se.x;
      start.y = se.y;
      start.z = se.z + 0.80000001;
      NDebugOverlay::Triangle(
        p1: &start,
        p2: &up,
        p3: &down,
        r: bgcolor[0],
        g: bgcolor[1],
        b: bgcolor[2],
        a: bgcolor[3],
        noDepthTest: true,
        duration: 0.01023);
    }
  }
  v31 = (this->m_attributeFlags & 0x100) == 0;
  nw.x = nw.x + 0.2;
  nw.y = nw.y + 0.2;
  ne.x = ne.x - 0.2;
  ne.y = ne.y + 0.2;
  sw.x = sw.x + 0.2;
  sw.y = sw.y - 0.2;
  se.x = se.x - 0.2;
  se.y = se.y - 0.2;
  if ( v31 )
  {
    NavDrawLine(from: &nw, to: &ne, navColor: v3);
    NavDrawLine(from: &ne, to: &se, navColor: v3);
    NavDrawLine(from: &se, to: &sw, navColor: v3);
    NavDrawLine(from: &sw, to: &nw, navColor: v3);
  }
  else
  {
    NavDrawDashedLine(from: &nw, to: &ne, navColor: v3);
    NavDrawDashedLine(from: &ne, to: &se, navColor: v3);
    NavDrawDashedLine(from: &se, to: &sw, navColor: v3);
    NavDrawDashedLine(from: &sw, to: &nw, navColor: v3);
  }
  if ( this == CNavMesh::GetMarkedArea(this: TheNavMesh) && TheNavMesh->m_markedCorner != NUM_CORNERS )
  {
    CNavArea::GetCornerHotspot(this, a2: COERCE_FLOAT(&savedregs), corner: TheNavMesh->m_markedCorner, hotspot: p);
    NavDrawLine(from: &p[1], to: &p[2], navColor: NavMarkedColor);
    NavDrawLine(from: &p[2], to: &p[3], navColor: NavMarkedColor);
  }
  if ( this != CNavMesh::GetMarkedArea(this: TheNavMesh)
    && this == TheNavMesh->m_selectedArea
    && TheNavMesh->m_editMode == 0 )
  {
    CornerUnderCursor = CNavArea::GetCornerUnderCursor(this);
    if ( CNavArea::GetCornerHotspot(this, a2: COERCE_FLOAT(&savedregs), corner: CornerUnderCursor, hotspot: p) )
    {
      NavDrawLine(from: &p[1], to: &p[2], navColor: NavSelectedColor);
      NavDrawLine(from: &p[2], to: &p[3], navColor: NavSelectedColor);
    }
  }
  if ( (this->m_attributeFlags & 1) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeCrouchColor;
    NavDrawLine(from: &nw, to: &se, navColor: v3);
  }
  m_attributeFlags = this->m_attributeFlags;
  if ( (m_attributeFlags & 2) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeJumpColor;
    if ( (m_attributeFlags & 1) == 0 )
      NavDrawLine(from: &nw, to: &se, navColor: v3);
    NavDrawLine(from: &ne, to: &sw, navColor: v3);
  }
  if ( (this->m_attributeFlags & 4) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributePreciseColor;
    v34 = this->m_center.y;
    v35 = this->m_center.x;
    up.y = v34 - 8.0;
    v36 = this->m_center.z;
    up.x = v35;
    up.z = v36;
    down.x = v35;
    down.y = v34 + 8.0;
    down.z = v36;
    NavDrawLine(from: &up, to: &down, navColor: v3);
    v37 = this->m_center.x;
    v38 = this->m_center.z;
    end.x = v37 - 8.0;
    end.y = this->m_center.y;
    end.z = v38;
    start.x = v37 + 8.0;
    start.y = end.y;
    start.z = v38;
    NavDrawLine(from: &end, to: &start, navColor: v3);
  }
  if ( (this->m_attributeFlags & 8) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeNoJumpColor;
    v39 = this->m_center.y;
    v40 = this->m_center.x;
    end.y = v39 + 8.0;
    up.x = v40;
    up.y = v39 - 8.0;
    v41 = this->m_center.z;
    end.x = v40;
    up.z = v41;
    end.z = v41;
    down.x = v40 - 8.0;
    down.y = v39;
    down.z = v41;
    start.x = v40 + 8.0;
    start.y = v39;
    start.z = v41;
    NavDrawLine(from: &up, to: &start, navColor: v3);
    NavDrawLine(from: &start, to: &end, navColor: v3);
    NavDrawLine(from: &end, to: &down, navColor: v3);
    NavDrawLine(from: &down, to: &up, navColor: v3);
  }
  if ( (this->m_attributeFlags & 0x1000) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeStairColor;
    v43 = this->m_neZ;
    v44 = this->m_seCorner.z;
    v45 = this->m_swZ;
    v46 = *(_QWORD *)&this->m_seCorner.x;
    v47 = v46;
    down.z = this->m_nwCorner.z;
    v42 = down.z;
    v48 = v43 + down.z;
    down.z = v44;
    *(_QWORD *)&down.x = v46;
    *(float *)&v46 = (float)(v45 + v44) * 0.5;
    *(_QWORD *)&down.x = *(_QWORD *)&this->m_nwCorner.x;
    v49 = this->m_swZ + v42;
    *(_QWORD *)&down.x = v47;
    down.z = v44;
    if ( fabs((float)(v49 * 0.5) - (float)((float)(v44 + v43) * 0.5)) <= fabs((float)(v48 * 0.5) - *(float *)&v46) )
    {
      v66 = 0.0;
      v116 = 9.0 / (float)(this->m_seCorner.y - this->m_nwCorner.y);
      t = 0.0;
      do
      {
        m_invDxCorners = this->m_invDxCorners;
        v68 = (float)((float)(this->m_seCorner.y - this->m_nwCorner.y) * v66) + this->m_nwCorner.y;
        y = v68;
        if ( m_invDxCorners == 0.0 || (m_invDyCorners = this->m_invDyCorners) == 0.0 )
        {
          v72 = this->m_neZ;
          v75 = v72;
        }
        else
        {
          v70 = (float)(this->m_seCorner.x - this->m_nwCorner.x) * m_invDxCorners;
          v71 = (float)(v68 - this->m_nwCorner.y) * m_invDyCorners;
          if ( v70 < 0.0 )
            v70 = 0.0;
          if ( (float)(v70 - 1.0) >= 0.0 )
            v70 = 1.0;
          if ( v71 < 0.0 )
            v71 = 0.0;
          if ( (float)(v71 - 1.0) >= 0.0 )
            v71 = 1.0;
          v72 = this->m_neZ;
          v73 = (float)((float)(v72 - this->m_nwCorner.z) * v70) + this->m_nwCorner.z;
          v74 = (float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v70) + this->m_swZ) - v73) * v71;
          v68 = y;
          v75 = v74 + v73;
        }
        down.x = this->m_seCorner.x;
        down.y = v68;
        down.z = v75;
        if ( m_invDxCorners != 0.0 )
        {
          v76 = this->m_invDyCorners;
          if ( v76 != 0.0 )
          {
            v77 = m_invDxCorners * 0.0;
            v78 = (float)(v68 - this->m_nwCorner.y) * v76;
            if ( (float)(m_invDxCorners * 0.0) < 0.0 )
              v77 = 0.0;
            if ( (float)(v77 - 1.0) >= 0.0 )
              v77 = 1.0;
            if ( v78 < 0.0 )
              v78 = 0.0;
            if ( (float)(v78 - 1.0) >= 0.0 )
              v78 = 1.0;
            v79 = this->m_nwCorner.z + (float)((float)(v72 - this->m_nwCorner.z) * v77);
            v72 = (float)((float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v77) + this->m_swZ) - v79)
                        * v78)
                + v79;
          }
        }
        up.x = this->m_nwCorner.x;
        up.y = v68;
        up.z = v72;
        NavDrawLine(from: &up, to: &down, navColor: v3);
        v66 = v116 + t;
        t = v116 + t;
      }
      while ( t <= 1.0 );
    }
    else
    {
      v50 = 0.0;
      y = 9.0 / (float)(this->m_seCorner.x - this->m_nwCorner.x);
      t = 0.0;
      do
      {
        v51 = this->m_invDxCorners;
        v52 = (float)((float)(this->m_seCorner.x - this->m_nwCorner.x) * v50) + this->m_nwCorner.x;
        if ( v51 == 0.0 || (v53 = this->m_invDyCorners) == 0.0 )
        {
          v56 = this->m_neZ;
          v58 = v56;
        }
        else
        {
          v54 = (float)(v52 - this->m_nwCorner.x) * v51;
          v55 = (float)(this->m_seCorner.y - this->m_nwCorner.y) * v53;
          if ( v54 < 0.0 )
            v54 = 0.0;
          if ( (float)(v54 - 1.0) >= 0.0 )
            v54 = 1.0;
          if ( v55 < 0.0 )
            v55 = 0.0;
          if ( (float)(v55 - 1.0) >= 0.0 )
            v55 = 1.0;
          v56 = this->m_neZ;
          v57 = (float)((float)(v56 - this->m_nwCorner.z) * v54) + this->m_nwCorner.z;
          v58 = (float)((float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v54) + this->m_swZ) - v57)
                      * v55)
              + v57;
        }
        v59 = this->m_invDxCorners;
        v60 = this->m_seCorner.y;
        down.x = v52;
        down.y = v60;
        down.z = v58;
        if ( v59 != 0.0 )
        {
          v61 = this->m_invDyCorners;
          if ( v61 != 0.0 )
          {
            v62 = (float)(v52 - this->m_nwCorner.x) * v59;
            v63 = v61 * 0.0;
            if ( v62 < 0.0 )
              v62 = 0.0;
            if ( (float)(v62 - 1.0) >= 0.0 )
              v62 = 1.0;
            if ( v63 < 0.0 )
              v63 = 0.0;
            if ( (float)(v63 - 1.0) >= 0.0 )
              v63 = 1.0;
            v64 = this->m_nwCorner.z + (float)((float)(v56 - this->m_nwCorner.z) * v62);
            v56 = (float)((float)((float)((float)((float)(this->m_seCorner.z - this->m_swZ) * v62) + this->m_swZ) - v64)
                        * v63)
                + v64;
          }
        }
        v65 = this->m_nwCorner.y;
        up.x = v52;
        up.y = v65;
        up.z = v56;
        NavDrawLine(from: &up, to: &down, navColor: v3);
        v50 = t + y;
        t = t + y;
      }
      while ( t <= 1.0 );
    }
  }
  if ( (this->m_attributeFlags & 0x10) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeStopColor;
    v80 = this->m_center.z;
    v81 = this->m_center.y;
    start.x = this->m_center.x + 8.0;
    start.y = v81 - 3.2;
    start.z = v80;
    end.x = start.x;
    end.y = v81 + 3.2;
    end.z = v80;
    NavDrawLine(from: &start, to: &end, navColor: v3);
    v82 = this->m_center.z;
    v83 = this->m_center.x;
    v84 = this->m_center.y;
    start.x = v83 + 8.0;
    start.y = v84 + 3.2;
    start.z = v82;
    end.x = v83 + 3.2;
    end.y = v84 + 8.0;
    end.z = v82;
    NavDrawLine(from: &start, to: &end, navColor: v3);
    v85 = this->m_center.z;
    v86 = this->m_center.y;
    start.x = this->m_center.x - 8.0;
    start.y = v86 - 3.2;
    start.z = v85;
    end.x = start.x;
    end.y = v86 + 3.2;
    end.z = v85;
    NavDrawLine(from: &start, to: &end, navColor: v3);
    v87 = this->m_center.z;
    v88 = this->m_center.x;
    v89 = this->m_center.y;
    start.x = v88 - 8.0;
    start.y = v89 + 3.2;
    start.z = v87;
    end.x = v88 - 3.2;
    end.y = v89 + 8.0;
    end.z = v87;
    NavDrawLine(from: &start, to: &end, navColor: v3);
    v90 = this->m_center.y + 8.0;
    v91 = this->m_center.z;
    v92 = this->m_center.x;
    start.x = v92 - 3.2;
    start.y = v90;
    start.z = v91;
    end.x = v92 + 3.2;
    end.y = v90;
    end.z = v91;
    NavDrawLine(from: &start, to: &end, navColor: v3);
    v93 = this->m_center.z;
    v94 = this->m_center.x;
    v95 = this->m_center.y;
    start.x = v94 - 8.0;
    start.y = v95 - 3.2;
    start.z = v93;
    end.x = v94 - 3.2;
    end.y = v95 - 8.0;
    end.z = v93;
    NavDrawLine(from: &start, to: &end, navColor: v3);
    v96 = this->m_center.y - 8.0;
    v97 = this->m_center.z;
    v98 = this->m_center.x;
    start.x = v98 - 3.2;
    start.y = v96;
    start.z = v97;
    end.x = v98 + 3.2;
    end.y = v96;
    end.z = v97;
    NavDrawLine(from: &start, to: &end, navColor: v3);
    v99 = this->m_center.z;
    v100 = this->m_center.x;
    v101 = this->m_center.y;
    start.x = v100 + 3.2;
    start.y = v101 - 8.0;
    start.z = v99;
    end.x = v100 + 8.0;
    end.y = v101 - 3.2;
    end.z = v99;
    NavDrawLine(from: &start, to: &end, navColor: v3);
  }
  if ( (this->m_attributeFlags & 0x40) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeWalkColor;
    v102 = this->m_center.x;
    v103 = this->m_center.z;
    down.x = v102 + 8.0;
    down.y = this->m_center.y;
    down.z = v103;
    up.x = v102 - 8.0;
    up.y = down.y;
    up.z = v103;
    NavDrawHorizontalArrow(from: &up, to: &down, width: 4.0, navColor: v3);
  }
  if ( (this->m_attributeFlags & 0x20) != 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeRunColor;
    v104 = this->m_center.x;
    v105 = this->m_center.z;
    down.x = v104 + 8.0;
    down.y = this->m_center.y + 4.0;
    down.z = v105;
    up.x = v104 - 8.0;
    up.y = down.y;
    up.z = v105;
    NavDrawHorizontalArrow(from: &up, to: &down, width: 4.0, navColor: v3);
    v106 = this->m_center.x;
    v107 = this->m_center.z;
    down.x = v106 + 8.0;
    down.y = this->m_center.y - 4.0;
    down.z = v107;
    up.x = v106 - 8.0;
    up.y = down.y;
    up.z = v107;
    NavDrawHorizontalArrow(from: &up, to: &down, width: 4.0, navColor: v3);
  }
  if ( SLOBYTE(this->m_attributeFlags) < 0 )
  {
    if ( useAttributeColors )
      v3 = NavAttributeAvoidColor;
    v108 = this->m_center.x;
    down.x = v108 + 3.0;
    v109 = this->m_center.z;
    down.y = this->m_center.y + 8.0;
    down.z = v109;
    up.x = v108 - 3.0;
    up.y = down.y;
    up.z = v109;
    NavDrawTriangle(point1: &this->m_center, point2: &up, point3: &down, navColor: v3);
    v110 = this->m_center.x;
    v111 = this->m_center.z;
    down.x = v110 + 2.0;
    v112 = this->m_center.y - 3.0;
    down.y = this->m_center.y - 6.0;
    down.z = v111;
    up.x = v110 - 2.0;
    up.y = down.y;
    up.z = v111;
    start.x = v110;
    start.y = v112;
    start.z = v111;
    NavDrawTriangle(point1: &start, point2: &up, point3: &down, navColor: v3);
  }
  if ( this->IsBlocked(this, a2: -1, a3: false)
    || this->m_avoidanceObstacleHeight > 18.0
    || gpGlobals->tickcount <= this->m_damagingTickCount )
  {
    if ( !this->IsBlocked(this, a2: -1, a3: false)
      || (v31 = this->m_attributeFlags >= 0, v113 = NavBlockedByFuncNavBlockerColor, v31) )
    {
      v113 = NavBlockedByDoorColor;
    }
    nw.x = nw.x + 4.0;
    nw.y = nw.y + 4.0;
    ne.x = ne.x - 4.0;
    ne.y = ne.y + 4.0;
    sw.x = sw.x + 4.0;
    sw.y = sw.y - 4.0;
    se.x = se.x - 4.0;
    se.y = se.y - 4.0;
    NavDrawLine(from: &nw, to: &ne, navColor: v113);
    NavDrawLine(from: &ne, to: &se, navColor: v113);
    NavDrawLine(from: &se, to: &sw, navColor: v113);
    NavDrawLine(from: &sw, to: &nw, navColor: v113);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC270
// Name: public: virtual void CNavArea::ComputeHidingSpots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ComputeHidingSpots(CNavArea *this)
{
  CNavArea *v1; // edi
  int m_attributeFlags; // eax
  NavDirType v3; // eax
  float lo; // xmm0_4
  float hi; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // esi
  int m_Size; // ebx
  NavConnect *m_Elements; // edi
  CNavArea *id; // esi
  CNavArea *v10; // ecx
  float x; // xmm2_4
  float y; // xmm0_4
  NavCornerType v13; // ebx
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v14; // edx
  int v15; // esi
  int v16; // ecx
  HidingSpot **v17; // edx
  HidingSpot *v18; // esi
  bool v19; // al
  CNavArea *v20; // ebx
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v21; // ecx
  int v22; // edi
  int v23; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v24; // eax
  NavDirType v25; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v26; // [esp-Ch] [ebp-44h]
  int cornerCount[4]; // [esp+4h] [ebp-34h] BYREF
  Vector spot; // [esp+14h] [ebp-24h] BYREF
  CNavArea::ComputeHidingSpots::__l2::<unnamed_type_extent> extent; // [esp+20h] [ebp-18h]
  NavDirType dir; // [esp+28h] [ebp-10h]
  int c; // [esp+2Ch] [ebp-Ch]
  CNavArea *area; // [esp+30h] [ebp-8h]
  bool isHoriz; // [esp+37h] [ebp-1h]

  v1 = this;
  area = this;
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::PurgeAndDeleteElements(this: &this->m_hidingSpots);
  m_attributeFlags = v1->m_attributeFlags;
  if ( (m_attributeFlags & 2) == 0 && (m_attributeFlags & 0x200) == 0 )
  {
    v3 = NORTH;
    memset(cornerCount, 0, sizeof(cornerCount));
    c = 0;
    do
    {
      lo = 999999.88;
      hi = -999999.88;
      extent.lo = 999999.88;
      extent.hi = -999999.88;
      if ( v3 == NORTH || (isHoriz = false, v3 == SOUTH) )
        isHoriz = true;
      m_pData = v1->m_connect[v3].m_pData;
      m_Size = m_pData->m_Size;
      if ( m_pData->m_Size > 0 )
      {
        lo = extent.lo;
        hi = extent.hi;
        dir = OppositeDirection(dir: v3);
        m_Elements = m_pData->m_Elements;
        do
        {
          id = (CNavArea *)m_Elements->id;
          v10 = (CNavArea *)m_Elements->id;
          spot.z = m_Elements->length;
          if ( CNavArea::IsConnected(this: v10, area, dir) != 0 && (id->m_attributeFlags & 2) == 0 )
          {
            if ( isHoriz )
            {
              if ( lo > id->m_nwCorner.x )
                lo = id->m_nwCorner.x;
              x = id->m_seCorner.x;
            }
            else
            {
              if ( lo > id->m_nwCorner.y )
                lo = id->m_nwCorner.y;
              x = id->m_seCorner.y;
            }
            if ( x > hi )
              hi = x;
          }
          ++m_Elements;
          --m_Size;
        }
        while ( m_Size != 0 );
        v1 = area;
        v3 = c;
      }
      switch ( v3 )
      {
        case NORTH:
          if ( (float)(lo - v1->m_nwCorner.x) >= 20.0 )
            ++cornerCount[0];
          if ( (float)(v1->m_seCorner.x - hi) >= 20.0 )
            ++cornerCount[1];
          break;
        case EAST:
          if ( (float)(lo - v1->m_nwCorner.y) >= 20.0 )
            ++cornerCount[1];
          y = v1->m_seCorner.y;
          goto LABEL_30;
        case SOUTH:
          if ( (float)(lo - v1->m_nwCorner.x) >= 20.0 )
            ++cornerCount[3];
          y = v1->m_seCorner.x;
LABEL_30:
          if ( (float)(y - hi) >= 20.0 )
            ++cornerCount[2];
          break;
        case WEST:
          if ( (float)(lo - v1->m_nwCorner.y) >= 20.0 )
            ++cornerCount[0];
          if ( (float)(v1->m_seCorner.y - hi) >= 20.0 )
            ++cornerCount[3];
          break;
        default:
          break;
      }
      c = ++v3;
    }
    while ( v3 < NUM_DIRECTIONS );
    v13 = NORTH_WEST;
    c = 0;
    do
    {
      if ( cornerCount[v13] == 2 )
      {
        FindPositionInArea(area: v1, corner: v13, a3: &spot.x);
        if ( v13 != NORTH_WEST && (v14 = area->m_hidingSpots.m_pData, v15 = v14->m_Size, v16 = 0, v14->m_Size > 0) )
        {
          v17 = v14->m_Elements;
          while ( (float)((float)((float)((float)((*v17)->m_pos.y - spot.y) * (float)((*v17)->m_pos.y - spot.y))
                                + (float)((float)((*v17)->m_pos.x - spot.x) * (float)((*v17)->m_pos.x - spot.x)))
                        + (float)((float)((*v17)->m_pos.z - spot.z) * (float)((*v17)->m_pos.z - spot.z))) >= 900.0 )
          {
            ++v16;
            ++v17;
            if ( v16 >= v15 )
              goto LABEL_47;
          }
        }
        else
        {
LABEL_47:
          v18 = TheNavMesh->CreateHidingSpot(this: TheNavMesh);
          v18->m_pos = spot;
          v19 = IsHidingSpotInCover(&spot);
          v20 = area;
          v18->m_flags |= v19 ? 1 : 8;
          v21 = v20->m_hidingSpots.m_pData;
          v22 = v21->m_Size;
          v23 = v21->m_Size + 1;
          if ( v23 > v21->m_Size )
          {
            if ( v21 == (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
            {
              v24 = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v23 + 4);
              v20->m_hidingSpots.m_pData = v24;
              v24->m_Size = 0;
            }
            else
            {
              v26 = v20->m_hidingSpots.m_pData;
              dir = 4 * v23 + 4;
              v25 = _msize(pMem: v26);
              if ( dir > v25 )
                v20->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: v20->m_hidingSpots.m_pData, size: dir);
            }
          }
          v20->m_hidingSpots.m_pData->m_Elements[v22] = v18;
          ++v20->m_hidingSpots.m_pData->m_Size;
          v13 = c;
        }
        v1 = area;
      }
      c = ++v13;
    }
    while ( v13 < NUM_CORNERS );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC590
// Name: public: virtual void CNavArea::UpdateBlocked(bool,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CNavArea::UpdateBlocked(
        CNavArea *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        bool force,
        int teamID)
{
  float m_Value; // xmm0_4
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  double v9; // st7
  float z; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  bool (__thiscall *IsBlocked)(CNavArea *, int, bool); // eax
  IGameEvent *v15; // edi
  CNavMesh_vtbl *v16; // eax
  void (*OnAreaBlocked)(void); // edx
  int v19; // [esp+5Ch] [ebp-11Ch]
  Vector v21; // [esp+6Ch] [ebp-10Ch] BYREF
  CGameTrace tr; // [esp+78h] [ebp-100h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+D4h] [ebp-A4h] BYREF
  int v24; // [esp+ECh] [ebp-8Ch]
  int v25; // [esp+F0h] [ebp-88h]
  int v26; // [esp+F4h] [ebp-84h]
  float v27; // [esp+FCh] [ebp-7Ch]
  float v28; // [esp+100h] [ebp-78h]
  float v29; // [esp+104h] [ebp-74h]
  float v30; // [esp+10Ch] [ebp-6Ch]
  float v31; // [esp+110h] [ebp-68h]
  float v32; // [esp+114h] [ebp-64h]
  int v33; // [esp+11Ch] [ebp-5Ch]
  bool v34; // [esp+120h] [ebp-58h]
  char v35; // [esp+121h] [ebp-57h]
  Vector v36; // [esp+138h] [ebp-40h] BYREF
  Vector origin; // [esp+144h] [ebp-34h] BYREF
  Extent bounds; // [esp+150h] [ebp-28h] BYREF
  float sizeY; // [esp+168h] [ebp-10h]
  int v40; // [esp+16Ch] [ebp-Ch] OVERLAPPED
  float interval; // [esp+170h] [ebp-8h]
  float retaddr; // [esp+178h] [ebp+0h]

  v40 = a2;
  interval = retaddr;
  if ( !force
    && IntervalTimer::Now(this: (CEffectsServer *)&this->m_blockedTimer) <= (double)this->m_blockedTimer.m_timestamp.m_Value )
  {
    return;
  }
  m_Value = 0.0;
  p_m_timestamp = &this->m_blockedTimer.m_timestamp;
  if ( this->m_blockedTimer.m_timestamp.m_Value > 0.0 )
    m_Value = this->m_blockedTimer.m_duration.m_Value;
  bounds.hi.z = m_Value + 1.0;
  if ( (float)(m_Value + 1.0) > 5.0 )
    bounds.hi.z = 5.0;
  v9 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_blockedTimer) + bounds.hi.z;
  bounds.hi.x = v9;
  if ( p_m_timestamp->m_Value != v9 )
  {
    this->m_blockedTimer.NetworkStateChanged(this: &this->m_blockedTimer, a2: &this->m_blockedTimer.m_timestamp);
    p_m_timestamp->m_Value = bounds.hi.x;
  }
  if ( this->m_blockedTimer.m_duration.m_Value != bounds.hi.z )
  {
    this->m_blockedTimer.NetworkStateChanged(this: &this->m_blockedTimer, a2: &this->m_blockedTimer.m_duration);
    this->m_blockedTimer.m_duration.m_Value = bounds.hi.z;
  }
  if ( this->m_attributeFlags < 0 )
  {
    if ( force )
      CNavArea::UpdateBlockedFromNavBlockers(this);
    return;
  }
  z = this->m_center.z;
  *(_QWORD *)&v36.x = *(_QWORD *)&this->m_center.x;
  v36.z = z + 35.5;
  v11 = (float)((float)(this->m_seCorner.x - this->m_nwCorner.x) * 0.5) - 5.0;
  if ( v11 >= 16.0 )
    goto LABEL_18;
  if ( v11 >= 1.0 )
  {
    if ( v11 < 16.0 )
      goto LABEL_19;
LABEL_18:
    v11 = 16.0;
    goto LABEL_19;
  }
  v11 = 1.0;
LABEL_19:
  v12 = (float)((float)(this->m_seCorner.y - this->m_nwCorner.y) * 0.5) - 5.0;
  bounds.hi.z = v11;
  if ( v12 >= 16.0 )
    goto LABEL_23;
  if ( v12 < 1.0 )
  {
    v12 = 1.0;
    goto LABEL_24;
  }
  if ( v12 >= 16.0 )
LABEL_23:
    v12 = 16.0;
LABEL_24:
  bounds.hi.x = v12;
  LODWORD(origin.x) = LODWORD(v11) ^ _mask__NegFloat_;
  LODWORD(origin.y) = LODWORD(v12) ^ _mask__NegFloat_;
  origin.z = 0.0;
  v13 = *(float *)(((int (__thiscall *)(CGameRules *, int, int))g_pGameRules->GetViewVectors)(
                     a1: g_pGameRules,
                     a2: a3,
                     a3: a4)
                 + 56)
      - 35.5;
  IsBlocked = this->IsBlocked;
  bounds.lo.x = bounds.hi.z;
  bounds.lo.y = v12;
  bounds.lo.z = v13;
  HIBYTE(bounds.hi.y) = IsBlocked(this, a2: -1, a3: false);
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&tr.hitbox,
    passedict: nullptr,
    collisionGroup: 8,
    pExtraShouldHitFunc: nullptr);
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v30 = (float)(bounds.lo.x - origin.x) * 0.5;
  v31 = (float)(bounds.lo.y - origin.y) * 0.5;
  v32 = (float)(bounds.lo.z - origin.z) * 0.5;
  tr.hitbox = (int)&CTraceFilterWalkableEntities::`vftable';
  filter.m_pPassEnt = (const IHandleEntity *)7;
  v33 = 0;
  v35 = 0;
  v34 = (float)((float)((float)(v31 * v31) + (float)(v30 * v30)) + (float)(v32 * v32)) < 0.000001;
  *(float *)&filter.m_collisionGroup = (float)((float)(bounds.lo.x + origin.x) * 0.5) + v36.x;
  *(float *)&filter.m_pExtraShouldHitCheckFunction = (float)((float)(bounds.lo.y + origin.y) * 0.5) + v36.y;
  LODWORD(v21.y) = &v21;
  *(float *)&filter.m_flags = (float)((float)(bounds.lo.z + origin.z) * 0.5) + v36.z;
  v27 = (float)((float)(bounds.lo.x + origin.x) * 0.5) * -1.0;
  v28 = (float)((float)(bounds.lo.y + origin.y) * 0.5) * -1.0;
  v29 = (float)((float)(bounds.lo.z + origin.z) * 0.5) * -1.0;
  ((void (__thiscall *)(IEngineTrace *, int *, int, int *))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: &filter.m_collisionGroup,
    a3: 147467,
    a4: &tr.hitbox);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v21, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  if ( tr.plane.pad[1] != 0 )
  {
    if ( force )
    {
      if ( teamID == -1 )
        *(_WORD *)this->m_isBlocked = 257;
      else
        this->m_isBlocked[teamID % 2] = true;
    }
  }
  else
  {
    *(_WORD *)this->m_isBlocked = 0;
  }
  HIBYTE(sizeY) = this->IsBlocked(this, a2: -1, a3: false);
  if ( HIBYTE(bounds.hi.y) != HIBYTE(sizeY) )
  {
    v15 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD, _DWORD, int))gameeventmanager->CreateEventA)(
                          a1: gameeventmanager,
                          a2: "nav_blocked",
                          a3: 0,
                          a4: 0,
                          a5: v19);
    if ( v15 != nullptr )
    {
      v15->SetInt(this: v15, a2: "area", a3: this->m_id);
      v15->SetInt(this: v15, a2: "blocked", a3: HIBYTE(sizeY));
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v15, a3: false);
    }
    v16 = TheNavMesh->__vftable;
    if ( HIBYTE(sizeY) != 0 )
      OnAreaBlocked = (void (*)(void))v16->OnAreaBlocked;
    else
      OnAreaBlocked = (void (*)(void))v16->OnAreaUnblocked;
    OnAreaBlocked();
  }
  if ( CNavMesh::GetMarkedArea(this: TheNavMesh) == this )
  {
    if ( this->IsBlocked(this, a2: teamID, a3: false) )
      NDebugOverlay::Box(origin: &v36, mins: &origin, maxs: &bounds.lo, r: 255, g: 0, b: 0, a: 64, flDuration: 3.0);
    else
      NDebugOverlay::Box(origin: &v36, mins: &origin, maxs: &bounds.lo, r: 0, g: 255, b: 0, a: 64, flDuration: 3.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCA50
// Name: public: void CNavArea::UpdateAvoidanceObstacles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::UpdateAvoidanceObstacles(CNavArea *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float m_Value; // xmm0_4
  double v4; // st7
  float z; // eax
  float v6; // ecx
  float v7; // xmm0_4
  CNavMesh *v8; // eax
  float v9; // xmm0_4
  int v10; // edi
  INavAvoidanceObstacle *v11; // esi
  int v12; // eax
  double v13; // st7
  Vector vecSurroundMins; // [esp+Ch] [ebp-38h] BYREF
  Vector vecSurroundMaxs; // [esp+18h] [ebp-2Ch] BYREF
  Vector maxs; // [esp+24h] [ebp-20h] BYREF
  Vector mins; // [esp+30h] [ebp-14h] BYREF
  float propHeight; // [esp+3Ch] [ebp-8h]
  float obstructionHeight; // [esp+40h] [ebp-4h]

  p_m_timestamp = &this->m_avoidanceObstacleTimer.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_avoidanceObstacleTimer) > (double)this->m_avoidanceObstacleTimer.m_timestamp.m_Value )
  {
    m_Value = 0.0;
    if ( this->m_blockedTimer.m_timestamp.m_Value > 0.0 )
      m_Value = this->m_blockedTimer.m_duration.m_Value;
    obstructionHeight = m_Value + 1.0;
    if ( (float)(m_Value + 1.0) > 5.0 )
      obstructionHeight = 5.0;
    v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_avoidanceObstacleTimer) + obstructionHeight;
    propHeight = v4;
    if ( p_m_timestamp->m_Value != v4 )
    {
      this->m_avoidanceObstacleTimer.NetworkStateChanged(
        this: &this->m_avoidanceObstacleTimer,
        a2: &this->m_avoidanceObstacleTimer.m_timestamp);
      p_m_timestamp->m_Value = propHeight;
    }
    if ( this->m_avoidanceObstacleTimer.m_duration.m_Value != obstructionHeight )
    {
      this->m_avoidanceObstacleTimer.NetworkStateChanged(
        this: &this->m_avoidanceObstacleTimer,
        a2: &this->m_avoidanceObstacleTimer.m_duration);
      this->m_avoidanceObstacleTimer.m_duration.m_Value = obstructionHeight;
    }
    z = this->m_nwCorner.z;
    v6 = this->m_seCorner.z;
    *(_QWORD *)&mins.x = *(_QWORD *)&this->m_nwCorner.x;
    *(_QWORD *)&maxs.x = *(_QWORD *)&this->m_seCorner.x;
    v7 = this->m_nwCorner.z;
    mins.z = z;
    maxs.z = v6;
    if ( v6 <= v7 )
      mins.z = v6;
    else
      mins.z = v7;
    if ( v7 <= v6 )
      v7 = v6;
    v8 = TheNavMesh;
    maxs.z = v7 + 55.0;
    v9 = 0.0;
    v10 = 0;
    obstructionHeight = 0.0;
    if ( TheNavMesh->m_avoidanceObstacles.m_Size > 0 )
    {
      do
      {
        v11 = v8->m_avoidanceObstacles.m_Memory.m_pMemory[v10];
        v12 = (int)v11->GetObstructingEntity(this: v11);
        if ( v12 != 0 )
        {
          (*(void (__thiscall **)(int, Vector *, Vector *))(*(_DWORD *)(v12 + 228) + 60))(
            a1: v12 + 228,
            a2: &vecSurroundMins,
            a3: &vecSurroundMaxs);
          if ( IsBoxIntersectingBox(
                 boxMin1: &mins,
                 boxMax1: &maxs,
                 boxMin2: &vecSurroundMins,
                 boxMax2: &vecSurroundMaxs)
            && v11->CanObstructNavAreas(this: v11) )
          {
            v13 = ((double (__thiscall *)(INavAvoidanceObstacle *))v11->GetNavObstructionHeight)(a1: v11);
            propHeight = v13;
            if ( obstructionHeight <= v13 )
              obstructionHeight = propHeight;
          }
        }
        v8 = TheNavMesh;
        ++v10;
      }
      while ( v10 < TheNavMesh->m_avoidanceObstacles.m_Size );
      v9 = obstructionHeight;
    }
    this->m_avoidanceObstacleHeight = v9;
    if ( v9 == 0.0 )
      TheNavMesh->OnAvoidanceObstacleLeftArea(this: TheNavMesh, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCC40
// Name: private: void CNavArea::ResetPotentiallyVisibleAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ResetPotentiallyVisibleAreas(CNavArea *this)
{
  this->m_potentiallyVisibleAreas.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102FCC50
// Name: public: virtual bool CNavArea::IsPotentiallyVisible(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::IsPotentiallyVisible(CNavArea *this, const CNavArea *viewedArea)
{
  int m_Size; // ecx
  int v5; // eax
  CNavArea::AreaBindInfo *v6; // edx
  CNavArea *area; // ecx
  int v8; // edx
  int v9; // eax
  CNavArea::AreaBindInfo *m_pMemory; // esi
  const CNavArea **p_area; // ecx
  bool v12; // zf
  bool v13; // bl

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavArea::IsPotentiallyVisible",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( viewedArea == nullptr )
    goto LABEL_2;
  if ( viewedArea == this )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  else
  {
    m_Size = this->m_potentiallyVisibleAreas.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
    {
LABEL_9:
      area = this->m_inheritVisibilityFrom.area;
      if ( area == nullptr || (v8 = area->m_potentiallyVisibleAreas.m_Size, v9 = 0, v8 <= 0) )
      {
LABEL_2:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 0;
      }
      m_pMemory = area->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
      p_area = (const CNavArea **)&m_pMemory->area;
      while ( *p_area != viewedArea )
      {
        ++v9;
        p_area += 2;
        if ( v9 >= v8 )
          goto LABEL_2;
      }
      v12 = m_pMemory[v9].attributes == 0;
    }
    else
    {
      v6 = this->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
      while ( v6->area != viewedArea )
      {
        ++v5;
        ++v6;
        if ( v5 >= m_Size )
          goto LABEL_9;
      }
      v12 = this->m_potentiallyVisibleAreas.m_Memory.m_pMemory[v5].attributes == 0;
    }
    v13 = !v12;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCD40
// Name: public: virtual bool CNavArea::IsCompletelyVisible(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsCompletelyVisible(CNavArea *this, const CNavArea *viewedArea)
{
  int m_Size; // ecx
  int v5; // eax
  CNavArea::AreaBindInfo *v6; // edx
  CNavArea *area; // ecx
  int v8; // edx
  int v9; // eax
  CNavArea::AreaBindInfo *m_pMemory; // esi
  const CNavArea **p_area; // ecx
  unsigned __int8 attributes; // bl

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavArea::IsCompletelyVisible",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( viewedArea == nullptr )
    goto LABEL_2;
  if ( viewedArea == this )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return true;
  }
  else
  {
    m_Size = this->m_potentiallyVisibleAreas.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
    {
LABEL_9:
      area = this->m_inheritVisibilityFrom.area;
      if ( area == nullptr || (v8 = area->m_potentiallyVisibleAreas.m_Size, v9 = 0, v8 <= 0) )
      {
LABEL_2:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return false;
      }
      m_pMemory = area->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
      p_area = (const CNavArea **)&m_pMemory->area;
      while ( *p_area != viewedArea )
      {
        ++v9;
        p_area += 2;
        if ( v9 >= v8 )
          goto LABEL_2;
      }
      attributes = m_pMemory[v9].attributes;
    }
    else
    {
      v6 = this->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
      while ( v6->area != viewedArea )
      {
        ++v5;
        ++v6;
        if ( v5 >= m_Size )
          goto LABEL_9;
      }
      attributes = this->m_potentiallyVisibleAreas.m_Memory.m_pMemory[v5].attributes;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return (attributes & 2) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCE30
// Name: public: CNavAreaCriticalData::CNavAreaCriticalData(void)
// Source: json
//------------------------------------------------------------------------------
CNavAreaCriticalData *__thiscall CNavAreaCriticalData::CNavAreaCriticalData(CNavAreaCriticalData *this)
{
  CNavAreaCriticalData *result; // eax

  result = this;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_connect[0].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_connect[1].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_connect[2].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_connect[3].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  this->m_ladder[0].m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  this->m_ladder[1].m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_elevatorAreas.m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FCEA0
// Name: public: CNavAreaCriticalData::~CNavAreaCriticalData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavAreaCriticalData::~CNavAreaCriticalData(CNavAreaCriticalData *this)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *p_m_elevatorAreas; // esi
  int i; // edi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // esi
  int j; // edi

  p_m_elevatorAreas = &this->m_elevatorAreas;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  if ( p_m_elevatorAreas->m_pData != (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: p_m_elevatorAreas->m_pData);
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    p_m_elevatorAreas->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
  for ( i = 1; i >= 0; --i )
  {
    m_pData = p_m_elevatorAreas[-1].m_pData;
    --p_m_elevatorAreas;
    if ( m_pData != (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: m_pData);
      p_m_elevatorAreas->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
  }
  m_ladder = this->m_ladder;
  for ( j = 3; j >= 0; --j )
  {
    --m_ladder;
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    if ( m_ladder->m_pData != (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: m_ladder->m_pData);
      if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
          & 1) == 0 )
        `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
      m_ladder->m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCF60
// Name: public: virtual void CNavArea::OnDestroyNotify(class CNavLadder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::OnDestroyNotify(CNavArea *this, CNavLadder *dead)
{
  CNavArea::Disconnect(this, ladder: dead);
}

//------------------------------------------------------------------------------
// Address: 0x102FCF70
// Name: public: void CNavArea::ConnectTo(class CNavLadder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ConnectTo(CNavArea *this, float ladder)
{
  CNavLadder *v2; // edi
  CNavLadder *v4; // [esp-4h] [ebp-Ch]

  v2 = (CNavLadder *)LODWORD(ladder);
  v4 = (CNavLadder *)LODWORD(ladder);
  ladder = (float)(*(float *)(LODWORD(ladder) + 20) + *(float *)(LODWORD(ladder) + 8)) * 0.5;
  CNavArea::Disconnect(this, ladder: v4);
  if ( this->m_center.z <= ladder )
  {
    CNavArea::Disconnect(this, ladder: v2);
    ladder = *(float *)&v2;
    CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::AddToTail(
      this: this->m_ladder,
      src: (const NavLadderConnect *)&ladder);
  }
  else
  {
    CNavArea::Disconnect(this, ladder: v2);
    ladder = *(float *)&v2;
    CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::AddToTail(
      this: &this->m_ladder[1],
      src: (const NavLadderConnect *)&ladder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCFE0
// Name: public: void CNavArea::AddIncomingConnection(class CNavArea __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::AddIncomingConnection(CNavArea *this, CNavArea *source, NavDirType incomingEdgeDir)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v4; // esi
  int v5; // eax
  CNavArea **m_Elements; // edi
  CNavArea *v7; // edx
  float v8; // xmm0_4
  int v9; // edi
  float v10; // xmm0_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v11; // eax
  int m_Size; // [esp-4h] [ebp-10h]

  m_pData = this->m_incomingConnect[incomingEdgeDir].m_pData;
  v4 = &this->m_incomingConnect[incomingEdgeDir];
  v5 = 0;
  m_Size = m_pData->m_Size;
  if ( m_pData->m_Size <= 0 )
  {
    v7 = source;
LABEL_9:
    v8 = v7->m_center.x - this->m_center.x;
    v9 = v4->m_pData->m_Size;
    v10 = fsqrt(
            (float)((float)((float)(v7->m_center.y - this->m_center.y) * (float)(v7->m_center.y - this->m_center.y))
                  + (float)((float)(v7->m_center.z - this->m_center.z) * (float)(v7->m_center.z - this->m_center.z)))
          + (float)(v8 * v8));
    CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::EnsureCapacity(
      this: &this->m_incomingConnect[incomingEdgeDir],
      num: v9 + 1);
    v11 = v4->m_pData;
    v11->m_Elements[v9].id = (unsigned int)source;
    v11->m_Elements[v9].length = v10;
    ++v4->m_pData->m_Size;
    return;
  }
  m_Elements = (CNavArea **)m_pData->m_Elements;
  while ( 1 )
  {
    v7 = source;
    if ( *m_Elements == source )
      break;
    ++v5;
    m_Elements += 2;
    if ( v5 >= m_Size )
      goto LABEL_9;
  }
  if ( v5 == -1 )
    goto LABEL_9;
}

//------------------------------------------------------------------------------
// Address: 0x102FD2D0
// Name: public: CNavArea::CNavArea(void)
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CNavArea::CNavArea(CNavArea *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  unsigned __int8 *m_playerCount; // ecx
  float *m_dangerTimestamp; // eax
  int i; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // edi
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // edi
  int j; // [esp+Ch] [ebp-4h]
  int k; // [esp+Ch] [ebp-4h]

  CNavAreaCriticalData::CNavAreaCriticalData(this: &this->CNavAreaCriticalData);
  this->__vftable = (CNavArea_vtbl *)&CNavArea::`vftable';
  this->m_blockedTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_blockedTimer.__vftable;
  this->m_blockedTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_blockedTimer.m_duration);
  v3 = this->m_blockedTimer.__vftable;
  this->m_blockedTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_blockedTimer, a2: &this->m_blockedTimer.m_timestamp);
  this->m_avoidanceObstacleTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = this->m_avoidanceObstacleTimer.__vftable;
  this->m_avoidanceObstacleTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v4->NetworkStateChanged)(a1: &this->m_avoidanceObstacleTimer.m_duration);
  v5 = this->m_avoidanceObstacleTimer.__vftable;
  this->m_avoidanceObstacleTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_avoidanceObstacleTimer, a2: &this->m_avoidanceObstacleTimer.m_timestamp);
  this->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  this->m_spotEncounters.m_pData = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_incomingConnect[0].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_incomingConnect[1].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_incomingConnect[2].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  this->m_incomingConnect[3].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  this->m_potentiallyVisibleAreas.m_Memory.m_pMemory = nullptr;
  this->m_potentiallyVisibleAreas.m_Size = 0;
  this->m_potentiallyVisibleAreas.m_pElements = nullptr;
  this->m_marker = 0;
  this->m_nearNavSearchMarker = 0;
  this->m_damagingTickCount = 0;
  this->m_openMarker = 0;
  this->m_parent = nullptr;
  this->m_parentHow = GO_NORTH;
  this->m_attributeFlags = 0;
  this->m_place = TheNavMesh->m_navPlace;
  this->m_isUnderwater = false;
  this->m_avoidanceObstacleHeight = 0.0;
  this->m_totalCost = 0.0;
  this->m_node[0] = nullptr;
  this->m_node[1] = nullptr;
  this->m_node[2] = nullptr;
  this->m_node[3] = nullptr;
  m_playerCount = this->m_playerCount;
  m_dangerTimestamp = this->m_dangerTimestamp;
  for ( i = 2; i != 0; --i )
  {
    m_playerCount[2] = 0;
    *(m_dangerTimestamp - 2) = 0.0;
    *m_dangerTimestamp = 0.0;
    *(m_dangerTimestamp - 4) = 0.0;
    m_dangerTimestamp[4] = 0.0;
    *m_playerCount = 0;
    ++m_dangerTimestamp;
    ++m_playerCount;
  }
  this->m_id = CNavArea::m_nextID++;
  this->m_debugid = 0;
  this->m_prevHash = nullptr;
  this->m_nextHash = nullptr;
  this->m_isBattlefront = false;
  m_connect = this->m_connect;
  for ( j = 4; j != 0; --j )
  {
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    if ( m_connect->m_pData != (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: m_connect->m_pData);
      if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
          & 1) == 0 )
        `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
      m_connect->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
    ++m_connect;
  }
  m_ladder = this->m_ladder;
  for ( k = 2; k != 0; --k )
  {
    if ( m_ladder->m_pData != (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: m_ladder->m_pData);
      m_ladder->m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
    ++m_ladder;
  }
  this->m_lightIntensity[0] = 1.0;
  this->m_lightIntensity[1] = 1.0;
  this->m_lightIntensity[2] = 1.0;
  this->m_lightIntensity[3] = 1.0;
  this->m_elevator = nullptr;
  if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
      & 1) == 0 )
    `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
  if ( this->m_elevatorAreas.m_pData != (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: this->m_elevatorAreas.m_pData);
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    this->m_elevatorAreas.m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
  this->m_inheritVisibilityFrom.id = 0;
  this->m_isInheritedFrom = false;
  this->m_invDxCorners = 0.0;
  this->m_invDyCorners = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102FD5A0
// Name: public: void CNavArea::GetNodes(enum NavDirType,class CUtlVector<class CNavNode __near *,class CUtlMemory<class CNavNode __near *,int>> __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::GetNodes(CNavArea *this, NavDirType dir, CUtlMemory<vgui::TreeNode *,int> *nodes)
{
  CNavArea *v4; // edx
  int v5; // eax
  CNavNode *v6; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CNavNode **v9; // ecx
  int v10; // eax
  CNavNode **v11; // eax
  int v12; // edi
  int v13; // eax
  CNavNode **v14; // ecx
  int v15; // eax
  CNavNode **v16; // eax
  NavDirType traversalDirection; // [esp+10h] [ebp+8h]
  NavCornerType endCorner; // [esp+14h] [ebp+Ch]

  v4 = this;
  if ( nodes != nullptr )
  {
    nodes[1].m_pMemory = nullptr;
    switch ( dir )
    {
      case NORTH:
        endCorner = NORTH_EAST;
        traversalDirection = EAST;
        goto LABEL_7;
      case EAST:
        v5 = 1;
        endCorner = SOUTH_EAST;
        traversalDirection = SOUTH;
        goto LABEL_8;
      case SOUTH:
        v5 = 3;
        endCorner = SOUTH_EAST;
        traversalDirection = EAST;
        goto LABEL_8;
      case WEST:
        endCorner = SOUTH_WEST;
        traversalDirection = SOUTH;
LABEL_7:
        v5 = 0;
LABEL_8:
        v6 = this->m_node[v5];
        if ( v6 == nullptr )
          return;
        break;
      default:
        return;
    }
    while ( v6 != v4->m_node[endCorner] )
    {
      m_pMemory = (int)nodes[1].m_pMemory;
      m_nAllocationCount = nodes->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: nodes, num: m_pMemory - m_nAllocationCount + 1);
      ++nodes[1].m_pMemory;
      v9 = (CNavNode **)nodes->m_pMemory;
      v10 = (int)nodes[1].m_pMemory - m_pMemory - 1;
      nodes[1].m_nAllocationCount = (int)nodes->m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
      v11 = (CNavNode **)&nodes->m_pMemory[m_pMemory];
      if ( v11 != nullptr )
        *v11 = v6;
      v6 = v6->m_to[traversalDirection];
      if ( v6 == nullptr )
        return;
      v4 = this;
    }
    v12 = (int)nodes[1].m_pMemory;
    v13 = nodes->m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<CNavLadder *,int>::Grow(this: nodes, num: v12 - v13 + 1);
    ++nodes[1].m_pMemory;
    v14 = (CNavNode **)nodes->m_pMemory;
    v15 = (int)nodes[1].m_pMemory - v12 - 1;
    nodes[1].m_nAllocationCount = (int)nodes->m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    v16 = (CNavNode **)&nodes->m_pMemory[v12];
    if ( v16 != nullptr )
      *v16 = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD720
// Name: public: void CNavArea::ConnectTo(class CNavArea __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ConnectTo(CNavArea *this, CNavArea *area, NavDirType dir)
{
  CNavArea *v3; // edx
  int v5; // eax
  NavConnect *v6; // ecx
  float v7; // xmm0_4
  int v8; // eax
  float v9; // xmm0_4
  int v10; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v11; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v13; // ecx
  int v14; // eax
  CNavArea **m_Elements; // edx
  int v16; // ecx
  int v17; // eax
  NavDirType v18; // edi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v19; // edx
  int v20; // ecx
  int v21; // eax
  CNavArea **v22; // edx
  signed int con_4; // [esp+4h] [ebp-14h]
  int m_Size; // [esp+8h] [ebp-10h]
  int v25; // [esp+8h] [ebp-10h]
  int v26; // [esp+8h] [ebp-10h]

  v3 = area;
  if ( area != this )
  {
    v5 = 0;
    m_Size = this->m_connect[dir].m_pData->m_Size;
    if ( m_Size <= 0 )
    {
LABEL_6:
      v7 = area->m_center.x - this->m_center.x;
      v8 = this->m_connect[dir].m_pData->m_Size;
      v9 = fsqrt(
             (float)((float)((float)(area->m_center.y - this->m_center.y) * (float)(area->m_center.y - this->m_center.y))
                   + (float)((float)(area->m_center.z - this->m_center.z) * (float)(area->m_center.z - this->m_center.z)))
           + (float)(v7 * v7));
      v10 = v8 + 1;
      v25 = v8;
      if ( v8 + 1 > v8 )
      {
        if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
            & 1) == 0 )
          `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
        if ( this->m_connect[dir].m_pData == (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
        {
          v11 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 8 * v10 + 4);
          this->m_connect[dir].m_pData = v11;
          v11->m_Size = 0;
        }
        else
        {
          con_4 = 8 * v10 + 4;
          if ( con_4 > (int)_msize(pMem: this->m_connect[dir].m_pData) )
            this->m_connect[dir].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_connect[dir].m_pData, size: con_4);
        }
        v3 = area;
        v8 = v25;
      }
      m_pData = this->m_connect[dir].m_pData;
      m_pData->m_Elements[v8].id = (unsigned int)v3;
      m_pData->m_Elements[v8].length = v9;
      ++this->m_connect[dir].m_pData->m_Size;
      v13 = this->m_incomingConnect[dir].m_pData;
      v14 = v13->m_Size;
      v26 = 0;
      if ( v13->m_Size > 0 )
      {
        m_Elements = (CNavArea **)v13->m_Elements;
        while ( 1 )
        {
          v16 = v26;
          if ( *m_Elements == area )
            break;
          m_Elements += 2;
          ++v26;
          if ( v16 + 1 >= v14 )
            goto LABEL_26;
        }
        if ( v26 != -1 )
        {
          v17 = v14 - v26 - 1;
          if ( v17 > 0 )
            _V_memmove(
              dest: &this->m_incomingConnect[dir].m_pData->m_Elements[v26],
              src: &this->m_incomingConnect[dir].m_pData->m_Elements[v26 + 1],
              count: 8 * v17);
          if ( --this->m_incomingConnect[dir].m_pData->m_Size == 0 )
          {
            free(pMem: this->m_incomingConnect[dir].m_pData);
            if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
                & 1) == 0 )
              `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
            this->m_incomingConnect[dir].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
          }
        }
      }
LABEL_26:
      switch ( dir )
      {
        case NORTH:
          v18 = SOUTH;
          break;
        case EAST:
          v18 = WEST;
          break;
        case WEST:
          v18 = EAST;
          break;
        default:
          v18 = NORTH;
          break;
      }
      v19 = area->m_connect[v18].m_pData;
      v20 = v19->m_Size;
      v21 = 0;
      if ( v19->m_Size <= 0 )
        goto LABEL_37;
      v22 = (CNavArea **)v19->m_Elements;
      while ( *v22 != this )
      {
        ++v21;
        v22 += 2;
        if ( v21 >= v20 )
          goto LABEL_37;
      }
      if ( v21 == -1 )
LABEL_37:
        CNavArea::AddIncomingConnection(this: area, source: this, incomingEdgeDir: v18);
    }
    else
    {
      v6 = this->m_connect[dir].m_pData->m_Elements;
      while ( v6->area != area )
      {
        ++v5;
        ++v6;
        if ( v5 >= m_Size )
          goto LABEL_6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD970
// Name: public: void CNavArea::Disconnect(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Disconnect(CNavArea *this, CNavArea *area)
{
  CNavArea *v2; // esi
  NavDirType v4; // ebx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // edx
  int m_Size; // eax
  int v7; // ecx
  NavConnect *m_Elements; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v9; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v10; // ecx
  int v11; // edx
  int v12; // eax
  CNavArea **v13; // esi
  CNavArea *connect; // [esp+Ch] [ebp-Ch]
  NavDirType dirOpposite; // [esp+14h] [ebp-4h]

  v2 = area;
  connect = area;
  v4 = NORTH;
  while ( 1 )
  {
    switch ( v4 )
    {
      case NORTH:
        dirOpposite = SOUTH;
        break;
      case EAST:
        dirOpposite = WEST;
        break;
      case WEST:
        dirOpposite = EAST;
        break;
      default:
        dirOpposite = NORTH;
        break;
    }
    m_pData = this->m_connect[v4].m_pData;
    m_Size = m_pData->m_Size;
    v7 = 0;
    if ( m_pData->m_Size > 0 )
    {
      m_Elements = m_pData->m_Elements;
      while ( m_Elements->area != v2 )
      {
        ++v7;
        ++m_Elements;
        if ( v7 >= m_Size )
          goto LABEL_29;
      }
      if ( v7 != -1 )
      {
        v9 = this->m_connect[v4].m_pData;
        if ( v9->m_Size - v7 - 1 > 0 )
          _V_memmove(dest: &v9->m_Elements[v7], src: &v9->m_Elements[v7 + 1], count: 8 * (v9->m_Size - v7 - 1));
        if ( --this->m_connect[v4].m_pData->m_Size == 0 )
        {
          free(pMem: this->m_connect[v4].m_pData);
          if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
              & 1) == 0 )
            `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
          this->m_connect[v4].m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
        }
        if ( CNavArea::IsConnected(this: area, area: this, dir: dirOpposite) != 0 )
        {
          CNavArea::AddIncomingConnection(this, source: area, incomingEdgeDir: v4);
        }
        else
        {
          v10 = &area->m_incomingConnect[dirOpposite];
          v11 = v10->m_pData->m_Size;
          v12 = 0;
          connect = this;
          if ( v11 > 0 )
          {
            v13 = (CNavArea **)v10->m_pData->m_Elements;
            while ( *v13 != this )
            {
              ++v12;
              v13 += 2;
              if ( v12 >= v11 )
                goto LABEL_29;
            }
            if ( v12 != -1 )
              CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Remove(this: v10, elem: v12);
          }
        }
      }
    }
LABEL_29:
    if ( ++v4 >= NUM_DIRECTIONS )
      break;
    v2 = connect;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDAC0
// Name: private: void CNavArea::MergeAdjacentConnections(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::MergeAdjacentConnections(CNavArea *this, CNavArea *adjArea)
{
  NavDirType v2; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // ebx
  int i; // edi
  CNavArea *area; // ecx
  int v7; // eax
  CNavArea *v8; // edi
  int v9; // edx
  int v10; // ecx
  NavConnect *v11; // eax
  bool v12; // cc
  CNavLadder *v13; // edi
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v14; // ecx
  int v15; // ebx
  int v16; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v17; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v18; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx
  int m_Size; // ebx
  int v21; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v22; // eax
  _DWORD *v23; // ecx
  NavConnect connect; // [esp+Ch] [ebp-18h] BYREF
  float v25; // [esp+14h] [ebp-10h]
  int it; // [esp+18h] [ebp-Ch]
  int **v27; // [esp+1Ch] [ebp-8h]
  int dir; // [esp+20h] [ebp-4h]

  v2 = NORTH;
  dir = 0;
  m_connect = adjArea->m_connect;
  do
  {
    for ( i = 0; i < m_connect->m_pData->m_Size; ++i )
    {
      area = m_connect->m_pData->m_Elements[i].area;
      connect.length = m_connect->m_pData->m_Elements[i].length;
      if ( area != adjArea && area != this )
      {
        CNavArea::ConnectTo(this, area, dir: v2);
        v2 = dir;
      }
    }
    ++v2;
    ++m_connect;
    dir = v2;
  }
  while ( v2 < NUM_DIRECTIONS );
  CNavArea::Disconnect(this, area: adjArea);
  v7 = 0;
  for ( it = 0; v7 < TheNavAreas.m_Size; it = v7 )
  {
    v8 = TheNavAreas.m_Memory.m_pMemory[v7];
    if ( v8 != this && v8 != adjArea )
    {
      dir = 0;
      v27 = (int **)v8->m_connect;
      do
      {
        v9 = **v27;
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = (NavConnect *)(*v27 + 1);
          while ( 1 )
          {
            connect = *v11;
            if ( connect.area == adjArea )
              break;
            ++v10;
            ++v11;
            if ( v10 >= v9 )
              goto LABEL_18;
          }
          CNavArea::Disconnect(this: v8, area: adjArea);
          CNavArea::Disconnect(this: v8, area: this);
          CNavArea::ConnectTo(this: v8, area: this, (NavDirType)dir);
        }
LABEL_18:
        ++v27;
        ++dir;
      }
      while ( dir < 4 );
      v7 = it;
    }
    ++v7;
  }
  dir = (int)adjArea->m_ladder;
  for ( it = 2; it != 0; --it )
  {
    v12 = **(_DWORD **)dir <= 0;
    v27 = nullptr;
    if ( !v12 )
    {
      while ( 1 )
      {
        v13 = *(CNavLadder **)(*(_DWORD *)dir + 4 * (_DWORD)v27 + 4);
        v25 = (float)(v13->m_bottom.z + v13->m_top.z) * 0.5;
        CNavArea::Disconnect(this, ladder: v13);
        if ( this->m_center.z <= v25 )
        {
          CNavArea::Disconnect(this, ladder: v13);
          m_pData = this->m_ladder[0].m_pData;
          m_Size = m_pData->m_Size;
          v21 = m_pData->m_Size + 1;
          if ( v21 > m_pData->m_Size )
          {
            if ( m_pData == (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
            {
              v22 = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v21 + 4);
              this->m_ladder[0].m_pData = v22;
              v22->m_Size = 0;
            }
            else
            {
              LODWORD(connect.length) = 4 * v21 + 4;
              if ( SLODWORD(connect.length) > (int)_msize(pMem: m_pData) )
                this->m_ladder[0].m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_ladder[0].m_pData, size: LODWORD(connect.length));
            }
          }
          this->m_ladder[0].m_pData->m_Elements[m_Size].id = (unsigned int)v13;
          v18 = this->m_ladder[0].m_pData;
          goto LABEL_36;
        }
        CNavArea::Disconnect(this, ladder: v13);
        v14 = this->m_ladder[1].m_pData;
        v15 = v14->m_Size;
        v16 = v14->m_Size + 1;
        if ( v16 <= v14->m_Size )
          goto LABEL_29;
        if ( v14 != (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
          break;
        v17 = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v16 + 4);
        this->m_ladder[1].m_pData = v17;
        v17->m_Size = 0;
        this->m_ladder[1].m_pData->m_Elements[v15].id = (unsigned int)v13;
        v18 = this->m_ladder[1].m_pData;
LABEL_36:
        ++v18->m_Size;
        v23 = *(_DWORD **)dir;
        v27 = (int **)((char *)v27 + 1);
        if ( (int)v27 >= *v23 )
          goto LABEL_37;
      }
      LODWORD(connect.length) = 4 * v16 + 4;
      if ( SLODWORD(connect.length) > (int)_msize(pMem: v14) )
        this->m_ladder[1].m_pData = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_ladder[1].m_pData, size: LODWORD(connect.length));
LABEL_29:
      this->m_ladder[1].m_pData->m_Elements[v15].id = (unsigned int)v13;
      v18 = this->m_ladder[1].m_pData;
      goto LABEL_36;
    }
LABEL_37:
    dir += 4;
  }
  connect.id = (unsigned int)adjArea;
  LODWORD(connect.length) = this;
  CNavMesh::ForAllLadders<LadderConnectionReplacement>(this: TheNavMesh, func: (LadderConnectionReplacement *)&connect);
}

//------------------------------------------------------------------------------
// Address: 0x102FDD50
// Name: private: void CNavArea::FinishSplitEdit(class CNavArea __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::FinishSplitEdit(CNavArea *this, CNavArea *newArea, NavDirType ignoreEdge)
{
  CNavArea *v4; // edi
  float x; // xmm5_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float y; // xmm1_4
  CNavArea *v9; // ecx
  float v10; // xmm0_4
  NavDirType v11; // ebx
  int dtr_CNavArea; // ecx
  int v13; // edx
  int v14; // eax
  CNavArea *v15; // edi
  CountdownTimer_vtbl *v16; // eax
  NavDirType v17; // ecx
  CNavArea *NetworkStateChanged_2; // edi
  bool v19; // cc
  NavDirType v20; // eax
  int m_Size; // eax
  int v22; // ebx
  CNavArea **m_pMemory; // ecx
  int v24; // eax
  CNavArea **v25; // ebx
  int v26; // eax
  CNavNode **i; // ecx
  int v28; // ecx
  int v29; // eax
  int v30; // edx
  float v31; // xmm2_4
  CNavNode *v32; // edi
  CNavNode *v33; // edx
  CNavNode *j; // ecx
  CNavNode *k; // eax
  CNavNode *v36; // eax
  CNavNode *v37; // ecx
  CNavNode *v38; // edx
  int count; // [esp+18h] [ebp-10h]
  int a; // [esp+20h] [ebp-8h]
  NavDirType dir; // [esp+24h] [ebp-4h]
  NavDirType dira; // [esp+24h] [ebp-4h]
  CNavArea *newAreaa; // [esp+30h] [ebp+8h]

  v4 = this;
  newArea->InheritAttributes(this: newArea, a2: this, a3: nullptr);
  x = newArea->m_seCorner.x;
  v6 = newArea->m_nwCorner.x;
  v7 = newArea->m_seCorner.y;
  newArea->m_center.x = (float)(v6 + x) * 0.5;
  y = newArea->m_nwCorner.y;
  newArea->m_center.y = (float)(y + v7) * 0.5;
  newArea->m_center.z = (float)(newArea->m_seCorner.z + newArea->m_nwCorner.z) * 0.5;
  newArea->m_neZ = CNavArea::GetZ(this: v4, x, y);
  newArea->m_swZ = CNavArea::GetZ(this: v9, x: v6, y: v7);
  v10 = 0.0;
  if ( (float)(v4->m_seCorner.x - v4->m_nwCorner.x) <= 0.0 || (float)(v4->m_seCorner.y - v4->m_nwCorner.y) <= 0.0 )
  {
    newArea->m_invDxCorners = 0.0;
  }
  else
  {
    newArea->m_invDxCorners = 1.0 / (float)(x - v6);
    v10 = 1.0 / (float)(v7 - newArea->m_nwCorner.y);
  }
  newArea->m_invDyCorners = v10;
  v11 = NORTH;
  newAreaa = (CNavArea *)v4->m_connect;
  do
  {
    if ( v11 != ignoreEdge )
    {
      count = (int)newAreaa->dtr_CNavArea;
      a = 0;
      if ( count > 0 )
      {
        do
        {
          dtr_CNavArea = (int)newAreaa->dtr_CNavArea;
          v13 = a;
          v14 = 0;
          if ( dtr_CNavArea <= 0 )
          {
LABEL_11:
            v15 = nullptr;
          }
          else
          {
            while ( v13 != 0 )
            {
              ++v14;
              --v13;
              if ( v14 >= dtr_CNavArea )
                goto LABEL_11;
            }
            v15 = *((CNavArea **)&newAreaa->OnServerActivate + 2 * v14);
          }
          switch ( v11 )
          {
            case NORTH:
            case SOUTH:
              if ( newArea->m_seCorner.x > v15->m_nwCorner.x && v15->m_seCorner.x > newArea->m_nwCorner.x )
              {
                CNavArea::ConnectTo(this: newArea, area: v15, dir: v11);
                dir = OppositeDirection(dir: v11);
                if ( CNavArea::IsConnected(this: v15, area: this, dir) != 0 )
                  goto LABEL_21;
              }
              break;
            case EAST:
            case WEST:
              if ( newArea->m_seCorner.y > v15->m_nwCorner.y && v15->m_seCorner.y > newArea->m_nwCorner.y )
              {
                CNavArea::ConnectTo(this: newArea, area: v15, dir: v11);
                dir = OppositeDirection(dir: v11);
                if ( CNavArea::IsConnected(this: v15, area: this, dir) != 0 )
LABEL_21:
                  CNavArea::ConnectTo(this: v15, area: newArea, dir);
              }
              break;
            default:
              break;
          }
          v16 = newAreaa->m_blockedTimer.__vftable;
          v17 = NORTH;
          for ( dira = NORTH; v17 < (int)v16->NetworkStateChanged; dira = v17 )
          {
            NetworkStateChanged_2 = (CNavArea *)v16[v17].NetworkStateChanged_2;
            switch ( v11 )
            {
              case NORTH:
              case SOUTH:
                if ( newArea->m_seCorner.x > NetworkStateChanged_2->m_nwCorner.x )
                {
                  v19 = NetworkStateChanged_2->m_seCorner.x <= newArea->m_nwCorner.x;
                  goto LABEL_28;
                }
                break;
              case EAST:
              case WEST:
                if ( newArea->m_seCorner.y > NetworkStateChanged_2->m_nwCorner.y )
                {
                  v19 = NetworkStateChanged_2->m_seCorner.y <= newArea->m_nwCorner.y;
LABEL_28:
                  if ( !v19 )
                  {
                    v20 = OppositeDirection(dir: v11);
                    CNavArea::ConnectTo(this: NetworkStateChanged_2, area: newArea, dir: v20);
                  }
                }
                break;
              default:
                break;
            }
            v16 = newAreaa->m_blockedTimer.__vftable;
            v17 = dira + 1;
          }
          ++a;
        }
        while ( a < count );
        v4 = this;
      }
    }
    newAreaa = (CNavArea *)((char *)newAreaa + 4);
    ++v11;
  }
  while ( v11 < NUM_DIRECTIONS );
  m_Size = TheNavAreas.m_Size;
  v22 = TheNavAreas.m_Size;
  if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
      num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
    m_Size = TheNavAreas.m_Size;
  }
  m_pMemory = TheNavAreas.m_Memory.m_pMemory;
  TheNavAreas.m_Size = m_Size + 1;
  v24 = m_Size - v22;
  TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
  if ( v24 > 0 )
  {
    _V_memmove(
      dest: &TheNavAreas.m_Memory.m_pMemory[v22 + 1],
      src: &TheNavAreas.m_Memory.m_pMemory[v22],
      count: 4 * v24);
    m_pMemory = TheNavAreas.m_Memory.m_pMemory;
  }
  v25 = &m_pMemory[v22];
  if ( v25 != nullptr )
    *v25 = newArea;
  CNavMesh::AddNavArea(this: TheNavMesh, area: newArea);
  v26 = 0;
  for ( i = v4->m_node; *i == nullptr; ++i )
  {
    if ( ++v26 >= 4 )
      return;
  }
  newArea->m_node[0] = v4->m_node[0];
  newArea->m_node[1] = v4->m_node[1];
  newArea->m_node[2] = v4->m_node[2];
  newArea->m_node[3] = v4->m_node[3];
  v28 = 4;
  v29 = 4;
  v30 = 4;
  switch ( ignoreEdge )
  {
    case NORTH:
      v28 = 2;
      v30 = 1;
      goto LABEL_49;
    case EAST:
      v28 = 3;
      v29 = 1;
      v30 = 2;
      break;
    case SOUTH:
      v28 = 0;
      v29 = 3;
      v30 = 2;
      break;
    case WEST:
      v28 = 1;
      v30 = 3;
LABEL_49:
      v29 = 0;
      break;
    default:
      break;
  }
  v31 = newArea->m_nwCorner.x;
  while ( 1 )
  {
    v32 = newArea->m_node[v29];
    if ( (float)(v32->m_pos.x + 12.5) >= v31
      && newArea->m_seCorner.x >= (float)(v32->m_pos.x - 12.5)
      && (float)(v32->m_pos.y + 12.5) >= newArea->m_nwCorner.y
      && newArea->m_seCorner.y >= (float)(v32->m_pos.y - 12.5) )
    {
      break;
    }
    newArea->m_node[v29] = v32->m_to[v28];
    newArea->m_node[v30] = newArea->m_node[v30]->m_to[v28];
  }
  v33 = newArea->m_node[0];
  for ( j = newArea->m_node[1]; v33 != newArea->m_node[3]; j = j->m_to[2] )
  {
    for ( k = v33; k != j; k = k->m_to[1] )
      k->m_area = newArea;
    v33 = v33->m_to[2];
  }
  v36 = newArea->m_node[0];
  v37 = newArea->m_node[3];
  newArea->m_neZ = newArea->m_node[1]->m_pos.z;
  v38 = newArea->m_node[2];
  newArea->m_nwCorner.z = v36->m_pos.z;
  newArea->m_swZ = v37->m_pos.z;
  newArea->m_seCorner.z = v38->m_pos.z;
}

//------------------------------------------------------------------------------
// Address: 0x102FE1D0
// Name: public: bool CNavArea::SpliceEdit(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNavArea::SpliceEdit@<al>(CNavArea *this@<ecx>, int a2@<edi>, CNavArea *other)
{
  float x; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  CNavArea *v8; // ecx
  CNavArea *v9; // esi
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  CNavArea *v15; // ecx
  float v16; // xmm7_4
  float v17; // xmm7_4
  int m_Size; // eax
  int v19; // edi
  CNavArea **m_pMemory; // ecx
  int v21; // eax
  CNavArea **v22; // eax
  float y; // [esp+4h] [ebp-40h]
  float ya; // [esp+4h] [ebp-40h]
  float yb; // [esp+4h] [ebp-40h]
  float yc; // [esp+4h] [ebp-40h]
  Vector nw; // [esp+14h] [ebp-30h] BYREF
  Vector ne; // [esp+20h] [ebp-24h] BYREF
  Vector sw; // [esp+2Ch] [ebp-18h] BYREF
  Vector se; // [esp+38h] [ebp-Ch] BYREF

  x = other->m_seCorner.x;
  v5 = this->m_nwCorner.x;
  if ( v5 <= x )
  {
    v11 = this->m_seCorner.x;
    v12 = other->m_nwCorner.x;
    if ( v12 <= v11 )
    {
      v16 = other->m_seCorner.y;
      if ( this->m_nwCorner.y <= v16 )
      {
        v17 = this->m_seCorner.y;
        if ( other->m_nwCorner.y <= v17 )
          return 0;
        if ( v5 <= v12 )
          v5 = other->m_nwCorner.x;
        if ( x > v11 )
          x = this->m_seCorner.x;
        yb = this->m_seCorner.y;
        nw.x = v5;
        nw.y = v17;
        nw.z = CNavArea::GetZ(this, x: v5, y: yb);
        yc = other->m_nwCorner.y;
        se.x = x;
        se.y = yc;
        se.z = CNavArea::GetZ(this: other, x, y: yc);
        ne.x = x;
        ne.y = v17;
        ne.z = CNavArea::GetZ(this, x, y: v17);
        sw.x = v5;
        sw.y = se.y;
        sw.z = CNavArea::GetZ(this: other, x: v5, y: se.y);
        v9 = TheNavMesh->CreateArea(this: TheNavMesh);
        if ( v9 == nullptr )
        {
LABEL_7:
          _Warning(a1: "SpliceEdit: Out of memory.\n");
          return 0;
        }
        CNavArea::Build(this: v9, nwCorner: &nw, neCorner: &ne, seCorner: &se, swCorner: &sw);
        CNavArea::ConnectTo(this, area: v9, dir: SOUTH);
        CNavArea::ConnectTo(this: v9, area: this, dir: NORTH);
        CNavArea::ConnectTo(this: other, area: v9, dir: NORTH);
        CNavArea::ConnectTo(this: v9, area: other, dir: SOUTH);
      }
      else
      {
        if ( v5 <= v12 )
          v5 = other->m_nwCorner.x;
        if ( x > v11 )
          x = this->m_seCorner.x;
        y = other->m_seCorner.y;
        nw.x = v5;
        nw.y = v16;
        nw.z = CNavArea::GetZ(this: other, x: v5, y);
        ya = this->m_nwCorner.y;
        se.x = x;
        se.y = ya;
        se.z = CNavArea::GetZ(this, x, y: ya);
        ne.x = x;
        ne.y = v16;
        ne.z = CNavArea::GetZ(this: other, x, y: v16);
        sw.x = v5;
        sw.y = se.y;
        sw.z = CNavArea::GetZ(this, x: v5, y: se.y);
        v9 = TheNavMesh->CreateArea(this: TheNavMesh);
        if ( v9 == nullptr )
          goto LABEL_7;
        CNavArea::Build(this: v9, nwCorner: &nw, neCorner: &ne, seCorner: &se, swCorner: &sw);
        CNavArea::ConnectTo(this, area: v9, dir: NORTH);
        CNavArea::ConnectTo(this: v9, area: this, dir: SOUTH);
        CNavArea::ConnectTo(this: other, area: v9, dir: SOUTH);
        CNavArea::ConnectTo(this: v9, area: other, dir: NORTH);
      }
    }
    else
    {
      v13 = other->m_nwCorner.y;
      if ( this->m_nwCorner.y > v13 )
        v13 = this->m_nwCorner.y;
      v14 = other->m_seCorner.y;
      if ( v14 > this->m_seCorner.y )
        v14 = this->m_seCorner.y;
      nw.x = this->m_seCorner.x;
      nw.y = v13;
      nw.z = CNavArea::GetZ(this, x: v11, y: v13);
      se.x = other->m_nwCorner.x;
      se.y = v14;
      se.z = CNavArea::GetZ(this: other, x: se.x, y: v14);
      ne.x = se.x;
      ne.y = v13;
      ne.z = CNavArea::GetZ(this: v15, x: se.x, y: v13);
      sw.x = nw.x;
      sw.y = v14;
      sw.z = CNavArea::GetZ(this, x: nw.x, y: v14);
      v9 = TheNavMesh->CreateArea(this: TheNavMesh);
      if ( v9 == nullptr )
        goto LABEL_7;
      CNavArea::Build(this: v9, nwCorner: &nw, neCorner: &ne, seCorner: &se, swCorner: &sw);
      CNavArea::ConnectTo(this, area: v9, dir: EAST);
      CNavArea::ConnectTo(this: v9, area: this, dir: WEST);
      CNavArea::ConnectTo(this: other, area: v9, dir: WEST);
      CNavArea::ConnectTo(this: v9, area: other, dir: EAST);
    }
  }
  else
  {
    v6 = other->m_nwCorner.y;
    if ( this->m_nwCorner.y > v6 )
      v6 = this->m_nwCorner.y;
    v7 = other->m_seCorner.y;
    if ( v7 > this->m_seCorner.y )
      v7 = this->m_seCorner.y;
    nw.x = other->m_seCorner.x;
    nw.y = v6;
    nw.z = CNavArea::GetZ(this: other, x, y: v6);
    se.x = this->m_nwCorner.x;
    se.y = v7;
    se.z = CNavArea::GetZ(this, x: se.x, y: v7);
    ne.x = se.x;
    ne.y = v6;
    ne.z = CNavArea::GetZ(this: v8, x: se.x, y: v6);
    sw.x = x;
    sw.y = v7;
    sw.z = CNavArea::GetZ(this: other, x, y: v7);
    v9 = TheNavMesh->CreateArea(this: TheNavMesh);
    if ( v9 == nullptr )
      goto LABEL_7;
    CNavArea::Build(this: v9, nwCorner: &nw, neCorner: &ne, seCorner: &se, swCorner: &sw);
    CNavArea::ConnectTo(this, area: v9, dir: WEST);
    CNavArea::ConnectTo(this: v9, area: this, dir: EAST);
    CNavArea::ConnectTo(this: other, area: v9, dir: EAST);
    CNavArea::ConnectTo(this: v9, area: other, dir: WEST);
  }
  ((void (__thiscall *)(CNavArea *, CNavArea *, CNavArea *, int))v9->InheritAttributes)(
    a1: v9,
    a2: this,
    a3: other,
    a4: a2);
  m_Size = TheNavAreas.m_Size;
  v19 = TheNavAreas.m_Size;
  if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
      num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
    m_Size = TheNavAreas.m_Size;
  }
  m_pMemory = TheNavAreas.m_Memory.m_pMemory;
  TheNavAreas.m_Size = m_Size + 1;
  v21 = m_Size - v19;
  TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
  if ( v21 > 0 )
  {
    _V_memmove(
      dest: &TheNavAreas.m_Memory.m_pMemory[v19 + 1],
      src: &TheNavAreas.m_Memory.m_pMemory[v19],
      count: 4 * v21);
    m_pMemory = TheNavAreas.m_Memory.m_pMemory;
  }
  v22 = &m_pMemory[v19];
  if ( v22 != nullptr )
    *v22 = v9;
  CNavMesh::AddNavArea(this: TheNavMesh, area: v9);
  TheNavMesh->OnEditCreateNotify(this: TheNavMesh, a2: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FE6D0
// Name: public: bool CNavArea::MergeEdit(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::MergeEdit(CNavArea *this, CNavArea *adj)
{
  CNavArea *v2; // edi
  float v3; // xmm5_4
  CNavArea *v4; // esi
  bool result; // al
  float v6; // xmm2_4
  float x; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float y; // xmm2_4
  CNavArea *v12; // ecx
  __int64 originalSECorner; // [esp+10h] [ebp-18h]
  __int64 originalNWCorner; // [esp+1Ch] [ebp-Ch]

  v2 = adj;
  v3 = adj->m_nwCorner.x;
  v4 = this;
  result = false;
  if ( fabs(this->m_nwCorner.x - v3) < 1.0 )
    result = fabs(this->m_seCorner.x - adj->m_seCorner.x) < 1.0;
  v6 = adj->m_nwCorner.y;
  if ( fabs(this->m_nwCorner.y - v6) < 1.0 && fabs(this->m_seCorner.y - adj->m_seCorner.y) < 1.0 || result )
  {
    originalNWCorner = *(_QWORD *)&this->m_nwCorner.x;
    originalSECorner = *(_QWORD *)&this->m_seCorner.x;
    if ( this->m_nwCorner.x > v3 || this->m_nwCorner.y > v6 )
    {
      this->m_nwCorner.x = adj->m_nwCorner.x;
      this->m_nwCorner.y = v2->m_nwCorner.y;
      this->m_nwCorner.z = v2->m_nwCorner.z;
    }
    if ( v2->m_seCorner.x > this->m_seCorner.x || v2->m_seCorner.y > this->m_seCorner.y )
      this->m_seCorner = v2->m_seCorner;
    x = this->m_seCorner.x;
    v8 = this->m_nwCorner.x;
    v9 = this->m_seCorner.y;
    v10 = 0.0;
    this->m_center.x = (float)(x + v8) * 0.5;
    y = this->m_nwCorner.y;
    this->m_center.y = (float)(v9 + y) * 0.5;
    this->m_center.z = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
    if ( (float)(x - v8) <= 0.0 || (float)(v9 - y) <= 0.0 )
    {
      this->m_invDyCorners = 0.0;
    }
    else
    {
      v10 = 1.0 / (float)(x - v8);
      this->m_invDyCorners = 1.0 / (float)(v9 - y);
    }
    this->m_invDxCorners = v10;
    if ( x > *(float *)&originalSECorner || *((float *)&originalNWCorner + 1) > y )
      this = v2;
    v4->m_neZ = CNavArea::GetZ(this, x, y);
    if ( *(float *)&originalNWCorner > v8 || (v12 = v4, v9 > *((float *)&originalSECorner + 1)) )
      v12 = v2;
    v4->m_swZ = CNavArea::GetZ(this: v12, x: v8, y: v9);
    CNavArea::MergeAdjacentConnections(this: v4, adjArea: v2);
    v4->InheritAttributes(this: v4, a2: v2, a3: nullptr);
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheNavAreas,
      src: (vgui::TreeNode **)&adj);
    TheNavMesh->OnEditDestroyNotify_2(this: TheNavMesh, a2: v2);
    TheNavMesh->DestroyArea(this: TheNavMesh, a2: v2);
    TheNavMesh->OnEditCreateNotify(this: TheNavMesh, a2: v4);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FE8F0
// Name: public: void CNavArea::RemoveOrthogonalConnections(enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::RemoveOrthogonalConnections(CNavArea *this, int dir)
{
  int v3; // eax
  NavDirType v4; // ebx
  CNavArea *AdjacentArea; // edi
  NavDirType dirToRemove[2]; // [esp+Ch] [ebp-8h]
  int i; // [esp+1Ch] [ebp+8h]

  switch ( dir )
  {
    case 0:
      dirToRemove[0] = WEST;
      break;
    case 1:
      dirToRemove[0] = NORTH;
      break;
    case 2:
      dirToRemove[0] = EAST;
      break;
    case 3:
      dirToRemove[0] = SOUTH;
      break;
    default:
      dirToRemove[0] = NORTH;
      break;
  }
  switch ( dir )
  {
    case 0:
      dirToRemove[1] = EAST;
      break;
    case 1:
      dirToRemove[1] = SOUTH;
      break;
    case 2:
      dirToRemove[1] = WEST;
      break;
    default:
      dirToRemove[1] = NORTH;
      break;
  }
  v3 = 0;
  i = 0;
  do
  {
    v4 = dirToRemove[v3];
    if ( this->m_connect[v4].m_pData->m_Size > 0 )
    {
      do
      {
        AdjacentArea = CNavArea::GetAdjacentArea(this, dir: v4, i: 0);
        CNavArea::Disconnect(this, area: AdjacentArea);
        CNavArea::Disconnect(this: AdjacentArea, area: this);
      }
      while ( this->m_connect[v4].m_pData->m_Size > 0 );
      v3 = i;
    }
    i = ++v3;
  }
  while ( v3 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x102FE9D0
// Name: private: void CNavArea::AddSpotEncounters(class CNavArea const __near *,enum NavDirType,class CNavArea const __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::AddSpotEncounters(
        CNavArea *this,
        CNavArea *from,
        NavDirType fromDir,
        CNavArea *to,
        int toDir)
{
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  NavDirType v8; // eax
  float v9; // xmm5_4
  float v10; // xmm7_4
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  NavDirType v12; // ecx
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  unsigned int v16; // esi
  float v17; // xmm0_4
  CNavArea *v18; // esi
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v19; // ecx
  int m_Size; // ebx
  int v21; // eax
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v22; // eax
  int x; // [esp+0h] [ebp-B0h]
  CGameTrace result; // [esp+14h] [ebp-9Ch] BYREF
  Vector eye; // [esp+68h] [ebp-48h] BYREF
  Vector vecAbsEnd; // [esp+74h] [ebp-3Ch] BYREF
  SpotOrder spotOrder; // [esp+80h] [ebp-30h] BYREF
  Vector delta; // [esp+88h] [ebp-28h] BYREF
  float v29; // [esp+94h] [ebp-1Ch]
  float v30; // [esp+98h] [ebp-18h]
  float v31; // [esp+9Ch] [ebp-14h]
  CNavArea *v32; // [esp+A0h] [ebp-10h]
  Vector dir; // [esp+A4h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+B0h] [ebp+0h] BYREF
  signed int done; // [esp+B8h] [ebp+8h]
  char done_3; // [esp+BBh] [ebp+Bh]
  float along; // [esp+BCh] [ebp+Ch]
  float length; // [esp+C0h] [ebp+10h]

  v32 = this;
  v6 = operator new(nSize: 0x44u);
  v7 = nullptr;
  if ( v6 != nullptr )
  {
    *v6 = 0;
    v6[1] = -1082130432;
    v6[3] = 0;
    v6[4] = -1082130432;
    v6[12] = 0;
    v6[13] = 0;
    v6[14] = 0;
    v6[15] = 0;
    v6[16] = 0;
    v7 = v6;
  }
  *v7 = from;
  v8 = toDir;
  v7[2] = fromDir;
  v7[3] = to;
  v7[5] = v8;
  CNavArea::ComputePortal(this, to, dir: v8, center: (Vector *)v7 + 3, halfWidth: (float *)&toDir);
  CNavArea::ComputePortal(this: v32, to: from, dir: fromDir, center: (Vector *)v7 + 2, halfWidth: (float *)&toDir);
  *((float *)v7 + 8) = CNavArea::GetZ(this: from, x: *((float *)v7 + 6), y: *((float *)v7 + 7)) + 62.0;
  *((float *)v7 + 11) = CNavArea::GetZ(this: to, x: *((float *)v7 + 9), y: *((float *)v7 + 10)) + 62.0;
  dir.x = *((float *)v7 + 9) - *((float *)v7 + 6);
  dir.y = *((float *)v7 + 10) - *((float *)v7 + 7);
  dir.z = *((float *)v7 + 11) - *((float *)v7 + 8);
  length = VectorNormalize(vec: &dir);
  v9 = 0.0;
  v10 = length;
  m_pData = TheHidingSpots.m_pData;
  ++HidingSpot::m_masterMarker;
  done_3 = 0;
  along = 0.0;
  do
  {
    if ( v9 >= v10 )
    {
      v9 = v10;
      along = v10;
      done_3 = 1;
    }
    v12 = NORTH;
    v13 = *((float *)v7 + 6) + (float)(dir.x * v9);
    v14 = *((float *)v7 + 7) + (float)(dir.y * v9);
    v15 = (float)(dir.z * v9) + *((float *)v7 + 8);
    v29 = v13;
    v30 = v14;
    v31 = v15;
    eye.x = v13;
    eye.y = v14;
    eye.z = v15;
    toDir = 0;
    if ( m_pData->m_Size > 0 )
    {
      while ( 1 )
      {
        v16 = (unsigned int)m_pData->m_Elements[v12];
        if ( (*(_BYTE *)(v16 + 28) & 1) != 0 && *(_DWORD *)(v16 + 20) != HidingSpot::m_masterMarker )
        {
          delta.x = *(float *)(v16 + 4) - v13;
          delta.y = *(float *)(v16 + 8) - v14;
          delta.z = (float)(*(float *)(v16 + 12) + 62.0) - v15;
          if ( (float)((float)((float)(delta.y * delta.y) + (float)(delta.x * delta.x)) + (float)(delta.z * delta.z)) <= 4000000.0 )
            break;
        }
LABEL_21:
        v12 = toDir + 1;
        toDir = v12;
        if ( v12 >= m_pData->m_Size )
        {
          v10 = length;
          goto LABEL_23;
        }
        v15 = v31;
      }
      vecAbsEnd.x = *(float *)(v16 + 4);
      vecAbsEnd.y = *(float *)(v16 + 8);
      vecAbsEnd.z = *(float *)(v16 + 12) + 35.5;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: v16,
        vecAbsStart: &eye,
        &vecAbsEnd,
        mask: 0x2400Bu,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: &result);
      if ( result.fraction != 1.0 )
      {
        v9 = along;
        goto LABEL_20;
      }
      VectorNormalize(vec: &delta);
      v17 = (float)((float)(dir.y * delta.y) + (float)(dir.x * delta.x)) + (float)(dir.z * delta.z);
      if ( v17 < 0.70709997 && v17 > -0.70709997 )
      {
        v9 = along;
        if ( along <= 0.0 )
        {
LABEL_18:
          *(_DWORD *)(v16 + 20) = HidingSpot::m_masterMarker;
LABEL_20:
          v13 = v29;
          v14 = v30;
          m_pData = TheHidingSpots.m_pData;
          goto LABEL_21;
        }
        x = v7[15];
        spotOrder.id = v16;
        spotOrder.t = along / length;
        CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
          this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)(v7 + 12),
          elem: x,
          src: (const AI_NamespaceAddInfo_t *)&spotOrder);
      }
      v9 = along;
      goto LABEL_18;
    }
LABEL_23:
    v9 = v9 + 25.0;
    along = v9;
  }
  while ( done_3 == 0 );
  v18 = v32;
  v19 = v32->m_spotEncounters.m_pData;
  m_Size = v19->m_Size;
  v21 = v19->m_Size + 1;
  if ( v21 > v19->m_Size )
  {
    if ( v19 == (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      v22 = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v21 + 4);
      v18->m_spotEncounters.m_pData = v22;
      v22->m_Size = 0;
    }
    else
    {
      done = 4 * v21 + 4;
      if ( done > (int)_msize(pMem: v19) )
        v18->m_spotEncounters.m_pData = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: v18->m_spotEncounters.m_pData, size: done);
    }
  }
  v18->m_spotEncounters.m_pData->m_Elements[m_Size] = (SpotEncounter *)v7;
  ++v18->m_spotEncounters.m_pData->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102FED90
// Name: public: virtual void CNavArea::ComputeSpotEncounters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ComputeSpotEncounters(CNavArea *this)
{
  CNavArea *v1; // esi
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  NavDirType v3; // edx
  int **m_connect; // eax
  CNavArea **v5; // edi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v6; // ecx
  int v7; // ebx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v8; // eax
  int i; // esi
  CNavArea **v10; // eax
  int fromDir; // [esp+4h] [ebp-14h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v12; // [esp+8h] [ebp-10h]
  int it; // [esp+10h] [ebp-8h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v15; // [esp+14h] [ebp-4h]

  v1 = this;
  m_pData = this->m_spotEncounters.m_pData;
  if ( m_pData != (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: m_pData);
    v1->m_spotEncounters.m_pData = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
  if ( nav_quicksave.m_pParent == nullptr || nav_quicksave.m_pParent->m_Value.m_nValue == 0 )
  {
    v3 = NORTH;
    m_connect = (int **)v1->m_connect;
    fromDir = 0;
    v15 = v1->m_connect;
    do
    {
      it = 0;
      if ( **m_connect > 0 )
      {
        do
        {
          v5 = (CNavArea **)&v15->m_pData->m_Elements[it];
          v6 = v1->m_connect;
          v7 = 0;
          v12 = v1->m_connect;
          do
          {
            v8 = v6->m_pData;
            for ( i = 0; i < v6->m_pData->m_Size; ++i )
            {
              v10 = (CNavArea **)&v8->m_Elements[i];
              if ( v10 != v5 )
              {
                CNavArea::AddSpotEncounters(this, from: *v5, fromDir: v3, to: *v10, toDir: v7);
                v3 = fromDir;
                v6 = v12;
              }
              v8 = v6->m_pData;
            }
            ++v7;
            v12 = ++v6;
          }
          while ( v7 < 4 );
          v1 = this;
          ++it;
        }
        while ( it < v15->m_pData->m_Size );
      }
      ++v3;
      m_connect = (int **)&v15[1];
      fromDir = v3;
      ++v15;
    }
    while ( v3 < NUM_DIRECTIONS );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FEE80
// Name: private: static void CNavArea::ComputeVisToArea(class CNavArea __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CNavArea::ComputeVisToArea(CNavArea **pOtherArea)
{
  CNavArea *v1; // esi
  CNavArea::VisibilityType v2; // ebx
  CNavArea::VisibilityType v3; // eax
  TSLNodeBase_t *v4; // eax
  CNavArea *v5; // ebx
  int m_Size; // edi
  _DWORD *p_id; // edi
  TSLNodeBase_t *info_4; // [esp+Ch] [ebp-8h]
  CNavArea::VisibilityType visOtherToThis; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  v1 = *pOtherArea;
  visOtherToThis = NOT_VISIBLE;
  v2 = *pOtherArea != g_pCurVisArea ? NOT_VISIBLE : COMPLETELY_VISIBLE;
  if ( *pOtherArea == g_pCurVisArea )
  {
    if ( (*pOtherArea != g_pCurVisArea ? 0 : 2) == 0 )
      return;
    goto LABEL_13;
  }
  v3 = CNavArea::ComputeVisibility(
         this: g_pCurVisArea,
         a2: COERCE_FLOAT(&savedregs),
         area: v1,
         isPVSValid: true,
         bCheckPVS: true,
         pOutsidePVS: (bool *)&pOtherArea + 3);
  visOtherToThis = v3;
  if ( HIBYTE(pOtherArea) != 0 )
  {
LABEL_6:
    if ( v3 != NOT_VISIBLE )
      goto LABEL_9;
    goto LABEL_7;
  }
  if ( v3 != NOT_VISIBLE
    || (float)(nav_max_view_distance.m_pParent->m_Value.m_fValue * nav_max_view_distance.m_pParent->m_Value.m_fValue) > (float)((float)((float)((float)(g_pCurVisArea->m_center.x - v1->m_center.x) * (float)(g_pCurVisArea->m_center.x - v1->m_center.x)) + (float)((float)(g_pCurVisArea->m_center.y - v1->m_center.y) * (float)(g_pCurVisArea->m_center.y - v1->m_center.y))) + (float)((float)(g_pCurVisArea->m_center.z - v1->m_center.z) * (float)(g_pCurVisArea->m_center.z - v1->m_center.z))) )
  {
    v2 = CNavArea::ComputeVisibility(
           this: v1,
           a2: COERCE_FLOAT(&savedregs),
           area: g_pCurVisArea,
           isPVSValid: true,
           bCheckPVS: false,
           pOutsidePVS: nullptr);
    v3 = visOtherToThis;
    goto LABEL_6;
  }
LABEL_7:
  if ( v2 == NOT_VISIBLE )
    return;
  visOtherToThis = POTENTIALLY_VISIBLE;
LABEL_9:
  if ( v2 == NOT_VISIBLE )
  {
    if ( visOtherToThis == NOT_VISIBLE )
      return;
    LOBYTE(v2) = 1;
  }
LABEL_13:
  LOBYTE(info_4) = v2;
  v4 = CTSListBase::Pop(this: &g_ComputedVis.m_FreeList);
  if ( v4 == nullptr )
    v4 = (TSLNodeBase_t *)operator new(nSize: 0x10u);
  *((_DWORD *)&v4->Next + 1) = v1;
  v4[1].Next = info_4;
  CTSListBase::Push(this: &g_ComputedVis, pNode: v4);
  if ( visOtherToThis != NOT_VISIBLE )
  {
    v5 = g_pCurVisArea;
    m_Size = v1->m_potentiallyVisibleAreas.m_Size;
    LOBYTE(info_4) = visOtherToThis;
    CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
      this: &v1->m_potentiallyVisibleAreas,
      num: 1);
    if ( v1->m_potentiallyVisibleAreas.m_Size - m_Size - 1 > 0 )
      _V_memmove(
        dest: &v1->m_potentiallyVisibleAreas.m_Memory.m_pMemory[m_Size + 1],
        src: &v1->m_potentiallyVisibleAreas.m_Memory.m_pMemory[m_Size],
        count: 8 * (v1->m_potentiallyVisibleAreas.m_Size - m_Size - 1));
    p_id = &v1->m_potentiallyVisibleAreas.m_Memory.m_pMemory[m_Size].id;
    if ( p_id != nullptr )
    {
      *p_id = v5;
      p_id[1] = info_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FEFF0
// Name: public: class CNavNode __near * CNavArea::FindClosestNode(class Vector const __near &,enum NavDirType)const
// Source: json
//------------------------------------------------------------------------------
CNavNode *__thiscall CNavArea::FindClosestNode(CNavArea *this, const Vector *pos, NavDirType dir)
{
  int v3; // eax
  CNavNode **i; // edx
  float v6; // xmm3_4
  CNavNode *v7; // edi
  int j; // ecx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  CNavNode *v12; // eax
  CUtlVector<CNavNode *,CUtlMemory<CNavNode *,int> > nodes; // [esp+4h] [ebp-14h] BYREF

  v3 = 0;
  for ( i = this->m_node; *i == nullptr; ++i )
  {
    if ( ++v3 >= 4 )
      return nullptr;
  }
  memset(&nodes, 0, sizeof(nodes));
  CNavArea::GetNodes(this, dir, (CUtlMemory<vgui::TreeNode *,int> *)&nodes);
  v6 = 3.4028235e38;
  v7 = nullptr;
  for ( j = 0; j < nodes.m_Size; ++j )
  {
    v12 = nodes.m_Memory.m_pMemory[j];
    x = pos->x;
    y = pos->y;
    z = pos->z;
    if ( v6 > (float)((float)((float)((float)(y - v12->m_pos.y) * (float)(y - v12->m_pos.y))
                            + (float)((float)(x - v12->m_pos.x) * (float)(x - v12->m_pos.x)))
                    + (float)((float)(z - v12->m_pos.z) * (float)(z - v12->m_pos.z))) )
    {
      v6 = (float)((float)((float)(y - v12->m_pos.y) * (float)(y - v12->m_pos.y))
                 + (float)((float)(x - v12->m_pos.x) * (float)(x - v12->m_pos.x)))
         + (float)((float)(z - v12->m_pos.z) * (float)(z - v12->m_pos.z));
      v7 = nodes.m_Memory.m_pMemory[j];
    }
  }
  if ( nodes.m_Memory.m_nGrowSize >= 0 && nodes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: nodes.m_Memory.m_pMemory);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x102FF0C0
// Name: private: void CNavArea::FinishMerge(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::FinishMerge(CNavArea *this, CNavArea *adjArea)
{
  float v3; // xmm2_4
  float x; // xmm0_4
  float v5; // xmm1_4
  float y; // xmm4_4
  CNavNode *v7; // eax
  CNavNode *v8; // ecx
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  CNavArea *v13; // edi
  CNavArea *v14; // ecx

  v3 = 0.0;
  this->m_nwCorner = this->m_node[0]->m_pos;
  this->m_seCorner = this->m_node[2]->m_pos;
  x = this->m_seCorner.x;
  v5 = this->m_nwCorner.x;
  y = this->m_nwCorner.y;
  v7 = this->m_node[1];
  v8 = this->m_node[3];
  v9 = v5 + x;
  v10 = x - this->m_nwCorner.x;
  this->m_center.x = v9 * 0.5;
  v11 = this->m_seCorner.y;
  this->m_center.y = (float)(y + v11) * 0.5;
  this->m_center.z = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
  this->m_neZ = v7->m_pos.z;
  this->m_swZ = v8->m_pos.z;
  if ( v10 <= 0.0 || (v12 = v11 - y) <= 0.0 )
  {
    this->m_invDxCorners = 0.0;
  }
  else
  {
    this->m_invDxCorners = 1.0 / v10;
    v3 = 1.0 / v12;
  }
  v13 = adjArea;
  v14 = adjArea;
  this->m_invDyCorners = v3;
  CNavArea::AssignNodes(this: v14, area: this);
  CNavArea::MergeAdjacentConnections(this, adjArea: v13);
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheNavAreas,
    src: (vgui::TreeNode **)&adjArea);
  TheNavMesh->OnEditDestroyNotify_2(this: TheNavMesh, a2: v13);
  TheNavMesh->DestroyArea(this: TheNavMesh, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x102FF1E0
// Name: public: bool CNavArea::SplitEdit(bool,float,class CNavArea __near * __near *,class CNavArea __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavArea::SplitEdit(
        CNavArea *this,
        int splitAlongX,
        float splitEdge,
        CNavArea **outAlpha,
        CNavArea **outBeta)
{
  CNavArea *v5; // ebx
  CNavArea *v7; // eax
  float y; // xmm0_4
  CNavArea *v9; // esi
  double x; // st7
  CNavArea *v11; // eax
  float v12; // xmm0_4
  CNavArea *v13; // edi
  CNavArea *v14; // eax
  float v15; // xmm0_4
  bool v16; // cc
  CNavLadder *v17; // ebx
  __int64 v18; // xmm0_8
  double DistanceSquaredToPoint; // st6
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // ecx
  _DWORD *v21; // ecx
  Vector ladderPos; // [esp+14h] [ebp-20h] BYREF
  CNavArea *p_m_Size; // [esp+20h] [ebp-14h]
  float v24; // [esp+24h] [ebp-10h]
  float v25; // [esp+28h] [ebp-Ch]
  NavLadderConnect src; // [esp+2Ch] [ebp-8h] BYREF
  int i; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  v5 = this;
  p_m_Size = this;
  if ( (_BYTE)splitAlongX != 0 )
  {
    if ( (float)(this->m_nwCorner.y + 1.0) < splitEdge && splitEdge < (float)(this->m_seCorner.y - 1.0) )
    {
      v7 = TheNavMesh->CreateArea(this: TheNavMesh);
      y = splitEdge;
      v9 = v7;
      v7->m_nwCorner.x = v5->m_nwCorner.x;
      v7->m_nwCorner.y = v5->m_nwCorner.y;
      v7->m_nwCorner.z = v5->m_nwCorner.z;
      x = v5->m_seCorner.x;
      v7->m_seCorner.y = y;
      v7->m_seCorner.x = x;
      v7->m_seCorner.z = CNavArea::GetZ(this: v5, x: v7->m_seCorner.x, y);
      v11 = TheNavMesh->CreateArea(this: TheNavMesh);
      v12 = splitEdge;
      v13 = v11;
      v11->m_nwCorner.x = v5->m_nwCorner.x;
      v11->m_nwCorner.y = v12;
      v11->m_nwCorner.z = CNavArea::GetZ(this: v5, x: v11->m_nwCorner.x, y: v12);
      v13->m_seCorner.x = v5->m_seCorner.x;
      v13->m_seCorner.y = v5->m_seCorner.y;
      v13->m_seCorner.z = v5->m_seCorner.z;
      CNavArea::ConnectTo(this: v9, area: v13, dir: SOUTH);
      CNavArea::ConnectTo(this: v13, area: v9, dir: NORTH);
      CNavArea::FinishSplitEdit(this: v5, newArea: v9, ignoreEdge: SOUTH);
      CNavArea::FinishSplitEdit(this: v5, newArea: v13, ignoreEdge: NORTH);
      goto LABEL_9;
    }
    return 0;
  }
  if ( (float)(this->m_nwCorner.x + 1.0) >= splitEdge || splitEdge >= (float)(this->m_seCorner.x - 1.0) )
    return 0;
  v14 = TheNavMesh->CreateArea(this: TheNavMesh);
  v15 = splitEdge;
  v9 = v14;
  v14->m_nwCorner.x = v5->m_nwCorner.x;
  v14->m_nwCorner.y = v5->m_nwCorner.y;
  v14->m_nwCorner.z = v5->m_nwCorner.z;
  v14->m_seCorner.x = v15;
  v14->m_seCorner.y = v5->m_seCorner.y;
  v14->m_seCorner.z = CNavArea::GetZ(this: v5, x: v14->m_seCorner.x, y: v14->m_seCorner.y);
  v13 = TheNavMesh->CreateArea(this: TheNavMesh);
  v13->m_nwCorner.x = splitEdge;
  v13->m_nwCorner.y = v5->m_nwCorner.y;
  v13->m_nwCorner.z = CNavArea::GetZ(this: v5, x: v13->m_nwCorner.x, y: v13->m_nwCorner.y);
  v13->m_seCorner.x = v5->m_seCorner.x;
  v13->m_seCorner.y = v5->m_seCorner.y;
  v13->m_seCorner.z = v5->m_seCorner.z;
  CNavArea::ConnectTo(this: v9, area: v13, dir: EAST);
  CNavArea::ConnectTo(this: v13, area: v9, dir: WEST);
  CNavArea::FinishSplitEdit(this: v5, newArea: v9, ignoreEdge: EAST);
  CNavArea::FinishSplitEdit(this: v5, newArea: v13, ignoreEdge: WEST);
LABEL_9:
  if ( TheNavMesh->m_generationMode == GENERATE_NONE
    && nav_split_place_on_ground.m_pParent != nullptr
    && nav_split_place_on_ground.m_pParent->m_Value.m_nValue != 0 )
  {
    CNavArea::PlaceOnGround(this: v9, a2: (int)&savedregs, corner: NUM_CORNERS, inset: 0.0);
    CNavArea::PlaceOnGround(this: v13, a2: (int)&savedregs, corner: NUM_CORNERS, inset: 0.0);
  }
  splitAlongX = (int)v5->m_ladder;
  for ( i = 2; i != 0; --i )
  {
    v16 = **(_DWORD **)splitAlongX <= 0;
    splitEdge = 0.0;
    if ( !v16 )
    {
      do
      {
        v17 = *(CNavLadder **)(*(_DWORD *)splitAlongX + 4 * LODWORD(splitEdge) + 4);
        v18 = *(_QWORD *)&v17->m_top.x;
        ladderPos.z = v17->m_top.z;
        *(_QWORD *)&ladderPos.x = v18;
        *(float *)&src.id = CNavArea::GetDistanceSquaredToPoint(this: v9, pos: &ladderPos);
        DistanceSquaredToPoint = CNavArea::GetDistanceSquaredToPoint(this: v13, pos: &ladderPos);
        if ( DistanceSquaredToPoint <= *(float *)&src.id )
        {
          v24 = (float)(v17->m_bottom.z + v17->m_top.z) * 0.5;
          CNavArea::Disconnect(this: v13, ladder: v17);
          if ( v13->m_center.z <= v24 )
          {
            CNavArea::Disconnect(this: v13, ladder: v17);
            m_ladder = v13->m_ladder;
          }
          else
          {
            CNavArea::Disconnect(this: v13, ladder: v17);
            m_ladder = &v13->m_ladder[1];
          }
        }
        else
        {
          v25 = (float)(v17->m_bottom.z + v17->m_top.z) * 0.5;
          CNavArea::Disconnect(this: v9, ladder: v17);
          if ( v9->m_center.z <= v25 )
          {
            CNavArea::Disconnect(this: v9, ladder: v17);
            m_ladder = v9->m_ladder;
          }
          else
          {
            CNavArea::Disconnect(this: v9, ladder: v17);
            m_ladder = &v9->m_ladder[1];
          }
        }
        src.id = (unsigned int)v17;
        CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::AddToTail(
          this: m_ladder,
          &src);
        v21 = *(_DWORD **)splitAlongX;
        ++LODWORD(splitEdge);
      }
      while ( SLODWORD(splitEdge) < *v21 );
      v5 = p_m_Size;
    }
    splitAlongX += 4;
  }
  v16 = TheNavMesh->m_ladders.m_Size <= 0;
  splitAlongX = 0;
  p_m_Size = (CNavArea *)&TheNavMesh->m_ladders.m_Size;
  if ( !v16 )
  {
    LODWORD(splitEdge) = &TheNavMesh->m_ladders;
    do
      CNavLadder::OnSplit(
        this: *(CNavLadder **)(*(_DWORD *)LODWORD(splitEdge) + 4 * splitAlongX++),
        original: v5,
        alpha: v9,
        beta: v13);
    while ( splitAlongX < (int)p_m_Size->__vftable );
  }
  if ( outAlpha != nullptr )
    *outAlpha = v9;
  if ( outBeta != nullptr )
    *outBeta = v13;
  TheNavMesh->OnEditCreateNotify(this: TheNavMesh, a2: v9);
  TheNavMesh->OnEditCreateNotify(this: TheNavMesh, a2: v13);
  if ( CNavMesh::IsInSelectedSet(this: TheNavMesh, area: v5) )
  {
    CNavMesh::AddToSelectedSet(this: TheNavMesh, area: v9);
    CNavMesh::AddToSelectedSet(this: TheNavMesh, area: v13);
  }
  ((void (__thiscall *)(CNavMesh *, CNavArea *, _DWORD, _DWORD, _DWORD, CNavArea *, _DWORD))TheNavMesh->OnEditDestroyNotify_2)(
    a1: TheNavMesh,
    a2: v5,
    a3: LODWORD(ladderPos.x),
    a4: LODWORD(ladderPos.y),
    a5: LODWORD(ladderPos.z),
    a6: p_m_Size,
    a7: LODWORD(v24));
  splitAlongX = (int)v5;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheNavAreas,
    src: (vgui::TreeNode **)&splitAlongX);
  CNavMesh::RemoveFromSelectedSet(this: TheNavMesh, area: v5);
  TheNavMesh->DestroyArea(this: TheNavMesh, a2: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FF620
// Name: public: void CUtlVectorUltraConservative<struct SpotEncounter __near *,class CUtlVectorUltraConservativeAllocator>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::PurgeAndDeleteElements(
        CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator> *this)
{
  int i; // edi
  SpotEncounter *v3; // ebx

  if ( this->m_pData != (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    for ( i = 0; i < this->m_pData->m_Size; ++i )
    {
      v3 = this->m_pData->m_Elements[i];
      if ( v3 != nullptr )
      {
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v3->spots);
        free(pMem: v3);
      }
    }
    if ( this->m_pData != (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: this->m_pData);
      this->m_pData = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF700
// Name: public: void CParallelProcessor<class CNavArea __near *,class CFuncJobItemProcessor<class CNavArea __near *>,1>::Run(class CNavArea __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::Run(
        CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> *this,
        CNavArea **pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  CNavArea **v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)operator new(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> *,void (__thiscall CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> *,void (__thiscall CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF820
// Name: public: virtual CNavArea::~CNavArea(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::~CNavArea(CNavArea *this)
{
  CNavMesh *v2; // ecx
  int v3; // edi
  int *p_m_Size; // ebx
  CNavArea::AreaBindInfo *m_pMemory; // eax
  void **m_node; // edi
  int i; // ebx
  AreaDestroyNotification notification; // [esp+Ch] [ebp-4h] BYREF

  this->__vftable = (CNavArea_vtbl *)&CNavArea::`vftable';
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::PurgeAndDeleteElements(this: &this->m_spotEncounters);
  if ( !CNavArea::m_isReset )
  {
    notification.m_area = this;
    CNavMesh::ForAllAreas<AreaDestroyNotification>(this: TheNavMesh, func: &notification);
    v2 = TheNavMesh;
    v3 = 0;
    p_m_Size = &TheNavMesh->m_ladders.m_Size;
    if ( TheNavMesh->m_ladders.m_Size > 0 )
    {
      notification.m_area = (CNavArea *)&TheNavMesh->m_ladders;
      do
        CNavLadder::OnDestroyNotify(this: *((CNavLadder **)&notification.m_area->dtr_CNavArea + v3++), dead: this);
      while ( v3 < *p_m_Size );
      v2 = TheNavMesh;
    }
    v2->RemoveNavArea(this: v2, a2: this);
    notification.m_area = this;
    ForEachActor<EditDestroyNotification>(func: (ForgetArea *)&notification);
  }
  m_pMemory = this->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
  this->m_potentiallyVisibleAreas.m_Size = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  this->m_potentiallyVisibleAreas.m_Memory.m_pMemory = nullptr;
  this->m_potentiallyVisibleAreas.m_pElements = nullptr;
  m_node = (void **)this->m_node;
  for ( i = 3; i >= 0; --i )
  {
    --m_node;
    if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
        & 1) == 0 )
      `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
    if ( *m_node != &`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: *m_node);
      if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
          & 1) == 0 )
        `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
      *m_node = &`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
  }
  if ( this->m_spotEncounters.m_pData != (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: this->m_spotEncounters.m_pData);
    this->m_spotEncounters.m_pData = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
  if ( this->m_hidingSpots.m_pData != (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: this->m_hidingSpots.m_pData);
    this->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
  CNavAreaCriticalData::~CNavAreaCriticalData(this: &this->CNavAreaCriticalData);
}

//------------------------------------------------------------------------------
// Address: 0x102FF970
// Name: private: void CNavArea::Strip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Strip(CNavArea *this)
{
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::PurgeAndDeleteElements(this: &this->m_spotEncounters);
}

//------------------------------------------------------------------------------
// Address: 0x102FF9B0
// Name: private: class CUtlVectorConservative<struct CNavArea::AreaBindInfo> const __near & CNavArea::ComputeVisibilityDelta(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVectorConservative<CNavArea::AreaBindInfo> *__thiscall CNavArea::ComputeVisibilityDelta(
        CNavArea *this,
        const CNavArea *other)
{
  CNavArea *v2; // esi
  int v3; // edi
  const CNavArea *v4; // eax
  CNavArea::AreaBindInfo *m_pMemory; // ebx
  int m_Size; // esi
  int v8; // ecx
  CNavArea::AreaBindInfo *v9; // eax
  int v10; // esi
  CNavArea::AreaBindInfo *v11; // eax
  int v12; // ebx
  CNavArea *area; // edi
  int v14; // ecx
  int v15; // eax
  unsigned int *v16; // edx
  int v17; // esi
  CNavArea::AreaBindInfo *v18; // eax
  int info_4; // [esp+Ch] [ebp-8h]

  v2 = this;
  v3 = 0;
  if ( (_S3_164 & 1) == 0 )
  {
    _S3_164 |= 1u;
    delta.m_Memory.m_pMemory = nullptr;
    delta.m_Size = 0;
    delta.m_pElements = nullptr;
    atexit(func: CNavArea::ComputeVisibilityDelta_::_2_::_dynamic_atexit_destructor_for__delta__);
  }
  v4 = other;
  delta.m_Size = 0;
  if ( other->m_inheritVisibilityFrom.id != 0 )
  {
    CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::operator=(
      this: &delta,
      other: &v2->m_potentiallyVisibleAreas);
    return &delta;
  }
  else
  {
    if ( v2->m_potentiallyVisibleAreas.m_Size > 0 )
    {
      do
      {
        m_pMemory = v2->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
        if ( m_pMemory[v3].id != 0 )
        {
          m_Size = v4->m_potentiallyVisibleAreas.m_Size;
          v8 = 0;
          if ( m_Size > 0 )
          {
            v9 = v4->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
            do
            {
              if ( m_pMemory[v3].id == v9->id && m_pMemory[v3].attributes == v9->attributes )
                break;
              ++v8;
              ++v9;
            }
            while ( v8 < m_Size );
          }
          if ( v8 == m_Size )
          {
            v10 = delta.m_Size;
            CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
              this: &delta,
              num: 1);
            if ( delta.m_Size - v10 - 1 > 0 )
              _V_memmove(
                dest: &delta.m_Memory.m_pMemory[v10 + 1],
                src: &delta.m_Memory.m_pMemory[v10],
                count: 8 * (delta.m_Size - v10 - 1));
            v11 = &delta.m_Memory.m_pMemory[v10];
            if ( v11 != nullptr )
            {
              v11->id = m_pMemory[v3].id;
              *(_DWORD *)&v11->attributes = *(_DWORD *)&m_pMemory[v3].attributes;
            }
          }
        }
        v2 = this;
        v4 = other;
        ++v3;
      }
      while ( v3 < this->m_potentiallyVisibleAreas.m_Size );
    }
    v12 = 0;
    if ( v4->m_potentiallyVisibleAreas.m_Size > 0 )
    {
      while ( 1 )
      {
        area = v4->m_potentiallyVisibleAreas.m_Memory.m_pMemory[v12].area;
        if ( area != nullptr )
        {
          v14 = v2->m_potentiallyVisibleAreas.m_Size;
          v15 = 0;
          if ( v14 > 0 )
          {
            v16 = (unsigned int *)v2->m_potentiallyVisibleAreas.m_Memory.m_pMemory;
            do
            {
              if ( (CNavArea *)*v16 == area )
                break;
              ++v15;
              v16 += 2;
            }
            while ( v15 < v14 );
          }
          if ( v15 == v14 )
          {
            v17 = delta.m_Size;
            LOBYTE(info_4) = 0;
            CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
              this: &delta,
              num: 1);
            if ( delta.m_Size - v17 - 1 > 0 )
              _V_memmove(
                dest: &delta.m_Memory.m_pMemory[v17 + 1],
                src: &delta.m_Memory.m_pMemory[v17],
                count: 8 * (delta.m_Size - v17 - 1));
            v18 = &delta.m_Memory.m_pMemory[v17];
            if ( v18 != nullptr )
            {
              v18->id = (unsigned int)area;
              *(_DWORD *)&v18->attributes = info_4;
            }
          }
        }
        v4 = other;
        if ( ++v12 >= other->m_potentiallyVisibleAreas.m_Size )
          break;
        v2 = this;
      }
    }
    return &delta;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FFBA0
// Name: private: void CNavArea::ComputeVisibilityToMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNavArea::ComputeVisibilityToMesh(CNavArea *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  CNavArea *v3; // edi
  float m_fValue; // xmm0_4
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int v6; // esi
  CNavArea **m_pMemory; // ebx
  CNavArea *v8; // ecx
  BOOL v9; // eax
  int v10; // eax
  signed int Depth; // esi
  CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *p_m_potentiallyVisibleAreas; // ebx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  CNavArea::AreaBindInfo *v16; // eax
  int m_Size; // esi
  TSLHead_t m_Head; // kr00_8
  unsigned int v19; // eax
  int i; // ebx
  CNavArea *v21; // ecx
  BOOL v22; // eax
  CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs> *v23; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *v26; // esi
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v27; // ecx
  int v28; // eax
  NavVisPair_t *v29; // edi
  int v30; // [esp-4h] [ebp-64h]
  int v31; // [esp-4h] [ebp-64h]
  TSLHead_t v32; // [esp+0h] [ebp-60h]
  TSLHead_t v33; // [esp+0h] [ebp-60h]
  CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1> v35; // [esp+14h] [ebp-4Ch] BYREF
  NavAreaCollector collector; // [esp+2Ch] [ebp-34h] BYREF
  NavVisPair_t visPair; // [esp+44h] [ebp-1Ch] BYREF
  int v38; // [esp+4Ch] [ebp-14h] BYREF
  unsigned int pBucket; // [esp+50h] [ebp-10h] BYREF
  int pIndex; // [esp+54h] [ebp-Ch] BYREF
  CNavArea *v41; // [esp+58h] [ebp-8h]
  float radius; // [esp+5Ch] [ebp-4h] BYREF

  v3 = this;
  this->m_inheritVisibilityFrom.id = 0;
  this->m_isInheritedFrom = false;
  m_fValue = nav_max_view_distance.m_pParent->m_Value.m_fValue;
  v41 = this;
  collector.m_area.m_Memory.m_nGrowSize = 0;
  collector.m_area.m_Size = 0;
  collector.m_checkForDuplicates = false;
  radius = m_fValue;
  if ( m_fValue == 0.0 )
    radius = 0.0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  collector.m_area.m_Memory.m_nAllocationCount = 1000;
  collector.m_area.m_Memory.m_pMemory = (CNavArea **)((int (__thiscall *)(IMemAlloc *, int, int, int))Alloc_2)(
                                                       a1: _g_pMemAlloc,
                                                       a2: 4000,
                                                       a3: a2,
                                                       a4: a3);
  collector.m_area.m_pElements = collector.m_area.m_Memory.m_pMemory;
  CNavMesh::ForAllAreasInRadius<NavAreaCollector>(this: TheNavMesh, func: &collector, pos: &v3->m_center, radius);
  v6 = collector.m_area.m_Size - 1;
  m_pMemory = collector.m_area.m_Memory.m_pMemory;
  if ( collector.m_area.m_Size - 1 >= 0 )
  {
    LODWORD(radius) = &collector.m_area.m_Memory.m_pMemory[collector.m_area.m_Size - 1];
    do
    {
      v8 = m_pMemory[v6];
      v9 = v8 < v3;
      visPair.pAreas[v9] = v3;
      visPair.pAreas[(v9 + 1) & 1] = v8;
      pIndex = 0;
      if ( CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs>::DoFind(
             this: g_pNavVisPairHash,
             src: &visPair,
             &pBucket,
             &pIndex) != 0
        && (pIndex | (pBucket << 16)) != 0xFFFFFFFF
        && collector.m_area.m_Size > 0 )
      {
        v10 = collector.m_area.m_Size - 1;
        if ( v6 != collector.m_area.m_Size - 1 )
          m_pMemory[v6] = *(CNavArea **)LODWORD(radius);
        LODWORD(radius) -= 4;
        collector.m_area.m_Size = v10;
      }
      --v6;
    }
    while ( v6 >= 0 );
  }
  CNavArea::SetupPVS(this: v3);
  g_pCurVisArea = v3;
  v35.m_pItems.m_value = nullptr;
  v35.m_pLimit = nullptr;
  _InterlockedExchange((volatile __int32 *)&v35.m_pItems, 0);
  v35.m_ItemProcessor.m_pfnBegin = nullptr;
  v35.m_ItemProcessor.m_pfnEnd = nullptr;
  v35.m_ItemProcessor.m_pfnProcess = CNavArea::ComputeVisToArea;
  CParallelProcessor<CNavArea *,CFuncJobItemProcessor<CNavArea *>,1>::Run(
    this: &v35,
    pItems: m_pMemory,
    nItems: collector.m_area.m_Size,
    nChunkSize: 1,
    nMaxParallel: 0x7FFFFFFF,
    pThreadPool: nullptr);
  Depth = g_ComputedVis.m_Head.value.Depth;
  p_m_potentiallyVisibleAreas = &v3->m_potentiallyVisibleAreas;
  if ( v3->m_potentiallyVisibleAreas.m_Memory.m_pMemory != nullptr )
    v13 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v3->m_potentiallyVisibleAreas.m_Memory.m_pMemory);
  else
    v13 = 0;
  if ( Depth <= (int)(v13 >> 3) )
  {
    if ( p_m_potentiallyVisibleAreas->m_Memory.m_pMemory != nullptr )
      v15 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: p_m_potentiallyVisibleAreas->m_Memory.m_pMemory);
    else
      v15 = 0;
    v14 = v15 >> 3;
  }
  else
  {
    v14 = Depth;
  }
  v16 = (CNavArea::AreaBindInfo *)_g_pMemAlloc->Realloc_2(
                                    this: _g_pMemAlloc,
                                    a2: p_m_potentiallyVisibleAreas->m_Memory.m_pMemory,
                                    a3: 8 * v14);
  p_m_potentiallyVisibleAreas->m_Memory.m_pMemory = v16;
  v3->m_potentiallyVisibleAreas.m_pElements = v16;
  if ( g_ComputedVis.m_Head.value.Depth != 0 )
  {
    do
    {
      m_Size = v3->m_potentiallyVisibleAreas.m_Size;
      CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
        this: p_m_potentiallyVisibleAreas,
        num: 1);
      if ( v3->m_potentiallyVisibleAreas.m_Size - m_Size - 1 > 0 )
        _V_memmove(
          dest: &v3->m_potentiallyVisibleAreas.m_Memory.m_pMemory[m_Size + 1],
          src: &v3->m_potentiallyVisibleAreas.m_Memory.m_pMemory[m_Size],
          count: 8 * (v3->m_potentiallyVisibleAreas.m_Size - m_Size - 1));
      m_Head = g_ComputedVis.m_Head;
      pBucket = (unsigned int)&p_m_potentiallyVisibleAreas->m_Memory.m_pMemory[m_Size];
      if ( g_ComputedVis.m_Head.value.Next != nullptr )
      {
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                   a1: &g_ComputedVis,
                                   a2: m_Head.value.Next->Next,
                                   a3: m_Head.value32.DepthAndSequence - 1,
                                   a4: m_Head.value.Next,
                                   a5: m_Head.value32.DepthAndSequence) == 0 )
        {
          _mm_pause();
          m_Head = g_ComputedVis.m_Head;
          if ( g_ComputedVis.m_Head.value.Next == nullptr )
            goto LABEL_31;
        }
        if ( m_Head.value.Next != nullptr )
        {
          v19 = pBucket;
          *(_DWORD *)pBucket = *((_DWORD *)&m_Head.value.Next->Next + 1);
          *(_DWORD *)(v19 + 4) = m_Head.value.Next[1].Next;
          v32 = g_ComputedVis.m_FreeList.m_Head;
          v30 = g_ComputedVis.m_FreeList.m_Head.value32.DepthAndSequence + 65537;
          m_Head.value.Next->Next = g_ComputedVis.m_FreeList.m_Head.value.Next;
          if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                  a1: &g_ComputedVis.m_FreeList,
                                  a2: m_Head.value.Next,
                                  a3: v30,
                                  a4: v32.value.Next,
                                  a5: v32.value32.DepthAndSequence) == 0 )
          {
            do
            {
              _mm_pause();
              v33 = g_ComputedVis.m_FreeList.m_Head;
              v31 = g_ComputedVis.m_FreeList.m_Head.value32.DepthAndSequence + 65537;
              m_Head.value.Next->Next = g_ComputedVis.m_FreeList.m_Head.value.Next;
            }
            while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                       a1: &g_ComputedVis.m_FreeList,
                                       a2: m_Head.value.Next,
                                       a3: v31,
                                       a4: v33.value.Next,
                                       a5: v33.value32.DepthAndSequence) == 0 );
          }
        }
      }
LABEL_31:
      ;
    }
    while ( g_ComputedVis.m_Head.value.Depth != 0 );
    v3 = v41;
  }
  for ( i = 0; i < collector.m_area.m_Size; ++i )
  {
    v21 = collector.m_area.m_Memory.m_pMemory[i];
    v22 = v21 < v3;
    visPair.pAreas[v22] = v3;
    visPair.pAreas[(v22 + 1) & 1] = v21;
    v23 = g_pNavVisPairHash;
    if ( CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs>::DoFind(
           this: g_pNavVisPairHash,
           src: &visPair,
           pBucket: (unsigned int *)&radius,
           pIndex: &v38) == 0 )
    {
      v24 = v23->m_Buckets.m_Memory.m_pMemory[LODWORD(radius)].m_Size;
      m_nAllocationCount = v23->m_Buckets.m_Memory.m_pMemory[LODWORD(radius)].m_Memory.m_nAllocationCount;
      v26 = (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&v23->m_Buckets.m_Memory.m_pMemory[LODWORD(radius)];
      if ( v24 + 1 > m_nAllocationCount )
        CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
          this: v26,
          num: v24 - m_nAllocationCount + 1);
      ++v26[1].m_pMemory;
      v27 = v26->m_pMemory;
      v28 = (int)v26[1].m_pMemory - v24 - 1;
      v26[1].m_nAllocationCount = (int)v26->m_pMemory;
      if ( v28 > 0 )
        _V_memmove(dest: &v27[v24 + 1], src: &v27[v24], count: 8 * v28);
      v29 = (NavVisPair_t *)&v26->m_pMemory[v24];
      if ( v29 != nullptr )
        *v29 = visPair;
      v3 = v41;
    }
  }
  if ( collector.m_area.m_Memory.m_nGrowSize >= 0 && collector.m_area.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: collector.m_area.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x104138A0
// Name: _dynamic_initializer_for__CNavVectorNoEditAllocator::m_memory__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CNavVectorNoEditAllocator::m_memory__()
{
  CMemoryStack::CMemoryStack(this: &CNavVectorNoEditAllocator::m_memory);
  return atexit(func: dynamic_atexit_destructor_for__CNavVectorNoEditAllocator::m_memory__);
}

//------------------------------------------------------------------------------
// Address: 0x104210C0
// Name: _dynamic_atexit_destructor_for__CNavVectorNoEditAllocator::m_memory__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CNavVectorNoEditAllocator::m_memory__()
{
  CMemoryStack::~CMemoryStack(this: &CNavVectorNoEditAllocator::m_memory);
}

//------------------------------------------------------------------------------
// Address: 0x104138C0
// Name: _dynamic_initializer_for__nav_update_lighting_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_update_lighting_command__()
{
  ConCommand::ConCommand(
    this: &nav_update_lighting_command,
    pName: "nav_update_lighting",
    callback: (void (__cdecl *)())nav_update_lighting,
    pHelpString: "Recomputes lighting values",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_update_lighting_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104138F0
// Name: _dynamic_initializer_for__nav_update_blocked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_update_blocked__()
{
  ConCommand::ConCommand(
    this: &nav_update_blocked,
    pName: "nav_update_blocked",
    callback: CommandNavUpdateBlocked,
    pHelpString: "Updates the blocked/unblocked status for every nav area.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_update_blocked__);
}

//------------------------------------------------------------------------------
// Address: 0x10413920
// Name: _dynamic_initializer_for__nav_check_floor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_check_floor__()
{
  ConCommand::ConCommand(
    this: &nav_check_floor,
    pName: "nav_check_floor",
    callback: CommandNavCheckFloor,
    pHelpString: "Updates the blocked/unblocked status for every nav area.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_check_floor__);
}

//------------------------------------------------------------------------------
// Address: 0x10413950
// Name: _dynamic_initializer_for__nav_select_overlapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_overlapping__()
{
  ConCommand::ConCommand(
    this: &nav_select_overlapping,
    pName: "nav_select_overlapping",
    callback: (void (__cdecl *)())CommandNavSelectOverlapping,
    pHelpString: "Selects nav areas that are overlapping others.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_overlapping__);
}

//------------------------------------------------------------------------------
// Address: 0x10413980
// Name: _dynamic_initializer_for__g_ComputedVis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ComputedVis__()
{
  const char *v1; // [esp+0h] [ebp-4h]

  if ( ((unsigned __int8)&g_ComputedVis & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_10458314, a2: v1);
    __debugbreak();
  }
  g_ComputedVis.m_Head.value64 = 0;
  if ( ((unsigned __int8)&g_ComputedVis.m_FreeList & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_10458314, a2: v1);
    __debugbreak();
  }
  g_ComputedVis.m_FreeList.m_Head.value64 = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_ComputedVis__);
}

//------------------------------------------------------------------------------
// Address: 0x104139E0
// Name: _dynamic_initializer_for__nav_show_area_info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_area_info__()
{
  ConVar::ConVar(
    this: &nav_show_area_info,
    pName: "nav_show_area_info",
    pDefaultValue: "0.5",
    flags: 0x4000,
    pHelpString: "Duration in seconds to show nav area ID and attributes while editing");
  return atexit(func: dynamic_atexit_destructor_for__nav_show_area_info__);
}

//------------------------------------------------------------------------------
// Address: 0x10413A10
// Name: _dynamic_initializer_for__nav_snap_to_grid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_snap_to_grid__()
{
  ConVar::ConVar(
    this: &nav_snap_to_grid,
    pName: "nav_snap_to_grid",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Snap to the nav generation grid when creating new nav areas");
  return atexit(func: dynamic_atexit_destructor_for__nav_snap_to_grid__);
}

//------------------------------------------------------------------------------
// Address: 0x10413A40
// Name: _dynamic_initializer_for__nav_create_place_on_ground__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_create_place_on_ground__()
{
  ConVar::ConVar(
    this: &nav_create_place_on_ground,
    pName: "nav_create_place_on_ground",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "If true, nav areas will be placed flush with the ground when created by hand.");
  return atexit(func: dynamic_atexit_destructor_for__nav_create_place_on_ground__);
}

//------------------------------------------------------------------------------
// Address: 0x10413A70
// Name: _dynamic_initializer_for__nav_draw_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_draw_limit__()
{
  ConVar::ConVar(
    this: &nav_draw_limit,
    pName: "nav_draw_limit",
    pDefaultValue: "500",
    flags: 0x4000,
    pHelpString: "The maximum number of areas to draw in edit mode");
  return atexit(func: dynamic_atexit_destructor_for__nav_draw_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10413AA0
// Name: _dynamic_initializer_for__nav_solid_props__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_solid_props__()
{
  ConVar::ConVar(
    this: &nav_solid_props,
    pName: "nav_solid_props",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Make props solid to nav generation/editing");
  return atexit(func: dynamic_atexit_destructor_for__nav_solid_props__);
}

//------------------------------------------------------------------------------
// Address: 0x10413AD0
// Name: _dynamic_initializer_for__nav_create_area_at_feet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_create_area_at_feet__()
{
  ConVar::ConVar(
    this: &nav_create_area_at_feet,
    pName: "nav_create_area_at_feet",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Anchor nav_begin_area Z to editing player's feet");
  return atexit(func: dynamic_atexit_destructor_for__nav_create_area_at_feet__);
}

//------------------------------------------------------------------------------
// Address: 0x10413B00
// Name: _dynamic_initializer_for__nav_drag_selection_volume_zmax_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_drag_selection_volume_zmax_offset__()
{
  ConVar::ConVar(
    this: &nav_drag_selection_volume_zmax_offset,
    pName: "nav_drag_selection_volume_zmax_offset",
    pDefaultValue: "32",
    flags: 0x2000,
    pHelpString: "The offset of the nav drag volume top from center");
  return atexit(func: dynamic_atexit_destructor_for__nav_drag_selection_volume_zmax_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x10413B30
// Name: _dynamic_initializer_for__nav_drag_selection_volume_zmin_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_drag_selection_volume_zmin_offset__()
{
  ConVar::ConVar(
    this: &nav_drag_selection_volume_zmin_offset,
    pName: "nav_drag_selection_volume_zmin_offset",
    pDefaultValue: "32",
    flags: 0x2000,
    pHelpString: "The offset of the nav drag volume bottom from center");
  return atexit(func: dynamic_atexit_destructor_for__nav_drag_selection_volume_zmin_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x104210D0
// Name: _dynamic_atexit_destructor_for__nav_update_lighting_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_update_lighting_command__()
{
  ConCommand::~ConCommand(this: &nav_update_lighting_command);
}

//------------------------------------------------------------------------------
// Address: 0x104210E0
// Name: _dynamic_atexit_destructor_for__nav_update_blocked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_update_blocked__()
{
  ConCommand::~ConCommand(this: &nav_update_blocked);
}

//------------------------------------------------------------------------------
// Address: 0x104210F0
// Name: _dynamic_atexit_destructor_for__nav_check_floor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_check_floor__()
{
  ConCommand::~ConCommand(this: &nav_check_floor);
}

//------------------------------------------------------------------------------
// Address: 0x10421100
// Name: _dynamic_atexit_destructor_for__nav_select_overlapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_overlapping__()
{
  ConCommand::~ConCommand(this: &nav_select_overlapping);
}

//------------------------------------------------------------------------------
// Address: 0x10421110
// Name: _dynamic_atexit_destructor_for__TheNavAreas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__TheNavAreas__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&TheNavAreas);
}
