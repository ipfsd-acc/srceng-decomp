// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_movelinear.cpp
// Functions: 7
// ============================================================

#include "game\client\c_func_movelinear.h"

//------------------------------------------------------------------------------
// Address: 0x10070F10
// Name: public: virtual class ClientClass __near * C_FuncMoveLinear::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncMoveLinear::GetClientClass(C_FuncMoveLinear *this)
{
  return &__g_C_FuncMoveLinearClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10070FC0
// Name: public: virtual void C_FuncMoveLinear::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncMoveLinear::OnDataChanged(C_FuncMoveLinear *this, DataUpdateType_t type)
{
  C_BaseEntity::OnDataChanged(this, type);
  if ( type == DATA_UPDATE_CREATED )
  {
    CCollisionProperty::SetSolid(this: (CCollisionProperty *)&this->m_hOldMoveParent, val: SOLID_VPHYSICS);
    C_BaseEntity::VPhysicsInitShadow(
      this: (C_FuncMoveLinear *)((char *)this - 8),
      allowPhysicsMovement: 0,
      allowPhysicsRotation: 0,
      pSolid: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412290
// Name: DT_FuncMoveLinear::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMoveLinear::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncMoveLinear::g_RecvTable);
  return atexit(func: DT_FuncMoveLinear::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104122B0
// Name: DT_FuncMoveLinear::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMoveLinear::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncMoveLinear::ignored>();
  DT_FuncMoveLinear::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430350
// Name: DT_FuncMoveLinear::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncMoveLinear::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncMoveLinear::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10071000
// Name: _C_FuncMoveLinear_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncMoveLinear_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9B0u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3[608] = -1;
  *v3 = &C_FuncMoveLinear::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncMoveLinear::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncMoveLinear::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncMoveLinear::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncMoveLinear::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104122C0
// Name: _dynamic_initializer_for____g_C_FuncOccluderClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncOccluderClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncOccluderClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncOccluderClientClass;
  return result;
}
