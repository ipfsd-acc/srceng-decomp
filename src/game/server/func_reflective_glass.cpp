// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_reflective_glass.cpp
// Functions: 8
// ============================================================

#include "game\server\func_reflective_glass.h"

//------------------------------------------------------------------------------
// Address: 0x1013D420
// Name: private: virtual struct datamap_t __near * CFuncReflectiveGlass::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncReflectiveGlass::GetDataDescMap(CFuncReflectiveGlass *this)
{
  return &CFuncReflectiveGlass::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013D430
// Name: public: virtual class ServerClass __near * CFuncReflectiveGlass::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncReflectiveGlass::GetServerClass(CFuncReflectiveGlass *this)
{
  return &g_CFuncReflectiveGlass_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10404190
// Name: CFuncReflectiveGlass_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncReflectiveGlass_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncReflectiveGlass>();
  CFuncReflectiveGlass_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104041E0
// Name: DT_FuncReflectiveGlass::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncReflectiveGlass::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncReflectiveGlass::g_SendTable);
  return atexit(func: DT_FuncReflectiveGlass::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10404200
// Name: DT_FuncReflectiveGlass::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncReflectiveGlass::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncReflectiveGlass::ignored>();
  DT_FuncReflectiveGlass::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B940
// Name: DT_FuncReflectiveGlass::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncReflectiveGlass::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncReflectiveGlass::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B950
// Name: _ServerClassInit_DT_FuncReflectiveGlass::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncReflectiveGlass::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_69;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B970
// Name: _DataMapInit_CFuncReflectiveGlass__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncReflectiveGlass__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_222);
}
