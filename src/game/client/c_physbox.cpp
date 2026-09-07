// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_physbox.cpp
// Functions: 9
// ============================================================

#include "game\client\c_physbox.h"

//------------------------------------------------------------------------------
// Address: 0x100798F0
// Name: public: virtual class ClientClass __near * C_PhysBox::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PhysBox::GetClientClass(C_PhysBox *this)
{
  return &__g_C_PhysBoxClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10079990
// Name: public: C_PhysBox::C_PhysBox(void)
// Source: json
//------------------------------------------------------------------------------
C_PhysBox *__thiscall C_PhysBox::C_PhysBox(C_PhysBox *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PhysBox_vtbl *)&C_PhysBox::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PhysBox::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PhysBox::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PhysBox::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PhysBox::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100799C0
// Name: public: virtual C_PhysBox::~C_PhysBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysBox::~C_PhysBox(C_PhysBox *this)
{
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PhysBox_vtbl *)&C_PhysBox::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PhysBox::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PhysBox::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PhysBox::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PhysBox::`vftable';
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10079AB0
// Name: public: virtual enum ShadowType_t C_PhysBox::ShadowCastType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PhysBox::ShadowCastType(C_PhysBox *this)
{
  return (this->m_nWaterType & 0x30) != 0 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10412A80
// Name: DT_PhysBox::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBox::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PhysBox::g_RecvTable);
  return atexit(func: DT_PhysBox::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412AA0
// Name: DT_PhysBox::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBox::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PhysBox::ignored>();
  DT_PhysBox::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430720
// Name: DT_PhysBox::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysBox::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PhysBox::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100799F0
// Name: _C_PhysBox_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PhysBox_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_PhysBox::`vftable'{for `IClientUnknown'};
  v3[1] = &C_PhysBox::`vftable'{for `IClientRenderable'};
  v3[2] = &C_PhysBox::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_PhysBox::`vftable'{for `IClientThinkable'};
  v3[4] = &C_PhysBox::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10412AB0
// Name: _dynamic_initializer_for____g_C_StatuePropClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_StatuePropClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_StatuePropClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_StatuePropClientClass;
  return result;
}
