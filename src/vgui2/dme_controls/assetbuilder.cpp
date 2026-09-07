// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/assetbuilder.cpp
// Functions: 94
// ============================================================

#include "vgui2\dme_controls\assetbuilder.h"

//------------------------------------------------------------------------------
// Address: 0x00451320
// Name: public: virtual void CDmePanelFactory<class CDmeElementPanel,class CDmElement>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeElementPanel,CDmElement>::SetDmeElement(
        CDmePanelFactory<CDmeElementPanel,CDmElement> *this,
        vgui::EditablePanel *pPanel,
        KeyValues *pElement)
{
  pPanel->__vftable[1].RequestInfo(this: pPanel, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00464140
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeElementPanel,class CDmElement>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeElementPanel *__thiscall CDmePanelFactory<CDmeElementPanel,CDmElement>::CreateDmePanel(
        CDmePanelFactory<CDmeElementPanel,CDmElement> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CDmElement *v4; // esi
  CDmeElementPanel *v5; // eax
  CDmeElementPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeElementPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
  if ( v5 != nullptr )
    v6 = CDmeElementPanel::CDmeElementPanel(this: v5, pParent, pPanelName);
  else
    v6 = nullptr;
  v6->SetObject(this: v6, a2: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00473480
// Name: public: virtual void CDmePanelFactory<class CDmeSourceSkinPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin> *this,
        CDmeSourceSkinPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkinPanel::SetDmeElement(this: pPanel, pSourceSkin: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00473760
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeSourceSkinPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceSkinPanel *__thiscall CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // esi
  CDmeSourceSkinPanel *v5; // eax
  CDmeSourceSkinPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeSourceSkinPanel *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v5 != nullptr )
  {
    v6 = CDmeSourceSkinPanel::CDmeSourceSkinPanel(this: v5, pParent, pPanelName);
    CDmeSourceSkinPanel::SetDmeElement(this: v6, pSourceSkin: v4);
    return v6;
  }
  else
  {
    CDmeSourceSkinPanel::SetDmeElement(this: nullptr, pSourceSkin: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004737D0
// Name: public: static char const __near * CAssetBuilder::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetBuilder::GetPanelClassName()
{
  return "CAssetBuilder";
}

//------------------------------------------------------------------------------
// Address: 0x004737E0
// Name: public: static char const __near * CCompileStatusBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCompileStatusBar::GetPanelClassName()
{
  return "CCompileStatusBar";
}

//------------------------------------------------------------------------------
// Address: 0x004737F0
// Name: public: virtual void CCompileStatusBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCompileStatusBar::PaintBackground(CCompileStatusBar *this)
{
  FontVertex_t verts[4]; // [esp+4h] [ebp-4Ch] BYREF
  float du; // [esp+44h] [ebp-Ch]
  int h; // [esp+48h] [ebp-8h] BYREF
  int w; // [esp+4Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  switch ( this->m_Status )
  {
    case CURRENTLY_COMPILING:
      du = _Plat_FloatTime() * 0.2;
      verts[0].m_Position.x = 0.0;
      verts[0].m_Position.y = 0.0;
      verts[0].m_TexCoord.x = 1.0 - (float)(du - (float)(int)du);
      verts[0].m_TexCoord.y = 0.0;
      verts[1].m_Position.x = (float)w;
      verts[1].m_Position.y = 0.0;
      verts[1].m_TexCoord.x = verts[0].m_TexCoord.x + 1.0;
      verts[1].m_TexCoord.y = 0.0;
      verts[2].m_Position.x = (float)w;
      verts[2].m_Position.y = (float)h;
      verts[2].m_TexCoord.x = verts[0].m_TexCoord.x + 1.0;
      verts[2].m_TexCoord.y = 1.0;
      verts[3].m_Position.x = 0.0;
      verts[3].m_Position.y = (float)h;
      verts[3].m_TexCoord.x = verts[0].m_TexCoord.x;
      verts[3].m_TexCoord.y = 1.0;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_CompilingId);
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      break;
    case COMPILATION_FAILED:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
      break;
    case COMPILATION_SUCCESSFUL:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 255, a4: 0, a5: 255);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473980
// Name: TypeSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl TypeSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  const char *String; // ebx
  const char *v4; // eax
  int result; // eax
  const char *v6; // ebx
  const char *v7; // eax
  int Int; // esi

  String = KeyValues::GetString(this: item1->kv, keyName: "type", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "type", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "file", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "file", defaultValue: defaultValue);
    result = _V_stricmp(s1: v6, s2: v7);
    if ( result == 0 )
    {
      Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
      return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473A20
// Name: FileSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  const char *String; // ebx
  const char *v4; // eax
  int result; // eax
  const char *v6; // ebx
  const char *v7; // eax
  int Int; // esi

  String = KeyValues::GetString(this: item1->kv, keyName: "file", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "file", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "type", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "type", defaultValue: defaultValue);
    result = _V_stricmp(s1: v6, s2: v7);
    if ( result == 0 )
    {
      Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
      return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473AC0
// Name: public: virtual void CAssetBuilder::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnKeyCodeTyped(CAssetBuilder *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE )
  {
    this->OnRemoveSource(this);
  }
  else if ( code == KEY_ENTER )
  {
    this->OnZoomInSource(this);
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473B00
// Name: private: void CAssetBuilder::OnAbortCompile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnAbortCompile(CAssetBuilder *this)
{
  vgui::Button *m_pAbortCompile; // ecx
  CCompileStatusBar *m_pCompileStatusBar; // esi
  vgui::Label *m_pStatus; // ecx

  if ( (*((_BYTE *)this + 492) & 1) != 0 )
  {
    g_pDmeMakefileUtils->AbortCurrentCompilation(this: g_pDmeMakefileUtils);
    m_pAbortCompile = this->m_pAbortCompile;
    *((_BYTE *)this + 492) &= ~1u;
    m_pAbortCompile->SetEnabled(this: m_pAbortCompile, a2: false);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pStatus = m_pCompileStatusBar->m_pStatus;
    m_pCompileStatusBar->m_Status = COMPILATION_FAILED;
    m_pStatus->SetText_2(this: m_pStatus, a2: "Compile Aborted");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473C40
// Name: public: virtual struct vgui::PanelMessageMap __near * CCompileStatusBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCompileStatusBar::GetMessageMap(CCompileStatusBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCompileStatusBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCompileStatusBar::GetMessageMap'::`2'::s_pMap;
  `CCompileStatusBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCompileStatusBar");
  `CCompileStatusBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473C70
// Name: public: virtual struct PanelAnimationMap __near * CCompileStatusBar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCompileStatusBar::GetAnimMap(CCompileStatusBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CCompileStatusBar");
}

//------------------------------------------------------------------------------
// Address: 0x00473C80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCompileStatusBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCompileStatusBar::GetKBMap(CCompileStatusBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCompileStatusBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCompileStatusBar::GetKBMap'::`2'::s_pMap;
  `CCompileStatusBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCompileStatusBar");
  `CCompileStatusBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473CB0
// Name: public: CCompileStatusBar::CCompileStatusBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCompileStatusBar *__thiscall CCompileStatusBar::CCompileStatusBar(
        CCompileStatusBar *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *m_pStatus; // ecx
  int v10; // eax

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CCompileStatusBar_vtbl *)&CCompileStatusBar::`vftable';
  if ( `CCompileStatusBar::ChainToMap'::`2'::chained == 0 )
  {
    `CCompileStatusBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CCompileStatusBar");
    v4->pfnClassName = CCompileStatusBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CCompileStatusBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCompileStatusBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CCompileStatusBar");
    v5->pfnClassName = CCompileStatusBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CCompileStatusBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCompileStatusBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CCompileStatusBar");
    v6->pfnClassName = CCompileStatusBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  v7 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "StatusLabel", text: defaultValue);
  else
    v8 = nullptr;
  this->m_pStatus = v8;
  vgui::Panel::SetAutoResize(
    this: v8,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  this->m_pStatus->SetContentAlignment(this: this->m_pStatus, a2: a_center);
  this->m_pStatus->SetTextColorState(this: this->m_pStatus, a2: CS_BRIGHT);
  m_pStatus = this->m_pStatus;
  this->m_Status = NOT_COMPILING;
  m_pStatus->SetText_2(this: m_pStatus, a2: defaultValue);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v10 = g_pVGuiSurface->DrawGetTextureId(this: g_pVGuiSurface, a2: "vgui/progressbar");
  this->m_CompilingId = v10;
  if ( v10 == -1 )
    this->m_CompilingId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  g_pVGuiSurface->DrawSetTextureFile(
    this: g_pVGuiSurface,
    a2: this->m_CompilingId,
    a3: "vgui/progressbar",
    a4: 1,
    a5: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00473E90
// Name: private: void CAssetBuilder::ShowSourceFileBrowser(char const __near *,struct DmeMakefileType_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::ShowSourceFileBrowser(
        CAssetBuilder *this,
        const char *pTitle,
        DmeMakefileType_t *pSourceType,
        KeyValues *pDialogKeys)
{
  CDmeMakefile *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // esi
  char pContext[260]; // [esp+Ch] [ebp-208h] BYREF
  char pStartingDir[260]; // [esp+110h] [ebp-104h] BYREF

  V_snprintf(pDest: pContext, maxLen: 260, pFormat: "asset_builder_session_%s", pSourceType->m_pTypeName);
  v5 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
  CDmeMakefile::GetDefaultDirectory(
    this: v5,
    pDefaultDirectoryID: pSourceType->m_pDefaultDirectoryID,
    pFullPath: pStartingDir,
    nBufLen: 260);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
  v6 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
  if ( v6 != nullptr )
    v7 = vgui::FileOpenDialog::FileOpenDialog(
           this: v6,
           parent: this,
           title: pTitle,
           bOpenOnly: true,
           pContextKeyValues: pDialogKeys);
  else
    v7 = nullptr;
  vgui::FileOpenDialog::SetStartDirectoryContext(this: v7, pStartDirContext: pContext, pDefaultDir: pStartingDir);
  vgui::FileOpenDialog::AddFilter(
    this: v7,
    filter: pSourceType->m_pFileFilter,
    filterName: pSourceType->m_pFileFilterString,
    bActive: true,
    pFilterInfo: nullptr);
  v7->AddActionSignalTarget_2(this: v7, a2: this);
  vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x00473F70
// Name: private: class KeyValues __near * CAssetBuilder::GetSelectedSourceKeyvalues(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CAssetBuilder::GetSelectedSourceKeyvalues(CAssetBuilder *this)
{
  int v2; // eax

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) != 1
    || g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) == nullptr )
  {
    return nullptr;
  }
  v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
  return this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00473FD0
// Name: private: void CAssetBuilder::OnCompile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnCompile(CAssetBuilder *this)
{
  CDmElement *v2; // eax
  vgui::Button *m_pAbortCompile; // ecx
  CCompileStatusBar *m_pCompileStatusBar; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebx
  int v7; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    CAssetBuilder::OnAbortCompile(this);
    this->m_pCompileOutput->SetText(this: this->m_pCompileOutput, a2: defaultValue);
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    g_pDmeMakefileUtils->PerformCompile(this: g_pDmeMakefileUtils, a2: v2, a3: false);
    m_pAbortCompile = this->m_pAbortCompile;
    *((_BYTE *)this + 492) |= 1u;
    m_pAbortCompile->SetEnabled(this: m_pAbortCompile, a2: true);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pCompileStatusBar->m_Status = CURRENTLY_COMPILING;
    m_pCompileStatusBar->m_pStatus->SetText_2(this: m_pCompileStatusBar->m_pStatus, a2: "Compiling...");
    v5 = g_pVGui;
    v6 = g_pVGui->__vftable;
    v7 = ((int (__thiscall *)(CAssetBuilder *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v6->AddTickSignal)(a1: v5, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474090
// Name: private: virtual void CAssetBuilder::OnBrowseSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnBrowseSourceFile(CAssetBuilder *this)
{
  KeyValues *SelectedSourceKeyvalues; // eax
  int Int; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  CDmElement *v6; // eax
  int v7; // eax

  SelectedSourceKeyvalues = CAssetBuilder::GetSelectedSourceKeyvalues(this);
  if ( SelectedSourceKeyvalues != nullptr )
  {
    Int = KeyValues::GetInt(this: SelectedSourceKeyvalues, keyName: "sourceTypeIndex", defaultValue: -1);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "SelectSourceFile");
    else
      v5 = nullptr;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    v7 = ((int (__thiscall *)(CDmElement *))v6->__vftable[1].OnAttributeArrayElementAdded)(a1: v6);
    CAssetBuilder::ShowSourceFileBrowser(
      this,
      pTitle: "Select Source File",
      pSourceType: (DmeMakefileType_t *)(v7 + 24 * Int),
      pDialogKeys: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474110
// Name: public: virtual void CAssetBuilder::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnCommand(CAssetBuilder *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnCompile") == 0 )
    goto LABEL_2;
  if ( _V_stricmp(s1: pCommand, s2: "OnAbortCompile") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnPublish") == 0 )
    {
LABEL_2:
      CAssetBuilder::OnCompile(this);
      return;
    }
    vgui::Panel::OnCommand(this, command: pCommand);
  }
  else
  {
    CAssetBuilder::OnAbortCompile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474250
// Name: private: void CAssetBuilder::SelectSource(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SelectSource(CAssetBuilder *this, CDmeSource *pSource)
{
  int v3; // edi
  KeyValues *v4; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v6; // eax
  CDmeSource *v7; // esi
  vgui::ListPanel_vtbl *v8; // edx

  v3 = this->m_pSourcesList->FirstItem(this: this->m_pSourcesList);
  if ( v3 != this->m_pSourcesList->InvalidItemID(this: this->m_pSourcesList) )
  {
    while ( 1 )
    {
      v4 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v3);
      Int = KeyValues::GetInt(this: v4, keyName: "dmeSource", defaultValue: -1);
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
      v7 = (CDmeSource *)v6;
      if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeSource::m_classType) )
        v7 = nullptr;
      v8 = this->m_pSourcesList->__vftable;
      if ( v7 == pSource )
        break;
      v3 = ((int (__stdcall *)(int))v8->NextItem)(a1: v3);
      if ( v3 == this->m_pSourcesList->InvalidItemID(this: this->m_pSourcesList) )
        return;
    }
    ((void (__stdcall *)(int))v8->SetSingleSelectedItem)(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474320
// Name: private: void CAssetBuilder::OnNewSourceFileSelected(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnNewSourceFileSelected(CAssetBuilder *this, char *pFileName, KeyValues *kv)
{
  int v4; // eax
  vgui::ListPanel *m_pSourcesList; // ecx
  vgui::ListPanel_vtbl *v6; // edx
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  const char *v9; // ebx
  CDmeMakefile *v10; // eax
  DmFileId_t v11; // eax
  CDmeMakefile *v12; // eax
  CDmeSource *m_handle; // [esp-Ch] [ebp-28h]
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  int nItemID; // [esp+14h] [ebp-8h]
  KeyValues *pKeyValues; // [esp+18h] [ebp-4h]
  const char *pSourceMakeFile; // [esp+28h] [ebp+Ch]
  CDmeMakefile *pSourceMakeFilea; // [esp+28h] [ebp+Ch]

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v4 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    m_pSourcesList = this->m_pSourcesList;
    v6 = m_pSourcesList->__vftable;
    nItemID = v4;
    pKeyValues = v6->GetItem(this: m_pSourcesList, a2: v4);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dmeSource", defaultValue: -1);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v9 = (const char *)v8;
    if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeSource::m_classType) )
    {
      pSourceMakeFile = KeyValues::GetString(this: kv, keyName: "makefileType", defaultValue: defaultValue);
      CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
      m_handle = (CDmeSource *)this->m_hMakefile.m_handle;
      v10 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
      CDmeMakefile::SetSourceFullPath(this: v10, pSource: m_handle, pFullPath: v9);
      v11 = ((int (__thiscall *)(IDataModel *))g_pDataModel->FindOrCreateFileId)(a1: g_pDataModel);
      pSourceMakeFilea = CreateElement<CDmeMakefile>(
                           pElementType: pSourceMakeFile,
                           pObjectName: pFileName,
                           fileid: v11,
                           pObjectID: nullptr);
      CDmeMakefile::SetFileName(this: pSourceMakeFilea, pFileName);
      v12 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, const char *, CDmeMakefile *))g_pDataModel->GetElement)(
                              a1: g_pDataModel,
                              a2: this->m_hMakefile.m_handle,
                              a3: v9,
                              a4: pSourceMakeFilea);
      CDmeMakefile::SetAssociation(
        this: v12,
        pSource: (CDmeSource *)pFileName,
        pSourceMakefile: (CDmeMakefile *)pFileName);
      this->SetDirty(this);
      CChangeUndoScopeGuard::Release(this: &guard);
      KeyValues::SetString(this: pKeyValues, keyName: "file", value: pFileName);
      this->m_pSourcesList->ApplyItemChanges(this: this->m_pSourcesList, a2: nItemID);
      this->m_pSourcesList->SortList(this: this->m_pSourcesList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004744B0
// Name: private: virtual void CAssetBuilder::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAssetBuilder::OnOpenContextMenu(CAssetBuilder *this@<ecx>, int a2@<ebx>, KeyValues *kv)
{
  vgui::Panel *v4; // eax
  vgui::Menu *v6; // eax
  vgui::Menu *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  vgui::Panel *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  vgui::Panel *v13; // eax
  KeyValues *v14; // eax
  CDmeSource *ElementKey; // eax
  CDmeSource *v16; // ebx
  const char *m_pAsString; // eax
  CDmeMakefile *v18; // eax
  vgui::Panel *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // ebx
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // ebx
  vgui::Panel *v25; // eax
  vgui::Panel *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // ebx
  vgui::Panel *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // ebx
  vgui::Panel *v32; // eax
  KeyValues *v33; // eax
  KeyValues *v34; // ebx
  vgui::Panel *v35; // eax
  KeyValues *v36; // eax
  KeyValues *v37; // ebx
  vgui::Panel *v38; // eax
  vgui::Menu *v39; // eax
  int nItemID; // [esp+8h] [ebp-Ch]
  int nCount; // [esp+Ch] [ebp-8h]
  bool bShowLoadSourceFile; // [esp+11h] [ebp-3h]
  bool bShowZoomOut; // [esp+12h] [ebp-2h]
  bool bShowZoomIn; // [esp+13h] [ebp-1h]
  vgui::ListPanel *bHasValidSourceFile; // [esp+1Ch] [ebp+8h]
  bool bHasValidSourceFile_3; // [esp+1Fh] [ebp+Bh]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v4->MarkForDeletion(this: v4);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    bHasValidSourceFile = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
    nItemID = KeyValues::GetInt(this: kv, keyName: "itemID", defaultValue: -1);
    if ( bHasValidSourceFile == this->m_pSourcesList )
    {
      v6 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      if ( v6 != nullptr )
        v7 = vgui::Menu::Menu(this: v6, parent: this, panelName: "ActionMenu");
      else
        v7 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v7);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "AddSource");
      else
        v9 = nullptr;
      v10 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v10->__vftable[1].PaintTraverse)(
        a1: v10,
        a2: "Add...",
        a3: v9,
        a4: this,
        a5: 0);
      nCount = this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList);
      if ( nCount > 0 )
      {
        v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v11 != nullptr )
          v12 = KeyValues::KeyValues(this: v11, setName: "RemoveSource");
        else
          v12 = nullptr;
        v13 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v13->__vftable[1].PaintTraverse)(
          a1: v13,
          a2: "Remove",
          a3: v12,
          a4: this,
          a5: 0);
      }
      bShowZoomIn = false;
      bShowZoomOut = this->m_hMakefileStack.m_Size > 1;
      bShowLoadSourceFile = false;
      bHasValidSourceFile_3 = false;
      if ( nCount == 1 && nItemID != -1 )
      {
        v14 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: nItemID);
        ElementKey = GetElementKeyValue<CDmeSource>(pKeyValues: v14, pName: "dmeSource");
        v16 = ElementKey;
        if ( ElementKey != nullptr )
        {
          m_pAsString = ElementKey->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          bHasValidSourceFile_3 = *m_pAsString != 0;
          v18 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
          if ( CDmeMakefile::FindDependentMakefile(this: v18, pSource: v16) != nullptr )
          {
            bShowZoomIn = true;
            goto LABEL_25;
          }
          bShowLoadSourceFile = bHasValidSourceFile_3;
        }
      }
      if ( !bShowZoomOut )
      {
LABEL_35:
        if ( nCount == 1 )
        {
          v26 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, int))v26->__vftable[1].DeletePanel)(a1: v26, a2);
          v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v27 != nullptr )
            v28 = KeyValues::KeyValues(this: v27, setName: "NewSourceFile");
          else
            v28 = nullptr;
          v29 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v29->__vftable[1].PaintTraverse)(
            a1: v29,
            a2: "New Source File...",
            a3: v28,
            a4: this,
            a5: 0);
          v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v30 != nullptr )
            v31 = KeyValues::KeyValues(this: v30, setName: "BrowseSourceFile");
          else
            v31 = nullptr;
          v32 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *))v32->__vftable[1].PaintTraverse)(
            a1: v32,
            a2: "Select Source File...",
            a3: v31,
            a4: this);
          if ( bShowLoadSourceFile )
          {
            v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v33 != nullptr )
              v34 = KeyValues::KeyValues(this: v33, setName: "LoadSourceFile");
            else
              v34 = nullptr;
            v35 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v35->__vftable[1].PaintTraverse)(
              a1: v35,
              a2: "Load Source File",
              a3: v34,
              a4: this,
              a5: 0);
          }
          if ( bHasValidSourceFile_3 )
          {
            v36 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v36 != nullptr )
              v37 = KeyValues::KeyValues(this: v36, setName: "EditSourceFile");
            else
              v37 = nullptr;
            v38 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v38->__vftable[1].PaintTraverse)(
              a1: v38,
              a2: "Edit Source File",
              a3: v37,
              a4: this,
              a5: 0);
          }
        }
        v39 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::PlaceContextMenu(parent: this, menu: v39);
        return;
      }
LABEL_25:
      v19 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v19->__vftable[1].DeletePanel(this: v19);
      if ( bShowZoomIn )
      {
        v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v20 != nullptr )
          v21 = KeyValues::KeyValues(this: v20, setName: "ZoomInSource");
        else
          v21 = nullptr;
        v22 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v22->__vftable[1].PaintTraverse)(
          a1: v22,
          a2: "Zoom In",
          a3: v21,
          a4: this,
          a5: 0);
      }
      if ( bShowZoomOut )
      {
        v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v23 != nullptr )
          v24 = KeyValues::KeyValues(this: v23, setName: "ZoomOutSource");
        else
          v24 = nullptr;
        v25 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v25->__vftable[1].PaintTraverse)(
          a1: v25,
          a2: "Zoom Out",
          a3: v24,
          a4: this,
          a5: 0);
      }
      goto LABEL_35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474890
// Name: private: void CAssetBuilder::OnSourceItemSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceItemSelectionChanged(CAssetBuilder *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1 )
  {
    v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    v3 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2);
    Int = KeyValues::GetInt(this: v3, keyName: "dmeSource", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeSource::m_classType) )
      v6 = nullptr;
    CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: v6, bForce: false, pPanelName: nullptr);
  }
  else
  {
    CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474930
// Name: private: virtual void CAssetBuilder::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnItemSelected(CAssetBuilder *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pSourcesList )
    CAssetBuilder::OnSourceItemSelectionChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x00474960
// Name: private: class CDmeSource __near * CAssetBuilder::GetSelectedSource(void)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CAssetBuilder::GetSelectedSource(CAssetBuilder *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr
    && (v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0),
        v3 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2),
        Int = KeyValues::GetInt(this: v3, keyName: "dmeSource", defaultValue: -1),
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
        v6 = v5,
        v5 != nullptr)
    && v5->IsA(this: v5, a2: CDmeSource::m_classType) )
  {
    return (CDmeSource *)v6;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474A00
// Name: private: void CAssetBuilder::OnSourceFileNameChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceFileNameChanged(CAssetBuilder *this, const char *pFileName)
{
  int v3; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmeSource *v6; // edi
  CDmeMakefile *v7; // eax
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-Ch] BYREF
  KeyValues *pKeyValues; // [esp+14h] [ebp-4h]

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v3 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    pKeyValues = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v3);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dmeSource", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = (CDmeSource *)v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeSource::m_classType) )
    {
      CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
      v7 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
      CDmeMakefile::SetSourceFullPath(this: v7, pSource: v6, pFullPath: pFileName);
      this->SetDirty(this);
      CChangeUndoScopeGuard::Release(this: &guard);
      KeyValues::SetString(this: pKeyValues, keyName: "file", value: pFileName);
      this->m_pSourcesList->ApplyItemChanges(this: this->m_pSourcesList, a2: v3);
      this->m_pSourcesList->SortList(this: this->m_pSourcesList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474B20
// Name: private: virtual void CAssetBuilder::OnEditSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnEditSourceFile(CAssetBuilder *this)
{
  CDmeSource *SelectedSource; // eax

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
    CDmeSource::OpenEditor(this: SelectedSource);
}

//------------------------------------------------------------------------------
// Address: 0x00474B40
// Name: private: virtual void CAssetBuilder::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnFileSelected(CAssetBuilder *this, KeyValues *kv)
{
  char *String; // esi
  KeyValues *Key; // edi

  String = (char *)KeyValues::GetString(this: kv, keyName: "fullpath", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( KeyValues::FindKey(this: kv, keyName: "SelectSourceFile", bCreate: false) != nullptr )
      goto LABEL_6;
    Key = KeyValues::FindKey(this: kv, keyName: "NewSourceFileSelected", bCreate: false);
    if ( Key == nullptr )
      return;
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: String, a3: nullptr) )
LABEL_6:
      CAssetBuilder::OnSourceFileNameChanged(this, pFileName: String);
    else
      CAssetBuilder::OnNewSourceFileSelected(this, pFileName: String, kv: Key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474C50
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x00474CE0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x00474D70
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
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
// Address: 0x00474E00
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x00474E90
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
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
// Address: 0x00474F20
// Name: public: static void CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_SetDirty::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_SetDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474FB0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475040
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "NewSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004750D0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LoadSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475160
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "EditSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004751F0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475280
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BrowseSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475310
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ZoomInSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004753A0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ZoomOutSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475430
// Name: void BuildAssetTypeList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildAssetTypeList()
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  int v1; // edi
  bool (__thiscall *IsValidFactory)(IDataModel *, int); // edx
  const char *v3; // ebx
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CExpressionCalculator *v6; // esi
  int m_Size; // eax
  int v8; // edi
  PickerInfo_t *m_pMemory; // ecx
  int v10; // eax
  int (__thiscall *v11)(CExpressionCalculator *); // eax
  IDataModel_vtbl *v12; // edi
  int BufferType; // eax
  int v14; // eax
  IDataModel_vtbl *v15; // edx
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  PickerInfo_t *v17; // [esp+14h] [ebp-8h]
  int hFactory; // [esp+18h] [ebp-4h]

  if ( !s_bAssetTypeListBuilt )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    s_bAssetTypeListBuilt = true;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v1 = g_pDataModel->GetFirstFactory(this: g_pDataModel);
    IsValidFactory = g_pDataModel->IsValidFactory;
    hFactory = v1;
    if ( IsValidFactory(this: g_pDataModel, a2: v1) )
    {
      while ( 1 )
      {
        v3 = g_pDataModel->GetFactoryName(this: g_pDataModel, a2: v1);
        v4 = g_pDataModel->CreateElement(this: g_pDataModel, a2: v3, a3: "temp", a4: DMFILEID_INVALID, a5: nullptr);
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
        v6 = (CExpressionCalculator *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
        {
          if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v6->m_expr.m_Storage.m_Memory.m_pMemory
                + 4))(
                 a1: v6,
                 a2: CDmeMakefile::m_classType.u) != 0
            && (*((int (__thiscall **)(CExpressionCalculator *))v6->m_expr.m_Storage.m_Memory.m_pMemory + 14))(a1: v6) != 0 )
          {
            m_Size = s_AssetTypes.m_Choices.m_Size;
            v8 = s_AssetTypes.m_Choices.m_Size;
            if ( s_AssetTypes.m_Choices.m_Size + 1 > s_AssetTypes.m_Choices.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<MDLSquenceLayer_t,int>::Grow(
                this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&s_AssetTypes.m_Choices,
                num: s_AssetTypes.m_Choices.m_Size - s_AssetTypes.m_Choices.m_Memory.m_nAllocationCount + 1);
              m_Size = s_AssetTypes.m_Choices.m_Size;
            }
            m_pMemory = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            s_AssetTypes.m_Choices.m_Size = m_Size + 1;
            v10 = m_Size - v8;
            s_AssetTypes.m_Choices.m_pElements = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            if ( v10 > 0 )
            {
              _V_memmove(
                dest: &s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8 + 1],
                src: &s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8],
                count: 8 * v10);
              m_pMemory = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            }
            v11 = *((int (__thiscall **)(CExpressionCalculator *))v6->m_expr.m_Storage.m_Memory.m_pMemory + 14);
            v17 = &m_pMemory[v8];
            v17->m_pChoiceString = *(const char **)(v11(a1: v6) + 4);
            s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8].m_pChoiceValue = v3;
          }
          v12 = g_pDataModel->__vftable;
          BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
          v12->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
          v1 = hFactory;
        }
        v14 = g_pDataModel->GetNextFactory(this: g_pDataModel, a2: v1);
        v15 = g_pDataModel->__vftable;
        hFactory = v14;
        if ( !v15->IsValidFactory(this: g_pDataModel, a2: v14) )
          break;
        v1 = hFactory;
      }
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475610
// Name: BuildAssetSubTypeList
// Source: json
//------------------------------------------------------------------------------
PickerList_t *__cdecl BuildAssetSubTypeList(const char **ppSubTypes, PickerList_t *pickerList)
{
  CExpressionCalculator *v2; // ebx
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeMakefile *v6; // esi
  bool (__thiscall *IsA)(struct CDmeMakefile *, CUtlSymbolLarge); // eax
  char v8; // al
  const char **v9; // eax
  int v10; // esi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v14; // eax
  int v15; // ebx
  PickerInfo_t *v16; // esi
  IDataModel_vtbl *v17; // esi
  int BufferType; // eax
  bool guard_4; // [esp+10h] [ebp-18h]
  int nCount; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h] BYREF
  CDmeMakefile *pMakeFile; // [esp+1Ch] [ebp-Ch]
  CExpressionCalculator *v23; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v2 = nullptr;
  if ( ppSubTypes == nullptr )
    return &s_AssetTypes;
  pickerList->m_Choices.m_Size = 0;
  guard_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  nCount = s_AssetTypes.m_Choices.m_Size;
  i = 0;
  if ( s_AssetTypes.m_Choices.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = g_pDataModel->CreateElement(
             this: g_pDataModel,
             a2: s_AssetTypes.m_Choices.m_Memory.m_pMemory[i].m_pChoiceValue,
             a3: "temp",
             a4: DMFILEID_INVALID,
             a5: nullptr);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
      v6 = (CDmeMakefile *)v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        IsA = v6->IsA;
        v2 = (CExpressionCalculator *)v6;
        v23 = (CExpressionCalculator *)v6;
        v8 = ((int (__thiscall *)(_DWORD, _DWORD))IsA)(a1: v6, a2: (CUtlSymbolLarge)CDmeMakefile::m_classType.u.m_Id);
        pMakeFile = v6;
        if ( v8 != 0 )
          goto LABEL_10;
      }
      else
      {
        v23 = nullptr;
      }
      pMakeFile = nullptr;
LABEL_10:
      v9 = ppSubTypes;
      v10 = 0;
      if ( *ppSubTypes != nullptr )
      {
        while ( 1 )
        {
          g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v21, a3: *v9);
          if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, int))v2->m_expr.m_Storage.m_Memory.m_pMemory
                + 4))(
                 a1: v2,
                 a2: v21) != 0 )
            break;
          v9 = &ppSubTypes[++v10];
          if ( *v9 == nullptr )
            goto LABEL_20;
        }
        m_Size = pickerList->m_Choices.m_Size;
        m_nAllocationCount = pickerList->m_Choices.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<MDLSquenceLayer_t,int>::Grow(
            this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&pickerList->m_Choices,
            num: m_Size - m_nAllocationCount + 1);
        ++pickerList->m_Choices.m_Size;
        m_pMemory = pickerList->m_Choices.m_Memory.m_pMemory;
        v14 = pickerList->m_Choices.m_Size - m_Size - 1;
        pickerList->m_Choices.m_pElements = m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v14);
        v15 = m_Size;
        v16 = pickerList->m_Choices.m_Memory.m_pMemory;
        v16[v15].m_pChoiceString = pMakeFile->GetMakefileType(this: pMakeFile)->m_pHumanReadableName;
        pickerList->m_Choices.m_Memory.m_pMemory[v15].m_pChoiceValue = s_AssetTypes.m_Choices.m_Memory.m_pMemory[i].m_pChoiceValue;
        v2 = v23;
      }
LABEL_20:
      if ( v2 != nullptr )
      {
        v17 = g_pDataModel->__vftable;
        BufferType = CCodecBuffer_Block::GetBufferType(this: v2);
        v17->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
      }
      if ( ++i >= nCount )
        break;
      v2 = nullptr;
    }
  }
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
  return pickerList;
}

//------------------------------------------------------------------------------
// Address: 0x00475810
// Name: ReadMakefile
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__usercall ReadMakefile@<eax>(const char *pFileName@<edi>, CDmElement **ppRoot)
{
  CDmElement **v2; // ebx
  CDmeMakefile *Value; // esi
  CDmElement **v4; // esi
  CDmElement *v5; // ecx
  CDmElement *v6; // esi

  v2 = ppRoot;
  if ( ppRoot != nullptr )
    *ppRoot = nullptr;
  if ( g_pDataModel->RestoreFromFile(
         this: g_pDataModel,
         a2: pFileName,
         a3: nullptr,
         a4: nullptr,
         a5: (CDmElement **)&ppRoot,
         a6: CR_DELETE_OLD,
         a7: nullptr) == DMFILEID_INVALID
    || (Value = (CDmeMakefile *)ppRoot, ppRoot == nullptr) )
  {
    _Warning(a1: "Unable to read makefile \"%s\"!\n", pFileName);
    return nullptr;
  }
  if ( (*(unsigned __int8 (__thiscall **)(CDmElement **, CUtlSymbolLarge::<unnamed_type_u>))&(*ppRoot)->m_Id.m_Value[12])(
         a1: ppRoot,
         a2: CDmeMakefile::m_classType.u) == 0 )
  {
    v4 = ppRoot;
    if ( ppRoot != nullptr
      && (*(unsigned __int8 (__thiscall **)(CDmElement **, CUtlSymbolLarge::<unnamed_type_u>))&(*ppRoot)->m_Id.m_Value[12])(
           a1: ppRoot,
           a2: CDmElement::m_classType.u) != 0 )
    {
      v5 = (CDmElement *)v4;
    }
    else
    {
      v5 = nullptr;
    }
    Value = CDmElement::GetValueElement<CDmeMakefile>(this: v5, pAttributeName: "makefile");
    if ( Value == nullptr )
    {
      v6 = ppRoot[14];
      DestroyElement(pElement: (CDmElement *)ppRoot);
      if ( v6 != (CDmElement *)-1 && *g_pDataModel->GetFileName(this: g_pDataModel, a2: v6) != 0 )
      {
        g_pDataModel->RemoveFileId(this: g_pDataModel, a2: (DmFileId_t)v6);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( v2 != nullptr )
    *v2 = CastElement<CDmElement>(pElement: (CDmElement *)ppRoot);
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x00475910
// Name: public: CAssetBuilder::CAssetBuilder(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetBuilder *__thiscall CAssetBuilder::CAssetBuilder(
        CAssetBuilder *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::PropertyPage *v9; // eax
  vgui::PropertyPage *v10; // eax
  vgui::PropertyPage *v11; // eax
  vgui::PropertyPage *v12; // eax
  vgui::PropertyPage *v13; // eax
  vgui::PropertyPage *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  vgui::Splitter *v17; // eax
  vgui::Splitter *v18; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v20; // edi
  CDmePanel *v21; // eax
  CDmePanel *v22; // eax
  CDmePanel *v23; // eax
  CDmePanel *v24; // eax
  vgui::ListPanel *v25; // eax
  vgui::ListPanel *v26; // eax
  vgui::ListPanel *v27; // eax
  vgui::ListPanel *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::TextEntry *v30; // eax
  vgui::Button *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::Button *v34; // eax
  vgui::Button *v35; // eax
  vgui::Button *v36; // eax
  CCompileStatusBar *v37; // eax
  CCompileStatusBar *v38; // eax
  vgui::PropertyPage *m_pInputPage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CAssetBuilder_vtbl *)&CAssetBuilder::`vftable';
  if ( `CAssetBuilder::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v4->pfnClassName = CAssetBuilder::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CAssetBuilder::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAssetBuilder");
    v5->pfnClassName = CAssetBuilder::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CAssetBuilder::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetBuilder");
    v6->pfnClassName = CAssetBuilder::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_hRootMakefile.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hMakefile.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hMakefileStack.m_Memory.m_pMemory = nullptr;
  this->m_hMakefileStack.m_Memory.m_nAllocationCount = 0;
  this->m_hMakefileStack.m_Memory.m_nGrowSize = 0;
  this->m_hMakefileStack.m_Size = 0;
  this->m_hMakefileStack.m_pElements = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: DMELEMENT_HANDLE_INVALID);
  *((_BYTE *)this + 492) = *((_BYTE *)this + 492) & 0xFC | 2;
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "InputOutputSheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pInputOutputSheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v9 != nullptr )
    v10 = vgui::PropertyPage::PropertyPage(this: v9, parent: this->m_pInputOutputSheet, panelName: "InputPage");
  else
    v10 = nullptr;
  this->m_pInputPage = v10;
  v11 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v11 != nullptr )
    v12 = vgui::PropertyPage::PropertyPage(this: v11, parent: this->m_pInputOutputSheet, panelName: "OutputPage");
  else
    v12 = nullptr;
  this->m_pOutputPage = v12;
  v13 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v13 != nullptr )
    v14 = vgui::PropertyPage::PropertyPage(this: v13, parent: this->m_pInputOutputSheet, panelName: "CompilePage");
  else
    v14 = nullptr;
  this->m_pCompilePage = v14;
  v15 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v15 != nullptr )
    v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pInputOutputSheet, panelName: "OutputPreviewPage");
  else
    v16 = nullptr;
  this->m_pOutputPreviewPage = v16;
  v17 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v17 != nullptr )
    v18 = vgui::Splitter::Splitter(
            this: v17,
            parent: this->m_pInputPage,
            name: "PropertiesSplitter",
            mode: SPLITTER_MODE_VERTICAL,
            nCount: 1);
  else
    v18 = nullptr;
  this->m_pPropertiesSplitter = v18;
  Child = vgui::Panel::GetChild(this: v18, index: 0);
  v20 = vgui::Panel::GetChild(this: this->m_pPropertiesSplitter, index: 1);
  v21 = (CDmePanel *)MemAlloc_Alloc(nSize: 0x250u);
  if ( v21 != nullptr )
    v22 = CDmePanel::CDmePanel(this: v21, pParent: v20, pPanelName: "CompileOptions", bComboBoxVisible: true);
  else
    v22 = nullptr;
  this->m_pDmePanel = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (CDmePanel *)MemAlloc_Alloc(nSize: 0x250u);
  if ( v23 != nullptr )
    v24 = CDmePanel::CDmePanel(
            this: v23,
            pParent: this->m_pOutputPreviewPage,
            pPanelName: "OutputPreview",
            bComboBoxVisible: false);
  else
    v24 = nullptr;
  this->m_pOututPreviewPanel = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  v25 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v25 != nullptr )
    v26 = vgui::ListPanel::ListPanel(this: v25, parent: Child, panelName: "SourcesList");
  else
    v26 = nullptr;
  this->m_pSourcesList = v26;
  v26->AddColumnHeader(this: v26, a2: 0, a3: "type", a4: "type", a5: 100, a6: 0);
  this->m_pSourcesList->AddColumnHeader(this: this->m_pSourcesList, a2: 1, a3: "file", a4: "file", a5: 52, a6: 0);
  this->m_pSourcesList->AddActionSignalTarget_2(this: this->m_pSourcesList, a2: this);
  this->m_pSourcesList->SetSortFunc(this: this->m_pSourcesList, a2: 0, a3: TypeSortFunc);
  this->m_pSourcesList->SetSortFunc(this: this->m_pSourcesList, a2: 1, a3: FileSortFunc);
  this->m_pSourcesList->SetSortColumn(this: this->m_pSourcesList, a2: 0);
  this->m_pSourcesList->SetEmptyListText_2(this: this->m_pSourcesList, a2: "No sources");
  v27 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v27 != nullptr )
    v28 = vgui::ListPanel::ListPanel(this: v27, parent: this->m_pOutputPage, panelName: "OutputList");
  else
    v28 = nullptr;
  this->m_pOutputList = v28;
  v28->AddColumnHeader(this: v28, a2: 0, a3: "type", a4: "type", a5: 100, a6: 0);
  this->m_pOutputList->AddColumnHeader(this: this->m_pOutputList, a2: 1, a3: "file", a4: "file", a5: 52, a6: 0);
  this->m_pOutputList->AddActionSignalTarget_2(this: this->m_pOutputList, a2: this);
  this->m_pOutputList->SetSortFunc(this: this->m_pOutputList, a2: 0, a3: TypeSortFunc);
  this->m_pOutputList->SetSortFunc(this: this->m_pOutputList, a2: 1, a3: FileSortFunc);
  this->m_pOutputList->SetSortColumn(this: this->m_pOutputList, a2: 0);
  this->m_pOutputList->SetEmptyListText_2(this: this->m_pOutputList, a2: "No outputs");
  v29 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v29 != nullptr )
    v30 = vgui::TextEntry::TextEntry(this: v29, parent: this->m_pCompilePage, panelName: "CompileOutput");
  else
    v30 = nullptr;
  this->m_pCompileOutput = v30;
  v30->SetMultiline(this: v30, a2: true);
  this->m_pCompileOutput->SetVerticalScrollbar(this: this->m_pCompileOutput, a2: true);
  v31 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v31 != nullptr )
    v32 = vgui::Button::Button(
            this: v31,
            parent: this,
            panelName: "CompileButton",
            text: "Compile",
            pActionSignalTarget: this,
            pCmd: "OnCompile");
  else
    v32 = nullptr;
  this->m_pCompile = v32;
  v33 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v33 != nullptr )
    v34 = vgui::Button::Button(
            this: v33,
            parent: this,
            panelName: "PublishButton",
            text: "Publish",
            pActionSignalTarget: this,
            pCmd: "OnPublish");
  else
    v34 = nullptr;
  this->m_pPublish = v34;
  v35 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v35 != nullptr )
    v36 = vgui::Button::Button(
            this: v35,
            parent: this,
            panelName: "AbortCompileButton",
            text: "AbortCompile",
            pActionSignalTarget: this,
            pCmd: "OnAbortCompile");
  else
    v36 = nullptr;
  this->m_pAbortCompile = v36;
  v37 = (CCompileStatusBar *)MemAlloc_Alloc(nSize: 0x18Cu);
  if ( v37 != nullptr )
    v38 = CCompileStatusBar::CCompileStatusBar(this: v37, pParent: this, pPanelName: "CompileStatus");
  else
    v38 = nullptr;
  m_pInputPage = this->m_pInputPage;
  this->m_pCompileStatusBar = v38;
  m_pInputPage->LoadControlSettingsAndUserConfig(this: m_pInputPage, a2: "resource/assetbuilderinputpage.res", a3: 0);
  this->m_pOutputPage->LoadControlSettingsAndUserConfig(
    this: this->m_pOutputPage,
    a2: "resource/assetbuilderoutputpage.res",
    a3: 0);
  this->m_pCompilePage->LoadControlSettingsAndUserConfig(
    this: this->m_pCompilePage,
    a2: "resource/assetbuildercompilepage.res",
    a3: 0);
  this->m_pOutputPreviewPage->LoadControlSettingsAndUserConfig(
    this: this->m_pOutputPreviewPage,
    a2: "resource/assetbuilderoutputpreviewpage.res",
    a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetbuilder.res",
    dialogID: 0);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pInputPage,
    a3: "Input",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pOutputPage,
    a3: "Output",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pCompilePage,
    a3: "Compile",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pOutputPreviewPage,
    a3: "Preview",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: false);
  this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: false);
  this->m_pAbortCompile->SetEnabled(this: this->m_pAbortCompile, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00476000
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetBuilder::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetBuilder::GetMessageMap(CAssetBuilder *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetBuilder::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetBuilder::GetMessageMap'::`2'::s_pMap;
  `CAssetBuilder::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
  `CAssetBuilder::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476030
// Name: public: virtual struct PanelAnimationMap __near * CAssetBuilder::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetBuilder::GetAnimMap(CAssetBuilder *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetBuilder");
}

//------------------------------------------------------------------------------
// Address: 0x00476040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetBuilder::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetBuilder::GetKBMap(CAssetBuilder *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetBuilder::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetBuilder::GetKBMap'::`2'::s_pMap;
  `CAssetBuilder::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetBuilder");
  `CAssetBuilder::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476070
// Name: private: void CAssetBuilder::BuildFileIDList(class CDmeMakefile __near *,class CUtlVector<enum DmFileId_t,class CUtlMemory<enum DmFileId_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::BuildFileIDList(
        CAssetBuilder *this,
        CDmeTransform *pMakeFile,
        CUtlMemory<vgui::TreeNode *,int> *fileIds)
{
  DmFileId_t m_fileId; // ebx
  int m_pMemory; // edi
  int v5; // eax
  DmFileId_t *v6; // ecx
  int m_nAllocationCount; // eax
  DmFileId_t *v8; // ecx
  int v9; // eax
  DmFileId_t *v10; // edi
  CDmAttribute *ClipCount; // ebx
  int i; // edi
  CDmeSource *Source; // eax
  CDmeMakefile *DependentMakefile; // eax

  if ( pMakeFile != nullptr )
  {
    m_fileId = pMakeFile->m_fileId;
    m_pMemory = (int)fileIds[1].m_pMemory;
    v5 = 0;
    if ( m_pMemory > 0 )
    {
      v6 = (DmFileId_t *)fileIds->m_pMemory;
      do
      {
        if ( *v6 == m_fileId )
          break;
        ++v5;
        ++v6;
      }
      while ( v5 < m_pMemory );
    }
    if ( v5 == m_pMemory )
    {
      m_nAllocationCount = fileIds->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: fileIds, num: m_pMemory - m_nAllocationCount + 1);
      ++fileIds[1].m_pMemory;
      v8 = (DmFileId_t *)fileIds->m_pMemory;
      v9 = (int)fileIds[1].m_pMemory - m_pMemory - 1;
      fileIds[1].m_nAllocationCount = (int)fileIds->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
      v10 = (DmFileId_t *)&fileIds->m_pMemory[m_pMemory];
      if ( v10 != nullptr )
        *v10 = m_fileId;
    }
    ClipCount = CDmeTrack::GetClipCount(this: pMakeFile);
    for ( i = 0; i < (int)ClipCount; ++i )
    {
      Source = CDmeMakefile::GetSource(this: (CDmeMakefile *)pMakeFile, nIndex: i);
      DependentMakefile = CDmeSource::GetDependentMakefile(this: Source);
      CAssetBuilder::BuildFileIDList(
        this,
        pMakeFile: DependentMakefile,
        (CUtlVector<enum DmFileId_t,CUtlMemory<enum DmFileId_t,int> > *)fileIds);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476130
// Name: private: void CAssetBuilder::CleanupMakefile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::CleanupMakefile(CAssetBuilder *this)
{
  int i; // edi
  DmElementHandle_t m_handle; // eax
  CDmeTransform *v4; // eax
  int v5; // esi
  int j; // edi
  DmFileId_t *m_pMemory; // eax
  CUtlVector<enum DmFileId_t,CUtlMemory<enum DmFileId_t,int> > fileIds; // [esp+Ch] [ebp-1Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+20h] [ebp-8h]

  for ( i = this->m_hMakefileStack.m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel != nullptr )
      CDmeElementRefHelper::Unref(
        this: &this->m_hMakefileStack.m_Memory.m_pMemory[i],
        hElement: this->m_hMakefileStack.m_Memory.m_pMemory[i].m_handle,
        handleType: HT_WEAK);
  }
  this->m_hMakefileStack.m_Size = 0;
  CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  CDmePanel::SetDmeElement(this: this->m_pOututPreviewPanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRootMakefile.m_handle) != nullptr )
  {
    m_handle = this->m_hRootMakefile.m_handle;
    memset(&fileIds, 0, sizeof(fileIds));
    v4 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
    CAssetBuilder::BuildFileIDList(this, pMakeFile: v4, (CUtlMemory<vgui::TreeNode *,int> *)&fileIds);
    guard.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: DMELEMENT_HANDLE_INVALID);
    v5 = 0;
    for ( j = fileIds.m_Size; v5 < j; ++v5 )
    {
      if ( fileIds.m_Memory.m_pMemory[v5] != DMFILEID_INVALID
        && *g_pDataModel->GetFileName(this: g_pDataModel, a2: fileIds.m_Memory.m_pMemory[v5]) != 0 )
      {
        g_pDataModel->RemoveFileId(this: g_pDataModel, a2: fileIds.m_Memory.m_pMemory[v5]);
      }
    }
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
    m_pMemory = fileIds.m_Memory.m_pMemory;
    fileIds.m_Size = 0;
    if ( fileIds.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileIds.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileIds.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileIds.m_Memory.m_pMemory = nullptr;
      }
      fileIds.m_Memory.m_nAllocationCount = 0;
    }
    fileIds.m_pElements = m_pMemory;
    if ( fileIds.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004762C0
// Name: private: virtual void CAssetBuilder::OnNewSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnNewSourceFile(CAssetBuilder *this)
{
  KeyValues *SelectedSourceKeyvalues; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char **v6; // eax
  const PickerList_t *v7; // esi
  CPickerFrame *v8; // eax
  CPickerFrame *v9; // eax
  PickerList_t typePickerList; // [esp+Ch] [ebp-18h] BYREF

  SelectedSourceKeyvalues = CAssetBuilder::GetSelectedSourceKeyvalues(this);
  Int = KeyValues::GetInt(this: SelectedSourceKeyvalues, keyName: "dmeSource", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeSource::m_classType) )
  {
    BuildAssetTypeList();
    memset(&typePickerList, 0, sizeof(typePickerList));
    v6 = (const char **)((int (__thiscall *)(CDmElement *))v5->__vftable[1].OnAttributeChanged)(a1: v5);
    v7 = BuildAssetSubTypeList(ppSubTypes: v6, pickerList: &typePickerList);
    v8 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v8 != nullptr )
      v9 = CPickerFrame::CPickerFrame(
             this: v8,
             pParent: this,
             pTitle: "Select Sub-Asset Type",
             pPickerType: "Asset Type",
             pTextType: "assetType");
    else
      v9 = nullptr;
    CPickerFrame::DoModal(this: v9, list: v7, pContextKeyValues: nullptr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&typePickerList.m_Choices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476380
// Name: private: virtual void CAssetBuilder::OnAddSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnAddSource(CAssetBuilder *this)
{
  vgui::Panel *v1; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  DmElementHandle_t m_pElements; // eax
  int v4; // ebx
  CDmElement *v5; // eax
  DmeMakefileType_t *v6; // eax
  DmeMakefileType_t *v7; // esi
  DmeMakefileType_t *v8; // edi
  CDmeMakefile *v9; // eax
  int m_Size; // eax
  int v11; // esi
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  CPickerFrame *v16; // eax
  CPickerFrame *v17; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-28h]
  PickerList_t sourceType; // [esp+4h] [ebp-20h] BYREF
  DmeMakefileType_t *pSourceTypes; // [esp+1Ch] [ebp-8h]
  CAssetBuilder *v21; // [esp+20h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hMakefile.m_handle;
  v21 = this;
  if ( (int)GetElement(this: g_pDataModel, a2: m_handle) != 0 )
  {
    m_pElements = (DmElementHandle_t)v1[1].m_OverridableColorEntries.m_pElements;
    v4 = 0;
    memset(&sourceType, 0, sizeof(sourceType));
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pElements);
    v6 = (DmeMakefileType_t *)((int (__thiscall *)(CDmElement *))v5->__vftable[1].OnAttributeArrayElementAdded)(a1: v5);
    v7 = v6;
    pSourceTypes = v6;
    if ( v6->m_pTypeName != nullptr )
    {
      v8 = v6;
      do
      {
        if ( !v8->m_bIsSingleton
          || (v9 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: v21->m_hMakefile.m_handle),
              !CDmeMakefile::HasSourceOfType(this: v9, pSourceType: v8->m_pTypeName)) )
        {
          m_Size = sourceType.m_Choices.m_Size;
          v11 = sourceType.m_Choices.m_Size;
          if ( sourceType.m_Choices.m_Size + 1 > sourceType.m_Choices.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<MDLSquenceLayer_t,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&sourceType.m_Choices,
              num: sourceType.m_Choices.m_Size - sourceType.m_Choices.m_Memory.m_nAllocationCount + 1);
            m_Size = sourceType.m_Choices.m_Size;
          }
          m_pMemory = sourceType.m_Choices.m_Memory.m_pMemory;
          sourceType.m_Choices.m_Size = m_Size + 1;
          v13 = m_Size - v11;
          sourceType.m_Choices.m_pElements = sourceType.m_Choices.m_Memory.m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(
              dest: &sourceType.m_Choices.m_Memory.m_pMemory[v11 + 1],
              src: &sourceType.m_Choices.m_Memory.m_pMemory[v11],
              count: 8 * v13);
            m_pMemory = sourceType.m_Choices.m_Memory.m_pMemory;
          }
          m_pMemory[v11].m_pChoiceString = v8->m_pHumanReadableName;
          sourceType.m_Choices.m_Memory.m_pMemory[v11].m_pChoiceValue = v8->m_pTypeName;
          v7 = pSourceTypes;
        }
        v8 = &v7[++v4];
      }
      while ( v8->m_pTypeName != nullptr );
      v1 = v21;
    }
    if ( sourceType.m_Choices.m_Size != 0 )
    {
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "OnAddSource");
      else
        v15 = nullptr;
      v16 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
      if ( v16 != nullptr )
        v17 = CPickerFrame::CPickerFrame(
                this: v16,
                pParent: v1,
                pTitle: "Select Source Type",
                pPickerType: "Source Type",
                pTextType: "sourceType");
      else
        v17 = nullptr;
      CPickerFrame::DoModal(this: v17, list: &sourceType, pContextKeyValues: v15);
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sourceType.m_Choices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476500
// Name: private: virtual void CAssetBuilder::OnLoadSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::OnLoadSourceFile(CAssetBuilder *this@<ecx>, int a2@<edi>)
{
  CDmeSource *SelectedSource; // ebx
  CDmeMakefile *v4; // eax
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDmeMakefile *v6; // eax
  CDmeMakefile *v7; // eax
  CDmeMakefile *v8; // [esp-4h] [ebp-11Ch]
  char pFullPath[260]; // [esp+8h] [ebp-110h] BYREF
  CDmElement *pRoot; // [esp+10Ch] [ebp-Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+110h] [ebp-8h] BYREF

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
  {
    v4 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, CDmeSource *))g_pDataModel->GetElement)(
                           a1: g_pDataModel,
                           a2: this->m_hMakefile.m_handle,
                           a3: SelectedSource);
    CDmeMakefile::GetSourceFullPath(this: v4, pSource: (CDmeSource *)pFullPath, pFullPath: (char *)0x104, nBufLen: a2);
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = ReadMakefile(pFileName: pFullPath, ppRoot: &pRoot);
    if ( v6 != nullptr )
    {
      v8 = v6;
      v7 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
      CDmeMakefile::SetAssociation(this: v7, pSource: SelectedSource, pSourceMakefile: v8);
      CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: SelectedSource, bForce: true, pPanelName: nullptr);
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004765D0
// Name: public: virtual CAssetBuilder::~CAssetBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::~CAssetBuilder(CAssetBuilder *this)
{
  bool v2; // zf
  vgui::Panel *v3; // eax

  v2 = (*((_BYTE *)this + 492) & 2) == 0;
  this->__vftable = (CAssetBuilder_vtbl *)&CAssetBuilder::`vftable';
  if ( !v2 )
    CAssetBuilder::CleanupMakefile(this);
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v3->MarkForDeletion(this: v3);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int>>::Purge(this: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)&this->m_hMakefileStack);
  if ( this->m_hMakefileStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_hMakefileStack.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hMakefileStack.m_Memory.m_pMemory);
      this->m_hMakefileStack.m_Memory.m_pMemory = nullptr;
    }
    this->m_hMakefileStack.m_Memory.m_nAllocationCount = 0;
  }
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hMakefile, hElement: this->m_hMakefile.m_handle, handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hRootMakefile,
      hElement: this->m_hRootMakefile.m_handle,
      handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004766A0
// Name: private: void CAssetBuilder::RefreshSourceList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::RefreshSourceList(CAssetBuilder *this@<ecx>, char *a2@<edi>, int a3@<esi>)
{
  CDmElement *v4; // eax
  DmeMakefileType_t *v5; // eax
  KeyValues *v6; // esi
  DmElementHandle_t m_handle; // eax
  CDmeMakefile *v8; // eax
  int v9; // edi
  int v10; // eax
  CDmeMakefile *v11; // eax
  KeyValues *v12; // eax
  CExpressionCalculator *v13; // eax
  int BufferType; // eax
  int v15; // ecx
  CDmeSource *v16; // [esp-Ch] [ebp-138h]
  char pFullPath[260]; // [esp+4h] [ebp-128h] BYREF
  DmeMakefileType_t *pSourceTypes; // [esp+108h] [ebp-24h]
  int nCount; // [esp+10Ch] [ebp-20h]
  CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int> > sources; // [esp+110h] [ebp-1Ch] BYREF
  int i; // [esp+124h] [ebp-8h]
  DmeMakefileType_t *v24; // [esp+128h] [ebp-4h]

  this->m_pSourcesList->RemoveAll(this: this->m_pSourcesList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    v5 = (DmeMakefileType_t *)((int (__thiscall *)(CDmElement *))v4->__vftable[1].OnAttributeArrayElementAdded)(a1: v4);
    v6 = nullptr;
    pSourceTypes = v5;
    i = 0;
    if ( v5->m_pTypeName != nullptr )
    {
      v24 = v5;
      do
      {
        m_handle = this->m_hMakefile.m_handle;
        memset(&sources, 0, sizeof(sources));
        v8 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
        CDmeMakefile::GetSources(this: v8, pSourceType: v24->m_pTypeName, &sources);
        v9 = 0;
        for ( nCount = sources.m_Size; v9 < nCount; v6 = nullptr )
        {
          v16 = (CDmeSource *)sources.m_Memory.m_pMemory[v9].m_handle;
          v10 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
          v11 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int, char *, int))g_pDataModel->GetElement)(
                                  a1: g_pDataModel,
                                  a2: this->m_hMakefile.m_handle,
                                  a3: v10,
                                  a4: pFullPath,
                                  a5: 260);
          CDmeMakefile::GetSourceFullPath(this: v11, pSource: v16, pFullPath: a2, nBufLen: a3);
          v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v12 != nullptr )
            v6 = KeyValues::KeyValues(
                   this: v12,
                   setName: "node",
                   firstKey: "type",
                   firstValue: v24->m_pHumanReadableName);
          KeyValues::SetString(this: v6, keyName: "file", value: pFullPath);
          KeyValues::SetInt(this: v6, keyName: "sourceTypeIndex", value: i);
          KeyValues::SetInt(this: v6, keyName: "index", value: v9);
          v13 = (CExpressionCalculator *)g_pDataModel->GetElement(
                                           this: g_pDataModel,
                                           a2: sources.m_Memory.m_pMemory[v9].m_handle);
          if ( v13 != nullptr )
            BufferType = CCodecBuffer_Block::GetBufferType(this: v13);
          else
            BufferType = -1;
          KeyValues::SetInt(this: v6, keyName: "dmeSource", value: BufferType);
          a3 = 0;
          a2 = nullptr;
          ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD))this->m_pSourcesList->AddItem)(
            a1: this->m_pSourcesList,
            a2: v6,
            a3: 0);
          ++v9;
        }
        CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int>>::Purge(this: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)&sources);
        if ( sources.m_Memory.m_nGrowSize >= 0 && sources.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sources.m_Memory.m_pMemory);
        v15 = ++i;
        v24 = &pSourceTypes[v15];
      }
      while ( v24->m_pTypeName != nullptr );
    }
    this->m_pSourcesList->SortList(this: this->m_pSourcesList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004768A0
// Name: private: virtual void CAssetBuilder::OnRemoveSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnRemoveSource(CAssetBuilder *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  KeyValues *v6; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  CExpressionCalculator *v9; // edi
  CDmeMakefile *v10; // eax
  IDataModel_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  CDmeSource *BufferType; // [esp+0h] [ebp-20h]
  bool guard_4; // [esp+10h] [ebp-10h]
  int nCount; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int nRow; // [esp+1Ch] [ebp-4h]

  nCount = this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList);
  if ( nCount != 0 && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    if ( v2 == -1 )
    {
      nRow = -1;
      v3 = -1;
    }
    else
    {
      v3 = this->m_pSourcesList->GetItemCurrentRow(this: this->m_pSourcesList, a2: v2);
      nRow = v3;
    }
    guard_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v4 = 0;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v5 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: v4);
        v6 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v5);
        Int = KeyValues::GetInt(this: v6, keyName: "dmeSource", defaultValue: -1);
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeSource::m_classType) )
        {
          v10 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, CExpressionCalculator *))g_pDataModel->GetElement)(
                                  a1: g_pDataModel,
                                  a2: this->m_hMakefile.m_handle,
                                  a3: v9);
          CDmeMakefile::RemoveSource(this: v10, pSource: BufferType);
          v11 = g_pDataModel->__vftable;
          BufferType = (CDmeSource *)CCodecBuffer_Block::GetBufferType(this: v9);
          ((void (__thiscall *)(IDataModel *))v11->DestroyElement)(a1: g_pDataModel);
          this->SetDirty(this);
          v4 = i;
        }
        i = ++v4;
      }
      while ( v4 < nCount );
      v3 = nRow;
    }
    CAssetBuilder::RefreshSourceList(this, a2: (char *)v3, a3: (int)this);
    v12 = this->m_pSourcesList->GetItemCount(this: this->m_pSourcesList);
    if ( v12 != 0 && v3 >= 0 )
    {
      if ( v3 >= v12 )
        v3 = v12 - 1;
      v13 = this->m_pSourcesList->GetItemIDFromRow(this: this->m_pSourcesList, a2: v3);
      this->m_pSourcesList->SetSingleSelectedItem(this: this->m_pSourcesList, a2: v13);
    }
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476A70
// Name: private: void CAssetBuilder::OnSourceFileAdded(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceFileAdded(CAssetBuilder *this, const char *pFileName, const char *pTypeName)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDmeMakefile *v5; // eax
  char *v6; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v5 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
  v6 = (char *)CDmeMakefile::AddSource(this: v5, pSourceType: pTypeName, pFullPath: pFileName);
  CChangeUndoScopeGuard::Release(this: &guard);
  this->SetDirty(this);
  CAssetBuilder::RefreshSourceList(this, a2: v6, a3: (int)this);
  CAssetBuilder::SelectSource(this, pSource: (CDmeSource *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x00476B00
// Name: private: void CAssetBuilder::FinishCompilation(enum CompilationState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::FinishCompilation(CAssetBuilder *this, CompilationState_t state)
{
  int v3; // eax
  int v4; // edi
  CDmElement *v5; // eax
  int v6; // eax
  int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int v10; // eax
  CCompileStatusBar *m_pCompileStatusBar; // esi
  vgui::Label *m_pStatus; // ecx
  CCompileStatusBar *v13; // esi
  vgui::Label *v14; // ecx
  char pBuf[256]; // [esp+8h] [ebp-100h] BYREF

  CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  v3 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
  if ( v3 == -1 )
    v4 = -1;
  else
    v4 = this->m_pSourcesList->GetItemCurrentRow(this: this->m_pSourcesList, a2: v3);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
  CDmePanel::SetDmeElement(
    this: this->m_pOututPreviewPanel,
    pDmeElement: v5,
    bForce: true,
    pPanelName: "DmeMakeFileOutputPreview");
  *((_BYTE *)this + 492) &= ~1u;
  CAssetBuilder::RefreshSourceList(this, a2: (char *)v4, a3: (int)this);
  v6 = this->m_pSourcesList->GetItemCount(this: this->m_pSourcesList);
  if ( v6 != 0 && v4 >= 0 )
  {
    if ( v4 >= v6 )
      v4 = v6 - 1;
    v7 = this->m_pSourcesList->GetItemIDFromRow(this: this->m_pSourcesList, a2: v4);
    this->m_pSourcesList->SetSingleSelectedItem(this: this->m_pSourcesList, a2: v7);
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "UpdateFileName");
  else
    v9 = nullptr;
  this->PostActionSignal(this, a2: v9);
  if ( state == 2 )
  {
    v10 = g_pDmeMakefileUtils->GetExitCode(this: g_pDmeMakefileUtils);
    V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "Compilation Error (return code %d)", v10);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pStatus = m_pCompileStatusBar->m_pStatus;
    m_pCompileStatusBar->m_Status = COMPILATION_FAILED;
    m_pStatus->SetText_2(this: m_pStatus, a2: pBuf);
  }
  else
  {
    v13 = this->m_pCompileStatusBar;
    v14 = v13->m_pStatus;
    v13->m_Status = COMPILATION_SUCCESSFUL;
    v14->SetText_2(this: v14, a2: "Compile Successful!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476C80
// Name: public: virtual void CAssetBuilder::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnTick(CAssetBuilder *this)
{
  int v2; // edi
  void *v3; // esp
  CompilationState_t v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebx
  int v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-10h] BYREF
  CompilationState_t state; // [esp+Ch] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  if ( (*((_BYTE *)this + 492) & 1) == 0 )
    goto LABEL_7;
  v2 = g_pDmeMakefileUtils->GetCompileOutputSize(this: g_pDmeMakefileUtils);
  v3 = alloca(v2 + 1);
  v4 = g_pDmeMakefileUtils->UpdateCompilation(this: g_pDmeMakefileUtils, a2: v8, a3: v2);
  state = v4;
  if ( v2 > 0 )
  {
    this->m_pCompileOutput->InsertString_2(this: this->m_pCompileOutput, a2: v8);
    v4 = state;
  }
  if ( v4 != COMPILATION_NOT_COMPLETE )
    CAssetBuilder::FinishCompilation(this, state: v4);
  if ( (*((_BYTE *)this + 492) & 1) == 0 )
  {
LABEL_7:
    this->m_pAbortCompile->SetEnabled(this: this->m_pAbortCompile, a2: false);
    v5 = g_pVGui;
    v6 = g_pVGui->__vftable;
    v7 = this->GetVPanel(this);
    v6->RemoveTickSignal(this: v5, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476D60
// Name: private: void CAssetBuilder::RefreshOutputList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::RefreshOutputList(CAssetBuilder *this@<ecx>, int a2@<edi>)
{
  KeyValues *v3; // esi
  DmElementHandle_t m_handle; // eax
  int v5; // eax
  int v6; // edi
  KeyValues *v7; // eax
  const char *v8; // eax
  BOOL v9; // edi
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > outputs; // [esp+8h] [ebp-1Ch] BYREF
  int bEnabled; // [esp+1Ch] [ebp-8h]
  unsigned int v13; // [esp+20h] [ebp-4h]

  this->m_pOutputList->RemoveAll(this: this->m_pOutputList);
  v3 = nullptr;
  this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: false);
  this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: false);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    m_handle = this->m_hMakefile.m_handle;
    memset(&outputs, 0, sizeof(outputs));
    v5 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
           a1: g_pDataModel,
           a2: m_handle,
           a3: a2);
    (*(void (__thiscall **)(int, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))(*(_DWORD *)v5 + 64))(
      a1: v5,
      a2: &outputs);
    v6 = 0;
    bEnabled = outputs.m_Size;
    if ( outputs.m_Size <= 0 )
      goto LABEL_11;
    v13 = 0;
    while ( 1 )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v3 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "type", firstValue: "Output");
      v8 = CUtlString::operator char const *(this: &outputs.m_Memory.m_pMemory[v13 / 0x10]);
      KeyValues::SetString(this: v3, keyName: "file", value: v8);
      KeyValues::SetInt(this: v3, keyName: "index", value: v6);
      this->m_pOutputList->AddItem(this: this->m_pOutputList, a2: v3, a3: 0, a4: false, a5: false);
      v13 += 16;
      if ( ++v6 >= bEnabled )
        break;
      v3 = nullptr;
    }
    if ( bEnabled > 0 && g_pDmeMakefileUtils != nullptr )
      LOBYTE(bEnabled) = 1;
    else
LABEL_11:
      LOBYTE(bEnabled) = 0;
    v9 = bEnabled;
    this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: bEnabled);
    this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: v9);
    this->m_pOutputList->SortList(this: this->m_pOutputList);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &outputs);
    m_pMemory = outputs.m_Memory.m_pMemory;
    if ( outputs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( outputs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        outputs.m_Memory.m_pMemory = nullptr;
      }
      outputs.m_Memory.m_nAllocationCount = 0;
    }
    outputs.m_pElements = m_pMemory;
    if ( outputs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476F20
// Name: private: virtual void CAssetBuilder::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnPicked(CAssetBuilder *this, KeyValues *kv)
{
  const char *String; // edi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmeMakefile *v7; // esi
  const char **v8; // ebx
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::FileOpenDialog *v11; // eax
  vgui::FileOpenDialog *v12; // edi
  IDataModel_vtbl *v13; // edi
  int BufferType; // eax
  char pContext[260]; // [esp+Ch] [ebp-214h] BYREF
  char pStartingDir[260]; // [esp+110h] [ebp-110h] BYREF
  vgui::Panel *parent; // [esp+214h] [ebp-Ch]
  CDisableUndoScopeGuard guard; // [esp+218h] [ebp-8h] BYREF

  parent = this;
  String = KeyValues::GetString(this: kv, keyName: "choice", defaultValue: defaultValue);
  if ( KeyValues::FindKey(this: kv, keyName: "OnAddSource", bCreate: false) != nullptr )
  {
    CAssetBuilder::OnSourceFileAdded(this, pFileName: defaultValue, pTypeName: String);
  }
  else
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v5 = g_pDataModel->CreateElement(this: g_pDataModel, a2: String, a3: "unnamed", a4: DMFILEID_INVALID, a5: nullptr);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
    v7 = (CDmeMakefile *)v6;
    if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeMakefile::m_classType) )
    {
      v8 = (const char **)v7->GetMakefileType(this: v7);
      V_snprintf(pDest: pContext, maxLen: 260, pFormat: "asset_builder_session_%s", *v8);
      CDmeMakefile::GetDefaultDirectory(this: v7, pDefaultDirectoryID: v8[3], pFullPath: pStartingDir, nBufLen: 260);
      g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(
                this: v9,
                setName: "NewSourceFileSelected",
                firstKey: "makefileType",
                firstValue: String);
      else
        v10 = nullptr;
      v11 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
      if ( v11 != nullptr )
        v12 = vgui::FileOpenDialog::FileOpenDialog(
                this: v11,
                parent,
                title: "Select Asset Builder File Name",
                bOpenOnly: false,
                pContextKeyValues: v10);
      else
        v12 = nullptr;
      vgui::FileOpenDialog::SetStartDirectoryContext(this: v12, pStartDirContext: pContext, pDefaultDir: pStartingDir);
      vgui::FileOpenDialog::AddFilter(this: v12, filter: v8[4], filterName: v8[5], bActive: true, pFilterInfo: nullptr);
      v12->AddActionSignalTarget_2(this: v12, a2: parent);
      vgui::FileOpenDialog::DoModal(this: v12, bUnused: false);
      v13 = g_pDataModel->__vftable;
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
      v13->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477100
// Name: public: void CAssetBuilder::SetCurrentMakefile(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SetCurrentMakefile(CAssetBuilder *this, CExpressionCalculator *pMakeFile)
{
  DmElementHandle_t BufferType; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( pMakeFile != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pMakeFile);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hMakefile, h: BufferType);
  CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  CDmePanel::SetDmeElement(
    this: this->m_pOututPreviewPanel,
    pDmeElement: (CDmElement *)pMakeFile,
    bForce: true,
    pPanelName: "DmeMakeFileOutputPreview");
  CAssetBuilder::RefreshSourceList(this, a2: (char *)pMakeFile, a3: (int)this);
  CAssetBuilder::RefreshOutputList(this, a2: (int)pMakeFile);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "UpdateFileName");
    this->PostActionSignal(this, a2: v5);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004771A0
// Name: private: virtual void CAssetBuilder::OnZoomInSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnZoomInSource(CAssetBuilder *this)
{
  CDmeSource *SelectedSource; // esi
  CDmeMakefile *v3; // eax
  CExpressionCalculator *DependentMakefile; // eax
  CExpressionCalculator *v5; // edi
  DmElementHandle_t BufferType; // esi
  CDmElement *v7; // eax
  CDmeHandle<CDmeMakefile,0> *m_pMemory; // eax
  CDmeHandle<CDmeMakefile,0> *v9; // ecx
  CDmeHandle<CDmeMakefile,0> hChild; // [esp+Ch] [ebp-4h] BYREF

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
  {
    v3 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    DependentMakefile = (CExpressionCalculator *)CDmeMakefile::FindDependentMakefile(this: v3, pSource: SelectedSource);
    v5 = DependentMakefile;
    if ( DependentMakefile != nullptr )
    {
      hChild.m_handle = DMELEMENT_HANDLE_INVALID;
      BufferType = CCodecBuffer_Block::GetBufferType(this: DependentMakefile);
      if ( BufferType != DMELEMENT_HANDLE_INVALID )
      {
        CDmeElementRefHelper::Unref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
        hChild.m_handle = BufferType;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
        if ( v7 != nullptr && !v7->IsA(this: v7, a2: CDmeMakefile::m_classType) )
          hChild.m_handle = DMELEMENT_HANDLE_INVALID;
        CDmeElementRefHelper::Ref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
      }
      if ( this->m_hMakefileStack.m_Size >= this->m_hMakefileStack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hMakefileStack,
          num: 1);
      ++this->m_hMakefileStack.m_Size;
      m_pMemory = this->m_hMakefileStack.m_Memory.m_pMemory;
      v9 = &m_pMemory[this->m_hMakefileStack.m_Size - 1];
      this->m_hMakefileStack.m_pElements = m_pMemory;
      if ( v9 != nullptr )
      {
        v9->m_handle = DMELEMENT_HANDLE_INVALID;
        CDmeHandle<CDmeMakefile,0>::Set(this: v9, h: hChild.m_handle);
      }
      CAssetBuilder::SetCurrentMakefile(this, pMakeFile: v5);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004772C0
// Name: private: virtual void CAssetBuilder::OnZoomOutSource(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::OnZoomOutSource(CAssetBuilder *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CDmeMakefile *v4; // ebx
  CDmeElementRefHelper *v5; // ecx
  CExpressionCalculator *v6; // eax
  CDmeMakefile *v7; // edi
  CDmeSource *AssociatedSource; // eax

  if ( this->m_hMakefileStack.m_Size > 1 )
  {
    v4 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
                           a1: g_pDataModel,
                           a2: this->m_hMakefileStack.m_Memory.m_pMemory[this->m_hMakefileStack.m_Size - 1].m_handle,
                           a3: a2);
    if ( g_pDataModel != nullptr )
    {
      v5 = &this->m_hMakefileStack.m_Memory.m_pMemory[this->m_hMakefileStack.m_Size - 1];
      CDmeElementRefHelper::Unref(this: v5, hElement: *(_DWORD *)v5, handleType: HT_WEAK);
    }
    v6 = (CExpressionCalculator *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
                                    a1: g_pDataModel,
                                    a2: this->m_hMakefileStack.m_Memory.m_pMemory[--this->m_hMakefileStack.m_Size - 1].m_handle,
                                    a3);
    v7 = (CDmeMakefile *)v6;
    if ( v6 != nullptr )
    {
      CAssetBuilder::SetCurrentMakefile(this, pMakeFile: v6);
      AssociatedSource = CDmeMakefile::FindAssociatedSource(this: v7, pChildMakefile: v4);
      if ( AssociatedSource != nullptr )
        CAssetBuilder::SelectSource(this, pSource: AssociatedSource);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477370
// Name: public: void CAssetBuilder::SetRootMakefile(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SetRootMakefile(CAssetBuilder *this, CExpressionCalculator *pMakeFile)
{
  DmElementHandle_t BufferType; // eax
  CDmeHandle<CDmeMakefile,0> *m_pMemory; // eax
  CDmeHandle<CDmeMakefile,0> *v5; // ecx

  CAssetBuilder::CleanupMakefile(this);
  if ( pMakeFile != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: pMakeFile);
    CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: BufferType);
    if ( this->m_hMakefileStack.m_Size >= this->m_hMakefileStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hMakefileStack,
        num: 1);
    ++this->m_hMakefileStack.m_Size;
    m_pMemory = this->m_hMakefileStack.m_Memory.m_pMemory;
    v5 = &m_pMemory[this->m_hMakefileStack.m_Size - 1];
    this->m_hMakefileStack.m_pElements = m_pMemory;
    if ( v5 != nullptr )
    {
      v5->m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmeMakefile,0>::Set(this: v5, h: this->m_hRootMakefile.m_handle);
    }
  }
  CAssetBuilder::SetCurrentMakefile(this, pMakeFile);
}

//------------------------------------------------------------------------------
// Address: 0x00477400
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CAssetBuilder,class CDmeMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetBuilder *__thiscall CDmePanelFactory<CAssetBuilder,CDmeMakefile>::CreateDmePanel(
        CDmePanelFactory<CAssetBuilder,CDmeMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CExpressionCalculator *v4; // esi
  CAssetBuilder *v5; // eax
  CAssetBuilder *v6; // edi

  v4 = (CExpressionCalculator *)pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CAssetBuilder *)MemAlloc_Alloc(nSize: 0x1F0u);
  if ( v5 != nullptr )
  {
    v6 = CAssetBuilder::CAssetBuilder(this: v5, pParent, pPanelName);
    CAssetBuilder::SetRootMakefile(this: v6, pMakeFile: v4);
    return v6;
  }
  else
  {
    CAssetBuilder::SetRootMakefile(this: nullptr, pMakeFile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477470
// Name: public: virtual void CDmePanelFactory<class CAssetBuilder,class CDmeMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CAssetBuilder,CDmeMakefile>::SetDmeElement(
        CDmePanelFactory<CAssetBuilder,CDmeMakefile> *this,
        CAssetBuilder *pPanel,
        CDmElement *pElement)
{
  CAssetBuilder::SetRootMakefile(this: pPanel, pMakeFile: (CExpressionCalculator *)pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00478020
// Name: public: virtual void CDmePanelFactory<class CDmeSourceDCCFilePanel,class CDmeSourceDCCFile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::SetDmeElement(
        CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile> *this,
        CDmeSourceDCCFilePanel *pPanel,
        CDmeSourceDCCFile *pElement)
{
  CDmeSourceDCCFilePanel::SetDmeElement(this: pPanel, pSourceDCCFile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x004786F0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeSourceDCCFilePanel,class CDmeSourceDCCFile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceDCCFilePanel *__thiscall CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::CreateDmePanel(
        CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceDCCFile *pElement)
{
  CDmeSourceDCCFile *v4; // esi
  CDmeSourceDCCFilePanel *v5; // eax
  CDmeSourceDCCFilePanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceDCCFile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeSourceDCCFilePanel *)MemAlloc_Alloc(nSize: 0x1A0u);
  if ( v5 != nullptr )
  {
    v6 = CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(this: v5, pParent, pPanelName);
    CDmeSourceDCCFilePanel::SetDmeElement(this: v6, pSourceDCCFile: v4);
    return v6;
  }
  else
  {
    CDmeSourceDCCFilePanel::SetDmeElement(this: nullptr, pSourceDCCFile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479F30
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDag>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDag> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeDag *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pScene: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0047B560
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDag>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDag> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDag *pElement)
{
  CDmeDag *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pScene: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pScene: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B5D0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pSkin: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pSkin: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B640
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pSkin: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0047B920
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceAnimation>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceAnimation *pElement)
{
  CDmeSourceAnimation *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceAnimation::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pAnimation: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pAnimation: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B990
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceAnimation>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeSourceAnimation *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pAnimation: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0047B9B0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDCCMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDCCMakefile *pElement)
{
  CDmeDCCMakefile *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDCCMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pDCCMakefile: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pDCCMakefile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BA20
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDCCMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeDCCMakefile *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pDCCMakefile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0047BD30
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeDag>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDag> *this,
        vgui::EditablePanel *pPanel,
        CDmElement *pElement)
{
  ((void (__thiscall *)(vgui::EditablePanel *, CDmElement *))pPanel->__vftable[1].GetVPanel)(a1: pPanel, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0047E7C0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeDag>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDag> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CDmElement *v4; // esi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  v6->SetDmeElement(this: v6, a2: (CDmeDag *)v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0047EE10
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // edi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // esi
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = pElement;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  CDmeDagRenderPanel::SetDmeElement(this: v6->m_pDagRenderPanel, pSkin: v4);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: v4);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: v6, pRoot: OutputElement);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0047EEA0
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin> *this,
        CDmeDagEditPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  CDmeDagRenderPanel::SetDmeElement(this: pPanel->m_pDagRenderPanel, pSkin: pElement);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: pElement);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: pPanel, pRoot: OutputElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EEE0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceAnimation>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceAnimation *pElement)
{
  CDmeSourceAnimation *v4; // edi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // esi
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSourceAnimation::m_classType.u.m_Id) )
  {
    v4 = pElement;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  CDmeDagRenderPanel::SetDmeElement(this: v6->m_pDagRenderPanel, pAnimation: v4);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: v4);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: v6, pRoot: OutputElement);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0047EF70
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceAnimation>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation> *this,
        CDmeDagEditPanel *pPanel,
        CDmeSourceAnimation *pElement)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  CDmeDagRenderPanel::SetDmeElement(this: pPanel->m_pDagRenderPanel, pAnimation: pElement);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: pElement);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: pPanel, pRoot: OutputElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EFB0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeDCCMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDCCMakefile *pElement)
{
  CDmeDCCMakefile *v4; // esi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDCCMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagEditPanel::SetDmeElement(this: v6, pDCCMakefile: v4);
    return v6;
  }
  else
  {
    CDmeDagEditPanel::SetDmeElement(this: nullptr, pDCCMakefile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F020
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeDCCMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile> *this,
        CDmeDagEditPanel *pPanel,
        CDmeDCCMakefile *pElement)
{
  CDmeDagEditPanel::SetDmeElement(this: pPanel, pDCCMakefile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0047F1B0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeMDLPanel,class CDmeMDLMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMDLPanel *__thiscall CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeMakefile *pElement)
{
  CDmeMakefile *v4; // esi
  CDmeMDLPanel *v5; // eax
  CDmeMDLPanel *v6; // edi
  CDmElement *OutputElement; // eax
  CDmeMDL *v8; // esi
  CDmeMDLPanel_vtbl *v9; // ebx
  unsigned __int16 MDL; // ax

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeMDLMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeMDLPanel *)MemAlloc_Alloc(nSize: 0xBE8u);
  if ( v5 != nullptr )
    v6 = CDmeMDLPanel::CDmeMDLPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  if ( v4 != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: v4, bCreateIfNecessary: true);
    v8 = (CDmeMDL *)OutputElement;
    if ( OutputElement != nullptr && OutputElement->IsA(this: OutputElement, a2: CDmeMDL::m_classType) )
    {
      v9 = v6->__vftable;
      MDL = CDmeMDL::GetMDL(this: v8);
      v9->SetMDL_2(this: v6, a2: MDL, a3: nullptr);
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0047F250
// Name: public: virtual void CDmePanelFactory<class CDmeMDLPanel,class CDmeMDLMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile> *this,
        vgui::EditablePanel *pPanel,
        CDmeMakefile *pElement)
{
  CDmElement *OutputElement; // eax
  CDmeMDL *v4; // esi
  vgui::EditablePanel_vtbl *v5; // edi
  unsigned __int16 MDL; // ax

  if ( pElement != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: pElement, bCreateIfNecessary: true);
    v4 = (CDmeMDL *)OutputElement;
    if ( OutputElement != nullptr && OutputElement->IsA(this: OutputElement, a2: CDmeMDL::m_classType) )
    {
      v5 = pPanel->__vftable;
      MDL = CDmeMDL::GetMDL(this: v4);
      ((void (__thiscall *)(vgui::EditablePanel *, _DWORD, _DWORD))v5[1].Repaint)(a1: pPanel, a2: MDL, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062B370
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
  v2 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
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
// Address: 0x0062BDA0
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
// Address: 0x0062BDD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x0062BDE0
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

//------------------------------------------------------------------------------
// Address: 0x00474190
// Name: class CDmeSource __near * GetElementKeyValue<class CDmeSource>(class KeyValues __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *__cdecl GetElementKeyValue<CDmeSource>(KeyValues *pKeyValues, const char *pName)
{
  DmElementHandle_t Int; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: pName, defaultValue: -1);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v4;
  else
    return nullptr;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10462830
// Name: public: virtual void CDmePanelFactory<class CParticleSystemPreviewPanel,class CDmeParticleSystemDefinition>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CParticleSystemPreviewPanel,CDmeParticleSystemDefinition>::SetDmeElement(
        CDmePanelFactory<CParticleSystemPreviewPanel,CDmeParticleSystemDefinition> *this,
        vgui::EditablePanel *pPanel,
        CDmeParticleSystemDefinition *pElement)
{
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&pPanel[1].m_clrDropFrame + 1024))(a1: *(_DWORD *)&pPanel[1].m_clrDropFrame) == 0 )
    CParticleSystemPanel::SetParticleSystem(
      this: *(CParticleSystemPanel **)&pPanel[1].m_OnDelete_register,
      pDef: pElement);
  pPanel[1].m_infoFont = (unsigned int)pElement;
}

//------------------------------------------------------------------------------
// Address: 0x104635C0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CParticleSystemPreviewPanel,class CDmeParticleSystemDefinition>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSystemPreviewPanel *__thiscall CDmePanelFactory<CParticleSystemPreviewPanel,CDmeParticleSystemDefinition>::CreateDmePanel(
        CDmePanelFactory<CParticleSystemPreviewPanel,CDmeParticleSystemDefinition> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeParticleSystemDefinition *pElement)
{
  CDmeParticleSystemDefinition *v4; // edi
  CParticleSystemPreviewPanel *v5; // eax
  CParticleSystemPreviewPanel *v6; // esi

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeParticleSystemDefinition::m_classType.u.m_Id) )
  {
    v4 = pElement;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CParticleSystemPreviewPanel *)operator new(nSize: 0x1C0u);
  if ( v5 != nullptr )
    v6 = CParticleSystemPreviewPanel::CParticleSystemPreviewPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  if ( !v6->m_pLockPreview->IsSelected(this: v6->m_pLockPreview) )
    CParticleSystemPanel::SetParticleSystem(this: v6->m_pParticleSystemPanel, pDef: v4);
  v6->m_pUnlockSystem = v4;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x104667E0
// Name: public: virtual void CDmePanelFactory<class CDmeElementPanel,class CDmElement>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeElementPanel,CDmElement>::SetDmeElement(
        CDmePanelFactory<CDmeElementPanel,CDmElement> *this,
        vgui::EditablePanel *pPanel,
        KeyValues *pElement)
{
  pPanel->__vftable[1].RequestInfo(this: pPanel, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x104782C0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeElementPanel,class CDmElement>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeElementPanel *__thiscall CDmePanelFactory<CDmeElementPanel,CDmElement>::CreateDmePanel(
        CDmePanelFactory<CDmeElementPanel,CDmElement> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CDmElement *v4; // esi
  CDmeElementPanel *v5; // eax
  CDmeElementPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeElementPanel *)operator new(nSize: 0x2C4u);
  if ( v5 != nullptr )
    v6 = CDmeElementPanel::CDmeElementPanel(this: v5, pParent, pPanelName);
  else
    v6 = nullptr;
  v6->SetObject(this: v6, a2: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x104791F0
// Name: public: virtual void CDmePanelFactory<class CDmeSourceSkinPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin> *this,
        CDmeSourceSkinPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkinPanel::SetDmeElement(this: pPanel, pSourceSkin: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x104794D0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeSourceSkinPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceSkinPanel *__thiscall CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // esi
  CDmeSourceSkinPanel *v5; // eax
  CDmeSourceSkinPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeSourceSkinPanel *)operator new(nSize: 0x194u);
  if ( v5 != nullptr )
  {
    v6 = CDmeSourceSkinPanel::CDmeSourceSkinPanel(this: v5, pParent, pPanelName);
    CDmeSourceSkinPanel::SetDmeElement(this: v6, pSourceSkin: v4);
    return v6;
  }
  else
  {
    CDmeSourceSkinPanel::SetDmeElement(this: nullptr, pSourceSkin: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479540
// Name: public: static char const __near * CAssetBuilder::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetBuilder::GetPanelClassName()
{
  return "CAssetBuilder";
}

//------------------------------------------------------------------------------
// Address: 0x10479550
// Name: public: static char const __near * CCompileStatusBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCompileStatusBar::GetPanelClassName()
{
  return "CCompileStatusBar";
}

//------------------------------------------------------------------------------
// Address: 0x10479560
// Name: public: virtual void CCompileStatusBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCompileStatusBar::PaintBackground(CCompileStatusBar *this)
{
  int v2; // [esp+0h] [ebp-50h]
  FontVertex_t verts[4]; // [esp+4h] [ebp-4Ch] BYREF
  float du; // [esp+44h] [ebp-Ch]
  int h; // [esp+48h] [ebp-8h] BYREF
  int w; // [esp+4Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  switch ( this->m_Status )
  {
    case CURRENTLY_COMPILING:
      du = _Plat_FloatTime(
             a1: v2,
             a2: LODWORD(verts[0].m_Position.x),
             a3: LODWORD(verts[0].m_Position.y),
             a4: LODWORD(verts[0].m_TexCoord.x),
             a5: LODWORD(verts[0].m_TexCoord.y))
         * 0.2;
      verts[0].m_Position.x = 0.0;
      verts[0].m_Position.y = 0.0;
      verts[0].m_TexCoord.x = 1.0 - (float)(du - (float)(int)du);
      verts[0].m_TexCoord.y = 0.0;
      verts[1].m_Position.x = (float)w;
      verts[1].m_Position.y = 0.0;
      verts[1].m_TexCoord.x = verts[0].m_TexCoord.x + 1.0;
      verts[1].m_TexCoord.y = 0.0;
      verts[2].m_Position.x = (float)w;
      verts[2].m_Position.y = (float)h;
      verts[2].m_TexCoord.x = verts[0].m_TexCoord.x + 1.0;
      verts[2].m_TexCoord.y = 1.0;
      verts[3].m_Position.x = 0.0;
      verts[3].m_Position.y = (float)h;
      verts[3].m_TexCoord.x = verts[0].m_TexCoord.x;
      verts[3].m_TexCoord.y = 1.0;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_CompilingId);
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      break;
    case COMPILATION_FAILED:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
      break;
    case COMPILATION_SUCCESSFUL:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 255, a4: 0, a5: 255);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104796F0
// Name: TypeSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl TypeSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  char *String; // ebx
  char *v4; // eax
  int result; // eax
  char *v6; // ebx
  char *v7; // eax
  int Int; // esi

  String = KeyValues::GetString(this: item1->kv, keyName: "type", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "type", defaultValue: &var);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "file", defaultValue: &var);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "file", defaultValue: &var);
    result = _V_stricmp(s1: v6, s2: v7);
    if ( result == 0 )
    {
      Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
      return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10479790
// Name: FileSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  char *String; // ebx
  char *v4; // eax
  int result; // eax
  char *v6; // ebx
  char *v7; // eax
  int Int; // esi

  String = KeyValues::GetString(this: item1->kv, keyName: "file", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "file", defaultValue: &var);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "type", defaultValue: &var);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "type", defaultValue: &var);
    result = _V_stricmp(s1: v6, s2: v7);
    if ( result == 0 )
    {
      Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
      return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10479830
// Name: public: virtual void CAssetBuilder::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnKeyCodeTyped(CAssetBuilder *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE )
  {
    this->OnRemoveSource(this);
  }
  else if ( code == KEY_ENTER )
  {
    this->OnZoomInSource(this);
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479870
// Name: private: void CAssetBuilder::OnAbortCompile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnAbortCompile(CAssetBuilder *this)
{
  vgui::Button *m_pAbortCompile; // ecx
  CCompileStatusBar *m_pCompileStatusBar; // esi
  vgui::Label *m_pStatus; // ecx

  if ( (*((_BYTE *)this + 492) & 1) != 0 )
  {
    g_pDmeMakefileUtils->AbortCurrentCompilation(this: g_pDmeMakefileUtils);
    m_pAbortCompile = this->m_pAbortCompile;
    *((_BYTE *)this + 492) &= ~1u;
    m_pAbortCompile->SetEnabled(this: m_pAbortCompile, a2: false);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pStatus = m_pCompileStatusBar->m_pStatus;
    m_pCompileStatusBar->m_Status = COMPILATION_FAILED;
    m_pStatus->SetText(this: m_pStatus, a2: "Compile Aborted");
  }
}

//------------------------------------------------------------------------------
// Address: 0x104799D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CCompileStatusBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCompileStatusBar::GetMessageMap(CCompileStatusBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCompileStatusBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCompileStatusBar::GetMessageMap'::`2'::s_pMap;
  `CCompileStatusBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCompileStatusBar");
  `CCompileStatusBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10479A00
// Name: public: virtual struct PanelAnimationMap __near * CCompileStatusBar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCompileStatusBar::GetAnimMap(CCompileStatusBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CCompileStatusBar");
}

//------------------------------------------------------------------------------
// Address: 0x10479A10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCompileStatusBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCompileStatusBar::GetKBMap(CCompileStatusBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCompileStatusBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCompileStatusBar::GetKBMap'::`2'::s_pMap;
  `CCompileStatusBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCompileStatusBar");
  `CCompileStatusBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10479A40
// Name: public: CCompileStatusBar::CCompileStatusBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCompileStatusBar *__thiscall CCompileStatusBar::CCompileStatusBar(
        CCompileStatusBar *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *m_pStatus; // ecx
  int v10; // eax

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CCompileStatusBar_vtbl *)&CCompileStatusBar::`vftable';
  if ( `CCompileStatusBar::ChainToMap'::`2'::chained == 0 )
  {
    `CCompileStatusBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CCompileStatusBar");
    v4->pfnClassName = CCompileStatusBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CCompileStatusBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCompileStatusBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CCompileStatusBar");
    v5->pfnClassName = CCompileStatusBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CCompileStatusBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCompileStatusBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CCompileStatusBar");
    v6->pfnClassName = CCompileStatusBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "StatusLabel", text: &var);
  else
    v8 = nullptr;
  this->m_pStatus = v8;
  vgui::Panel::SetAutoResize(
    this: v8,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  this->m_pStatus->SetContentAlignment(this: this->m_pStatus, a2: a_center);
  this->m_pStatus->SetTextColorState(this: this->m_pStatus, a2: CS_BRIGHT);
  m_pStatus = this->m_pStatus;
  this->m_Status = NOT_COMPILING;
  m_pStatus->SetText(this: m_pStatus, a2: &var);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v10 = g_pVGuiSurface->DrawGetTextureId(this: g_pVGuiSurface, a2: "vgui/progressbar");
  this->m_CompilingId = v10;
  if ( v10 == -1 )
    this->m_CompilingId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  g_pVGuiSurface->DrawSetTextureFile(
    this: g_pVGuiSurface,
    a2: this->m_CompilingId,
    a3: "vgui/progressbar",
    a4: 1,
    a5: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10479C20
// Name: private: void CAssetBuilder::ShowSourceFileBrowser(char const __near *,struct DmeMakefileType_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::ShowSourceFileBrowser(
        CAssetBuilder *this,
        const char *pTitle,
        DmeMakefileType_t *pSourceType,
        KeyValues *pDialogKeys)
{
  CDmeMakefile *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // esi
  char pContext[260]; // [esp+Ch] [ebp-208h] BYREF
  char pStartingDir[260]; // [esp+110h] [ebp-104h] BYREF

  V_snprintf(pDest: pContext, maxLen: 0x104u, pFormat: "asset_builder_session_%s", pSourceType->m_pTypeName);
  v5 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
  CDmeMakefile::GetDefaultDirectory(
    this: v5,
    pDefaultDirectoryID: pSourceType->m_pDefaultDirectoryID,
    pFullPath: pStartingDir,
    nBufLen: 260);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
  v6 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v6 != nullptr )
    v7 = vgui::FileOpenDialog::FileOpenDialog(
           this: v6,
           parent: this,
           title: pTitle,
           bOpenOnly: true,
           pContextKeyValues: pDialogKeys);
  else
    v7 = nullptr;
  vgui::FileOpenDialog::SetStartDirectoryContext(this: v7, pStartDirContext: pContext, pDefaultDir: pStartingDir);
  vgui::FileOpenDialog::AddFilter(
    this: v7,
    filter: (char *)pSourceType->m_pFileFilter,
    filterName: pSourceType->m_pFileFilterString,
    bActive: true,
    pFilterInfo: nullptr);
  v7->AddActionSignalTarget_2(this: v7, a2: this);
  vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x10479D00
// Name: private: class KeyValues __near * CAssetBuilder::GetSelectedSourceKeyvalues(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CAssetBuilder::GetSelectedSourceKeyvalues(CAssetBuilder *this)
{
  int v2; // eax

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) != 1
    || g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) == nullptr )
  {
    return nullptr;
  }
  v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
  return this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10479D60
// Name: private: void CAssetBuilder::OnCompile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnCompile(CAssetBuilder *this)
{
  CDmElement *v2; // eax
  vgui::Button *m_pAbortCompile; // ecx
  CCompileStatusBar *m_pCompileStatusBar; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebx
  int v7; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    CAssetBuilder::OnAbortCompile(this);
    this->m_pCompileOutput->SetText(this: this->m_pCompileOutput, a2: &var);
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    g_pDmeMakefileUtils->PerformCompile(this: g_pDmeMakefileUtils, a2: v2, a3: false);
    m_pAbortCompile = this->m_pAbortCompile;
    *((_BYTE *)this + 492) |= 1u;
    m_pAbortCompile->SetEnabled(this: m_pAbortCompile, a2: true);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pCompileStatusBar->m_Status = CURRENTLY_COMPILING;
    m_pCompileStatusBar->m_pStatus->SetText(this: m_pCompileStatusBar->m_pStatus, a2: "Compiling...");
    v5 = g_pVGui;
    v6 = g_pVGui->__vftable;
    v7 = ((int (__thiscall *)(CAssetBuilder *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v6->AddTickSignal)(a1: v5, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479E20
// Name: private: virtual void CAssetBuilder::OnBrowseSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnBrowseSourceFile(CAssetBuilder *this)
{
  KeyValues *SelectedSourceKeyvalues; // eax
  int Int; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  CDmElement *v6; // eax
  int v7; // eax

  SelectedSourceKeyvalues = CAssetBuilder::GetSelectedSourceKeyvalues(this);
  if ( SelectedSourceKeyvalues != nullptr )
  {
    Int = KeyValues::GetInt(this: SelectedSourceKeyvalues, keyName: "sourceTypeIndex", defaultValue: -1);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "SelectSourceFile");
    else
      v5 = nullptr;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    v7 = ((int (__thiscall *)(CDmElement *))v6->__vftable[1].OnAttributeArrayElementAdded)(a1: v6);
    CAssetBuilder::ShowSourceFileBrowser(
      this,
      pTitle: "Select Source File",
      pSourceType: (DmeMakefileType_t *)(v7 + 24 * Int),
      pDialogKeys: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479EA0
// Name: public: virtual void CAssetBuilder::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnCommand(CAssetBuilder *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnCompile") == 0 )
    goto LABEL_2;
  if ( _V_stricmp(s1: pCommand, s2: "OnAbortCompile") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnPublish") == 0 )
    {
LABEL_2:
      CAssetBuilder::OnCompile(this);
      return;
    }
    vgui::Panel::OnCommand(this, command: pCommand);
  }
  else
  {
    CAssetBuilder::OnAbortCompile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479F70
// Name: private: void CAssetBuilder::SelectSource(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SelectSource(CAssetBuilder *this, CDmeSource *pSource)
{
  int v3; // edi
  KeyValues *v4; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v6; // eax
  CDmeSource *v7; // esi
  vgui::ListPanel_vtbl *v8; // edx

  v3 = this->m_pSourcesList->FirstItem(this: this->m_pSourcesList);
  if ( v3 != this->m_pSourcesList->InvalidItemID(this: this->m_pSourcesList) )
  {
    while ( 1 )
    {
      v4 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v3);
      Int = KeyValues::GetInt(this: v4, keyName: "dmeSource", defaultValue: -1);
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
      v7 = (CDmeSource *)v6;
      if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeSource::m_classType) )
        v7 = nullptr;
      v8 = this->m_pSourcesList->__vftable;
      if ( v7 == pSource )
        break;
      v3 = ((int (__stdcall *)(int))v8->NextItem)(a1: v3);
      if ( v3 == this->m_pSourcesList->InvalidItemID(this: this->m_pSourcesList) )
        return;
    }
    ((void (__stdcall *)(int))v8->SetSingleSelectedItem)(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047A040
// Name: private: void CAssetBuilder::OnNewSourceFileSelected(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnNewSourceFileSelected(CAssetBuilder *this, char *pFileName, KeyValues *kv)
{
  int v4; // eax
  vgui::ListPanel *m_pSourcesList; // ecx
  vgui::ListPanel_vtbl *v6; // edx
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  const char *v9; // ebx
  CDmeMakefile *v10; // eax
  DmFileId_t v11; // eax
  CDmeMakefile *v12; // eax
  CDmeSource *m_handle; // [esp-Ch] [ebp-28h]
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  int nItemID; // [esp+14h] [ebp-8h]
  KeyValues *pKeyValues; // [esp+18h] [ebp-4h]
  char *pSourceMakeFile; // [esp+28h] [ebp+Ch]
  CDmeMakefile *pSourceMakeFilea; // [esp+28h] [ebp+Ch]

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v4 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    m_pSourcesList = this->m_pSourcesList;
    v6 = m_pSourcesList->__vftable;
    nItemID = v4;
    pKeyValues = v6->GetItem(this: m_pSourcesList, a2: v4);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dmeSource", defaultValue: -1);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v9 = (const char *)v8;
    if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeSource::m_classType) )
    {
      pSourceMakeFile = KeyValues::GetString(this: kv, keyName: "makefileType", defaultValue: &var);
      CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
      m_handle = (CDmeSource *)this->m_hMakefile.m_handle;
      v10 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
      CDmeMakefile::SetSourceFullPath(this: v10, pSource: m_handle, pFullPath: v9);
      v11 = ((int (__thiscall *)(IDataModel *))g_pDataModel->FindOrCreateFileId)(a1: g_pDataModel);
      pSourceMakeFilea = CreateElement<CDmeMakefile>(
                           pElementType: pSourceMakeFile,
                           pObjectName: pFileName,
                           fileid: v11,
                           pObjectID: nullptr);
      CDmeMakefile::SetFileName(this: pSourceMakeFilea, pFileName);
      v12 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, const char *, CDmeMakefile *))g_pDataModel->GetElement)(
                              a1: g_pDataModel,
                              a2: this->m_hMakefile.m_handle,
                              a3: v9,
                              a4: pSourceMakeFilea);
      CDmeMakefile::SetAssociation(
        this: v12,
        pSource: (CDmeSource *)pFileName,
        pSourceMakefile: (CDmeMakefile *)pFileName);
      this->SetDirty(this);
      CChangeUndoScopeGuard::Release(this: &guard);
      KeyValues::SetString(this: pKeyValues, keyName: "file", value: pFileName);
      this->m_pSourcesList->ApplyItemChanges(this: this->m_pSourcesList, a2: nItemID);
      this->m_pSourcesList->SortList(this: this->m_pSourcesList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047A1D0
// Name: private: virtual void CAssetBuilder::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAssetBuilder::OnOpenContextMenu(CAssetBuilder *this@<ecx>, int a2@<ebx>, int a3@<edi>, KeyValues *kv)
{
  vgui::Panel *v5; // eax
  vgui::Menu *v7; // eax
  CDragDropHelperPanel *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // ebx
  vgui::Panel *v14; // eax
  KeyValues *v15; // eax
  CDmeSource *ElementKey; // eax
  CDmeSource *v17; // ebx
  const char *m_pAsString; // eax
  CDmeMakefile *v19; // eax
  vgui::Panel *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // ebx
  vgui::Panel *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // ebx
  vgui::Panel *v26; // eax
  vgui::Panel *v27; // eax
  KeyValues *v28; // eax
  KeyValues *v29; // ebx
  vgui::Panel *v30; // eax
  KeyValues *v31; // eax
  KeyValues *v32; // ebx
  vgui::Panel *v33; // eax
  KeyValues *v34; // eax
  KeyValues *v35; // ebx
  vgui::Panel *v36; // eax
  KeyValues *v37; // eax
  KeyValues *v38; // ebx
  vgui::Panel *v39; // eax
  vgui::Menu *v40; // eax
  int nItemID; // [esp+8h] [ebp-Ch]
  int nCount; // [esp+Ch] [ebp-8h]
  bool bShowLoadSourceFile; // [esp+11h] [ebp-3h]
  bool bShowZoomOut; // [esp+12h] [ebp-2h]
  bool bShowZoomIn; // [esp+13h] [ebp-1h]
  vgui::ListPanel *bHasValidSourceFile; // [esp+1Ch] [ebp+8h]
  bool bHasValidSourceFile_3; // [esp+1Fh] [ebp+Bh]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v5->MarkForDeletion(this: v5);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
      pPanel: nullptr);
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    bHasValidSourceFile = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
    nItemID = KeyValues::GetInt(this: kv, keyName: "itemID", defaultValue: -1);
    if ( bHasValidSourceFile == this->m_pSourcesList )
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
        v10 = KeyValues::KeyValues(this: v9, setName: "AddSource");
      else
        v10 = nullptr;
      v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v11->__vftable[1].PaintTraverse)(
        a1: v11,
        a2: "Add...",
        a3: v10,
        a4: this,
        a5: 0);
      nCount = this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList);
      if ( nCount > 0 )
      {
        v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v12 != nullptr )
          v13 = KeyValues::KeyValues(this: v12, setName: "RemoveSource");
        else
          v13 = nullptr;
        v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v14->__vftable[1].PaintTraverse)(
          a1: v14,
          a2: "Remove",
          a3: v13,
          a4: this,
          a5: 0);
      }
      bShowZoomIn = false;
      bShowZoomOut = this->m_hMakefileStack.m_Size > 1;
      bShowLoadSourceFile = false;
      bHasValidSourceFile_3 = false;
      if ( nCount == 1 && nItemID != -1 )
      {
        v15 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: nItemID);
        ElementKey = GetElementKeyValue<CDmeSource>(pKeyValues: v15, pName: "dmeSource");
        v17 = ElementKey;
        if ( ElementKey != nullptr )
        {
          m_pAsString = ElementKey->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = &var;
          bHasValidSourceFile_3 = *m_pAsString != 0;
          v19 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
          if ( CDmeMakefile::FindDependentMakefile(this: v19, pSource: v17) != nullptr )
          {
            bShowZoomIn = true;
            goto LABEL_25;
          }
          bShowLoadSourceFile = bHasValidSourceFile_3;
        }
      }
      if ( !bShowZoomOut )
      {
LABEL_35:
        if ( nCount == 1 )
        {
          v27 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, int))v27->__vftable[1].DeletePanel)(a1: v27, a2);
          v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v28 != nullptr )
            v29 = KeyValues::KeyValues(this: v28, setName: "NewSourceFile");
          else
            v29 = nullptr;
          v30 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v30->__vftable[1].PaintTraverse)(
            a1: v30,
            a2: "New Source File...",
            a3: v29,
            a4: this,
            a5: 0);
          v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v31 != nullptr )
            v32 = KeyValues::KeyValues(this: v31, setName: "BrowseSourceFile");
          else
            v32 = nullptr;
          v33 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *))v33->__vftable[1].PaintTraverse)(
            a1: v33,
            a2: "Select Source File...",
            a3: v32,
            a4: this);
          if ( bShowLoadSourceFile )
          {
            v34 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v34 != nullptr )
              v35 = KeyValues::KeyValues(this: v34, setName: "LoadSourceFile");
            else
              v35 = nullptr;
            v36 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v36->__vftable[1].PaintTraverse)(
              a1: v36,
              a2: "Load Source File",
              a3: v35,
              a4: this,
              a5: 0);
          }
          if ( bHasValidSourceFile_3 )
          {
            v37 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v37 != nullptr )
              v38 = KeyValues::KeyValues(this: v37, setName: "EditSourceFile");
            else
              v38 = nullptr;
            v39 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v39->__vftable[1].PaintTraverse)(
              a1: v39,
              a2: "Edit Source File",
              a3: v38,
              a4: this,
              a5: 0);
          }
        }
        v40 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::PlaceContextMenu(a1: a3, parent: this, menu: v40);
        return;
      }
LABEL_25:
      v20 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v20->__vftable[1].DeletePanel(this: v20);
      if ( bShowZoomIn )
      {
        v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v21 != nullptr )
          v22 = KeyValues::KeyValues(this: v21, setName: "ZoomInSource");
        else
          v22 = nullptr;
        v23 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v23->__vftable[1].PaintTraverse)(
          a1: v23,
          a2: "Zoom In",
          a3: v22,
          a4: this,
          a5: 0);
      }
      if ( bShowZoomOut )
      {
        v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v24 != nullptr )
          v25 = KeyValues::KeyValues(this: v24, setName: "ZoomOutSource");
        else
          v25 = nullptr;
        v26 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v26->__vftable[1].PaintTraverse)(
          a1: v26,
          a2: "Zoom Out",
          a3: v25,
          a4: this,
          a5: 0);
      }
      goto LABEL_35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047A5B0
// Name: private: void CAssetBuilder::OnSourceItemSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceItemSelectionChanged(CAssetBuilder *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1 )
  {
    v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    v3 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2);
    Int = KeyValues::GetInt(this: v3, keyName: "dmeSource", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeSource::m_classType) )
      v6 = nullptr;
    CDmePanel::SetDmeElement(
      this: this->m_pDmePanel,
      a2: (int)this,
      pDmeElement: v6,
      bForce: false,
      pPanelName: nullptr);
  }
  else
  {
    CDmePanel::SetDmeElement(
      this: this->m_pDmePanel,
      a2: (int)this,
      pDmeElement: nullptr,
      bForce: false,
      pPanelName: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047A650
// Name: private: virtual void CAssetBuilder::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnItemSelected(CAssetBuilder *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pSourcesList )
    CAssetBuilder::OnSourceItemSelectionChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047A680
// Name: private: class CDmeSource __near * CAssetBuilder::GetSelectedSource(void)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CAssetBuilder::GetSelectedSource(CAssetBuilder *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr
    && (v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0),
        v3 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2),
        Int = KeyValues::GetInt(this: v3, keyName: "dmeSource", defaultValue: -1),
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
        v6 = v5,
        v5 != nullptr)
    && v5->IsA(this: v5, a2: CDmeSource::m_classType) )
  {
    return (CDmeSource *)v6;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047A720
// Name: private: void CAssetBuilder::OnSourceFileNameChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceFileNameChanged(CAssetBuilder *this, char *pFileName)
{
  int v3; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmeSource *v6; // edi
  CDmeMakefile *v7; // eax
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-Ch] BYREF
  KeyValues *pKeyValues; // [esp+14h] [ebp-4h]

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v3 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    pKeyValues = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v3);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dmeSource", defaultValue: -1);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v6 = (CDmeSource *)v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeSource::m_classType) )
    {
      CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
      v7 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
      CDmeMakefile::SetSourceFullPath(this: v7, pSource: v6, pFullPath: pFileName);
      this->SetDirty(this);
      CChangeUndoScopeGuard::Release(this: &guard);
      KeyValues::SetString(this: pKeyValues, keyName: "file", value: pFileName);
      this->m_pSourcesList->ApplyItemChanges(this: this->m_pSourcesList, a2: v3);
      this->m_pSourcesList->SortList(this: this->m_pSourcesList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047A840
// Name: private: virtual void CAssetBuilder::OnEditSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnEditSourceFile(CAssetBuilder *this)
{
  CDmeSource *SelectedSource; // eax

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
    CDmeSource::OpenEditor(this: SelectedSource);
}

//------------------------------------------------------------------------------
// Address: 0x1047A860
// Name: private: virtual void CAssetBuilder::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnFileSelected(CAssetBuilder *this, KeyValues *kv)
{
  char *String; // esi
  KeyValues *Key; // edi

  String = KeyValues::GetString(this: kv, keyName: "fullpath", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( KeyValues::FindKey(this: kv, keyName: "SelectSourceFile", bCreate: false) != nullptr )
      goto LABEL_6;
    Key = KeyValues::FindKey(this: kv, keyName: "NewSourceFileSelected", bCreate: false);
    if ( Key == nullptr )
      return;
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: String, a3: nullptr) )
LABEL_6:
      CAssetBuilder::OnSourceFileNameChanged(this, pFileName: String);
    else
      CAssetBuilder::OnNewSourceFileSelected(this, pFileName: String, kv: Key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047A970
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x1047AA00
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x1047AA90
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
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
// Address: 0x1047AB20
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x1047ABB0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
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
// Address: 0x1047AC40
// Name: public: static void CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_SetDirty::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_SetDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047ACD0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047AD60
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "NewSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047ADF0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LoadSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047AE80
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "EditSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047AF10
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047AFA0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BrowseSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047B030
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ZoomInSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047B0C0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ZoomOutSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047B150
// Name: void BuildAssetTypeList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildAssetTypeList()
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  int v1; // edi
  bool (__thiscall *IsValidFactory)(IDataModel *, int); // edx
  const char *v3; // ebx
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CExpressionCalculator *v6; // esi
  int m_Size; // eax
  int v8; // edi
  PickerInfo_t *m_pMemory; // ecx
  int v10; // eax
  int (__thiscall *v11)(CExpressionCalculator *); // eax
  IDataModel_vtbl *v12; // edi
  int BufferType; // eax
  int v14; // eax
  IDataModel_vtbl *v15; // edx
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  PickerInfo_t *v17; // [esp+14h] [ebp-8h]
  int hFactory; // [esp+18h] [ebp-4h]

  if ( !s_bAssetTypeListBuilt )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    s_bAssetTypeListBuilt = true;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v1 = g_pDataModel->GetFirstFactory(this: g_pDataModel);
    IsValidFactory = g_pDataModel->IsValidFactory;
    hFactory = v1;
    if ( IsValidFactory(this: g_pDataModel, a2: v1) )
    {
      while ( 1 )
      {
        v3 = g_pDataModel->GetFactoryName(this: g_pDataModel, a2: v1);
        v4 = g_pDataModel->CreateElement(this: g_pDataModel, a2: v3, a3: "temp", a4: DMFILEID_INVALID, a5: nullptr);
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
        v6 = (CExpressionCalculator *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
        {
          if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v6->m_expr.m_Storage.m_Memory.m_pMemory
                + 4))(
                 a1: v6,
                 a2: CDmeMakefile::m_classType.u) != 0
            && (*((int (__thiscall **)(CExpressionCalculator *))v6->m_expr.m_Storage.m_Memory.m_pMemory + 14))(a1: v6) != 0 )
          {
            m_Size = s_AssetTypes.m_Choices.m_Size;
            v8 = s_AssetTypes.m_Choices.m_Size;
            if ( s_AssetTypes.m_Choices.m_Size + 1 > s_AssetTypes.m_Choices.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CacheOptimizedKDNode,int>::Grow(
                this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&s_AssetTypes.m_Choices,
                num: s_AssetTypes.m_Choices.m_Size - s_AssetTypes.m_Choices.m_Memory.m_nAllocationCount + 1);
              m_Size = s_AssetTypes.m_Choices.m_Size;
            }
            m_pMemory = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            s_AssetTypes.m_Choices.m_Size = m_Size + 1;
            v10 = m_Size - v8;
            s_AssetTypes.m_Choices.m_pElements = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            if ( v10 > 0 )
            {
              _V_memmove(
                dest: (unsigned __int8 *)&s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8 + 1],
                src: (unsigned __int8 *)&s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8],
                count: 8 * v10);
              m_pMemory = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            }
            v11 = *((int (__thiscall **)(CExpressionCalculator *))v6->m_expr.m_Storage.m_Memory.m_pMemory + 14);
            v17 = &m_pMemory[v8];
            v17->m_pChoiceString = *(const char **)(v11(a1: v6) + 4);
            s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8].m_pChoiceValue = v3;
          }
          v12 = g_pDataModel->__vftable;
          BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
          v12->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
          v1 = hFactory;
        }
        v14 = g_pDataModel->GetNextFactory(this: g_pDataModel, a2: v1);
        v15 = g_pDataModel->__vftable;
        hFactory = v14;
        if ( !v15->IsValidFactory(this: g_pDataModel, a2: v14) )
          break;
        v1 = hFactory;
      }
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047B330
// Name: BuildAssetSubTypeList
// Source: json
//------------------------------------------------------------------------------
PickerList_t *__cdecl BuildAssetSubTypeList(const char **ppSubTypes, PickerList_t *pickerList)
{
  CExpressionCalculator *v2; // ebx
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeMakefile *v6; // esi
  bool (__thiscall *IsA)(struct CDmeMakefile *, CUtlSymbolLarge); // eax
  char v8; // al
  const char **v9; // eax
  int v10; // esi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v14; // eax
  int v15; // ebx
  PickerInfo_t *v16; // esi
  IDataModel_vtbl *v17; // esi
  int BufferType; // eax
  bool guard_4; // [esp+10h] [ebp-18h]
  int nCount; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h] BYREF
  CDmeMakefile *pMakeFile; // [esp+1Ch] [ebp-Ch]
  CDmeMakefile *v23; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v2 = nullptr;
  if ( ppSubTypes == nullptr )
    return &s_AssetTypes;
  pickerList->m_Choices.m_Size = 0;
  guard_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  nCount = s_AssetTypes.m_Choices.m_Size;
  i = 0;
  if ( s_AssetTypes.m_Choices.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = g_pDataModel->CreateElement(
             this: g_pDataModel,
             a2: s_AssetTypes.m_Choices.m_Memory.m_pMemory[i].m_pChoiceValue,
             a3: "temp",
             a4: DMFILEID_INVALID,
             a5: nullptr);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
      v6 = (CDmeMakefile *)v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        IsA = v6->IsA;
        v2 = (CExpressionCalculator *)v6;
        v23 = v6;
        v8 = ((int (__thiscall *)(_DWORD, _DWORD))IsA)(a1: v6, a2: (CUtlSymbolLarge)CDmeMakefile::m_classType.u.m_Id);
        pMakeFile = v6;
        if ( v8 != 0 )
          goto LABEL_10;
      }
      else
      {
        v23 = nullptr;
      }
      pMakeFile = nullptr;
LABEL_10:
      v9 = ppSubTypes;
      v10 = 0;
      if ( *ppSubTypes != nullptr )
      {
        while ( 1 )
        {
          g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v21, a3: *v9);
          if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, int))v2->m_expr.m_Storage.m_Memory.m_pMemory
                + 4))(
                 a1: v2,
                 a2: v21) != 0 )
            break;
          v9 = &ppSubTypes[++v10];
          if ( *v9 == nullptr )
            goto LABEL_20;
        }
        m_Size = pickerList->m_Choices.m_Size;
        m_nAllocationCount = pickerList->m_Choices.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CacheOptimizedKDNode,int>::Grow(
            this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&pickerList->m_Choices,
            num: m_Size - m_nAllocationCount + 1);
        ++pickerList->m_Choices.m_Size;
        m_pMemory = pickerList->m_Choices.m_Memory.m_pMemory;
        v14 = pickerList->m_Choices.m_Size - m_Size - 1;
        pickerList->m_Choices.m_pElements = m_pMemory;
        if ( v14 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 8 * v14);
        v15 = m_Size;
        v16 = pickerList->m_Choices.m_Memory.m_pMemory;
        v16[v15].m_pChoiceString = pMakeFile->GetMakefileType(this: pMakeFile)->m_pHumanReadableName;
        pickerList->m_Choices.m_Memory.m_pMemory[v15].m_pChoiceValue = s_AssetTypes.m_Choices.m_Memory.m_pMemory[i].m_pChoiceValue;
        v2 = (CExpressionCalculator *)v23;
      }
LABEL_20:
      if ( v2 != nullptr )
      {
        v17 = g_pDataModel->__vftable;
        BufferType = CCodecBuffer_Block::GetBufferType(this: v2);
        v17->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
      }
      if ( ++i >= nCount )
        break;
      v2 = nullptr;
    }
  }
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
  return pickerList;
}

//------------------------------------------------------------------------------
// Address: 0x1047B530
// Name: ReadMakefile
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__usercall ReadMakefile@<eax>(const char *pFileName@<edi>, CDmElement **ppRoot)
{
  CDmElement **v2; // ebx
  CDmeMakefile *Value; // esi
  CDmElement **v4; // esi
  CDmElement *v5; // ecx
  CDmElement *v6; // esi

  v2 = ppRoot;
  if ( ppRoot != nullptr )
    *ppRoot = nullptr;
  if ( g_pDataModel->RestoreFromFile(
         this: g_pDataModel,
         a2: pFileName,
         a3: nullptr,
         a4: nullptr,
         a5: (CDmElement **)&ppRoot,
         a6: CR_DELETE_OLD,
         a7: nullptr) == DMFILEID_INVALID
    || (Value = (CDmeMakefile *)ppRoot, ppRoot == nullptr) )
  {
    _Warning(a1: "Unable to read makefile \"%s\"!\n", pFileName);
    return nullptr;
  }
  if ( (*(unsigned __int8 (__thiscall **)(CDmElement **, CUtlSymbolLarge::<unnamed_type_u>))&(*ppRoot)->m_Id.m_Value[12])(
         a1: ppRoot,
         a2: CDmeMakefile::m_classType.u) == 0 )
  {
    v4 = ppRoot;
    if ( ppRoot != nullptr
      && (*(unsigned __int8 (__thiscall **)(CDmElement **, CUtlSymbolLarge::<unnamed_type_u>))&(*ppRoot)->m_Id.m_Value[12])(
           a1: ppRoot,
           a2: CDmElement::m_classType.u) != 0 )
    {
      v5 = (CDmElement *)v4;
    }
    else
    {
      v5 = nullptr;
    }
    Value = CDmElement::GetValueElement<CDmeMakefile>(this: v5, pAttributeName: "makefile");
    if ( Value == nullptr )
    {
      v6 = ppRoot[14];
      DestroyElement(pElement: (CDmElement *)ppRoot);
      if ( v6 != (CDmElement *)-1 && *g_pDataModel->GetFileName(this: g_pDataModel, a2: v6) != 0 )
      {
        g_pDataModel->RemoveFileId(this: g_pDataModel, a2: (DmFileId_t)v6);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( v2 != nullptr )
    *v2 = CastElement<CDmElement>(pElement: (CDmElement *)ppRoot);
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x1047B630
// Name: public: CAssetBuilder::CAssetBuilder(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetBuilder *__thiscall CAssetBuilder::CAssetBuilder(
        CAssetBuilder *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::PropertyPage *v9; // eax
  vgui::PropertyPage *v10; // eax
  vgui::PropertyPage *v11; // eax
  vgui::PropertyPage *v12; // eax
  vgui::PropertyPage *v13; // eax
  vgui::PropertyPage *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  vgui::Splitter *v17; // eax
  vgui::Splitter *v18; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v20; // edi
  CDmePanel *v21; // eax
  CDmePanel *v22; // eax
  CDmePanel *v23; // eax
  CDmePanel *v24; // eax
  vgui::ListPanel *v25; // eax
  vgui::ListPanel *v26; // eax
  vgui::ListPanel *v27; // eax
  vgui::ListPanel *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::TextEntry *v30; // eax
  vgui::Button *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::Button *v34; // eax
  vgui::Button *v35; // eax
  vgui::Button *v36; // eax
  CCompileStatusBar *v37; // eax
  CCompileStatusBar *v38; // eax
  vgui::PropertyPage *m_pInputPage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CAssetBuilder_vtbl *)&CAssetBuilder::`vftable';
  if ( `CAssetBuilder::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v4->pfnClassName = CAssetBuilder::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CAssetBuilder::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAssetBuilder");
    v5->pfnClassName = CAssetBuilder::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CAssetBuilder::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetBuilder");
    v6->pfnClassName = CAssetBuilder::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_hRootMakefile.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hMakefile.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hMakefileStack.m_Memory.m_pMemory = nullptr;
  this->m_hMakefileStack.m_Memory.m_nAllocationCount = 0;
  this->m_hMakefileStack.m_Memory.m_nGrowSize = 0;
  this->m_hMakefileStack.m_Size = 0;
  this->m_hMakefileStack.m_pElements = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
    pPanel: nullptr);
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: DMELEMENT_HANDLE_INVALID);
  *((_BYTE *)this + 492) = *((_BYTE *)this + 492) & 0xFC | 2;
  v7 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(
           this: v7,
           parent: this,
           panelName: (vgui::Panel *)"InputOutputSheet",
           draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pInputOutputSheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v9 != nullptr )
    v10 = vgui::PropertyPage::PropertyPage(this: v9, parent: this->m_pInputOutputSheet, panelName: "InputPage");
  else
    v10 = nullptr;
  this->m_pInputPage = v10;
  v11 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v11 != nullptr )
    v12 = vgui::PropertyPage::PropertyPage(this: v11, parent: this->m_pInputOutputSheet, panelName: "OutputPage");
  else
    v12 = nullptr;
  this->m_pOutputPage = v12;
  v13 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v13 != nullptr )
    v14 = vgui::PropertyPage::PropertyPage(this: v13, parent: this->m_pInputOutputSheet, panelName: "CompilePage");
  else
    v14 = nullptr;
  this->m_pCompilePage = v14;
  v15 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v15 != nullptr )
    v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pInputOutputSheet, panelName: "OutputPreviewPage");
  else
    v16 = nullptr;
  this->m_pOutputPreviewPage = v16;
  v17 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v17 != nullptr )
    v18 = vgui::Splitter::Splitter(
            this: v17,
            parent: this->m_pInputPage,
            name: "PropertiesSplitter",
            mode: SPLITTER_MODE_VERTICAL,
            nCount: 1);
  else
    v18 = nullptr;
  this->m_pPropertiesSplitter = v18;
  Child = vgui::Panel::GetChild(this: v18, index: 0);
  v20 = vgui::Panel::GetChild(this: this->m_pPropertiesSplitter, index: 1);
  v21 = (CDmePanel *)operator new(nSize: 0x250u);
  if ( v21 != nullptr )
    v22 = CDmePanel::CDmePanel(this: v21, pParent: v20, pPanelName: "CompileOptions", bComboBoxVisible: true);
  else
    v22 = nullptr;
  this->m_pDmePanel = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (CDmePanel *)operator new(nSize: 0x250u);
  if ( v23 != nullptr )
    v24 = CDmePanel::CDmePanel(
            this: v23,
            pParent: this->m_pOutputPreviewPage,
            pPanelName: "OutputPreview",
            bComboBoxVisible: false);
  else
    v24 = nullptr;
  this->m_pOututPreviewPanel = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  v25 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v25 != nullptr )
    v26 = vgui::ListPanel::ListPanel(this: v25, parent: Child, panelName: "SourcesList");
  else
    v26 = nullptr;
  this->m_pSourcesList = v26;
  v26->AddColumnHeader(this: v26, a2: 0, a3: "type", a4: "type", a5: 100, a6: 0);
  this->m_pSourcesList->AddColumnHeader(this: this->m_pSourcesList, a2: 1, a3: "file", a4: "file", a5: 52, a6: 0);
  this->m_pSourcesList->AddActionSignalTarget_2(this: this->m_pSourcesList, a2: this);
  this->m_pSourcesList->SetSortFunc(this: this->m_pSourcesList, a2: 0, a3: TypeSortFunc);
  this->m_pSourcesList->SetSortFunc(this: this->m_pSourcesList, a2: 1, a3: FileSortFunc);
  this->m_pSourcesList->SetSortColumn(this: this->m_pSourcesList, a2: 0);
  this->m_pSourcesList->SetEmptyListText_2(this: this->m_pSourcesList, a2: "No sources");
  v27 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v27 != nullptr )
    v28 = vgui::ListPanel::ListPanel(this: v27, parent: this->m_pOutputPage, panelName: "OutputList");
  else
    v28 = nullptr;
  this->m_pOutputList = v28;
  v28->AddColumnHeader(this: v28, a2: 0, a3: "type", a4: "type", a5: 100, a6: 0);
  this->m_pOutputList->AddColumnHeader(this: this->m_pOutputList, a2: 1, a3: "file", a4: "file", a5: 52, a6: 0);
  this->m_pOutputList->AddActionSignalTarget_2(this: this->m_pOutputList, a2: this);
  this->m_pOutputList->SetSortFunc(this: this->m_pOutputList, a2: 0, a3: TypeSortFunc);
  this->m_pOutputList->SetSortFunc(this: this->m_pOutputList, a2: 1, a3: FileSortFunc);
  this->m_pOutputList->SetSortColumn(this: this->m_pOutputList, a2: 0);
  this->m_pOutputList->SetEmptyListText_2(this: this->m_pOutputList, a2: "No outputs");
  v29 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v29 != nullptr )
    v30 = vgui::TextEntry::TextEntry(this: v29, parent: this->m_pCompilePage, panelName: (vgui::Panel *)"CompileOutput");
  else
    v30 = nullptr;
  this->m_pCompileOutput = v30;
  v30->SetMultiline(this: v30, a2: true);
  this->m_pCompileOutput->SetVerticalScrollbar(this: this->m_pCompileOutput, a2: true);
  v31 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v31 != nullptr )
    v32 = vgui::Button::Button(
            this: v31,
            parent: this,
            panelName: "CompileButton",
            text: "Compile",
            pActionSignalTarget: this,
            pCmd: "OnCompile");
  else
    v32 = nullptr;
  this->m_pCompile = v32;
  v33 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v33 != nullptr )
    v34 = vgui::Button::Button(
            this: v33,
            parent: this,
            panelName: "PublishButton",
            text: "Publish",
            pActionSignalTarget: this,
            pCmd: "OnPublish");
  else
    v34 = nullptr;
  this->m_pPublish = v34;
  v35 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v35 != nullptr )
    v36 = vgui::Button::Button(
            this: v35,
            parent: this,
            panelName: "AbortCompileButton",
            text: "AbortCompile",
            pActionSignalTarget: this,
            pCmd: "OnAbortCompile");
  else
    v36 = nullptr;
  this->m_pAbortCompile = v36;
  v37 = (CCompileStatusBar *)operator new(nSize: 0x18Cu);
  if ( v37 != nullptr )
    v38 = CCompileStatusBar::CCompileStatusBar(this: v37, pParent: this, pPanelName: "CompileStatus");
  else
    v38 = nullptr;
  m_pInputPage = this->m_pInputPage;
  this->m_pCompileStatusBar = v38;
  m_pInputPage->LoadControlSettingsAndUserConfig(this: m_pInputPage, a2: "resource/assetbuilderinputpage.res", a3: 0);
  this->m_pOutputPage->LoadControlSettingsAndUserConfig(
    this: this->m_pOutputPage,
    a2: "resource/assetbuilderoutputpage.res",
    a3: 0);
  this->m_pCompilePage->LoadControlSettingsAndUserConfig(
    this: this->m_pCompilePage,
    a2: "resource/assetbuildercompilepage.res",
    a3: 0);
  this->m_pOutputPreviewPage->LoadControlSettingsAndUserConfig(
    this: this->m_pOutputPreviewPage,
    a2: "resource/assetbuilderoutputpreviewpage.res",
    a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetbuilder.res",
    dialogID: 0);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pInputPage,
    a3: "Input",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pOutputPage,
    a3: "Output",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pCompilePage,
    a3: "Compile",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pOutputPreviewPage,
    a3: "Preview",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: false);
  this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: false);
  this->m_pAbortCompile->SetEnabled(this: this->m_pAbortCompile, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1047BD20
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetBuilder::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetBuilder::GetMessageMap(CAssetBuilder *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetBuilder::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetBuilder::GetMessageMap'::`2'::s_pMap;
  `CAssetBuilder::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
  `CAssetBuilder::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1047BD50
// Name: public: virtual struct PanelAnimationMap __near * CAssetBuilder::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetBuilder::GetAnimMap(CAssetBuilder *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetBuilder");
}

//------------------------------------------------------------------------------
// Address: 0x1047BD60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetBuilder::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetBuilder::GetKBMap(CAssetBuilder *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetBuilder::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetBuilder::GetKBMap'::`2'::s_pMap;
  `CAssetBuilder::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetBuilder");
  `CAssetBuilder::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1047BD90
// Name: private: void CAssetBuilder::BuildFileIDList(class CDmeMakefile __near *,class CUtlVector<enum DmFileId_t,class CUtlMemory<enum DmFileId_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::BuildFileIDList(
        CAssetBuilder *this,
        CDmeMakefile *pMakeFile,
        CUtlMemory<vgui::TreeNode *,int> *fileIds)
{
  DmFileId_t m_fileId; // ebx
  int m_pMemory; // edi
  int v5; // eax
  DmFileId_t *v6; // ecx
  int m_nAllocationCount; // eax
  DmFileId_t *v8; // ecx
  int v9; // eax
  DmFileId_t *v10; // edi
  CDmAttribute *ClipCount; // ebx
  int i; // edi
  CDmeSource *Source; // eax
  CDmeMakefile *DependentMakefile; // eax

  if ( pMakeFile != nullptr )
  {
    m_fileId = pMakeFile->m_fileId;
    m_pMemory = (int)fileIds[1].m_pMemory;
    v5 = 0;
    if ( m_pMemory > 0 )
    {
      v6 = (DmFileId_t *)fileIds->m_pMemory;
      do
      {
        if ( *v6 == m_fileId )
          break;
        ++v5;
        ++v6;
      }
      while ( v5 < m_pMemory );
    }
    if ( v5 == m_pMemory )
    {
      m_nAllocationCount = fileIds->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: fileIds, num: m_pMemory - m_nAllocationCount + 1);
      ++fileIds[1].m_pMemory;
      v8 = (DmFileId_t *)fileIds->m_pMemory;
      v9 = (int)fileIds[1].m_pMemory - m_pMemory - 1;
      fileIds[1].m_nAllocationCount = (int)fileIds->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v8[m_pMemory + 1], src: (unsigned __int8 *)&v8[m_pMemory], count: 4 * v9);
      v10 = (DmFileId_t *)&fileIds->m_pMemory[m_pMemory];
      if ( v10 != nullptr )
        *v10 = m_fileId;
    }
    ClipCount = CDmeTrack::GetClipCount(this: (CDmeTransform *)pMakeFile);
    for ( i = 0; i < (int)ClipCount; ++i )
    {
      Source = CDmeMakefile::GetSource(this: pMakeFile, nIndex: i);
      DependentMakefile = CDmeSource::GetDependentMakefile(this: Source);
      CAssetBuilder::BuildFileIDList(
        this,
        pMakeFile: DependentMakefile,
        (CUtlVector<enum DmFileId_t,CUtlMemory<enum DmFileId_t,int> > *)fileIds);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047BE50
// Name: private: void CAssetBuilder::CleanupMakefile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::CleanupMakefile(CAssetBuilder *this)
{
  int i; // edi
  DmElementHandle_t m_handle; // eax
  CDmeMakefile *v4; // eax
  int v5; // esi
  int j; // edi
  DmFileId_t *m_pMemory; // eax
  CUtlVector<enum DmFileId_t,CUtlMemory<enum DmFileId_t,int> > fileIds; // [esp+Ch] [ebp-1Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+20h] [ebp-8h]

  for ( i = this->m_hMakefileStack.m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel != nullptr )
      CDmeElementRefHelper::Unref(
        this: &this->m_hMakefileStack.m_Memory.m_pMemory[i],
        hElement: this->m_hMakefileStack.m_Memory.m_pMemory[i].m_handle,
        handleType: HT_WEAK);
  }
  this->m_hMakefileStack.m_Size = 0;
  CDmePanel::SetDmeElement(this: this->m_pDmePanel, a2: i, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  CDmePanel::SetDmeElement(
    this: this->m_pOututPreviewPanel,
    a2: i,
    pDmeElement: nullptr,
    bForce: false,
    pPanelName: nullptr);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRootMakefile.m_handle) != nullptr )
  {
    m_handle = this->m_hRootMakefile.m_handle;
    memset(&fileIds, 0, sizeof(fileIds));
    v4 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
    CAssetBuilder::BuildFileIDList(this, pMakeFile: v4, (CUtlMemory<vgui::TreeNode *,int> *)&fileIds);
    guard.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: DMELEMENT_HANDLE_INVALID);
    v5 = 0;
    for ( j = fileIds.m_Size; v5 < j; ++v5 )
    {
      if ( fileIds.m_Memory.m_pMemory[v5] != DMFILEID_INVALID
        && *g_pDataModel->GetFileName(this: g_pDataModel, a2: fileIds.m_Memory.m_pMemory[v5]) != 0 )
      {
        g_pDataModel->RemoveFileId(this: g_pDataModel, a2: fileIds.m_Memory.m_pMemory[v5]);
      }
    }
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
    m_pMemory = fileIds.m_Memory.m_pMemory;
    fileIds.m_Size = 0;
    if ( fileIds.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileIds.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileIds.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileIds.m_Memory.m_pMemory = nullptr;
      }
      fileIds.m_Memory.m_nAllocationCount = 0;
    }
    fileIds.m_pElements = m_pMemory;
    if ( fileIds.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047BFE0
// Name: private: virtual void CAssetBuilder::OnNewSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnNewSourceFile(CAssetBuilder *this)
{
  KeyValues *SelectedSourceKeyvalues; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char **v6; // eax
  const PickerList_t *v7; // esi
  CPickerFrame *v8; // eax
  CPickerFrame *v9; // eax
  PickerList_t typePickerList; // [esp+Ch] [ebp-18h] BYREF

  SelectedSourceKeyvalues = CAssetBuilder::GetSelectedSourceKeyvalues(this);
  Int = KeyValues::GetInt(this: SelectedSourceKeyvalues, keyName: "dmeSource", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeSource::m_classType) )
  {
    BuildAssetTypeList();
    memset(&typePickerList, 0, sizeof(typePickerList));
    v6 = (const char **)((int (__thiscall *)(CDmElement *))v5->__vftable[1].OnAttributeChanged)(a1: v5);
    v7 = BuildAssetSubTypeList(ppSubTypes: v6, pickerList: &typePickerList);
    v8 = (CPickerFrame *)operator new(nSize: 0x224u);
    if ( v8 != nullptr )
      v9 = CPickerFrame::CPickerFrame(
             this: v8,
             pParent: this,
             pTitle: "Select Sub-Asset Type",
             pPickerType: "Asset Type",
             pTextType: "assetType");
    else
      v9 = nullptr;
    CPickerFrame::DoModal(this: v9, list: v7, pContextKeyValues: nullptr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&typePickerList.m_Choices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047C0A0
// Name: private: virtual void CAssetBuilder::OnAddSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnAddSource(CAssetBuilder *this)
{
  vgui::Panel *v1; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  DmElementHandle_t m_pElements; // eax
  int v4; // ebx
  CDmElement *v5; // eax
  DmeMakefileType_t *v6; // eax
  DmeMakefileType_t *v7; // esi
  DmeMakefileType_t *v8; // edi
  CDmeMakefile *v9; // eax
  int m_Size; // eax
  int v11; // esi
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  CPickerFrame *v16; // eax
  CPickerFrame *v17; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-28h]
  PickerList_t sourceType; // [esp+4h] [ebp-20h] BYREF
  DmeMakefileType_t *pSourceTypes; // [esp+1Ch] [ebp-8h]
  CAssetBuilder *v21; // [esp+20h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hMakefile.m_handle;
  v21 = this;
  if ( (int)GetElement(this: g_pDataModel, a2: m_handle) != 0 )
  {
    m_pElements = (DmElementHandle_t)v1[1].m_OverridableColorEntries.m_pElements;
    v4 = 0;
    memset(&sourceType, 0, sizeof(sourceType));
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pElements);
    v6 = (DmeMakefileType_t *)((int (__thiscall *)(CDmElement *))v5->__vftable[1].OnAttributeArrayElementAdded)(a1: v5);
    v7 = v6;
    pSourceTypes = v6;
    if ( v6->m_pTypeName != nullptr )
    {
      v8 = v6;
      do
      {
        if ( !v8->m_bIsSingleton
          || (v9 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: v21->m_hMakefile.m_handle),
              !CDmeMakefile::HasSourceOfType(this: v9, pSourceType: v8->m_pTypeName)) )
        {
          m_Size = sourceType.m_Choices.m_Size;
          v11 = sourceType.m_Choices.m_Size;
          if ( sourceType.m_Choices.m_Size + 1 > sourceType.m_Choices.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CacheOptimizedKDNode,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&sourceType.m_Choices,
              num: sourceType.m_Choices.m_Size - sourceType.m_Choices.m_Memory.m_nAllocationCount + 1);
            m_Size = sourceType.m_Choices.m_Size;
          }
          m_pMemory = sourceType.m_Choices.m_Memory.m_pMemory;
          sourceType.m_Choices.m_Size = m_Size + 1;
          v13 = m_Size - v11;
          sourceType.m_Choices.m_pElements = sourceType.m_Choices.m_Memory.m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(
              dest: (unsigned __int8 *)&sourceType.m_Choices.m_Memory.m_pMemory[v11 + 1],
              src: (unsigned __int8 *)&sourceType.m_Choices.m_Memory.m_pMemory[v11],
              count: 8 * v13);
            m_pMemory = sourceType.m_Choices.m_Memory.m_pMemory;
          }
          m_pMemory[v11].m_pChoiceString = v8->m_pHumanReadableName;
          sourceType.m_Choices.m_Memory.m_pMemory[v11].m_pChoiceValue = v8->m_pTypeName;
          v7 = pSourceTypes;
        }
        v8 = &v7[++v4];
      }
      while ( v8->m_pTypeName != nullptr );
      v1 = v21;
    }
    if ( sourceType.m_Choices.m_Size != 0 )
    {
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "OnAddSource");
      else
        v15 = nullptr;
      v16 = (CPickerFrame *)operator new(nSize: 0x224u);
      if ( v16 != nullptr )
        v17 = CPickerFrame::CPickerFrame(
                this: v16,
                pParent: v1,
                pTitle: "Select Source Type",
                pPickerType: "Source Type",
                pTextType: "sourceType");
      else
        v17 = nullptr;
      CPickerFrame::DoModal(this: v17, list: &sourceType, pContextKeyValues: v15);
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&sourceType.m_Choices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047C220
// Name: private: virtual void CAssetBuilder::OnLoadSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::OnLoadSourceFile(CAssetBuilder *this@<ecx>, int a2@<edi>)
{
  CDmeSource *SelectedSource; // ebx
  CDmeMakefile *v4; // eax
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDmeMakefile *v6; // eax
  int v7; // edi
  CDmeMakefile *v8; // eax
  int v9; // [esp-4h] [ebp-11Ch]
  CDmeMakefile *v10; // [esp-4h] [ebp-11Ch]
  char pFullPath[260]; // [esp+8h] [ebp-110h] BYREF
  CDmElement *pRoot; // [esp+10Ch] [ebp-Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+110h] [ebp-8h] BYREF

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
  {
    v4 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, CDmeSource *))g_pDataModel->GetElement)(
                           a1: g_pDataModel,
                           a2: this->m_hMakefile.m_handle,
                           a3: SelectedSource);
    CDmeMakefile::GetSourceFullPath(this: v4, pSource: (CDmeSource *)pFullPath, pFullPath: (char *)0x104, nBufLen: a2);
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = ReadMakefile(pFileName: pFullPath, ppRoot: &pRoot);
    v7 = v9;
    if ( v6 != nullptr )
    {
      v10 = v6;
      v8 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
      CDmeMakefile::SetAssociation(this: v8, pSource: SelectedSource, pSourceMakefile: v10);
      CDmePanel::SetDmeElement(
        this: this->m_pDmePanel,
        a2: v7,
        pDmeElement: SelectedSource,
        bForce: true,
        pPanelName: nullptr);
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047C2F0
// Name: public: virtual CAssetBuilder::~CAssetBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::~CAssetBuilder(CAssetBuilder *this)
{
  bool v2; // zf
  vgui::Panel *v3; // eax

  v2 = (*((_BYTE *)this + 492) & 2) == 0;
  this->__vftable = (CAssetBuilder_vtbl *)&CAssetBuilder::`vftable';
  if ( !v2 )
    CAssetBuilder::CleanupMakefile(this);
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v3->MarkForDeletion(this: v3);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
      pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int>>::Purge(this: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)&this->m_hMakefileStack);
  if ( this->m_hMakefileStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_hMakefileStack.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hMakefileStack.m_Memory.m_pMemory);
      this->m_hMakefileStack.m_Memory.m_pMemory = nullptr;
    }
    this->m_hMakefileStack.m_Memory.m_nAllocationCount = 0;
  }
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hMakefile, hElement: this->m_hMakefile.m_handle, handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hRootMakefile,
      hElement: this->m_hRootMakefile.m_handle,
      handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047C3C0
// Name: private: void CAssetBuilder::RefreshSourceList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::RefreshSourceList(CAssetBuilder *this@<ecx>, char *a2@<edi>, int a3@<esi>)
{
  CDmElement *v4; // eax
  DmeMakefileType_t *v5; // eax
  KeyValues *v6; // esi
  DmElementHandle_t m_handle; // eax
  CDmeMakefile *v8; // eax
  int v9; // edi
  int v10; // eax
  CDmeMakefile *v11; // eax
  KeyValues *v12; // eax
  CExpressionCalculator *v13; // eax
  int BufferType; // eax
  int v15; // ecx
  CDmeSource *v16; // [esp-Ch] [ebp-138h]
  char pFullPath[260]; // [esp+4h] [ebp-128h] BYREF
  DmeMakefileType_t *pSourceTypes; // [esp+108h] [ebp-24h]
  int nCount; // [esp+10Ch] [ebp-20h]
  CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int> > sources; // [esp+110h] [ebp-1Ch] BYREF
  int i; // [esp+124h] [ebp-8h]
  DmeMakefileType_t *v24; // [esp+128h] [ebp-4h]

  this->m_pSourcesList->RemoveAll(this: this->m_pSourcesList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    v5 = (DmeMakefileType_t *)((int (__thiscall *)(CDmElement *))v4->__vftable[1].OnAttributeArrayElementAdded)(a1: v4);
    v6 = nullptr;
    pSourceTypes = v5;
    i = 0;
    if ( v5->m_pTypeName != nullptr )
    {
      v24 = v5;
      do
      {
        m_handle = this->m_hMakefile.m_handle;
        memset(&sources, 0, sizeof(sources));
        v8 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
        CDmeMakefile::GetSources(this: v8, pSourceType: v24->m_pTypeName, &sources);
        v9 = 0;
        for ( nCount = sources.m_Size; v9 < nCount; v6 = nullptr )
        {
          v16 = (CDmeSource *)sources.m_Memory.m_pMemory[v9].m_handle;
          v10 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
          v11 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int, char *, int))g_pDataModel->GetElement)(
                                  a1: g_pDataModel,
                                  a2: this->m_hMakefile.m_handle,
                                  a3: v10,
                                  a4: pFullPath,
                                  a5: 260);
          CDmeMakefile::GetSourceFullPath(this: v11, pSource: v16, pFullPath: a2, nBufLen: a3);
          v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v12 != nullptr )
            v6 = KeyValues::KeyValues(
                   this: v12,
                   setName: "node",
                   firstKey: "type",
                   firstValue: (char *)v24->m_pHumanReadableName);
          KeyValues::SetString(this: v6, keyName: "file", value: pFullPath);
          KeyValues::SetInt(this: v6, keyName: "sourceTypeIndex", value: i);
          KeyValues::SetInt(this: v6, keyName: "index", value: v9);
          v13 = (CExpressionCalculator *)g_pDataModel->GetElement(
                                           this: g_pDataModel,
                                           a2: sources.m_Memory.m_pMemory[v9].m_handle);
          if ( v13 != nullptr )
            BufferType = CCodecBuffer_Block::GetBufferType(this: v13);
          else
            BufferType = -1;
          KeyValues::SetInt(this: v6, keyName: "dmeSource", value: BufferType);
          a3 = 0;
          a2 = nullptr;
          ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD))this->m_pSourcesList->AddItem)(
            a1: this->m_pSourcesList,
            a2: v6,
            a3: 0);
          ++v9;
        }
        CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int>>::Purge(this: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)&sources);
        if ( sources.m_Memory.m_nGrowSize >= 0 && sources.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sources.m_Memory.m_pMemory);
        v15 = ++i;
        v24 = &pSourceTypes[v15];
      }
      while ( v24->m_pTypeName != nullptr );
    }
    this->m_pSourcesList->SortList(this: this->m_pSourcesList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047C5C0
// Name: private: virtual void CAssetBuilder::OnRemoveSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnRemoveSource(CAssetBuilder *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  KeyValues *v6; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  CExpressionCalculator *v9; // edi
  CDmeMakefile *v10; // eax
  IDataModel_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  CDmeSource *BufferType; // [esp+0h] [ebp-20h]
  bool guard_4; // [esp+10h] [ebp-10h]
  int nCount; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int nRow; // [esp+1Ch] [ebp-4h]

  nCount = this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList);
  if ( nCount != 0 && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    if ( v2 == -1 )
    {
      nRow = -1;
      v3 = -1;
    }
    else
    {
      v3 = this->m_pSourcesList->GetItemCurrentRow(this: this->m_pSourcesList, a2: v2);
      nRow = v3;
    }
    guard_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v4 = 0;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v5 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: v4);
        v6 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v5);
        Int = KeyValues::GetInt(this: v6, keyName: "dmeSource", defaultValue: -1);
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeSource::m_classType) )
        {
          v10 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, CExpressionCalculator *))g_pDataModel->GetElement)(
                                  a1: g_pDataModel,
                                  a2: this->m_hMakefile.m_handle,
                                  a3: v9);
          CDmeMakefile::RemoveSource(this: v10, pSource: BufferType);
          v11 = g_pDataModel->__vftable;
          BufferType = (CDmeSource *)CCodecBuffer_Block::GetBufferType(this: v9);
          ((void (__thiscall *)(IDataModel *))v11->DestroyElement)(a1: g_pDataModel);
          this->SetDirty(this);
          v4 = i;
        }
        i = ++v4;
      }
      while ( v4 < nCount );
      v3 = nRow;
    }
    CAssetBuilder::RefreshSourceList(this, a2: (char *)v3, a3: (int)this);
    v12 = this->m_pSourcesList->GetItemCount(this: this->m_pSourcesList);
    if ( v12 != 0 && v3 >= 0 )
    {
      if ( v3 >= v12 )
        v3 = v12 - 1;
      v13 = this->m_pSourcesList->GetItemIDFromRow(this: this->m_pSourcesList, a2: v3);
      this->m_pSourcesList->SetSingleSelectedItem(this: this->m_pSourcesList, a2: v13);
    }
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047C790
// Name: private: void CAssetBuilder::OnSourceFileAdded(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceFileAdded(CAssetBuilder *this, const char *pFileName, const char *pTypeName)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDmeMakefile *v5; // eax
  char *v6; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v5 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
  v6 = (char *)CDmeMakefile::AddSource(this: v5, pSourceType: pTypeName, pFullPath: pFileName);
  CChangeUndoScopeGuard::Release(this: &guard);
  this->SetDirty(this);
  CAssetBuilder::RefreshSourceList(this, a2: v6, a3: (int)this);
  CAssetBuilder::SelectSource(this, pSource: (CDmeSource *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x1047C820
// Name: private: void CAssetBuilder::FinishCompilation(enum CompilationState_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAssetBuilder::FinishCompilation(CAssetBuilder *this@<ecx>, int a2@<edi>, CompilationState_t state)
{
  int v4; // eax
  int v5; // edi
  CDmElement *v6; // eax
  int v7; // eax
  int v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  int v11; // eax
  CCompileStatusBar *m_pCompileStatusBar; // esi
  vgui::Label *m_pStatus; // ecx
  CCompileStatusBar *v14; // esi
  vgui::Label *v15; // ecx
  char pBuf[256]; // [esp+8h] [ebp-100h] BYREF

  CDmePanel::SetDmeElement(this: this->m_pDmePanel, a2, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  v4 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
  if ( v4 == -1 )
    v5 = -1;
  else
    v5 = this->m_pSourcesList->GetItemCurrentRow(this: this->m_pSourcesList, a2: v4);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
  CDmePanel::SetDmeElement(
    this: this->m_pOututPreviewPanel,
    a2: v5,
    pDmeElement: v6,
    bForce: true,
    pPanelName: "DmeMakeFileOutputPreview");
  *((_BYTE *)this + 492) &= ~1u;
  CAssetBuilder::RefreshSourceList(this, a2: (char *)v5, a3: (int)this);
  v7 = this->m_pSourcesList->GetItemCount(this: this->m_pSourcesList);
  if ( v7 != 0 && v5 >= 0 )
  {
    if ( v5 >= v7 )
      v5 = v7 - 1;
    v8 = this->m_pSourcesList->GetItemIDFromRow(this: this->m_pSourcesList, a2: v5);
    this->m_pSourcesList->SetSingleSelectedItem(this: this->m_pSourcesList, a2: v8);
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "UpdateFileName");
  else
    v10 = nullptr;
  this->PostActionSignal(this, a2: v10);
  if ( state == 2 )
  {
    v11 = g_pDmeMakefileUtils->GetExitCode(this: g_pDmeMakefileUtils);
    V_snprintf(pDest: pBuf, maxLen: 0x100u, pFormat: "Compilation Error (return code %d)", v11);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pStatus = m_pCompileStatusBar->m_pStatus;
    m_pCompileStatusBar->m_Status = COMPILATION_FAILED;
    m_pStatus->SetText(this: m_pStatus, a2: pBuf);
  }
  else
  {
    v14 = this->m_pCompileStatusBar;
    v15 = v14->m_pStatus;
    v14->m_Status = COMPILATION_SUCCESSFUL;
    v15->SetText(this: v15, a2: "Compile Successful!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047C9A0
// Name: public: virtual void CAssetBuilder::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnTick(CAssetBuilder *this)
{
  int v2; // edi
  void *v3; // esp
  CompilationState_t v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebx
  int v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-10h] BYREF
  CompilationState_t state; // [esp+Ch] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  if ( (*((_BYTE *)this + 492) & 1) == 0 )
    goto LABEL_7;
  v2 = g_pDmeMakefileUtils->GetCompileOutputSize(this: g_pDmeMakefileUtils);
  v3 = alloca(v2 + 1);
  v4 = g_pDmeMakefileUtils->UpdateCompilation(this: g_pDmeMakefileUtils, a2: v8, a3: v2);
  state = v4;
  if ( v2 > 0 )
  {
    this->m_pCompileOutput->InsertString_2(this: this->m_pCompileOutput, a2: v8);
    v4 = state;
  }
  if ( v4 != COMPILATION_NOT_COMPLETE )
    CAssetBuilder::FinishCompilation(this, a2: v2, state: v4);
  if ( (*((_BYTE *)this + 492) & 1) == 0 )
  {
LABEL_7:
    this->m_pAbortCompile->SetEnabled(this: this->m_pAbortCompile, a2: false);
    v5 = g_pVGui;
    v6 = g_pVGui->__vftable;
    v7 = this->GetVPanel(this);
    v6->RemoveTickSignal(this: v5, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047CA80
// Name: private: void CAssetBuilder::RefreshOutputList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::RefreshOutputList(CAssetBuilder *this@<ecx>, int a2@<edi>)
{
  KeyValues *v3; // esi
  DmElementHandle_t m_handle; // eax
  int v5; // eax
  int v6; // edi
  KeyValues *v7; // eax
  char *v8; // eax
  BOOL v9; // edi
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > outputs; // [esp+8h] [ebp-1Ch] BYREF
  int bEnabled; // [esp+1Ch] [ebp-8h]
  unsigned int v13; // [esp+20h] [ebp-4h]

  this->m_pOutputList->RemoveAll(this: this->m_pOutputList);
  v3 = nullptr;
  this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: false);
  this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: false);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle) != nullptr )
  {
    m_handle = this->m_hMakefile.m_handle;
    memset(&outputs, 0, sizeof(outputs));
    v5 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
           a1: g_pDataModel,
           a2: m_handle,
           a3: a2);
    (*(void (__thiscall **)(int, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))(*(_DWORD *)v5 + 64))(
      a1: v5,
      a2: &outputs);
    v6 = 0;
    bEnabled = outputs.m_Size;
    if ( outputs.m_Size <= 0 )
      goto LABEL_11;
    v13 = 0;
    while ( 1 )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v3 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "type", firstValue: "Output");
      v8 = (char *)CUtlString::operator char const *(this: &outputs.m_Memory.m_pMemory[v13 / 0x10]);
      KeyValues::SetString(this: v3, keyName: "file", value: v8);
      KeyValues::SetInt(this: v3, keyName: "index", value: v6);
      this->m_pOutputList->AddItem(this: this->m_pOutputList, a2: v3, a3: 0, a4: false, a5: false);
      v13 += 16;
      if ( ++v6 >= bEnabled )
        break;
      v3 = nullptr;
    }
    if ( bEnabled > 0 && g_pDmeMakefileUtils != nullptr )
      LOBYTE(bEnabled) = 1;
    else
LABEL_11:
      LOBYTE(bEnabled) = 0;
    v9 = bEnabled;
    this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: bEnabled);
    this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: v9);
    this->m_pOutputList->SortList(this: this->m_pOutputList);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &outputs);
    m_pMemory = outputs.m_Memory.m_pMemory;
    if ( outputs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( outputs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        outputs.m_Memory.m_pMemory = nullptr;
      }
      outputs.m_Memory.m_nAllocationCount = 0;
    }
    outputs.m_pElements = m_pMemory;
    if ( outputs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047CC40
// Name: private: virtual void CAssetBuilder::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnPicked(CAssetBuilder *this, KeyValues *kv)
{
  char *String; // edi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmeMakefile *v7; // esi
  int v8; // ebx
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::FileOpenDialog *v11; // eax
  vgui::FileOpenDialog *v12; // edi
  IDataModel_vtbl *v13; // edi
  int BufferType; // eax
  char pContext[260]; // [esp+Ch] [ebp-214h] BYREF
  char pStartingDir[260]; // [esp+110h] [ebp-110h] BYREF
  vgui::Panel *parent; // [esp+214h] [ebp-Ch]
  CDisableUndoScopeGuard guard; // [esp+218h] [ebp-8h] BYREF

  parent = this;
  String = KeyValues::GetString(this: kv, keyName: "choice", defaultValue: &var);
  if ( KeyValues::FindKey(this: kv, keyName: "OnAddSource", bCreate: false) != nullptr )
  {
    CAssetBuilder::OnSourceFileAdded(this, pFileName: &var, pTypeName: String);
  }
  else
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    v5 = g_pDataModel->CreateElement(this: g_pDataModel, a2: String, a3: "unnamed", a4: DMFILEID_INVALID, a5: nullptr);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
    v7 = (CDmeMakefile *)v6;
    if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeMakefile::m_classType) )
    {
      v8 = (int)v7->GetMakefileType(this: v7);
      V_snprintf(pDest: pContext, maxLen: 0x104u, pFormat: "asset_builder_session_%s", *(const char **)v8);
      CDmeMakefile::GetDefaultDirectory(
        this: v7,
        pDefaultDirectoryID: *(const char **)(v8 + 12),
        pFullPath: pStartingDir,
        nBufLen: 260);
      g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(
                this: v9,
                setName: "NewSourceFileSelected",
                firstKey: "makefileType",
                firstValue: String);
      else
        v10 = nullptr;
      v11 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
      if ( v11 != nullptr )
        v12 = vgui::FileOpenDialog::FileOpenDialog(
                this: v11,
                parent,
                title: "Select Asset Builder File Name",
                bOpenOnly: false,
                pContextKeyValues: v10);
      else
        v12 = nullptr;
      vgui::FileOpenDialog::SetStartDirectoryContext(this: v12, pStartDirContext: pContext, pDefaultDir: pStartingDir);
      vgui::FileOpenDialog::AddFilter(
        this: v12,
        filter: *(char **)(v8 + 16),
        filterName: *(const char **)(v8 + 20),
        bActive: true,
        pFilterInfo: nullptr);
      v12->AddActionSignalTarget_2(this: v12, a2: parent);
      vgui::FileOpenDialog::DoModal(this: v12, bUnused: false);
      v13 = g_pDataModel->__vftable;
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
      v13->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047CE20
// Name: public: void CAssetBuilder::SetCurrentMakefile(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SetCurrentMakefile(CAssetBuilder *this, CDmeMakefile *pMakeFile)
{
  DmElementHandle_t BufferType; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( pMakeFile != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pMakeFile);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hMakefile, h: BufferType);
  CDmePanel::SetDmeElement(
    this: this->m_pDmePanel,
    a2: (int)pMakeFile,
    pDmeElement: nullptr,
    bForce: false,
    pPanelName: nullptr);
  CDmePanel::SetDmeElement(
    this: this->m_pOututPreviewPanel,
    a2: (int)pMakeFile,
    pDmeElement: pMakeFile,
    bForce: true,
    pPanelName: "DmeMakeFileOutputPreview");
  CAssetBuilder::RefreshSourceList(this, a2: (char *)pMakeFile, a3: (int)this);
  CAssetBuilder::RefreshOutputList(this, a2: (int)pMakeFile);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "UpdateFileName");
    this->PostActionSignal(this, a2: v5);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047CEC0
// Name: private: virtual void CAssetBuilder::OnZoomInSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnZoomInSource(CAssetBuilder *this)
{
  CDmeSource *SelectedSource; // esi
  CDmeMakefile *v3; // eax
  CExpressionCalculator *DependentMakefile; // eax
  CDmeMakefile *v5; // edi
  DmElementHandle_t BufferType; // esi
  CDmElement *v7; // eax
  CDmeHandle<CDmeMakefile,0> *m_pMemory; // eax
  CDmeHandle<CDmeMakefile,0> *v9; // ecx
  CDmeHandle<CDmeMakefile,0> hChild; // [esp+Ch] [ebp-4h] BYREF

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
  {
    v3 = (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMakefile.m_handle);
    DependentMakefile = (CExpressionCalculator *)CDmeMakefile::FindDependentMakefile(this: v3, pSource: SelectedSource);
    v5 = (CDmeMakefile *)DependentMakefile;
    if ( DependentMakefile != nullptr )
    {
      hChild.m_handle = DMELEMENT_HANDLE_INVALID;
      BufferType = CCodecBuffer_Block::GetBufferType(this: DependentMakefile);
      if ( BufferType != DMELEMENT_HANDLE_INVALID )
      {
        CDmeElementRefHelper::Unref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
        hChild.m_handle = BufferType;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
        if ( v7 != nullptr && !v7->IsA(this: v7, a2: CDmeMakefile::m_classType) )
          hChild.m_handle = DMELEMENT_HANDLE_INVALID;
        CDmeElementRefHelper::Ref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
      }
      if ( this->m_hMakefileStack.m_Size >= this->m_hMakefileStack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hMakefileStack,
          num: 1);
      ++this->m_hMakefileStack.m_Size;
      m_pMemory = this->m_hMakefileStack.m_Memory.m_pMemory;
      v9 = &m_pMemory[this->m_hMakefileStack.m_Size - 1];
      this->m_hMakefileStack.m_pElements = m_pMemory;
      if ( v9 != nullptr )
      {
        v9->m_handle = DMELEMENT_HANDLE_INVALID;
        CDmeHandle<CDmeMakefile,0>::Set(this: v9, h: hChild.m_handle);
      }
      CAssetBuilder::SetCurrentMakefile(this, pMakeFile: v5);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047CFE0
// Name: private: virtual void CAssetBuilder::OnZoomOutSource(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::OnZoomOutSource(CAssetBuilder *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CDmeMakefile *v4; // ebx
  CDmeElementRefHelper *v5; // ecx
  CDmeMakefile *v6; // eax
  CDmeMakefile *v7; // edi
  CDmeSource *AssociatedSource; // eax

  if ( this->m_hMakefileStack.m_Size > 1 )
  {
    v4 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
                           a1: g_pDataModel,
                           a2: this->m_hMakefileStack.m_Memory.m_pMemory[this->m_hMakefileStack.m_Size - 1].m_handle,
                           a3: a2);
    if ( g_pDataModel != nullptr )
    {
      v5 = &this->m_hMakefileStack.m_Memory.m_pMemory[this->m_hMakefileStack.m_Size - 1];
      CDmeElementRefHelper::Unref(this: v5, hElement: *(_DWORD *)v5, handleType: HT_WEAK);
    }
    v6 = (CDmeMakefile *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
                           a1: g_pDataModel,
                           a2: this->m_hMakefileStack.m_Memory.m_pMemory[--this->m_hMakefileStack.m_Size - 1].m_handle,
                           a3);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CAssetBuilder::SetCurrentMakefile(this, pMakeFile: v6);
      AssociatedSource = CDmeMakefile::FindAssociatedSource(this: v7, pChildMakefile: v4);
      if ( AssociatedSource != nullptr )
        CAssetBuilder::SelectSource(this, pSource: AssociatedSource);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D090
// Name: public: void CAssetBuilder::SetRootMakefile(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SetRootMakefile(CAssetBuilder *this, CDmeMakefile *pMakeFile)
{
  DmElementHandle_t BufferType; // eax
  CDmeHandle<CDmeMakefile,0> *m_pMemory; // eax
  CDmeHandle<CDmeMakefile,0> *v5; // ecx

  CAssetBuilder::CleanupMakefile(this);
  if ( pMakeFile != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pMakeFile);
    CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: BufferType);
    if ( this->m_hMakefileStack.m_Size >= this->m_hMakefileStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hMakefileStack,
        num: 1);
    ++this->m_hMakefileStack.m_Size;
    m_pMemory = this->m_hMakefileStack.m_Memory.m_pMemory;
    v5 = &m_pMemory[this->m_hMakefileStack.m_Size - 1];
    this->m_hMakefileStack.m_pElements = m_pMemory;
    if ( v5 != nullptr )
    {
      v5->m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmeMakefile,0>::Set(this: v5, h: this->m_hRootMakefile.m_handle);
    }
  }
  CAssetBuilder::SetCurrentMakefile(this, pMakeFile);
}

//------------------------------------------------------------------------------
// Address: 0x1047D120
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CAssetBuilder,class CDmeMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetBuilder *__thiscall CDmePanelFactory<CAssetBuilder,CDmeMakefile>::CreateDmePanel(
        CDmePanelFactory<CAssetBuilder,CDmeMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeMakefile *pElement)
{
  CDmeMakefile *v4; // esi
  CAssetBuilder *v5; // eax
  CAssetBuilder *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CAssetBuilder *)operator new(nSize: 0x1F0u);
  if ( v5 != nullptr )
  {
    v6 = CAssetBuilder::CAssetBuilder(this: v5, pParent, pPanelName);
    CAssetBuilder::SetRootMakefile(this: v6, pMakeFile: v4);
    return v6;
  }
  else
  {
    CAssetBuilder::SetRootMakefile(this: nullptr, pMakeFile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D190
// Name: public: virtual void CDmePanelFactory<class CAssetBuilder,class CDmeMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CAssetBuilder,CDmeMakefile>::SetDmeElement(
        CDmePanelFactory<CAssetBuilder,CDmeMakefile> *this,
        CAssetBuilder *pPanel,
        CDmeMakefile *pElement)
{
  CAssetBuilder::SetRootMakefile(this: pPanel, pMakeFile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x1047DD80
// Name: public: virtual void CDmePanelFactory<class CDmeSourceDCCFilePanel,class CDmeSourceDCCFile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::SetDmeElement(
        CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile> *this,
        CDmeSourceDCCFilePanel *pPanel,
        CDmeSourceDCCFile *pElement)
{
  CDmeSourceDCCFilePanel::SetDmeElement(this: pPanel, pSourceDCCFile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x1047E450
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeSourceDCCFilePanel,class CDmeSourceDCCFile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceDCCFilePanel *__thiscall CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::CreateDmePanel(
        CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceDCCFile *pElement)
{
  CDmeSourceDCCFile *v4; // esi
  CDmeSourceDCCFilePanel *v5; // eax
  CDmeSourceDCCFilePanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceDCCFile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeSourceDCCFilePanel *)operator new(nSize: 0x1A0u);
  if ( v5 != nullptr )
  {
    v6 = CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(this: v5, pParent, pPanelName);
    CDmeSourceDCCFilePanel::SetDmeElement(this: v6, pSourceDCCFile: v4);
    return v6;
  }
  else
  {
    CDmeSourceDCCFilePanel::SetDmeElement(this: nullptr, pSourceDCCFile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047F8B0
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDag>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDag> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeDag *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pScene: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x10480EE0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDag>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDag> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDag *pElement)
{
  CDmeDag *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)operator new(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pScene: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pScene: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10480F50
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)operator new(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pSkin: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pSkin: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10480FC0
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pSkin: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x104812A0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceAnimation>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceAnimation *pElement)
{
  CDmeSourceAnimation *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceAnimation::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)operator new(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pAnimation: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pAnimation: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481310
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceAnimation>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeSourceAnimation *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pAnimation: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x10481330
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDCCMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDCCMakefile *pElement)
{
  CDmeDCCMakefile *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDCCMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)operator new(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pDCCMakefile: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pDCCMakefile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104813A0
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDCCMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeDCCMakefile *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pDCCMakefile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x104816B0
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeDag>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDag> *this,
        vgui::EditablePanel *pPanel,
        CDmElement *pElement)
{
  ((void (__thiscall *)(vgui::EditablePanel *, CDmElement *))pPanel->__vftable[1].GetVPanel)(a1: pPanel, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x10484140
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeDag>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDag> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CDmElement *v4; // esi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)operator new(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  v6->SetDmeElement(this: v6, a2: (CDmeDag *)v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10484790
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // edi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // esi
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = pElement;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)operator new(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  CDmeDagRenderPanel::SetDmeElement(this: v6->m_pDagRenderPanel, pSkin: v4);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: v4);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: v6, pRoot: OutputElement);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10484820
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin> *this,
        CDmeDagEditPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  CDmeDagRenderPanel::SetDmeElement(this: pPanel->m_pDagRenderPanel, pSkin: pElement);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: pElement);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: pPanel, pRoot: OutputElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10484860
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceAnimation>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceAnimation *pElement)
{
  CDmeSourceAnimation *v4; // edi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // esi
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSourceAnimation::m_classType.u.m_Id) )
  {
    v4 = pElement;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)operator new(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  CDmeDagRenderPanel::SetDmeElement(this: v6->m_pDagRenderPanel, pAnimation: v4);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: v4);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: v6, pRoot: OutputElement);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x104848F0
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceAnimation>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation> *this,
        CDmeDagEditPanel *pPanel,
        CDmeSourceAnimation *pElement)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  CDmeDagRenderPanel::SetDmeElement(this: pPanel->m_pDagRenderPanel, pAnimation: pElement);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: pElement);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: pPanel, pRoot: OutputElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10484930
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeDCCMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDCCMakefile *pElement)
{
  CDmeDCCMakefile *v4; // esi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDCCMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)operator new(nSize: 0x1A8u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagEditPanel::SetDmeElement(this: v6, pDCCMakefile: v4);
    return v6;
  }
  else
  {
    CDmeDagEditPanel::SetDmeElement(this: nullptr, pDCCMakefile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104849A0
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeDCCMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile> *this,
        CDmeDagEditPanel *pPanel,
        CDmeDCCMakefile *pElement)
{
  CDmeDagEditPanel::SetDmeElement(this: pPanel, pDCCMakefile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x10484B30
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeMDLPanel,class CDmeMDLMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMDLPanel *__thiscall CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeMakefile *pElement)
{
  CDmeMakefile *v4; // esi
  CDmeMDLPanel *v5; // eax
  CDmeMDLPanel *v6; // edi
  CDmElement *OutputElement; // eax
  CDmeMDL *v8; // esi
  CDmeMDLPanel_vtbl *v9; // ebx
  unsigned __int16 MDL; // ax

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeMDLMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeMDLPanel *)operator new(nSize: 0xBE8u);
  if ( v5 != nullptr )
    v6 = CDmeMDLPanel::CDmeMDLPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  if ( v4 != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: v4, bCreateIfNecessary: true);
    v8 = (CDmeMDL *)OutputElement;
    if ( OutputElement != nullptr && OutputElement->IsA(this: OutputElement, a2: CDmeMDL::m_classType) )
    {
      v9 = v6->__vftable;
      MDL = CDmeMDL::GetMDL(this: v8);
      v9->SetMDL_2(this: v6, a2: MDL, a3: nullptr);
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10484BD0
// Name: public: virtual void CDmePanelFactory<class CDmeMDLPanel,class CDmeMDLMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile> *this,
        vgui::EditablePanel *pPanel,
        CDmeMakefile *pElement)
{
  CDmElement *OutputElement; // eax
  CDmeMDL *v4; // esi
  vgui::EditablePanel_vtbl *v5; // edi
  unsigned __int16 MDL; // ax

  if ( pElement != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: pElement, bCreateIfNecessary: true);
    v4 = (CDmeMDL *)OutputElement;
    if ( OutputElement != nullptr && OutputElement->IsA(this: OutputElement, a2: CDmeMDL::m_classType) )
    {
      v5 = pPanel->__vftable;
      MDL = CDmeMDL::GetMDL(this: v4);
      ((void (__thiscall *)(vgui::EditablePanel *, _DWORD, _DWORD))v5[1].Repaint)(a1: pPanel, a2: MDL, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479F20
// Name: class CDmeSource __near * GetElementKeyValue<class CDmeSource>(class KeyValues __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *__cdecl GetElementKeyValue<CDmeSource>(KeyValues *pKeyValues, const char *pName)
{
  DmElementHandle_t Int; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: pName, defaultValue: -1);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v4;
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00454CD0
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeDag>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDag> *this,
        vgui::EditablePanel *pPanel,
        CDmElement *pElement)
{
  ((void (__thiscall *)(vgui::EditablePanel *, CDmElement *))pPanel->__vftable[1].GetVPanel)(a1: pPanel, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00457910
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeDag>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDag> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CDmElement *v4; // esi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  v6->SetDmeElement(this: v6, a2: (CDmeDag *)v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00457F60
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // edi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // esi
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = pElement;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  CDmeDagRenderPanel::SetDmeElement(this: v6->m_pDagRenderPanel, pSkin: v4);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: v4);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: v6, pRoot: OutputElement);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00457FF0
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin> *this,
        CDmeDagEditPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  CDmeDagRenderPanel::SetDmeElement(this: pPanel->m_pDagRenderPanel, pSkin: pElement);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: pElement);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: pPanel, pRoot: OutputElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458030
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceAnimation>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceAnimation *pElement)
{
  CDmeSourceAnimation *v4; // edi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // esi
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSourceAnimation::m_classType.u.m_Id) )
  {
    v4 = pElement;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  CDmeDagRenderPanel::SetDmeElement(this: v6->m_pDagRenderPanel, pAnimation: v4);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: v4);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: v6, pRoot: OutputElement);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004580C0
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeSourceAnimation>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation> *this,
        CDmeDagEditPanel *pPanel,
        CDmeSourceAnimation *pElement)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax

  CDmeDagRenderPanel::SetDmeElement(this: pPanel->m_pDagRenderPanel, pAnimation: pElement);
  DependentMakefile = CDmeSource::GetDependentMakefile(this: pElement);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    if ( OutputElement != nullptr )
      CDmeDagEditPanel::SetMakefileRootElement(this: pPanel, pRoot: OutputElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458100
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagEditPanel,class CDmeDCCMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDCCMakefile *pElement)
{
  CDmeDCCMakefile *v4; // esi
  CDmeDagEditPanel *v5; // eax
  CDmeDagEditPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDCCMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagEditPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagEditPanel::CDmeDagEditPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagEditPanel::SetDmeElement(this: v6, pDCCMakefile: v4);
    return v6;
  }
  else
  {
    CDmeDagEditPanel::SetDmeElement(this: nullptr, pDCCMakefile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458170
// Name: public: virtual void CDmePanelFactory<class CDmeDagEditPanel,class CDmeDCCMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile> *this,
        CDmeDagEditPanel *pPanel,
        CDmeDCCMakefile *pElement)
{
  CDmeDagEditPanel::SetDmeElement(this: pPanel, pDCCMakefile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x004596C0
// Name: public: virtual void CDmePanelFactory<class CDmeElementPanel,class CDmElement>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeElementPanel,CDmElement>::SetDmeElement(
        CDmePanelFactory<CDmeElementPanel,CDmElement> *this,
        vgui::EditablePanel *pPanel,
        KeyValues *pElement)
{
  pPanel->__vftable[1].RequestInfo(this: pPanel, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0046C110
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeElementPanel,class CDmElement>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeElementPanel *__thiscall CDmePanelFactory<CDmeElementPanel,CDmElement>::CreateDmePanel(
        CDmePanelFactory<CDmeElementPanel,CDmElement> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CDmElement *v4; // esi
  CDmeElementPanel *v5; // eax
  CDmeElementPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeElementPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
  if ( v5 != nullptr )
    v6 = CDmeElementPanel::CDmeElementPanel(this: v5, pParent, pPanelName);
  else
    v6 = nullptr;
  v6->SetObject(this: v6, a2: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00473340
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeCombinationSystemEditorPanel,class CDmeCombinationOperator>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationSystemEditorPanel *__thiscall CDmePanelFactory<CDmeCombinationSystemEditorPanel,CDmeCombinationOperator>::CreateDmePanel(
        CDmePanelFactory<CDmeCombinationSystemEditorPanel,CDmeCombinationOperator> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CDmeCombinationOperator *v4; // edi
  CDmeCombinationSystemEditorPanel *v5; // eax
  CDmeCombinationSystemEditorPanel *v6; // esi

  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeCombinationOperator::m_classType.u.m_Id) )
  {
    v4 = (CDmeCombinationOperator *)((char *)&pElement[-1] + 64);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (CDmeCombinationSystemEditorPanel *)MemAlloc_Alloc(nSize: 0x1A0u);
  if ( v5 != nullptr )
    v6 = CDmeCombinationSystemEditorPanel::CDmeCombinationSystemEditorPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  CDmeCombinationControlsPanel::SetCombinationOperator(this: v6->m_pControlsPanel, pOp: v4);
  CDmeCombinationDominationRulesPanel::SetCombinationOperator(this: v6->m_pDominationRulesPanel, pOp: v4);
  if ( v4 != nullptr )
    CDmeElementPanel::SetDmeElement(this: v6->m_pPropertiesPanel, pElement: &v4->CDmElement);
  else
    CDmeElementPanel::SetDmeElement(this: v6->m_pPropertiesPanel, pElement: nullptr);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004733E0
// Name: public: virtual void CDmePanelFactory<class CDmeCombinationSystemEditorPanel,class CDmeCombinationOperator>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeCombinationSystemEditorPanel,CDmeCombinationOperator>::SetDmeElement(
        CDmePanelFactory<CDmeCombinationSystemEditorPanel,CDmeCombinationOperator> *this,
        vgui::EditablePanel *pPanel,
        CDmElement *pElement)
{
  CDmeCombinationOperator *v3; // esi

  if ( pElement != nullptr )
    v3 = (CDmeCombinationOperator *)((char *)&pElement[-1] + 64);
  else
    v3 = nullptr;
  CDmeCombinationControlsPanel::SetCombinationOperator(
    this: *(CDmeCombinationControlsPanel **)&pPanel[1].m_InternalCursorMoved_register,
    pOp: v3);
  CDmeCombinationDominationRulesPanel::SetCombinationOperator(
    this: *(CDmeCombinationDominationRulesPanel **)&pPanel[1].m_InternalMouseDoublePressed_register,
    pOp: v3);
  if ( v3 != nullptr )
    CDmeElementPanel::SetDmeElement(
      this: *(CDmeElementPanel **)&pPanel[1].m_InternalKeyCodePressed_register,
      pElement: &v3->CDmElement);
  else
    CDmeElementPanel::SetDmeElement(
      this: *(CDmeElementPanel **)&pPanel[1].m_InternalKeyCodePressed_register,
      pElement: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00473440
// Name: public: static char const __near * CAssetBuilder::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetBuilder::GetPanelClassName()
{
  return "CAssetBuilder";
}

//------------------------------------------------------------------------------
// Address: 0x00473450
// Name: public: static char const __near * CAssetBuilderFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetBuilderFrame::GetPanelClassName()
{
  return "CAssetBuilderFrame";
}

//------------------------------------------------------------------------------
// Address: 0x00473460
// Name: public: static char const __near * CCompileStatusBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCompileStatusBar::GetPanelClassName()
{
  return "CCompileStatusBar";
}

//------------------------------------------------------------------------------
// Address: 0x00473470
// Name: public: virtual void CCompileStatusBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCompileStatusBar::PaintBackground(CCompileStatusBar *this)
{
  FontVertex_t verts[4]; // [esp+4h] [ebp-4Ch] BYREF
  float du; // [esp+44h] [ebp-Ch]
  int h; // [esp+48h] [ebp-8h] BYREF
  int w; // [esp+4Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  switch ( this->m_Status )
  {
    case CURRENTLY_COMPILING:
      du = _Plat_FloatTime() * 0.2;
      verts[0].m_Position.x = 0.0;
      verts[0].m_Position.y = 0.0;
      verts[0].m_TexCoord.x = 1.0 - (float)(du - (float)(int)du);
      verts[0].m_TexCoord.y = 0.0;
      verts[1].m_Position.x = (float)w;
      verts[1].m_Position.y = 0.0;
      verts[1].m_TexCoord.x = verts[0].m_TexCoord.x + 1.0;
      verts[1].m_TexCoord.y = 0.0;
      verts[2].m_Position.x = (float)w;
      verts[2].m_Position.y = (float)h;
      verts[2].m_TexCoord.x = verts[0].m_TexCoord.x + 1.0;
      verts[2].m_TexCoord.y = 1.0;
      verts[3].m_Position.x = 0.0;
      verts[3].m_Position.y = (float)h;
      verts[3].m_TexCoord.x = verts[0].m_TexCoord.x;
      verts[3].m_TexCoord.y = 1.0;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_CompilingId);
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      break;
    case COMPILATION_FAILED:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
      break;
    case COMPILATION_SUCCESSFUL:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 255, a4: 0, a5: 255);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473600
// Name: OverwriteFileDialog
// Source: json
//------------------------------------------------------------------------------
void __usercall OverwriteFileDialog(
        vgui::Panel *pActionTarget@<edi>,
        const char *pFileName@<eax>,
        KeyValues *pOkCommand)
{
  vgui::Panel_vtbl *v4; // esi
  int v5; // eax
  vgui::MessageBox *v6; // eax
  vgui::MessageBox *v7; // esi
  char pBuf[1024]; // [esp+14h] [ebp-400h] BYREF

  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: nullptr) )
  {
    V_snprintf(pDest: pBuf, maxLen: 1024, pFormat: "File already exists. Overwrite it?\n\n\"%s\"\n", pFileName);
    v6 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v6 != nullptr )
      v7 = vgui::MessageBox::MessageBox(this: v6, title: "Overwrite Existing File?", text: pBuf, parent: pActionTarget);
    else
      v7 = nullptr;
    v7->AddActionSignalTarget_2(this: v7, a2: pActionTarget);
    v7->SetOKButtonVisible(this: v7, a2: true);
    v7->SetOKButtonText_2(this: v7, a2: "Yes");
    vgui::MessageBox::SetCancelButtonVisible(this: v7, state: true);
    vgui::MessageBox::SetCancelButtonText(this: v7, buttonText: "No");
    v7->SetCloseButtonVisible(this: v7, a2: false);
    v7->SetCommand(this: v7, a2: pOkCommand);
    v7->DoModal_2(this: v7, a2: nullptr);
  }
  else
  {
    v4 = pActionTarget->__vftable;
    v5 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))pActionTarget->GetVPanel)(
           a1: pActionTarget,
           a2: pOkCommand,
           a3: 0);
    ((void (__thiscall *)(vgui::Panel *, int))v4->PostMessage_2)(a1: pActionTarget, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473700
// Name: TypeSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl TypeSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  const char *String; // ebx
  const char *v4; // eax
  int result; // eax
  const char *v6; // ebx
  const char *v7; // eax
  int Int; // esi

  String = KeyValues::GetString(this: item1->kv, keyName: "type", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "type", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "file", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "file", defaultValue: defaultValue);
    result = _V_stricmp(s1: v6, s2: v7);
    if ( result == 0 )
    {
      Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
      return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004737A0
// Name: FileSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  const char *String; // ebx
  const char *v4; // eax
  int result; // eax
  const char *v6; // ebx
  const char *v7; // eax
  int Int; // esi

  String = KeyValues::GetString(this: item1->kv, keyName: "file", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "file", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "type", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "type", defaultValue: defaultValue);
    result = _V_stricmp(s1: v6, s2: v7);
    if ( result == 0 )
    {
      Int = KeyValues::GetInt(this: item1->kv, keyName: "index", defaultValue: 0);
      return Int - KeyValues::GetInt(this: item2->kv, keyName: "index", defaultValue: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473840
// Name: public: virtual void CAssetBuilder::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnKeyCodeTyped(CAssetBuilder *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE )
  {
    this->OnRemoveSource(this);
  }
  else if ( code == KEY_ENTER )
  {
    this->OnZoomInSource(this);
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473880
// Name: private: void CAssetBuilder::OnAbortCompile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnAbortCompile(CAssetBuilder *this)
{
  vgui::Button *m_pAbortCompile; // ecx
  CCompileStatusBar *m_pCompileStatusBar; // esi
  vgui::Label *m_pStatus; // ecx

  if ( (*((_BYTE *)this + 492) & 1) != 0 )
  {
    g_pDmeMakefileUtils->AbortCurrentCompilation(this: g_pDmeMakefileUtils);
    m_pAbortCompile = this->m_pAbortCompile;
    *((_BYTE *)this + 492) &= ~1u;
    m_pAbortCompile->SetEnabled(this: m_pAbortCompile, a2: false);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pStatus = m_pCompileStatusBar->m_pStatus;
    m_pCompileStatusBar->m_Status = COMPILATION_FAILED;
    m_pStatus->SetText_2(this: m_pStatus, a2: "Compile Aborted");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004738E0
// Name: private: virtual void CAssetBuilderFrame::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::OnFileSelected(CAssetBuilderFrame *this, KeyValues *kv)
{
  const char *String; // ebx
  KeyValues *Key; // esi
  KeyValues *v4; // edi
  const char *v5; // eax
  KeyValues *v6; // esi

  String = KeyValues::GetString(this: kv, keyName: "fullpath", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Key = KeyValues::FindKey(this: kv, keyName: "OnFileNew", bCreate: false);
    if ( Key != nullptr )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::GetString(this: Key, keyName: "makefileType", defaultValue: defaultValue);
        v6 = KeyValues::KeyValues(this: v4, setName: "PerformFileNew", firstKey: "makefileType", firstValue: v5);
      }
      else
      {
        v6 = nullptr;
      }
      KeyValues::SetString(this: v6, keyName: "fileName", value: String);
      OverwriteFileDialog(pActionTarget: this, pFileName: String, pOkCommand: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473A90
// Name: public: virtual struct vgui::PanelMessageMap __near * CCompileStatusBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCompileStatusBar::GetMessageMap(CCompileStatusBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCompileStatusBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCompileStatusBar::GetMessageMap'::`2'::s_pMap;
  `CCompileStatusBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCompileStatusBar");
  `CCompileStatusBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473AD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCompileStatusBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCompileStatusBar::GetKBMap(CCompileStatusBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCompileStatusBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCompileStatusBar::GetKBMap'::`2'::s_pMap;
  `CCompileStatusBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCompileStatusBar");
  `CCompileStatusBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473CE0
// Name: private: void CAssetBuilder::ShowSourceFileBrowser(char const __near *,struct DmeMakefileType_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::ShowSourceFileBrowser(
        CAssetBuilder *this,
        const char *pTitle,
        DmeMakefileType_t *pSourceType,
        KeyValues *pDialogKeys)
{
  CDmeMakefile *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // esi
  char pContext[260]; // [esp+Ch] [ebp-208h] BYREF
  char pStartingDir[260]; // [esp+110h] [ebp-104h] BYREF

  V_snprintf(pDest: pContext, maxLen: 260, pFormat: "asset_builder_session_%s", pSourceType->m_pTypeName);
  v5 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hMakefile.m_handle);
  CDmeMakefile::GetDefaultDirectory(
    this: v5,
    pDefaultDirectoryID: pSourceType->m_pDefaultDirectoryID,
    pFullPath: pStartingDir,
    nBufLen: 260);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
  v6 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
  if ( v6 != nullptr )
    v7 = vgui::FileOpenDialog::FileOpenDialog(
           this: v6,
           parent: this,
           title: pTitle,
           bOpenOnly: true,
           pContextKeyValues: pDialogKeys);
  else
    v7 = nullptr;
  vgui::FileOpenDialog::SetStartDirectoryContext(this: v7, pStartDirContext: pContext, pDefaultDir: pStartingDir);
  vgui::FileOpenDialog::AddFilter(
    this: v7,
    filter: pSourceType->m_pFileFilter,
    filterName: pSourceType->m_pFileFilterString,
    bActive: true,
    pFilterInfo: nullptr);
  v7->AddActionSignalTarget_2(this: v7, a2: this);
  vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x00473DC0
// Name: private: class KeyValues __near * CAssetBuilder::GetSelectedSourceKeyvalues(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CAssetBuilder::GetSelectedSourceKeyvalues(CAssetBuilder *this)
{
  int v2; // eax

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) != 1
    || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) == 0 )
  {
    return nullptr;
  }
  v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
  return this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00473E20
// Name: private: void CAssetBuilder::OnCompile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnCompile(CAssetBuilder *this)
{
  CDmElement *v2; // eax
  vgui::Button *m_pAbortCompile; // ecx
  CCompileStatusBar *m_pCompileStatusBar; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebx
  int v7; // eax

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0 )
  {
    CAssetBuilder::OnAbortCompile(this);
    this->m_pCompileOutput->SetText(this: this->m_pCompileOutput, a2: defaultValue);
    v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hMakefile.m_handle);
    g_pDmeMakefileUtils->PerformCompile(this: g_pDmeMakefileUtils, a2: v2, a3: false);
    m_pAbortCompile = this->m_pAbortCompile;
    *((_BYTE *)this + 492) |= 1u;
    m_pAbortCompile->SetEnabled(this: m_pAbortCompile, a2: true);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pCompileStatusBar->m_Status = CURRENTLY_COMPILING;
    m_pCompileStatusBar->m_pStatus->SetText_2(this: m_pCompileStatusBar->m_pStatus, a2: "Compiling...");
    v5 = g_pVGui;
    v6 = g_pVGui->__vftable;
    v7 = ((int (__thiscall *)(CAssetBuilder *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v6->AddTickSignal)(a1: v5, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473EE0
// Name: private: virtual void CAssetBuilderFrame::UpdateFileName(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilderFrame::UpdateFileName(CAssetBuilderFrame *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  int v4; // esi
  CAssetBuilderFrame_vtbl *v5; // esi
  char *v6; // eax
  const char *v7; // eax
  const char *v8; // edi
  bool v9; // zf
  const char *v10; // eax
  const char *v11; // eax
  const char *m_pHumanReadableName; // [esp-Ch] [ebp-220h]
  const char *v13; // [esp-4h] [ebp-218h]
  char pBuf[520]; // [esp+8h] [ebp-20Ch] BYREF
  DmeMakefileType_t *pMakefileType; // [esp+210h] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_pAssetBuilder->m_hMakefile.m_handle);
  v4 = v3;
  if ( v3 != 0 )
  {
    pMakefileType = (DmeMakefileType_t *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 56))(a1: v3, a2);
    if ( *(_DWORD *)(v4 + 56) == -1
      || (v7 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 364))(
                               a1: g_pDataModel.u,
                               a2: *(_DWORD *)(v4 + 56)),
          v8 = v7,
          v7 == nullptr)
      || *v7 == 0 )
    {
      v8 = "<unnamed>";
    }
    v9 = CUtlString::Get(this: &this->m_TitleString) == nullptr;
    v10 = " *";
    if ( v9 )
    {
      V_snprintf(pDest: pBuf, maxLen: 520, pFormat: "%s - s%s", pMakefileType->m_pHumanReadableName, v8);
    }
    else
    {
      if ( *(_BYTE *)(v4 + 104) == 0 )
        v10 = defaultValue;
      v13 = v10;
      m_pHumanReadableName = pMakefileType->m_pHumanReadableName;
      v11 = CUtlString::Get(this: &this->m_TitleString);
      V_snprintf(pDest: pBuf, maxLen: 520, pFormat: "%s - %s - %s%s", v11, m_pHumanReadableName, v8, v13);
    }
    ((void (__thiscall *)(CAssetBuilderFrame *, char *))this->SetTitle_2)(a1: this, a2: pBuf);
  }
  else
  {
    v5 = this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
    v6 = CUtlString::Get(this: &this->m_TitleString);
    v5->SetTitle_2(this, a2: v6, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474000
// Name: private: void CAssetBuilderFrame::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::SetDirty(CAssetBuilderFrame *this, bool bDirty)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_pAssetBuilder->m_hMakefile.m_handle);
  if ( v3 != 0 && *(_BYTE *)(v3 + 104) != bDirty )
  {
    *(_BYTE *)(v3 + 104) = bDirty;
    this->UpdateFileName(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474040
// Name: private: virtual void CAssetBuilderFrame::OnDmeElementChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::OnDmeElementChanged(CAssetBuilderFrame *this)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_pAssetBuilder->m_hMakefile.m_handle);
  if ( v2 != 0 && *(_BYTE *)(v2 + 104) != 1 )
  {
    *(_BYTE *)(v2 + 104) = 1;
    this->UpdateFileName(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474080
// Name: private: virtual void CAssetBuilderFrame::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::OnPicked(CAssetBuilderFrame *this, KeyValues *kv)
{
  const char *String; // edi
  unsigned __int8 (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  int v4; // eax
  int v5; // eax
  CDmeMakefile *v6; // esi
  const char **v7; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::FileOpenDialog *v10; // eax
  vgui::FileOpenDialog *v11; // edi
  int v12; // edi
  int BufferType; // eax
  char pContext[260]; // [esp+Ch] [ebp-318h] BYREF
  char pTitle[260]; // [esp+110h] [ebp-214h] BYREF
  char pStartingDir[260]; // [esp+214h] [ebp-110h] BYREF
  CDisableUndoScopeGuard guard; // [esp+318h] [ebp-Ch] BYREF
  vgui::Panel *parent; // [esp+320h] [ebp-4h]

  parent = this;
  String = KeyValues::GetString(this: kv, keyName: "choice", defaultValue: defaultValue);
  v3 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v3)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: String,
         a3: "unnamed",
         a4: -1,
         a5: 0);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v4);
  v6 = (CDmeMakefile *)v5;
  if ( v5 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeMakefile::m_classType.u) != 0 )
  {
    v7 = (const char **)v6->GetMakefileType(this: v6);
    V_snprintf(pDest: pContext, maxLen: 260, pFormat: "asset_builder_session_%s", *v7);
    CDmeMakefile::GetDefaultDirectory(this: v6, pDefaultDirectoryID: v7[3], pFullPath: pStartingDir, nBufLen: 260);
    g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
    V_snprintf(pDest: pTitle, maxLen: 260, pFormat: "Select %s File Name", v7[1]);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "OnFileNew", firstKey: "makefileType", firstValue: String);
    else
      v9 = nullptr;
    v10 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v10 != nullptr )
      v11 = vgui::FileOpenDialog::FileOpenDialog(
              this: v10,
              parent,
              title: pTitle,
              bOpenOnly: false,
              pContextKeyValues: v9);
    else
      v11 = nullptr;
    vgui::FileOpenDialog::SetStartDirectoryContext(this: v11, pStartDirContext: pContext, pDefaultDir: pStartingDir);
    vgui::FileOpenDialog::AddFilter(this: v11, filter: v7[4], filterName: v7[5], bActive: true, pFilterInfo: nullptr);
    v11->AddActionSignalTarget_2(this: v11, a2: parent);
    vgui::FileOpenDialog::DoModal(this: v11, bUnused: false);
    v12 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v12 + 68))(a1: g_pDataModel.u, a2: BufferType);
  }
  CChangeUndoScopeGuard::Release(this: &guard);
}

//------------------------------------------------------------------------------
// Address: 0x004742D0
// Name: private: virtual void CAssetBuilderFrame::OnFileSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::OnFileSave(CAssetBuilderFrame *this)
{
  int v2; // edi
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  const char *v5; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_pAssetBuilder->m_hMakefile.m_handle);
  if ( v2 != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "FileSave");
    else
      v4 = nullptr;
    v5 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 364))(
                         a1: g_pDataModel.u,
                         a2: *(_DWORD *)(v2 + 56));
    vgui::FileOpenStateMachine::SaveFile(
      this: this->m_pFileOpenStateMachine,
      pContextKeyValues: v4,
      pFileName: v5,
      pFileType: "model",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474350
// Name: private: virtual void CAssetBuilderFrame::OnFileSaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::OnFileSaveAs(CAssetBuilderFrame *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_pAssetBuilder->m_hMakefile.m_handle) != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "FileSave");
    else
      v3 = nullptr;
    vgui::FileOpenStateMachine::SaveFile(
      this: this->m_pFileOpenStateMachine,
      pContextKeyValues: v3,
      pFileName: nullptr,
      pFileType: "model",
      nFlags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004743B0
// Name: private: virtual void CAssetBuilder::OnBrowseSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnBrowseSourceFile(CAssetBuilder *this)
{
  KeyValues *SelectedSourceKeyvalues; // eax
  int Int; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  int v6; // eax
  int v7; // eax

  SelectedSourceKeyvalues = CAssetBuilder::GetSelectedSourceKeyvalues(this);
  if ( SelectedSourceKeyvalues != nullptr )
  {
    Int = KeyValues::GetInt(this: SelectedSourceKeyvalues, keyName: "sourceTypeIndex", defaultValue: -1);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "SelectSourceFile");
    else
      v5 = nullptr;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hMakefile.m_handle);
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 60))(a1: v6);
    CAssetBuilder::ShowSourceFileBrowser(
      this,
      pTitle: "Select Source File",
      pSourceType: (DmeMakefileType_t *)(v7 + 24 * Int),
      pDialogKeys: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474430
// Name: public: virtual void CAssetBuilder::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnCommand(CAssetBuilder *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnCompile") == 0 )
    goto LABEL_2;
  if ( _V_stricmp(s1: pCommand, s2: "OnAbortCompile") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnPublish") == 0 )
    {
LABEL_2:
      CAssetBuilder::OnCompile(this);
      return;
    }
    vgui::Panel::OnCommand(this, command: pCommand);
  }
  else
  {
    CAssetBuilder::OnAbortCompile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474500
// Name: private: void CAssetBuilder::SelectSource(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SelectSource(CAssetBuilder *this, CDmeSource *pSource)
{
  int v3; // edi
  KeyValues *v4; // eax
  int Int; // eax
  int v6; // eax
  CDmeSource *v7; // esi
  vgui::ListPanel_vtbl *v8; // edx

  v3 = this->m_pSourcesList->FirstItem(this: this->m_pSourcesList);
  if ( v3 != this->m_pSourcesList->InvalidItemID(this: this->m_pSourcesList) )
  {
    while ( 1 )
    {
      v4 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v3);
      Int = KeyValues::GetInt(this: v4, keyName: "dmeSource", defaultValue: -1);
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: Int);
      v7 = (CDmeSource *)v6;
      if ( v6 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeSource::m_classType.u) == 0 )
      {
        v7 = nullptr;
      }
      v8 = this->m_pSourcesList->__vftable;
      if ( v7 == pSource )
        break;
      v3 = ((int (__stdcall *)(int))v8->NextItem)(a1: v3);
      if ( v3 == this->m_pSourcesList->InvalidItemID(this: this->m_pSourcesList) )
        return;
    }
    ((void (__stdcall *)(int))v8->SetSingleSelectedItem)(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004745D0
// Name: private: void CAssetBuilder::OnNewSourceFileSelected(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnNewSourceFileSelected(CAssetBuilder *this, char *pFileName, KeyValues *kv)
{
  int v4; // eax
  vgui::ListPanel *m_pSourcesList; // ecx
  vgui::ListPanel_vtbl *v6; // edx
  int Int; // eax
  int v8; // eax
  const char *v9; // ebx
  CDmeMakefile *v10; // eax
  DmFileId_t v11; // eax
  CDmeMakefile *v12; // eax
  CDmeSource *m_handle; // [esp-Ch] [ebp-28h]
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  int nItemID; // [esp+14h] [ebp-8h]
  KeyValues *pKeyValues; // [esp+18h] [ebp-4h]
  const char *pSourceMakeFile; // [esp+28h] [ebp+Ch]
  CDmeMakefile *pSourceMakeFilea; // [esp+28h] [ebp+Ch]

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0 )
  {
    v4 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    m_pSourcesList = this->m_pSourcesList;
    v6 = m_pSourcesList->__vftable;
    nItemID = v4;
    pKeyValues = v6->GetItem(this: m_pSourcesList, a2: v4);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dmeSource", defaultValue: -1);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: Int);
    v9 = (const char *)v8;
    if ( v8 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeSource::m_classType.u) != 0 )
    {
      pSourceMakeFile = KeyValues::GetString(this: kv, keyName: "makefileType", defaultValue: defaultValue);
      CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
      m_handle = (CDmeSource *)this->m_hMakefile.m_handle;
      v10 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(a1: g_pDataModel.u);
      CDmeMakefile::SetSourceFullPath(this: v10, pSource: m_handle, pFullPath: v9);
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 356))(a1: g_pDataModel.u);
      pSourceMakeFilea = CreateElement<CDmeMakefile>(
                           pElementType: pSourceMakeFile,
                           pObjectName: pFileName,
                           fileid: v11,
                           pObjectID: nullptr);
      CDmeMakefile::SetFileName(this: pSourceMakeFilea, pFileName);
      v12 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, const char *, CDmeMakefile *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                              a1: g_pDataModel.u,
                              a2: this->m_hMakefile.m_handle,
                              a3: v9,
                              a4: pSourceMakeFilea);
      CDmeMakefile::SetAssociation(
        this: v12,
        pSource: (CDmeSource *)pFileName,
        pSourceMakefile: (CDmeMakefile *)pFileName);
      this->SetDirty(this);
      CChangeUndoScopeGuard::Release(this: &guard);
      KeyValues::SetString(this: pKeyValues, keyName: "file", value: pFileName);
      this->m_pSourcesList->ApplyItemChanges(this: this->m_pSourcesList, a2: nItemID);
      this->m_pSourcesList->SortList(this: this->m_pSourcesList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474760
// Name: private: virtual void CAssetBuilder::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAssetBuilder::OnOpenContextMenu(CAssetBuilder *this@<ecx>, int a2@<ebx>, KeyValues *kv)
{
  vgui::Panel *v4; // eax
  vgui::Menu *v6; // eax
  vgui::Menu *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  vgui::Panel *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  vgui::Panel *v13; // eax
  KeyValues *v14; // eax
  CDmeSource *ElementKey; // eax
  CDmeSource *v16; // ebx
  const char *m_pAsString; // eax
  CDmeMakefile *v18; // eax
  vgui::Panel *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // ebx
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // ebx
  vgui::Panel *v25; // eax
  vgui::Panel *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // ebx
  vgui::Panel *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // ebx
  vgui::Panel *v32; // eax
  KeyValues *v33; // eax
  KeyValues *v34; // ebx
  vgui::Panel *v35; // eax
  KeyValues *v36; // eax
  KeyValues *v37; // ebx
  vgui::Panel *v38; // eax
  vgui::Menu *v39; // eax
  int nItemID; // [esp+8h] [ebp-Ch]
  int nCount; // [esp+Ch] [ebp-8h]
  bool bShowLoadSourceFile; // [esp+11h] [ebp-3h]
  bool bShowZoomOut; // [esp+12h] [ebp-2h]
  bool bShowZoomIn; // [esp+13h] [ebp-1h]
  vgui::ListPanel *bHasValidSourceFile; // [esp+1Ch] [ebp+8h]
  bool bHasValidSourceFile_3; // [esp+1Fh] [ebp+Bh]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v4->MarkForDeletion(this: v4);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0 )
  {
    bHasValidSourceFile = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
    nItemID = KeyValues::GetInt(this: kv, keyName: "itemID", defaultValue: -1);
    if ( bHasValidSourceFile == this->m_pSourcesList )
    {
      v6 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      if ( v6 != nullptr )
        v7 = vgui::Menu::Menu(this: v6, parent: this, panelName: "ActionMenu");
      else
        v7 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v7);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "AddSource");
      else
        v9 = nullptr;
      v10 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v10->__vftable[1].PaintTraverse)(
        a1: v10,
        a2: "Add...",
        a3: v9,
        a4: this,
        a5: 0);
      nCount = this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList);
      if ( nCount > 0 )
      {
        v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v11 != nullptr )
          v12 = KeyValues::KeyValues(this: v11, setName: "RemoveSource");
        else
          v12 = nullptr;
        v13 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v13->__vftable[1].PaintTraverse)(
          a1: v13,
          a2: "Remove",
          a3: v12,
          a4: this,
          a5: 0);
      }
      bShowZoomIn = false;
      bShowZoomOut = this->m_hMakefileStack.m_Size > 1;
      bShowLoadSourceFile = false;
      bHasValidSourceFile_3 = false;
      if ( nCount == 1 && nItemID != -1 )
      {
        v14 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: nItemID);
        ElementKey = GetElementKeyValue<CDmeSource>(pKeyValues: v14, pName: "dmeSource");
        v16 = ElementKey;
        if ( ElementKey != nullptr )
        {
          m_pAsString = ElementKey->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          bHasValidSourceFile_3 = *m_pAsString != 0;
          v18 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hMakefile.m_handle);
          if ( CDmeMakefile::FindDependentMakefile(this: v18, pSource: v16) != nullptr )
          {
            bShowZoomIn = true;
            goto LABEL_25;
          }
          bShowLoadSourceFile = bHasValidSourceFile_3;
        }
      }
      if ( !bShowZoomOut )
      {
LABEL_35:
        if ( nCount == 1 )
        {
          v26 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, int))v26->__vftable[1].DeletePanel)(a1: v26, a2);
          v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v27 != nullptr )
            v28 = KeyValues::KeyValues(this: v27, setName: "NewSourceFile");
          else
            v28 = nullptr;
          v29 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v29->__vftable[1].PaintTraverse)(
            a1: v29,
            a2: "New Source File...",
            a3: v28,
            a4: this,
            a5: 0);
          v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v30 != nullptr )
            v31 = KeyValues::KeyValues(this: v30, setName: "BrowseSourceFile");
          else
            v31 = nullptr;
          v32 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *))v32->__vftable[1].PaintTraverse)(
            a1: v32,
            a2: "Select Source File...",
            a3: v31,
            a4: this);
          if ( bShowLoadSourceFile )
          {
            v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v33 != nullptr )
              v34 = KeyValues::KeyValues(this: v33, setName: "LoadSourceFile");
            else
              v34 = nullptr;
            v35 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v35->__vftable[1].PaintTraverse)(
              a1: v35,
              a2: "Load Source File",
              a3: v34,
              a4: this,
              a5: 0);
          }
          if ( bHasValidSourceFile_3 )
          {
            v36 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v36 != nullptr )
              v37 = KeyValues::KeyValues(this: v36, setName: "EditSourceFile");
            else
              v37 = nullptr;
            v38 = vgui::PHandle::Get(this: &this->m_hContextMenu);
            ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v38->__vftable[1].PaintTraverse)(
              a1: v38,
              a2: "Edit Source File",
              a3: v37,
              a4: this,
              a5: 0);
          }
        }
        v39 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::PlaceContextMenu(parent: this, menu: v39);
        return;
      }
