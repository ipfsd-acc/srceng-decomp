// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmepresetgroupeditorpanel.cpp
// Functions: 114
// ============================================================

#include "vgui2\dme_controls\dmepresetgroupeditorpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00496180
// Name: public: static char const __near * CDmePresetGroupEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupEditorPanel::GetPanelClassName()
{
  return "CDmePresetGroupEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00496190
// Name: public: static char const __near * CDmePresetGroupEditorFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupEditorFrame::GetPanelClassName()
{
  return "CDmePresetGroupEditorFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004961A0
// Name: public: static char const __near * CDmePresetGroupListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupListPanel::GetPanelClassName()
{
  return "CDmePresetGroupListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004961B0
// Name: public: static char const __near * CDmePresetListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetListPanel::GetPanelClassName()
{
  return "CDmePresetListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004961C0
// Name: IndexSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl IndexSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  int Int; // esi

  Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
  return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004961F0
// Name: private: void CDmePresetGroupEditorPanel::SetSelectedPreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::SetSelectedPreset(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pPresetName)
{
  int i; // edi
  KeyValues *v5; // eax
  const char *String; // eax

  this->m_pPresetList->ClearSelectedItems(this: this->m_pPresetList);
  for ( i = this->m_pPresetList->FirstItem(this: this->m_pPresetList);
        i != this->m_pPresetList->InvalidItemID(this: this->m_pPresetList);
        i = ((int (__thiscall *)(CDmePresetListPanel *))this->m_pPresetList->NextItem)(a1: this->m_pPresetList) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(CDmePresetListPanel *, int, int))this->m_pPresetList->GetItem)(
                        a1: this->m_pPresetList,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: defaultValue);
    if ( _V_strcmp(s1: String, s2: pPresetName) == 0 )
      this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: i);
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004962A0
// Name: private: void CDmePresetGroupEditorPanel::SetSelectedPresetGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::SetSelectedPresetGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pPresetGroupName)
{
  int i; // edi
  KeyValues *v5; // eax
  const char *String; // eax

  this->m_pPresetGroupList->ClearSelectedItems(this: this->m_pPresetGroupList);
  for ( i = this->m_pPresetGroupList->FirstItem(this: this->m_pPresetGroupList);
        i != this->m_pPresetGroupList->InvalidItemID(this: this->m_pPresetGroupList);
        i = ((int (__thiscall *)(CDmePresetGroupListPanel *))this->m_pPresetGroupList->NextItem)(a1: this->m_pPresetGroupList) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(CDmePresetGroupListPanel *, int, int))this->m_pPresetGroupList->GetItem)(
                        a1: this->m_pPresetGroupList,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
    if ( _V_strcmp(s1: String, s2: pPresetGroupName) == 0 )
      this->m_pPresetGroupList->AddSelectedItem(this: this->m_pPresetGroupList, a2: i);
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496350
// Name: public: virtual void CDmePresetGroupEditorPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *,bool,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::SetupFileOpenDialog(
        CDmePresetGroupEditorPanel *this,
        vgui::FileOpenDialog *pDialog,
        bool bOpenFile,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  void (__thiscall *SetTitle_2)(vgui::Frame *, const char *, bool); // edx
  char pPresetPath[260]; // [esp+8h] [ebp-104h] BYREF

  SetTitle_2 = pDialog->SetTitle_2;
  if ( bOpenFile )
    ((void (__stdcall *)(const char *, int))SetTitle_2)(a1: "Import Preset File", a2: 1);
  else
    ((void (__stdcall *)(const char *, int))SetTitle_2)(a1: "Export Preset File", a2: 1);
  if ( _V_stricmp(s1: pFileFormat, s2: "preset") != 0 )
  {
    if ( _V_stricmp(s1: pFileFormat, s2: "vfe") != 0 )
    {
      if ( _V_stricmp(s1: pFileFormat, s2: "txt") == 0 )
      {
        GetModSubdirectory(pSubDir: "expressions", pBuf: pPresetPath, nBufLen: 260);
        vgui::FileOpenDialog::SetStartDirectoryContext(
          this: pDialog,
          pStartDirContext: "preset_exportvfe",
          pDefaultDir: pPresetPath);
        vgui::FileOpenDialog::AddFilter(
          this: pDialog,
          filter: "*.*",
          filterName: "All Files (*.*)",
          bActive: false,
          pFilterInfo: nullptr);
        vgui::FileOpenDialog::AddFilter(
          this: pDialog,
          filter: "*.txt",
          filterName: "Faceposer Expression File (*.txt)",
          bActive: true,
          pFilterInfo: "txt");
      }
    }
    else
    {
      GetModSubdirectory(pSubDir: "expressions", pBuf: pPresetPath, nBufLen: 260);
      vgui::FileOpenDialog::SetStartDirectoryContext(
        this: pDialog,
        pStartDirContext: "preset_exportvfe",
        pDefaultDir: pPresetPath);
      vgui::FileOpenDialog::AddFilter(
        this: pDialog,
        filter: "*.*",
        filterName: "All Files (*.*)",
        bActive: false,
        pFilterInfo: nullptr);
      vgui::FileOpenDialog::AddFilter(
        this: pDialog,
        filter: "*.vfe",
        filterName: "Expression File (*.vfe)",
        bActive: true,
        pFilterInfo: "vfe");
    }
  }
  else
  {
    GetModSubdirectory(pSubDir: "models", pBuf: pPresetPath, nBufLen: 260);
    vgui::FileOpenDialog::SetStartDirectoryContext(
      this: pDialog,
      pStartDirContext: "preset_importexport",
      pDefaultDir: pPresetPath);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.*",
      filterName: "All Files (*.*)",
      bActive: false,
      pFilterInfo: nullptr);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.pre",
      filterName: "Preset File (*.pre)",
      bActive: true,
      pFilterInfo: "preset");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004964E0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnAddGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnAddGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v2 != nullptr )
    v3 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Add Preset Group",
           prompt: "Enter name of new preset group",
           defaultValue: defaultValue);
  else
    v3 = nullptr;
  vgui::InputDialog::SetMultiline(this: v3, state: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "OnAddGroup");
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
  }
  else
  {
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496550
// Name: private: virtual void CDmePresetGroupEditorPanel::OnAddPhonemeGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnAddPhonemeGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v2 != nullptr )
    v3 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Add Phoneme Preset Group",
           prompt: "Enter name of new preset group",
           defaultValue: "phoneme");
  else
    v3 = nullptr;
  vgui::InputDialog::SetMultiline(this: v3, state: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "OnAddPhonemeGroup");
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
  }
  else
  {
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004965C0
// Name: public: virtual void CDmePresetGroupListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnKeyCodeTyped(CDmePresetGroupListPanel *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE || code == KEY_BACKSPACE )
  {
    this->m_pPresetGroupPanel->OnRemoveGroup(this: this->m_pPresetGroupPanel);
  }
  else
  {
    if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    {
      goto LABEL_9;
    }
    if ( code == KEY_UP )
    {
      this->m_pPresetGroupPanel->OnMoveGroupUp(this: this->m_pPresetGroupPanel);
      return;
    }
    if ( code == KEY_DOWN )
      this->m_pPresetGroupPanel->OnMoveGroupDown(this: this->m_pPresetGroupPanel);
    else
LABEL_9:
      vgui::ListPanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496660
// Name: public: virtual void CDmePresetGroupListPanel::OnDroppablePanelPaint(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnDroppablePanelPaint(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist,
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *dragPanels)
{
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  Color *DropFrameColor; // eax
  Color result; // [esp+Ch] [ebp-2Ch] BYREF
  int y2; // [esp+10h] [ebp-28h] BYREF
  int h2; // [esp+14h] [ebp-24h] BYREF
  int column; // [esp+18h] [ebp-20h] BYREF
  int w2; // [esp+1Ch] [ebp-1Ch] BYREF
  int x2; // [esp+20h] [ebp-18h] BYREF
  int row; // [esp+24h] [ebp-14h] BYREF
  int h; // [esp+28h] [ebp-10h] BYREF
  int w; // [esp+2Ch] [ebp-Ch] BYREF
  int y; // [esp+30h] [ebp-8h] BYREF
  int x; // [esp+34h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  this->GetCellBounds(this, a2: row, a3: 0, a4: &x, a5: &y, a6: &w, a7: &h);
  this->GetCellBounds(this, a2: row, a3: 3, a4: &x2, a5: &y2, a6: &w2, a7: &h2);
  w = w2 + x2 - x;
  vgui::Panel::LocalToScreen(this, &x, &y);
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  DropFrameColor = vgui::Panel::GetDropFrameColor(this, &result);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v5->DrawSetColor)(a1: v4, a2: *DropFrameColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + w, a5: y + 2);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + h - 2, a4: x + w, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + 2, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + w - 2, a3: y, a4: x + w, a5: y + h);
}

//------------------------------------------------------------------------------
// Address: 0x004967B0
// Name: public: virtual void CDmePresetListPanel::OnDroppablePanelPaint(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnDroppablePanelPaint(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist,
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *dragPanels)
{
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  Color *DropFrameColor; // eax
  Color result; // [esp+Ch] [ebp-1Ch] BYREF
  int row; // [esp+10h] [ebp-18h] BYREF
  int column; // [esp+14h] [ebp-14h] BYREF
  int h; // [esp+18h] [ebp-10h] BYREF
  int w; // [esp+1Ch] [ebp-Ch] BYREF
  int y; // [esp+20h] [ebp-8h] BYREF
  int x; // [esp+24h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  this->GetCellBounds(this, a2: row, a3: column, a4: &x, a5: &y, a6: &w, a7: &h);
  vgui::Panel::LocalToScreen(this, &x, &y);
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  DropFrameColor = vgui::Panel::GetDropFrameColor(this, &result);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v5->DrawSetColor)(a1: v4, a2: *DropFrameColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + w, a5: y + 2);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + h - 2, a4: x + w, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + 2, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + w - 2, a3: y, a4: x + w, a5: y + h);
}

//------------------------------------------------------------------------------
// Address: 0x004968D0
// Name: private: virtual void CDmePresetGroupEditorFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnCommand(CDmePresetGroupEditorFrame *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "Ok") != 0 )
    vgui::Frame::OnCommand(this, command: pCommand);
  else
    this->CloseModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x00496910
// Name: public: void CDmePresetGroupEditorPanel::NotifyDataChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::NotifyDataChanged(CDmePresetGroupEditorFrame *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "PresetsChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496A20
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupEditorFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupEditorFrame::GetMessageMap(CDmePresetGroupEditorFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupEditorFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
  `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00496A50
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupEditorFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupEditorFrame::GetAnimMap(CDmePresetGroupEditorFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00496A60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupEditorFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupEditorFrame::GetKBMap(CDmePresetGroupEditorFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupEditorFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorFrame::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupEditorFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
  `CDmePresetGroupEditorFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00496A90
// Name: public: char const __near * CDmePresetGroupEditorPanel::GetSelectedPresetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmePresetGroupEditorPanel::GetSelectedPresetName(CDmePresetGroupEditorPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) == nullptr
    || this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) != 1 )
  {
    return nullptr;
  }
  v3 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
  v4 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "presetName", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x00496B00
// Name: public: char const __near * CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(CDmePresetGroupEditorPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) == nullptr
    || this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) != 1 )
  {
    return nullptr;
  }
  v3 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
  v4 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "presetGroupName", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x00496B70
// Name: private: bool CDmePresetGroupEditorPanel::HasDuplicatePresetName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::HasDuplicatePresetName(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetName,
        const char *pIgnorePresetName)
{
  const char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v6; // eax
  vgui::MessageBox *v7; // eax
  vgui::MessageBox *v8; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName == nullptr )
    return 0;
  v6 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  if ( FindAnyPreset(pFilmClip: v6, pPresetGroupName: SelectedPresetGroupName, pPresetName) == nullptr
    || _V_strcmp(s1: pPresetName, s2: pIgnorePresetName) == 0 )
  {
    return 0;
  }
  v7 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v7 != nullptr )
    v8 = vgui::MessageBox::MessageBox(
           this: v7,
           title: "#DmePresetGroupEditor_DuplicatePresetNameTitle",
           text: "#DmePresetGroupEditor_DuplicatePresetNameText",
           parent: this);
  else
    v8 = nullptr;
  v8->DoModal_2(this: v8, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00496C10
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRenamePreset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRenamePreset(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( CDmePresetGroupEditorPanel::GetSelectedPresetName(this) != nullptr )
  {
    v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v2 != nullptr )
      v3 = vgui::InputDialog::InputDialog(
             this: v2,
             parent: this,
             title: "Rename Preset",
             prompt: "Enter new name of preset",
             defaultValue: defaultValue);
    else
      v3 = nullptr;
    vgui::InputDialog::SetMultiline(this: v3, state: false);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnRenamePreset");
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
    }
    else
    {
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496C90
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresets(CDmePresetGroupEditorPanel *this)
{
  CDmeAnimationSet *v2; // edi
  const char *SelectedPresetGroupName; // eax
  CDmePresetGroup *PresetGroup; // ebx
  CPresetPickerFrame *v5; // eax
  CPresetPickerFrame *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-8h] BYREF

  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v2, pGroupName: SelectedPresetGroupName);
  if ( PresetGroup != nullptr )
  {
    v5 = (CPresetPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v5 != nullptr )
      v6 = CPresetPickerFrame::CPresetPickerFrame(
             this: v5,
             pParent: this,
             pTitle: "Select Preset(s) to Export",
             bAllowMultiSelect: true);
    else
      v6 = nullptr;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "ExportPicked");
      CPresetPickerFrame::DoModal(this: v6, pPresetGroup: PresetGroup, bSelectAll: true, pContextKeyValues: v8);
    }
    else
    {
      CPresetPickerFrame::DoModal(this: v6, pPresetGroup: PresetGroup, bSelectAll: true, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496D50
// Name: private: virtual void CDmePresetGroupEditorPanel::OnImportPresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnImportPresets(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  vgui::FileOpenStateMachine *v4; // eax
  KeyValues *v5; // [esp-10h] [ebp-14h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ImportPresets");
  else
    v3 = nullptr;
  v5 = v3;
  v4 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::OpenFile(
    this: v4,
    pOpenFileType: "preset",
    pContextKeyValues: v5,
    pSaveFileName: nullptr,
    pSaveFileType: nullptr,
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00496DA0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroupToVFE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroupToVFE(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroupToVFE");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "vfe",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496E60
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroupToTXT(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroupToTXT(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroupToTXT");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "txt",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496F20
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroups(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroup");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "preset",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496FE0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnImportPresetGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnImportPresetGroups(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  vgui::FileOpenStateMachine *v4; // eax
  KeyValues *v5; // [esp-10h] [ebp-14h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ImportPresetGroup");
  else
    v3 = nullptr;
  v5 = v3;
  v4 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::OpenFile(
    this: v4,
    pOpenFileType: "preset",
    pContextKeyValues: v5,
    pSaveFileName: nullptr,
    pSaveFileType: nullptr,
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00497030
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRenameGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRenameGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this) != nullptr )
  {
    v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v2 != nullptr )
      v3 = vgui::InputDialog::InputDialog(
             this: v2,
             parent: this,
             title: "Rename Preset Group",
             prompt: "Enter new name of preset group",
             defaultValue: defaultValue);
    else
      v3 = nullptr;
    vgui::InputDialog::SetMultiline(this: v3, state: false);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnRenameGroup");
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
    }
    else
    {
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004970B0
// Name: public: CDmePresetGroupListPanel::CDmePresetGroupListPanel(class vgui::Panel __near *,char const __near *,class CDmePresetGroupEditorPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupListPanel *__thiscall CDmePresetGroupListPanel::CDmePresetGroupListPanel(
        CDmePresetGroupListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmePresetGroupEditorPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmePresetGroupListPanel_vtbl *)&CDmePresetGroupListPanel::`vftable';
  if ( `CDmePresetGroupListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupListPanel");
    v5->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetGroupListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupListPanel");
    v6->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetGroupListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupListPanel");
    v7->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  this->m_pPresetGroupPanel = pComboPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00497190
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupListPanel::GetMessageMap(CDmePresetGroupListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupListPanel");
  `CDmePresetGroupListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004971C0
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupListPanel::GetAnimMap(CDmePresetGroupListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004971D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupListPanel::GetKBMap(CDmePresetGroupListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupListPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupListPanel");
  `CDmePresetGroupListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497200
// Name: public: virtual void CDmePresetGroupListPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnCreateDragData(CDmePresetGroupListPanel *this, KeyValues *msg)
{
  const char *SelectedPresetGroupName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    KeyValues::SetString(this: msg, keyName: "presetGroupName", value: SelectedPresetGroupName);
    KeyValues::SetInt(this: msg, keyName: "selfDroppable", value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497240
// Name: public: CDmePresetListPanel::CDmePresetListPanel(class vgui::Panel __near *,char const __near *,class CDmePresetGroupEditorPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetListPanel *__thiscall CDmePresetListPanel::CDmePresetListPanel(
        CDmePresetListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmePresetGroupEditorPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmePresetListPanel_vtbl *)&CDmePresetListPanel::`vftable';
  if ( `CDmePresetListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetListPanel");
    v5->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePresetListPanel");
    v6->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetListPanel");
    v7->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  this->m_pPresetGroupPanel = pComboPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00497320
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetListPanel::GetMessageMap(CDmePresetListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetListPanel");
  `CDmePresetListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497350
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetListPanel::GetAnimMap(CDmePresetListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00497360
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetListPanel::GetKBMap(CDmePresetListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetListPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetListPanel");
  `CDmePresetListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004973E0
// Name: private: virtual void CDmePresetGroupEditorFrame::OnUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnUndo(CDmePresetGroupEditorFrame *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-8h] BYREF

  if ( g_pDataModel->CanUndo(this: g_pDataModel) )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    *(_WORD *)&guard.m_bOldValue = ((unsigned __int8 (__thiscall *)(IDataModel *, _DWORD))IsUndoEnabled)(
                                     a1: g_pDataModel,
                                     a2: 0);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDataModel->Undo(this: g_pDataModel);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497450
// Name: private: virtual void CDmePresetGroupEditorFrame::OnRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnRedo(CDmePresetGroupEditorFrame *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-8h] BYREF

  if ( g_pDataModel->CanRedo(this: g_pDataModel) )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    *(_WORD *)&guard.m_bOldValue = ((unsigned __int8 (__thiscall *)(IDataModel *, _DWORD))IsUndoEnabled)(
                                     a1: g_pDataModel,
                                     a2: 0);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDataModel->Redo(this: g_pDataModel);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497520
// Name: public: virtual CDmePresetGroupEditorPanel::~CDmePresetGroupEditorPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::~CDmePresetGroupEditorPanel(CDmePresetGroupEditorPanel *this)
{
  vgui::Panel *v2; // eax

  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorPanel_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v2->MarkForDeletion(this: v2);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hFilmClip, hElement: this->m_hFilmClip.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00497590
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupEditorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupEditorPanel::GetMessageMap(CDmePresetGroupEditorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupEditorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
  `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004975C0
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupEditorPanel::GetAnimMap(CDmePresetGroupEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004975D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupEditorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupEditorPanel::GetKBMap(CDmePresetGroupEditorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupEditorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupEditorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorPanel");
  `CDmePresetGroupEditorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497600
// Name: private: void CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        CDmePresetGroupEditorPanel *a3@<esi>)
{
  const char *SelectedPresetGroupName; // ebx
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax
  CDmeFilmClip *v7; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // ebx
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  vgui::Panel *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // ebx
  vgui::Panel *v21; // eax
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // ebx
  vgui::Panel *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // ebx
  vgui::Panel *v28; // eax
  vgui::Menu *v29; // eax
  CDmePresetGroupEditorPanel *v30; // [esp-8h] [ebp-Ch]

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    if ( SelectedPresetGroupName != nullptr )
    {
      v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      v6 = v5 != nullptr ? vgui::Menu::Menu(this: v5, parent: this, panelName: "ActionMenu") : nullptr;
      v30 = a3;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v6);
      v7 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
      AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v7, pPresetGroupName: SelectedPresetGroupName);
      if ( AnyPresetGroup != nullptr )
      {
        if ( !AnyPresetGroup->m_bIsReadOnly.m_Storage )
        {
          if ( CDmePresetGroupEditorPanel::GetSelectedPresetName(this) != nullptr )
          {
            v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v9 != nullptr )
              v10 = KeyValues::KeyValues(this: v9, setName: "RenamePreset");
            else
              v10 = nullptr;
            v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, CDmePresetGroupEditorPanel *, int))v11->__vftable[1].PaintTraverse)(
              a1: v11,
              a2: "#DmePresetGroupEditor_RenamePreset",
              a3: v10,
              a4: this,
              a5: 0,
              a6: a3,
              a7: a2);
            v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v12 != nullptr )
              v13 = KeyValues::KeyValues(this: v12, setName: "RemovePreset");
            else
              v13 = nullptr;
            v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v14->__vftable[1].PaintTraverse)(
              a1: v14,
              a2: "#DmePresetGroupEditor_RemovePreset",
              a3: v13,
              a4: this,
              a5: 0);
            v15 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            v15->__vftable[1].DeletePanel(this: v15);
            v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v16 != nullptr )
              v17 = KeyValues::KeyValues(this: v16, setName: "MovePresetUp");
            else
              v17 = nullptr;
            v18 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v18->__vftable[1].PaintTraverse)(
              a1: v18,
              a2: "#DmePresetGroupEditor_MoveUp",
              a3: v17,
              a4: this,
              a5: 0);
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "MovePresetDown");
            else
              v20 = nullptr;
            v21 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            a2 = 0;
            v30 = this;
            v21->__vftable[1].PaintTraverse(this: v21, a2: (bool)"#DmePresetGroupEditor_MoveDown", a3: (bool)v20);
          }
          v22 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, CDmePresetGroupEditorPanel *, int))v22->__vftable[1].DeletePanel)(
            a1: v22,
            a2: v30,
            a3: a2);
          v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v23 != nullptr )
            v24 = KeyValues::KeyValues(this: v23, setName: "ImportPresets");
          else
            v24 = nullptr;
          v25 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          v25->__vftable[1].PaintTraverse(this: v25, a2: (bool)"#DmePresetGroupEditor_ImportPresets", a3: (bool)v24);
        }
        v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v26 != nullptr )
          v27 = KeyValues::KeyValues(this: v26, setName: "ExportPresets");
        else
          v27 = nullptr;
        v28 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v28->__vftable[1].PaintTraverse)(
          a1: v28,
          a2: "#DmePresetGroupEditor_ExportPresets",
          a3: v27,
          a4: this,
          a5: 0);
        v29 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::PlaceContextMenu(parent: this, menu: v29);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497870
// Name: private: virtual void CDmePresetGroupEditorPanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::OnOpenContextMenu(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        CDmePresetGroupEditorPanel *a3@<esi>,
        KeyValues *kv)
{
  vgui::Panel *v5; // eax
  CDmePresetListPanel *Ptr; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // ebx
  vgui::Panel *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // ebx
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  vgui::Panel *v20; // eax
  vgui::Panel *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // ebx
  vgui::Panel *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // ebx
  vgui::Panel *v31; // eax
  KeyValues *v32; // eax
  KeyValues *v33; // ebx
  vgui::Panel *v34; // eax
  CDmeFilmClip *v35; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  vgui::Panel *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // ebx
  vgui::Panel *v40; // eax
  vgui::Panel *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // ebx
  vgui::Panel *v44; // eax
  KeyValues *v45; // eax
  KeyValues *v46; // ebx
  vgui::Panel *v47; // eax
  KeyValues *v48; // eax
  KeyValues *v49; // ebx
  vgui::Panel *v50; // eax
  KeyValues *v51; // eax
  KeyValues *v52; // ebx
  vgui::Panel *v53; // eax
  vgui::Menu *v54; // eax
  const char *pPresetGroupName; // [esp+10h] [ebp+8h]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v5->MarkForDeletion(this: v5);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    Ptr = (CDmePresetListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
    if ( Ptr == this->m_pPresetList )
    {
      CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(this, a2, a3);
      return;
    }
    if ( Ptr == (CDmePresetListPanel *)this->m_pPresetGroupList )
    {
      v7 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      if ( v7 != nullptr )
        v8 = vgui::Menu::Menu(this: v7, parent: this, panelName: "ActionMenu");
      else
        v8 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v8);
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "AddGroup");
      else
        v10 = nullptr;
      v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, int))v11->__vftable[1].PaintTraverse)(
        a1: v11,
        a2: "#DmePresetGroupEditor_AddGroup",
        a3: v10,
        a4: this,
        a5: 0,
        a6: a2);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "AddPhonemeGroup");
      else
        v13 = nullptr;
      v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v14->__vftable[1].PaintTraverse)(
        a1: v14,
        a2: "#DmePresetGroupEditor_AddPhonemeGroup",
        a3: v13,
        a4: this);
      pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
      if ( pPresetGroupName != nullptr )
      {
        v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v15 != nullptr )
          v16 = KeyValues::KeyValues(this: v15, setName: "RenameGroup");
        else
          v16 = nullptr;
        v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, _DWORD))v17->__vftable[1].PaintTraverse)(
          a1: v17,
          a2: "#DmePresetGroupEditor_RenameGroup",
          a3: v16,
          a4: this,
          a5: 0,
          a6: 0);
        v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v18 != nullptr )
          v19 = KeyValues::KeyValues(this: v18, setName: "RemoveGroup");
        else
          v19 = nullptr;
        v20 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v20->__vftable[1].PaintTraverse)(
          a1: v20,
          a2: "#DmePresetGroupEditor_RemoveGroup",
          a3: v19,
          a4: this,
          a5: 0);
        v21 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v21->__vftable[1].DeletePanel(this: v21);
        v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v22 != nullptr )
          v23 = KeyValues::KeyValues(this: v22, setName: "ToggleGroupVisibility");
        else
          v23 = nullptr;
        v24 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v24->__vftable[1].PaintTraverse)(
          a1: v24,
          a2: "#DmePresetGroupEditor_ToggleVisibility",
          a3: v23,
          a4: this,
          a5: 0);
        v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v25 != nullptr )
          v26 = KeyValues::KeyValues(this: v25, setName: "ToggleGroupSharing");
        else
          v26 = nullptr;
        v27 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v27->__vftable[1].PaintTraverse)(
          a1: v27,
          a2: "#DmePresetGroupEditor_ToggleSharing",
          a3: v26,
          a4: this,
          a5: 0);
        v28 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v28->__vftable[1].DeletePanel(this: v28);
        v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v29 != nullptr )
          v30 = KeyValues::KeyValues(this: v29, setName: "MoveGroupUp");
        else
          v30 = nullptr;
        v31 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v31->__vftable[1].PaintTraverse)(
          a1: v31,
          a2: "#DmePresetGroupEditor_MoveUp",
          a3: v30,
          a4: this,
          a5: 0);
        v32 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v32 != nullptr )
          v33 = KeyValues::KeyValues(this: v32, setName: "MoveGroupDown");
        else
          v33 = nullptr;
        v34 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v34->__vftable[1].PaintTraverse)(
          a1: v34,
          a2: "#DmePresetGroupEditor_MoveDown",
          a3: v33,
          a4: this);
        v35 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
        AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v35, pPresetGroupName);
        if ( AnyPresetGroup == nullptr )
          return;
        if ( !AnyPresetGroup->m_bIsReadOnly.m_Storage )
        {
          v37 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, _DWORD))v37->__vftable[1].DeletePanel)(a1: v37, a2: 0);
          v38 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v38 != nullptr )
            v39 = KeyValues::KeyValues(this: v38, setName: "RemoveDefaultControls");
          else
            v39 = nullptr;
          v40 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v40->__vftable[1].PaintTraverse)(
            a1: v40,
            a2: "#DmePresetGroupEditor_RemoveDefaultControls",
            a3: v39,
            a4: this);
        }
      }
      v41 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v41->__vftable[1].DeletePanel)(a1: v41, a2: 0);
      v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v42 != nullptr )
        v43 = KeyValues::KeyValues(this: v42, setName: "ImportPresetGroups");
      else
        v43 = nullptr;
      v44 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v44->__vftable[1].PaintTraverse)(
        a1: v44,
        a2: "#DmePresetGroupEditor_ImportPresets",
        a3: v43,
        a4: this);
      if ( pPresetGroupName != nullptr )
      {
        v45 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v45 != nullptr )
          v46 = KeyValues::KeyValues(this: v45, setName: "ExportPresetGroups");
        else
          v46 = nullptr;
        v47 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, _DWORD))v47->__vftable[1].PaintTraverse)(
          a1: v47,
          a2: "#DmePresetGroupEditor_ExportPresets",
          a3: v46,
          a4: this,
          a5: 0,
          a6: 0);
        v48 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v48 != nullptr )
          v49 = KeyValues::KeyValues(this: v48, setName: "ExportPresetGroupsToTXT");
        else
          v49 = nullptr;
        v50 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v50->__vftable[1].PaintTraverse)(
          a1: v50,
          a2: "#DmePresetGroupEditor_ExportPresetsToFaceposer",
          a3: v49,
          a4: this,
          a5: 0);
        v51 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v51 != nullptr )
          v52 = KeyValues::KeyValues(this: v51, setName: "ExportPresetGroupsToVFE");
        else
          v52 = nullptr;
        v53 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v53->__vftable[1].PaintTraverse)(
          a1: v53,
          a2: "#DmePresetGroupEditor_ExportPresetsToExpression",
          a3: v52,
          a4: this);
      }
      v54 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
      vgui::Menu::PlaceContextMenu(parent: this, menu: v54);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497D30
// Name: private: bool CDmePresetGroupEditorPanel::HasDuplicateGroupName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::HasDuplicateGroupName(
        CDmePresetGroupEditorPanel *this,
        const char *pGroupName,
        const char *pIgnorePresetGroupName)
{
  CDmeFilmClip *v5; // eax
  vgui::MessageBox *v6; // eax
  vgui::MessageBox *v7; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) == nullptr )
    return 0;
  v5 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  if ( FindAnyPresetGroup(pFilmClip: v5, pPresetGroupName: pGroupName) == nullptr
    || _V_strcmp(s1: pGroupName, s2: pIgnorePresetGroupName) == 0 )
  {
    return 0;
  }
  v6 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v6 != nullptr )
    v7 = vgui::MessageBox::MessageBox(
           this: v6,
           title: "#DmePresetGroupEditor_DuplicateNameTitle",
           text: "#DmePresetGroupEditor_DuplicateNameText",
           parent: this);
  else
    v7 = nullptr;
  v7->DoModal_2(this: v7, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00497DE0
// Name: public: virtual bool CDmePresetGroupListPanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePresetGroupListPanel::IsDroppable(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  bool result; // al
  KeyValues *v5; // eax
  const char *v6; // edi
  CDmeFilmClip *v7; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  int column; // [esp+8h] [ebp-Ch] BYREF
  int row; // [esp+Ch] [ebp-8h] BYREF
  int x; // [esp+10h] [ebp-4h] BYREF

  result = false;
  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( this->m_pPresetGroupPanel != nullptr )
    {
      if ( KeyValues::GetString(this: v3, keyName: "presetGroupName", defaultValue: defaultValue) != nullptr )
        return true;
      if ( KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: defaultValue) != nullptr )
      {
        g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
        this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
        v5 = this->GetItem(this, a2: row);
        v6 = v5 != nullptr
           ? KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue)
           : nullptr;
        v7 = (CDmeFilmClip *)g_pDataModel->GetElement(
                               this: g_pDataModel,
                               a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
        AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v7, pPresetGroupName: v6);
        if ( AnyPresetGroup != nullptr && !AnyPresetGroup->m_bIsReadOnly.m_Storage )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497EE0
// Name: public: virtual void CDmePresetListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnKeyCodeTyped(CDmePresetListPanel *this, ButtonCode_t code)
{
  const char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v4; // eax
  CDmePresetGroup *AnyPresetGroup; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    v4 = (CDmeFilmClip *)g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
    AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v4, pPresetGroupName: SelectedPresetGroupName);
    if ( AnyPresetGroup != nullptr && !AnyPresetGroup->m_bIsReadOnly.m_Storage )
    {
      if ( code == KEY_DELETE || code == KEY_BACKSPACE )
      {
        this->m_pPresetGroupPanel->OnRemovePreset(this: this->m_pPresetGroupPanel);
        return;
      }
      if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
        || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
      {
        if ( code == KEY_UP )
        {
          this->m_pPresetGroupPanel->OnMovePresetUp(this: this->m_pPresetGroupPanel);
          return;
        }
        if ( code == KEY_DOWN )
        {
          this->m_pPresetGroupPanel->OnMovePresetDown(this: this->m_pPresetGroupPanel);
          return;
        }
      }
    }
    vgui::ListPanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497FC0
// Name: public: virtual void CDmePresetListPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnCreateDragData(CDmePresetListPanel *this, KeyValues *msg)
{
  const char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v4; // eax
  const char *SelectedPresetName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    v4 = (CDmeFilmClip *)g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
    if ( !FindAnyPresetGroup(pFilmClip: v4, pPresetGroupName: SelectedPresetGroupName)->m_bIsReadOnly.m_Storage )
    {
      SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this: this->m_pPresetGroupPanel);
      if ( SelectedPresetName != nullptr )
      {
        KeyValues::SetString(this: msg, keyName: "presetName", value: SelectedPresetName);
        KeyValues::SetString(this: msg, keyName: "presetGroupName", value: SelectedPresetGroupName);
        KeyValues::SetInt(this: msg, keyName: "selfDroppable", value: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498050
// Name: public: virtual bool CDmePresetListPanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePresetListPanel::IsDroppable(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // esi
  bool result; // al

  result = false;
  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this
      && this->m_pPresetGroupPanel != nullptr
      && KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: nullptr) != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004980E0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnFileStateMachineFinished(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnFileStateMachineFinished(
        CDmePresetGroupEditorPanel *this,
        KeyValues *pParams)
{
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CPresetPickerFrame *v8; // eax
  CPresetPickerFrame *v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int BufferType; // eax
  CDisableUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF

  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pParams);
  Name = KeyValues::GetName(this: FirstTrueSubKey);
  if ( _V_stricmp(s1: Name, s2: "ImportPresets") == 0 )
  {
    Int = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "presets", defaultValue: -1);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v7 = v6;
    if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
    {
      if ( KeyValues::GetInt(this: pParams, keyName: "completionState", defaultValue: 0) != 0 )
      {
        v8 = (CPresetPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
        if ( v8 != nullptr )
          v9 = CPresetPickerFrame::CPresetPickerFrame(
                 this: v8,
                 pParent: this,
                 pTitle: "Select Preset(s) to Import",
                 bAllowMultiSelect: true);
        else
          v9 = nullptr;
        v9->AddActionSignalTarget_2(this: v9, a2: this);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "ImportPicked");
        else
          v11 = nullptr;
        BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
        KeyValues::SetInt(this: v11, keyName: "presets", value: BufferType);
        CPresetPickerFrame::DoModal(this: v9, pPresetGroup: v7, bSelectAll: true, pContextKeyValues: v11);
      }
      else
      {
        CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &sg);
        g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v7->m_fileId);
        CChangeUndoScopeGuard::Release(this: &sg);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498210
// Name: public: virtual bool CDmePresetGroupEditorPanel::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::OnWriteFileToDisk(
        CDmePresetGroupEditorPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  const char *String; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v6; // eax
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // ebx
  const char *Name; // eax
  IDataModel_vtbl *v11; // esi
  int v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  DmElementHandle_t v15; // edi
  const char *SelectedPresetGroupName; // esi
  CDmeTransformControl *v17; // ebx
  CDmaElementArray<CDmePreset> *Position; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmeAnimationSet *v20; // eax
  CDmePresetGroup *v21; // eax
  int v22; // esi
  CDmePresetGroup *i; // edi
  const char *v24; // eax
  CExpressionCalculator *Preset; // eax
  IDataModel_vtbl *v26; // esi
  int v27; // eax
  IDataModel_vtbl *v28; // esi
  int BufferType; // eax
  char pBuf[32]; // [esp+Ch] [ebp-3Ch] BYREF
  CDisableUndoScopeGuard sg; // [esp+2Ch] [ebp-1Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+34h] [ebp-14h] BYREF
  CDmaElementArray<CDmePreset> *presets; // [esp+3Ch] [ebp-Ch]
  DmElementHandle_t src; // [esp+40h] [ebp-8h] BYREF
  int nCount; // [esp+44h] [ebp-4h]
  char bOk_3; // [esp+53h] [ebp+Bh]

  src = (DmElementHandle_t)this;
  String = KeyValues::GetString(this: pContextKeyValues, keyName: "presetGroupName", defaultValue: defaultValue);
  Int = KeyValues::GetInt(this: pContextKeyValues, keyName: "animSet", defaultValue: -1);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v7 = (CDmeAnimationSet *)v6;
  if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeAnimationSet::m_classType) )
  {
    v7 = nullptr;
LABEL_4:
    PresetGroup = nullptr;
    goto LABEL_5;
  }
  if ( String == nullptr )
    goto LABEL_4;
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: String);
LABEL_5:
  Name = KeyValues::GetName(this: pContextKeyValues);
  if ( _V_stricmp(s1: Name, s2: "ExportPresetGroup") != 0 )
  {
    v13 = KeyValues::GetName(this: pContextKeyValues);
    if ( _V_stricmp(s1: v13, s2: "ExportPresetGroupToVFE") != 0 )
    {
      v14 = KeyValues::GetName(this: pContextKeyValues);
      if ( _V_stricmp(s1: v14, s2: "ExportPresetGroupToTXT") != 0 )
      {
        nCount = KeyValues::GetInt(this: pContextKeyValues, keyName: "count", defaultValue: 0);
        if ( nCount != 0 )
        {
          v15 = src;
          SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: (CDmePresetGroupEditorPanel *)(src - 380));
          if ( SelectedPresetGroupName == nullptr )
            SelectedPresetGroupName = "root";
          CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &sg);
          v17 = (CDmeTransformControl *)CreateElement<CDmePresetGroup>(
                                          pObjectName: SelectedPresetGroupName,
                                          fileid: DMFILEID_INVALID,
                                          pObjectID: nullptr);
          Position = (CDmaElementArray<CDmePreset> *)CDmeTransformControl::GetPosition(this: v17);
          GetElement = g_pDataModel->GetElement;
          presets = Position;
          traversal.m_pFilmClip = (CDmeFilmClip *)GetElement(this: g_pDataModel, a2: *(DmElementHandle_t *)(v15 + 36));
          traversal.m_nIndex = 0;
          v20 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          v21 = CDmeAnimationSet::FindPresetGroup(this: v20, pGroupName: SelectedPresetGroupName);
          v22 = 0;
          for ( i = v21; v22 < nCount; ++v22 )
          {
            V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", v22);
            v24 = KeyValues::GetString(this: pContextKeyValues, keyName: pBuf, defaultValue: defaultValue);
            Preset = (CExpressionCalculator *)CDmePresetGroup::FindPreset(this: i, pPresetName: v24);
            if ( Preset != nullptr )
            {
              src = CCodecBuffer_Block::GetBufferType(this: Preset);
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                this: presets,
                &src);
            }
          }
          v26 = g_pDataModel->__vftable;
          v27 = ((int (__thiscall *)(IDataModel *, const char *, const char *, CDmeTransformControl *))g_pDataModel->GetDefaultEncoding)(
                  a1: g_pDataModel,
                  a2: pFileFormat,
                  a3: pFileFormat,
                  a4: v17);
          bOk_3 = ((int (__thiscall *)(IDataModel *, const char *, _DWORD, int))v26->SaveToFile)(
                    a1: g_pDataModel,
                    a2: pFileName,
                    a3: 0,
                    a4: v27);
          v28 = g_pDataModel->__vftable;
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
          v28->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
          CChangeUndoScopeGuard::Release(this: &sg);
          return bOk_3;
        }
        else
        {
          return 1;
        }
      }
      else
      {
        if ( PresetGroup == nullptr )
          return 0;
        return CDmePresetGroup::ExportToTXT(this: PresetGroup, pFileName, pAnimationSet: v7, pComboOp: nullptr);
      }
    }
    else
    {
      if ( PresetGroup == nullptr )
        return 0;
      return CDmePresetGroup::ExportToVFE(this: PresetGroup, pFileName, pAnimationSet: v7, pComboOp: nullptr);
    }
  }
  else
  {
    if ( PresetGroup == nullptr )
      return 0;
    v11 = g_pDataModel->__vftable;
    v12 = ((int (__thiscall *)(IDataModel *, const char *, const char *, CDmePresetGroup *))g_pDataModel->GetDefaultEncoding)(
            a1: g_pDataModel,
            a2: pFileFormat,
            a3: pFileFormat,
            a4: PresetGroup);
    return ((bool (__thiscall *)(IDataModel *, const char *, _DWORD, int))v11->SaveToFile)(
             a1: g_pDataModel,
             a2: pFileName,
             a3: 0,
             a4: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498480
// Name: private: virtual void CDmePresetGroupEditorPanel::OnPresetPickCancelled(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnPresetPickCancelled(CDmePresetGroupEditorPanel *this, KeyValues *pParams)
{
  KeyValues *Key; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDisableUndoScopeGuard sg; // [esp+4h] [ebp-8h] BYREF

  Key = KeyValues::FindKey(this: pParams, keyName: "ImportPicked", bCreate: false);
  if ( Key != nullptr )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    sg.m_bNotify = false;
    sg.m_pNotify = nullptr;
    *(_WORD *)&sg.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    Int = KeyValues::GetInt(this: Key, keyName: "presets", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      v6 = nullptr;
    g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v6->m_fileId);
    CChangeUndoScopeGuard::Release(this: &sg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498540
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRemoveDefaultControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemoveDefaultControls(CDmePresetGroupEditorPanel *this)
{
  CDmeTransformControl *PresetGroup; // eax
  const Vector *Position; // esi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  CDmElement *v7; // eax
  CDmeTransform *v8; // esi
  const Vector *v9; // esi
  float v10; // eax
  DmElementArray_t *v11; // eax
  int v12; // ecx
  int v13; // edi
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // ebx
  const char *m_pAsString; // eax
  CDmElement *Control; // eax
  CDmElement *v19; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v21; // edi
  CDmaVar<float> *m_pData; // edi
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // edi
  CDmaVar<float> *v25; // edi
  CDmAttribute *v26; // eax
  CDmAttribute *v27; // esi
  CDmaVar<float> *v28; // esi
  CDmAttribute *v29; // eax
  CDmAttribute *v30; // esi
  CDmaVar<float> *v31; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-34h] BYREF
  CDmrElementArray<CDmePreset> presets; // [esp+14h] [ebp-2Ch] BYREF
  CDmrElementArray<CDmElement> controls; // [esp+1Ch] [ebp-24h] BYREF
  const char *pPresetGroupName; // [esp+24h] [ebp-1Ch]
  int v36; // [esp+28h] [ebp-18h]
  CDmeAnimationSet *pAnimSet; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  float flDefaultValue; // [esp+34h] [ebp-Ch]
  int j; // [esp+38h] [ebp-8h]
  bool bIsDefault; // [esp+3Fh] [ebp-1h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Remove Default Controls", a3: "Remove Default Controls", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Remove Default Controls", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( pAnimSet != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = (CDmeTransformControl *)CDmeAnimationSet::FindPresetGroup(
                                                this: pAnimSet,
                                                pGroupName: pPresetGroupName);
        if ( PresetGroup != nullptr )
        {
          Position = CDmeTransformControl::GetPosition(this: PresetGroup);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
          x = Position[2].x;
          if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
          {
            m_pStorage = nullptr;
            presets.m_pAttribute = nullptr;
            presets.m_pStorage = nullptr;
            m_Size = 0;
          }
          else
          {
            presets.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
            m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
            presets.m_pStorage = m_pStorage;
            m_Size = m_pStorage->m_Size;
          }
          v36 = m_Size;
          i = 0;
          if ( m_Size > 0 )
            break;
        }
LABEL_71:
        pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( pAnimSet == nullptr )
          goto LABEL_72;
      }
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[i]);
        v8 = (CDmeTransform *)v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmePreset::m_classType) )
          v8 = nullptr;
        if ( !CDmePreset::IsAnimated(this: (CDmePreset *)v8) )
        {
          v9 = CDmeTransform::GetPosition(this: v8);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
          v10 = v9[2].x;
          if ( v10 == 0.0 || (*(_BYTE *)(LODWORD(v10) + 16) & 0x1F) != 0xF )
          {
            v11 = nullptr;
            controls.m_pAttribute = nullptr;
            controls.m_pStorage = nullptr;
            v12 = 0;
          }
          else
          {
            controls.m_pAttribute = (CDmAttribute *)LODWORD(v9[2].x);
            v11 = *(DmElementArray_t **)(LODWORD(v10) + 4);
            controls.m_pStorage = v11;
            v12 = v11->m_Size;
          }
          j = v12 - 1;
          if ( v12 - 1 >= 0 )
            break;
        }
