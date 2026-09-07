// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmecontrols.cpp
// Functions: 82
// ============================================================

#include "vgui2\dme_controls\dmecontrols.h"

//------------------------------------------------------------------------------
// Address: 0x00402CE0
// Name: class vgui::Panel __near * CreateElementViewerPanel(void)
// Source: json
//------------------------------------------------------------------------------
CElementViewerPanel *__cdecl CreateElementViewerPanel()
{
  CElementViewerPanel *v0; // eax
  CElementViewerPanel *v1; // esi
  CElementViewerPanel_vtbl *v2; // edi
  unsigned int v3; // eax

  v0 = (CElementViewerPanel *)MemAlloc_Alloc(nSize: 0x18Cu);
  if ( v0 != nullptr )
    v1 = CElementViewerPanel::CElementViewerPanel(this: v0);
  else
    v1 = nullptr;
  v2 = v1->vgui::Panel::vgui::IClientPanel::__vftable;
  v3 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  v2->SetParent(this: v1, a2: v3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0044FC60
// Name: class ISoundEmitterSystemBase __near * vgui::SoundEmitterSystem(void)
// Source: json
//------------------------------------------------------------------------------
ISoundEmitterSystemBase *__cdecl vgui::SoundEmitterSystem()
{
  return vgui::g_pSoundEmitterSystem;
}

//------------------------------------------------------------------------------
// Address: 0x0044FC70
// Name: class IEngineTool __near * vgui::EngineTool(void)
// Source: json
//------------------------------------------------------------------------------
IEngineTool *__cdecl vgui::EngineTool()
{
  return vgui::enginetools;
}

//------------------------------------------------------------------------------
// Address: 0x0044FC80
// Name: class IElementPropertiesChoices __near * vgui::ElementPropertiesChoices(void)
// Source: json
//------------------------------------------------------------------------------
IElementPropertiesChoices *__cdecl vgui::ElementPropertiesChoices()
{
  return vgui::g_pElementPropertiesChoices;
}

//------------------------------------------------------------------------------
// Address: 0x0044FC90
// Name: void vgui::SetElementPropertiesChoices(class IElementPropertiesChoices __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::SetElementPropertiesChoices(IElementPropertiesChoices *pElementPropertiesChoices)
{
  vgui::g_pElementPropertiesChoices = pElementPropertiesChoices;
  if ( pElementPropertiesChoices == nullptr )
    vgui::g_pElementPropertiesChoices = &s_DefaultChoices;
}

//------------------------------------------------------------------------------
// Address: 0x00606410
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
// Address: 0x00606910
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
// Address: 0x006133F0
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
// Address: 0x0061A7B0
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
// Address: 0x0061A7E0
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
// Address: 0x00627C20
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
// Address: 0x00680E90
// Name: vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Panel>(__formal: nullptr);
  s_pUnpack_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00680EA0
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack_1;
  return s_pUnpack_1;
}

//------------------------------------------------------------------------------
// Address: 0x00680F30
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
// Address: 0x00680FD0
// Name: vgui::_dynamic_initializer_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
int vgui::_dynamic_initializer_for__g_MenuMgr__()
{
  return atexit(func: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x00681000
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>(__formal: nullptr);
  s_pUnpack_2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00681010
// Name: _dynamic_initializer_for__vgui::Button::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Button::s_pUnpackParams__()
{
  vgui::Button::s_pUnpackParams = s_pUnpack_2;
  return s_pUnpack_2;
}

//------------------------------------------------------------------------------
// Address: 0x006810A0
// Name: vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Label>(__formal: nullptr);
  s_pUnpack_3 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006810B0
// Name: _dynamic_initializer_for__vgui::Label::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Label::s_pUnpackParams__()
{
  vgui::Label::s_pUnpackParams = s_pUnpack_3;
  return s_pUnpack_3;
}

//------------------------------------------------------------------------------
// Address: 0x00681460
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00681480
// Name: _dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__);
}

//------------------------------------------------------------------------------
// Address: 0x006833D0
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
// Address: 0x006834A0
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x006834C0
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x006834F0
// Name: _dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vgui::ToolWindow::s_ToolWindows);
}

//------------------------------------------------------------------------------
// Address: 0x00680EB0
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x00680ED0
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x00680EE0
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x00680F80
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x00680FA0
// Name: _dynamic_initializer_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StartDirContexts__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StartDirContexts__);
}

