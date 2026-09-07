// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_occluder.cpp
// Functions: 7
// ============================================================

#include "game\client\c_func_occluder.h"

//------------------------------------------------------------------------------
// Address: 0x10071070
// Name: public: virtual class ClientClass __near * C_FuncOccluder::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncOccluder::GetClientClass(C_FuncOccluder *this)
{
  return &__g_C_FuncOccluderClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10071120
// Name: public: virtual void C_FuncOccluder::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncOccluder::OnDataChanged(C_FuncOccluder *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  engine->ActivateOccluder(
    this: engine,
    a2: *(_DWORD *)&this->m_bIsBlurred,
    a3: *((unsigned __int8 *)&this->m_bIsBlurred + 4));
}

//------------------------------------------------------------------------------
// Address: 0x104122E0
// Name: DT_FuncOccluder::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncOccluder::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncOccluder::g_RecvTable);
  return atexit(func: DT_FuncOccluder::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412300
// Name: DT_FuncOccluder::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncOccluder::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncOccluder::ignored>();
  DT_FuncOccluder::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430360
// Name: DT_FuncOccluder::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncOccluder::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncOccluder::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10071160
// Name: _C_FuncOccluder_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncOccluder_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_FuncOccluder::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncOccluder::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncOccluder::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncOccluder::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncOccluder::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10412310
// Name: _dynamic_initializer_for____g_C_FuncReflectiveGlassClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncReflectiveGlassClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncReflectiveGlassClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncReflectiveGlassClientClass;
  return result;
}
