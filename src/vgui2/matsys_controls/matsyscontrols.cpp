// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/matsyscontrols.cpp
// Functions: 108
// ============================================================

#include "vgui2\matsys_controls\matsyscontrols.h"

//------------------------------------------------------------------------------
// Address: 0x101EFB30
// Name: class vgui::Panel __near * CreateAskConnectPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAskConnectPanel *__cdecl CreateAskConnectPanel(unsigned int parent)
{
  CAskConnectPanel *v1; // eax

  v1 = (CAskConnectPanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v1 != nullptr )
    return CAskConnectPanel::CAskConnectPanel(this: v1, parent);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10264D30
// Name: class IMaterialSystem __near * vgui::MaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem *__cdecl vgui::MaterialSystem()
{
  return vgui::g_pMaterialSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10264D40
// Name: class IMatSystemSurface __near * vgui::MatSystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
IMatSystemSurface *__cdecl vgui::MatSystemSurface()
{
  return vgui::g_pMatSystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x10264D50
// Name: bool vgui::VGui_InitMatSysInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitMatSysInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  IMaterialSystem *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IMatSystemSurface *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IMDLCache *v12; // eax
  int v13; // esi
  void *(__cdecl *v14)(const char *, int *); // eax
  IStudioRender *v15; // eax
  int v16; // esi
  void *(__cdecl *v17)(const char *, int *); // eax
  IMaterialSystemHardwareConfig *v18; // eax

  result = vgui::VGui_InitInterfacesList(moduleName, factoryList, numFactories);
  if ( result )
  {
    v4 = 0;
    if ( numFactories <= 0 )
    {
LABEL_6:
      v6 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v5 = factoryList[v4];
        if ( v5 != nullptr )
        {
          v6 = (IMaterialSystem *)v5(a1: "VMaterialSystem080", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pMaterialSystem = v6;
    if ( numFactories <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v8 = factoryList[v7];
        if ( v8 != nullptr )
        {
          v9 = (IMatSystemSurface *)v8(a1: "MatSystemSurface006", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::g_pMatSystemSurface = v9;
    if ( numFactories <= 0 )
    {
LABEL_16:
      v12 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v11 = factoryList[v10];
        if ( v11 != nullptr )
        {
          v12 = (IMDLCache *)v11(a1: "MDLCache004", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    v13 = 0;
    vgui::g_pMDLCache = v12;
    if ( numFactories <= 0 )
    {
LABEL_21:
      v15 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v14 = factoryList[v13];
        if ( v14 != nullptr )
        {
          v15 = (IStudioRender *)v14(a1: "VStudioRender026", a2: nullptr);
          if ( v15 != nullptr )
            break;
        }
        if ( ++v13 >= numFactories )
          goto LABEL_21;
      }
    }
    v16 = 0;
    vgui::g_pStudioRender = v15;
    if ( numFactories <= 0 )
    {
LABEL_26:
      v18 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v17 = factoryList[v16];
        if ( v17 != nullptr )
        {
          v18 = (IMaterialSystemHardwareConfig *)v17(a1: "MaterialSystemHardwareConfig013", a2: nullptr);
          if ( v18 != nullptr )
            break;
        }
        if ( ++v16 >= numFactories )
          goto LABEL_26;
      }
    }
    vgui::g_pMaterialSystemHardwareConfig = v18;
    return vgui::g_pMaterialSystem != nullptr && vgui::g_pMatSystemSurface != nullptr && v18 != nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029B530
// Name: class vgui::Panel __near * ComboBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__cdecl ComboBox_Factory()
{
  vgui::ComboBox *v0; // eax

  v0 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v0 != nullptr )
    return vgui::ComboBox::ComboBox(this: v0, parent: nullptr, panelName: nullptr, numLines: 5, allowEdit: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C0C40
// Name: class vgui::Panel __near * ScrollBar_Vertical_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Vertical_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C0C70
// Name: class vgui::Panel __near * ScrollBar_Horizontal_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Horizontal_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C7A30
// Name: class vgui::Panel __near * Create_CvarToggleCheckButton(void)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__cdecl Create_CvarToggleCheckButton()
{
  vgui::CvarToggleCheckButton<ConVarRef> *v0; // eax

  v0 = (vgui::CvarToggleCheckButton<ConVarRef> *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v0 != nullptr )
    return vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: defaultValue,
             cvarname: nullptr,
             ignoreMissingCvar: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CAB60
// Name: class vgui::Panel __near * MessageBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__cdecl MessageBox_Factory()
{
  vgui::MessageBox *v0; // eax

  v0 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v0 != nullptr )
    return vgui::MessageBox::MessageBox(this: v0, title: "MessageBox", text: "MessageBoxText", parent: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D1EF0
// Name: class vgui::Panel __near * URLLabel_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__cdecl URLLabel_Factory()
{
  vgui::URLLabel *v0; // eax

  v0 = (vgui::URLLabel *)MemAlloc_Alloc(nSize: 0x1B4u);
  if ( v0 != nullptr )
    return vgui::URLLabel::URLLabel(this: v0, parent: nullptr, panelName: nullptr, text: "URLLabel", pszURL: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1031F220
// Name: _dynamic_initializer_for__vgui_drawfocus__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawfocus__()
{
  ConVar::ConVar(
    this: &vgui_drawfocus,
    pName: "vgui_drawfocus",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Report which panel is under the mouse.");
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawfocus__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F250
// Name: _dynamic_initializer_for__vgui_drawkeyfocus__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawkeyfocus__()
{
  ConVar::ConVar(
    this: &vgui_drawkeyfocus,
    pName: "vgui_drawkeyfocus",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Report which panel has keyboard focus.");
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawkeyfocus__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F280
// Name: _dynamic_initializer_for__vgui_togglepanel_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_togglepanel_command__()
{
  ConCommand::ConCommand(
    this: &vgui_togglepanel_command,
    pName: "vgui_togglepanel",
    callback: (void (__cdecl *)())vgui_togglepanel,
    pHelpString: "show/hide vgui panel by name.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_togglepanel_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F2B0
// Name: _dynamic_initializer_for__vgui_dump_panels_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_dump_panels_command__()
{
  ConCommand::ConCommand(
    this: &vgui_dump_panels_command,
    pName: "vgui_dump_panels",
    callback: (void (__cdecl *)())vgui_dump_panels,
    pHelpString: "vgui_dump_panels [visible]",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_dump_panels_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F860
// Name: _dynamic_initializer_for__vgui_drawtree__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree__()
{
  ConVar::ConVar(
    this: &vgui_drawtree,
    pName: "vgui_drawtree",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Draws the vgui panel hiearchy to the specified depth level.");
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F890
// Name: _dynamic_initializer_for__vgui_drawtree_visible__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_visible__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_visible,
    pName: "vgui_drawtree_visible",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw the visible panels.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_visible__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F8C0
// Name: _dynamic_initializer_for__vgui_drawtree_hidden__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_hidden__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_hidden,
    pName: "vgui_drawtree_hidden",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw the hidden panels.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_hidden__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F8F0
// Name: _dynamic_initializer_for__vgui_drawtree_popupsonly__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_popupsonly__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_popupsonly,
    pName: "vgui_drawtree_popupsonly",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draws the vgui popup list in hierarchy(1) or most recently used(2) order.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_popupsonly__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F920
// Name: _dynamic_initializer_for__vgui_drawtree_freeze__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_freeze__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_freeze,
    pName: "vgui_drawtree_freeze",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 to stop updating the vgui_drawtree view.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_freeze__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F950
// Name: _dynamic_initializer_for__vgui_drawtree_panelptr__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_panelptr__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_panelptr,
    pName: "vgui_drawtree_panelptr",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show the panel pointer values in the vgui_drawtree view.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_panelptr__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F980
// Name: _dynamic_initializer_for__vgui_drawtree_panelalpha__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_panelalpha__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_panelalpha,
    pName: "vgui_drawtree_panelalpha",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show the panel alpha values in the vgui_drawtree view.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_panelalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F9B0
// Name: _dynamic_initializer_for__vgui_drawtree_render_order__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_render_order__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_render_order,
    pName: "vgui_drawtree_render_order",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "List the vgui_drawtree panels in render order.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_render_order__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F9E0
// Name: _dynamic_initializer_for__vgui_drawtree_bounds__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_bounds__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_bounds,
    pName: "vgui_drawtree_bounds",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show panel bounds.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_bounds__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FA10
// Name: _dynamic_initializer_for__vgui_drawtree_draw_selected__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_draw_selected__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_draw_selected,
    pName: "vgui_drawtree_draw_selected",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Highlight the selected panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_draw_selected__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FA40
// Name: _dynamic_initializer_for__vgui_drawtree_scheme__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_scheme__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_scheme,
    pName: "vgui_drawtree_scheme",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show scheme file for each panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_scheme__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FA70
// Name: _dynamic_initializer_for__vgui_drawtree_on__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_on__()
{
  ConCommand::ConCommand(
    this: &vgui_drawtree_on,
    pName: "+vgui_drawtree",
    callback: vgui_drawtree_on_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_on__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FAA0
// Name: _dynamic_initializer_for__vgui_drawtree_off__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_off__()
{
  ConCommand::ConCommand(
    this: &vgui_drawtree_off,
    pName: "-vgui_drawtree",
    callback: vgui_drawtree_off_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_off__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FAD0
// Name: _dynamic_initializer_for__vgui_drawtree_clear__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_clear__()
{
  ConCommand::ConCommand(
    this: &vgui_drawtree_clear,
    pName: "vgui_drawtree_clear",
    callback: vgui_drawtree_clear_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_clear__);
}

//------------------------------------------------------------------------------
// Address: 0x10320380
// Name: vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Panel>();
  s_pUnpack = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10320390
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack;
  return s_pUnpack;
}

//------------------------------------------------------------------------------
// Address: 0x10320420
// Name: _dynamic_initializer_for__vgui::Panel::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::Panel::m_MessageMap__()
{
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].func = (unsigned int) __thiscall IToolSystem::`vcall'{48,{flat}};
  *((_QWORD *)&vgui::Panel::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].nameSymbol = 0;
  vgui::Panel::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103204D0
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>();
  s_pUnpack_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103204E0
// Name: _dynamic_initializer_for__vgui::Button::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Button::s_pUnpackParams__()
{
  vgui::Button::s_pUnpackParams = s_pUnpack_0;
  return s_pUnpack_0;
}

//------------------------------------------------------------------------------
// Address: 0x103205C0
// Name: vgui::_dynamic_initializer_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
int vgui::_dynamic_initializer_for__g_MenuMgr__()
{
  return atexit(func: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x103205D0
// Name: vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Label>();
  s_pUnpack_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103205E0
// Name: _dynamic_initializer_for__vgui::Label::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Label::s_pUnpackParams__()
{
  vgui::Label::s_pUnpackParams = s_pUnpack_1;
  return s_pUnpack_1;
}

//------------------------------------------------------------------------------
// Address: 0x10320950
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10320970
// Name: _dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__);
}

//------------------------------------------------------------------------------
// Address: 0x10327230
// Name: _dynamic_atexit_destructor_for__vgui_drawfocus__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawfocus__()
{
  ConVar::~ConVar(this: &vgui_drawfocus);
}

//------------------------------------------------------------------------------
// Address: 0x10327240
// Name: _dynamic_atexit_destructor_for__vgui_drawkeyfocus__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawkeyfocus__()
{
  ConVar::~ConVar(this: &vgui_drawkeyfocus);
}

//------------------------------------------------------------------------------
// Address: 0x10327250
// Name: _dynamic_atexit_destructor_for__vgui_togglepanel_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_togglepanel_command__()
{
  ConCommand::~ConCommand(this: &vgui_togglepanel_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327260
// Name: _dynamic_atexit_destructor_for__vgui_dump_panels_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_dump_panels_command__()
{
  ConCommand::~ConCommand(this: &vgui_dump_panels_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327430
// Name: _dynamic_atexit_destructor_for__vgui_drawtree__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree__()
{
  ConVar::~ConVar(this: &vgui_drawtree);
}

//------------------------------------------------------------------------------
// Address: 0x10327440
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_visible__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_visible__()
{
  ConVar::~ConVar(this: &vgui_drawtree_visible);
}

//------------------------------------------------------------------------------
// Address: 0x10327450
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_hidden__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_hidden__()
{
  ConVar::~ConVar(this: &vgui_drawtree_hidden);
}

//------------------------------------------------------------------------------
// Address: 0x10327460
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_popupsonly__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_popupsonly__()
{
  ConVar::~ConVar(this: &vgui_drawtree_popupsonly);
}

//------------------------------------------------------------------------------
// Address: 0x10327470
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_freeze__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_freeze__()
{
  ConVar::~ConVar(this: &vgui_drawtree_freeze);
}

//------------------------------------------------------------------------------
// Address: 0x10327480
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_panelptr__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_panelptr__()
{
  ConVar::~ConVar(this: &vgui_drawtree_panelptr);
}

//------------------------------------------------------------------------------
// Address: 0x10327490
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_panelalpha__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_panelalpha__()
{
  ConVar::~ConVar(this: &vgui_drawtree_panelalpha);
}

//------------------------------------------------------------------------------
// Address: 0x103274A0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_render_order__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_render_order__()
{
  ConVar::~ConVar(this: &vgui_drawtree_render_order);
}

//------------------------------------------------------------------------------
// Address: 0x103274B0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_bounds__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_bounds__()
{
  ConVar::~ConVar(this: &vgui_drawtree_bounds);
}

//------------------------------------------------------------------------------
// Address: 0x103274C0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_draw_selected__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_draw_selected__()
{
  ConVar::~ConVar(this: &vgui_drawtree_draw_selected);
}

//------------------------------------------------------------------------------
// Address: 0x103274D0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_scheme__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_scheme__()
{
  ConVar::~ConVar(this: &vgui_drawtree_scheme);
}

//------------------------------------------------------------------------------
// Address: 0x103274E0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_on__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_on__()
{
  ConCommand::~ConCommand(this: &vgui_drawtree_on);
}

//------------------------------------------------------------------------------
// Address: 0x103274F0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_off__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_off__()
{
  ConCommand::~ConCommand(this: &vgui_drawtree_off);
}

//------------------------------------------------------------------------------
// Address: 0x10327500
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_clear__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_clear__()
{
  ConCommand::~ConCommand(this: &vgui_drawtree_clear);
}

//------------------------------------------------------------------------------
// Address: 0x10327910
// Name: _vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary.m_PanelKeyBindingMapPool);
  CUtlDict<CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::RemoveAll(this: &dictionary.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x103279F0
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10327A00
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x10327A30
// Name: _dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::ToolWindow::s_ToolWindows);
}

//------------------------------------------------------------------------------
// Address: 0x103203A0
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x103203C0
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x103203D0
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x10320470
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10320490
// Name: _dynamic_initializer_for__g_ComboBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ComboBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ComboBox_Helper,
           className: "ComboBox",
           func: (vgui::Panel *(__cdecl *)())ComboBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x103204B0
// Name: _dynamic_initializer_for__g_TextEntry_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TextEntry_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TextEntry_Helper,
           className: "TextEntry",
           func: (vgui::Panel *(__cdecl *)())Create_TextEntry);
}

//------------------------------------------------------------------------------
// Address: 0x103204F0
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x10320510
// Name: _dynamic_initializer_for__g_Button_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Button_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Button_Helper,
           className: "Button",
           func: (vgui::Panel *(__cdecl *)())Create_Button);
}

//------------------------------------------------------------------------------
// Address: 0x10320530
// Name: _dynamic_initializer_for__g_EditablePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_EditablePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_EditablePanel_Helper,
           className: "EditablePanel",
           func: (vgui::Panel *(__cdecl *)())Create_EditablePanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320550
// Name: _dynamic_initializer_for__g_CheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CheckButton_Helper,
           className: "CheckButton",
           func: (vgui::Panel *(__cdecl *)())Create_CheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x103205F0
// Name: _dynamic_initializer_for__g_Label_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Label_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Label_Helper,
           className: "Label",
           func: (vgui::Panel *(__cdecl *)())Create_Label);
}

//------------------------------------------------------------------------------
// Address: 0x10320610
// Name: _dynamic_initializer_for__g_ListPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListPanel_Helper,
           className: "ListPanel",
           func: (vgui::Panel *(__cdecl *)())Create_ListPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320630
// Name: _dynamic_initializer_for__g_Slider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Slider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Slider_Helper,
           className: "Slider",
           func: (vgui::Panel *(__cdecl *)())Create_Slider);
}

//------------------------------------------------------------------------------
// Address: 0x10320650
// Name: _dynamic_initializer_for__g_ProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ProgressBar_Helper,
           className: "ProgressBar",
           func: (vgui::Panel *(__cdecl *)())Create_ProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x10320670
// Name: _dynamic_initializer_for__g_ContinuousProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ContinuousProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ContinuousProgressBar_Helper,
           className: "ContinuousProgressBar",
           func: (vgui::Panel *(__cdecl *)())Create_ContinuousProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x10320690
// Name: _dynamic_initializer_for__g_ToggleButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ToggleButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ToggleButton_Helper,
           className: "ToggleButton",
           func: (vgui::Panel *(__cdecl *)())Create_ToggleButton);
}

//------------------------------------------------------------------------------
// Address: 0x103206B0
// Name: _dynamic_initializer_for__g_RichText_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RichText_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RichText_Helper,
           className: "RichText",
           func: (vgui::Panel *(__cdecl *)())Create_RichText);
}

//------------------------------------------------------------------------------
// Address: 0x103206D0
// Name: _dynamic_initializer_for__g_ImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ImagePanel_Helper,
           className: "ImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_ImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x103206F0
// Name: _dynamic_initializer_for__g_ScrollBar_Vertical_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Vertical_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Vertical_Helper,
           className: "ScrollBar_Vertical",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Vertical_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320710
// Name: _dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Horizontal_Helper,
           className: "ScrollBar_Horizontal",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320730
// Name: _dynamic_initializer_for__g_ScrollBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Helper,
           className: "ScrollBar",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320750
// Name: _dynamic_initializer_for__g_ListViewPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListViewPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListViewPanel_Helper,
           className: "ListViewPanel",
           func: (vgui::Panel *(__cdecl *)())Create_ListViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320770
// Name: _dynamic_initializer_for__g_RadioButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RadioButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RadioButton_Helper,
           className: "RadioButton",
           func: (vgui::Panel *(__cdecl *)())Create_RadioButton);
}

//------------------------------------------------------------------------------
// Address: 0x10320790
// Name: _dynamic_initializer_for__g_AnimatingImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_AnimatingImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_AnimatingImagePanel_Helper,
           className: "AnimatingImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_AnimatingImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x103207B0
// Name: _dynamic_initializer_for__g_CBitmapImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CBitmapImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CBitmapImagePanel_Helper,
           className: "CBitmapImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_CBitmapImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x103207D0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CvarToggleCheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CvarToggleCheckButton_Helper,
           className: "CvarToggleCheckButton",
           func: (vgui::Panel *(__cdecl *)())Create_CvarToggleCheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x103207F0
// Name: _dynamic_initializer_for__g_Divider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Divider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Divider_Helper,
           className: "Divider",
           func: (vgui::Panel *(__cdecl *)())Create_Divider);
}

//------------------------------------------------------------------------------
// Address: 0x10320810
// Name: _dynamic_initializer_for__g_ExpandButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ExpandButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ExpandButton_Helper,
           className: "ExpandButton",
           func: (vgui::Panel *(__cdecl *)())Create_ExpandButton);
}

//------------------------------------------------------------------------------
// Address: 0x10320830
// Name: _dynamic_initializer_for__g_GraphPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_GraphPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_GraphPanel_Helper,
           className: "GraphPanel",
           func: (vgui::Panel *(__cdecl *)())Create_GraphPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320850
// Name: _dynamic_initializer_for__g_MenuBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuBar_Helper,
           className: "MenuBar",
           func: (vgui::Panel *(__cdecl *)())Create_MenuBar);
}

//------------------------------------------------------------------------------
// Address: 0x10320870
// Name: _dynamic_initializer_for__g_MenuItem_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuItem_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuItem_Helper,
           className: "MenuItem",
           func: (vgui::Panel *(__cdecl *)())Create_MenuItem);
}

//------------------------------------------------------------------------------
// Address: 0x10320890
// Name: _dynamic_initializer_for__g_MessageBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MessageBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MessageBox_Helper,
           className: "MessageBox",
           func: (vgui::Panel *(__cdecl *)())MessageBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x103208B0
// Name: _dynamic_initializer_for__g_CircularProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CircularProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CircularProgressBar_Helper,
           className: "CircularProgressBar",
           func: (vgui::Panel *(__cdecl *)())Create_CircularProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x103208D0
// Name: _dynamic_initializer_for__g_ScalableImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScalableImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScalableImagePanel_Helper,
           className: "ScalableImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_ScalableImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x103208F0
// Name: _dynamic_initializer_for__g_TreeView_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TreeView_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TreeView_Helper,
           className: "TreeView",
           func: (vgui::Panel *(__cdecl *)())Create_TreeView);
}

//------------------------------------------------------------------------------
// Address: 0x10320910
// Name: _dynamic_initializer_for__g_CTreeViewListControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CTreeViewListControl_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CTreeViewListControl_Helper,
           className: "CTreeViewListControl",
           func: (vgui::Panel *(__cdecl *)())Create_CTreeViewListControl);
}

//------------------------------------------------------------------------------
// Address: 0x10320930
// Name: _dynamic_initializer_for__g_URLLabel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_URLLabel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_URLLabel_Helper,
           className: "URLLabel",
           func: (vgui::Panel *(__cdecl *)())URLLabel_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320960
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10327270
// Name: _dynamic_atexit_destructor_for__g_FocusPanelList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FocusPanelList__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_FocusPanelList);
}

//------------------------------------------------------------------------------
// Address: 0x10327280
// Name: _dynamic_atexit_destructor_for__g_EngineVGuiImp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EngineVGuiImp__()
{
  g_EngineVGuiImp.__vftable = (CEngineVGui_vtbl *)&CEngineVGui::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_EngineVGuiImp.m_LoadingProgress);
  g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CEngineVGui>_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ConCommand'};
  g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ICommandCallback'};
  g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor);
  g_EngineVGuiImp.__vftable = (CEngineVGui_vtbl *)&IEngineVGui::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10327A20
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_BuildModeDialogMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10327A40
// Name: _DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_9);
}

//------------------------------------------------------------------------------
// Address: 0x10327A50
// Name: _DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_10);
}

//------------------------------------------------------------------------------
// Address: 0x10327A60
// Name: _DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_11);
}

//------------------------------------------------------------------------------
// Address: 0x10327A70
// Name: _DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_12);
}

//------------------------------------------------------------------------------
// Address: 0x10327A80
// Name: _DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_13);
}

//------------------------------------------------------------------------------
// Address: 0x10327A90
// Name: _DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_14);
}

//------------------------------------------------------------------------------
// Address: 0x10327AA0
// Name: _DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_15);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004B58E0
// Name: class IMaterialSystem __near * vgui::MaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem *__cdecl vgui::MaterialSystem()
{
  return vgui::g_pMaterialSystem;
}

//------------------------------------------------------------------------------
// Address: 0x004B58F0
// Name: class IMaterialSystemHardwareConfig __near * vgui::MaterialSystemHardwareConfig(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystemHardwareConfig *__cdecl vgui::MaterialSystemHardwareConfig()
{
  return vgui::g_pMaterialSystemHardwareConfig;
}

//------------------------------------------------------------------------------
// Address: 0x004B5900
// Name: class IMDLCache __near * vgui::MDLCache(void)
// Source: json
//------------------------------------------------------------------------------
IMDLCache *__cdecl vgui::MDLCache()
{
  return vgui::g_pMDLCache;
}

//------------------------------------------------------------------------------
// Address: 0x004B5910
// Name: class IMatSystemSurface __near * vgui::MatSystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
IMatSystemSurface *__cdecl vgui::MatSystemSurface()
{
  return vgui::g_pMatSystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x004B5920
// Name: class IStudioRender __near * vgui::StudioRender(void)
// Source: json
//------------------------------------------------------------------------------
IStudioRender *__cdecl vgui::StudioRender()
{
  return vgui::g_pStudioRender;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101EFDE0
// Name: class vgui::Panel __near * CreateAskConnectPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAskConnectPanel *__cdecl CreateAskConnectPanel(unsigned int parent)
{
  CAskConnectPanel *v1; // eax

  v1 = (CAskConnectPanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v1 != nullptr )
    return CAskConnectPanel::CAskConnectPanel(this: v1, parent);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10264D60
// Name: class IMatSystemSurface __near * vgui::MatSystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
IMatSystemSurface *__cdecl vgui::MatSystemSurface()
{
  return vgui::g_pMatSystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x10264D70
// Name: bool vgui::VGui_InitMatSysInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitMatSysInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  IMaterialSystem *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IMatSystemSurface *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IMDLCache *v12; // eax
  int v13; // esi
  void *(__cdecl *v14)(const char *, int *); // eax
  IStudioRender *v15; // eax
  int v16; // esi
  void *(__cdecl *v17)(const char *, int *); // eax
  IMaterialSystemHardwareConfig *v18; // eax

  result = vgui::VGui_InitInterfacesList(moduleName, factoryList, numFactories);
  if ( result )
  {
    v4 = 0;
    if ( numFactories <= 0 )
    {
LABEL_6:
      v6 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v5 = factoryList[v4];
        if ( v5 != nullptr )
        {
          v6 = (IMaterialSystem *)v5(a1: "VMaterialSystem080", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pMaterialSystem = v6;
    if ( numFactories <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v8 = factoryList[v7];
        if ( v8 != nullptr )
        {
          v9 = (IMatSystemSurface *)v8(a1: "MatSystemSurface006", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::g_pMatSystemSurface = v9;
    if ( numFactories <= 0 )
    {
LABEL_16:
      v12 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v11 = factoryList[v10];
        if ( v11 != nullptr )
        {
          v12 = (IMDLCache *)v11(a1: "MDLCache004", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    v13 = 0;
    vgui::g_pMDLCache = v12;
    if ( numFactories <= 0 )
    {
LABEL_21:
      v15 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v14 = factoryList[v13];
        if ( v14 != nullptr )
        {
          v15 = (IStudioRender *)v14(a1: "VStudioRender026", a2: nullptr);
          if ( v15 != nullptr )
            break;
        }
        if ( ++v13 >= numFactories )
          goto LABEL_21;
      }
    }
    v16 = 0;
    vgui::g_pStudioRender = v15;
    if ( numFactories <= 0 )
    {
LABEL_26:
      v18 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v17 = factoryList[v16];
        if ( v17 != nullptr )
        {
          v18 = (IMaterialSystemHardwareConfig *)v17(a1: "MaterialSystemHardwareConfig013", a2: nullptr);
          if ( v18 != nullptr )
            break;
        }
        if ( ++v16 >= numFactories )
          goto LABEL_26;
      }
    }
    vgui::g_pMaterialSystemHardwareConfig = v18;
    return vgui::g_pMaterialSystem != nullptr && vgui::g_pMatSystemSurface != nullptr && v18 != nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029B660
// Name: class vgui::Panel __near * ComboBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__cdecl ComboBox_Factory()
{
  vgui::ComboBox *v0; // eax

  v0 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v0 != nullptr )
    return vgui::ComboBox::ComboBox(this: v0, parent: nullptr, panelName: nullptr, numLines: 5, allowEdit: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C0D10
// Name: class vgui::Panel __near * ScrollBar_Vertical_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Vertical_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C0D40
// Name: class vgui::Panel __near * ScrollBar_Horizontal_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Horizontal_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C7B00
// Name: class vgui::Panel __near * Create_CvarToggleCheckButton(void)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__cdecl Create_CvarToggleCheckButton()
{
  vgui::CvarToggleCheckButton<ConVarRef> *v0; // eax

  v0 = (vgui::CvarToggleCheckButton<ConVarRef> *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v0 != nullptr )
    return vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: defaultValue,
             cvarname: nullptr,
             ignoreMissingCvar: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CAC90
// Name: class vgui::Panel __near * MessageBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__cdecl MessageBox_Factory()
{
  vgui::MessageBox *v0; // eax

  v0 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v0 != nullptr )
    return vgui::MessageBox::MessageBox(this: v0, title: "MessageBox", text: "MessageBoxText", parent: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D1F90
// Name: class vgui::Panel __near * URLLabel_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__cdecl URLLabel_Factory()
{
  vgui::URLLabel *v0; // eax

  v0 = (vgui::URLLabel *)MemAlloc_Alloc(nSize: 0x1B4u);
  if ( v0 != nullptr )
    return vgui::URLLabel::URLLabel(this: v0, parent: nullptr, panelName: nullptr, text: "URLLabel", pszURL: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1031F3F0
// Name: _dynamic_initializer_for__vgui_drawfocus__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawfocus__()
{
  ConVar::ConVar(
    this: &vgui_drawfocus,
    pName: "vgui_drawfocus",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Report which panel is under the mouse.");
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawfocus__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F420
// Name: _dynamic_initializer_for__vgui_drawkeyfocus__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawkeyfocus__()
{
  ConVar::ConVar(
    this: &vgui_drawkeyfocus,
    pName: "vgui_drawkeyfocus",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Report which panel has keyboard focus.");
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawkeyfocus__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F450
// Name: _dynamic_initializer_for__vgui_togglepanel_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_togglepanel_command__()
{
  ConCommand::ConCommand(
    this: &vgui_togglepanel_command,
    pName: "vgui_togglepanel",
    callback: vgui_togglepanel,
    pHelpString: "show/hide vgui panel by name.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_togglepanel_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F480
// Name: _dynamic_initializer_for__vgui_dump_panels_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_dump_panels_command__()
{
  ConCommand::ConCommand(
    this: &vgui_dump_panels_command,
    pName: "vgui_dump_panels",
    callback: vgui_dump_panels,
    pHelpString: "vgui_dump_panels [visible]",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_dump_panels_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FA30
// Name: _dynamic_initializer_for__vgui_drawtree__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree__()
{
  ConVar::ConVar(
    this: &vgui_drawtree,
    pName: "vgui_drawtree",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Draws the vgui panel hiearchy to the specified depth level.");
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FA60
// Name: _dynamic_initializer_for__vgui_drawtree_visible__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_visible__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_visible,
    pName: "vgui_drawtree_visible",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw the visible panels.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_visible__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FA90
// Name: _dynamic_initializer_for__vgui_drawtree_hidden__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_hidden__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_hidden,
    pName: "vgui_drawtree_hidden",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw the hidden panels.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_hidden__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FAC0
// Name: _dynamic_initializer_for__vgui_drawtree_popupsonly__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_popupsonly__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_popupsonly,
    pName: "vgui_drawtree_popupsonly",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draws the vgui popup list in hierarchy(1) or most recently used(2) order.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_popupsonly__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FAF0
// Name: _dynamic_initializer_for__vgui_drawtree_freeze__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_freeze__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_freeze,
    pName: "vgui_drawtree_freeze",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 to stop updating the vgui_drawtree view.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_freeze__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FB20
// Name: _dynamic_initializer_for__vgui_drawtree_panelptr__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_panelptr__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_panelptr,
    pName: "vgui_drawtree_panelptr",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show the panel pointer values in the vgui_drawtree view.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_panelptr__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FB50
// Name: _dynamic_initializer_for__vgui_drawtree_panelalpha__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_panelalpha__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_panelalpha,
    pName: "vgui_drawtree_panelalpha",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show the panel alpha values in the vgui_drawtree view.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_panelalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FB80
// Name: _dynamic_initializer_for__vgui_drawtree_render_order__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_render_order__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_render_order,
    pName: "vgui_drawtree_render_order",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "List the vgui_drawtree panels in render order.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_render_order__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FBB0
// Name: _dynamic_initializer_for__vgui_drawtree_bounds__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_bounds__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_bounds,
    pName: "vgui_drawtree_bounds",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show panel bounds.",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_bounds__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FBE0
// Name: _dynamic_initializer_for__vgui_drawtree_draw_selected__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_draw_selected__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_draw_selected,
    pName: "vgui_drawtree_draw_selected",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Highlight the selected panel",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_draw_selected__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FC10
// Name: _dynamic_initializer_for__vgui_drawtree_scheme__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_scheme__()
{
  ConVar::ConVar(
    this: &vgui_drawtree_scheme,
    pName: "vgui_drawtree_scheme",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show scheme file for each panel",
    callback: ChangeCallback_RefreshDrawTree);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_scheme__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FC40
// Name: _dynamic_initializer_for__vgui_drawtree_on__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_on__()
{
  ConCommand::ConCommand(
    this: &vgui_drawtree_on,
    pName: "+vgui_drawtree",
    callback: vgui_drawtree_on_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_on__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FC70
// Name: _dynamic_initializer_for__vgui_drawtree_off__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_off__()
{
  ConCommand::ConCommand(
    this: &vgui_drawtree_off,
    pName: "-vgui_drawtree",
    callback: vgui_drawtree_off_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_off__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FCA0
// Name: _dynamic_initializer_for__vgui_drawtree_clear__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_drawtree_clear__()
{
  ConCommand::ConCommand(
    this: &vgui_drawtree_clear,
    pName: "vgui_drawtree_clear",
    callback: vgui_drawtree_clear_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_drawtree_clear__);
}

//------------------------------------------------------------------------------
// Address: 0x10320560
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack;
  return s_pUnpack;
}

//------------------------------------------------------------------------------
// Address: 0x103206A0
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>(__formal: nullptr);
  s_pUnpack_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103207A0
// Name: vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Label>(__formal: nullptr);
  s_pUnpack_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10320B20
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10320B40
// Name: _dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__);
}

//------------------------------------------------------------------------------
// Address: 0x10327420
// Name: _dynamic_atexit_destructor_for__vgui_drawfocus__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawfocus__()
{
  ConVar::~ConVar(this: &vgui_drawfocus);
}

//------------------------------------------------------------------------------
// Address: 0x10327620
// Name: _dynamic_atexit_destructor_for__vgui_drawtree__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree__()
{
  ConVar::~ConVar(this: &vgui_drawtree);
}

//------------------------------------------------------------------------------
// Address: 0x10327630
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_visible__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_visible__()
{
  ConVar::~ConVar(this: &vgui_drawtree_visible);
}

//------------------------------------------------------------------------------
// Address: 0x10327640
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_hidden__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_hidden__()
{
  ConVar::~ConVar(this: &vgui_drawtree_hidden);
}

//------------------------------------------------------------------------------
// Address: 0x10327650
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_popupsonly__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_popupsonly__()
{
  ConVar::~ConVar(this: &vgui_drawtree_popupsonly);
}

//------------------------------------------------------------------------------
// Address: 0x10327660
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_freeze__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_freeze__()
{
  ConVar::~ConVar(this: &vgui_drawtree_freeze);
}

//------------------------------------------------------------------------------
// Address: 0x10327670
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_panelptr__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_panelptr__()
{
  ConVar::~ConVar(this: &vgui_drawtree_panelptr);
}

//------------------------------------------------------------------------------
// Address: 0x10327680
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_panelalpha__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_panelalpha__()
{
  ConVar::~ConVar(this: &vgui_drawtree_panelalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10327690
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_render_order__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_render_order__()
{
  ConVar::~ConVar(this: &vgui_drawtree_render_order);
}

//------------------------------------------------------------------------------
// Address: 0x103276A0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_bounds__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_bounds__()
{
  ConVar::~ConVar(this: &vgui_drawtree_bounds);
}

//------------------------------------------------------------------------------
// Address: 0x103276B0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_draw_selected__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_draw_selected__()
{
  ConVar::~ConVar(this: &vgui_drawtree_draw_selected);
}

//------------------------------------------------------------------------------
// Address: 0x103276C0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_scheme__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_scheme__()
{
  ConVar::~ConVar(this: &vgui_drawtree_scheme);
}

//------------------------------------------------------------------------------
// Address: 0x103276D0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_on__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_on__()
{
  ConCommand::~ConCommand(this: &vgui_drawtree_on);
}

//------------------------------------------------------------------------------
// Address: 0x103276E0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_off__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_off__()
{
  ConCommand::~ConCommand(this: &vgui_drawtree_off);
}

//------------------------------------------------------------------------------
// Address: 0x103276F0
// Name: _dynamic_atexit_destructor_for__vgui_drawtree_clear__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_drawtree_clear__()
{
  ConCommand::~ConCommand(this: &vgui_drawtree_clear);
}

//------------------------------------------------------------------------------
// Address: 0x10327B00
// Name: _vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary.m_PanelKeyBindingMapPool);
  CUtlDict<CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::RemoveAll(this: &dictionary.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10327BE0
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10327BF0
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x10327C20
// Name: _dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::ToolWindow::s_ToolWindows);
}

//------------------------------------------------------------------------------
// Address: 0x10320570
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10320590
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x103205A0
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x10320640
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10320660
// Name: _dynamic_initializer_for__g_ComboBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ComboBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ComboBox_Helper,
           className: "ComboBox",
           func: (vgui::Panel *(__cdecl *)())ComboBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320680
// Name: _dynamic_initializer_for__g_TextEntry_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TextEntry_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TextEntry_Helper,
           className: "TextEntry",
           func: Create_TextEntry);
}

//------------------------------------------------------------------------------
// Address: 0x103206C0
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x103206E0
// Name: _dynamic_initializer_for__g_Button_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Button_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Button_Helper,
           className: "Button",
           func: Create_Button);
}

//------------------------------------------------------------------------------
// Address: 0x10320700
// Name: _dynamic_initializer_for__g_EditablePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_EditablePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_EditablePanel_Helper,
           className: "EditablePanel",
           func: Create_EditablePanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320720
// Name: _dynamic_initializer_for__g_CheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CheckButton_Helper,
           className: "CheckButton",
           func: Create_CheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x103207C0
// Name: _dynamic_initializer_for__g_Label_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Label_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Label_Helper, className: "Label", func: Create_Label);
}

//------------------------------------------------------------------------------
// Address: 0x103207E0
// Name: _dynamic_initializer_for__g_ListPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListPanel_Helper,
           className: "ListPanel",
           func: Create_ListPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320800
// Name: _dynamic_initializer_for__g_Slider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Slider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Slider_Helper,
           className: "Slider",
           func: Create_Slider);
}

//------------------------------------------------------------------------------
// Address: 0x10320820
// Name: _dynamic_initializer_for__g_ProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ProgressBar_Helper,
           className: "ProgressBar",
           func: Create_ProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x10320840
// Name: _dynamic_initializer_for__g_ContinuousProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ContinuousProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ContinuousProgressBar_Helper,
           className: "ContinuousProgressBar",
           func: Create_ContinuousProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x10320860
// Name: _dynamic_initializer_for__g_ToggleButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ToggleButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ToggleButton_Helper,
           className: "ToggleButton",
           func: Create_ToggleButton);
}

//------------------------------------------------------------------------------
// Address: 0x10320880
// Name: _dynamic_initializer_for__g_RichText_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RichText_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RichText_Helper,
           className: "RichText",
           func: Create_RichText);
}

//------------------------------------------------------------------------------
// Address: 0x103208A0
// Name: _dynamic_initializer_for__g_ImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ImagePanel_Helper,
           className: "ImagePanel",
           func: Create_ImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x103208C0
// Name: _dynamic_initializer_for__g_ScrollBar_Vertical_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Vertical_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Vertical_Helper,
           className: "ScrollBar_Vertical",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Vertical_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x103208E0
// Name: _dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Horizontal_Helper,
           className: "ScrollBar_Horizontal",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320900
// Name: _dynamic_initializer_for__g_ScrollBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Helper,
           className: "ScrollBar",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320920
// Name: _dynamic_initializer_for__g_ListViewPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListViewPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListViewPanel_Helper,
           className: "ListViewPanel",
           func: Create_ListViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320940
// Name: _dynamic_initializer_for__g_RadioButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RadioButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RadioButton_Helper,
           className: "RadioButton",
           func: Create_RadioButton);
}

//------------------------------------------------------------------------------
// Address: 0x10320980
// Name: _dynamic_initializer_for__g_CBitmapImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CBitmapImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CBitmapImagePanel_Helper,
           className: "CBitmapImagePanel",
           func: Create_CBitmapImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x103209A0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CvarToggleCheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CvarToggleCheckButton_Helper,
           className: "CvarToggleCheckButton",
           func: (vgui::Panel *(__cdecl *)())Create_CvarToggleCheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x103209C0
// Name: _dynamic_initializer_for__g_Divider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Divider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Divider_Helper,
           className: "Divider",
           func: Create_Divider);
}

//------------------------------------------------------------------------------
// Address: 0x103209E0
// Name: _dynamic_initializer_for__g_ExpandButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ExpandButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ExpandButton_Helper,
           className: "ExpandButton",
           func: Create_ExpandButton);
}

//------------------------------------------------------------------------------
// Address: 0x10320A00
// Name: _dynamic_initializer_for__g_GraphPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_GraphPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_GraphPanel_Helper,
           className: "GraphPanel",
           func: Create_GraphPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320A20
// Name: _dynamic_initializer_for__g_MenuBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuBar_Helper,
           className: "MenuBar",
           func: Create_MenuBar);
}

//------------------------------------------------------------------------------
// Address: 0x10320A40
// Name: _dynamic_initializer_for__g_MenuItem_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuItem_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuItem_Helper,
           className: "MenuItem",
           func: Create_MenuItem);
}

//------------------------------------------------------------------------------
// Address: 0x10320A60
// Name: _dynamic_initializer_for__g_MessageBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MessageBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MessageBox_Helper,
           className: "MessageBox",
           func: (vgui::Panel *(__cdecl *)())MessageBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320A80
// Name: _dynamic_initializer_for__g_CircularProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CircularProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CircularProgressBar_Helper,
           className: "CircularProgressBar",
           func: Create_CircularProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x10320AA0
// Name: _dynamic_initializer_for__g_ScalableImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScalableImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScalableImagePanel_Helper,
           className: "ScalableImagePanel",
           func: Create_ScalableImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x10320AC0
// Name: _dynamic_initializer_for__g_TreeView_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TreeView_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TreeView_Helper,
           className: "TreeView",
           func: Create_TreeView);
}

//------------------------------------------------------------------------------
// Address: 0x10320AE0
// Name: _dynamic_initializer_for__g_CTreeViewListControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CTreeViewListControl_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CTreeViewListControl_Helper,
           className: "CTreeViewListControl",
           func: Create_CTreeViewListControl);
}

//------------------------------------------------------------------------------
// Address: 0x10320B00
// Name: _dynamic_initializer_for__g_URLLabel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_URLLabel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_URLLabel_Helper,
           className: "URLLabel",
           func: (vgui::Panel *(__cdecl *)())URLLabel_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10320B30
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10327C10
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_BuildModeDialogMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10327C30
// Name: _DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_9);
}

//------------------------------------------------------------------------------
// Address: 0x10327C40
// Name: _DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_10);
}

//------------------------------------------------------------------------------
// Address: 0x10327C50
// Name: _DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_11);
}

//------------------------------------------------------------------------------
// Address: 0x10327C60
// Name: _DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_12);
}

//------------------------------------------------------------------------------
// Address: 0x10327C70
// Name: _DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_13);
}

//------------------------------------------------------------------------------
// Address: 0x10327C80
// Name: _DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_14);
}

//------------------------------------------------------------------------------
// Address: 0x10327C90
// Name: _DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_15);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10205D30
// Name: class IMaterialSystem __near * vgui::MaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem *__cdecl vgui::MaterialSystem()
{
  return vgui::g_pMaterialSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10205D40
// Name: class IMaterialSystemHardwareConfig __near * vgui::MaterialSystemHardwareConfig(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystemHardwareConfig *__cdecl vgui::MaterialSystemHardwareConfig()
{
  return vgui::g_pMaterialSystemHardwareConfig;
}

//------------------------------------------------------------------------------
// Address: 0x10205D50
// Name: class IMDLCache __near * vgui::MDLCache(void)
// Source: json
//------------------------------------------------------------------------------
IMDLCache *__cdecl vgui::MDLCache()
{
  return vgui::g_pMDLCache;
}

//------------------------------------------------------------------------------
// Address: 0x10205D60
// Name: class IMatSystemSurface __near * vgui::MatSystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
IMatSystemSurface *__cdecl vgui::MatSystemSurface()
{
  return vgui::g_pMatSystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x10205D70
// Name: class IStudioRender __near * vgui::StudioRender(void)
// Source: json
//------------------------------------------------------------------------------
IStudioRender *__cdecl vgui::StudioRender()
{
  return vgui::g_pStudioRender;
}

//------------------------------------------------------------------------------
// Address: 0x10205D80
// Name: bool vgui::VGui_InitMatSysInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitMatSysInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  IMaterialSystem *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IMatSystemSurface *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IMDLCache *v12; // eax
  int v13; // esi
  void *(__cdecl *v14)(const char *, int *); // eax
  IStudioRender *v15; // eax
  int v16; // esi
  void *(__cdecl *v17)(const char *, int *); // eax
  IMaterialSystemHardwareConfig *v18; // eax

  result = vgui::VGui_InitInterfacesList(moduleName, factoryList, numFactories);
  if ( result )
  {
    v4 = 0;
    if ( numFactories <= 0 )
    {
LABEL_6:
      v6 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v5 = factoryList[v4];
        if ( v5 != nullptr )
        {
          v6 = (IMaterialSystem *)v5(a1: "VMaterialSystem080", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pMaterialSystem = v6;
    if ( numFactories <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v8 = factoryList[v7];
        if ( v8 != nullptr )
        {
          v9 = (IMatSystemSurface *)v8(a1: "MatSystemSurface006", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::g_pMatSystemSurface = v9;
    if ( numFactories <= 0 )
    {
LABEL_16:
      v12 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v11 = factoryList[v10];
        if ( v11 != nullptr )
        {
          v12 = (IMDLCache *)v11(a1: "MDLCache004", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    v13 = 0;
    vgui::g_pMDLCache = v12;
    if ( numFactories <= 0 )
    {
LABEL_21:
      v15 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v14 = factoryList[v13];
        if ( v14 != nullptr )
        {
          v15 = (IStudioRender *)v14(a1: "VStudioRender026", a2: nullptr);
          if ( v15 != nullptr )
            break;
        }
        if ( ++v13 >= numFactories )
          goto LABEL_21;
      }
    }
    v16 = 0;
    vgui::g_pStudioRender = v15;
    if ( numFactories <= 0 )
    {
LABEL_26:
      v18 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v17 = factoryList[v16];
        if ( v17 != nullptr )
        {
          v18 = (IMaterialSystemHardwareConfig *)v17(a1: "MaterialSystemHardwareConfig013", a2: nullptr);
          if ( v18 != nullptr )
            break;
        }
        if ( ++v16 >= numFactories )
          goto LABEL_26;
      }
    }
    vgui::g_pMaterialSystemHardwareConfig = v18;
    return vgui::g_pMaterialSystem != nullptr && vgui::g_pMatSystemSurface != nullptr && v18 != nullptr;
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004022D0
// Name: class vgui::PHandle CreatePickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DHANDLE<CDragDropHelperPanel> *__cdecl CreatePickerFrame(vgui::DHANDLE<CDragDropHelperPanel> *result)
{
  CMDLBrowserFrame *v1; // eax
  CDragDropHelperPanel *v2; // edi
  CDragDropHelperPanel_vtbl *v3; // esi
  unsigned int v4; // eax
  IMatRenderContext *v5; // eax
  IMatRenderContext *v6; // esi
  int x; // [esp+Ch] [ebp-10h] BYREF
  int y; // [esp+10h] [ebp-Ch] BYREF
  int w; // [esp+14h] [ebp-8h] BYREF
  int h; // [esp+18h] [ebp-4h] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v1 = (CMDLBrowserFrame *)operator new(nSize: 0x220u);
  if ( v1 != nullptr )
    v2 = (CDragDropHelperPanel *)CMDLBrowserFrame::CMDLBrowserFrame(this: v1, a2: (int)&savedregs);
  else
    v2 = nullptr;
  v3 = v2->__vftable;
  v4 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  v3->SetParent(this: v2, a2: v4);
  result->m_iPanelID = -1;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: result, pPanel: v2);
  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v6 = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v6->GetViewport(this: v6, a2: &x, a3: &y, a4: &w, a5: &h);
  vgui::Panel::SetBounds(this: v2, x: x + 2, y: y + 2, wide: w - 4, tall: h - 4);
  v6->EndRender(this: v6);
  v6->Release(this: v6);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B920
// Name: class IMaterialSystem __near * vgui::MaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem *__cdecl vgui::MaterialSystem()
{
  return vgui::g_pMaterialSystem;
}

//------------------------------------------------------------------------------
// Address: 0x0040B930
// Name: class IMaterialSystemHardwareConfig __near * vgui::MaterialSystemHardwareConfig(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystemHardwareConfig *__cdecl vgui::MaterialSystemHardwareConfig()
{
  return vgui::g_pMaterialSystemHardwareConfig;
}

//------------------------------------------------------------------------------
// Address: 0x0040B940
// Name: class IMDLCache __near * vgui::MDLCache(void)
// Source: json
//------------------------------------------------------------------------------
IMDLCache *__cdecl vgui::MDLCache()
{
  return vgui::g_pMDLCache;
}

//------------------------------------------------------------------------------
// Address: 0x0040B950
// Name: class IMatSystemSurface __near * vgui::MatSystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
IMatSystemSurface *__cdecl vgui::MatSystemSurface()
{
  return vgui::g_pMatSystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x0040B960
// Name: class IStudioRender __near * vgui::StudioRender(void)
// Source: json
//------------------------------------------------------------------------------
IStudioRender *__cdecl vgui::StudioRender()
{
  return vgui::g_pStudioRender;
}

//------------------------------------------------------------------------------
// Address: 0x0040B970
// Name: bool vgui::VGui_InitMatSysInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitMatSysInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  IMaterialSystem *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IMatSystemSurface *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IMDLCache *v12; // eax
  int v13; // esi
  void *(__cdecl *v14)(const char *, int *); // eax
  IStudioRender *v15; // eax
  int v16; // esi
  void *(__cdecl *v17)(const char *, int *); // eax
  IMaterialSystemHardwareConfig *v18; // eax

  result = vgui::VGui_InitInterfacesList(moduleName, factoryList, numFactories);
  if ( result )
  {
    v4 = 0;
    if ( numFactories <= 0 )
    {
LABEL_6:
      v6 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v5 = factoryList[v4];
        if ( v5 != nullptr )
        {
          v6 = (IMaterialSystem *)v5(a1: "VMaterialSystem080", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pMaterialSystem = v6;
    if ( numFactories <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v8 = factoryList[v7];
        if ( v8 != nullptr )
        {
          v9 = (IMatSystemSurface *)v8(a1: "MatSystemSurface006", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::g_pMatSystemSurface = v9;
    if ( numFactories <= 0 )
    {
LABEL_16:
      v12 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v11 = factoryList[v10];
        if ( v11 != nullptr )
        {
          v12 = (IMDLCache *)v11(a1: "MDLCache004", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    v13 = 0;
    vgui::g_pMDLCache = v12;
    if ( numFactories <= 0 )
    {
LABEL_21:
      v15 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v14 = factoryList[v13];
        if ( v14 != nullptr )
        {
          v15 = (IStudioRender *)v14(a1: "VStudioRender026", a2: nullptr);
          if ( v15 != nullptr )
            break;
        }
        if ( ++v13 >= numFactories )
          goto LABEL_21;
      }
    }
    v16 = 0;
    vgui::g_pStudioRender = v15;
    if ( numFactories <= 0 )
    {
LABEL_26:
      v18 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v17 = factoryList[v16];
        if ( v17 != nullptr )
        {
          v18 = (IMaterialSystemHardwareConfig *)v17(a1: "MaterialSystemHardwareConfig013", a2: nullptr);
          if ( v18 != nullptr )
            break;
        }
        if ( ++v16 >= numFactories )
          goto LABEL_26;
      }
    }
    vgui::g_pMaterialSystemHardwareConfig = v18;
    return vgui::g_pMaterialSystem != nullptr && vgui::g_pMatSystemSurface != nullptr && v18 != nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449D90
// Name: class vgui::Panel __near * ComboBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__cdecl ComboBox_Factory()
{
  vgui::ComboBox *v0; // eax

  v0 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v0 != nullptr )
    return vgui::ComboBox::ComboBox(this: v0, parent: nullptr, panelName: nullptr, numLines: 5, allowEdit: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044A290
// Name: class vgui::Panel __near * Create_CvarToggleCheckButton(void)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__cdecl Create_CvarToggleCheckButton()
{
  vgui::CvarToggleCheckButton<ConVarRef> *v0; // eax

  v0 = (vgui::CvarToggleCheckButton<ConVarRef> *)operator new(nSize: 0x22Cu);
  if ( v0 != nullptr )
    return vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: defaultValue,
             cvarname: nullptr,
             ignoreMissingCvar: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045B9D0
// Name: class vgui::Panel __near * MessageBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__cdecl MessageBox_Factory()
{
  vgui::MessageBox *v0; // eax

  v0 = (vgui::MessageBox *)operator new(nSize: 0x234u);
  if ( v0 != nullptr )
    return vgui::MessageBox::MessageBox(this: v0, title: "MessageBox", text: "MessageBoxText", parent: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004632B0
// Name: class vgui::Panel __near * ScrollBar_Vertical_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Vertical_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004632E0
// Name: class vgui::Panel __near * ScrollBar_Horizontal_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Horizontal_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00470300
// Name: class vgui::Panel __near * URLLabel_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__cdecl URLLabel_Factory()
{
  vgui::URLLabel *v0; // eax

  v0 = (vgui::URLLabel *)operator new(nSize: 0x1B4u);
  if ( v0 != nullptr )
    return vgui::URLLabel::URLLabel(this: v0, parent: nullptr, panelName: nullptr, text: "URLLabel", pszURL: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B8630
// Name: vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Panel>(__formal: nullptr);
  s_pUnpack = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8640
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack;
  return s_pUnpack;
}

//------------------------------------------------------------------------------
// Address: 0x004B86D0
// Name: _dynamic_initializer_for__vgui::Panel::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::Panel::m_MessageMap__()
{
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].func = (unsigned int) __thiscall vgui::Panel::`vcall'{48,{flat}};
  *((_QWORD *)&vgui::Panel::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].nameSymbol = 0;
  vgui::Panel::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8760
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>(__formal: nullptr);
  s_pUnpack_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8770
// Name: _dynamic_initializer_for__vgui::Button::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Button::s_pUnpackParams__()
{
  vgui::Button::s_pUnpackParams = s_pUnpack_0;
  return s_pUnpack_0;
}

//------------------------------------------------------------------------------
// Address: 0x004B87E0
// Name: vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Label>(__formal: nullptr);
  s_pUnpack_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B87F0
// Name: _dynamic_initializer_for__vgui::Label::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Label::s_pUnpackParams__()
{
  vgui::Label::s_pUnpackParams = s_pUnpack_1;
  return s_pUnpack_1;
}

//------------------------------------------------------------------------------
// Address: 0x004B89A0
// Name: vgui::_dynamic_initializer_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
int vgui::_dynamic_initializer_for__g_MenuMgr__()
{
  return atexit(func: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8BD0
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8BF0
// Name: _dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__);
}

//------------------------------------------------------------------------------
// Address: 0x004B9350
// Name: _vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary.m_PanelKeyBindingMapPool);
  CUtlDict<CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::RemoveAll(this: &dictionary.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004B9410
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x004B9420
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x004B9450
// Name: _dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::ToolWindow::s_ToolWindows);
}

//------------------------------------------------------------------------------
// Address: 0x004B8650
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8670
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8680
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8720
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8740
// Name: _dynamic_initializer_for__g_EditablePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_EditablePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_EditablePanel_Helper,
           className: "EditablePanel",
           func: Create_EditablePanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8780
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x004B87A0
// Name: _dynamic_initializer_for__g_Button_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Button_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Button_Helper,
           className: "Button",
           func: Create_Button);
}

//------------------------------------------------------------------------------
// Address: 0x004B87C0
// Name: _dynamic_initializer_for__g_ImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ImagePanel_Helper,
           className: "ImagePanel",
           func: Create_ImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8800
// Name: _dynamic_initializer_for__g_Label_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Label_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Label_Helper, className: "Label", func: Create_Label);
}

//------------------------------------------------------------------------------
// Address: 0x004B8820
// Name: _dynamic_initializer_for__g_ToggleButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ToggleButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ToggleButton_Helper,
           className: "ToggleButton",
           func: Create_ToggleButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B8840
// Name: _dynamic_initializer_for__g_AnimatingImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_AnimatingImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_AnimatingImagePanel_Helper,
           className: "AnimatingImagePanel",
           func: Create_AnimatingImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8860
// Name: _dynamic_initializer_for__g_CBitmapImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CBitmapImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CBitmapImagePanel_Helper,
           className: "CBitmapImagePanel",
           func: Create_CBitmapImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8880
// Name: _dynamic_initializer_for__g_CheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CheckButton_Helper,
           className: "CheckButton",
           func: Create_CheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B88A0
// Name: _dynamic_initializer_for__g_ComboBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ComboBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ComboBox_Helper,
           className: "ComboBox",
           func: (vgui::Panel *(__cdecl *)())ComboBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x004B88C0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CvarToggleCheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CvarToggleCheckButton_Helper,
           className: "CvarToggleCheckButton",
           func: (vgui::Panel *(__cdecl *)())Create_CvarToggleCheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B88E0
// Name: _dynamic_initializer_for__g_Divider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Divider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Divider_Helper,
           className: "Divider",
           func: Create_Divider);
}

//------------------------------------------------------------------------------
// Address: 0x004B8900
// Name: _dynamic_initializer_for__g_ExpandButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ExpandButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ExpandButton_Helper,
           className: "ExpandButton",
           func: Create_ExpandButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B8920
// Name: _dynamic_initializer_for__g_GraphPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_GraphPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_GraphPanel_Helper,
           className: "GraphPanel",
           func: Create_GraphPanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8940
// Name: _dynamic_initializer_for__g_ListPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListPanel_Helper,
           className: "ListPanel",
           func: Create_ListPanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8960
// Name: _dynamic_initializer_for__g_ListViewPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListViewPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListViewPanel_Helper,
           className: "ListViewPanel",
           func: Create_ListViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8980
// Name: _dynamic_initializer_for__g_Menu_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Menu_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Menu_Helper, className: "Menu", func: Create_Menu);
}

//------------------------------------------------------------------------------
// Address: 0x004B89B0
// Name: _dynamic_initializer_for__g_MenuBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuBar_Helper,
           className: "MenuBar",
           func: Create_MenuBar);
}

//------------------------------------------------------------------------------
// Address: 0x004B89D0
// Name: _dynamic_initializer_for__g_MenuButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuButton_Helper,
           className: "MenuButton",
           func: Create_MenuButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B89F0
// Name: _dynamic_initializer_for__g_MenuItem_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuItem_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuItem_Helper,
           className: "MenuItem",
           func: Create_MenuItem);
}

//------------------------------------------------------------------------------
// Address: 0x004B8A10
// Name: _dynamic_initializer_for__g_MessageBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MessageBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MessageBox_Helper,
           className: "MessageBox",
           func: (vgui::Panel *(__cdecl *)())MessageBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x004B8A30
// Name: _dynamic_initializer_for__g_ProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ProgressBar_Helper,
           className: "ProgressBar",
           func: Create_ProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x004B8A50
// Name: _dynamic_initializer_for__g_ContinuousProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ContinuousProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ContinuousProgressBar_Helper,
           className: "ContinuousProgressBar",
           func: Create_ContinuousProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x004B8A70
// Name: _dynamic_initializer_for__g_CircularProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CircularProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CircularProgressBar_Helper,
           className: "CircularProgressBar",
           func: Create_CircularProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x004B8A90
// Name: _dynamic_initializer_for__g_RadioButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RadioButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RadioButton_Helper,
           className: "RadioButton",
           func: Create_RadioButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B8AB0
// Name: _dynamic_initializer_for__g_RichText_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RichText_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RichText_Helper,
           className: "RichText",
           func: Create_RichText);
}

//------------------------------------------------------------------------------
// Address: 0x004B8AD0
// Name: _dynamic_initializer_for__g_ScalableImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScalableImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScalableImagePanel_Helper,
           className: "ScalableImagePanel",
           func: Create_ScalableImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x004B8AF0
// Name: _dynamic_initializer_for__g_ScrollBar_Vertical_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Vertical_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Vertical_Helper,
           className: "ScrollBar_Vertical",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Vertical_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x004B8B10
// Name: _dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Horizontal_Helper,
           className: "ScrollBar_Horizontal",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x004B8B30
// Name: _dynamic_initializer_for__g_ScrollBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Helper,
           className: "ScrollBar",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x004B8B50
// Name: _dynamic_initializer_for__g_TextEntry_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TextEntry_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TextEntry_Helper,
           className: "TextEntry",
           func: Create_TextEntry);
}

//------------------------------------------------------------------------------
// Address: 0x004B8B70
// Name: _dynamic_initializer_for__g_TreeView_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TreeView_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TreeView_Helper,
           className: "TreeView",
           func: Create_TreeView);
}

//------------------------------------------------------------------------------
// Address: 0x004B8B90
// Name: _dynamic_initializer_for__g_CTreeViewListControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CTreeViewListControl_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CTreeViewListControl_Helper,
           className: "CTreeViewListControl",
           func: Create_CTreeViewListControl);
}

//------------------------------------------------------------------------------
// Address: 0x004B8BB0
// Name: _dynamic_initializer_for__g_URLLabel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_URLLabel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_URLLabel_Helper,
           className: "URLLabel",
           func: (vgui::Panel *(__cdecl *)())URLLabel_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x004B8BE0
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8C00
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuaternionPool__()
{
  if ( ((unsigned __int8)&g_QuaternionPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_QuaternionPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_QuaternionPool__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8C30
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VectorPool__()
{
  if ( ((unsigned __int8)&g_VectorPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_VectorPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_VectorPool__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8C60
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatrixPool__()
{
  if ( ((unsigned __int8)&g_MatrixPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_MatrixPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_MatrixPool__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8C90
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8CD0
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8D00
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8D30
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x004B9440
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_BuildModeDialogMgr);
}

//------------------------------------------------------------------------------
// Address: 0x004B9460
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x004B9470
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x004B9480
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x004B9490
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x004B94C0
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x004B94D0
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x004B94E0
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004C54B0
// Name: class IMaterialSystem __near * vgui::MaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem *__cdecl vgui::MaterialSystem()
{
  return vgui::g_pMaterialSystem;
}

//------------------------------------------------------------------------------
// Address: 0x004C54C0
// Name: class IMaterialSystemHardwareConfig __near * vgui::MaterialSystemHardwareConfig(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystemHardwareConfig *__cdecl vgui::MaterialSystemHardwareConfig()
{
  return vgui::g_pMaterialSystemHardwareConfig;
}

//------------------------------------------------------------------------------
// Address: 0x004C54D0
// Name: class IMDLCache __near * vgui::MDLCache(void)
// Source: json
//------------------------------------------------------------------------------
IMDLCache *__cdecl vgui::MDLCache()
{
  return vgui::g_pMDLCache;
}

//------------------------------------------------------------------------------
// Address: 0x004C54E0
// Name: class IMatSystemSurface __near * vgui::MatSystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
IMatSystemSurface *__cdecl vgui::MatSystemSurface()
{
  return vgui::g_pMatSystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x004C54F0
// Name: class IStudioRender __near * vgui::StudioRender(void)
// Source: json
//------------------------------------------------------------------------------
IStudioRender *__cdecl vgui::StudioRender()
{
  return vgui::g_pStudioRender;
}

//------------------------------------------------------------------------------
// Address: 0x004C5500
// Name: bool vgui::VGui_InitMatSysInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitMatSysInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  IMaterialSystem *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IMatSystemSurface *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IMDLCache *v12; // eax
  int v13; // esi
  void *(__cdecl *v14)(const char *, int *); // eax
  IStudioRender *v15; // eax
  int v16; // esi
  void *(__cdecl *v17)(const char *, int *); // eax
  IMaterialSystemHardwareConfig *v18; // eax

  result = vgui::VGui_InitInterfacesList(moduleName, factoryList, numFactories);
  if ( result )
  {
    v4 = 0;
    if ( numFactories <= 0 )
    {
LABEL_6:
      v6 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v5 = factoryList[v4];
        if ( v5 != nullptr )
        {
          v6 = (IMaterialSystem *)v5(a1: "VMaterialSystem080", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pMaterialSystem = v6;
    if ( numFactories <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v8 = factoryList[v7];
        if ( v8 != nullptr )
        {
          v9 = (IMatSystemSurface *)v8(a1: "MatSystemSurface006", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::g_pMatSystemSurface = v9;
    if ( numFactories <= 0 )
    {
LABEL_16:
      v12 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v11 = factoryList[v10];
        if ( v11 != nullptr )
        {
          v12 = (IMDLCache *)v11(a1: "MDLCache004", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    v13 = 0;
    vgui::g_pMDLCache = v12;
    if ( numFactories <= 0 )
    {
LABEL_21:
      v15 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v14 = factoryList[v13];
        if ( v14 != nullptr )
        {
          v15 = (IStudioRender *)v14(a1: "VStudioRender026", a2: nullptr);
          if ( v15 != nullptr )
            break;
        }
        if ( ++v13 >= numFactories )
          goto LABEL_21;
      }
    }
    v16 = 0;
    vgui::g_pStudioRender = v15;
    if ( numFactories <= 0 )
    {
LABEL_26:
      v18 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v17 = factoryList[v16];
        if ( v17 != nullptr )
        {
          v18 = (IMaterialSystemHardwareConfig *)v17(a1: "MaterialSystemHardwareConfig013", a2: nullptr);
          if ( v18 != nullptr )
            break;
        }
        if ( ++v16 >= numFactories )
          goto LABEL_26;
      }
    }
    vgui::g_pMaterialSystemHardwareConfig = v18;
    return vgui::g_pMaterialSystem != nullptr && vgui::g_pMatSystemSurface != nullptr && v18 != nullptr;
  }
  return result;
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00431200
// Name: vgui::InitializeInterface
// Source: json
//------------------------------------------------------------------------------
void *__usercall vgui::InitializeInterface@<eax>(
        int numFactories@<edi>,
        const char *interfaceName,
        void *(__cdecl **factoryList)(const char *, int *))
{
  int v3; // esi
  void *(__cdecl *v4)(const char *, int *); // eax
  void *result; // eax

  v3 = 0;
  if ( numFactories <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = factoryList[v3];
    if ( v4 != nullptr )
    {
      result = v4(a1: interfaceName, a2: nullptr);
      if ( result != nullptr )
        break;
    }
    if ( ++v3 >= numFactories )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431240
// Name: bool vgui::VGui_InitMatSysInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitMatSysInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  IMaterialSystemHardwareConfig *v4; // eax

  result = vgui::VGui_InitInterfacesList(moduleName, factoryList, numFactories);
  if ( result )
  {
    vgui::g_pMaterialSystem = (IMaterialSystem *)vgui::InitializeInterface(
                                                   numFactories,
                                                   interfaceName: "VMaterialSystem080",
                                                   factoryList);
    vgui::g_pMatSystemSurface = (IMatSystemSurface *)vgui::InitializeInterface(
                                                       numFactories,
                                                       interfaceName: "MatSystemSurface006",
                                                       factoryList);
    vgui::g_pMDLCache = (IMDLCache *)vgui::InitializeInterface(numFactories, interfaceName: "MDLCache004", factoryList);
    vgui::g_pStudioRender = (IStudioRender *)vgui::InitializeInterface(
                                               numFactories,
                                               interfaceName: "VStudioRender026",
                                               factoryList);
    v4 = (IMaterialSystemHardwareConfig *)vgui::InitializeInterface(
                                            numFactories,
                                            interfaceName: "MaterialSystemHardwareConfig013",
                                            factoryList);
    vgui::g_pMaterialSystemHardwareConfig = v4;
    return vgui::g_pMaterialSystem != nullptr && vgui::g_pMatSystemSurface != nullptr && v4 != nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483250
// Name: class vgui::Panel __near * ComboBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__cdecl ComboBox_Factory()
{
  vgui::ComboBox *v0; // eax

  v0 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v0 != nullptr )
    return vgui::ComboBox::ComboBox(this: v0, parent: nullptr, panelName: nullptr, numLines: 5, allowEdit: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00483770
// Name: class vgui::Panel __near * Create_CvarToggleCheckButton(void)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__cdecl Create_CvarToggleCheckButton()
{
  vgui::CvarToggleCheckButton<ConVarRef> *v0; // eax

  v0 = (vgui::CvarToggleCheckButton<ConVarRef> *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v0 != nullptr )
    return vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: defaultValue,
             cvarname: nullptr,
             ignoreMissingCvar: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00494720
// Name: class vgui::Panel __near * MessageBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__cdecl MessageBox_Factory()
{
  vgui::MessageBox *v0; // eax

  v0 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v0 != nullptr )
    return vgui::MessageBox::MessageBox(this: v0, title: "MessageBox", text: "MessageBoxText", parent: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049B790
// Name: class vgui::Panel __near * ScrollBar_Vertical_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Vertical_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049B7C0
// Name: class vgui::Panel __near * ScrollBar_Horizontal_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Horizontal_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004A7FB0
// Name: class vgui::Panel __near * URLLabel_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__cdecl URLLabel_Factory()
{
  vgui::URLLabel *v0; // eax

  v0 = (vgui::URLLabel *)MemAlloc_Alloc(nSize: 0x1B4u);
  if ( v0 != nullptr )
    return vgui::URLLabel::URLLabel(this: v0, parent: nullptr, panelName: nullptr, text: "URLLabel", pszURL: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00533DD0
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>(__formal: nullptr);
  s_pUnpack_8 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533DE0
// Name: _dynamic_initializer_for__vgui::Button::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Button::s_pUnpackParams__()
{
  vgui::Button::s_pUnpackParams = s_pUnpack_8;
  return s_pUnpack_8;
}

//------------------------------------------------------------------------------
// Address: 0x00533E70
// Name: vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Label>(__formal: nullptr);
  s_pUnpack_9 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533E80
// Name: _dynamic_initializer_for__vgui::Label::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Label::s_pUnpackParams__()
{
  vgui::Label::s_pUnpackParams = s_pUnpack_9;
  return s_pUnpack_9;
}

//------------------------------------------------------------------------------
// Address: 0x00533EB0
// Name: vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Panel>(__formal: nullptr);
  s_pUnpack_10 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533EC0
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack_10;
  return s_pUnpack_10;
}

//------------------------------------------------------------------------------
// Address: 0x00533F50
// Name: _dynamic_initializer_for__vgui::Panel::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::Panel::m_MessageMap__()
{
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].func = (unsigned int) __thiscall vgui::Panel::`vcall'{48,{flat}};
  *((_QWORD *)&vgui::Panel::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].nameSymbol = 0;
  vgui::Panel::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00534120
// Name: vgui::_dynamic_initializer_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
int vgui::_dynamic_initializer_for__g_MenuMgr__()
{
  return atexit(func: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x00534370
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005343B0
// Name: _dynamic_initializer_for__vgui_show_glyph_miss__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_show_glyph_miss__()
{
  ConVar::ConVar(this: &vgui_show_glyph_miss, pName: "vgui_show_glyph_miss", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__vgui_show_glyph_miss__);
}

//------------------------------------------------------------------------------
// Address: 0x005353B0
// Name: _vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &stru_5E5848.m_PanelKeyBindingMapPool);
  CUtlDict<CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::RemoveAll(this: &stru_5E5848.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(this: &stru_5E5848.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00535420
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x00535470
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x005354C0
// Name: _dynamic_atexit_destructor_for__vgui_show_glyph_miss__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_show_glyph_miss__()
{
  ConVar::~ConVar(this: &vgui_show_glyph_miss);
}

//------------------------------------------------------------------------------
// Address: 0x00533DF0
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x00533E10
// Name: _dynamic_initializer_for__g_Button_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Button_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Button_Helper,
           className: "Button",
           func: Create_Button);
}

//------------------------------------------------------------------------------
// Address: 0x00533E30
// Name: _dynamic_initializer_for__g_EditablePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_EditablePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_EditablePanel_Helper,
           className: "EditablePanel",
           func: Create_EditablePanel);
}

//------------------------------------------------------------------------------
// Address: 0x00533E50
// Name: _dynamic_initializer_for__g_ImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ImagePanel_Helper,
           className: "ImagePanel",
           func: Create_ImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x00533E90
// Name: _dynamic_initializer_for__g_Label_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Label_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Label_Helper, className: "Label", func: Create_Label);
}

//------------------------------------------------------------------------------
// Address: 0x00533ED0
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x00533EF0
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x00533F00
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x00533FA0
// Name: _dynamic_initializer_for__g_ToggleButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ToggleButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ToggleButton_Helper,
           className: "ToggleButton",
           func: Create_ToggleButton);
}

//------------------------------------------------------------------------------
// Address: 0x00533FC0
// Name: _dynamic_initializer_for__g_AnimatingImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_AnimatingImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_AnimatingImagePanel_Helper,
           className: "AnimatingImagePanel",
           func: Create_AnimatingImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x00533FE0
// Name: _dynamic_initializer_for__g_CBitmapImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CBitmapImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CBitmapImagePanel_Helper,
           className: "CBitmapImagePanel",
           func: Create_CBitmapImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x00534000
// Name: _dynamic_initializer_for__g_CheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CheckButton_Helper,
           className: "CheckButton",
           func: Create_CheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x00534020
// Name: _dynamic_initializer_for__g_ComboBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ComboBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ComboBox_Helper,
           className: "ComboBox",
           func: (vgui::Panel *(__cdecl *)())ComboBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x00534040
// Name: _dynamic_initializer_for__g_CvarToggleCheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CvarToggleCheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CvarToggleCheckButton_Helper,
           className: "CvarToggleCheckButton",
           func: (vgui::Panel *(__cdecl *)())Create_CvarToggleCheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x00534060
// Name: _dynamic_initializer_for__g_Divider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Divider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Divider_Helper,
           className: "Divider",
           func: Create_Divider);
}

//------------------------------------------------------------------------------
// Address: 0x00534080
// Name: _dynamic_initializer_for__g_ExpandButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ExpandButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ExpandButton_Helper,
           className: "ExpandButton",
           func: Create_ExpandButton);
}

//------------------------------------------------------------------------------
// Address: 0x005340A0
// Name: _dynamic_initializer_for__g_GraphPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_GraphPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_GraphPanel_Helper,
           className: "GraphPanel",
           func: Create_GraphPanel);
}

//------------------------------------------------------------------------------
// Address: 0x005340C0
// Name: _dynamic_initializer_for__g_ListPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListPanel_Helper,
           className: "ListPanel",
           func: Create_ListPanel);
}

//------------------------------------------------------------------------------
// Address: 0x005340E0
// Name: _dynamic_initializer_for__g_ListViewPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListViewPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListViewPanel_Helper,
           className: "ListViewPanel",
           func: Create_ListViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00534100
// Name: _dynamic_initializer_for__g_Menu_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Menu_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Menu_Helper, className: "Menu", func: Create_Menu);
}

//------------------------------------------------------------------------------
// Address: 0x00534130
// Name: _dynamic_initializer_for__g_MenuBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuBar_Helper,
           className: "MenuBar",
           func: Create_MenuBar);
}

//------------------------------------------------------------------------------
// Address: 0x00534150
// Name: _dynamic_initializer_for__g_MenuButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuButton_Helper,
           className: "MenuButton",
           func: Create_MenuButton);
}

//------------------------------------------------------------------------------
// Address: 0x00534170
// Name: _dynamic_initializer_for__g_MenuItem_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuItem_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuItem_Helper,
           className: "MenuItem",
           func: Create_MenuItem);
}

//------------------------------------------------------------------------------
// Address: 0x00534190
// Name: _dynamic_initializer_for__g_MessageBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MessageBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MessageBox_Helper,
           className: "MessageBox",
           func: (vgui::Panel *(__cdecl *)())MessageBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x005341B0
// Name: _dynamic_initializer_for__g_ProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ProgressBar_Helper,
           className: "ProgressBar",
           func: Create_ProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x005341D0
// Name: _dynamic_initializer_for__g_ContinuousProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ContinuousProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ContinuousProgressBar_Helper,
           className: "ContinuousProgressBar",
           func: Create_ContinuousProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x005341F0
// Name: _dynamic_initializer_for__g_CircularProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CircularProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CircularProgressBar_Helper,
           className: "CircularProgressBar",
           func: Create_CircularProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x00534210
// Name: _dynamic_initializer_for__g_RadioButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RadioButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RadioButton_Helper,
           className: "RadioButton",
           func: Create_RadioButton);
}

//------------------------------------------------------------------------------
// Address: 0x00534230
// Name: _dynamic_initializer_for__g_RichText_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RichText_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RichText_Helper,
           className: "RichText",
           func: (vgui::Panel *(__cdecl *)())Create_RichText);
}

//------------------------------------------------------------------------------
// Address: 0x00534250
// Name: _dynamic_initializer_for__g_ScalableImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScalableImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScalableImagePanel_Helper,
           className: "ScalableImagePanel",
           func: Create_ScalableImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x00534270
// Name: _dynamic_initializer_for__g_ScrollBar_Vertical_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Vertical_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Vertical_Helper,
           className: "ScrollBar_Vertical",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Vertical_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x00534290
// Name: _dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Horizontal_Helper,
           className: "ScrollBar_Horizontal",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x005342B0
// Name: _dynamic_initializer_for__g_ScrollBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Helper,
           className: "ScrollBar",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x005342D0
// Name: _dynamic_initializer_for__g_TextEntry_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TextEntry_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TextEntry_Helper,
           className: "TextEntry",
           func: Create_TextEntry);
}

//------------------------------------------------------------------------------
// Address: 0x005342F0
// Name: _dynamic_initializer_for__g_TreeView_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TreeView_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TreeView_Helper,
           className: "TreeView",
           func: Create_TreeView);
}

//------------------------------------------------------------------------------
// Address: 0x00534310
// Name: _dynamic_initializer_for__g_CTreeViewListControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CTreeViewListControl_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CTreeViewListControl_Helper,
           className: "CTreeViewListControl",
           func: Create_CTreeViewListControl);
}

//------------------------------------------------------------------------------
// Address: 0x00534330
// Name: _dynamic_initializer_for__g_URLLabel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_URLLabel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_URLLabel_Helper,
           className: "URLLabel",
           func: (vgui::Panel *(__cdecl *)())URLLabel_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x00534350
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x00534380
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x00534390
// Name: _dynamic_initializer_for__s_FontManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_FontManager__()
{
  CFontManager::CFontManager(this: &s_FontManager);
  return atexit(func: dynamic_atexit_destructor_for__s_FontManager__);
}

//------------------------------------------------------------------------------
// Address: 0x005343E0
// Name: _dynamic_initializer_for__s_TextureDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TextureDictionary__()
{
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AddToTail(this: &s_TextureDictionary.m_Textures);
  return atexit(func: dynamic_atexit_destructor_for__s_TextureDictionary__);
}

//------------------------------------------------------------------------------
// Address: 0x00534400
// Name: _dynamic_initializer_for__g_BitmapFontTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BitmapFontTable__()
{
  g_BitmapFontTable.m_Memory.m_pMemory = (BitmapFontTable_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 80);
  g_BitmapFontTable.m_Size = 0;
  g_BitmapFontTable.m_pElements = g_BitmapFontTable.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_BitmapFontTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00535430
// Name: _dynamic_atexit_destructor_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ScriptSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x00535490
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_BuildModeDialogMgr);
}

//------------------------------------------------------------------------------
// Address: 0x005354A0
// Name: _dynamic_atexit_destructor_for__s_FontManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_FontManager__()
{
  CFontManager::ClearAllFonts(this: &s_FontManager);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_FontManager.m_Win32Fonts);
  CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::~CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>(this: &s_FontManager.m_FontAmalgams);
}

//------------------------------------------------------------------------------
// Address: 0x005354D0
// Name: _dynamic_atexit_destructor_for__s_TextureDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TextureDictionary__()
{
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(this: &s_TextureDictionary.m_Textures);
  if ( s_TextureDictionary.m_Textures.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_TextureDictionary.m_Textures.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_TextureDictionary.m_Textures.m_Memory.m_pMemory);
      s_TextureDictionary.m_Textures.m_Memory.m_pMemory = nullptr;
    }
    s_TextureDictionary.m_Textures.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00535520
// Name: _DataMapInit_BitmapGlyph_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_BitmapGlyph_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x00535530
// Name: _DataMapInit_BitmapFont_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_BitmapFont_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x00535540
// Name: _dynamic_atexit_destructor_for__g_BitmapFontTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BitmapFontTable__()
{
  CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::~CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>(this: &g_BitmapFontTable);
}

//------------------------------------------------------------------------------
// Address: 0x00535550
// Name: _DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x00535560
// Name: _DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x00535570
// Name: _DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x00535580
// Name: _DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x00535590
// Name: _DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

//------------------------------------------------------------------------------
// Address: 0x005355A0
// Name: _DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_6);
}

//------------------------------------------------------------------------------
// Address: 0x005355B0
// Name: _DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_7);
}

//------------------------------------------------------------------------------
// Address: 0x005355C0
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x005355D0
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x101CEA50
// Name: class vgui::Panel __near * VGui_GetFullscreenRootPanel(void)
// Source: json
//------------------------------------------------------------------------------
C_CSRootPanel *__cdecl VGui_GetFullscreenRootPanel()
{
  return g_pFullscreenRootPanel;
}

//------------------------------------------------------------------------------
// Address: 0x101D5180
// Name: class vgui::Panel __near * CvarToggleCheckButton_Factory(void)
// Source: json
//------------------------------------------------------------------------------
CCvarToggleCheckButton *__cdecl CvarToggleCheckButton_Factory()
{
  CCvarToggleCheckButton *v0; // eax

  v0 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v0 != nullptr )
    return CCvarToggleCheckButton::CCvarToggleCheckButton(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: "CvarToggleCheckButton",
             cvarname: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CB240
// Name: class IMaterialSystem __near * vgui::MaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystem *__cdecl vgui::MaterialSystem()
{
  return vgui::g_pMaterialSystem;
}

//------------------------------------------------------------------------------
// Address: 0x102CB250
// Name: class IMaterialSystemHardwareConfig __near * vgui::MaterialSystemHardwareConfig(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystemHardwareConfig *__cdecl vgui::MaterialSystemHardwareConfig()
{
  return vgui::g_pMaterialSystemHardwareConfig;
}

//------------------------------------------------------------------------------
// Address: 0x102CB260
// Name: class IMDLCache __near * vgui::MDLCache(void)
// Source: json
//------------------------------------------------------------------------------
IMDLCache *__cdecl vgui::MDLCache()
{
  return vgui::g_pMDLCache;
}

//------------------------------------------------------------------------------
// Address: 0x102CB270
// Name: class IMatSystemSurface __near * vgui::MatSystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
IMatSystemSurface *__cdecl vgui::MatSystemSurface()
{
  return vgui::g_pMatSystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x102CB280
// Name: class IStudioRender __near * vgui::StudioRender(void)
// Source: json
//------------------------------------------------------------------------------
IStudioRender *__cdecl vgui::StudioRender()
{
  return vgui::g_pStudioRender;
}

//------------------------------------------------------------------------------
// Address: 0x102CB290
// Name: bool vgui::VGui_InitMatSysInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitMatSysInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  IMaterialSystem *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IMatSystemSurface *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IMDLCache *v12; // eax
  int v13; // esi
  void *(__cdecl *v14)(const char *, int *); // eax
  IStudioRender *v15; // eax
  int v16; // esi
  void *(__cdecl *v17)(const char *, int *); // eax
  IMaterialSystemHardwareConfig *v18; // eax

  result = vgui::VGui_InitInterfacesList(moduleName, factoryList, numFactories);
  if ( result )
  {
    v4 = 0;
    if ( numFactories <= 0 )
    {
LABEL_6:
      v6 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v5 = factoryList[v4];
        if ( v5 != nullptr )
        {
          v6 = (IMaterialSystem *)v5(a1: "VMaterialSystem080", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pMaterialSystem = v6;
    if ( numFactories <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v8 = factoryList[v7];
        if ( v8 != nullptr )
        {
          v9 = (IMatSystemSurface *)v8(a1: "MatSystemSurface006", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::g_pMatSystemSurface = v9;
    if ( numFactories <= 0 )
    {
LABEL_16:
      v12 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v11 = factoryList[v10];
        if ( v11 != nullptr )
        {
          v12 = (IMDLCache *)v11(a1: "MDLCache004", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    v13 = 0;
    vgui::g_pMDLCache = v12;
    if ( numFactories <= 0 )
    {
LABEL_21:
      v15 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v14 = factoryList[v13];
        if ( v14 != nullptr )
        {
          v15 = (IStudioRender *)v14(a1: "VStudioRender026", a2: nullptr);
          if ( v15 != nullptr )
            break;
        }
        if ( ++v13 >= numFactories )
          goto LABEL_21;
      }
    }
    v16 = 0;
    vgui::g_pStudioRender = v15;
    if ( numFactories <= 0 )
    {
LABEL_26:
      v18 = nullptr;
    }
    else
    {
      while ( 1 )
      {
        v17 = factoryList[v16];
        if ( v17 != nullptr )
        {
          v18 = (IMaterialSystemHardwareConfig *)v17(a1: "MaterialSystemHardwareConfig013", a2: nullptr);
          if ( v18 != nullptr )
            break;
        }
        if ( ++v16 >= numFactories )
          goto LABEL_26;
      }
    }
    vgui::g_pMaterialSystemHardwareConfig = v18;
    return vgui::g_pMaterialSystem != nullptr && vgui::g_pMatSystemSurface != nullptr && v18 != nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A1BC0
// Name: class vgui::Panel __near * ComboBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__cdecl ComboBox_Factory()
{
  vgui::ComboBox *v0; // eax

  v0 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v0 != nullptr )
    return vgui::ComboBox::ComboBox(this: v0, parent: nullptr, panelName: nullptr, numLines: 5, allowEdit: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103A20A0
// Name: class vgui::Panel __near * Create_CvarToggleCheckButton(void)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__cdecl Create_CvarToggleCheckButton()
{
  vgui::CvarToggleCheckButton<ConVarRef> *v0; // eax

  v0 = (vgui::CvarToggleCheckButton<ConVarRef> *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v0 != nullptr )
    return vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: prType,
             cvarname: nullptr,
             ignoreMissingCvar: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B35A0
// Name: class vgui::Panel __near * MessageBox_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__cdecl MessageBox_Factory()
{
  vgui::MessageBox *v0; // eax

  v0 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v0 != nullptr )
    return vgui::MessageBox::MessageBox(this: v0, title: "MessageBox", text: "MessageBoxText", parent: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B7010
// Name: class vgui::Panel __near * ScrollBar_Vertical_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Vertical_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B7040
// Name: class vgui::Panel __near * ScrollBar_Horizontal_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__cdecl ScrollBar_Horizontal_Factory()
{
  vgui::ScrollBar *v0; // eax

  v0 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ScrollBar::ScrollBar(this: v0, parent: nullptr, panelName: nullptr, vertical: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103BD1C0
// Name: class vgui::Panel __near * URLLabel_Factory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__cdecl URLLabel_Factory()
{
  vgui::URLLabel *v0; // eax

  v0 = (vgui::URLLabel *)MemAlloc_Alloc(nSize: 0x1B4u);
  if ( v0 != nullptr )
    return vgui::URLLabel::URLLabel(this: v0, parent: nullptr, panelName: nullptr, text: "URLLabel", pszURL: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10423FD0
// Name: _dynamic_initializer_for__vgui_message_dialog_modal__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_message_dialog_modal__()
{
  ConVar::ConVar(this: &vgui_message_dialog_modal, pName: "vgui_message_dialog_modal", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__vgui_message_dialog_modal__);
}

//------------------------------------------------------------------------------
// Address: 0x1042EEE0
// Name: vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Panel>();
  s_pUnpack_172 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042EEF0
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack_172;
  return s_pUnpack_172;
}

//------------------------------------------------------------------------------
// Address: 0x1042EF80
// Name: _dynamic_initializer_for__vgui::Panel::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::Panel::m_MessageMap__()
{
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].func = (unsigned int) __thiscall vgui::Panel::`vcall'{48,{flat}};
  *((_QWORD *)&vgui::Panel::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&vgui::Panel::m_MessageMap[0].nameSymbol = 0;
  vgui::Panel::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042F030
// Name: vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Label>();
  s_pUnpack_173 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042F040
// Name: _dynamic_initializer_for__vgui::Label::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Label::s_pUnpackParams__()
{
  vgui::Label::s_pUnpackParams = s_pUnpack_173;
  return s_pUnpack_173;
}

//------------------------------------------------------------------------------
// Address: 0x1042F090
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>();
  s_pUnpack_174 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042F0A0
// Name: _dynamic_initializer_for__vgui::Button::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Button::s_pUnpackParams__()
{
  vgui::Button::s_pUnpackParams = s_pUnpack_174;
  return s_pUnpack_174;
}

//------------------------------------------------------------------------------
// Address: 0x1042F290
// Name: vgui::_dynamic_initializer_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
int vgui::_dynamic_initializer_for__g_MenuMgr__()
{
  return atexit(func: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F4F0
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F530
// Name: _dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__);
}

//------------------------------------------------------------------------------
// Address: 0x10435AE0
// Name: _dynamic_atexit_destructor_for__vgui_message_dialog_modal__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_message_dialog_modal__()
{
  ConVar::~ConVar(this: &vgui_message_dialog_modal);
}

//------------------------------------------------------------------------------
// Address: 0x10437290
// Name: _vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::GetPanelKeyBindingMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary.m_PanelKeyBindingMapPool);
  CUtlDict<CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::RemoveAll(this: &dictionary.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10437350
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10437380
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x104373B0
// Name: _dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::ToolWindow::s_ToolWindows);
}

//------------------------------------------------------------------------------
// Address: 0x10424000
// Name: _dynamic_initializer_for__cl_showncustomtabhelp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showncustomtabhelp__()
{
  ConVar::ConVar(this: &cl_showncustomtabhelp, pName: "cl_showncustomtabhelp", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cl_showncustomtabhelp__);
}

//------------------------------------------------------------------------------
// Address: 0x10424030
// Name: _dynamic_initializer_for__gamemenucommand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gamemenucommand__()
{
  ConCommand::ConCommand(
    this: &gamemenucommand,
    pName: "gamemenucommand",
    callback: (void (__cdecl *)())CC_GameMenuCommand,
    pHelpString: "Issue game menu command.",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))CC_GameMenuCompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__gamemenucommand__);
}

//------------------------------------------------------------------------------
// Address: 0x1042EF00
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x1042EF20
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x1042EF30
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x1042EFD0
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x1042EFF0
// Name: _dynamic_initializer_for__g_EditablePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_EditablePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_EditablePanel_Helper,
           className: "EditablePanel",
           func: (vgui::Panel *(__cdecl *)())Create_EditablePanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F010
// Name: _dynamic_initializer_for__g_TextEntry_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TextEntry_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TextEntry_Helper,
           className: "TextEntry",
           func: (vgui::Panel *(__cdecl *)())Create_TextEntry);
}

//------------------------------------------------------------------------------
// Address: 0x1042F050
// Name: _dynamic_initializer_for__g_Label_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Label_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Label_Helper,
           className: "Label",
           func: (vgui::Panel *(__cdecl *)())Create_Label);
}

//------------------------------------------------------------------------------
// Address: 0x1042F070
// Name: _dynamic_initializer_for__g_RichText_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RichText_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RichText_Helper,
           className: "RichText",
           func: (vgui::Panel *(__cdecl *)())Create_RichText);
}

//------------------------------------------------------------------------------
// Address: 0x1042F0B0
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F0D0
// Name: _dynamic_initializer_for__g_Button_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Button_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Button_Helper,
           className: "Button",
           func: (vgui::Panel *(__cdecl *)())Create_Button);
}

//------------------------------------------------------------------------------
// Address: 0x1042F0F0
// Name: _dynamic_initializer_for__g_CheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CheckButton_Helper,
           className: "CheckButton",
           func: (vgui::Panel *(__cdecl *)())Create_CheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x1042F110
// Name: _dynamic_initializer_for__g_ToggleButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ToggleButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ToggleButton_Helper,
           className: "ToggleButton",
           func: (vgui::Panel *(__cdecl *)())Create_ToggleButton);
}

//------------------------------------------------------------------------------
// Address: 0x1042F130
// Name: _dynamic_initializer_for__g_ImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ImagePanel_Helper,
           className: "ImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_ImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F150
// Name: _dynamic_initializer_for__g_AnimatingImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_AnimatingImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_AnimatingImagePanel_Helper,
           className: "AnimatingImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_AnimatingImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F170
// Name: _dynamic_initializer_for__g_CBitmapImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CBitmapImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CBitmapImagePanel_Helper,
           className: "CBitmapImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_CBitmapImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F190
// Name: _dynamic_initializer_for__g_ComboBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ComboBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ComboBox_Helper,
           className: "ComboBox",
           func: (vgui::Panel *(__cdecl *)())ComboBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1042F1B0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CvarToggleCheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CvarToggleCheckButton_Helper,
           className: "CvarToggleCheckButton",
           func: (vgui::Panel *(__cdecl *)())Create_CvarToggleCheckButton);
}

//------------------------------------------------------------------------------
// Address: 0x1042F1D0
// Name: _dynamic_initializer_for__g_Divider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Divider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Divider_Helper,
           className: "Divider",
           func: (vgui::Panel *(__cdecl *)())Create_Divider);
}

//------------------------------------------------------------------------------
// Address: 0x1042F1F0
// Name: _dynamic_initializer_for__g_ExpandButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ExpandButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ExpandButton_Helper,
           className: "ExpandButton",
           func: (vgui::Panel *(__cdecl *)())Create_ExpandButton);
}

//------------------------------------------------------------------------------
// Address: 0x1042F210
// Name: _dynamic_initializer_for__g_GraphPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_GraphPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_GraphPanel_Helper,
           className: "GraphPanel",
           func: (vgui::Panel *(__cdecl *)())Create_GraphPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F230
// Name: _dynamic_initializer_for__g_ListPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListPanel_Helper,
           className: "ListPanel",
           func: (vgui::Panel *(__cdecl *)())Create_ListPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F250
// Name: _dynamic_initializer_for__g_ListViewPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ListViewPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ListViewPanel_Helper,
           className: "ListViewPanel",
           func: (vgui::Panel *(__cdecl *)())Create_ListViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F270
// Name: _dynamic_initializer_for__g_Menu_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Menu_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Menu_Helper,
           className: "Menu",
           func: (vgui::Panel *(__cdecl *)())Create_Menu);
}

//------------------------------------------------------------------------------
// Address: 0x1042F2A0
// Name: _dynamic_initializer_for__g_MenuBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuBar_Helper,
           className: "MenuBar",
           func: (vgui::Panel *(__cdecl *)())Create_MenuBar);
}

//------------------------------------------------------------------------------
// Address: 0x1042F2C0
// Name: _dynamic_initializer_for__g_MenuButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuButton_Helper,
           className: "MenuButton",
           func: (vgui::Panel *(__cdecl *)())Create_MenuButton);
}

//------------------------------------------------------------------------------
// Address: 0x1042F2E0
// Name: _dynamic_initializer_for__g_MenuItem_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MenuItem_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MenuItem_Helper,
           className: "MenuItem",
           func: (vgui::Panel *(__cdecl *)())Create_MenuItem);
}

//------------------------------------------------------------------------------
// Address: 0x1042F300
// Name: _dynamic_initializer_for__g_MessageBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_MessageBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_MessageBox_Helper,
           className: "MessageBox",
           func: (vgui::Panel *(__cdecl *)())MessageBox_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1042F320
// Name: _dynamic_initializer_for__g_ProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ProgressBar_Helper,
           className: "ProgressBar",
           func: (vgui::Panel *(__cdecl *)())Create_ProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x1042F340
// Name: _dynamic_initializer_for__g_ContinuousProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ContinuousProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ContinuousProgressBar_Helper,
           className: "ContinuousProgressBar",
           func: (vgui::Panel *(__cdecl *)())Create_ContinuousProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x1042F360
// Name: _dynamic_initializer_for__g_CircularProgressBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CircularProgressBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CircularProgressBar_Helper,
           className: "CircularProgressBar",
           func: (vgui::Panel *(__cdecl *)())Create_CircularProgressBar);
}

//------------------------------------------------------------------------------
// Address: 0x1042F380
// Name: _dynamic_initializer_for__g_RadioButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_RadioButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_RadioButton_Helper,
           className: "RadioButton",
           func: (vgui::Panel *(__cdecl *)())Create_RadioButton);
}

//------------------------------------------------------------------------------
// Address: 0x1042F3A0
// Name: _dynamic_initializer_for__g_ScalableImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScalableImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScalableImagePanel_Helper,
           className: "ScalableImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_ScalableImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F3C0
// Name: _dynamic_initializer_for__g_ScrollBar_Vertical_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Vertical_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Vertical_Helper,
           className: "ScrollBar_Vertical",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Vertical_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1042F3E0
// Name: _dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Horizontal_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Horizontal_Helper,
           className: "ScrollBar_Horizontal",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1042F400
// Name: _dynamic_initializer_for__g_ScrollBar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ScrollBar_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ScrollBar_Helper,
           className: "ScrollBar",
           func: (vgui::Panel *(__cdecl *)())ScrollBar_Horizontal_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1042F420
// Name: _dynamic_initializer_for__g_TreeView_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_TreeView_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_TreeView_Helper,
           className: "TreeView",
           func: (vgui::Panel *(__cdecl *)())Create_TreeView);
}

//------------------------------------------------------------------------------
// Address: 0x1042F440
// Name: _dynamic_initializer_for__g_CTreeViewListControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CTreeViewListControl_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CTreeViewListControl_Helper,
           className: "CTreeViewListControl",
           func: (vgui::Panel *(__cdecl *)())Create_CTreeViewListControl);
}

//------------------------------------------------------------------------------
// Address: 0x1042F460
// Name: _dynamic_initializer_for__g_URLLabel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_URLLabel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_URLLabel_Helper,
           className: "URLLabel",
           func: (vgui::Panel *(__cdecl *)())URLLabel_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1042F480
// Name: _dynamic_initializer_for__g_Slider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Slider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Slider_Helper,
           className: "Slider",
           func: (vgui::Panel *(__cdecl *)())Create_Slider);
}

