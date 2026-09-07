// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_memory.cpp
// Functions: 23
// ============================================================

#include "game\server\ai_memory.h"

//------------------------------------------------------------------------------
// Address: 0x10059430
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CBaseEntity __near *,struct AI_EnemyInfo_t __near *,unsigned char>::Node_t,unsigned char>,unsigned char>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char> *m_pMemory; // edx
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
    if ( (unsigned __int8)m_nAllocationCount < v5 )
    {
      if ( (_BYTE)m_nAllocationCount != 0 || v5 > 255 )
      {
        if ( (unsigned __int8)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int8)m_nAllocationCount < v5 );
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AE70
// Name: public: virtual void CAI_EnemiesListSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_EnemiesListSaveRestoreOps::Save(
        CAI_EnemiesListSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> > *pField; // esi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  unsigned __int8 Inorder; // al
  int nMemories; // [esp+8h] [ebp-4h] BYREF
  unsigned __int8 i; // [esp+14h] [ebp+8h]

  pField = (CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> > *)fieldInfo->pField;
  WriteInt_2 = pSave->WriteInt_2;
  nMemories = *((unsigned __int8 *)fieldInfo->pField + 17);
  WriteInt_2(this: pSave, a2: &nMemories, a3: 1);
  Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(this: pField);
  for ( i = Inorder; Inorder != 0xFF; i = Inorder )
  {
    pSave->WriteAll(this: pSave, a2: pField->m_Elements.m_pMemory[Inorder].m_Data.elem, a3: &AI_EnemyInfo_t::m_DataMap);
    Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
                this: pField,
                i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AEE0
// Name: public: virtual void CAI_EnemiesListSaveRestoreOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_EnemiesListSaveRestoreOps::MakeEmpty(
        CAI_EnemiesListSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> > *pField; // esi
  unsigned __int8 Inorder; // al
  unsigned __int8 i; // [esp+Ch] [ebp+8h]

  pField = (CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> > *)fieldInfo->pField;
  Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(this: (CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> > *)fieldInfo->pField);
  for ( i = Inorder; Inorder != 0xFF; i = Inorder )
  {
    free(pMem: pField->m_Elements.m_pMemory[Inorder].m_Data.elem);
    Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
                this: pField,
                i);
  }
  CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::RemoveAll(this: pField);
}

//------------------------------------------------------------------------------
// Address: 0x1005AF30
// Name: public: CAI_Enemies::~CAI_Enemies(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Enemies::~CAI_Enemies(CAI_Enemies *this)
{
  unsigned __int8 Inorder; // al
  unsigned __int8 i; // [esp+8h] [ebp-4h]

  Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(this: &this->m_Map.m_Tree);
  for ( i = Inorder; Inorder != 0xFF; i = Inorder )
  {
    free(pMem: this->m_Map.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem);
    Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
                this: &this->m_Map.m_Tree,
                i);
  }
  CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::RemoveAll(this: &this->m_Map.m_Tree);
  this->m_Map.m_Tree.m_FirstFree = -1;
  if ( this->m_Map.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Map.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Map.m_Tree.m_Elements.m_pMemory);
      this->m_Map.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_Map.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_Map.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_Map.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Map.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Map.m_Tree.m_Elements.m_pMemory);
      this->m_Map.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_Map.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AFD0