LABEL_70:
        if ( ++i >= v36 )
          goto LABEL_71;
        m_pStorage = presets.m_pStorage;
      }
      while ( 1 )
      {
        v13 = j;
        v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v11->m_Memory.m_pMemory[j]);
        v15 = v14;
        if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmElement::m_classType) )
          v16 = v15;
        else
          v16 = nullptr;
        m_pAsString = v16->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        Control = CDmeAnimationSet::FindControl(this: pAnimSet, pControlName: m_pAsString);
        v19 = Control;
        if ( Control == nullptr )
        {
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
            this: &controls,
            elem: v13);
          goto LABEL_69;
        }
        bIsDefault = true;
        if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        Attribute = CDmElement::FindAttribute(this: Control, pAttributeName: "defaultValue");
        v21 = Attribute;
        if ( Attribute != nullptr )
        {
          if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          if ( (Attribute->m_nFlags & 0x1F) == 3 )
          {
            m_pData = (CDmaVar<float> *)Attribute->m_pData;
          }
          else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
          {
            CDmAttribute::CopyDataOut<float>(this: v21, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
            m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
          }
          else
          {
            m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
          }
        }
        else
        {
          m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
        }
        flDefaultValue = m_pData->m_Storage;
        if ( CDmElement::HasAttribute(this: v19, pAttributeName: "rightValue", type: AT_UNKNOWN) )
        {
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v23 = CDmElement::FindAttribute(this: v16, pAttributeName: "leftValue");
          v24 = v23;
          if ( v23 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v23->m_nFlags & 0x1F) == 3 )
            {
              v25 = (CDmaVar<float> *)v23->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v23) )
            {
              CDmAttribute::CopyDataOut<float>(this: v24, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v25 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v25 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v25 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue != v25->m_Storage )
            bIsDefault = false;
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v26 = CDmElement::FindAttribute(this: v16, pAttributeName: "rightValue");
          v27 = v26;
          if ( v26 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v26->m_nFlags & 0x1F) == 3 )
            {
              v28 = (CDmaVar<float> *)v26->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v26) )
            {
              CDmAttribute::CopyDataOut<float>(this: v27, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v28 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v28 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v28 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue == v28->m_Storage && bIsDefault )
            goto LABEL_68;
        }
        else
        {
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v29 = CDmElement::FindAttribute(this: v16, pAttributeName: "value");
          v30 = v29;
          if ( v29 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v29->m_nFlags & 0x1F) == 3 )
            {
              v31 = (CDmaVar<float> *)v29->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v29) )
            {
              CDmAttribute::CopyDataOut<float>(this: v30, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v31 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v31 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v31 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue == v31->m_Storage )
LABEL_68:
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
              this: &controls,
              elem: j);
        }
LABEL_69:
        if ( --j < 0 )
          goto LABEL_70;
        v11 = controls.m_pStorage;
      }
    }
LABEL_72:
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498A30
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MovePresetUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498AC0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MovePresetDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498B50
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveGroupUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498BE0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveGroupDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498C70
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498D00
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemovePreset";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498D90
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498E20
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "InputCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498EB0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498F40
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddPhonemeGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498FD0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RenameGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499060
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveDefaultControls";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004990F0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RenamePreset";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499180
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleGroupVisibility";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499210
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleGroupSharing";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004992A0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499330
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemDeselected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004993C0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportPresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499450
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004994E0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1020,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportPresetGroups";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499570
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1024,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroups";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499600
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1028,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroupsToVFE";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499690
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1032,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroupsToTXT";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499720
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1036,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetPicked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004997B0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertySheet::`vcall'{1040,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetPickCancelled";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499840
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1044,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileStateMachineFinished";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004998D0
// Name: public: static void CDmePresetGroupEditorFrame::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePresetGroupEditorFrame::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x004999A0
// Name: public: static void CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PresetsChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499A30
// Name: public: CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupEditorPanel *__thiscall CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(
        CDmePresetGroupEditorPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v10; // ebx
  CDmePresetGroupListPanel *v11; // eax
  CDmePresetGroupListPanel *v12; // eax
  CDmePresetListPanel *v13; // eax
  CDmePresetListPanel *v14; // eax
  vgui::FileOpenStateMachine *v15; // eax
  vgui::FileOpenStateMachine *v16; // eax
  vgui::Panel *v17; // eax
  int savedregs; // [esp+ECh] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&vgui::IFileOpenStateMachineClient::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorPanel_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( `CDmePresetGroupEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v4->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePresetGroupEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorPanel");
    v5->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePresetGroupEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorPanel");
    v6->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(a1: (int)&savedregs);
  this->m_hFilmClip.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_hFileOpenStateMachine.m_iPanelID = -1;
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PresetGroupSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
  v11 = (CDmePresetGroupListPanel *)MemAlloc_Alloc(nSize: 0x254u);
  if ( v11 != nullptr )
    v12 = CDmePresetGroupListPanel::CDmePresetGroupListPanel(
            this: v11,
            pParent: Child,
            pName: "PresetGroupList",
            pComboPanel: this);
  else
    v12 = nullptr;
  this->m_pPresetGroupList = v12;
  v12->AddColumnHeader(this: v12, a2: 0, a3: "name", a4: "Preset Group Name", a5: 150, a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 1,
    a3: "visible",
    a4: "Visible",
    a5: 70,
    a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 2,
    a3: "shared",
    a4: "Shared",
    a5: 52,
    a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 3,
    a3: "readonly",
    a4: "Read Only",
    a5: 52,
    a6: 0);
  this->m_pPresetGroupList->SetSelectIndividualCells(this: this->m_pPresetGroupList, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pPresetGroupList, bState: false);
  this->m_pPresetGroupList->SetEmptyListText_2(this: this->m_pPresetGroupList, a2: "No preset groups");
  this->m_pPresetGroupList->AddActionSignalTarget_2(this: this->m_pPresetGroupList, a2: this);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 0, a3: IndexSortFunc);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 1, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 1, a3: false);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 2, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 2, a3: false);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 3, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 3, a3: false);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetGroupList->SetDropEnabled)(a1: 1, a2: 0);
  this->m_pPresetGroupList->SetSortColumn(this: this->m_pPresetGroupList, a2: 0);
  this->m_pPresetGroupList->SetDragEnabled(this: this->m_pPresetGroupList, a2: true);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetGroupList->SetDropEnabled)(a1: 1, a2: 0);
  vgui::ListPanel::SetIgnoreDoubleClick(this: this->m_pPresetGroupList, state: true);
  v13 = (CDmePresetListPanel *)MemAlloc_Alloc(nSize: 0x254u);
  if ( v13 != nullptr )
    v14 = CDmePresetListPanel::CDmePresetListPanel(this: v13, pParent: v10, pName: "PresetList", pComboPanel: this);
  else
    v14 = nullptr;
  this->m_pPresetList = v14;
  v14->AddColumnHeader(this: v14, a2: 0, a3: "name", a4: "Preset Name", a5: 150, a6: 0);
  this->m_pPresetList->SetSelectIndividualCells(this: this->m_pPresetList, a2: false);
  this->m_pPresetList->SetEmptyListText_2(this: this->m_pPresetList, a2: "No presets");
  this->m_pPresetList->AddActionSignalTarget_2(this: this->m_pPresetList, a2: this);
  this->m_pPresetList->SetSortFunc(this: this->m_pPresetList, a2: 0, a3: IndexSortFunc);
  this->m_pPresetList->SetSortColumn(this: this->m_pPresetList, a2: 0);
  this->m_pPresetList->SetDragEnabled(this: this->m_pPresetList, a2: true);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetList->SetDropEnabled)(a1: 1, a2: 0);
  vgui::ListPanel::SetIgnoreDoubleClick(this: this->m_pPresetList, state: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepresetgroupeditorpanel.res",
    dialogID: 0);
  v15 = (vgui::FileOpenStateMachine *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v15 != nullptr )
    v16 = vgui::FileOpenStateMachine::FileOpenStateMachine(
            this: v15,
            pParent: this,
            pClient: &this->vgui::IFileOpenStateMachineClient);
  else
    v16 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hFileOpenStateMachine, pPanel: v16);
  v17 = vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  v17->AddActionSignalTarget_2(this: v17, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00499F00
// Name: private: void CDmePresetGroupEditorPanel::RefreshPresetNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::RefreshPresetNames(CDmePresetGroupEditorPanel *this)
{
  const char *SelectedPresetName; // eax
  CDmePresetListPanel *m_pPresetList; // ecx
  const char *SelectedPresetGroupName; // eax
  const char *v5; // edi
  KeyValues *v6; // esi
  CDmeFilmClip *v7; // eax
  const char *m_pAsString; // edi
  KeyValues *v9; // eax
  int v10; // esi
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > presetNames; // [esp+4h] [ebp-1Ch] BYREF
  const char *pSelectedPresetName; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
  m_pPresetList = this->m_pPresetList;
  pSelectedPresetName = SelectedPresetName;
  m_pPresetList->RemoveAll(this: m_pPresetList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    v5 = SelectedPresetGroupName;
    v6 = nullptr;
    if ( SelectedPresetGroupName != nullptr )
    {
      memset(&presetNames, 0, sizeof(presetNames));
      if ( _V_strcmp(s1: SelectedPresetGroupName, s2: "Procedural") != 0 )
      {
        v7 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
        CollectPresetNamesForGroup(
          pFilmClip: v7,
          pPresetGroupName: v5,
          (CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
      }
      else
      {
        CollectProceduralPresetNames((CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
      }
      i = 0;
      if ( presetNames.m_Size > 0 )
      {
        while ( 1 )
        {
          m_pAsString = presetNames.m_Memory.m_pMemory[i].u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v9 != nullptr )
            v6 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "name", firstValue: m_pAsString);
          KeyValues::SetString(this: v6, keyName: "presetName", value: m_pAsString);
          KeyValues::SetInt(this: v6, keyName: "index", value: i);
          v10 = this->m_pPresetList->AddItem(this: this->m_pPresetList, a2: v6, a3: 0, a4: false, a5: false);
          if ( pSelectedPresetName != nullptr && _V_strcmp(s1: pSelectedPresetName, s2: m_pAsString) == 0 )
            this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: v10);
          if ( ++i >= presetNames.m_Size )
            break;
          v6 = nullptr;
        }
      }
      this->m_pPresetList->SortList(this: this->m_pPresetList);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&presetNames);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A080
// Name: private: void CDmePresetGroupEditorPanel::PerformRenamePreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::PerformRenamePreset(
        CDmePresetGroupEditorPanel *this,
        const char *pNewPresetName)
{
  const char *SelectedPresetName; // esi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *v5; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *v7; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-1Ch] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+18h] [ebp-8h]
  const char *pPresetName; // [esp+1Ch] [ebp-4h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
    pPresetName = SelectedPresetName;
    if ( SelectedPresetName != nullptr
      && CDmePresetGroupEditorPanel::HasDuplicatePresetName(
           this,
           pPresetName: pNewPresetName,
           pIgnorePresetName: SelectedPresetName) == 0 )
    {
      StartUndo = g_pDataModel->StartUndo;
      *(_WORD *)&sg.m_bReleased = 256;
      sg.m_pNotify = nullptr;
      StartUndo(this: g_pDataModel, a2: "Rename Preset", a3: "Rename Preset", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Rename Preset", a3: 6, a4: 256);
      traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                                this: g_pDataModel,
                                                a2: this->m_hFilmClip.m_handle);
      traversal.m_nIndex = 0;
      v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( v5 != nullptr )
      {
        while ( 1 )
        {
          PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v5, pGroupName: pPresetGroupName);
          if ( PresetGroup != nullptr )
          {
            v7 = CDmePresetGroup::FindOrAddPreset(this: PresetGroup, pPresetName: SelectedPresetName);
            if ( v7 != nullptr )
            {
              g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: pNewPresetName);
              CDmAttribute::SetValue<CUtlSymbolLarge>(this: v7->m_Name.m_pAttribute, &value);
            }
          }
          v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          if ( v5 == nullptr )
            break;
          SelectedPresetName = pPresetName;
        }
      }
      CUndoScopeGuard::Release(this: &sg);
      CDmePresetGroupEditorPanel::RefreshPresetNames(this);
      CDmePresetGroupEditorPanel::NotifyDataChanged((CDmePresetGroupEditorFrame *)this);
      if ( !sg.m_bReleased )
      {
        g_pDataModel->FinishUndo(this: g_pDataModel);
        if ( sg.m_bNotify )
          g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
        if ( sg.m_pNotify != nullptr )
          g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A1F0
// Name: public: virtual void CDmePresetGroupEditorPanel::OnRemovePreset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemovePreset(CDmePresetGroupEditorPanel *this)
{
  int v2; // eax
  int v3; // edi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // eax
  int v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-18h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-10h] BYREF
  const char *pPresetName; // [esp+14h] [ebp-8h]
  const char *pPresetGroupName; // [esp+18h] [ebp-4h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    pPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
    if ( pPresetName != nullptr )
    {
      v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
      v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
      StartUndo = g_pDataModel->StartUndo;
      *(_WORD *)&sg.m_bReleased = 256;
      sg.m_pNotify = nullptr;
      StartUndo(this: g_pDataModel, a2: "Remove Preset", a3: "Remove Preset", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Remove Preset", a3: 6, a4: 256);
      traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                                this: g_pDataModel,
                                                a2: this->m_hFilmClip.m_handle);
      traversal.m_nIndex = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pPresetGroupName);
        if ( PresetGroup != nullptr )
          CDmePresetGroup::RemovePreset(this: PresetGroup, pPresetName);
      }
      CUndoScopeGuard::Release(this: &sg);
      CDmePresetGroupEditorPanel::RefreshPresetNames(this);
      if ( v3 >= this->m_pPresetList->GetItemCount(this: this->m_pPresetList) )
        --v3;
      if ( v3 >= 0 )
      {
        v7 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3);
        this->m_pPresetList->ClearSelectedItems(this: this->m_pPresetList);
        this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: v7);
      }
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "PresetsChanged");
      else
        v9 = nullptr;
      this->PostActionSignal(this, a2: v9);
      if ( !sg.m_bReleased )
      {
        g_pDataModel->FinishUndo(this: g_pDataModel);
        if ( sg.m_bNotify )
          g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
        if ( sg.m_pNotify != nullptr )
          g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A3B0
// Name: public: void CDmePresetGroupEditorPanel::MovePresetInFrontOf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetInFrontOf(
        CDmePresetGroupEditorPanel *this,
        const char *pDragPresetName,
        const char *pDropPresetName)
{
  const char *SelectedPresetGroupName; // esi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  CDmeAnimationSet *v6; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePresetGroup *v8; // esi
  CDmePreset *Preset; // edi
  CDmePreset *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+10h] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+18h] [ebp-4h]

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  pPresetGroupName = SelectedPresetGroupName;
  if ( SelectedPresetGroupName != nullptr )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    StartUndo(this: g_pDataModel, a2: "Reorder Presets", a3: "Reorder Presets", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Reorder Presets", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v6 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v6 != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v6, pGroupName: SelectedPresetGroupName);
        v8 = PresetGroup;
        if ( PresetGroup != nullptr )
        {
          Preset = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName: pDragPresetName);
          if ( Preset != nullptr )
          {
            v10 = CDmePresetGroup::FindPreset(this: v8, pPresetName: pDropPresetName);
            CDmePresetGroup::MovePresetInFrontOf(this: v8, pPreset: Preset, pInFrontOf: v10);
          }
        }
        v6 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( v6 == nullptr )
          break;
        SelectedPresetGroupName = pPresetGroupName;
      }
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this);
    CDmePresetGroupEditorPanel::SetSelectedPreset(this, a2: (int)this, pPresetName: pDragPresetName);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "PresetsChanged");
    else
      v12 = nullptr;
    this->PostActionSignal(this, a2: v12);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A520
// Name: private: virtual void CDmePresetGroupEditorPanel::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnItemDeselected(CDmePresetGroupEditorPanel *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pPresetGroupList )
    CDmePresetGroupEditorPanel::RefreshPresetNames(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049A550
// Name: public: void CDmePresetGroupEditorPanel::MovePresetIntoGroup(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetIntoGroup(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetName,
        const char *pSrcGroupName,
        const char *pDstGroupName)
{
  CDmePresetGroupEditorPanel *v4; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // eax
  CDmePresetGroup *v9; // edi
  CDmePresetGroup *v10; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-1Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-Ch] BYREF
  CDmePresetGroupEditorPanel *v14; // [esp+14h] [ebp-4h]

  v4 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hFilmClip.m_handle;
  v14 = this;
  if ( (int)GetElement(this: g_pDataModel, a2: m_handle) != 0
    && pPresetName != nullptr
    && pSrcGroupName != nullptr
    && pDstGroupName != nullptr )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    StartUndo(this: g_pDataModel, a2: "Change Preset Group", a3: "Change Preset Group", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Change Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v7 != nullptr )
    {
      do
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: pSrcGroupName);
        v9 = PresetGroup;
        if ( PresetGroup != nullptr && CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName) != nullptr )
        {
          CDmePresetGroup::RemovePreset(this: v9, pPresetName);
          v10 = CDmeAnimationSet::FindOrAddPresetGroup(this: v7, pGroupName: pDstGroupName);
          CDmePresetGroup::FindOrAddPreset(this: v10, pPresetName);
        }
        v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      }
      while ( v7 != nullptr );
      v4 = v14;
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this: v4);
    CDmePresetGroupEditorPanel::NotifyDataChanged(this: (CDmePresetGroupEditorFrame *)v4);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A6B0
// Name: public: virtual void CDmePresetListPanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnPanelDropped(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  int v4; // eax
  KeyValues *v5; // ebx
  const char *String; // edi
  const char *v7; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( msgList->m_Size != 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this
      && this->m_pPresetGroupPanel != nullptr )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
      this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
      v4 = this->GetItemIDFromRow(this, a2: row);
      v5 = this->GetItem(this, a2: v4);
      String = KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: nullptr);
      v7 = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: nullptr);
      if ( String != nullptr && v7 != nullptr )
        CDmePresetGroupEditorPanel::MovePresetInFrontOf(
          this: this->m_pPresetGroupPanel,
          pDragPresetName: String,
          pDropPresetName: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A780
// Name: public: CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupEditorFrame *__thiscall CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(
        CDmePresetGroupEditorFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmePresetGroupEditorPanel *v7; // eax
  CDmePresetGroupEditorPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  __int128 v12; // [esp-1Ch] [ebp-34h]
  __int128 v13; // [esp-1Ch] [ebp-34h]
  __int64 v14; // [esp+10h] [ebp-8h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "DmePresetGroupEditorFrame", showTaskbarIcon: true, bPopup: true);
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&IDmNotify::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorFrame_vtbl *)&CDmePresetGroupEditorFrame::`vftable'{for `vgui::Frame'};
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&CDmePresetGroupEditorFrame::`vftable'{for `IDmNotify'};
  if ( `CDmePresetGroupEditorFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
    v4->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDmePresetGroupEditorFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorFrame");
    v5->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDmePresetGroupEditorFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
    v6->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(a1: (int)&savedregs);
  if ( `CDmePresetGroupEditorFrame::PanelKBMapFunc_undo::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v12 = (unsigned int) __thiscall CElementPropertiesTreeInternal::`vcall'{1120,{flat}};
    v14 = 0;
    `CDmePresetGroupEditorFrame::PanelKBMapFunc_undo::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v12 + 1) = 0;
    CDmePresetGroupEditorFrame::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "undo",
      defaultcode: KEY_Z,
      default_modifiers: 2,
      function: v12,
      helpstring: (unsigned int)"#undo_help",
      passive: false);
  }
  if ( `CDmePresetGroupEditorFrame::PanelKBMapFunc_redo::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v13 = (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    v14 = 0;
    `CDmePresetGroupEditorFrame::PanelKBMapFunc_redo::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v13 + 1) = 0;
    CDmePresetGroupEditorFrame::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "redo",
      defaultcode: KEY_Z,
      default_modifiers: 3,
      function: v13,
      helpstring: (unsigned int)"#redo_help",
      passive: false);
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CDmePresetGroupEditorPanel *)MemAlloc_Alloc(nSize: 0x1B8u);
  if ( v7 != nullptr )
    v8 = CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(
           this: v7,
           pParent: this,
           pName: "DmePresetGroupEditorPanel");
  else
    v8 = nullptr;
  this->m_pEditor = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "#VGui_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pOkButton = v10;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepresetgroupeditorframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: &this->IDmNotify);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049A9B0
// Name: public: void CDmePresetGroupEditorPanel::RefreshAnimationSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::RefreshAnimationSet(CDmePresetGroupEditorPanel *this)
{
  CDmePresetGroupEditorPanel *v1; // edi
  const char *SelectedPresetGroupName; // eax
  CDmePresetGroupListPanel *m_pPresetGroupList; // ecx
  KeyValues *v4; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmeFilmClip *v6; // eax
  bool *p_bGroupReadOnly; // edi
  const char *v8; // ebx
  KeyValues *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  Color v13; // eax
  int v14; // esi
  DmElementHandle_t m_handle; // [esp-14h] [ebp-40h]
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+4h] [ebp-28h] BYREF
  const char *pSelectedPresetGroupName; // [esp+18h] [ebp-14h]
  CDmePresetGroupEditorPanel *v18; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v20; // [esp+24h] [ebp-8h]
  Color value; // [esp+28h] [ebp-4h]

  v1 = this;
  v18 = this;
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  m_pPresetGroupList = v1->m_pPresetGroupList;
  pSelectedPresetGroupName = SelectedPresetGroupName;
  m_pPresetGroupList->RemoveAll(this: m_pPresetGroupList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hFilmClip.m_handle) != nullptr )
  {
    v4 = nullptr;
    GetElement = g_pDataModel->GetElement;
    m_handle = v1->m_hFilmClip.m_handle;
    memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
    v6 = (CDmeFilmClip *)GetElement(this: g_pDataModel, a2: m_handle);
    CollectPresetGroupInfo(
      pFilmClip: v6,
      presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
      bSkipReadOnly: false,
      bSkipInvisible: false);
    i = 0;
    if ( presetGroupInfo.m_Size > 0 )
    {
      p_bGroupReadOnly = &presetGroupInfo.m_Memory.m_pMemory->bGroupReadOnly;
      do
      {
        v8 = defaultValue;
        if ( *(_DWORD *)(p_bGroupReadOnly - 5) != -1 )
          v8 = *(const char **)(p_bGroupReadOnly - 5);
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v4 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "name", firstValue: v8);
        KeyValues::SetString(this: v4, keyName: "presetGroupName", value: v8);
        v10 = "Yes";
        if ( !p_bGroupReadOnly[1] )
          v10 = "No";
        KeyValues::SetString(this: v4, keyName: "visible", value: v10);
        v11 = "Yes";
        if ( !*(p_bGroupReadOnly - 1) )
          v11 = "No";
        KeyValues::SetString(this: v4, keyName: "shared", value: v11);
        v12 = "Yes";
        if ( !*p_bGroupReadOnly )
          v12 = "No";
        KeyValues::SetString(this: v4, keyName: "readonly", value: v12);
        if ( *p_bGroupReadOnly )
        {
          value = (Color)-16776961;
          v13 = (Color)-16776961;
        }
        else
        {
          v20 = -1;
          v13 = (Color)-1;
        }
        KeyValues::SetColor(this: v4, keyName: "cellcolor", value: v13);
        KeyValues::SetInt(this: v4, keyName: "index", value: i);
        v14 = v18->m_pPresetGroupList->AddItem(this: v18->m_pPresetGroupList, a2: v4, a3: 0, a4: false, a5: false);
        if ( pSelectedPresetGroupName != nullptr && _V_strcmp(s1: pSelectedPresetGroupName, s2: v8) == 0 )
          v18->m_pPresetGroupList->AddSelectedItem(this: v18->m_pPresetGroupList, a2: v14);
        p_bGroupReadOnly += 8;
        v4 = nullptr;
        ++i;
      }
      while ( i < presetGroupInfo.m_Size );
      v1 = v18;
    }
    v1->m_pPresetGroupList->SortList(this: v1->m_pPresetGroupList);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this: v1);
    if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049ABB0
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMovePresetUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMovePresetUp(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) == 1 )
  {
    v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
    v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
    v4 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3 - 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v2);
      v6 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v4);
      String = KeyValues::GetString(this: v6, keyName: "presetName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetInFrontOf(this, pDragPresetName: v7, pDropPresetName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AC60
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMovePresetDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMovePresetDown(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // ebx
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) == 1 )
  {
    v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
    v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
    v4 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3 + 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v2);
      v6 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v4);
      String = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v6, keyName: "presetName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetInFrontOf(this, pDragPresetName: v7, pDropPresetName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AD10
// Name: public: virtual bool CDmePresetGroupEditorPanel::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::OnReadFileFromDisk(
        CDmePresetGroupEditorPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  DmFileId_t v6; // esi
  const char *Name; // eax
  CDmElement *v9; // esi
  CDmeAnimationSet *v10; // edi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  const char *m_pAsString; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // eax
  CDmePresetGroupEditorPanel *v14; // esi
  CDmAttribute *Attribute; // eax
  int BufferType; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-20h] BYREF
  CUndoScopeGuard v18; // [esp+14h] [ebp-18h] BYREF
  CDisableUndoScopeGuard sg; // [esp+1Ch] [ebp-10h] BYREF
  CDmePresetGroupEditorPanel *v20; // [esp+24h] [ebp-8h]
  CDmElement *pRoot; // [esp+28h] [ebp-4h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v20 = this;
  sg.m_bNotify = false;
  sg.m_pNotify = nullptr;
  *(_WORD *)&sg.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v6 = g_pDataModel->RestoreFromFile(
         this: g_pDataModel,
         a2: pFileName,
         a3: nullptr,
         a4: pFileFormat,
         a5: &pRoot,
         a6: CR_FORCE_COPY,
         a7: nullptr);
  CChangeUndoScopeGuard::Release(this: &sg);
  if ( v6 == DMFILEID_INVALID )
    goto LABEL_2;
  Name = KeyValues::GetName(this: pContextKeyValues);
  if ( _V_stricmp(s1: Name, s2: "ImportPresetGroup") != 0 )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "presets");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      if ( pRoot != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pRoot);
      else
        BufferType = -1;
      KeyValues::SetInt(this: pContextKeyValues, keyName: "presets", value: BufferType);
      goto LABEL_19;
    }
LABEL_2:
    CChangeUndoScopeGuard::Release(this: &sg);
    return 0;
  }
  v9 = pRoot;
  if ( pRoot == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(
          a1: pRoot,
          a2: (CUtlSymbolLarge)CDmePresetGroup::m_classType.u.m_Id) )
  {
    goto LABEL_2;
  }
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                            this: g_pDataModel,
                                            a2: *(_DWORD *)&this->m_InternalKeyFocusTicked_register);
  traversal.m_nIndex = 0;
  v10 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  StartUndo = g_pDataModel->StartUndo;
  *(_WORD *)&v18.m_bReleased = 256;
  v18.m_pNotify = nullptr;
  StartUndo(this: g_pDataModel, a2: "Import Preset Group", a3: "Import Preset Group", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Import Preset Group", a3: 6, a4: 256);
  CDmElement::SetFileId(this: v9, fileid: v10->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CDmeAnimationSet::RemovePresetGroup(this: v10, pPresetGroupName: m_pAsString);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v10);
  CDmaElementArrayBase<CDmePresetGroup,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: PresetGroups,
    pValue: (int)v9);
  CUndoScopeGuard::Release(this: &v18);
  v14 = v20;
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this: (CDmePresetGroupEditorPanel *)((char *)v20 - 380));
  CDmePresetGroupEditorPanel::NotifyDataChanged(this: (CDmePresetGroupEditorFrame *)&v14[-1].m_lLastDoublePressTime);
  if ( !v18.m_bReleased )
  {
    g_pDataModel->FinishUndo(this: g_pDataModel);
    if ( v18.m_bNotify )
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v18.m_pNotify != nullptr )
    {
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v18.m_pNotify);
      CChangeUndoScopeGuard::Release(this: &sg);
      return 1;
    }
  }
LABEL_19:
  CChangeUndoScopeGuard::Release(this: &sg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AF30
// Name: private: void CDmePresetGroupEditorPanel::ImportPresets(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::ImportPresets(
        CDmePresetGroupEditorPanel *this,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *presetNames,
        CDmePreset *pRoot)
{
  CDmePresetGroupEditorPanel *v3; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmeAnimationSet *v5; // esi
  const char *SelectedPresetGroupName; // eax
  CDmePresetGroup *PresetGroup; // ebx
  CDmAttribute *Attribute; // esi
  int v9; // eax
  int v10; // edi
  int m_Size; // ebx
  CDmElement *v12; // eax
  CDmeTransform *v13; // esi
  const char *m_pAsString; // eax
  const Vector *Position; // ebx
  int v16; // edi
  CDmElement *v17; // eax
  CDmElement *v18; // esi
  CDmElement *v19; // ecx
  CDmElement *v20; // esi
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-3Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-2Ch] BYREF
  CDmrElementArray<CDmePreset> srcPresets; // [esp+14h] [ebp-24h] BYREF
  CDmePresetGroupEditorPanel *v26; // [esp+1Ch] [ebp-1Ch]
  int nPresetCount; // [esp+20h] [ebp-18h]
  CDmePreset *pPreset; // [esp+24h] [ebp-14h]
  const char *pPresetName; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  DmElementHandle_t src; // [esp+30h] [ebp-8h] BYREF
  CDmePresetGroup *pPresetGroup; // [esp+34h] [ebp-4h]
  CDmeTransform *pSrcPreset; // [esp+44h] [ebp+Ch]
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *pSrcPreseta; // [esp+44h] [ebp+Ch]

  v3 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hFilmClip.m_handle;
  v26 = this;
  traversal.m_pFilmClip = (CDmeFilmClip *)GetElement(this: g_pDataModel, a2: m_handle);
  traversal.m_nIndex = 0;
  v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: v3);
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v5, pGroupName: SelectedPresetGroupName);
  pPresetGroup = PresetGroup;
  if ( PresetGroup != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "presets");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      srcPresets.m_pAttribute = Attribute;
      srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      if ( srcPresets.m_pStorage->m_Size != 0 )
      {
        g_pDataModel->StartUndo(this: g_pDataModel, a2: "Import Presets", a3: "Import Presets", a4: 0);
        g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Import Presets", a3: 6, a4: 256);
        v9 = 0;
        nPresetCount = presetNames->m_Size;
        i = 0;
        if ( nPresetCount > 0 )
        {
          while ( 1 )
          {
            pPresetName = presetNames->m_Memory.m_pMemory[v9];
            v10 = 0;
            pPreset = CDmePresetGroup::FindOrAddPreset(this: PresetGroup, pPresetName);
            pSrcPreset = nullptr;
            if ( srcPresets.m_pAttribute != nullptr )
              m_Size = srcPresets.m_pStorage->m_Size;
            else
              m_Size = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[v10]);
                v13 = (CDmeTransform *)v12;
                if ( v12 != nullptr && v12->IsA(this: v12, a2: CDmePreset::m_classType) )
                {
                  m_pAsString = v13->m_Name.m_Storage.u.m_pAsString;
                  if ( m_pAsString == (const char *)-1 )
                    m_pAsString = defaultValue;
                  if ( _V_strcmp(s1: m_pAsString, s2: pPresetName) == 0 )
                    break;
                }
                if ( ++v10 >= m_Size )
                  goto LABEL_20;
              }
              pSrcPreset = v13;
            }
