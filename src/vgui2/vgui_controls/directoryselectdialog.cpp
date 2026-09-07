// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/directoryselectdialog.cpp
// Functions: 30
// ============================================================

#include "vgui2\vgui_controls\directoryselectdialog.h"

//------------------------------------------------------------------------------
// Address: 0x102C50F0
// Name: public: static char const __near * vgui::DirectorySelectDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::DirectorySelectDialog::GetPanelClassName()
{
  return "DirectorySelectDialog";
}

//------------------------------------------------------------------------------
// Address: 0x102C5100
// Name: public: static char const __near * CreateDirectoryDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CreateDirectoryDialog::GetPanelClassName()
{
  return "CreateDirectoryDialog";
}

//------------------------------------------------------------------------------
// Address: 0x102C5110
// Name: protected: virtual void vgui::DirectorySelectDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::PerformLayout(vgui::DirectorySelectDialog *this)
{
  int Wide; // eax
  int v3; // eax
  int Tall; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-Ch] [ebp-10h]
  int v9; // [esp-4h] [ebp-8h]

  vgui::Frame::PerformLayout(this);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDriveCombo, x: 24, y: 30, wide: Wide - 48, tall: 24);
  v9 = vgui::Panel::GetTall(this) - 128;
  v3 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDirTree, x: 24, y: 64, wide: v3 - 48, tall: v9);
  Tall = vgui::Panel::GetTall(this);
  vgui::Panel::SetBounds(this: this->m_pCreateButton, x: 24, y: Tall - 48, wide: 104, tall: 24);
  v7 = vgui::Panel::GetTall(this) - 48;
  v5 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pSelectButton, x: v5 - 172, y: v7, wide: 72, tall: 24);
  v8 = vgui::Panel::GetTall(this) - 48;
  v6 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pCancelButton, x: v6 - 96, y: v8, wide: 72, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x102C51D0
// Name: protected: virtual void vgui::DirectorySelectDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::ApplySchemeSettings(
        vgui::DirectorySelectDialog *this,
        vgui::IScheme *pScheme)
{
  vgui::ImageList *v3; // eax
  vgui::Dar<unsigned long> *v4; // esi
  vgui::IImage *v5; // eax
  vgui::IImage *v6; // eax

  v3 = (vgui::ImageList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
    v4 = (vgui::Dar<unsigned long> *)vgui::ImageList::ImageList(this: v3, deleteImagesWhenDone: false);
  else
    v4 = nullptr;
  v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "Resource/icon_folder", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v4, elem: (unsigned int)v5);
  v6 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "Resource/icon_folder_selected", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v4, elem: (unsigned int)v6);
  this->m_pDirTree->SetImageList(this: this->m_pDirTree, a2: (vgui::ImageList *)v4, a3: true);
  vgui::Frame::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x102C5250
// Name: public: virtual void vgui::DirectorySelectDialog::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::DoModal(vgui::DirectorySelectDialog *this)
{
  vgui::IInput *v2; // edi
  vgui::IInput_vtbl *v3; // ebx
  int v4; // eax

  v2 = g_pVGuiInput;
  v3 = g_pVGuiInput->__vftable;
  v4 = this->GetVPanel(this);
  v3->SetAppModalSurface(this: v2, a2: v4);
  vgui::Frame::Activate(this);
  this->MoveToCenterOfScreen(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C5290
// Name: private: void vgui::DirectorySelectDialog::BuildDriveChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::BuildDriveChoices(vgui::DirectorySelectDialog *this)
{
  char *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  char drives[256]; // [esp+Ch] [ebp-108h] BYREF
  int itemID; // [esp+10Ch] [ebp-8h]
  int len; // [esp+110h] [ebp-4h]

  vgui::ComboBox::RemoveAll(this: this->m_pDriveCombo);
  memset(drives, 0, sizeof(drives));
  len = g_pVGuiSystem->GetAvailableDrives(this: g_pVGuiSystem, a2: drives, a3: 256);
  v2 = drives;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "drive");
  else
    v4 = nullptr;
  if ( len / 4 > 0 )
  {
    len /= 4;
    do
    {
      KeyValues::SetString(this: v4, keyName: "drive", value: v2);
      itemID = this->m_pDriveCombo->AddItem_2(this: this->m_pDriveCombo, a2: v2, a3: v4);
      if ( _V_stricmp(s1: v2, s2: this->m_szCurrentDrive) == 0 )
        this->m_pDriveCombo->ActivateItem(this: this->m_pDriveCombo, a2: itemID);
      v2 += 4;
      --len;
    }
    while ( len != 0 );
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102C5380
// Name: private: bool vgui::DirectorySelectDialog::DoesDirectoryHaveSubdirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::DirectorySelectDialog::DoesDirectoryHaveSubdirectories(
        vgui::DirectorySelectDialog *this,
        const char *path,
        const char *dir)
{
  const char *v3; // eax
  char searchString[512]; // [esp+4h] [ebp-304h] BYREF
  char szFullPath[260]; // [esp+204h] [ebp-104h] BYREF

  sprintf(string: searchString, format: "%s%s\\*.*", path, dir);
  v3 = g_pFullFileSystem->FindFirstEx(this: g_pFullFileSystem, a2: searchString, a3: 0, a4: &dir);
  if ( v3 != nullptr )
  {
    while ( 1 )
    {
      V_snprintf(pDest: szFullPath, maxLen: 260, pFormat: "%s\\%s", path, v3);
      V_FixSlashes(pname: szFullPath, separator: 92);
      if ( g_pFullFileSystem->IsDirectory(this: g_pFullFileSystem, a2: szFullPath, a3: nullptr) )
        break;
      v3 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: dir);
      if ( v3 == nullptr )
        goto LABEL_4;
    }
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)dir);
    return 1;
  }
  else
  {
LABEL_4:
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)dir);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5470
// Name: public: CreateDirectoryDialog::CreateDirectoryDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CreateDirectoryDialog *__thiscall CreateDirectoryDialog::CreateDirectoryDialog(
        CreateDirectoryDialog *this,
        vgui::Panel *parent,
        const char *defaultCreateDirName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Button *m_pOKButton; // ecx
  unsigned int v14; // eax

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CreateDirectoryDialog_vtbl *)&CreateDirectoryDialog::`vftable';
  if ( `CreateDirectoryDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CreateDirectoryDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CreateDirectoryDialog");
    v4->pfnClassName = CreateDirectoryDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `CreateDirectoryDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CreateDirectoryDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CreateDirectoryDialog");
    v5->pfnClassName = CreateDirectoryDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CreateDirectoryDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CreateDirectoryDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CreateDirectoryDialog");
    v6->pfnClassName = CreateDirectoryDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::Panel::SetSize(this, wide: 320, tall: 100);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "Choose directory name", surfaceTitle: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "OKButton",
           text: "#vgui_ok",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v8 = nullptr;
  this->m_pOKButton = v8;
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OKButton",
            text: "#vgui_cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pCancelButton = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "NameEntry");
  else
    v12 = nullptr;
  m_pOKButton = this->m_pOKButton;
  this->m_pNameEntry = v12;
  m_pOKButton->SetCommand(this: m_pOKButton, a2: "OK");
  this->m_pCancelButton->SetCommand(this: this->m_pCancelButton, a2: "Close");
  this->m_pNameEntry->SetText(this: this->m_pNameEntry, a2: defaultCreateDirName);
  this->m_pNameEntry->RequestFocus(this: this->m_pNameEntry, a2: 0);
  vgui::TextEntry::SelectAllText(this: this->m_pNameEntry, bResetCursorPos: true);
  v14 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  this->m_PrevAppFocusPanel = v14;
  if ( v14 != 0 )
    g_pVGuiInput->SetAppModalSurface(this: g_pVGuiInput, a2: this->_vpanel);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C5670
// Name: public: virtual void CreateDirectoryDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CreateDirectoryDialog::PerformLayout(CreateDirectoryDialog *this)
{
  int Wide; // eax
  int v3; // eax
  int v4; // eax

  vgui::Frame::PerformLayout(this);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pNameEntry, x: 24, y: 32, wide: Wide - 48, tall: 24);
  v3 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pOKButton, x: v3 - 176, y: 64, wide: 72, tall: 24);
  v4 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pCancelButton, x: v4 - 94, y: 64, wide: 72, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x102C56D0
// Name: public: virtual void CreateDirectoryDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CreateDirectoryDialog::OnCommand(CreateDirectoryDialog *this, const char *command)
{
  KeyValues *v3; // edi
  const char *v4; // eax
  KeyValues *v5; // eax

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = this->GetControlString_2(this, a2: "NameEntry", a3: defaultValue);
      v5 = KeyValues::KeyValues(this: v3, setName: "CreateDirectory", firstKey: "dir", firstValue: v4);
    }
    else
    {
      v5 = nullptr;
    }
    this->PostActionSignal(this, a2: v5);
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5760
// Name: public: virtual void CreateDirectoryDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CreateDirectoryDialog::OnClose(CreateDirectoryDialog *this)
{
  vgui::Frame::OnClose(this);
  this->MarkForDeletion(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C57D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CreateDirectoryDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CreateDirectoryDialog::GetMessageMap(CreateDirectoryDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CreateDirectoryDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CreateDirectoryDialog::GetMessageMap'::`2'::s_pMap;
  `CreateDirectoryDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CreateDirectoryDialog");
  `CreateDirectoryDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C5800