// Name: public: struct AI_EnemyInfo_t __near * CAI_Enemies::GetNext(struct AIEnemiesIter_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
AI_EnemyInfo_t *__thiscall CAI_Enemies::GetNext(CAI_Enemies *this, AIEnemiesIter_t__ **pIter)
{
  unsigned __int8 Inorder; // al
  unsigned int m_Index; // ecx
  unsigned __int8 i; // [esp+14h] [ebp+8h]

  i = *(_BYTE *)pIter;
  if ( i != 0xFF )
  {
    do
    {
      Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
                  this: &this->m_Map.m_Tree,
                  i);
      *pIter = (AIEnemiesIter_t__ *)Inorder;
      if ( Inorder == 0xFF )
        break;
      m_Index = this->m_Map.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem->hEnemy.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        return this->m_Map.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      }
      i = *(_BYTE *)pIter;
    }
    while ( *(_BYTE *)pIter != 0xFF );
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005B060
// Name: public: struct AI_EnemyInfo_t __near * CAI_Enemies::Find(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
AI_EnemyInfo_t *__thiscall CAI_Enemies::Find(CAI_Enemies *this, CBaseEntity *pEntity, bool bTryDangerMemory)
{
  CBaseEntity *v3; // eax
  unsigned __int8 v5; // al
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t v7; // [esp+4h] [ebp-10h] BYREF
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v3 = pEntity;
  if ( pEntity == (CBaseEntity *)852 )
    v3 = nullptr;
  search.key = v3;
  v5 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v5 == 0xFF
    && (!bTryDangerMemory
     || (v7.key = nullptr,
         (v5 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
                 this: &this->m_Map.m_Tree,
                 search: &v7)) == 0xFF)) )
  {
    return nullptr;
  }
  else
  {
    return this->m_Map.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B0C0
// Name: public: struct AI_EnemyInfo_t __near * CAI_Enemies::GetDangerMemory(void)
// Source: json
//------------------------------------------------------------------------------
AI_EnemyInfo_t *__thiscall CAI_Enemies::GetDangerMemory(CAI_Enemies *this)
{
  unsigned __int8 v2; // al
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = nullptr;
  v2 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v2 == 0xFF )
    return nullptr;
  else
    return this->m_Map.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x1005B100
// Name: public: void CAI_Enemies::OnTookDamageFrom(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Enemies::OnTookDamageFrom(CAI_Enemies *this, CBaseEntity *pEnemy)
{
  CBaseEntity *v2; // eax
  unsigned __int8 v4; // al
  AI_EnemyInfo_t *elem; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t v6; // [esp+4h] [ebp-10h] BYREF
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v2 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v2 = nullptr;
  search.key = v2;
  v4 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v4 != 0xFF
    || (v6.key = nullptr,
        (v4 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
                this: &this->m_Map.m_Tree,
                search: &v6)) != 0xFF) )
  {
    elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    if ( elem != nullptr )
      elem->timeLastReceivedDamageFrom = gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B160
// Name: public: bool CAI_Enemies::HasMemory(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Enemies::HasMemory(CAI_Enemies *this, CBaseEntity *pEnemy)
{
  CBaseEntity *v2; // eax
  unsigned __int8 v4; // al
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v2 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v2 = nullptr;
  search.key = v2;
  v4 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  return v4 != 0xFF && this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005B1B0
// Name: public: void CAI_Enemies::MarkAsEluded(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Enemies::MarkAsEluded(CAI_Enemies *this, CBaseEntity *pEnemy)
{
  CBaseEntity *v2; // eax
  unsigned __int8 v4; // al
  AI_EnemyInfo_t *elem; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v2 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v2 = nullptr;
  search.key = v2;
  v4 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v4 != 0xFF )
  {
    elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    if ( elem != nullptr )
      elem->bEludedMe = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B200
// Name: public: class Vector const __near & CAI_Enemies::LastKnownPosition(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Enemies::LastKnownPosition(CAI_Enemies *this, CBaseEntity *pEnemy)
{
  CBaseEntity *v2; // eax
  unsigned __int8 v4; // al
  AI_EnemyInfo_t *elem; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t v7; // [esp+4h] [ebp-10h] BYREF
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v2 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v2 = nullptr;
  search.key = v2;
  v4 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v4 == 0xFF
    && (v7.key = nullptr,
        (v4 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
                this: &this->m_Map.m_Tree,
                search: &v7)) == 0xFF)
    || (elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem) == nullptr )
  {
    _DevWarning(a1: 2, a2: "Asking LastKnownPosition for enemy that's not in my memory!!\n");
    return &this->m_vecDefaultLKP;
  }
  else
  {
    this->m_vecDefaultLKP.x = elem->vLastKnownLocation.x;
    this->m_vecDefaultLKP.y = elem->vLastKnownLocation.y;
    this->m_vecDefaultLKP.z = elem->vLastKnownLocation.z;
    return &this->m_vecDefaultLKP;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B290
// Name: public: float CAI_Enemies::LastTimeSeen(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Enemies::LastTimeSeen(CAI_Enemies *this, CBaseEntity *pEnemy, bool bCheckDangerMemory)
{
  CBaseEntity *v5; // eax
  unsigned __int8 v6; // al
  AI_EnemyInfo_t *elem; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t v8; // [esp+8h] [ebp-10h] BYREF
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  if ( pEnemy == nullptr )
    return 0.0;
  v5 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v5 = nullptr;
  search.key = v5;
  v6 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v6 != 0xFF
    || bCheckDangerMemory
    && (v8.key = nullptr,
        (v6 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
                this: &this->m_Map.m_Tree,
                search: &v8)) != 0xFF) )
  {
    elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    if ( elem != nullptr )
      return elem->timeLastSeen;
  }
  if ( pEnemy != (CBaseEntity *)852 )
    _DevWarning(a1: 2, a2: "Asking LastTimeSeen for enemy that's not in my memory!!\n");
  return -3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x1005B330
// Name: public: float CAI_Enemies::FirstTimeSeen(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Enemies::FirstTimeSeen(CAI_Enemies *this, CBaseEntity *pEnemy)
{
  CBaseEntity *v4; // eax
  unsigned __int8 v5; // al
  AI_EnemyInfo_t *elem; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t v7; // [esp+8h] [ebp-10h] BYREF
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  if ( pEnemy == nullptr )
    return 0.0;
  v4 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v4 = nullptr;
  search.key = v4;
  v5 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v5 != 0xFF
    || (v7.key = nullptr,
        (v5 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
                this: &this->m_Map.m_Tree,
                search: &v7)) != 0xFF) )
  {
    elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
    if ( elem != nullptr )
      return elem->timeFirstSeen;
  }
  if ( pEnemy != (CBaseEntity *)852 )
    _DevWarning(a1: 2, a2: "Asking FirstTimeSeen for enemy that's not in my memory!!\n");
  return -3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x1005B3C0
// Name: public: bool CAI_Enemies::HasEludedMe(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Enemies::HasEludedMe(CAI_Enemies *this, CBaseEntity *pEnemy)
{
  CBaseEntity *v2; // eax
  unsigned __int8 v4; // al
  AI_EnemyInfo_t *elem; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v2 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v2 = nullptr;
  search.key = v2;
  v4 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v4 == 0xFF )
    return false;
  elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  return elem != nullptr && elem->bEludedMe;
}

