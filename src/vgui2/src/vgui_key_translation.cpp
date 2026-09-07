// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/vgui_key_translation.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100174B0
// Name: enum ButtonCode_t KeyCode_VirtualKeyToVGUI(int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl KeyCode_VirtualKeyToVGUI(int key)
{
  if ( g_pInputSystem != nullptr )
    return g_pInputSystem->VirtualKeyToButtonCode(this: g_pInputSystem, a2: key);
  else
    return BUTTON_CODE_NONE;
}
