// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cliententitylist.cpp
// Functions: 28
// ============================================================

#include "game\client\cliententitylist.h"

//------------------------------------------------------------------------------
// Address: 0x100A3A60
// Name: public: virtual class IClientNetworkable __near * CClientEntityList::GetClientNetworkable(int)
// Source: json
//------------------------------------------------------------------------------
IClientNetworkable *__thiscall CClientEntityList::GetClientNetworkable(CClientEntityList *this, int entnum)
{
  return (IClientNetworkable *)*(&this->m_EntPtrArray[2].m_SerialNumber + 2 * entnum);
}

//------------------------------------------------------------------------------
// Address: 0x100A3A70
// Name: public: virtual struct EntityCacheInfo_t __near * CClientEntityList::GetClientNetworkableArray(void)
// Source: json
//------------------------------------------------------------------------------
EntityCacheInfo_t *__thiscall CClientEntityList::GetClientNetworkableArray(CClientEntityList *this)
{
  return (EntityCacheInfo_t *)&this->m_EntPtrArray[2].m_SerialNumber;
}

//------------------------------------------------------------------------------
// Address: 0x100A3A80
// Name: public: void CClientEntityList::SetDormant(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::SetDormant(CClientEntityList *this, int entityIndex, bool bDormant)
{
  this->m_EntityCacheInfo[entityIndex].m_bDormant = bDormant;
}

//------------------------------------------------------------------------------
// Address: 0x100A3AA0
// Name: public: virtual int CClientEntityList::NumberOfEntities(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientEntityList::NumberOfEntities(CClientEntityList *this, bool bIncludeNonNetworkable)
{
  if ( bIncludeNonNetworkable )
    return (int)this->m_EntPtrArray[1].m_pNext + this->m_EntPtrArray[1].m_SerialNumber;
  else
    return this->m_EntPtrArray[1].m_SerialNumber;
}

