// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/vallocator.cpp
// Functions: 2
// ============================================================

#include "public\vallocator.h"

//------------------------------------------------------------------------------
// Address: 0x101EF320
// Name: public: virtual void __near * VStdAllocator::Alloc(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall VStdAllocator::Alloc(VStdAllocator *this, unsigned int size)
{
  if ( size != 0 )
    return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101EF350
// Name: public: virtual void VStdAllocator::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VStdAllocator::Free(VStdAllocator *this, void *ptr)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ptr);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101EF5D0
// Name: public: virtual void __near * VStdAllocator::Alloc(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall VStdAllocator::Alloc(VStdAllocator *this, unsigned int size)
{
  if ( size != 0 )
    return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101EF600
// Name: public: virtual void VStdAllocator::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VStdAllocator::Free(VStdAllocator *this, void *ptr)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ptr);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1017EC00
// Name: public: virtual void __near * VStdAllocator::Alloc(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall VStdAllocator::Alloc(VStdAllocator *this, unsigned int size)
{
  if ( size != 0 )
    return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017EC30
// Name: public: virtual void VStdAllocator::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VStdAllocator::Free(VStdAllocator *this, void *ptr)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x104170C0
// Name: _dynamic_initializer_for__locator_icon_min_size_non_ss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_icon_min_size_non_ss__()
{
  ConVar::ConVar(
    this: &locator_icon_min_size_non_ss,
    pName: "locator_icon_min_size_non_ss",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Minimum scale of the icon on the screen");
  return atexit(func: dynamic_atexit_destructor_for__locator_icon_min_size_non_ss__);
}

//------------------------------------------------------------------------------
// Address: 0x104170F0
// Name: _dynamic_initializer_for__locator_icon_max_size_non_ss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_icon_max_size_non_ss__()
{
  ConVar::ConVar(
    this: &locator_icon_max_size_non_ss,
    pName: "locator_icon_max_size_non_ss",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Minimum scale of the icon on the screen");
  return atexit(func: dynamic_atexit_destructor_for__locator_icon_max_size_non_ss__);
}

//------------------------------------------------------------------------------
// Address: 0x10417120
// Name: _dynamic_initializer_for__locator_fade_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_fade_time__()
{
  ConVar::ConVar(
    this: &locator_fade_time,
    pName: "locator_fade_time",
    pDefaultValue: "0.3",
    flags: 0,
    pHelpString: "Number of seconds it takes for a lesson to fully fade in/out.");
  return atexit(func: dynamic_atexit_destructor_for__locator_fade_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10417150
// Name: _dynamic_initializer_for__locator_lerp_speed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_lerp_speed__()
{
  ConVar::ConVar(
    this: &locator_lerp_speed,
    pName: "locator_lerp_speed",
    pDefaultValue: "5.0f",
    flags: 0,
    pHelpString: "Speed that static lessons move along the Y axis.");
  return atexit(func: dynamic_atexit_destructor_for__locator_lerp_speed__);
}

//------------------------------------------------------------------------------
// Address: 0x10417180
// Name: _dynamic_initializer_for__locator_lerp_rest__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_lerp_rest__()
{
  ConVar::ConVar(
    this: &locator_lerp_rest,
    pName: "locator_lerp_rest",
    pDefaultValue: "0.25f",
    flags: 0,
    pHelpString: "Number of seconds before moving from the center.");
  return atexit(func: dynamic_atexit_destructor_for__locator_lerp_rest__);
}

//------------------------------------------------------------------------------
// Address: 0x104171B0
// Name: _dynamic_initializer_for__locator_lerp_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_lerp_time__()
{
  ConVar::ConVar(
    this: &locator_lerp_time,
    pName: "locator_lerp_time",
    pDefaultValue: "1.75f",
    flags: 0,
    pHelpString: "Number of seconds to lerp before reaching final destination");
  return atexit(func: dynamic_atexit_destructor_for__locator_lerp_time__);
}

//------------------------------------------------------------------------------
// Address: 0x104171E0
// Name: _dynamic_initializer_for__locator_pulse_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_pulse_time__()
{
  ConVar::ConVar(
    this: &locator_pulse_time,
    pName: "locator_pulse_time",
    pDefaultValue: "1.0f",
    flags: 0,
    pHelpString: "Number of seconds to pulse after changing icon or position");
  return atexit(func: dynamic_atexit_destructor_for__locator_pulse_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10417210
// Name: _dynamic_initializer_for__locator_start_at_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_start_at_crosshair__()
{
  ConVar::ConVar(
    this: &locator_start_at_crosshair,
    pName: "locator_start_at_crosshair",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Start position at the crosshair instead of the top middle of the screen.");
  return atexit(func: dynamic_atexit_destructor_for__locator_start_at_crosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x10417240
// Name: _dynamic_initializer_for__locator_topdown_style__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_topdown_style__()
{
  ConVar::ConVar(
    this: &locator_topdown_style,
    pName: "locator_topdown_style",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Topdown games set this to handle distance and offscreen location differently.");
  return atexit(func: dynamic_atexit_destructor_for__locator_topdown_style__);
}

//------------------------------------------------------------------------------
// Address: 0x10417270
// Name: _dynamic_initializer_for__locator_background_style__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_style__()
{
  ConVar::ConVar(
    this: &locator_background_style,
    pName: "locator_background_style",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Setting this to 1 will show rectangle backgrounds behind the items word-bubble pointers.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_style__);
}

//------------------------------------------------------------------------------
// Address: 0x104172A0
// Name: _dynamic_initializer_for__locator_background_color__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_color__()
{
  ConVar::ConVar(
    this: &locator_background_color,
    pName: "locator_background_color",
    pDefaultValue: "36 36 36 160",
    flags: 0,
    pHelpString: "The default color for the background.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_color__);
}

//------------------------------------------------------------------------------
// Address: 0x104172D0
// Name: _dynamic_initializer_for__locator_background_border_color__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_border_color__()
{
  ConVar::ConVar(
    this: &locator_background_border_color,
    pName: "locator_background_border_color",
    pDefaultValue: "16 16 16 200",
    flags: 0,
    pHelpString: "The default color for the border.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_border_color__);
}

//------------------------------------------------------------------------------
// Address: 0x10417300
// Name: _dynamic_initializer_for__locator_background_thickness_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_thickness_x__()
{
  ConVar::ConVar(
    this: &locator_background_thickness_x,
    pName: "locator_background_thickness_x",
    pDefaultValue: "8",
    flags: 0,
    pHelpString: "How many pixels the background borders the left and right.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_thickness_x__);
}

//------------------------------------------------------------------------------
// Address: 0x10417330
// Name: _dynamic_initializer_for__locator_background_thickness_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_thickness_y__()
{
  ConVar::ConVar(
    this: &locator_background_thickness_y,
    pName: "locator_background_thickness_y",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "How many pixels the background borders the top and bottom.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_thickness_y__);
}

//------------------------------------------------------------------------------
// Address: 0x10417360
// Name: _dynamic_initializer_for__locator_background_shift_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_shift_x__()
{
  ConVar::ConVar(
    this: &locator_background_shift_x,
    pName: "locator_background_shift_x",
    pDefaultValue: "3",
    flags: 0,
    pHelpString: "How many pixels the background is shifted right.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_shift_x__);
}

//------------------------------------------------------------------------------
// Address: 0x10417390
// Name: _dynamic_initializer_for__locator_background_shift_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_shift_y__()
{
  ConVar::ConVar(
    this: &locator_background_shift_y,
    pName: "locator_background_shift_y",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "How many pixels the background is shifted down.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_shift_y__);
}

//------------------------------------------------------------------------------
// Address: 0x104173C0
// Name: _dynamic_initializer_for__locator_background_border_thickness__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_background_border_thickness__()
{
  ConVar::ConVar(
    this: &locator_background_border_thickness,
    pName: "locator_background_border_thickness",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "How many pixels the background borders the left and right.");
  return atexit(func: dynamic_atexit_destructor_for__locator_background_border_thickness__);
}

//------------------------------------------------------------------------------
// Address: 0x104173F0
// Name: _dynamic_initializer_for__locator_target_offset_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_target_offset_x__()
{
  ConVar::ConVar(
    this: &locator_target_offset_x,
    pName: "locator_target_offset_x",
    pDefaultValue: "-17",
    flags: 0,
    pHelpString: "How many pixels to offset the locator from the target position.");
  return atexit(func: dynamic_atexit_destructor_for__locator_target_offset_x__);
}

//------------------------------------------------------------------------------
// Address: 0x10417420
// Name: _dynamic_initializer_for__locator_target_offset_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_target_offset_y__()
{
  ConVar::ConVar(
    this: &locator_target_offset_y,
    pName: "locator_target_offset_y",
    pDefaultValue: "-64",
    flags: 0,
    pHelpString: "How many pixels to offset the locator from the target position.");
  return atexit(func: dynamic_atexit_destructor_for__locator_target_offset_y__);
}

//------------------------------------------------------------------------------
// Address: 0x10417450
// Name: _dynamic_initializer_for__locator_split_maxwide_percent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_split_maxwide_percent__()
{
  ConVar::ConVar(
    this: &locator_split_maxwide_percent,
    pName: "locator_split_maxwide_percent",
    pDefaultValue: "0.80f",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__locator_split_maxwide_percent__);
}

//------------------------------------------------------------------------------
// Address: 0x10417480
// Name: _dynamic_initializer_for__locator_split_len__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__locator_split_len__()
{
  ConVar::ConVar(this: &locator_split_len, pName: "locator_split_len", pDefaultValue: "0.5f", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__locator_split_len__);
}

//------------------------------------------------------------------------------
// Address: 0x10431CE0
// Name: _dynamic_atexit_destructor_for__locator_icon_min_size_non_ss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_icon_min_size_non_ss__()
{
  ConVar::~ConVar(this: &locator_icon_min_size_non_ss);
}

//------------------------------------------------------------------------------
// Address: 0x10431CF0
// Name: _dynamic_atexit_destructor_for__locator_icon_max_size_non_ss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_icon_max_size_non_ss__()
{
  ConVar::~ConVar(this: &locator_icon_max_size_non_ss);
}

//------------------------------------------------------------------------------
// Address: 0x10431D00
// Name: _dynamic_atexit_destructor_for__locator_fade_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_fade_time__()
{
  ConVar::~ConVar(this: &locator_fade_time);
}

//------------------------------------------------------------------------------
// Address: 0x10431D10
// Name: _dynamic_atexit_destructor_for__locator_lerp_speed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_lerp_speed__()
{
  ConVar::~ConVar(this: &locator_lerp_speed);
}

//------------------------------------------------------------------------------
// Address: 0x10431D20
// Name: _dynamic_atexit_destructor_for__locator_lerp_rest__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_lerp_rest__()
{
  ConVar::~ConVar(this: &locator_lerp_rest);
}

//------------------------------------------------------------------------------
// Address: 0x10431D30
// Name: _dynamic_atexit_destructor_for__locator_lerp_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_lerp_time__()
{
  ConVar::~ConVar(this: &locator_lerp_time);
}

//------------------------------------------------------------------------------
// Address: 0x10431D40
// Name: _dynamic_atexit_destructor_for__locator_pulse_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_pulse_time__()
{
  ConVar::~ConVar(this: &locator_pulse_time);
}

//------------------------------------------------------------------------------
// Address: 0x10431D50
// Name: _dynamic_atexit_destructor_for__locator_start_at_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_start_at_crosshair__()
{
  ConVar::~ConVar(this: &locator_start_at_crosshair);
}

//------------------------------------------------------------------------------
// Address: 0x10431D60
// Name: _dynamic_atexit_destructor_for__locator_topdown_style__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_topdown_style__()
{
  ConVar::~ConVar(this: &locator_topdown_style);
}

//------------------------------------------------------------------------------
// Address: 0x10431D70
// Name: _dynamic_atexit_destructor_for__locator_background_style__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_style__()
{
  ConVar::~ConVar(this: &locator_background_style);
}

//------------------------------------------------------------------------------
// Address: 0x10431D80
// Name: _dynamic_atexit_destructor_for__locator_background_color__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_color__()
{
  ConVar::~ConVar(this: &locator_background_color);
}

//------------------------------------------------------------------------------
// Address: 0x10431D90
// Name: _dynamic_atexit_destructor_for__locator_background_border_color__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_border_color__()
{
  ConVar::~ConVar(this: &locator_background_border_color);
}

//------------------------------------------------------------------------------
// Address: 0x10431DA0
// Name: _dynamic_atexit_destructor_for__locator_background_thickness_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_thickness_x__()
{
  ConVar::~ConVar(this: &locator_background_thickness_x);
}

//------------------------------------------------------------------------------
// Address: 0x10431DB0
// Name: _dynamic_atexit_destructor_for__locator_background_thickness_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_thickness_y__()
{
  ConVar::~ConVar(this: &locator_background_thickness_y);
}

//------------------------------------------------------------------------------
// Address: 0x10431DC0
// Name: _dynamic_atexit_destructor_for__locator_background_shift_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_shift_x__()
{
  ConVar::~ConVar(this: &locator_background_shift_x);
}

//------------------------------------------------------------------------------
// Address: 0x10431DD0
// Name: _dynamic_atexit_destructor_for__locator_background_shift_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_shift_y__()
{
  ConVar::~ConVar(this: &locator_background_shift_y);
}

//------------------------------------------------------------------------------
// Address: 0x10431DE0
// Name: _dynamic_atexit_destructor_for__locator_background_border_thickness__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_background_border_thickness__()
{
  ConVar::~ConVar(this: &locator_background_border_thickness);
}

//------------------------------------------------------------------------------
// Address: 0x10431DF0
// Name: _dynamic_atexit_destructor_for__locator_target_offset_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_target_offset_x__()
{
  ConVar::~ConVar(this: &locator_target_offset_x);
}

//------------------------------------------------------------------------------
// Address: 0x10431E00
// Name: _dynamic_atexit_destructor_for__locator_target_offset_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_target_offset_y__()
{
  ConVar::~ConVar(this: &locator_target_offset_y);
}

//------------------------------------------------------------------------------
// Address: 0x10431E10
// Name: _dynamic_atexit_destructor_for__locator_split_maxwide_percent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_split_maxwide_percent__()
{
  ConVar::~ConVar(this: &locator_split_maxwide_percent);
}

//------------------------------------------------------------------------------
// Address: 0x10431E20
// Name: _dynamic_atexit_destructor_for__locator_split_len__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__locator_split_len__()
{
  ConVar::~ConVar(this: &locator_split_len);
}

//------------------------------------------------------------------------------
// Address: 0x10431E30
// Name: _dynamic_atexit_destructor_for__fov_watcher__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fov_watcher__()
{
  ConVar::~ConVar(this: &fov_watcher);
}

//------------------------------------------------------------------------------
// Address: 0x10431E40
// Name: _dynamic_atexit_destructor_for__hud_subtitles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_subtitles_command__()
{
  ConCommand::~ConCommand(this: &hud_subtitles_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431E50
// Name: _dynamic_atexit_destructor_for__s_GameSystems__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameSystems__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameSystems);
}

//------------------------------------------------------------------------------
// Address: 0x10431E60
// Name: _dynamic_atexit_destructor_for__s_GameSystemsPerFrame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameSystemsPerFrame__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameSystemsPerFrame);
}

//------------------------------------------------------------------------------
// Address: 0x10431E70
// Name: _dynamic_atexit_destructor_for__cam_snapto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_snapto__()
{
  ConVar::~ConVar(this: &cam_snapto);
}

//------------------------------------------------------------------------------
// Address: 0x10431E80
// Name: _dynamic_atexit_destructor_for__cam_ideallag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_ideallag__()
{
  ConVar::~ConVar(this: &cam_ideallag);
}

//------------------------------------------------------------------------------
// Address: 0x10431E90
// Name: _dynamic_atexit_destructor_for__cam_idealdelta__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_idealdelta__()
{
  ConVar::~ConVar(this: &cam_idealdelta);
}

//------------------------------------------------------------------------------
// Address: 0x10431EA0
// Name: _dynamic_atexit_destructor_for__cam_idealyaw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_idealyaw__()
{
  ConVar::~ConVar(this: &cam_idealyaw);
}

//------------------------------------------------------------------------------
// Address: 0x10431EB0
// Name: _dynamic_atexit_destructor_for__cam_idealpitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_idealpitch__()
{
  ConVar::~ConVar(this: &cam_idealpitch);
}

//------------------------------------------------------------------------------
// Address: 0x10431EC0
// Name: _dynamic_atexit_destructor_for__cam_idealdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_idealdist__()
{
  ConVar::~ConVar(this: &cam_idealdist);
}

//------------------------------------------------------------------------------
// Address: 0x10431ED0
// Name: _dynamic_atexit_destructor_for__cam_idealdistright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_idealdistright__()
{
  ConVar::~ConVar(this: &cam_idealdistright);
}

//------------------------------------------------------------------------------
// Address: 0x10431EE0
// Name: _dynamic_atexit_destructor_for__cam_idealdistup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_idealdistup__()
{
  ConVar::~ConVar(this: &cam_idealdistup);
}

//------------------------------------------------------------------------------
// Address: 0x10431EF0
// Name: _dynamic_atexit_destructor_for__cam_collision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_collision__()
{
  ConVar::~ConVar(this: &cam_collision);
}

//------------------------------------------------------------------------------
// Address: 0x10431F00
// Name: _dynamic_atexit_destructor_for__cam_showangles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_showangles__()
{
  ConVar::~ConVar(this: &cam_showangles);
}

//------------------------------------------------------------------------------
// Address: 0x10431F10
// Name: _dynamic_atexit_destructor_for__c_maxpitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_maxpitch__()
{
  ConVar::~ConVar(this: &c_maxpitch);
}

//------------------------------------------------------------------------------
// Address: 0x10431F20
// Name: _dynamic_atexit_destructor_for__c_minpitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_minpitch__()
{
  ConVar::~ConVar(this: &c_minpitch);
}

//------------------------------------------------------------------------------
// Address: 0x10431F30
// Name: _dynamic_atexit_destructor_for__c_maxyaw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_maxyaw__()
{
  ConVar::~ConVar(this: &c_maxyaw);
}

//------------------------------------------------------------------------------
// Address: 0x10431F40
// Name: _dynamic_atexit_destructor_for__c_minyaw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_minyaw__()
{
  ConVar::~ConVar(this: &c_minyaw);
}

//------------------------------------------------------------------------------
// Address: 0x10431F50
// Name: _dynamic_atexit_destructor_for__c_maxdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_maxdistance__()
{
  ConVar::~ConVar(this: &c_maxdistance);
}

//------------------------------------------------------------------------------
// Address: 0x10431F60
// Name: _dynamic_atexit_destructor_for__c_mindistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_mindistance__()
{
  ConVar::~ConVar(this: &c_mindistance);
}

//------------------------------------------------------------------------------
// Address: 0x10431F70
// Name: _dynamic_atexit_destructor_for__c_orthowidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_orthowidth__()
{
  ConVar::~ConVar(this: &c_orthowidth);
}

//------------------------------------------------------------------------------
// Address: 0x10431F80
// Name: _dynamic_atexit_destructor_for__c_orthoheight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_orthoheight__()
{
  ConVar::~ConVar(this: &c_orthoheight);
}

//------------------------------------------------------------------------------
// Address: 0x10431F90
// Name: _dynamic_atexit_destructor_for__c_thirdpersonshoulder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_thirdpersonshoulder__()
{
  ConVar::~ConVar(this: &c_thirdpersonshoulder_0);
}

//------------------------------------------------------------------------------
// Address: 0x10431FA0
// Name: _dynamic_atexit_destructor_for__c_thirdpersonshoulderoffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_thirdpersonshoulderoffset__()
{
  ConVar::~ConVar(this: &c_thirdpersonshoulderoffset_0);
}

//------------------------------------------------------------------------------
// Address: 0x10431FB0
// Name: _dynamic_atexit_destructor_for__c_thirdpersonshoulderdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_thirdpersonshoulderdist__()
{
  ConVar::~ConVar(this: &c_thirdpersonshoulderdist);
}

//------------------------------------------------------------------------------
// Address: 0x10431FC0
// Name: _dynamic_atexit_destructor_for__c_thirdpersonshoulderheight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_thirdpersonshoulderheight__()
{
  ConVar::~ConVar(this: &c_thirdpersonshoulderheight_0);
}

//------------------------------------------------------------------------------
// Address: 0x10431FD0
// Name: _dynamic_atexit_destructor_for__c_thirdpersonshoulderaimdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__c_thirdpersonshoulderaimdist__()
{
  ConVar::~ConVar(this: &c_thirdpersonshoulderaimdist_0);
}

//------------------------------------------------------------------------------
// Address: 0x10431FE0
// Name: _dynamic_atexit_destructor_for__cam_command_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cam_command_command__()
{
  ConCommand::~ConCommand(this: &cam_command_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431FF0
// Name: _dynamic_atexit_destructor_for__startpitchup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startpitchup__()
{
  ConCommand::~ConCommand(this: &startpitchup);
}

//------------------------------------------------------------------------------
// Address: 0x10432000
// Name: _dynamic_atexit_destructor_for__endpitcup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endpitcup__()
{
  ConCommand::~ConCommand(this: &endpitcup);
}

//------------------------------------------------------------------------------
// Address: 0x10432010
// Name: _dynamic_atexit_destructor_for__startpitchdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startpitchdown__()
{
  ConCommand::~ConCommand(this: &startpitchdown);
}

//------------------------------------------------------------------------------
// Address: 0x10432020
// Name: _dynamic_atexit_destructor_for__endpitchdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endpitchdown__()
{
  ConCommand::~ConCommand(this: &endpitchdown);
}

//------------------------------------------------------------------------------
// Address: 0x10432030
// Name: _dynamic_atexit_destructor_for__startcamyawleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startcamyawleft__()
{
  ConCommand::~ConCommand(this: &startcamyawleft);
}

//------------------------------------------------------------------------------
// Address: 0x10432040
// Name: _dynamic_atexit_destructor_for__endcamyawleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endcamyawleft__()
{
  ConCommand::~ConCommand(this: &endcamyawleft);
}

//------------------------------------------------------------------------------
// Address: 0x10432050
// Name: _dynamic_atexit_destructor_for__startcamyawright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startcamyawright__()
{
  ConCommand::~ConCommand(this: &startcamyawright);
}

//------------------------------------------------------------------------------
// Address: 0x10432060
// Name: _dynamic_atexit_destructor_for__endcamyawright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endcamyawright__()
{
  ConCommand::~ConCommand(this: &endcamyawright);
}

//------------------------------------------------------------------------------
// Address: 0x10432070
// Name: _dynamic_atexit_destructor_for__startcamin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startcamin__()
{
  ConCommand::~ConCommand(this: &startcamin);
}

//------------------------------------------------------------------------------
// Address: 0x10432080
// Name: _dynamic_atexit_destructor_for__endcamin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endcamin__()
{
  ConCommand::~ConCommand(this: &endcamin);
}

//------------------------------------------------------------------------------
// Address: 0x10432090
// Name: _dynamic_atexit_destructor_for__startcamout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startcamout__()
{
  ConCommand::~ConCommand(this: &startcamout);
}

//------------------------------------------------------------------------------
// Address: 0x104320A0
// Name: _dynamic_atexit_destructor_for__camout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__camout__()
{
  ConCommand::~ConCommand(this: &camout);
}

//------------------------------------------------------------------------------
// Address: 0x104320B0
// Name: _dynamic_atexit_destructor_for__thirdperson__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thirdperson__()
{
  ConCommand::~ConCommand(this: &thirdperson);
}

//------------------------------------------------------------------------------
// Address: 0x104320C0
// Name: _dynamic_atexit_destructor_for__thirdperson_mayamode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thirdperson_mayamode__()
{
  ConCommand::~ConCommand(this: &thirdperson_mayamode);
}

//------------------------------------------------------------------------------
// Address: 0x104320D0
// Name: _dynamic_atexit_destructor_for__firstperson__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__firstperson__()
{
  ConCommand::~ConCommand(this: &firstperson);
}

//------------------------------------------------------------------------------
// Address: 0x104320E0
// Name: _dynamic_atexit_destructor_for__thirdpersonshoulder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thirdpersonshoulder__()
{
  ConCommand::~ConCommand(this: &thirdpersonshoulder);
}

//------------------------------------------------------------------------------
// Address: 0x104320F0
// Name: _dynamic_atexit_destructor_for__camortho__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__camortho__()
{
  ConCommand::~ConCommand(this: &camortho);
}

//------------------------------------------------------------------------------
// Address: 0x10432100
// Name: _dynamic_atexit_destructor_for__startcammousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startcammousemove__()
{
  ConCommand::~ConCommand(this: &startcammousemove);
}

//------------------------------------------------------------------------------
// Address: 0x10432110
// Name: _dynamic_atexit_destructor_for__endcammousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endcammousemove__()
{
  ConCommand::~ConCommand(this: &endcammousemove);
}

//------------------------------------------------------------------------------
// Address: 0x10432120
// Name: _dynamic_atexit_destructor_for__startcamdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startcamdistance__()
{
  ConCommand::~ConCommand(this: &startcamdistance);
}

//------------------------------------------------------------------------------
// Address: 0x10432130
// Name: _dynamic_atexit_destructor_for__endcamdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endcamdistance__()
{
  ConCommand::~ConCommand(this: &endcamdistance);
}

//------------------------------------------------------------------------------
// Address: 0x10432140
// Name: _dynamic_atexit_destructor_for__snapto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__snapto__()
{
  ConCommand::~ConCommand(this: &snapto);
}

//------------------------------------------------------------------------------
// Address: 0x10432150
// Name: _dynamic_atexit_destructor_for__joy_variable_frametime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_variable_frametime__()
{
  ConVar::~ConVar(this: &joy_variable_frametime);
}

//------------------------------------------------------------------------------
// Address: 0x10432160
// Name: _dynamic_atexit_destructor_for__joy_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_name__()
{
  ConVar::~ConVar(this: &joy_name);
}

//------------------------------------------------------------------------------
// Address: 0x10432170
// Name: _dynamic_atexit_destructor_for__joy_advanced__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_advanced__()
{
  ConVar::~ConVar(this: &joy_advanced);
}

//------------------------------------------------------------------------------
// Address: 0x10432180
// Name: _dynamic_atexit_destructor_for__joy_advaxisx__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_advaxisx__()
{
  ConVar::~ConVar(this: &joy_advaxisx);
}

//------------------------------------------------------------------------------
// Address: 0x10432190
// Name: _dynamic_atexit_destructor_for__joy_advaxisy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_advaxisy__()
{
  ConVar::~ConVar(this: &joy_advaxisy);
}

//------------------------------------------------------------------------------
// Address: 0x104321A0
// Name: _dynamic_atexit_destructor_for__joy_advaxisz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_advaxisz__()
{
  ConVar::~ConVar(this: &joy_advaxisz);
}

//------------------------------------------------------------------------------
// Address: 0x104321B0
// Name: _dynamic_atexit_destructor_for__joy_advaxisr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_advaxisr__()
{
  ConVar::~ConVar(this: &joy_advaxisr);
}

//------------------------------------------------------------------------------
// Address: 0x104321C0
// Name: _dynamic_atexit_destructor_for__joy_advaxisu__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_advaxisu__()
{
  ConVar::~ConVar(this: &joy_advaxisu);
}

//------------------------------------------------------------------------------
// Address: 0x104321D0
// Name: _dynamic_atexit_destructor_for__joy_advaxisv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_advaxisv__()
{
  ConVar::~ConVar(this: &joy_advaxisv);
}

//------------------------------------------------------------------------------
// Address: 0x104321E0
// Name: _dynamic_atexit_destructor_for__joy_forwardthreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_forwardthreshold__()
{
  ConVar::~ConVar(this: &joy_forwardthreshold);
}

//------------------------------------------------------------------------------
// Address: 0x104321F0
// Name: _dynamic_atexit_destructor_for__joy_sidethreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_sidethreshold__()
{
  ConVar::~ConVar(this: &joy_sidethreshold);
}

//------------------------------------------------------------------------------
// Address: 0x10432200
// Name: _dynamic_atexit_destructor_for__joy_pitchthreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_pitchthreshold__()
{
  ConVar::~ConVar(this: &joy_pitchthreshold);
}

//------------------------------------------------------------------------------
// Address: 0x10432210
// Name: _dynamic_atexit_destructor_for__joy_yawthreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_yawthreshold__()
{
  ConVar::~ConVar(this: &joy_yawthreshold);
}

//------------------------------------------------------------------------------
// Address: 0x10432220
// Name: _dynamic_atexit_destructor_for__joy_forwardsensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_forwardsensitivity__()
{
  ConVar::~ConVar(this: &joy_forwardsensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x10432230
// Name: _dynamic_atexit_destructor_for__joy_sidesensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_sidesensitivity__()
{
  ConVar::~ConVar(this: &joy_sidesensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x10432240
// Name: _dynamic_atexit_destructor_for__joy_pitchsensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_pitchsensitivity__()
{
  ConVar::~ConVar(this: &joy_pitchsensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x10432250
// Name: _dynamic_atexit_destructor_for__joy_yawsensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_yawsensitivity__()
{
  ConVar::~ConVar(this: &joy_yawsensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x10432260
// Name: _dynamic_atexit_destructor_for__joy_response_move__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_response_move__()
{
  ConVar::~ConVar(this: &joy_response_move);
}

//------------------------------------------------------------------------------
// Address: 0x10432270
// Name: _dynamic_atexit_destructor_for__joy_response_move_vehicle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_response_move_vehicle__()
{
  ConVar::~ConVar(this: &joy_response_move_vehicle);
}

//------------------------------------------------------------------------------
// Address: 0x10432280
// Name: _dynamic_atexit_destructor_for__joy_response_look__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_response_look__()
{
  ConVar::~ConVar(this: &joy_response_look);
}

//------------------------------------------------------------------------------
// Address: 0x10432290
// Name: _dynamic_atexit_destructor_for__joy_response_look_pitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_response_look_pitch__()
{
  ConVar::~ConVar(this: &joy_response_look_pitch);
}

//------------------------------------------------------------------------------
// Address: 0x104322A0
// Name: _dynamic_atexit_destructor_for__joy_lowend__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_lowend__()
{
  ConVar::~ConVar(this: &joy_lowend);
}

//------------------------------------------------------------------------------
// Address: 0x104322B0
// Name: _dynamic_atexit_destructor_for__joy_lowmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_lowmap__()
{
  ConVar::~ConVar(this: &joy_lowmap);
}

//------------------------------------------------------------------------------
// Address: 0x104322C0
// Name: _dynamic_atexit_destructor_for__joy_gamma__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_gamma__()
{
  ConVar::~ConVar(this: &joy_gamma);
}

//------------------------------------------------------------------------------
// Address: 0x104322D0
// Name: _dynamic_atexit_destructor_for__joy_accelscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_accelscale__()
{
  ConVar::~ConVar(this: &joy_accelscale);
}

//------------------------------------------------------------------------------
// Address: 0x104322E0
// Name: _dynamic_atexit_destructor_for__joy_accelmax__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_accelmax__()
{
  ConVar::~ConVar(this: &joy_accelmax);
}

//------------------------------------------------------------------------------
// Address: 0x104322F0
// Name: _dynamic_atexit_destructor_for__joy_autoaimdampenrange__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_autoaimdampenrange__()
{
  ConVar::~ConVar(this: &joy_autoaimdampenrange);
}

//------------------------------------------------------------------------------
// Address: 0x10432300
// Name: _dynamic_atexit_destructor_for__joy_autoaimdampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_autoaimdampen__()
{
  ConVar::~ConVar(this: &joy_autoaimdampen);
}

//------------------------------------------------------------------------------
// Address: 0x10432310
// Name: _dynamic_atexit_destructor_for__joy_autoaim_dampen_smoothout_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_autoaim_dampen_smoothout_speed__()
{
  ConVar::~ConVar(this: &joy_autoaim_dampen_smoothout_speed);
}

//------------------------------------------------------------------------------
// Address: 0x10432320
// Name: _dynamic_atexit_destructor_for__joy_vehicle_turn_lowend__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_vehicle_turn_lowend__()
{
  ConVar::~ConVar(this: &joy_vehicle_turn_lowend);
}

//------------------------------------------------------------------------------
// Address: 0x10432330
// Name: _dynamic_atexit_destructor_for__joy_vehicle_turn_lowmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_vehicle_turn_lowmap__()
{
  ConVar::~ConVar(this: &joy_vehicle_turn_lowmap);
}

//------------------------------------------------------------------------------
// Address: 0x10432340
// Name: _dynamic_atexit_destructor_for__joy_sensitive_step0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_sensitive_step0__()
{
  ConVar::~ConVar(this: &joy_sensitive_step0);
}

//------------------------------------------------------------------------------
// Address: 0x10432350
// Name: _dynamic_atexit_destructor_for__joy_sensitive_step1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_sensitive_step1__()
{
  ConVar::~ConVar(this: &joy_sensitive_step1);
}

//------------------------------------------------------------------------------
// Address: 0x10432360
// Name: _dynamic_atexit_destructor_for__joy_sensitive_step2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_sensitive_step2__()
{
  ConVar::~ConVar(this: &joy_sensitive_step2);
}

//------------------------------------------------------------------------------
// Address: 0x10432370
// Name: _dynamic_atexit_destructor_for__joy_circle_correct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_circle_correct__()
{
  ConVar::~ConVar(this: &joy_circle_correct);
}

//------------------------------------------------------------------------------
// Address: 0x10432380
// Name: _dynamic_atexit_destructor_for__joy_diagonalpov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_diagonalpov__()
{
  ConVar::~ConVar(this: &joy_diagonalpov);
}

//------------------------------------------------------------------------------
// Address: 0x10432390
// Name: _dynamic_atexit_destructor_for__joy_display_input__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_display_input__()
{
  ConVar::~ConVar(this: &joy_display_input);
}

//------------------------------------------------------------------------------
// Address: 0x104323A0
// Name: _dynamic_atexit_destructor_for__joy_wwhack2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_wwhack2__()
{
  ConVar::~ConVar(this: &joy_wwhack2);
}

//------------------------------------------------------------------------------
// Address: 0x104323B0
// Name: _dynamic_atexit_destructor_for__joy_autosprint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_autosprint__()
{
  ConVar::~ConVar(this: &joy_autosprint);
}

//------------------------------------------------------------------------------
// Address: 0x104323C0
// Name: _dynamic_atexit_destructor_for__joy_inverty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_inverty__()
{
  ConVar::~ConVar(this: &joy_inverty);
}

} // namespace client