LABEL_20:
            Position = CDmeTransform::GetPosition(this: pSrcPreset);
            pSrcPreseta = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeTransform::GetPosition(this: (CDmeTransform *)pPreset);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: pSrcPreseta);
            v16 = 0;
            pPreset = (CDmePreset *)LODWORD(Position[1].x);
            if ( (int)pPreset > 0 )
            {
              do
              {
                v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(LODWORD(Position->x) + 4 * v16));
                v18 = v17;
                if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmElement::m_classType) )
                  v19 = v18;
                else
                  v19 = nullptr;
                v20 = CDmElement::CopyInternal(this: v19, depth: TD_DEEP);
                CDmElement::SetFileId(this: v20, fileid: pPresetGroup->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
                if ( v20 != nullptr )
                  src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v20);
                else
                  src = DMELEMENT_HANDLE_INVALID;
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: pSrcPreseta,
                  &src);
                ++v16;
              }
              while ( v16 < (int)pPreset );
            }
            v9 = i + 1;
            i = v9;
            if ( v9 >= nPresetCount )
              break;
            PresetGroup = pPresetGroup;
          }
          v3 = v26;
        }
        CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v3);
        v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v21 != nullptr )
          v22 = KeyValues::KeyValues(this: v21, setName: "PresetsChanged");
        else
          v22 = nullptr;
        v3->PostActionSignal(this: v3, a2: v22);
        g_pDataModel->FinishUndo(this: g_pDataModel);
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B1C0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnPresetPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnPresetPicked(CDmePresetGroupEditorPanel *this, KeyValues *pParams)
{
  int m_Size; // esi
  KeyValues *v3; // edi
  const char **m_pMemory; // ebx
  int Int; // eax
  int v6; // edi
  const char **v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  int j; // esi
  vgui::FileOpenStateMachine *v11; // eax
  KeyValues *Key; // eax
  KeyValues *v13; // edi
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmePreset *v16; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v18; // al
  IDataModel_vtbl *v19; // edx
  DmElementHandle_t v20; // eax
  CDmElement *v21; // eax
  CDmElement *v22; // esi
  char pBuf[32]; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<char const *,CUtlMemory<char const *,int> > presetNames; // [esp+2Ch] [ebp-28h] BYREF
  CChangeUndoScopeGuard v25; // [esp+40h] [ebp-14h] BYREF
  CDmePresetGroupEditorPanel *v26; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int nCount; // [esp+50h] [ebp-4h]

  m_Size = 0;
  v3 = pParams;
  v26 = this;
  m_pMemory = nullptr;
  memset(&presetNames, 0, sizeof(presetNames));
  Int = KeyValues::GetInt(this: pParams, keyName: "count", defaultValue: 0);
  nCount = Int;
  if ( Int == 0 )
  {
LABEL_27:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&presetNames);
    return;
  }
  i = 0;
  if ( Int > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", i);
      *(_DWORD *)&v25.m_bOldValue = KeyValues::GetString(this: v3, keyName: pBuf, defaultValue: defaultValue);
      v6 = m_Size;
      if ( m_Size + 1 > presetNames.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&presetNames,
          num: m_Size - presetNames.m_Memory.m_nAllocationCount + 1);
        m_Size = presetNames.m_Size;
        m_pMemory = presetNames.m_Memory.m_pMemory;
      }
      presetNames.m_Size = ++m_Size;
      presetNames.m_pElements = m_pMemory;
      if ( m_Size - v6 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (m_Size - v6 - 1));
      v7 = &m_pMemory[v6];
      if ( v7 != nullptr )
        *v7 = *(const char **)&v25.m_bOldValue;
      v3 = pParams;
      ++i;
    }
    while ( i < nCount );
  }
  if ( KeyValues::FindKey(this: v3, keyName: "ExportPicked", bCreate: false) == nullptr )
  {
    Key = KeyValues::FindKey(this: v3, keyName: "ImportPicked", bCreate: false);
    v13 = Key;
    if ( Key != nullptr )
    {
      v14 = KeyValues::GetInt(this: Key, keyName: "presets", defaultValue: -1);
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
      v16 = (CDmePreset *)v15;
      if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
        v16 = nullptr;
      CDmePresetGroupEditorPanel::ImportPresets(this: v26, &presetNames, pRoot: v16);
      IsUndoEnabled = g_pDataModel->IsUndoEnabled;
      *(_WORD *)&v25.m_bReleased = 0;
      v25.m_pNotify = nullptr;
      v18 = IsUndoEnabled(this: g_pDataModel);
      v19 = g_pDataModel->__vftable;
      v25.m_bOldValue = v18;
      v19->SetUndoEnabled(this: g_pDataModel, a2: false);
      v20 = KeyValues::GetInt(this: v13, keyName: "presets", defaultValue: -1);
      v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: v20);
      v22 = v21;
      if ( v21 == nullptr || !v21->IsA(this: v21, a2: CDmElement::m_classType) )
        v22 = nullptr;
      g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v22->m_fileId);
      CChangeUndoScopeGuard::Release(this: &v25);
    }
    goto LABEL_27;
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "ExportPresets");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: "count", value: nCount);
  for ( j = 0; j < nCount; ++j )
  {
    V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", j);
    KeyValues::SetString(this: v9, keyName: pBuf, value: m_pMemory[j]);
  }
  v11 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &v26->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::SaveFile(
    this: v11,
    pContextKeyValues: v9,
    pFileName: nullptr,
    pFileType: "preset",
    nFlags: 1);
  if ( presetNames.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0049B450
// Name: private: void CDmePresetGroupEditorPanel::PerformAddGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::PerformAddGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pNewGroupName)
{
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-10h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: nullptr) == 0 )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))StartUndo)(
      a1: g_pDataModel,
      a2: "Add Preset Group",
      a3: "Add Preset Group",
      a4: 0,
      a5: a3);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Add Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      CDmeAnimationSet::FindOrAddPresetGroup(this: i, pGroupName: pNewGroupName);
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this, a2, pPresetGroupName: pNewGroupName);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
    else
      v8 = nullptr;
    this->PostActionSignal(this, a2: v8);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B5B0
// Name: private: void CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pNewGroupName)
{
  CDmePresetGroupEditorPanel *v3; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmeAnimationSet *v5; // eax
  int v6; // ebx
  int i; // edi
  const char *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-118h]
  int v12; // [esp-4h] [ebp-118h]
  char pTempBuf[256]; // [esp+4h] [ebp-110h] BYREF
  CDmePresetGroup *pPresetGroup; // [esp+104h] [ebp-10h]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+108h] [ebp-Ch] BYREF
  CDmePresetGroupEditorPanel *v16; // [esp+110h] [ebp-4h]

  v3 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hFilmClip.m_handle;
  v16 = this;
  if ( (int)GetElement(this: g_pDataModel, a2: m_handle) != 0
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this: v3,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: nullptr) == 0 )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Add Phoneme Preset Group", a3: "Add Phoneme Preset Group", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Add Phoneme Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v5 != nullptr )
    {
      v12 = a2;
      do
      {
        pPresetGroup = CDmeAnimationSet::FindOrAddPresetGroup(this: v5, pGroupName: pNewGroupName);
        v6 = NumPhonemes();
        for ( i = 0; i < v6; ++i )
        {
          if ( IsStandardPhoneme(index: i) )
          {
            v8 = NameForPhonemeByIndex(index: i);
            if ( _V_stricmp(s1: v8, s2: "<sil>") == 0 )
              v8 = "silence";
            V_snprintf(pDest: pTempBuf, maxLen: 256, pFormat: "p_%s", v8);
            CDmePresetGroup::FindOrAddPreset(this: pPresetGroup, pPresetName: pTempBuf);
            v3 = v16;
          }
        }
        v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      }
      while ( v5 != nullptr );
      a2 = v12;
    }
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v3);
    CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this: v3, a2, pPresetGroupName: pNewGroupName);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
    {
      v10 = KeyValues::KeyValues(this: v9, setName: "PresetsChanged");
      v3->PostActionSignal(this: v3, a2: v10);
    }
    else
    {
      v3->PostActionSignal(this: v3, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B760
// Name: private: void CDmePresetGroupEditorPanel::PerformRenameGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::PerformRenameGroup(
        CDmePresetGroupEditorPanel *this,
        const char *pNewGroupName)
{
  const char *SelectedPresetGroupName; // ebx
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+14h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+1Ch] [ebp-4h] BYREF

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName != nullptr
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: SelectedPresetGroupName) == 0 )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    StartUndo(this: g_pDataModel, a2: "Rename Preset Group", a3: "Rename Preset Group", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Rename Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: SelectedPresetGroupName);
      if ( PresetGroup != nullptr )
      {
        g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: pNewGroupName);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: PresetGroup->m_Name.m_pAttribute, &value);
      }
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
    else
      v8 = nullptr;
    this->PostActionSignal(this, a2: v8);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B8C0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnInputCompleted(CDmePresetGroupEditorPanel *this, KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v4; // esi

  String = KeyValues::GetString(this: pKeyValues, keyName: "text", defaultValue: nullptr);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnAddGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformAddGroup(this, a2: (int)this, a3: (int)pKeyValues, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnAddPhonemeGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(this, a2: (int)this, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnRenameGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformRenameGroup(this, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnRenamePreset", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformRenamePreset(this, pNewPresetName: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B970
// Name: public: void CDmePresetGroupEditorPanel::ToggleGroupVisibility(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::ToggleGroupVisibility(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetGroupName)
{
  const char *v2; // edi
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  v2 = pPresetGroupName;
  if ( pPresetGroupName != nullptr )
  {
    g_pDataModel->StartUndo(
      this: g_pDataModel,
      a2: "Toggle Preset Group Visibility",
      a3: "Toggle Preset Group Visibility",
      a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Toggle Preset Group Visibility", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: v2);
      if ( PresetGroup != nullptr )
      {
        HIBYTE(pPresetGroupName) = !PresetGroup->m_bIsVisible.m_Storage;
        CDmAttribute::SetValue<bool>(this: PresetGroup->m_bIsVisible.m_pAttribute, value: (bool *)&pPresetGroupName + 3);
      }
    }
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "PresetsChanged");
    else
      v7 = nullptr;
    this->PostActionSignal(this, a2: v7);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049BA80
// Name: private: virtual void CDmePresetGroupEditorPanel::OnToggleGroupVisibility(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnToggleGroupVisibility(CDmePresetGroupEditorPanel *this)
{
  const char *SelectedPresetGroupName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName != nullptr )
    CDmePresetGroupEditorPanel::ToggleGroupVisibility(this, pPresetGroupName: SelectedPresetGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x0049BAA0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnToggleGroupSharing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnToggleGroupSharing(CDmePresetGroupEditorPanel *this)
{
  CDmePresetGroupEditorPanel *v1; // esi
  const char *SelectedPresetGroupName; // edi
  CDmeAnimationSet *v3; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmElement *v5; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // esi
  CDmaVar<bool> *m_pData; // esi
  CDmAttribute *v9; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmePresetGroupEditorPanel *v11; // [esp+14h] [ebp-Ch]
  const char *pPresetGroupName; // [esp+18h] [ebp-8h]
  bool value; // [esp+1Fh] [ebp-1h] BYREF

  v1 = this;
  v11 = this;
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  pPresetGroupName = SelectedPresetGroupName;
  if ( SelectedPresetGroupName != nullptr )
  {
    g_pDataModel->StartUndo(
      this: g_pDataModel,
      a2: "Toggle Preset Group Sharing",
      a3: "Toggle Preset Group Sharing",
      a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Toggle Preset Group Sharing", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v3 != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: SelectedPresetGroupName);
        v5 = PresetGroup;
        if ( PresetGroup != nullptr )
        {
          if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
          }
          Attribute = CDmElement::FindAttribute(this: PresetGroup, pAttributeName: "shared");
          v7 = Attribute;
          if ( Attribute != nullptr )
          {
            if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
            }
            if ( (Attribute->m_nFlags & 0x1F) == 4 )
            {
              m_pData = (CDmaVar<bool> *)Attribute->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
            {
              CDmAttribute::CopyDataOut<bool>(this: v7, value: &`CDmAttribute::GetValue<bool>'::`7'::tempVal);
              m_pData = (CDmaVar<bool> *)&`CDmAttribute::GetValue<bool>'::`7'::tempVal;
            }
            else
            {
              m_pData = &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
            }
          }
          else
          {
            m_pData = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
          }
          if ( m_pData->m_Storage )
          {
            CDmElement::RemoveAttribute(this: v5, pAttributeName: "shared");
          }
          else
          {
            value = true;
            v9 = CDmElement::FindAttribute(this: v5, pAttributeName: "shared");
            if ( v9 != nullptr
              || (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "shared", type: AT_BOOL)) != nullptr )
            {
              CDmAttribute::SetValue<bool>(this: v9, &value);
            }
          }
        }
        v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( v3 == nullptr )
          break;
        SelectedPresetGroupName = pPresetGroupName;
      }
      v1 = v11;
    }
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v1);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049BC40
// Name: public: virtual void CDmePresetGroupEditorPanel::OnRemoveGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemoveGroup(CDmePresetGroupEditorPanel *this)
{
  const char *SelectedPresetGroupName; // eax
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  int v5; // eax
  int v6; // edi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  int v9; // edi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    pPresetGroupName = SelectedPresetGroupName;
    if ( SelectedPresetGroupName != nullptr )
    {
      if ( _V_stricmp(s1: SelectedPresetGroupName, s2: "procedural") != 0 )
      {
        v5 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
        v6 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v5);
        StartUndo = g_pDataModel->StartUndo;
        *(_WORD *)&sg.m_bReleased = 256;
        sg.m_pNotify = nullptr;
        StartUndo(this: g_pDataModel, a2: "Remove Preset Group", a3: "Remove Preset Group", a4: 0);
        g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Remove Preset Group", a3: 6, a4: 256);
        traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                                  this: g_pDataModel,
                                                  a2: this->m_hFilmClip.m_handle);
        traversal.m_nIndex = 0;
        for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
              i != nullptr;
              i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
        {
          CDmeAnimationSet::RemovePresetGroup(this: i, pPresetGroupName);
        }
        CUndoScopeGuard::Release(this: &sg);
        CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
        if ( v6 >= this->m_pPresetGroupList->GetItemCount(this: this->m_pPresetGroupList) )
          --v6;
        if ( v6 >= 0 )
        {
          v9 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v6);
          this->m_pPresetGroupList->ClearSelectedItems(this: this->m_pPresetGroupList);
          this->m_pPresetGroupList->AddSelectedItem(this: this->m_pPresetGroupList, a2: v9);
        }
        CDmePresetGroupEditorPanel::NotifyDataChanged((CDmePresetGroupEditorFrame *)this);
        if ( !sg.m_bReleased )
        {
          g_pDataModel->FinishUndo(this: g_pDataModel);
          if ( sg.m_bNotify )
            g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
          if ( sg.m_pNotify != nullptr )
            g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
        }
      }
      else
      {
        v3 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v3 != nullptr )
        {
          v4 = vgui::MessageBox::MessageBox(
                 this: v3,
                 title: "#DmePresetGroupEditor_CannotRemovePresetGroupTitle",
                 text: "#DmePresetGroupEditor_CannotRemovePresetGroupText",
                 parent: this);
          v4->DoModal_2(this: v4, a2: nullptr);
        }
        else
        {
          (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049BE30
// Name: public: void CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(
        CDmePresetGroupEditorPanel *this,
        const char *pDragGroupName,
        const char *pDropGroupName)
{
  CDmeAnimationSet *i; // esi
  CDmePresetGroup *PresetGroup; // edi
  CDmePresetGroup *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Reorder Preset Groups", a3: "Reorder Preset Groups", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Reorder Preset Groups", a3: 6, a4: 256);
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pDragGroupName);
    if ( PresetGroup != nullptr )
    {
      v6 = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pDropGroupName);
      CDmeAnimationSet::MovePresetGroupInFrontOf(this: i, pPresetGroup: PresetGroup, pInFrontOf: v6);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
  CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this, a2: (int)this, pPresetGroupName: pDragGroupName);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
  else
    v8 = nullptr;
  this->PostActionSignal(this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x0049BF40
// Name: public: virtual void CDmePresetGroupListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnMouseDoublePressed(CDmePresetGroupListPanel *this, int code)
{
  int v3; // eax
  KeyValues *v4; // eax
  const char *String; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( code == 107 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &code);
    this->GetCellAtPos(this, a2: x, a3: code, a4: &row, a5: &column);
    v3 = this->GetItemIDFromRow(this, a2: row);
    v4 = this->GetItem(this, a2: v3);
    String = KeyValues::GetString(this: v4, keyName: "presetGroupName", defaultValue: defaultValue);
    CDmePresetGroupEditorPanel::ToggleGroupVisibility(this: this->m_pPresetGroupPanel, pPresetGroupName: String);
  }
  else
  {
    vgui::ListPanel::OnMouseDoublePressed(this, (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049BFD0
// Name: public: virtual void CDmePresetGroupListPanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnPanelDropped(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  int v4; // eax
  KeyValues *v5; // eax
  const char *String; // ebx
  const char *v7; // eax
  const char *v8; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( msgList->m_Size != 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( this->m_pPresetGroupPanel != nullptr )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
      this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
      v4 = this->GetItemIDFromRow(this, a2: row);
      v5 = this->GetItem(this, a2: v4);
      if ( v5 != nullptr )
      {
        String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
        v7 = KeyValues::GetString(this: v3, keyName: "presetGroupName", defaultValue: defaultValue);
        if ( v7 != nullptr )
        {
          CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(
            this: this->m_pPresetGroupPanel,
            pDragGroupName: v7,
            pDropGroupName: String);
        }
        else
        {
          v8 = KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: defaultValue);
          if ( v8 != nullptr )
            CDmePresetGroupEditorPanel::MovePresetIntoGroup(
              this: this->m_pPresetGroupPanel,
              pPresetName: v8,
              pSrcGroupName: nullptr,
              pDstGroupName: String);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C0C0
// Name: public: virtual void CDmePresetGroupEditorFrame::NotifyDataChanged(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::NotifyDataChanged(
        CDmePresetGroupEditorFrame *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 132) + 136))(a1: (char *)this - 528) != 0
    && nNotifySource != 6 )
  {
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: *(CDmePresetGroupEditorPanel **)&this->m_OnDelete_register);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C100
// Name: public: void CDmePresetGroupEditorPanel::SetAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::SetAnimationSetClip(
        CDmePresetGroupEditorPanel *this,
        CDmeFilmClip *pFilmClip)
{
  DmElementHandle_t BufferType; // eax

  if ( pFilmClip != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pFilmClip);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeFilmClip,0>::Set(this: &this->m_hFilmClip, h: BufferType);
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049C140
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMoveGroupUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMoveGroupUp(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) == 1 )
  {
    v2 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
    v3 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v2);
    v4 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v3 - 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v2);
      v6 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v4);
      String = KeyValues::GetString(this: v6, keyName: "presetGroupName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(this, pDragGroupName: v7, pDropGroupName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C1F0
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMoveGroupDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMoveGroupDown(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // ebx
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) == 1 )
  {
    v2 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
    v3 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v2);
    v4 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v3 + 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v2);
      v6 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v4);
      String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v6, keyName: "presetGroupName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(this, pDragGroupName: v7, pDropGroupName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004974C0
// Name: class CDmePresetGroup __near * CreateElement<class CDmePresetGroup>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePresetGroup *__cdecl CreateElement<CDmePresetGroup>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmePresetGroup::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmePresetGroup::m_classType) )
    return (CDmePresetGroup *)v5;
  else
    return nullptr;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104A6090
// Name: public: static char const __near * CDmePresetGroupEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupEditorPanel::GetPanelClassName()
{
  return "CDmePresetGroupEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104A60A0
// Name: public: static char const __near * CDmePresetGroupEditorFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupEditorFrame::GetPanelClassName()
{
  return "CDmePresetGroupEditorFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104A60B0
// Name: public: static char const __near * CDmePresetGroupListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupListPanel::GetPanelClassName()
{
  return "CDmePresetGroupListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104A60C0
// Name: public: static char const __near * CDmePresetListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetListPanel::GetPanelClassName()
{
  return "CDmePresetListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104A60D0
// Name: IndexSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl IndexSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  int Int; // esi

  Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
  return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104A6100
// Name: public: void CDmePresetGroupEditorPanel::NotifyDataChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::NotifyDataChanged(CDmePresetGroupEditorFrame *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "PresetsChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6140
// Name: private: void CDmePresetGroupEditorPanel::SetSelectedPreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::SetSelectedPreset(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pPresetName)
{
  int i; // edi
  KeyValues *v5; // eax
  char *String; // eax

  this->m_pPresetList->ClearSelectedItems(this: this->m_pPresetList);
  for ( i = this->m_pPresetList->FirstItem(this: this->m_pPresetList);
        i != this->m_pPresetList->InvalidItemID(this: this->m_pPresetList);
        i = ((int (__thiscall *)(CDmePresetListPanel *))this->m_pPresetList->NextItem)(a1: this->m_pPresetList) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(CDmePresetListPanel *, int, int))this->m_pPresetList->GetItem)(
                        a1: this->m_pPresetList,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: &var);
    if ( _V_strcmp(s1: String, s2: pPresetName) == 0 )
      this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: i);
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A61F0
// Name: private: void CDmePresetGroupEditorPanel::SetSelectedPresetGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::SetSelectedPresetGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pPresetGroupName)
{
  int i; // edi
  KeyValues *v5; // eax
  char *String; // eax

  this->m_pPresetGroupList->ClearSelectedItems(this: this->m_pPresetGroupList);
  for ( i = this->m_pPresetGroupList->FirstItem(this: this->m_pPresetGroupList);
        i != this->m_pPresetGroupList->InvalidItemID(this: this->m_pPresetGroupList);
        i = ((int (__thiscall *)(CDmePresetGroupListPanel *))this->m_pPresetGroupList->NextItem)(a1: this->m_pPresetGroupList) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(CDmePresetGroupListPanel *, int, int))this->m_pPresetGroupList->GetItem)(
                        a1: this->m_pPresetGroupList,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: &var);
    if ( _V_strcmp(s1: String, s2: pPresetGroupName) == 0 )
      this->m_pPresetGroupList->AddSelectedItem(this: this->m_pPresetGroupList, a2: i);
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A62A0
// Name: public: virtual void CDmePresetGroupEditorPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *,bool,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::SetupFileOpenDialog(
        CDmePresetGroupEditorPanel *this,
        vgui::FileOpenDialog *pDialog,
        bool bOpenFile,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  void (__thiscall *SetTitle_2)(vgui::Frame *, const char *, bool); // edx
  char pPresetPath[260]; // [esp+8h] [ebp-104h] BYREF

  SetTitle_2 = pDialog->SetTitle_2;
  if ( bOpenFile )
    ((void (__stdcall *)(const char *, int))SetTitle_2)(a1: "Import Preset File", a2: 1);
  else
    ((void (__stdcall *)(const char *, int))SetTitle_2)(a1: "Export Preset File", a2: 1);
  if ( _V_stricmp(s1: pFileFormat, s2: "preset") != 0 )
  {
    if ( _V_stricmp(s1: pFileFormat, s2: "vfe") != 0 )
    {
      if ( _V_stricmp(s1: pFileFormat, s2: "txt") == 0 )
      {
        GetModSubdirectory(pSubDir: "expressions", pBuf: pPresetPath, nBufLen: 260);
        vgui::FileOpenDialog::SetStartDirectoryContext(
          this: pDialog,
          pStartDirContext: "preset_exportvfe",
          pDefaultDir: pPresetPath);
        vgui::FileOpenDialog::AddFilter(
          this: pDialog,
          filter: "*.*",
          filterName: "All Files (*.*)",
          bActive: false,
          pFilterInfo: nullptr);
        vgui::FileOpenDialog::AddFilter(
          this: pDialog,
          filter: "*.txt",
          filterName: "Faceposer Expression File (*.txt)",
          bActive: true,
          pFilterInfo: "txt");
      }
    }
    else
    {
      GetModSubdirectory(pSubDir: "expressions", pBuf: pPresetPath, nBufLen: 260);
      vgui::FileOpenDialog::SetStartDirectoryContext(
        this: pDialog,
        pStartDirContext: "preset_exportvfe",
        pDefaultDir: pPresetPath);
      vgui::FileOpenDialog::AddFilter(
        this: pDialog,
        filter: "*.*",
        filterName: "All Files (*.*)",
        bActive: false,
        pFilterInfo: nullptr);
      vgui::FileOpenDialog::AddFilter(
        this: pDialog,
        filter: "*.vfe",
        filterName: "Expression File (*.vfe)",
        bActive: true,
        pFilterInfo: "vfe");
    }
  }
  else
  {
    GetModSubdirectory(pSubDir: "models", pBuf: pPresetPath, nBufLen: 260);
    vgui::FileOpenDialog::SetStartDirectoryContext(
      this: pDialog,
      pStartDirContext: "preset_importexport",
      pDefaultDir: pPresetPath);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.*",
      filterName: "All Files (*.*)",
      bActive: false,
      pFilterInfo: nullptr);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.pre",
      filterName: "Preset File (*.pre)",
      bActive: true,
      pFilterInfo: "preset");
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6430
// Name: private: virtual void CDmePresetGroupEditorPanel::OnAddGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnAddGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::InputDialog *)operator new(nSize: 0x22Cu);
  if ( v2 != nullptr )
    v3 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Add Preset Group",
           prompt: "Enter name of new preset group",
           defaultValue: &var);
  else
    v3 = nullptr;
  vgui::InputDialog::SetMultiline(this: v3, state: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "OnAddGroup");
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
  }
  else
  {
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A64A0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnAddPhonemeGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnAddPhonemeGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::InputDialog *)operator new(nSize: 0x22Cu);
  if ( v2 != nullptr )
    v3 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Add Phoneme Preset Group",
           prompt: "Enter name of new preset group",
           defaultValue: "phoneme");
  else
    v3 = nullptr;
  vgui::InputDialog::SetMultiline(this: v3, state: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "OnAddPhonemeGroup");
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
  }
  else
  {
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6510
// Name: public: virtual void CDmePresetGroupListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnKeyCodeTyped(CDmePresetGroupListPanel *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE || code == KEY_BACKSPACE )
  {
    this->m_pPresetGroupPanel->OnRemoveGroup(this: this->m_pPresetGroupPanel);
  }
  else
  {
    if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    {
      goto LABEL_9;
    }
    if ( code == KEY_UP )
    {
      this->m_pPresetGroupPanel->OnMoveGroupUp(this: this->m_pPresetGroupPanel);
      return;
    }
    if ( code == KEY_DOWN )
      this->m_pPresetGroupPanel->OnMoveGroupDown(this: this->m_pPresetGroupPanel);
    else
LABEL_9:
      vgui::ListPanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A65B0
// Name: public: virtual void CDmePresetGroupListPanel::OnDroppablePanelPaint(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnDroppablePanelPaint(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist,
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *dragPanels)
{
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  Color *DropFrameColor; // eax
  Color result; // [esp+Ch] [ebp-2Ch] BYREF
  int y2; // [esp+10h] [ebp-28h] BYREF
  int h2; // [esp+14h] [ebp-24h] BYREF
  int column; // [esp+18h] [ebp-20h] BYREF
  int w2; // [esp+1Ch] [ebp-1Ch] BYREF
  int x2; // [esp+20h] [ebp-18h] BYREF
  int row; // [esp+24h] [ebp-14h] BYREF
  int h; // [esp+28h] [ebp-10h] BYREF
  int w; // [esp+2Ch] [ebp-Ch] BYREF
  int y; // [esp+30h] [ebp-8h] BYREF
  int x; // [esp+34h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  this->GetCellBounds(this, a2: row, a3: 0, a4: &x, a5: &y, a6: &w, a7: &h);
  this->GetCellBounds(this, a2: row, a3: 3, a4: &x2, a5: &y2, a6: &w2, a7: &h2);
  w = w2 + x2 - x;
  vgui::Panel::LocalToScreen(this, &x, &y);
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  DropFrameColor = vgui::Panel::GetDropFrameColor(this, &result);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v5->DrawSetColor)(a1: v4, a2: *DropFrameColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + w, a5: y + 2);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + h - 2, a4: x + w, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + 2, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + w - 2, a3: y, a4: x + w, a5: y + h);
}

//------------------------------------------------------------------------------
// Address: 0x104A6700
// Name: public: virtual void CDmePresetListPanel::OnDroppablePanelPaint(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnDroppablePanelPaint(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist,
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *dragPanels)
{
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  Color *DropFrameColor; // eax
  Color result; // [esp+Ch] [ebp-1Ch] BYREF
  int row; // [esp+10h] [ebp-18h] BYREF
  int column; // [esp+14h] [ebp-14h] BYREF
  int h; // [esp+18h] [ebp-10h] BYREF
  int w; // [esp+1Ch] [ebp-Ch] BYREF
  int y; // [esp+20h] [ebp-8h] BYREF
  int x; // [esp+24h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  this->GetCellBounds(this, a2: row, a3: column, a4: &x, a5: &y, a6: &w, a7: &h);
  vgui::Panel::LocalToScreen(this, &x, &y);
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  DropFrameColor = vgui::Panel::GetDropFrameColor(this, &result);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v5->DrawSetColor)(a1: v4, a2: *DropFrameColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + w, a5: y + 2);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + h - 2, a4: x + w, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + 2, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + w - 2, a3: y, a4: x + w, a5: y + h);
}

//------------------------------------------------------------------------------
// Address: 0x104A6820
// Name: private: virtual void CDmePresetGroupEditorFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnCommand(CDmePresetGroupEditorFrame *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "Ok") != 0 )
    vgui::Frame::OnCommand(this, command: pCommand);
  else
    this->CloseModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A68F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupEditorFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupEditorFrame::GetMessageMap(CDmePresetGroupEditorFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupEditorFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
  `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A6920
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupEditorFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupEditorFrame::GetAnimMap(CDmePresetGroupEditorFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104A6930
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupEditorFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupEditorFrame::GetKBMap(CDmePresetGroupEditorFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupEditorFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorFrame::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupEditorFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
  `CDmePresetGroupEditorFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A6960
// Name: public: char const __near * CDmePresetGroupEditorPanel::GetSelectedPresetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDmePresetGroupEditorPanel::GetSelectedPresetName(CDmePresetGroupEditorPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) == nullptr
    || this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) != 1 )
  {
    return nullptr;
  }
  v3 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
  v4 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "presetName", defaultValue: &var);
}

//------------------------------------------------------------------------------
// Address: 0x104A69D0
// Name: public: char const __near * CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(CDmePresetGroupEditorPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) == nullptr
    || this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) != 1 )
  {
    return nullptr;
  }
  v3 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
  v4 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "presetGroupName", defaultValue: &var);
}

