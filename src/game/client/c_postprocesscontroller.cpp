// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_postprocesscontroller.cpp
// Functions: 10
// ============================================================

#include "game\client\c_postprocesscontroller.h"

//------------------------------------------------------------------------------
// Address: 0x10080BA0
// Name: public: virtual class ClientClass __near * C_PostProcessController::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PostProcessController::GetClientClass(C_PostProcessController *this)
{
  return &__g_C_PostProcessControllerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10080C90
// Name: public: virtual void C_PostProcessController::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PostProcessController::PostDataUpdate(C_PostProcessController *this, DataUpdateType_t updateType)
{
  C_BaseEntity::PostDataUpdate(this, updateType);
  if ( LOBYTE(this->m_PostProcessParameters.m_flParameters[9]) != 0 )
    C_PostProcessController::ms_pMasterController = (C_PostProcessController *)((char *)this - 8);
}

//------------------------------------------------------------------------------
// Address: 0x10080CC0
// Name: public: C_PostProcessController::C_PostProcessController(void)
// Source: json
//------------------------------------------------------------------------------
C_PostProcessController *__thiscall C_PostProcessController::C_PostProcessController(C_PostProcessController *this)
{
  C_PostProcessController *result; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PostProcessController_vtbl *)&C_PostProcessController::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PostProcessController::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PostProcessController::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PostProcessController::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PostProcessController::`vftable';
  memset(dst: (int)&this->m_PostProcessParameters, value: nullptr, count: sizeof(this->m_PostProcessParameters));
  this->m_PostProcessParameters.m_flParameters[3] = 0.80000001;
  this->m_PostProcessParameters.m_flParameters[4] = 1.1;
  this->m_bMaster = false;
  result = this;
  if ( C_PostProcessController::ms_pMasterController == nullptr )
    C_PostProcessController::ms_pMasterController = this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412F50
// Name: DT_PostProcessController::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PostProcessController::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PostProcessController::g_RecvTable);
  return atexit(func: DT_PostProcessController::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412F70
// Name: DT_PostProcessController::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PostProcessController::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PostProcessController::ignored>();
  DT_PostProcessController::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430880
// Name: DT_PostProcessController::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PostProcessController::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PostProcessController::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10080DA0
// Name: _C_PostProcessController_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PostProcessController_CreateObject(int entnum, int serialNum)
{
  C_PostProcessController *v2; // eax
  C_PostProcessController *v3; // eax
  C_PostProcessController *v4; // esi

  v2 = (C_PostProcessController *)C_BaseEntity::operator new(stAllocateBlock: 0x9B0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PostProcessController::C_PostProcessController(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412F80
// Name: _dynamic_initializer_for__C_Prop_Hallucination::sm_OcclusionProxyMaterial__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__C_Prop_Hallucination::sm_OcclusionProxyMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &C_Prop_Hallucination::sm_OcclusionProxyMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__C_Prop_Hallucination::sm_OcclusionProxyMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x10412FA0
// Name: _dynamic_initializer_for____g_C_Prop_HallucinationClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_Prop_HallucinationClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_Prop_HallucinationClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_Prop_HallucinationClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430890
// Name: _dynamic_atexit_destructor_for__C_Prop_Hallucination::sm_OcclusionProxyMaterial__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__C_Prop_Hallucination::sm_OcclusionProxyMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &C_Prop_Hallucination::sm_OcclusionProxyMaterial);
}