//------------------------------------------------------------------------------
// Address: 0x1005B510
// Name: public: CAI_Enemies::CAI_Enemies(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Enemies *__thiscall CAI_Enemies::CAI_Enemies(CAI_Enemies *this)
{
  CAI_Enemies *result; // eax
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char> *m_pMemory; // edx

  result = this;
  this->m_Map.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Map.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Map.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Map.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_Map.m_Tree.m_Elements.m_pMemory;
  this->m_flFreeKnowledgeDuration = 1.75;
  *(_DWORD *)&this->m_Map.m_Tree.m_Root = -65281;
  this->m_Map.m_Tree.m_pElements = m_pMemory;
  this->m_flEnemyDiscardTime = 60.0;
  this->m_vecDefaultLKP = vec3_invalid;
  this->m_vecDefaultLSP = vec3_invalid;
  this->m_serial = 0;
  if ( this->m_Map.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Map.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CBaseEntity *const *, CBaseEntity *const *))CDefOps<CChoreoActor *>::LessFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005B5B0
// Name: public: struct AI_EnemyInfo_t __near * CAI_Enemies::GetFirst(struct AIEnemiesIter_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
AI_EnemyInfo_t *__thiscall CAI_Enemies::GetFirst(CAI_Enemies *this, AIEnemiesIter_t__ **pIter)
{
  unsigned __int8 Inorder; // al
  AI_EnemyInfo_t *result; // eax
  unsigned int m_Index; // ecx

  Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(this: &this->m_Map.m_Tree);
  *pIter = (AIEnemiesIter_t__ *)Inorder;
  if ( Inorder == 0xFF )
    return nullptr;
  result = this->m_Map.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
  m_Index = result->hEnemy.m_Index;
  if ( result->hEnemy.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    return CAI_Enemies::GetNext(this, pIter);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005B620
// Name: public: virtual void CAI_EnemiesListSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_EnemiesListSaveRestoreOps::Restore(
        CAI_EnemiesListSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  IRestore *v3; // ebx
  CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> > *pField; // esi
  int v5; // eax
  AI_EnemyInfo_t *v6; // eax
  AI_EnemyInfo_t *v7; // edi
  unsigned int m_Index; // ecx
  const char *v9; // ebx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  CBaseEntity *v16; // eax
  unsigned __int8 v17; // al
  unsigned __int8 v18; // dl
  int v19; // edi
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char> *v20; // ecx
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char> *m_pMemory; // edx
  int v23; // ecx
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char> *v24; // ecx
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t *p_m_Data; // edi
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t insert; // [esp+8h] [ebp-14h] BYREF
  int nMemories; // [esp+10h] [ebp-Ch]
  unsigned __int8 elem[4]; // [esp+17h] [ebp-5h]
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  v3 = pRestore;
  pField = (CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char> > *)fieldInfo->pField;
  v5 = pRestore->ReadInt(this: pRestore);
  if ( v5 != 0 )
  {
    while ( 1 )
    {
      nMemories = v5 - 1;
      v6 = (AI_EnemyInfo_t *)operator new(nSize: 0x3Cu);
      v7 = nullptr;
      if ( v6 != nullptr )
      {
        v6->hEnemy.m_Index = -1;
        v6->vLastKnownLocation = vec3_origin;
        v6->vLastSeenLocation = vec3_origin;
        v6->timeLastSeen = 0.0;
        v6->timeFirstSeen = 0.0;
        v6->timeLastReacquired = 0.0;
        v6->timeValidEnemy = 0.0;
        v6->timeLastReceivedDamageFrom = 0.0;
        v6->nFaction = 0;
        *(_DWORD *)&v6->bDangerMemory = 0;
        v6->timeAtFirstHand = -3.4028235e38;
        v7 = v6;
      }
      v3->ReadAll(this: v3, a2: v7, a3: &AI_EnemyInfo_t::m_DataMap);
      m_Index = v7->hEnemy.m_Index;
      if ( v7->hEnemy.m_Index != -1
        && (v9 = (const char *)g_pEntityList,
            v10 = (unsigned __int16)m_Index,
            v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
            v12 = HIWORD(m_Index),
            v11->m_SerialNumber == v12)
        && v11->m_pEntity != nullptr )
      {
        v13 = v10;
        v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
        v15 = &g_pEntityList->m_EntPtrArray[v13];
        v16 = v14 ? (CBaseEntity *)v15->m_pEntity : nullptr;
        insert.key = v16;
        LOBYTE(v9) = -1;
        insert.elem = v7;
        HIBYTE(fieldInfo) = -1;
        leftchild = false;
        CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::FindInsertionPosition(
          this: pField,
          &insert,
          parent: (unsigned __int8 *)&fieldInfo + 3,
          &leftchild);
        v17 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::NewNode(
                this: pField,
                a2: v9);
        v18 = HIBYTE(fieldInfo);
        v19 = v17;
        v20 = &pField->m_Elements.m_pMemory[v19];
        elem[0] = v17;
        v20->m_Parent = HIBYTE(fieldInfo);
        *(_WORD *)&v20->m_Left = -1;
        v20->m_Tag = 0;
        if ( v18 == 0xFF )
        {
          pField->m_Root = v17;
        }
        else
        {
          v21 = v18;
          m_pMemory = pField->m_Elements.m_pMemory;
          v23 = v21;
          if ( leftchild )
            m_pMemory[v23].m_Left = v17;
          else
            m_pMemory[v23].m_Right = v17;
        }
        CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertRebalance(
          this: pField,
          elem: elem[0]);
        v24 = pField->m_Elements.m_pMemory;
        ++pField->m_NumElements;
        p_m_Data = &v24[v19].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = insert;
      }
      else
      {
        free(pMem: v7);
      }
      v5 = nMemories;
      if ( nMemories == 0 )
        break;
      v3 = pRestore;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B7F0
// Name: public: void CAI_Enemies::RefreshMemories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Enemies::RefreshMemories(CAI_Enemies *this)
{
  float m_flEnemyDiscardTime; // xmm0_4
  unsigned __int8 Inorder; // al
  int v4; // esi
  AI_EnemyInfo_t *elem; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  IHandleEntity *v13; // edx
  int v14; // eax
  bool v15; // zf
  CBaseEntity **v16; // eax
  CBaseEntity *v17; // esi
  unsigned int v18; // eax
  CBaseEntity *v19; // esi
  unsigned __int8 i; // [esp+7h] [ebp-5h]
  unsigned __int8 iNext; // [esp+Bh] [ebp-1h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  m_flEnemyDiscardTime = this->m_flEnemyDiscardTime;
  if ( this->m_flFreeKnowledgeDuration >= m_flEnemyDiscardTime )
    this->m_flFreeKnowledgeDuration = m_flEnemyDiscardTime - 0.1;
  Inorder = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(this: &this->m_Map.m_Tree);
  i = Inorder;
  if ( Inorder != 0xFF )
  {
    while ( 1 )
    {
      v4 = Inorder;
      elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
      iNext = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
                this: &this->m_Map.m_Tree,
                i);
      m_Index = elem->hEnemy.m_Index;
      if ( elem->hEnemy.m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
      {
        v8 = (int)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
        if ( v8 != 0 && (*(_DWORD *)(v8 + 2520) == 7 || *(_DWORD *)(v8 + 1784) != elem->nFaction) )
        {
LABEL_16:
          free(pMem: elem);
          if ( i != 0xFF )
          {
            CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Unlink(
              this: &this->m_Map.m_Tree,
              elem: i);
            this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Left = i;
            this->m_Map.m_Tree.m_Elements.m_pMemory[v4].m_Right = this->m_Map.m_Tree.m_FirstFree;
            --this->m_Map.m_Tree.m_NumElements;
            this->m_Map.m_Tree.m_FirstFree = i;
          }
          goto LABEL_40;
        }
      }
      else if ( !elem->bDangerMemory )
      {
        goto LABEL_16;
      }
      if ( !elem->bUnforgettable && gpGlobals->curtime > (float)(elem->timeLastSeen + this->m_flEnemyDiscardTime) )
        goto LABEL_16;
      v9 = elem->hEnemy.m_Index;
      if ( elem->hEnemy.m_Index != -1 )
      {
        v10 = (unsigned __int16)v9;
        v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v9];
        v12 = HIWORD(v9);
        if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
        {
          if ( (float)(elem->timeLastSeen + this->m_flFreeKnowledgeDuration) >= gpGlobals->curtime )
          {
            v13 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v12
                ? g_pEntityList->m_EntPtrArray[v10].m_pEntity
                : nullptr;
            if ( ((int)v13[50].__vftable & 0x10000) == 0 )
            {
              v14 = v10;
              v15 = g_pEntityList->m_EntPtrArray[v14].m_SerialNumber == v12;
              v16 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v14];
              if ( v15 )
                v17 = *v16;
              else
                v17 = nullptr;
              if ( (v17->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
              elem->vLastKnownLocation.x = v17->m_vecAbsOrigin.x;
              elem->vLastKnownLocation.y = v17->m_vecAbsOrigin.y;
              elem->vLastKnownLocation.z = v17->m_vecAbsOrigin.z;
            }
          }
          if ( elem->timeLastSeen >= gpGlobals->curtime )
          {
            v18 = elem->hEnemy.m_Index;
            if ( elem->hEnemy.m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
            {
              v19 = nullptr;
            }
            else
            {
              v19 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
            }
            if ( (v19->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v19, a2: (int)&savedregs);
            elem->vLastSeenLocation.x = v19->m_vecAbsOrigin.x;
            elem->vLastSeenLocation.y = v19->m_vecAbsOrigin.y;
            elem->vLastSeenLocation.z = v19->m_vecAbsOrigin.z;
          }
        }
      }
LABEL_40:
      i = iNext;
      if ( iNext == 0xFF )
        return;
      Inorder = iNext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BA30
// Name: public: bool CAI_Enemies::UpdateMemory(class CAI_Network __near *,class CBaseEntity __near *,class Vector const __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Enemies::UpdateMemory(
        CAI_Enemies *this,
        CAI_Network *pAINet,
        CBaseEntity *pEnemy,
        const Vector *vPosition,
        float reactionDelay,
        bool firstHand)
{
  CBaseEntity *v6; // edi
  CBaseEntity *v8; // eax
  unsigned __int8 v9; // al
  AI_EnemyInfo_t *elem; // ecx
  bool v11; // dl
  const Vector *v12; // eax
  float v13; // xmm0_4
  AI_EnemyInfo_t *v15; // eax
  AI_EnemyInfo_t *v16; // esi
  bool v17; // zf
  float curtime; // xmm1_4
  int v19; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t *p_m_Data; // eax
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v6 = pEnemy;
  if ( pEnemy == (CBaseEntity *)852 )
    v6 = nullptr;
  v8 = v6;
  if ( v6 == (CBaseEntity *)852 )
    v8 = nullptr;
  search.key = v8;
  v9 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  if ( v9 == 0xFF || (elem = this->m_Map.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem) == nullptr )
  {
    v15 = (AI_EnemyInfo_t *)operator new(nSize: 0x3Cu);
    v16 = nullptr;
    if ( v15 != nullptr )
    {
      v15->hEnemy.m_Index = -1;
      v15->vLastKnownLocation = vec3_origin;
      v15->vLastSeenLocation = vec3_origin;
      v15->nFaction = 0;
      *(_DWORD *)&v15->bDangerMemory = 0;
      v15->timeLastSeen = 0.0;
      v15->timeFirstSeen = 0.0;
      v15->timeLastReacquired = 0.0;
      v15->timeValidEnemy = 0.0;
      v15->timeLastReceivedDamageFrom = 0.0;
      v15->timeAtFirstHand = -3.4028235e38;
      v16 = v15;
    }
    v17 = !firstHand;
    v16->vLastKnownLocation = *vPosition;
    if ( v17 )
    {
      curtime = gpGlobals->curtime - (this->m_flFreeKnowledgeDuration + 0.01);
      v16->timeAtFirstHand = -3.4028235e38;
    }
    else
    {
      curtime = gpGlobals->curtime;
      v16->timeAtFirstHand = curtime;
    }
    v16->timeLastReacquired = curtime;
    v16->timeFirstSeen = curtime;
    v16->timeLastSeen = curtime;
    if ( reactionDelay > 0.0 )
      v16->timeValidEnemy = gpGlobals->curtime + reactionDelay;
    v16->bEludedMe = false;
    if ( v6 != nullptr )
      v16->hEnemy.m_Index = v6->GetRefEHandle(this: v6)->m_Index;
    else
      v16->hEnemy.m_Index = -1;
    v16->bDangerMemory = v6 == nullptr;
    if ( v6 != nullptr )
    {
      v19 = (int)v6->MyNPCPointer(this: v6);
      if ( v19 != 0 )
        v16->nFaction = *(_DWORD *)(v19 + 1784);
    }
    search.key = v6;
    search.elem = v16;
    LOBYTE(vPosition) = -1;
    firstHand = false;
    CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::FindInsertionPosition(
      this: &this->m_Map.m_Tree,
      insert: &search,
      parent: (unsigned __int8 *)&vPosition,
      leftchild: &firstHand);
    p_m_Data = &this->m_Map.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertAt(
                                                          this: &this->m_Map.m_Tree,
                                                          a2: (const char *)this,
                                                          parent: (unsigned __int8)vPosition,
                                                          leftchild: firstHand)].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = search;
    ++this->m_serial;
    return 1;
  }
  else
  {
    v11 = firstHand;
    if ( firstHand )
      elem->timeLastSeen = gpGlobals->curtime;
    v12 = vPosition;
    elem->bEludedMe = false;
    v13 = (float)((float)((float)(elem->vLastKnownLocation.y - v12->y) * (float)(elem->vLastKnownLocation.y - v12->y))
                + (float)((float)(elem->vLastKnownLocation.x - v12->x) * (float)(elem->vLastKnownLocation.x - v12->x)))
        + (float)((float)(elem->vLastKnownLocation.z - v12->z) * (float)(elem->vLastKnownLocation.z - v12->z));
    if ( v13 > 57600.0 || v13 > 2304.0 && (float)(gpGlobals->curtime - elem->timeLastSeen) > 4.0 )
      elem->timeLastReacquired = gpGlobals->curtime;
    if ( v13 > 144.0 )
    {
      elem->vLastKnownLocation.x = v12->x;
      elem->vLastKnownLocation.y = v12->y;
      elem->vLastKnownLocation.z = v12->z;
    }
    if ( v11 && elem->timeAtFirstHand == -3.402823466385289e38 )
      elem->timeAtFirstHand = gpGlobals->curtime;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BD00
// Name: public: void CAI_Enemies::ClearMemory(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Enemies::ClearMemory(CAI_Enemies *this, CBaseEntity *pEnemy)
{
  unsigned __int8 v3; // al
  unsigned __int8 v4; // bl
  int v5; // edi
  CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t search; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 i; // [esp+18h] [ebp+8h]

  search.key = pEnemy;
  v3 = CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_Map.m_Tree,
         &search);
  v4 = v3;
  i = v3;
  if ( v3 != 0xFF )
  {
    v5 = v3;
    free(pMem: this->m_Map.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem);
    CUtlRBTree<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char,CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,AI_EnemyInfo_t *,unsigned char>::Node_t,unsigned char>,unsigned char>>::Unlink(
      this: &this->m_Map.m_Tree,
      elem: i);
    this->m_Map.m_Tree.m_Elements.m_pMemory[v5].m_Left = v4;
    this->m_Map.m_Tree.m_Elements.m_pMemory[v5].m_Right = this->m_Map.m_Tree.m_FirstFree;
    --this->m_Map.m_Tree.m_NumElements;
    this->m_Map.m_Tree.m_FirstFree = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FC7F0
// Name: CAI_Enemies_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Enemies_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Enemies>(__formal: nullptr);
  CAI_Enemies_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FC800
// Name: AI_EnemyInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_EnemyInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AI_EnemyInfo_t>();
  AI_EnemyInfo_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005B410
// Name: struct datamap_t __near * DataMapInit<class CAI_Enemies>(class CAI_Enemies __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Enemies>()
{
  if ( (_S2_21 & 1) == 0 )
  {
    _S2_21 |= 1u;
    nameHolder_49.m_pszBase = "CAI_Enemies";
    nameHolder_49.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_49.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_49.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_49.m_Names.m_Size = 0;
    nameHolder_49.m_Names.m_pElements = nullptr;
    nameHolder_49.m_nLenBase = 11;
    atexit(func: DataMapInit_CAI_Enemies__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Enemies::m_DataMap.baseMap = nullptr;
  CAI_Enemies::m_DataMap.dataNumFields = 6;
  CAI_Enemies::m_DataMap.dataDesc = &dataDesc_47[1];
  return &CAI_Enemies::m_DataMap;
}