//------------------------------------------------------------------------------
// Address: 0x104A6A40
// Name: private: bool CDmePresetGroupEditorPanel::HasDuplicatePresetName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::HasDuplicatePresetName(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetName,
        const char *pIgnorePresetName)
{
  char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v6; // eax
  vgui::MessageBox *v7; // eax
  vgui::MessageBox *v8; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName == nullptr )
    return 0;
  v6 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  if ( FindAnyPreset(pFilmClip: v6, pPresetGroupName: SelectedPresetGroupName, pPresetName) == nullptr
    || _V_strcmp(s1: pPresetName, s2: pIgnorePresetName) == 0 )
  {
    return 0;
  }
  v7 = (vgui::MessageBox *)operator new(nSize: 0x234u);
  if ( v7 != nullptr )
    v8 = vgui::MessageBox::MessageBox(
           this: v7,
           title: "#DmePresetGroupEditor_DuplicatePresetNameTitle",
           text: "#DmePresetGroupEditor_DuplicatePresetNameText",
           parent: this);
  else
    v8 = nullptr;
  v8->DoModal_2(this: v8, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104A6AE0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRenamePreset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRenamePreset(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( CDmePresetGroupEditorPanel::GetSelectedPresetName(this) != nullptr )
  {
    v2 = (vgui::InputDialog *)operator new(nSize: 0x22Cu);
    if ( v2 != nullptr )
      v3 = vgui::InputDialog::InputDialog(
             this: v2,
             parent: this,
             title: "Rename Preset",
             prompt: "Enter new name of preset",
             defaultValue: &var);
    else
      v3 = nullptr;
    vgui::InputDialog::SetMultiline(this: v3, state: false);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnRenamePreset");
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
    }
    else
    {
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6B60
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresets(CDmePresetGroupEditorPanel *this)
{
  CDmeAnimationSet *v2; // edi
  char *SelectedPresetGroupName; // eax
  CDmePresetGroup *PresetGroup; // ebx
  CPresetPickerFrame *v5; // eax
  CPresetPickerFrame *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-8h] BYREF

  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v2, pGroupName: SelectedPresetGroupName);
  if ( PresetGroup != nullptr )
  {
    v5 = (CPresetPickerFrame *)operator new(nSize: 0x224u);
    if ( v5 != nullptr )
      v6 = CPresetPickerFrame::CPresetPickerFrame(
             this: v5,
             pParent: this,
             pTitle: "Select Preset(s) to Export",
             bAllowMultiSelect: true);
    else
      v6 = nullptr;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "ExportPicked");
      CPresetPickerFrame::DoModal(this: v6, pPresetGroup: PresetGroup, bSelectAll: true, pContextKeyValues: v8);
    }
    else
    {
      CPresetPickerFrame::DoModal(this: v6, pPresetGroup: PresetGroup, bSelectAll: true, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6C20
// Name: private: virtual void CDmePresetGroupEditorPanel::OnImportPresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnImportPresets(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  vgui::FileOpenStateMachine *v4; // eax
  KeyValues *v5; // [esp-10h] [ebp-14h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ImportPresets");
  else
    v3 = nullptr;
  v5 = v3;
  v4 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::OpenFile(
    this: v4,
    pOpenFileType: "preset",
    pContextKeyValues: v5,
    pSaveFileName: nullptr,
    pSaveFileType: nullptr,
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104A6C70
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroupToVFE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroupToVFE(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroupToVFE");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: (char *)pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "vfe",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6D30
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroupToTXT(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroupToTXT(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroupToTXT");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: (char *)pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "txt",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6DF0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroups(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroup");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: (char *)pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "preset",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6EB0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnImportPresetGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnImportPresetGroups(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  vgui::FileOpenStateMachine *v4; // eax
  KeyValues *v5; // [esp-10h] [ebp-14h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ImportPresetGroup");
  else
    v3 = nullptr;
  v5 = v3;
  v4 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::OpenFile(
    this: v4,
    pOpenFileType: "preset",
    pContextKeyValues: v5,
    pSaveFileName: nullptr,
    pSaveFileType: nullptr,
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104A6F00
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRenameGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRenameGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this) != nullptr )
  {
    v2 = (vgui::InputDialog *)operator new(nSize: 0x22Cu);
    if ( v2 != nullptr )
      v3 = vgui::InputDialog::InputDialog(
             this: v2,
             parent: this,
             title: "Rename Preset Group",
             prompt: "Enter new name of preset group",
             defaultValue: &var);
    else
      v3 = nullptr;
    vgui::InputDialog::SetMultiline(this: v3, state: false);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnRenameGroup");
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
    }
    else
    {
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A6F80
// Name: public: CDmePresetGroupListPanel::CDmePresetGroupListPanel(class vgui::Panel __near *,char const __near *,class CDmePresetGroupEditorPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupListPanel *__thiscall CDmePresetGroupListPanel::CDmePresetGroupListPanel(
        CDmePresetGroupListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmePresetGroupEditorPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmePresetGroupListPanel_vtbl *)&CDmePresetGroupListPanel::`vftable';
  if ( `CDmePresetGroupListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupListPanel");
    v5->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetGroupListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupListPanel");
    v6->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetGroupListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupListPanel");
    v7->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  this->m_pPresetGroupPanel = pComboPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A7060
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupListPanel::GetMessageMap(CDmePresetGroupListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupListPanel");
  `CDmePresetGroupListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A7090
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupListPanel::GetAnimMap(CDmePresetGroupListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104A70A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupListPanel::GetKBMap(CDmePresetGroupListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupListPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupListPanel");
  `CDmePresetGroupListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A70D0
// Name: public: virtual void CDmePresetGroupListPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnCreateDragData(CDmePresetGroupListPanel *this, KeyValues *msg)
{
  char *SelectedPresetGroupName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    KeyValues::SetString(this: msg, keyName: "presetGroupName", value: SelectedPresetGroupName);
    KeyValues::SetInt(this: msg, keyName: "selfDroppable", value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A7110
// Name: public: CDmePresetListPanel::CDmePresetListPanel(class vgui::Panel __near *,char const __near *,class CDmePresetGroupEditorPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetListPanel *__thiscall CDmePresetListPanel::CDmePresetListPanel(
        CDmePresetListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmePresetGroupEditorPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmePresetListPanel_vtbl *)&CDmePresetListPanel::`vftable';
  if ( `CDmePresetListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetListPanel");
    v5->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePresetListPanel");
    v6->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetListPanel");
    v7->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  this->m_pPresetGroupPanel = pComboPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A71F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetListPanel::GetMessageMap(CDmePresetListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetListPanel");
  `CDmePresetListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A7220
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetListPanel::GetAnimMap(CDmePresetListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104A7230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetListPanel::GetKBMap(CDmePresetListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetListPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetListPanel");
  `CDmePresetListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A72B0
// Name: private: virtual void CDmePresetGroupEditorFrame::OnUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnUndo(CDmePresetGroupEditorFrame *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-8h] BYREF

  if ( g_pDataModel->CanUndo(this: g_pDataModel) )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    *(_WORD *)&guard.m_bOldValue = ((unsigned __int8 (__thiscall *)(IDataModel *, _DWORD))IsUndoEnabled)(
                                     a1: g_pDataModel,
                                     a2: 0);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDataModel->Undo(this: g_pDataModel);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A7320
// Name: private: virtual void CDmePresetGroupEditorFrame::OnRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnRedo(CDmePresetGroupEditorFrame *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-8h] BYREF

  if ( g_pDataModel->CanRedo(this: g_pDataModel) )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    *(_WORD *)&guard.m_bOldValue = ((unsigned __int8 (__thiscall *)(IDataModel *, _DWORD))IsUndoEnabled)(
                                     a1: g_pDataModel,
                                     a2: 0);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDataModel->Redo(this: g_pDataModel);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A73F0
// Name: public: virtual CDmePresetGroupEditorPanel::~CDmePresetGroupEditorPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::~CDmePresetGroupEditorPanel(CDmePresetGroupEditorPanel *this)
{
  vgui::Panel *v2; // eax

  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorPanel_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v2->MarkForDeletion(this: v2);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
      pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hFilmClip, hElement: this->m_hFilmClip.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A7460
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupEditorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupEditorPanel::GetMessageMap(CDmePresetGroupEditorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupEditorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
  `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A7490
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupEditorPanel::GetAnimMap(CDmePresetGroupEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104A74A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupEditorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupEditorPanel::GetKBMap(CDmePresetGroupEditorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupEditorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupEditorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorPanel");
  `CDmePresetGroupEditorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A74D0
// Name: private: void CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        CDmePresetGroupEditorPanel *a3@<esi>)
{
  char *SelectedPresetGroupName; // ebx
  vgui::Menu *v5; // eax
  CDragDropHelperPanel *v6; // eax
  CDmeFilmClip *v7; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // ebx
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  vgui::Panel *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // ebx
  vgui::Panel *v21; // eax
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // ebx
  vgui::Panel *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // ebx
  vgui::Panel *v28; // eax
  vgui::Menu *v29; // eax
  CDmePresetGroupEditorPanel *v30; // [esp-8h] [ebp-Ch]

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    if ( SelectedPresetGroupName != nullptr )
    {
      v5 = (vgui::Menu *)operator new(nSize: 0x420u);
      v6 = v5 != nullptr
         ? (CDragDropHelperPanel *)vgui::Menu::Menu(this: v5, parent: this, panelName: "ActionMenu")
         : nullptr;
      v30 = a3;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
        pPanel: v6);
      v7 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
      AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v7, pPresetGroupName: SelectedPresetGroupName);
      if ( AnyPresetGroup != nullptr )
      {
        if ( !AnyPresetGroup->m_bIsReadOnly.m_Storage )
        {
          if ( CDmePresetGroupEditorPanel::GetSelectedPresetName(this) != nullptr )
          {
            v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v9 != nullptr )
              v10 = KeyValues::KeyValues(this: v9, setName: "RenamePreset");
            else
              v10 = nullptr;
            v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, CDmePresetGroupEditorPanel *, int))v11->__vftable[1].PaintTraverse)(
              a1: v11,
              a2: "#DmePresetGroupEditor_RenamePreset",
              a3: v10,
              a4: this,
              a5: 0,
              a6: a3,
              a7: a2);
            v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v12 != nullptr )
              v13 = KeyValues::KeyValues(this: v12, setName: "RemovePreset");
            else
              v13 = nullptr;
            v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v14->__vftable[1].PaintTraverse)(
              a1: v14,
              a2: "#DmePresetGroupEditor_RemovePreset",
              a3: v13,
              a4: this,
              a5: 0);
            v15 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            v15->__vftable[1].DeletePanel(this: v15);
            v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v16 != nullptr )
              v17 = KeyValues::KeyValues(this: v16, setName: "MovePresetUp");
            else
              v17 = nullptr;
            v18 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v18->__vftable[1].PaintTraverse)(
              a1: v18,
              a2: "#DmePresetGroupEditor_MoveUp",
              a3: v17,
              a4: this,
              a5: 0);
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "MovePresetDown");
            else
              v20 = nullptr;
            v21 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            a2 = 0;
            v30 = this;
            v21->__vftable[1].PaintTraverse(this: v21, a2: (bool)"#DmePresetGroupEditor_MoveDown", a3: (bool)v20);
          }
          v22 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, CDmePresetGroupEditorPanel *, int))v22->__vftable[1].DeletePanel)(
            a1: v22,
            a2: v30,
            a3: a2);
          v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v23 != nullptr )
            v24 = KeyValues::KeyValues(this: v23, setName: "ImportPresets");
          else
            v24 = nullptr;
          v25 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          v25->__vftable[1].PaintTraverse(this: v25, a2: (bool)"#DmePresetGroupEditor_ImportPresets", a3: (bool)v24);
        }
        v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v26 != nullptr )
          v27 = KeyValues::KeyValues(this: v26, setName: "ExportPresets");
        else
          v27 = nullptr;
        v28 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v28->__vftable[1].PaintTraverse)(
          a1: v28,
          a2: "#DmePresetGroupEditor_ExportPresets",
          a3: v27,
          a4: this,
          a5: 0);
        v29 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::PlaceContextMenu(a1: (int)this, parent: this, menu: v29);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A7740
// Name: private: virtual void CDmePresetGroupEditorPanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::OnOpenContextMenu(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        CDmePresetGroupEditorPanel *a3@<esi>,
        KeyValues *kv)
{
  vgui::Panel *v5; // eax
  CDmePresetListPanel *Ptr; // eax
  vgui::Menu *v7; // eax
  CDragDropHelperPanel *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // ebx
  vgui::Panel *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // ebx
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  vgui::Panel *v20; // eax
  vgui::Panel *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // ebx
  vgui::Panel *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // ebx
  vgui::Panel *v31; // eax
  KeyValues *v32; // eax
  KeyValues *v33; // ebx
  vgui::Panel *v34; // eax
  CDmeFilmClip *v35; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  vgui::Panel *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // ebx
  vgui::Panel *v40; // eax
  vgui::Panel *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // ebx
  vgui::Panel *v44; // eax
  KeyValues *v45; // eax
  KeyValues *v46; // ebx
  vgui::Panel *v47; // eax
  KeyValues *v48; // eax
  KeyValues *v49; // ebx
  vgui::Panel *v50; // eax
  KeyValues *v51; // eax
  KeyValues *v52; // ebx
  vgui::Panel *v53; // eax
  vgui::Menu *v54; // eax
  char *pPresetGroupName; // [esp+10h] [ebp+8h]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v5->MarkForDeletion(this: v5);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
      pPanel: nullptr);
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    Ptr = (CDmePresetListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
    if ( Ptr == this->m_pPresetList )
    {
      CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(this, a2, a3);
      return;
    }
    if ( Ptr == (CDmePresetListPanel *)this->m_pPresetGroupList )
    {
      v7 = (vgui::Menu *)operator new(nSize: 0x420u);
      if ( v7 != nullptr )
        v8 = (CDragDropHelperPanel *)vgui::Menu::Menu(this: v7, parent: this, panelName: "ActionMenu");
      else
        v8 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
        pPanel: v8);
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "AddGroup");
      else
        v10 = nullptr;
      v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, int))v11->__vftable[1].PaintTraverse)(
        a1: v11,
        a2: "#DmePresetGroupEditor_AddGroup",
        a3: v10,
        a4: this,
        a5: 0,
        a6: a2);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "AddPhonemeGroup");
      else
        v13 = nullptr;
      v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v14->__vftable[1].PaintTraverse)(
        a1: v14,
        a2: "#DmePresetGroupEditor_AddPhonemeGroup",
        a3: v13,
        a4: this);
      pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
      if ( pPresetGroupName != nullptr )
      {
        v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v15 != nullptr )
          v16 = KeyValues::KeyValues(this: v15, setName: "RenameGroup");
        else
          v16 = nullptr;
        v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, _DWORD))v17->__vftable[1].PaintTraverse)(
          a1: v17,
          a2: "#DmePresetGroupEditor_RenameGroup",
          a3: v16,
          a4: this,
          a5: 0,
          a6: 0);
        v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v18 != nullptr )
          v19 = KeyValues::KeyValues(this: v18, setName: "RemoveGroup");
        else
          v19 = nullptr;
        v20 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v20->__vftable[1].PaintTraverse)(
          a1: v20,
          a2: "#DmePresetGroupEditor_RemoveGroup",
          a3: v19,
          a4: this,
          a5: 0);
        v21 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v21->__vftable[1].DeletePanel(this: v21);
        v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v22 != nullptr )
          v23 = KeyValues::KeyValues(this: v22, setName: "ToggleGroupVisibility");
        else
          v23 = nullptr;
        v24 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v24->__vftable[1].PaintTraverse)(
          a1: v24,
          a2: "#DmePresetGroupEditor_ToggleVisibility",
          a3: v23,
          a4: this,
          a5: 0);
        v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v25 != nullptr )
          v26 = KeyValues::KeyValues(this: v25, setName: "ToggleGroupSharing");
        else
          v26 = nullptr;
        v27 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v27->__vftable[1].PaintTraverse)(
          a1: v27,
          a2: "#DmePresetGroupEditor_ToggleSharing",
          a3: v26,
          a4: this,
          a5: 0);
        v28 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v28->__vftable[1].DeletePanel(this: v28);
        v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v29 != nullptr )
          v30 = KeyValues::KeyValues(this: v29, setName: "MoveGroupUp");
        else
          v30 = nullptr;
        v31 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v31->__vftable[1].PaintTraverse)(
          a1: v31,
          a2: "#DmePresetGroupEditor_MoveUp",
          a3: v30,
          a4: this,
          a5: 0);
        v32 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v32 != nullptr )
          v33 = KeyValues::KeyValues(this: v32, setName: "MoveGroupDown");
        else
          v33 = nullptr;
        v34 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v34->__vftable[1].PaintTraverse)(
          a1: v34,
          a2: "#DmePresetGroupEditor_MoveDown",
          a3: v33,
          a4: this);
        v35 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
        AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v35, pPresetGroupName);
        if ( AnyPresetGroup == nullptr )
          return;
        if ( !AnyPresetGroup->m_bIsReadOnly.m_Storage )
        {
          v37 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, _DWORD))v37->__vftable[1].DeletePanel)(a1: v37, a2: 0);
          v38 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v38 != nullptr )
            v39 = KeyValues::KeyValues(this: v38, setName: "RemoveDefaultControls");
          else
            v39 = nullptr;
          v40 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v40->__vftable[1].PaintTraverse)(
            a1: v40,
            a2: "#DmePresetGroupEditor_RemoveDefaultControls",
            a3: v39,
            a4: this);
        }
      }
      v41 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v41->__vftable[1].DeletePanel)(a1: v41, a2: 0);
      v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v42 != nullptr )
        v43 = KeyValues::KeyValues(this: v42, setName: "ImportPresetGroups");
      else
        v43 = nullptr;
      v44 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v44->__vftable[1].PaintTraverse)(
        a1: v44,
        a2: "#DmePresetGroupEditor_ImportPresets",
        a3: v43,
        a4: this);
      if ( pPresetGroupName != nullptr )
      {
        v45 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v45 != nullptr )
          v46 = KeyValues::KeyValues(this: v45, setName: "ExportPresetGroups");
        else
          v46 = nullptr;
        v47 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, _DWORD))v47->__vftable[1].PaintTraverse)(
          a1: v47,
          a2: "#DmePresetGroupEditor_ExportPresets",
          a3: v46,
          a4: this,
          a5: 0,
          a6: 0);
        v48 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v48 != nullptr )
          v49 = KeyValues::KeyValues(this: v48, setName: "ExportPresetGroupsToTXT");
        else
          v49 = nullptr;
        v50 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v50->__vftable[1].PaintTraverse)(
          a1: v50,
          a2: "#DmePresetGroupEditor_ExportPresetsToFaceposer",
          a3: v49,
          a4: this,
          a5: 0);
        v51 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v51 != nullptr )
          v52 = KeyValues::KeyValues(this: v51, setName: "ExportPresetGroupsToVFE");
        else
          v52 = nullptr;
        v53 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v53->__vftable[1].PaintTraverse)(
          a1: v53,
          a2: "#DmePresetGroupEditor_ExportPresetsToExpression",
          a3: v52,
          a4: this);
      }
      v54 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
      vgui::Menu::PlaceContextMenu(a1: (int)this, parent: this, menu: v54);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A7C00
// Name: private: bool CDmePresetGroupEditorPanel::HasDuplicateGroupName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::HasDuplicateGroupName(
        CDmePresetGroupEditorPanel *this,
        const char *pGroupName,
        const char *pIgnorePresetGroupName)
{
  CDmeFilmClip *v5; // eax
  vgui::MessageBox *v6; // eax
  vgui::MessageBox *v7; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) == nullptr )
    return 0;
  v5 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  if ( FindAnyPresetGroup(pFilmClip: v5, pPresetGroupName: pGroupName) == nullptr
    || _V_strcmp(s1: pGroupName, s2: pIgnorePresetGroupName) == 0 )
  {
    return 0;
  }
  v6 = (vgui::MessageBox *)operator new(nSize: 0x234u);
  if ( v6 != nullptr )
    v7 = vgui::MessageBox::MessageBox(
           this: v6,
           title: "#DmePresetGroupEditor_DuplicateNameTitle",
           text: "#DmePresetGroupEditor_DuplicateNameText",
           parent: this);
  else
    v7 = nullptr;
  v7->DoModal_2(this: v7, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104A7CB0
// Name: public: virtual bool CDmePresetGroupListPanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePresetGroupListPanel::IsDroppable(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  bool result; // al
  KeyValues *v5; // eax
  const char *v6; // edi
  CDmeFilmClip *v7; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  int column; // [esp+8h] [ebp-Ch] BYREF
  int row; // [esp+Ch] [ebp-8h] BYREF
  int x; // [esp+10h] [ebp-4h] BYREF

  result = false;
  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( this->m_pPresetGroupPanel != nullptr )
    {
      if ( KeyValues::GetString(this: v3, keyName: "presetGroupName", defaultValue: &var) != nullptr )
        return true;
      if ( KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: &var) != nullptr )
      {
        g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
        this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
        v5 = this->GetItem(this, a2: row);
        v6 = v5 != nullptr ? KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: &var) : nullptr;
        v7 = (CDmeFilmClip *)g_pDataModel->GetElement(
                               this: g_pDataModel,
                               a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
        AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v7, pPresetGroupName: v6);
        if ( AnyPresetGroup != nullptr && !AnyPresetGroup->m_bIsReadOnly.m_Storage )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A7DB0
// Name: public: virtual void CDmePresetListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnKeyCodeTyped(CDmePresetListPanel *this, ButtonCode_t code)
{
  char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v4; // eax
  CDmePresetGroup *AnyPresetGroup; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    v4 = (CDmeFilmClip *)g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
    AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v4, pPresetGroupName: SelectedPresetGroupName);
    if ( AnyPresetGroup != nullptr && !AnyPresetGroup->m_bIsReadOnly.m_Storage )
    {
      if ( code == KEY_DELETE || code == KEY_BACKSPACE )
      {
        this->m_pPresetGroupPanel->OnRemovePreset(this: this->m_pPresetGroupPanel);
        return;
      }
      if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
        || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
      {
        if ( code == KEY_UP )
        {
          this->m_pPresetGroupPanel->OnMovePresetUp(this: this->m_pPresetGroupPanel);
          return;
        }
        if ( code == KEY_DOWN )
        {
          this->m_pPresetGroupPanel->OnMovePresetDown(this: this->m_pPresetGroupPanel);
          return;
        }
      }
    }
    vgui::ListPanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A7E90
// Name: public: virtual void CDmePresetListPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnCreateDragData(CDmePresetListPanel *this, KeyValues *msg)
{
  char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v4; // eax
  char *SelectedPresetName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    v4 = (CDmeFilmClip *)g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
    if ( !FindAnyPresetGroup(pFilmClip: v4, pPresetGroupName: SelectedPresetGroupName)->m_bIsReadOnly.m_Storage )
    {
      SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this: this->m_pPresetGroupPanel);
      if ( SelectedPresetName != nullptr )
      {
        KeyValues::SetString(this: msg, keyName: "presetName", value: SelectedPresetName);
        KeyValues::SetString(this: msg, keyName: "presetGroupName", value: SelectedPresetGroupName);
        KeyValues::SetInt(this: msg, keyName: "selfDroppable", value: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A7F20
// Name: public: virtual bool CDmePresetListPanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePresetListPanel::IsDroppable(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // esi
  bool result; // al

  result = false;
  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this
      && this->m_pPresetGroupPanel != nullptr
      && KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: nullptr) != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A7FB0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnFileStateMachineFinished(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnFileStateMachineFinished(
        CDmePresetGroupEditorPanel *this,
        KeyValues *pParams)
{
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CPresetPickerFrame *v8; // eax
  CPresetPickerFrame *v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int BufferType; // eax
  CDisableUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF

  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pParams);
  Name = KeyValues::GetName(this: FirstTrueSubKey);
  if ( _V_stricmp(s1: Name, s2: "ImportPresets") == 0 )
  {
    Int = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "presets", defaultValue: -1);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v7 = v6;
    if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
    {
      if ( KeyValues::GetInt(this: pParams, keyName: "completionState", defaultValue: 0) != 0 )
      {
        v8 = (CPresetPickerFrame *)operator new(nSize: 0x224u);
        if ( v8 != nullptr )
          v9 = CPresetPickerFrame::CPresetPickerFrame(
                 this: v8,
                 pParent: this,
                 pTitle: "Select Preset(s) to Import",
                 bAllowMultiSelect: true);
        else
          v9 = nullptr;
        v9->AddActionSignalTarget_2(this: v9, a2: this);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "ImportPicked");
        else
          v11 = nullptr;
        BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
        KeyValues::SetInt(this: v11, keyName: "presets", value: BufferType);
        CPresetPickerFrame::DoModal(this: v9, pPresetGroup: v7, bSelectAll: true, pContextKeyValues: v11);
      }
      else
      {
        CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &sg);
        g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v7->m_fileId);
        CChangeUndoScopeGuard::Release(this: &sg);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A80E0
// Name: public: virtual bool CDmePresetGroupEditorPanel::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::OnWriteFileToDisk(
        CDmePresetGroupEditorPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  char *String; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v6; // eax
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // ebx
  const char *Name; // eax
  IDataModel_vtbl *v11; // esi
  int v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  DmElementHandle_t v15; // edi
  char *SelectedPresetGroupName; // esi
  CDmeTransformControl *v17; // ebx
  CDmaVar<Vector> *Position; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmeAnimationSet *v20; // eax
  CDmePresetGroup *v21; // eax
  int v22; // esi
  CDmePresetGroup *i; // edi
  char *v24; // eax
  CExpressionCalculator *Preset; // eax
  IDataModel_vtbl *v26; // esi
  int v27; // eax
  IDataModel_vtbl *v28; // esi
  int BufferType; // eax
  char pBuf[32]; // [esp+Ch] [ebp-3Ch] BYREF
  CDisableUndoScopeGuard sg; // [esp+2Ch] [ebp-1Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+34h] [ebp-14h] BYREF
  CDmaElementArray<CDmePreset> *presets; // [esp+3Ch] [ebp-Ch]
  DmElementHandle_t src; // [esp+40h] [ebp-8h] BYREF
  int nCount; // [esp+44h] [ebp-4h]
  char bOk_3; // [esp+53h] [ebp+Bh]

  src = (DmElementHandle_t)this;
  String = KeyValues::GetString(this: pContextKeyValues, keyName: "presetGroupName", defaultValue: &var);
  Int = KeyValues::GetInt(this: pContextKeyValues, keyName: "animSet", defaultValue: -1);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v7 = (CDmeAnimationSet *)v6;
  if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeAnimationSet::m_classType) )
  {
    v7 = nullptr;
LABEL_4:
    PresetGroup = nullptr;
    goto LABEL_5;
  }
  if ( String == nullptr )
    goto LABEL_4;
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: String);
LABEL_5:
  Name = KeyValues::GetName(this: pContextKeyValues);
  if ( _V_stricmp(s1: Name, s2: "ExportPresetGroup") != 0 )
  {
    v13 = KeyValues::GetName(this: pContextKeyValues);
    if ( _V_stricmp(s1: v13, s2: "ExportPresetGroupToVFE") != 0 )
    {
      v14 = KeyValues::GetName(this: pContextKeyValues);
      if ( _V_stricmp(s1: v14, s2: "ExportPresetGroupToTXT") != 0 )
      {
        nCount = KeyValues::GetInt(this: pContextKeyValues, keyName: "count", defaultValue: 0);
        if ( nCount != 0 )
        {
          v15 = src;
          SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: (CDmePresetGroupEditorPanel *)(src - 380));
          if ( SelectedPresetGroupName == nullptr )
            SelectedPresetGroupName = "root";
          CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &sg);
          v17 = (CDmeTransformControl *)CreateElement<CDmePresetGroup>(
                                          pObjectName: SelectedPresetGroupName,
                                          fileid: DMFILEID_INVALID,
                                          pObjectID: nullptr);
          Position = CDmeTransformControl::GetPosition(this: v17);
          GetElement = g_pDataModel->GetElement;
          presets = (CDmaElementArray<CDmePreset> *)Position;
          traversal.m_pFilmClip = (CDmeFilmClip *)GetElement(this: g_pDataModel, a2: *(DmElementHandle_t *)(v15 + 36));
          traversal.m_nIndex = 0;
          v20 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          v21 = CDmeAnimationSet::FindPresetGroup(this: v20, pGroupName: SelectedPresetGroupName);
          v22 = 0;
          for ( i = v21; v22 < nCount; ++v22 )
          {
            V_snprintf(pDest: pBuf, maxLen: 0x20u, pFormat: "%d", v22);
            v24 = KeyValues::GetString(this: pContextKeyValues, keyName: pBuf, defaultValue: &var);
            Preset = (CExpressionCalculator *)CDmePresetGroup::FindPreset(this: i, pPresetName: v24);
            if ( Preset != nullptr )
            {
              src = CCodecBuffer_Block::GetBufferType(this: Preset);
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                this: presets,
                &src);
            }
          }
          v26 = g_pDataModel->__vftable;
          v27 = ((int (__thiscall *)(IDataModel *, const char *, const char *, CDmeTransformControl *))g_pDataModel->GetDefaultEncoding)(
                  a1: g_pDataModel,
                  a2: pFileFormat,
                  a3: pFileFormat,
                  a4: v17);
          bOk_3 = ((int (__thiscall *)(IDataModel *, const char *, _DWORD, int))v26->SaveToFile)(
                    a1: g_pDataModel,
                    a2: pFileName,
                    a3: 0,
                    a4: v27);
          v28 = g_pDataModel->__vftable;
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
          v28->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
          CChangeUndoScopeGuard::Release(this: &sg);
          return bOk_3;
        }
        else
        {
          return 1;
        }
      }
      else
      {
        if ( PresetGroup == nullptr )
          return 0;
        return CDmePresetGroup::ExportToTXT(this: PresetGroup, pFileName, pAnimationSet: v7, pComboOp: nullptr);
      }
    }
    else
    {
      if ( PresetGroup == nullptr )
        return 0;
      return CDmePresetGroup::ExportToVFE(this: PresetGroup, pFileName, pAnimationSet: v7, pComboOp: nullptr);
    }
  }
  else
  {
    if ( PresetGroup == nullptr )
      return 0;
    v11 = g_pDataModel->__vftable;
    v12 = ((int (__thiscall *)(IDataModel *, const char *, const char *, CDmePresetGroup *))g_pDataModel->GetDefaultEncoding)(
            a1: g_pDataModel,
            a2: pFileFormat,
            a3: pFileFormat,
            a4: PresetGroup);
    return ((bool (__thiscall *)(IDataModel *, const char *, _DWORD, int))v11->SaveToFile)(
             a1: g_pDataModel,
             a2: pFileName,
             a3: 0,
             a4: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8350
// Name: private: virtual void CDmePresetGroupEditorPanel::OnPresetPickCancelled(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnPresetPickCancelled(CDmePresetGroupEditorPanel *this, KeyValues *pParams)
{
  KeyValues *Key; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDisableUndoScopeGuard sg; // [esp+4h] [ebp-8h] BYREF

  Key = KeyValues::FindKey(this: pParams, keyName: "ImportPicked", bCreate: false);
  if ( Key != nullptr )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    sg.m_bNotify = false;
    sg.m_pNotify = nullptr;
    *(_WORD *)&sg.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    Int = KeyValues::GetInt(this: Key, keyName: "presets", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      v6 = nullptr;
    g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v6->m_fileId);
    CChangeUndoScopeGuard::Release(this: &sg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8410
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRemoveDefaultControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemoveDefaultControls(CDmePresetGroupEditorPanel *this)
{
  CDmeTransformControl *PresetGroup; // eax
  CDmaVar<Vector> *Position; // esi
  float z; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  CDmElement *v7; // eax
  CDmeTransform *v8; // esi
  const Vector *v9; // esi
  float x; // eax
  DmElementArray_t *v11; // eax
  int v12; // ecx
  int v13; // edi
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // ebx
  const char *m_pAsString; // eax
  CDmElement *Control; // eax
  CDmElement *v19; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v21; // edi
  CDmaVar<float> *m_pData; // edi
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // edi
  CDmaVar<float> *v25; // edi
  CDmAttribute *v26; // eax
  CDmAttribute *v27; // esi
  CDmaVar<float> *v28; // esi
  CDmAttribute *v29; // eax
  CDmAttribute *v30; // esi
  CDmaVar<float> *v31; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-34h] BYREF
  CDmrElementArray<CDmePreset> presets; // [esp+14h] [ebp-2Ch] BYREF
  CDmrElementArray<CDmElement> controls; // [esp+1Ch] [ebp-24h] BYREF
  const char *pPresetGroupName; // [esp+24h] [ebp-1Ch]
  int v36; // [esp+28h] [ebp-18h]
  CDmeAnimationSet *pAnimSet; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  float flDefaultValue; // [esp+34h] [ebp-Ch]
  int j; // [esp+38h] [ebp-8h]
  bool bIsDefault; // [esp+3Fh] [ebp-1h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Remove Default Controls", a3: "Remove Default Controls", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Remove Default Controls", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( pAnimSet != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = (CDmeTransformControl *)CDmeAnimationSet::FindPresetGroup(
                                                this: pAnimSet,
                                                pGroupName: pPresetGroupName);
        if ( PresetGroup != nullptr )
        {
          Position = CDmeTransformControl::GetPosition(this: PresetGroup);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
          z = Position[1].m_Storage.z;
          if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
          {
            m_pStorage = nullptr;
            presets.m_pAttribute = nullptr;
            presets.m_pStorage = nullptr;
            m_Size = 0;
          }
          else
          {
            presets.m_pAttribute = (CDmAttribute *)LODWORD(Position[1].m_Storage.z);
            m_pStorage = *(DmElementArray_t **)(LODWORD(z) + 4);
            presets.m_pStorage = m_pStorage;
            m_Size = m_pStorage->m_Size;
          }
          v36 = m_Size;
          i = 0;
          if ( m_Size > 0 )
            break;
        }
LABEL_71:
        pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( pAnimSet == nullptr )
          goto LABEL_72;
      }
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[i]);
        v8 = (CDmeTransform *)v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmePreset::m_classType) )
          v8 = nullptr;
        if ( !CDmePreset::IsAnimated(this: (CDmePreset *)v8) )
        {
          v9 = CDmeTransform::GetPosition(this: v8);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
          x = v9[2].x;
          if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
          {
            v11 = nullptr;
            controls.m_pAttribute = nullptr;
            controls.m_pStorage = nullptr;
            v12 = 0;
          }
          else
          {
            controls.m_pAttribute = (CDmAttribute *)LODWORD(v9[2].x);
            v11 = *(DmElementArray_t **)(LODWORD(x) + 4);
            controls.m_pStorage = v11;
            v12 = v11->m_Size;
          }
          j = v12 - 1;
          if ( v12 - 1 >= 0 )
            break;
        }
LABEL_70:
        if ( ++i >= v36 )
          goto LABEL_71;
        m_pStorage = presets.m_pStorage;
      }
      while ( 1 )
      {
        v13 = j;
        v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v11->m_Memory.m_pMemory[j]);
        v15 = v14;
        if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmElement::m_classType) )
          v16 = v15;
        else
          v16 = nullptr;
        m_pAsString = v16->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        Control = CDmeAnimationSet::FindControl(this: pAnimSet, pControlName: m_pAsString);
        v19 = Control;
        if ( Control == nullptr )
        {
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
            this: &controls,
            elem: v13);
          goto LABEL_69;
        }
        bIsDefault = true;
        if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        Attribute = CDmElement::FindAttribute(this: Control, pAttributeName: "defaultValue");
        v21 = Attribute;
        if ( Attribute != nullptr )
        {
          if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          if ( (Attribute->m_nFlags & 0x1F) == 3 )
          {
            m_pData = (CDmaVar<float> *)Attribute->m_pData;
          }
          else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
          {
            CDmAttribute::CopyDataOut<float>(this: v21, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
            m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
          }
          else
          {
            m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
          }
        }
        else
        {
          m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
        }
        flDefaultValue = m_pData->m_Storage;
        if ( CDmElement::HasAttribute(this: v19, pAttributeName: "rightValue", type: AT_UNKNOWN) )
        {
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v23 = CDmElement::FindAttribute(this: v16, pAttributeName: "leftValue");
          v24 = v23;
          if ( v23 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v23->m_nFlags & 0x1F) == 3 )
            {
              v25 = (CDmaVar<float> *)v23->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v23) )
            {
              CDmAttribute::CopyDataOut<float>(this: v24, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v25 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v25 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v25 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue != v25->m_Storage )
            bIsDefault = false;
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v26 = CDmElement::FindAttribute(this: v16, pAttributeName: "rightValue");
          v27 = v26;
          if ( v26 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v26->m_nFlags & 0x1F) == 3 )
            {
              v28 = (CDmaVar<float> *)v26->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v26) )
            {
              CDmAttribute::CopyDataOut<float>(this: v27, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v28 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v28 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v28 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue == v28->m_Storage && bIsDefault )
            goto LABEL_68;
        }
        else
        {
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v29 = CDmElement::FindAttribute(this: v16, pAttributeName: "value");
          v30 = v29;
          if ( v29 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v29->m_nFlags & 0x1F) == 3 )
            {
              v31 = (CDmaVar<float> *)v29->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v29) )
            {
              CDmAttribute::CopyDataOut<float>(this: v30, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v31 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v31 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v31 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue == v31->m_Storage )
LABEL_68:
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
              this: &controls,
              elem: j);
        }
LABEL_69:
        if ( --j < 0 )
          goto LABEL_70;
        v11 = controls.m_pStorage;
      }
    }