//------------------------------------------------------------------------------
// Address: 0x00680FB0
// Name: _dynamic_initializer_for__g_Menu_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Menu_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Menu_Helper, className: "Menu", func: Create_Menu);
}

//------------------------------------------------------------------------------
// Address: 0x00680FE0
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
// Address: 0x00681020
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x00681040
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
// Address: 0x00681060
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
// Address: 0x00681080
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
// Address: 0x006810C0
// Name: _dynamic_initializer_for__g_Label_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Label_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Label_Helper, className: "Label", func: Create_Label);
}

//------------------------------------------------------------------------------
// Address: 0x006810E0
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
// Address: 0x00681100
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
// Address: 0x00681120
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
// Address: 0x00681140
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
// Address: 0x00681160
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
// Address: 0x00681180
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
// Address: 0x006811A0
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
// Address: 0x006811C0
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
// Address: 0x006811E0
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
// Address: 0x00681200
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
// Address: 0x00681220
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
// Address: 0x00681240
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
// Address: 0x00681260
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
// Address: 0x00681280
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
// Address: 0x006812A0
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
// Address: 0x006812C0
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
// Address: 0x006812E0
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
// Address: 0x00681300
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
// Address: 0x00681320
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
// Address: 0x00681340
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
// Address: 0x00681360
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
// Address: 0x00681380
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
// Address: 0x006813A0
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
// Address: 0x006813C0
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
// Address: 0x006813E0
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
// Address: 0x00681400
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
// Address: 0x00681420
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
// Address: 0x00681440
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
// Address: 0x00681470
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x00681490
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
// Address: 0x006814C0
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
// Address: 0x006814F0
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
// Address: 0x00681520
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
// Address: 0x00681560
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
// Address: 0x00681590
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
// Address: 0x006815C0
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x006834B0
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

//------------------------------------------------------------------------------
// Address: 0x006834E0
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_BuildModeDialogMgr);
}

