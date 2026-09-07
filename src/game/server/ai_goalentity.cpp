// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_goalentity.cpp
// Functions: 16
// ============================================================

#include "game\server\ai_goalentity.h"

//------------------------------------------------------------------------------
// Address: 0x10050D70
// Name: protected: virtual struct datamap_t __near * CAI_GoalEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_GoalEntity::GetDataDescMap(CAI_GoalEntity *this)
{
  return &CAI_GoalEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10050E90
// Name: protected: virtual void CAI_GoalEntity::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::UpdateOnRemove(CAI_GoalEntity *this)
{
  void (__thiscall *InputDeactivate)(CAI_GoalEntity *, inputdata_t *); // edx
  inputdata_t inputdata; // [esp+4h] [ebp-20h] BYREF

  if ( (this->m_flags & 1) != 0 )
  {
    inputdata.value.iVal = 0;
    inputdata.value.fieldType = FIELD_VOID;
    InputDeactivate = this->InputDeactivate;
    inputdata.value.eVal.m_Index = -1;
    InputDeactivate(this, a2: &inputdata);
  }
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10051300
// Name: public: virtual void CAI_GoalEntity::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::OnRestore(CAI_GoalEntity *this)
{
  unsigned int m_flags; // eax
  void (__thiscall *InputUpdateActors)(CAI_GoalEntity *, inputdata_t *); // edx
  char v4; // [esp+4h] [ebp-20h] BYREF
  int v5; // [esp+Ch] [ebp-18h]
  int v6; // [esp+18h] [ebp-Ch]
  int v7; // [esp+1Ch] [ebp-8h]

  CBaseEntity::OnRestore(this);
  m_flags = this->m_flags;
  if ( (m_flags & 4) != 0 )
  {
    this->m_flags = m_flags & 0xFFFFFFFB;
    v5 = 0;
    v7 = 0;
    InputUpdateActors = this->InputUpdateActors;
    v6 = -1;
    InputUpdateActors(this, a2: (inputdata_t *)&v4);
  }
  if ( (this->m_flags & 1) != 0 )
    CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
}

//------------------------------------------------------------------------------
// Address: 0x10051360
// Name: protected: void CAI_GoalEntity::DelayedRefresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::DelayedRefresh(CAI_GoalEntity *this)
{
  bool v2; // zf
  CAI_GoalEntity_vtbl *v3; // eax
  inputdata_t ignored; // [esp+10h] [ebp-20h] BYREF

  v2 = !this->m_fStartActive;
  v3 = this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  ignored.value.iVal = 0;
  ignored.value.eVal.m_Index = -1;
  ignored.value.fieldType = FIELD_VOID;
  if ( v2 )
  {
    ((void (__stdcall *)(inputdata_t *))v3->InputUpdateActors)(a1: &ignored);
  }
  else
  {
    ((void (__stdcall *)(inputdata_t *))v3->InputActivate)(a1: &ignored);
    this->m_fStartActive = false;
  }
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: "Refresh");
}

//------------------------------------------------------------------------------
// Address: 0x100513D0
// Name: protected: void CAI_GoalEntity::PruneActors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::PruneActors(CAI_GoalEntity *this)
{
  int v1; // ebx
  CBaseEntityList *v2; // edi
  CHandle<CAI_BaseNPC> *v3; // esi
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  IHandleEntity *m_pEntity; // edx
  unsigned int v7; // eax
  IHandleEntity *v8; // edx
  int m_Size; // edx

  v1 = this->m_actors.m_Size - 1;
  if ( v1 >= 0 )
  {
    v2 = g_pEntityList;
    do
    {
      v3 = &this->m_actors.m_Memory.m_pMemory[v1];
      m_Index = v3->m_Index;
      if ( v3->m_Index == -1
        || v2->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || v2->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
        || ((v5 = v3->m_Index, v3->m_Index == -1)
         || v2->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
          ? (m_pEntity = nullptr)
          : (m_pEntity = v2->m_EntPtrArray[(unsigned __int16)v5].m_pEntity),
            ((int)m_pEntity[49].__vftable & 1) != 0
         || ((v7 = v3->m_Index, v3->m_Index == -1)
          || v2->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7)
           ? (v8 = nullptr)
           : (v8 = v2->m_EntPtrArray[(unsigned __int16)v7].m_pEntity),
             v8[630].__vftable == (IHandleEntity_vtbl *)7)) )
      {
        m_Size = this->m_actors.m_Size;
        if ( m_Size > 0 )
        {
          if ( v1 != m_Size - 1 )
            this->m_actors.m_Memory.m_pMemory[v1].m_Index = this->m_actors.m_Memory.m_pMemory[m_Size - 1].m_Index;
          --this->m_actors.m_Size;
          v2 = g_pEntityList;
        }
      }
      --v1;
    }
    while ( v1 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100514B0
// Name: protected: virtual void CAI_GoalEntity::OnEntityCreated(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::OnEntityCreated(CAI_GoalEntity *this, CBaseEntity *pEntity)
{
  if ( pEntity->MyNPCPointer(this: pEntity) != nullptr )
    CBaseEntity::ThinkSet(
      this: (CAI_GoalEntity *)((char *)this - 852),
      func: (void (__thiscall *)(CBaseEntity *))CAI_GoalEntity::DelayedRefresh,
      thinkTime: gpGlobals->curtime + 0.1,
      szContext: "Refresh");
}

//------------------------------------------------------------------------------
// Address: 0x100529C0
// Name: public: virtual void CAI_GoalEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::Spawn(CAI_GoalEntity *this)
{
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CAI_GoalEntity::DelayedRefresh,
    thinkTime: gpGlobals->curtime + 0.1,
    szContext: "Refresh");
}

//------------------------------------------------------------------------------
// Address: 0x100529F0
// Name: public: virtual void CAI_GoalEntity::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::InputActivate(CAI_GoalEntity *this, inputdata_t *inputdata)
{
  unsigned int m_flags; // eax
  int i; // edi
  unsigned int m_Index; // eax
  CAI_BaseNPC *m_pEntity; // ecx

  if ( (this->m_flags & 1) == 0 )
  {
    this->OnActivate(this);
    CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
    m_flags = this->m_flags;
    if ( (m_flags & 1) != 0 && (m_flags & 2) != 0 )
    {
      CAI_GoalEntity::PruneActors(this);
    }
    else
    {
      this->ResolveNames(this);
      this->m_flags |= 2u;
    }
    this->m_flags |= 1u;
    for ( i = 0; i < this->m_actors.m_Size; ++i )
    {
      m_Index = this->m_actors.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      this->EnableGoal(this, a2: m_pEntity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052AB0
// Name: public: virtual void CAI_GoalEntity::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::InputDeactivate(CAI_GoalEntity *this, inputdata_t *inputdata)
{
  unsigned int m_flags; // eax
  int i; // edi
  unsigned int m_Index; // eax
  CAI_BaseNPC *m_pEntity; // ecx

  if ( (this->m_flags & 1) != 0 )
  {
    this->OnDeactivate(this);
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
    m_flags = this->m_flags;
    if ( (m_flags & 1) != 0 && (m_flags & 2) != 0 )
    {
      CAI_GoalEntity::PruneActors(this);
    }
    else
    {
      this->ResolveNames(this);
      this->m_flags |= 2u;
    }
    this->m_flags &= ~1u;
    for ( i = 0; i < this->m_actors.m_Size; ++i )
    {
      m_Index = this->m_actors.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      this->DisableGoal(this, a2: m_pEntity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052B70
// Name: public: virtual int CAI_GoalEntity::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_GoalEntity::DrawDebugTextOverlays(CAI_GoalEntity *this)
{
  int v2; // edi
  unsigned int m_flags; // eax
  const char *v4; // eax
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  v2 = CBaseEntity::DrawDebugTextOverlays(this);
  m_flags = this->m_flags;
  if ( (m_flags & 1) == 0 )
    goto LABEL_6;
  if ( (m_flags & 2) != 0 )
  {
    CAI_GoalEntity::PruneActors(this);
  }
  else
  {
    this->ResolveNames(this);
    this->m_flags |= 2u;
  }
  v4 = "yes";
  if ( this->m_actors.m_Size == 0 )
LABEL_6:
    v4 = "no";
  V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Active: %s", v4);
  CBaseEntity::EntityText(this, text_offset: v2, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
  return v2 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053220
// Name: protected: virtual void CAI_GoalEntity::ResolveNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::ResolveNames(CAI_GoalEntity *this)
{
  CAI_GoalEntity *v1; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_actors; // esi
  CBaseEntity *v3; // ebx
  CAI_GoalEntity::SearchType_t m_SearchType; // eax
  const char *pszValue; // eax
  CBaseEntity *EntityByClassname; // eax
  const char *v7; // eax
  CAI_BaseNPC *v8; // eax
  unsigned int m_Index; // ecx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v12; // ecx
  int v13; // eax
  unsigned int *v14; // eax
  const char *v15; // eax
  CBaseEntity *EntityByName; // eax
  CHandle<CAI_BaseNPC> temp; // [esp+Ch] [ebp-8h]

  v1 = this;
  p_m_actors = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_actors;
  v3 = nullptr;
  this->m_actors.m_Size = 0;
  while ( 1 )
  {
    m_SearchType = v1->m_SearchType;
    if ( m_SearchType != ST_ENTNAME )
    {
      if ( m_SearchType != ST_CLASSNAME )
        goto LABEL_11;
      pszValue = v1->m_iszActor.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByClassname = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: v3, szName: pszValue);
    }
    else
    {
      v7 = v1->m_iszActor.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      EntityByClassname = CGlobalEntityList::FindEntityByName(
                            this: &gEntList,
                            pStartEntity: v3,
                            szName: v7,
                            pSearchingEntity: nullptr,
                            pActivator: nullptr,
                            pCaller: nullptr,
                            pFilter: nullptr);
    }
    v3 = EntityByClassname;
LABEL_11:
    if ( v3 == nullptr )
      break;
    v8 = v3->MyNPCPointer(this: v3);
    if ( v8 != nullptr && v8->m_NPCState != NPC_STATE_DEAD )
    {
      m_Index = v8->GetRefEHandle(this: v8)->m_Index;
      m_pMemory = p_m_actors[1].m_pMemory;
      m_nAllocationCount = p_m_actors->m_nAllocationCount;
      temp.m_Index = m_Index;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_actors, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_actors[1].m_pMemory;
      v12 = p_m_actors->m_pMemory;
      v13 = (char *)p_m_actors[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_actors[1].m_nAllocationCount = (int)p_m_actors->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[(_DWORD)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 4 * v13);
      v14 = (unsigned int *)&p_m_actors->m_pMemory[(_DWORD)m_pMemory];
      v1 = this;
      if ( v14 != nullptr )
        *v14 = temp.m_Index;
    }
  }
  v15 = v1->m_iszGoal.pszValue;
  if ( v15 == nullptr )
    v15 = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v15,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    v1->m_hGoalEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    v1->m_hGoalEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10053370
// Name: public: virtual void CAI_GoalEntity::InputUpdateActors(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GoalEntity::InputUpdateActors(CAI_GoalEntity *this, inputdata_t *inputdata)
{
  UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short> *v2; // ebx
  int v4; // eax
  unsigned int m_Index; // eax
  CAI_BaseNPC *m_pEntity; // eax
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // dx
  unsigned __int16 v9; // cx
  int v10; // esi
  UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short> *m_pMemory; // eax
  int v12; // esi
  int v13; // edx
  CAI_BaseNPC **v14; // esi
  bool v15; // cc
  int v16; // esi
  unsigned int v17; // eax
  CAI_BaseNPC *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  IHandleEntity *v21; // ecx
  unsigned __int16 v22; // ax
  int v23; // esi
  unsigned __int16 m_FirstFree; // cx
  UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short> *v25; // eax
  unsigned __int16 j; // si
  CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl*)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short> > prevActors; // [esp+Ch] [ebp-2Ch] BYREF
  CAI_BaseNPC *insert; // [esp+28h] [ebp-10h] BYREF
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-Ch] BYREF
  int i; // [esp+30h] [ebp-8h]
  bool leftchild; // [esp+37h] [ebp-1h] BYREF

  v2 = nullptr;
  memset(&prevActors.m_Elements, 0, sizeof(prevActors.m_Elements));
  *(_DWORD *)&prevActors.m_Root = 0xFFFF;
  *(_DWORD *)&prevActors.m_FirstFree = -1;
  prevActors.m_pElements = nullptr;
  prevActors.m_LessFunc = (bool (__cdecl *)(CAI_BaseNPC *const *, CAI_BaseNPC *const *))CDefOps<CChoreoActor *>::LessFunc;
  CAI_GoalEntity::PruneActors(this);
  v4 = 0;
  for ( i = 0; v4 < this->m_actors.m_Size; i = v4 )
  {
    m_Index = this->m_actors.m_Memory.m_pMemory[v4].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    insert = m_pEntity;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &prevActors,
      &insert,
      parent,
      &leftchild);
    v7 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
           this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&prevActors,
           a2: (const char *)this);
    v8 = parent[0];
    v9 = v7;
    v10 = 3 * v7;
    m_pMemory = prevActors.m_Elements.m_pMemory;
    v12 = 4 * v10;
    *(unsigned __int16 *)((char *)&prevActors.m_Elements.m_pMemory->m_Right + v12) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v12) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v12) = 0;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v12) = v8;
    if ( v8 == 0xFFFF )
    {
      prevActors.m_Root = v9;
    }
    else
    {
      v13 = v8;
      if ( leftchild )
        m_pMemory[v13].m_Left = v9;
      else
        m_pMemory[v13].m_Right = v9;
    }
    CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &prevActors,
      elem: v9);
    v2 = prevActors.m_Elements.m_pMemory;
    ++prevActors.m_NumElements;
    v14 = (CAI_BaseNPC **)((char *)&prevActors.m_Elements.m_pMemory->m_Data + v12);
    if ( v14 != nullptr )
      *v14 = insert;
    v4 = i + 1;
  }
  this->ResolveNames(this);
  v15 = this->m_actors.m_Size <= 0;
  i = 0;
  if ( !v15 )
  {
    do
    {
      v16 = i;
      v17 = this->m_actors.m_Memory.m_pMemory[i].m_Index;
      if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
        v18 = nullptr;
      else
        v18 = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
      insert = v18;
      if ( CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::Find(
             this: &prevActors,
             search: &insert) == 0xFFFF )
      {
        if ( (this->m_flags & 1) != 0 )
        {
          v19 = this->m_actors.m_Memory.m_pMemory[v16].m_Index;
          if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
            this->EnableGoal(this, a2: nullptr);
          else
            this->EnableGoal(this, a2: (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity);
        }
      }
      else
      {
        v20 = this->m_actors.m_Memory.m_pMemory[v16].m_Index;
        if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
          v21 = nullptr;
        else
          v21 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
        *(_DWORD *)parent = v21;
        v22 = CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::Find(
                this: &prevActors,
                search: (CAI_BaseNPC *const *)parent);
        v23 = v22;
        if ( v22 != 0xFFFF )
        {
          CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::Unlink(
            this: &prevActors,
            elem: v22);
          v2 = prevActors.m_Elements.m_pMemory;
          m_FirstFree = prevActors.m_FirstFree;
          v25 = &prevActors.m_Elements.m_pMemory[v23];
          --prevActors.m_NumElements;
          v25->m_Left = v23;
          v25->m_Right = m_FirstFree;
          prevActors.m_FirstFree = v23;
        }
      }
      ++i;
    }
    while ( i < this->m_actors.m_Size );
  }
  for ( j = CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::FirstInorder(this: &prevActors);
        j != 0xFFFF;
        j = CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::NextInorder(
              this: &prevActors,
              i: j) )
  {
    if ( (this->m_flags & 1) != 0 )
      this->DisableGoal(this, a2: v2[j].m_Data);
  }
  CUtlRBTree<CAI_BaseNPC *,unsigned short,bool (__cdecl *)(CAI_BaseNPC * const &,CAI_BaseNPC * const &),CUtlMemory<UtlRBTreeNode_t<CAI_BaseNPC *,unsigned short>,unsigned short>>::RemoveAll(this: &prevActors);
  if ( prevActors.m_Elements.m_nGrowSize >= 0 && prevActors.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: prevActors.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103FBC50
// Name: CAI_GoalEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_GoalEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_GoalEntity>();
  CAI_GoalEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FBC60
// Name: _dynamic_initializer_for__CAI_HintManager::gm_AllHints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CAI_HintManager::gm_AllHints__()
{
  return atexit(func: dynamic_atexit_destructor_for__CAI_HintManager::gm_AllHints__);
}

//------------------------------------------------------------------------------
// Address: 0x103FBC70
// Name: _dynamic_initializer_for__CAI_HintManager::gm_TypedHints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CAI_HintManager::gm_TypedHints__()
{
  return atexit(func: dynamic_atexit_destructor_for__CAI_HintManager::gm_TypedHints__);
}

//------------------------------------------------------------------------------
// Address: 0x103FBC80
// Name: _dynamic_initializer_for__ai_hint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_hint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_Hint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_hint,
           a3: "ai_hint");
}
