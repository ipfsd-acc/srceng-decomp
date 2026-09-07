// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/player_lagcompensation.cpp
// Functions: 23
// ============================================================

#include "game\server\player_lagcompensation.h"

//------------------------------------------------------------------------------
// Address: 0x10044B00
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct AI_Follower_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *this@<ecx>,
        const char *a2@<esi>,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *v5; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pBlocks; // eax

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
    v5 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: 76 * m_nGrowSize + 8);
    if ( v5 == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_10434C50, a2);
    m_pBlocks = this->m_pBlocks;
    v5->m_pNext = nullptr;
    v5->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v5;
    }
    else
    {
      this->m_pBlocks = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044C60
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct AI_Follower_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AI_Follower_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 76 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 76 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 76 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10077AB0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CAI_PlaneSolver::CircleObstacles_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CAI_PlaneSolver::CircleObstacles_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[4 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[4 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[4 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1008A5A0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> > *this@<ecx>,
        const char *a2@<esi>,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *v5; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *m_pBlocks; // eax

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
    v5 = (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 68 * m_nGrowSize + 8);
    if ( v5 == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_10434C50, a2);
    m_pBlocks = this->m_pBlocks;
    v5->m_pNext = nullptr;
    v5->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v5;
    }
    else
    {
      this->m_pBlocks = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A640
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 68 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 68 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 68 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10161B00
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t)(unsigned int)m_pNext;
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
// Address: 0x10161B80
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<class CInfoCameraLink __near *,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CInfoCameraLink __near *,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *m_pNext; // eax

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
// Address: 0x10161C00
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<class CInfoCameraLink __near *,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > *this@<ecx>,
        const char *a2@<esi>,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *v5; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *m_pBlocks; // eax

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
    v5 = (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                          this: _g_pMemAlloc,
                                                                                          a2: 12 * m_nGrowSize + 8);
    if ( v5 == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_10434C50, a2);
    m_pBlocks = this->m_pBlocks;
    v5->m_pNext = nullptr;
    v5->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v5;
    }
    else
    {
      this->m_pBlocks = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C84B0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct LagRecord,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > *this@<ecx>,
        const char *a2@<esi>,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *v5; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *m_pBlocks; // eax

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
    v5 = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: 312 * m_nGrowSize + 8);
    if ( v5 == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_10434C50, a2);
    m_pBlocks = this->m_pBlocks;
    v5->m_pNext = nullptr;
    v5->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v5;
    }
    else
    {
      this->m_pBlocks = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C85A0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct LagRecord,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LagRecord,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[39 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[39 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[39 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101C8700
// Name: public: LagRecord::LagRecord(void)
// Source: json
//------------------------------------------------------------------------------
LagRecord *__userpurge LagRecord::LagRecord@<dx:ax>(LagRecord *this@<ecx>)
{
  LayerRecord *m_layerRecords; // ecx
  int v2; // esi
  __int64 result; // rax
  _DWORD *v4; // ecx
  int i; // esi

  LODWORD(result) = this;
  m_layerRecords = this->m_layerRecords;
  v2 = 14;
  result = (unsigned int)result;
  do
  {
    m_layerRecords->m_sequence = 0;
    m_layerRecords->m_cycle = 0.0;
    m_layerRecords->m_weight = 0.0;
    m_layerRecords->m_order = 0;
    ++m_layerRecords;
    --v2;
  }
  while ( v2 >= 0 );
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 24) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 36) = 0;
  *(_DWORD *)(result + 40) = 0;
  *(_DWORD *)(result + 44) = 0;
  *(_DWORD *)(result + 48) = 0;
  *(_DWORD *)(result + 52) = -1082130432;
  *(_DWORD *)(result + 296) = 0;
  *(_DWORD *)(result + 300) = 0;
  v4 = (_DWORD *)(result + 64);
  for ( i = 15; i != 0; --i )
  {
    *(v4 - 2) = 0;
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4 += 4;
  }
  return (LagRecord *)result;
}

//------------------------------------------------------------------------------
// Address: 0x101C87B0
// Name: RestoreEntityTo
// Source: json
//------------------------------------------------------------------------------
void __usercall RestoreEntityTo(CBaseEntity *pEntity@<esi>, const Vector *vWantedPos@<edi>)
{
  edict_t *m_pPev; // eax
  CGameTrace tr; // [esp+2Ch] [ebp-60h] BYREF
  Vector vPos; // [esp+80h] [ebp-Ch] BYREF
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "RestoreEntityTo",
    a3: 0,
    a4: "CLagCompensationManager",
    a5: false,
    a6: 4);
  if ( sv_lagcompensationforcerestore.m_pParent != nullptr
    && sv_lagcompensationforcerestore.m_pParent->m_Value.m_nValue != 0 )
  {
    CBaseEntity::SetAbsOrigin(this: pEntity, absOrigin: vWantedPos);
    CBaseEntity::PhysicsTouchTriggers(this: pEntity, pPrevAbsOrigin: nullptr);
  }
  UTIL_TraceEntity(
    pEntity,
    vecAbsStart: vWantedPos,
    vecAbsEnd: vWantedPos,
    mask: 0x201400Bu,
    pIgnore: pEntity,
    nCollisionGroup: 8,
    ptr: &tr);
  if ( tr.startsolid || tr.allsolid )
  {
    if ( sv_unlag_debug.m_pParent != nullptr && sv_unlag_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      m_pPev = pEntity->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      DevMsg(
        a1: "RestoreEntityTo could not restore player position for client \"%d\" ( %.1f %.1f %.1f )\n",
        m_pPev,
        vWantedPos->x,
        vWantedPos->y,
        vWantedPos->z);
    }
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    UTIL_TraceEntity(
      pEntity,
      vecAbsStart: &pEntity->m_vecAbsOrigin,
      vecAbsEnd: vWantedPos,
      mask: 0x201400Bu,
      pIgnore: pEntity,
      nCollisionGroup: 8,
      ptr: &tr);
    if ( tr.startsolid || tr.allsolid )
    {
      if ( sv_unlag_debug.m_pParent != nullptr && sv_unlag_debug.m_pParent->m_Value.m_nValue != 0 )
        DevMsg(a1: " restore failed entirely\n");
    }
    else
    {
      if ( (pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
      vPos.x = (float)((float)(vWantedPos->x - pEntity->m_vecAbsOrigin.x) * (float)(g_flFractionScale * tr.fraction))
             + pEntity->m_vecAbsOrigin.x;
      vPos.y = (float)((float)(vWantedPos->y - pEntity->m_vecAbsOrigin.y) * (float)(g_flFractionScale * tr.fraction))
             + pEntity->m_vecAbsOrigin.y;
      vPos.z = (float)((float)(vWantedPos->z - pEntity->m_vecAbsOrigin.z) * (float)(g_flFractionScale * tr.fraction))
             + pEntity->m_vecAbsOrigin.z;
      CBaseEntity::SetAbsOrigin(this: pEntity, absOrigin: &vPos);
      CBaseEntity::PhysicsTouchTriggers(this: pEntity, pPrevAbsOrigin: nullptr);
      if ( sv_unlag_debug.m_pParent != nullptr && sv_unlag_debug.m_pParent->m_Value.m_nValue != 0 )
        DevMsg(a1: " restore got most of the way\n");
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CBaseEntity::SetAbsOrigin(this: pEntity, absOrigin: &tr.endpos);
    CBaseEntity::PhysicsTouchTriggers(this: pEntity, pPrevAbsOrigin: nullptr);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC950
// Name: public: bool CLagCompensationManager::BacktrackEntity(class CBaseEntity __near *,float,class CUtlFixedLinkedList<struct LagRecord> __near *,struct LagRecord __near *,struct LagRecord __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CLagCompensationManager::BacktrackEntity@<al>(
        CLagCompensationManager *this@<ecx>,
        CBaseEntity *a2@<ebp>,
        CBaseEntity *entity,
        float flTargetTime,
        CUtlFixedLinkedList<LagRecord> *track,
        LagRecord *restore,
        LagRecord *change,
        bool wantsAnims)
{
  int m_Head; // esi
  CBaseEntity *v9; // edx
  float *v10; // ecx
  int v11; // edi
  float z; // eax
  float v13; // xmm3_4
  float y; // xmm2_4
  float v15; // xmm4_4
  signed int m_pPev; // eax
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  bool v21; // zf
  const QAngle *v22; // esi
  int v23; // edx
  float v24; // xmm4_4
  float v25; // xmm1_4
  unsigned int v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  CBaseEntity *v32; // esi
  edict_t *v33; // eax
  unsigned __int16 v34; // ax
  _BYTE *v35; // esi
  float x; // ecx
  const Vector *AbsOrigin; // eax
  const Vector *v38; // eax
  float v39; // xmm4_4
  int v40; // xmm1_4
  unsigned int v41; // edx
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  unsigned int v45; // eax
  double m_Value; // st7
  LagRecord *v47; // eax
  float v48; // xmm3_4
  unsigned int v49; // ecx
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi
  const Vector *v51; // ecx
  int v52; // ecx
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v54; // eax
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  int m_iEFlags; // eax
  double v57; // st7
  int v58; // eax
  float v59; // esi
  float v60; // xmm3_4
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  unsigned int v62; // xmm1_4
  unsigned int v63; // xmm2_4
  float *v64; // eax
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm2_4
  float v68; // xmm3_4
  float v69; // xmm0_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm0_4
  __int128 v73; // xmm1
  float v74; // xmm0_4
  __int128 v75; // xmm1
  float v76; // xmm2_4
  float v77; // xmm3_4
  float v78; // xmm0_4
  __int128 v79; // xmm1
  CBaseAnimating *v80; // eax
  CBaseAnimating *v81; // esi
  float v82; // xmm0_4
  float v83; // xmm1_4
  float v84; // xmm0_4
  CBaseAnimatingOverlay *v85; // eax
  int v86; // ecx
  CBaseEntity *v87; // edx
  int v88; // edi
  CAnimationLayer *AnimOverlay; // esi
  int v90; // eax
  float v91; // xmm3_4
  float v92; // xmm0_4
  float v93; // xmm1_4
  float v94; // xmm0_4
  float v95; // xmm1_4
  CBaseAnimatingOverlay *v96; // eax
  CBaseEdict *v97; // eax
  IChangeInfoAccessor *v98; // eax
  float v99; // xmm1_4
  CBaseAnimatingOverlay *v100; // eax
  CBaseEdict *v101; // eax
  IChangeInfoAccessor *v102; // eax
  CBaseAnimatingOverlay *v103; // eax
  CBaseEdict *v104; // eax
  CBaseAnimatingOverlay *v105; // eax
  CBaseEdict *v106; // eax
  float v107; // xmm0_4
  float v108; // xmm1_4
  CBaseAnimatingOverlay *v109; // eax
  CBaseEdict *v110; // eax
  IChangeInfoAccessor *v111; // eax
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v113; // eax
  CBaseAnimatingOverlay *v114; // eax
  CBaseEdict *v115; // eax
  CBaseAnimatingOverlay *v116; // eax
  CBaseEdict *v117; // eax
  CBaseAnimatingOverlay *v118; // eax
  CBaseEdict *v119; // eax
  CBaseAnimating *v120; // eax
  LagRecord *v121; // eax
  CBaseAnimating *(__thiscall *GetBaseAnimating)(CBaseEntity *); // edx
  CBaseAnimating *v123; // eax
  _BYTE v124[12]; // [esp+38h] [ebp-10Ch] BYREF
  CGameTrace tr; // [esp+44h] [ebp-100h]
  int v126; // [esp+98h] [ebp-ACh]
  int v127; // [esp+9Ch] [ebp-A8h]
  float v128; // [esp+A0h] [ebp-A4h]
  CBaseAnimatingOverlay *v129; // [esp+A4h] [ebp-A0h]
  __int128 v130; // [esp+A8h] [ebp-9Ch] OVERLAPPED BYREF
  Vector forward; // [esp+B8h] [ebp-8Ch] BYREF
  float v132; // [esp+C4h] [ebp-80h]
  Vector prevOrg; // [esp+C8h] [ebp-7Ch] BYREF
  QAngle ang; // [esp+D4h] [ebp-70h] BYREF
  Vector maxs; // [esp+E0h] [ebp-64h] BYREF
  Vector mins; // [esp+ECh] [ebp-58h] BYREF
  float v137; // [esp+F8h] [ebp-4Ch]
  __int128 orgdiff; // [esp+FCh] [ebp-48h] OVERLAPPED BYREF
  CHandle<CBaseEntity> v139; // [esp+10Ch] [ebp-38h] BYREF
  float v140; // [esp+110h] [ebp-34h] BYREF
  int layerCount; // [esp+114h] [ebp-30h]
  CHandle<CBaseEntity> eh; // [esp+118h] [ebp-2Ch]
  Vector org; // [esp+11Ch] [ebp-28h]
  unsigned int v144; // [esp+128h] [ebp-1Ch]
  int layerIndex; // [esp+12Ch] [ebp-18h]
  CGameTrace *frac; // [esp+130h] [ebp-14h]
  int flags; // [esp+134h] [ebp-10h]
  CBaseEntity *pHitEntity; // [esp+138h] [ebp-Ch] BYREF
  void *v149; // [esp+13Ch] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+144h] [ebp+0h]

  pHitEntity = a2;
  v149 = retaddr;
  LODWORD(org.x) = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "BacktrackEntity",
    a3: 0,
    a4: "CLagCompensationManager",
    a5: false,
    a6: 4);
  if ( track->m_ElementCount <= 0 )
    goto LABEL_18;
  m_Head = track->m_Head;
  v9 = entity;
  v10 = nullptr;
  v11 = 0;
  if ( (entity->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&pHitEntity);
    v9 = entity;
    v10 = nullptr;
  }
  z = v9->m_vecAbsOrigin.z;
  *(_QWORD *)&forward.y = *(_QWORD *)&v9->m_vecAbsOrigin.x;
  v13 = forward.z;
  y = forward.y;
  v132 = z;
  v15 = z;
  while ( m_Head != 0 && (*(_DWORD *)(m_Head + 304) != m_Head || *(_DWORD *)(m_Head + 308) == m_Head) )
  {
    v10 = (float *)v11;
    v11 = m_Head;
    if ( (*(_BYTE *)m_Head & 1) == 0
      || (float)((float)((float)((float)(*(float *)(m_Head + 4) - y) * (float)(*(float *)(m_Head + 4) - y))
                       + (float)((float)(*(float *)(m_Head + 8) - v13) * (float)(*(float *)(m_Head + 8) - v13)))
               + (float)((float)(*(float *)(m_Head + 12) - v15) * (float)(*(float *)(m_Head + 12) - v15))) > 4096.0 )
    {
      goto LABEL_18;
    }
    if ( flTargetTime >= *(float *)(m_Head + 52) )
      break;
    y = *(float *)(m_Head + 4);
    v13 = *(float *)(m_Head + 8);
    v15 = *(float *)(m_Head + 12);
    m_Head = *(_DWORD *)(m_Head + 308);
  }
  flags = (int)v10;
  if ( v11 == 0 )
  {
    if ( sv_unlag_debug.m_pParent != nullptr && sv_unlag_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      m_pPev = (signed int)v9->m_Network.m_pPev;
      if ( m_pPev != 0 )
        m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
      DevMsg(a1: "No valid positions in history for BacktrackPlayer client ( %d )\n", m_pPev);
    }
    goto LABEL_18;
  }
  org.z = 0.0;
  if ( v10 != nullptr && (v18 = *(float *)(v11 + 52), flTargetTime > v18) && (v19 = v10[13]) > v18 )
  {
    v20 = (float)(flTargetTime - v18) / (float)(v19 - v18);
    v21 = v10[4] == *(float *)(v11 + 16);
    v22 = (const QAngle *)(v10 + 4);
    org.z = v20;
    if ( v21 && v10[5] == *(float *)(v11 + 20) && v10[6] == *(float *)(v11 + 24) )
    {
      v23 = *(_DWORD *)(v11 + 24);
      *(_QWORD *)((char *)&orgdiff + 4) = *(_QWORD *)(v11 + 16);
      HIDWORD(orgdiff) = v23;
    }
    else
    {
      AngleQuaternion(angles: (const QAngle *)(v11 + 16), outQuat: (Quaternion *)&mins);
      AngleQuaternion(angles: v22, outQuat: (Quaternion *)&forward);
      QuaternionSlerp(
        p: (const Quaternion *)&mins,
        q: (const Quaternion *)&forward,
        t: org.z,
        qt: (Quaternion *)&orgdiff);
      QuaternionAngles(q: (const Quaternion *)&orgdiff, angles: (QAngle *)((char *)&v130 + 4));
      *(_QWORD *)((char *)&orgdiff + 4) = *(_QWORD *)((char *)&v130 + 4);
      v20 = org.z;
      HIDWORD(orgdiff) = HIDWORD(v130);
      v10 = (float *)flags;
    }
    prevOrg = *(Vector *)((char *)&orgdiff + 4);
    v24 = *(float *)(v11 + 4);
    v25 = v10[1] - v24;
    *(float *)&v26 = (float)((float)(v10[3] - *(float *)(v11 + 12)) * v20) + *(float *)(v11 + 12);
    *(float *)&layerCount = (float)((float)(v10[2] - *(float *)(v11 + 8)) * v20) + *(float *)(v11 + 8);
    eh.m_Index = v26;
    v140 = v24 + (float)(v25 * v20);
    v27 = *(float *)(v11 + 28);
    v28 = v10[7] - v27;
    v29 = (float)((float)(v10[9] - *(float *)(v11 + 36)) * v20) + *(float *)(v11 + 36);
    maxs.y = (float)((float)(v10[8] - *(float *)(v11 + 32)) * v20) + *(float *)(v11 + 32);
    maxs.z = v29;
    maxs.x = v27 + (float)(v28 * v20);
    v30 = (float)((float)(v10[11] - *(float *)(v11 + 44)) * v20) + *(float *)(v11 + 44);
    v31 = (float)((float)(v10[12] - *(float *)(v11 + 48)) * v20) + *(float *)(v11 + 48);
    ang.x = *(float *)(v11 + 40) + (float)((float)(v10[10] - *(float *)(v11 + 40)) * v20);
    ang.y = v30;
    ang.z = v31;
  }
  else
  {
    prevOrg = *(Vector *)(v11 + 16);
    v140 = *(float *)(v11 + 4);
    layerCount = *(int *)(v11 + 8);
    eh.m_Index = *(unsigned int *)(v11 + 12);
    maxs = *(Vector *)(v11 + 28);
    ang = *(QAngle *)(v11 + 40);
  }
  if ( sv_unlag_fixstuck.m_pParent != nullptr && sv_unlag_fixstuck.m_pParent->m_Value.m_nValue != 0 )
  {
    v32 = entity;
    UTIL_TraceEntity(
      pEntity: entity,
      vecAbsStart: (const Vector *)&v140,
      vecAbsEnd: (const Vector *)&v140,
      mask: 0x201400Bu,
      ptr: (CGameTrace *)v124);
    if ( tr.plane.pad[1] != 0 || tr.plane.pad[0] != 0 )
    {
      if ( sv_unlag_debug.m_pParent != nullptr && sv_unlag_debug.m_pParent->m_Value.m_nValue != 0 )
      {
        v33 = CBaseEntity::entindex(this: entity);
        DevMsg(a1: "WARNING: BackupPlayer trying to back player into a bad position - client %d\n", v33);
      }
      layerIndex = *(int *)&tr.surface.surfaceProps;
      if ( *(_DWORD *)&tr.surface.surfaceProps != 0
        && *(_DWORD *)&tr.surface.surfaceProps != *(_DWORD *)(LODWORD(org.x) + 48) )
      {
        v139.m_Index = -1;
        CHandle<CBaseEntity>::operator=(this: &v139, val: *(const CBaseEntity **)&tr.surface.surfaceProps);
        DWORD2(orgdiff) = v139;
        v34 = CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(LODWORD(org.x) + 16),
                search: (const CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t *)&orgdiff
              + 1);
        if ( v34 != 0xFFFF )
        {
          v35 = *(_BYTE **)(*(_DWORD *)(LODWORD(org.x) + 20) + 16 * v34 + 12);
          if ( *v35 == 0 )
          {
            LOBYTE(frac) = 1;
            layerIndex = (int)(v35 + 352);
            v144 = (unsigned int)(v35 + 48);
            LODWORD(org.z) = v35 + 4;
            x = org.x;
            org.y = flTargetTime;
            LODWORD(org.x) = v35 + 352;
            *v35 = 1;
            CLagCompensationManager::BacktrackEntity(
              this: (CLagCompensationManager *)LODWORD(x),
              entity: (CBaseEntity *)LODWORD(org.x),
              flTargetTime: org.y,
              track: (CUtlFixedLinkedList<LagRecord> *)LODWORD(org.z),
              restore: (LagRecord *)v144,
              change: (LagRecord *)layerIndex,
              wantsAnims: (bool)frac);
            *v35 = 0;
          }
          v32 = entity;
        }
      }
      frac = (CGameTrace *)v124;
      *(float *)&layerIndex = 9.4958026e-38;
      v144 = (unsigned int)&v140;
      AbsOrigin = CBaseEntity::GetAbsOrigin(this: v32);
      UTIL_TraceEntity(
        pEntity: v32,
        vecAbsStart: AbsOrigin,
        vecAbsEnd: (const Vector *)v144,
        mask: layerIndex,
        ptr: frac);
      if ( tr.plane.pad[1] != 0 || tr.plane.pad[0] != 0 )
      {
        if ( sv_unlag_debug.m_pParent != nullptr && sv_unlag_debug.m_pParent->m_Value.m_nValue != 0 )
          DevMsg(a1: "Backtrack failed completely, bad starting position\n");
      }
      else
      {
        *(float *)&layerIndex = tr.plane.normal.z * g_flFractionScale;
        v38 = CBaseEntity::GetAbsOrigin(this: v32);
        v39 = v38->z;
        *(float *)&v40 = (float)((float)(*(float *)&layerCount - v38->y) * *(float *)&layerIndex) + v38->y;
        v140 = (float)((float)(v140 - v38->x) * *(float *)&layerIndex) + v38->x;
        layerCount = v40;
        *(float *)&eh.m_Index = (float)((float)(*(float *)&eh.m_Index - v39) * *(float *)&layerIndex) + v39;
        if ( sv_unlag_debug.m_pParent != nullptr && sv_unlag_debug.m_pParent->m_Value.m_nValue != 0 )
          DevMsg(a1: "Backtrack got most of the way\n");
      }
    }
  }
  v41 = (unsigned int)entity->m_iEFlags >> 11;
  v144 = 0;
  if ( (v41 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&pHitEntity);
  v42 = entity->m_angAbsRotation.x - prevOrg.x;
  v43 = entity->m_angAbsRotation.y - prevOrg.y;
  v44 = entity->m_angAbsRotation.z - prevOrg.z;
  v45 = (unsigned int)entity->m_iEFlags >> 11;
  mins.y = v42;
  mins.z = v43;
  v137 = v44;
  if ( (v45 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&pHitEntity);
    v44 = v137;
    v43 = mins.z;
    v42 = mins.y;
  }
  m_Value = entity->m_flSimulationTime.m_Value;
  v47 = restore;
  mins.y = entity->m_vecAbsOrigin.x - v140;
  mins.z = entity->m_vecAbsOrigin.y - *(float *)&layerCount;
  v48 = entity->m_vecAbsOrigin.z;
  restore->m_flSimulationTime = m_Value;
  v137 = v48 - *(float *)&eh.m_Index;
  if ( (float)((float)((float)(v43 * v43) + (float)(v42 * v42)) + (float)(v44 * v44)) > 0.010000001 )
  {
    v49 = (unsigned int)entity->m_iEFlags >> 11;
    v144 = 512;
    if ( (v49 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&pHitEntity);
      v47 = restore;
    }
    v47->m_vecAngles.x = entity->m_angAbsRotation.x;
    frac = (CGameTrace *)&prevOrg;
    v47->m_vecAngles.y = entity->m_angAbsRotation.y;
    v47->m_vecAngles.z = entity->m_angAbsRotation.z;
    CBaseEntity::SetAbsAngles(this: entity, absAngles: (const QAngle *)frac);
    change->m_vecAngles = (QAngle)prevOrg;
  }
  p_m_Collision = &entity->m_Collision;
  v51 = entity->m_Collision.OBBMins(this: &entity->m_Collision);
  if ( v51->x != maxs.x
    || v51->y != maxs.y
    || v51->z != maxs.z
    || *(float *)(v52 = (int)p_m_Collision->OBBMaxs(this: p_m_Collision)) != ang.x
    || *(float *)(v52 + 4) != ang.y
    || *(float *)(v52 + 8) != ang.z )
  {
    OBBMins = p_m_Collision->OBBMins;
    v144 |= 0x400u;
    v54 = (float *)OBBMins(this: p_m_Collision);
    restore->m_vecMins.x = *v54;
    restore->m_vecMins.y = v54[1];
    OBBMaxs = p_m_Collision->OBBMaxs;
    restore->m_vecMins.z = v54[2];
    restore->m_vecMaxs = *OBBMaxs(this: p_m_Collision);
    CBaseEntity::SetSize(this: entity, mins: &maxs, maxs: (const Vector *)&ang);
    change->m_vecMins = maxs;
    change->m_vecMaxs = (Vector)ang;
  }
  *(float *)&layerIndex = mins.z * mins.z;
  if ( (float)((float)((float)(mins.z * mins.z) + (float)(mins.y * mins.y)) + (float)(v137 * v137)) > 0.010000001 )
  {
    m_iEFlags = entity->m_iEFlags;
    v144 |= 0x100u;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&pHitEntity);
    restore->m_vecOrigin.x = entity->m_vecAbsOrigin.x;
    v57 = entity->m_vecAbsOrigin.y;
    frac = (CGameTrace *)&v140;
    restore->m_vecOrigin.y = v57;
    restore->m_vecOrigin.z = entity->m_vecAbsOrigin.z;
    CBaseEntity::SetAbsOrigin(this: entity, absOrigin: &frac->startpos);
    change->m_vecOrigin.x = v140;
    change->m_vecOrigin.y = *(float *)&layerCount;
    change->m_vecOrigin.z = *(float *)&eh.m_Index;
  }
  v58 = *(_DWORD *)(LODWORD(org.x) + 52);
  if ( v58 != 0 )
  {
    if ( v58 != 2 )
      goto LABEL_79;
    v59 = org.x;
    AngleVectors(angles: (const QAngle *)(LODWORD(org.x) + 68), forward: (Vector *)((char *)&v130 + 4));
    v60 = *(float *)(LODWORD(v59) + 80);
    WorldSpaceCenter = entity->WorldSpaceCenter;
    *(float *)&v62 = (float)(*((float *)&v130 + 2) * v60) + *(float *)(LODWORD(v59) + 60);
    *(float *)&v63 = (float)(*((float *)&v130 + 3) * v60) + *(float *)(LODWORD(v59) + 64);
    *((float *)&orgdiff + 1) = (float)(*((float *)&v130 + 1) * v60) + *(float *)(LODWORD(v59) + 56);
    *((_QWORD *)&orgdiff + 1) = __PAIR64__(v63, v62);
    v64 = (float *)WorldSpaceCenter(this: entity);
    v65 = *((float *)&orgdiff + 2) - *(float *)(LODWORD(v59) + 60);
    v66 = *v64 - *(float *)(LODWORD(v59) + 56);
    v67 = v64[1] - *(float *)(LODWORD(v59) + 60);
    v132 = v64[2] - *(float *)(LODWORD(v59) + 64);
    v68 = *((float *)&orgdiff + 1) - *(float *)(LODWORD(v59) + 56);
    mins.z = v65;
    v69 = *((float *)&orgdiff + 3) - *(float *)(LODWORD(v59) + 64);
    LODWORD(org.y) = v64;
    forward.y = v66;
    forward.z = v67;
    mins.y = v68;
    v137 = v69;
    *(float *)&layerIndex = VectorNormalize(vec: (Vector *)&mins.y);
    v70 = (float)((float)(mins.y * forward.y) + (float)(mins.z * forward.z)) + (float)(v137 * v132);
    if ( v70 >= 0.0 )
    {
      if ( v70 <= *(float *)&layerIndex )
      {
        v76 = (float)(mins.z * v70) + *(float *)(LODWORD(v59) + 60);
        v77 = (float)(v137 * v70) + *(float *)(LODWORD(v59) + 64);
        v78 = *(float *)LODWORD(org.y) - (float)((float)(mins.y * v70) + *(float *)(LODWORD(v59) + 56));
        v79 = 0;
        *(float *)&v79 = fsqrt(
                           (float)((float)(v78 * v78)
                                 + (float)((float)(*(float *)(LODWORD(org.y) + 4) - v76)
                                         * (float)(*(float *)(LODWORD(org.y) + 4) - v76)))
                         + (float)((float)(*(float *)(LODWORD(org.y) + 8) - v77)
                                 * (float)(*(float *)(LODWORD(org.y) + 8) - v77)));
        v130 = v79;
        v74 = *(float *)&v79;
      }
      else
      {
        v75 = 0;
        *(float *)&v75 = fsqrt(
                           (float)((float)((float)(*(float *)LODWORD(org.y) - *((float *)&orgdiff + 1))
                                         * (float)(*(float *)LODWORD(org.y) - *((float *)&orgdiff + 1)))
                                 + (float)((float)(*(float *)(LODWORD(org.y) + 4) - *((float *)&orgdiff + 2))
                                         * (float)(*(float *)(LODWORD(org.y) + 4) - *((float *)&orgdiff + 2))))
                         + (float)((float)(*(float *)(LODWORD(org.y) + 8) - *((float *)&orgdiff + 3))
                                 * (float)(*(float *)(LODWORD(org.y) + 8) - *((float *)&orgdiff + 3))));
        v130 = v75;
        LODWORD(v74) = v75 ^ _mask__NegFloat_;
      }
    }
    else
    {
      v71 = *(float *)(LODWORD(org.y) + 4) - *(float *)(LODWORD(v59) + 60);
      v72 = (float)((float)((float)(*(float *)LODWORD(org.y) - *(float *)(LODWORD(v59) + 56))
                          * (float)(*(float *)LODWORD(org.y) - *(float *)(LODWORD(v59) + 56)))
                  + (float)(v71 * v71))
          + (float)((float)(*(float *)(LODWORD(org.y) + 8) - *(float *)(LODWORD(v59) + 64))
                  * (float)(*(float *)(LODWORD(org.y) + 8) - *(float *)(LODWORD(v59) + 64)));
      v73 = 0;
      *(float *)&v73 = fsqrt(v72);
      v130 = v73;
      LODWORD(v74) = v73 ^ _mask__NegFloat_;
    }
    if ( v74 >= 0.0 && v74 <= 100.0 )
    {
LABEL_79:
      if ( wantsAnims && entity->GetBaseAnimating(this: entity) != nullptr )
      {
        v80 = entity->GetBaseAnimating(this: entity);
        v144 |= 0x800u;
        v21 = flags == 0;
        v81 = v80;
        restore->m_masterSequence = v80->m_nSequence.m_Value;
        restore->m_masterCycle = v80->m_flCycle.m_Value;
        HIBYTE(frac) = 0;
        if ( !v21 )
          HIBYTE(frac) = *(_DWORD *)(v11 + 296) == *(_DWORD *)(flags + 296);
        if ( org.z > 0.0 && HIBYTE(frac) != 0 )
        {
          CBaseAnimating::SetSequence(
            this: v80,
            nSequence: (int)(float)((float)((float)(*(_DWORD *)(flags + 296) - *(_DWORD *)(v11 + 296)) * org.z)
                       + (float)*(int *)(v11 + 296)));
          CBaseAnimating::SetCycle(
            this: v81,
            flCycle: (float)((float)(*(float *)(flags + 300) - *(float *)(v11 + 300)) * org.z) + *(float *)(v11 + 300));
          v82 = *(float *)(flags + 300);
          v83 = *(float *)(v11 + 300);
          if ( v83 <= v82 )
          {
            v84 = (float)((float)(v82 - v83) * org.z) + v83;
          }
          else
          {
            v84 = (float)((float)((float)(v82 + 1.0) - v83) * org.z) + v83;
            if ( v84 >= 1.0 )
              v84 = v84 - 1.0;
          }
        }
        else
        {
          CBaseAnimating::SetSequence(this: v80, nSequence: *(_DWORD *)(v11 + 296));
          v84 = *(float *)(v11 + 300);
        }
        CBaseAnimating::SetCycle(this: v81, flCycle: v84);
        v85 = entity->GetBaseAnimatingOverlay(this: entity);
        v129 = v85;
        if ( v85 != nullptr )
        {
          HIDWORD(orgdiff) = v85->m_AnimOverlay.m_Size;
          org.y = 0.0;
          if ( SHIDWORD(orgdiff) > 0 )
          {
            v86 = flags;
            v139.m_Index = flags + 56;
            flags = (int)&restore->m_layerRecords[0].m_weight;
            layerIndex = v11 + 60;
            v126 = v86 - v11;
            v87 = (CBaseEntity *)((char *)restore - v11);
            v88 = v11 + 60;
            tr.m_pEnt = v87;
            v127 = v86 - (_DWORD)restore;
            while ( 1 )
            {
              AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: v129, iIndex: SLODWORD(org.y));
              if ( AnimOverlay == nullptr )
                goto LABEL_162;
              v90 = flags;
              *(float *)((char *)&tr.m_pEnt->__vftable + v88) = AnimOverlay->m_flCycle.m_Value;
              v91 = org.z;
              *(_DWORD *)(v90 + 4) = AnimOverlay->m_nOrder.m_Value;
              *(_DWORD *)(v90 - 8) = AnimOverlay->m_nSequence.m_Value;
              *(float *)v90 = AnimOverlay->m_flWeight.m_Value;
              if ( v91 <= 0.0
                || HIBYTE(frac) == 0
                || *(_DWORD *)(v88 + 8) != *(_DWORD *)(v126 + v88 + 8)
                || *(_DWORD *)(v88 - 4) != *(_DWORD *)v139.m_Index )
              {
                if ( AnimOverlay->m_flCycle.m_Value != *(float *)v88 )
                {
                  m_pOwnerEntity = AnimOverlay->m_pOwnerEntity;
                  if ( m_pOwnerEntity != nullptr )
                  {
                    if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
                    {
                      *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
                    }
                    else
                    {
                      v113 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
                      if ( v113 != nullptr )
                      {
                        v113->m_fStateFlags |= 0x101u;
                        CBaseEdict::GetChangeAccessor(this: v113)->m_iChangeInfoSerialNumber = 0;
                      }
                    }
                  }
                  AnimOverlay->m_flCycle.m_Value = *(float *)v88;
                }
                if ( AnimOverlay->m_nOrder.m_Value != *(_DWORD *)(v88 + 8) )
                {
                  v114 = AnimOverlay->m_pOwnerEntity;
                  if ( v114 != nullptr )
                  {
                    if ( v114->m_Network.m_TimerEvent.m_bRegistered )
                    {
                      *((_BYTE *)&v114->m_Network + 76) |= 1u;
                    }
                    else
                    {
                      v115 = &v114->m_Network.m_pPev->CBaseEdict;
                      if ( v115 != nullptr )
                      {
                        v115->m_fStateFlags |= 0x101u;
                        CBaseEdict::GetChangeAccessor(this: v115)->m_iChangeInfoSerialNumber = 0;
                      }
                    }
                  }
                  AnimOverlay->m_nOrder.m_Value = *(_DWORD *)(v88 + 8);
                }
                if ( AnimOverlay->m_nSequence.m_Value != *(_DWORD *)(v88 - 4) )
                {
                  v116 = AnimOverlay->m_pOwnerEntity;
                  if ( v116 != nullptr )
                  {
                    if ( v116->m_Network.m_TimerEvent.m_bRegistered )
                    {
                      *((_BYTE *)&v116->m_Network + 76) |= 1u;
                    }
                    else
                    {
                      v117 = &v116->m_Network.m_pPev->CBaseEdict;
                      if ( v117 != nullptr )
                      {
                        v117->m_fStateFlags |= 0x101u;
                        CBaseEdict::GetChangeAccessor(this: v117)->m_iChangeInfoSerialNumber = 0;
                      }
                    }
                  }
                  AnimOverlay->m_nSequence.m_Value = *(_DWORD *)(v88 - 4);
                }
                if ( AnimOverlay->m_flWeight.m_Value != *(float *)(v88 + 4) )
                {
                  v118 = AnimOverlay->m_pOwnerEntity;
                  if ( v118 != nullptr )
                  {
                    if ( v118->m_Network.m_TimerEvent.m_bRegistered )
                    {
                      *((_BYTE *)&v118->m_Network + 76) |= 1u;
                    }
                    else
                    {
                      v119 = &v118->m_Network.m_pPev->CBaseEdict;
                      if ( v119 != nullptr )
                      {
                        v119->m_fStateFlags |= 0x101u;
                        CBaseEdict::GetChangeAccessor(this: v119)->m_iChangeInfoSerialNumber = 0;
                      }
                    }
                  }
                  AnimOverlay->m_flWeight.m_Value = *(float *)(v88 + 4);
                }
                goto LABEL_162;
              }
              v92 = *(float *)(v126 + v88);
              v93 = *(float *)v88;
              if ( *(float *)v88 > v92 )
                break;
              v94 = (float)((float)(v92 - v93) * v91) + v93;
              v99 = AnimOverlay->m_flCycle.m_Value;
              v128 = v94;
              if ( v99 != v94 )
              {
                v100 = AnimOverlay->m_pOwnerEntity;
                if ( v100 != nullptr )
                {
                  if ( v100->m_Network.m_TimerEvent.m_bRegistered )
                  {
                    *((_BYTE *)&v100->m_Network + 76) |= 1u;
                  }
                  else
                  {
                    v101 = &v100->m_Network.m_pPev->CBaseEdict;
                    if ( v101 != nullptr )
                    {
                      v101->m_fStateFlags |= 0x101u;
                      v102 = CBaseEdict::GetChangeAccessor(this: v101);
                      v94 = v128;
                      v102->m_iChangeInfoSerialNumber = 0;
                    }
                  }
                }
LABEL_112:
                AnimOverlay->m_flCycle.m_Value = v94;
              }
LABEL_113:
              if ( AnimOverlay->m_nOrder.m_Value != *(_DWORD *)(v88 + 8) )
              {
                v103 = AnimOverlay->m_pOwnerEntity;
                if ( v103 != nullptr )
                {
                  if ( v103->m_Network.m_TimerEvent.m_bRegistered )
                  {
                    *((_BYTE *)&v103->m_Network + 76) |= 1u;
                  }
                  else
                  {
                    v104 = &v103->m_Network.m_pPev->CBaseEdict;
                    if ( v104 != nullptr )
                    {
                      v104->m_fStateFlags |= 0x101u;
                      CBaseEdict::GetChangeAccessor(this: v104)->m_iChangeInfoSerialNumber = 0;
                    }
                  }
                }
                AnimOverlay->m_nOrder.m_Value = *(_DWORD *)(v88 + 8);
              }
              if ( AnimOverlay->m_nSequence.m_Value != *(_DWORD *)(v88 - 4) )
              {
                v105 = AnimOverlay->m_pOwnerEntity;
                if ( v105 != nullptr )
                {
                  if ( v105->m_Network.m_TimerEvent.m_bRegistered )
                  {
                    *((_BYTE *)&v105->m_Network + 76) |= 1u;
                  }
                  else
                  {
                    v106 = &v105->m_Network.m_pPev->CBaseEdict;
                    if ( v106 != nullptr )
                    {
                      v106->m_fStateFlags |= 0x101u;
                      CBaseEdict::GetChangeAccessor(this: v106)->m_iChangeInfoSerialNumber = 0;
                    }
                  }
                }
                AnimOverlay->m_nSequence.m_Value = *(_DWORD *)(v88 - 4);
              }
              v108 = AnimOverlay->m_flWeight.m_Value;
              *(float *)&tr.hitbox = (float)((float)(*(float *)(v127 + flags) - *(float *)(v88 + 4)) * org.z)
                                   + *(float *)(v88 + 4);
              v107 = *(float *)&tr.hitbox;
              if ( v108 == *(float *)&tr.hitbox )
                goto LABEL_162;
              v109 = AnimOverlay->m_pOwnerEntity;
              if ( v109 == nullptr )
                goto LABEL_133;
              if ( !v109->m_Network.m_TimerEvent.m_bRegistered )
              {
                v110 = &v109->m_Network.m_pPev->CBaseEdict;
                if ( v110 != nullptr )
                {
                  v110->m_fStateFlags |= 0x101u;
                  v111 = CBaseEdict::GetChangeAccessor(this: v110);
                  v107 = *(float *)&tr.hitbox;
                  v111->m_iChangeInfoSerialNumber = 0;
                }
LABEL_133:
                AnimOverlay->m_flWeight.m_Value = v107;
                goto LABEL_162;
              }
              *((_BYTE *)&v109->m_Network + 76) |= 1u;
              AnimOverlay->m_flWeight.m_Value = v107;
LABEL_162:
              v139.m_Index += 16;
              flags += 16;
              v88 += 16;
              ++LODWORD(org.y);
              if ( SLODWORD(org.y) >= SHIDWORD(orgdiff) )
                goto LABEL_163;
            }
            v94 = (float)((float)((float)(v92 + 1.0) - v93) * v91) + v93;
            if ( v94 >= 1.0 )
              v94 = v94 - 1.0;
            v95 = AnimOverlay->m_flCycle.m_Value;
            *(float *)&layerIndex = v94;
            if ( v95 == v94 )
              goto LABEL_113;
            v96 = AnimOverlay->m_pOwnerEntity;
            if ( v96 != nullptr )
            {
              if ( v96->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&v96->m_Network + 76) |= 1u;
              }
              else
              {
                v97 = &v96->m_Network.m_pPev->CBaseEdict;
                if ( v97 != nullptr )
                {
                  v97->m_fStateFlags |= 0x101u;
                  v98 = CBaseEdict::GetChangeAccessor(this: v97);
                  v94 = *(float *)&layerIndex;
                  v98->m_iChangeInfoSerialNumber = 0;
                }
              }
            }
            goto LABEL_112;
          }
        }
      }
    }
  }
LABEL_163:
  if ( v144 == 0 )
  {
LABEL_18:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  if ( sv_lagflushbonecache.m_pParent != nullptr
    && sv_lagflushbonecache.m_pParent->m_Value.m_nValue != 0
    && (v144 & 0x800) != 0
    && entity->GetBaseAnimating(this: entity) != nullptr )
  {
    v120 = entity->GetBaseAnimating(this: entity);
    v120->InvalidateBoneCache(this: v120);
  }
  v121 = (LagRecord *)v144;
  *(_BYTE *)(LODWORD(org.x) + 44) = 1;
  restore->m_fFlags = (int)v121;
  change->m_fFlags = (int)v121;
  if ( sv_showlagcompensation.m_pParent != nullptr
    && sv_showlagcompensation.m_pParent->m_Value.m_nValue == 1
    && entity->GetBaseAnimating(this: entity) != nullptr )
  {
    GetBaseAnimating = entity->GetBaseAnimating;
    frac = (CGameTrace *)1;
    *(float *)&layerIndex = 4.0;
    v123 = GetBaseAnimating(this: entity);
    CBaseAnimating::DrawServerHitboxes(this: v123, duration: *(float *)&layerIndex, monocolor: (bool)frac);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CDA00
// Name: public: void CLagCompensationManager::RestoreEntityFromRecords(class CBaseEntity __near *,struct LagRecord __near *,struct LagRecord __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLagCompensationManager::RestoreEntityFromRecords(
        CLagCompensationManager *this,
        CBaseAnimatingOverlay *entity,
        LagRecord *restore,
        LagRecord *change,
        bool wantsAnims)
{
  bool v6; // zf
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v8; // eax
  const Vector *v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  CBaseAnimating *v17; // eax
  LagRecord *v18; // edi
  CBaseAnimating *v19; // esi
  CBaseAnimatingOverlay *v20; // eax
  int *p_m_order; // esi
  CAnimationLayer *AnimOverlay; // eax
  CAnimationLayer *v23; // edi
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v25; // eax
  CBaseAnimatingOverlay *v26; // eax
  CBaseEdict *v27; // eax
  CBaseAnimatingOverlay *v28; // eax
  CBaseEdict *v29; // eax
  CBaseAnimatingOverlay *v30; // eax
  CBaseEdict *v31; // eax
  float m_flSimulationTime; // xmm0_4
  edict_t *m_pPev; // ecx
  Vector vWantedPos; // [esp+10h] [ebp-10h] BYREF
  bool restoreSimulationTime; // [esp+1Fh] [ebp-1h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF
  CBaseAnimatingOverlay *pAnimatingOverlay; // [esp+28h] [ebp+8h]
  int layerCount; // [esp+30h] [ebp+10h]
  int layerIndex; // [esp+34h] [ebp+14h]

  v6 = (restore->m_fFlags & 0x400) == 0;
  restoreSimulationTime = false;
  if ( !v6 )
  {
    OBBMins = entity->m_Collision.OBBMins;
    restoreSimulationTime = true;
    v8 = (float *)OBBMins(this: &entity->m_Collision);
    if ( change->m_vecMins.x == *v8 && change->m_vecMins.y == v8[1] && change->m_vecMins.z == v8[2] )
    {
      v9 = entity->m_Collision.OBBMaxs(this: &entity->m_Collision);
      if ( change->m_vecMaxs.x == v9->x && change->m_vecMaxs.y == v9->y && change->m_vecMaxs.z == v9->z )
        CBaseEntity::SetSize(this: entity, mins: &restore->m_vecMins, maxs: &restore->m_vecMaxs);
    }
  }
  if ( (restore->m_fFlags & 0x200) != 0 )
  {
    v10 = (unsigned int)entity->m_iEFlags >> 11;
    restoreSimulationTime = true;
    if ( (v10 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    if ( change->m_vecAngles.x == entity->m_angAbsRotation.x
      && change->m_vecAngles.y == entity->m_angAbsRotation.y
      && change->m_vecAngles.z == entity->m_angAbsRotation.z )
    {
      CBaseEntity::SetAbsAngles(this: entity, absAngles: &restore->m_vecAngles);
    }
  }
  if ( (restore->m_fFlags & 0x100) != 0 )
  {
    v11 = (unsigned int)entity->m_iEFlags >> 11;
    restoreSimulationTime = true;
    if ( (v11 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    v12 = entity->m_vecAbsOrigin.x - change->m_vecOrigin.x;
    v13 = entity->m_vecAbsOrigin.y - change->m_vecOrigin.y;
    v14 = entity->m_vecAbsOrigin.z - change->m_vecOrigin.z;
    if ( (float)((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v14 * v14)) < 4096.0 )
    {
      v15 = restore->m_vecOrigin.x + v12;
      vWantedPos.y = restore->m_vecOrigin.y + v13;
      v16 = restore->m_vecOrigin.z + v14;
      vWantedPos.x = v15;
      vWantedPos.z = v16;
      RestoreEntityTo(pEntity: entity, &vWantedPos);
    }
  }
  v17 = entity->GetBaseAnimating(this: entity);
  v18 = restore;
  v19 = v17;
  if ( wantsAnims && v17 != nullptr && (restore->m_fFlags & 0x800) != 0 )
  {
    CBaseAnimating::SetSequence(this: v17, nSequence: restore->m_masterSequence);
    CBaseAnimating::SetCycle(this: v19, flCycle: restore->m_masterCycle);
    v20 = entity->GetBaseAnimatingOverlay(this: entity);
    pAnimatingOverlay = v20;
    if ( v20 != nullptr )
    {
      layerCount = v20->m_AnimOverlay.m_Size;
      layerIndex = 0;
      if ( layerCount > 0 )
      {
        p_m_order = &restore->m_layerRecords[0].m_order;
        while ( 1 )
        {
          AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: v20, iIndex: layerIndex);
          v23 = AnimOverlay;
          if ( AnimOverlay != nullptr )
          {
            if ( AnimOverlay->m_flCycle.m_Value != *((float *)p_m_order - 2) )
            {
              m_pOwnerEntity = AnimOverlay->m_pOwnerEntity;
              if ( m_pOwnerEntity != nullptr )
              {
                if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
                {
                  *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
                }
                else
                {
                  v25 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
                  if ( v25 != nullptr )
                  {
                    v25->m_fStateFlags |= 0x101u;
                    CBaseEdict::GetChangeAccessor(this: v25)->m_iChangeInfoSerialNumber = 0;
                  }
                }
              }
              v23->m_flCycle.m_Value = *((float *)p_m_order - 2);
            }
            if ( v23->m_nOrder.m_Value != *p_m_order )
            {
              v26 = v23->m_pOwnerEntity;
              if ( v26 != nullptr )
              {
                if ( v26->m_Network.m_TimerEvent.m_bRegistered )
                {
                  *((_BYTE *)&v26->m_Network + 76) |= 1u;
                }
                else
                {
                  v27 = &v26->m_Network.m_pPev->CBaseEdict;
                  if ( v27 != nullptr )
                  {
                    v27->m_fStateFlags |= 0x101u;
                    CBaseEdict::GetChangeAccessor(this: v27)->m_iChangeInfoSerialNumber = 0;
                  }
                }
              }
              v23->m_nOrder.m_Value = *p_m_order;
            }
            if ( v23->m_nSequence.m_Value != *(p_m_order - 3) )
            {
              v28 = v23->m_pOwnerEntity;
              if ( v28 != nullptr )
              {
                if ( v28->m_Network.m_TimerEvent.m_bRegistered )
                {
                  *((_BYTE *)&v28->m_Network + 76) |= 1u;
                }
                else
                {
                  v29 = &v28->m_Network.m_pPev->CBaseEdict;
                  if ( v29 != nullptr )
                  {
                    v29->m_fStateFlags |= 0x101u;
                    CBaseEdict::GetChangeAccessor(this: v29)->m_iChangeInfoSerialNumber = 0;
                  }
                }
              }
              v23->m_nSequence.m_Value = *(p_m_order - 3);
            }
            if ( v23->m_flWeight.m_Value != *((float *)p_m_order - 1) )
            {
              v30 = v23->m_pOwnerEntity;
              if ( v30 != nullptr )
              {
                if ( v30->m_Network.m_TimerEvent.m_bRegistered )
                {
                  *((_BYTE *)&v30->m_Network + 76) |= 1u;
                }
                else
                {
                  v31 = &v30->m_Network.m_pPev->CBaseEdict;
                  if ( v31 != nullptr )
                  {
                    v31->m_fStateFlags |= 0x101u;
                    CBaseEdict::GetChangeAccessor(this: v31)->m_iChangeInfoSerialNumber = 0;
                  }
                }
              }
              v23->m_flWeight.m_Value = *((float *)p_m_order - 1);
            }
          }
          p_m_order += 4;
          if ( ++layerIndex >= layerCount )
            break;
          v20 = pAnimatingOverlay;
        }
        v18 = restore;
      }
    }
  }
  else if ( !restoreSimulationTime )
  {
    return;
  }
  m_flSimulationTime = v18->m_flSimulationTime;
  if ( entity->m_flSimulationTime.m_Value != m_flSimulationTime )
  {
    if ( entity->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&entity->m_Network + 76) |= 1u;
      entity->m_flSimulationTime.m_Value = m_flSimulationTime;
    }
    else
    {
      m_pPev = entity->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x68u);
      entity->m_flSimulationTime.m_Value = m_flSimulationTime;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDF30
// Name: public: virtual void CLagCompensationManager::FinishLagCompensation(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLagCompensationManager::FinishLagCompensation(CLagCompensationManager *this, CBasePlayer *player)
{
  bool v3; // zf
  unsigned __int16 i; // si
  const char *m_pszName; // ecx
  int v6; // edx
  unsigned int v7; // eax
  CBaseAnimatingOverlay *m_pEntity; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FinishLagCompensation",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 3);
  v3 = LOBYTE(this->m_CompensatedEntities.m_Tree.m_Root) == 0;
  LOBYTE(this->m_weaponAngles.y) = 0;
  if ( !v3 )
  {
    for ( i = CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_pNext);
          i != 0xFFFF;
          i = CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_pNext,
                i) )
    {
      m_pszName = this->m_pszName;
      v6 = *(_DWORD *)&m_pszName[16 * i + 12];
      if ( *(_BYTE *)v6 != 0 )
      {
        v7 = *(_DWORD *)&m_pszName[16 * i + 8];
        if ( v7 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
        {
          m_pEntity = (CBaseAnimatingOverlay *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
          if ( m_pEntity != nullptr )
            CLagCompensationManager::RestoreEntityFromRecords(
              this: (CLagCompensationManager *)((char *)this - 12),
              entity: m_pEntity,
              restore: (LagRecord *)(v6 + 48),
              change: (LagRecord *)(v6 + 352),
              wantsAnims: true);
        }
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101CE000
// Name: public: void CLagCompensationManager::RecordDataIntoTrack(class CBaseEntity __near *,class CUtlFixedLinkedList<struct LagRecord> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLagCompensationManager::RecordDataIntoTrack(
        CLagCompensationManager *this,
        CBaseAnimating *entity,
        CUtlFixedLinkedList<LagRecord> *track,
        bool wantsAnims)
{
  int m_Tail; // esi
  int v5; // edi
  int v6; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *v8; // esi
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v10; // eax
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v12; // eax
  CBaseAnimating *v13; // eax
  CBaseAnimating *v14; // ebx
  CBaseAnimatingOverlay *v15; // eax
  int v16; // edi
  int *p_m_nBlockSize; // ebx
  CAnimationLayer *AnimOverlay; // eax
  int flDeadtime; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h] BYREF
  CBaseAnimating *pAnimating; // [esp+Ch] [ebp+8h]
  int layerCount; // [esp+10h] [ebp+Ch]
  CBaseAnimatingOverlay *pAnimatingOverlay; // [esp+14h] [ebp+10h]

  flDeadtime = (int)(float)(gpGlobals->curtime - sv_maxunlag.m_pParent->m_Value.m_fValue);
  while ( 1 )
  {
    m_Tail = track->m_Tail;
    if ( m_Tail == 0 )
      break;
    v5 = *(_DWORD *)(m_Tail + 304);
    if ( v5 == m_Tail && *(_DWORD *)(m_Tail + 308) != m_Tail )
      break;
    if ( *(float *)(m_Tail + 52) >= (float)flDeadtime )
      break;
    if ( !CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::IsIdxAfter(
            this: &track->m_Memory,
            i: m_Tail,
            it: &track->m_LastAlloc)
      && v5 != m_Tail )
    {
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 308) = *(_DWORD *)(m_Tail + 308);
      else
        track->m_Head = *(_DWORD *)(m_Tail + 308);
      v6 = *(_DWORD *)(m_Tail + 308);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 304) = *(_DWORD *)(m_Tail + 304);
      else
        track->m_Tail = *(_DWORD *)(m_Tail + 304);
      *(_DWORD *)(m_Tail + 308) = m_Tail;
      *(_DWORD *)(m_Tail + 304) = m_Tail;
      --track->m_ElementCount;
    }
    *(_DWORD *)(m_Tail + 308) = track->m_FirstFree;
    track->m_FirstFree = m_Tail;
  }
  if ( track->m_ElementCount <= 0 || *(float *)(track->m_Head + 52) < entity->m_flSimulationTime.m_Value )
  {
    v8 = CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AddToHead(this: track);
    v8->m_pNext = nullptr;
    if ( entity->IsAlive(this: entity) )
      v8->m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)((int)v8->m_pNext | 1);
    *(float *)&v8[6].m_nBlockSize = entity->m_flSimulationTime.m_Value;
    if ( (entity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    *(QAngle *)&v8[2].m_pNext = entity->m_angAbsRotation;
    if ( (entity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    OBBMaxs = entity->m_Collision.OBBMaxs;
    *(Vector *)&v8->m_nBlockSize = entity->m_vecAbsOrigin;
    v10 = (float *)OBBMaxs(this: &entity->m_Collision);
    v8[5].m_pNext = *(CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t **)v10;
    v8[5].m_nBlockSize = (int)v10[1];
    OBBMins = entity->m_Collision.OBBMins;
    v8[6].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)v10[2];
    v12 = (float *)OBBMins(this: &entity->m_Collision);
    v8[3].m_nBlockSize = *(int *)v12;
    v8[4].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)v12[1];
    v8[4].m_nBlockSize = (int)v12[2];
    v13 = entity->GetBaseAnimating(this: entity);
    v14 = v13;
    pAnimating = v13;
    if ( wantsAnims && v13 != nullptr )
    {
      v15 = entity->GetBaseAnimatingOverlay(this: entity);
      pAnimatingOverlay = v15;
      if ( v15 != nullptr )
      {
        v16 = 0;
        layerCount = v15->m_AnimOverlay.m_Size;
        if ( layerCount > 0 )
        {
          p_m_nBlockSize = &v8[8].m_nBlockSize;
          while ( 1 )
          {
            AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: v15, iIndex: v16);
            if ( AnimOverlay != nullptr )
            {
              *(p_m_nBlockSize - 2) = SLODWORD(AnimOverlay->m_flCycle.m_Value);
              *p_m_nBlockSize = AnimOverlay->m_nOrder.m_Value;
              *(p_m_nBlockSize - 3) = AnimOverlay->m_nSequence.m_Value;
              *(p_m_nBlockSize - 1) = SLODWORD(AnimOverlay->m_flWeight.m_Value);
            }
            ++v16;
            p_m_nBlockSize += 4;
            if ( v16 >= layerCount )
              break;
            v15 = pAnimatingOverlay;
          }
          v14 = pAnimating;
        }
      }
      v8[37].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)v14->m_nSequence.m_Value;
      *(float *)&v8[37].m_nBlockSize = v14->m_flCycle.m_Value;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE2C0
// Name: public: CLagCompensationManager::CLagCompensationManager(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLagCompensationManager *__thiscall CLagCompensationManager::CLagCompensationManager(
        CLagCompensationManager *this,
        const char *name)
{
  UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short> *m_pMemory; // ecx

  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name);
  this->ILagCompensationManager::__vftable = (ILagCompensationManager_vtbl *)&ILagCompensationManager::`vftable';
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CLagCompensationManager_vtbl *)&CLagCompensationManager::`vftable'{for `CAutoGameSystemPerFrame'};
  this->ILagCompensationManager::__vftable = (ILagCompensationManager_vtbl *)&CLagCompensationManager::`vftable'{for `ILagCompensationManager'};
  this->m_CompensatedEntities.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CHandle<CBaseEntity> *, const CHandle<CBaseEntity> *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_CompensatedEntities.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_CompensatedEntities.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_CompensatedEntities.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_CompensatedEntities.m_Tree.m_Root = -1;
  this->m_CompensatedEntities.m_Tree.m_NumElements = 0;
  this->m_CompensatedEntities.m_Tree.m_FirstFree = -1;
  this->m_CompensatedEntities.m_Tree.m_LastAlloc.index = -1;
  this->m_CompensatedEntities.m_Tree.m_pElements = this->m_CompensatedEntities.m_Tree.m_Elements.m_pMemory;
  this->m_AdditionalEntities.m_LessFunc = (bool (__cdecl *)(const CHandle<CBaseEntity> *, const CHandle<CBaseEntity> *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_AdditionalEntities.m_Elements.m_pMemory = nullptr;
  this->m_AdditionalEntities.m_Elements.m_nAllocationCount = 0;
  this->m_AdditionalEntities.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_AdditionalEntities.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_AdditionalEntities.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_AdditionalEntities.m_FirstFree = -1;
  this->m_AdditionalEntities.m_pElements = m_pMemory;
  this->m_bNeedToRestore = false;
  this->m_isCurrentlyDoingCompensation = false;
  this->m_weaponRange = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101CE350
// Name: private: void CLagCompensationManager::ClearHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLagCompensationManager::ClearHistory(CLagCompensationManager *this)
{
  CLagCompensationManager *v1; // edi
  CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short> *p_m_CompensatedEntities; // esi
  int i; // ebx
  CLagCompensationManager::EntityLagData *elem; // eax
  CUtlFixedLinkedList<LagRecord> *p_m_LagRecords; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *v7; // [esp-4h] [ebp-18h]
  CLagCompensationManager::EntityLagData *pMem; // [esp+10h] [ebp-4h]

  v1 = this;
  p_m_CompensatedEntities = &this->m_CompensatedEntities;
  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_CompensatedEntities.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &v1->m_CompensatedEntities.m_Tree,
                                i) )
  {
    elem = v1->m_CompensatedEntities.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    pMem = elem;
    if ( elem != nullptr )
    {
      p_m_LagRecords = &elem->m_LagRecords;
      CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::RemoveAll(this: &elem->m_LagRecords);
      m_pBlocks = p_m_LagRecords->m_Memory.m_pBlocks;
      if ( p_m_LagRecords->m_Memory.m_pBlocks != nullptr )
      {
        do
        {
          v7 = m_pBlocks;
          m_pBlocks = m_pBlocks->m_pNext;
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
        }
        while ( m_pBlocks != nullptr );
        p_m_LagRecords->m_Memory.m_pBlocks = nullptr;
        p_m_LagRecords->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem);
      v1 = this;
    }
    p_m_CompensatedEntities = &v1->m_CompensatedEntities;
  }
  CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_CompensatedEntities->m_Tree);
  p_m_CompensatedEntities->m_Tree.m_FirstFree = -1;
  if ( p_m_CompensatedEntities->m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    p_m_CompensatedEntities->m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( p_m_CompensatedEntities->m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_CompensatedEntities->m_Tree.m_Elements.m_pMemory);
      p_m_CompensatedEntities->m_Tree.m_Elements.m_pMemory = nullptr;
    }
    p_m_CompensatedEntities->m_Tree.m_Elements.m_nAllocationCount = 0;
    p_m_CompensatedEntities->m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE470
// Name: public: virtual void CLagCompensationManager::AddAdditionalEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLagCompensationManager::AddAdditionalEntity(
        CLagCompensationManager *this@<ecx>,
        const char *a2@<edi>,
        CBaseEntity *pEntity)
{
  unsigned int m_Index; // eax
  CHandle<CBaseEntity> eh; // [esp+4h] [ebp-4h] BYREF

  m_Index = -1;
  eh.m_Index = -1;
  if ( pEntity != nullptr )
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  eh.m_Index = m_Index;
  if ( CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>::Find(
         this: (CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl*)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short> > *)&this->m_weaponAngles.z,
         search: &eh) == 0xFFFF )
    CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>::Insert(
      this: (CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl*)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short> > *)&this->m_weaponAngles.z,
      a2,
      insert: &eh);
}

//------------------------------------------------------------------------------
// Address: 0x101CE4C0
// Name: public: virtual void CLagCompensationManager::RemoveAdditionalEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLagCompensationManager::RemoveAdditionalEntity(CLagCompensationManager *this, CBaseEntity *pEntity)
{
  unsigned int m_Index; // eax
  unsigned __int16 v4; // ax
  int v5; // edi
  int v6; // eax
  CHandle<CBaseEntity> eh; // [esp+8h] [ebp-4h] BYREF

  m_Index = -1;
  eh.m_Index = -1;
  if ( pEntity != nullptr )
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  eh.m_Index = m_Index;
  v4 = CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>::Find(
         this: (CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl*)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short> > *)&this->m_weaponAngles.z,
         search: &eh);
  v5 = v4;
  if ( v4 != 0xFFFF )
  {
    CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl*)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short> > *)&this->m_weaponAngles.z,
      elem: v4);
    v6 = 12 * v5;
    *(_WORD *)(v6 + LODWORD(this->m_weaponRange)) = v5;
    *(_WORD *)(v6 + LODWORD(this->m_weaponRange) + 2) = this->m_AdditionalEntities.m_Elements.m_nAllocationCount;
    --HIWORD(this->m_AdditionalEntities.m_Elements.m_pMemory);
    LOWORD(this->m_AdditionalEntities.m_Elements.m_nAllocationCount) = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE540
// Name: public: virtual void CLagCompensationManager::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLagCompensationManager::FrameUpdatePostEntityThink(CLagCompensationManager *this)
{
  int v1; // edi
  CBasePlayer *v2; // esi
  const char *j; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v6; // ecx
  UtlRBTreeNode_t<CBaseEntity *,unsigned short> *m_pMemory; // eax
  unsigned int v8; // esi
  CBaseEntity **p_m_Data; // esi
  int v10; // esi
  CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short> *p_m_CompensatedEntities; // edi
  CBaseEntity *m_Data; // ecx
  unsigned __int16 v13; // ax
  _DWORD *v14; // eax
  _DWORD *v15; // ecx
  int k; // edx
  _DWORD *v17; // ecx
  int m; // edx
  _DWORD *v19; // ecx
  int n; // edx
  _DWORD *v21; // ecx
  int ii; // edx
  CLagCompensationManager *v23; // edi
  unsigned __int16 v24; // ax
  unsigned __int16 v25; // dx
  CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl*)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short> > *v26; // ecx
  UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short> *v27; // eax
  int v28; // esi
  UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short> *v29; // eax
  CLagCompensationManager *v30; // edi
  UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short> *v31; // eax
  int v32; // edx
  UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short> *v33; // ecx
  CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t *v34; // esi
  CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl*)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short> > rbEntityList; // [esp+8h] [ebp-44h] BYREF
  CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t search; // [esp+24h] [ebp-28h] BYREF
  CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t insert; // [esp+2Ch] [ebp-20h] BYREF
  CBaseEntity *pEntity; // [esp+34h] [ebp-18h]
  CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl*)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short> > *p_m_AdditionalEntities; // [esp+38h] [ebp-14h]
  CHandle<CBaseEntity> eh; // [esp+3Ch] [ebp-10h] BYREF
  int i; // [esp+40h] [ebp-Ch] BYREF
  CLagCompensationManager *v42; // [esp+44h] [ebp-8h]
  bool leftchild; // [esp+4Bh] [ebp-1h] BYREF

  v1 = 1;
  v42 = this;
  if ( gpGlobals->maxClients > 1 && sv_unlag.m_pParent != nullptr && sv_unlag.m_pParent->m_Value.m_nValue != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "FrameUpdatePostEntityThink",
      a3: 0,
      a4: "CLagCompensationManager",
      a5: false,
      a6: 4);
    rbEntityList.m_LessFunc = (bool (__cdecl *)(CBaseEntity *const *, CBaseEntity *const *))CDefOps<CChoreoActor *>::LessFunc;
    memset(&rbEntityList.m_Elements, 0, sizeof(rbEntityList.m_Elements));
    *(_DWORD *)&rbEntityList.m_Root = 0xFFFF;
    *(_DWORD *)&rbEntityList.m_FirstFree = -1;
    rbEntityList.m_pElements = nullptr;
    if ( gpGlobals->maxClients >= 1 )
    {
      do
      {
        v2 = UTIL_PlayerByIndex(playerIndex: v1);
        if ( v2 != nullptr )
        {
          eh.m_Index = (unsigned int)v2;
          if ( CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::Find(
                 this: &rbEntityList,
                 search: (CBaseEntity *const *)&eh) == 0xFFFF )
          {
            eh.m_Index = (unsigned int)v2;
            CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::Insert(
              this: &rbEntityList,
              insert: (CBaseEntity *const *)&eh);
          }
        }
        ++v1;
      }
      while ( v1 <= gpGlobals->maxClients );
    }
    p_m_AdditionalEntities = &v42->m_AdditionalEntities;
    for ( j = (const char *)(unsigned __int16)CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>::FirstInorder(this: &v42->m_AdditionalEntities);
          j != (const char *)0xFFFF;
          j = (const char *)(unsigned __int16)CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl *)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short>>::NextInorder(
                                                this: p_m_AdditionalEntities,
                                                i: (unsigned __int16)j) )
    {
      m_Index = v42->m_AdditionalEntities.m_Elements.m_pMemory[(unsigned __int16)j].m_Data.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      eh.m_Index = (unsigned int)m_pEntity;
      if ( m_pEntity != nullptr
        && CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::Find(
             this: &rbEntityList,
             search: (CBaseEntity *const *)&eh) == 0xFFFF )
      {
        i = 0xFFFF;
        leftchild = false;
        CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &rbEntityList,
          insert: (CBaseEntity *const *)&eh,
          parent: (unsigned __int16 *)&i,
          &leftchild);
        v6 = (unsigned __int16)CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
                                 this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&rbEntityList,
                                 a2: j);
        m_pMemory = rbEntityList.m_Elements.m_pMemory;
        v8 = v6;
        rbEntityList.m_Elements.m_pMemory[v8].m_Parent = i;
        m_pMemory[v8].m_Right = -1;
        m_pMemory[v8].m_Left = -1;
        m_pMemory[v8].m_Tag = 0;
        if ( (_WORD)i == 0xFFFF )
        {
          rbEntityList.m_Root = v6;
        }
        else if ( leftchild )
        {
          m_pMemory[(unsigned __int16)i].m_Left = v6;
        }
        else
        {
          m_pMemory[(unsigned __int16)i].m_Right = v6;
        }
        CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::InsertRebalance(
          this: &rbEntityList,
          elem: v6);
        ++rbEntityList.m_NumElements;
        p_m_Data = &rbEntityList.m_Elements.m_pMemory[v8].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = (CBaseEntity *)eh.m_Index;
      }
    }
    v10 = (unsigned __int16)CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::FirstInorder(this: &rbEntityList);
    i = v10;
    if ( v10 != 0xFFFF )
    {
      p_m_CompensatedEntities = &v42->m_CompensatedEntities;
      do
      {
        m_Data = rbEntityList.m_Elements.m_pMemory[(unsigned __int16)v10].m_Data;
        pEntity = m_Data;
        if ( m_Data != nullptr )
          eh.m_Index = m_Data->GetRefEHandle(this: m_Data)->m_Index;
        else
          eh.m_Index = -1;
        search.key = eh;
        v13 = CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &p_m_CompensatedEntities->m_Tree,
                &search);
        if ( v13 == 0xFFFF )
        {
          v14 = operator new(nSize: 0x290u);
          if ( v14 != nullptr )
          {
            *(_BYTE *)v14 = 0;
            v14[1] = 0;
            v14[2] = 0;
            v14[3] = 0;
            v14[9] = 0;
            v14[10] = -1;
            v14[4] = 0;
            v14[5] = 0;
            v14[6] = 0;
            v14[7] = 0;
            v14[8] = 0;
            v14[11] = 0;
            v15 = v14 + 26;
            for ( k = 14; k >= 0; --k )
            {
              *v15 = 0;
              v15[1] = 0;
              v15[2] = 0;
              v15[3] = 0;
              v15 += 4;
            }
            v14[12] = 0;
            v14[13] = 0;
            v14[14] = 0;
            v14[15] = 0;
            v14[16] = 0;
            v14[17] = 0;
            v14[18] = 0;
            v14[19] = 0;
            v14[20] = 0;
            v14[21] = 0;
            v14[22] = 0;
            v14[23] = 0;
            v14[24] = 0;
            v14[25] = -1082130432;
            v14[86] = 0;
            v14[87] = 0;
            v17 = v14 + 28;
            for ( m = 15; m != 0; --m )
            {
              *(v17 - 2) = 0;
              *(v17 - 1) = 0;
              *v17 = 0;
              v17[1] = 0;
              v17 += 4;
            }
            v19 = v14 + 102;
            for ( n = 14; n >= 0; --n )
            {
              *v19 = 0;
              v19[1] = 0;
              v19[2] = 0;
              v19[3] = 0;
              v19 += 4;
            }
            v14[88] = 0;
            v14[89] = 0;
            v14[90] = 0;
            v14[91] = 0;
            v14[92] = 0;
            v14[93] = 0;
            v14[94] = 0;
            v14[95] = 0;
            v14[96] = 0;
            v14[97] = 0;
            v14[98] = 0;
            v14[99] = 0;
            v14[100] = 0;
            v14[101] = -1082130432;
            v14[162] = 0;
            v14[163] = 0;
            v21 = v14 + 104;
            for ( ii = 15; ii != 0; --ii )
            {
              *(v21 - 2) = 0;
              *(v21 - 1) = 0;
              *v21 = 0;
              v21[1] = 0;
              v21 += 4;
            }
          }
          else
          {
            v14 = nullptr;
          }
          v23 = v42;
          insert.elem = (CLagCompensationManager::EntityLagData *)v14;
          insert.key = eh;
          eh.m_Index = 0xFFFF;
          leftchild = false;
          CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: &v42->m_CompensatedEntities.m_Tree,
            &insert,
            parent: (unsigned __int16 *)&eh,
            &leftchild);
          v24 = CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                  this: &v23->m_CompensatedEntities.m_Tree,
                  a2: (const char *)v23);
          v25 = eh.m_Index;
          v26 = (CUtlRBTree<CHandle<CBaseEntity>,unsigned short,bool (__cdecl*)(CHandle<CBaseEntity> const &,CHandle<CBaseEntity> const &),CUtlMemory<UtlRBTreeNode_t<CHandle<CBaseEntity>,unsigned short>,unsigned short> > *)v24;
          v27 = v23->m_CompensatedEntities.m_Tree.m_Elements.m_pMemory;
          p_m_AdditionalEntities = v26;
          v28 = (int)v26;
          v29 = &v27[(_DWORD)v26];
          v29->m_Right = -1;
          v29->m_Left = -1;
          v29->m_Tag = 0;
          v30 = v42;
          v29->m_Parent = v25;
          p_m_CompensatedEntities = &v30->m_CompensatedEntities;
          if ( v25 == 0xFFFF )
          {
            p_m_CompensatedEntities->m_Tree.m_Root = (unsigned __int16)v26;
          }
          else
          {
            v31 = p_m_CompensatedEntities->m_Tree.m_Elements.m_pMemory;
            v32 = v25;
            if ( leftchild )
              v31[v32].m_Left = (unsigned __int16)v26;
            else
              v31[v32].m_Right = (unsigned __int16)v26;
          }
          CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: &p_m_CompensatedEntities->m_Tree,
            elem: (unsigned __int16)v26);
          v33 = p_m_CompensatedEntities->m_Tree.m_Elements.m_pMemory;
          ++p_m_CompensatedEntities->m_Tree.m_NumElements;
          v34 = &v33[v28].m_Data;
          if ( v34 != nullptr )
            *v34 = insert;
          v13 = (unsigned __int16)p_m_AdditionalEntities;
          LOWORD(v10) = i;
        }
        CLagCompensationManager::RecordDataIntoTrack(
          this: v42,
          entity: (CBaseAnimating *)pEntity,
          track: &v42->m_CompensatedEntities.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem->m_LagRecords,
          wantsAnims: true);
        v10 = (unsigned __int16)CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::NextInorder(
                                  this: &rbEntityList,
                                  i: v10);
        i = v10;
      }
      while ( v10 != 0xFFFF );
    }
    CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::RemoveAll(this: &rbEntityList);
    if ( rbEntityList.m_Elements.m_nGrowSize >= 0 && rbEntityList.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rbEntityList.m_Elements.m_pMemory);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CLagCompensationManager::ClearHistory(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CEA80
// Name: public: virtual void CLagCompensationManager::StartLagCompensation(class CBasePlayer __near *,enum LagCompensationType,class Vector const __near &,class QAngle const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLagCompensationManager::StartLagCompensation(
        CLagCompensationManager *this,
        CBasePlayer *player,
        UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short> *lagCompensationType,
        const CBitVec<2048> *weaponPos,
        Vector *weaponAngles,
        float weaponRange)
{
  const char *m_pszName; // edx
  unsigned int v7; // ebx
  int v8; // eax
  int m_Size; // eax
  int v10; // edi
  int v11; // eax
  CHandle<CBaseEntity> *v12; // edi
  _DWORD *v13; // ecx
  int j; // edx
  _DWORD *v15; // eax
  int k; // ecx
  CLagCompensationManager *v17; // esi
  float v18; // eax
  int v19; // ebx
  const char *v20; // ecx
  int v21; // eax
  _DWORD *v22; // edx
  bool v23; // zf
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t **v24; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *v25; // edi
  int v26; // ebx
  int v27; // eax
  int m_nBlockSize; // eax
  _DWORD *v29; // edi
  const CUserCmd *v30; // eax
  CUserCmd *m_pCurrentCommand; // ebx
  edict_t *m_pPev; // eax
  INetChannelInfo *v33; // eax
  float m_fValue; // xmm2_4
  float v35; // xmm0_4
  float interval_per_tick; // xmm3_4
  float v37; // xmm0_4
  int m_nValue; // eax
  edict_t *v39; // eax
  unsigned __int16 Inorder; // ax
  const char *v41; // edx
  int v42; // eax
  int v43; // edi
  unsigned int v44; // eax
  CBasePlayer **v45; // ecx
  CBasePlayer *v46; // ebx
  void *v47; // [esp+40h] [ebp-64h]
  const char *v48; // [esp+44h] [ebp-60h]
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > invalidList; // [esp+50h] [ebp-54h] BYREF
  CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t search; // [esp+64h] [ebp-40h] BYREF
  int v51; // [esp+6Ch] [ebp-38h]
  int v52; // [esp+70h] [ebp-34h]
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *v53; // [esp+74h] [ebp-30h]
  int v54; // [esp+78h] [ebp-2Ch]
  _DWORD v55[2]; // [esp+7Ch] [ebp-28h] BYREF
  _DWORD v56[2]; // [esp+84h] [ebp-20h] BYREF
  const CUserCmd *cmd; // [esp+8Ch] [ebp-18h]
  int slot; // [esp+90h] [ebp-14h]
  float correct; // [esp+94h] [ebp-10h]
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::Iterator_t *it; // [esp+98h] [ebp-Ch]
  CLagCompensationManager *v61; // [esp+9Ch] [ebp-8h]
  int i; // [esp+A0h] [ebp-4h]
  int savedregs; // [esp+A4h] [ebp+0h] BYREF
  LagCompensationType lagCompensationTypea; // [esp+B0h] [ebp+Ch]
  const CBitVec<2048> *pEntityTransmitBits; // [esp+B4h] [ebp+10h]

  v61 = this;
  memset(&invalidList, 0, sizeof(invalidList));
  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_pNext);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v61->m_pNext,
                                i) )
  {
    m_pszName = v61->m_pszName;
    v7 = *(_DWORD *)&m_pszName[16 * (unsigned __int16)i + 8];
    v8 = *(_DWORD *)&m_pszName[16 * (unsigned __int16)i + 12];
    if ( v7 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
    {
      *(_BYTE *)v8 = 0;
      *(_DWORD *)(v8 + 48) = 0;
      *(_DWORD *)(v8 + 52) = 0;
      *(_DWORD *)(v8 + 56) = 0;
      *(_DWORD *)(v8 + 60) = 0;
      *(_DWORD *)(v8 + 64) = 0;
      *(_DWORD *)(v8 + 68) = 0;
      *(_DWORD *)(v8 + 72) = 0;
      *(_DWORD *)(v8 + 76) = 0;
      *(_DWORD *)(v8 + 80) = 0;
      *(_DWORD *)(v8 + 84) = 0;
      *(_DWORD *)(v8 + 88) = 0;
      *(_DWORD *)(v8 + 92) = 0;
      *(_DWORD *)(v8 + 96) = 0;
      *(_DWORD *)(v8 + 100) = -1082130432;
      *(_DWORD *)(v8 + 344) = 0;
      *(_DWORD *)(v8 + 348) = 0;
      v13 = (_DWORD *)(v8 + 112);
      for ( j = 15; j != 0; --j )
      {
        *(v13 - 2) = 0;
        *(v13 - 1) = 0;
        *v13 = 0;
        v13[1] = 0;
        v13 += 4;
      }
      *(_DWORD *)(v8 + 352) = 0;
      *(_DWORD *)(v8 + 356) = 0;
      *(_DWORD *)(v8 + 360) = 0;
      *(_DWORD *)(v8 + 364) = 0;
      *(_DWORD *)(v8 + 368) = 0;
      *(_DWORD *)(v8 + 372) = 0;
      *(_DWORD *)(v8 + 376) = 0;
      *(_DWORD *)(v8 + 380) = 0;
      *(_DWORD *)(v8 + 384) = 0;
      *(_DWORD *)(v8 + 388) = 0;
      *(_DWORD *)(v8 + 392) = 0;
      *(_DWORD *)(v8 + 396) = 0;
      *(_DWORD *)(v8 + 400) = 0;
      *(_DWORD *)(v8 + 404) = -1082130432;
      *(_DWORD *)(v8 + 648) = 0;
      *(_DWORD *)(v8 + 652) = 0;
      v15 = (_DWORD *)(v8 + 416);
      for ( k = 15; k != 0; --k )
      {
        *(v15 - 2) = 0;
        *(v15 - 1) = 0;
        *v15 = 0;
        v15[1] = 0;
        v15 += 4;
      }
    }
    else
    {
      m_Size = invalidList.m_Size;
      v10 = invalidList.m_Size;
      if ( invalidList.m_Size + 1 > invalidList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&invalidList,
          num: invalidList.m_Size - invalidList.m_Memory.m_nAllocationCount + 1);
        m_Size = invalidList.m_Size;
      }
      invalidList.m_Size = m_Size + 1;
      v11 = m_Size - v10;
      invalidList.m_pElements = invalidList.m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(
          dest: &invalidList.m_Memory.m_pMemory[v10 + 1],
          src: &invalidList.m_Memory.m_pMemory[v10],
          count: 4 * v11);
      v12 = &invalidList.m_Memory.m_pMemory[v10];
      if ( v12 != nullptr )
        v12->m_Index = v7;
    }
  }
  v17 = v61;
  v18 = 0.0;
  correct = 0.0;
  if ( invalidList.m_Size <= 0 )
    goto LABEL_55;
  do
  {
    search.key.m_Index = invalidList.m_Memory.m_pMemory[LODWORD(v18)].m_Index;
    v19 = CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v17->m_pNext,
            &search);
    slot = v19;
    if ( v19 == 0xFFFF )
      goto LABEL_54;
    v20 = v17->m_pszName;
    cmd = (const CUserCmd *)(16 * (unsigned __int16)v19);
    v21 = *(_DWORD *)((char *)&cmd->viewangles.x + (_DWORD)v20);
    i = v21;
    if ( v21 == 0 )
      goto LABEL_52;
    v22 = (_DWORD *)(v21 + 4);
    v23 = *(_DWORD *)(v21 + 36) == 0;
    it = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::Iterator_t *)(v21 + 36);
    if ( v23 && *(_DWORD *)(v21 + 40) == -1 )
      goto LABEL_48;
    if ( *v22 != 0 )
    {
      v56[0] = *v22;
      v56[1] = 0;
      v24 = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t **)v56;
    }
    else
    {
      v55[0] = 0;
      v55[1] = -1;
      v24 = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t **)v55;
    }
    v25 = *v24;
    v26 = (int)v24[1];
    while ( 1 )
    {
      if ( v25 != nullptr )
      {
        if ( v26 >= 0
          && v26 < v25->m_nBlockSize
          && &v25[39 * v26] != (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)-8
          && !CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::IsIdxAfter(
                this: (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > *)(i + 4),
                i: (unsigned int)&v25[39 * v26 + 1],
                it)
          && (v25[39 * v26 + 39].m_pNext != &v25[39 * v26 + 1]
           || (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)v25[39 * v26 + 39].m_nBlockSize == &v25[39 * v26 + 1]) )
        {
          v27 = i;
          v25[39 * v26 + 39].m_pNext = &v25[39 * v26 + 1];
          v25[39 * v26 + 39].m_nBlockSize = *(_DWORD *)(v27 + 24);
          *(_DWORD *)(v27 + 24) = &v25[39 * v26 + 1];
        }
      }
      else if ( v26 == -1 )
      {
        goto LABEL_47;
      }
      if ( v25 == it->m_pBlockHeader && v26 == it->m_nIndex )
        break;
      if ( v25 != nullptr && v26 >= 0 && (m_nBlockSize = v25->m_nBlockSize, v26 < m_nBlockSize) )
      {
        if ( ++v26 < m_nBlockSize )
          goto LABEL_45;
        v25 = v25->m_pNext;
        if ( v25 != nullptr )
        {
          v17 = v61;
          v53 = v25;
          v54 = 0;
          v26 = 0;
        }
        else
        {
          v51 = 0;
          v52 = -1;
          v25 = nullptr;
          v26 = -1;
LABEL_45:
          v17 = v61;
        }
      }
      else
      {
        v17 = v61;
        v25 = nullptr;
        v26 = -1;
      }
    }
    v17 = v61;