LABEL_72:
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8900
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MovePresetUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8990
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MovePresetDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8A20
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveGroupUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8AB0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveGroupDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8B40
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8BD0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemovePreset";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8C60
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8CF0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "InputCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8D80
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8E10
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddPhonemeGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8EA0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RenameGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8F30
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveDefaultControls";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A8FC0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RenamePreset";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9050
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleGroupVisibility";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A90E0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleGroupSharing";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9170
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9200
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemDeselected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9290
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportPresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9320
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A93B0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseToolSystem::`vcall'{1020,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportPresetGroups";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9440
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1024,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroups";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A94D0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1028,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroupsToVFE";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9560
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1032,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroupsToTXT";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A95F0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1036,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetPicked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9680
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertySheet::`vcall'{1040,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetPickCancelled";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9710
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1044,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileStateMachineFinished";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A97A0
// Name: public: static void CDmePresetGroupEditorFrame::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePresetGroupEditorFrame::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x104A9870
// Name: public: static void CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PresetsChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9900
// Name: public: CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupEditorPanel *__thiscall CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(
        CDmePresetGroupEditorPanel *this,
        vgui::Panel *pParent,
        char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v10; // ebx
  CDmePresetGroupListPanel *v11; // eax
  CDmePresetGroupListPanel *v12; // eax
  CDmePresetListPanel *v13; // eax
  CDmePresetListPanel *v14; // eax
  vgui::FileOpenStateMachine *v15; // eax
  CDragDropHelperPanel *v16; // eax
  vgui::Panel *v17; // eax
  int _10; // [esp+10h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&vgui::IFileOpenStateMachineClient::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorPanel_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( `CDmePresetGroupEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v4->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePresetGroupEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorPanel");
    v5->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePresetGroupEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorPanel");
    v6->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(a1: (int)&_10);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(a1: (int)&_10);
  this->m_hFilmClip.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_hFileOpenStateMachine.m_iPanelID = -1;
  v7 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PresetGroupSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
  v11 = (CDmePresetGroupListPanel *)operator new(nSize: 0x254u);
  if ( v11 != nullptr )
    v12 = CDmePresetGroupListPanel::CDmePresetGroupListPanel(
            this: v11,
            pParent: Child,
            pName: "PresetGroupList",
            pComboPanel: this);
  else
    v12 = nullptr;
  this->m_pPresetGroupList = v12;
  v12->AddColumnHeader(this: v12, a2: 0, a3: "name", a4: "Preset Group Name", a5: 150, a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 1,
    a3: "visible",
    a4: "Visible",
    a5: 70,
    a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 2,
    a3: "shared",
    a4: "Shared",
    a5: 52,
    a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 3,
    a3: "readonly",
    a4: "Read Only",
    a5: 52,
    a6: 0);
  this->m_pPresetGroupList->SetSelectIndividualCells(this: this->m_pPresetGroupList, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pPresetGroupList, bState: false);
  this->m_pPresetGroupList->SetEmptyListText_2(this: this->m_pPresetGroupList, a2: "No preset groups");
  this->m_pPresetGroupList->AddActionSignalTarget_2(this: this->m_pPresetGroupList, a2: this);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 0, a3: IndexSortFunc);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 1, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 1, a3: false);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 2, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 2, a3: false);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 3, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 3, a3: false);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetGroupList->SetDropEnabled)(a1: 1, a2: 0);
  this->m_pPresetGroupList->SetSortColumn(this: this->m_pPresetGroupList, a2: 0);
  this->m_pPresetGroupList->SetDragEnabled(this: this->m_pPresetGroupList, a2: true);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetGroupList->SetDropEnabled)(a1: 1, a2: 0);
  vgui::ListPanel::SetIgnoreDoubleClick(this: this->m_pPresetGroupList, state: true);
  v13 = (CDmePresetListPanel *)operator new(nSize: 0x254u);
  if ( v13 != nullptr )
    v14 = CDmePresetListPanel::CDmePresetListPanel(this: v13, pParent: v10, pName: "PresetList", pComboPanel: this);
  else
    v14 = nullptr;
  this->m_pPresetList = v14;
  v14->AddColumnHeader(this: v14, a2: 0, a3: "name", a4: "Preset Name", a5: 150, a6: 0);
  this->m_pPresetList->SetSelectIndividualCells(this: this->m_pPresetList, a2: false);
  this->m_pPresetList->SetEmptyListText_2(this: this->m_pPresetList, a2: "No presets");
  this->m_pPresetList->AddActionSignalTarget_2(this: this->m_pPresetList, a2: this);
  this->m_pPresetList->SetSortFunc(this: this->m_pPresetList, a2: 0, a3: IndexSortFunc);
  this->m_pPresetList->SetSortColumn(this: this->m_pPresetList, a2: 0);
  this->m_pPresetList->SetDragEnabled(this: this->m_pPresetList, a2: true);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetList->SetDropEnabled)(a1: 1, a2: 0);
  vgui::ListPanel::SetIgnoreDoubleClick(this: this->m_pPresetList, state: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepresetgroupeditorpanel.res",
    dialogID: 0);
  v15 = (vgui::FileOpenStateMachine *)operator new(nSize: 0x1B0u);
  if ( v15 != nullptr )
    v16 = (CDragDropHelperPanel *)vgui::FileOpenStateMachine::FileOpenStateMachine(
                                    this: v15,
                                    pParent: this,
                                    pClient: &this->vgui::IFileOpenStateMachineClient);
  else
    v16 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenStateMachine,
    pPanel: v16);
  v17 = vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  v17->AddActionSignalTarget_2(this: v17, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A9DD0
// Name: private: void CDmePresetGroupEditorPanel::RefreshPresetNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::RefreshPresetNames(CDmePresetGroupEditorPanel *this)
{
  char *SelectedPresetName; // eax
  CDmePresetListPanel *m_pPresetList; // ecx
  char *SelectedPresetGroupName; // eax
  const char *v5; // edi
  KeyValues *v6; // esi
  CDmeFilmClip *v7; // eax
  char *m_Id; // edi
  KeyValues *v9; // eax
  int v10; // esi
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > presetNames; // [esp+4h] [ebp-1Ch] BYREF
  const char *pSelectedPresetName; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
  m_pPresetList = this->m_pPresetList;
  pSelectedPresetName = SelectedPresetName;
  m_pPresetList->RemoveAll(this: m_pPresetList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    v5 = SelectedPresetGroupName;
    v6 = nullptr;
    if ( SelectedPresetGroupName != nullptr )
    {
      memset(&presetNames, 0, sizeof(presetNames));
      if ( _V_strcmp(s1: SelectedPresetGroupName, s2: "Procedural") != 0 )
      {
        v7 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
        CollectPresetNamesForGroup(
          pFilmClip: v7,
          pPresetGroupName: v5,
          (CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
      }
      else
      {
        CollectProceduralPresetNames((CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
      }
      i = 0;
      if ( presetNames.m_Size > 0 )
      {
        while ( 1 )
        {
          m_Id = (char *)presetNames.m_Memory.m_pMemory[i].u.m_Id;
          if ( m_Id == (char *)-1 )
            m_Id = (char *)&var;
          v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v9 != nullptr )
            v6 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "name", firstValue: m_Id);
          KeyValues::SetString(this: v6, keyName: "presetName", value: m_Id);
          KeyValues::SetInt(this: v6, keyName: "index", value: i);
          v10 = this->m_pPresetList->AddItem(this: this->m_pPresetList, a2: v6, a3: 0, a4: false, a5: false);
          if ( pSelectedPresetName != nullptr && _V_strcmp(s1: pSelectedPresetName, s2: m_Id) == 0 )
            this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: v10);
          if ( ++i >= presetNames.m_Size )
            break;
          v6 = nullptr;
        }
      }
      this->m_pPresetList->SortList(this: this->m_pPresetList);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&presetNames);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A9F50
// Name: private: void CDmePresetGroupEditorPanel::PerformRenamePreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::PerformRenamePreset(
        CDmePresetGroupEditorPanel *this,
        const char *pNewPresetName)
{
  const char *SelectedPresetName; // esi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *v5; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *v7; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-1Ch] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+18h] [ebp-8h]
  const char *pPresetName; // [esp+1Ch] [ebp-4h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
    pPresetName = SelectedPresetName;
    if ( SelectedPresetName != nullptr
      && CDmePresetGroupEditorPanel::HasDuplicatePresetName(
           this,
           pPresetName: pNewPresetName,
           pIgnorePresetName: SelectedPresetName) == 0 )
    {
      StartUndo = g_pDataModel->StartUndo;
      *(_WORD *)&sg.m_bReleased = 256;
      sg.m_pNotify = nullptr;
      StartUndo(this: g_pDataModel, a2: "Rename Preset", a3: "Rename Preset", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Rename Preset", a3: 6, a4: 256);
      traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                                this: g_pDataModel,
                                                a2: this->m_hFilmClip.m_handle);
      traversal.m_nIndex = 0;
      v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( v5 != nullptr )
      {
        while ( 1 )
        {
          PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v5, pGroupName: pPresetGroupName);
          if ( PresetGroup != nullptr )
          {
            v7 = CDmePresetGroup::FindOrAddPreset(this: PresetGroup, pPresetName: SelectedPresetName);
            if ( v7 != nullptr )
            {
              g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: pNewPresetName);
              CDmAttribute::SetValue<CUtlSymbolLarge>(this: v7->m_Name.m_pAttribute, &value);
            }
          }
          v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          if ( v5 == nullptr )
            break;
          SelectedPresetName = pPresetName;
        }
      }
      CUndoScopeGuard::Release(this: &sg);
      CDmePresetGroupEditorPanel::RefreshPresetNames(this);
      CDmePresetGroupEditorPanel::NotifyDataChanged((CDmePresetGroupEditorFrame *)this);
      if ( !sg.m_bReleased )
      {
        g_pDataModel->FinishUndo(this: g_pDataModel);
        if ( sg.m_bNotify )
          g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
        if ( sg.m_pNotify != nullptr )
          g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AA0C0
// Name: public: virtual void CDmePresetGroupEditorPanel::OnRemovePreset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemovePreset(CDmePresetGroupEditorPanel *this)
{
  int v2; // eax
  int v3; // edi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // eax
  int v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-18h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-10h] BYREF
  const char *pPresetName; // [esp+14h] [ebp-8h]
  const char *pPresetGroupName; // [esp+18h] [ebp-4h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    pPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
    if ( pPresetName != nullptr )
    {
      v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
      v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
      StartUndo = g_pDataModel->StartUndo;
      *(_WORD *)&sg.m_bReleased = 256;
      sg.m_pNotify = nullptr;
      StartUndo(this: g_pDataModel, a2: "Remove Preset", a3: "Remove Preset", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Remove Preset", a3: 6, a4: 256);
      traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                                this: g_pDataModel,
                                                a2: this->m_hFilmClip.m_handle);
      traversal.m_nIndex = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pPresetGroupName);
        if ( PresetGroup != nullptr )
          CDmePresetGroup::RemovePreset(this: PresetGroup, pPresetName);
      }
      CUndoScopeGuard::Release(this: &sg);
      CDmePresetGroupEditorPanel::RefreshPresetNames(this);
      if ( v3 >= this->m_pPresetList->GetItemCount(this: this->m_pPresetList) )
        --v3;
      if ( v3 >= 0 )
      {
        v7 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3);
        this->m_pPresetList->ClearSelectedItems(this: this->m_pPresetList);
        this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: v7);
      }
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "PresetsChanged");
      else
        v9 = nullptr;
      this->PostActionSignal(this, a2: v9);
      if ( !sg.m_bReleased )
      {
        g_pDataModel->FinishUndo(this: g_pDataModel);
        if ( sg.m_bNotify )
          g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
        if ( sg.m_pNotify != nullptr )
          g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AA280
// Name: public: void CDmePresetGroupEditorPanel::MovePresetInFrontOf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetInFrontOf(
        CDmePresetGroupEditorPanel *this,
        const char *pDragPresetName,
        const char *pDropPresetName)
{
  const char *SelectedPresetGroupName; // esi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  CDmeAnimationSet *v6; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePresetGroup *v8; // esi
  CDmePreset *Preset; // edi
  CDmePreset *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+10h] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+18h] [ebp-4h]

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  pPresetGroupName = SelectedPresetGroupName;
  if ( SelectedPresetGroupName != nullptr )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    StartUndo(this: g_pDataModel, a2: "Reorder Presets", a3: "Reorder Presets", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Reorder Presets", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v6 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v6 != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v6, pGroupName: SelectedPresetGroupName);
        v8 = PresetGroup;
        if ( PresetGroup != nullptr )
        {
          Preset = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName: pDragPresetName);
          if ( Preset != nullptr )
          {
            v10 = CDmePresetGroup::FindPreset(this: v8, pPresetName: pDropPresetName);
            CDmePresetGroup::MovePresetInFrontOf(this: v8, pPreset: Preset, pInFrontOf: v10);
          }
        }
        v6 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( v6 == nullptr )
          break;
        SelectedPresetGroupName = pPresetGroupName;
      }
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this);
    CDmePresetGroupEditorPanel::SetSelectedPreset(this, a2: (int)this, pPresetName: pDragPresetName);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "PresetsChanged");
    else
      v12 = nullptr;
    this->PostActionSignal(this, a2: v12);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AA3F0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnItemDeselected(CDmePresetGroupEditorPanel *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pPresetGroupList )
    CDmePresetGroupEditorPanel::RefreshPresetNames(this);
}

//------------------------------------------------------------------------------
// Address: 0x104AA420
// Name: public: void CDmePresetGroupEditorPanel::MovePresetIntoGroup(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetIntoGroup(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetName,
        const char *pSrcGroupName,
        const char *pDstGroupName)
{
  CDmePresetGroupEditorPanel *v4; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // eax
  CDmePresetGroup *v9; // edi
  CDmePresetGroup *v10; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-1Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-Ch] BYREF
  CDmePresetGroupEditorPanel *v14; // [esp+14h] [ebp-4h]

  v4 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hFilmClip.m_handle;
  v14 = this;
  if ( (int)GetElement(this: g_pDataModel, a2: m_handle) != 0
    && pPresetName != nullptr
    && pSrcGroupName != nullptr
    && pDstGroupName != nullptr )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    StartUndo(this: g_pDataModel, a2: "Change Preset Group", a3: "Change Preset Group", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Change Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v7 != nullptr )
    {
      do
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: pSrcGroupName);
        v9 = PresetGroup;
        if ( PresetGroup != nullptr && CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName) != nullptr )
        {
          CDmePresetGroup::RemovePreset(this: v9, pPresetName);
          v10 = CDmeAnimationSet::FindOrAddPresetGroup(this: v7, pGroupName: pDstGroupName);
          CDmePresetGroup::FindOrAddPreset(this: v10, pPresetName);
        }
        v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      }
      while ( v7 != nullptr );
      v4 = v14;
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this: v4);
    CDmePresetGroupEditorPanel::NotifyDataChanged(this: (CDmePresetGroupEditorFrame *)v4);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AA580
// Name: public: virtual void CDmePresetListPanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnPanelDropped(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  int v4; // eax
  KeyValues *v5; // ebx
  char *String; // edi
  char *v7; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( msgList->m_Size != 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this
      && this->m_pPresetGroupPanel != nullptr )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
      this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
      v4 = this->GetItemIDFromRow(this, a2: row);
      v5 = this->GetItem(this, a2: v4);
      String = KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: nullptr);
      v7 = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: nullptr);
      if ( String != nullptr && v7 != nullptr )
        CDmePresetGroupEditorPanel::MovePresetInFrontOf(
          this: this->m_pPresetGroupPanel,
          pDragPresetName: String,
          pDropPresetName: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AA650
// Name: public: CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupEditorFrame *__thiscall CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(
        CDmePresetGroupEditorFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmePresetGroupEditorPanel *v7; // eax
  CDmePresetGroupEditorPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  __int128 v12; // [esp-1Ch] [ebp-34h]
  __int128 v13; // [esp-1Ch] [ebp-34h]
  __int64 v14; // [esp+10h] [ebp-8h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "DmePresetGroupEditorFrame", showTaskbarIcon: true, bPopup: true);
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&IDmNotify::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorFrame_vtbl *)&CDmePresetGroupEditorFrame::`vftable'{for `vgui::Frame'};
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&CDmePresetGroupEditorFrame::`vftable'{for `IDmNotify'};
  if ( `CDmePresetGroupEditorFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
    v4->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDmePresetGroupEditorFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorFrame");
    v5->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDmePresetGroupEditorFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
    v6->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(a1: (int)&savedregs);
  if ( `CDmePresetGroupEditorFrame::PanelKBMapFunc_undo::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v12 = (unsigned int) __thiscall CElementPropertiesTreeInternal::`vcall'{1120,{flat}};
    v14 = 0;
    `CDmePresetGroupEditorFrame::PanelKBMapFunc_undo::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v12 + 1) = 0;
    CDmePresetGroupEditorFrame::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "undo",
      defaultcode: KEY_Z,
      default_modifiers: 2,
      function: v12,
      helpstring: (unsigned int)"#undo_help",
      passive: false);
  }
  if ( `CDmePresetGroupEditorFrame::PanelKBMapFunc_redo::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v13 = (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    v14 = 0;
    `CDmePresetGroupEditorFrame::PanelKBMapFunc_redo::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v13 + 1) = 0;
    CDmePresetGroupEditorFrame::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "redo",
      defaultcode: KEY_Z,
      default_modifiers: 3,
      function: v13,
      helpstring: (unsigned int)"#redo_help",
      passive: false);
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CDmePresetGroupEditorPanel *)operator new(nSize: 0x1B8u);
  if ( v7 != nullptr )
    v8 = CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(
           this: v7,
           pParent: this,
           pName: "DmePresetGroupEditorPanel");
  else
    v8 = nullptr;
  this->m_pEditor = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "#VGui_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pOkButton = v10;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepresetgroupeditorframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: &this->IDmNotify);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104AA880
// Name: public: void CDmePresetGroupEditorPanel::RefreshAnimationSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::RefreshAnimationSet(CDmePresetGroupEditorPanel *this)
{
  CDmePresetGroupEditorPanel *v1; // edi
  char *SelectedPresetGroupName; // eax
  CDmePresetGroupListPanel *m_pPresetGroupList; // ecx
  KeyValues *v4; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmeFilmClip *v6; // eax
  bool *p_bGroupReadOnly; // edi
  char *v8; // ebx
  KeyValues *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  Color v13; // eax
  int v14; // esi
  DmElementHandle_t m_handle; // [esp-14h] [ebp-40h]
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+4h] [ebp-28h] BYREF
  const char *pSelectedPresetGroupName; // [esp+18h] [ebp-14h]
  CDmePresetGroupEditorPanel *v18; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v20; // [esp+24h] [ebp-8h]
  Color value; // [esp+28h] [ebp-4h]

  v1 = this;
  v18 = this;
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  m_pPresetGroupList = v1->m_pPresetGroupList;
  pSelectedPresetGroupName = SelectedPresetGroupName;
  m_pPresetGroupList->RemoveAll(this: m_pPresetGroupList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hFilmClip.m_handle) != nullptr )
  {
    v4 = nullptr;
    GetElement = g_pDataModel->GetElement;
    m_handle = v1->m_hFilmClip.m_handle;
    memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
    v6 = (CDmeFilmClip *)GetElement(this: g_pDataModel, a2: m_handle);
    CollectPresetGroupInfo(
      pFilmClip: v6,
      presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
      bSkipReadOnly: false,
      bSkipInvisible: false);
    i = 0;
    if ( presetGroupInfo.m_Size > 0 )
    {
      p_bGroupReadOnly = &presetGroupInfo.m_Memory.m_pMemory->bGroupReadOnly;
      do
      {
        v8 = (char *)&var;
        if ( *(_DWORD *)(p_bGroupReadOnly - 5) != -1 )
          v8 = *(char **)(p_bGroupReadOnly - 5);
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v4 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "name", firstValue: v8);
        KeyValues::SetString(this: v4, keyName: "presetGroupName", value: v8);
        v10 = "Yes";
        if ( !p_bGroupReadOnly[1] )
          v10 = "No";
        KeyValues::SetString(this: v4, keyName: "visible", value: v10);
        v11 = "Yes";
        if ( !*(p_bGroupReadOnly - 1) )
          v11 = "No";
        KeyValues::SetString(this: v4, keyName: "shared", value: v11);
        v12 = "Yes";
        if ( !*p_bGroupReadOnly )
          v12 = "No";
        KeyValues::SetString(this: v4, keyName: "readonly", value: v12);
        if ( *p_bGroupReadOnly )
        {
          value = (Color)-16776961;
          v13 = (Color)-16776961;
        }
        else
        {
          v20 = -1;
          v13 = (Color)-1;
        }
        KeyValues::SetColor(this: v4, keyName: "cellcolor", value: v13);
        KeyValues::SetInt(this: v4, keyName: "index", value: i);
        v14 = v18->m_pPresetGroupList->AddItem(this: v18->m_pPresetGroupList, a2: v4, a3: 0, a4: false, a5: false);
        if ( pSelectedPresetGroupName != nullptr && _V_strcmp(s1: pSelectedPresetGroupName, s2: v8) == 0 )
          v18->m_pPresetGroupList->AddSelectedItem(this: v18->m_pPresetGroupList, a2: v14);
        p_bGroupReadOnly += 8;
        v4 = nullptr;
        ++i;
      }
      while ( i < presetGroupInfo.m_Size );
      v1 = v18;
    }
    v1->m_pPresetGroupList->SortList(this: v1->m_pPresetGroupList);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this: v1);
    if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AAA80
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMovePresetUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMovePresetUp(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  char *v7; // eax
  char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) == 1 )
  {
    v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
    v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
    v4 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3 - 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v2);
      v6 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v4);
      String = KeyValues::GetString(this: v6, keyName: "presetName", defaultValue: &var);
      v7 = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: &var);
      CDmePresetGroupEditorPanel::MovePresetInFrontOf(this, pDragPresetName: v7, pDropPresetName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AAB30
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMovePresetDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMovePresetDown(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // ebx
  char *v7; // eax
  char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) == 1 )
  {
    v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
    v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
    v4 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3 + 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v2);
      v6 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v4);
      String = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: &var);
      v7 = KeyValues::GetString(this: v6, keyName: "presetName", defaultValue: &var);
      CDmePresetGroupEditorPanel::MovePresetInFrontOf(this, pDragPresetName: v7, pDropPresetName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AABE0
// Name: public: virtual bool CDmePresetGroupEditorPanel::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::OnReadFileFromDisk(
        CDmePresetGroupEditorPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  DmFileId_t v6; // esi
  const char *Name; // eax
  CDmElement *v9; // esi
  CDmeAnimationSet *v10; // edi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  const char *m_pAsString; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // eax
  CDmePresetGroupEditorPanel *v14; // esi
  CDmAttribute *Attribute; // eax
  int BufferType; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-20h] BYREF
  CUndoScopeGuard v18; // [esp+14h] [ebp-18h] BYREF
  CDisableUndoScopeGuard sg; // [esp+1Ch] [ebp-10h] BYREF
  CDmePresetGroupEditorPanel *v20; // [esp+24h] [ebp-8h]
  CDmElement *pRoot; // [esp+28h] [ebp-4h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v20 = this;
  sg.m_bNotify = false;
  sg.m_pNotify = nullptr;
  *(_WORD *)&sg.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v6 = g_pDataModel->RestoreFromFile(
         this: g_pDataModel,
         a2: pFileName,
         a3: nullptr,
         a4: pFileFormat,
         a5: &pRoot,
         a6: CR_FORCE_COPY,
         a7: nullptr);
  CChangeUndoScopeGuard::Release(this: &sg);
  if ( v6 == DMFILEID_INVALID )
    goto LABEL_2;
  Name = KeyValues::GetName(this: pContextKeyValues);
  if ( _V_stricmp(s1: Name, s2: "ImportPresetGroup") != 0 )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "presets");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      if ( pRoot != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pRoot);
      else
        BufferType = -1;
      KeyValues::SetInt(this: pContextKeyValues, keyName: "presets", value: BufferType);
      goto LABEL_19;
    }
LABEL_2:
    CChangeUndoScopeGuard::Release(this: &sg);
    return 0;
  }
  v9 = pRoot;
  if ( pRoot == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(
          a1: pRoot,
          a2: (CUtlSymbolLarge)CDmePresetGroup::m_classType.u.m_Id) )
  {
    goto LABEL_2;
  }
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                            this: g_pDataModel,
                                            a2: *(_DWORD *)&this->m_InternalKeyFocusTicked_register);
  traversal.m_nIndex = 0;
  v10 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  StartUndo = g_pDataModel->StartUndo;
  *(_WORD *)&v18.m_bReleased = 256;
  v18.m_pNotify = nullptr;
  StartUndo(this: g_pDataModel, a2: "Import Preset Group", a3: "Import Preset Group", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Import Preset Group", a3: 6, a4: 256);
  CDmElement::SetFileId(this: v9, fileid: v10->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  CDmeAnimationSet::RemovePresetGroup(this: v10, pPresetGroupName: m_pAsString);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v10);
  CDmaElementArrayBase<CDmePresetGroup,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: PresetGroups,
    pValue: (int)v9);
  CUndoScopeGuard::Release(this: &v18);
  v14 = v20;
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this: (CDmePresetGroupEditorPanel *)((char *)v20 - 380));
  CDmePresetGroupEditorPanel::NotifyDataChanged(this: (CDmePresetGroupEditorFrame *)&v14[-1].m_lLastDoublePressTime);
  if ( !v18.m_bReleased )
  {
    g_pDataModel->FinishUndo(this: g_pDataModel);
    if ( v18.m_bNotify )
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v18.m_pNotify != nullptr )
    {
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v18.m_pNotify);
      CChangeUndoScopeGuard::Release(this: &sg);
      return 1;
    }
  }
LABEL_19:
  CChangeUndoScopeGuard::Release(this: &sg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104AAE00
// Name: private: void CDmePresetGroupEditorPanel::ImportPresets(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::ImportPresets(
        CDmePresetGroupEditorPanel *this,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *presetNames,
        CDmePreset *pRoot)
{
  CDmePresetGroupEditorPanel *v3; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmeAnimationSet *v5; // esi
  char *SelectedPresetGroupName; // eax
  CDmePresetGroup *PresetGroup; // ebx
  CDmAttribute *Attribute; // esi
  int v9; // eax
  int v10; // edi
  int m_Size; // ebx
  CDmElement *v12; // eax
  CDmePreset *v13; // esi
  const char *m_pAsString; // eax
  const Vector *Position; // ebx
  int v16; // edi
  CDmElement *v17; // eax
  CDmElement *v18; // esi
  CDmElement *v19; // ecx
  CDmElement *v20; // esi
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-3Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-2Ch] BYREF
  CDmrElementArray<CDmePreset> srcPresets; // [esp+14h] [ebp-24h] BYREF
  CDmePresetGroupEditorPanel *v26; // [esp+1Ch] [ebp-1Ch]
  int nPresetCount; // [esp+20h] [ebp-18h]
  CDmePreset *pPreset; // [esp+24h] [ebp-14h]
  const char *pPresetName; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  DmElementHandle_t src; // [esp+30h] [ebp-8h] BYREF
  CDmePresetGroup *pPresetGroup; // [esp+34h] [ebp-4h]
  CDmePreset *pSrcPreset; // [esp+44h] [ebp+Ch]
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *pSrcPreseta; // [esp+44h] [ebp+Ch]

  v3 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hFilmClip.m_handle;
  v26 = this;
  traversal.m_pFilmClip = (CDmeFilmClip *)GetElement(this: g_pDataModel, a2: m_handle);
  traversal.m_nIndex = 0;
  v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: v3);
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v5, pGroupName: SelectedPresetGroupName);
  pPresetGroup = PresetGroup;
  if ( PresetGroup != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "presets");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      srcPresets.m_pAttribute = Attribute;
      srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      if ( srcPresets.m_pStorage->m_Size != 0 )
      {
        g_pDataModel->StartUndo(this: g_pDataModel, a2: "Import Presets", a3: "Import Presets", a4: 0);
        g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Import Presets", a3: 6, a4: 256);
        v9 = 0;
        nPresetCount = presetNames->m_Size;
        i = 0;
        if ( nPresetCount > 0 )
        {
          while ( 1 )
          {
            pPresetName = presetNames->m_Memory.m_pMemory[v9];
            v10 = 0;
            pPreset = CDmePresetGroup::FindOrAddPreset(this: PresetGroup, pPresetName);
            pSrcPreset = nullptr;
            if ( srcPresets.m_pAttribute != nullptr )
              m_Size = srcPresets.m_pStorage->m_Size;
            else
              m_Size = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[v10]);
                v13 = (CDmePreset *)v12;
                if ( v12 != nullptr && v12->IsA(this: v12, a2: CDmePreset::m_classType) )
                {
                  m_pAsString = v13->m_Name.m_Storage.u.m_pAsString;
                  if ( m_pAsString == (const char *)-1 )
                    m_pAsString = &var;
                  if ( _V_strcmp(s1: m_pAsString, s2: pPresetName) == 0 )
                    break;
                }
                if ( ++v10 >= m_Size )
                  goto LABEL_20;
              }
              pSrcPreset = v13;
            }
LABEL_20:
            Position = CDmeTransform::GetPosition(this: (CDmeTransform *)pSrcPreset);
            pSrcPreseta = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeTransform::GetPosition(this: (CDmeTransform *)pPreset);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: pSrcPreseta);
            v16 = 0;
            pPreset = (CDmePreset *)LODWORD(Position[1].x);
            if ( (int)pPreset > 0 )
            {
              do
              {
                v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(LODWORD(Position->x) + 4 * v16));
                v18 = v17;
                if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmElement::m_classType) )
                  v19 = v18;
                else
                  v19 = nullptr;
                v20 = CDmElement::CopyInternal(this: v19, depth: (const char *)1);
                CDmElement::SetFileId(this: v20, fileid: pPresetGroup->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
                if ( v20 != nullptr )
                  src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v20);
                else
                  src = DMELEMENT_HANDLE_INVALID;
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: pSrcPreseta,
                  &src);
                ++v16;
              }
              while ( v16 < (int)pPreset );
            }
            v9 = i + 1;
            i = v9;
            if ( v9 >= nPresetCount )
              break;
            PresetGroup = pPresetGroup;
          }
          v3 = v26;
        }
        CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v3);
        v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v21 != nullptr )
          v22 = KeyValues::KeyValues(this: v21, setName: "PresetsChanged");
        else
          v22 = nullptr;
        v3->PostActionSignal(this: v3, a2: v22);
        g_pDataModel->FinishUndo(this: g_pDataModel);
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AB090
// Name: private: virtual void CDmePresetGroupEditorPanel::OnPresetPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnPresetPicked(CDmePresetGroupEditorPanel *this, KeyValues *pParams)
{
  int m_Size; // esi
  KeyValues *v3; // edi
  const char **m_pMemory; // ebx
  int Int; // eax
  int v6; // edi
  const char **v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  int j; // esi
  vgui::FileOpenStateMachine *v11; // eax
  KeyValues *Key; // eax
  KeyValues *v13; // edi
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmePreset *v16; // esi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v18; // al
  IDataModel_vtbl *v19; // edx
  DmElementHandle_t v20; // eax
  CDmElement *v21; // eax
  CDmElement *v22; // esi
  char pBuf[32]; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<char const *,CUtlMemory<char const *,int> > presetNames; // [esp+2Ch] [ebp-28h] BYREF
  CChangeUndoScopeGuard v25; // [esp+40h] [ebp-14h] BYREF
  CDmePresetGroupEditorPanel *v26; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int nCount; // [esp+50h] [ebp-4h]

  m_Size = 0;
  v3 = pParams;
  v26 = this;
  m_pMemory = nullptr;
  memset(&presetNames, 0, sizeof(presetNames));
  Int = KeyValues::GetInt(this: pParams, keyName: "count", defaultValue: 0);
  nCount = Int;
  if ( Int == 0 )
  {
LABEL_27:
    CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&presetNames);
    return;
  }
  i = 0;
  if ( Int > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuf, maxLen: 0x20u, pFormat: "%d", i);
      *(_DWORD *)&v25.m_bOldValue = KeyValues::GetString(this: v3, keyName: pBuf, defaultValue: &var);
      v6 = m_Size;
      if ( m_Size + 1 > presetNames.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&presetNames,
          num: m_Size - presetNames.m_Memory.m_nAllocationCount + 1);
        m_Size = presetNames.m_Size;
        m_pMemory = presetNames.m_Memory.m_pMemory;
      }
      presetNames.m_Size = ++m_Size;
      presetNames.m_pElements = m_pMemory;
      if ( m_Size - v6 - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[v6 + 1],
          src: (unsigned __int8 *)&m_pMemory[v6],
          count: 4 * (m_Size - v6 - 1));
      v7 = &m_pMemory[v6];
      if ( v7 != nullptr )
        *v7 = *(const char **)&v25.m_bOldValue;
      v3 = pParams;
      ++i;
    }
    while ( i < nCount );
  }
  if ( KeyValues::FindKey(this: v3, keyName: "ExportPicked", bCreate: false) == nullptr )
  {
    Key = KeyValues::FindKey(this: v3, keyName: "ImportPicked", bCreate: false);
    v13 = Key;
    if ( Key != nullptr )
    {
      v14 = KeyValues::GetInt(this: Key, keyName: "presets", defaultValue: -1);
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
      v16 = (CDmePreset *)v15;
      if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
        v16 = nullptr;
      CDmePresetGroupEditorPanel::ImportPresets(this: v26, &presetNames, pRoot: v16);
      IsUndoEnabled = g_pDataModel->IsUndoEnabled;
      *(_WORD *)&v25.m_bReleased = 0;
      v25.m_pNotify = nullptr;
      v18 = IsUndoEnabled(this: g_pDataModel);
      v19 = g_pDataModel->__vftable;
      v25.m_bOldValue = v18;
      v19->SetUndoEnabled(this: g_pDataModel, a2: false);
      v20 = KeyValues::GetInt(this: v13, keyName: "presets", defaultValue: -1);
      v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: v20);
      v22 = v21;
      if ( v21 == nullptr || !v21->IsA(this: v21, a2: CDmElement::m_classType) )
        v22 = nullptr;
      g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v22->m_fileId);
      CChangeUndoScopeGuard::Release(this: &v25);
    }
    goto LABEL_27;
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "ExportPresets");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: "count", value: nCount);
  for ( j = 0; j < nCount; ++j )
  {
    V_snprintf(pDest: pBuf, maxLen: 0x20u, pFormat: "%d", j);
    KeyValues::SetString(this: v9, keyName: pBuf, value: (char *)m_pMemory[j]);
  }
  v11 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &v26->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::SaveFile(
    this: v11,
    pContextKeyValues: v9,
    pFileName: nullptr,
    pFileType: "preset",
    nFlags: 1);
  if ( presetNames.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x104AB320
// Name: private: void CDmePresetGroupEditorPanel::PerformAddGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::PerformAddGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pNewGroupName)
{
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-10h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: nullptr) == 0 )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))StartUndo)(
      a1: g_pDataModel,
      a2: "Add Preset Group",
      a3: "Add Preset Group",
      a4: 0,
      a5: a3);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Add Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      CDmeAnimationSet::FindOrAddPresetGroup(this: i, pGroupName: pNewGroupName);
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this, a2, pPresetGroupName: pNewGroupName);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
    else
      v8 = nullptr;
    this->PostActionSignal(this, a2: v8);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AB480