// Name: public: virtual struct PanelAnimationMap __near * CreateDirectoryDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CreateDirectoryDialog::GetAnimMap(CreateDirectoryDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CreateDirectoryDialog");
}

//------------------------------------------------------------------------------
// Address: 0x102C5810
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CreateDirectoryDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CreateDirectoryDialog::GetKBMap(CreateDirectoryDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CreateDirectoryDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CreateDirectoryDialog::GetKBMap'::`2'::s_pMap;
  `CreateDirectoryDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CreateDirectoryDialog");
  `CreateDirectoryDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C5840
// Name: private: void vgui::DirectorySelectDialog::ExpandTreeNode(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::ExpandTreeNode(
        vgui::DirectorySelectDialog *this,
        const char *path,
        int parentNodeIndex)
{
  const char *i; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  unsigned __int8 HaveSubdirectories; // al
  char searchString[512]; // [esp+8h] [ebp-204h] BYREF
  int h; // [esp+208h] [ebp-4h] BYREF

  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
  sprintf(string: searchString, format: "%s*.*", path);
  for ( i = g_pFullFileSystem->FindFirstEx(this: g_pFullFileSystem, a2: searchString, a3: 0, a4: &h);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: h) )
  {
    if ( _V_stricmp(s1: i, s2: "..") != 0 && _V_stricmp(s1: i, s2: ".") != 0 )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "item");
      else
        v6 = nullptr;
      KeyValues::SetString(this: v6, keyName: "Text", value: i);
      KeyValues::SetInt(this: v6, keyName: "Image", value: 1);
      KeyValues::SetInt(this: v6, keyName: "SelectedImage", value: 1);
      HaveSubdirectories = vgui::DirectorySelectDialog::DoesDirectoryHaveSubdirectories(this, path, dir: i);
      KeyValues::SetInt(this: v6, keyName: "Expand", value: HaveSubdirectories);
      this->m_pDirTree->AddItem(this: this->m_pDirTree, a2: v6, a3: parentNodeIndex);
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: h);
}

