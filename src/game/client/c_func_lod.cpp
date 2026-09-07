// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_lod.cpp
// Functions: 6
// ============================================================

#include "game\client\c_func_lod.h"

//------------------------------------------------------------------------------
// Address: 0x10070C80
// Name: public: virtual class ClientClass __near * C_Func_LOD::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Func_LOD::GetClientClass(C_Func_LOD *this)
{
  return &__g_C_Func_LODClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10070DB0
// Name: public: virtual void C_Func_LOD::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Func_LOD::OnDataChanged(C_Func_LOD *this, DataUpdateType_t type)
{
  C_BaseEntity::OnDataChanged(this, type);
  VPhysicsShadowDataChanged(bCreate: type == DATA_UPDATE_CREATED, pEntity: (C_Func_LOD *)((char *)this - 8));
  ((void (__stdcall *)(int, float, float))LODWORD(this->m_Particles.m_ParticleEffects.m_pElements->pControlPoints.m_Memory.m_pMemory->vecOriginOffset.x))(
    a1: 1065353216,
    a2: (float)*(int *)&this->m_bIsBlurred,
    a3: (float)*((int *)&this->m_bIsBlurred + 1));
}

//------------------------------------------------------------------------------
// Address: 0x104121F0
// Name: DT_Func_LOD::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_LOD::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Func_LOD::g_RecvTable);
  return atexit(func: DT_Func_LOD::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412210
// Name: DT_Func_LOD::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_LOD::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Func_LOD::ignored>();
  DT_Func_LOD::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430330
// Name: DT_Func_LOD::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Func_LOD::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Func_LOD::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412220
// Name: _dynamic_initializer_for____g_C_FuncMonitorClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncMonitorClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncMonitorClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncMonitorClientClass;
  return result;
}
