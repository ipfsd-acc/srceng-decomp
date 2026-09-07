// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_env_dof_controller.cpp
// Functions: 9
// ============================================================

#include "game\client\c_env_dof_controller.h"

//------------------------------------------------------------------------------
// Address: 0x10067490
// Name: public: virtual class ClientClass __near * C_EnvDOFController::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvDOFController::GetClientClass(C_EnvDOFController *this)
{
  return &__g_C_EnvDOFControllerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100675E0
// Name: public: C_EnvDOFController::C_EnvDOFController(void)
// Source: json
//------------------------------------------------------------------------------
C_EnvDOFController *__thiscall C_EnvDOFController::C_EnvDOFController(C_EnvDOFController *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->m_flNearBlurDepth = 50.0;
  this->m_flNearFocusDepth = 100.0;
  this->m_flFarFocusDepth = 250.0;
  this->m_flFarBlurDepth = 1000.0;
  this->m_flNearBlurRadius = 0.0;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvDOFController_vtbl *)&C_EnvDOFController::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvDOFController::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvDOFController::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvDOFController::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvDOFController::`vftable';
  this->m_bDOFEnabled = true;
  this->m_flFarBlurRadius = 5.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100676C0
// Name: public: virtual C_EnvDOFController::~C_EnvDOFController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvDOFController::~C_EnvDOFController(C_EnvDOFController *this)
{
  C_EnvDOFController *m_pEntity; // eax

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvDOFController_vtbl *)&C_EnvDOFController::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvDOFController::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvDOFController::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvDOFController::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvDOFController::`vftable';
  if ( g_hDOFControllerInUse.m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(g_hDOFControllerInUse.m_Index)].m_SerialNumber != HIWORD(g_hDOFControllerInUse.m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_EnvDOFController *)g_pEntityList->m_EntPtrArray[LOWORD(g_hDOFControllerInUse.m_Index)].m_pEntity;
  }
  if ( m_pEntity == this )
    g_bDOFEnabled = false;
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10067750
// Name: public: virtual void C_EnvDOFController::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvDOFController::OnDataChanged(C_EnvDOFController *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  g_bDOFEnabled = this->m_bIsBlurred && (this->m_flFarFocusDepth > 0.0 || this->m_flFarBlurDepth > 0.0);
  g_flDOFNearBlurDepth = *((float *)&this->m_bIsBlurred + 1);
  g_flDOFNearFocusDepth = *(float *)&this->m_bDOFEnabled;
  g_flDOFFarFocusDepth = this->m_flNearBlurDepth;
  g_flDOFFarBlurDepth = this->m_flNearFocusDepth;
  g_flDOFNearBlurRadius = this->m_flFarFocusDepth;
  g_flDOFFarBlurRadius = this->m_flFarBlurDepth;
  if ( this == (C_EnvDOFController *)8 )
    g_hDOFControllerInUse.m_Index = -1;
  else
    g_hDOFControllerInUse.m_Index = *(_DWORD *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 8))(a1: (char *)this - 8);
}

//------------------------------------------------------------------------------
// Address: 0x10411C10
// Name: DT_EnvDOFController::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvDOFController::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvDOFController::g_RecvTable);
  return atexit(func: DT_EnvDOFController::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411C30
// Name: DT_EnvDOFController::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvDOFController::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvDOFController::ignored>();
  DT_EnvDOFController::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104301F0
// Name: DT_EnvDOFController::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvDOFController::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvDOFController::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10067670
// Name: _C_EnvDOFController_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvDOFController_CreateObject(int entnum, int serialNum)
{
  C_EnvDOFController *v2; // eax
  C_EnvDOFController *v3; // eax
  C_EnvDOFController *v4; // esi

  v2 = (C_EnvDOFController *)C_BaseEntity::operator new(stAllocateBlock: 0x9A0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EnvDOFController::C_EnvDOFController(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411C40
// Name: _dynamic_initializer_for____g_C_FogControllerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FogControllerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FogControllerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FogControllerClientClass;
  return result;
}