//------------------------------------------------------------------------------
// Address: 0x00683500
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x00683510
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x00683520
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x00683530
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
// Address: 0x00683560
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x00683570
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x00683580
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102ED1B0
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
// Address: 0x102ED6A0
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
             text: &var,
             cvarname: nullptr,
             ignoreMissingCvar: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102FEF50
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
// Address: 0x103066E0
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
// Address: 0x10306710
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
// Address: 0x1030CCB0
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
// Address: 0x10463640
// Name: class ISoundEmitterSystemBase __near * vgui::SoundEmitterSystem(void)
// Source: json
//------------------------------------------------------------------------------
ISoundEmitterSystemBase *__cdecl vgui::SoundEmitterSystem()
{
  return vgui::g_pSoundEmitterSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10463650
// Name: class IEngineTool __near * vgui::EngineTool(void)
// Source: json
//------------------------------------------------------------------------------
IEngineTool *__cdecl vgui::EngineTool()
{
  return vgui::enginetools;
}

//------------------------------------------------------------------------------
// Address: 0x10463660
// Name: class IElementPropertiesChoices __near * vgui::ElementPropertiesChoices(void)
// Source: json
//------------------------------------------------------------------------------
IElementPropertiesChoices *__cdecl vgui::ElementPropertiesChoices()
{
  return vgui::g_pElementPropertiesChoices;
}

//------------------------------------------------------------------------------
// Address: 0x10463670
// Name: bool vgui::VGui_InitDmeInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitDmeInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  ISoundEmitterSystemBase *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IEngineTool *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IPhysicsCollision *v12; // eax

  result = vgui::VGui_InitMatSysInterfacesList(moduleName, factoryList, numFactories);
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
          v6 = (ISoundEmitterSystemBase *)v5(a1: "VSoundEmitter003", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pSoundEmitterSystem = v6;
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
          v9 = (IEngineTool *)v8(a1: "VENGINETOOL003", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::enginetools = v9;
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
          v12 = (IPhysicsCollision *)v11(a1: "VPhysicsCollision007", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    vgui::g_pPhysicsCollision = v12;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C42F0
// Name: vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Panel>();
  s_pUnpack_171 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C4300
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack_171;
  return s_pUnpack_171;
}

//------------------------------------------------------------------------------
// Address: 0x105C4390
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
// Address: 0x105C4420
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>();
  s_pUnpack_172 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C4430
// Name: _dynamic_initializer_for__vgui::Button::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Button::s_pUnpackParams__()
{
  vgui::Button::s_pUnpackParams = s_pUnpack_172;
  return s_pUnpack_172;
}

//------------------------------------------------------------------------------
// Address: 0x105C44C0
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
// Address: 0x105C44D0
// Name: _dynamic_initializer_for__vgui::Label::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Label::s_pUnpackParams__()
{
  vgui::Label::s_pUnpackParams = s_pUnpack_173;
  return s_pUnpack_173;
}

//------------------------------------------------------------------------------
// Address: 0x105C4680
// Name: vgui::_dynamic_initializer_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
int vgui::_dynamic_initializer_for__g_MenuMgr__()
{
  return atexit(func: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x105C4890
// Name: _dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__);
}

//------------------------------------------------------------------------------
// Address: 0x105C48B0
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x105CBFE0
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
// Address: 0x105CC0A0
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x105CC0B0
// Name: _dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::ToolWindow::s_ToolWindows);
}

//------------------------------------------------------------------------------
// Address: 0x105CC0E0
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x105C4310
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x105C4330
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x105C4340
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x105C43E0
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x105C4400
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
// Address: 0x105C4440
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x105C4460
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
// Address: 0x105C4480
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
// Address: 0x105C44A0
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
// Address: 0x105C44E0
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
// Address: 0x105C4500
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
// Address: 0x105C4520
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
// Address: 0x105C4540
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
// Address: 0x105C4560
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
// Address: 0x105C4580
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
// Address: 0x105C45A0
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
// Address: 0x105C45C0
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
// Address: 0x105C45E0
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
// Address: 0x105C4600
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
// Address: 0x105C4620
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
// Address: 0x105C4640
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
// Address: 0x105C4660
// Name: _dynamic_initializer_for__g_Menu_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Menu_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Menu_Helper, className: "Menu", func: Create_Menu);
}

//------------------------------------------------------------------------------
// Address: 0x105C4690
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
// Address: 0x105C46B0
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
// Address: 0x105C46D0
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
// Address: 0x105C46F0
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
// Address: 0x105C4710
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
// Address: 0x105C4730
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
// Address: 0x105C4750
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
// Address: 0x105C4770
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
// Address: 0x105C4790
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
// Address: 0x105C47B0
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
// Address: 0x105C47D0
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
// Address: 0x105C47F0
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
// Address: 0x105C4810
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
// Address: 0x105C4830
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
// Address: 0x105C4850
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
// Address: 0x105C4870
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
// Address: 0x105C48A0
// Name: _dynamic_initializer_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StartDirContexts__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StartDirContexts__);
}

//------------------------------------------------------------------------------
// Address: 0x105C48C0
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x105C48CC
// Name: _dynamic_initializer_for___afxTermDllState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___afxTermDllState__()
{
  int result; // eax

  AfxTlsAddRef();
  result = atexit(func: AfxTermDllState);
  _afxTermDllState = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C48E2
// Name: _dynamic_initializer_for___simpleMemoryException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___simpleMemoryException__()
{
  return atexit(func: dynamic_atexit_destructor_for___simpleMemoryException__);
}

//------------------------------------------------------------------------------
// Address: 0x105C48EE
// Name: _dynamic_initializer_for___simpleNotSupportedException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___simpleNotSupportedException__()
{
  return atexit(func: dynamic_atexit_destructor_for___simpleNotSupportedException__);
}

//------------------------------------------------------------------------------
// Address: 0x105C48FA
// Name: _dynamic_initializer_for___simpleInvalidArgException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___simpleInvalidArgException__()
{
  return atexit(func: dynamic_atexit_destructor_for___simpleInvalidArgException__);
}

//------------------------------------------------------------------------------
// Address: 0x105C4906
// Name: _dynamic_initializer_for___afxHtmlHelpState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___afxHtmlHelpState__()
{
  return atexit(func: dynamic_atexit_destructor_for___afxHtmlHelpState__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC0C0
// Name: _dynamic_atexit_destructor_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_StartDirContexts__()
{
  CUtlDict<CUtlString,unsigned short>::RemoveAll(this: &s_StartDirContexts);
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_StartDirContexts.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x105CC100
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_BuildModeDialogMgr);
}

//------------------------------------------------------------------------------
// Address: 0x105CC10A
// Name: _dynamic_atexit_destructor_for___simpleMemoryException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___simpleMemoryException__()
{
  _simpleMemoryException.__vftable = (CMemoryException_vtbl *)&CSimpleException::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC115
// Name: _dynamic_atexit_destructor_for___simpleNotSupportedException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___simpleNotSupportedException__()
{
  _simpleNotSupportedException.__vftable = (CNotSupportedException_vtbl *)&CSimpleException::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC120
// Name: _dynamic_atexit_destructor_for___simpleInvalidArgException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___simpleInvalidArgException__()
{
  _simpleInvalidArgException.__vftable = (CInvalidArgException_vtbl *)&CSimpleException::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC12B
// Name: _dynamic_atexit_destructor_for___afxHtmlHelpState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxHtmlHelpState__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxHtmlHelpState);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004072E0
// Name: class vgui::Panel __near * CreateSceneViewerPanel(void)
// Source: json
//------------------------------------------------------------------------------
CSceneViewerPanel *__cdecl CreateSceneViewerPanel()
{
  CSceneViewerPanel *v0; // eax
  CSceneViewerPanel *v1; // eax
  CSceneViewerPanel_vtbl *v2; // esi
  unsigned int v3; // eax

  if ( s_pSceneViewerPanel != nullptr )
    _Warning(a1: "Non-NULL Sceneviewer Panel!\n");
  v0 = (CSceneViewerPanel *)MemAlloc_Alloc(nSize: 0x268u);
  if ( v0 != nullptr )
    v1 = CSceneViewerPanel::CSceneViewerPanel(this: v0);
  else
    v1 = nullptr;
  s_pSceneViewerPanel = v1;
  v2 = v1->vgui::Panel::vgui::IClientPanel::__vftable;
  v3 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  v2->SetParent(this: s_pSceneViewerPanel, a2: v3);
  return s_pSceneViewerPanel;
}

//------------------------------------------------------------------------------
// Address: 0x0046CB60
// Name: class ISoundEmitterSystemBase __near * vgui::SoundEmitterSystem(void)
// Source: json
//------------------------------------------------------------------------------
ISoundEmitterSystemBase *__cdecl vgui::SoundEmitterSystem()
{
  return vgui::g_pSoundEmitterSystem;
}

//------------------------------------------------------------------------------
// Address: 0x0046CB70
// Name: class IEngineTool __near * vgui::EngineTool(void)
// Source: json
//------------------------------------------------------------------------------
IEngineTool *__cdecl vgui::EngineTool()
{
  return vgui::enginetools;
}

//------------------------------------------------------------------------------
// Address: 0x0046CB80
// Name: class IElementPropertiesChoices __near * vgui::ElementPropertiesChoices(void)
// Source: json
//------------------------------------------------------------------------------
IElementPropertiesChoices *__cdecl vgui::ElementPropertiesChoices()
{
  return vgui::g_pElementPropertiesChoices;
}

//------------------------------------------------------------------------------
// Address: 0x0046CB90
// Name: bool vgui::VGui_InitDmeInterfacesList(char const __near *,void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InitDmeInterfacesList(
        const char *moduleName,
        void *(__cdecl **factoryList)(const char *, int *),
        int numFactories)
{
  bool result; // al
  int v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  ISoundEmitterSystemBase *v6; // eax
  int v7; // esi
  void *(__cdecl *v8)(const char *, int *); // eax
  IEngineTool *v9; // eax
  int v10; // esi
  void *(__cdecl *v11)(const char *, int *); // eax
  IPhysicsCollision *v12; // eax

  result = vgui::VGui_InitMatSysInterfacesList(moduleName, factoryList, numFactories);
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
          v6 = (ISoundEmitterSystemBase *)v5(a1: "VSoundEmitter003", a2: nullptr);
          if ( v6 != nullptr )
            break;
        }
        if ( ++v4 >= numFactories )
          goto LABEL_6;
      }
    }
    v7 = 0;
    vgui::g_pSoundEmitterSystem = v6;
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
          v9 = (IEngineTool *)v8(a1: "VENGINETOOL003", a2: nullptr);
          if ( v9 != nullptr )
            break;
        }
        if ( ++v7 >= numFactories )
          goto LABEL_11;
      }
    }
    v10 = 0;
    vgui::enginetools = v9;
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
          v12 = (IPhysicsCollision *)v11(a1: "VPhysicsCollision007", a2: nullptr);
          if ( v12 != nullptr )
            break;
        }
        if ( ++v10 >= numFactories )
          goto LABEL_16;
      }
    }
    vgui::g_pPhysicsCollision = v12;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00630C90
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
// Address: 0x0063DA90
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
// Address: 0x0063DF90
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
// Address: 0x00650C90
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
// Address: 0x00650CC0
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
// Address: 0x0065E0C0
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
// Address: 0x006B2C00
// Name: vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Panel>(__formal: nullptr);
  s_pUnpack_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B2C10
