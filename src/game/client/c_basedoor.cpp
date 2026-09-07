// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_basedoor.cpp
// Functions: 20
// ============================================================

#include "game\client\c_basedoor.h"

//------------------------------------------------------------------------------
// Address: 0x10037800
// Name: public: virtual class ClientClass __near * C_BaseDoor::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseDoor::GetClientClass(C_BaseDoor *this)
{
  return &__g_C_BaseDoorClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10410A00
// Name: DT_BaseDoor::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseDoor::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseDoor::g_RecvTable);
  return atexit(func: DT_BaseDoor::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410A20
// Name: DT_BaseDoor::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseDoor::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseDoor::ignored>();
  DT_BaseDoor::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042FBC0
// Name: DT_BaseDoor::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseDoor::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseDoor::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10410A30
// Name: _dynamic_initializer_for__report_cliententitysim__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__report_cliententitysim__()
{
  ConVar::ConVar(
    this: &report_cliententitysim,
    pName: "report_cliententitysim",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "List all clientside simulations and time - will report and turn itself off.");
  return atexit(func: dynamic_atexit_destructor_for__report_cliententitysim__);
}

//------------------------------------------------------------------------------
// Address: 0x10410A60
// Name: _dynamic_initializer_for__cl_extrapolate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_extrapolate__()
{
  ConVar::ConVar(
    this: &cl_extrapolate,
    pName: "cl_extrapolate",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable/disable extrapolation if interpolation history runs out.");
  return atexit(func: dynamic_atexit_destructor_for__cl_extrapolate__);
}

//------------------------------------------------------------------------------
// Address: 0x10410A90
// Name: _dynamic_initializer_for__cl_interp_npcs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_interp_npcs__()
{
  ConVar::ConVar(
    this: &cl_interp_npcs,
    pName: "cl_interp_npcs",
    pDefaultValue: "0.0",
    flags: 0,
    pHelpString: "Interpolate NPC positions starting this many seconds in past (or cl_interp, if greater)");
  return atexit(func: dynamic_atexit_destructor_for__cl_interp_npcs__);
}

//------------------------------------------------------------------------------
// Address: 0x10410AC0
// Name: _dynamic_initializer_for__cl_interp_all__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_interp_all__()
{
  ConVar::ConVar(
    this: &cl_interp_all,
    pName: "cl_interp_all",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Disable interpolation list optimizations.",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))cc_cl_interp_all_changed);
  return atexit(func: dynamic_atexit_destructor_for__cl_interp_all__);
}

//------------------------------------------------------------------------------
// Address: 0x10410B00
// Name: _dynamic_initializer_for__r_drawmodeldecals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawmodeldecals__()
{
  ConVar::ConVar(this: &r_drawmodeldecals, pName: "r_drawmodeldecals", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_drawmodeldecals__);
}

//------------------------------------------------------------------------------
// Address: 0x10410B30
// Name: _dynamic_initializer_for__r_drawrenderboxes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawrenderboxes__()
{
  ConVar::ConVar(this: &r_drawrenderboxes, pName: "r_drawrenderboxes", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawrenderboxes__);
}

//------------------------------------------------------------------------------
// Address: 0x10410B60
// Name: _dynamic_initializer_for__g_EntityLists__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntityLists__()
{
  int v0; // ecx
  int *p_m_nGrowSize; // eax

  v0 = 4;
  p_m_nGrowSize = &g_EntityLists.m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    *((_WORD *)p_m_nGrowSize + 7) = -1;
    *((_WORD *)p_m_nGrowSize + 2) = -1;
    *((_WORD *)p_m_nGrowSize + 3) = -1;
    *((_WORD *)p_m_nGrowSize + 4) = -1;
    *((_WORD *)p_m_nGrowSize + 5) = 0;
    *((_WORD *)p_m_nGrowSize + 6) = 0;
    p_m_nGrowSize[4] = *(p_m_nGrowSize - 2);
    p_m_nGrowSize += 7;
    --v0;
  }
  while ( v0 >= 0 );
  return atexit(func: dynamic_atexit_destructor_for__g_EntityLists__);
}

//------------------------------------------------------------------------------
// Address: 0x10410BC0
// Name: _dynamic_initializer_for__g_Predictables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Predictables__()
{
  g_Predictables.m_Memory.m_pMemory = nullptr;
  g_Predictables.m_Memory.m_nAllocationCount = 0;
  g_Predictables.m_Memory.m_nGrowSize = 0;
  g_Predictables.m_Size = 0;
  g_Predictables.m_pElements = nullptr;
  g_Predictables.m_pLessContext = nullptr;
  g_Predictables.m_bNeedsSort = false;
  return atexit(func: dynamic_atexit_destructor_for__g_Predictables__);
}

//------------------------------------------------------------------------------
// Address: 0x10410C00
// Name: _dynamic_initializer_for__g_RecordingList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RecordingList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RecordingList__);
}

//------------------------------------------------------------------------------
// Address: 0x10410C10
// Name: _dynamic_initializer_for____g_C_BaseEntityClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseEntityClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseEntityClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseEntityClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042FBD0
// Name: _dynamic_atexit_destructor_for__report_cliententitysim__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__report_cliententitysim__()
{
  ConVar::~ConVar(this: &report_cliententitysim);
}

//------------------------------------------------------------------------------
// Address: 0x1042FBE0
// Name: _dynamic_atexit_destructor_for__cl_extrapolate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_extrapolate__()
{
  ConVar::~ConVar(this: &cl_extrapolate);
}

//------------------------------------------------------------------------------
// Address: 0x1042FBF0
// Name: _dynamic_atexit_destructor_for__cl_interp_npcs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_interp_npcs__()
{
  ConVar::~ConVar(this: &cl_interp_npcs);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC00
// Name: _dynamic_atexit_destructor_for__cl_interp_all__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_interp_all__()
{
  ConVar::~ConVar(this: &cl_interp_all);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC10
// Name: _dynamic_atexit_destructor_for__r_drawmodeldecals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawmodeldecals__()
{
  ConVar::~ConVar(this: &r_drawmodeldecals);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC20
// Name: _dynamic_atexit_destructor_for__r_drawrenderboxes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawrenderboxes__()
{
  ConVar::~ConVar(this: &r_drawrenderboxes);
}
