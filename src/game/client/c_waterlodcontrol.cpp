// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_waterlodcontrol.cpp
// Functions: 7
// ============================================================

#include "game\client\c_waterlodcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x10097870
// Name: public: virtual class ClientClass __near * C_WaterLODControl::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WaterLODControl::GetClientClass(C_WaterLODControl *this)
{
  return &__g_C_WaterLODControlClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10097930
// Name: public: virtual void C_WaterLODControl::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WaterLODControl::OnDataChanged(C_WaterLODControl *this, DataUpdateType_t updateType)
{
  ((void (__stdcall *)(_DWORD))view->SetCheapWaterStartDistance)(a1: *(_DWORD *)&this->m_bIsBlurred);
  ((void (__stdcall *)(_DWORD))view->SetCheapWaterEndDistance)(a1: *((_DWORD *)&this->m_bIsBlurred + 1));
}

//------------------------------------------------------------------------------
// Address: 0x10414140
// Name: DT_WaterLODControl::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterLODControl::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WaterLODControl::g_RecvTable);
  return atexit(func: DT_WaterLODControl::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10414160
// Name: DT_WaterLODControl::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterLODControl::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WaterLODControl::ignored>();
  DT_WaterLODControl::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430D90
// Name: DT_WaterLODControl::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WaterLODControl::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WaterLODControl::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10097970
// Name: _C_WaterLODControl_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WaterLODControl_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_WaterLODControl::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WaterLODControl::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WaterLODControl::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WaterLODControl::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WaterLODControl::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10414170
// Name: _dynamic_initializer_for____g_C_WorldClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WorldClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WorldClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WorldClientClass;
  return result;
}