//------------------------------------------------------------------------------
// Address: 0x102C5980
// Name: private: void vgui::DirectorySelectDialog::BuildDirTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::BuildDirTree(vgui::DirectorySelectDialog *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  int v4; // edi

  this->m_pDirTree->RemoveAll(this: this->m_pDirTree);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "root", firstKey: "Text", firstValue: this->m_szCurrentDrive);
  else
    v3 = nullptr;
  v4 = this->m_pDirTree->AddItem(this: this->m_pDirTree, a2: v3, a3: -1);
  vgui::DirectorySelectDialog::ExpandTreeNode(this, path: this->m_szCurrentDrive, parentNodeIndex: v4);
  this->m_pDirTree->ExpandItem(this: this->m_pDirTree, a2: v4, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x102C5B30
// Name: public: void vgui::DirectorySelectDialog::SetStartDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::SetStartDirectory(vgui::DirectorySelectDialog *this, char *path)
{
  int v3; // eax
  int v4; // eax
  bool v5; // zf
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // eax

  strncpy(dest: (unsigned __int8 *)this->m_szCurrentDir, source: (unsigned __int8 *)path, count: 0x200u);
  strncpy(dest: (unsigned __int8 *)this->m_szCurrentDrive, source: (unsigned __int8 *)path, count: 0x10u);
  this->m_szCurrentDrive[15] = 0;
  strstr(str1: (unsigned __int8 *)this->m_szCurrentDrive, str2: "\\");
  if ( v3 != 0 )
    *(_BYTE *)(v3 + 1) = 0;
  vgui::DirectorySelectDialog::BuildDirTree(this);
  vgui::DirectorySelectDialog::BuildDriveChoices(this);
  v4 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
  v5 = !this->m_pDirTree->IsItemIDValid(this: this->m_pDirTree, a2: v4);
  SetEnabled = this->m_pCreateButton->SetEnabled;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
  else
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102C5BD0
// Name: private: virtual void vgui::DirectorySelectDialog::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::OnTextChanged(vgui::DirectorySelectDialog *this)
{
  KeyValues *ActiveItemUserData; // eax
  char *String; // edi

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pDriveCombo);
  if ( ActiveItemUserData != nullptr )
  {
    String = KeyValues::GetString(this: ActiveItemUserData, keyName: "drive", defaultValue: defaultValue);
    if ( _V_stricmp(s1: String, s2: this->m_szCurrentDrive) != 0 )
      vgui::DirectorySelectDialog::SetStartDirectory(this, path: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5C20
// Name: public: static void vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "DirectorySelectDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5CB0
// Name: public: static void vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "DirectorySelectDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5D40
// Name: public: static void vgui::DirectorySelectDialog::PanelMessageFunc_OnCreateDirectory::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::DirectorySelectDialog::PanelMessageFunc_OnCreateDirectory::InitVar(int a1@<ebp>)
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
  if ( !`vgui::DirectorySelectDialog::PanelMessageFunc_OnCreateDirectory::InitVar'::`2'::bAdded )
  {
    `vgui::DirectorySelectDialog::PanelMessageFunc_OnCreateDirectory::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "DirectorySelectDialog");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CreateDirectory";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "dir";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5DE0
// Name: public: vgui::DirectorySelectDialog::DirectorySelectDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::DirectorySelectDialog *__thiscall vgui::DirectorySelectDialog::DirectorySelectDialog(
        vgui::DirectorySelectDialog *this,
        vgui::Panel *parent,
        const char *title)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TreeView *v7; // eax
  vgui::TreeView *v8; // edi
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *m_pCancelButton; // ecx

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::DirectorySelectDialog_vtbl *)&vgui::DirectorySelectDialog::`vftable';
  if ( `vgui::DirectorySelectDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::DirectorySelectDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "DirectorySelectDialog");
    v4->pfnClassName = vgui::DirectorySelectDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::DirectorySelectDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::DirectorySelectDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "DirectorySelectDialog");
    v5->pfnClassName = vgui::DirectorySelectDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::DirectorySelectDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::DirectorySelectDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "DirectorySelectDialog");
    v6->pfnClassName = vgui::DirectorySelectDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar();
  vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar();
  vgui::DirectorySelectDialog::PanelMessageFunc_OnCreateDirectory::InitVar();
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  vgui::Panel::SetSize(this, wide: 320, tall: 360);
  vgui::Panel::SetMinimumSize(this, wide: 300, tall: 240);
  this->m_szCurrentDir[0] = 0;
  this->m_szDefaultCreateDirName[0] = 0;
  v7 = (vgui::TreeView *)MemAlloc_Alloc(nSize: 0x1C0u);
  v8 = v7;
  if ( v7 != nullptr )
  {
    vgui::TreeView::TreeView(this: v7, parent: this, panelName: "DirTree");
    v8->__vftable = (vgui::TreeView_vtbl *)&vgui::DirectoryTreeView::`vftable';
    v8[1].__vftable = (vgui::TreeView_vtbl *)this;
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pDirTree = v8;
  v9 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(this: v9, parent: this, panelName: "DriveCombo", numLines: 6, allowEdit: false);
  else
    v10 = nullptr;
  this->m_pDriveCombo = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#VGui_Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "SelectButton",
            text: "#VGui_Select",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pSelectButton = v14;
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "CreateButton",
            text: "#VGui_CreateFolder",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v16 = nullptr;
  m_pCancelButton = this->m_pCancelButton;
  this->m_pCreateButton = v16;
  m_pCancelButton->SetCommand(this: m_pCancelButton, a2: "Cancel");
  this->m_pSelectButton->SetCommand(this: this->m_pSelectButton, a2: "Select");
  this->m_pCreateButton->SetCommand(this: this->m_pCreateButton, a2: "Create");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C6020
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::DirectorySelectDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::DirectorySelectDialog::GetMessageMap(vgui::DirectorySelectDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::DirectorySelectDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::DirectorySelectDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::DirectorySelectDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "DirectorySelectDialog");
  `vgui::DirectorySelectDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6050
// Name: public: virtual struct PanelAnimationMap __near * vgui::DirectorySelectDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::DirectorySelectDialog::GetAnimMap(vgui::DirectorySelectDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "DirectorySelectDialog");
}

//------------------------------------------------------------------------------
// Address: 0x102C6060
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::DirectorySelectDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::DirectorySelectDialog::GetKBMap(vgui::DirectorySelectDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::DirectorySelectDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::DirectorySelectDialog::GetKBMap'::`2'::s_pMap;
  `vgui::DirectorySelectDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "DirectorySelectDialog");
  `vgui::DirectorySelectDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6190
// Name: private: void vgui::DirectorySelectDialog::GenerateFullPathForNode(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::GenerateFullPathForNode(
        vgui::DirectorySelectDialog *this,
        int nodeIndex,
        char *path,
        int pathBufferSize)
{
  vgui::DirectorySelectDialog *v4; // edi
  int v5; // esi
  int m_Head; // eax
  UtlLinkedListElem_t<int,int> *v7; // ebx
  KeyValues *v8; // eax
  char *String; // ecx
  CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > nodes; // [esp+Ch] [ebp-2Ch] BYREF
  vgui::DirectorySelectDialog *v11; // [esp+34h] [ebp-4h]

  memset(&nodes, 0, 12);
  nodes.m_ElementCount = 0;
  nodes.m_NumAlloced = 0;
  nodes.m_pElements = nullptr;
  v4 = this;
  v11 = this;
  nodes.m_LastAlloc.index = -1;
  memset(&nodes.m_Head, 255, 12);
  CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToTail(this: &nodes, src: &nodeIndex);
  v5 = v4->m_pDirTree->GetItemParent(this: v4->m_pDirTree, a2: nodeIndex);
  for ( nodeIndex = v5; v5 != -1; nodeIndex = v5 )
  {
    CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToHead(this: &nodes, src: &nodeIndex);
    v5 = v4->m_pDirTree->GetItemParent(this: v4->m_pDirTree, a2: v5);
  }
  m_Head = nodes.m_Head;
  *path = 0;
  HIBYTE(nodeIndex) = 1;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v7 = &nodes.m_Memory.m_pMemory[m_Head];
      v8 = v4->m_pDirTree->GetItemData(this: v4->m_pDirTree, a2: v7->m_Element);
      String = KeyValues::GetString(this: v8, keyName: "Text", defaultValue: defaultValue);
      strcat(path, String);
      if ( HIBYTE(nodeIndex) == 0 )
        strcat(path, "\\");
      m_Head = v7->m_Next;
      HIBYTE(nodeIndex) = 0;
      if ( m_Head == -1 )
        break;
      v4 = v11;
    }
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&nodes);
  if ( nodes.m_Memory.m_nGrowSize >= 0 && nodes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: nodes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x102C62E0
// Name: private: virtual void vgui::DirectorySelectDialog::OnCreateDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::OnCreateDirectory(vgui::DirectorySelectDialog *this, const char *dir)
{
  int v3; // eax
  vgui::TreeView *m_pDirTree; // ecx
  int v5; // esi
  bool (__thiscall *IsItemIDValid)(vgui::TreeView *, int); // edx
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  int v12; // eax
  vgui::MessageBox *v13; // eax
  vgui::MessageBox *v14; // eax
  char v15; // [esp+7h] [ebp-205h] BYREF
  char fullPath[512]; // [esp+8h] [ebp-204h] BYREF
  int selectedIndex; // [esp+208h] [ebp-4h]

  v3 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
  m_pDirTree = this->m_pDirTree;
  v5 = v3;
  IsItemIDValid = m_pDirTree->IsItemIDValid;
  selectedIndex = v3;
  if ( IsItemIDValid(this: m_pDirTree, a2: v3) )
  {
    vgui::DirectorySelectDialog::GenerateFullPathForNode(this, nodeIndex: v5, path: fullPath, pathBufferSize: 512);
    v7 = strlen(dir) + 1;
    v8 = &v15;
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, dir, v7);
    if ( _mkdir(path: fullPath) != 0 )
    {
      v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v13 != nullptr )
        v14 = vgui::MessageBox::MessageBox(
                this: v13,
                title: "#vgui_CreateDirectoryFail_Title",
                text: "#vgui_CreateDirectoryFail_Info",
                parent: nullptr);
      else
        v14 = nullptr;
      v14->DoModal_2(this: v14, a2: this);
    }
    else
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        v11 = KeyValues::KeyValues(this: v10, setName: "item");
      else
        v11 = nullptr;
      KeyValues::SetString(this: v11, keyName: "Text", value: dir);
      KeyValues::SetInt(this: v11, keyName: "Image", value: 1);
      KeyValues::SetInt(this: v11, keyName: "SelectedImage", value: 1);
      v12 = this->m_pDirTree->AddItem(this: this->m_pDirTree, a2: v11, a3: selectedIndex);
      this->m_pDirTree->AddSelectedItem(this: this->m_pDirTree, a2: v12, a3: true, a4: true, a5: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6440
// Name: protected: virtual void vgui::DirectorySelectDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::OnCommand(vgui::DirectorySelectDialog *this, const char *command)
{
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  int v6; // eax
  CreateDirectoryDialog *v7; // eax
  CreateDirectoryDialog *DirectoryDialog; // edi
  char fullPath[512]; // [esp+8h] [ebp-200h] BYREF

  if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Select") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "Create") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        v6 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
        if ( this->m_pDirTree->IsItemIDValid(this: this->m_pDirTree, a2: v6) )
        {
          v7 = (CreateDirectoryDialog *)MemAlloc_Alloc(nSize: 0x224u);
          if ( v7 != nullptr )
            DirectoryDialog = CreateDirectoryDialog::CreateDirectoryDialog(
                                this: v7,
                                parent: this,
                                defaultCreateDirName: this->m_szDefaultCreateDirName);
          else
            DirectoryDialog = nullptr;
          DirectoryDialog->AddActionSignalTarget_2(this: DirectoryDialog, a2: this);
          DirectoryDialog->Activate(this: DirectoryDialog);
        }
      }
    }
    else
    {
      v3 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
      if ( this->m_pDirTree->IsItemIDValid(this: this->m_pDirTree, a2: v3) )
      {
        vgui::DirectorySelectDialog::GenerateFullPathForNode(this, nodeIndex: v3, path: fullPath, pathBufferSize: 512);
        v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v4 != nullptr )
          v5 = KeyValues::KeyValues(this: v4, setName: "DirectorySelected", firstKey: "dir", firstValue: fullPath);
        else
          v5 = nullptr;
        this->PostActionSignal(this, a2: v5);
        this->Close(this);
      }
    }
  }
  else
  {
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C65B0
// Name: private: virtual void vgui::DirectorySelectDialog::OnTreeViewItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::OnTreeViewItemSelected(vgui::DirectorySelectDialog *this)
{
  int v2; // edi
  bool v3; // al
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  int ActiveItem; // eax
  char fullPath[512]; // [esp+8h] [ebp-200h] BYREF

  v2 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
  v3 = this->m_pDirTree->IsItemIDValid(this: this->m_pDirTree, a2: v2);
  SetEnabled = this->m_pCreateButton->SetEnabled;
  if ( v3 )
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    vgui::DirectorySelectDialog::GenerateFullPathForNode(this, nodeIndex: v2, path: fullPath, pathBufferSize: 512);
    ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pDriveCombo);
    this->m_pDriveCombo->UpdateItem_2(this: this->m_pDriveCombo, a2: ActiveItem, a3: fullPath, a4: nullptr);
    this->m_pDriveCombo->SetText(this: this->m_pDriveCombo, a2: fullPath);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6660
// Name: public: virtual void vgui::DirectoryTreeView::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectoryTreeView::GenerateChildrenOfNode(vgui::DirectoryTreeView *this, int itemIndex)
{
  vgui::DirectorySelectDialog *m_pParent; // esi
  char path[512]; // [esp+8h] [ebp-200h] BYREF

  m_pParent = this->m_pParent;
  vgui::DirectorySelectDialog::GenerateFullPathForNode(this: m_pParent, nodeIndex: itemIndex, path, pathBufferSize: 512);
  vgui::DirectorySelectDialog::ExpandTreeNode(this: m_pParent, path, parentNodeIndex: itemIndex);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C5160
// Name: public: static char const __near * vgui::DirectorySelectDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::DirectorySelectDialog::GetPanelClassName()
{
  return "DirectorySelectDialog";
}

//------------------------------------------------------------------------------
// Address: 0x102C5170
// Name: public: static char const __near * CreateDirectoryDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CreateDirectoryDialog::GetPanelClassName()
{
  return "CreateDirectoryDialog";
}

//------------------------------------------------------------------------------
// Address: 0x102C5180
// Name: protected: virtual void vgui::DirectorySelectDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::PerformLayout(vgui::DirectorySelectDialog *this)
{
  int Wide; // eax
  int v3; // eax
  int Tall; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-Ch] [ebp-10h]
  int v9; // [esp-4h] [ebp-8h]

  vgui::Frame::PerformLayout(this);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDriveCombo, x: 24, y: 30, wide: Wide - 48, tall: 24);
  v9 = vgui::Panel::GetTall(this) - 128;
  v3 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDirTree, x: 24, y: 64, wide: v3 - 48, tall: v9);
  Tall = vgui::Panel::GetTall(this);
  vgui::Panel::SetBounds(this: this->m_pCreateButton, x: 24, y: Tall - 48, wide: 104, tall: 24);
  v7 = vgui::Panel::GetTall(this) - 48;
  v5 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pSelectButton, x: v5 - 172, y: v7, wide: 72, tall: 24);
  v8 = vgui::Panel::GetTall(this) - 48;
  v6 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pCancelButton, x: v6 - 96, y: v8, wide: 72, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x102C5240
// Name: protected: virtual void vgui::DirectorySelectDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::ApplySchemeSettings(
        vgui::DirectorySelectDialog *this,
        vgui::IScheme *pScheme)
{
  vgui::ImageList *v3; // eax
  vgui::Dar<unsigned long> *v4; // esi
  vgui::IImage *v5; // eax
  vgui::IImage *v6; // eax

  v3 = (vgui::ImageList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
    v4 = (vgui::Dar<unsigned long> *)vgui::ImageList::ImageList(this: v3, deleteImagesWhenDone: false);
  else
    v4 = nullptr;
  v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "Resource/icon_folder", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v4, elem: (unsigned int)v5);
  v6 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "Resource/icon_folder_selected", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v4, elem: (unsigned int)v6);
  this->m_pDirTree->SetImageList(this: this->m_pDirTree, a2: (vgui::ImageList *)v4, a3: true);
  vgui::Frame::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x102C52C0
// Name: public: virtual void vgui::DirectorySelectDialog::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::DoModal(vgui::DirectorySelectDialog *this)
{
  vgui::IInput *v2; // edi
  vgui::IInput_vtbl *v3; // ebx
  int v4; // eax

  v2 = g_pVGuiInput;
  v3 = g_pVGuiInput->__vftable;
  v4 = this->GetVPanel(this);
  v3->SetAppModalSurface(this: v2, a2: v4);
  vgui::Frame::Activate(this);
  this->MoveToCenterOfScreen(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C5300
// Name: private: void vgui::DirectorySelectDialog::BuildDriveChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::BuildDriveChoices(vgui::DirectorySelectDialog *this)
{
  char *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  char drives[256]; // [esp+Ch] [ebp-108h] BYREF
  int itemID; // [esp+10Ch] [ebp-8h]
  int len; // [esp+110h] [ebp-4h]

  vgui::ComboBox::RemoveAll(this: this->m_pDriveCombo);
  memset(drives, 0, sizeof(drives));
  len = g_pVGuiSystem->GetAvailableDrives(this: g_pVGuiSystem, a2: drives, a3: 256);
  v2 = drives;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "drive");
  else
    v4 = nullptr;
  if ( len / 4 > 0 )
  {
    len /= 4;
    do
    {
      KeyValues::SetString(this: v4, keyName: "drive", value: v2);
      itemID = this->m_pDriveCombo->AddItem_2(this: this->m_pDriveCombo, a2: v2, a3: v4);
      if ( _V_stricmp(s1: v2, s2: this->m_szCurrentDrive) == 0 )
        this->m_pDriveCombo->ActivateItem(this: this->m_pDriveCombo, a2: itemID);
      v2 += 4;
      --len;
    }
    while ( len != 0 );
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102C53F0
// Name: private: bool vgui::DirectorySelectDialog::DoesDirectoryHaveSubdirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::DirectorySelectDialog::DoesDirectoryHaveSubdirectories(
        vgui::DirectorySelectDialog *this,
        const char *path,
        const char *dir)
{
  const char *v3; // eax
  char searchString[512]; // [esp+4h] [ebp-304h] BYREF
  char szFullPath[260]; // [esp+204h] [ebp-104h] BYREF

  sprintf(string: searchString, format: "%s%s\\*.*", path, dir);
  v3 = g_pFullFileSystem->FindFirstEx(this: g_pFullFileSystem, a2: searchString, a3: 0, a4: &dir);
  if ( v3 != nullptr )
  {
    while ( 1 )
    {
      V_snprintf(pDest: szFullPath, maxLen: 260, pFormat: "%s\\%s", path, v3);
      V_FixSlashes(pname: szFullPath, separator: 92);
      if ( g_pFullFileSystem->IsDirectory(this: g_pFullFileSystem, a2: szFullPath, a3: nullptr) )
        break;
      v3 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: dir);
      if ( v3 == nullptr )
        goto LABEL_4;
    }
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)dir);
    return 1;
  }
  else
  {
LABEL_4:
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)dir);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C54D0
// Name: public: virtual void CreateDirectoryDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CreateDirectoryDialog::OnClose(CreateDirectoryDialog *this)
{
  vgui::Frame::OnClose(this);
  this->MarkForDeletion(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C5530
// Name: public: CreateDirectoryDialog::CreateDirectoryDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CreateDirectoryDialog *__thiscall CreateDirectoryDialog::CreateDirectoryDialog(
        CreateDirectoryDialog *this,
        vgui::Panel *parent,
        const char *defaultCreateDirName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Button *m_pOKButton; // ecx
  unsigned int v14; // eax

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CreateDirectoryDialog_vtbl *)&CreateDirectoryDialog::`vftable';
  if ( `CreateDirectoryDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CreateDirectoryDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"CreateDirectoryDialog");
    v4->pfnClassName = CreateDirectoryDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Frame");
  }
  if ( `CreateDirectoryDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CreateDirectoryDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CreateDirectoryDialog");
    v5->pfnClassName = CreateDirectoryDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CreateDirectoryDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CreateDirectoryDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CreateDirectoryDialog");
    v6->pfnClassName = CreateDirectoryDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Frame");
  }
  vgui::Panel::SetSize(this, wide: 320, tall: 100);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "Choose directory name", surfaceTitle: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "OKButton",
           text: "#vgui_ok",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v8 = nullptr;
  this->m_pOKButton = v8;
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OKButton",
            text: "#vgui_cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pCancelButton = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "NameEntry");
  else
    v12 = nullptr;
  m_pOKButton = this->m_pOKButton;
  this->m_pNameEntry = v12;
  m_pOKButton->SetCommand(this: m_pOKButton, a2: "OK");
  this->m_pCancelButton->SetCommand(this: this->m_pCancelButton, a2: "Close");
  this->m_pNameEntry->SetText(this: this->m_pNameEntry, a2: defaultCreateDirName);
  this->m_pNameEntry->RequestFocus(this: this->m_pNameEntry, a2: 0);
  vgui::TextEntry::SelectAllText(this: this->m_pNameEntry, bResetCursorPos: true);
  v14 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  this->m_PrevAppFocusPanel = v14;
  if ( v14 != 0 )
    g_pVGuiInput->SetAppModalSurface(this: g_pVGuiInput, a2: this->_vpanel);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C5730
// Name: public: virtual void CreateDirectoryDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CreateDirectoryDialog::PerformLayout(CreateDirectoryDialog *this)
{
  int Wide; // eax
  int v3; // eax
  int v4; // eax

  vgui::Frame::PerformLayout(this);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pNameEntry, x: 24, y: 32, wide: Wide - 48, tall: 24);
  v3 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pOKButton, x: v3 - 176, y: 64, wide: 72, tall: 24);
  v4 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pCancelButton, x: v4 - 94, y: 64, wide: 72, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x102C5790
// Name: public: virtual void CreateDirectoryDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CreateDirectoryDialog::OnCommand(CreateDirectoryDialog *this, const char *command)
{
  KeyValues *v3; // edi
  const char *v4; // eax
  KeyValues *v5; // eax

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = this->GetControlString_2(this, a2: "NameEntry", a3: defaultValue);
      v5 = KeyValues::KeyValues(this: v3, setName: "CreateDirectory", firstKey: "dir", firstValue: v4);
    }
    else
    {
      v5 = nullptr;
    }
    this->PostActionSignal(this, a2: v5);
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5870
// Name: public: virtual struct vgui::PanelMessageMap __near * CreateDirectoryDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CreateDirectoryDialog::GetMessageMap(CreateDirectoryDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CreateDirectoryDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CreateDirectoryDialog::GetMessageMap'::`2'::s_pMap;
  `CreateDirectoryDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"CreateDirectoryDialog");
  `CreateDirectoryDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C58A0
// Name: public: virtual struct PanelAnimationMap __near * CreateDirectoryDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CreateDirectoryDialog::GetAnimMap(CreateDirectoryDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CreateDirectoryDialog");
}