// Name: private: void CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pNewGroupName)
{
  CDmePresetGroupEditorPanel *v3; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmeAnimationSet *v5; // eax
  int v6; // ebx
  int i; // edi
  const char *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-118h]
  int v12; // [esp-4h] [ebp-118h]
  char pTempBuf[256]; // [esp+4h] [ebp-110h] BYREF
  CDmePresetGroup *pPresetGroup; // [esp+104h] [ebp-10h]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+108h] [ebp-Ch] BYREF
  CDmePresetGroupEditorPanel *v16; // [esp+110h] [ebp-4h]

  v3 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hFilmClip.m_handle;
  v16 = this;
  if ( (int)GetElement(this: g_pDataModel, a2: m_handle) != 0
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this: v3,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: nullptr) == 0 )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Add Phoneme Preset Group", a3: "Add Phoneme Preset Group", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Add Phoneme Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v5 != nullptr )
    {
      v12 = a2;
      do
      {
        pPresetGroup = CDmeAnimationSet::FindOrAddPresetGroup(this: v5, pGroupName: pNewGroupName);
        v6 = NumPhonemes();
        for ( i = 0; i < v6; ++i )
        {
          if ( IsStandardPhoneme(index: i) )
          {
            v8 = NameForPhonemeByIndex(index: i);
            if ( _V_stricmp(s1: v8, s2: "<sil>") == 0 )
              v8 = "silence";
            V_snprintf(pDest: pTempBuf, maxLen: 0x100u, pFormat: "p_%s", v8);
            CDmePresetGroup::FindOrAddPreset(this: pPresetGroup, pPresetName: pTempBuf);
            v3 = v16;
          }
        }
        v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      }
      while ( v5 != nullptr );
      a2 = v12;
    }
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v3);
    CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this: v3, a2, pPresetGroupName: pNewGroupName);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
    {
      v10 = KeyValues::KeyValues(this: v9, setName: "PresetsChanged");
      v3->PostActionSignal(this: v3, a2: v10);
    }
    else
    {
      v3->PostActionSignal(this: v3, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AB630
// Name: private: void CDmePresetGroupEditorPanel::PerformRenameGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::PerformRenameGroup(
        CDmePresetGroupEditorPanel *this,
        const char *pNewGroupName)
{
  char *SelectedPresetGroupName; // ebx
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+14h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+1Ch] [ebp-4h] BYREF

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName != nullptr
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: SelectedPresetGroupName) == 0 )
  {
    StartUndo = g_pDataModel->StartUndo;
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    StartUndo(this: g_pDataModel, a2: "Rename Preset Group", a3: "Rename Preset Group", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Rename Preset Group", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: SelectedPresetGroupName);
      if ( PresetGroup != nullptr )
      {
        g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: pNewGroupName);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: PresetGroup->m_Name.m_pAttribute, &value);
      }
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
    else
      v8 = nullptr;
    this->PostActionSignal(this, a2: v8);
    if ( !sg.m_bReleased )
    {
      g_pDataModel->FinishUndo(this: g_pDataModel);
      if ( sg.m_bNotify )
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      if ( sg.m_pNotify != nullptr )
        g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AB790
// Name: private: virtual void CDmePresetGroupEditorPanel::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnInputCompleted(CDmePresetGroupEditorPanel *this, KeyValues *pKeyValues)
{
  char *String; // eax
  const char *v4; // esi

  String = KeyValues::GetString(this: pKeyValues, keyName: "text", defaultValue: nullptr);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnAddGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformAddGroup(this, a2: (int)this, a3: (int)pKeyValues, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnAddPhonemeGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(this, a2: (int)this, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnRenameGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformRenameGroup(this, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnRenamePreset", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformRenamePreset(this, pNewPresetName: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AB840
// Name: public: void CDmePresetGroupEditorPanel::ToggleGroupVisibility(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::ToggleGroupVisibility(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetGroupName)
{
  const char *v2; // edi
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  v2 = pPresetGroupName;
  if ( pPresetGroupName != nullptr )
  {
    g_pDataModel->StartUndo(
      this: g_pDataModel,
      a2: "Toggle Preset Group Visibility",
      a3: "Toggle Preset Group Visibility",
      a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Toggle Preset Group Visibility", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: v2);
      if ( PresetGroup != nullptr )
      {
        HIBYTE(pPresetGroupName) = !PresetGroup->m_bIsVisible.m_Storage;
        CDmAttribute::SetValue<bool>(this: PresetGroup->m_bIsVisible.m_pAttribute, value: (bool *)&pPresetGroupName + 3);
      }
    }
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "PresetsChanged");
    else
      v7 = nullptr;
    this->PostActionSignal(this, a2: v7);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AB950
// Name: private: virtual void CDmePresetGroupEditorPanel::OnToggleGroupVisibility(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnToggleGroupVisibility(CDmePresetGroupEditorPanel *this)
{
  char *SelectedPresetGroupName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName != nullptr )
    CDmePresetGroupEditorPanel::ToggleGroupVisibility(this, pPresetGroupName: SelectedPresetGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x104AB970
// Name: private: virtual void CDmePresetGroupEditorPanel::OnToggleGroupSharing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnToggleGroupSharing(CDmePresetGroupEditorPanel *this)
{
  CDmePresetGroupEditorPanel *v1; // esi
  const char *SelectedPresetGroupName; // edi
  CDmeAnimationSet *v3; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmElement *v5; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // esi
  CDmaVar<bool> *m_pData; // esi
  CDmAttribute *v9; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmePresetGroupEditorPanel *v11; // [esp+14h] [ebp-Ch]
  const char *pPresetGroupName; // [esp+18h] [ebp-8h]
  bool value; // [esp+1Fh] [ebp-1h] BYREF

  v1 = this;
  v11 = this;
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  pPresetGroupName = SelectedPresetGroupName;
  if ( SelectedPresetGroupName != nullptr )
  {
    g_pDataModel->StartUndo(
      this: g_pDataModel,
      a2: "Toggle Preset Group Sharing",
      a3: "Toggle Preset Group Sharing",
      a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Toggle Preset Group Sharing", a3: 6, a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v3 != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: SelectedPresetGroupName);
        v5 = PresetGroup;
        if ( PresetGroup != nullptr )
        {
          if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
          }
          Attribute = CDmElement::FindAttribute(this: PresetGroup, pAttributeName: "shared");
          v7 = Attribute;
          if ( Attribute != nullptr )
          {
            if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
            }
            if ( (Attribute->m_nFlags & 0x1F) == 4 )
            {
              m_pData = (CDmaVar<bool> *)Attribute->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
            {
              CDmAttribute::CopyDataOut<bool>(this: v7, value: &`CDmAttribute::GetValue<bool>'::`7'::tempVal);
              m_pData = (CDmaVar<bool> *)&`CDmAttribute::GetValue<bool>'::`7'::tempVal;
            }
            else
            {
              m_pData = &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
            }
          }
          else
          {
            m_pData = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
          }
          if ( m_pData->m_Storage )
          {
            CDmElement::RemoveAttribute(this: v5, pAttributeName: "shared");
          }
          else
          {
            value = true;
            v9 = CDmElement::FindAttribute(this: v5, pAttributeName: "shared");
            if ( v9 != nullptr
              || (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "shared", type: AT_BOOL)) != nullptr )
            {
              CDmAttribute::SetValue<bool>(this: v9, &value);
            }
          }
        }
        v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( v3 == nullptr )
          break;
        SelectedPresetGroupName = pPresetGroupName;
      }
      v1 = v11;
    }
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v1);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104ABB10
// Name: public: virtual void CDmePresetGroupEditorPanel::OnRemoveGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemoveGroup(CDmePresetGroupEditorPanel *this)
{
  char *SelectedPresetGroupName; // eax
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  int v5; // eax
  int v6; // edi
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // eax
  CDmeAnimationSet *i; // eax
  int v9; // edi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle) != nullptr )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    pPresetGroupName = SelectedPresetGroupName;
    if ( SelectedPresetGroupName != nullptr )
    {
      if ( _V_stricmp(s1: SelectedPresetGroupName, s2: "procedural") != 0 )
      {
        v5 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
        v6 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v5);
        StartUndo = g_pDataModel->StartUndo;
        *(_WORD *)&sg.m_bReleased = 256;
        sg.m_pNotify = nullptr;
        StartUndo(this: g_pDataModel, a2: "Remove Preset Group", a3: "Remove Preset Group", a4: 0);
        g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Remove Preset Group", a3: 6, a4: 256);
        traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(
                                                  this: g_pDataModel,
                                                  a2: this->m_hFilmClip.m_handle);
        traversal.m_nIndex = 0;
        for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
              i != nullptr;
              i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
        {
          CDmeAnimationSet::RemovePresetGroup(this: i, pPresetGroupName);
        }
        CUndoScopeGuard::Release(this: &sg);
        CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
        if ( v6 >= this->m_pPresetGroupList->GetItemCount(this: this->m_pPresetGroupList) )
          --v6;
        if ( v6 >= 0 )
        {
          v9 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v6);
          this->m_pPresetGroupList->ClearSelectedItems(this: this->m_pPresetGroupList);
          this->m_pPresetGroupList->AddSelectedItem(this: this->m_pPresetGroupList, a2: v9);
        }
        CDmePresetGroupEditorPanel::NotifyDataChanged((CDmePresetGroupEditorFrame *)this);
        if ( !sg.m_bReleased )
        {
          g_pDataModel->FinishUndo(this: g_pDataModel);
          if ( sg.m_bNotify )
            g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
          if ( sg.m_pNotify != nullptr )
            g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: sg.m_pNotify);
        }
      }
      else
      {
        v3 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v3 != nullptr )
        {
          v4 = vgui::MessageBox::MessageBox(
                 this: v3,
                 title: "#DmePresetGroupEditor_CannotRemovePresetGroupTitle",
                 text: "#DmePresetGroupEditor_CannotRemovePresetGroupText",
                 parent: this);
          v4->DoModal_2(this: v4, a2: nullptr);
        }
        else
        {
          (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104ABD00
// Name: public: void CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(
        CDmePresetGroupEditorPanel *this,
        const char *pDragGroupName,
        const char *pDropGroupName)
{
  CDmeAnimationSet *i; // esi
  CDmePresetGroup *PresetGroup; // edi
  CDmePresetGroup *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Reorder Preset Groups", a3: "Reorder Preset Groups", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Reorder Preset Groups", a3: 6, a4: 256);
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pDragGroupName);
    if ( PresetGroup != nullptr )
    {
      v6 = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pDropGroupName);
      CDmeAnimationSet::MovePresetGroupInFrontOf(this: i, pPresetGroup: PresetGroup, pInFrontOf: v6);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
  CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this, a2: (int)this, pPresetGroupName: pDragGroupName);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
  else
    v8 = nullptr;
  this->PostActionSignal(this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x104ABE10
// Name: public: virtual void CDmePresetGroupListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnMouseDoublePressed(CDmePresetGroupListPanel *this, int code)
{
  int v3; // eax
  KeyValues *v4; // eax
  char *String; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( code == 107 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &code);
    this->GetCellAtPos(this, a2: x, a3: code, a4: &row, a5: &column);
    v3 = this->GetItemIDFromRow(this, a2: row);
    v4 = this->GetItem(this, a2: v3);
    String = KeyValues::GetString(this: v4, keyName: "presetGroupName", defaultValue: &var);
    CDmePresetGroupEditorPanel::ToggleGroupVisibility(this: this->m_pPresetGroupPanel, pPresetGroupName: String);
  }
  else
  {
    vgui::ListPanel::OnMouseDoublePressed(this, (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104ABEA0
// Name: public: virtual void CDmePresetGroupListPanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnPanelDropped(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  int v4; // eax
  KeyValues *v5; // eax
  char *String; // ebx
  char *v7; // eax
  char *v8; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( msgList->m_Size != 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( this->m_pPresetGroupPanel != nullptr )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
      this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
      v4 = this->GetItemIDFromRow(this, a2: row);
      v5 = this->GetItem(this, a2: v4);
      if ( v5 != nullptr )
      {
        String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: &var);
        v7 = KeyValues::GetString(this: v3, keyName: "presetGroupName", defaultValue: &var);
        if ( v7 != nullptr )
        {
          CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(
            this: this->m_pPresetGroupPanel,
            pDragGroupName: v7,
            pDropGroupName: String);
        }
        else
        {
          v8 = KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: &var);
          if ( v8 != nullptr )
            CDmePresetGroupEditorPanel::MovePresetIntoGroup(
              this: this->m_pPresetGroupPanel,
              pPresetName: v8,
              pSrcGroupName: nullptr,
              pDstGroupName: String);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104ABF90
// Name: public: virtual void CDmePresetGroupEditorFrame::NotifyDataChanged(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::NotifyDataChanged(
        CDmePresetGroupEditorFrame *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 132) + 136))(a1: (char *)this - 528) != 0
    && nNotifySource != 6 )
  {
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: *(CDmePresetGroupEditorPanel **)&this->m_OnDelete_register);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104ABFD0
// Name: public: void CDmePresetGroupEditorPanel::SetAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::SetAnimationSetClip(
        CDmePresetGroupEditorPanel *this,
        CDmeFilmClip *pFilmClip)
{
  DmElementHandle_t BufferType; // eax

  if ( pFilmClip != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pFilmClip);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeFilmClip,0>::Set(this: &this->m_hFilmClip, h: BufferType);
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
}

//------------------------------------------------------------------------------
// Address: 0x104AC010
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMoveGroupUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMoveGroupUp(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  char *v7; // eax
  char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) == 1 )
  {
    v2 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
    v3 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v2);
    v4 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v3 - 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v2);
      v6 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v4);
      String = KeyValues::GetString(this: v6, keyName: "presetGroupName", defaultValue: &var);
      v7 = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: &var);
      CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(this, pDragGroupName: v7, pDropGroupName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AC0C0
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMoveGroupDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMoveGroupDown(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // ebx
  char *v7; // eax
  char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) == 1 )
  {
    v2 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
    v3 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v2);
    v4 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v3 + 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v2);
      v6 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v4);
      String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: &var);
      v7 = KeyValues::GetString(this: v6, keyName: "presetGroupName", defaultValue: &var);
      CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(this, pDragGroupName: v7, pDropGroupName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A7390
// Name: class CDmePresetGroup __near * CreateElement<class CDmePresetGroup>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePresetGroup *__cdecl CreateElement<CDmePresetGroup>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmePresetGroup::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmePresetGroup::m_classType) )
    return (CDmePresetGroup *)v5;
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0049CBC0
// Name: public: static char const __near * CDmePresetGroupEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupEditorPanel::GetPanelClassName()
{
  return "CDmePresetGroupEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049CBD0
// Name: public: static char const __near * CDmePresetGroupEditorFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupEditorFrame::GetPanelClassName()
{
  return "CDmePresetGroupEditorFrame";
}

//------------------------------------------------------------------------------
// Address: 0x0049CBE0
// Name: public: static char const __near * CDmePresetGroupListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetGroupListPanel::GetPanelClassName()
{
  return "CDmePresetGroupListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049CBF0
// Name: public: static char const __near * CDmePresetListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePresetListPanel::GetPanelClassName()
{
  return "CDmePresetListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049CC00
// Name: IndexSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl IndexSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  int Int; // esi

  Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
  return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0049CC30
// Name: private: void CDmePresetGroupEditorPanel::SetSelectedPreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::SetSelectedPreset(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pPresetName)
{
  int i; // edi
  KeyValues *v5; // eax
  const char *String; // eax

  this->m_pPresetList->ClearSelectedItems(this: this->m_pPresetList);
  for ( i = this->m_pPresetList->FirstItem(this: this->m_pPresetList);
        i != this->m_pPresetList->InvalidItemID(this: this->m_pPresetList);
        i = ((int (__thiscall *)(CDmePresetListPanel *))this->m_pPresetList->NextItem)(a1: this->m_pPresetList) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(CDmePresetListPanel *, int, int))this->m_pPresetList->GetItem)(
                        a1: this->m_pPresetList,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: defaultValue);
    if ( _V_strcmp(s1: String, s2: pPresetName) == 0 )
      this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: i);
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049CCE0
// Name: private: void CDmePresetGroupEditorPanel::SetSelectedPresetGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::SetSelectedPresetGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pPresetGroupName)
{
  int i; // edi
  KeyValues *v5; // eax
  const char *String; // eax

  this->m_pPresetGroupList->ClearSelectedItems(this: this->m_pPresetGroupList);
  for ( i = this->m_pPresetGroupList->FirstItem(this: this->m_pPresetGroupList);
        i != this->m_pPresetGroupList->InvalidItemID(this: this->m_pPresetGroupList);
        i = ((int (__thiscall *)(CDmePresetGroupListPanel *))this->m_pPresetGroupList->NextItem)(a1: this->m_pPresetGroupList) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(CDmePresetGroupListPanel *, int, int))this->m_pPresetGroupList->GetItem)(
                        a1: this->m_pPresetGroupList,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
    if ( _V_strcmp(s1: String, s2: pPresetGroupName) == 0 )
      this->m_pPresetGroupList->AddSelectedItem(this: this->m_pPresetGroupList, a2: i);
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049CD90
// Name: public: virtual void CDmePresetGroupEditorPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *,bool,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::SetupFileOpenDialog(
        CDmePresetGroupEditorPanel *this,
        vgui::FileOpenDialog *pDialog,
        bool bOpenFile,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  void (__thiscall *SetTitle_2)(vgui::Frame *, const char *, bool); // edx
  char pPresetPath[260]; // [esp+8h] [ebp-104h] BYREF

  SetTitle_2 = pDialog->SetTitle_2;
  if ( bOpenFile )
    ((void (__stdcall *)(const char *, int))SetTitle_2)(a1: "Import Preset File", a2: 1);
  else
    ((void (__stdcall *)(const char *, int))SetTitle_2)(a1: "Export Preset File", a2: 1);
  if ( _V_stricmp(s1: pFileFormat, s2: "preset") != 0 )
  {
    if ( _V_stricmp(s1: pFileFormat, s2: "vfe") != 0 )
    {
      if ( _V_stricmp(s1: pFileFormat, s2: "txt") == 0 )
      {
        GetModSubdirectory(pSubDir: "expressions", pBuf: pPresetPath, nBufLen: 260);
        vgui::FileOpenDialog::SetStartDirectoryContext(
          this: pDialog,
          pStartDirContext: "preset_exportvfe",
          pDefaultDir: pPresetPath);
        vgui::FileOpenDialog::AddFilter(
          this: pDialog,
          filter: "*.*",
          filterName: "All Files (*.*)",
          bActive: false,
          pFilterInfo: nullptr);
        vgui::FileOpenDialog::AddFilter(
          this: pDialog,
          filter: "*.txt",
          filterName: "Faceposer Expression File (*.txt)",
          bActive: true,
          pFilterInfo: "txt");
      }
    }
    else
    {
      GetModSubdirectory(pSubDir: "expressions", pBuf: pPresetPath, nBufLen: 260);
      vgui::FileOpenDialog::SetStartDirectoryContext(
        this: pDialog,
        pStartDirContext: "preset_exportvfe",
        pDefaultDir: pPresetPath);
      vgui::FileOpenDialog::AddFilter(
        this: pDialog,
        filter: "*.*",
        filterName: "All Files (*.*)",
        bActive: false,
        pFilterInfo: nullptr);
      vgui::FileOpenDialog::AddFilter(
        this: pDialog,
        filter: "*.vfe",
        filterName: "Expression File (*.vfe)",
        bActive: true,
        pFilterInfo: "vfe");
    }
  }
  else
  {
    GetModSubdirectory(pSubDir: "models", pBuf: pPresetPath, nBufLen: 260);
    vgui::FileOpenDialog::SetStartDirectoryContext(
      this: pDialog,
      pStartDirContext: "preset_importexport",
      pDefaultDir: pPresetPath);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.*",
      filterName: "All Files (*.*)",
      bActive: false,
      pFilterInfo: nullptr);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.pre",
      filterName: "Preset File (*.pre)",
      bActive: true,
      pFilterInfo: "preset");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049CF20
// Name: private: virtual void CDmePresetGroupEditorPanel::OnAddGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnAddGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v2 != nullptr )
    v3 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Add Preset Group",
           prompt: "Enter name of new preset group",
           defaultValue: defaultValue);
  else
    v3 = nullptr;
  vgui::InputDialog::SetMultiline(this: v3, state: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "OnAddGroup");
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
  }
  else
  {
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049CF90
// Name: private: virtual void CDmePresetGroupEditorPanel::OnAddPhonemeGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnAddPhonemeGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v2 != nullptr )
    v3 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Add Phoneme Preset Group",
           prompt: "Enter name of new preset group",
           defaultValue: "phoneme");
  else
    v3 = nullptr;
  vgui::InputDialog::SetMultiline(this: v3, state: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "OnAddPhonemeGroup");
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
  }
  else
  {
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D000
// Name: public: virtual void CDmePresetGroupListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnKeyCodeTyped(CDmePresetGroupListPanel *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE || code == KEY_BACKSPACE )
  {
    this->m_pPresetGroupPanel->OnRemoveGroup(this: this->m_pPresetGroupPanel);
  }
  else
  {
    if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    {
      goto LABEL_9;
    }
    if ( code == KEY_UP )
    {
      this->m_pPresetGroupPanel->OnMoveGroupUp(this: this->m_pPresetGroupPanel);
      return;
    }
    if ( code == KEY_DOWN )
      this->m_pPresetGroupPanel->OnMoveGroupDown(this: this->m_pPresetGroupPanel);
    else
LABEL_9:
      vgui::ListPanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D0A0
// Name: public: virtual void CDmePresetGroupListPanel::OnDroppablePanelPaint(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnDroppablePanelPaint(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist,
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *dragPanels)
{
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  Color *DropFrameColor; // eax
  Color result; // [esp+Ch] [ebp-2Ch] BYREF
  int y2; // [esp+10h] [ebp-28h] BYREF
  int h2; // [esp+14h] [ebp-24h] BYREF
  int column; // [esp+18h] [ebp-20h] BYREF
  int w2; // [esp+1Ch] [ebp-1Ch] BYREF
  int x2; // [esp+20h] [ebp-18h] BYREF
  int row; // [esp+24h] [ebp-14h] BYREF
  int h; // [esp+28h] [ebp-10h] BYREF
  int w; // [esp+2Ch] [ebp-Ch] BYREF
  int y; // [esp+30h] [ebp-8h] BYREF
  int x; // [esp+34h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  this->GetCellBounds(this, a2: row, a3: 0, a4: &x, a5: &y, a6: &w, a7: &h);
  this->GetCellBounds(this, a2: row, a3: 3, a4: &x2, a5: &y2, a6: &w2, a7: &h2);
  w = w2 + x2 - x;
  vgui::Panel::LocalToScreen(this, &x, &y);
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  DropFrameColor = vgui::Panel::GetDropFrameColor(this, &result);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v5->DrawSetColor)(a1: v4, a2: *DropFrameColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + w, a5: y + 2);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + h - 2, a4: x + w, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + 2, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + w - 2, a3: y, a4: x + w, a5: y + h);
}

//------------------------------------------------------------------------------
// Address: 0x0049D1F0
// Name: public: virtual void CDmePresetListPanel::OnDroppablePanelPaint(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnDroppablePanelPaint(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist,
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *dragPanels)
{
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  Color *DropFrameColor; // eax
  Color result; // [esp+Ch] [ebp-1Ch] BYREF
  int row; // [esp+10h] [ebp-18h] BYREF
  int column; // [esp+14h] [ebp-14h] BYREF
  int h; // [esp+18h] [ebp-10h] BYREF
  int w; // [esp+1Ch] [ebp-Ch] BYREF
  int y; // [esp+20h] [ebp-8h] BYREF
  int x; // [esp+24h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  this->GetCellBounds(this, a2: row, a3: column, a4: &x, a5: &y, a6: &w, a7: &h);
  vgui::Panel::LocalToScreen(this, &x, &y);
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  DropFrameColor = vgui::Panel::GetDropFrameColor(this, &result);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v5->DrawSetColor)(a1: v4, a2: *DropFrameColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + w, a5: y + 2);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + h - 2, a4: x + w, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + 2, a5: y + h);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + w - 2, a3: y, a4: x + w, a5: y + h);
}

//------------------------------------------------------------------------------
// Address: 0x0049D310
// Name: private: virtual void CDmePresetGroupEditorFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnCommand(CDmePresetGroupEditorFrame *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "Ok") != 0 )
    vgui::Frame::OnCommand(this, command: pCommand);
  else
    this->CloseModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049D350
// Name: public: void CDmePresetGroupEditorPanel::NotifyDataChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::NotifyDataChanged(CDmePresetGroupEditorFrame *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "PresetsChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D450
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupEditorFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupEditorFrame::GetMessageMap(CDmePresetGroupEditorFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupEditorFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
  `CDmePresetGroupEditorFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049D480
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupEditorFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupEditorFrame::GetAnimMap(CDmePresetGroupEditorFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorFrame");
}

//------------------------------------------------------------------------------
// Address: 0x0049D490
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupEditorFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupEditorFrame::GetKBMap(CDmePresetGroupEditorFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupEditorFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorFrame::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupEditorFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
  `CDmePresetGroupEditorFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049D4C0
// Name: public: char const __near * CDmePresetGroupEditorPanel::GetSelectedPresetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmePresetGroupEditorPanel::GetSelectedPresetName(CDmePresetGroupEditorPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) == 0
    || this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) != 1 )
  {
    return nullptr;
  }
  v3 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
  v4 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "presetName", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0049D530
// Name: public: char const __near * CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(CDmePresetGroupEditorPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) == 0
    || this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) != 1 )
  {
    return nullptr;
  }
  v3 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
  v4 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "presetGroupName", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0049D5A0
// Name: private: bool CDmePresetGroupEditorPanel::HasDuplicatePresetName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::HasDuplicatePresetName(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetName,
        const char *pIgnorePresetName)
{
  const char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v6; // eax
  vgui::MessageBox *v7; // eax
  vgui::MessageBox *v8; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName == nullptr )
    return 0;
  v6 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hFilmClip.m_handle);
  if ( FindAnyPreset(pFilmClip: v6, pPresetGroupName: SelectedPresetGroupName, pPresetName) == nullptr
    || _V_strcmp(s1: pPresetName, s2: pIgnorePresetName) == 0 )
  {
    return 0;
  }
  v7 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v7 != nullptr )
    v8 = vgui::MessageBox::MessageBox(
           this: v7,
           title: "#DmePresetGroupEditor_DuplicatePresetNameTitle",
           text: "#DmePresetGroupEditor_DuplicatePresetNameText",
           parent: this);
  else
    v8 = nullptr;
  v8->DoModal_2(this: v8, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0049D640
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRenamePreset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRenamePreset(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( CDmePresetGroupEditorPanel::GetSelectedPresetName(this) != nullptr )
  {
    v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v2 != nullptr )
      v3 = vgui::InputDialog::InputDialog(
             this: v2,
             parent: this,
             title: "Rename Preset",
             prompt: "Enter new name of preset",
             defaultValue: defaultValue);
    else
      v3 = nullptr;
    vgui::InputDialog::SetMultiline(this: v3, state: false);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnRenamePreset");
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
    }
    else
    {
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D6C0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresets(CDmePresetGroupEditorPanel *this)
{
  CDmeAnimationSet *v2; // edi
  const char *SelectedPresetGroupName; // eax
  CDmePresetGroup *PresetGroup; // ebx
  CPresetPickerFrame *v5; // eax
  CPresetPickerFrame *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-8h] BYREF

  traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v2, pGroupName: SelectedPresetGroupName);
  if ( PresetGroup != nullptr )
  {
    v5 = (CPresetPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v5 != nullptr )
      v6 = CPresetPickerFrame::CPresetPickerFrame(
             this: v5,
             pParent: this,
             pTitle: "Select Preset(s) to Export",
             bAllowMultiSelect: true);
    else
      v6 = nullptr;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "ExportPicked");
      CPresetPickerFrame::DoModal(this: v6, pPresetGroup: PresetGroup, bSelectAll: true, pContextKeyValues: v8);
    }
    else
    {
      CPresetPickerFrame::DoModal(this: v6, pPresetGroup: PresetGroup, bSelectAll: true, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D780
// Name: private: virtual void CDmePresetGroupEditorPanel::OnImportPresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnImportPresets(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  vgui::FileOpenStateMachine *v4; // eax
  KeyValues *v5; // [esp-10h] [ebp-14h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ImportPresets");
  else
    v3 = nullptr;
  v5 = v3;
  v4 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::OpenFile(
    this: v4,
    pOpenFileType: "preset",
    pContextKeyValues: v5,
    pSaveFileName: nullptr,
    pSaveFileType: nullptr,
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0049D7D0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroupToVFE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroupToVFE(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroupToVFE");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "vfe",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D890
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroupToTXT(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroupToTXT(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroupToTXT");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "txt",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D950
// Name: private: virtual void CDmePresetGroupEditorPanel::OnExportPresetGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnExportPresetGroups(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // esi
  CExpressionCalculator *v3; // ebx
  KeyValues *v4; // eax
  int BufferType; // eax
  vgui::FileOpenStateMachine *v6; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  v3 = (CExpressionCalculator *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( CDmeAnimationSet::FindPresetGroup(this: (CDmeAnimationSet *)v3, pGroupName: pPresetGroupName) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "ExportPresetGroup");
    if ( v3 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v2, keyName: "animSet", value: BufferType);
    KeyValues::SetString(this: v2, keyName: "presetGroupName", value: pPresetGroupName);
    v6 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
    vgui::FileOpenStateMachine::SaveFile(
      this: v6,
      pContextKeyValues: v2,
      pFileName: nullptr,
      pFileType: "preset",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049DA10
// Name: private: virtual void CDmePresetGroupEditorPanel::OnImportPresetGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnImportPresetGroups(CDmePresetGroupEditorPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  vgui::FileOpenStateMachine *v4; // eax
  KeyValues *v5; // [esp-10h] [ebp-14h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ImportPresetGroup");
  else
    v3 = nullptr;
  v5 = v3;
  v4 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::OpenFile(
    this: v4,
    pOpenFileType: "preset",
    pContextKeyValues: v5,
    pSaveFileName: nullptr,
    pSaveFileType: nullptr,
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0049DA60
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRenameGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRenameGroup(CDmePresetGroupEditorPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this) != nullptr )
  {
    v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v2 != nullptr )
      v3 = vgui::InputDialog::InputDialog(
             this: v2,
             parent: this,
             title: "Rename Preset Group",
             prompt: "Enter new name of preset group",
             defaultValue: defaultValue);
    else
      v3 = nullptr;
    vgui::InputDialog::SetMultiline(this: v3, state: false);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnRenameGroup");
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
    }
    else
    {
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049DAE0
// Name: public: CDmePresetGroupListPanel::CDmePresetGroupListPanel(class vgui::Panel __near *,char const __near *,class CDmePresetGroupEditorPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupListPanel *__thiscall CDmePresetGroupListPanel::CDmePresetGroupListPanel(
        CDmePresetGroupListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmePresetGroupEditorPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmePresetGroupListPanel_vtbl *)&CDmePresetGroupListPanel::`vftable';
  if ( `CDmePresetGroupListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupListPanel");
    v5->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetGroupListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupListPanel");
    v6->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetGroupListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupListPanel");
    v7->pfnClassName = CDmePresetGroupListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  this->m_pPresetGroupPanel = pComboPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049DBC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupListPanel::GetMessageMap(CDmePresetGroupListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupListPanel");
  `CDmePresetGroupListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049DBF0
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupListPanel::GetAnimMap(CDmePresetGroupListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049DC00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupListPanel::GetKBMap(CDmePresetGroupListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupListPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupListPanel");
  `CDmePresetGroupListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049DC30
// Name: public: virtual void CDmePresetGroupListPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnCreateDragData(CDmePresetGroupListPanel *this, KeyValues *msg)
{
  const char *SelectedPresetGroupName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    KeyValues::SetString(this: msg, keyName: "presetGroupName", value: SelectedPresetGroupName);
    KeyValues::SetInt(this: msg, keyName: "selfDroppable", value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049DC70
// Name: public: CDmePresetListPanel::CDmePresetListPanel(class vgui::Panel __near *,char const __near *,class CDmePresetGroupEditorPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetListPanel *__thiscall CDmePresetListPanel::CDmePresetListPanel(
        CDmePresetListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmePresetGroupEditorPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmePresetListPanel_vtbl *)&CDmePresetListPanel::`vftable';
  if ( `CDmePresetListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetListPanel");
    v5->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmePresetListPanel");
    v6->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmePresetListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetListPanel");
    v7->pfnClassName = CDmePresetListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  this->m_pPresetGroupPanel = pComboPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049DD50
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetListPanel::GetMessageMap(CDmePresetListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetListPanel");
  `CDmePresetListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049DD80
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetListPanel::GetAnimMap(CDmePresetListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049DD90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetListPanel::GetKBMap(CDmePresetListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetListPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetListPanel");
  `CDmePresetListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049DE10
// Name: private: virtual void CDmePresetGroupEditorFrame::OnUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnUndo(CDmePresetGroupEditorFrame *this)
{
  unsigned __int8 (__thiscall *v1)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-8h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 248))(a1: g_pDataModel.u) != 0 )
  {
    v1 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 236);
    guard.m_bNotify = false;
    *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD, _DWORD))v1)(
                                     a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                     a2: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 280))(a1: g_pDataModel.u);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049DE80
// Name: private: virtual void CDmePresetGroupEditorFrame::OnRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::OnRedo(CDmePresetGroupEditorFrame *this)
{
  unsigned __int8 (__thiscall *v1)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-8h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 252))(a1: g_pDataModel.u) != 0 )
  {
    v1 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 236);
    guard.m_bNotify = false;
    *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD, _DWORD))v1)(
                                     a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                     a2: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 284))(a1: g_pDataModel.u);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049DF50
// Name: public: virtual CDmePresetGroupEditorPanel::~CDmePresetGroupEditorPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::~CDmePresetGroupEditorPanel(CDmePresetGroupEditorPanel *this)
{
  vgui::Panel *v2; // eax

  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorPanel_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v2->MarkForDeletion(this: v2);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(this: &this->m_hFilmClip, hElement: this->m_hFilmClip.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049DFC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePresetGroupEditorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePresetGroupEditorPanel::GetMessageMap(CDmePresetGroupEditorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePresetGroupEditorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::s_pMap;
  `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
  `CDmePresetGroupEditorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049DFF0
// Name: public: virtual struct PanelAnimationMap __near * CDmePresetGroupEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePresetGroupEditorPanel::GetAnimMap(CDmePresetGroupEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049E000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePresetGroupEditorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePresetGroupEditorPanel::GetKBMap(CDmePresetGroupEditorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePresetGroupEditorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePresetGroupEditorPanel::GetKBMap'::`2'::s_pMap;
  `CDmePresetGroupEditorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorPanel");
  `CDmePresetGroupEditorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049E030
// Name: private: void CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        CDmePresetGroupEditorPanel *a3@<esi>)
{
  const char *SelectedPresetGroupName; // ebx
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax
  CDmeFilmClip *v7; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // ebx
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  vgui::Panel *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // ebx
  vgui::Panel *v21; // eax
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // ebx
  vgui::Panel *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // ebx
  vgui::Panel *v28; // eax
  vgui::Menu *v29; // eax
  CDmePresetGroupEditorPanel *v30; // [esp-8h] [ebp-Ch]

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) != 0 )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    if ( SelectedPresetGroupName != nullptr )
    {
      v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      v6 = v5 != nullptr ? vgui::Menu::Menu(this: v5, parent: this, panelName: "ActionMenu") : nullptr;
      v30 = a3;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v6);
      v7 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_hFilmClip.m_handle);
      AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v7, pPresetGroupName: SelectedPresetGroupName);
      if ( AnyPresetGroup != nullptr )
      {
        if ( !AnyPresetGroup->m_bIsReadOnly.m_Storage )
        {
          if ( CDmePresetGroupEditorPanel::GetSelectedPresetName(this) != nullptr )
          {
            v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v9 != nullptr )
              v10 = KeyValues::KeyValues(this: v9, setName: "RenamePreset");
            else
              v10 = nullptr;
            v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, CDmePresetGroupEditorPanel *, int))v11->__vftable[1].PaintTraverse)(
              a1: v11,
              a2: "#DmePresetGroupEditor_RenamePreset",
              a3: v10,
              a4: this,
              a5: 0,
              a6: a3,
              a7: a2);
            v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v12 != nullptr )
              v13 = KeyValues::KeyValues(this: v12, setName: "RemovePreset");
            else
              v13 = nullptr;
            v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v14->__vftable[1].PaintTraverse)(
              a1: v14,
              a2: "#DmePresetGroupEditor_RemovePreset",
              a3: v13,
              a4: this,
              a5: 0);
            v15 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            v15->__vftable[1].DeletePanel(this: v15);
            v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v16 != nullptr )
              v17 = KeyValues::KeyValues(this: v16, setName: "MovePresetUp");
            else
              v17 = nullptr;
            v18 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v18->__vftable[1].PaintTraverse)(
              a1: v18,
              a2: "#DmePresetGroupEditor_MoveUp",
              a3: v17,
              a4: this,
              a5: 0);
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "MovePresetDown");
            else
              v20 = nullptr;
            v21 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            a2 = 0;
            v30 = this;
            v21->__vftable[1].PaintTraverse(this: v21, a2: (bool)"#DmePresetGroupEditor_MoveDown", a3: (bool)v20);
          }
          v22 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, CDmePresetGroupEditorPanel *, int))v22->__vftable[1].DeletePanel)(
            a1: v22,
            a2: v30,
            a3: a2);
          v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v23 != nullptr )
            v24 = KeyValues::KeyValues(this: v23, setName: "ImportPresets");
          else
            v24 = nullptr;
          v25 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          v25->__vftable[1].PaintTraverse(this: v25, a2: (bool)"#DmePresetGroupEditor_ImportPresets", a3: (bool)v24);
        }
        v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v26 != nullptr )
          v27 = KeyValues::KeyValues(this: v26, setName: "ExportPresets");
        else
          v27 = nullptr;
        v28 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v28->__vftable[1].PaintTraverse)(
          a1: v28,
          a2: "#DmePresetGroupEditor_ExportPresets",
          a3: v27,
          a4: this,
          a5: 0);
        v29 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::PlaceContextMenu(parent: this, menu: v29);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049E2A0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::OnOpenContextMenu(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        CDmePresetGroupEditorPanel *a3@<esi>,
        KeyValues *kv)
{
  vgui::Panel *v5; // eax
  CDmePresetListPanel *Ptr; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // ebx
  vgui::Panel *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // ebx
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  vgui::Panel *v20; // eax
  vgui::Panel *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // ebx
  vgui::Panel *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // ebx
  vgui::Panel *v31; // eax
  KeyValues *v32; // eax
  KeyValues *v33; // ebx
  vgui::Panel *v34; // eax
  CDmeFilmClip *v35; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  vgui::Panel *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // ebx
  vgui::Panel *v40; // eax
  vgui::Panel *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // ebx
  vgui::Panel *v44; // eax
  KeyValues *v45; // eax
  KeyValues *v46; // ebx
  vgui::Panel *v47; // eax
  KeyValues *v48; // eax
  KeyValues *v49; // ebx
  vgui::Panel *v50; // eax
  KeyValues *v51; // eax
  KeyValues *v52; // ebx
  vgui::Panel *v53; // eax
  vgui::Menu *v54; // eax
  const char *pPresetGroupName; // [esp+10h] [ebp+8h]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v5->MarkForDeletion(this: v5);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) != 0 )
  {
    Ptr = (CDmePresetListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
    if ( Ptr == this->m_pPresetList )
    {
      CDmePresetGroupEditorPanel::OnOpenPresetContextMenu(this, a2, a3);
      return;
    }
    if ( Ptr == (CDmePresetListPanel *)this->m_pPresetGroupList )
    {
      v7 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      if ( v7 != nullptr )
        v8 = vgui::Menu::Menu(this: v7, parent: this, panelName: "ActionMenu");
      else
        v8 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v8);
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "AddGroup");
      else
        v10 = nullptr;
      v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, int))v11->__vftable[1].PaintTraverse)(
        a1: v11,
        a2: "#DmePresetGroupEditor_AddGroup",
        a3: v10,
        a4: this,
        a5: 0,
        a6: a2);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "AddPhonemeGroup");
      else
        v13 = nullptr;
      v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v14->__vftable[1].PaintTraverse)(
        a1: v14,
        a2: "#DmePresetGroupEditor_AddPhonemeGroup",
        a3: v13,
        a4: this);
      pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
      if ( pPresetGroupName != nullptr )
      {
        v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v15 != nullptr )
          v16 = KeyValues::KeyValues(this: v15, setName: "RenameGroup");
        else
          v16 = nullptr;
        v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, _DWORD))v17->__vftable[1].PaintTraverse)(
          a1: v17,
          a2: "#DmePresetGroupEditor_RenameGroup",
          a3: v16,
          a4: this,
          a5: 0,
          a6: 0);
        v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v18 != nullptr )
          v19 = KeyValues::KeyValues(this: v18, setName: "RemoveGroup");
        else
          v19 = nullptr;
        v20 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v20->__vftable[1].PaintTraverse)(
          a1: v20,
          a2: "#DmePresetGroupEditor_RemoveGroup",
          a3: v19,
          a4: this,
          a5: 0);
        v21 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v21->__vftable[1].DeletePanel(this: v21);
        v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v22 != nullptr )
          v23 = KeyValues::KeyValues(this: v22, setName: "ToggleGroupVisibility");
        else
          v23 = nullptr;
        v24 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v24->__vftable[1].PaintTraverse)(
          a1: v24,
          a2: "#DmePresetGroupEditor_ToggleVisibility",
          a3: v23,
          a4: this,
          a5: 0);
        v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v25 != nullptr )
          v26 = KeyValues::KeyValues(this: v25, setName: "ToggleGroupSharing");
        else
          v26 = nullptr;
        v27 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v27->__vftable[1].PaintTraverse)(
          a1: v27,
          a2: "#DmePresetGroupEditor_ToggleSharing",
          a3: v26,
          a4: this,
          a5: 0);
        v28 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v28->__vftable[1].DeletePanel(this: v28);
        v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v29 != nullptr )
          v30 = KeyValues::KeyValues(this: v29, setName: "MoveGroupUp");
        else
          v30 = nullptr;
        v31 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v31->__vftable[1].PaintTraverse)(
          a1: v31,
          a2: "#DmePresetGroupEditor_MoveUp",
          a3: v30,
          a4: this,
          a5: 0);
        v32 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v32 != nullptr )
          v33 = KeyValues::KeyValues(this: v32, setName: "MoveGroupDown");
        else
          v33 = nullptr;
        v34 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v34->__vftable[1].PaintTraverse)(
          a1: v34,
          a2: "#DmePresetGroupEditor_MoveDown",
          a3: v33,
          a4: this);
        v35 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                a1: g_pDataModel.u,
                                a2: this->m_hFilmClip.m_handle);
        AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v35, pPresetGroupName);
        if ( AnyPresetGroup == nullptr )
          return;
        if ( !AnyPresetGroup->m_bIsReadOnly.m_Storage )
        {
          v37 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, _DWORD))v37->__vftable[1].DeletePanel)(a1: v37, a2: 0);
          v38 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v38 != nullptr )
            v39 = KeyValues::KeyValues(this: v38, setName: "RemoveDefaultControls");
          else
            v39 = nullptr;
          v40 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v40->__vftable[1].PaintTraverse)(
            a1: v40,
            a2: "#DmePresetGroupEditor_RemoveDefaultControls",
            a3: v39,
            a4: this);
        }
      }
      v41 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v41->__vftable[1].DeletePanel)(a1: v41, a2: 0);
      v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v42 != nullptr )
        v43 = KeyValues::KeyValues(this: v42, setName: "ImportPresetGroups");
      else
        v43 = nullptr;
      v44 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v44->__vftable[1].PaintTraverse)(
        a1: v44,
        a2: "#DmePresetGroupEditor_ImportPresets",
        a3: v43,
        a4: this);
      if ( pPresetGroupName != nullptr )
      {
        v45 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v45 != nullptr )
          v46 = KeyValues::KeyValues(this: v45, setName: "ExportPresetGroups");
        else
          v46 = nullptr;
        v47 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD, _DWORD))v47->__vftable[1].PaintTraverse)(
          a1: v47,
          a2: "#DmePresetGroupEditor_ExportPresets",
          a3: v46,
          a4: this,
          a5: 0,
          a6: 0);
        v48 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v48 != nullptr )
          v49 = KeyValues::KeyValues(this: v48, setName: "ExportPresetGroupsToTXT");
        else
          v49 = nullptr;
        v50 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *, _DWORD))v50->__vftable[1].PaintTraverse)(
          a1: v50,
          a2: "#DmePresetGroupEditor_ExportPresetsToFaceposer",
          a3: v49,
          a4: this,
          a5: 0);
        v51 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v51 != nullptr )
          v52 = KeyValues::KeyValues(this: v51, setName: "ExportPresetGroupsToVFE");
        else
          v52 = nullptr;
        v53 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmePresetGroupEditorPanel *))v53->__vftable[1].PaintTraverse)(
          a1: v53,
          a2: "#DmePresetGroupEditor_ExportPresetsToExpression",
          a3: v52,
          a4: this);
      }
      v54 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
      vgui::Menu::PlaceContextMenu(parent: this, menu: v54);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049E760
