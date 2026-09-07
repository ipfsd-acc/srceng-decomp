// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/vgui_tools.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102C30B0
// Name: bool VGui_Startup(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VGui_Startup(void *(__cdecl *appSystemFactory)(const char *, int *))
{
  CFoundryTool *v1; // ecx
  const char *VGuiControlsModuleName; // eax

  VGuiControlsModuleName = GetVGuiControlsModuleName(this: v1);
  return vgui::VGui_InitDmeInterfacesList(
           moduleName: VGuiControlsModuleName,
           factoryList: &appSystemFactory,
           numFactories: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102C30D0
// Name: void VGui_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VGui_Shutdown(vgui::ToolWindow *this)
{
  CDmeFXClip::OnDestruction(this);
  g_pVGui->RunFrame(this: g_pVGui);
}