//------------------------------------------------------------------------------
// Address: 0x102C58B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CreateDirectoryDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CreateDirectoryDialog::GetKBMap(CreateDirectoryDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CreateDirectoryDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CreateDirectoryDialog::GetKBMap'::`2'::s_pMap;
  `CreateDirectoryDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CreateDirectoryDialog");
  `CreateDirectoryDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C58E0
// Name: private: void vgui::DirectorySelectDialog::ExpandTreeNode(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::ExpandTreeNode(
        vgui::DirectorySelectDialog *this,
        const char *path,
        int parentNodeIndex)
{
  const char *i; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  unsigned __int8 HaveSubdirectories; // al
  char searchString[512]; // [esp+8h] [ebp-204h] BYREF
  int h; // [esp+208h] [ebp-4h] BYREF

  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
  sprintf(string: searchString, format: "%s*.*", path);
  for ( i = g_pFullFileSystem->FindFirstEx(this: g_pFullFileSystem, a2: searchString, a3: 0, a4: &h);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: h) )
  {
    if ( _V_stricmp(s1: i, s2: "..") != 0 && _V_stricmp(s1: i, s2: ".") != 0 )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "item");
      else
        v6 = nullptr;
      KeyValues::SetString(this: v6, keyName: "Text", value: i);
      KeyValues::SetInt(this: v6, keyName: "Image", value: 1);
      KeyValues::SetInt(this: v6, keyName: "SelectedImage", value: 1);
      HaveSubdirectories = vgui::DirectorySelectDialog::DoesDirectoryHaveSubdirectories(this, path, dir: i);
      KeyValues::SetInt(this: v6, keyName: "Expand", value: HaveSubdirectories);
      this->m_pDirTree->AddItem(this: this->m_pDirTree, a2: v6, a3: parentNodeIndex);
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: h);
}

