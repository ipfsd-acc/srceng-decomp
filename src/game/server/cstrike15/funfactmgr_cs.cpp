// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/funfactmgr_cs.cpp
// Functions: 11
// ============================================================

#include "game\server\cstrike15\funfactmgr_cs.h"

//------------------------------------------------------------------------------
// Address: 0x10053D90
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,class CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014FAE0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196150
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CPhysCollide const __near *,struct BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<ThinkSync,unsigned short> *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<ThinkSync,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                       this: _g_pMemAlloc,
                                                                       a2: m_pMemory,
                                                                       a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<ThinkSync,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227990
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct studiohdr_t const __near *,struct StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 88 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024D050
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct ResponseRules::Rule __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029F3F0
// Name: protected: virtual void CCSFunFactMgr::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSFunFactMgr::FireGameEvent(CCSFunFactMgr *this, IGameEvent *event)
{
  const char *v3; // eax
  unsigned int v4; // eax

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: "player_connect", s2: v3) == 0 )
  {
    v4 = event->GetInt(this: event, a2: "index", a3: 0);
    if ( v4 <= 0x3F )
      *((_DWORD *)&this->CGameEventListener::IGameEventListener2::__vftable + v4) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A0420
// Name: public: virtual void CCSFunFactMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSFunFactMgr::Shutdown(CCSFunFactMgr *this)
{
  int i; // esi
  const FunFactEvaluator *pEvaluator; // ecx

  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_funFactDatabase.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_funFactDatabase.m_Tree,
                                i) )
  {
    pEvaluator = this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.pEvaluator;
    if ( pEvaluator != nullptr )
      ((void (__thiscall *)(const FunFactEvaluator *, int))pEvaluator->dtr_FunFactEvaluator)(a1: pEvaluator, a2: 1);
  }
  CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_funFactDatabase.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x102A0490