LABEL_25:
      v19 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v19->__vftable[1].DeletePanel(this: v19);
      if ( bShowZoomIn )
      {
        v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v20 != nullptr )
          v21 = KeyValues::KeyValues(this: v20, setName: "ZoomInSource");
        else
          v21 = nullptr;
        v22 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v22->__vftable[1].PaintTraverse)(
          a1: v22,
          a2: "Zoom In",
          a3: v21,
          a4: this,
          a5: 0);
      }
      if ( bShowZoomOut )
      {
        v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v23 != nullptr )
          v24 = KeyValues::KeyValues(this: v23, setName: "ZoomOutSource");
        else
          v24 = nullptr;
        v25 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAssetBuilder *, _DWORD))v25->__vftable[1].PaintTraverse)(
          a1: v25,
          a2: "Zoom Out",
          a3: v24,
          a4: this,
          a5: 0);
      }
      goto LABEL_35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474BE0
// Name: private: virtual void CAssetBuilder::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnItemSelected(CAssetBuilder *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pSourcesList )
    CAssetBuilder::OnSourceItemSelectionChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x00474C10
// Name: private: class CDmeSource __near * CAssetBuilder::GetSelectedSource(void)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CAssetBuilder::GetSelectedSource(CAssetBuilder *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  int Int; // eax
  int v5; // eax
  int v6; // esi

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0
    && (v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0),
        v3 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v2),
        Int = KeyValues::GetInt(this: v3, keyName: "dmeSource", defaultValue: -1),
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: Int),
        v6 = v5,
        v5 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeSource::m_classType.u) != 0 )
  {
    return (CDmeSource *)v6;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474CB0
// Name: private: void CAssetBuilder::OnSourceFileNameChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceFileNameChanged(CAssetBuilder *this, const char *pFileName)
{
  int v3; // ebx
  int Int; // eax
  int v5; // eax
  CDmeSource *v6; // edi
  CDmeMakefile *v7; // eax
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-Ch] BYREF
  KeyValues *pKeyValues; // [esp+14h] [ebp-4h]

  if ( this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList) == 1
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0 )
  {
    v3 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    pKeyValues = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v3);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dmeSource", defaultValue: -1);
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: Int);
    v6 = (CDmeSource *)v5;
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeSource::m_classType.u) != 0 )
    {
      CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
      v7 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_hMakefile.m_handle);
      CDmeMakefile::SetSourceFullPath(this: v7, pSource: v6, pFullPath: pFileName);
      this->SetDirty(this);
      CChangeUndoScopeGuard::Release(this: &guard);
      KeyValues::SetString(this: pKeyValues, keyName: "file", value: pFileName);
      this->m_pSourcesList->ApplyItemChanges(this: this->m_pSourcesList, a2: v3);
      this->m_pSourcesList->SortList(this: this->m_pSourcesList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474DD0
// Name: private: virtual void CAssetBuilder::OnEditSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnEditSourceFile(CAssetBuilder *this)
{
  CDmeSource *SelectedSource; // eax

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
    CDmeSource::OpenEditor(this: SelectedSource);
}

//------------------------------------------------------------------------------
// Address: 0x00474DF0
// Name: public: virtual CAssetBuilderFrame::~CAssetBuilderFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::~CAssetBuilderFrame(CAssetBuilderFrame *this)
{
  bool v2; // sf

  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CAssetBuilderFrame_vtbl *)&CAssetBuilderFrame::`vftable'{for `vgui::Frame'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CAssetBuilderFrame::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  v2 = this->m_TitleString.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_TitleString.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_TitleString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TitleString.m_Storage.m_Memory.m_pMemory);
      this->m_TitleString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_TitleString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x00474E50
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetBuilderFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetBuilderFrame::GetMessageMap(CAssetBuilderFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetBuilderFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetBuilderFrame::GetMessageMap'::`2'::s_pMap;
  `CAssetBuilderFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
  `CAssetBuilderFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474E80
// Name: public: virtual struct PanelAnimationMap __near * CAssetBuilderFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetBuilderFrame::GetAnimMap(CAssetBuilderFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetBuilderFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00474EC0
// Name: private: virtual void CAssetBuilder::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnFileSelected(CAssetBuilder *this, KeyValues *kv)
{
  char *String; // esi
  KeyValues *Key; // edi

  String = (char *)KeyValues::GetString(this: kv, keyName: "fullpath", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( KeyValues::FindKey(this: kv, keyName: "SelectSourceFile", bCreate: false) != nullptr )
      goto LABEL_6;
    Key = KeyValues::FindKey(this: kv, keyName: "NewSourceFileSelected", bCreate: false);
    if ( Key == nullptr )
      return;
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: String, a3: nullptr) )
LABEL_6:
      CAssetBuilder::OnSourceFileNameChanged(this, pFileName: String);
    else
      CAssetBuilder::OnNewSourceFileSelected(this, pFileName: String, kv: Key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475070
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x00475100
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x00475190
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
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
// Address: 0x00475220
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
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
// Address: 0x004752B0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
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
// Address: 0x00475340
// Name: public: static void CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_SetDirty::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_SetDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004753D0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475460
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "NewSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004754F0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LoadSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475580
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "EditSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004756A0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BrowseSourceFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475730
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ZoomInSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004757C0
// Name: public: static void CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar'::`2'::bAdded )
  {
    `CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ZoomOutSource";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475850
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnDmeElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnDmeElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004758E0
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnFileNew::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnFileNew::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnFileNew::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnFileNew::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileNew";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475970
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnFileOpen::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnFileOpen::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnFileOpen::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnFileOpen::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilderFrame::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileOpen";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475A00
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnFileSave::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnFileSave::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnFileSave::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnFileSave::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSave";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475A90
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnFileSaveAs::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnFileSaveAs::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnFileSaveAs::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnFileSaveAs::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSaveAs";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475B20
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilderFrame::`vcall'{1136,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
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
// Address: 0x00475BB0
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Button::`vcall'{1140,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
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
// Address: 0x00475C40
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnFileStateMachineFinished::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnFileStateMachineFinished::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
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
// Address: 0x00475CD0
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_OnPerformFileNew::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_OnPerformFileNew::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_OnPerformFileNew::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_OnPerformFileNew::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PerformFileNew";
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
// Address: 0x00475D60
// Name: public: static void CAssetBuilderFrame::PanelMessageFunc_UpdateFileName::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAssetBuilderFrame::PanelMessageFunc_UpdateFileName::InitVar(int a1@<ebp>)
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
  if ( !`CAssetBuilderFrame::PanelMessageFunc_UpdateFileName::InitVar'::`2'::bAdded )
  {
    `CAssetBuilderFrame::PanelMessageFunc_UpdateFileName::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "UpdateFileName";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475DF0
// Name: void BuildAssetTypeList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildAssetTypeList()
{
  unsigned __int8 (__thiscall *v0)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  int v1; // edi
  unsigned __int8 (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, int); // edx
  const char *v3; // ebx
  int v4; // eax
  int v5; // eax
  CExpressionCalculator *v6; // esi
  int m_Size; // eax
  int v8; // edi
  PickerInfo_t *m_pMemory; // ecx
  int v10; // eax
  int (__thiscall *v11)(CExpressionCalculator *); // eax
  int v12; // edi
  int BufferType; // eax
  int v14; // eax
  int v15; // edx
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  PickerInfo_t *v17; // [esp+14h] [ebp-8h]
  int hFactory; // [esp+18h] [ebp-4h]

  if ( !s_bAssetTypeListBuilt )
  {
    v0 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    s_bAssetTypeListBuilt = true;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v0)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 44))(a1: g_pDataModel.u);
    v2 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 52);
    hFactory = v1;
    if ( ((int (__thiscall *)(_DWORD, _DWORD))v2)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id, a2: v1) != 0 )
    {
      while ( 1 )
      {
        v3 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 56))(
                             a1: g_pDataModel.u,
                             a2: v1);
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
               a1: g_pDataModel.u,
               a2: v3,
               a3: "temp",
               a4: -1,
               a5: 0);
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: v4);
        v6 = (CExpressionCalculator *)v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmElement::m_classType.u) != 0 )
        {
          if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v6->m_expr.m_Storage.m_Memory.m_pMemory
                + 4))(
                 a1: v6,
                 a2: CDmeMakefile::m_classType.u) != 0
            && (*((int (__thiscall **)(CExpressionCalculator *))v6->m_expr.m_Storage.m_Memory.m_pMemory + 14))(a1: v6) != 0 )
          {
            m_Size = s_AssetTypes.m_Choices.m_Size;
            v8 = s_AssetTypes.m_Choices.m_Size;
            if ( s_AssetTypes.m_Choices.m_Size + 1 > s_AssetTypes.m_Choices.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<MDLSquenceLayer_t,int>::Grow(
                this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&s_AssetTypes.m_Choices,
                num: s_AssetTypes.m_Choices.m_Size - s_AssetTypes.m_Choices.m_Memory.m_nAllocationCount + 1);
              m_Size = s_AssetTypes.m_Choices.m_Size;
            }
            m_pMemory = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            s_AssetTypes.m_Choices.m_Size = m_Size + 1;
            v10 = m_Size - v8;
            s_AssetTypes.m_Choices.m_pElements = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            if ( v10 > 0 )
            {
              _V_memmove(
                dest: &s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8 + 1],
                src: &s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8],
                count: 8 * v10);
              m_pMemory = s_AssetTypes.m_Choices.m_Memory.m_pMemory;
            }
            v11 = *((int (__thiscall **)(CExpressionCalculator *))v6->m_expr.m_Storage.m_Memory.m_pMemory + 14);
            v17 = &m_pMemory[v8];
            v17->m_pChoiceString = *(const char **)(v11(a1: v6) + 4);
            s_AssetTypes.m_Choices.m_Memory.m_pMemory[v8].m_pChoiceValue = v3;
          }
          v12 = *(_DWORD *)g_pDataModel.u.m_Id;
          BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v12 + 68))(
            a1: g_pDataModel.u,
            a2: BufferType);
          v1 = hFactory;
        }
        v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 48))(
                a1: g_pDataModel.u,
                a2: v1);
        v15 = *(_DWORD *)g_pDataModel.u.m_Id;
        hFactory = v14;
        if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v15 + 52))(
               a1: g_pDataModel.u,
               a2: v14) == 0 )
          break;
        v1 = hFactory;
      }
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475FD0
// Name: BuildAssetSubTypeList
// Source: json
//------------------------------------------------------------------------------
PickerList_t *__cdecl BuildAssetSubTypeList(const char **ppSubTypes, PickerList_t *pickerList)
{
  CExpressionCalculator *v2; // ebx
  int v4; // eax
  int v5; // eax
  CDmeMakefile *v6; // esi
  bool (__thiscall *IsA)(struct CDmeMakefile *, CUtlSymbolLarge); // eax
  char v8; // al
  const char **v9; // eax
  int v10; // esi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v14; // eax
  int v15; // ebx
  PickerInfo_t *v16; // esi
  int v17; // esi
  int BufferType; // eax
  char guard_4; // [esp+10h] [ebp-18h]
  int nCount; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h] BYREF
  CDmeMakefile *pMakeFile; // [esp+1Ch] [ebp-Ch]
  CExpressionCalculator *v23; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v2 = nullptr;
  if ( ppSubTypes == nullptr )
    return &s_AssetTypes;
  pickerList->m_Choices.m_Size = 0;
  guard_4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  nCount = s_AssetTypes.m_Choices.m_Size;
  i = 0;
  if ( s_AssetTypes.m_Choices.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
             a1: g_pDataModel.u,
             a2: s_AssetTypes.m_Choices.m_Memory.m_pMemory[i].m_pChoiceValue,
             a3: "temp",
             a4: -1,
             a5: 0);
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: v4);
      v6 = (CDmeMakefile *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        IsA = v6->IsA;
        v2 = (CExpressionCalculator *)v6;
        v23 = (CExpressionCalculator *)v6;
        v8 = ((int (__thiscall *)(_DWORD, _DWORD))IsA)(a1: v6, a2: (CUtlSymbolLarge)CDmeMakefile::m_classType.u.m_Id);
        pMakeFile = v6;
        if ( v8 != 0 )
          goto LABEL_10;
      }
      else
      {
        v23 = nullptr;
      }
      pMakeFile = nullptr;
LABEL_10:
      v9 = ppSubTypes;
      v10 = 0;
      if ( *ppSubTypes != nullptr )
      {
        while ( 1 )
        {
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
            a1: g_pDataModel.u,
            a2: &v21,
            a3: *v9);
          if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, int))v2->m_expr.m_Storage.m_Memory.m_pMemory
                + 4))(
                 a1: v2,
                 a2: v21) != 0 )
            break;
          v9 = &ppSubTypes[++v10];
          if ( *v9 == nullptr )
            goto LABEL_20;
        }
        m_Size = pickerList->m_Choices.m_Size;
        m_nAllocationCount = pickerList->m_Choices.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<MDLSquenceLayer_t,int>::Grow(
            this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&pickerList->m_Choices,
            num: m_Size - m_nAllocationCount + 1);
        ++pickerList->m_Choices.m_Size;
        m_pMemory = pickerList->m_Choices.m_Memory.m_pMemory;
        v14 = pickerList->m_Choices.m_Size - m_Size - 1;
        pickerList->m_Choices.m_pElements = m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v14);
        v15 = m_Size;
        v16 = pickerList->m_Choices.m_Memory.m_pMemory;
        v16[v15].m_pChoiceString = pMakeFile->GetMakefileType(this: pMakeFile)->m_pHumanReadableName;
        pickerList->m_Choices.m_Memory.m_pMemory[v15].m_pChoiceValue = s_AssetTypes.m_Choices.m_Memory.m_pMemory[i].m_pChoiceValue;
        v2 = v23;
      }
LABEL_20:
      if ( v2 != nullptr )
      {
        v17 = *(_DWORD *)g_pDataModel.u.m_Id;
        BufferType = CCodecBuffer_Block::GetBufferType(this: v2);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v17 + 68))(a1: g_pDataModel.u, a2: BufferType);
      }
      if ( ++i >= nCount )
        break;
      v2 = nullptr;
    }
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: guard_4);
  return pickerList;
}

//------------------------------------------------------------------------------
// Address: 0x004761D0
// Name: ReadMakefile
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__usercall ReadMakefile@<eax>(const char *pFileName@<edi>, CDmElement **ppRoot)
{
  CDmElement **v2; // ebx
  CDmeMakefile *Value; // esi
  CDmElement **v4; // esi
  CDmElement *v5; // ecx
  CDmElement *v6; // esi

  v2 = ppRoot;
  if ( ppRoot != nullptr )
    *ppRoot = nullptr;
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, _DWORD, CDmElement ***, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
         a1: g_pDataModel.u,
         a2: pFileName,
         a3: 0,
         a4: 0,
         a5: &ppRoot,
         a6: 1,
         a7: 0) == -1
    || (Value = (CDmeMakefile *)ppRoot, ppRoot == nullptr) )
  {
    _Warning(a1: "Unable to read makefile \"%s\"!\n", pFileName);
    return nullptr;
  }
  if ( (*(unsigned __int8 (__thiscall **)(CDmElement **, CUtlSymbolLarge::<unnamed_type_u>))&(*ppRoot)->m_Id.m_Value[12])(
         a1: ppRoot,
         a2: CDmeMakefile::m_classType.u) == 0 )
  {
    v4 = ppRoot;
    if ( ppRoot != nullptr
      && (*(unsigned __int8 (__thiscall **)(CDmElement **, CUtlSymbolLarge::<unnamed_type_u>))&(*ppRoot)->m_Id.m_Value[12])(
           a1: ppRoot,
           a2: CDmElement::m_classType.u) != 0 )
    {
      v5 = (CDmElement *)v4;
    }
    else
    {
      v5 = nullptr;
    }
    Value = CDmElement::GetValueElement<CDmeMakefile>(this: v5, pAttributeName: "makefile");
    if ( Value == nullptr )
    {
      v6 = ppRoot[14];
      DestroyElement(pElement: (CDmElement *)ppRoot);
      if ( v6 != (CDmElement *)-1
        && *(_BYTE *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 364))(
                       a1: g_pDataModel.u,
                       a2: v6) != 0 )
      {
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement *))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
          a1: g_pDataModel.u,
          a2: v6);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( v2 != nullptr )
    *v2 = CastElement<CDmElement>(pElement: (CDmElement *)ppRoot);
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x004762D0
// Name: public: CAssetBuilder::CAssetBuilder(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetBuilder *__thiscall CAssetBuilder::CAssetBuilder(
        CAssetBuilder *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::PropertyPage *v9; // eax
  vgui::PropertyPage *v10; // eax
  vgui::PropertyPage *v11; // eax
  vgui::PropertyPage *v12; // eax
  vgui::PropertyPage *v13; // eax
  vgui::PropertyPage *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  vgui::Splitter *v17; // eax
  vgui::Splitter *v18; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v20; // edi
  CDmePanel *v21; // eax
  CDmePanel *v22; // eax
  CDmePanel *v23; // eax
  CDmePanel *v24; // eax
  vgui::ListPanel *v25; // eax
  vgui::ListPanel *v26; // eax
  vgui::ListPanel *v27; // eax
  vgui::ListPanel *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::TextEntry *v30; // eax
  vgui::Button *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::Button *v34; // eax
  vgui::Button *v35; // eax
  vgui::Button *v36; // eax
  CCompileStatusBar *v37; // eax
  CCompileStatusBar *v38; // eax
  vgui::PropertyPage *m_pInputPage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CAssetBuilder_vtbl *)&CAssetBuilder::`vftable';
  if ( `CAssetBuilder::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
    v4->pfnClassName = CAssetBuilder::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CAssetBuilder::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAssetBuilder");
    v5->pfnClassName = CAssetBuilder::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CAssetBuilder::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilder::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetBuilder");
    v6->pfnClassName = CAssetBuilder::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CAssetBuilder::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_SetDirty::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnAddSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnNewSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnLoadSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnEditSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnRemoveSource::InitVar();
  CAssetBuilder::PanelMessageFunc_OnBrowseSourceFile::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnZoomInSource::InitVar(a1: (int)&savedregs);
  CAssetBuilder::PanelMessageFunc_OnZoomOutSource::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_hRootMakefile.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hMakefile.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hMakefileStack.m_Memory.m_pMemory = nullptr;
  this->m_hMakefileStack.m_Memory.m_nAllocationCount = 0;
  this->m_hMakefileStack.m_Memory.m_nGrowSize = 0;
  this->m_hMakefileStack.m_Size = 0;
  this->m_hMakefileStack.m_pElements = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: DMELEMENT_HANDLE_INVALID);
  *((_BYTE *)this + 492) = *((_BYTE *)this + 492) & 0xFC | 2;
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "InputOutputSheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pInputOutputSheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v9 != nullptr )
    v10 = vgui::PropertyPage::PropertyPage(this: v9, parent: this->m_pInputOutputSheet, panelName: "InputPage");
  else
    v10 = nullptr;
  this->m_pInputPage = v10;
  v11 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v11 != nullptr )
    v12 = vgui::PropertyPage::PropertyPage(this: v11, parent: this->m_pInputOutputSheet, panelName: "OutputPage");
  else
    v12 = nullptr;
  this->m_pOutputPage = v12;
  v13 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v13 != nullptr )
    v14 = vgui::PropertyPage::PropertyPage(this: v13, parent: this->m_pInputOutputSheet, panelName: "CompilePage");
  else
    v14 = nullptr;
  this->m_pCompilePage = v14;
  v15 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v15 != nullptr )
    v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pInputOutputSheet, panelName: "OutputPreviewPage");
  else
    v16 = nullptr;
  this->m_pOutputPreviewPage = v16;
  v17 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v17 != nullptr )
    v18 = vgui::Splitter::Splitter(
            this: v17,
            parent: this->m_pInputPage,
            name: "PropertiesSplitter",
            mode: SPLITTER_MODE_VERTICAL,
            nCount: 1);
  else
    v18 = nullptr;
  this->m_pPropertiesSplitter = v18;
  Child = vgui::Panel::GetChild(this: v18, index: 0);
  v20 = vgui::Panel::GetChild(this: this->m_pPropertiesSplitter, index: 1);
  v21 = (CDmePanel *)MemAlloc_Alloc(nSize: 0x250u);
  if ( v21 != nullptr )
    v22 = CDmePanel::CDmePanel(this: v21, pParent: v20, pPanelName: "CompileOptions", bComboBoxVisible: true);
  else
    v22 = nullptr;
  this->m_pDmePanel = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (CDmePanel *)MemAlloc_Alloc(nSize: 0x250u);
  if ( v23 != nullptr )
    v24 = CDmePanel::CDmePanel(
            this: v23,
            pParent: this->m_pOutputPreviewPage,
            pPanelName: "OutputPreview",
            bComboBoxVisible: false);
  else
    v24 = nullptr;
  this->m_pOututPreviewPanel = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  v25 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v25 != nullptr )
    v26 = vgui::ListPanel::ListPanel(this: v25, parent: Child, panelName: "SourcesList");
  else
    v26 = nullptr;
  this->m_pSourcesList = v26;
  v26->AddColumnHeader(this: v26, a2: 0, a3: "type", a4: "type", a5: 100, a6: 0);
  this->m_pSourcesList->AddColumnHeader(this: this->m_pSourcesList, a2: 1, a3: "file", a4: "file", a5: 52, a6: 0);
  this->m_pSourcesList->AddActionSignalTarget_2(this: this->m_pSourcesList, a2: this);
  this->m_pSourcesList->SetSortFunc(this: this->m_pSourcesList, a2: 0, a3: TypeSortFunc);
  this->m_pSourcesList->SetSortFunc(this: this->m_pSourcesList, a2: 1, a3: FileSortFunc);
  this->m_pSourcesList->SetSortColumn(this: this->m_pSourcesList, a2: 0);
  this->m_pSourcesList->SetEmptyListText_2(this: this->m_pSourcesList, a2: "No sources");
  v27 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v27 != nullptr )
    v28 = vgui::ListPanel::ListPanel(this: v27, parent: this->m_pOutputPage, panelName: "OutputList");
  else
    v28 = nullptr;
  this->m_pOutputList = v28;
  v28->AddColumnHeader(this: v28, a2: 0, a3: "type", a4: "type", a5: 100, a6: 0);
  this->m_pOutputList->AddColumnHeader(this: this->m_pOutputList, a2: 1, a3: "file", a4: "file", a5: 52, a6: 0);
  this->m_pOutputList->AddActionSignalTarget_2(this: this->m_pOutputList, a2: this);
  this->m_pOutputList->SetSortFunc(this: this->m_pOutputList, a2: 0, a3: TypeSortFunc);
  this->m_pOutputList->SetSortFunc(this: this->m_pOutputList, a2: 1, a3: FileSortFunc);
  this->m_pOutputList->SetSortColumn(this: this->m_pOutputList, a2: 0);
  this->m_pOutputList->SetEmptyListText_2(this: this->m_pOutputList, a2: "No outputs");
  v29 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v29 != nullptr )
    v30 = vgui::TextEntry::TextEntry(this: v29, parent: this->m_pCompilePage, panelName: "CompileOutput");
  else
    v30 = nullptr;
  this->m_pCompileOutput = v30;
  v30->SetMultiline(this: v30, a2: true);
  this->m_pCompileOutput->SetVerticalScrollbar(this: this->m_pCompileOutput, a2: true);
  v31 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v31 != nullptr )
    v32 = vgui::Button::Button(
            this: v31,
            parent: this,
            panelName: "CompileButton",
            text: "Compile",
            pActionSignalTarget: this,
            pCmd: "OnCompile");
  else
    v32 = nullptr;
  this->m_pCompile = v32;
  v33 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v33 != nullptr )
    v34 = vgui::Button::Button(
            this: v33,
            parent: this,
            panelName: "PublishButton",
            text: "Publish",
            pActionSignalTarget: this,
            pCmd: "OnPublish");
  else
    v34 = nullptr;
  this->m_pPublish = v34;
  v35 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v35 != nullptr )
    v36 = vgui::Button::Button(
            this: v35,
            parent: this,
            panelName: "AbortCompileButton",
            text: "AbortCompile",
            pActionSignalTarget: this,
            pCmd: "OnAbortCompile");
  else
    v36 = nullptr;
  this->m_pAbortCompile = v36;
  v37 = (CCompileStatusBar *)MemAlloc_Alloc(nSize: 0x18Cu);
  if ( v37 != nullptr )
    v38 = CCompileStatusBar::CCompileStatusBar(this: v37, pParent: this, pPanelName: "CompileStatus");
  else
    v38 = nullptr;
  m_pInputPage = this->m_pInputPage;
  this->m_pCompileStatusBar = v38;
  m_pInputPage->LoadControlSettingsAndUserConfig(this: m_pInputPage, a2: "resource/assetbuilderinputpage.res", a3: 0);
  this->m_pOutputPage->LoadControlSettingsAndUserConfig(
    this: this->m_pOutputPage,
    a2: "resource/assetbuilderoutputpage.res",
    a3: 0);
  this->m_pCompilePage->LoadControlSettingsAndUserConfig(
    this: this->m_pCompilePage,
    a2: "resource/assetbuildercompilepage.res",
    a3: 0);
  this->m_pOutputPreviewPage->LoadControlSettingsAndUserConfig(
    this: this->m_pOutputPreviewPage,
    a2: "resource/assetbuilderoutputpreviewpage.res",
    a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetbuilder.res",
    dialogID: 0);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pInputPage,
    a3: "Input",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pOutputPage,
    a3: "Output",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pCompilePage,
    a3: "Compile",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pInputOutputSheet->AddPage(
    this: this->m_pInputOutputSheet,
    a2: this->m_pOutputPreviewPage,
    a3: "Preview",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: false);
  this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: false);
  this->m_pAbortCompile->SetEnabled(this: this->m_pAbortCompile, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004769C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetBuilder::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetBuilder::GetMessageMap(CAssetBuilder *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetBuilder::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetBuilder::GetMessageMap'::`2'::s_pMap;
  `CAssetBuilder::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilder");
  `CAssetBuilder::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004769F0
// Name: public: virtual struct PanelAnimationMap __near * CAssetBuilder::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetBuilder::GetAnimMap(CAssetBuilder *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetBuilder");
}

//------------------------------------------------------------------------------
// Address: 0x00476A00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetBuilder::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetBuilder::GetKBMap(CAssetBuilder *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetBuilder::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetBuilder::GetKBMap'::`2'::s_pMap;
  `CAssetBuilder::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetBuilder");
  `CAssetBuilder::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476A30
// Name: private: void CAssetBuilder::BuildFileIDList(class CDmeMakefile __near *,class CUtlVector<enum DmFileId_t,class CUtlMemory<enum DmFileId_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::BuildFileIDList(
        CAssetBuilder *this,
        CDmeTransform *pMakeFile,
        CUtlMemory<vgui::TreeNode *,int> *fileIds)
{
  DmFileId_t m_fileId; // ebx
  int m_pMemory; // edi
  int v5; // eax
  DmFileId_t *v6; // ecx
  int m_nAllocationCount; // eax
  DmFileId_t *v8; // ecx
  int v9; // eax
  DmFileId_t *v10; // edi
  CDmAttribute *ClipCount; // ebx
  int i; // edi
  CDmeSource *Source; // eax
  CDmeMakefile *DependentMakefile; // eax

  if ( pMakeFile != nullptr )
  {
    m_fileId = pMakeFile->m_fileId;
    m_pMemory = (int)fileIds[1].m_pMemory;
    v5 = 0;
    if ( m_pMemory > 0 )
    {
      v6 = (DmFileId_t *)fileIds->m_pMemory;
      do
      {
        if ( *v6 == m_fileId )
          break;
        ++v5;
        ++v6;
      }
      while ( v5 < m_pMemory );
    }
    if ( v5 == m_pMemory )
    {
      m_nAllocationCount = fileIds->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: fileIds, num: m_pMemory - m_nAllocationCount + 1);
      ++fileIds[1].m_pMemory;
      v8 = (DmFileId_t *)fileIds->m_pMemory;
      v9 = (int)fileIds[1].m_pMemory - m_pMemory - 1;
      fileIds[1].m_nAllocationCount = (int)fileIds->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
      v10 = (DmFileId_t *)&fileIds->m_pMemory[m_pMemory];
      if ( v10 != nullptr )
        *v10 = m_fileId;
    }
    ClipCount = CDmeTrack::GetClipCount(this: pMakeFile);
    for ( i = 0; i < (int)ClipCount; ++i )
    {
      Source = CDmeMakefile::GetSource(this: (CDmeMakefile *)pMakeFile, nIndex: i);
      DependentMakefile = CDmeSource::GetDependentMakefile(this: Source);
      CAssetBuilder::BuildFileIDList(
        this,
        pMakeFile: DependentMakefile,
        (CUtlVector<enum DmFileId_t,CUtlMemory<enum DmFileId_t,int> > *)fileIds);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476AF0
// Name: private: void CAssetBuilder::CleanupMakefile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::CleanupMakefile(CAssetBuilder *this)
{
  int i; // edi
  DmElementHandle_t m_handle; // eax
  CDmeTransform *v4; // eax
  int v5; // esi
  int j; // edi
  DmFileId_t *m_pMemory; // eax
  CUtlVector<enum DmFileId_t,CUtlMemory<enum DmFileId_t,int> > fileIds; // [esp+Ch] [ebp-1Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+20h] [ebp-8h]

  for ( i = this->m_hMakefileStack.m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel.u.m_Id != 0 )
      CDmeElementRefHelper::Unref(
        this: &this->m_hMakefileStack.m_Memory.m_pMemory[i],
        hElement: this->m_hMakefileStack.m_Memory.m_pMemory[i].m_handle,
        handleType: HT_WEAK);
  }
  this->m_hMakefileStack.m_Size = 0;
  CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  CDmePanel::SetDmeElement(this: this->m_pOututPreviewPanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hRootMakefile.m_handle) != 0 )
  {
    m_handle = this->m_hRootMakefile.m_handle;
    memset(&fileIds, 0, sizeof(fileIds));
    v4 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: m_handle);
    CAssetBuilder::BuildFileIDList(this, pMakeFile: v4, (CUtlMemory<vgui::TreeNode *,int> *)&fileIds);
    guard.m_bOldValue = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: DMELEMENT_HANDLE_INVALID);
    v5 = 0;
    for ( j = fileIds.m_Size; v5 < j; ++v5 )
    {
      if ( fileIds.m_Memory.m_pMemory[v5] != DMFILEID_INVALID
        && *(_BYTE *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 364))(
                       a1: g_pDataModel.u,
                       a2: fileIds.m_Memory.m_pMemory[v5]) != 0 )
      {
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
          a1: g_pDataModel.u,
          a2: fileIds.m_Memory.m_pMemory[v5]);
      }
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&guard.m_bOldValue);
    m_pMemory = fileIds.m_Memory.m_pMemory;
    fileIds.m_Size = 0;
    if ( fileIds.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileIds.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileIds.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileIds.m_Memory.m_pMemory = nullptr;
      }
      fileIds.m_Memory.m_nAllocationCount = 0;
    }
    fileIds.m_pElements = m_pMemory;
    if ( fileIds.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476D40
// Name: private: virtual void CAssetBuilder::OnAddSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnAddSource(CAssetBuilder *this)
{
  vgui::Panel *v1; // edi
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  vgui::OverridableColorEntry *m_pElements; // eax
  int v4; // ebx
  int v5; // eax
  DmeMakefileType_t *v6; // eax
  DmeMakefileType_t *v7; // esi
  DmeMakefileType_t *v8; // edi
  CDmeMakefile *v9; // eax
  int m_Size; // eax
  int v11; // esi
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  CPickerFrame *v16; // eax
  CPickerFrame *v17; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-28h]
  PickerList_t sourceType; // [esp+4h] [ebp-20h] BYREF
  DmeMakefileType_t *pSourceTypes; // [esp+1Ch] [ebp-8h]
  CAssetBuilder *v21; // [esp+20h] [ebp-4h]

  v1 = this;
  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_handle = this->m_hMakefile.m_handle;
  v21 = this;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))v2)(
         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
         a2: m_handle) != 0 )
  {
    m_pElements = v1[1].m_OverridableColorEntries.m_pElements;
    v4 = 0;
    memset(&sourceType, 0, sizeof(sourceType));
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, vgui::OverridableColorEntry *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
           a1: g_pDataModel.u,
           a2: m_pElements);
    v6 = (DmeMakefileType_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 60))(a1: v5);
    v7 = v6;
    pSourceTypes = v6;
    if ( v6->m_pTypeName != nullptr )
    {
      v8 = v6;
      do
      {
        if ( !v8->m_bIsSingleton
          || (v9 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                     a1: g_pDataModel.u,
                                     a2: v21->m_hMakefile.m_handle),
              !CDmeMakefile::HasSourceOfType(this: v9, pSourceType: v8->m_pTypeName)) )
        {
          m_Size = sourceType.m_Choices.m_Size;
          v11 = sourceType.m_Choices.m_Size;
          if ( sourceType.m_Choices.m_Size + 1 > sourceType.m_Choices.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<MDLSquenceLayer_t,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&sourceType.m_Choices,
              num: sourceType.m_Choices.m_Size - sourceType.m_Choices.m_Memory.m_nAllocationCount + 1);
            m_Size = sourceType.m_Choices.m_Size;
          }
          m_pMemory = sourceType.m_Choices.m_Memory.m_pMemory;
          sourceType.m_Choices.m_Size = m_Size + 1;
          v13 = m_Size - v11;
          sourceType.m_Choices.m_pElements = sourceType.m_Choices.m_Memory.m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(
              dest: &sourceType.m_Choices.m_Memory.m_pMemory[v11 + 1],
              src: &sourceType.m_Choices.m_Memory.m_pMemory[v11],
              count: 8 * v13);
            m_pMemory = sourceType.m_Choices.m_Memory.m_pMemory;
          }
          m_pMemory[v11].m_pChoiceString = v8->m_pHumanReadableName;
          sourceType.m_Choices.m_Memory.m_pMemory[v11].m_pChoiceValue = v8->m_pTypeName;
          v7 = pSourceTypes;
        }
        v8 = &v7[++v4];
      }
      while ( v8->m_pTypeName != nullptr );
      v1 = v21;
    }
    if ( sourceType.m_Choices.m_Size != 0 )
    {
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "OnAddSource");
      else
        v15 = nullptr;
      v16 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
      if ( v16 != nullptr )
        v17 = CPickerFrame::CPickerFrame(
                this: v16,
                pParent: v1,
                pTitle: "Select Source Type",
                pPickerType: "Source Type",
                pTextType: "sourceType");
      else
        v17 = nullptr;
      CPickerFrame::DoModal(this: v17, list: &sourceType, pContextKeyValues: v15);
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sourceType.m_Choices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476EC0
// Name: private: virtual void CAssetBuilder::OnLoadSourceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::OnLoadSourceFile(CAssetBuilder *this@<ecx>, int a2@<edi>)
{
  CDmeSource *SelectedSource; // ebx
  CDmeMakefile *v4; // eax
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  CDmeMakefile *v6; // eax
  CDmeMakefile *v7; // eax
  CDmeMakefile *v8; // [esp-4h] [ebp-11Ch]
  char pFullPath[260]; // [esp+8h] [ebp-110h] BYREF
  CDmElement *pRoot; // [esp+10Ch] [ebp-Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+110h] [ebp-8h] BYREF

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
  {
    v4 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, CDmeSource *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hMakefile.m_handle,
                           a3: SelectedSource);
    CDmeMakefile::GetSourceFullPath(this: v4, pSource: (CDmeSource *)pFullPath, pFullPath: (char *)0x104, nBufLen: a2);
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    v6 = ReadMakefile(pFileName: pFullPath, ppRoot: &pRoot);
    if ( v6 != nullptr )
    {
      v8 = v6;
      v7 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_hMakefile.m_handle);
      CDmeMakefile::SetAssociation(this: v7, pSource: SelectedSource, pSourceMakefile: v8);
      CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: SelectedSource, bForce: true, pPanelName: nullptr);
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476F90
// Name: public: CAssetBuilderFrame::CAssetBuilderFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetBuilderFrame *__thiscall CAssetBuilderFrame::CAssetBuilderFrame(
        CAssetBuilderFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CAssetBuilder *v7; // eax
  CAssetBuilder *v8; // eax
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // edi
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  vgui::FileOpenStateMachine *v19; // eax
  vgui::FileOpenStateMachine *v20; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "AssetBuilderFrame", showTaskbarIcon: true, bPopup: true);
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&vgui::IFileOpenStateMachineClient::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CAssetBuilderFrame_vtbl *)&CAssetBuilderFrame::`vftable'{for `vgui::Frame'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CAssetBuilderFrame::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( `CAssetBuilderFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilderFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAssetBuilderFrame");
    v4->pfnClassName = CAssetBuilderFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CAssetBuilderFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetBuilderFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAssetBuilderFrame");
    v5->pfnClassName = CAssetBuilderFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CAssetBuilderFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetBuilderFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetBuilderFrame");
    v6->pfnClassName = CAssetBuilderFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CAssetBuilderFrame::PanelMessageFunc_OnDmeElementChanged::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnFileNew::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnFileOpen::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnFileSave::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnFileSaveAs::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnFileStateMachineFinished::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_OnPerformFileNew::InitVar(a1: (int)&savedregs);
  CAssetBuilderFrame::PanelMessageFunc_UpdateFileName::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_TitleString);
  CUtlString::operator=(this: &this->m_TitleString, src: pTitle);
  vgui::Frame::SetMenuButtonVisible(this, state: true);
  vgui::Frame::SetImages(this, pEnabledImage: "resource/downarrow", pDisabledImage: nullptr);
  v7 = (CAssetBuilder *)MemAlloc_Alloc(nSize: 0x1F0u);
  if ( v7 != nullptr )
    v8 = CAssetBuilder::CAssetBuilder(this: v7, pParent: this, pPanelName: "AssetBuilder");
  else
    v8 = nullptr;
  this->m_pAssetBuilder = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: nullptr, panelName: "FileMenu");
  else
    v10 = nullptr;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "FileNew");
  else
    v12 = nullptr;
  v10->AddMenuItem(this: v10, a2: "new", a3: "#AssetBuilder_FileNew", a4: v12, a5: this, a6: nullptr);
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "FileOpen");
  else
    v14 = nullptr;
  v10->AddMenuItem(this: v10, a2: "open", a3: "#AssetBuilder_FileOpen", a4: v14, a5: this, a6: nullptr);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "FileSave");
  else
    v16 = nullptr;
  v10->AddMenuItem(this: v10, a2: "save", a3: "#AssetBuilder_FileSave", a4: v16, a5: this, a6: nullptr);
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v17 != nullptr )
    v18 = KeyValues::KeyValues(this: v17, setName: "FileSaveAs");
  else
    v18 = nullptr;
  v10->AddMenuItem(this: v10, a2: "saveas", a3: "#AssetBuilder_FileSaveAs", a4: v18, a5: this, a6: nullptr);
  vgui::Frame::SetSysMenu(this, menu: v10);
  v19 = (vgui::FileOpenStateMachine *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v19 != nullptr )
    v20 = vgui::FileOpenStateMachine::FileOpenStateMachine(
            this: v19,
            pParent: this,
            pClient: &this->vgui::IFileOpenStateMachineClient);
  else
    v20 = nullptr;
  this->m_pFileOpenStateMachine = v20;
  v20->AddActionSignalTarget_2(this: v20, a2: this);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetbuilderframe.res",
    dialogID: 0);
  CAssetBuilderFrame::UpdateFileName(this, a2: (int)v10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00477260
// Name: private: void CAssetBuilderFrame::ShowNewAssetPicker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::ShowNewAssetPicker(CAssetBuilderFrame *this)
{
  CPickerFrame *v2; // eax
  CPickerFrame *v3; // eax

  BuildAssetTypeList();
  v2 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v2 != nullptr )
  {
    v3 = CPickerFrame::CPickerFrame(
           this: v2,
           pParent: this,
           pTitle: "Select Asset Type",
           pPickerType: "Asset Type",
           pTextType: "assetType");
    CPickerFrame::DoModal(this: v3, list: &s_AssetTypes, pContextKeyValues: nullptr);
  }
  else
  {
    CPickerFrame::DoModal(this: nullptr, list: &s_AssetTypes, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477390
// Name: public: virtual CAssetBuilder::~CAssetBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::~CAssetBuilder(CAssetBuilder *this)
{
  bool v2; // zf
  vgui::Panel *v3; // eax

  v2 = (*((_BYTE *)this + 492) & 2) == 0;
  this->__vftable = (CAssetBuilder_vtbl *)&CAssetBuilder::`vftable';
  if ( !v2 )
    CAssetBuilder::CleanupMakefile(this);
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v3->MarkForDeletion(this: v3);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  CUtlVector<CDmeHandle<CDmeSourceMayaFile,0>,CUtlMemory<CDmeHandle<CDmeSourceMayaFile,0>,int>>::Purge(this: (CUtlVector<CDmeHandle<CDmeSourceMayaFile,0>,CUtlMemory<CDmeHandle<CDmeSourceMayaFile,0>,int> > *)&this->m_hMakefileStack);
  if ( this->m_hMakefileStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_hMakefileStack.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hMakefileStack.m_Memory.m_pMemory);
      this->m_hMakefileStack.m_Memory.m_pMemory = nullptr;
    }
    this->m_hMakefileStack.m_Memory.m_nAllocationCount = 0;
  }
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(this: &this->m_hMakefile, hElement: this->m_hMakefile.m_handle, handleType: HT_WEAK);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hRootMakefile,
      hElement: this->m_hRootMakefile.m_handle,
      handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00477460
// Name: private: void CAssetBuilder::RefreshSourceList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::RefreshSourceList(CAssetBuilder *this@<ecx>, char *a2@<edi>, int a3@<esi>)
{
  int v4; // eax
  DmeMakefileType_t *v5; // eax
  KeyValues *v6; // esi
  DmElementHandle_t m_handle; // eax
  CDmeMakefile *v8; // eax
  int v9; // edi
  int v10; // eax
  CDmeMakefile *v11; // eax
  KeyValues *v12; // eax
  CExpressionCalculator *v13; // eax
  int BufferType; // eax
  int v15; // ecx
  CDmeSource *v16; // [esp-Ch] [ebp-138h]
  char pFullPath[260]; // [esp+4h] [ebp-128h] BYREF
  DmeMakefileType_t *pSourceTypes; // [esp+108h] [ebp-24h]
  int nCount; // [esp+10Ch] [ebp-20h]
  CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int> > sources; // [esp+110h] [ebp-1Ch] BYREF
  int i; // [esp+124h] [ebp-8h]
  DmeMakefileType_t *v24; // [esp+128h] [ebp-4h]

  this->m_pSourcesList->RemoveAll(this: this->m_pSourcesList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hMakefile.m_handle);
    v5 = (DmeMakefileType_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 60))(a1: v4);
    v6 = nullptr;
    pSourceTypes = v5;
    i = 0;
    if ( v5->m_pTypeName != nullptr )
    {
      v24 = v5;
      do
      {
        m_handle = this->m_hMakefile.m_handle;
        memset(&sources, 0, sizeof(sources));
        v8 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                               a1: g_pDataModel.u,
                               a2: m_handle);
        CDmeMakefile::GetSources(this: v8, pSourceType: v24->m_pTypeName, &sources);
        v9 = 0;
        for ( nCount = sources.m_Size; v9 < nCount; v6 = nullptr )
        {
          v16 = (CDmeSource *)sources.m_Memory.m_pMemory[v9].m_handle;
          v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
          v11 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int, char *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hMakefile.m_handle,
                                  a3: v10,
                                  a4: pFullPath,
                                  a5: 260);
          CDmeMakefile::GetSourceFullPath(this: v11, pSource: v16, pFullPath: a2, nBufLen: a3);
          v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v12 != nullptr )
            v6 = KeyValues::KeyValues(
                   this: v12,
                   setName: "node",
                   firstKey: "type",
                   firstValue: v24->m_pHumanReadableName);
          KeyValues::SetString(this: v6, keyName: "file", value: pFullPath);
          KeyValues::SetInt(this: v6, keyName: "sourceTypeIndex", value: i);
          KeyValues::SetInt(this: v6, keyName: "index", value: v9);
          v13 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                           a1: g_pDataModel.u,
                                           a2: sources.m_Memory.m_pMemory[v9].m_handle);
          if ( v13 != nullptr )
            BufferType = CCodecBuffer_Block::GetBufferType(this: v13);
          else
            BufferType = -1;
          KeyValues::SetInt(this: v6, keyName: "dmeSource", value: BufferType);
          a3 = 0;
          a2 = nullptr;
          ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD))this->m_pSourcesList->AddItem)(
            a1: this->m_pSourcesList,
            a2: v6,
            a3: 0);
          ++v9;
        }
        CUtlVector<CDmeHandle<CDmeSourceMayaFile,0>,CUtlMemory<CDmeHandle<CDmeSourceMayaFile,0>,int>>::Purge(this: (CUtlVector<CDmeHandle<CDmeSourceMayaFile,0>,CUtlMemory<CDmeHandle<CDmeSourceMayaFile,0>,int> > *)&sources);
        if ( sources.m_Memory.m_nGrowSize >= 0 && sources.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sources.m_Memory.m_pMemory);
        v15 = ++i;
        v24 = &pSourceTypes[v15];
      }
      while ( v24->m_pTypeName != nullptr );
    }
    this->m_pSourcesList->SortList(this: this->m_pSourcesList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477660
// Name: private: virtual void CAssetBuilder::OnRemoveSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnRemoveSource(CAssetBuilder *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  KeyValues *v6; // eax
  int Int; // eax
  int v8; // eax
  CExpressionCalculator *v9; // edi
  CDmeMakefile *v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  CDmeSource *BufferType; // [esp+0h] [ebp-20h]
  char guard_4; // [esp+10h] [ebp-10h]
  int nCount; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int nRow; // [esp+1Ch] [ebp-4h]

  nCount = this->m_pSourcesList->GetSelectedItemsCount(this: this->m_pSourcesList);
  if ( nCount != 0
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0 )
  {
    v2 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
    if ( v2 == -1 )
    {
      nRow = -1;
      v3 = -1;
    }
    else
    {
      v3 = this->m_pSourcesList->GetItemCurrentRow(this: this->m_pSourcesList, a2: v2);
      nRow = v3;
    }
    guard_4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    v4 = 0;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v5 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: v4);
        v6 = this->m_pSourcesList->GetItem(this: this->m_pSourcesList, a2: v5);
        Int = KeyValues::GetInt(this: v6, keyName: "dmeSource", defaultValue: -1);
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: Int);
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeSource::m_classType.u) != 0 )
        {
          v10 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, CExpressionCalculator *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hMakefile.m_handle,
                                  a3: v9);
          CDmeMakefile::RemoveSource(this: v10, pSource: BufferType);
          v11 = *(_DWORD *)g_pDataModel.u.m_Id;
          BufferType = (CDmeSource *)CCodecBuffer_Block::GetBufferType(this: v9);
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(v11 + 68))(a1: g_pDataModel.u);
          this->SetDirty(this);
          v4 = i;
        }
        i = ++v4;
      }
      while ( v4 < nCount );
      v3 = nRow;
    }
    CAssetBuilder::RefreshSourceList(this, a2: (char *)v3, a3: (int)this);
    v12 = this->m_pSourcesList->GetItemCount(this: this->m_pSourcesList);
    if ( v12 != 0 && v3 >= 0 )
    {
      if ( v3 >= v12 )
        v3 = v12 - 1;
      v13 = this->m_pSourcesList->GetItemIDFromRow(this: this->m_pSourcesList, a2: v3);
      this->m_pSourcesList->SetSingleSelectedItem(this: this->m_pSourcesList, a2: v13);
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: guard_4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477830
// Name: private: void CAssetBuilder::OnSourceFileAdded(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnSourceFileAdded(CAssetBuilder *this, const char *pFileName, const char *pTypeName)
{
  unsigned __int8 (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  CDmeMakefile *v5; // eax
  char *v6; // edi
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  v4 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v4)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  v5 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hMakefile.m_handle);
  v6 = (char *)CDmeMakefile::AddSource(this: v5, pSourceType: pTypeName, pFullPath: pFileName);
  CChangeUndoScopeGuard::Release(this: &guard);
  this->SetDirty(this);
  CAssetBuilder::RefreshSourceList(this, a2: v6, a3: (int)this);
  CAssetBuilder::SelectSource(this, pSource: (CDmeSource *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x004778C0
// Name: private: void CAssetBuilder::FinishCompilation(enum CompilationState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::FinishCompilation(CAssetBuilder *this, CompilationState_t state)
{
  int v3; // eax
  int v4; // edi
  CDmElement *v5; // eax
  int v6; // eax
  int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int v10; // eax
  CCompileStatusBar *m_pCompileStatusBar; // esi
  vgui::Label *m_pStatus; // ecx
  CCompileStatusBar *v13; // esi
  vgui::Label *v14; // ecx
  char pBuf[256]; // [esp+8h] [ebp-100h] BYREF

  CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  v3 = this->m_pSourcesList->GetSelectedItem(this: this->m_pSourcesList, a2: 0);
  if ( v3 == -1 )
    v4 = -1;
  else
    v4 = this->m_pSourcesList->GetItemCurrentRow(this: this->m_pSourcesList, a2: v3);
  v5 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hMakefile.m_handle);
  CDmePanel::SetDmeElement(
    this: this->m_pOututPreviewPanel,
    pDmeElement: v5,
    bForce: true,
    pPanelName: "DmeMakeFileOutputPreview");
  *((_BYTE *)this + 492) &= ~1u;
  CAssetBuilder::RefreshSourceList(this, a2: (char *)v4, a3: (int)this);
  v6 = this->m_pSourcesList->GetItemCount(this: this->m_pSourcesList);
  if ( v6 != 0 && v4 >= 0 )
  {
    if ( v4 >= v6 )
      v4 = v6 - 1;
    v7 = this->m_pSourcesList->GetItemIDFromRow(this: this->m_pSourcesList, a2: v4);
    this->m_pSourcesList->SetSingleSelectedItem(this: this->m_pSourcesList, a2: v7);
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "UpdateFileName");
  else
    v9 = nullptr;
  this->PostActionSignal(this, a2: v9);
  if ( state == 2 )
  {
    v10 = g_pDmeMakefileUtils->GetExitCode(this: g_pDmeMakefileUtils);
    V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "Compilation Error (return code %d)", v10);
    m_pCompileStatusBar = this->m_pCompileStatusBar;
    m_pStatus = m_pCompileStatusBar->m_pStatus;
    m_pCompileStatusBar->m_Status = COMPILATION_FAILED;
    m_pStatus->SetText_2(this: m_pStatus, a2: pBuf);
  }
  else
  {
    v13 = this->m_pCompileStatusBar;
    v14 = v13->m_pStatus;
    v13->m_Status = COMPILATION_SUCCESSFUL;
    v14->SetText_2(this: v14, a2: "Compile Successful!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477A40
// Name: public: virtual void CAssetBuilder::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnTick(CAssetBuilder *this)
{
  int v2; // edi
  void *v3; // esp
  CompilationState_t v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebx
  int v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-10h] BYREF
  CompilationState_t state; // [esp+Ch] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  if ( (*((_BYTE *)this + 492) & 1) == 0 )
    goto LABEL_7;
  v2 = g_pDmeMakefileUtils->GetCompileOutputSize(this: g_pDmeMakefileUtils);
  v3 = alloca(v2 + 1);
  v4 = g_pDmeMakefileUtils->UpdateCompilation(this: g_pDmeMakefileUtils, a2: v8, a3: v2);
  state = v4;
  if ( v2 > 0 )
  {
    this->m_pCompileOutput->InsertString_2(this: this->m_pCompileOutput, a2: v8);
    v4 = state;
  }
  if ( v4 != COMPILATION_NOT_COMPLETE )
    CAssetBuilder::FinishCompilation(this, state: v4);
  if ( (*((_BYTE *)this + 492) & 1) == 0 )
  {
LABEL_7:
    this->m_pAbortCompile->SetEnabled(this: this->m_pAbortCompile, a2: false);
    v5 = g_pVGui;
    v6 = g_pVGui->__vftable;
    v7 = this->GetVPanel(this);
    v6->RemoveTickSignal(this: v5, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477AF0
// Name: private: virtual void CAssetBuilderFrame::OnFileStateMachineFinished(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::OnFileStateMachineFinished(CAssetBuilderFrame *this, KeyValues *pKeyValues)
{
  int v3; // eax

  if ( KeyValues::FindKey(this: pKeyValues, keyName: "FileNew", bCreate: false) != nullptr )
  {
    if ( KeyValues::GetInt(this: pKeyValues, keyName: "wroteFile", defaultValue: 0) != 0 )
    {
      v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_pAssetBuilder->m_hMakefile.m_handle);
      if ( v3 != 0 && *(_BYTE *)(v3 + 104) != 0 )
      {
        *(_BYTE *)(v3 + 104) = 0;
        this->UpdateFileName(this);
      }
      this->UpdateFileName(this);
    }
    if ( KeyValues::GetInt(this: pKeyValues, keyName: "completionState", defaultValue: 0) == 1 )
      CAssetBuilderFrame::ShowNewAssetPicker(this);
  }
  else if ( KeyValues::FindKey(this: pKeyValues, keyName: "FileSave", bCreate: false) != nullptr
         && KeyValues::GetInt(this: pKeyValues, keyName: "wroteFile", defaultValue: 0) != 0 )
  {
    CAssetBuilderFrame::SetDirty(this, bDirty: false);
    this->UpdateFileName(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477BF0
// Name: private: void CAssetBuilder::RefreshOutputList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::RefreshOutputList(CAssetBuilder *this@<ecx>, int a2@<edi>)
{
  KeyValues *v3; // esi
  DmElementHandle_t m_handle; // eax
  int v5; // eax
  int v6; // edi
  KeyValues *v7; // eax
  const char *v8; // eax
  BOOL v9; // edi
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > outputs; // [esp+8h] [ebp-1Ch] BYREF
  int bEnabled; // [esp+1Ch] [ebp-8h]
  unsigned int v13; // [esp+20h] [ebp-4h]

  this->m_pOutputList->RemoveAll(this: this->m_pOutputList);
  v3 = nullptr;
  this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: false);
  this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: false);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hMakefile.m_handle) != 0 )
  {
    m_handle = this->m_hMakefile.m_handle;
    memset(&outputs, 0, sizeof(outputs));
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
           a1: g_pDataModel.u,
           a2: m_handle,
           a3: a2);
    (*(void (__thiscall **)(int, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))(*(_DWORD *)v5 + 64))(
      a1: v5,
      a2: &outputs);
    v6 = 0;
    bEnabled = outputs.m_Size;
    if ( outputs.m_Size <= 0 )
      goto LABEL_11;
    v13 = 0;
    while ( 1 )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v3 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "type", firstValue: "Output");
      v8 = CUtlString::operator char const *(this: &outputs.m_Memory.m_pMemory[v13 / 0x10]);
      KeyValues::SetString(this: v3, keyName: "file", value: v8);
      KeyValues::SetInt(this: v3, keyName: "index", value: v6);
      this->m_pOutputList->AddItem(this: this->m_pOutputList, a2: v3, a3: 0, a4: false, a5: false);
      v13 += 16;
      if ( ++v6 >= bEnabled )
        break;
      v3 = nullptr;
    }
    if ( bEnabled > 0 && g_pDmeMakefileUtils != nullptr )
      LOBYTE(bEnabled) = 1;
    else
LABEL_11:
      LOBYTE(bEnabled) = 0;
    v9 = bEnabled;
    this->m_pCompile->SetEnabled(this: this->m_pCompile, a2: bEnabled);
    this->m_pPublish->SetEnabled(this: this->m_pPublish, a2: v9);
    this->m_pOutputList->SortList(this: this->m_pOutputList);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &outputs);
    m_pMemory = outputs.m_Memory.m_pMemory;
    if ( outputs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( outputs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        outputs.m_Memory.m_pMemory = nullptr;
      }
      outputs.m_Memory.m_nAllocationCount = 0;
    }
    outputs.m_pElements = m_pMemory;
    if ( outputs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477DB0
// Name: private: virtual void CAssetBuilder::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnPicked(CAssetBuilder *this, KeyValues *kv)
{
  const char *String; // edi
  unsigned __int8 (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  int v5; // eax
  int v6; // eax
  CDmeMakefile *v7; // esi
  const char **v8; // ebx
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::FileOpenDialog *v11; // eax
  vgui::FileOpenDialog *v12; // edi
  int v13; // edi
  int BufferType; // eax
  char pContext[260]; // [esp+Ch] [ebp-214h] BYREF
  char pStartingDir[260]; // [esp+110h] [ebp-110h] BYREF
  vgui::Panel *parent; // [esp+214h] [ebp-Ch]
  CDisableUndoScopeGuard guard; // [esp+218h] [ebp-8h] BYREF

  parent = this;
  String = KeyValues::GetString(this: kv, keyName: "choice", defaultValue: defaultValue);
  if ( KeyValues::FindKey(this: kv, keyName: "OnAddSource", bCreate: false) != nullptr )
  {
    CAssetBuilder::OnSourceFileAdded(this, pFileName: defaultValue, pTypeName: String);
  }
  else
  {
    v4 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v4)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
           a1: g_pDataModel.u,
           a2: String,
           a3: "unnamed",
           a4: -1,
           a5: 0);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v5);
    v7 = (CDmeMakefile *)v6;
    if ( v6 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeMakefile::m_classType.u) != 0 )
    {
      v8 = (const char **)v7->GetMakefileType(this: v7);
      V_snprintf(pDest: pContext, maxLen: 260, pFormat: "asset_builder_session_%s", *v8);
      CDmeMakefile::GetDefaultDirectory(this: v7, pDefaultDirectoryID: v8[3], pFullPath: pStartingDir, nBufLen: 260);
      g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(
                this: v9,
                setName: "NewSourceFileSelected",
                firstKey: "makefileType",
                firstValue: String);
      else
        v10 = nullptr;
      v11 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
      if ( v11 != nullptr )
        v12 = vgui::FileOpenDialog::FileOpenDialog(
                this: v11,
                parent,
                title: "Select Asset Builder File Name",
                bOpenOnly: false,
                pContextKeyValues: v10);
      else
        v12 = nullptr;
      vgui::FileOpenDialog::SetStartDirectoryContext(this: v12, pStartDirContext: pContext, pDefaultDir: pStartingDir);
      vgui::FileOpenDialog::AddFilter(this: v12, filter: v8[4], filterName: v8[5], bActive: true, pFilterInfo: nullptr);
      v12->AddActionSignalTarget_2(this: v12, a2: parent);
      vgui::FileOpenDialog::DoModal(this: v12, bUnused: false);
      v13 = *(_DWORD *)g_pDataModel.u.m_Id;
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v13 + 68))(a1: g_pDataModel.u, a2: BufferType);
    }
    CChangeUndoScopeGuard::Release(this: &guard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477F90
// Name: public: void CAssetBuilder::SetCurrentMakefile(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SetCurrentMakefile(CAssetBuilder *this, CExpressionCalculator *pMakeFile)
{
  DmElementHandle_t BufferType; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( pMakeFile != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pMakeFile);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hMakefile, h: BufferType);
  CDmePanel::SetDmeElement(this: this->m_pDmePanel, pDmeElement: nullptr, bForce: false, pPanelName: nullptr);
  CDmePanel::SetDmeElement(
    this: this->m_pOututPreviewPanel,
    pDmeElement: (CDmElement *)pMakeFile,
    bForce: true,
    pPanelName: "DmeMakeFileOutputPreview");
  CAssetBuilder::RefreshSourceList(this, a2: (char *)pMakeFile, a3: (int)this);
  CAssetBuilder::RefreshOutputList(this, a2: (int)pMakeFile);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "UpdateFileName");
    this->PostActionSignal(this, a2: v5);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478030
// Name: private: virtual void CAssetBuilder::OnZoomInSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::OnZoomInSource(CAssetBuilder *this)
{
  CDmeSource *SelectedSource; // esi
  CDmeMakefile *v3; // eax
  CExpressionCalculator *DependentMakefile; // eax
  CExpressionCalculator *v5; // edi
  DmElementHandle_t BufferType; // esi
  int v7; // eax
  CDmeHandle<CDmeMakefile,0> *m_pMemory; // eax
  CDmeHandle<CDmeMakefile,0> *v9; // ecx
  CDmeHandle<CDmeMakefile,0> hChild; // [esp+Ch] [ebp-4h] BYREF

  SelectedSource = CAssetBuilder::GetSelectedSource(this);
  if ( SelectedSource != nullptr )
  {
    v3 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hMakefile.m_handle);
    DependentMakefile = (CExpressionCalculator *)CDmeMakefile::FindDependentMakefile(this: v3, pSource: SelectedSource);
    v5 = DependentMakefile;
    if ( DependentMakefile != nullptr )
    {
      hChild.m_handle = DMELEMENT_HANDLE_INVALID;
      BufferType = CCodecBuffer_Block::GetBufferType(this: DependentMakefile);
      if ( BufferType != DMELEMENT_HANDLE_INVALID )
      {
        CDmeElementRefHelper::Unref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
        hChild.m_handle = BufferType;
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: BufferType);
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeMakefile::m_classType.u) == 0 )
        {
          hChild.m_handle = DMELEMENT_HANDLE_INVALID;
        }
        CDmeElementRefHelper::Ref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
      }
      if ( this->m_hMakefileStack.m_Size >= this->m_hMakefileStack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hMakefileStack,
          num: 1);
      ++this->m_hMakefileStack.m_Size;
      m_pMemory = this->m_hMakefileStack.m_Memory.m_pMemory;
      v9 = &m_pMemory[this->m_hMakefileStack.m_Size - 1];
      this->m_hMakefileStack.m_pElements = m_pMemory;
      if ( v9 != nullptr )
      {
        v9->m_handle = DMELEMENT_HANDLE_INVALID;
        CDmeHandle<CDmeMakefile,0>::Set(this: v9, h: hChild.m_handle);
      }
      CAssetBuilder::SetCurrentMakefile(this, pMakeFile: v5);
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hChild, hElement: hChild.m_handle, handleType: HT_WEAK);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478150
// Name: private: virtual void CAssetBuilder::OnZoomOutSource(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAssetBuilder::OnZoomOutSource(CAssetBuilder *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CDmeMakefile *v4; // ebx
  CDmeElementRefHelper *v5; // ecx
  CExpressionCalculator *v6; // eax
  CDmeMakefile *v7; // edi
  CDmeSource *AssociatedSource; // eax

  if ( this->m_hMakefileStack.m_Size > 1 )
  {
    v4 = (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hMakefileStack.m_Memory.m_pMemory[this->m_hMakefileStack.m_Size - 1].m_handle,
                           a3: a2);
    if ( g_pDataModel.u.m_Id != 0 )
    {
      v5 = &this->m_hMakefileStack.m_Memory.m_pMemory[this->m_hMakefileStack.m_Size - 1];
      CDmeElementRefHelper::Unref(this: v5, hElement: *(_DWORD *)v5, handleType: HT_WEAK);
    }
    v6 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                    a1: g_pDataModel.u,
                                    a2: this->m_hMakefileStack.m_Memory.m_pMemory[--this->m_hMakefileStack.m_Size - 1].m_handle,
                                    a3);
    v7 = (CDmeMakefile *)v6;
    if ( v6 != nullptr )
    {
      CAssetBuilder::SetCurrentMakefile(this, pMakeFile: v6);
      AssociatedSource = CDmeMakefile::FindAssociatedSource(this: v7, pChildMakefile: v4);
      if ( AssociatedSource != nullptr )
        CAssetBuilder::SelectSource(this, pSource: AssociatedSource);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478200
// Name: public: virtual bool CAssetBuilderFrame::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAssetBuilderFrame::OnWriteFileToDisk(
        CAssetBuilderFrame *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  int v5; // edi
  unsigned __int8 (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  vgui::MessageBox *v7; // eax
  vgui::MessageBox *v8; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  bool v14; // zf
  int v15; // esi
  int v16; // eax
  char v17; // al
  CAssetBuilder *v18; // esi
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-Ch] BYREF
  bool bOk; // [esp+17h] [ebp-1h]

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *(_DWORD *)(*(_DWORD *)&this->m_OnCommand_register + 468));
  v6 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v6)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  bOk = CDmeMakefile::SetFileName(this: (CDmeMakefile *)v5, pFileName);
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( bOk )
  {
    v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 380))(
            a1: g_pDataModel.u,
            a2: *(_DWORD *)(v5 + 56));
    v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
            a1: g_pDataModel.u,
            a2: v10);
    v12 = v11;
    if ( v11 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
           a1: v11,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v12 = 0;
    }
    v13 = v12;
    v14 = v12 == 0;
    v15 = *(_DWORD *)g_pDataModel.u.m_Id;
    if ( v14 )
      v13 = v5;
    v16 = (*(int (__stdcall **)(const char *, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 124))(
            a1: pFileFormat,
            a2: pFileFormat,
            a3: v13);
    v17 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(v15 + 184))(
            a1: g_pDataModel.u,
            a2: pFileName,
            a3: 0,
            a4: v16);
    v18 = *(CAssetBuilder **)&this->m_OnCommand_register;
    bOk = v17;
    CAssetBuilder::RefreshSourceList(this: v18, a2: (char *)v5, a3: (int)v18);
    CAssetBuilder::RefreshOutputList(this: v18, a2: v5);
    return bOk;
  }
  else
  {
    v7 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v7 != nullptr )
      v8 = vgui::MessageBox::MessageBox(
             this: v7,
             title: "#AssetBuilder_CannotRenameSourceFiles",
             text: "#AssetBuilder_CannotRenameSourceFilesText",
             parent: (CAssetBuilderFrame *)((char *)this - 528));
    else
      v8 = nullptr;
    v8->DoModal_2(this: v8, a2: nullptr);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478350
// Name: public: void CAssetBuilder::SetRootMakefile(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilder::SetRootMakefile(CAssetBuilder *this, CExpressionCalculator *pMakeFile)
{
  DmElementHandle_t BufferType; // eax
  CDmeHandle<CDmeMakefile,0> *m_pMemory; // eax
  CDmeHandle<CDmeMakefile,0> *v5; // ecx

  CAssetBuilder::CleanupMakefile(this);
  if ( pMakeFile != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: pMakeFile);
    CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_hRootMakefile, h: BufferType);
    if ( this->m_hMakefileStack.m_Size >= this->m_hMakefileStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hMakefileStack,
        num: 1);
    ++this->m_hMakefileStack.m_Size;
    m_pMemory = this->m_hMakefileStack.m_Memory.m_pMemory;
    v5 = &m_pMemory[this->m_hMakefileStack.m_Size - 1];
    this->m_hMakefileStack.m_pElements = m_pMemory;
    if ( v5 != nullptr )
    {
      v5->m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmeMakefile,0>::Set(this: v5, h: this->m_hRootMakefile.m_handle);
    }
  }
  CAssetBuilder::SetCurrentMakefile(this, pMakeFile);
}

//------------------------------------------------------------------------------
// Address: 0x004783E0
// Name: public: virtual void CAssetBuilderFrame::SetupFileOpenDialog(class vgui::FileOpenDialog __near *,bool,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::SetupFileOpenDialog(
        CAssetBuilderFrame *this,
        vgui::FileOpenDialog *pDialog,
        bool bOpenFile,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  CAssetBuilder *v6; // esi
  const char *v7; // [esp-8h] [ebp-110h]
  char pStartingDir[260]; // [esp+4h] [ebp-104h] BYREF

  GetModContentSubdirectory(pSubDir: defaultValue, pBuf: pStartingDir, nBufLen: 260);
  if ( bOpenFile )
  {
    v6 = *(CAssetBuilder **)&this->m_OnCommand_register;
    CAssetBuilder::CleanupMakefile(this: v6);
    CAssetBuilder::SetCurrentMakefile(this: v6, pMakeFile: nullptr);
    v7 = "Open Asset MakeFile";
  }
  else
  {
    v7 = "Save Asset MakeFile As";
  }
  pDialog->SetTitle_2(this: pDialog, a2: v7, a3: true);
  vgui::FileOpenDialog::SetStartDirectoryContext(
    this: pDialog,
    pStartDirContext: "asset_browser_makefile",
    pDefaultDir: pStartingDir);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.*",
    filterName: "All Files (*.*)",
    bActive: false,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.dmx",
    filterName: "Asset MakeFiles (*.dmx)",
    bActive: true,
    pFilterInfo: "keyvalues2");
}

//------------------------------------------------------------------------------
// Address: 0x00478490
// Name: private: virtual void CAssetBuilderFrame::OnPerformFileNew(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetBuilderFrame::OnPerformFileNew(CAssetBuilderFrame *this, KeyValues *kv)
{
  const char *String; // ebx
  const char *v4; // esi
  unsigned __int8 (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  int v6; // eax
  int v7; // eax
  CDmeMakefile *v8; // ebx
  int v9; // eax
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-8h] BYREF
  DmFileId_t fileid; // [esp+1Ch] [ebp+8h]

  String = KeyValues::GetString(this: kv, keyName: "makefileType", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: kv, keyName: "fileName", defaultValue: defaultValue);
  fileid = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 356))(
             a1: g_pDataModel.u,
             a2: v4);
  v5 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: String,
         a3: v4,
         a4: fileid,
         a5: 0);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v6);
  v8 = (CDmeMakefile *)v7;
  if ( v7 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmeMakefile::m_classType.u) == 0 )
  {
    v8 = nullptr;
  }
  CChangeUndoScopeGuard::Release(this: &guard);
  if ( v8 != nullptr )
  {
    CDmeMakefile::SetFileName(this: v8, pFileName: v4);
    CAssetBuilder::SetRootMakefile(this: this->m_pAssetBuilder, pMakeFile: (CExpressionCalculator *)v8);
    this->UpdateFileName(this);
    v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_pAssetBuilder->m_hMakefile.m_handle);
    if ( v9 != 0 && *(_BYTE *)(v9 + 104) != 1 )
    {
      *(_BYTE *)(v9 + 104) = 1;
      this->UpdateFileName(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004785C0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CAssetBuilder,class CDmeMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetBuilder *__thiscall CDmePanelFactory<CAssetBuilder,CDmeMakefile>::CreateDmePanel(
        CDmePanelFactory<CAssetBuilder,CDmeMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmElement *pElement)
{
  CExpressionCalculator *v4; // esi
  CAssetBuilder *v5; // eax
  CAssetBuilder *v6; // edi

  v4 = (CExpressionCalculator *)pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CAssetBuilder *)MemAlloc_Alloc(nSize: 0x1F0u);
  if ( v5 != nullptr )
  {
    v6 = CAssetBuilder::CAssetBuilder(this: v5, pParent, pPanelName);
    CAssetBuilder::SetRootMakefile(this: v6, pMakeFile: v4);
    return v6;
  }
  else
  {
    CAssetBuilder::SetRootMakefile(this: nullptr, pMakeFile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478630
// Name: public: virtual void CDmePanelFactory<class CAssetBuilder,class CDmeMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CAssetBuilder,CDmeMakefile>::SetDmeElement(
        CDmePanelFactory<CAssetBuilder,CDmeMakefile> *this,
        CAssetBuilder *pPanel,
        CDmElement *pElement)
{
  CAssetBuilder::SetRootMakefile(this: pPanel, pMakeFile: (CExpressionCalculator *)pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00478650
// Name: public: virtual bool CAssetBuilderFrame::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetBuilderFrame::OnReadFileFromDisk(
        CAssetBuilderFrame *this,
        CDmElement *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  CExpressionCalculator *v5; // eax

  v5 = (CExpressionCalculator *)ReadMakefile((const char *)pFileName, ppRoot: &pFileName);
  if ( v5 == nullptr )
    return 0;
  CAssetBuilder::SetRootMakefile(this: *(CAssetBuilder **)&this->m_OnCommand_register, pMakeFile: v5);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 132) + 1152))(a1: (char *)this - 528);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047ECB0
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDag>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDag> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeDag *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pScene: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x004801D0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDag>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDag> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDag *pElement)
{
  CDmeDag *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pScene: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pScene: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480240
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pSkin: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pSkin: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004802B0
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pSkin: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00480590
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceAnimation>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceAnimation *pElement)
{
  CDmeSourceAnimation *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceAnimation::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pAnimation: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pAnimation: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480600
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeSourceAnimation>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeSourceAnimation *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pAnimation: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00480620
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDCCMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeDCCMakefile *pElement)
{
  CDmeDCCMakefile *v4; // esi
  CDmeDagRenderPanel *v5; // eax
  CDmeDagRenderPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeDCCMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v5 != nullptr )
  {
    v6 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v5, pParent, pName: pPanelName);
    CDmeDagRenderPanel::SetDmeElement(this: v6, pDCCMakefile: v4);
    return v6;
  }
  else
  {
    CDmeDagRenderPanel::SetDmeElement(this: nullptr, pDCCMakefile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480690
// Name: public: virtual void CDmePanelFactory<class CDmeDagRenderPanel,class CDmeDCCMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile> *this,
        CDmeDagRenderPanel *pPanel,
        CDmeDCCMakefile *pElement)
{
  CDmeDagRenderPanel::SetDmeElement(this: pPanel, pDCCMakefile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0048E640
// Name: public: virtual void CDmePanelFactory<class CDmeSourceSkinPanel,class CDmeSourceSkin>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::SetDmeElement(
        CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin> *this,
        CDmeSourceSkinPanel *pPanel,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkinPanel::SetDmeElement(this: pPanel, pSourceSkin: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0048E920
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeSourceSkinPanel,class CDmeSourceSkin>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceSkinPanel *__thiscall CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::CreateDmePanel(
        CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceSkin *pElement)
{
  CDmeSourceSkin *v4; // esi
  CDmeSourceSkinPanel *v5; // eax
  CDmeSourceSkinPanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceSkin::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeSourceSkinPanel *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v5 != nullptr )
  {
    v6 = CDmeSourceSkinPanel::CDmeSourceSkinPanel(this: v5, pParent, pPanelName);
    CDmeSourceSkinPanel::SetDmeElement(this: v6, pSourceSkin: v4);
    return v6;
  }
  else
  {
    CDmeSourceSkinPanel::SetDmeElement(this: nullptr, pSourceSkin: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F510
// Name: public: virtual void CDmePanelFactory<class CDmeSourceDCCFilePanel,class CDmeSourceDCCFile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::SetDmeElement(
        CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile> *this,
        CDmeSourceDCCFilePanel *pPanel,
        CDmeSourceDCCFile *pElement)
{
  CDmeSourceDCCFilePanel::SetDmeElement(this: pPanel, pSourceDCCFile: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0048FBE0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeSourceDCCFilePanel,class CDmeSourceDCCFile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceDCCFilePanel *__thiscall CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::CreateDmePanel(
        CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeSourceDCCFile *pElement)
{
  CDmeSourceDCCFile *v4; // esi
  CDmeSourceDCCFilePanel *v5; // eax
  CDmeSourceDCCFilePanel *v6; // edi

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeSourceDCCFile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeSourceDCCFilePanel *)MemAlloc_Alloc(nSize: 0x1A0u);
  if ( v5 != nullptr )
  {
    v6 = CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(this: v5, pParent, pPanelName);
    CDmeSourceDCCFilePanel::SetDmeElement(this: v6, pSourceDCCFile: v4);
    return v6;
  }
  else
  {
    CDmeSourceDCCFilePanel::SetDmeElement(this: nullptr, pSourceDCCFile: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048FDC0
// Name: public: virtual class vgui::EditablePanel __near * CDmePanelFactory<class CDmeMDLPanel,class CDmeMDLMakefile>::CreateDmePanel(class vgui::Panel __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMDLPanel *__thiscall CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::CreateDmePanel(
        CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile> *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        CDmeMakefile *pElement)
{
  CDmeMakefile *v4; // esi
  CDmeMDLPanel *v5; // eax
  CDmeMDLPanel *v6; // edi
  CDmElement *OutputElement; // eax
  CDmeMDL *v8; // esi
  CDmeMDLPanel_vtbl *v9; // ebx
  unsigned __int16 MDL; // ax

  v4 = pElement;
  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeMDLMakefile::m_classType.u.m_Id) )
  {
    v4 = nullptr;
  }
  v5 = (CDmeMDLPanel *)MemAlloc_Alloc(nSize: 0xBE8u);
  if ( v5 != nullptr )
    v6 = CDmeMDLPanel::CDmeMDLPanel(this: v5, pParent, pName: pPanelName);
  else
    v6 = nullptr;
  if ( v4 != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: v4, bCreateIfNecessary: true);
    v8 = (CDmeMDL *)OutputElement;
    if ( OutputElement != nullptr && OutputElement->IsA(this: OutputElement, a2: CDmeMDL::m_classType) )
    {
      v9 = v6->__vftable;
      MDL = CDmeMDL::GetMDL(this: v8);
      v9->SetMDL_2(this: v6, a2: MDL, a3: nullptr);
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0048FE60
// Name: public: virtual void CDmePanelFactory<class CDmeMDLPanel,class CDmeMDLMakefile>::SetDmeElement(class vgui::EditablePanel __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::SetDmeElement(
        CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile> *this,
        vgui::EditablePanel *pPanel,
        CDmeMakefile *pElement)
{
  CDmElement *OutputElement; // eax
  CDmeMDL *v4; // esi
  vgui::EditablePanel_vtbl *v5; // edi
  unsigned __int16 MDL; // ax

  if ( pElement != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: pElement, bCreateIfNecessary: true);
    v4 = (CDmeMDL *)OutputElement;
    if ( OutputElement != nullptr && OutputElement->IsA(this: OutputElement, a2: CDmeMDL::m_classType) )
    {
      v5 = pPanel->__vftable;
      MDL = CDmeMDL::GetMDL(this: v4);
      ((void (__thiscall *)(vgui::EditablePanel *, _DWORD, _DWORD))v5[1].Repaint)(a1: pPanel, a2: MDL, a3: 0);
    }
  }
}

} // namespace sceneviewer
