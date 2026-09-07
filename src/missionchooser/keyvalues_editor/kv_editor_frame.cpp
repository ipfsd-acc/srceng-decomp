// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/keyvalues_editor/kv_editor_frame.cpp
// Functions: 13
// ============================================================

#include "missionchooser\keyvalues_editor\kv_editor_frame.h"

//------------------------------------------------------------------------------
// Address: 0x1000DF00
// Name: public: static char const __near * CKV_Editor_Frame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Editor_Frame::GetPanelClassName()
{
  return "CKV_Editor_Frame";
}

//------------------------------------------------------------------------------
// Address: 0x1000DF10
// Name: protected: virtual void CKV_Editor_Frame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CKV_Editor_Frame::OnClose(CTile_Check_Frame *this)
{
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000DF20
// Name: public: virtual void CKV_Editor_Frame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Frame::PerformLayout(CKV_Editor_Frame *this)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  int Wide; // eax
  int v5; // eax
  int v6; // [esp-10h] [ebp-1Ch]
  int v7; // [esp-Ch] [ebp-18h]
  int v8; // [esp-4h] [ebp-10h]
  int screenTall; // [esp+4h] [ebp-8h] BYREF
  int screenWide; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_bFirstPerformLayout )
  {
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenWide, a3: &screenTall);
    v2 = (float)screenWide * 0.039999999;
    v3 = (float)screenWide * 0.15000001;
    v7 = screenTall - 2 * (int)v2;
    v6 = screenWide - 3 * (int)v3;
    this->m_bFirstPerformLayout = false;
    vgui::Panel::SetBounds(this, x: (int)v3, y: (int)v2, wide: v6, tall: v7);
  }
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pMenuBar, x: 20, y: 35, wide: Wide - 40, tall: 25);
  v8 = vgui::Panel::GetTall(this) - 85;
  v5 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pEditor, x: 20, y: 65, wide: v5 - 40, tall: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1000DFE0
// Name: public: void CKV_Editor_Frame::DoFileOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Frame::DoFileOpen(CKV_Editor_Frame *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi

  this->m_FileSelectType = KV_FST_LAYOUT_OPEN;
  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: nullptr,
           title: "Open....",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  vgui::FileOpenDialog::SetStartDirectory(this: v3, dir: this->m_pEditor->m_szFileDirectory);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: this->m_pEditor->m_szFileFilter,
    filterName: this->m_pEditor->m_szFileFilterName,
    bActive: true,
    pFilterInfo: nullptr);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000E070
// Name: public: void CKV_Editor_Frame::DoFileSaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Frame::DoFileSaveAs(CKV_Editor_Frame *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi

  this->m_FileSelectType = KV_FST_LAYOUT_SAVE_AS;
  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: nullptr,
           title: "Save Map Layout",
           bOpenOnly: false,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  vgui::FileOpenDialog::SetStartDirectory(this: v3, dir: this->m_pEditor->m_szFileDirectory);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: this->m_pEditor->m_szFileFilter,
    filterName: this->m_pEditor->m_szFileFilterName,
    bActive: true,
    pFilterInfo: nullptr);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000E100
