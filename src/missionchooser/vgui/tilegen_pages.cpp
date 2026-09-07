// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/tilegen_pages.cpp
// Functions: 68
// ============================================================

#include "missionchooser\vgui\tilegen_pages.h"

//------------------------------------------------------------------------------
// Address: 0x1002C470
// Name: public: static char const __near * CTileGenLayoutPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTileGenLayoutPage::GetPanelClassName()
{
  return "CTileGenLayoutPage";
}

//------------------------------------------------------------------------------
// Address: 0x1002C480
// Name: public: static char const __near * CTilegenKVEditorPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTilegenKVEditorPage::GetPanelClassName()
{
  return "CTilegenKVEditorPage";
}

//------------------------------------------------------------------------------
// Address: 0x1002C490
// Name: public: static char const __near * CTilegenLayoutSystemPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTilegenLayoutSystemPage::GetPanelClassName()
{
  return "CTilegenLayoutSystemPage";
}

//------------------------------------------------------------------------------
// Address: 0x1002C4A0
// Name: public: virtual void CTileGenLayoutPage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenLayoutPage::ApplySchemeSettings(CTileGenLayoutPage *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(this, a2: "TileGenLayoutPage.res", a3: "TILEGEN", a4: nullptr, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002C510
// Name: public: virtual struct vgui::PanelMap_t __near * CTilegenKVEditorPage::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall CTilegenKVEditorPage::GetPanelMap(CTilegenKVEditorPage *this)
{
  return &CTilegenKVEditorPage::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x1002C520
// Name: public: virtual void CTilegenKVEditorPage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenKVEditorPage::ApplySchemeSettings(CTilegenKVEditorPage *this, vgui::IScheme *pScheme)
{
  unsigned int v3; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  this->m_pTree->SetFont(this: this->m_pTree, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1002C560
// Name: public: virtual void CTilegenKVEditorPage::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenKVEditorPage::OnCommand(CTilegenKVEditorPage *this, const char *command)
{
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // edx
  vgui::MessageBox *v5; // eax
  vgui::MessageBox *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  char fullPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( _V_stricmp(s1: command, s2: "Save") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "New") != 0 )
      vgui::Panel::OnCommand(this, command);
    else
      this->SaveNew(this);
    return;
  }
  v3 = this->GetKeyValues(this);
  if ( v3 == nullptr )
    goto LABEL_17;
  v4 = g_pFullFileSystem != nullptr ? &g_pFullFileSystem->IBaseFileSystem : nullptr;
  if ( KeyValues::SaveToFile(this: v3, filesystem: v4, resourceName: this->m_szFilename, pathID: "GAME") )
    goto LABEL_17;
  if ( p4 == nullptr )
  {
    VGUIMessageBox(
      pParent: this,
      pTitle: "Save Error",
      pMsg: "Failed to save %s.  Make sure file is checked out from Perforce.",
      this->m_szFilename);
    goto LABEL_17;
  }
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: this->m_szFilename,
    a3: "GAME",
    a4: fullPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( !p4->IsFileInPerforce(this: p4, a2: fullPath) )
  {
LABEL_17:
    this->UpdateList(this);
    return;
  }
  v5 = (vgui::MessageBox *)operator new(nSize: 0x234u);
  if ( v5 != nullptr )
    v6 = vgui::MessageBox::MessageBox(
           this: v5,
           title: "Check Out?",
           text: "File is not writeable. Would you like to check it out from Perforce?",
           parent: this);
  else
    v6 = nullptr;
  vgui::MessageBox::SetCancelButtonVisible(this: v6, state: true);
  v6->SetOKButtonText_2(this: v6, a2: "#MessageBox_Yes");
  vgui::MessageBox::SetCancelButtonText(this: v6, buttonText: "#MessageBox_No");
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "CheckOutFromP4", firstKey: "file", firstValue: fullPath);
  else
    v8 = nullptr;
  v6->SetCommand(this: v6, a2: v8);
  v6->DoModal_2(this: v6, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002C710
// Name: public: virtual void CTilegenKVEditorPage::OnCheckOutFromP4(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenKVEditorPage::OnCheckOutFromP4(CTilegenKVEditorPage *this, KeyValues *pKV)
{
  const char *String; // edi
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // edx

  String = KeyValues::GetString(this: pKV, keyName: "file", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( p4->OpenFileForEdit(this: p4, a2: String) )
    {
      v4 = this->GetKeyValues(this);
      if ( g_pFullFileSystem != nullptr )
        v5 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v5 = nullptr;
      if ( !KeyValues::SaveToFile(this: v4, filesystem: v5, resourceName: this->m_szFilename, pathID: "GAME") )
        VGUIMessageBox(
          pParent: this,
          pTitle: "Save Error!",
          pMsg: "Checked out '%s' from Perforce, but failed to save file.",
          String);
    }
    else
    {
      VGUIMessageBox(pParent: this, pTitle: "P4 Error!", pMsg: "Failed to check out '%s' from Perforce.", String);
    }
  }
  this->UpdateList(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002C7B0
// Name: public: virtual void CTilegenLayoutSystemPage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenLayoutSystemPage::ApplySchemeSettings(CTilegenLayoutSystemPage *this, vgui::IScheme *pScheme)
{
  unsigned int v3; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  this->m_pTree->SetFont(this: this->m_pTree, a2: v3);
  this->LoadControlSettings(this, a2: "TilegenLayoutSystemPage.res", a3: "TILEGEN", a4: nullptr, a5: nullptr);
  LOBYTE(pScheme) = this->m_szFilename[0] != 0;
  this->m_pReloadMissionButton->SetVisible(this: this->m_pReloadMissionButton, a2: (bool)pScheme);
  this->m_pSaveButton->SetVisible(this: this->m_pSaveButton, a2: (bool)pScheme);
  this->m_pGenerateButton->SetVisible(this: this->m_pGenerateButton, a2: (bool)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1002C850
// Name: public: virtual void CTilegenLayoutSystemPage::OnTreeViewItemSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenLayoutSystemPage::OnTreeViewItemSelected(CTilegenLayoutSystemPage *this, int nItemIndex)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *String; // eax
  KeyValues *m_pMissionFileKV; // ebx
  const char *v7; // edi
  KeyValues *FileByName; // eax
  vgui::Label_vtbl *v9; // ebx
  int v10; // eax

  v3 = this->m_pTree->GetItemData(this: this->m_pTree, a2: nItemIndex);
  v4 = v3;
  if ( v3 != nullptr && KeyValues::FindKey(this: v3, keyName: "Filename", bCreate: false) != nullptr )
  {
    String = KeyValues::GetString(this: v4, keyName: "Filename", defaultValue: szDescription);
    m_pMissionFileKV = this->m_pEditor->m_pMissionFileKV;
    v7 = String;
    FileByName = CASW_KeyValuesDatabase::GetFileByName(this: this->m_pNewMissionDatabase, pFilename: String);
    if ( m_pMissionFileKV != FileByName )
    {
      CLayoutSystemKVEditor::SetMissionData(this: this->m_pEditor, pMissionFileKV: FileByName);
      v9 = this->m_pFilenameLabel->CTilegenKVEditorPage::__vftable;
      v10 = _V_strlen(str: "tilegen/");
      v9->SetText(this: this->m_pFilenameLabel, a2: &v7[v10]);
      this->m_pReloadMissionButton->SetVisible(this: this->m_pReloadMissionButton, a2: true);
      this->m_pSaveButton->SetVisible(this: this->m_pSaveButton, a2: true);
      this->m_pGenerateButton->SetVisible(this: this->m_pGenerateButton, a2: true);
      V_snprintf(pDest: this->m_szFilename, maxLen: 260, pFormat: "%s", v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C950
// Name: public: virtual void CTilegenLayoutSystemPage::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTilegenLayoutSystemPage::OnFileSelected(
        CTilegenLayoutSystemPage *this@<ecx>,
        int a2@<ebx>,
        const char *pFullPath)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  IBaseFileSystem *v6; // eax
  int v7; // eax
  vgui::MessageBox *v8; // eax
  vgui::MessageBox *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  vgui::Label_vtbl *v13; // [esp+8h] [ebp-4h]

  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFullPath, a3: nullptr) )
  {
    VGUIMessageBox(
      pParent: this,
      pTitle: "Save Error",
      pMsg: "A layout system already exists with filename %s.",
      pFullPath);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Mission");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::SaveToFile(this: v5, filesystem: v6, resourceName: pFullPath, pathID: nullptr) )
    {
      CLayoutSystemKVEditor::SetMissionData(this: this->m_pEditor, pMissionFileKV: v5);
      this->m_pReloadMissionButton->SetVisible(this: this->m_pReloadMissionButton, a2: true);
      this->m_pSaveButton->SetVisible(this: this->m_pSaveButton, a2: true);
      this->m_pGenerateButton->SetVisible(this: this->m_pGenerateButton, a2: true);
      if ( g_pFullFileSystem->FullPathToRelativePath(
             this: g_pFullFileSystem,
             a2: pFullPath,
             a3: this->m_szFilename,
             a4: 260) )
      {
        v13 = this->m_pFilenameLabel->CTilegenKVEditorPage::__vftable;
        v7 = _V_strlen(str: "tilegen/");
        v13->SetText(this: this->m_pFilenameLabel, a2: &this->m_szFilename[v7]);
        CASW_KeyValuesDatabase::AddFile(
          this: this->m_pNewMissionDatabase,
          pKeyValues: v5,
          pFilename: this->m_szFilename);
        this->UpdateList(this);
        if ( p4 != nullptr )
        {
          v8 = (vgui::MessageBox *)operator new(nSize: 0x234u);
          if ( v8 != nullptr )
            v9 = vgui::MessageBox::MessageBox(
                   this: v8,
                   title: "Add to P4?",
                   text: "Would you like to add this mission to perforce?",
                   parent: this);
          else
            v9 = nullptr;
          vgui::MessageBox::SetCancelButtonVisible(this: v9, state: true);
          ((void (__thiscall *)(vgui::MessageBox *, const char *, int))v9->SetOKButtonText_2)(
            a1: v9,
            a2: "#MessageBox_Yes",
            a3: a2);
          vgui::MessageBox::SetCancelButtonText(this: v9, buttonText: "#MessageBox_No");
          v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v10 != nullptr )
            v11 = KeyValues::KeyValues(this: v10, setName: "AddToP4", firstKey: "file", firstValue: pFullPath);
          else
            v11 = nullptr;
          v9->SetCommand(this: v9, a2: v11);
          v9->DoModal_2(this: v9, a2: nullptr);
        }
      }
      else
      {
        _Warning(a1: "Failed to convert this to a relative path: %s\n", pFullPath);
      }
    }
    else
    {
      VGUIMessageBox(pParent: this, pTitle: "Save Error", pMsg: "Failed to save new file %s.", pFullPath);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CB60
// Name: public: virtual void CTilegenLayoutSystemPage::OnAddToP4(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenLayoutSystemPage::OnAddToP4(CTilegenLayoutSystemPage *this, KeyValues *pKV)
{
  const char *String; // esi

  String = KeyValues::GetString(this: pKV, keyName: "file", defaultValue: nullptr);
  if ( String != nullptr && !p4->OpenFileForAdd(this: p4, a2: String) )
    VGUIMessageBox(pParent: this, pTitle: "P4 Error!", pMsg: "Failed to add '%s' to Perforce.", String);
}

//------------------------------------------------------------------------------
// Address: 0x1002CBB0
// Name: protected: virtual void CTilegenLayoutSystemPage::SaveNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenLayoutSystemPage::SaveNew(CTilegenLayoutSystemPage *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi
  char buffer[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: nullptr,
           title: "Save New Layout System As...",
           bOpenOnly: false,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s/tilegen/new_missions", g_gamedir);
  vgui::FileOpenDialog::SetStartDirectory(this: v3, dir: buffer);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: "*.txt",
    filterName: "Layout System file (*.txt)",
    bActive: true,
    pFilterInfo: nullptr);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002CC50
// Name: protected: virtual class KeyValues __near * CTilegenLayoutSystemPage::GetKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CTilegenLayoutSystemPage::GetKeyValues(CTilegenLayoutSystemPage *this)
{
  return this->m_pEditor->m_pMissionFileKV;
}

//------------------------------------------------------------------------------
// Address: 0x1002CC70
// Name: public: CTileGenLayoutPage::CTileGenLayoutPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTileGenLayoutPage *__thiscall CTileGenLayoutPage::CTileGenLayoutPage(
        CTileGenLayoutPage *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CScrollingWindow *v7; // eax
  CScrollingWindow *v8; // eax
  CMapLayoutPanel *v9; // eax
  CMapLayoutPanel *v10; // eax
  CScrollingWindow *m_pScrollingWindow; // ecx

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CTileGenLayoutPage_vtbl *)&CTileGenLayoutPage::`vftable';
  if ( `CTileGenLayoutPage::ChainToMap'::`2'::chained == 0 )
  {
    `CTileGenLayoutPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTileGenLayoutPage");
    v4->pfnClassName = CTileGenLayoutPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CTileGenLayoutPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTileGenLayoutPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTileGenLayoutPage");
    v5->pfnClassName = CTileGenLayoutPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CTileGenLayoutPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTileGenLayoutPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTileGenLayoutPage");
    v6->pfnClassName = CTileGenLayoutPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  v7 = (CScrollingWindow *)operator new(nSize: 0x168u);
  if ( v7 != nullptr )
    v8 = CScrollingWindow::CScrollingWindow(this: v7, parent: this, name: "ScrollingWindow");
  else
    v8 = nullptr;
  this->m_pScrollingWindow = v8;
  v9 = (CMapLayoutPanel *)operator new(nSize: 0x158u);
  if ( v9 != nullptr )
    v10 = CMapLayoutPanel::CMapLayoutPanel(this: v9, parent: this, name: "MapLayoutPanel");
  else
    v10 = nullptr;
  m_pScrollingWindow = this->m_pScrollingWindow;
  this->m_pMapLayoutPanel = v10;
  CScrollingWindow::SetChildPanel(this: m_pScrollingWindow, pPanel: v10);
  CScrollingWindow::MoveToLowerCenter(this: this->m_pScrollingWindow);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002CDA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CTileGenLayoutPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTileGenLayoutPage::GetMessageMap(CTileGenLayoutPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTileGenLayoutPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTileGenLayoutPage::GetMessageMap'::`2'::s_pMap;
  `CTileGenLayoutPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTileGenLayoutPage");
  `CTileGenLayoutPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002CDD0
// Name: public: virtual struct PanelAnimationMap __near * CTileGenLayoutPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTileGenLayoutPage::GetAnimMap(CTileGenLayoutPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CTileGenLayoutPage");
}

//------------------------------------------------------------------------------
// Address: 0x1002CDE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTileGenLayoutPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTileGenLayoutPage::GetKBMap(CTileGenLayoutPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTileGenLayoutPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTileGenLayoutPage::GetKBMap'::`2'::s_pMap;
  `CTileGenLayoutPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTileGenLayoutPage");
  `CTileGenLayoutPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002CE40
// Name: protected: int CTilegenKVEditorPage::RecursiveCreateFolderNodes(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenKVEditorPage::RecursiveCreateFolderNodes(
        CTilegenKVEditorPage *this,
        int iParentIndex,
        char *szFilename)
{
  const char *v3; // edi
  int v5; // eax
  const char *v6; // eax
  KeyValues *v8; // eax
  const char *String; // eax
  KeyValues *v10; // eax
  int v11; // eax
  vgui::TreeView *m_pTree; // ecx
  int v13; // eax
  int iChild; // [esp+Ch] [ebp-8h]
  char *szFolder; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  KeyValues *ia; // [esp+1Ch] [ebp+8h]

  v3 = szFilename;
  v5 = _V_strlen(str: szFilename);
  v6 = V_strnchr(pStr: v3, c: 92, n: v5);
  szFolder = (char *)v6;
  if ( v6 == nullptr )
    return iParentIndex;
  while ( 1 )
  {
    *v6 = 0;
    i = 0;
    if ( this->m_pTree->GetNumChildren(this: this->m_pTree, a2: iParentIndex) > 0 )
      break;
LABEL_7:
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      ia = KeyValues::KeyValues(this: v10, setName: "FolderEntry");
    else
      ia = nullptr;
    KeyValues::SetString(this: ia, keyName: "Text", value: v3);
    v11 = this->m_pTree->AddItem(this: this->m_pTree, a2: ia, a3: iParentIndex);
    m_pTree = this->m_pTree;
    iParentIndex = v11;
    szFilename = (char *)-8355712;
    m_pTree->SetItemFgColor(this: m_pTree, a2: v11, a3: (const Color *)&szFilename);
    v3 = szFolder + 1;
    v13 = _V_strlen(str: szFolder + 1);
    szFolder = (char *)V_strnchr(pStr: szFolder + 1, c: 92, n: v13);
    if ( szFolder == nullptr )
      return iParentIndex;
    v6 = szFolder;
  }
  while ( 1 )
  {
    iChild = this->m_pTree->GetChild(this: this->m_pTree, a2: iParentIndex, a3: i);
    v8 = this->m_pTree->GetItemData(this: this->m_pTree, a2: iChild);
    String = KeyValues::GetString(this: v8, keyName: "Text", defaultValue: szDescription);
    if ( _V_stricmp(s1: v3, s2: String) == 0 )
      return iChild;
    if ( ++i >= this->m_pTree->GetNumChildren(this: this->m_pTree, a2: iParentIndex) )
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CFA0
// Name: protected: void CTilegenKVEditorPage::UpdateListHelper(class CASW_KeyValuesDatabase __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenKVEditorPage::UpdateListHelper(
        CTilegenKVEditorPage *this,
        CASW_KeyValuesDatabase *pMissionDatabase,
        const char *pFolderName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int v6; // eax
  bool v8; // cc
  int v9; // esi
  int v10; // eax
  int FolderNodes; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  int v14; // eax
  vgui::TreeView *m_pTree; // ecx
  char szMissionFilename[260]; // [esp+Ch] [ebp-114h] BYREF
  int iNode; // [esp+110h] [ebp-10h]
  int i; // [esp+114h] [ebp-Ch]
  int missionIndex; // [esp+118h] [ebp-8h]
  int v20; // [esp+11Ch] [ebp-4h] BYREF
  CASW_KeyValuesDatabase *pMissionDatabasea; // [esp+128h] [ebp+8h]

  this->m_pTree->RemoveAll(this: this->m_pTree);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "TVI");
  else
    v5 = nullptr;
  KeyValues::SetString(this: v5, keyName: "Text", value: "Missions");
  v6 = this->m_pTree->AddItem(this: this->m_pTree, a2: v5, a3: -1);
  v8 = pMissionDatabase->m_Files.m_Size <= 0;
  v9 = v6;
  missionIndex = v6;
  i = 0;
  if ( !v8 )
  {
    pMissionDatabasea = nullptr;
    do
    {
      V_strncpy(
        pDest: szMissionFilename,
        pSrc: &pMissionDatabasea->m_RootFolder[(unsigned int)pMissionDatabase->m_Files.m_Memory.m_pMemory],
        maxLen: 260);
      V_FixSlashes(pname: szMissionFilename, separator: 92);
      v10 = _V_strlen(str: pFolderName);
      FolderNodes = CTilegenKVEditorPage::RecursiveCreateFolderNodes(
                      this,
                      iParentIndex: v9,
                      szFilename: &szMissionFilename[v10]);
      iNode = FolderNodes;
      if ( FolderNodes != v9 )
        this->m_pTree->ExpandItem(this: this->m_pTree, a2: FolderNodes, a3: true);
      V_strncpy(
        pDest: szMissionFilename,
        pSrc: &pMissionDatabasea->m_RootFolder[(unsigned int)pMissionDatabase->m_Files.m_Memory.m_pMemory],
        maxLen: 260);
      V_FileBase(in: szMissionFilename, out: szMissionFilename, maxlen: 260);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "MissionEntry");
      else
        v13 = nullptr;
      KeyValues::SetString(this: v13, keyName: "Text", value: szMissionFilename);
      KeyValues::SetString(
        this: v13,
        keyName: "Filename",
        value: &pMissionDatabasea->m_RootFolder[(unsigned int)pMissionDatabase->m_Files.m_Memory.m_pMemory]);
      v14 = this->m_pTree->AddItem(this: this->m_pTree, a2: v13, a3: iNode);
      m_pTree = this->m_pTree;
      v20 = -1;
      m_pTree->SetItemFgColor(this: m_pTree, a2: v14, a3: (const Color *)&v20);
      pMissionDatabasea = (CASW_KeyValuesDatabase *)((char *)pMissionDatabasea + 264);
      v9 = missionIndex;
      ++i;
    }
    while ( i < pMissionDatabase->m_Files.m_Size );
  }
  this->m_pTree->ExpandItem(this: this->m_pTree, a2: v9, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002D180
// Name: public: virtual void CTilegenLayoutSystemPage::UpdateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenLayoutSystemPage::UpdateList(CTilegenLayoutSystemPage *this)
{
  CTilegenKVEditorPage::UpdateListHelper(
    this,
    pMissionDatabase: this->m_pNewMissionDatabase,
    pFolderName: "tilegen/new_missions/");
}

//------------------------------------------------------------------------------
// Address: 0x1002D1A0
// Name: public: static void CTilegenKVEditorPage::PanelMessageFunc_OnTreeViewItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTilegenKVEditorPage::PanelMessageFunc_OnTreeViewItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CTilegenKVEditorPage::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded )
  {
    `CTilegenKVEditorPage::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CTilegenKVEditorPage");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TreeViewItemSelected";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemIndex";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D240
// Name: public: static void CTilegenKVEditorPage::PanelMessageFunc_OnCheckOutFromP4::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTilegenKVEditorPage::PanelMessageFunc_OnCheckOutFromP4::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CTilegenKVEditorPage::PanelMessageFunc_OnCheckOutFromP4::InitVar'::`2'::bAdded )
  {
    `CTilegenKVEditorPage::PanelMessageFunc_OnCheckOutFromP4::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CTilegenKVEditorPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CTilegenKVEditorPage");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "CheckOutFromP4";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D2D0
// Name: public: static void CTilegenLayoutSystemPage::PanelMessageFunc_OnAddToP4::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTilegenLayoutSystemPage::PanelMessageFunc_OnAddToP4::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CTilegenLayoutSystemPage::PanelMessageFunc_OnAddToP4::InitVar'::`2'::bAdded )
  {
    `CTilegenLayoutSystemPage::PanelMessageFunc_OnAddToP4::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRuleInstanceNodePanel::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CTilegenLayoutSystemPage");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "AddToP4";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D360
// Name: public: CTilegenKVEditorPage::CTilegenKVEditorPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenKVEditorPage *__thiscall CTilegenKVEditorPage::CTilegenKVEditorPage(
        CTilegenKVEditorPage *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TreeView *v7; // eax
  vgui::TreeView *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CTilegenKVEditorPage_vtbl *)&CTilegenKVEditorPage::`vftable';
  if ( `CTilegenKVEditorPage::ChainToMap'::`2'::chained == 0 )
  {
    `CTilegenKVEditorPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTilegenKVEditorPage");
    v4->pfnClassName = CTilegenKVEditorPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CTilegenKVEditorPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTilegenKVEditorPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTilegenKVEditorPage");
    v5->pfnClassName = CTilegenKVEditorPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CTilegenKVEditorPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTilegenKVEditorPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTilegenKVEditorPage");
    v6->pfnClassName = CTilegenKVEditorPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CTilegenKVEditorPage::PanelMessageFunc_OnTreeViewItemSelected::InitVar(a1: (int)&savedregs);
  CTilegenKVEditorPage::PanelMessageFunc_OnCheckOutFromP4::InitVar(a1: (int)&savedregs);
  v7 = (vgui::TreeView *)operator new(nSize: 0x1BCu);
  if ( v7 != nullptr )
    v8 = vgui::TreeView::TreeView(this: v7, parent: this, panelName: "Tree");
  else
    v8 = nullptr;
  this->m_pTree = v8;
  vgui::Panel::MakeReadyForUse(this: v8);
  vgui::TreeView::SetSortFunc(this: this->m_pTree, pSortFunc: `anonymous namespace'::GroupTreeSortFunc);
  this->m_szFilename[0] = 0;
  v9 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "FilenameLabel", text: szDescription);
  else
    v10 = nullptr;
  this->m_pFilenameLabel = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "SaveButton",
            text: "Save",
            pActionSignalTarget: this,
            pCmd: "Save");
  else
    v12 = nullptr;
  this->m_pSaveButton = v12;
  v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v13 != nullptr )
    this->m_pNewButton = vgui::Button::Button(
                           this: v13,
                           parent: this,
                           panelName: "NewButton",
                           text: "New",
                           pActionSignalTarget: this,
                           pCmd: "New");
  else
    this->m_pNewButton = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D510
// Name: public: virtual struct vgui::PanelMessageMap __near * CTilegenKVEditorPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTilegenKVEditorPage::GetMessageMap(CTilegenKVEditorPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTilegenKVEditorPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTilegenKVEditorPage::GetMessageMap'::`2'::s_pMap;
  `CTilegenKVEditorPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTilegenKVEditorPage");
  `CTilegenKVEditorPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D540
// Name: public: virtual struct PanelAnimationMap __near * CTilegenKVEditorPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTilegenKVEditorPage::GetAnimMap(CTilegenKVEditorPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CTilegenKVEditorPage");
}

//------------------------------------------------------------------------------
// Address: 0x1002D550
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTilegenKVEditorPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTilegenKVEditorPage::GetKBMap(CTilegenKVEditorPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTilegenKVEditorPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTilegenKVEditorPage::GetKBMap'::`2'::s_pMap;
  `CTilegenKVEditorPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTilegenKVEditorPage");
  `CTilegenKVEditorPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D580
// Name: public: CTilegenLayoutSystemPage::CTilegenLayoutSystemPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenLayoutSystemPage *__thiscall CTilegenLayoutSystemPage::CTilegenLayoutSystemPage(
        CTilegenLayoutSystemPage *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CTilegenMissionPreprocessor *v7; // eax
  int v8; // edi
  CLayoutSystemKVEditor *v9; // eax
  CLayoutSystemKVEditor *v10; // eax
  CTilegenMissionPreprocessor *m_pPreprocessor; // edx
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  CASW_KeyValuesDatabase *v18; // eax
  CASW_KeyValuesDatabase *v19; // eax
  CASW_KeyValuesDatabase *v20; // eax
  CASW_KeyValuesDatabase *v21; // eax
  int v22; // ebx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CTilegenKVEditorPage::CTilegenKVEditorPage(this, pParent, pName);
  this->__vftable = (CTilegenLayoutSystemPage_vtbl *)&CTilegenLayoutSystemPage::`vftable';
  if ( `CTilegenLayoutSystemPage::ChainToMap'::`2'::chained == 0 )
  {
    `CTilegenLayoutSystemPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTilegenLayoutSystemPage");
    v4->pfnClassName = CTilegenLayoutSystemPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CTilegenKVEditorPage");
  }
  if ( `CTilegenLayoutSystemPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTilegenLayoutSystemPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTilegenLayoutSystemPage");
    v5->pfnClassName = CTilegenLayoutSystemPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CTilegenKVEditorPage");
  }
  if ( `CTilegenLayoutSystemPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTilegenLayoutSystemPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTilegenLayoutSystemPage");
    v6->pfnClassName = CTilegenLayoutSystemPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CTilegenKVEditorPage");
  }
  CTilegenLayoutSystemPage::PanelMessageFunc_OnAddToP4::InitVar(a1: (int)&savedregs);
  v7 = (CTilegenMissionPreprocessor *)operator new(nSize: 0x2Cu);
  v8 = 0;
  if ( v7 != nullptr )
  {
    v7->m_Enums.m_Memory.m_pMemory = nullptr;
    v7->m_Enums.m_Memory.m_nAllocationCount = 0;
    v7->m_Enums.m_Memory.m_nGrowSize = 0;
    v7->m_Enums.m_Size = 0;
    v7->m_Enums.m_pElements = nullptr;
    v7->m_Rules.m_Memory.m_pMemory = nullptr;
    v7->m_Rules.m_Memory.m_nAllocationCount = 0;
    v7->m_Rules.m_Memory.m_nGrowSize = 0;
    v7->m_Rules.m_Size = 0;
    v7->m_Rules.m_pElements = nullptr;
    v7->m_nUniqueIndex = 0;
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pPreprocessor = v7;
  v9 = (CLayoutSystemKVEditor *)operator new(nSize: 0x194u);
  if ( v9 != nullptr )
    v10 = CLayoutSystemKVEditor::CLayoutSystemKVEditor(this: v9, pParent: this, pName: "Editor");
  else
    v10 = nullptr;
  m_pPreprocessor = this->m_pPreprocessor;
  this->m_pEditor = v10;
  v10->m_pPreprocessor = m_pPreprocessor;
  v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "GenerateButton",
            text: "Generate",
            pActionSignalTarget: this,
            pCmd: "Generate");
  else
    v13 = nullptr;
  this->m_pGenerateButton = v13;
  v14 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "ReloadRulesButton",
            text: "Reload Rules",
            pActionSignalTarget: this,
            pCmd: "ReloadRules");
  else
    v15 = nullptr;
  this->m_pReloadRulesButton = v15;
  v16 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "ReloadMissionButton",
            text: "Reload",
            pActionSignalTarget: this,
            pCmd: "ReloadMission");
  else
    v17 = nullptr;
  this->m_pReloadMissionButton = v17;
  v18 = (CASW_KeyValuesDatabase *)operator new(nSize: 0x118u);
  if ( v18 != nullptr )
    v19 = CASW_KeyValuesDatabase::CASW_KeyValuesDatabase(this: v18);
  else
    v19 = nullptr;
  this->m_pNewMissionDatabase = v19;
  CASW_KeyValuesDatabase::LoadFiles(this: v19, pFolderName: "tilegen/new_missions/");
  v20 = (CASW_KeyValuesDatabase *)operator new(nSize: 0x118u);
  if ( v20 != nullptr )
    v21 = CASW_KeyValuesDatabase::CASW_KeyValuesDatabase(this: v20);
  else
    v21 = nullptr;
  this->m_pRulesDatabase = v21;
  CASW_KeyValuesDatabase::LoadFiles(this: v21, pFolderName: "tilegen/rules/");
  if ( this->m_pRulesDatabase->m_Files.m_Size > 0 )
  {
    v22 = 0;
    do
    {
      CTilegenMissionPreprocessor::ParseAndStripRules(
        this: this->m_pPreprocessor,
        pRulesKV: this->m_pRulesDatabase->m_Files.m_Memory.m_pMemory[v22].m_pKeyValues);
      ++v8;
      ++v22;
    }
    while ( v8 < this->m_pRulesDatabase->m_Files.m_Size );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CTilegenLayoutSystemPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTilegenLayoutSystemPage::GetMessageMap(CTilegenLayoutSystemPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTilegenLayoutSystemPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTilegenLayoutSystemPage::GetMessageMap'::`2'::s_pMap;
  `CTilegenLayoutSystemPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTilegenLayoutSystemPage");
  `CTilegenLayoutSystemPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D820
// Name: public: virtual struct PanelAnimationMap __near * CTilegenLayoutSystemPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTilegenLayoutSystemPage::GetAnimMap(CTilegenLayoutSystemPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CTilegenLayoutSystemPage");
}

//------------------------------------------------------------------------------
// Address: 0x1002D830
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTilegenLayoutSystemPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTilegenLayoutSystemPage::GetKBMap(CTilegenLayoutSystemPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTilegenLayoutSystemPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTilegenLayoutSystemPage::GetKBMap'::`2'::s_pMap;
  `CTilegenLayoutSystemPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTilegenLayoutSystemPage");
  `CTilegenLayoutSystemPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D860
// Name: public: virtual void CTilegenLayoutSystemPage::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenLayoutSystemPage::OnCommand(CTilegenLayoutSystemPage *this, const char *pCommand)
{
  KeyValues *FileByName; // eax
  CTilegenMissionPreprocessor *m_pPreprocessor; // ebx
  int v5; // edi
  CTilegenMissionPreprocessor *v6; // eax
  CASW_KeyValuesDatabase *m_pRulesDatabase; // ecx
  int v8; // ebx

  if ( _V_stricmp(s1: pCommand, s2: "Generate") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "ReloadMission") != 0 )
    {
      if ( _V_stricmp(s1: pCommand, s2: "ReloadRules") != 0 )
      {
        CTilegenKVEditorPage::OnCommand(this, command: pCommand);
      }
      else
      {
        m_pPreprocessor = this->m_pPreprocessor;
        v5 = 0;
        if ( m_pPreprocessor != nullptr )
        {
          CTilegenMissionPreprocessor::~CTilegenMissionPreprocessor(this: this->m_pPreprocessor);
          free(pMem: m_pPreprocessor);
        }
        v6 = (CTilegenMissionPreprocessor *)operator new(nSize: 0x2Cu);
        if ( v6 != nullptr )
        {
          v6->m_Enums.m_Memory.m_pMemory = nullptr;
          v6->m_Enums.m_Memory.m_nAllocationCount = 0;
          v6->m_Enums.m_Memory.m_nGrowSize = 0;
          v6->m_Enums.m_Size = 0;
          v6->m_Enums.m_pElements = nullptr;
          v6->m_Rules.m_Memory.m_pMemory = nullptr;
          v6->m_Rules.m_Memory.m_nAllocationCount = 0;
          v6->m_Rules.m_Memory.m_nGrowSize = 0;
          v6->m_Rules.m_Size = 0;
          v6->m_Rules.m_pElements = nullptr;
          v6->m_nUniqueIndex = 0;
        }
        else
        {
          v6 = nullptr;
        }
        m_pRulesDatabase = this->m_pRulesDatabase;
        this->m_pPreprocessor = v6;
        CASW_KeyValuesDatabase::LoadFiles(this: m_pRulesDatabase, pFolderName: "tilegen/rules/");
        if ( this->m_pRulesDatabase->m_Files.m_Size > 0 )
        {
          v8 = 0;
          do
          {
            CTilegenMissionPreprocessor::ParseAndStripRules(
              this: this->m_pPreprocessor,
              pRulesKV: this->m_pRulesDatabase->m_Files.m_Memory.m_pMemory[v8].m_pKeyValues);
            ++v5;
            ++v8;
          }
          while ( v5 < this->m_pRulesDatabase->m_Files.m_Size );
        }
        this->m_pEditor->m_pPreprocessor = this->m_pPreprocessor;
        CLayoutSystemKVEditor::RecreateMissionPanel(this: this->m_pEditor);
      }
    }
    else if ( CASW_KeyValuesDatabase::ReloadFile(this: this->m_pNewMissionDatabase, pFilename: this->m_szFilename) != nullptr )
    {
      FileByName = CASW_KeyValuesDatabase::GetFileByName(
                     this: this->m_pNewMissionDatabase,
                     pFilename: this->m_szFilename);
      CLayoutSystemKVEditor::SetMissionData(this: this->m_pEditor, pMissionFileKV: FileByName);
    }
  }
  else if ( g_pTileGenDialog != nullptr )
  {
    CTileGenDialog::GenerateMission(this: g_pTileGenDialog, szMissionFile: this->m_szFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D9E0
// Name: public: virtual CTilegenLayoutSystemPage::~CTilegenLayoutSystemPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenLayoutSystemPage::~CTilegenLayoutSystemPage(CTilegenLayoutSystemPage *this)
{
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *m_pNewMissionDatabase; // edi
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *m_pRulesDatabase; // edi
  CTilegenMissionPreprocessor *m_pPreprocessor; // edi

  m_pNewMissionDatabase = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pNewMissionDatabase;
  this->__vftable = (CTilegenLayoutSystemPage_vtbl *)&CTilegenLayoutSystemPage::`vftable';
  if ( m_pNewMissionDatabase != nullptr )
  {
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: m_pNewMissionDatabase + 13);
    free(pMem: m_pNewMissionDatabase);
  }
  m_pRulesDatabase = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pRulesDatabase;
  if ( m_pRulesDatabase != nullptr )
  {
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: m_pRulesDatabase + 13);
    free(pMem: m_pRulesDatabase);
  }
  m_pPreprocessor = this->m_pPreprocessor;
  if ( m_pPreprocessor != nullptr )
  {
    CTilegenMissionPreprocessor::~CTilegenMissionPreprocessor(this: this->m_pPreprocessor);
    free(pMem: m_pPreprocessor);
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD0F0
// Name: _dynamic_initializer_for__CTilegenKVEditorPage::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenKVEditorPage::m_MessageMap__()
{
  *(_QWORD *)&CTilegenKVEditorPage::m_MessageMap[0].func = (unsigned int) __thiscall CTilegenKVEditorPage::`vcall'{952,{flat}};
  *((_QWORD *)&CTilegenKVEditorPage::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&CTilegenKVEditorPage::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&CTilegenKVEditorPage::m_MessageMap[0].nameSymbol = 0;
  CTilegenKVEditorPage::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FD140
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD150
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD160
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD170
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD180
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD190
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD1A0
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD1B0
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD1C0
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD1D0
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD1E0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD1F0
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD200
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD210
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD220
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD230
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD240
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD250
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD260
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD270
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD280
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD290
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD2A0
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD2B0
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD2C0
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD2D0
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD2E0
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD2F0
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD300
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD310
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD320
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD330
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100FD340
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}
