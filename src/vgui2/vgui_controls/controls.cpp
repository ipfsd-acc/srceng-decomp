// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/controls.cpp
// Functions: 2
// ============================================================

#include "vgui2\vgui_controls\controls.h"

//------------------------------------------------------------------------------
// Address: 0x102D2C90
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  CEngineSingleUserFilter *v1; // ecx

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( CAudioSourceMP3::SampleSize(this: v1) != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2, _locale: defaultValue);
  setlocale(_category: 5, _locale: defaultValue);
  setlocale(_category: 1, _locale: defaultValue);
  setlocale(_category: 3, _locale: defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102D2D50
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10015830
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100158F0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0044FB10
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2, _locale: defaultValue);
  setlocale(_category: 5, _locale: defaultValue);
  setlocale(_category: 1, _locale: defaultValue);
  setlocale(_category: 3, _locale: defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044FBD0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10036A10
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036AD0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00627C50
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  CBaseAppSystem<IParticleSystemQuery> *v1; // ecx

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( CDmeTypedLog<bool>::GetNumBookmarkComponents(this: v1) != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00627D10
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D2D20
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  CEngineSingleUserFilter *v1; // ecx

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( CAudioSourceMP3::SampleSize(this: v1) != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102D2DE0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102DCE20
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  CBaseAppSystem<IParticleSystemQuery> *v1; // ecx
  const char *savedregs; // [esp+0h] [ebp+0h]

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( CDmeTypedLog<bool>::GetNumBookmarkComponents(this: v1) != 1 )
    _Error(this: (ISceneTokenProcessor *)&stru_1065B308, a2: savedregs);
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)&var);
  setlocale(_category: 5u, _locale: (char *)&var);
  setlocale(_category: 1u, _locale: (char *)&var);
  setlocale(_category: 3u, _locale: (char *)&var);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102DCEE0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100CFF90
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00470330
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004703F0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00429510
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004295D0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0065E0F0
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  CBaseAppSystem<IParticleSystemQuery> *v1; // ecx

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( CDmeTypedLog<bool>::GetNumBookmarkComponents(this: v1) != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0065E1B0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10061640
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10061700
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1005EBB0
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( ATI_Compress::CCodec::GetBlockHeight() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005EC70
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004686C0
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)&defaultValue);
  setlocale(_category: 5u, _locale: (char *)&defaultValue);
  setlocale(_category: 1u, _locale: (char *)&defaultValue);
  setlocale(_category: 3u, _locale: (char *)&defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00468780
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004A7FE0
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  CDmSerializerKeyValues2 *v1; // ecx

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( CDmElementFramework::Init(this: v1) != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004A80A0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0041EFF0
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F0B0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00410E70
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( _heapmin() != 1 )
    _Error(a1: "Must include memoverride.cpp in your project.");
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410F30
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103BD1F0
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  C_OP_RenderPoints *v1; // ecx
  const char *savedregs; // [esp+0h] [ebp+0h]

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( C_OP_ConstrainDistance::GetWrittenAttributes(this: v1) != 1 )
    _Error(this: (ISceneTokenProcessor *)&stru_1054C8D0, a2: savedregs);
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)prType);
  setlocale(_category: 5u, _locale: (char *)prType);
  setlocale(_category: 1u, _locale: (char *)prType);
  setlocale(_category: 3u, _locale: (char *)prType);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103BD2B0
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103BFF60
// Name: bool vgui::VGui_InitInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::VGui_InitInterfacesList(char *moduleName)
{
  CBaseCombatWeapon *v1; // ecx
  const char *savedregs; // [esp+0h] [ebp+0h]

  g_nYou_Must_Add_Public_Vgui_Controls_Vgui_ControlsCpp_To_Your_Project = 1;
  if ( CDEagle::GetCSWeaponID(this: v1) != 1 )
    _Error(this: (ISceneTokenProcessor *)&stru_1051AD08, a2: savedregs);
  strncpy(dest: (unsigned __int8 *)g_szControlsModuleName, source: (unsigned __int8 *)moduleName, count: 0x100u);
  g_szControlsModuleName[255] = 0;
  setlocale(_category: 2u, _locale: (char *)locale);
  setlocale(_category: 5u, _locale: (char *)locale);
  setlocale(_category: 1u, _locale: (char *)locale);
  setlocale(_category: 3u, _locale: (char *)locale);
  if ( g_pVGui != nullptr
    && g_pVGuiInput != nullptr
    && g_pVGuiPanel != nullptr
    && g_pVGuiSurface != nullptr
    && g_pVGuiSchemeManager != nullptr
    && g_pVGuiSystem != nullptr )
  {
    return 1;
  }
  _Warning(a1: "vgui_controls is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C0020
// Name: char const __near * vgui::GetControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::GetControlsModuleName()
{
  return g_szControlsModuleName;
}

} // namespace server