// Name: public: void CKV_Editor_Frame::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Frame::OnFileSelected(CKV_Editor_Frame *this, const char *fullpath)
{
  KV_FileSelectType m_FileSelectType; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *m_pKeys; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IBaseFileSystem *v8; // eax
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // eax

  m_FileSelectType = this->m_FileSelectType;
  if ( m_FileSelectType == KV_FST_LAYOUT_SAVE_AS )
  {
    if ( this->m_pEditor->m_pKeys != nullptr )
    {
      V_snprintf(pDest: this->m_szLastFileName, maxLen: 260, pFormat: "%s", fullpath);
      if ( g_pFullFileSystem != nullptr )
        v4 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      KeyValues::SaveToFile(this: this->m_pEditor->m_pKeys, filesystem: v4, resourceName: fullpath, pathID: "GAME");
    }
  }
  else if ( m_FileSelectType == KV_FST_LAYOUT_OPEN )
  {
    m_pKeys = this->m_pEditor->m_pKeys;
    if ( m_pKeys != nullptr )
      KeyValues::deleteThis(this: m_pKeys);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "Keys");
    else
      v7 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v8 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v8 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v7,
           filesystem: v8,
           resourceName: fullpath,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      this->m_pEditor->SetKeys(this: this->m_pEditor, a2: v7);
    }
    else
    {
      v9 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v9 != nullptr )
      {
        v10 = vgui::MessageBox::MessageBox(this: v9, title: "Error", text: "Error loading KeyValues", parent: this);
        v10->DoModal_2(this: v10, a2: nullptr);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E240
// Name: public: virtual struct vgui::PanelMap_t __near * CKV_Editor_Frame::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall CKV_Editor_Frame::GetPanelMap(CKV_Editor_Frame *this)
{
  return &CKV_Editor_Frame::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000E250
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Editor_Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Editor_Frame::GetMessageMap(CKV_Editor_Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Editor_Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor_Frame::GetMessageMap'::`2'::s_pMap;
  `CKV_Editor_Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Frame");
  `CKV_Editor_Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E280
// Name: public: virtual struct PanelAnimationMap __near * CKV_Editor_Frame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Editor_Frame::GetAnimMap(CKV_Editor_Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Editor_Frame");
}

//------------------------------------------------------------------------------
// Address: 0x1000E290
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Editor_Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Editor_Frame::GetKBMap(CKV_Editor_Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Editor_Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor_Frame::GetKBMap'::`2'::s_pMap;
  `CKV_Editor_Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Frame");
  `CKV_Editor_Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E2C0
// Name: public: CKV_Editor_Frame::CKV_Editor_Frame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Editor_Frame *__thiscall CKV_Editor_Frame::CKV_Editor_Frame(
        CKV_Editor_Frame *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int v7; // eax
  CKV_Editor *v8; // eax
  CKV_Editor *v9; // eax
  vgui::MenuBar *v10; // eax
  vgui::MenuBar *v11; // eax
  vgui::MenuButton *v12; // eax
  vgui::MenuButton *v13; // edi
  vgui::Menu *v14; // eax
  vgui::Menu *v15; // eax
  char keys_dir[1024]; // [esp+8h] [ebp-400h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CKV_Editor_Frame_vtbl *)&CKV_Editor_Frame::`vftable';
  if ( `CKV_Editor_Frame::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Frame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Frame");
    v4->pfnClassName = CKV_Editor_Frame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `CKV_Editor_Frame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Frame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Editor_Frame");
    v5->pfnClassName = CKV_Editor_Frame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CKV_Editor_Frame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Frame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Frame");
    v6->pfnClassName = CKV_Editor_Frame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  v7 = g_pVGuiSchemeManager->LoadSchemeFromFile(this: g_pVGuiSchemeManager, a2: "tilegen_scheme.res", a3: nullptr);
  vgui::Panel::SetScheme(this, scheme: v7);
  v8 = (CKV_Editor *)operator new(nSize: 0x2ECu);
  if ( v8 != nullptr )
    v9 = CKV_Editor::CKV_Editor(this: v8, parent: this, name: "KVEditor");
  else
    v9 = nullptr;
  this->m_pEditor = v9;
  CKV_Editor::SetFileFilter(this: v9, szFilter: "*.txt", szFilterName: "KeyValues files (*.txt)");
  this->m_szLastFileName[0] = 0;
  vgui::Panel::SetSize(this, wide: 384, tall: 420);
  vgui::Panel::SetMinimumSize(this, wide: 384, tall: 420);
  v10 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v10 != nullptr )
    v11 = vgui::MenuBar::MenuBar(this: v10, parent: this, panelName: "KV_Editor_MenuBar");
  else
    v11 = nullptr;
  this->m_pMenuBar = v11;
  v12 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v12 != nullptr )
    v13 = vgui::MenuButton::MenuButton(this: v12, parent: this, panelName: "KV_Editor_FileMenuButton", text: "&File");
  else
    v13 = nullptr;
  v14 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v14 != nullptr )
    v15 = vgui::Menu::Menu(this: v14, parent: v13, panelName: "KV_Editor_FileMenu");
  else
    v15 = nullptr;
  this->m_pFileMenu = v15;
  v15->AddMenuItem(this: v15, a2: "&Open...", a3: "OpenKeys", a4: this, a5: nullptr);
  this->m_pFileMenu->AddMenuItem(this: this->m_pFileMenu, a2: "&Save", a3: "SaveKeys", a4: this, a5: nullptr);
  this->m_pFileMenu->AddMenuItem(this: this->m_pFileMenu, a2: "&Save As...", a3: "SaveKeysAs", a4: this, a5: nullptr);
  v13->SetMenu(this: v13, a2: this->m_pFileMenu);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: v13);
  v13->SetKeyBoardInputEnabled(this: v13, a2: false);
  this->m_pFileMenu->SetKeyBoardInputEnabled(this: this->m_pFileMenu, a2: false);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetMaximizeButtonVisible(this, state: false);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  this->m_bFirstPerformLayout = true;
  vgui::Frame::SetTitle(this, title: "KeyValues Editor", surfaceTitle: true);
  V_snprintf(pDest: keys_dir, maxLen: 1024, pFormat: "%s\\tilegen\\missions", g_gamedir);
  CKV_Editor::SetFileDirectory(this: this->m_pEditor, szDirName: keys_dir);
  this->m_pEditor->SetFileSpec_2(this: this->m_pEditor, a2: "tilegen/mission_editor_spec.txt", a3: "GAME");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E5D0
