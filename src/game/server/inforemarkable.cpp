// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/inforemarkable.cpp
// Functions: 4
// ============================================================

#include "game\server\inforemarkable.h"

//------------------------------------------------------------------------------
// Address: 0x100B1BD0
// Name: public: virtual void CRemarkableEntityList::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemarkableEntityList::LevelShutdownPostEntity(CWeaponList *this)
{
  CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *p_m_list; // esi
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *m_pMemory; // ecx

  p_m_list = &this->m_list;
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_list);
  if ( p_m_list->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_list->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_list->m_Memory.m_pMemory);
      p_m_list->m_Memory.m_pMemory = nullptr;
    }
    p_m_list->m_Memory.m_nAllocationCount = 0;
  }
  p_m_list->m_FirstFree = -1;
  m_pMemory = p_m_list->m_Memory.m_pMemory;
  *(_DWORD *)&p_m_list->m_NumAlloced = -65536;
  p_m_list->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10162670
// Name: public: virtual struct datamap_t __near * CInfoRemarkable::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInfoRemarkable::GetDataDescMap(CInfoRemarkable *this)
{
  return &CInfoRemarkable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10162A00
// Name: public: virtual void CInfoRemarkable::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoRemarkable::Spawn(CInfoRemarkable *this)
{
  int v2; // esi
  UtlLinkedListElem_t<CInfoRemarkable *,unsigned short> *v3; // eax

  v2 = (unsigned __int16)CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>>::AllocInternal(
                           this: &g_RemarkableList.m_list,
                           multilist: false);
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_RemarkableList.m_list,
      before: 0xFFFFu,
      elem: v2);
    v3 = &g_RemarkableList.m_list.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
      v3->m_Element = this;
  }
  this->m_iTimesRemarkedUpon = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10405510
// Name: CInfoRemarkable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInfoRemarkable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInfoRemarkable>();
  CInfoRemarkable_DataDescInit::g_DataMapHolder = result;
  return result;
}