// Name: public: CCSFunFactMgr::CCSFunFactMgr(void)
// Source: json
//------------------------------------------------------------------------------
CCSFunFactMgr *__thiscall CCSFunFactMgr::CCSFunFactMgr(CCSFunFactMgr *this)
{
  UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CCSFunFactMgr");
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 42;
  this->m_bRegisteredForEvents = false;
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CCSFunFactMgr_vtbl *)&CCSFunFactMgr::`vftable'{for `CAutoGameSystemPerFrame'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSFunFactMgr::`vftable'{for `CGameEventListener'};
  this->m_funFactDatabase.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
  this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_funFactDatabase.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_funFactDatabase.m_Tree.m_Elements.m_nAllocationCount = 100;
  this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2400);
  m_pMemory = this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_funFactDatabase.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_funFactDatabase.m_Tree.m_FirstFree = -1;
  this->m_funFactDatabase.m_Tree.m_pElements = m_pMemory;
  memset(this->m_playerCooldown, 0, sizeof(this->m_playerCooldown));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A0540
// Name: public: virtual CCSFunFactMgr::~CCSFunFactMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSFunFactMgr::~CCSFunFactMgr(CCSFunFactMgr *this)
{
  CGameEventListener *v2; // esi
  bool v3; // zf

  v2 = &this->CGameEventListener;
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CCSFunFactMgr_vtbl *)&CCSFunFactMgr::`vftable'{for `CAutoGameSystemPerFrame'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSFunFactMgr::`vftable'{for `CGameEventListener'};
  CCSFunFactMgr::Shutdown(this);
  CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_funFactDatabase.m_Tree);
  v3 = !v2->m_bRegisteredForEvents;
  v2->__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  v2->m_nDebugID = 13;
  if ( !v3 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v2->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A05A0
// Name: public: bool CCSFunFactMgr::GetRoundEndFunFact(int,int,struct FunFact __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CCSFunFactMgr::GetRoundEndFunFact(
        CCSFunFactMgr *this,
        int iWinningTeam,
        int iRoundResult,
        FunFact *funfact)
{
  char *v4; // edi
  int Inorder; // ebx
  int v7; // edi
  const FunFactEvaluator *pEvaluator; // ecx
  int v9; // eax
  IMemAlloc *v10; // ecx
  float *v12; // edi
  unsigned __int16 v13; // ax
  CCSFunFactMgr::FunFactDatabaseEntry *p_elem; // ebx
  float v15; // xmm1_4
  FunFact *v16; // eax
  float *v17; // eax
  int j; // ecx
  unsigned __int16 k; // ax
  void *v20; // eax
  long double v21; // [esp+0h] [ebp-40h]
  _BYTE v22[24]; // [esp+8h] [ebp-38h] OVERLAPPED BYREF
  CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t search; // [esp+20h] [ebp-20h] BYREF
  int iFunFactIndex; // [esp+30h] [ebp-10h]
  float fBestScore; // [esp+34h] [ebp-Ch]
  int v26; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  v4 = nullptr;
  memset(&v22[4], 0, 20);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_funFactDatabase.m_Tree);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      v7 = (unsigned __int16)Inorder;
      pEvaluator = this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.pEvaluator;
      if ( pEvaluator->Evaluate(
             this: (FunFactEvaluator *)pEvaluator,
             a2: (CUtlVector<FunFact,CUtlMemory<FunFact,int> > *)&v22[4]) )
      {
        ++this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.iOccurrences;
      }
      Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &this->m_funFactDatabase.m_Tree,
                                    i: Inorder);
    }
    while ( Inorder != 0xFFFF );
    v4 = *(char **)&v22[4];
  }
  v9 = *(_DWORD *)&v22[16];
  ++this->m_numRounds;
  if ( v9 == 0 )
  {
    *(_DWORD *)&v22[16] = 0;
    if ( *(int *)&v22[12] < 0 )
    {
LABEL_12:
      *(_DWORD *)&v22[20] = v4;
      if ( *(int *)&v22[12] >= 0 && v4 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      return 0;
    }
    if ( v4 == nullptr )
    {
LABEL_11:
      *(_DWORD *)&v22[8] = 0;
      goto LABEL_12;
    }
    v10 = _g_pMemAlloc;
LABEL_10:
    v10->Free_2(this: v10, a2: v4);
    v4 = nullptr;
    *(_DWORD *)&v22[4] = 0;
    goto LABEL_11;
  }
  fBestScore = -3.4028235e38;
  iFunFactIndex = -1;
  i = 0;
  if ( v9 <= 0 )
  {
LABEL_24:
    *(_DWORD *)&v22[16] = 0;
    if ( *(int *)&v22[12] < 0 )
      goto LABEL_12;
    if ( v4 == nullptr )
      goto LABEL_11;
    v10 = _g_pMemAlloc;
    goto LABEL_10;
  }
  v26 = 0;
  while ( 1 )
  {
    v12 = (float *)&v4[v26];
    search.key = *(int *)v12;
    v13 = CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &this->m_funFactDatabase.m_Tree,
            &search);
    p_elem = &this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem;
    v15 = 1.0
        - (float)((float)this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem.iOccurrences
                / (float)this->m_numRounds);
    __libm_sse2_pow(x: v21, y: *(long double *)v22);
    if ( (float)(v15
               + (float)((float)((float)((float)(v12[6] + 1.0) * (float)(p_elem->pEvaluator->m_fCoolness * 2.0))
                               - p_elem->fCooldown)
                       - (float)(this->m_playerCooldown[*((_DWORD *)v12 + 2)] * 0.80000001))) > fBestScore )
    {
      fBestScore = v15
                 + (float)((float)((float)((float)(v12[6] + 1.0) * (float)(p_elem->pEvaluator->m_fCoolness * 2.0))
                                 - p_elem->fCooldown)
                         - (float)(this->m_playerCooldown[*((_DWORD *)v12 + 2)] * 0.80000001));
      iFunFactIndex = i;
    }
    v26 += 28;
    if ( ++i >= *(int *)&v22[16] )
      break;
    v4 = *(char **)&v22[4];
  }
  if ( iFunFactIndex < 0 )
  {
    v4 = *(char **)&v22[4];
    goto LABEL_24;
  }
  v16 = (FunFact *)(*(_DWORD *)&v22[4] + 28 * iFunFactIndex);
  *funfact = *v16;
  v17 = &this->m_playerCooldown[1];
  for ( j = 8; j != 0; --j )
  {
    *(v17 - 1) = *(v17 - 1) * 0.60000002;
    *v17 = *v17 * 0.60000002;
    v17[1] = v17[1] * 0.60000002;
    v17[2] = v17[2] * 0.60000002;
    v17[3] = v17[3] * 0.60000002;
    v17[4] = v17[4] * 0.60000002;
    v17[5] = v17[5] * 0.60000002;
    v17[6] = v17[6] * 0.60000002;
    v17 += 8;
  }
  for ( k = CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_funFactDatabase.m_Tree);
        k != 0xFFFF;
        k = CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_funFactDatabase.m_Tree,
              i: k) )
  {
    this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[k].m_Data.elem.fCooldown = this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[k].m_Data.elem.fCooldown
                                                                                 * 0.80000001;
  }
  this->m_playerCooldown[funfact->iPlayer] = 1.0;
  search.key = funfact->id;
  this->m_funFactDatabase.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                                        this: &this->m_funFactDatabase.m_Tree,
                                                        &search)].m_Data.elem.fCooldown = 1.0;
  v20 = *(void **)&v22[4];
  *(_DWORD *)&v22[16] = 0;
  if ( *(int *)&v22[12] >= 0 )
  {
    if ( *(_DWORD *)&v22[4] != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&v22[4]);
      v20 = nullptr;
      *(_DWORD *)&v22[4] = 0;
    }
    *(_DWORD *)&v22[8] = 0;
  }
  *(_DWORD *)&v22[20] = v20;
  if ( *(int *)&v22[12] >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A0970
// Name: public: virtual bool CCSFunFactMgr::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CCSFunFactMgr::Init@<al>(CCSFunFactMgr *this@<ecx>, char *p_m_Data@<edi>)
{
  CCSFunFactMgr *v2; // esi
  bool (__thiscall *AddListener)(IGameEventManager2 *, IGameEventListener2 *, const char *, bool); // eax
  CFunFactHelper *m_pNext; // eax
  CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // esi
  const FunFactEvaluator *v6; // eax
  int m_id; // edx
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // edi
  UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short> *v12; // eax
  int v13; // edx
  UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short> *v15; // ecx
  CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t insert; // [esp+Ch] [ebp-2Ch] BYREF
  CCSFunFactMgr::FunFactDatabaseEntry entry; // [esp+1Ch] [ebp-1Ch]
  CCSFunFactMgr *v19; // [esp+28h] [ebp-10h]
  CFunFactHelper *pFunFactHelper; // [esp+2Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+30h] [ebp-8h] BYREF
  bool leftchild; // [esp+37h] [ebp-1h] BYREF

  v2 = this;
  this->m_bRegisteredForEvents = true;
  AddListener = gameeventmanager->AddListener;
  v19 = this;
  AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_connect", a4: true);
  m_pNext = CFunFactHelper::s_pFirst;
  pFunFactHelper = CFunFactHelper::s_pFirst;
  if ( CFunFactHelper::s_pFirst != nullptr )
  {
    entry.fCooldown = 0.0;
    entry.iOccurrences = 0;
    p_m_Tree = &v2->m_funFactDatabase.m_Tree;
    do
    {
      v6 = m_pNext->m_pfnCreate();
      m_id = v6->m_id;
      entry.pEvaluator = v6;
      insert.key = m_id;
      insert.elem = entry;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: p_m_Tree,
        &insert,
        parent,
        &leftchild);
      v8 = CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
             this: p_m_Tree,
             a2: p_m_Data);
      v9 = parent[0];
      v10 = v8;
      v11 = v8;
      v12 = &p_m_Tree->m_Elements.m_pMemory[v11];
      v12->m_Right = -1;
      v12->m_Left = -1;
      v12->m_Parent = v9;
      v12->m_Tag = 0;
      if ( v9 == 0xFFFF )
      {
        p_m_Tree->m_Root = v10;
      }
      else
      {
        v13 = v9;
        m_pMemory = p_m_Tree->m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v13].m_Left = v10;
        else
          m_pMemory[v13].m_Right = v10;
      }
      CUtlRBTree<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short,CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: p_m_Tree,
        elem: v10);
      v15 = p_m_Tree->m_Elements.m_pMemory;
      ++p_m_Tree->m_NumElements;
      p_m_Data = (char *)&v15[v11].m_Data;
      if ( p_m_Data != nullptr )
        *(CUtlMap<int,CCSFunFactMgr::FunFactDatabaseEntry,unsigned short>::Node_t *)p_m_Data = insert;
      m_pNext = pFunFactHelper->m_pNext;
      pFunFactHelper = m_pNext;
    }
    while ( m_pNext != nullptr );
    v2 = v19;
  }
  memset(v2->m_playerCooldown, 0, sizeof(v2->m_playerCooldown));
  v2->m_numRounds = 0;
  return 1;
}
