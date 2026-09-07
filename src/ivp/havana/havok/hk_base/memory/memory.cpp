// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_base/memory/memory.cpp
// Functions: 13
// ============================================================

#include "ivp\havana\havok\hk_base\memory\memory.h"

//------------------------------------------------------------------------------
// Address: 0x10043EA0
// Name: public: void __near * hk_Memory::allocate(int,enum hk_MEMORY_CLASS)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall hk_Memory::allocate(hk_Memory *this, unsigned int size, hk_MEMORY_CLASS cl)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size);
}

//------------------------------------------------------------------------------
// Address: 0x10043EC0
// Name: public: void hk_Memory::deallocate(void __near *,int,enum hk_MEMORY_CLASS)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Memory::deallocate(hk_Memory *this, void *p, int size, hk_MEMORY_CLASS cl)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p);
}

//------------------------------------------------------------------------------
// Address: 0x10043EE0
// Name: public: static class hk_Memory __near * hk_Memory::get_instance(void)
// Source: json
//------------------------------------------------------------------------------
hk_Memory *__cdecl hk_Memory::get_instance()
{
  if ( (_S1_6 & 1) == 0 )
  {
    _S1_6 |= 1u;
    atexit(func: hk_Memory::get_instance_::_2_::_dynamic_atexit_destructor_for__s_memory_instance__);
  }
  return &s_memory_instance;
}

//------------------------------------------------------------------------------
// Address: 0x100C7210
// Name: _hk_Memory::get_instance_::_2_::_dynamic_atexit_destructor_for__s_memory_instance__
// Source: json
//------------------------------------------------------------------------------
void __cdecl hk_Memory::get_instance_::_2_::_dynamic_atexit_destructor_for__s_memory_instance__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100C7220
// Name: _dynamic_atexit_destructor_for__IVP_Controller_Independent::empty_list__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__IVP_Controller_Independent::empty_list__()
{
  if ( (Vector2D *)IVP_Controller_Independent::empty_list.elems == &vec2_origin_61 )
  {
    IVP_Controller_Independent::empty_list.n_elems = 0;
  }
  else
  {
    if ( IVP_Controller_Independent::empty_list.elems != nullptr )
      free(data: IVP_Controller_Independent::empty_list.elems);
    IVP_Controller_Independent::empty_list.elems = nullptr;
    *(_DWORD *)&IVP_Controller_Independent::empty_list.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7260
// Name: _dynamic_atexit_destructor_for__IVP_Environment_Manager::static_environment_manager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__IVP_Environment_Manager::static_environment_manager__()
{
  if ( (Vector2D *)IVP_Environment_Manager::static_environment_manager.environments.elems == &vec2_origin_71 )
  {
    IVP_Environment_Manager::static_environment_manager.environments.n_elems = 0;
  }
  else
  {
    if ( IVP_Environment_Manager::static_environment_manager.environments.elems != nullptr )
      free(data: IVP_Environment_Manager::static_environment_manager.environments.elems);
    IVP_Environment_Manager::static_environment_manager.environments.elems = nullptr;
    *(_DWORD *)&IVP_Environment_Manager::static_environment_manager.environments.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C72A0
// Name: _dynamic_atexit_destructor_for__ivp_debugmanager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ivp_debugmanager__()
{
  ivp_debugmanager.__vftable = (IVP_BetterDebugmanager_vtbl *)&IVP_BetterDebugmanager::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C72B0
// Name: _dynamic_atexit_destructor_for__ivp_surface_manager_ball_global__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ivp_surface_manager_ball_global__()
{
  ivp_surface_manager_ball_global.__vftable = (IVP_SurfaceManager_Ball_vtbl *)&IVP_SurfaceManager_Ball::`vftable';
  if ( ivp_surface_manager_ball_global.compact_ledge != nullptr )
  {
    ivp_free_aligned(data: (void *)ivp_surface_manager_ball_global.compact_ledge);
    ivp_surface_manager_ball_global.compact_ledge = nullptr;
  }
  IVP_SurfaceManager::~IVP_SurfaceManager(this: &ivp_surface_manager_ball_global);
}

//------------------------------------------------------------------------------
// Address: 0x100C72E0
// Name: _dynamic_atexit_destructor_for__s_TempMemoryPolyhedron__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TempMemoryPolyhedron__()
{
  s_TempMemoryPolyhedron.__vftable = (CPolyhedron_TempMemory_vtbl *)&CPolyhedron::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C72F0
// Name: _dynamic_atexit_destructor_for__s_TempMemoryPolyhedron_Buffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TempMemoryPolyhedron_Buffer__()
{
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_TempMemoryPolyhedron_Buffer);
}

//------------------------------------------------------------------------------
// Address: 0x100C7300
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(data: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C7350
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(data: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C7390
// Name: _dynamic_atexit_destructor_for__hk_Console::m_default_console_buffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hk_Console::m_default_console_buffer__()
{
  hk_Console::m_default_console_buffer.__vftable = (hk_Console_vtbl *)&hk_Console::`vftable';
}