// Name: private: bool CDmePresetGroupEditorPanel::HasDuplicateGroupName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::HasDuplicateGroupName(
        CDmePresetGroupEditorPanel *this,
        const char *pGroupName,
        const char *pIgnorePresetGroupName)
{
  CDmeFilmClip *v5; // eax
  vgui::MessageBox *v6; // eax
  vgui::MessageBox *v7; // eax

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) == 0 )
    return 0;
  v5 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hFilmClip.m_handle);
  if ( FindAnyPresetGroup(pFilmClip: v5, pPresetGroupName: pGroupName) == nullptr
    || _V_strcmp(s1: pGroupName, s2: pIgnorePresetGroupName) == 0 )
  {
    return 0;
  }
  v6 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v6 != nullptr )
    v7 = vgui::MessageBox::MessageBox(
           this: v6,
           title: "#DmePresetGroupEditor_DuplicateNameTitle",
           text: "#DmePresetGroupEditor_DuplicateNameText",
           parent: this);
  else
    v7 = nullptr;
  v7->DoModal_2(this: v7, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E810
// Name: public: virtual bool CDmePresetGroupListPanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePresetGroupListPanel::IsDroppable(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  bool result; // al
  KeyValues *v5; // eax
  const char *v6; // edi
  CDmeFilmClip *v7; // eax
  CDmePresetGroup *AnyPresetGroup; // eax
  int column; // [esp+8h] [ebp-Ch] BYREF
  int row; // [esp+Ch] [ebp-8h] BYREF
  int x; // [esp+10h] [ebp-4h] BYREF

  result = false;
  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( this->m_pPresetGroupPanel != nullptr )
    {
      if ( KeyValues::GetString(this: v3, keyName: "presetGroupName", defaultValue: defaultValue) != nullptr )
        return true;
      if ( KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: defaultValue) != nullptr )
      {
        g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
        this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
        v5 = this->GetItem(this, a2: row);
        v6 = v5 != nullptr
           ? KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue)
           : nullptr;
        v7 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                               a1: g_pDataModel.u,
                               a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
        AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v7, pPresetGroupName: v6);
        if ( AnyPresetGroup != nullptr && !AnyPresetGroup->m_bIsReadOnly.m_Storage )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049E910
// Name: public: virtual void CDmePresetListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnKeyCodeTyped(CDmePresetListPanel *this, ButtonCode_t code)
{
  const char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v4; // eax
  CDmePresetGroup *AnyPresetGroup; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    v4 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
    AnyPresetGroup = FindAnyPresetGroup(pFilmClip: v4, pPresetGroupName: SelectedPresetGroupName);
    if ( AnyPresetGroup != nullptr && !AnyPresetGroup->m_bIsReadOnly.m_Storage )
    {
      if ( code == KEY_DELETE || code == KEY_BACKSPACE )
      {
        this->m_pPresetGroupPanel->OnRemovePreset(this: this->m_pPresetGroupPanel);
        return;
      }
      if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
        || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
      {
        if ( code == KEY_UP )
        {
          this->m_pPresetGroupPanel->OnMovePresetUp(this: this->m_pPresetGroupPanel);
          return;
        }
        if ( code == KEY_DOWN )
        {
          this->m_pPresetGroupPanel->OnMovePresetDown(this: this->m_pPresetGroupPanel);
          return;
        }
      }
    }
    vgui::ListPanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049E9F0
// Name: public: virtual void CDmePresetListPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnCreateDragData(CDmePresetListPanel *this, KeyValues *msg)
{
  const char *SelectedPresetGroupName; // edi
  CDmeFilmClip *v4; // eax
  const char *SelectedPresetName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: this->m_pPresetGroupPanel);
  if ( SelectedPresetGroupName != nullptr )
  {
    v4 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_pPresetGroupPanel->m_hFilmClip.m_handle);
    if ( !FindAnyPresetGroup(pFilmClip: v4, pPresetGroupName: SelectedPresetGroupName)->m_bIsReadOnly.m_Storage )
    {
      SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this: this->m_pPresetGroupPanel);
      if ( SelectedPresetName != nullptr )
      {
        KeyValues::SetString(this: msg, keyName: "presetName", value: SelectedPresetName);
        KeyValues::SetString(this: msg, keyName: "presetGroupName", value: SelectedPresetGroupName);
        KeyValues::SetInt(this: msg, keyName: "selfDroppable", value: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049EA80
// Name: public: virtual bool CDmePresetListPanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePresetListPanel::IsDroppable(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // esi
  bool result; // al

  result = false;
  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this
      && this->m_pPresetGroupPanel != nullptr
      && KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: nullptr) != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049EB10
// Name: private: virtual void CDmePresetGroupEditorPanel::OnFileStateMachineFinished(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnFileStateMachineFinished(
        CDmePresetGroupEditorPanel *this,
        KeyValues *pParams)
{
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  int Int; // eax
  int v6; // eax
  CExpressionCalculator *v7; // esi
  CPresetPickerFrame *v8; // eax
  CPresetPickerFrame *v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int BufferType; // eax
  CDisableUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF

  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pParams);
  Name = KeyValues::GetName(this: FirstTrueSubKey);
  if ( _V_stricmp(s1: Name, s2: "ImportPresets") == 0 )
  {
    Int = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "presets", defaultValue: -1);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: Int);
    v7 = (CExpressionCalculator *)v6;
    if ( v6 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmElement::m_classType.u) != 0 )
    {
      if ( KeyValues::GetInt(this: pParams, keyName: "completionState", defaultValue: 0) != 0 )
      {
        v8 = (CPresetPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
        if ( v8 != nullptr )
          v9 = CPresetPickerFrame::CPresetPickerFrame(
                 this: v8,
                 pParent: this,
                 pTitle: "Select Preset(s) to Import",
                 bAllowMultiSelect: true);
        else
          v9 = nullptr;
        v9->AddActionSignalTarget_2(this: v9, a2: this);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "ImportPicked");
        else
          v11 = nullptr;
        BufferType = CCodecBuffer_Block::GetBufferType(this: v7);
        KeyValues::SetInt(this: v11, keyName: "presets", value: BufferType);
        CPresetPickerFrame::DoModal(this: v9, pPresetGroup: (CDmElement *)v7, bSelectAll: true, pContextKeyValues: v11);
      }
      else
      {
        CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &sg);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, float *))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
          a1: g_pDataModel.u,
          a2: v7->m_stack.m_Memory.m_pMemory);
        CChangeUndoScopeGuard::Release(this: &sg);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049EC40
// Name: public: virtual bool CDmePresetGroupEditorPanel::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::OnWriteFileToDisk(
        CDmePresetGroupEditorPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  const char *String; // ebx
  int Int; // eax
  int v6; // eax
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // ebx
  const char *Name; // eax
  int v11; // esi
  int v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  DmElementHandle_t v15; // edi
  const char *SelectedPresetGroupName; // esi
  CDmeTransformControl *v17; // ebx
  CDmaElementArray<CDmePreset> *Position; // eax
  int (__thiscall *v19)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeAnimationSet *v20; // eax
  CDmePresetGroup *v21; // eax
  int v22; // esi
  CDmePresetGroup *i; // edi
  const char *v24; // eax
  CExpressionCalculator *Preset; // eax
  int v26; // esi
  int v27; // eax
  int v28; // esi
  int BufferType; // eax
  char pBuf[32]; // [esp+Ch] [ebp-3Ch] BYREF
  CDisableUndoScopeGuard sg; // [esp+2Ch] [ebp-1Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+34h] [ebp-14h] BYREF
  CDmaElementArray<CDmePreset> *presets; // [esp+3Ch] [ebp-Ch]
  DmElementHandle_t src; // [esp+40h] [ebp-8h] BYREF
  int nCount; // [esp+44h] [ebp-4h]
  char bOk_3; // [esp+53h] [ebp+Bh]

  src = (DmElementHandle_t)this;
  String = KeyValues::GetString(this: pContextKeyValues, keyName: "presetGroupName", defaultValue: defaultValue);
  Int = KeyValues::GetInt(this: pContextKeyValues, keyName: "animSet", defaultValue: -1);
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v7 = (CDmeAnimationSet *)v6;
  if ( v6 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeAnimationSet::m_classType.u) == 0 )
  {
    v7 = nullptr;
LABEL_4:
    PresetGroup = nullptr;
    goto LABEL_5;
  }
  if ( String == nullptr )
    goto LABEL_4;
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: String);
LABEL_5:
  Name = KeyValues::GetName(this: pContextKeyValues);
  if ( _V_stricmp(s1: Name, s2: "ExportPresetGroup") != 0 )
  {
    v13 = KeyValues::GetName(this: pContextKeyValues);
    if ( _V_stricmp(s1: v13, s2: "ExportPresetGroupToVFE") != 0 )
    {
      v14 = KeyValues::GetName(this: pContextKeyValues);
      if ( _V_stricmp(s1: v14, s2: "ExportPresetGroupToTXT") != 0 )
      {
        nCount = KeyValues::GetInt(this: pContextKeyValues, keyName: "count", defaultValue: 0);
        if ( nCount != 0 )
        {
          v15 = src;
          SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: (CDmePresetGroupEditorPanel *)(src - 380));
          if ( SelectedPresetGroupName == nullptr )
            SelectedPresetGroupName = "root";
          CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &sg);
          v17 = (CDmeTransformControl *)CreateElement<CDmePresetGroup>(
                                          pObjectName: SelectedPresetGroupName,
                                          fileid: DMFILEID_INVALID,
                                          pObjectID: nullptr);
          Position = (CDmaElementArray<CDmePreset> *)CDmeTransformControl::GetPosition(this: v17);
          v19 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
          presets = Position;
          traversal.m_pFilmClip = (CDmeFilmClip *)((int (__thiscall *)(_DWORD, _DWORD))v19)(
                                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                                    a2: *(_DWORD *)(v15 + 36));
          traversal.m_nIndex = 0;
          v20 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          v21 = CDmeAnimationSet::FindPresetGroup(this: v20, pGroupName: SelectedPresetGroupName);
          v22 = 0;
          for ( i = v21; v22 < nCount; ++v22 )
          {
            V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", v22);
            v24 = KeyValues::GetString(this: pContextKeyValues, keyName: pBuf, defaultValue: defaultValue);
            Preset = (CExpressionCalculator *)CDmePresetGroup::FindPreset(this: i, pPresetName: v24);
            if ( Preset != nullptr )
            {
              src = CCodecBuffer_Block::GetBufferType(this: Preset);
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                this: presets,
                &src);
            }
          }
          v26 = *(_DWORD *)g_pDataModel.u.m_Id;
          v27 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, CDmeTransformControl *))(*(_DWORD *)g_pDataModel.u.m_Id + 124))(
                  a1: g_pDataModel.u,
                  a2: pFileFormat,
                  a3: pFileFormat,
                  a4: v17);
          bOk_3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(v26 + 184))(
                    a1: g_pDataModel.u,
                    a2: pFileName,
                    a3: 0,
                    a4: v27);
          v28 = *(_DWORD *)g_pDataModel.u.m_Id;
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v28 + 68))(
            a1: g_pDataModel.u,
            a2: BufferType);
          CChangeUndoScopeGuard::Release(this: &sg);
          return bOk_3;
        }
        else
        {
          return 1;
        }
      }
      else
      {
        if ( PresetGroup == nullptr )
          return 0;
        return CDmePresetGroup::ExportToTXT(this: PresetGroup, pFileName, pAnimationSet: v7, pComboOp: nullptr);
      }
    }
    else
    {
      if ( PresetGroup == nullptr )
        return 0;
      return CDmePresetGroup::ExportToVFE(this: PresetGroup, pFileName, pAnimationSet: v7, pComboOp: nullptr);
    }
  }
  else
  {
    if ( PresetGroup == nullptr )
      return 0;
    v11 = *(_DWORD *)g_pDataModel.u.m_Id;
    v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, CDmePresetGroup *))(*(_DWORD *)g_pDataModel.u.m_Id + 124))(
            a1: g_pDataModel.u,
            a2: pFileFormat,
            a3: pFileFormat,
            a4: PresetGroup);
    return (*(bool (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(v11 + 184))(
             a1: g_pDataModel.u,
             a2: pFileName,
             a3: 0,
             a4: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049EEB0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnPresetPickCancelled(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnPresetPickCancelled(CDmePresetGroupEditorPanel *this, KeyValues *pParams)
{
  KeyValues *Key; // esi
  unsigned __int8 (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  int Int; // eax
  int v5; // eax
  int v6; // esi
  CDisableUndoScopeGuard sg; // [esp+4h] [ebp-8h] BYREF

  Key = KeyValues::FindKey(this: pParams, keyName: "ImportPicked", bCreate: false);
  if ( Key != nullptr )
  {
    v3 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    sg.m_bNotify = false;
    sg.m_pNotify = nullptr;
    *(_WORD *)&sg.m_bOldValue = ((int (__thiscall *)(_DWORD))v3)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    Int = KeyValues::GetInt(this: Key, keyName: "presets", defaultValue: -1);
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: Int);
    v6 = v5;
    if ( v5 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v6 = 0;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)(v6 + 56));
    CChangeUndoScopeGuard::Release(this: &sg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049EF70
// Name: private: virtual void CDmePresetGroupEditorPanel::OnRemoveDefaultControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemoveDefaultControls(CDmePresetGroupEditorPanel *this)
{
  CDmeTransformControl *PresetGroup; // eax
  const Vector *Position; // esi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  int v7; // eax
  CDmeTransform *v8; // esi
  const Vector *v9; // esi
  float v10; // eax
  DmElementArray_t *v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // ebx
  const char *m_pAsString; // eax
  CDmElement *Control; // eax
  CDmElement *v19; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v21; // edi
  CDmaVar<float> *m_pData; // edi
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // edi
  CDmaVar<float> *v25; // edi
  CDmAttribute *v26; // eax
  CDmAttribute *v27; // esi
  CDmaVar<float> *v28; // esi
  CDmAttribute *v29; // eax
  CDmAttribute *v30; // esi
  CDmaVar<float> *v31; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-34h] BYREF
  CDmrElementArray<CDmePreset> presets; // [esp+14h] [ebp-2Ch] BYREF
  CDmrElementArray<CDmElement> controls; // [esp+1Ch] [ebp-24h] BYREF
  const char *pPresetGroupName; // [esp+24h] [ebp-1Ch]
  int v36; // [esp+28h] [ebp-18h]
  CDmeAnimationSet *pAnimSet; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  float flDefaultValue; // [esp+34h] [ebp-Ch]
  int j; // [esp+38h] [ebp-8h]
  bool bIsDefault; // [esp+3Fh] [ebp-1h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Remove Default Controls",
      a3: "Remove Default Controls",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Remove Default Controls",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( pAnimSet != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = (CDmeTransformControl *)CDmeAnimationSet::FindPresetGroup(
                                                this: pAnimSet,
                                                pGroupName: pPresetGroupName);
        if ( PresetGroup != nullptr )
        {
          Position = CDmeTransformControl::GetPosition(this: PresetGroup);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
          x = Position[2].x;
          if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
          {
            m_pStorage = nullptr;
            presets.m_pAttribute = nullptr;
            presets.m_pStorage = nullptr;
            m_Size = 0;
          }
          else
          {
            presets.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
            m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
            presets.m_pStorage = m_pStorage;
            m_Size = m_pStorage->m_Size;
          }
          v36 = m_Size;
          i = 0;
          if ( m_Size > 0 )
            break;
        }
LABEL_71:
        pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( pAnimSet == nullptr )
          goto LABEL_72;
      }
      while ( 1 )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pStorage->m_Memory.m_pMemory[i]);
        v8 = (CDmeTransform *)v7;
        if ( v7 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmePreset::m_classType.u) == 0 )
        {
          v8 = nullptr;
        }
        if ( !CDmePreset::IsAnimated(this: (CDmePreset *)v8) )
        {
          v9 = CDmeTransform::GetPosition(this: v8);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
          v10 = v9[2].x;
          if ( v10 == 0.0 || (*(_BYTE *)(LODWORD(v10) + 16) & 0x1F) != 0xF )
          {
            v11 = nullptr;
            controls.m_pAttribute = nullptr;
            controls.m_pStorage = nullptr;
            v12 = 0;
          }
          else
          {
            controls.m_pAttribute = (CDmAttribute *)LODWORD(v9[2].x);
            v11 = *(DmElementArray_t **)(LODWORD(v10) + 4);
            controls.m_pStorage = v11;
            v12 = v11->m_Size;
          }
          j = v12 - 1;
          if ( v12 - 1 >= 0 )
            break;
        }
LABEL_70:
        if ( ++i >= v36 )
          goto LABEL_71;
        m_pStorage = presets.m_pStorage;
      }
      while ( 1 )
      {
        v13 = j;
        v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v11->m_Memory.m_pMemory[j]);
        v15 = (CDmElement *)v14;
        if ( v14 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
               a1: v14,
               a2: CDmElement::m_classType.u) != 0 )
        {
          v16 = v15;
        }
        else
        {
          v16 = nullptr;
        }
        m_pAsString = v16->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        Control = CDmeAnimationSet::FindControl(this: pAnimSet, pControlName: m_pAsString);
        v19 = Control;
        if ( Control == nullptr )
        {
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
            this: &controls,
            elem: v13);
          goto LABEL_69;
        }
        bIsDefault = true;
        if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        Attribute = CDmElement::FindAttribute(this: Control, pAttributeName: "defaultValue");
        v21 = Attribute;
        if ( Attribute != nullptr )
        {
          if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          if ( (Attribute->m_nFlags & 0x1F) == 3 )
          {
            m_pData = (CDmaVar<float> *)Attribute->m_pData;
          }
          else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
          {
            CDmAttribute::CopyDataOut<float>(this: v21, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
            m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
          }
          else
          {
            m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
          }
        }
        else
        {
          m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
        }
        flDefaultValue = m_pData->m_Storage;
        if ( CDmElement::HasAttribute(this: v19, pAttributeName: "rightValue", type: AT_UNKNOWN) )
        {
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v23 = CDmElement::FindAttribute(this: v16, pAttributeName: "leftValue");
          v24 = v23;
          if ( v23 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v23->m_nFlags & 0x1F) == 3 )
            {
              v25 = (CDmaVar<float> *)v23->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v23) )
            {
              CDmAttribute::CopyDataOut<float>(this: v24, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v25 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v25 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v25 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue != v25->m_Storage )
            bIsDefault = false;
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v26 = CDmElement::FindAttribute(this: v16, pAttributeName: "rightValue");
          v27 = v26;
          if ( v26 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v26->m_nFlags & 0x1F) == 3 )
            {
              v28 = (CDmaVar<float> *)v26->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v26) )
            {
              CDmAttribute::CopyDataOut<float>(this: v27, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v28 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v28 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v28 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue == v28->m_Storage && bIsDefault )
            goto LABEL_68;
        }
        else
        {
          if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
          }
          v29 = CDmElement::FindAttribute(this: v16, pAttributeName: "value");
          v30 = v29;
          if ( v29 != nullptr )
          {
            if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
            }
            if ( (v29->m_nFlags & 0x1F) == 3 )
            {
              v31 = (CDmaVar<float> *)v29->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: v29) )
            {
              CDmAttribute::CopyDataOut<float>(this: v30, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
              v31 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
            }
            else
            {
              v31 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
            }
          }
          else
          {
            v31 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
          }
          if ( flDefaultValue == v31->m_Storage )
LABEL_68:
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
              this: &controls,
              elem: j);
        }
LABEL_69:
        if ( --j < 0 )
          goto LABEL_70;
        v11 = controls.m_pStorage;
      }
    }
LABEL_72:
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F460
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MovePresetUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F4F0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MovePresetDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F580
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveGroupUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F610
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveGroupDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F6A0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F730
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemovePreset";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F7C0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F850
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "InputCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F8E0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F970
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddPhonemeGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FA00
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RenameGroup";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FA90
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveDefaultControls";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FB20
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RenamePreset";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FBB0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleGroupVisibility";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FC40
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleGroupSharing";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FCD0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FD60
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemDeselected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FDF0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportPresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FE80
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FF10
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1020,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportPresetGroups";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049FFA0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1024,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroups";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0030
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1028,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroupsToVFE";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A00C0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1032,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ExportPresetGroupsToTXT";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0150
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1036,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetPicked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A01E0
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertySheet::`vcall'{1040,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetPickCancelled";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0270
// Name: public: static void CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1044,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileStateMachineFinished";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0300
// Name: public: static void CDmePresetGroupEditorFrame::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePresetGroupEditorFrame::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x004A03D0
// Name: public: static void CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded )
  {
    `CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PresetsChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0460
// Name: public: CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupEditorPanel *__thiscall CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(
        CDmePresetGroupEditorPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v10; // ebx
  CDmePresetGroupListPanel *v11; // eax
  CDmePresetGroupListPanel *v12; // eax
  CDmePresetListPanel *v13; // eax
  CDmePresetListPanel *v14; // eax
  vgui::FileOpenStateMachine *v15; // eax
  vgui::FileOpenStateMachine *v16; // eax
  vgui::Panel *v17; // eax
  int savedregs; // [esp+ECh] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&vgui::IFileOpenStateMachineClient::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorPanel_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CDmePresetGroupEditorPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( `CDmePresetGroupEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorPanel");
    v4->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePresetGroupEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorPanel");
    v5->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePresetGroupEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorPanel");
    v6->pfnClassName = CDmePresetGroupEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetUp::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMovePresetDown::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupUp::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnMoveGroupDown::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemovePreset::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnAddPhonemeGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenameGroup::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRemoveDefaultControls::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnRenamePreset::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupVisibility::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnToggleGroupSharing::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresets::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresets::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnImportPresetGroups::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroups::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToVFE::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnExportPresetGroupToTXT::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPicked::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnPresetPickCancelled::InitVar(a1: (int)&savedregs);
  CDmePresetGroupEditorPanel::PanelMessageFunc_OnFileStateMachineFinished::InitVar(a1: (int)&savedregs);
  this->m_hFilmClip.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_hFileOpenStateMachine.m_iPanelID = -1;
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PresetGroupSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
  v11 = (CDmePresetGroupListPanel *)MemAlloc_Alloc(nSize: 0x254u);
  if ( v11 != nullptr )
    v12 = CDmePresetGroupListPanel::CDmePresetGroupListPanel(
            this: v11,
            pParent: Child,
            pName: "PresetGroupList",
            pComboPanel: this);
  else
    v12 = nullptr;
  this->m_pPresetGroupList = v12;
  v12->AddColumnHeader(this: v12, a2: 0, a3: "name", a4: "Preset Group Name", a5: 150, a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 1,
    a3: "visible",
    a4: "Visible",
    a5: 70,
    a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 2,
    a3: "shared",
    a4: "Shared",
    a5: 52,
    a6: 0);
  this->m_pPresetGroupList->AddColumnHeader(
    this: this->m_pPresetGroupList,
    a2: 3,
    a3: "readonly",
    a4: "Read Only",
    a5: 52,
    a6: 0);
  this->m_pPresetGroupList->SetSelectIndividualCells(this: this->m_pPresetGroupList, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pPresetGroupList, bState: false);
  this->m_pPresetGroupList->SetEmptyListText_2(this: this->m_pPresetGroupList, a2: "No preset groups");
  this->m_pPresetGroupList->AddActionSignalTarget_2(this: this->m_pPresetGroupList, a2: this);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 0, a3: IndexSortFunc);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 1, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 1, a3: false);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 2, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 2, a3: false);
  this->m_pPresetGroupList->SetSortFunc(this: this->m_pPresetGroupList, a2: 3, a3: nullptr);
  this->m_pPresetGroupList->SetColumnSortable(this: this->m_pPresetGroupList, a2: 3, a3: false);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetGroupList->SetDropEnabled)(a1: 1, a2: 0);
  this->m_pPresetGroupList->SetSortColumn(this: this->m_pPresetGroupList, a2: 0);
  this->m_pPresetGroupList->SetDragEnabled(this: this->m_pPresetGroupList, a2: true);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetGroupList->SetDropEnabled)(a1: 1, a2: 0);
  vgui::ListPanel::SetIgnoreDoubleClick(this: this->m_pPresetGroupList, state: true);
  v13 = (CDmePresetListPanel *)MemAlloc_Alloc(nSize: 0x254u);
  if ( v13 != nullptr )
    v14 = CDmePresetListPanel::CDmePresetListPanel(this: v13, pParent: v10, pName: "PresetList", pComboPanel: this);
  else
    v14 = nullptr;
  this->m_pPresetList = v14;
  v14->AddColumnHeader(this: v14, a2: 0, a3: "name", a4: "Preset Name", a5: 150, a6: 0);
  this->m_pPresetList->SetSelectIndividualCells(this: this->m_pPresetList, a2: false);
  this->m_pPresetList->SetEmptyListText_2(this: this->m_pPresetList, a2: "No presets");
  this->m_pPresetList->AddActionSignalTarget_2(this: this->m_pPresetList, a2: this);
  this->m_pPresetList->SetSortFunc(this: this->m_pPresetList, a2: 0, a3: IndexSortFunc);
  this->m_pPresetList->SetSortColumn(this: this->m_pPresetList, a2: 0);
  this->m_pPresetList->SetDragEnabled(this: this->m_pPresetList, a2: true);
  ((void (__stdcall *)(int, _DWORD))this->m_pPresetList->SetDropEnabled)(a1: 1, a2: 0);
  vgui::ListPanel::SetIgnoreDoubleClick(this: this->m_pPresetList, state: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepresetgroupeditorpanel.res",
    dialogID: 0);
  v15 = (vgui::FileOpenStateMachine *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v15 != nullptr )
    v16 = vgui::FileOpenStateMachine::FileOpenStateMachine(
            this: v15,
            pParent: this,
            pClient: &this->vgui::IFileOpenStateMachineClient);
  else
    v16 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hFileOpenStateMachine, pPanel: v16);
  v17 = vgui::PHandle::Get(this: &this->m_hFileOpenStateMachine);
  v17->AddActionSignalTarget_2(this: v17, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A0930
// Name: private: void CDmePresetGroupEditorPanel::RefreshPresetNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::RefreshPresetNames(CDmePresetGroupEditorPanel *this)
{
  const char *SelectedPresetName; // eax
  CDmePresetListPanel *m_pPresetList; // ecx
  const char *SelectedPresetGroupName; // eax
  const char *v5; // edi
  KeyValues *v6; // esi
  CDmeFilmClip *v7; // eax
  const char *m_pAsString; // edi
  KeyValues *v9; // eax
  int v10; // esi
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > presetNames; // [esp+4h] [ebp-1Ch] BYREF
  const char *pSelectedPresetName; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
  m_pPresetList = this->m_pPresetList;
  pSelectedPresetName = SelectedPresetName;
  m_pPresetList->RemoveAll(this: m_pPresetList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) != 0 )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    v5 = SelectedPresetGroupName;
    v6 = nullptr;
    if ( SelectedPresetGroupName != nullptr )
    {
      memset(&presetNames, 0, sizeof(presetNames));
      if ( _V_strcmp(s1: SelectedPresetGroupName, s2: "Procedural") != 0 )
      {
        v7 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                               a1: g_pDataModel.u,
                               a2: this->m_hFilmClip.m_handle);
        CollectPresetNamesForGroup(
          pFilmClip: v7,
          pPresetGroupName: v5,
          (CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
      }
      else
      {
        CollectProceduralPresetNames((CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
      }
      i = 0;
      if ( presetNames.m_Size > 0 )
      {
        while ( 1 )
        {
          m_pAsString = presetNames.m_Memory.m_pMemory[i].u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v9 != nullptr )
            v6 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "name", firstValue: m_pAsString);
          KeyValues::SetString(this: v6, keyName: "presetName", value: m_pAsString);
          KeyValues::SetInt(this: v6, keyName: "index", value: i);
          v10 = this->m_pPresetList->AddItem(this: this->m_pPresetList, a2: v6, a3: 0, a4: false, a5: false);
          if ( pSelectedPresetName != nullptr && _V_strcmp(s1: pSelectedPresetName, s2: m_pAsString) == 0 )
            this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: v10);
          if ( ++i >= presetNames.m_Size )
            break;
          v6 = nullptr;
        }
      }
      this->m_pPresetList->SortList(this: this->m_pPresetList);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&presetNames);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0AB0
// Name: private: void CDmePresetGroupEditorPanel::PerformRenamePreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::PerformRenamePreset(
        CDmePresetGroupEditorPanel *this,
        const char *pNewPresetName)
{
  const char *SelectedPresetName; // esi
  void (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // eax
  CDmeAnimationSet *v5; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *v7; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-1Ch] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+18h] [ebp-8h]
  const char *pPresetName; // [esp+1Ch] [ebp-4h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    SelectedPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
    pPresetName = SelectedPresetName;
    if ( SelectedPresetName != nullptr
      && CDmePresetGroupEditorPanel::HasDuplicatePresetName(
           this,
           pPresetName: pNewPresetName,
           pIgnorePresetName: SelectedPresetName) == 0 )
    {
      v4 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
      *(_WORD *)&sg.m_bReleased = 256;
      sg.m_pNotify = nullptr;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v4)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: "Rename Preset",
        a3: "Rename Preset",
        a4: 0);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 460))(
        a1: g_pDataModel.u,
        a2: "Rename Preset",
        a3: 6,
        a4: 256);
      traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                                a1: g_pDataModel.u,
                                                a2: this->m_hFilmClip.m_handle);
      traversal.m_nIndex = 0;
      v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( v5 != nullptr )
      {
        while ( 1 )
        {
          PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v5, pGroupName: pPresetGroupName);
          if ( PresetGroup != nullptr )
          {
            v7 = CDmePresetGroup::FindOrAddPreset(this: PresetGroup, pPresetName: SelectedPresetName);
            if ( v7 != nullptr )
            {
              (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                a1: g_pDataModel.u,
                a2: &value,
                a3: pNewPresetName);
              CDmAttribute::SetValue<CUtlSymbolLarge>(this: v7->m_Name.m_pAttribute, &value);
            }
          }
          v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          if ( v5 == nullptr )
            break;
          SelectedPresetName = pPresetName;
        }
      }
      CUndoScopeGuard::Release(this: &sg);
      CDmePresetGroupEditorPanel::RefreshPresetNames(this);
      CDmePresetGroupEditorPanel::NotifyDataChanged((CDmePresetGroupEditorFrame *)this);
      if ( !sg.m_bReleased )
      {
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
        if ( sg.m_bNotify )
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
            a1: g_pDataModel.u,
            a2: 0);
        if ( sg.m_pNotify != nullptr )
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
            a1: g_pDataModel.u,
            a2: sg.m_pNotify);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0C20
// Name: public: virtual void CDmePresetGroupEditorPanel::OnRemovePreset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemovePreset(CDmePresetGroupEditorPanel *this)
{
  int v2; // eax
  int v3; // edi
  void (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // eax
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // eax
  int v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-18h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-10h] BYREF
  const char *pPresetName; // [esp+14h] [ebp-8h]
  const char *pPresetGroupName; // [esp+18h] [ebp-4h]

  pPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( pPresetGroupName != nullptr )
  {
    pPresetName = CDmePresetGroupEditorPanel::GetSelectedPresetName(this);
    if ( pPresetName != nullptr )
    {
      v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
      v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
      v4 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
      *(_WORD *)&sg.m_bReleased = 256;
      sg.m_pNotify = nullptr;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v4)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: "Remove Preset",
        a3: "Remove Preset",
        a4: 0);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 460))(
        a1: g_pDataModel.u,
        a2: "Remove Preset",
        a3: 6,
        a4: 256);
      traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                                a1: g_pDataModel.u,
                                                a2: this->m_hFilmClip.m_handle);
      traversal.m_nIndex = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pPresetGroupName);
        if ( PresetGroup != nullptr )
          CDmePresetGroup::RemovePreset(this: PresetGroup, pPresetName);
      }
      CUndoScopeGuard::Release(this: &sg);
      CDmePresetGroupEditorPanel::RefreshPresetNames(this);
      if ( v3 >= this->m_pPresetList->GetItemCount(this: this->m_pPresetList) )
        --v3;
      if ( v3 >= 0 )
      {
        v7 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3);
        this->m_pPresetList->ClearSelectedItems(this: this->m_pPresetList);
        this->m_pPresetList->AddSelectedItem(this: this->m_pPresetList, a2: v7);
      }
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "PresetsChanged");
      else
        v9 = nullptr;
      this->PostActionSignal(this, a2: v9);
      if ( !sg.m_bReleased )
      {
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
        if ( sg.m_bNotify )
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
            a1: g_pDataModel.u,
            a2: 0);
        if ( sg.m_pNotify != nullptr )
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
            a1: g_pDataModel.u,
            a2: sg.m_pNotify);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0DE0
// Name: public: void CDmePresetGroupEditorPanel::MovePresetInFrontOf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetInFrontOf(
        CDmePresetGroupEditorPanel *this,
        const char *pDragPresetName,
        const char *pDropPresetName)
{
  const char *SelectedPresetGroupName; // esi
  void (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // edx
  CDmeAnimationSet *v6; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePresetGroup *v8; // esi
  CDmePreset *Preset; // edi
  CDmePreset *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+10h] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+18h] [ebp-4h]

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  pPresetGroupName = SelectedPresetGroupName;
  if ( SelectedPresetGroupName != nullptr )
  {
    v5 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v5)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: "Reorder Presets",
      a3: "Reorder Presets",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Reorder Presets",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v6 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v6 != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v6, pGroupName: SelectedPresetGroupName);
        v8 = PresetGroup;
        if ( PresetGroup != nullptr )
        {
          Preset = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName: pDragPresetName);
          if ( Preset != nullptr )
          {
            v10 = CDmePresetGroup::FindPreset(this: v8, pPresetName: pDropPresetName);
            CDmePresetGroup::MovePresetInFrontOf(this: v8, pPreset: Preset, pInFrontOf: v10);
          }
        }
        v6 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( v6 == nullptr )
          break;
        SelectedPresetGroupName = pPresetGroupName;
      }
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this);
    CDmePresetGroupEditorPanel::SetSelectedPreset(this, a2: (int)this, pPresetName: pDragPresetName);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "PresetsChanged");
    else
      v12 = nullptr;
    this->PostActionSignal(this, a2: v12);
    if ( !sg.m_bReleased )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      if ( sg.m_bNotify )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
          a1: g_pDataModel.u,
          a2: 0);
      if ( sg.m_pNotify != nullptr )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
          a1: g_pDataModel.u,
          a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0F50
// Name: private: virtual void CDmePresetGroupEditorPanel::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnItemDeselected(CDmePresetGroupEditorPanel *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pPresetGroupList )
    CDmePresetGroupEditorPanel::RefreshPresetNames(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A0F80
// Name: public: void CDmePresetGroupEditorPanel::MovePresetIntoGroup(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetIntoGroup(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetName,
        const char *pSrcGroupName,
        const char *pDstGroupName)
{
  CDmePresetGroupEditorPanel *v4; // edi
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  void (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // eax
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // eax
  CDmePresetGroup *v9; // edi
  CDmePresetGroup *v10; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-1Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-Ch] BYREF
  CDmePresetGroupEditorPanel *v14; // [esp+14h] [ebp-4h]

  v4 = this;
  v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_handle = this->m_hFilmClip.m_handle;
  v14 = this;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))v5)(
         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
         a2: m_handle) != 0
    && pPresetName != nullptr
    && pSrcGroupName != nullptr
    && pDstGroupName != nullptr )
  {
    v6 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v6)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: "Change Preset Group",
      a3: "Change Preset Group",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Change Preset Group",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: v4->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v7 != nullptr )
    {
      do
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: pSrcGroupName);
        v9 = PresetGroup;
        if ( PresetGroup != nullptr && CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName) != nullptr )
        {
          CDmePresetGroup::RemovePreset(this: v9, pPresetName);
          v10 = CDmeAnimationSet::FindOrAddPresetGroup(this: v7, pGroupName: pDstGroupName);
          CDmePresetGroup::FindOrAddPreset(this: v10, pPresetName);
        }
        v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      }
      while ( v7 != nullptr );
      v4 = v14;
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this: v4);
    CDmePresetGroupEditorPanel::NotifyDataChanged(this: (CDmePresetGroupEditorFrame *)v4);
    if ( !sg.m_bReleased )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      if ( sg.m_bNotify )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
          a1: g_pDataModel.u,
          a2: 0);
      if ( sg.m_pNotify != nullptr )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
          a1: g_pDataModel.u,
          a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A10E0