//------------------------------------------------------------------------------
// Address: 0x100A3AC0
// Name: public: virtual void CClientEntityList::SetMaxEntities(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::SetMaxEntities(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x100A3AE0
// Name: public: virtual class IClientEntity __near * CClientEntityList::GetClientEntity(int)
// Source: json
//------------------------------------------------------------------------------
IClientEntity *__thiscall CClientEntityList::GetClientEntity(CClientEntityList *this, int entnum)
{
  int v2; // ecx

  if ( entnum >= 0 && (v2 = *((_DWORD *)this + 4 * entnum - 32772)) != 0 )
    return (*(IClientEntity *(__thiscall **)(int))(*(_DWORD *)v2 + 24))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A3B10
// Name: public: void CClientEntityList::RecomputeHighestEntityUsed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::RecomputeHighestEntityUsed(CClientEntityList *this)
{
  int v1; // eax
  CEntInfo *i; // edx

  this->m_iMaxUsedServerIndex = -1;
  v1 = 2047;
  for ( i = &this->m_EntPtrArray[2047]; i->m_pEntity == nullptr; --i )
  {
    if ( --v1 < 0 )
      return;
  }
  this->m_iMaxUsedServerIndex = v1;
}

//------------------------------------------------------------------------------
// Address: 0x100A3B40
// Name: public: class C_BaseEntity __near * CClientEntityList::GetBaseEntity(int)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CClientEntityList::GetBaseEntity(CClientEntityList *this, int entnum)
{
  IHandleEntity *m_pEntity; // eax

  if ( entnum >= 0 && (m_pEntity = this->m_EntPtrArray[entnum].m_pEntity) != nullptr )
    return ((C_BaseEntity *(__thiscall *)(IHandleEntity *))m_pEntity->__vftable[2].SetRefEHandle)(a1: m_pEntity);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A3B70
// Name: public: virtual class IClientNetworkable __near * CClientEntityList::GetClientNetworkableFromHandle(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
IClientNetworkable *__thiscall CClientEntityList::GetClientNetworkableFromHandle(
        CClientEntityList *this,
        CBaseHandle hEnt)
{
  int v2; // eax

  v2 = ((int (__thiscall *)(CClientEntityList *, unsigned int))this->dtr_CClientEntityList)(a1: this, a2: hEnt.m_Index);
  if ( v2 != 0 )
    return (*(IClientNetworkable *(__thiscall **)(int))(*(_DWORD *)v2 + 16))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A3BA0
// Name: public: virtual class IClientEntity __near * CClientEntityList::GetClientEntityFromHandle(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
IClientEntity *__thiscall CClientEntityList::GetClientEntityFromHandle(CClientEntityList *this, CBaseHandle hEnt)
{
  int v2; // eax

  v2 = ((int (__thiscall *)(CClientEntityList *, unsigned int))this->dtr_CClientEntityList)(a1: this, a2: hEnt.m_Index);
  if ( v2 != 0 )
    return (*(IClientEntity *(__thiscall **)(int))(*(_DWORD *)v2 + 24))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A3BD0
// Name: public: class IClientRenderable __near * CClientEntityList::GetClientRenderableFromHandle(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CClientEntityList::GetClientRenderableFromHandle(
        CClientEntityList *this,
        CBaseHandle hEnt)
{
  int v2; // eax

  v2 = ((int (__thiscall *)(IClientEntityList *, unsigned int))this->GetClientUnknownFromHandle)(
         a1: &this->IClientEntityList,
         a2: hEnt.m_Index);
  if ( v2 != 0 )
    return (*(IClientRenderable *(__thiscall **)(int))(*(_DWORD *)v2 + 20))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A3C10
// Name: public: class C_BaseEntity __near * CClientEntityList::GetBaseEntityFromHandle(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CClientEntityList::GetBaseEntityFromHandle(CClientEntityList *this, CBaseHandle hEnt)
{
  int v2; // eax

  v2 = ((int (__thiscall *)(IClientEntityList *, unsigned int))this->GetClientUnknownFromHandle)(
         a1: &this->IClientEntityList,
         a2: hEnt.m_Index);
  if ( v2 != 0 )
    return (*(C_BaseEntity *(__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A3C50
// Name: public: class IClientThinkable __near * CClientEntityList::GetClientThinkableFromHandle(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__thiscall CClientEntityList::GetClientThinkableFromHandle(CClientEntityList *this, CBaseHandle hEnt)
{
  int v2; // eax

  v2 = ((int (__thiscall *)(IClientEntityList *, unsigned int))this->GetClientUnknownFromHandle)(
         a1: &this->IClientEntityList,
         a2: hEnt.m_Index);
  if ( v2 != 0 )
    return (*(IClientThinkable *(__thiscall **)(int))(*(_DWORD *)v2 + 32))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A3C90
// Name: public: class C_BaseEntity __near * CClientEntityList::FirstBaseEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CClientEntityList::FirstBaseEntity(CClientEntityList *this)
{
  CEntInfo *m_pHead; // esi
  C_BaseEntity *result; // eax

  m_pHead = this->m_activeList.m_pHead;
  if ( m_pHead == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( m_pHead->m_pEntity != nullptr )
    {
      result = (C_BaseEntity *)((int (__thiscall *)(IHandleEntity *))m_pHead->m_pEntity->__vftable[2].SetRefEHandle)(a1: m_pHead->m_pEntity);
      if ( result != nullptr )
        break;
    }
    m_pHead = m_pHead->m_pNext;
    if ( m_pHead == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3CC0
// Name: public: class C_BaseEntity __near * CClientEntityList::NextBaseEntity(class C_BaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CClientEntityList::NextBaseEntity(CClientEntityList *this, C_BaseEntity *pEnt)
{
  CEntInfo *m_pHead; // esi
  C_BaseEntity *result; // eax
  unsigned int m_Index; // eax
  CEntInfo *v6; // eax
  CEntInfo *m_pNext; // esi

  if ( pEnt == nullptr )
  {
    m_pHead = this->m_activeList.m_pHead;
    if ( m_pHead != nullptr )
    {
      while ( 1 )
      {
        if ( m_pHead->m_pEntity != nullptr )
        {
          result = (C_BaseEntity *)((int (__thiscall *)(IHandleEntity *))m_pHead->m_pEntity->__vftable[2].SetRefEHandle)(a1: m_pHead->m_pEntity);
          if ( result != nullptr )
            break;
        }
        m_pHead = m_pHead->m_pNext;
        if ( m_pHead == nullptr )
          return nullptr;
      }
      return result;
    }
    return nullptr;
  }
  m_Index = pEnt->GetRefEHandle(this: pEnt)->m_Index;
  if ( m_Index == -1 )
    m_Index = 0x1FFF;
  else
    m_Index = (unsigned __int16)m_Index;
  v6 = &this->m_EntPtrArray[m_Index];
  if ( v6 == nullptr )
    return nullptr;
  m_pNext = v6->m_pNext;
  if ( m_pNext == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( m_pNext->m_pEntity != nullptr )
    {
      result = (C_BaseEntity *)((int (__thiscall *)(IHandleEntity *))m_pNext->m_pEntity->__vftable[2].SetRefEHandle)(a1: m_pNext->m_pEntity);
      if ( result != nullptr )
        break;
    }
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3E50
// Name: public: void CClientEntityList::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::Release(CClientEntityList *this)
{
  CEntInfo *m_pHead; // eax
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  CEntInfo *v7; // eax

  m_pHead = this->m_activeList.m_pHead;
  if ( m_pHead != nullptr )
  {
    v3 = (((char *)m_pHead - (char *)this - 4) >> 4)
       | (this->m_EntPtrArray[((char *)m_pHead - (char *)this - 4) >> 4].m_SerialNumber << 16);
    while ( v3 != -1 )
    {
      v4 = ((int (__thiscall *)(IClientEntityList *, int))this->GetClientNetworkableFromHandle)(
             a1: &this->IClientEntityList,
             a2: v3);
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
      }
      else
      {
        v5 = ((int (__thiscall *)(IClientEntityList *, int))this->GetClientUnknownFromHandle)(
               a1: &this->IClientEntityList,
               a2: v3);
        if ( v5 != 0 )
        {
          v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 32))(a1: v5);
          if ( v6 != 0 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 16))(a1: v6);
        }
      }
      CBaseEntityList::RemoveEntity(this, handle: (CBaseHandle)v3);
      v7 = this->m_activeList.m_pHead;
      if ( v7 != nullptr )
        v3 = (((char *)v7 - (char *)this - 4) >> 4)
           | (this->m_EntPtrArray[((char *)v7 - (char *)this - 4) >> 4].m_SerialNumber << 16);
      else
        v3 = -1;
    }
  }
  this->m_iNumServerEnts = 0;
  this->m_iMaxServerEnts = 0;
  this->m_iNumClientNonNetworkable = 0;
  this->m_iMaxUsedServerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100A3F40
// Name: public: C_BaseEntityIterator::C_BaseEntityIterator(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntityIterator *__thiscall C_BaseEntityIterator::C_BaseEntityIterator(C_BaseEntityIterator *this)
{
  this->m_CurBaseEntity = *(unsigned __int16 *)(cl_entitylist.m_Index + 196680);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A43E0
// Name: public: class C_BaseEntity __near * C_BaseEntityIterator::Next(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntityIterator::Next(C_BaseEntityIterator *this)
{
  int m_CurBaseEntity; // ecx
  int v3; // eax
  int v4; // edi

  if ( this->m_CurBaseEntity == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    m_CurBaseEntity = this->m_CurBaseEntity;
    v3 = *(_DWORD *)(cl_entitylist.m_Index + 196668);
    v4 = *(_DWORD *)(v3 + 8 * m_CurBaseEntity);
    this->m_CurBaseEntity = *(unsigned __int16 *)(v3 + 8 * m_CurBaseEntity + 6);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(v4 + 8) + 36))(a1: v4 + 8) == 0 )
      break;
    if ( this->m_CurBaseEntity == 0xFFFF )
      return nullptr;
  }
  return (C_BaseEntity *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A57F0
// Name: public: void CClientEntityList::AddListenerEntity(class IClientEntityListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::AddListenerEntity(CClientEntityList *this, IClientEntityListener *pListener)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_entityListeners; // esi
  int m_Size; // ecx
  int v4; // eax
  IClientEntityListener **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_entityListeners = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_entityListeners;
  m_Size = this->m_entityListeners.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IClientEntityListener **)p_m_entityListeners->m_pMemory;
  while ( *m_pMemory != pListener )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 < 0 )
  {
LABEL_7:
    m_nAllocationCount = p_m_entityListeners->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_entityListeners, num: m_Size - m_nAllocationCount + 1);
    ++p_m_entityListeners[1].m_pMemory;
    v8 = p_m_entityListeners->m_pMemory;
    v9 = (int)p_m_entityListeners[1].m_pMemory - v7 - 1;
    p_m_entityListeners[1].m_nAllocationCount = (int)p_m_entityListeners->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_entityListeners->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pListener;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5BB0
// Name: public: virtual CClientEntityList::~CClientEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::~CClientEntityList(CClientEntityList *this)
{
  this->CBaseEntityList::__vftable = (CClientEntityList_vtbl *)&CClientEntityList::`vftable'{for `CBaseEntityList'};
  this->IClientEntityList::__vftable = (IClientEntityList_vtbl *)&CClientEntityList::`vftable'{for `IClientEntityList'};
  CClientEntityList::Release(this);
  CUtlRBTree<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short,CUtlMap<IClientUnknown *,unsigned short,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short,CUtlMap<IClientUnknown *,unsigned short,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_PVSNotifierMap.m_Tree);
  CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)&this->m_PVSNotifyInfos);
  if ( this->m_PVSNotifyInfos.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PVSNotifyInfos.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PVSNotifyInfos.m_Memory.m_pMemory);
      this->m_PVSNotifyInfos.m_Memory.m_pMemory = nullptr;
    }
    this->m_PVSNotifyInfos.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_BaseEntities);
  if ( this->m_BaseEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BaseEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BaseEntities.m_Memory.m_pMemory);
      this->m_BaseEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_BaseEntities.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_entityListeners);
  CBaseEntityList::~CBaseEntityList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A5C70
// Name: public: virtual class IClientUnknown __near * CClientEntityList::GetClientUnknownFromHandle(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
IClientUnknown *__thiscall CClientEntityList::GetClientUnknownFromHandle(CClientEntityList *this, CBaseHandle hEnt)
{
  if ( hEnt.m_Index == -1
    || this->m_EntPtrArray[LOWORD(hEnt.m_Index) - 8193].m_pEntity != (IHandleEntity *)HIWORD(hEnt.m_Index) )
  {
    return nullptr;
  }
  else
  {
    return *((IClientUnknown **)this + 4 * LOWORD(hEnt.m_Index) - 32772);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5D10
// Name: public: CClientEntityList::CClientEntityList(void)
// Source: json
//------------------------------------------------------------------------------
CClientEntityList *__thiscall CClientEntityList::CClientEntityList(CClientEntityList *this)
{
  UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short> *m_pMemory; // edx

  CBaseEntityList::CBaseEntityList(this);
  this->IClientEntityList::__vftable = (IClientEntityList_vtbl *)&IClientEntityList::`vftable';
  this->CBaseEntityList::__vftable = (CClientEntityList_vtbl *)&CClientEntityList::`vftable'{for `CBaseEntityList'};
  this->IClientEntityList::__vftable = (IClientEntityList_vtbl *)&CClientEntityList::`vftable'{for `IClientEntityList'};
  this->m_entityListeners.m_Memory.m_pMemory = nullptr;
  this->m_entityListeners.m_Memory.m_nAllocationCount = 0;
  this->m_entityListeners.m_Memory.m_nGrowSize = 0;
  this->m_entityListeners.m_Size = 0;
  this->m_entityListeners.m_pElements = nullptr;
  this->m_BaseEntities.m_Memory.m_pMemory = nullptr;
  this->m_BaseEntities.m_Memory.m_nAllocationCount = 0;
  this->m_BaseEntities.m_Memory.m_nGrowSize = 0;
  this->m_BaseEntities.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_BaseEntities.m_FirstFree = 0xFFFF;
  this->m_BaseEntities.m_pElements = this->m_BaseEntities.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_BaseEntities.m_Head = -1;
  this->m_BaseEntities.m_NumAlloced = 0;
  this->m_PVSNotifyInfos.m_Memory.m_pMemory = nullptr;
  this->m_PVSNotifyInfos.m_Memory.m_nAllocationCount = 0;
  this->m_PVSNotifyInfos.m_Memory.m_nGrowSize = 0;
  this->m_PVSNotifyInfos.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_PVSNotifyInfos.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_PVSNotifyInfos.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_PVSNotifyInfos.m_Head = -1;
  this->m_PVSNotifyInfos.m_pElements = m_pMemory;
  this->m_PVSNotifyInfos.m_NumAlloced = 0;
  this->m_PVSNotifierMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(IClientUnknown *const *, IClientUnknown *const *))CDefOps<C_BaseEntity *>::LessFunc;
  this->m_PVSNotifierMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PVSNotifierMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PVSNotifierMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PVSNotifierMap.m_Tree.m_pElements = this->m_PVSNotifierMap.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_PVSNotifierMap.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_PVSNotifierMap.m_Tree.m_FirstFree = -1;
  this->m_iMaxUsedServerIndex = -1;
  this->m_iMaxServerEnts = 0;
  CClientEntityList::Release(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A5EB0
// Name: private: void CClientEntityList::AddPVSNotifier(class IClientUnknown __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::AddPVSNotifier(CClientEntityList *this, IClientUnknown *pUnknown)
{
  IClientRenderable *v3; // ebx
  unsigned __int16 v4; // ax
  const char *v5; // edi
  unsigned __int16 v6; // cx
  IPVSNotify *v7; // edx
  UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short> *v8; // eax
  CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t insert; // [esp+Ch] [ebp-8h] BYREF

  v3 = pUnknown->GetClientRenderable(this: pUnknown);
  if ( v3 != nullptr )
  {
    *(_DWORD *)&insert.elem = v3->GetPVSNotifyInterface(this: v3);
    if ( *(_DWORD *)&insert.elem != 0 )
    {
      v4 = CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short>>::AllocInternal(
             this: &this->m_PVSNotifyInfos,
             multilist: false);
      v5 = (const char *)v4;
      if ( v4 == 0xFFFF )
      {
        v6 = -1;
      }
      else
      {
        CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::LinkBefore(
          this: (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)&this->m_PVSNotifyInfos,
          before: 0xFFFFu,
          elem: v4);
        v6 = (unsigned __int16)v5;
      }
      v7 = *(IPVSNotify **)&insert.elem;
      v8 = &this->m_PVSNotifyInfos.m_Memory.m_pMemory[v6];
      insert.elem = v6;
      v8->m_Element.m_PVSNotifiersLink = v6;
      v8->m_Element.m_pNotify = v7;
      v8->m_Element.m_pRenderable = v3;
      v8->m_Element.m_InPVSStatus = 0;
      insert.key = pUnknown;
      CUtlRBTree<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short,CUtlMap<IClientUnknown *,unsigned short,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        this: &this->m_PVSNotifierMap.m_Tree,
        a2: v5,
        &insert);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5F50
// Name: private: void CClientEntityList::RemovePVSNotifier(class IClientUnknown __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::RemovePVSNotifier(CClientEntityList *this, IClientUnknown *pUnknown)
{
  IClientRenderable *(__thiscall *GetClientRenderable)(IClientUnknown *); // edx
  int v4; // eax
  CUtlMap<IClientUnknown *,unsigned short,unsigned short> *p_m_PVSNotifierMap; // ebx
  int v6; // edi
  CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short> > *p_m_PVSNotifyInfos; // esi
  CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF
  CClientEntityList *v9; // [esp+10h] [ebp-4h]
  unsigned __int16 indexIntoPVSNotifyInfos; // [esp+1Ch] [ebp+8h]

  GetClientRenderable = pUnknown->GetClientRenderable;
  v9 = this;
  v4 = (int)GetClientRenderable(this: pUnknown);
  if ( v4 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 64))(a1: v4) != 0 )
  {
    p_m_PVSNotifierMap = &this->m_PVSNotifierMap;
    search.key = pUnknown;
    v6 = CUtlRBTree<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short,CUtlMap<IClientUnknown *,unsigned short,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &p_m_PVSNotifierMap->m_Tree,
           &search);
    if ( v6 >= p_m_PVSNotifierMap->m_Tree.m_Elements.m_nAllocationCount
      || (unsigned __int16)v6 > p_m_PVSNotifierMap->m_Tree.m_LastAlloc.index
      || CUtlRBTree<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short,CUtlMap<IClientUnknown *,unsigned short,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_PVSNotifierMap->m_Tree,
           i: v6) == (_WORD)v6 )
    {
      _Warning(a1: "PVS notifier not in m_PVSNotifierMap\n");
    }
    else
    {
      p_m_PVSNotifyInfos = &v9->m_PVSNotifyInfos;
      indexIntoPVSNotifyInfos = v9->m_PVSNotifierMap.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
      CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)&v9->m_PVSNotifyInfos,
        elem: indexIntoPVSNotifyInfos);
      p_m_PVSNotifyInfos->m_Memory.m_pMemory[indexIntoPVSNotifyInfos].m_Next = p_m_PVSNotifyInfos->m_FirstFree;
      p_m_PVSNotifyInfos->m_FirstFree = indexIntoPVSNotifyInfos;
      CUtlMap<IClientUnknown *,unsigned short,unsigned short>::RemoveAt(this: p_m_PVSNotifierMap, i: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6020
// Name: protected: virtual void CClientEntityList::OnAddEntity(class IHandleEntity __near *,class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::OnAddEntity(CClientEntityList *this, C_BaseEntity *pEnt, CBaseHandle handle)
{
  unsigned int m_Index_low; // edi
  unsigned __int16 v5; // ax
  int v6; // edi
  C_BaseEntity *v7; // ebx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<C_BaseEntity *,unsigned short> *v9; // eax
  int i; // edi
  IClientEntityListener *v11; // ecx
  int entnum; // [esp+Ch] [ebp-4h]
  C_BaseEntity *pBaseEntity; // [esp+18h] [ebp+8h]

  if ( handle.m_Index == -1 )
  {
    m_Index_low = 0x1FFF;
    entnum = 0x1FFF;
  }
  else
  {
    entnum = LOWORD(handle.m_Index);
    m_Index_low = LOWORD(handle.m_Index);
  }
  if ( m_Index_low <= 0x7FF )
  {
    ++this->m_iNumServerEnts;
    if ( (signed int)m_Index_low > this->m_iMaxUsedServerIndex )
      this->m_iMaxUsedServerIndex = m_Index_low;
    this->m_EntityCacheInfo[m_Index_low].m_pNetworkable = pEnt->GetClientNetworkable(this: pEnt);
    this->m_EntityCacheInfo[m_Index_low].m_bDormant = 1;
  }
  CClientEntityList::AddPVSNotifier(this, pUnknown: pEnt);
  pBaseEntity = pEnt->GetBaseEntity(this: pEnt);
  if ( pBaseEntity != nullptr )
  {
    v5 = CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_BaseEntities,
           multilist: false);
    v6 = v5;
    if ( v5 == 0xFFFF )
    {
      v7 = pBaseEntity;
      v8 = -1;
    }
    else
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_BaseEntities,
        before: 0xFFFFu,
        elem: v5);
      v7 = pBaseEntity;
      v9 = &this->m_BaseEntities.m_Memory.m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_Element = pBaseEntity;
      v8 = v6;
    }
    this->m_EntityCacheInfo[entnum].m_BaseEntitiesIndex = v8;
    if ( (v7->ObjectCaps(this: v7) & 0x400) != 0 )
      ++this->m_iNumClientNonNetworkable;
    for ( i = this->m_entityListeners.m_Size - 1; i >= 0; --i )
    {
      v11 = this->m_entityListeners.m_Memory.m_pMemory[i];
      v11->OnEntityCreated(this: v11, a2: v7);
    }
  }
  else
  {
    this->m_EntityCacheInfo[m_Index_low].m_BaseEntitiesIndex = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6150
// Name: protected: virtual void CClientEntityList::OnRemoveEntity(class IHandleEntity __near *,class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEntityList::OnRemoveEntity(CClientEntityList *this, IClientUnknown *pEnt, CBaseHandle handle)
{
  int m_Index_low; // edi
  int v5; // ebx
  int i; // edi
  IClientEntityListener *v7; // ecx
  unsigned __int16 m_BaseEntitiesIndex; // ax
  unsigned __int16 *p_m_BaseEntitiesIndex; // ebx
  int v10; // edi
  int entnum; // [esp+Ch] [ebp-4h]

  if ( handle.m_Index == -1 )
  {
    m_Index_low = 0x1FFF;
    entnum = 0x1FFF;
  }
  else
  {
    entnum = LOWORD(handle.m_Index);
    m_Index_low = LOWORD(handle.m_Index);
  }
  if ( (unsigned int)m_Index_low <= 0x7FF )
  {
    this->m_EntityCacheInfo[m_Index_low].m_pNetworkable = nullptr;
    --this->m_iNumServerEnts;
    if ( m_Index_low >= this->m_iMaxUsedServerIndex )
      CClientEntityList::RecomputeHighestEntityUsed(this);
  }
  CClientEntityList::RemovePVSNotifier(this, pUnknown: pEnt);
  v5 = (int)pEnt->GetBaseEntity(this: pEnt);
  if ( v5 != 0 )
  {
    if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 240))(a1: v5) & 0x400) != 0 )
      --this->m_iNumClientNonNetworkable;
    for ( i = this->m_entityListeners.m_Size - 1; i >= 0; --i )
    {
      v7 = this->m_entityListeners.m_Memory.m_pMemory[i];
      v7->OnEntityDeleted(this: v7, a2: (C_BaseEntity *)v5);
    }
    m_Index_low = entnum;
  }
  m_BaseEntitiesIndex = this->m_EntityCacheInfo[m_Index_low].m_BaseEntitiesIndex;
  p_m_BaseEntitiesIndex = &this->m_EntityCacheInfo[m_Index_low].m_BaseEntitiesIndex;
  if ( m_BaseEntitiesIndex != 0xFFFF )
  {
    v10 = this->m_EntityCacheInfo[m_Index_low].m_BaseEntitiesIndex;
    CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_BaseEntities,
      elem: m_BaseEntitiesIndex);
    this->m_BaseEntities.m_Memory.m_pMemory[v10].m_Next = this->m_BaseEntities.m_FirstFree;
    this->m_BaseEntities.m_FirstFree = v10;
  }
  *p_m_BaseEntitiesIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100A6260
// Name: __CreateCClientLeafSystemIClientLeafSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientLeafSystem *__cdecl _CreateCClientLeafSystemIClientLeafSystem_interface()
{
  return &CClientLeafSystem::s_ClientLeafSystem;
}

//------------------------------------------------------------------------------
// Address: 0x100A6270
// Name: __CreateCClientLeafSystemIClientAlphaPropertyMgr_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientAlphaPropertyMgr *__cdecl _CreateCClientLeafSystemIClientAlphaPropertyMgr_interface()
{
  return &CClientLeafSystem::s_ClientLeafSystem.IClientAlphaPropertyMgr;
}
