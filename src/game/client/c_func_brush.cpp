// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_brush.cpp
// Functions: 18
// ============================================================

#include "game\client\c_func_brush.h"

//------------------------------------------------------------------------------
// Address: 0x1006F260
// Name: public: virtual class ClientClass __near * C_FuncBrush::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncBrush::GetClientClass(C_FuncBrush *this)
{
  return &__g_C_FuncBrushClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006F2E0
// Name: public: virtual void C_FuncBrush::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncBrush::OnDataChanged(C_FuncBrush *this, DataUpdateType_t type)
{
  C_BaseEntity::OnDataChanged(this, type);
  VPhysicsShadowDataChanged(bCreate: type == DATA_UPDATE_CREATED, pEntity: (C_FuncBrush *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x10412060
// Name: DT_FuncBrush::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncBrush::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncBrush::g_RecvTable);
  return atexit(func: DT_FuncBrush::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412080
// Name: DT_FuncBrush::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncBrush::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncBrush::ignored>();
  DT_FuncBrush::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042C610
// Name: _dynamic_initializer_for__func_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_break_max_pieces__()
{
  ConVar::ConVar(this: &func_break_max_pieces, pName: "func_break_max_pieces", pDefaultValue: "15", flags: 8320);
  return atexit(func: dynamic_atexit_destructor_for__func_break_max_pieces__);
}

//------------------------------------------------------------------------------
// Address: 0x104302D0
// Name: DT_FuncBrush::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncBrush::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncBrush::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436CB0
// Name: _dynamic_atexit_destructor_for__func_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__func_break_max_pieces__()
{
  ConVar::~ConVar(this: &func_break_max_pieces);
}

//------------------------------------------------------------------------------
// Address: 0x1006F310
// Name: _C_FuncBrush_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncBrush_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_FuncBrush::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncBrush::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncBrush::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncBrush::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncBrush::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10412090
// Name: _dynamic_initializer_for____g_C_FuncConveyorClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncConveyorClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncConveyorClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncConveyorClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042C640
// Name: _dynamic_initializer_for__cl_fasttempentcollision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_fasttempentcollision__()
{
  ConVar::ConVar(this: &cl_fasttempentcollision, pName: "cl_fasttempentcollision", pDefaultValue: "5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_fasttempentcollision__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C670
// Name: _dynamic_initializer_for__g_TempEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TempEnts__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_TempEnts.m_TempEntsPool,
    blockSize: 0xD70u,
    numElements: 25,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  g_TempEnts.m_TempEnts.m_Memory.m_pMemory = nullptr;
  g_TempEnts.m_TempEnts.m_Memory.m_nAllocationCount = 0;
  g_TempEnts.m_TempEnts.m_Memory.m_nGrowSize = 0;
  g_TempEnts.m_TempEnts.m_LastAlloc.index = -1;
  *(_DWORD *)&g_TempEnts.m_TempEnts.m_Head = -1;
  *(_DWORD *)&g_TempEnts.m_TempEnts.m_FirstFree = 0xFFFF;
  g_TempEnts.m_TempEnts.m_NumAlloced = 0;
  g_TempEnts.m_TempEnts.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_TempEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C6E0
// Name: _dynamic_initializer_for__g_BreakableHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BreakableHelper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BreakableHelper__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C6F0
// Name: _dynamic_initializer_for____g_C_TEMuzzleFlash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEMuzzleFlash__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEMuzzleFlash);
  _g_C_TEMuzzleFlash.m_vecOrigin.x = 0.0;
  _g_C_TEMuzzleFlash.m_vecOrigin.y = 0.0;
  _g_C_TEMuzzleFlash.m_vecOrigin.z = 0.0;
  _g_C_TEMuzzleFlash.m_vecAngles.x = 0.0;
  _g_C_TEMuzzleFlash.m_vecAngles.y = 0.0;
  _g_C_TEMuzzleFlash.m_vecAngles.z = 0.0;
  _g_C_TEMuzzleFlash.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEMuzzleFlash_vtbl *)&C_TEMuzzleFlash::`vftable'{for `IClientUnknown'};
  _g_C_TEMuzzleFlash.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEMuzzleFlash::`vftable'{for `IClientNetworkable'};
  _g_C_TEMuzzleFlash.m_flScale = 1.0;
  _g_C_TEMuzzleFlash.m_nType = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEMuzzleFlash__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C770
// Name: _dynamic_initializer_for____g_C_TEMuzzleFlashClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEMuzzleFlashClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEMuzzleFlashClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEMuzzleFlashClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436CC0
// Name: _dynamic_atexit_destructor_for__cl_fasttempentcollision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_fasttempentcollision__()
{
  ConVar::~ConVar(this: &cl_fasttempentcollision);
}

//------------------------------------------------------------------------------
// Address: 0x10436CD0
// Name: _dynamic_atexit_destructor_for__g_BreakableHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BreakableHelper__()
{
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&g_BreakableHelper);
  if ( g_BreakableHelper.m_Breakables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_BreakableHelper.m_Breakables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_BreakableHelper.m_Breakables.m_Memory.m_pMemory);
      g_BreakableHelper.m_Breakables.m_Memory.m_pMemory = nullptr;
    }
    g_BreakableHelper.m_Breakables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10436D20
// Name: _dynamic_atexit_destructor_for__g_TempEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TempEnts__()
{
  CTempEnts::~CTempEnts(this: &g_TempEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10436D30
// Name: _dynamic_atexit_destructor_for____g_C_TEMuzzleFlash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEMuzzleFlash__()
{
  _g_C_TEMuzzleFlash.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEMuzzleFlash_vtbl *)&C_TEMuzzleFlash::`vftable'{for `IClientUnknown'};
  _g_C_TEMuzzleFlash.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEMuzzleFlash::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEMuzzleFlash);
}
