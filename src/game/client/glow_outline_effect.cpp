// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/glow_outline_effect.cpp
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x104166C0
// Name: _dynamic_initializer_for__glow_outline_effect_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__glow_outline_effect_enable__()
{
  ConVar::ConVar(
    this: &glow_outline_effect_enable,
    pName: "glow_outline_effect_enable",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable entity outline glow effects.");
  return atexit(func: dynamic_atexit_destructor_for__glow_outline_effect_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x104166F0
// Name: _dynamic_initializer_for__glow_outline_effect_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__glow_outline_effect_width__()
{
  ConVar::ConVar(
    this: &glow_outline_effect_width,
    pName: "glow_outline_width",
    pDefaultValue: "6.0f",
    flags: 0x4000,
    pHelpString: "Width of glow outline effect in screen space.");
  return atexit(func: dynamic_atexit_destructor_for__glow_outline_effect_width__);
}

//------------------------------------------------------------------------------
// Address: 0x104319A0
// Name: _dynamic_atexit_destructor_for__glow_outline_effect_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__glow_outline_effect_enable__()
{
  ConVar::~ConVar(this: &glow_outline_effect_enable);
}

//------------------------------------------------------------------------------
// Address: 0x104319B0
// Name: _dynamic_atexit_destructor_for__glow_outline_effect_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__glow_outline_effect_width__()
{
  ConVar::~ConVar(this: &glow_outline_effect_width);
}

//------------------------------------------------------------------------------
// Address: 0x10416720
// Name: _dynamic_initializer_for__g_GlowObjectManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GlowObjectManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_GlowObjectManager__);
}

//------------------------------------------------------------------------------
// Address: 0x104319C0
// Name: _dynamic_atexit_destructor_for__g_GlowObjectManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GlowObjectManager__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_GlowObjectManager);
}

//------------------------------------------------------------------------------
// Address: 0x104319D0
// Name: _dynamic_atexit_destructor_for__cl_ShowSunVectors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ShowSunVectors__()
{
  ConVar::~ConVar(this: &cl_ShowSunVectors);
}

//------------------------------------------------------------------------------
// Address: 0x104319E0
// Name: _dynamic_atexit_destructor_for__cl_sun_decay_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_sun_decay_rate__()
{
  ConVar::~ConVar(this: &cl_sun_decay_rate);
}

//------------------------------------------------------------------------------
// Address: 0x104319F0
// Name: _dynamic_atexit_destructor_for__building_cubemaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__building_cubemaps__()
{
  ConVar::~ConVar(this: &building_cubemaps);
}

//------------------------------------------------------------------------------
// Address: 0x10431A00
// Name: _dynamic_atexit_destructor_for__g_GlowOverlaySystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GlowOverlaySystem__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_GlowOverlaySystem.m_GlowOverlays);
  if ( g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory);
      g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory = nullptr;
    }
    g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystem::~IGameSystem(this: &g_GlowOverlaySystem);
}

//------------------------------------------------------------------------------
// Address: 0x10431A50
// Name: _dynamic_atexit_destructor_for__cl_showhelp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showhelp__()
{
  ConVar::~ConVar(this: &cl_showhelp);
}

//------------------------------------------------------------------------------
// Address: 0x10431A60
// Name: _dynamic_atexit_destructor_for__cl_clearhinthistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clearhinthistory__()
{
  ConCommand::~ConCommand(this: &cl_clearhinthistory);
}