// Name: _dynamic_initializer_for__vgui::Panel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Panel::s_pUnpackParams__()
{
  vgui::Panel::s_pUnpackParams = s_pUnpack_1;
  return s_pUnpack_1;
}

//------------------------------------------------------------------------------
// Address: 0x006B2CA0
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
// Address: 0x006B2D80
// Name: vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiLabel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Label>(__formal: nullptr);
  s_pUnpack_2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B2D90
// Name: _dynamic_initializer_for__vgui::Label::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Label::s_pUnpackParams__()
{
  vgui::Label::s_pUnpackParams = s_pUnpack_2;
  return s_pUnpack_2;
}

//------------------------------------------------------------------------------
// Address: 0x006B2DE0
// Name: vgui::_dynamic_initializer_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
int vgui::_dynamic_initializer_for__g_MenuMgr__()
{
  return atexit(func: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2E10
// Name: vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiButton_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::Button>(__formal: nullptr);
  s_pUnpack_3 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B2E20
// Name: _dynamic_initializer_for__vgui::Button::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::Button::s_pUnpackParams__()
{
  vgui::Button::s_pUnpackParams = s_pUnpack_3;
  return s_pUnpack_3;
}

//------------------------------------------------------------------------------
// Address: 0x006B31D0
// Name: _dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::BuildGroup::m_HandleTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__);
}

//------------------------------------------------------------------------------
// Address: 0x006B31F0
// Name: _dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui::ToolWindow::s_ToolWindows__()
{
  return atexit(func: dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5E50
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
// Address: 0x006B5F20
// Name: vgui::_dynamic_atexit_destructor_for__g_MenuMgr__
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::_dynamic_atexit_destructor_for__g_MenuMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_MenuMgr);
}

//------------------------------------------------------------------------------
// Address: 0x006B5F40
// Name: _dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::BuildGroup::m_HandleTable__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vgui::BuildGroup::m_HandleTable.m_unused);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vgui::BuildGroup::m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x006B5F70
// Name: _dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui::ToolWindow::s_ToolWindows__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vgui::ToolWindow::s_ToolWindows);
}

