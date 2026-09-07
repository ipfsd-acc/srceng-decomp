// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_sprite_perfmonitor.cpp
// Functions: 7
// ============================================================

#include "game\client\c_sprite_perfmonitor.h"

//------------------------------------------------------------------------------
// Address: 0x1008F9A0
// Name: public: virtual class ClientClass __near * C_ParticlePerformanceMonitor::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ParticlePerformanceMonitor::GetClientClass(C_ParticlePerformanceMonitor *this)
{
  return &__g_C_ParticlePerformanceMonitorClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1008FA50
// Name: public: virtual void C_ParticlePerformanceMonitor::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticlePerformanceMonitor::OnDataChanged(
        C_ParticlePerformanceMonitor *this,
        DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( *(&this->m_bIsBlurred + 1) )
  {
    if ( !g_bMeasureParticlePerformance )
      ResetParticlePerformanceCounters();
    g_bMeasureParticlePerformance = *(&this->m_bIsBlurred + 1);
    g_bDisplayParticlePerformance = this->m_bIsBlurred;
  }
  else
  {
    g_bMeasureParticlePerformance = *(&this->m_bIsBlurred + 1);
    g_bDisplayParticlePerformance = this->m_bIsBlurred;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413AA0
// Name: DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ParticlePerformanceMonitor::g_RecvTable);
  return atexit(func: DT_ParticlePerformanceMonitor::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413AC0
// Name: DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ParticlePerformanceMonitor::ignored>();
  DT_ParticlePerformanceMonitor::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430BF0
// Name: DT_ParticlePerformanceMonitor::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticlePerformanceMonitor::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ParticlePerformanceMonitor::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1008FAD0
// Name: _C_ParticlePerformanceMonitor_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ParticlePerformanceMonitor_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_BaseEntity *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseEntity_vtbl *)&C_ParticlePerformanceMonitor::`vftable'{for `IClientUnknown'};
  v3->IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticlePerformanceMonitor::`vftable'{for `IClientRenderable'};
  v3->IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticlePerformanceMonitor::`vftable'{for `IClientNetworkable'};
  v3->IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticlePerformanceMonitor::`vftable'{for `IClientThinkable'};
  v3->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticlePerformanceMonitor::`vftable';
  LOWORD(v3[1].IClientEntity::IClientUnknown::IHandleEntity::__vftable) = 0;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413AD0
// Name: _dynamic_initializer_for____g_C_SunClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SunClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SunClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SunClientClass;
  return result;
}
