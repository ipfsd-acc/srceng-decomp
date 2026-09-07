// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_entityfreezing.cpp
// Functions: 10
// ============================================================

#include "game\client\c_entityfreezing.h"

//------------------------------------------------------------------------------
// Address: 0x10065CD0
// Name: public: virtual class ClientClass __near * C_EntityFreezing::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EntityFreezing::GetClientClass(C_EntityFreezing *this)
{
  return &__g_C_EntityFreezingClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10065E00
// Name: public: virtual void C_EntityFreezing::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFreezing::OnDataChanged(C_EntityFreezing *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    (*(void (__stdcall **)(int))(*((_DWORD *)this - 2) + 456))(a1: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x10065E40
// Name: public: virtual void C_EntityFreezing::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFreezing::ClientThink(C_EntityFreezing *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10065E50
// Name: public: virtual int C_EntityFreezing::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_EntityFreezing::DrawModel(C_EntityFreezing *this, int flags, const RenderableInstance_t *instance)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10065EE0
// Name: public: C_EntityFreezing::C_EntityFreezing(void)
// Source: json
//------------------------------------------------------------------------------
C_EntityFreezing *__thiscall C_EntityFreezing::C_EntityFreezing(C_EntityFreezing *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EntityFreezing_vtbl *)&C_EntityFreezing::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EntityFreezing::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EntityFreezing::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EntityFreezing::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EntityFreezing::`vftable';
  this->m_HitboxBlobData.m_Memory.m_pMemory = nullptr;
  this->m_HitboxBlobData.m_Memory.m_nAllocationCount = 0;
  this->m_HitboxBlobData.m_Memory.m_nGrowSize = 0;
  this->m_HitboxBlobData.m_Size = 0;
  this->m_HitboxBlobData.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10411AA0
// Name: DT_EntityFreezing::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFreezing::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EntityFreezing::g_RecvTable);
  return atexit(func: DT_EntityFreezing::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411AC0
// Name: DT_EntityFreezing::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFreezing::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EntityFreezing::ignored>();
  DT_EntityFreezing::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430190
// Name: DT_EntityFreezing::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityFreezing::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EntityFreezing::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10065F30
// Name: _C_EntityFreezing_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EntityFreezing_CreateObject(int entnum, int serialNum)
{
  C_EntityFreezing *v2; // eax
  C_EntityFreezing *v3; // eax
  C_EntityFreezing *v4; // esi

  v2 = (C_EntityFreezing *)C_BaseEntity::operator new(stAllocateBlock: 0xA70u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EntityFreezing::C_EntityFreezing(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411AD0
// Name: _dynamic_initializer_for____g_C_EntityParticleTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EntityParticleTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EntityParticleTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EntityParticleTrailClientClass;
  return result;
}
