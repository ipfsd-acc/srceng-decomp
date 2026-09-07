// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_physics_prop_statue.cpp
// Functions: 9
// ============================================================

#include "game\client\c_physics_prop_statue.h"

//------------------------------------------------------------------------------
// Address: 0x10079AD0
// Name: public: virtual class ClientClass __near * C_StatueProp::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_StatueProp::GetClientClass(C_StatueProp *this)
{
  return &__g_C_StatuePropClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10079BE0
// Name: public: virtual void C_StatueProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_StatueProp::Spawn(C_StatueProp *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  this->m_EntClientFlags |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x10079BF0
// Name: public: virtual void C_StatueProp::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_StatueProp::OnDataChanged(C_StatueProp *this, DataUpdateType_t updateType)
{
  C_PhysicsProp::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10079C50
// Name: public: virtual void C_StatueProp::ComputeWorldSpaceSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_StatueProp::ComputeWorldSpaceSurroundingBox(
        C_StatueProp *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hInitBaseAnimating.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
      ((void (__thiscall *)(IHandleEntity *, Vector *, Vector *))m_pEntity[195].__vftable[5].dtr_IHandleEntity)(
        a1: &m_pEntity[195],
        a2: pVecWorldMins,
        a3: pVecWorldMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412AD0
// Name: DT_StatueProp::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_StatueProp::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_StatueProp::g_RecvTable);
  return atexit(func: DT_StatueProp::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412AF0
// Name: DT_StatueProp::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_StatueProp::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_StatueProp::ignored>();
  DT_StatueProp::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430730
// Name: DT_StatueProp::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_StatueProp::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_StatueProp::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10079CA0
// Name: _C_StatueProp_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_StatueProp_CreateObject(int entnum, int serialNum)
{
  C_PhysicsProp *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_PhysicsProp *)C_BaseEntity::operator new(stAllocateBlock: 0xD18u);
  v3 = &v2->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_PhysicsProp::C_PhysicsProp(this: v2);
  *v3 = &C_StatueProp::`vftable'{for `IClientUnknown'};
  v3[1] = &C_StatueProp::`vftable'{for `IClientRenderable'};
  v3[2] = &C_StatueProp::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_StatueProp::`vftable'{for `IClientThinkable'};
  v3[4] = &C_StatueProp::`vftable'{for `C_BaseAnimating'};
  v3[814] = &C_StatueProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  v3[828] = -1;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10412B00
// Name: _dynamic_initializer_for____g_C_PhysicsPropClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PhysicsPropClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PhysicsPropClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PhysicsPropClientClass;
  return result;
}