// Name: protected: virtual void CKV_Editor_Frame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Frame::OnCommand(CKV_Editor_Frame *this, const char *command)
{
  KeyValues *m_pKeys; // ecx

  if ( _V_stricmp(s1: command, s2: "OpenKeys") == 0 )
  {
    CKV_Editor_Frame::DoFileOpen(this);
    return;
  }
  if ( _V_stricmp(s1: command, s2: "SaveKeys") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "SaveKeysAs") != 0 )
      return;
    goto LABEL_10;
  }
  if ( _V_strlen(str: this->m_szLastFileName) <= 0 )
  {
LABEL_10:
    CKV_Editor_Frame::DoFileSaveAs(this);
    return;
  }
  m_pKeys = this->m_pEditor->m_pKeys;
  if ( m_pKeys != nullptr )
  {
    if ( g_pFullFileSystem != nullptr )
      KeyValues::SaveToFile(
        this: m_pKeys,
        filesystem: &g_pFullFileSystem->IBaseFileSystem,
        resourceName: this->m_szLastFileName,
        pathID: "GAME");
    else
      KeyValues::SaveToFile(this: m_pKeys, filesystem: nullptr, resourceName: this->m_szLastFileName, pathID: "GAME");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010050
// Name: public: virtual void CKV_Editor_Frame::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Frame::ApplySchemeSettings(CTile_Check_Frame *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00407D90
// Name: public: void CKV_Editor_Frame::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Frame::OnFileSelected(CKV_Editor_Frame *this, const char *fullpath)
{
  KV_FileSelectType m_FileSelectType; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *m_pKeys; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IBaseFileSystem *v8; // eax
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // eax

  m_FileSelectType = this->m_FileSelectType;
  if ( m_FileSelectType == KV_FST_LAYOUT_SAVE_AS )
  {
    if ( this->m_pEditor->m_pKeys != nullptr )
    {
      V_snprintf(pDest: this->m_szLastFileName, maxLen: 260, pFormat: "%s", fullpath);
      if ( g_pFullFileSystem != nullptr )
        v4 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      KeyValues::SaveToFile(this: this->m_pEditor->m_pKeys, filesystem: v4, resourceName: fullpath, pathID: "GAME");
    }
  }
  else if ( m_FileSelectType == KV_FST_LAYOUT_OPEN )
  {
    m_pKeys = this->m_pEditor->m_pKeys;
    if ( m_pKeys != nullptr )
      KeyValues::deleteThis(this: m_pKeys);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "Keys");
    else
      v7 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v8 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v8 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v7,
           filesystem: v8,
           resourceName: fullpath,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      this->m_pEditor->SetKeys(this: this->m_pEditor, a2: v7);
    }
    else
    {
      v9 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v9 != nullptr )
      {
        v10 = vgui::MessageBox::MessageBox(this: v9, title: "Error", text: "Error loading KeyValues", parent: this);
        v10->DoModal_2(this: v10, a2: nullptr);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004625B0
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x00463030
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463060
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x00463070
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vgui_editor
