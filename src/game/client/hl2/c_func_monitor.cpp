// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hl2/c_func_monitor.cpp
// Functions: 5
// ============================================================

#include "game\client\hl2\c_func_monitor.h"

//------------------------------------------------------------------------------
// Address: 0x10070E20
// Name: public: virtual class ClientClass __near * C_FuncMonitor::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncMonitor::GetClientClass(C_FuncMonitor *this)
{
  return &__g_C_FuncMonitorClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10412240
// Name: DT_FuncMonitor::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMonitor::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncMonitor::g_RecvTable);
  return atexit(func: DT_FuncMonitor::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412260
// Name: DT_FuncMonitor::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMonitor::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncMonitor::ignored>();
  DT_FuncMonitor::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430340
// Name: DT_FuncMonitor::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncMonitor::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncMonitor::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412270
// Name: _dynamic_initializer_for____g_C_FuncMoveLinearClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncMoveLinearClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncMoveLinearClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncMoveLinearClientClass;
  return result;
}
