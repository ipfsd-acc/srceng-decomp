// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gamegraphic.cpp
// Functions: 31
// ============================================================

#include "vgui2\game_controls\gamegraphic.h"

//------------------------------------------------------------------------------
// Address: 0x0040CFA0
// Name: public: unsigned short CUtlMap<class CUtlString,void __near *,unsigned short>::Find(class CUtlString const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,void *,unsigned short>::Find(
        CUtlMap<CUtlString,void *,unsigned short> *this,
        const CUtlString *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CUtlString,void *,unsigned short>::Node_t dummyNode; // [esp+0h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v3 = CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: (const CUtlMap<CUtlString,void *,unsigned short>::Node_t *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  dummyNode.elem = nullptr;
  if ( dummyNode.key.m_Storage.m_nActualLength >= 0 && dummyNode.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040D000
// Name: public: unsigned short CUtlMap<class CUtlString,class IGameUIScreenControllerFactory __near *,unsigned short>::Find(class CUtlString const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Find(
        CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short> *this,
        const CUtlString *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t dummyNode; // [esp+0h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v3 = CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: (const CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  dummyNode.elem = nullptr;
  if ( dummyNode.key.m_Storage.m_nActualLength >= 0 && dummyNode.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040D060
// Name: public: unsigned short CUtlMap<class CUtlString,class IGameUIGraphicClassFactory __near *,unsigned short>::Find(class CUtlString const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Find(
        CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short> *this,
        const CUtlString *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t dummyNode; // [esp+0h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v3 = CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: (const CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  dummyNode.elem = nullptr;
  if ( dummyNode.key.m_Storage.m_nActualLength >= 0 && dummyNode.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040DD60
// Name: public: unsigned short CUtlMap<class CUtlString,void __near *,unsigned short>::Insert(class CUtlString const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,void *,unsigned short>::Insert(
        CUtlMap<CUtlString,void *,unsigned short> *this,
        const CUtlString *key,
        void *const *insert)
{
  unsigned __int16 v4; // si
  CUtlMap<CUtlString,void *,unsigned short>::Node_t node; // [esp+0h] [ebp-18h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  CUtlString::CUtlString(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v7 = (int)*insert;
  v4 = CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: (const CUtlMap<CUtlString,void *,unsigned short>::Node_t *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  node.elem = nullptr;
  if ( node.key.m_Storage.m_nActualLength >= 0 && node.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)node.key.m_Storage.m_Memory.m_nAllocationCount);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040DDD0
// Name: public: unsigned short CUtlMap<class CUtlString,class IGameUIScreenControllerFactory __near *,unsigned short>::Insert(class CUtlString const __near &,class IGameUIScreenControllerFactory __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Insert(
        CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short> *this,
        const CUtlString *key,
        IGameUIScreenControllerFactory *const *insert)
{
  unsigned __int16 v4; // si
  CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t node; // [esp+0h] [ebp-18h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  CUtlString::CUtlString(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v7 = (int)*insert;
  v4 = CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: (const CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  node.elem = nullptr;
  if ( node.key.m_Storage.m_nActualLength >= 0 && node.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)node.key.m_Storage.m_Memory.m_nAllocationCount);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040DE40
// Name: public: unsigned short CUtlMap<class CUtlString,class IGameUIGraphicClassFactory __near *,unsigned short>::Insert(class CUtlString const __near &,class IGameUIGraphicClassFactory __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Insert(
        CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short> *this,
        const CUtlString *key,
        IGameUIGraphicClassFactory *const *insert)
{
  unsigned __int16 v4; // si
  CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t node; // [esp+0h] [ebp-18h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  CUtlString::CUtlString(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v7 = (int)*insert;
  v4 = CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: (const CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  node.elem = nullptr;
  if ( node.key.m_Storage.m_nActualLength >= 0 && node.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)node.key.m_Storage.m_Memory.m_nAllocationCount);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041F920
// Name: public: bool CUtlMap<int,class CGameUISystem __near *,unsigned short>::Remove(int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<int,CGameUISystem *,unsigned short>::Remove(
        CUtlMap<int,CGameUISystem *,unsigned short> *this,
        CGameUISystem **key)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  int v5; // eax
  CUtlMap<int,CGameUISystem *,unsigned short>::Node_t dummyNode; // [esp+4h] [ebp-Ch] BYREF

  dummyNode.elem = *key;
  v3 = CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: (const CUtlMap<int,CGameUISystem *,unsigned short>::Node_t *)&dummyNode.elem);
  v4 = v3;
  if ( v3 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v3);
  v5 = v4;
  this->m_Tree.m_Elements.m_pMemory[v5].m_Left = v4;
  this->m_Tree.m_Elements.m_pMemory[v5].m_Right = this->m_Tree.m_FirstFree;
  --this->m_Tree.m_NumElements;
  this->m_Tree.m_FirstFree = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F9A0
// Name: public: unsigned short CUtlMap<int,class CGameUISystem __near *,unsigned short>::InsertOrReplace(int const __near &,class CGameUISystem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<int,CGameUISystem *,unsigned short>::InsertOrReplace(
        CUtlMap<int,CGameUISystem *,unsigned short> *this,
        int *key,
        CGameUISystem **insert)
{
  unsigned __int16 result; // ax
  CGameUISystem *v5; // ecx
  CUtlMap<int,CGameUISystem *,unsigned short>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  search.key = *key;
  result = CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_Tree,
             &search);
  if ( result == 0xFFFF )
  {
    v5 = *insert;
    search.key = *key;
    search.elem = v5;
    return CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
             this: &this->m_Tree,
             insert: &search);
  }
  else
  {
    this->m_Tree.m_Elements.m_pMemory[result].m_Data.elem = *insert;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424080
// Name: public: class DmeTime_t CGameGraphic::GetAnimationTimePassed(void)
// Source: json
//------------------------------------------------------------------------------
DmeTime_t *__thiscall CGameGraphic::GetAnimationTimePassed(CGameGraphic *this, DmeTime_t *result)
{
  int m_tms; // edi
  DmeTime_t v5; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_Geometry.m_bAnimate )
  {
    m_tms = this->m_Geometry.m_AnimStartTime.m_tms;
    this->m_flAnimTime.m_tms = CGameUISystemMgr::GetTime(this: g_pGameUISystemMgrImpl, result: &v5)->m_tms - m_tms;
  }
  result->m_tms = (int)this->m_flAnimTime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004240C0
// Name: public: virtual void CGameGraphic::UpdateRenderData(struct color32_s,class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::UpdateRenderData(
        CGameGraphic *this,
        color32_s parentColor,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  CGeometry *p_m_Geometry; // esi

  if ( this->m_Geometry.m_bVisible )
  {
    p_m_Geometry = &this->m_Geometry;
    CGeometry::SetResultantColor(this: &this->m_Geometry, parentColor);
    CGeometry::UpdateRenderData(this: p_m_Geometry, renderGeometryLists, firstListIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004240F0
// Name: public: virtual void CGameGraphic::DrawExtents(class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::DrawExtents(
        CGameGraphic *this,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  CGeometry::DrawExtents(
    this: &this->m_Geometry,
    renderGeometryLists,
    firstListIndex,
    extentLineColor: (color32_s)-16711936);
}

//------------------------------------------------------------------------------
// Address: 0x00424120
// Name: public: virtual void CGameGraphic::UpdateRenderTransforms(struct StageRenderInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::UpdateRenderTransforms(CGameGraphic *this, const StageRenderInfo_t *stageRenderInfo)
{
  CGeometry::UpdateRenderTransforms(this: &this->m_Geometry, stageRenderInfo, pGroup: this->m_pGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00424140
// Name: public: virtual void CGameGraphic::StartPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::StartPlaying(CGameGraphic *this)
{
  DmeTime_t result; // [esp+4h] [ebp-4h] BYREF

  this->m_Geometry.m_bAnimate = true;
  this->m_Geometry.m_AnimStartTime = (DmeTime_t)CGameUISystemMgr::GetTime(this: g_pGameUISystemMgrImpl, &result)->m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00424170
// Name: public: virtual void CGameGraphic::StopPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::StopPlaying(CGameGraphic *this)
{
  this->m_Geometry.m_bAnimate = false;
}

//------------------------------------------------------------------------------
// Address: 0x00424180
// Name: public: bool CGameGraphic::IsGraphicNamed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameGraphic::IsGraphicNamed(CGameGraphic *this, const char *pName)
{
  const char *v2; // eax

  v2 = CUtlString::Get(this: &this->m_pName);
  return _V_stricmp(s1: v2, s2: pName) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004241B0
// Name: public: virtual void CGameGraphic::AdvanceState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::AdvanceState(CGameGraphic *this)
{
  int m_Size; // ecx
  int v3; // eax

  this->StopPlaying(this);
  m_Size = this->m_Anims.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_CurrentState + 1;
    if ( v3 > m_Size - 1 )
      v3 = 0;
    this->m_CurrentState = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424240
// Name: public: bool CGameGraphic::IsDonePlaying(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameGraphic::IsDonePlaying(CGameGraphic *this)
{
  int m_tms; // edi
  DmeTime_t v4; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_CurrentState == -1 )
    return true;
  if ( this->m_Geometry.m_bAnimate )
  {
    m_tms = this->m_Geometry.m_AnimStartTime.m_tms;
    this->m_flAnimTime.m_tms = CGameUISystemMgr::GetTime(this: g_pGameUISystemMgrImpl, result: &v4)->m_tms - m_tms;
  }
  return CAnimData::IsDone(this: this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState], time: this->m_flAnimTime);
}

//------------------------------------------------------------------------------
// Address: 0x004242A0
// Name: protected: int CGameGraphic::GetStateIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameGraphic::GetStateIndex(CGameGraphic *this, const char *pStateName)
{
  int i; // esi
  const char *v5; // eax
  const char *v6; // eax

  while ( 2 )
  {
    for ( i = 0; ; ++i )
    {
      if ( i >= this->m_Anims.m_Size )
        return -1;
      v5 = CUtlString::operator char const *(this: &this->m_Anims.m_Memory.m_pMemory[i]->m_pStateName);
      if ( _V_stricmp(s1: pStateName, s2: v5) == 0 )
        break;
    }
    v6 = CUtlString::operator char const *(this: &this->m_Anims.m_Memory.m_pMemory[i]->m_pAnimAlias);
    if ( _V_stricmp(s1: v6, s2: defaultValue) != 0 )
    {
      pStateName = CUtlString::operator char const *(this: &this->m_Anims.m_Memory.m_pMemory[i]->m_pAnimAlias);
      continue;
    }
    break;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00424340
// Name: public: char const __near * CGameGraphic::GetState(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameGraphic::GetState(CGameGraphic *this)
{
  int m_CurrentState; // eax
  const char *v4; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == -1 )
    return defaultValue;
  v4 = CUtlString::operator char const *(this: &this->m_Anims.m_Memory.m_pMemory[m_CurrentState]->m_pAnimAlias);
  if ( _V_stricmp(s1: v4, s2: defaultValue) != 0 )
    return CUtlString::operator char const *(this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_pAnimAlias);
  else
    return CUtlString::operator char const *(this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_pStateName);
}

//------------------------------------------------------------------------------
// Address: 0x004247C0
// Name: public: virtual class KeyValues __near * CGameGraphic::HandleScriptCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CGameGraphic::HandleScriptCommand(CGameGraphic *this, KeyValues *args)
{
  KeyValues *v2; // edi
  const char *Name; // ebx
  CGameGraphic_vtbl *v5; // ebx
  CGameGraphic_vtbl *v7; // ebx
  int Int; // eax
  void (__thiscall *SetVisible)(CGameGraphic *, bool); // edx
  KeyValues *v10; // eax
  void (__thiscall *SetColor)(CGameGraphic *, color32_s); // edx
  int v12; // eax
  CGameGraphic_vtbl *v13; // ebx
  const char *String; // eax
  KeyValues *v15; // edi
  const char *State; // eax
  KeyValues *v17; // edi
  bool IsDonePlaying; // al
  const char *v19; // eax
  float Float; // [esp+4h] [ebp-18h]
  float v21; // [esp+4h] [ebp-18h]
  float defaultValue; // [esp+8h] [ebp-14h]
  float defaultValuea; // [esp+8h] [ebp-14h]
  KeyValues *defaultValueb; // [esp+8h] [ebp-14h]
  float defaultValuec; // [esp+8h] [ebp-14h]
  Color v26; // [esp+18h] [ebp-4h] BYREF

  v2 = args;
  Name = KeyValues::GetName(this: args);
  if ( _V_stricmp(s1: "SetCenter", s2: Name) == 0 )
  {
    v5 = this->__vftable;
    defaultValue = KeyValues::GetFloat(this: v2, keyName: "y", defaultValue: 0.0);
    Float = KeyValues::GetFloat(this: v2, keyName: "x", defaultValue: 0.0);
    ((void (__thiscall *)(CGameGraphic *, _DWORD, _DWORD))v5->SetCenter)(
      a1: this,
      a2: LODWORD(Float),
      a3: LODWORD(defaultValue));
    return nullptr;
  }
  if ( _V_stricmp(s1: "SetScale", s2: Name) == 0 )
  {
    v7 = this->__vftable;
    defaultValuea = KeyValues::GetFloat(this: v2, keyName: "y", defaultValue: 0.0);
    v21 = KeyValues::GetFloat(this: v2, keyName: "x", defaultValue: 0.0);
    ((void (__thiscall *)(CGameGraphic *, _DWORD, _DWORD))v7->SetScale)(
      a1: this,
      a2: LODWORD(v21),
      a3: LODWORD(defaultValuea));
    return nullptr;
  }
  if ( _V_stricmp(s1: "SetRotation", s2: Name) == 0 )
  {
    this->m_Geometry.m_Rotation = KeyValues::GetFloat(this: v2, keyName: "rotation", defaultValue: 0.0);
    return nullptr;
  }
  if ( _V_stricmp(s1: "SetVisible", s2: Name) == 0 )
  {
    Int = KeyValues::GetInt(this: v2, keyName: "visible", defaultValue: 1);
    SetVisible = this->SetVisible;
    LOBYTE(args) = Int != 0;
    SetVisible(this, a2: (bool)args);
    return nullptr;
  }
  if ( _V_stricmp(s1: "GetVisible", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "SetHorizGradient", s2: Name) == 0 )
    {
      this->m_Geometry.m_bHorizontalGradient = KeyValues::GetInt(this: v2, keyName: "horizgradient", defaultValue: 1) != 0;
      return nullptr;
    }
    if ( _V_stricmp(s1: "SetColor", s2: Name) == 0 )
    {
      LOWORD(args) = -1;
      BYTE2(args) = -1;
      HIBYTE(args) = -1;
      KeyValues::GetColor(this: v2, result: &v26, keyName: "color", defaultColor: (const Color *)&args);
      LOWORD(args) = *(_WORD *)v26._color;
      BYTE2(args) = v26._color[2];
      SetColor = this->SetColor;
      HIBYTE(args) = v26._color[3];
      ((void (__thiscall *)(CGameGraphic *, KeyValues *))SetColor)(a1: this, a2: args);
      return nullptr;
    }
    if ( _V_stricmp(s1: "SetState", s2: Name) == 0 )
    {
      v12 = KeyValues::GetInt(this: v2, keyName: "play", defaultValue: 1);
      v13 = this->__vftable;
      LOBYTE(args) = v12 != 0;
      defaultValueb = args;
      String = KeyValues::GetString(this: v2, keyName: "state", defaultValue: ::defaultValue);
      v13->SetState(this, a2: String, a3: (bool)defaultValueb);
      defaultValuec = KeyValues::GetFloat(this: v2, keyName: "time", defaultValue: 0.0);
      this->m_flAnimTime = (DmeTime_t)DmeTime_t::DmeTime_t(this: (DmeTime_t *)&args, sec: defaultValuec)->m_tms;
      return nullptr;
    }
    if ( _V_stricmp(s1: "GetState", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "IsDonePlaying", s2: Name) != 0 )
      {
        v19 = KeyValues::GetName(this: v2);
        DevWarning(a1: "CGameGraphic::HandleScriptCommand for unknown command %s!\n", v19);
      }
      else
      {
        v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v17 != nullptr )
        {
          IsDonePlaying = CGameGraphic::IsDonePlaying(this);
          return KeyValues::KeyValues(this: v17, setName: ::defaultValue, firstKey: "done", firstValue: IsDonePlaying);
        }
      }
    }
    else
    {
      v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v15 != nullptr )
      {
        State = CGameGraphic::GetState(this);
        return KeyValues::KeyValues(this: v15, setName: ::defaultValue, firstKey: "state", firstValue: State);
      }
    }
  }
  else
  {
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      return KeyValues::KeyValues(
               this: v10,
               setName: ::defaultValue,
               firstKey: "visible",
               firstValue: this->m_Geometry.m_bVisible);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00424B00
// Name: public: virtual bool CGameGraphic::HasState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameGraphic::HasState(CGameGraphic *this, const char *pStateName)
{
  return CGameGraphic::GetStateIndex(this, pStateName) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x00424B20
// Name: public: virtual void CGameGraphic::SetState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::SetState(CGameGraphic *this, const char *pStateName, bool bStartPlaying)
{
  int StateIndex; // eax

  StateIndex = CGameGraphic::GetStateIndex(this, pStateName);
  if ( StateIndex == -1 || this->m_CurrentState == StateIndex )
  {
LABEL_5:
    if ( bStartPlaying )
      return;
    goto LABEL_6;
  }
  this->m_CurrentState = StateIndex;
  if ( bStartPlaying )
  {
    this->StartPlaying(this);
    goto LABEL_5;
  }
LABEL_6:
  this->StopPlaying(this);
}

//------------------------------------------------------------------------------
// Address: 0x00426090
// Name: public: static class CGameGraphic __near * CGameGraphic::FromScriptHandle(int)
// Source: json
//------------------------------------------------------------------------------
CGameGraphic *__cdecl CGameGraphic::FromScriptHandle(int iScriptHandle)
{
  unsigned __int16 v1; // ax
  CUtlMap<int,CGameGraphic *,unsigned short>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  search.key = iScriptHandle;
  v1 = CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_mapScriptHandles_0.m_Tree,
         &search);
  if ( v1 == 0xFFFF )
    return nullptr;
  else
    return g_mapScriptHandles_0.m_Tree.m_Elements.m_pMemory[v1].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x004261B0
// Name: public: virtual CGameGraphic::~CGameGraphic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::~CGameGraphic(CGameGraphic *this)
{
  CGraphicGroup *m_pGroup; // ecx
  int m_Size; // eax
  int v4; // edi
  CAnimData **m_pMemory; // ecx
  CAnimData *v6; // ebp
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // di
  int v9; // eax
  bool v10; // sf
  CAnimData **v11; // eax
  CTriangle *v12; // eax
  color32_s *v13; // eax
  Vector2D *v14; // eax
  Vector2D *v15; // eax
  CUtlMap<int,CGameGraphic *,unsigned short>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  m_pGroup = this->m_pGroup;
  this->__vftable = (CGameGraphic_vtbl *)&CGameGraphic::`vftable';
  if ( m_pGroup != nullptr )
    CGraphicGroup::RemoveFromGroup(this: m_pGroup, pGraphic: this);
  m_Size = this->m_Anims.m_Size;
  v4 = 0;
  for ( search.key = m_Size; v4 < m_Size; ++v4 )
  {
    m_pMemory = this->m_Anims.m_Memory.m_pMemory;
    v6 = m_pMemory[v4];
    if ( v6 != nullptr )
    {
      CAnimData::~CAnimData(this: m_pMemory[v4]);
      free(pMem: v6);
      m_Size = search.key;
    }
    this->m_Anims.m_Memory.m_pMemory[v4] = nullptr;
  }
  this->m_Anims.m_Size = 0;
  search.key = this->m_iScriptHandle;
  v7 = CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_mapScriptHandles_0.m_Tree,
         &search);
  v8 = v7;
  if ( v7 != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &g_mapScriptHandles_0.m_Tree,
      elem: v7);
    v9 = v8;
    g_mapScriptHandles_0.m_Tree.m_Elements.m_pMemory[v9].m_Left = v8;
    g_mapScriptHandles_0.m_Tree.m_Elements.m_pMemory[v9].m_Right = g_mapScriptHandles_0.m_Tree.m_FirstFree;
    --g_mapScriptHandles_0.m_Tree.m_NumElements;
    g_mapScriptHandles_0.m_Tree.m_FirstFree = v8;
  }
  v10 = this->m_Anims.m_Memory.m_nGrowSize < 0;
  this->m_Anims.m_Size = 0;
  if ( !v10 )
  {
    if ( this->m_Anims.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Anims.m_Memory.m_pMemory);
      this->m_Anims.m_Memory.m_pMemory = nullptr;
    }
    this->m_Anims.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Anims.m_Memory.m_nGrowSize < 0;
  v11 = this->m_Anims.m_Memory.m_pMemory;
  this->m_Anims.m_pElements = v11;
  if ( !v10 )
  {
    if ( v11 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      this->m_Anims.m_Memory.m_pMemory = nullptr;
    }
    this->m_Anims.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_Triangles.m_Memory.m_nGrowSize < 0;
  this->m_Geometry.m_Triangles.m_Size = 0;
  if ( !v10 )
  {
    if ( this->m_Geometry.m_Triangles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Geometry.m_Triangles.m_Memory.m_pMemory);
      this->m_Geometry.m_Triangles.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_Triangles.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_Triangles.m_Memory.m_nGrowSize < 0;
  v12 = this->m_Geometry.m_Triangles.m_Memory.m_pMemory;
  this->m_Geometry.m_Triangles.m_pElements = v12;
  if ( !v10 )
  {
    if ( v12 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      this->m_Geometry.m_Triangles.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_Triangles.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_VertexColors.m_Memory.m_nGrowSize < 0;
  this->m_Geometry.m_VertexColors.m_Size = 0;
  if ( !v10 )
  {
    if ( this->m_Geometry.m_VertexColors.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Geometry.m_VertexColors.m_Memory.m_pMemory);
      this->m_Geometry.m_VertexColors.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_VertexColors.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_VertexColors.m_Memory.m_nGrowSize < 0;
  v13 = this->m_Geometry.m_VertexColors.m_Memory.m_pMemory;
  this->m_Geometry.m_VertexColors.m_pElements = v13;
  if ( !v10 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      this->m_Geometry.m_VertexColors.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_VertexColors.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_TextureCoords.m_Memory.m_nGrowSize < 0;
  this->m_Geometry.m_TextureCoords.m_Size = 0;
  if ( !v10 )
  {
    if ( this->m_Geometry.m_TextureCoords.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Geometry.m_TextureCoords.m_Memory.m_pMemory);
      this->m_Geometry.m_TextureCoords.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_TextureCoords.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_TextureCoords.m_Memory.m_nGrowSize < 0;
  v14 = this->m_Geometry.m_TextureCoords.m_Memory.m_pMemory;
  this->m_Geometry.m_TextureCoords.m_pElements = v14;
  if ( !v10 )
  {
    if ( v14 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
      this->m_Geometry.m_TextureCoords.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_TextureCoords.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_RelativePositions.m_Memory.m_nGrowSize < 0;
  this->m_Geometry.m_RelativePositions.m_Size = 0;
  if ( !v10 )
  {
    if ( this->m_Geometry.m_RelativePositions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Geometry.m_RelativePositions.m_Memory.m_pMemory);
      this->m_Geometry.m_RelativePositions.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_RelativePositions.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_Geometry.m_RelativePositions.m_Memory.m_nGrowSize < 0;
  v15 = this->m_Geometry.m_RelativePositions.m_Memory.m_pMemory;
  this->m_Geometry.m_RelativePositions.m_pElements = v15;
  if ( !v10 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      this->m_Geometry.m_RelativePositions.m_Memory.m_pMemory = nullptr;
    }
    this->m_Geometry.m_RelativePositions.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_pName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pName.m_Storage.m_nActualLength = 0;
  if ( !v10 )
  {
    if ( this->m_pName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pName.m_Storage.m_Memory.m_pMemory);
      this->m_pName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426440
// Name: public: unsigned short CUtlMap<int,class CGameGraphic __near *,unsigned short>::InsertOrReplace(int const __near &,class CGameGraphic __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<int,CGameGraphic *,unsigned short>::InsertOrReplace(
        CUtlMap<int,CGameGraphic *,unsigned short> *this,
        int *key,
        CGameGraphic **insert)
{
  unsigned __int16 result; // ax
  CGameGraphic *v5; // ecx
  CUtlMap<int,CGameGraphic *,unsigned short>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  search.key = *key;
  result = CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_Tree,
             &search);
  if ( result == 0xFFFF )
  {
    v5 = *insert;
    search.key = *key;
    search.elem = v5;
    return CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
             this: &this->m_Tree,
             insert: &search);
  }
  else
  {
    this->m_Tree.m_Elements.m_pMemory[result].m_Data.elem = *insert;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004264B0
// Name: public: CGameGraphic::CGameGraphic(void)
// Source: json
//------------------------------------------------------------------------------
CGameGraphic *__thiscall CGameGraphic::CGameGraphic(CGameGraphic *this)
{
  CUtlString *p_m_pName; // edi
  int v3; // ecx
  CGameGraphic *insert; // [esp+Ch] [ebp-4h] BYREF

  p_m_pName = &this->m_pName;
  this->__vftable = (CGameGraphic_vtbl *)&CGameGraphic::`vftable';
  CUtlString::CUtlString(this: &this->m_pName);
  CGeometry::CGeometry(this: &this->m_Geometry);
  v3 = g_iSerialHandle + 1;
  this->m_Anims.m_Memory.m_pMemory = nullptr;
  this->m_Anims.m_Memory.m_nAllocationCount = 0;
  this->m_Anims.m_Memory.m_nGrowSize = 0;
  this->m_Anims.m_Size = 0;
  this->m_Anims.m_pElements = nullptr;
  this->m_flAnimTime.m_tms = 0x80000000;
  g_iSerialHandle = v3;
  this->m_iScriptHandle = v3;
  insert = this;
  CUtlMap<int,CGameGraphic *,unsigned short>::InsertOrReplace(
    this: &g_mapScriptHandles_0,
    key: &this->m_iScriptHandle,
    &insert);
  CUtlString::operator=(this: p_m_pName, src: defaultValue);
  this->m_pGroup = nullptr;
  this->m_bCanAcceptInput = false;
  this->m_flAnimTime.m_tms = 0;
  this->m_CurrentState = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B290
// Name: public: unsigned short CUtlMap<class CUtlString,class IGameUIScreenController __near *,unsigned short>::Find(class CUtlString const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Find(
        CUtlMap<CUtlString,IGameUIScreenController *,unsigned short> *this,
        const CUtlString *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t dummyNode; // [esp+0h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v3 = CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: (const CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t *)&dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  dummyNode.elem = nullptr;
  if ( dummyNode.key.m_Storage.m_nActualLength >= 0 && dummyNode.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dummyNode.key.m_Storage.m_Memory.m_nAllocationCount);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0042BB20
// Name: public: unsigned short CUtlMap<class CUtlString,class IGameUIScreenController __near *,unsigned short>::Insert(class CUtlString const __near &,class IGameUIScreenController __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Insert(
        CUtlMap<CUtlString,IGameUIScreenController *,unsigned short> *this,
        const CUtlString *key,
        IGameUIScreenController *const *insert)
{
  unsigned __int16 v4; // si
  CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t node; // [esp+0h] [ebp-18h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  CUtlString::CUtlString(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  CUtlString::operator=(this: (CUtlString *)&node.key.m_Storage.m_Memory.m_nAllocationCount, src: key);
  v7 = (int)*insert;
  v4 = CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: (const CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t *)&node.key.m_Storage.m_Memory.m_nAllocationCount);
  node.elem = nullptr;
  if ( node.key.m_Storage.m_nActualLength >= 0 && node.key.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)node.key.m_Storage.m_Memory.m_nAllocationCount);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0042BB90
// Name: public: void CUtlMap<class CUtlString,class IGameUIScreenController __near *,unsigned short>::RemoveAt(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::RemoveAt(
        CUtlMap<CUtlString,IGameUIScreenController *,unsigned short> *this,
        unsigned __int16 i)
{
  if ( i != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Tree,
      elem: i);
    CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FreeNode(
      this: &this->m_Tree,
      i);
    --this->m_Tree.m_NumElements;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004241E0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<int,class CGameGraphic __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,class CGameGraphic __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,class CGameGraphic __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00426570
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CAnimData>(class CAnimData __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CAnimData>()
{
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    dword_5BAAB8 = 2;
    dword_5BAABC = 32;
    dword_5BAAC0 = 4;
    dword_5BAAC4 = -1;
    dword_5BAAC8 = 0;
    dword_5BAACC = 0;
    dword_5BAAD0 = 0;
    dword_5BAAD4 = 0;
    dword_5BAAD8 = 0;
    dword_5BAADC = (int)"animationrate";
    dword_5BAAE0 = (int)"1";
    dword_5BAAE4 = 3;
    dword_5BAAE8 = 36;
    dword_5BAAEC = 4;
    dword_5BAAF0 = -1;
    dword_5BAAF4 = 0;
    dword_5BAAF8 = 0;
    dword_5BAAFC = 0;
    dword_5BAB00 = 0;
    dword_5BAB04 = 0;
    dword_5BAB08 = 0;
    dword_5BAB0C = 0;
    dword_5BAB10 = 0;
    dword_5BAB14 = 0;
    dword_5BAB18 = 0;
    dword_5BAB1C = -1;
    dword_5BAB20 = 0;
    dword_5BAB24 = 0;
    dword_5BAB28 = 0;
    dword_5BAB2C = 0;
    dword_5BAB30 = 0;
  }
  return unpack_3;
}