// Name: public: virtual void CDmePresetListPanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetListPanel::OnPanelDropped(
        CDmePresetListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  int v4; // eax
  KeyValues *v5; // ebx
  const char *String; // edi
  const char *v7; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( msgList->m_Size != 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this
      && this->m_pPresetGroupPanel != nullptr )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
      this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
      v4 = this->GetItemIDFromRow(this, a2: row);
      v5 = this->GetItem(this, a2: v4);
      String = KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: nullptr);
      v7 = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: nullptr);
      if ( String != nullptr && v7 != nullptr )
        CDmePresetGroupEditorPanel::MovePresetInFrontOf(
          this: this->m_pPresetGroupPanel,
          pDragPresetName: String,
          pDropPresetName: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A11B0
// Name: public: CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroupEditorFrame *__thiscall CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(
        CDmePresetGroupEditorFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmePresetGroupEditorPanel *v7; // eax
  CDmePresetGroupEditorPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  __int128 v12; // [esp-1Ch] [ebp-34h]
  __int128 v13; // [esp-1Ch] [ebp-34h]
  __int64 v14; // [esp+10h] [ebp-8h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "DmePresetGroupEditorFrame", showTaskbarIcon: true, bPopup: true);
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&IDmNotify::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmePresetGroupEditorFrame_vtbl *)&CDmePresetGroupEditorFrame::`vftable'{for `vgui::Frame'};
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&CDmePresetGroupEditorFrame::`vftable'{for `IDmNotify'};
  if ( `CDmePresetGroupEditorFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePresetGroupEditorFrame");
    v4->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDmePresetGroupEditorFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePresetGroupEditorFrame");
    v5->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDmePresetGroupEditorFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePresetGroupEditorFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePresetGroupEditorFrame");
    v6->pfnClassName = CDmePresetGroupEditorFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDmePresetGroupEditorFrame::PanelMessageFunc_OnPresetsChanged::InitVar(a1: (int)&savedregs);
  if ( `CDmePresetGroupEditorFrame::PanelKBMapFunc_undo::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v12 = (unsigned int) __thiscall CElementPropertiesTreeInternal::`vcall'{1120,{flat}};
    v14 = 0;
    `CDmePresetGroupEditorFrame::PanelKBMapFunc_undo::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v12 + 1) = 0;
    CDmePresetGroupEditorFrame::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "undo",
      defaultcode: KEY_Z,
      default_modifiers: 2,
      function: v12,
      helpstring: (unsigned int)"#undo_help",
      passive: false);
  }
  if ( `CDmePresetGroupEditorFrame::PanelKBMapFunc_redo::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v13 = (unsigned int) __thiscall CAssetBuilderFrame::`vcall'{1124,{flat}};
    v14 = 0;
    `CDmePresetGroupEditorFrame::PanelKBMapFunc_redo::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v13 + 1) = 0;
    CDmePresetGroupEditorFrame::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "redo",
      defaultcode: KEY_Z,
      default_modifiers: 3,
      function: v13,
      helpstring: (unsigned int)"#redo_help",
      passive: false);
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CDmePresetGroupEditorPanel *)MemAlloc_Alloc(nSize: 0x1B8u);
  if ( v7 != nullptr )
    v8 = CDmePresetGroupEditorPanel::CDmePresetGroupEditorPanel(
           this: v7,
           pParent: this,
           pName: "DmePresetGroupEditorPanel");
  else
    v8 = nullptr;
  this->m_pEditor = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "#VGui_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pOkButton = v10;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepresetgroupeditorframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 444))(
    a1: g_pDataModel.u,
    a2: &this->IDmNotify);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A13E0
// Name: public: void CDmePresetGroupEditorPanel::RefreshAnimationSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::RefreshAnimationSet(CDmePresetGroupEditorPanel *this)
{
  CDmePresetGroupEditorPanel *v1; // edi
  const char *SelectedPresetGroupName; // eax
  CDmePresetGroupListPanel *m_pPresetGroupList; // ecx
  KeyValues *v4; // esi
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  CDmeFilmClip *v6; // eax
  bool *p_bGroupReadOnly; // edi
  const char *v8; // ebx
  KeyValues *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  Color v13; // eax
  int v14; // esi
  DmElementHandle_t m_handle; // [esp-14h] [ebp-40h]
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+4h] [ebp-28h] BYREF
  const char *pSelectedPresetGroupName; // [esp+18h] [ebp-14h]
  CDmePresetGroupEditorPanel *v18; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v20; // [esp+24h] [ebp-8h]
  Color value; // [esp+28h] [ebp-4h]

  v1 = this;
  v18 = this;
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  m_pPresetGroupList = v1->m_pPresetGroupList;
  pSelectedPresetGroupName = SelectedPresetGroupName;
  m_pPresetGroupList->RemoveAll(this: m_pPresetGroupList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v1->m_hFilmClip.m_handle) != 0 )
  {
    v4 = nullptr;
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    m_handle = v1->m_hFilmClip.m_handle;
    memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
    v6 = (CDmeFilmClip *)((int (__thiscall *)(_DWORD, _DWORD))v5)(
                           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                           a2: m_handle);
    CollectPresetGroupInfo(
      pFilmClip: v6,
      presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
      bSkipReadOnly: false,
      bSkipInvisible: false);
    i = 0;
    if ( presetGroupInfo.m_Size > 0 )
    {
      p_bGroupReadOnly = &presetGroupInfo.m_Memory.m_pMemory->bGroupReadOnly;
      do
      {
        v8 = defaultValue;
        if ( *(_DWORD *)(p_bGroupReadOnly - 5) != -1 )
          v8 = *(const char **)(p_bGroupReadOnly - 5);
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v4 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "name", firstValue: v8);
        KeyValues::SetString(this: v4, keyName: "presetGroupName", value: v8);
        v10 = "Yes";
        if ( !p_bGroupReadOnly[1] )
          v10 = "No";
        KeyValues::SetString(this: v4, keyName: "visible", value: v10);
        v11 = "Yes";
        if ( !*(p_bGroupReadOnly - 1) )
          v11 = "No";
        KeyValues::SetString(this: v4, keyName: "shared", value: v11);
        v12 = "Yes";
        if ( !*p_bGroupReadOnly )
          v12 = "No";
        KeyValues::SetString(this: v4, keyName: "readonly", value: v12);
        if ( *p_bGroupReadOnly )
        {
          value = (Color)-16776961;
          v13 = (Color)-16776961;
        }
        else
        {
          v20 = -1;
          v13 = (Color)-1;
        }
        KeyValues::SetColor(this: v4, keyName: "cellcolor", value: v13);
        KeyValues::SetInt(this: v4, keyName: "index", value: i);
        v14 = v18->m_pPresetGroupList->AddItem(this: v18->m_pPresetGroupList, a2: v4, a3: 0, a4: false, a5: false);
        if ( pSelectedPresetGroupName != nullptr && _V_strcmp(s1: pSelectedPresetGroupName, s2: v8) == 0 )
          v18->m_pPresetGroupList->AddSelectedItem(this: v18->m_pPresetGroupList, a2: v14);
        p_bGroupReadOnly += 8;
        v4 = nullptr;
        ++i;
      }
      while ( i < presetGroupInfo.m_Size );
      v1 = v18;
    }
    v1->m_pPresetGroupList->SortList(this: v1->m_pPresetGroupList);
    CDmePresetGroupEditorPanel::RefreshPresetNames(this: v1);
    if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A15E0
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMovePresetUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMovePresetUp(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) == 1 )
  {
    v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
    v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
    v4 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3 - 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v2);
      v6 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v4);
      String = KeyValues::GetString(this: v6, keyName: "presetName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetInFrontOf(this, pDragPresetName: v7, pDropPresetName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A1690
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMovePresetDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMovePresetDown(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // ebx
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList) == 1 )
  {
    v2 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
    v3 = this->m_pPresetList->GetItemCurrentRow(this: this->m_pPresetList, a2: v2);
    v4 = this->m_pPresetList->GetItemIDFromRow(this: this->m_pPresetList, a2: v3 + 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v2);
      v6 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v4);
      String = KeyValues::GetString(this: v5, keyName: "presetName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v6, keyName: "presetName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetInFrontOf(this, pDragPresetName: v7, pDropPresetName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A1740
// Name: public: virtual bool CDmePresetGroupEditorPanel::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePresetGroupEditorPanel::OnReadFileFromDisk(
        CDmePresetGroupEditorPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  unsigned __int8 (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  int v6; // esi
  const char *Name; // eax
  CDmeDag *v9; // esi
  CDmeAnimationSet *v10; // edi
  void (__thiscall *v11)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // edx
  const char *m_pAsString; // eax
  CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *PresetGroups; // eax
  CDmePresetGroupEditorPanel *v14; // esi
  CDmAttribute *Attribute; // eax
  int BufferType; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-20h] BYREF
  CUndoScopeGuard v18; // [esp+14h] [ebp-18h] BYREF
  CDisableUndoScopeGuard sg; // [esp+1Ch] [ebp-10h] BYREF
  CDmePresetGroupEditorPanel *v20; // [esp+24h] [ebp-8h]
  CDmElement *pRoot; // [esp+28h] [ebp-4h] BYREF

  v5 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  v20 = this;
  sg.m_bNotify = false;
  sg.m_pNotify = nullptr;
  *(_WORD *)&sg.m_bOldValue = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, const char *, CDmElement **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
         a1: g_pDataModel.u,
         a2: pFileName,
         a3: 0,
         a4: pFileFormat,
         a5: &pRoot,
         a6: 3,
         a7: 0);
  CChangeUndoScopeGuard::Release(this: &sg);
  if ( v6 == -1 )
    goto LABEL_2;
  Name = KeyValues::GetName(this: pContextKeyValues);
  if ( _V_stricmp(s1: Name, s2: "ImportPresetGroup") != 0 )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "presets");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      if ( pRoot != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pRoot);
      else
        BufferType = -1;
      KeyValues::SetInt(this: pContextKeyValues, keyName: "presets", value: BufferType);
      goto LABEL_19;
    }
LABEL_2:
    CChangeUndoScopeGuard::Release(this: &sg);
    return 0;
  }
  v9 = (CDmeDag *)pRoot;
  if ( pRoot == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(
          a1: pRoot,
          a2: (CUtlSymbolLarge)CDmePresetGroup::m_classType.u.m_Id) )
  {
    goto LABEL_2;
  }
  traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: *(_DWORD *)&this->m_InternalKeyFocusTicked_register);
  traversal.m_nIndex = 0;
  v10 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  v11 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
  *(_WORD *)&v18.m_bReleased = 256;
  v18.m_pNotify = nullptr;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v11)(
    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
    a2: "Import Preset Group",
    a3: "Import Preset Group",
    a4: 0);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "Import Preset Group",
    a3: 6,
    a4: 256);
  CDmElement::SetFileId(this: v9, fileid: v10->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CDmeAnimationSet::RemovePresetGroup(this: v10, pPresetGroupName: m_pAsString);
  PresetGroups = (CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeAnimationSet::GetPresetGroups(this: v10);
  CDmaElementArrayBase<CDmePresetGroup,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: PresetGroups,
    pValue: v9);
  CUndoScopeGuard::Release(this: &v18);
  v14 = v20;
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this: (CDmePresetGroupEditorPanel *)((char *)v20 - 380));
  CDmePresetGroupEditorPanel::NotifyDataChanged(this: (CDmePresetGroupEditorFrame *)&v14[-1].m_lLastDoublePressTime);
  if ( !v18.m_bReleased )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    if ( v18.m_bNotify )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
        a1: g_pDataModel.u,
        a2: 0);
    if ( v18.m_pNotify != nullptr )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v18.m_pNotify);
      CChangeUndoScopeGuard::Release(this: &sg);
      return 1;
    }
  }
LABEL_19:
  CChangeUndoScopeGuard::Release(this: &sg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1960
// Name: private: void CDmePresetGroupEditorPanel::ImportPresets(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::ImportPresets(
        CDmePresetGroupEditorPanel *this,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *presetNames,
        CDmePreset *pRoot)
{
  CDmePresetGroupEditorPanel *v3; // edi
  int (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  CDmeAnimationSet *v5; // esi
  const char *SelectedPresetGroupName; // eax
  CDmePresetGroup *PresetGroup; // ebx
  CDmAttribute *Attribute; // esi
  int v9; // eax
  int v10; // edi
  int m_Size; // ebx
  int v12; // eax
  CDmeTransform *v13; // esi
  const char *m_pAsString; // eax
  const Vector *Position; // ebx
  int v16; // edi
  int v17; // eax
  CDmElement *v18; // esi
  CDmElement *v19; // ecx
  CDmElement *v20; // esi
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-3Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-2Ch] BYREF
  CDmrElementArray<CDmePreset> srcPresets; // [esp+14h] [ebp-24h] BYREF
  CDmePresetGroupEditorPanel *v26; // [esp+1Ch] [ebp-1Ch]
  int nPresetCount; // [esp+20h] [ebp-18h]
  CDmePreset *pPreset; // [esp+24h] [ebp-14h]
  const char *pPresetName; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  DmElementHandle_t src; // [esp+30h] [ebp-8h] BYREF
  CDmePresetGroup *pPresetGroup; // [esp+34h] [ebp-4h]
  CDmeTransform *pSrcPreset; // [esp+44h] [ebp+Ch]
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *pSrcPreseta; // [esp+44h] [ebp+Ch]

  v3 = this;
  v4 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_handle = this->m_hFilmClip.m_handle;
  v26 = this;
  traversal.m_pFilmClip = (CDmeFilmClip *)((int (__thiscall *)(_DWORD, _DWORD))v4)(
                                            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                            a2: m_handle);
  traversal.m_nIndex = 0;
  v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this: v3);
  PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v5, pGroupName: SelectedPresetGroupName);
  pPresetGroup = PresetGroup;
  if ( PresetGroup != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "presets");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      srcPresets.m_pAttribute = Attribute;
      srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      if ( srcPresets.m_pStorage->m_Size != 0 )
      {
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
          a1: g_pDataModel.u,
          a2: "Import Presets",
          a3: "Import Presets",
          a4: 0);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 460))(
          a1: g_pDataModel.u,
          a2: "Import Presets",
          a3: 6,
          a4: 256);
        v9 = 0;
        nPresetCount = presetNames->m_Size;
        i = 0;
        if ( nPresetCount > 0 )
        {
          while ( 1 )
          {
            pPresetName = presetNames->m_Memory.m_pMemory[v9];
            v10 = 0;
            pPreset = CDmePresetGroup::FindOrAddPreset(this: PresetGroup, pPresetName);
            pSrcPreset = nullptr;
            if ( srcPresets.m_pAttribute != nullptr )
              m_Size = srcPresets.m_pStorage->m_Size;
            else
              m_Size = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: srcPresets.m_pStorage->m_Memory.m_pMemory[v10]);
                v13 = (CDmeTransform *)v12;
                if ( v12 != 0
                  && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
                       a1: v12,
                       a2: CDmePreset::m_classType.u) != 0 )
                {
                  m_pAsString = v13->m_Name.m_Storage.u.m_pAsString;
                  if ( m_pAsString == (const char *)-1 )
                    m_pAsString = defaultValue;
                  if ( _V_strcmp(s1: m_pAsString, s2: pPresetName) == 0 )
                    break;
                }
                if ( ++v10 >= m_Size )
                  goto LABEL_20;
              }
              pSrcPreset = v13;
            }
LABEL_20:
            Position = CDmeTransform::GetPosition(this: pSrcPreset);
            pSrcPreseta = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)CDmeTransform::GetPosition(this: (CDmeTransform *)pPreset);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: pSrcPreseta);
            v16 = 0;
            pPreset = (CDmePreset *)LODWORD(Position[1].x);
            if ( (int)pPreset > 0 )
            {
              do
              {
                v17 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: *(_DWORD *)(LODWORD(Position->x) + 4 * v16));
                v18 = (CDmElement *)v17;
                if ( v17 != 0
                  && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v17 + 16))(
                       a1: v17,
                       a2: CDmElement::m_classType.u) != 0 )
                {
                  v19 = v18;
                }
                else
                {
                  v19 = nullptr;
                }
                v20 = CDmElement::CopyInternal(this: v19, depth: TD_DEEP);
                CDmElement::SetFileId(this: v20, fileid: pPresetGroup->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
                if ( v20 != nullptr )
                  src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v20);
                else
                  src = DMELEMENT_HANDLE_INVALID;
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: pSrcPreseta,
                  &src);
                ++v16;
              }
              while ( v16 < (int)pPreset );
            }
            v9 = i + 1;
            i = v9;
            if ( v9 >= nPresetCount )
              break;
            PresetGroup = pPresetGroup;
          }
          v3 = v26;
        }
        CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v3);
        v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v21 != nullptr )
          v22 = KeyValues::KeyValues(this: v21, setName: "PresetsChanged");
        else
          v22 = nullptr;
        v3->PostActionSignal(this: v3, a2: v22);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
          a1: g_pDataModel.u,
          a2: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A1BF0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnPresetPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnPresetPicked(CDmePresetGroupEditorPanel *this, KeyValues *pParams)
{
  int m_Size; // esi
  KeyValues *v3; // edi
  const char **m_pMemory; // ebx
  int Int; // eax
  int v6; // edi
  const char **v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  int j; // esi
  vgui::FileOpenStateMachine *v11; // eax
  KeyValues *Key; // eax
  KeyValues *v13; // edi
  int v14; // eax
  int v15; // eax
  CDmePreset *v16; // esi
  int (__thiscall *v17)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v18; // al
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // esi
  char pBuf[32]; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<char const *,CUtlMemory<char const *,int> > presetNames; // [esp+2Ch] [ebp-28h] BYREF
  CChangeUndoScopeGuard v25; // [esp+40h] [ebp-14h] BYREF
  CDmePresetGroupEditorPanel *v26; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int nCount; // [esp+50h] [ebp-4h]

  m_Size = 0;
  v3 = pParams;
  v26 = this;
  m_pMemory = nullptr;
  memset(&presetNames, 0, sizeof(presetNames));
  Int = KeyValues::GetInt(this: pParams, keyName: "count", defaultValue: 0);
  nCount = Int;
  if ( Int == 0 )
  {
LABEL_27:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&presetNames);
    return;
  }
  i = 0;
  if ( Int > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", i);
      *(_DWORD *)&v25.m_bOldValue = KeyValues::GetString(this: v3, keyName: pBuf, defaultValue: defaultValue);
      v6 = m_Size;
      if ( m_Size + 1 > presetNames.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&presetNames,
          num: m_Size - presetNames.m_Memory.m_nAllocationCount + 1);
        m_Size = presetNames.m_Size;
        m_pMemory = presetNames.m_Memory.m_pMemory;
      }
      presetNames.m_Size = ++m_Size;
      presetNames.m_pElements = m_pMemory;
      if ( m_Size - v6 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (m_Size - v6 - 1));
      v7 = &m_pMemory[v6];
      if ( v7 != nullptr )
        *v7 = *(const char **)&v25.m_bOldValue;
      v3 = pParams;
      ++i;
    }
    while ( i < nCount );
  }
  if ( KeyValues::FindKey(this: v3, keyName: "ExportPicked", bCreate: false) == nullptr )
  {
    Key = KeyValues::FindKey(this: v3, keyName: "ImportPicked", bCreate: false);
    v13 = Key;
    if ( Key != nullptr )
    {
      v14 = KeyValues::GetInt(this: Key, keyName: "presets", defaultValue: -1);
      v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: v14);
      v16 = (CDmePreset *)v15;
      if ( v15 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
             a1: v15,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v16 = nullptr;
      }
      CDmePresetGroupEditorPanel::ImportPresets(this: v26, &presetNames, pRoot: v16);
      v17 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
      *(_WORD *)&v25.m_bReleased = 0;
      v25.m_pNotify = nullptr;
      v18 = ((int (__thiscall *)(_DWORD))v17)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
      v19 = *(_DWORD *)g_pDataModel.u.m_Id;
      v25.m_bOldValue = v18;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v19 + 232))(a1: g_pDataModel.u, a2: 0);
      v20 = KeyValues::GetInt(this: v13, keyName: "presets", defaultValue: -1);
      v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: v20);
      v22 = v21;
      if ( v21 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v21 + 16))(
             a1: v21,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v22 = 0;
      }
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
        a1: g_pDataModel.u,
        a2: *(_DWORD *)(v22 + 56));
      CChangeUndoScopeGuard::Release(this: &v25);
    }
    goto LABEL_27;
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "ExportPresets");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: "count", value: nCount);
  for ( j = 0; j < nCount; ++j )
  {
    V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", j);
    KeyValues::SetString(this: v9, keyName: pBuf, value: m_pMemory[j]);
  }
  v11 = (vgui::FileOpenStateMachine *)vgui::PHandle::Get(this: &v26->m_hFileOpenStateMachine);
  vgui::FileOpenStateMachine::SaveFile(
    this: v11,
    pContextKeyValues: v9,
    pFileName: nullptr,
    pFileType: "preset",
    nFlags: 1);
  if ( presetNames.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004A1E80
// Name: private: void CDmePresetGroupEditorPanel::PerformAddGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::PerformAddGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pNewGroupName)
{
  void (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, int); // eax
  CDmeAnimationSet *i; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-10h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) != 0
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: nullptr) == 0 )
  {
    v5 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v5)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: "Add Preset Group",
      a3: "Add Preset Group",
      a4: 0,
      a5: a3);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Add Preset Group",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      CDmeAnimationSet::FindOrAddPresetGroup(this: i, pGroupName: pNewGroupName);
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this, a2, pPresetGroupName: pNewGroupName);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
    else
      v8 = nullptr;
    this->PostActionSignal(this, a2: v8);
    if ( !sg.m_bReleased )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      if ( sg.m_bNotify )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
          a1: g_pDataModel.u,
          a2: 0);
      if ( sg.m_pNotify != nullptr )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
          a1: g_pDataModel.u,
          a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A1FE0
// Name: private: void CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(
        CDmePresetGroupEditorPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pNewGroupName)
{
  CDmePresetGroupEditorPanel *v3; // esi
  int (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  CDmeAnimationSet *v5; // eax
  int v6; // ebx
  int i; // edi
  const char *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-118h]
  int v12; // [esp-4h] [ebp-118h]
  char pTempBuf[256]; // [esp+4h] [ebp-110h] BYREF
  CDmePresetGroup *pPresetGroup; // [esp+104h] [ebp-10h]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+108h] [ebp-Ch] BYREF
  CDmePresetGroupEditorPanel *v16; // [esp+110h] [ebp-4h]

  v3 = this;
  v4 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_handle = this->m_hFilmClip.m_handle;
  v16 = this;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))v4)(
         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
         a2: m_handle) != 0
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this: v3,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: nullptr) == 0 )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Add Phoneme Preset Group",
      a3: "Add Phoneme Preset Group",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Add Phoneme Preset Group",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: v3->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v5 != nullptr )
    {
      v12 = a2;
      do
      {
        pPresetGroup = CDmeAnimationSet::FindOrAddPresetGroup(this: v5, pGroupName: pNewGroupName);
        v6 = NumPhonemes();
        for ( i = 0; i < v6; ++i )
        {
          if ( IsStandardPhoneme(index: i) )
          {
            v8 = NameForPhonemeByIndex(index: i);
            if ( _V_stricmp(s1: v8, s2: "<sil>") == 0 )
              v8 = "silence";
            V_snprintf(pDest: pTempBuf, maxLen: 256, pFormat: "p_%s", v8);
            CDmePresetGroup::FindOrAddPreset(this: pPresetGroup, pPresetName: pTempBuf);
            v3 = v16;
          }
        }
        v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      }
      while ( v5 != nullptr );
      a2 = v12;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v3);
    CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this: v3, a2, pPresetGroupName: pNewGroupName);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
    {
      v10 = KeyValues::KeyValues(this: v9, setName: "PresetsChanged");
      v3->PostActionSignal(this: v3, a2: v10);
    }
    else
    {
      v3->PostActionSignal(this: v3, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2190
// Name: private: void CDmePresetGroupEditorPanel::PerformRenameGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::PerformRenameGroup(
        CDmePresetGroupEditorPanel *this,
        const char *pNewGroupName)
{
  const char *SelectedPresetGroupName; // ebx
  void (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // eax
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+14h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+1Ch] [ebp-4h] BYREF

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName != nullptr
    && CDmePresetGroupEditorPanel::HasDuplicateGroupName(
         this,
         pGroupName: pNewGroupName,
         pIgnorePresetGroupName: SelectedPresetGroupName) == 0 )
  {
    v4 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
    *(_WORD *)&sg.m_bReleased = 256;
    sg.m_pNotify = nullptr;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v4)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: "Rename Preset Group",
      a3: "Rename Preset Group",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Rename Preset Group",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: SelectedPresetGroupName);
      if ( PresetGroup != nullptr )
      {
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
          a1: g_pDataModel.u,
          a2: &value,
          a3: pNewGroupName);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: PresetGroup->m_Name.m_pAttribute, &value);
      }
    }
    CUndoScopeGuard::Release(this: &sg);
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
    else
      v8 = nullptr;
    this->PostActionSignal(this, a2: v8);
    if ( !sg.m_bReleased )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      if ( sg.m_bNotify )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
          a1: g_pDataModel.u,
          a2: 0);
      if ( sg.m_pNotify != nullptr )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
          a1: g_pDataModel.u,
          a2: sg.m_pNotify);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A22F0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnInputCompleted(CDmePresetGroupEditorPanel *this, KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v4; // esi

  String = KeyValues::GetString(this: pKeyValues, keyName: "text", defaultValue: nullptr);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnAddGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformAddGroup(this, a2: (int)this, a3: (int)pKeyValues, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnAddPhonemeGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformAddPhonemeGroup(this, a2: (int)this, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnRenameGroup", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformRenameGroup(this, pNewGroupName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnRenamePreset", bCreate: false) != nullptr )
    {
      CDmePresetGroupEditorPanel::PerformRenamePreset(this, pNewPresetName: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A23A0
// Name: public: void CDmePresetGroupEditorPanel::ToggleGroupVisibility(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::ToggleGroupVisibility(
        CDmePresetGroupEditorPanel *this,
        const char *pPresetGroupName)
{
  const char *v2; // edi
  CDmeAnimationSet *i; // eax
  CDmePresetGroup *PresetGroup; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  v2 = pPresetGroupName;
  if ( pPresetGroupName != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Toggle Preset Group Visibility",
      a3: "Toggle Preset Group Visibility",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Toggle Preset Group Visibility",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          i != nullptr;
          i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: v2);
      if ( PresetGroup != nullptr )
      {
        HIBYTE(pPresetGroupName) = !PresetGroup->m_bIsVisible.m_Storage;
        CDmAttribute::SetValue<bool>(this: PresetGroup->m_bIsVisible.m_pAttribute, value: (bool *)&pPresetGroupName + 3);
      }
    }
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "PresetsChanged");
    else
      v7 = nullptr;
    this->PostActionSignal(this, a2: v7);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A24B0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnToggleGroupVisibility(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnToggleGroupVisibility(CDmePresetGroupEditorPanel *this)
{
  const char *SelectedPresetGroupName; // eax

  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  if ( SelectedPresetGroupName != nullptr )
    CDmePresetGroupEditorPanel::ToggleGroupVisibility(this, pPresetGroupName: SelectedPresetGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x004A24D0
// Name: private: virtual void CDmePresetGroupEditorPanel::OnToggleGroupSharing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnToggleGroupSharing(CDmePresetGroupEditorPanel *this)
{
  CDmePresetGroupEditorPanel *v1; // esi
  const char *SelectedPresetGroupName; // edi
  CDmeAnimationSet *v3; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmElement *v5; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // esi
  CDmaVar<bool> *m_pData; // esi
  CDmAttribute *v9; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmePresetGroupEditorPanel *v11; // [esp+14h] [ebp-Ch]
  const char *pPresetGroupName; // [esp+18h] [ebp-8h]
  bool value; // [esp+1Fh] [ebp-1h] BYREF

  v1 = this;
  v11 = this;
  SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
  pPresetGroupName = SelectedPresetGroupName;
  if ( SelectedPresetGroupName != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Toggle Preset Group Sharing",
      a3: "Toggle Preset Group Sharing",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Toggle Preset Group Sharing",
      a3: 6,
      a4: 256);
    traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: v1->m_hFilmClip.m_handle);
    traversal.m_nIndex = 0;
    v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v3 != nullptr )
    {
      while ( 1 )
      {
        PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: SelectedPresetGroupName);
        v5 = PresetGroup;
        if ( PresetGroup != nullptr )
        {
          if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
          }
          Attribute = CDmElement::FindAttribute(this: PresetGroup, pAttributeName: "shared");
          v7 = Attribute;
          if ( Attribute != nullptr )
          {
            if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
            }
            if ( (Attribute->m_nFlags & 0x1F) == 4 )
            {
              m_pData = (CDmaVar<bool> *)Attribute->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
            {
              CDmAttribute::CopyDataOut<bool>(this: v7, value: &`CDmAttribute::GetValue<bool>'::`7'::tempVal);
              m_pData = (CDmaVar<bool> *)&`CDmAttribute::GetValue<bool>'::`7'::tempVal;
            }
            else
            {
              m_pData = &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
            }
          }
          else
          {
            m_pData = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
          }
          if ( m_pData->m_Storage )
          {
            CDmElement::RemoveAttribute(this: v5, pAttributeName: "shared");
          }
          else
          {
            value = true;
            v9 = CDmElement::FindAttribute(this: v5, pAttributeName: "shared");
            if ( v9 != nullptr
              || (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "shared", type: AT_BOOL)) != nullptr )
            {
              CDmAttribute::SetValue<bool>(this: v9, &value);
            }
          }
        }
        v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        if ( v3 == nullptr )
          break;
        SelectedPresetGroupName = pPresetGroupName;
      }
      v1 = v11;
    }
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: v1);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2670
// Name: public: virtual void CDmePresetGroupEditorPanel::OnRemoveGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnRemoveGroup(CDmePresetGroupEditorPanel *this)
{
  const char *SelectedPresetGroupName; // eax
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  int v5; // eax
  int v6; // edi
  void (__thiscall *v7)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // eax
  CDmeAnimationSet *i; // eax
  int v9; // edi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-14h] BYREF
  CPresetGroupUndoScopeGuard sg; // [esp+Ch] [ebp-Ch] BYREF
  const char *pPresetGroupName; // [esp+14h] [ebp-4h]

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hFilmClip.m_handle) != 0 )
  {
    SelectedPresetGroupName = CDmePresetGroupEditorPanel::GetSelectedPresetGroupName(this);
    pPresetGroupName = SelectedPresetGroupName;
    if ( SelectedPresetGroupName != nullptr )
    {
      if ( _V_stricmp(s1: SelectedPresetGroupName, s2: "procedural") != 0 )
      {
        v5 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
        v6 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v5);
        v7 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
        *(_WORD *)&sg.m_bReleased = 256;
        sg.m_pNotify = nullptr;
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v7)(
          a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
          a2: "Remove Preset Group",
          a3: "Remove Preset Group",
          a4: 0);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 460))(
          a1: g_pDataModel.u,
          a2: "Remove Preset Group",
          a3: 6,
          a4: 256);
        traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                                  a1: g_pDataModel.u,
                                                  a2: this->m_hFilmClip.m_handle);
        traversal.m_nIndex = 0;
        for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
              i != nullptr;
              i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
        {
          CDmeAnimationSet::RemovePresetGroup(this: i, pPresetGroupName);
        }
        CUndoScopeGuard::Release(this: &sg);
        CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
        if ( v6 >= this->m_pPresetGroupList->GetItemCount(this: this->m_pPresetGroupList) )
          --v6;
        if ( v6 >= 0 )
        {
          v9 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v6);
          this->m_pPresetGroupList->ClearSelectedItems(this: this->m_pPresetGroupList);
          this->m_pPresetGroupList->AddSelectedItem(this: this->m_pPresetGroupList, a2: v9);
        }
        CDmePresetGroupEditorPanel::NotifyDataChanged((CDmePresetGroupEditorFrame *)this);
        if ( !sg.m_bReleased )
        {
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
          if ( sg.m_bNotify )
            (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
              a1: g_pDataModel.u,
              a2: 0);
          if ( sg.m_pNotify != nullptr )
            (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
              a1: g_pDataModel.u,
              a2: sg.m_pNotify);
        }
      }
      else
      {
        v3 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v3 != nullptr )
        {
          v4 = vgui::MessageBox::MessageBox(
                 this: v3,
                 title: "#DmePresetGroupEditor_CannotRemovePresetGroupTitle",
                 text: "#DmePresetGroupEditor_CannotRemovePresetGroupText",
                 parent: this);
          v4->DoModal_2(this: v4, a2: nullptr);
        }
        else
        {
          (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2860
// Name: public: void CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(
        CDmePresetGroupEditorPanel *this,
        const char *pDragGroupName,
        const char *pDropGroupName)
{
  CDmeAnimationSet *i; // esi
  CDmePresetGroup *PresetGroup; // edi
  CDmePresetGroup *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 256))(
    a1: g_pDataModel.u,
    a2: "Reorder Preset Groups",
    a3: "Reorder Preset Groups",
    a4: 0);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "Reorder Preset Groups",
    a3: 6,
    a4: 256);
  traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pDragGroupName);
    if ( PresetGroup != nullptr )
    {
      v6 = CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pDropGroupName);
      CDmeAnimationSet::MovePresetGroupInFrontOf(this: i, pPresetGroup: PresetGroup, pInFrontOf: v6);
    }
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
  CDmePresetGroupEditorPanel::SetSelectedPresetGroup(this, a2: (int)this, pPresetGroupName: pDragGroupName);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "PresetsChanged");
  else
    v8 = nullptr;
  this->PostActionSignal(this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x004A2970
// Name: public: virtual void CDmePresetGroupListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnMouseDoublePressed(CDmePresetGroupListPanel *this, int code)
{
  int v3; // eax
  KeyValues *v4; // eax
  const char *String; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( code == 107 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &code);
    this->GetCellAtPos(this, a2: x, a3: code, a4: &row, a5: &column);
    v3 = this->GetItemIDFromRow(this, a2: row);
    v4 = this->GetItem(this, a2: v3);
    String = KeyValues::GetString(this: v4, keyName: "presetGroupName", defaultValue: defaultValue);
    CDmePresetGroupEditorPanel::ToggleGroupVisibility(this: this->m_pPresetGroupPanel, pPresetGroupName: String);
  }
  else
  {
    vgui::ListPanel::OnMouseDoublePressed(this, (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2A00
// Name: public: virtual void CDmePresetGroupListPanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupListPanel::OnPanelDropped(
        CDmePresetGroupListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  int v4; // eax
  KeyValues *v5; // eax
  const char *String; // ebx
  const char *v7; // eax
  const char *v8; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( msgList->m_Size != 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( this->m_pPresetGroupPanel != nullptr )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
      this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
      v4 = this->GetItemIDFromRow(this, a2: row);
      v5 = this->GetItem(this, a2: v4);
      if ( v5 != nullptr )
      {
        String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
        v7 = KeyValues::GetString(this: v3, keyName: "presetGroupName", defaultValue: defaultValue);
        if ( v7 != nullptr )
        {
          CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(
            this: this->m_pPresetGroupPanel,
            pDragGroupName: v7,
            pDropGroupName: String);
        }
        else
        {
          v8 = KeyValues::GetString(this: v3, keyName: "presetName", defaultValue: defaultValue);
          if ( v8 != nullptr )
            CDmePresetGroupEditorPanel::MovePresetIntoGroup(
              this: this->m_pPresetGroupPanel,
              pPresetName: v8,
              pSrcGroupName: nullptr,
              pDstGroupName: String);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2AF0
// Name: public: virtual void CDmePresetGroupEditorFrame::NotifyDataChanged(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorFrame::NotifyDataChanged(
        CDmePresetGroupEditorFrame *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 132) + 136))(a1: (char *)this - 528) != 0
    && nNotifySource != 6 )
  {
    CDmePresetGroupEditorPanel::RefreshAnimationSet(this: *(CDmePresetGroupEditorPanel **)&this->m_OnDelete_register);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2B30
// Name: public: void CDmePresetGroupEditorPanel::SetAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::SetAnimationSetClip(
        CDmePresetGroupEditorPanel *this,
        CDmeFilmClip *pFilmClip)
{
  DmElementHandle_t BufferType; // eax

  if ( pFilmClip != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pFilmClip);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeFilmClip,0>::Set(this: &this->m_hFilmClip, h: BufferType);
  CDmePresetGroupEditorPanel::RefreshAnimationSet(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A2B70
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMoveGroupUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMoveGroupUp(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) == 1 )
  {
    v2 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
    v3 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v2);
    v4 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v3 - 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v2);
      v6 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v4);
      String = KeyValues::GetString(this: v6, keyName: "presetGroupName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(this, pDragGroupName: v7, pDropGroupName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2C20
// Name: public: virtual void CDmePresetGroupEditorPanel::OnMoveGroupDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePresetGroupEditorPanel::OnMoveGroupDown(CDmePresetGroupEditorPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  KeyValues *v5; // edi
  KeyValues *v6; // ebx
  const char *v7; // eax
  const char *String; // [esp-Ch] [ebp-10h]

  if ( this->m_pPresetGroupList->GetSelectedItemsCount(this: this->m_pPresetGroupList) == 1 )
  {
    v2 = this->m_pPresetGroupList->GetSelectedItem(this: this->m_pPresetGroupList, a2: 0);
    v3 = this->m_pPresetGroupList->GetItemCurrentRow(this: this->m_pPresetGroupList, a2: v2);
    v4 = this->m_pPresetGroupList->GetItemIDFromRow(this: this->m_pPresetGroupList, a2: v3 + 1);
    if ( v4 >= 0 )
    {
      v5 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v2);
      v6 = this->m_pPresetGroupList->GetItem(this: this->m_pPresetGroupList, a2: v4);
      String = KeyValues::GetString(this: v5, keyName: "presetGroupName", defaultValue: defaultValue);
      v7 = KeyValues::GetString(this: v6, keyName: "presetGroupName", defaultValue: defaultValue);
      CDmePresetGroupEditorPanel::MovePresetGroupInFrontOf(this, pDragGroupName: v7, pDropGroupName: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049DEF0
// Name: class CDmePresetGroup __near * CreateElement<class CDmePresetGroup>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePresetGroup *__cdecl CreateElement<CDmePresetGroup>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmePresetGroup::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmePresetGroup::m_classType.u) != 0 )
  {
    return (CDmePresetGroup *)v5;
  }
  else
  {
    return nullptr;
  }
}

} // namespace sceneviewer
