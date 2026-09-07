// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_rotating.cpp
// Functions: 6
// ============================================================

#include "game\client\c_func_rotating.h"

//------------------------------------------------------------------------------
// Address: 0x100715F0
// Name: public: virtual class ClientClass __near * C_FuncRotating::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncRotating::GetClientClass(C_FuncRotating *this)
{
  return &__g_C_FuncRotatingClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x104123A0
// Name: DT_FuncRotating::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncRotating::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncRotating::g_RecvTable);
  return atexit(func: DT_FuncRotating::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104123C0
// Name: DT_FuncRotating::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncRotating::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncRotating::ignored>();
  DT_FuncRotating::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430390
// Name: DT_FuncRotating::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncRotating::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncRotating::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10071600
// Name: _C_FuncRotating_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncRotating_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_FuncRotating::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncRotating::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncRotating::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncRotating::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncRotating::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104123D0
// Name: _dynamic_initializer_for____g_C_FuncSmokeVolumeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncSmokeVolumeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncSmokeVolumeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncSmokeVolumeClientClass;
  return result;
}