LABEL_47:
    LOWORD(v19) = slot;
    v22 = (_DWORD *)(i + 4);
    *(_DWORD *)(i + 16) = 0;
    v22[4] = 0;
    v22[6] = 0;
    v21 = i;
LABEL_48:
    v29 = (_DWORD *)*v22;
    if ( *v22 != 0 )
    {
      do
      {
        v47 = v29;
        v29 = (_DWORD *)*v29;
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47);
      }
      while ( v29 != nullptr );
      v21 = i;
      *(_DWORD *)(i + 4) = 0;
      *(_DWORD *)(v21 + 8) = 0;
    }
    free(pMem: (void *)v21);
LABEL_52:
    if ( (_WORD)v19 != 0xFFFF )
    {
      CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v17->m_pNext,
        elem: v19);
      v30 = cmd;
      *(_WORD *)((char *)&cmd->__vftable + (unsigned int)v17->m_pszName) = v19;
      *(_WORD *)&v17->m_pszName[(unsigned int)v30 + 2] = v17->m_CompensatedEntities.m_Tree.m_Elements.m_nAllocationCount;
      --HIWORD(v17->m_CompensatedEntities.m_Tree.m_Elements.m_pMemory);
      LOWORD(v17->m_CompensatedEntities.m_Tree.m_Elements.m_nAllocationCount) = v19;
    }
