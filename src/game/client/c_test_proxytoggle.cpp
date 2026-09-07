// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_test_proxytoggle.cpp
// Functions: 10
// ============================================================

#include "game\client\c_test_proxytoggle.h"

//------------------------------------------------------------------------------
// Address: 0x10092E40
// Name: public: virtual class ClientClass __near * C_Test_ProxyToggle_Networkable::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Test_ProxyToggle_Networkable::GetClientClass(C_Test_ProxyToggle_Networkable *this)
{
  return &__g_C_Test_ProxyToggle_NetworkableClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10092F50
// Name: Test_ProxyToggle_EnsureValue
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_ProxyToggle_EnsureValue(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax
  const char *m_WithProxy; // ecx
  const char *v4; // [esp+0h] [ebp-8h]

  if ( args->m_nArgc >= 2 )
  {
    if ( g_pTestObj == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_1046BD18, a2: v4);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)"Test_ProxyToggle_EnsureValue: requires value parameter.", a2: v4);
  }
  v1 = prType;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  v2 = atoi(nptr: v1);
  m_WithProxy = (const char *)g_pTestObj->m_WithProxy;
  if ( m_WithProxy != (const char *)v2 )
    _Error(this: (ISceneTokenProcessor *)&stru_1046BCC8, a2: m_WithProxy, v2);
}

//------------------------------------------------------------------------------
// Address: 0x10413CF0
// Name: DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ProxyToggle_ProxiedData::g_RecvTable);
  return atexit(func: DT_ProxyToggle_ProxiedData::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413D10
// Name: DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ProxyToggle_ProxiedData::ignored>();
  DT_ProxyToggle_ProxiedData::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413D40
// Name: DT_ProxyToggle::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ProxyToggle::g_RecvTable);
  return atexit(func: DT_ProxyToggle::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413D60
// Name: DT_ProxyToggle::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ProxyToggle::ignored>();
  DT_ProxyToggle::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430C80
// Name: DT_ProxyToggle_ProxiedData::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ProxyToggle_ProxiedData::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ProxyToggle_ProxiedData::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430C90
// Name: DT_ProxyToggle::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ProxyToggle::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ProxyToggle::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10092E50
// Name: _C_Test_ProxyToggle_Networkable_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Test_ProxyToggle_Networkable_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_Test_ProxyToggle_Networkable *v3; // esi
  bool (__thiscall *Init)(C_BaseEntity *, int, int); // eax

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = (C_Test_ProxyToggle_Networkable *)v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Test_ProxyToggle_Networkable_vtbl *)&C_Test_ProxyToggle_Networkable::`vftable'{for `IClientUnknown'};
  v3->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Test_ProxyToggle_Networkable::`vftable'{for `IClientRenderable'};
  v3->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Test_ProxyToggle_Networkable::`vftable'{for `IClientNetworkable'};
  v3->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Test_ProxyToggle_Networkable::`vftable'{for `IClientThinkable'};
  v3->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Test_ProxyToggle_Networkable::`vftable';
  Init = v3->Init;
  g_pTestObj = v3;
  Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413D20
// Name: _dynamic_initializer_for____g_C_Test_ProxyToggle_NetworkableClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_Test_ProxyToggle_NetworkableClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_Test_ProxyToggle_NetworkableClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_Test_ProxyToggle_NetworkableClientClass;
  return result;
}
