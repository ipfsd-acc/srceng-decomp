// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior_follow.cpp
// Functions: 29
// ============================================================

#include "game\server\ai_behavior_follow.h"

//------------------------------------------------------------------------------
// Address: 0x10044A70
// Name: public: virtual struct datamap_t __near * CAI_FollowGoal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_FollowGoal::GetDataDescMap(CAI_FollowGoal *this)
{
  return &CAI_FollowGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10044B90
// Name: public: float CAI_Component::GetHullWidth(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_Component::GetHullWidth(CAI_Component *this)
{
  return NAI_Hull::Width(id: this->m_pOuter->m_eHull);
}

//------------------------------------------------------------------------------
// Address: 0x10044BB0
// Name: private: void CVarBitVecBase<unsigned short>::ReallocInts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::ReallocInts(CVarBitVecBase<unsigned short> *this, int numInts)
{
  CVarBitVecBase<unsigned short> *m_pInt; // eax
  unsigned int *p_m_iBitStringStorage; // edi
  unsigned int *v5; // eax
  unsigned int v6; // ecx

  if ( numInts != 0 )
  {
    m_pInt = (CVarBitVecBase<unsigned short> *)this->m_pInt;
    p_m_iBitStringStorage = &this->m_iBitStringStorage;
    if ( m_pInt == (CVarBitVecBase<unsigned short> *)&this->m_iBitStringStorage )
    {
      if ( numInts != 1 )
      {
        v5 = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * numInts);
        v6 = *p_m_iBitStringStorage;
        this->m_pInt = v5;
        *v5 = v6;
      }
    }
    else if ( numInts == 1 )
    {
      *p_m_iBitStringStorage = *(_DWORD *)&m_pInt->m_numBits;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pInt);
      this->m_pInt = p_m_iBitStringStorage;
    }
    else
    {
      this->m_pInt = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pInt, a3: 4 * numInts);
    }
  }
  else
  {
    if ( this->m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pInt);
    this->m_pInt = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044D50
// Name: public: void CAI_GoalEntity::SetGoalEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::SetGoalEntity(CAI_GoalEntity *this, CBaseEntity *pGoalEntity)
{
  this->m_iszGoal.pszValue = pGoalEntity->m_iName.m_Value.pszValue;
  this->m_hGoalEntity.m_Index = pGoalEntity->GetRefEHandle(this: pGoalEntity)->m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10044D80
// Name: protected: void CAI_FollowBehavior::NoteSuccessfulFollow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowBehavior::NoteSuccessfulFollow(CAI_FollowBehavior *this)
{
  CAI_BaseNPC *m_pOuter; // ecx

  this->m_nFailedFollowAttempts = 0;
  this->m_flTimeFailFollowStarted = 3.4028235e38;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr && ai_debug_follow.m_pParent != nullptr && ai_debug_follow.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(pAI: m_pOuter, pszFormat: "Follow: NoteSuccessfulFollow()\n");
}

//------------------------------------------------------------------------------
// Address: 0x10044DC0
// Name: private: int CAI_FollowManager::FindBestSlot(struct AI_FollowGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_FollowManager::FindBestSlot(CAI_FollowManager *this, AI_FollowGroup_t *pGroup)
{
  int nSlots; // edi
  int result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  AI_FollowSlot_t *pSlots; // eax
  AI_FollowFormation_t *pFormation; // [esp+8h] [ebp-Ch]
  int best; // [esp+10h] [ebp-4h]
  int bestPriority; // [esp+1Ch] [ebp+8h]

  nSlots = pGroup->pFormation->nSlots;
  pFormation = pGroup->pFormation;
  result = -1;
  v5 = 0;
  best = -1;
  bestPriority = -1;
  v6 = 1;
  if ( nSlots > 0 )
  {
    v7 = 0;
    do
    {
      if ( (v6 & pGroup->slotUsage.m_pInt[v5 >> 5]) == 0 )
      {
        pSlots = pFormation->pSlots;
        if ( pSlots[v7].priority > bestPriority )
        {
          bestPriority = pSlots[v7].priority;
          best = v5;
        }
      }
      ++v5;
      ++v7;
      v6 = __ROL4__(v6, 1);
    }
    while ( v5 < nSlots );
    return best;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044E30
// Name: private: struct AI_FollowGroup_t __near * CAI_FollowManager::FindGroup(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
AI_FollowGroup_t *__thiscall CAI_FollowManager::FindGroup(CAI_FollowManager *this, CBaseEntity *pTarget)
{
  int m_Size; // edi
  int v3; // esi
  AI_FollowGroup_t **i; // edx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  AI_FollowGroup_t **m_pMemory; // [esp+Ch] [ebp-4h]

  m_Size = this->m_groups.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_groups.m_Memory.m_pMemory;
  for ( i = this->m_groups.m_Memory.m_pMemory; ; ++i )
  {
    m_Index = (*i)->hFollowTarget.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pTarget )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  return m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10044EA0
// Name: public: void CVarBitVecBase<unsigned short>::Resize(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::Resize(
        CVarBitVecBase<unsigned short> *this,
        int resizeNumBits,
        bool bClearAll)
{
  int m_numInts; // ecx
  int v5; // edi
  unsigned int *v6; // eax
  unsigned int *p_m_iBitStringStorage; // eax
  unsigned __int8 *m_pInt; // eax
  unsigned int *v9; // eax

  m_numInts = this->m_numInts;
  v5 = (resizeNumBits + 31) / 32;
  if ( v5 != m_numInts )
  {
    if ( this->m_pInt != nullptr )
    {
      CVarBitVecBase<unsigned short>::ReallocInts(this, numInts: (resizeNumBits + 31) / 32);
      if ( !bClearAll && resizeNumBits >= this->m_numBits )
      {
        v6 = &this->m_pInt[this->m_numInts - 1];
        *v6 &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
        memset(dst: (unsigned __int8 *)&this->m_pInt[this->m_numInts], value: 0, count: 4 * (v5 - this->m_numInts));
      }
    }
    else
    {
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
          p_m_iBitStringStorage = &this->m_iBitStringStorage;
        else
          p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v5);
        this->m_pInt = p_m_iBitStringStorage;
      }
      bClearAll = true;
    }
    this->m_numInts = v5;
    if ( !bClearAll )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( bClearAll )
  {
LABEL_13:
    m_pInt = (unsigned __int8 *)this->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: m_pInt, value: 0, count: 4 * v5);
LABEL_15:
    this->m_numBits = resizeNumBits;
    return;
  }
  if ( resizeNumBits < this->m_numBits )
    goto LABEL_15;
  v9 = this->m_pInt;
  if ( v9 == nullptr )
    goto LABEL_15;
  v9[m_numInts - 1] &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
  this->m_numBits = resizeNumBits;
}

//------------------------------------------------------------------------------
// Address: 0x10045510
// Name: public: CVarBitVec::~CVarBitVec(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVec::~CVarBitVec(CVarBitVec *this)
{
  if ( this->m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pInt);
  this->m_pInt = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10045F70
// Name: public: AI_FollowGroup_t::~AI_FollowGroup_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AI_FollowGroup_t::~AI_FollowGroup_t(AI_FollowGroup_t *this)
{
  CUtlFixedLinkedList<AI_Follower_t> *p_followers; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *v4; // [esp-4h] [ebp-Ch]

  if ( this->slotUsage.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->slotUsage.m_pInt);
  p_followers = &this->followers;
  this->slotUsage.m_pInt = nullptr;
  CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::RemoveAll(this: &this->followers);
  m_pBlocks = p_followers->m_Memory.m_pBlocks;
  if ( p_followers->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v4 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    while ( m_pBlocks != nullptr );
    p_followers->m_Memory.m_pBlocks = nullptr;
    p_followers->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100466D0
// Name: public: AI_FollowGroup_t::AI_FollowGroup_t(void)
// Source: json
//------------------------------------------------------------------------------
AI_FollowGroup_t *__thiscall AI_FollowGroup_t::AI_FollowGroup_t(AI_FollowGroup_t *this)
{
  this->hFollowTarget.m_Index = -1;
  this->followers.m_Memory.m_pBlocks = nullptr;
  this->followers.m_Memory.m_nAllocationCount = 0;
  this->followers.m_Memory.m_nGrowSize = 0;
  this->followers.m_LastAlloc.m_nIndex = -1;
  this->followers.m_LastAlloc.m_pBlockHeader = nullptr;
  this->followers.m_Head = 0;
  this->followers.m_Tail = 0;
  this->followers.m_FirstFree = 0;
  this->followers.m_ElementCount = 0;
  this->followers.m_NumAlloced = 0;
  this->followers.m_pElements = nullptr;
  *(_QWORD *)&this->slotUsage.m_numBits = 0;
  this->slotUsage.m_pInt = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100467F0
// Name: private: bool CAI_FollowManager::RedistributeSlots(struct AI_FollowGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_FollowManager::RedistributeSlots(CAI_FollowManager *this, AI_FollowGroup_t *pGroup)
{
  AI_FollowGroup_t *v2; // edi
  unsigned int m_Index; // eax
  CBaseEntity *v4; // ebx
  int v6; // eax
  int v7; // esi
  float z; // xmm0_4
  unsigned int *m_Head; // ebx
  int v10; // edi
  unsigned int v11; // eax
  CBaseEntity *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  CBaseEntity *v15; // ebx
  float y; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  int v19; // ecx
  unsigned int *v20; // eax
  int v21; // ebx
  unsigned int *v22; // eax
  const char *v23; // edi
  CEntInfo *v24; // eax
  CBaseEntity *v25; // eax
  unsigned __int16 v26; // ax
  unsigned __int16 v27; // dx
  unsigned int v28; // ecx
  UtlRBTreeNode_t<CBaseEntity *,unsigned short> *m_pMemory; // eax
  unsigned int v30; // esi
  int v31; // edx
  CBaseEntity **p_m_Data; // esi
  CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl*)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short> > movedFollowers; // [esp+14h] [ebp-44h] BYREF
  Vector slotPos; // [esp+30h] [ebp-28h]
  CAI_FollowManager *v36; // [esp+3Ch] [ebp-1Ch]
  CBaseEntity *search; // [esp+40h] [ebp-18h] BYREF
  CBaseEntity *insert; // [esp+44h] [ebp-14h] BYREF
  int bestSlot; // [esp+48h] [ebp-10h] BYREF
  int h; // [esp+4Ch] [ebp-Ch]
  IHandleEntity *m_pEntity; // [esp+50h] [ebp-8h]
  bool v42; // [esp+57h] [ebp-1h] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  v2 = pGroup;
  m_Index = pGroup->hFollowTarget.m_Index;
  v4 = nullptr;
  v36 = this;
  v42 = false;
  memset(&movedFollowers.m_Elements, 0, sizeof(movedFollowers.m_Elements));
  *(_DWORD *)&movedFollowers.m_Root = 0xFFFF;
  *(_DWORD *)&movedFollowers.m_FirstFree = -1;
  movedFollowers.m_pElements = nullptr;
  movedFollowers.m_LessFunc = (bool (__cdecl *)(CBaseEntity *const *, CBaseEntity *const *))CDefOps<CChoreoActor *>::LessFunc;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v4 = (CBaseEntity *)m_pEntity;
  }
  if ( (v4->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
  v6 = CAI_FollowManager::FindBestSlot(this, pGroup);
  bestSlot = v6;
  if ( v6 != -1 )
  {
    while ( movedFollowers.m_NumElements < v2->followers.m_ElementCount )
    {
      v7 = (int)&v2->pFormation->pSlots[v6];
      slotPos.x = *(float *)(v7 + 4) + v4->m_vecAbsOrigin.x;
      slotPos.y = v4->m_vecAbsOrigin.y + *(float *)(v7 + 8);
      z = v4->m_vecAbsOrigin.z;
      m_Head = (unsigned int *)v2->followers.m_Head;
      v10 = 0;
      slotPos.z = z + *(float *)(v7 + 12);
      h = (int)m_Head;
      if ( m_Head == nullptr )
        break;
      while ( 1 )
      {
        v11 = *m_Head;
        if ( *m_Head == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          v12 = nullptr;
        else
          v12 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
        search = v12;
        if ( CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::Find(
               this: &movedFollowers,
               &search) == 0xFFFF )
        {
          v13 = m_Head[1];
          if ( v13 == -1 || *(_DWORD *)v7 > pGroup->pFormation->pSlots[v13].priority )
          {
            v14 = *m_Head;
            if ( *m_Head == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
              v15 = nullptr;
            else
              v15 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
            if ( (v15->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v15, a2: (int)&savedregs);
            y = v15->m_vecAbsOrigin.y;
            v17 = v15->m_vecAbsOrigin.x - slotPos.x;
            v18 = v15->m_vecAbsOrigin.z;
            m_Head = (unsigned int *)h;
            if ( (float)((float)((float)((float)(y - slotPos.y) * (float)(y - slotPos.y)) + (float)(v17 * v17))
                       + (float)((float)(v18 - slotPos.z) * (float)(v18 - slotPos.z))) < 3.4028235e38 )
              v10 = h;
          }
        }
        h = m_Head[18];
        if ( h == 0 )
          break;
        m_Head = (unsigned int *)h;
      }
      if ( v10 == 0 )
        break;
      v19 = *(_DWORD *)(v10 + 4);
      if ( v19 != -1 )
      {
        v20 = &pGroup->slotUsage.m_pInt[v19 >> 5];
        *v20 &= ~(1 << (v19 & 0x1F));
      }
      v21 = bestSlot;
      *(_DWORD *)(v10 + 4) = bestSlot;
      *(float *)(v10 + 12) = *(float *)(v7 + 4);
      *(float *)(v10 + 16) = *(float *)(v7 + 8);
      *(float *)(v10 + 20) = *(float *)(v7 + 12);
      *(float *)(v10 + 24) = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                               a1: random,
                               a2: *(_DWORD *)(v7 + 20),
                               a3: *(_DWORD *)(v7 + 24));
      *(float *)(v10 + 28) = *(float *)(v7 + 28);
      *(float *)(v10 + 32) = *(float *)(v7 + 32);
      v22 = &pGroup->slotUsage.m_pInt[v21 >> 5];
      *v22 |= 1 << (v21 & 0x1F);
      v23 = *(const char **)v10;
      if ( v23 == (const char *)-1
        || (v24 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v23],
            v23 = (const char *)((unsigned int)v23 >> 16),
            (const char *)v24->m_SerialNumber != v23) )
      {
        v25 = nullptr;
      }
      else
      {
        v25 = (CBaseEntity *)v24->m_pEntity;
      }
      insert = v25;
      bestSlot = 0xFFFF;
      v42 = false;
      CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &movedFollowers,
        &insert,
        parent: (unsigned __int16 *)&bestSlot,
        leftchild: &v42);
      v26 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
              this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&movedFollowers,
              a2: v23);
      v27 = bestSlot;
      v28 = v26;
      m_pMemory = movedFollowers.m_Elements.m_pMemory;
      v30 = v28;
      movedFollowers.m_Elements.m_pMemory[v30].m_Right = -1;
      m_pMemory[v30].m_Left = -1;
      m_pMemory[v30].m_Tag = 0;
      m_pMemory[v30].m_Parent = v27;
      if ( v27 == 0xFFFF )
      {
        movedFollowers.m_Root = v28;
      }
      else
      {
        v31 = v27;
        if ( v42 )
          m_pMemory[v31].m_Left = v28;
        else
          m_pMemory[v31].m_Right = v28;
      }
      CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &movedFollowers,
        elem: v28);
      ++movedFollowers.m_NumElements;
      p_m_Data = &movedFollowers.m_Elements.m_pMemory[v30].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      v42 = true;
      bestSlot = CAI_FollowManager::FindBestSlot(this: v36, pGroup);
      if ( bestSlot == -1 )
        break;
      v6 = bestSlot;
      v4 = (CBaseEntity *)m_pEntity;
      v2 = pGroup;
    }
  }
  CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::~CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>(this: &movedFollowers);
  return v42;
}

//------------------------------------------------------------------------------
// Address: 0x10046B80
// Name: public: void CAI_FollowManager::ChangeFormation(struct AI_FollowManagerInfoHandle_t __near &,enum AI_Formations_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowManager::ChangeFormation(
        CAI_FollowManager *this,
        AI_FollowFormation_t *hInfo,
        AI_Formations_t formation)
{
  AI_FollowGroup_t *pszName; // ebx
  AI_Formations_t v4; // eax
  AI_FollowFormation_t *v5; // ecx
  unsigned int *m_Head; // edi
  unsigned int v7; // eax
  CAI_BaseNPC *m_pEntity; // ecx
  CAI_FollowBehavior *v9; // esi
  CAI_ClassScheduleIdSpace *(__thiscall *GetClassScheduleIdSpace)(struct CAI_FollowBehavior *); // eax
  int v11; // eax
  int v12; // eax
  unsigned __int8 *m_pInt; // eax
  CAI_FollowBehavior *pFollowBehavior; // [esp+8h] [ebp-4h] BYREF
  AI_FollowFormation_t *pNewFormation; // [esp+14h] [ebp+8h]

  pszName = (AI_FollowGroup_t *)hInfo->pszName;
  if ( hInfo->pszName != nullptr && hInfo->flags != 0 )
  {
    v4 = formation;
    if ( formation >= AIF_SIMPLE )
    {
      if ( (unsigned int)formation >= (AIF_VORTIGAUNT|AIF_ANTLION) )
        v4 = AIF_TOPDOWN_TIGHT;
    }
    else
    {
      v4 = AIF_SIMPLE;
    }
    v5 = g_AI_Formations[v4];
    pNewFormation = v5;
    if ( v5 != pszName->pFormation )
    {
      m_Head = (unsigned int *)pszName->followers.m_Head;
      if ( m_Head != nullptr )
      {
        do
        {
          v7 = *m_Head;
          m_Head[1] = -1;
          if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
            m_pEntity = nullptr;
          else
            m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
          CAI_BaseNPC::GetBehavior<CAI_FollowBehavior>(this: m_pEntity, ppBehavior: &pFollowBehavior);
          v9 = pFollowBehavior;
          if ( pFollowBehavior != nullptr )
          {
            pFollowBehavior->m_params.formation = formation;
            GetClassScheduleIdSpace = v9->GetClassScheduleIdSpace;
            v9->m_TargetMonitor.m_flMarkTolerance = -1.0;
            v11 = (int)GetClassScheduleIdSpace(this: v9);
            v12 = CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v11 + 52), localID: 100000);
            CAI_BaseNPC::SetCondition(this: v9->m_pOuter, iCondition: v12);
            v9->m_bTargetUnreachable = false;
          }
          m_Head = (unsigned int *)m_Head[18];
        }
        while ( m_Head != nullptr );
        v5 = pNewFormation;
      }
      m_pInt = (unsigned __int8 *)pszName->slotUsage.m_pInt;
      if ( m_pInt != nullptr )
      {
        memset(dst: m_pInt, value: 0, count: 4 * pszName->slotUsage.m_numInts);
        v5 = pNewFormation;
      }
      pszName->pFormation = v5;
      CVarBitVecBase<unsigned short>::Resize(this: &pszName->slotUsage, resizeNumBits: v5->nSlots, bClearAll: false);
      CAI_FollowManager::RedistributeSlots(this, pGroup: pszName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046CC0
// Name: private: struct AI_FollowGroup_t __near * CAI_FollowManager::FindCreateGroup(class CBaseEntity __near *,enum AI_Formations_t)
// Source: json
//------------------------------------------------------------------------------
AI_FollowGroup_t *__thiscall CAI_FollowManager::FindCreateGroup(
        CAI_FollowManager *this,
        CBaseEntity *pTarget,
        AI_Formations_t formation)
{
  AI_FollowGroup_t *result; // eax
  AI_FollowGroup_t *v5; // eax
  AI_FollowGroup_t *v6; // edi
  AI_Formations_t v7; // eax
  AI_FollowFormation_t *v8; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AI_FollowGroup_t **m_pMemory; // eax
  int v12; // ecx
  AI_FollowGroup_t **v13; // esi

  result = CAI_FollowManager::FindGroup(this, pTarget);
  if ( result == nullptr )
  {
    v5 = (AI_FollowGroup_t *)operator new(nSize: 0x40u);
    if ( v5 != nullptr )
      v6 = AI_FollowGroup_t::AI_FollowGroup_t(this: v5);
    else
      v6 = nullptr;
    v7 = formation;
    if ( formation >= AIF_SIMPLE )
    {
      if ( (unsigned int)formation >= (AIF_VORTIGAUNT|AIF_ANTLION) )
        v7 = AIF_TOPDOWN_TIGHT;
    }
    else
    {
      v7 = AIF_SIMPLE;
    }
    v8 = g_AI_Formations[v7];
    v6->pFormation = v8;
    CVarBitVecBase<unsigned short>::Resize(this: &v6->slotUsage, resizeNumBits: v8->nSlots, bClearAll: false);
    if ( pTarget != nullptr )
      v6->hFollowTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
    else
      v6->hFollowTarget.m_Index = -1;
    m_Size = this->m_groups.m_Size;
    m_nAllocationCount = this->m_groups.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
    ++this->m_groups.m_Size;
    m_pMemory = this->m_groups.m_Memory.m_pMemory;
    v12 = this->m_groups.m_Size - 1;
    this->m_groups.m_pElements = this->m_groups.m_Memory.m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v12);
    v13 = this->m_groups.m_Memory.m_pMemory;
    result = v6;
    if ( v13 != nullptr )
      *v13 = v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046D90
// Name: private: void CAI_FollowManager::RemoveGroup(struct AI_FollowGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowManager::RemoveGroup(CAI_FollowManager *this, AI_FollowGroup_t *pGroup)
{
  int v3; // esi
  AI_FollowGroup_t **m_pMemory; // ecx
  AI_FollowGroup_t **i; // eax
  AI_FollowGroup_t *v6; // ebx
  int m_Size; // ecx

  v3 = 0;
  if ( this->m_groups.m_Size > 0 )
  {
    m_pMemory = this->m_groups.m_Memory.m_pMemory;
    for ( i = this->m_groups.m_Memory.m_pMemory; *i != pGroup; ++i )
    {
      if ( ++v3 >= this->m_groups.m_Size )
        return;
    }
    v6 = m_pMemory[v3];
    if ( v6 != nullptr )
    {
      AI_FollowGroup_t::~AI_FollowGroup_t(this: m_pMemory[v3]);
      free(pMem: v6);
    }
    m_Size = this->m_groups.m_Size;
    if ( m_Size > 0 )
    {
      if ( v3 != m_Size - 1 )
        this->m_groups.m_Memory.m_pMemory[v3] = this->m_groups.m_Memory.m_pMemory[m_Size - 1];
      --this->m_groups.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046E00
// Name: public: CAI_FollowManager::~CAI_FollowManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowManager::~CAI_FollowManager(CAI_FollowManager *this)
{
  int v2; // eax
  AI_FollowGroup_t *v3; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pBlocks; // esi
  AI_FollowGroup_t **m_pMemory; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *v6; // [esp-8h] [ebp-14h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_groups.m_Size; i = v2 )
  {
    v3 = this->m_groups.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      if ( v3->slotUsage.m_numInts > 1u )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->slotUsage.m_pInt);
      v3->slotUsage.m_pInt = nullptr;
      CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::RemoveAll(this: &v3->followers);
      m_pBlocks = v3->followers.m_Memory.m_pBlocks;
      if ( m_pBlocks != nullptr )
      {
        do
        {
          v6 = m_pBlocks;
          m_pBlocks = m_pBlocks->m_pNext;
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
        }
        while ( m_pBlocks != nullptr );
        v3->followers.m_Memory.m_pBlocks = nullptr;
        v3->followers.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_groups.m_Size = 0;
  if ( this->m_groups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_groups.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_groups.m_Memory.m_pMemory);
      this->m_groups.m_Memory.m_pMemory = nullptr;
    }
    this->m_groups.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_groups.m_Memory.m_pMemory;
  this->m_groups.m_pElements = this->m_groups.m_Memory.m_pMemory;
  if ( this->m_groups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_groups.m_Memory.m_pMemory = nullptr;
    }
    this->m_groups.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046ED0
// Name: public: bool CAI_FollowManager::AddFollower(class CBaseEntity __near *,class CAI_BaseNPC __near *,enum AI_Formations_t,struct AI_FollowManagerInfoHandle_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_FollowManager::AddFollower(
        CAI_FollowManager *this,
        CBaseEntity *pTarget,
        CAI_BaseNPC *pFollower,
        AI_Formations_t formation,
        AI_FollowManagerInfoHandle_t *pHandle)
{
  AI_FollowGroup_t *Group; // ebx
  int BestSlot; // eax
  int v8; // edi
  int v9; // eax
  int v10; // esi
  unsigned int *v11; // eax
  int slot; // [esp+24h] [ebp+10h]

  Group = CAI_FollowManager::FindCreateGroup(this, pTarget, formation);
  BestSlot = CAI_FollowManager::FindBestSlot(this, pGroup: Group);
  slot = BestSlot;
  if ( BestSlot == -1 )
  {
    pHandle->m_hFollower = 0;
    pHandle->m_pGroup = nullptr;
    return 0;
  }
  else
  {
    v8 = (int)&Group->pFormation->pSlots[BestSlot];
    v9 = CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::AllocInternal(
           this: &Group->followers,
           multilist: false);
    v10 = v9;
    if ( v9 != 0 )
    {
      CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::LinkBefore(
        this: &Group->followers,
        before: 0,
        elem: v9);
      *(_DWORD *)v10 = -1;
      *(_DWORD *)(v10 + 4) = -1;
      memset(dst: (unsigned __int8 *)(v10 + 8), value: 0, count: 0x38u);
      *(_DWORD *)(v10 + 64) = 0;
    }
    if ( pFollower != nullptr )
      *(_DWORD *)v10 = pFollower->GetRefEHandle(this: pFollower)->m_Index;
    else
      *(_DWORD *)v10 = -1;
    *(_DWORD *)(v10 + 4) = slot;
    *(_DWORD *)(v10 + 64) = Group;
    v11 = &Group->slotUsage.m_pInt[slot >> 5];
    *v11 |= 1 << (slot & 0x1F);
    *(float *)(v10 + 12) = *(float *)(v8 + 4);
    *(float *)(v10 + 16) = *(float *)(v8 + 8);
    *(float *)(v10 + 20) = *(float *)(v8 + 12);
    *(float *)(v10 + 24) = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                             a1: random,
                             a2: *(_DWORD *)(v8 + 20),
                             a3: *(_DWORD *)(v8 + 24));
    *(float *)(v10 + 28) = *(float *)(v8 + 28);
    *(float *)(v10 + 32) = *(float *)(v8 + 32);
    pHandle->m_hFollower = v10;
    pHandle->m_pGroup = Group;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046FF0
// Name: public: void CAI_FollowManager::RemoveFollower(struct AI_FollowManagerInfoHandle_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowManager::RemoveFollower(CAI_FollowManager *this, AI_FollowManagerInfoHandle_t *hInfo)
{
  AI_FollowGroup_t *m_pGroup; // esi
  int v4; // ecx
  unsigned int *v5; // edx

  m_pGroup = hInfo->m_pGroup;
  if ( hInfo->m_pGroup != nullptr && hInfo->m_hFollower != 0 )
  {
    v4 = *(_DWORD *)(hInfo->m_hFollower + 4);
    v5 = &m_pGroup->slotUsage.m_pInt[v4 >> 5];
    *v5 &= ~(1 << (v4 & 0x1F));
    CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::Free(
      this: &m_pGroup->followers,
      elem: hInfo->m_hFollower);
    if ( m_pGroup->followers.m_ElementCount != 0 )
    {
      if ( CHandle<CBaseEntity>::operator!=(this: &m_pGroup->hFollowTarget, val: nullptr) )
        CAI_FollowManager::RedistributeSlots(this, pGroup: m_pGroup);
    }
    else
    {
      CAI_FollowManager::RemoveGroup(this, pGroup: m_pGroup);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047070
// Name: public: void CAI_FollowBehavior::SetFollowTarget(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowBehavior::SetFollowTarget(
        CAI_FollowBehavior *this,
        CBaseEntity *pLeader,
        BOOL fFinishCurSchedule)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  CBaseEntity *v6; // edi
  unsigned int v7; // eax
  CAI_BaseNPC *m_pOuter; // eax
  CAI_BaseNPC *v9; // eax

  m_Index = this->m_hFollowTarget.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v6 = pLeader;
  if ( pLeader != m_pEntity && this->m_pOuter->IsAlive(this: this->m_pOuter) )
  {
    this->m_flTimeUpdatedFollowPosition = 0.0;
    v7 = this->m_hFollowTarget.m_Index;
    if ( v7 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
    {
      CAI_FollowManager::RemoveFollower(this: &g_AIFollowManager, hInfo: &this->m_hFollowManagerInfo);
      this->m_hFollowTarget.m_Index = -1;
      m_pOuter = this->m_pOuter;
      this->m_hFollowManagerInfo.m_pGroup = nullptr;
      if ( m_pOuter->m_pPrimaryBehavior == this )
      {
        if ( CAI_Navigator::GetGoalType(this: m_pOuter->m_pNavigator) == GOALTYPE_TARGETENT )
          CAI_Navigator::StopMoving(this: this->m_pOuter->m_pNavigator, bImmediate: true);
        if ( this->m_pOuter->GetEnemy_2(this: this->m_pOuter) != nullptr )
        {
          v9 = this->m_pOuter;
          if ( v9->m_IdealNPCState != NPC_STATE_COMBAT )
            v9->m_IdealNPCState = NPC_STATE_COMBAT;
        }
      }
      v6 = pLeader;
    }
    if ( v6 != nullptr
      && CAI_FollowManager::AddFollower(
           this: &g_AIFollowManager,
           pTarget: v6,
           pFollower: this->m_pOuter,
           formation: this->m_params.formation,
           pHandle: &this->m_hFollowManagerInfo) != 0 )
    {
      CHandle<CBaseEntity>::operator=(this: &this->m_hFollowTarget, val: v6);
      this->m_bFirstFacing = true;
      this->m_flTimeFollowTargetVisible = 0.0;
      CAI_Behavior<CAI_BaseNPC,100000>::SetCondition(this, condition: 100000);
      this->m_TargetMonitor.m_flMarkTolerance = -1.0;
      CAI_FollowBehavior::NoteSuccessfulFollow(this);
    }
    CAI_BehaviorBase::NotifyChangeBehaviorStatus(this, fCanFinishSchedule: fFinishCurSchedule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100471E0
// Name: public: bool CAI_FollowBehavior::SetFollowGoal(class CAI_FollowGoal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_FollowBehavior::SetFollowGoal(
        CAI_FollowBehavior *this,
        CAI_FollowGoal *pGoal,
        bool fFinishCurSchedule)
{
  CBaseEntity *GoalEntity; // eax
  bool v5; // zf
  AI_Formations_t m_iFormation; // eax
  int v8; // [esp+Ch] [ebp-4h]

  if ( !this->m_pOuter->ShouldAcceptGoal(this: this->m_pOuter, a2: this, a3: pGoal) )
    return 0;
  this->m_pOuter->ClearCommandGoal(this: this->m_pOuter);
  if ( hl2_episodic.m_pParent != nullptr && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
    CAI_BaseNPC::SetCondition(this: this->m_pOuter, iCondition: 25);
  GoalEntity = CAI_GoalEntity::GetGoalEntity(this: pGoal);
  CAI_FollowBehavior::SetFollowTarget(this, pLeader: GoalEntity, fFinishCurSchedule: false);
  v5 = this->m_hFollowManagerInfo.m_pGroup == nullptr;
  m_iFormation = pGoal->m_iFormation;
  LOBYTE(v8) = 0;
  *(_DWORD *)&this->m_params.bNormalMemoryDiscard = v8;
  this->m_params.formation = m_iFormation;
  if ( !v5 )
  {
    CAI_FollowManager::ChangeFormation(
      this: &g_AIFollowManager,
      hInfo: (AI_FollowFormation_t *)&this->m_hFollowManagerInfo,
      formation: m_iFormation);
    this->m_flTimeUpdatedFollowPosition = 0.0;
  }
  this->m_hFollowGoalEnt.m_Index = pGoal->GetRefEHandle(this: pGoal)->m_Index;
  this->m_flTimeUpdatedFollowPosition = 0.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100472B0
// Name: public: void CAI_FollowBehavior::ClearFollowGoal(class CAI_FollowGoal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowBehavior::ClearFollowGoal(CAI_FollowBehavior *this, CAI_FollowGoal *pGoal)
{
  unsigned int m_Index; // eax
  CAI_FollowGoal *m_pEntity; // ecx

  this->m_pOuter->OnClearGoal(this: this->m_pOuter, a2: this, a3: pGoal);
  m_Index = this->m_hFollowGoalEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CAI_FollowGoal *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( pGoal == m_pEntity )
  {
    CAI_FollowBehavior::SetFollowTarget(this, pLeader: nullptr, fFinishCurSchedule: false);
    this->m_hFollowGoalEnt.m_Index = -1;
    this->m_flTimeUpdatedFollowPosition = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047320
// Name: public: virtual void CAI_FollowGoal::EnableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowGoal::EnableGoal(CAI_FollowGoal *this, CAI_FollowBehavior *pAI)
{
  CAI_FollowBehavior *v2; // esi
  CAI_FollowBehavior_vtbl *v4; // ebx
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v6; // esi

  v2 = pAI;
  if ( CAI_BaseNPC::GetBehavior<CAI_FollowBehavior>(this: (CAI_BaseNPC *)pAI, ppBehavior: &pAI) != 0 )
  {
    if ( CAI_GoalEntity::GetGoalEntity(this) != nullptr
      || gpGlobals->maxClients == 1
      && (v4 = v2->CAI_Behavior<CAI_BaseNPC,100000>::CAI_ComponentWithOuter<CAI_BaseNPC,CAI_BehaviorBase>::CAI_BehaviorBase::CAI_Component::__vftable,
          LocalPlayer = UTIL_GetLocalPlayer(),
          v4[3].NPC_TranslateActivity(this: v2, a2: (Activity)LocalPlayer) == ACT_COVER)
      && (v6 = UTIL_GetLocalPlayer(), CAI_GoalEntity::SetGoalEntity(this, pGoalEntity: v6), v6 != nullptr) )
    {
      CAI_FollowBehavior::SetFollowGoal(this: pAI, pGoal: this, fFinishCurSchedule: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047390
// Name: public: virtual void CAI_FollowGoal::DisableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FollowGoal::DisableGoal(CAI_FollowGoal *this, CAI_FollowBehavior *pAI)
{
  if ( pAI != nullptr && CAI_BaseNPC::GetBehavior<CAI_FollowBehavior>(this: (CAI_BaseNPC *)pAI, ppBehavior: &pAI) != 0 )
    CAI_FollowBehavior::ClearFollowGoal(this: pAI, pGoal: this);
}

//------------------------------------------------------------------------------
// Address: 0x103FB780
// Name: AI_FollowNavInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_FollowNavInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AI_FollowNavInfo_t>();
  AI_FollowNavInfo_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB790
// Name: AI_FollowParams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_FollowParams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AI_FollowParams_t>();
  AI_FollowParams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB7A0
// Name: CAI_FollowBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_FollowBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_FollowBehavior>();
  CAI_FollowBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB7B0
// Name: CAI_FollowGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_FollowGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_FollowGoal>();
  CAI_FollowGoal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB7C0
// Name: _dynamic_initializer_for__ai_goal_follow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_goal_follow__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_FollowGoal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_goal_follow,
           a3: "ai_goal_follow");
}

//------------------------------------------------------------------------------
// Address: 0x103FB7E0
// Name: _dynamic_initializer_for__CAI_FollowBehavior::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_FollowBehavior::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_FollowBehavior::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_FollowBehavior::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_FollowBehavior::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}
