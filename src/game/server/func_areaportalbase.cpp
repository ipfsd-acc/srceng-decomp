// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_areaportalbase.cpp
// Functions: 5
// ============================================================

#include "game\server\func_areaportalbase.h"

//------------------------------------------------------------------------------
// Address: 0x10130E40
// Name: public: virtual struct datamap_t __near * CFuncAreaPortalBase::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncAreaPortalBase::GetDataDescMap(CFuncAreaPortalBase *this)
{
  return &CFuncAreaPortalBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10130E50
// Name: public: virtual bool CFuncAreaPortalBase::UpdateVisibility(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,float,bool __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFuncAreaPortalBase::UpdateVisibility(
        CFuncAreaPortalBase *this,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *vecOrigins,
        float fovDistanceAdjustFactor,
        bool *bIsOpenOnClient)
{
  bool v4; // zf
  int v6; // edi
  Vector *v7; // esi
  VPlane plane; // [esp+0h] [ebp-18h] BYREF
  CFuncAreaPortalBase *v9; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v4 = this->m_portalNumber == -1;
  v9 = this;
  if ( v4 )
    return 0;
  v6 = 0;
  i = 0;
  if ( vecOrigins->m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = &vecOrigins->m_Memory.m_pMemory[v6];
    if ( ((unsigned __int8 (__stdcall *)(Vector *, int, VPlane *))engine->GetAreaPortalPlane)(
           a1: v7,
           a2: v9->m_portalNumber,
           a3: &plane) == 0
      || (float)((float)((float)((float)((float)(v7->y * plane.m_Normal.y) + (float)(v7->x * plane.m_Normal.x))
                               + (float)(v7->z * plane.m_Normal.z))
                       - plane.m_Dist)
               + 80.0) > 0.0 )
    {
      break;
    }
    ++v6;
    if ( ++i >= vecOrigins->m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10131110
// Name: public: virtual CFuncAreaPortalBase::~CFuncAreaPortalBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncAreaPortalBase::~CFuncAreaPortalBase(CFuncAreaPortalBase *this)
{
  int m_AreaPortalsElement; // edi
  unsigned __int16 v3; // [esp-4h] [ebp-Ch]

  m_AreaPortalsElement = this->m_AreaPortalsElement;
  v3 = this->m_AreaPortalsElement;
  this->__vftable = (CFuncAreaPortalBase_vtbl *)&CFuncAreaPortalBase::`vftable';
  CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
    this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_AreaPortals,
    elem: v3);
  g_AreaPortals.m_Memory.m_pMemory[m_AreaPortalsElement].m_Next = g_AreaPortals.m_FirstFree;
  g_AreaPortals.m_FirstFree = m_AreaPortalsElement;
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10131150
// Name: public: CFuncAreaPortalBase::CFuncAreaPortalBase(void)
// Source: json
//------------------------------------------------------------------------------
CFuncAreaPortalBase *__thiscall CFuncAreaPortalBase::CFuncAreaPortalBase(CFuncAreaPortalBase *this)
{
  int v2; // edi
  unsigned __int16 v3; // ax
  UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short> *v4; // eax

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFuncAreaPortalBase_vtbl *)&CFuncAreaPortalBase::`vftable';
  this->m_portalNumber = -1;
  v2 = (unsigned __int16)CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::AllocInternal(
                           this: &g_AreaPortals,
                           multilist: false);
  v3 = -1;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_AreaPortals,
      before: 0xFFFFu,
      elem: v2);
    v4 = &g_AreaPortals.m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      v4->m_Element = this;
    v3 = v2;
  }
  this->m_AreaPortalsElement = v3;
  this->m_iPortalVersion = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10403A00
// Name: CFuncAreaPortalBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncAreaPortalBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncAreaPortalBase>();
  CFuncAreaPortalBase_DataDescInit::g_DataMapHolder = result;
  return result;
}