//------------------------------------------------------------------------------
// Address: 0x102C5A20
// Name: private: void vgui::DirectorySelectDialog::BuildDirTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::BuildDirTree(vgui::DirectorySelectDialog *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  int v4; // edi

  this->m_pDirTree->RemoveAll(this: this->m_pDirTree);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "root", firstKey: "Text", firstValue: this->m_szCurrentDrive);
  else
    v3 = nullptr;
  v4 = this->m_pDirTree->AddItem(this: this->m_pDirTree, a2: v3, a3: -1);
  vgui::DirectorySelectDialog::ExpandTreeNode(this, path: this->m_szCurrentDrive, parentNodeIndex: v4);
  this->m_pDirTree->ExpandItem(this: this->m_pDirTree, a2: v4, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x102C5C70
// Name: private: virtual void vgui::DirectorySelectDialog::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::OnTextChanged(vgui::DirectorySelectDialog *this)
{
  KeyValues *ActiveItemUserData; // eax
  char *String; // edi

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pDriveCombo);
  if ( ActiveItemUserData != nullptr )
  {
    String = KeyValues::GetString(this: ActiveItemUserData, keyName: "drive", defaultValue: defaultValue);
    if ( _V_stricmp(s1: String, s2: this->m_szCurrentDrive) != 0 )
      vgui::DirectorySelectDialog::SetStartDirectory(this, path: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5CC0
// Name: public: static void vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"DirectorySelectDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5D50
// Name: public: static void vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"DirectorySelectDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5E90
// Name: public: vgui::DirectorySelectDialog::DirectorySelectDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::DirectorySelectDialog *__thiscall vgui::DirectorySelectDialog::DirectorySelectDialog(
        vgui::DirectorySelectDialog *this,
        vgui::Panel *parent,
        const char *title)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TreeView *v7; // eax
  vgui::TreeView *v8; // edi
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *m_pCancelButton; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::DirectorySelectDialog_vtbl *)&vgui::DirectorySelectDialog::`vftable';
  if ( `vgui::DirectorySelectDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::DirectorySelectDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"DirectorySelectDialog");
    v4->pfnClassName = vgui::DirectorySelectDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Frame");
  }
  if ( `vgui::DirectorySelectDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::DirectorySelectDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "DirectorySelectDialog");
    v5->pfnClassName = vgui::DirectorySelectDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::DirectorySelectDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::DirectorySelectDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"DirectorySelectDialog");
    v6->pfnClassName = vgui::DirectorySelectDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Frame");
  }
  vgui::DirectorySelectDialog::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::DirectorySelectDialog::PanelMessageFunc_OnTreeViewItemSelected::InitVar(a1: (int)&savedregs);
  vgui::DirectorySelectDialog::PanelMessageFunc_OnCreateDirectory::InitVar();
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  vgui::Panel::SetSize(this, wide: 320, tall: 360);
  vgui::Panel::SetMinimumSize(this, wide: 300, tall: 240);
  this->m_szCurrentDir[0] = 0;
  this->m_szDefaultCreateDirName[0] = 0;
  v7 = (vgui::TreeView *)MemAlloc_Alloc(nSize: 0x1C0u);
  v8 = v7;
  if ( v7 != nullptr )
  {
    vgui::TreeView::TreeView(this: v7, parent: this, panelName: "DirTree");
    v8->__vftable = (vgui::TreeView_vtbl *)&vgui::DirectoryTreeView::`vftable';
    v8[1].__vftable = (vgui::TreeView_vtbl *)this;
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pDirTree = v8;
  v9 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(this: v9, parent: this, panelName: "DriveCombo", numLines: 6, allowEdit: false);
  else
    v10 = nullptr;
  this->m_pDriveCombo = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#VGui_Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "SelectButton",
            text: "#VGui_Select",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pSelectButton = v14;
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "CreateButton",
            text: "#VGui_CreateFolder",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v16 = nullptr;
  m_pCancelButton = this->m_pCancelButton;
  this->m_pCreateButton = v16;
  m_pCancelButton->SetCommand(this: m_pCancelButton, a2: "Cancel");
  this->m_pSelectButton->SetCommand(this: this->m_pSelectButton, a2: "Select");
  this->m_pCreateButton->SetCommand(this: this->m_pCreateButton, a2: "Create");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C60D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::DirectorySelectDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::DirectorySelectDialog::GetMessageMap(vgui::DirectorySelectDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::DirectorySelectDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::DirectorySelectDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::DirectorySelectDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"DirectorySelectDialog");
  `vgui::DirectorySelectDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6100
// Name: public: virtual struct PanelAnimationMap __near * vgui::DirectorySelectDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::DirectorySelectDialog::GetAnimMap(vgui::DirectorySelectDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "DirectorySelectDialog");
}

//------------------------------------------------------------------------------
// Address: 0x102C6110
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::DirectorySelectDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::DirectorySelectDialog::GetKBMap(vgui::DirectorySelectDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::DirectorySelectDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::DirectorySelectDialog::GetKBMap'::`2'::s_pMap;
  `vgui::DirectorySelectDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"DirectorySelectDialog");
  `vgui::DirectorySelectDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6240
// Name: private: void vgui::DirectorySelectDialog::GenerateFullPathForNode(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::GenerateFullPathForNode(
        vgui::DirectorySelectDialog *this,
        int nodeIndex,
        char *path,
        int pathBufferSize)
{
  vgui::DirectorySelectDialog *v4; // edi
  int v5; // esi
  int m_Head; // eax
  UtlLinkedListElem_t<int,int> *v7; // ebx
  KeyValues *v8; // eax
  char *String; // ecx
  CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > nodes; // [esp+Ch] [ebp-2Ch] BYREF
  vgui::DirectorySelectDialog *v11; // [esp+34h] [ebp-4h]

  memset(&nodes, 0, 12);
  nodes.m_ElementCount = 0;
  nodes.m_NumAlloced = 0;
  nodes.m_pElements = nullptr;
  v4 = this;
  v11 = this;
  nodes.m_LastAlloc.index = -1;
  memset(&nodes.m_Head, 255, 12);
  CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToTail(this: &nodes, src: &nodeIndex);
  v5 = v4->m_pDirTree->GetItemParent(this: v4->m_pDirTree, a2: nodeIndex);
  for ( nodeIndex = v5; v5 != -1; nodeIndex = v5 )
  {
    CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToHead(this: &nodes, src: &nodeIndex);
    v5 = v4->m_pDirTree->GetItemParent(this: v4->m_pDirTree, a2: v5);
  }
  m_Head = nodes.m_Head;
  *path = 0;
  HIBYTE(nodeIndex) = 1;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v7 = &nodes.m_Memory.m_pMemory[m_Head];
      v8 = v4->m_pDirTree->GetItemData(this: v4->m_pDirTree, a2: v7->m_Element);
      String = KeyValues::GetString(this: v8, keyName: "Text", defaultValue: defaultValue);
      strcat(path, String);
      if ( HIBYTE(nodeIndex) == 0 )
        strcat(path, "\\");
      m_Head = v7->m_Next;
      HIBYTE(nodeIndex) = 0;
      if ( m_Head == -1 )
        break;
      v4 = v11;
    }
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&nodes);
  if ( nodes.m_Memory.m_nGrowSize >= 0 && nodes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: nodes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x102C6390
// Name: private: virtual void vgui::DirectorySelectDialog::OnCreateDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::OnCreateDirectory(vgui::DirectorySelectDialog *this, const char *dir)
{
  int v3; // eax
  vgui::TreeView *m_pDirTree; // ecx
  int v5; // esi
  bool (__thiscall *IsItemIDValid)(vgui::TreeView *, int); // edx
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  int v12; // eax
  vgui::MessageBox *v13; // eax
  vgui::MessageBox *v14; // eax
  char v15; // [esp+7h] [ebp-205h] BYREF
  char fullPath[512]; // [esp+8h] [ebp-204h] BYREF
  int selectedIndex; // [esp+208h] [ebp-4h]

  v3 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
  m_pDirTree = this->m_pDirTree;
  v5 = v3;
  IsItemIDValid = m_pDirTree->IsItemIDValid;
  selectedIndex = v3;
  if ( IsItemIDValid(this: m_pDirTree, a2: v3) )
  {
    vgui::DirectorySelectDialog::GenerateFullPathForNode(this, nodeIndex: v5, path: fullPath, pathBufferSize: 512);
    v7 = strlen(dir) + 1;
    v8 = &v15;
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, dir, v7);
    if ( _mkdir(path: fullPath) != 0 )
    {
      v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v13 != nullptr )
        v14 = vgui::MessageBox::MessageBox(
                this: v13,
                title: "#vgui_CreateDirectoryFail_Title",
                text: "#vgui_CreateDirectoryFail_Info",
                parent: nullptr);
      else
        v14 = nullptr;
      v14->DoModal_2(this: v14, a2: this);
    }
    else
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        v11 = KeyValues::KeyValues(this: v10, setName: "item");
      else
        v11 = nullptr;
      KeyValues::SetString(this: v11, keyName: "Text", value: dir);
      KeyValues::SetInt(this: v11, keyName: "Image", value: 1);
      KeyValues::SetInt(this: v11, keyName: "SelectedImage", value: 1);
      v12 = this->m_pDirTree->AddItem(this: this->m_pDirTree, a2: v11, a3: selectedIndex);
      this->m_pDirTree->AddSelectedItem(this: this->m_pDirTree, a2: v12, a3: true, a4: true, a5: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C64F0
// Name: protected: virtual void vgui::DirectorySelectDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectorySelectDialog::OnCommand(vgui::DirectorySelectDialog *this, const char *command)
{
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  int v6; // eax
  CreateDirectoryDialog *v7; // eax
  CreateDirectoryDialog *DirectoryDialog; // edi
  char fullPath[512]; // [esp+8h] [ebp-200h] BYREF

  if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Select") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "Create") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        v6 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
        if ( this->m_pDirTree->IsItemIDValid(this: this->m_pDirTree, a2: v6) )
        {
          v7 = (CreateDirectoryDialog *)MemAlloc_Alloc(nSize: 0x224u);
          if ( v7 != nullptr )
            DirectoryDialog = CreateDirectoryDialog::CreateDirectoryDialog(
                                this: v7,
                                parent: this,
                                defaultCreateDirName: this->m_szDefaultCreateDirName);
          else
            DirectoryDialog = nullptr;
          DirectoryDialog->AddActionSignalTarget_2(this: DirectoryDialog, a2: this);
          DirectoryDialog->Activate(this: DirectoryDialog);
        }
      }
    }
    else
    {
      v3 = this->m_pDirTree->GetFirstSelectedItem(this: this->m_pDirTree);
      if ( this->m_pDirTree->IsItemIDValid(this: this->m_pDirTree, a2: v3) )
      {
        vgui::DirectorySelectDialog::GenerateFullPathForNode(this, nodeIndex: v3, path: fullPath, pathBufferSize: 512);
        v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v4 != nullptr )
          v5 = KeyValues::KeyValues(this: v4, setName: "DirectorySelected", firstKey: "dir", firstValue: fullPath);
        else
          v5 = nullptr;
        this->PostActionSignal(this, a2: v5);
        this->Close(this);
      }
    }
  }
  else
  {
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6710
// Name: public: virtual void vgui::DirectoryTreeView::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::DirectoryTreeView::GenerateChildrenOfNode(vgui::DirectoryTreeView *this, int itemIndex)
{
  vgui::DirectorySelectDialog *m_pParent; // esi
  char path[512]; // [esp+8h] [ebp-200h] BYREF

  m_pParent = this->m_pParent;
  vgui::DirectorySelectDialog::GenerateFullPathForNode(this: m_pParent, nodeIndex: itemIndex, path, pathBufferSize: 512);
  vgui::DirectorySelectDialog::ExpandTreeNode(this: m_pParent, path, parentNodeIndex: itemIndex);
}

} // namespace engine_xlsp