LABEL_54:
    LODWORD(v18) = LODWORD(correct) + 1;
    correct = v18;
  }
  while ( SLODWORD(v18) < invalidList.m_Size );
LABEL_55:
  LOBYTE(v17->m_CompensatedEntities.m_Tree.m_Root) = 0;
  *(_DWORD *)&v17->m_CompensatedEntities.m_Tree.m_FirstFree = player;
  if ( player->m_bLagCompensation
    && gpGlobals->maxClients > 1
    && sv_unlag.m_pParent != nullptr
    && sv_unlag.m_pParent->m_Value.m_nValue != 0
    && !player->IsBot(this: player)
    && (player->m_afPhysicsFlags.m_Value & 8) == 0 )
  {
    m_pCurrentCommand = player->m_pCurrentCommand;
    cmd = m_pCurrentCommand;
    if ( m_pCurrentCommand == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_104A4AD8, a2: v48);
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "StartLagCompensation",
      a3: 0,
      a4: "Networking",
      a5: false,
      a6: 4);
    LOBYTE(v17->m_weaponAngles.y) = 1;
    m_pPev = player->m_Network.m_pPev;
    correct = 0.0;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v33 = engine->GetPlayerNetInfo(this: engine, a2: m_pPev);
    if ( v33 != nullptr )
      correct = v33->GetLatency(this: v33, a2: 0);
    m_fValue = sv_maxunlag.m_pParent->m_Value.m_fValue;
    v35 = player->m_fLerpTime + correct;
    if ( v35 >= 0.0 )
    {
      if ( v35 <= m_fValue )
        m_fValue = player->m_fLerpTime + correct;
    }
    else
    {
      m_fValue = 0.0;
    }
    interval_per_tick = gpGlobals->interval_per_tick;
    v37 = (float)((float)m_pCurrentCommand->tick_count * interval_per_tick) - player->m_fLerpTime;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(m_fValue - (float)(gpGlobals->curtime - v37)) & _mask__AbsFloat_) > 0.2 )
      v37 = gpGlobals->curtime - m_fValue;
    if ( sv_lagpushticks.m_pParent != nullptr )
      m_nValue = sv_lagpushticks.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v17->m_CompensatedEntities.m_Tree.m_pElements = lagCompensationType;
    *(float *)&v17->m_bNeedToRestore = *(float *)weaponPos->m_Ints;
    v17->m_pCurrentPlayer = (CBasePlayer *)weaponPos->m_Ints[1];
    *(float *)&slot = (float)((float)m_nValue * interval_per_tick) + v37;
    v17->m_lagCompensationType = (LagCompensationType)weaponPos->m_Ints[2];
    v17->m_weaponPos = *weaponAngles;
    v17->m_weaponAngles.x = weaponRange;
    v39 = player->m_Network.m_pPev;
    if ( v39 != nullptr )
      v39 -= (int)gpGlobals->pEdicts;
    pEntityTransmitBits = engine->GetEntityTransmitBitsForClient(this: engine, a2: (char *)&v39[-1].m_pUnk + 3);
    Inorder = CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v17->m_pNext);
    LOWORD(lagCompensationTypea) = Inorder;
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        v41 = v17->m_pszName;
        v42 = 2 * Inorder;
        v43 = *(_DWORD *)&v41[8 * v42 + 12];
        v44 = *(_DWORD *)&v41[8 * v42 + 8];
        if ( v44 != -1 )
        {
          v45 = (CBasePlayer **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v44];
          if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_SerialNumber == HIWORD(v44) )
          {
            v46 = *v45;
            if ( *v45 != nullptr
              && player != v46
              && player->WantsLagCompensationOnEntity(this: player, a2: v46, a3: cmd, a4: pEntityTransmitBits) )
            {
              *(_BYTE *)v43 = CLagCompensationManager::BacktrackEntity(
                                this: (CLagCompensationManager *)((char *)v17 - 12),
                                a2: (CBaseEntity *)&savedregs,
                                entity: v46,
                                flTargetTime: *(float *)&slot,
                                track: (CUtlFixedLinkedList<LagRecord> *)(v43 + 4),
                                restore: (LagRecord *)(v43 + 48),
                                change: (LagRecord *)(v43 + 352),
                                wantsAnims: true);
            }
          }
        }
        lagCompensationTypea = (unsigned __int16)CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                                   this: (CUtlRBTree<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short,CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CHandle<CBaseEntity>,CLagCompensationManager::EntityLagData *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v17->m_pNext,
                                                   i: lagCompensationTypea);
        if ( lagCompensationTypea == 0xFFFF )
          break;
        Inorder = lagCompensationTypea;
      }
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    if ( invalidList.m_Memory.m_nGrowSize >= 0 && invalidList.m_Memory.m_pMemory != nullptr )
LABEL_93:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: invalidList.m_Memory.m_pMemory);
  }
  else if ( invalidList.m_Memory.m_nGrowSize >= 0 && invalidList.m_Memory.m_pMemory != nullptr )
  {
    goto LABEL_93;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CF170
// Name: public: virtual void CLagCompensationManager::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CLagCompensationManager::LevelShutdownPostEntity(CLagCompensationManager *this)
{
  CLagCompensationManager::ClearHistory(this);
}