//------------------------------------------------------------------------------
// Address: 0x006B2C20
// Name: _dynamic_initializer_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_OverridenColorSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_OverridenColorSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2C40
// Name: _dynamic_initializer_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KBMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KBMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2C50
// Name: _dynamic_initializer_for__g_Panel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Panel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Panel_Helper, className: "Panel", func: Create_Panel);
}

//------------------------------------------------------------------------------
// Address: 0x006B2CF0
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
// Address: 0x006B2D10
// Name: _dynamic_initializer_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ScriptSymbols, growSize: 0, initSize: 128, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ScriptSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2D30
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
// Address: 0x006B2D50
// Name: _dynamic_initializer_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StartDirContexts__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StartDirContexts__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2D60
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
// Address: 0x006B2DA0
// Name: _dynamic_initializer_for__g_Label_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Label_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Label_Helper, className: "Label", func: Create_Label);
}

//------------------------------------------------------------------------------
// Address: 0x006B2DC0
// Name: _dynamic_initializer_for__g_Menu_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Menu_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Menu_Helper, className: "Menu", func: Create_Menu);
}

//------------------------------------------------------------------------------
// Address: 0x006B2DF0
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
// Address: 0x006B2E30
// Name: _dynamic_initializer_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ButtonSoundNames, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ButtonSoundNames__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2E50
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
// Address: 0x006B2E70
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
// Address: 0x006B2E90
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
// Address: 0x006B2EB0
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
// Address: 0x006B2ED0
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
// Address: 0x006B2EF0
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
// Address: 0x006B2F10
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
// Address: 0x006B2F30
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
// Address: 0x006B2F50
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
// Address: 0x006B2F70
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
// Address: 0x006B2F90
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
// Address: 0x006B2FB0
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
// Address: 0x006B2FD0
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
// Address: 0x006B2FF0
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
// Address: 0x006B3010
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
// Address: 0x006B3030
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
// Address: 0x006B3050
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
// Address: 0x006B3070
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
// Address: 0x006B3090
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
// Address: 0x006B30B0
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
// Address: 0x006B30D0
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
// Address: 0x006B30F0
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
// Address: 0x006B3110
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
// Address: 0x006B3130
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
// Address: 0x006B3150
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
// Address: 0x006B3170
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
// Address: 0x006B3190
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
// Address: 0x006B31B0
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
// Address: 0x006B31E0
// Name: _dynamic_initializer_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildModeDialogMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BuildModeDialogMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3200
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
// Address: 0x006B3230
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
// Address: 0x006B3260
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
// Address: 0x006B3290
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
// Address: 0x006B32D0
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
// Address: 0x006B3300
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
// Address: 0x006B3330
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5F30
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

//------------------------------------------------------------------------------
// Address: 0x006B5F60
// Name: _dynamic_atexit_destructor_for__g_BuildModeDialogMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildModeDialogMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_BuildModeDialogMgr);
}

//------------------------------------------------------------------------------
// Address: 0x006B5F80
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x006B5F90
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x006B5FA0
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x006B5FB0
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
// Address: 0x006B5FE0
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x006B5FF0
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x006B6000
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

} // namespace sceneviewer