//------------------------------------------------------------------------------
// Address: 0x1042F4A0
// Name: _dynamic_initializer_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StartDirContexts__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StartDirContexts__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F4B0
// Name: _dynamic_initializer_for__g_SectionedListPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_SectionedListPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_SectionedListPanel_Helper,
           className: "SectionedListPanel",
           func: (vgui::Panel *(__cdecl *)())Create_SectionedListPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F4D0
// Name: _dynamic_initializer_for__g_CFooterPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CFooterPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CFooterPanel_Helper,
           className: "CFooterPanel",
           func: (vgui::Panel *(__cdecl *)())Create_CFooterPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1042F500
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F510
// Name: _dynamic_initializer_for__g_CControllerMap_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CControllerMap_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CControllerMap_Helper,
           className: "CControllerMap",
           func: (vgui::Panel *(__cdecl *)())Create_CControllerMap);
}

//------------------------------------------------------------------------------
// Address: 0x10435AF0
// Name: _dynamic_atexit_destructor_for__cl_showncustomtabhelp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showncustomtabhelp__()
{
  ConVar::~ConVar(this: &cl_showncustomtabhelp);
}

//------------------------------------------------------------------------------
// Address: 0x10435B00
// Name: _dynamic_atexit_destructor_for__gamemenucommand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gamemenucommand__()
{
  ConCommand::~ConCommand(this: &gamemenucommand);
}

//------------------------------------------------------------------------------
// Address: 0x10437360
// Name: _dynamic_atexit_destructor_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_StartDirContexts__()
{
  CUtlDict<CUtlString,unsigned short>::RemoveAll(this: &s_StartDirContexts);
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_StartDirContexts.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x104373A0
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_BuildModeDialogMgr);
}

} // namespace client
