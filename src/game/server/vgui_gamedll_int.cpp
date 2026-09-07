// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/vgui_gamedll_int.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1025C110
// Name: bool VGui_Startup(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VGui_Startup(void *(__cdecl *appSystemFactory)(const char *, int *))
{
  return vgui::VGui_InitInterfacesList(moduleName: "GAMEDLL", factoryList: &appSystemFactory, numFactories: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1025C130
// Name: bool VGui_PostInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VGui_PostInit()
{
  return enginevgui->GetPanel(this: enginevgui, a2: PANEL_GAMEDLL) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025C150
// Name: void VGui_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_Shutdown()
{
  g_pVGui->RunFrame(this: g_pVGui);
}
