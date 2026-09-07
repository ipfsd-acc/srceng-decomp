// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/baseassetpicker.cpp
// Functions: 85
// ============================================================

#include "vgui2\matsys_controls\baseassetpicker.h"

//------------------------------------------------------------------------------
// Address: 0x004B5930
// Name: public: static char const __near * CBaseAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPicker::GetPanelClassName()
{
  return "CBaseAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004B5940
// Name: public: static char const __near * CBaseAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPickerFrame::GetPanelClassName()
{
  return "CBaseAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004B5950
// Name: bool AssetTreeViewSortFunc(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AssetTreeViewSortFunc(KeyValues *node1, KeyValues *node2)
{
  const char *String; // esi
  const char *v3; // eax

  String = KeyValues::GetString(this: node1, keyName: "text", defaultValue: nullptr);
  v3 = KeyValues::GetString(this: node2, keyName: "text", defaultValue: nullptr);
  return _V_stricmp(s1: String, s2: v3) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B5990
// Name: public: static char const __near * CAssetTreeView::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetTreeView::GetPanelClassName()
{
  return "CAssetTreeView";
}

//------------------------------------------------------------------------------
// Address: 0x004B59A0
// Name: AssetBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  bool v3; // bl
  const char *String; // esi
  const char *v6; // eax

  v3 = KeyValues::GetInt(this: item1->kv, keyName: "root", defaultValue: 0) != 0;
  if ( v3 != (KeyValues::GetInt(this: item2->kv, keyName: "root", defaultValue: 0) != 0) )
    return 2 * !v3 - 1;
  String = KeyValues::GetString(this: item1->kv, keyName: "asset", defaultValue: defaultValue);
  v6 = KeyValues::GetString(this: item2->kv, keyName: "asset", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004B5A20
// Name: AssetBrowserModSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserModSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "modIndex", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "modIndex", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B5A70
// Name: AssetBrowserTimesUsedSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserTimesUsedSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "timesused", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "timesused", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B5AC0
// Name: public: bool CBaseAssetPicker::IsMultiselectEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAssetPicker::IsMultiselectEnabled(CBaseAssetPicker *this)
{
  return vgui::ListPanel::IsMultiselectEnabled(this: this->m_pAssetBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x004B5AD0
// Name: public: virtual void CBaseAssetPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnKeyCodeTyped(CBaseAssetPicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  vgui::IPanel *v5; // esi
  vgui::ListPanel *m_pAssetBrowser; // edi
  int v7; // eax
  int v8; // eax
  vgui::IPanel_vtbl *codea; // [esp+14h] [ebp+8h]

  if ( code == KEY_UP || code == KEY_DOWN || code == KEY_PAGEUP || code == KEY_PAGEDOWN )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "KeyCodeTyped", firstKey: "code", firstValue: code);
    else
      v4 = nullptr;
    v5 = g_pVGuiPanel;
    m_pAssetBrowser = this->m_pAssetBrowser;
    codea = g_pVGuiPanel->__vftable;
    v7 = this->GetVPanel(this);
    v8 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pAssetBrowser->GetVPanel)(
           a1: m_pAssetBrowser,
           a2: v4,
           a3: v7);
    ((void (__thiscall *)(vgui::IPanel *, int))codea->SendMessage)(a1: v5, a2: v8);
    KeyValues::deleteThis(this: v4);
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5B70
// Name: protected: bool CBaseAssetPicker::IsAssetVisible(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAssetPicker::IsAssetVisible(CBaseAssetPicker *this, const CachedAssetInfo_t *nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ecx
  int m_nCurrentModFilter; // eax
  const char *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-Ch] [ebp-10h]
  const CachedAssetInfo_t *info; // [esp+Ch] [ebp+8h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  info = v3;
  if ( m_nCurrentModFilter >= 0 && m_nCurrentModFilter != v3->m_nModIndex )
    return false;
  v6 = CUtlString::operator char const *(this: &v3->m_AssetName);
  v7 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
  if ( _V_strcmp(s1: v6, s2: v7) == 0 )
    return true;
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
  {
    v8 = CUtlString::Get(this: &this->m_Filter);
    if ( V_stristr(pStr: v6, pSearch: v8) == nullptr )
      return false;
  }
  if ( CUtlString::Length(this: &this->m_FolderFilter) != 0 )
  {
    v12 = CUtlString::Length(this: &this->m_FolderFilter);
    v9 = CUtlString::Get(this: &this->m_FolderFilter);
    if ( V_strnicmp(s1: v6, s2: v9, n: v12) != 0 )
      return false;
  }
  if ( (*((_BYTE *)this + 544) & 8) == 0 )
  {
    v10 = CUtlString::Length(this: &this->m_FolderFilter);
    strchr(string: (unsigned __int8 *)&v6[v10], chr: 0x5Cu);
    if ( v11 != 0 )
      return false;
  }
  return (*((_BYTE *)this + 544) & 0x10) == 0 || info->m_nTimesUsed != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B5C70
// Name: protected: void CBaseAssetPicker::RequestFilterFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::RequestFilterFocus(CBaseAssetPicker *this)
{
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pFilter, status: true);
  this->m_pFilter->RequestFocus(this: this->m_pFilter, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004B5CA0
// Name: protected: virtual void CBaseAssetPicker::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemDeselected(CBaseAssetPicker *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
    this->OnSelectedAssetPicked(this, a2: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x004B5CE0
// Name: public: int CBaseAssetPicker::GetSelectedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetSelectedAssetCount(CBaseAssetPicker *this)
{
  return this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x004B5CF0
// Name: public: char const __near * CBaseAssetPicker::GetSelectedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetSelectedAsset(CBaseAssetPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  v4 = nSelectionIndex;
  if ( nSelectionIndex < 0 )
    v4 = v3 - 1;
  if ( v3 <= v4 || v4 < 0 )
    return nullptr;
  v5 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: v4);
  v6 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v5);
  return KeyValues::GetString(this: v6, keyName: "asset", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x004B5D60
// Name: protected: void CBaseAssetPickerFrame::SetAssetPicker(class CBaseAssetPicker __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::SetAssetPicker(CBaseAssetPickerFrame *this, CBaseAssetPicker *pPicker)
{
  this->m_pPicker = pPicker;
  pPicker->AddActionSignalTarget_2(this: pPicker, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x004B5D80
// Name: public: void CBaseAssetPickerFrame::DoModal(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::DoModal(CBaseAssetPickerFrame *this, KeyValues *pKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  KeyValues *v4; // ecx
  CBaseAssetPicker *m_pPicker; // ecx

  vgui::Frame::DoModal(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  v4 = this->m_pContextKeyValues;
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pKeyValues;
  m_pPicker->Activate(this: m_pPicker);
}

//------------------------------------------------------------------------------
// Address: 0x004B5DE0
// Name: protected: void CBaseAssetPickerFrame::PostMessageAndClose(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::PostMessageAndClose(CBaseAssetPickerFrame *this, KeyValues *pKeyValues)
{
  if ( this->m_pContextKeyValues != nullptr )
  {
    KeyValues::AddSubKey(this: pKeyValues, pSubkey: this->m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->CloseModal(this);
  this->PostActionSignal(this, a2: pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004B5E30
// Name: public: virtual void CBaseAssetPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPickerFrame::OnCommand(CBaseAssetPickerFrame *this@<ecx>, int a2@<ebx>, KeyValues *pCommand)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  CBaseAssetPicker *m_pPicker; // esi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  KeyValues *v10; // eax
  const char *String; // eax
  int v12; // ebx
  int i; // esi
  const char *SelectedAsset; // eax
  char pBuf[512]; // [esp+8h] [ebp-204h] BYREF
  KeyValues *pAssetKeys; // [esp+208h] [ebp-4h]
  KeyValues *pActionKeys; // [esp+214h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "AssetSelected");
      pActionKeys = v5;
    }
    else
    {
      pActionKeys = nullptr;
      v5 = nullptr;
    }
    if ( vgui::ListPanel::IsMultiselectEnabled(this: this->m_pPicker->m_pAssetBrowser) )
    {
      pAssetKeys = KeyValues::FindKey(this: v5, keyName: "assets", bCreate: true);
      v12 = ((int (__thiscall *)(vgui::ListPanel *, int))this->m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
              a1: this->m_pPicker->m_pAssetBrowser,
              a2);
      for ( i = 0; i < v12; ++i )
      {
        V_snprintf(pDest: pBuf, maxLen: 512, pFormat: "asset%d", i);
        SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this: this->m_pPicker, nSelectionIndex: i);
        KeyValues::SetString(this: pAssetKeys, keyName: pBuf, value: SelectedAsset);
      }
      v5 = pActionKeys;
    }
    else
    {
      m_pPicker = this->m_pPicker;
      v7 = ((int (__thiscall *)(vgui::ListPanel *, int))m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
             a1: m_pPicker->m_pAssetBrowser,
             a2);
      v8 = v7 - 1;
      if ( __OFSUB__(v7, v7 - 1) || v8 < 0 )
      {
        KeyValues::SetString(this: v5, keyName: "asset", value: nullptr);
      }
      else
      {
        v9 = m_pPicker->m_pAssetBrowser->GetSelectedItem(this: m_pPicker->m_pAssetBrowser, a2: v8);
        v10 = m_pPicker->m_pAssetBrowser->GetItem(this: m_pPicker->m_pAssetBrowser, a2: v9);
        String = KeyValues::GetString(this: v10, keyName: "asset", defaultValue: defaultValue);
        KeyValues::SetString(this: v5, keyName: "asset", value: String);
      }
    }
    this->m_pPicker->CustomizeSelectionMessage(this: this->m_pPicker, a2: v5);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->CloseModal(this);
    ((void (__thiscall *)(CBaseAssetPickerFrame *))this->PostActionSignal)(a1: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6010
// Name: protected: virtual void CBaseAssetPickerFrame::CloseModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::CloseModal(CBaseAssetPickerFrame *this)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  unsigned int v4; // eax

  v2 = g_pVGui;
  v3 = g_pVGui->__vftable;
  v4 = this->m_pPicker->GetVPanel(this: this->m_pPicker);
  v3->RemoveTickSignal(this: v2, a2: v4);
  vgui::Frame::CloseModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B6040
// Name: public: virtual void CAssetTreeView::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ApplySchemeSettings(CAssetTreeView *this, vgui::IScheme *pScheme)
{
  CAssetTreeView_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultSmall", a3: false);
  v3->SetFont(this, a2: v4);
  ((void (__thiscall *)(CAssetTreeView *, int))this->SetFgColor)(a1: this, a2: -2892072);
}

//------------------------------------------------------------------------------
// Address: 0x004B6090
// Name: public: void CBaseAssetPicker::SetInitialSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::SetInitialSelection(CBaseAssetPicker *this, const char *pAssetName)
{
  int v3; // edi

  CUtlString::operator=(this: &this->m_SelectedAsset, src: pAssetName);
  if ( pAssetName != nullptr )
  {
    v3 = this->m_pAssetBrowser->GetItem_2(this: this->m_pAssetBrowser, a2: pAssetName);
    if ( v3 != -1 )
    {
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v3, a3: 0);
      vgui::ListPanel::ScrollToItem(this: this->m_pAssetBrowser, nItemID: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B60F0
// Name: public: virtual int CBaseAssetPicker::GetAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetAssetCount(CBaseAssetPicker *this)
{
  return this->m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B6100
// Name: public: CBaseAssetPickerFrame::CBaseAssetPickerFrame(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPickerFrame *__thiscall CBaseAssetPickerFrame::CBaseAssetPickerFrame(
        CBaseAssetPickerFrame *this,
        vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "AssetPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( `CBaseAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
    v3->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
    v4->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
    v5->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "OpenButton",
           text: "#FileOpenDialog_Open",
           pActionSignalTarget: this,
           pCmd: "Open");
  else
    v7 = nullptr;
  this->m_pOpenButton = v7;
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#FileOpenDialog_Cancel",
           pActionSignalTarget: this,
           pCmd: "Cancel");
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B6250
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPickerFrame::GetMessageMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B6280
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPickerFrame::GetAnimMap(CBaseAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004B6290
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPickerFrame::GetKBMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B62C0
// Name: public: virtual CBaseAssetPickerFrame::~CBaseAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::~CBaseAssetPickerFrame(CBaseAssetPickerFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B62F0
// Name: public: void CBaseAssetPickerFrame::SetInitialSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::SetInitialSelection(CBaseAssetPickerFrame *this, const char *pAssetName)
{
  CBaseAssetPicker *m_pPicker; // esi
  int v3; // edi

  m_pPicker = this->m_pPicker;
  CUtlString::operator=(this: &m_pPicker->m_SelectedAsset, src: pAssetName);
  if ( pAssetName != nullptr )
  {
    v3 = m_pPicker->m_pAssetBrowser->GetItem_2(this: m_pPicker->m_pAssetBrowser, a2: pAssetName);
    if ( v3 != -1 )
    {
      m_pPicker->m_pAssetBrowser->SetSelectedCell(this: m_pPicker->m_pAssetBrowser, a2: v3, a3: 0);
      vgui::ListPanel::ScrollToItem(this: m_pPicker->m_pAssetBrowser, nItemID: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B63E0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6490
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6540
// Name: public: void CAssetTreeView::OpenRoot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::OpenRoot(CAssetTreeView *this)
{
  const char *v2; // ebx
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  CAssetTreeView_vtbl *v6; // ebx
  int v7; // eax
  int v8; // ebx

  this->RemoveAll(this);
  v2 = CUtlString::operator char const *(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[this->m_DirectoryStructure.m_Root].m_Element);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "root");
  else
    v4 = nullptr;
  v5 = CUtlString::Get(this: &this->m_RootFolderName);
  KeyValues::SetString(this: v4, keyName: "text", value: v5);
  KeyValues::SetInt(this: v4, keyName: "root", value: 1);
  KeyValues::SetInt(this: v4, keyName: "expand", value: 1);
  KeyValues::SetInt(this: v4, keyName: "dirHandle", value: this->m_DirectoryStructure.m_Root);
  KeyValues::SetString(this: v4, keyName: "path", value: v2);
  v6 = this->__vftable;
  v7 = this->GetRootItemIndex(this);
  v8 = v6->AddItem(this, a2: v4, a3: v7);
  KeyValues::deleteThis(this: v4);
  this->ExpandItem(this, a2: v8, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x004B6620
// Name: private: static bool CAssetCache::CachedAssetLessFunc(struct CAssetCache::CachedAssetList_t const __near &,struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAssetCache::CachedAssetLessFunc(
        const CAssetCache::CachedAssetList_t *src1,
        const CAssetCache::CachedAssetList_t *src2)
{
  const char *v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  const char *v9; // [esp-4h] [ebp-Ch]
  int nCount; // [esp+14h] [ebp+Ch]

  v9 = CUtlString::operator char const *(this: &src2->m_pSubDir);
  v3 = CUtlString::operator char const *(this: &src1->m_pSubDir);
  v4 = _V_stricmp(s1: v3, s2: v9) > 0;
  if ( v4 != 0 )
    return v4 > 0;
  v6 = src1->m_Ext.m_Size - src2->m_Ext.m_Size;
  nCount = src1->m_Ext.m_Size;
  if ( v6 != 0 )
    return v6 > 0;
  v7 = 0;
  if ( src1->m_Ext.m_Size <= 0 )
    return false;
  while ( 1 )
  {
    v8 = _V_stricmp(s1: src1->m_Ext.m_Memory.m_pMemory[v7], s2: src2->m_Ext.m_Memory.m_pMemory[v7]);
    if ( v8 != 0 )
      break;
    if ( ++v7 >= nCount )
      return false;
  }
  return v8 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B66C0
// Name: private: int CAssetCache::GetAssetUsageCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAssetCache::GetAssetUsageCount(CAssetCache *this, const char *assetName)
{
  int result; // eax
  int v4; // edi
  int i; // ebx
  char *v6; // eax

  result = this->m_usedAssets.m_Size;
  if ( result != 0 )
  {
    v4 = 0;
    if ( result <= 0 )
    {
      return 0;
    }
    else
    {
      for ( i = 0; ; ++i )
      {
        v6 = CUtlString::Get(this: &this->m_usedAssets.m_Memory.m_pMemory[i].m_assetName);
        if ( V_stristr(pStr: v6, pSearch: assetName) != nullptr )
          break;
        if ( ++v4 >= this->m_usedAssets.m_Size )
          return 0;
      }
      return this->m_usedAssets.m_Memory.m_pMemory[v4].m_nTimesUsed;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B6720
// Name: private: bool CAssetCache::DoesExtensionMatch(struct CAssetCache::CachedAssetList_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::DoesExtensionMatch(
        CAssetCache *this,
        CAssetCache::CachedAssetList_t *info,
        const char *pFileName)
{
  int m_Size; // edi
  int v4; // esi
  char pChildExt[260]; // [esp+Ch] [ebp-104h] BYREF

  V_ExtractFileExtension(path: pFileName, dest: pChildExt, destSize: 260);
  m_Size = info->m_Ext.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: info->m_Ext.m_Memory.m_pMemory[v4], s2: pChildExt) != 0 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B6E90
// Name: private: void CAssetTreeView::AddDirectoryToTreeView(int,char const __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::AddDirectoryToTreeView(
        CAssetTreeView *this,
        int nParentItemIndex,
        const char *pFullParentPath,
        int hPath)
{
  int v5; // ebx
  const char *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  unsigned __int16 m_FirstChild; // bx
  int v10; // ebx
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // edx
  char pFullPath[260]; // [esp+Ch] [ebp-108h] BYREF
  const char *pDirName; // [esp+110h] [ebp-4h]

  v5 = (unsigned __int16)hPath;
  v6 = CUtlString::Get(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_Element);
  pDirName = v6;
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "text", firstValue: v6);
  else
    v8 = nullptr;
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s/%s", pFullParentPath, pDirName);
  V_FixSlashes(pname: pFullPath, separator: 92);
  _V_strlower(start: pFullPath);
  m_FirstChild = this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_FirstChild;
  KeyValues::SetString(this: v8, keyName: "path", value: pFullPath);
  KeyValues::SetInt(this: v8, keyName: "expand", value: m_FirstChild != 0xFFFF);
  KeyValues::SetInt(this: v8, keyName: "image", value: 0);
  KeyValues::SetInt(this: v8, keyName: "dirHandle", value: (unsigned __int16)hPath);
  v10 = this->AddItem(this, a2: v8, a3: nParentItemIndex);
  KeyValues::deleteThis(this: v8);
  SetItemFgColor = this->SetItemFgColor;
  hPath = -16727840;
  SetItemFgColor(this, a2: v10, a3: (const Color *)&hPath);
}

//------------------------------------------------------------------------------
// Address: 0x004B6FB0
// Name: public: virtual void CAssetTreeView::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::GenerateChildrenOfNode(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v3; // esi
  int Int; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // eax
  unsigned __int16 i; // cx
  unsigned int v7; // ebx
  const char *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // eax
  char pDest[260]; // [esp+8h] [ebp-114h] BYREF
  const char *pFullParentPath; // [esp+10Ch] [ebp-10h]
  int value; // [esp+110h] [ebp-Ch]
  const char *m_FirstChild; // [esp+114h] [ebp-8h]
  int v16; // [esp+118h] [ebp-4h] BYREF

  v3 = this->GetItemData(this, a2: nItemIndex);
  pFullParentPath = KeyValues::GetString(this: v3, keyName: "path", defaultValue: nullptr);
  if ( pFullParentPath != nullptr )
  {
    Int = (unsigned __int16)KeyValues::GetInt(this: v3, keyName: "dirHandle", defaultValue: 0xFFFF);
    if ( (_WORD)Int != 0xFFFF )
    {
      m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      for ( i = m_pMemory[Int].m_FirstChild; i != 0xFFFF; i = m_pMemory[v7].m_NextSibling )
      {
        value = i;
        v7 = i;
        v8 = CUtlString::Get(this: &m_pMemory[v7].m_Element);
        m_FirstChild = v8;
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "text", firstValue: v8);
        else
          v10 = nullptr;
        V_snprintf(pDest, maxLen: 260, pFormat: "%s/%s", pFullParentPath, m_FirstChild);
        V_FixSlashes(pname: pDest, separator: 92);
        _V_strlower(start: pDest);
        m_FirstChild = (const char *)this->m_DirectoryStructure.m_Memory.m_pMemory[v7].m_FirstChild;
        KeyValues::SetString(this: v10, keyName: "path", value: pDest);
        KeyValues::SetInt(this: v10, keyName: "expand", value: (_WORD)m_FirstChild != 0xFFFF);
        KeyValues::SetInt(this: v10, keyName: "image", value: 0);
        KeyValues::SetInt(this: v10, keyName: "dirHandle", value);
        value = this->AddItem(this, a2: v10, a3: nItemIndex);
        KeyValues::deleteThis(this: v10);
        SetItemFgColor = this->SetItemFgColor;
        v16 = -16727840;
        SetItemFgColor(this, a2: value, a3: (const Color *)&v16);
        m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7160
// Name: private: unsigned short CAssetTreeView::RefreshTreeViewItem(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::RefreshTreeViewItem(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v4; // edi
  const char *String; // eax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  bool v7; // zf
  BOOL v8; // ebx
  bool (__thiscall *ModifyItem)(vgui::TreeView *, int, KeyValues *); // edx
  int v10; // edi
  int v11; // ebx
  void *v12; // esp
  int i; // edi
  int v14; // eax
  unsigned __int16 refreshed; // ax
  int m_NextSibling; // edi
  unsigned __int16 *v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // dx
  KeyValues *v20; // [esp-4h] [ebp-20h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-1Ch] BYREF
  const char *pFullParentPath; // [esp+Ch] [ebp-10h]
  int hPath; // [esp+10h] [ebp-Ch]
  unsigned __int16 *pFoundHandles; // [esp+14h] [ebp-8h]
  int v25; // [esp+18h] [ebp-4h]

  if ( nItemIndex < 0 )
    return -1;
  v4 = this->GetItemData(this, a2: nItemIndex);
  hPath = (unsigned __int16)KeyValues::GetInt(this: v4, keyName: "dirHandle", defaultValue: 0xFFFF);
  String = KeyValues::GetString(this: v4, keyName: "path", defaultValue: nullptr);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  pFullParentPath = String;
  v7 = m_pMemory[hPath].m_FirstChild == 0xFFFF;
  v25 = 24 * hPath;
  v8 = !v7;
  if ( v8 == (KeyValues::GetInt(this: v4, keyName: "expand", defaultValue: 0) != 0) )
  {
    v10 = nItemIndex;
  }
  else
  {
    KeyValues::SetInt(this: v4, keyName: "expand", value: v8);
    ModifyItem = this->ModifyItem;
    v20 = v4;
    v10 = nItemIndex;
    ModifyItem(this, a2: nItemIndex, a3: v20);
  }
  if ( this->IsItemExpanded(this, a2: v10) )
  {
    v11 = this->GetNumChildren(this, a2: v10);
    v12 = alloca(2 * v11);
    pFoundHandles = (unsigned __int16 *)v21;
    memset(dst: v21, value: 0xFFu, count: 2 * v11);
    for ( i = 0; i < v11; ++i )
    {
      v14 = this->GetChild(this, a2: nItemIndex, a3: i);
      refreshed = CAssetTreeView::RefreshTreeViewItem(this, nItemIndex: v14);
      pFoundHandles[i] = refreshed;
    }
    m_NextSibling = *(unsigned __int16 *)((char *)&this->m_DirectoryStructure.m_Memory.m_pMemory->m_FirstChild + v25);
    if ( (_WORD)m_NextSibling != 0xFFFF )
    {
      v17 = pFoundHandles;
      v25 = (int)&pFoundHandles[v11 - 1];
      do
      {
        v18 = 0;
        if ( v11 <= 0 )
        {
LABEL_14:
          CAssetTreeView::AddDirectoryToTreeView(
            this,
            nParentItemIndex: nItemIndex,
            pFullParentPath,
            hPath: m_NextSibling);
          v17 = pFoundHandles;
        }
        else
        {
          while ( v17[v18] != (_WORD)m_NextSibling )
          {
            if ( ++v18 >= v11 )
              goto LABEL_14;
          }
          v19 = *(_WORD *)v25;
          --v11;
          v25 -= 2;
          v17[v18] = v19;
        }
        m_NextSibling = this->m_DirectoryStructure.m_Memory.m_pMemory[(unsigned __int16)m_NextSibling].m_NextSibling;
      }
      while ( (_WORD)m_NextSibling != 0xFFFF );
    }
  }
  return hPath;
}

//------------------------------------------------------------------------------
// Address: 0x004B7310
// Name: private: bool CAssetTreeView::SelectFolder_R(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetTreeView::SelectFolder_R(CAssetTreeView *this, int nItemID, const char *pPath)
{
  KeyValues *v6; // eax
  const char *String; // ebx
  const char *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // [esp-8h] [ebp-20h]
  CUtlString str; // [esp+8h] [ebp-10h] BYREF
  int nChildCount; // [esp+20h] [ebp+8h]

  if ( nItemID < 0 )
    return 0;
  v6 = this->GetItemData(this, a2: nItemID);
  String = KeyValues::GetString(this: v6, keyName: "path", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: pPath) != 0 )
  {
    CUtlString::CUtlString(this: &str, pString: String);
    CUtlString::operator+=(this: &str, c: 92);
    v11 = CUtlString::Length(this: &str);
    v8 = CUtlString::operator char const *(this: &str);
    if ( V_strnicmp(s1: v8, s2: pPath, n: v11) != 0 )
    {
      CUtlString::~CUtlString(this: &str);
      return 0;
    }
    else
    {
      this->ExpandItem(this, a2: nItemID, a3: true);
      v9 = 0;
      nChildCount = this->GetNumChildren(this, a2: nItemID);
      if ( nChildCount <= 0 )
      {
LABEL_10:
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 0;
      }
      else
      {
        while ( 1 )
        {
          v10 = this->GetChild(this, a2: nItemID, a3: v9);
          if ( CAssetTreeView::SelectFolder_R(this, nItemID: v10, pPath) )
            break;
          if ( ++v9 >= nChildCount )
            goto LABEL_10;
        }
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 1;
      }
    }
  }
  else
  {
    this->AddSelectedItem(this, a2: nItemID, a3: true, a4: false, a5: true);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7470
// Name: public: virtual void CBaseAssetPicker::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::GetUserConfigSettings(CBaseAssetPicker *this, KeyValues *pUserConfig)
{
  const char *v3; // eax
  const char *v4; // eax
  int m_nCurrentModFilter; // eax
  char v6; // bl
  CUtlString *v7; // eax
  const char *v8; // eax
  CUtlString v9; // [esp+Ch] [ebp-24h] BYREF
  CUtlString v10; // [esp+1Ch] [ebp-14h] BYREF
  int v11; // [esp+2Ch] [ebp-4h]

  v11 = 0;
  vgui::EditablePanel::GetUserConfigSettings(this, userConfig: pUserConfig);
  v3 = CUtlString::operator char const *(this: &this->m_Filter);
  KeyValues::SetString(this: pUserConfig, keyName: "filter", value: v3);
  v4 = CUtlString::operator char const *(this: &this->m_FolderFilter);
  KeyValues::SetString(this: pUserConfig, keyName: "folderfilter", value: v4);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  if ( m_nCurrentModFilter < 0 )
  {
    v6 = 2;
    v7 = CUtlString::CUtlString(this: &v10, pString: defaultValue);
  }
  else
  {
    v6 = 1;
    v7 = CUtlString::CUtlString(
           this: &v9,
           string: &s_AssetCache.m_ModList.m_Memory.m_pMemory[m_nCurrentModFilter].m_ModName);
  }
  v8 = CUtlString::operator char const *(this: v7);
  KeyValues::SetString(this: pUserConfig, keyName: "mod", value: v8);
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    v10.m_Storage.m_nActualLength = 0;
    if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
        v10.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v10.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
  }
  if ( (v6 & 1) != 0 )
  {
    v9.m_Storage.m_nActualLength = 0;
    if ( v9.m_Storage.m_Memory.m_nGrowSize >= 0 && v9.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7560
// Name: public: virtual struct CachedAssetInfo_t const __near & CBaseAssetPicker::GetCachedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const CachedAssetInfo_t *__thiscall CBaseAssetPicker::GetCachedAsset(CBaseAssetPicker *this, int nAssetIndex)
{
  return &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[nAssetIndex];
}

//------------------------------------------------------------------------------
// Address: 0x004B7590
// Name: public: virtual int CBaseAssetPicker::GetCachedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetCachedAssetCount(CBaseAssetPicker *this)
{
  AssetList_t__ *m_hAssetList; // eax

  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    return 0;
  else
    return s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B75C0
// Name: protected: void CBaseAssetPicker::RescanAssets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::RescanAssets(CBaseAssetPicker *this)
{
  char v2; // al
  vgui::IVGui *v3; // ebx
  vgui::IVGui_vtbl *v4; // edi
  int v5; // eax

  this->m_pAssetBrowser->RemoveAll(this: this->m_pAssetBrowser);
  this->m_AssetList.m_Size = 0;
  this->BeginCacheAssets(this, a2: true);
  *((_BYTE *)this + 544) |= 2u;
  v2 = *((_BYTE *)this + 544);
  this->m_nMatchingAssets = 0;
  if ( (v2 & 4) != 0 )
  {
    *((_BYTE *)this + 544) = v2 & 0xFB;
    v3 = g_pVGui;
    v4 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v4->AddTickSignal)(a1: v3, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7630
// Name: public: virtual void CBaseAssetPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnCommand(CBaseAssetPicker *this, const char *pCommand)
{
  const char *v2; // esi
  KeyValues *v4; // eax
  int v5; // esi
  void *v6; // esp
  KeyValues *v7; // esi
  char v8[12]; // [esp+0h] [ebp-10h] BYREF
  KeyValues *pKeyValues; // [esp+Ch] [ebp-4h]

  v2 = pCommand;
  if ( _V_stricmp(s1: pCommand, s2: "AssetRescan") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "FindAsset") == 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        pKeyValues = KeyValues::KeyValues(this: v4, setName: "AssetPickerFind");
      else
        pKeyValues = nullptr;
      v5 = this->m_pFullPath->GetTextLength(this: this->m_pFullPath);
      v6 = alloca(v5 + 1);
      if ( v5 <= 0 )
        v8[0] = 0;
      else
        this->m_pFullPath->GetText_2(this: this->m_pFullPath, a2: v8, a3: v5 + 1);
      v7 = pKeyValues;
      KeyValues::SetString(this: pKeyValues, keyName: "asset", value: v8);
      this->PostActionSignal(this, a2: v7);
      v2 = pCommand;
    }
    vgui::Panel::OnCommand(this, command: v2);
  }
  else
  {
    CBaseAssetPicker::RescanAssets(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7710
// Name: public: virtual class CUtlString CBaseAssetPicker::GetSelectedAssetFullPath(int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CBaseAssetPicker::GetSelectedAssetFullPath(
        CBaseAssetPicker *this,
        CUtlString *result,
        int nIndex)
{
  const char *SelectedAsset; // edi
  int Int; // eax
  int v6; // eax
  KeyValues *v7; // eax
  const char *v8; // eax
  const char *m_pAssetSubDir; // [esp-8h] [ebp-114h]
  char pBuf[260]; // [esp+8h] [ebp-104h] BYREF

  SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: nIndex - 1);
  Int = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  if ( Int != 0 )
  {
    v6 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: 0);
    v7 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v6);
    Int = KeyValues::GetInt(this: v7, keyName: "modIndex", defaultValue: 0);
  }
  m_pAssetSubDir = this->m_pAssetSubDir;
  v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[Int].m_Path);
  V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "%s\\%s\\%s", v8, m_pAssetSubDir, SelectedAsset);
  V_FixSlashes(pname: pBuf, separator: 92);
  CUtlString::CUtlString(this: result, pString: pBuf);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B77D0
// Name: protected: virtual void CBaseAssetPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemSelected(CBaseAssetPicker *this, KeyValues *kv)
{
  int v3; // edi
  vgui::TextEntry_vtbl *v4; // ebx
  CUtlString *v5; // eax
  const char *v6; // eax
  _DWORD v7[4]; // [esp+4h] [ebp-10h] BYREF
  const char *pSelectedAsset; // [esp+1Ch] [ebp+8h]

  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
  {
    v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) - 1;
    pSelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: v3);
    v4 = this->m_pFullPath->__vftable;
    v5 = this->GetSelectedAssetFullPath(this, result: v7, a3: v3);
    v6 = CUtlString::operator char const *(this: v5);
    v4->SetText(this: this->m_pFullPath, a2: v6);
    v7[3] = 0;
    if ( v7[2] >= 0 && v7[0] != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v7[0]);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
    this->OnSelectedAssetPicked(this, a2: pSelectedAsset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B78A0
// Name: public: virtual char const __near * CBaseAssetPicker::GetAssetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetAssetName(CBaseAssetPicker *this, int nAssetIndex)
{
  return CUtlString::operator char const *(this: &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[this->m_AssetList.m_Memory.m_pMemory[nAssetIndex].m_nAssetIndex].m_AssetName);
}

//------------------------------------------------------------------------------
// Address: 0x004B81B0
// Name: public: unsigned short CAssetTreeView::AddSubDirectory(unsigned short,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::AddSubDirectory(
        CAssetTreeView *this,
        unsigned __int16 hParent,
        const char *pDirName)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v4; // bx
  int v5; // edi
  CUtlString *p_m_Element; // ecx
  char *v7; // eax

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  v4 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  v5 = v4;
  p_m_Element = &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element;
  if ( p_m_Element != nullptr )
    CUtlString::CUtlString(this: p_m_Element);
  CUtlString::operator=(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element, src: pDirName);
  v7 = CUtlString::Get(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element);
  _V_strlower(start: v7);
  CUtlNTree<CUtlString,unsigned short>::LinkChildBefore(
    this: p_m_DirectoryStructure,
    parent: hParent,
    before: p_m_DirectoryStructure->m_Memory.m_pMemory[hParent].m_FirstChild,
    elem: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B8330
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x004B83C0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x004B8450
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x004B84E0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x004B8570
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x004B8600
// Name: protected: void CBaseAssetPicker::AddExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AddExtension(CBaseAssetPicker *this, vgui::TreeNode *pExtension)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_ExtraAssetExt; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_ExtraAssetExt.m_Memory.m_nAllocationCount;
  p_m_ExtraAssetExt = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ExtraAssetExt;
  m_Size = this->m_ExtraAssetExt.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_ExtraAssetExt, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ExtraAssetExt[1].m_pMemory;
  m_pMemory = p_m_ExtraAssetExt->m_pMemory;
  v6 = (int)p_m_ExtraAssetExt[1].m_pMemory - m_Size - 1;
  p_m_ExtraAssetExt[1].m_nAllocationCount = (int)p_m_ExtraAssetExt->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_ExtraAssetExt->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pExtension;
}

//------------------------------------------------------------------------------
// Address: 0x004B8670
// Name: protected: void CBaseAssetPicker::AddAssetToList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AddAssetToList(CBaseAssetPicker *this, int nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ebx
  unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  KeyValues *m_pInsertHelper; // esi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int v12; // esi
  const char *v13; // eax
  const char *v14; // eax
  KeyValues *v15; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBaseAssetPicker::AssetInfo_t *m_pMemory; // ecx
  int v19; // eax
  const char *v20; // [esp-4h] [ebp-1Ch]
  KeyValues *v21; // [esp+10h] [ebp-8h]
  bool bInRootDir; // [esp+17h] [ebp-1h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  v4 = (unsigned __int8 *)CUtlString::operator char const *(this: &v3->m_AssetName);
  strchr(string: v4, chr: 0x5Cu);
  if ( v5 != 0
    || (v6 = (unsigned __int8 *)CUtlString::operator char const *(this: &v3->m_AssetName),
        strchr(string: v6, chr: 0x2Fu),
        bInRootDir = true,
        v7 != 0) )
  {
    bInRootDir = false;
  }
  m_pInsertHelper = this->m_pInsertHelper;
  v9 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetName(this: m_pInsertHelper, setName: v9);
  v10 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "asset", value: v10);
  v11 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v3->m_nModIndex].m_ModName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "mod", value: v11);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "modIndex", value: v3->m_nModIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "root", value: bInRootDir);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "assetIndex", value: nAssetIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "timesused", value: v3->m_nTimesUsed);
  v12 = this->m_pAssetBrowser->AddItem(this: this->m_pAssetBrowser, a2: m_pInsertHelper, a3: 0, a4: false, a5: false);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0 )
  {
    v20 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v13 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
    if ( _V_strcmp(s1: v13, s2: v20) == 0 )
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v12, a3: 0);
  }
  v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v21 != nullptr )
  {
    v14 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v15 = KeyValues::KeyValues(this: v21, setName: "drag", firstKey: "text", firstValue: v14);
  }
  else
  {
    v15 = nullptr;
  }
  if ( this->m_pAssetTextType != nullptr )
    KeyValues::SetString(this: v15, keyName: "texttype", value: this->m_pAssetTextType);
  vgui::ListPanel::SetItemDragData(this: this->m_pAssetBrowser, itemID: v12, data: v15);
  m_Size = this->m_AssetList.m_Size;
  m_nAllocationCount = this->m_AssetList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MDLSquenceLayer_t,int>::Grow(
      this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_AssetList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_AssetList.m_Size;
  m_pMemory = this->m_AssetList.m_Memory.m_pMemory;
  v19 = this->m_AssetList.m_Size - m_Size - 1;
  this->m_AssetList.m_pElements = m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v19);
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nAssetIndex = nAssetIndex;
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nItemId = v12;
  LOBYTE(nAssetIndex) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)m_Size);
  this->m_pAssetBrowser->SetItemVisible(this: this->m_pAssetBrowser, a2: v12, a3: nAssetIndex);
  if ( (_BYTE)nAssetIndex != 0 )
    ++this->m_nMatchingAssets;
}

//------------------------------------------------------------------------------
// Address: 0x004B8960
// Name: public: void CAssetTreeView::ClearDirectories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ClearDirectories(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v3; // ax
  int v4; // edi
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  unsigned __int16 v6; // [esp+Ch] [ebp-4h]

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  v3 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: p_m_DirectoryStructure);
  v4 = v3;
  v6 = v3;
  if ( &p_m_DirectoryStructure->m_Memory.m_pMemory[v4] != nullptr )
  {
    CUtlString::CUtlString(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v4].m_Element);
    v3 = v6;
  }
  m_pMemory = p_m_DirectoryStructure->m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v3;
  CUtlString::operator=(this: &m_pMemory[v4].m_Element, src: &this->m_RootDirectory);
}

//------------------------------------------------------------------------------
// Address: 0x004B8BD0
// Name: public: CAssetTreeView::CAssetTreeView(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetTreeView *__thiscall CAssetTreeView::CAssetTreeView(
        CAssetTreeView *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pRootFolderName,
        const char *pRootDir)
{
  vgui::PanelMessageMap *v6; // esi
  PanelAnimationMap *v7; // esi
  vgui::PanelKeyBindingMap *v8; // esi
  unsigned __int16 v9; // ax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  int v11; // ebx
  bool v12; // zf
  CUtlString *p_m_Element; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *v14; // ecx
  vgui::IImage *v15; // eax
  unsigned __int16 pNamea; // [esp+18h] [ebp+Ch]

  vgui::TreeView::TreeView(this, parent: pParent, panelName: pName);
  this->__vftable = (CAssetTreeView_vtbl *)&CAssetTreeView::`vftable';
  if ( `CAssetTreeView::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
    v6->pfnClassName = CAssetTreeView::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CAssetTreeView");
    v7->pfnClassName = CAssetTreeView::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
    v8->pfnClassName = CAssetTreeView::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TreeView");
  }
  CUtlString::CUtlString(this: &this->m_RootFolderName);
  CUtlString::CUtlString(this: &this->m_RootDirectory);
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
  this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoryStructure.m_Memory.m_nGrowSize = 0;
  *(_DWORD *)&this->m_DirectoryStructure.m_Root = -1;
  *(_DWORD *)&this->m_DirectoryStructure.m_ElementCount = 0;
  this->m_DirectoryStructure.m_pElements = nullptr;
  vgui::TreeView::SetSortFunc(this, pSortFunc: AssetTreeViewSortFunc);
  CUtlString::operator=(this: &this->m_RootFolderName, src: pRootFolderName);
  CUtlString::operator=(this: &this->m_RootDirectory, src: pRootDir);
  v9 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  v11 = v9;
  v12 = &m_pMemory[v11] == nullptr;
  p_m_Element = &m_pMemory[v11].m_Element;
  pNamea = v9;
  if ( !v12 )
  {
    CUtlString::CUtlString(this: p_m_Element);
    v9 = pNamea;
  }
  v14 = this->m_DirectoryStructure.m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v9;
  CUtlString::operator=(this: &v14[v11].m_Element, src: &this->m_RootDirectory);
  v15 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "resource/icon_folder", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: (vgui::Dar<unsigned long> *)&this->m_Images, elem: (unsigned int)v15);
  vgui::TreeView::SetImageList(this, imageList: &this->m_Images, deleteImageListWhenDone: false);
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B8D80
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetTreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetTreeView::GetMessageMap(CAssetTreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetTreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetMessageMap'::`2'::s_pMap;
  `CAssetTreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
  `CAssetTreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8DB0
// Name: public: virtual struct PanelAnimationMap __near * CAssetTreeView::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetTreeView::GetAnimMap(CAssetTreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetTreeView");
}

//------------------------------------------------------------------------------
// Address: 0x004B8DC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetTreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetTreeView::GetKBMap(CAssetTreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetTreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetKBMap'::`2'::s_pMap;
  `CAssetTreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
  `CAssetTreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8DF0
// Name: public: virtual CAssetTreeView::~CAssetTreeView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::~CAssetTreeView(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  if ( this->m_DirectoryStructure.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoryStructure.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoryStructure.m_Memory.m_pMemory);
      this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  }
  vgui::ImageList::~ImageList(this: &this->m_Images);
  this->m_RootDirectory.m_Storage.m_nActualLength = 0;
  if ( this->m_RootDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootDirectory.m_Storage.m_Memory.m_pMemory);
      this->m_RootDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RootFolderName.m_Storage.m_nActualLength = 0;
  if ( this->m_RootFolderName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootFolderName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootFolderName.m_Storage.m_Memory.m_pMemory);
      this->m_RootFolderName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootFolderName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::TreeView::~TreeView(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B8EB0
// Name: public: void CAssetCache::BuildModList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::BuildModList(CAssetCache *this, const char *pSearchPathName)
{
  int v3; // edi
  void *v4; // esp
  unsigned __int8 *v5; // ebx
  char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CacheModInfo_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // edi
  _BYTE v12[12]; // [esp+0h] [ebp-114h] BYREF
  char pModName[260]; // [esp+Ch] [ebp-108h] BYREF
  char *pSemiColon; // [esp+110h] [ebp-4h]
  CacheModInfo_t *pSearchPathNamea; // [esp+11Ch] [ebp+8h]

  if ( !this->m_bBuiltModList )
  {
    this->m_pAssetSearchPath = pSearchPathName;
    this->m_bBuiltModList = true;
    CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::RemoveAll(this: &this->m_ModList);
    v3 = g_pFullFileSystem->GetSearchPath(
           this: g_pFullFileSystem,
           a2: this->m_pAssetSearchPath,
           a3: false,
           a4: nullptr,
           a5: 0);
    v4 = alloca(v3);
    v5 = v12;
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: this->m_pAssetSearchPath, a3: false, a4: v12, a5: v3);
    if ( v12 != nullptr )
    {
      do
      {
        strchr(string: v5, chr: 0x3Bu);
        pSemiColon = v6;
        if ( v6 != nullptr )
          *v6 = 0;
        V_StripTrailingSlash(ppath: (char *)v5);
        V_FixSlashes(pname: (char *)v5, separator: 92);
        V_FileBase(in: (const char *)v5, out: pModName, maxlen: 260);
        m_Size = this->m_ModList.m_Size;
        m_nAllocationCount = this->m_ModList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
            (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_ModList.m_Size;
        m_pMemory = this->m_ModList.m_Memory.m_pMemory;
        v10 = this->m_ModList.m_Size - m_Size - 1;
        this->m_ModList.m_pElements = this->m_ModList.m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v10);
        v11 = m_Size;
        pSearchPathNamea = &this->m_ModList.m_Memory.m_pMemory[v11];
        if ( pSearchPathNamea != nullptr )
        {
          CUtlString::CUtlString(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName);
          CUtlString::CUtlString(this: &pSearchPathNamea->m_Path);
        }
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName, pValue: pModName);
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_Path, pValue: (const char *)v5);
        if ( pSemiColon == nullptr )
          break;
        v5 = (unsigned __int8 *)(pSemiColon + 1);
      }
      while ( pSemiColon != (char *)-1 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8FF0
// Name: private: bool CAssetCache::AddFilesInDirectory(struct CAssetCache::CachedAssetList_t __near &,char const __near *,char const __near *,unsigned short,float,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::AddFilesInDirectory(
        CAssetCache *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *list,
        char *pStartingFile,
        const char *pFilePath,
        unsigned __int16 hCurrentDir,
        float flStartTime,
        float flDuration)
{
  bool v8; // zf
  CAssetCache *v9; // ebx
  const char *v11; // eax
  char *v12; // edi
  int v13; // eax
  const char *v14; // eax
  int v15; // edi
  int v16; // edi
  CacheModInfo_t *v17; // ebx
  const char *v18; // eax
  char *v19; // edi
  const char *v20; // eax
  int AssetUsageCount; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CachedAssetInfo_t *v24; // ecx
  int v25; // eax
  CachedAssetInfo_t *v26; // ecx
  CachedAssetInfo_t *v27; // edi
  int v28; // eax
  int v29; // [esp-8h] [ebp-228h]
  int v30; // [esp-8h] [ebp-228h]
  char pFullAssetPath[260]; // [esp+8h] [ebp-218h] BYREF
  char pRelativeChildPath[260]; // [esp+10Ch] [ebp-114h] BYREF
  int nTimesUsed; // [esp+210h] [ebp-10h]
  int nModCount; // [esp+214h] [ebp-Ch]
  CAssetCache *v35; // [esp+218h] [ebp-8h]
  int nSubDirLen; // [esp+21Ch] [ebp-4h]
  unsigned __int16 ia; // [esp+228h] [ebp+8h]
  int i; // [esp+228h] [ebp+8h]
  const char *pAssetName; // [esp+22Ch] [ebp+Ch]

  v8 = list[7].m_nAllocationCount == -1;
  v9 = this;
  v35 = this;
  if ( v8 )
    return 1;
  nModCount = this->m_ModList.m_Size;
  if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
  {
    v11 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
    nSubDirLen = _V_strlen(str: v11);
  }
  else
  {
    nSubDirLen = 0;
  }
  v12 = pStartingFile;
  if ( pStartingFile == nullptr )
    return 1;
  while ( 1 )
  {
    V_snprintf(pDest: pRelativeChildPath, maxLen: 260, pFormat: "%s\\%s", pFilePath, v12);
    if ( !g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount) )
      break;
    strstr(str1: (unsigned __int8 *)v12, str2: ".svn");
    if ( v13 == 0 )
    {
      if ( V_strnicmp(s1: v12, s2: ".", n: 2) != 0 && V_strnicmp(s1: v12, s2: "..", n: 3) != 0 )
      {
        ia = CAssetTreeView::AddSubDirectory(
               this: (CAssetTreeView *)list[1].m_nGrowSize,
               hParent: hCurrentDir,
               pDirName: v12);
        v15 = (unsigned __int16)CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(this: (CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *)&list[5]);
        CUtlString::operator=(this: (CUtlString *)&list[5].m_pMemory[v15], src: pRelativeChildPath);
        LOWORD(list[5].m_pMemory[v15].m_Data.key) = ia;
      }
      goto LABEL_30;
    }
    v14 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
LABEL_32:
    v12 = (char *)v14;
    if ( v14 == nullptr )
      return 1;
  }
  if ( CAssetCache::DoesExtensionMatch(this: v9, info: (CAssetCache::CachedAssetList_t *)list, pFileName: v12) != 0 )
  {
    v16 = 0;
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: pRelativeChildPath,
      a3: v9->m_pAssetSearchPath,
      a4: pFullAssetPath,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    i = 0;
    if ( nModCount > 0 )
    {
      while ( 1 )
      {
        v17 = &v35->m_ModList.m_Memory.m_pMemory[v16];
        v29 = CUtlString::Length(this: &v17->m_Path);
        v18 = CUtlString::operator char const *(this: &v17->m_Path);
        if ( V_strnicmp(s1: pFullAssetPath, s2: v18, n: v29) == 0 )
          break;
        ++v16;
        if ( ++i >= nModCount )
          goto LABEL_30;
      }
      if ( i >= 0 )
      {
        v19 = pRelativeChildPath;
        pAssetName = pRelativeChildPath;
        if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
        {
          v30 = nSubDirLen;
          v20 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
          if ( V_strnicmp(s1: v20, s2: pRelativeChildPath, n: v30) == 0 && pRelativeChildPath[nSubDirLen] == 92 )
          {
            pAssetName = &pRelativeChildPath[nSubDirLen + 1];
            v19 = &pRelativeChildPath[nSubDirLen + 1];
          }
        }
        strlwr(string: v19);
        AssetUsageCount = CAssetCache::GetAssetUsageCount(this: v35, assetName: v19);
        m_pMemory = (int)list[1].m_pMemory;
        nTimesUsed = AssetUsageCount;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
            this: list,
            num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v24 = (CachedAssetInfo_t *)list->m_pMemory;
        v25 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v25 > 0 )
          _V_memmove(dest: (void *)&v24[m_pMemory + 1], src: &v24[m_pMemory], count: 24 * v25);
        v26 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        if ( v26 != nullptr )
          CUtlString::CUtlString(this: &v26->m_AssetName);
        v27 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        CUtlString::Set(this: &v27->m_AssetName, pValue: pAssetName);
        v28 = nTimesUsed;
        v27->m_nModIndex = i;
        v27->m_nTimesUsed = v28;
      }
    }
  }
LABEL_30:
  if ( _Plat_FloatTime() - flStartTime < flDuration )
  {
    v14 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
    v9 = v35;
    goto LABEL_32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B92E0
// Name: public: bool CAssetCache::BeginAssetScan(struct AssetList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::BeginAssetScan(CAssetCache *this, AssetList_t__ *hList, bool bForceRescan)
{
  int v3; // eax
  CAssetCache::CachedAssetList_t *p_m_Data; // esi
  int m_hFind; // eax
  unsigned __int16 v7; // ax
  int v8; // ebx
  unsigned __int16 v9; // ax
  CUtlString *p_m_DirName; // ecx
  int v11; // ebx

  v3 = (unsigned __int16)hList;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data;
  if ( bForceRescan )
  {
    m_hFind = this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data.m_hFind;
    p_m_Data->m_bAssetScanComplete = false;
    if ( m_hFind != -1 )
    {
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: m_hFind);
      p_m_Data->m_hFind = -1;
    }
    CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_Data->m_DirectoriesToCheck);
  }
  if ( p_m_Data->m_bAssetScanComplete )
    return 1;
  if ( p_m_Data->m_hFind == -1 )
  {
    CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int>>::RemoveAll(this: (CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int> > *)p_m_Data);
    CAssetTreeView::ClearDirectories(this: p_m_Data->m_pFileTree);
    v7 = CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &p_m_Data->m_DirectoriesToCheck,
           multilist: false);
    v8 = v7;
    if ( v7 == 0xFFFF )
    {
      v9 = -1;
    }
    else
    {
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &p_m_Data->m_DirectoriesToCheck,
        before: 0xFFFFu,
        elem: v7);
      p_m_DirName = &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v8].m_Element.m_DirName;
      if ( p_m_DirName != nullptr )
        CUtlString::CUtlString(this: p_m_DirName);
      v9 = v8;
    }
    v11 = v9;
    CUtlString::operator=(
      this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_DirName,
      src: &p_m_Data->m_pSubDir);
    p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_hDirHandle = p_m_Data->m_pFileTree->m_DirectoryStructure.m_Root;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B93C0
// Name: public: virtual bool CBaseAssetPicker::BeginCacheAssets(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAssetPicker::BeginCacheAssets(CBaseAssetPicker *this, bool bForceRecache)
{
  return CAssetCache::BeginAssetScan(this: &s_AssetCache, hList: this->m_hAssetList, bForceRescan: bForceRecache);
}

//------------------------------------------------------------------------------
// Address: 0x004B93E0
// Name: protected: void CBaseAssetPicker::BuildAssetNameList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::BuildAssetNameList(CBaseAssetPicker *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  int v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int v7; // edi
  KeyValues *v8; // eax
  const KeyValues *v9; // eax
  bool v10; // zf
  char v11; // al
  CBaseAssetPicker_vtbl *v12; // edx
  vgui::IVGui *v13; // ebx
  vgui::IVGui_vtbl *v14; // edi
  int v15; // eax
  int v16; // ebx
  int i; // edi
  const char *m_pAssetSearchPath; // [esp-8h] [ebp-14h]
  int nModCount; // [esp+4h] [ebp-8h]
  const char *pModName; // [esp+8h] [ebp-4h]

  v3 = *((_BYTE *)this + 544);
  if ( (v3 & 1) == 0 )
  {
    *((_BYTE *)this + 544) = v3 | 1;
    v4 = 0;
    m_pAssetSearchPath = this->m_pAssetSearchPath;
    this->m_nMatchingAssets = 0;
    this->m_nCurrentModFilter = -1;
    CAssetCache::BuildModList(this: &s_AssetCache, pSearchPathName: m_pAssetSearchPath);
    vgui::ComboBox::RemoveAll(this: this->m_pModSelector);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "Mod", firstKey: "mod", firstValue: -1);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::ComboBox *, const char *, KeyValues *, int))this->m_pModSelector->AddItem_2)(
      a1: this->m_pModSelector,
      a2: "All Mods",
      a3: v6,
      a4: a2);
    v7 = 0;
    for ( nModCount = s_AssetCache.m_ModList.m_Size; v7 < nModCount; ++v4 )
    {
      pModName = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v4].m_ModName);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "Mod", firstKey: "mod", firstValue: v7);
      else
        v9 = nullptr;
      this->m_pModSelector->AddItem_2(this: this->m_pModSelector, a2: pModName, a3: v9);
      ++v7;
    }
    vgui::ComboBox::ActivateItemByRow(this: this->m_pModSelector, row: 0);
    v10 = !this->BeginCacheAssets(this, a2: false);
    v11 = *((_BYTE *)this + 544);
    if ( v10 )
    {
      v12 = this->__vftable;
      *((_BYTE *)this + 544) = v11 & 0xF9 | 2;
      v13 = g_pVGui;
      v14 = g_pVGui->__vftable;
      v15 = ((int (__thiscall *)(CBaseAssetPicker *, int))v12->GetVPanel)(a1: this, a2: 10);
      ((void (__thiscall *)(vgui::IVGui *, int))v14->AddTickSignal)(a1: v13, a2: v15);
    }
    else
    {
      *((_BYTE *)this + 544) = v11 & 0xF9 | 4;
    }
    v16 = this->GetCachedAssetCount(this);
    for ( i = 0; i < v16; ++i )
      CBaseAssetPicker::AddAssetToList(this, nAssetIndex: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9560
// Name: protected: void CBaseAssetPicker::RefreshAssetList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::RefreshAssetList(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // eax
  int v5; // edi
  const CachedAssetInfo_t *v6; // eax
  vgui::ListPanel *m_pAssetBrowser; // ecx
  vgui::ListPanelItem *(__thiscall *GetItemData)(vgui::ListPanel *, int); // edx
  int v9; // ebx
  vgui::ListPanelItem *v10; // eax
  KeyValues *kv; // ecx
  const char *v12; // eax
  int v13; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v15; // eax
  char pDest[512]; // [esp+8h] [ebp-210h] BYREF
  const CachedAssetInfo_t *info; // [esp+208h] [ebp-10h]
  int nCount; // [esp+20Ch] [ebp-Ch]
  vgui::ListPanelItem *pItem; // [esp+210h] [ebp-8h]
  int bIsVisible; // [esp+214h] [ebp-4h]

  CBaseAssetPicker::BuildAssetNameList(this, a2: a3);
  v5 = 0;
  nCount = this->m_AssetList.m_Size;
  v4 = nCount;
  this->m_nMatchingAssets = 0;
  if ( v4 > 0 )
  {
    do
    {
      LOBYTE(bIsVisible) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)v5);
      v6 = (const CachedAssetInfo_t *)((int (__thiscall *)(CBaseAssetPicker *, int, int))this->GetCachedAsset)(
                                        a1: this,
                                        a2: v5,
                                        a3: a2);
      m_pAssetBrowser = this->m_pAssetBrowser;
      GetItemData = m_pAssetBrowser->GetItemData;
      info = v6;
      v9 = v5;
      v10 = GetItemData(this: m_pAssetBrowser, a2: this->m_AssetList.m_Memory.m_pMemory[v5].m_nItemId);
      kv = v10->kv;
      pItem = v10;
      if ( KeyValues::GetInt(this: kv, keyName: "timesused", defaultValue: 0) != info->m_nTimesUsed )
      {
        KeyValues::SetInt(this: pItem->kv, keyName: "timesused", value: info->m_nTimesUsed);
        this->m_pAssetBrowser->ApplyItemChanges(
          this: this->m_pAssetBrowser,
          a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      }
      a2 = bIsVisible;
      ((void (__thiscall *)(vgui::ListPanel *, int))this->m_pAssetBrowser->SetItemVisible)(
        a1: this->m_pAssetBrowser,
        a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      if ( (_BYTE)bIsVisible != 0 )
        ++this->m_nMatchingAssets;
      ++v5;
    }
    while ( v5 < nCount );
  }
  v12 = defaultValue;
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
    v12 = " ...";
  V_snprintf(
    pDest,
    maxLen: 512,
    pFormat: "%s (%d/%d)%s",
    this->m_pAssetType,
    this->m_nMatchingAssets,
    this->m_AssetList.m_Size,
    v12);
  this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: pDest);
  this->m_pAssetBrowser->SortList(this: this->m_pAssetBrowser);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0
    && this->m_pAssetBrowser->GetItemCount(this: this->m_pAssetBrowser) > 0 )
  {
    this->OnNextSelectionIsDefault(this);
    v13 = this->m_pAssetBrowser->GetItemIDFromRow(this: this->m_pAssetBrowser, a2: 0);
    this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v13, a3: 0);
  }
  m_pFileTree = this->m_pFileTree;
  v15 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
  CAssetTreeView::RefreshTreeViewItem(this: m_pFileTree, nItemIndex: v15);
  m_pFileTree->InvalidateLayout(this: m_pFileTree, a2: false, a3: false);
  this->OnAssetListChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B9750
// Name: protected: virtual void CBaseAssetPicker::OnFileSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::OnFileSelected(CBaseAssetPicker *this@<ecx>, int a2@<ebx>)
{
  const char *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  const char *String; // esi
  const char *v7; // eax
  int nLen; // [esp+Ch] [ebp-4h]

  v3 = defaultValue;
  v4 = this->m_pFileTree->GetFirstSelectedItem(this: this->m_pFileTree);
  if ( v4 >= 0 )
  {
    v5 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: v4);
    String = KeyValues::GetString(this: v5, keyName: "path", defaultValue: defaultValue);
    v3 = &String[_V_strlen(str: this->m_pAssetSubDir)];
    if ( *v3 != 0 )
      ++v3;
  }
  v7 = CUtlString::Get(this: &this->m_FolderFilter);
  if ( _V_stricmp(s1: v3, s2: v7) != 0 )
  {
    nLen = _V_strlen(str: v3);
    CUtlString::operator=(this: &this->m_FolderFilter, src: v3);
    if ( nLen > 0 )
      CUtlString::operator+=(this: &this->m_FolderFilter, c: 92);
    CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9800
// Name: protected: virtual void CBaseAssetPicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnTextChanged(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *pKeyValues)
{
  vgui::ComboBox *Ptr; // eax
  vgui::TextEntry *m_pFilter; // ecx
  int v7; // edi
  void *v8; // esp
  const char *v9; // eax
  vgui::ComboBox *m_pModSelector; // ecx
  KeyValues *ActiveItemUserData; // eax
  char v12[12]; // [esp+0h] [ebp-Ch] BYREF

  Ptr = (vgui::ComboBox *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  m_pFilter = this->m_pFilter;
  if ( Ptr == m_pFilter )
  {
    v7 = m_pFilter->GetTextLength(this: m_pFilter);
    v8 = alloca(v7 + 1);
    if ( v7 <= 0 )
      v12[0] = 0;
    else
      this->m_pFilter->GetText_2(this: this->m_pFilter, a2: v12, a3: v7 + 1);
    v9 = CUtlString::Get(this: &this->m_Filter);
    if ( _V_stricmp(s1: v12, s2: v9) != 0 )
    {
      CUtlString::SetLength(this: &this->m_Filter, nLen: v7);
      CUtlString::operator=(this: &this->m_Filter, src: v12);
      CBaseAssetPicker::RefreshAssetList(this, a2: (int)v12, a3: v7);
    }
  }
  else
  {
    m_pModSelector = this->m_pModSelector;
    if ( Ptr == m_pModSelector )
    {
      ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: m_pModSelector);
      if ( ActiveItemUserData != nullptr )
      {
        this->m_nCurrentModFilter = KeyValues::GetInt(this: ActiveItemUserData, keyName: "mod", defaultValue: -1);
        CBaseAssetPicker::RefreshAssetList(this, a2, a3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B98E0
// Name: protected: virtual void CBaseAssetPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnCheckButtonChecked(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *kv)
{
  vgui::CheckButton *Ptr; // eax
  vgui::CheckButton *m_pSubDirCheck; // ecx
  vgui::CheckButton *m_pOnlyUsedCheck; // ecx

  Ptr = (vgui::CheckButton *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSubDirCheck = this->m_pSubDirCheck;
  if ( Ptr == m_pSubDirCheck )
  {
    *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                             ^ (8
                              * ((int (__thiscall *)(vgui::CheckButton *))m_pSubDirCheck->IsSelected)(a1: m_pSubDirCheck)))
                            & 8;
    CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  }
  else
  {
    m_pOnlyUsedCheck = this->m_pOnlyUsedCheck;
    if ( Ptr == m_pOnlyUsedCheck )
    {
      *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                               ^ (16
                                * ((int (__thiscall *)(vgui::CheckButton *))m_pOnlyUsedCheck->IsSelected)(a1: m_pOnlyUsedCheck)))
                              & 0x10;
      CBaseAssetPicker::RefreshAssetList(this, a2, a3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9AB0
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B9B10
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const char *pSearchSubDir,
        int nExtCount,
        const char **ppSearchExt)
{
  int v5; // eax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // eax

  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  v5 = _V_strlen(str: pSearchSubDir);
  CUtlString::CUtlString(this: &this->m_pSubDir, pMemory: pSearchSubDir, nSizeInBytes: v5 + 1);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  this->m_DirectoriesToCheck.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
    this: (CUtlVector<int,CUtlMemory<int,int> > *)&this->m_Ext,
    elem: this->m_Ext.m_Size,
    num: nExtCount,
    pToInsert: (const int *)ppSearchExt);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B9BA0
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const CAssetCache::CachedAssetList_t *__formal)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B9C00
// Name: public: bool CAssetCache::ContinueSearchForAssets(struct AssetList_t__ __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::ContinueSearchForAssets(CAssetCache *this, AssetList_t__ *hList, float flDuration)
{
  CAssetCache::CachedAssetList_t *p_m_Data; // ebx
  const char *v4; // eax
  int m_hDirHandle; // ecx
  int m_hFind; // edx
  int *p_m_hFind; // esi
  char *v8; // eax
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  bool v11; // sf
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v12; // esi
  unsigned __int16 v13; // dx
  char pSearchString[260]; // [esp+18h] [ebp-110h] BYREF
  int hCurrentDir; // [esp+11Ch] [ebp-Ch]
  CAssetCache *v17; // [esp+120h] [ebp-8h]
  const char *pFilePath; // [esp+124h] [ebp-4h]
  float flStartTime; // [esp+130h] [ebp+8h]

  v17 = this;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)hList].m_Data;
  flStartTime = _Plat_FloatTime();
  if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount != 0 )
  {
    while ( 1 )
    {
      v4 = CUtlString::operator char const *(this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_DirName);
      m_hDirHandle = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_hDirHandle;
      m_hFind = p_m_Data->m_hFind;
      p_m_hFind = &p_m_Data->m_hFind;
      pFilePath = v4;
      hCurrentDir = m_hDirHandle;
      if ( m_hFind == -1 )
      {
        V_snprintf(pDest: pSearchString, maxLen: 260, pFormat: "%s\\*", v4);
        v8 = (char *)g_pFullFileSystem->FindFirstEx(
                       this: g_pFullFileSystem,
                       a2: pSearchString,
                       a3: v17->m_pAssetSearchPath,
                       a4: &p_m_Data->m_hFind);
      }
      else
      {
        v8 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: m_hFind);
      }
      if ( CAssetCache::AddFilesInDirectory(
             this: v17,
             list: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)p_m_Data,
             pStartingFile: v8,
             pFilePath,
             hCurrentDir,
             flStartTime,
             flDuration) == 0 )
        return 0;
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: *p_m_hFind);
      *p_m_hFind = -1;
      m_Head = p_m_Data->m_DirectoriesToCheck.m_Head;
      pFilePath = (const char *)m_Head;
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
        this: &p_m_Data->m_DirectoriesToCheck,
        elem: m_Head);
      m_pMemory = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory;
      v11 = m_pMemory[m_Head].m_Element.m_DirName.m_Storage.m_Memory.m_nGrowSize < 0;
      v12 = &m_pMemory[m_Head];
      v12->m_Element.m_DirName.m_Storage.m_nActualLength = 0;
      if ( !v11 )
      {
        if ( v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory);
          v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v12->m_Element.m_DirName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v13 = (unsigned __int16)pFilePath;
      v12->m_Next = p_m_Data->m_DirectoriesToCheck.m_FirstFree;
      p_m_Data->m_DirectoriesToCheck.m_FirstFree = v13;
      if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount == 0 )
        goto LABEL_11;
    }
  }
  else
  {
LABEL_11:
    p_m_Data->m_bAssetScanComplete = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9D80
// Name: public: CAssetCache::CachedAssetList_t::~CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::CachedAssetList_t::~CachedAssetList_t(CAssetCache::CachedAssetList_t *this)
{
  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirectoriesToCheck);
  if ( this->m_DirectoriesToCheck.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoriesToCheck.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoriesToCheck.m_Memory.m_pMemory);
      this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Ext);
  this->m_pSubDir.m_Storage.m_nActualLength = 0;
  if ( this->m_pSubDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pSubDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSubDir.m_Storage.m_Memory.m_pMemory);
      this->m_pSubDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pSubDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>::~CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>(this: &this->m_AssetList);
}

//------------------------------------------------------------------------------
// Address: 0x004B9DF0
// Name: public: CBaseAssetPicker::CBaseAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPicker *__thiscall CBaseAssetPicker::CBaseAssetPicker(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType,
        const char *pAssetSearchPath)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  char v11; // al
  KeyValues *v12; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "AssetPicker");
  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  if ( `CBaseAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    v8->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
    v9->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
    v10->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FolderFilter);
  CUtlString::CUtlString(this: &this->m_Filter);
  CUtlString::CUtlString(this: &this->m_SelectedAsset);
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_pMemory = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_nAllocationCount = 0;
  this->m_ExtraAssetExt.m_Memory.m_nGrowSize = 0;
  this->m_ExtraAssetExt.m_Size = 0;
  this->m_ExtraAssetExt.m_pElements = nullptr;
  this->m_usedAssets.m_Memory.m_pMemory = nullptr;
  this->m_usedAssets.m_Memory.m_nAllocationCount = 0;
  this->m_usedAssets.m_Memory.m_nGrowSize = 0;
  this->m_usedAssets.m_Size = 0;
  this->m_usedAssets.m_pElements = nullptr;
  this->m_pAssetExt = pExt;
  v11 = *((_BYTE *)this + 544) & 0xE8;
  this->m_pAssetType = pAssetType;
  this->m_pAssetTextType = pTextType;
  this->m_pAssetSubDir = pSubDir;
  this->m_pAssetSearchPath = pAssetSearchPath;
  this->m_nMatchingAssets = 0;
  *((_BYTE *)this + 544) = v11 | 8;
  this->m_hAssetList = (AssetList_t__ *)0xFFFF;
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    this->m_pInsertHelper = KeyValues::KeyValues(this: v12, setName: "node");
  else
    this->m_pInsertHelper = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B9FC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPicker::GetMessageMap(CBaseAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9FF0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPicker::GetAnimMap(CBaseAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004BA000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPicker::GetKBMap(CBaseAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BA030
// Name: public: virtual CBaseAssetPicker::~CBaseAssetPicker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::~CBaseAssetPicker(CBaseAssetPicker *this)
{
  KeyValues *m_pInsertHelper; // ecx

  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  this->m_pFileTree->RemoveActionSignalTarget(this: this->m_pFileTree, a2: this);
  this->m_pFileTree->SetParent_2(this: this->m_pFileTree, a2: nullptr);
  m_pInsertHelper = this->m_pInsertHelper;
  this->m_pFileTree = nullptr;
  if ( m_pInsertHelper != nullptr )
    KeyValues::deleteThis(this: m_pInsertHelper);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &this->m_usedAssets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ExtraAssetExt);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_AssetList);
  this->m_SelectedAsset.m_Storage.m_nActualLength = 0;
  if ( this->m_SelectedAsset.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory);
      this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SelectedAsset.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Filter.m_Storage.m_nActualLength = 0;
  if ( this->m_Filter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Filter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Filter.m_Storage.m_Memory.m_pMemory);
      this->m_Filter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Filter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FolderFilter.m_Storage.m_nActualLength = 0;
  if ( this->m_FolderFilter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FolderFilter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FolderFilter.m_Storage.m_Memory.m_pMemory);
      this->m_FolderFilter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FolderFilter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BA140
// Name: public: virtual void CBaseAssetPicker::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::ApplyUserConfigSettings(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pUserConfig)
{
  const char *String; // ebx
  const char *v5; // eax
  const char *v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int v9; // ebx
  int ItemIDFromRow; // edi
  KeyValues *ItemUserData; // eax
  int nItemCount; // [esp+Ch] [ebp-4h]
  int nItemCounta; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig: pUserConfig);
  CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)pUserConfig);
  String = KeyValues::GetString(this: pUserConfig, keyName: "filter", defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: pUserConfig, keyName: "folderfilter", defaultValue: defaultValue);
  CUtlString::operator=(this: &this->m_FolderFilter, src: v5);
  v6 = KeyValues::GetString(this: pUserConfig, keyName: "mod", defaultValue: defaultValue);
  CUtlString::operator=(this: &this->m_Filter, src: String);
  this->m_pFilter->SetText(this: this->m_pFilter, a2: String);
  v7 = 0;
  this->m_nCurrentModFilter = -1;
  if ( v6 != nullptr && *v6 != 0 )
  {
    nItemCount = s_AssetCache.m_ModList.m_Size;
    i = 0;
    if ( s_AssetCache.m_ModList.m_Size > 0 )
    {
      while ( 1 )
      {
        v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v7].m_ModName);
        if ( _V_stricmp(s1: v6, s2: v8) == 0 )
          break;
        ++v7;
        if ( ++i >= nItemCount )
          return;
      }
      v9 = 0;
      nItemCounta = this->m_pModSelector->GetItemCount(this: this->m_pModSelector);
      if ( nItemCounta > 0 )
      {
        while ( 1 )
        {
          ItemIDFromRow = vgui::ComboBox::GetItemIDFromRow(this: this->m_pModSelector, row: v9);
          ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pModSelector, itemID: ItemIDFromRow);
          if ( KeyValues::GetInt(this: ItemUserData, keyName: "mod", defaultValue: 0) == i )
            break;
          if ( ++v9 >= nItemCounta )
            return;
        }
        this->m_nCurrentModFilter = i;
        this->m_pModSelector->ActivateItem(this: this->m_pModSelector, a2: ItemIDFromRow);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA2A0
// Name: public: virtual void CBaseAssetPicker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::Activate(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax

  CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pFilter, status: true);
  this->m_pFilter->RequestFocus(this: this->m_pFilter, a2: 0);
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
  {
    v4 = g_pVGui;
    v5 = g_pVGui->__vftable;
    v6 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v5->AddTickSignal)(a1: v4, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA300
// Name: public: virtual bool CBaseAssetPicker::IncrementalCacheAssets(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAssetPicker::IncrementalCacheAssets(CBaseAssetPicker *this, float flTimeAllowed)
{
  char v3; // bl

  v3 = CAssetCache::ContinueSearchForAssets(this: &s_AssetCache, hList: this->m_hAssetList, flDuration: flTimeAllowed);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    CAssetTreeView::OpenRoot(this: this->m_pFileTree);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004BA350
// Name: public: virtual void CBaseAssetPicker::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnTick(CBaseAssetPicker *this)
{
  int v2; // edi
  int v3; // xmm0_4
  char v4; // al
  int i; // ebx
  vgui::IVGui *v6; // ebx
  vgui::IVGui_vtbl *v7; // edi
  int v8; // eax
  const char *v9; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v11; // eax
  const char *v12; // eax
  char v13[252]; // [esp+10h] [ebp-204h] BYREF
  char pDest[263]; // [esp+10Ch] [ebp-108h] BYREF
  char v15; // [esp+213h] [ebp-1h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = this->GetCachedAssetCount(this);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    v3 = 1048576000;
  else
    v3 = 1020054733;
  v4 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->IncrementalCacheAssets)(a1: this, a2: v3);
  *((_BYTE *)this + 544) &= ~2u;
  v15 = v4;
  for ( i = this->GetCachedAssetCount(this); v2 < i; ++v2 )
    CBaseAssetPicker::AddAssetToList(this, nAssetIndex: v2);
  if ( v15 != 0 )
  {
    v6 = g_pVGui;
    v7 = g_pVGui->__vftable;
    v8 = this->GetVPanel(this);
    v7->RemoveTickSignal(this: v6, a2: v8);
    *((_BYTE *)this + 544) |= 4u;
    v9 = CUtlString::operator char const *(this: &this->m_FolderFilter);
    m_pFileTree = this->m_pFileTree;
    V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", this->m_pAssetSubDir, v9);
    V_StripTrailingSlash(ppath: pDest);
    v11 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
    CAssetTreeView::SelectFolder_R(this: m_pFileTree, nItemID: v11, pPath: pDest);
    CBaseAssetPicker::RefreshAssetList(this, a2: (int)v6, a3: (int)m_pFileTree);
  }
  else
  {
    v12 = defaultValue;
    if ( (*((_BYTE *)this + 544) & 4) == 0 )
      v12 = " ...";
    V_snprintf(
      pDest: v13,
      maxLen: 512,
      pFormat: "%s (%d/%d)%s",
      this->m_pAssetType,
      this->m_nMatchingAssets,
      this->m_AssetList.m_Size,
      v12);
    this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA750
// Name: public: struct AssetList_t__ __near * CAssetCache::FindAssetList(char const __near *,char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
AssetList_t__ *__thiscall CAssetCache::FindAssetList(
        CAssetCache *this,
        const char *pAssetType,
        const char *pSubDir,
        int nExtCount,
        const char **ppExt)
{
  int v6; // edi
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // eax
  int p_m_Data; // esi
  CAssetTreeView *v9; // eax
  CAssetTreeView *v10; // eax
  CAssetCache::CachedAssetList_t search; // [esp+Ch] [ebp-60h] BYREF

  CAssetCache::CachedAssetList_t::CachedAssetList_t(
    this: &search,
    pSearchSubDir: pSubDir,
    nExtCount,
    ppSearchExt: ppExt);
  v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_CachedAssets,
         &search);
  if ( v6 == 0xFFFF )
  {
    v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_CachedAssets,
           insert: &search);
    m_pMemory = this->m_CachedAssets.m_Elements.m_pMemory;
    p_m_Data = (int)&m_pMemory[v6].m_Data;
    CUtlString::operator=(this: &m_pMemory[v6].m_Data.m_pSubDir, src: pSubDir);
    CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
      this: (CUtlVector<int,CUtlMemory<int,int> > *)(p_m_Data + 40),
      elem: *(_DWORD *)(p_m_Data + 52),
      num: nExtCount,
      pToInsert: (const int *)ppExt);
    *(_DWORD *)(p_m_Data + 88) = -1;
    *(_BYTE *)(p_m_Data + 92) = 0;
    v9 = (CAssetTreeView *)MemAlloc_Alloc(nSize: 0x210u);
    if ( v9 != nullptr )
      v10 = CAssetTreeView::CAssetTreeView(
              this: v9,
              pParent: nullptr,
              pName: "FolderFilter",
              pRootFolderName: pAssetType,
              pRootDir: pSubDir);
    else
      v10 = nullptr;
    *(_DWORD *)(p_m_Data + 20) = v10;
  }
  CAssetCache::CachedAssetList_t::~CachedAssetList_t(this: &search);
  return (AssetList_t__ *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x004BA810
// Name: protected: void CBaseAssetPicker::CreateStandardControls(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::CreateStandardControls(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        bool bAllowMultiselect)
{
  int v4; // edi
  void *v5; // esp
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v9; // ebx
  vgui::ComboBox *v10; // eax
  vgui::ComboBox *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  AssetList_t__ *m_hAssetList; // eax
  CAssetTreeView *m_pFileTree; // ecx
  vgui::CheckButton *v16; // eax
  vgui::CheckButton *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::ListPanel *v19; // eax
  vgui::Panel *v20; // edi
  vgui::TextEntry *v21; // eax
  vgui::TextEntry *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  BOOL v25; // ecx
  vgui::TextEntry *v26; // eax
  vgui::TextEntry *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  const char *m_pAssetExt; // [esp+0h] [ebp-20Ch] BYREF
  unsigned __int8 v31[8]; // [esp+4h] [ebp-208h] BYREF
  char pDest[512]; // [esp+Ch] [ebp-200h] BYREF

  v4 = this->m_ExtraAssetExt.m_Size + 1;
  v5 = alloca(4 * v4);
  m_pAssetExt = this->m_pAssetExt;
  if ( v4 > 1 )
    memcpy(dst: v31, src: (unsigned __int8 *)this->m_ExtraAssetExt.m_Memory.m_pMemory, count: v4 - 1);
  this->m_hAssetList = CAssetCache::FindAssetList(
                         this: &s_AssetCache,
                         pAssetType: this->m_pAssetType,
                         pSubDir: this->m_pAssetSubDir,
                         nExtCount: v4,
                         ppExt: &m_pAssetExt);
  v6 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: pParent,
           name: "AssetSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  else
    v7 = nullptr;
  this->m_pAssetSplitter = v7;
  vgui::Panel::SetAutoResize(
    this: v7,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  Child = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v10 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v10 != nullptr )
    v11 = vgui::ComboBox::ComboBox(this: v10, parent: Child, panelName: "ModFilter", numLines: 5, allowEdit: false);
  else
    v11 = nullptr;
  this->m_pModSelector = v11;
  v11->AddActionSignalTarget_2(this: v11, a2: this);
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: Child,
            panelName: "RescanButton",
            text: "Rescan",
            pActionSignalTarget: this,
            pCmd: "AssetRescan");
  else
    v13 = nullptr;
  this->m_pRescanButton = v13;
  vgui::Panel::SetWide(this: v13, wide: 75);
  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    m_pFileTree = nullptr;
  else
    m_pFileTree = s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_pFileTree;
  this->m_pFileTree = m_pFileTree;
  m_pFileTree->SetParent_2(this: m_pFileTree, a2: Child);
  this->m_pFileTree->AddActionSignalTarget_2(this: this->m_pFileTree, a2: this);
  v16 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v16 != nullptr )
    v17 = vgui::CheckButton::CheckButton(
            this: v16,
            parent: Child,
            panelName: "SubDirCheck",
            text: "Check subfolders for files?");
  else
    v17 = nullptr;
  this->m_pSubDirCheck = v17;
  v17->SetSelected(this: v17, a2: true);
  this->m_pSubDirCheck->SetEnabled(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->SetVisible(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->AddActionSignalTarget_2(this: this->m_pSubDirCheck, a2: this);
  V_snprintf(pDest, maxLen: 512, pFormat: "No .%s files", this->m_pAssetExt);
  v18 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v18 != nullptr )
    v19 = vgui::ListPanel::ListPanel(this: v18, parent: v9, panelName: "AssetBrowser");
  else
    v19 = nullptr;
  this->m_pAssetBrowser = v19;
  v19->AddColumnHeader(this: v19, a2: 0, a3: "mod", a4: "Mod", a5: 52, a6: 0);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 1,
    a3: "asset",
    a4: this->m_pAssetType,
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 2,
    a3: "timesused",
    a4: "Times Used",
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->SetSelectIndividualCells(this: this->m_pAssetBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pAssetBrowser, bState: bAllowMultiselect);
  this->m_pAssetBrowser->SetEmptyListText_2(this: this->m_pAssetBrowser, a2: pDest);
  this->m_pAssetBrowser->SetDragEnabled(this: this->m_pAssetBrowser, a2: true);
  this->m_pAssetBrowser->AddActionSignalTarget_2(this: this->m_pAssetBrowser, a2: this);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 0, a3: AssetBrowserModSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 1, a3: AssetBrowserSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 2, a3: AssetBrowserTimesUsedSortFunc);
  this->m_pAssetBrowser->SetSortColumn(this: this->m_pAssetBrowser, a2: 1);
  v20 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v21 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v21 != nullptr )
    v22 = vgui::TextEntry::TextEntry(this: v21, parent: v20, panelName: "FilterList");
  else
    v22 = nullptr;
  this->m_pFilter = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(
            this: v23,
            parent: v20,
            panelName: "OnlyUsedCheck",
            text: "Show used assets only");
  else
    v24 = nullptr;
  v25 = (*((_BYTE *)this + 544) & 0x10) != 0;
  this->m_pOnlyUsedCheck = v24;
  v24->SetSelected(this: v24, a2: v25);
  this->m_pOnlyUsedCheck->AddActionSignalTarget_2(this: this->m_pOnlyUsedCheck, a2: this);
  v26 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v26 != nullptr )
    v27 = vgui::TextEntry::TextEntry(this: v26, parent: v20, panelName: "FullPath");
  else
    v27 = nullptr;
  this->m_pFullPath = v27;
  v27->SetEnabled(this: v27, a2: false);
  this->m_pFullPath->SetEditable(this: this->m_pFullPath, a2: false);
  v28 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: v20,
            panelName: "FindButton",
            text: "Find Asset",
            pActionSignalTarget: this,
            pCmd: "FindAsset");
  else
    v29 = nullptr;
  this->m_nCurrentModFilter = -1;
  this->m_pFindAssetButton = v29;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10205EB0
// Name: public: static char const __near * CBaseAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPicker::GetPanelClassName()
{
  return "CBaseAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x10205EC0
// Name: public: static char const __near * CBaseAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPickerFrame::GetPanelClassName()
{
  return "CBaseAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x10205ED0
// Name: bool AssetTreeViewSortFunc(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AssetTreeViewSortFunc(KeyValues *node1, KeyValues *node2)
{
  const char *String; // esi
  const char *v3; // eax

  String = KeyValues::GetString(this: node1, keyName: "text", defaultValue: nullptr);
  v3 = KeyValues::GetString(this: node2, keyName: "text", defaultValue: nullptr);
  return _V_stricmp(s1: String, s2: v3) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10205F10
// Name: public: static char const __near * CAssetTreeView::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetTreeView::GetPanelClassName()
{
  return "CAssetTreeView";
}

//------------------------------------------------------------------------------
// Address: 0x10205F20
// Name: AssetBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  bool v3; // bl
  const char *String; // esi
  const char *v6; // eax

  v3 = KeyValues::GetInt(this: item1->kv, keyName: "root", defaultValue: 0) != 0;
  if ( v3 != (KeyValues::GetInt(this: item2->kv, keyName: "root", defaultValue: 0) != 0) )
    return 2 * !v3 - 1;
  String = KeyValues::GetString(this: item1->kv, keyName: "asset", defaultValue: &var);
  v6 = KeyValues::GetString(this: item2->kv, keyName: "asset", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10205FA0
// Name: AssetBrowserModSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserModSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "modIndex", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "modIndex", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x10206000
// Name: AssetBrowserTimesUsedSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserTimesUsedSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "timesused", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "timesused", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x10206050
// Name: public: bool CBaseAssetPicker::IsMultiselectEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAssetPicker::IsMultiselectEnabled(CBaseAssetPicker *this)
{
  return vgui::ListPanel::IsMultiselectEnabled(this: this->m_pAssetBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x10206060
// Name: public: void CBaseAssetPicker::SetSelection(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::SetSelection(CBaseAssetPicker *this, const char *pAssetName, bool bInitialSelection)
{
  int v4; // esi

  if ( bInitialSelection )
    CUtlString::operator=(this: &this->m_SelectedAsset, src: pAssetName);
  if ( pAssetName != nullptr )
  {
    v4 = this->m_pAssetBrowser->GetItem_2(this: this->m_pAssetBrowser, a2: pAssetName);
    if ( v4 != -1 )
    {
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v4, a3: 0);
      vgui::ListPanel::ScrollToItem(this: this->m_pAssetBrowser, nItemID: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102060C0
// Name: public: void CBaseAssetPicker::SetFilter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::SetFilter(CBaseAssetPicker *this, const char *pFilter)
{
  CUtlString::operator=(this: &this->m_Filter, src: pFilter);
  this->m_pFilter->SetText(this: this->m_pFilter, a2: pFilter);
}

//------------------------------------------------------------------------------
// Address: 0x102060F0
// Name: public: char const __near * CBaseAssetPicker::GetFilter(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetFilter(CBaseAssetPicker *this)
{
  return CUtlString::operator char const *(this: &this->m_Filter);
}

//------------------------------------------------------------------------------
// Address: 0x10206100
// Name: public: virtual void CBaseAssetPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnKeyCodeTyped(CBaseAssetPicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  vgui::IPanel *v5; // esi
  vgui::ListPanel *m_pAssetBrowser; // edi
  int v7; // eax
  int v8; // eax
  vgui::IPanel_vtbl *codea; // [esp+14h] [ebp+8h]

  if ( code == KEY_UP || code == KEY_DOWN || code == KEY_PAGEUP || code == KEY_PAGEDOWN )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "KeyCodeTyped", firstKey: "code", firstValue: code);
    else
      v4 = nullptr;
    v5 = g_pVGuiPanel;
    m_pAssetBrowser = this->m_pAssetBrowser;
    codea = g_pVGuiPanel->__vftable;
    v7 = this->GetVPanel(this);
    v8 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pAssetBrowser->GetVPanel)(
           a1: m_pAssetBrowser,
           a2: v4,
           a3: v7);
    ((void (__thiscall *)(vgui::IPanel *, int))codea->SendMessage)(a1: v5, a2: v8);
    KeyValues::deleteThis(this: v4);
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102061A0
// Name: protected: bool CBaseAssetPicker::IsAssetVisible(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAssetPicker::IsAssetVisible(CBaseAssetPicker *this, const CachedAssetInfo_t *nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ecx
  int m_nCurrentModFilter; // eax
  const char *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-Ch] [ebp-10h]
  const CachedAssetInfo_t *info; // [esp+Ch] [ebp+8h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  info = v3;
  if ( m_nCurrentModFilter >= 0 && m_nCurrentModFilter != v3->m_nModIndex )
    return false;
  v6 = CUtlString::operator char const *(this: &v3->m_AssetName);
  v7 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
  if ( _V_strcmp(s1: v6, s2: v7) == 0 )
    return true;
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
  {
    v8 = CUtlString::Get(this: &this->m_Filter);
    if ( V_stristr(pStr: v6, pSearch: v8) == nullptr )
      return false;
  }
  if ( CUtlString::Length(this: &this->m_FolderFilter) != 0 )
  {
    v12 = CUtlString::Length(this: &this->m_FolderFilter);
    v9 = CUtlString::Get(this: &this->m_FolderFilter);
    if ( V_strnicmp(s1: v6, s2: v9, n: v12) != 0 )
      return false;
  }
  if ( (*((_BYTE *)this + 544) & 8) == 0 )
  {
    v10 = CUtlString::Length(this: &this->m_FolderFilter);
    strchr(string: (char *)&v6[v10], chr: 0x5Cu);
    if ( v11 != 0 )
      return false;
  }
  return (*((_BYTE *)this + 544) & 0x10) == 0 || info->m_nTimesUsed != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102062A0
// Name: protected: void CBaseAssetPicker::RequestFilterFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::RequestFilterFocus(CBaseAssetPicker *this)
{
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pFilter, status: true);
  this->m_pFilter->RequestFocus(this: this->m_pFilter, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102062D0
// Name: protected: virtual void CBaseAssetPicker::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemDeselected(CBaseAssetPicker *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
    this->OnSelectedAssetPicked(this, a2: &var);
}

//------------------------------------------------------------------------------
// Address: 0x10206310
// Name: public: int CBaseAssetPicker::GetSelectedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetSelectedAssetCount(CBaseAssetPicker *this)
{
  return this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x10206320
// Name: public: char const __near * CBaseAssetPicker::GetSelectedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetSelectedAsset(CBaseAssetPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  v4 = nSelectionIndex;
  if ( nSelectionIndex < 0 )
    v4 = v3 - 1;
  if ( v3 <= v4 || v4 < 0 )
    return nullptr;
  v5 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: v4);
  v6 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v5);
  return KeyValues::GetString(this: v6, keyName: "asset", defaultValue: &var);
}

//------------------------------------------------------------------------------
// Address: 0x10206390
// Name: public: int CBaseAssetPicker::GetSelectedAssetIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetSelectedAssetIndex(CBaseAssetPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  v4 = nSelectionIndex;
  if ( nSelectionIndex < 0 )
    v4 = v3 - 1;
  if ( v3 <= v4 || v4 < 0 )
    return -1;
  v5 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: v4);
  v6 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v5);
  return KeyValues::GetInt(this: v6, keyName: "assetIndex", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10206400
// Name: protected: void CBaseAssetPickerFrame::SetAssetPicker(class CBaseAssetPicker __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::SetAssetPicker(CBaseAssetPickerFrame *this, CBaseAssetPicker *pPicker)
{
  this->m_pPicker = pPicker;
  pPicker->AddActionSignalTarget_2(this: pPicker, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10206420
// Name: public: void CBaseAssetPickerFrame::DoModal(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::DoModal(CBaseAssetPickerFrame *this, KeyValues *pKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  KeyValues *v4; // ecx
  CBaseAssetPicker *m_pPicker; // ecx

  vgui::Frame::DoModal(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  v4 = this->m_pContextKeyValues;
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pKeyValues;
  m_pPicker->Activate(this: m_pPicker);
}

//------------------------------------------------------------------------------
// Address: 0x10206480
// Name: protected: void CBaseAssetPickerFrame::PostMessageAndClose(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::PostMessageAndClose(CBaseAssetPickerFrame *this, KeyValues *pKeyValues)
{
  if ( this->m_pContextKeyValues != nullptr )
  {
    KeyValues::AddSubKey(this: pKeyValues, pSubkey: this->m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->CloseModal(this);
  this->PostActionSignal(this, a2: pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x102064D0
// Name: public: virtual void CBaseAssetPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPickerFrame::OnCommand(CBaseAssetPickerFrame *this@<ecx>, int a2@<ebx>, KeyValues *pCommand)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  CBaseAssetPicker *m_pPicker; // esi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  KeyValues *v10; // eax
  const char *String; // eax
  int v12; // ebx
  int i; // esi
  const char *SelectedAsset; // eax
  char pBuf[512]; // [esp+8h] [ebp-204h] BYREF
  KeyValues *pAssetKeys; // [esp+208h] [ebp-4h]
  KeyValues *pActionKeys; // [esp+214h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "AssetSelected");
      pActionKeys = v5;
    }
    else
    {
      pActionKeys = nullptr;
      v5 = nullptr;
    }
    if ( vgui::ListPanel::IsMultiselectEnabled(this: this->m_pPicker->m_pAssetBrowser) )
    {
      pAssetKeys = KeyValues::FindKey(this: v5, keyName: "assets", bCreate: true);
      v12 = ((int (__thiscall *)(vgui::ListPanel *, int))this->m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
              a1: this->m_pPicker->m_pAssetBrowser,
              a2);
      for ( i = 0; i < v12; ++i )
      {
        V_snprintf(pDest: pBuf, maxLen: 512, pFormat: "asset%d", i);
        SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this: this->m_pPicker, nSelectionIndex: i);
        KeyValues::SetString(this: pAssetKeys, keyName: pBuf, value: SelectedAsset);
      }
      v5 = pActionKeys;
    }
    else
    {
      m_pPicker = this->m_pPicker;
      v7 = ((int (__thiscall *)(vgui::ListPanel *, int))m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
             a1: m_pPicker->m_pAssetBrowser,
             a2);
      v8 = v7 - 1;
      if ( __OFSUB__(v7, v7 - 1) || v8 < 0 )
      {
        KeyValues::SetString(this: v5, keyName: "asset", value: nullptr);
      }
      else
      {
        v9 = m_pPicker->m_pAssetBrowser->GetSelectedItem(this: m_pPicker->m_pAssetBrowser, a2: v8);
        v10 = m_pPicker->m_pAssetBrowser->GetItem(this: m_pPicker->m_pAssetBrowser, a2: v9);
        String = KeyValues::GetString(this: v10, keyName: "asset", defaultValue: &var);
        KeyValues::SetString(this: v5, keyName: "asset", value: String);
      }
    }
    this->m_pPicker->CustomizeSelectionMessage(this: this->m_pPicker, a2: v5);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->CloseModal(this);
    ((void (__thiscall *)(CBaseAssetPickerFrame *))this->PostActionSignal)(a1: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102066B0
// Name: protected: virtual void CBaseAssetPickerFrame::CloseModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::CloseModal(CBaseAssetPickerFrame *this)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  unsigned int v4; // eax

  v2 = g_pVGui;
  v3 = g_pVGui->__vftable;
  v4 = this->m_pPicker->GetVPanel(this: this->m_pPicker);
  v3->RemoveTickSignal(this: v2, a2: v4);
  vgui::Frame::CloseModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x10206700
// Name: public: virtual void CAssetTreeView::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ApplySchemeSettings(CAssetTreeView *this, vgui::IScheme *pScheme)
{
  CAssetTreeView_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultSmall", a3: false);
  v3->SetFont(this, a2: v4);
  ((void (__thiscall *)(CAssetTreeView *, int))this->SetFgColor)(a1: this, a2: -2892072);
}

//------------------------------------------------------------------------------
// Address: 0x10206750
// Name: protected: void CBaseAssetPicker::AutoLayoutStandardControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AutoLayoutStandardControls(CBaseAssetPicker *this)
{
  vgui::CBoxSizer *v2; // ebx
  vgui::Panel *Child; // esi
  vgui::CBoxSizer *v4; // eax
  vgui::CBoxSizer *v5; // eax
  vgui::Label *v6; // eax
  vgui::Label *v7; // eax
  vgui::CSizerBase *v8; // ebx
  vgui::CheckButton *m_pSubDirCheck; // edx
  vgui::CBoxSizer *v10; // eax
  vgui::CBoxSizer *v11; // ebx
  vgui::CBoxSizer *v12; // eax
  vgui::CBoxSizer *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::CBoxSizer *v16; // eax
  vgui::CBoxSizer *v17; // ebx
  vgui::Label *v18; // eax
  vgui::Label *v19; // eax
  vgui::CBoxSizer *v20; // eax
  vgui::CBoxSizer *v21; // ebx
  vgui::Label *v22; // eax
  vgui::Label *v23; // eax
  vgui::Panel *v24; // esi
  int m_Size; // [esp-Ch] [ebp-38h]
  int v26; // [esp-Ch] [ebp-38h]
  int v27; // [esp-Ch] [ebp-38h]
  int v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-Ch] [ebp-38h]
  int v30; // [esp-Ch] [ebp-38h]
  int v31; // [esp-Ch] [ebp-38h]
  int v32; // [esp-Ch] [ebp-38h]
  int v33; // [esp-Ch] [ebp-38h]
  int v34; // [esp-Ch] [ebp-38h]
  int v35; // [esp-Ch] [ebp-38h]
  int v36; // [esp-Ch] [ebp-38h]
  int v37; // [esp-Ch] [ebp-38h]
  int v38; // [esp-Ch] [ebp-38h]
  int v39; // [esp-Ch] [ebp-38h]
  int v40; // [esp-Ch] [ebp-38h]
  vgui::ComboBox *m_pModSelector; // [esp-8h] [ebp-34h]
  vgui::Button *m_pRescanButton; // [esp-8h] [ebp-34h]
  vgui::CSizerBase *v43; // [esp-8h] [ebp-34h]
  CAssetTreeView *m_pFileTree; // [esp-8h] [ebp-34h]
  vgui::ListPanel *m_pAssetBrowser; // [esp-8h] [ebp-34h]
  vgui::TextEntry *m_pFullPath; // [esp-8h] [ebp-34h]
  vgui::Button *m_pFindAssetButton; // [esp-8h] [ebp-34h]
  vgui::TextEntry *m_pFilter; // [esp-8h] [ebp-34h]
  vgui::CheckButton *m_pOnlyUsedCheck; // [esp-8h] [ebp-34h]
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-20h] BYREF
  vgui::Panel *pSplitterBottomLeftSide; // [esp+24h] [ebp-8h]
  vgui::Panel *pSplitterTopLeftSide; // [esp+28h] [ebp-4h]

  v2 = nullptr;
  Child = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 0);
  pSplitterTopLeftSide = Child;
  v4 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v4 != nullptr )
    pSplitterBottomLeftSide = (vgui::Panel *)vgui::CBoxSizer::CBoxSizer(this: v4, LayoutDirection: ESLD_VERTICAL);
  else
    pSplitterBottomLeftSide = nullptr;
  v5 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v5 != nullptr )
    v2 = vgui::CBoxSizer::CBoxSizer(this: v5, LayoutDirection: ESLD_HORIZONTAL);
  v6 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v6 != nullptr )
    v7 = vgui::Label::Label(this: v6, parent: Child, panelName: "ModFilterLabel", text: "Mod Filter");
  else
    v7 = nullptr;
  m_Size = v2->m_Members.m_Size;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: v2, nIndex: m_Size, pPanel: v7, &args);
  m_pModSelector = this->m_pModSelector;
  v26 = v2->m_Members.m_Size;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v2, nIndex: v26, pPanel: m_pModSelector, &args);
  m_pRescanButton = this->m_pRescanButton;
  v27 = v2->m_Members.m_Size;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: v2, nIndex: v27, pPanel: m_pRescanButton, &args);
  v43 = v2;
  v8 = (vgui::CSizerBase *)pSplitterBottomLeftSide;
  v28 = *(_DWORD *)&pSplitterBottomLeftSide->m_OnNavigateFrom_register;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertSizer(this: (vgui::CSizerBase *)pSplitterBottomLeftSide, nIndex: v28, pSizer: v43, &args);
  this->m_pSubDirCheck->SetEnabled(this: this->m_pSubDirCheck, a2: true);
  this->m_pSubDirCheck->SetVisible(this: this->m_pSubDirCheck, a2: true);
  m_pSubDirCheck = this->m_pSubDirCheck;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: v8, nIndex: v8->m_Members.m_Size, pPanel: m_pSubDirCheck, &args);
  m_pFileTree = this->m_pFileTree;
  v29 = v8->m_Members.m_Size;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v8, nIndex: v29, pPanel: m_pFileTree, &args);
  vgui::Panel::SetSizer(this: pSplitterTopLeftSide, pSizer: v8);
  pSplitterBottomLeftSide = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v10 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  v11 = nullptr;
  if ( v10 != nullptr )
  {
    v12 = vgui::CBoxSizer::CBoxSizer(this: v10, LayoutDirection: ESLD_VERTICAL);
    pSplitterTopLeftSide = (vgui::Panel *)v12;
  }
  else
  {
    pSplitterTopLeftSide = nullptr;
    v12 = nullptr;
  }
  m_pAssetBrowser = this->m_pAssetBrowser;
  v30 = v12->m_Members.m_Size;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v12, nIndex: v30, pPanel: m_pAssetBrowser, &args);
  v13 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v13 != nullptr )
    v11 = vgui::CBoxSizer::CBoxSizer(this: v13, LayoutDirection: ESLD_HORIZONTAL);
  v14 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v14 != nullptr )
    v15 = vgui::Label::Label(this: v14, parent: pSplitterBottomLeftSide, panelName: "FullPathLabel", text: "Full Path");
  else
    v15 = nullptr;
  v31 = v11->m_Members.m_Size;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: v11, nIndex: v31, pPanel: v15, &args);
  m_pFullPath = this->m_pFullPath;
  v32 = v11->m_Members.m_Size;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v11, nIndex: v32, pPanel: m_pFullPath, &args);
  m_pFindAssetButton = this->m_pFindAssetButton;
  v33 = v11->m_Members.m_Size;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v11, nIndex: v33, pPanel: m_pFindAssetButton, &args);
  v34 = *(_DWORD *)&pSplitterTopLeftSide->m_OnNavigateFrom_register;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertSizer(this: (vgui::CSizerBase *)pSplitterTopLeftSide, nIndex: v34, pSizer: v11, &args);
  v16 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v16 != nullptr )
    v17 = vgui::CBoxSizer::CBoxSizer(this: v16, LayoutDirection: ESLD_HORIZONTAL);
  else
    v17 = nullptr;
  v18 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v18 != nullptr )
    v19 = vgui::Label::Label(this: v18, parent: pSplitterBottomLeftSide, panelName: "FilterLabel", text: "Filter");
  else
    v19 = nullptr;
  v35 = v17->m_Members.m_Size;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: v17, nIndex: v35, pPanel: v19, &args);
  m_pFilter = this->m_pFilter;
  v36 = v17->m_Members.m_Size;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v17, nIndex: v36, pPanel: m_pFilter, &args);
  v37 = *(_DWORD *)&pSplitterTopLeftSide->m_OnNavigateFrom_register;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertSizer(this: (vgui::CSizerBase *)pSplitterTopLeftSide, nIndex: v37, pSizer: v17, &args);
  v20 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v20 != nullptr )
    v21 = vgui::CBoxSizer::CBoxSizer(this: v20, LayoutDirection: ESLD_HORIZONTAL);
  else
    v21 = nullptr;
  m_pOnlyUsedCheck = this->m_pOnlyUsedCheck;
  v38 = v21->m_Members.m_Size;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v21, nIndex: v38, pPanel: m_pOnlyUsedCheck, &args);
  v22 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v22 != nullptr )
    v23 = vgui::Label::Label(
            this: v22,
            parent: pSplitterBottomLeftSide,
            panelName: "OnlyUsedLabel",
            text: "Show used assets only");
  else
    v23 = nullptr;
  v39 = v21->m_Members.m_Size;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: v21, nIndex: v39, pPanel: v23, &args);
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  v24 = pSplitterTopLeftSide;
  v40 = *(_DWORD *)&pSplitterTopLeftSide->m_OnNavigateFrom_register;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertSizer(this: (vgui::CSizerBase *)pSplitterTopLeftSide, nIndex: v40, pSizer: v21, &args);
  vgui::Panel::SetSizer(this: pSplitterBottomLeftSide, pSizer: (vgui::CSizerBase *)v24);
}

//------------------------------------------------------------------------------
// Address: 0x10206C70
// Name: public: void CBaseAssetPicker::SetInitialSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::SetInitialSelection(CBaseAssetPicker *this, const char *pAssetName)
{
  int v3; // edi

  CUtlString::operator=(this: &this->m_SelectedAsset, src: pAssetName);
  if ( pAssetName != nullptr )
  {
    v3 = this->m_pAssetBrowser->GetItem_2(this: this->m_pAssetBrowser, a2: pAssetName);
    if ( v3 != -1 )
    {
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v3, a3: 0);
      vgui::ListPanel::ScrollToItem(this: this->m_pAssetBrowser, nItemID: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206CD0
// Name: public: virtual int CBaseAssetPicker::GetAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetAssetCount(CBaseAssetPicker *this)
{
  return this->m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10206CE0
// Name: public: int CBaseAssetPicker::ModCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::ModCount(CBaseAssetPicker *this)
{
  return s_AssetCache.m_ModList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10206CF0
// Name: public: CBaseAssetPickerFrame::CBaseAssetPickerFrame(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPickerFrame *__thiscall CBaseAssetPickerFrame::CBaseAssetPickerFrame(
        CBaseAssetPickerFrame *this,
        vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "AssetPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( `CBaseAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
    v3->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
    v4->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
    v5->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v6 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "OpenButton",
           text: "#FileOpenDialog_Open",
           pActionSignalTarget: this,
           pCmd: "Open");
  else
    v7 = nullptr;
  this->m_pOpenButton = v7;
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#FileOpenDialog_Cancel",
           pActionSignalTarget: this,
           pCmd: "Cancel");
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10206E40
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPickerFrame::GetMessageMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10206E70
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPickerFrame::GetAnimMap(CBaseAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x10206E80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPickerFrame::GetKBMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10206EB0
// Name: public: virtual CBaseAssetPickerFrame::~CBaseAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::~CBaseAssetPickerFrame(CBaseAssetPickerFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10206EE0
// Name: public: void CBaseAssetPickerFrame::SetInitialSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::SetInitialSelection(CBaseAssetPickerFrame *this, const char *pAssetName)
{
  CBaseAssetPicker *m_pPicker; // esi
  int v3; // edi

  m_pPicker = this->m_pPicker;
  CUtlString::operator=(this: &m_pPicker->m_SelectedAsset, src: pAssetName);
  if ( pAssetName != nullptr )
  {
    v3 = m_pPicker->m_pAssetBrowser->GetItem_2(this: m_pPicker->m_pAssetBrowser, a2: pAssetName);
    if ( v3 != -1 )
    {
      m_pPicker->m_pAssetBrowser->SetSelectedCell(this: m_pPicker->m_pAssetBrowser, a2: v3, a3: 0);
      vgui::ListPanel::ScrollToItem(this: m_pPicker->m_pAssetBrowser, nItemID: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207070
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207120
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102071D0
// Name: public: void CAssetTreeView::OpenRoot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::OpenRoot(CAssetTreeView *this)
{
  const char *v2; // ebx
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  CAssetTreeView_vtbl *v6; // ebx
  int v7; // eax
  int v8; // ebx

  this->RemoveAll(this);
  v2 = CUtlString::operator char const *(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[this->m_DirectoryStructure.m_Root].m_Element);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "root");
  else
    v4 = nullptr;
  v5 = CUtlString::Get(this: &this->m_RootFolderName);
  KeyValues::SetString(this: v4, keyName: "text", value: v5);
  KeyValues::SetInt(this: v4, keyName: "root", value: 1);
  KeyValues::SetInt(this: v4, keyName: "expand", value: 1);
  KeyValues::SetInt(this: v4, keyName: "dirHandle", value: this->m_DirectoryStructure.m_Root);
  KeyValues::SetString(this: v4, keyName: "path", value: v2);
  v6 = this->__vftable;
  v7 = this->GetRootItemIndex(this);
  v8 = v6->AddItem(this, a2: v4, a3: v7);
  KeyValues::deleteThis(this: v4);
  this->ExpandItem(this, a2: v8, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x102072B0
// Name: private: static bool CAssetCache::CachedAssetLessFunc(struct CAssetCache::CachedAssetList_t const __near &,struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAssetCache::CachedAssetLessFunc(
        const CAssetCache::CachedAssetList_t *src1,
        const CAssetCache::CachedAssetList_t *src2)
{
  const char *v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  const char *v9; // [esp-4h] [ebp-Ch]
  int nCount; // [esp+14h] [ebp+Ch]

  v9 = CUtlString::operator char const *(this: &src2->m_pSubDir);
  v3 = CUtlString::operator char const *(this: &src1->m_pSubDir);
  v4 = _V_stricmp(s1: v3, s2: v9) > 0;
  if ( v4 != 0 )
    return v4 > 0;
  v6 = src1->m_Ext.m_Size - src2->m_Ext.m_Size;
  nCount = src1->m_Ext.m_Size;
  if ( v6 != 0 )
    return v6 > 0;
  v7 = 0;
  if ( src1->m_Ext.m_Size <= 0 )
    return false;
  while ( 1 )
  {
    v8 = _V_stricmp(s1: src1->m_Ext.m_Memory.m_pMemory[v7], s2: src2->m_Ext.m_Memory.m_pMemory[v7]);
    if ( v8 != 0 )
      break;
    if ( ++v7 >= nCount )
      return false;
  }
  return v8 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10207350
// Name: private: int CAssetCache::GetAssetUsageCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAssetCache::GetAssetUsageCount(CAssetCache *this, const char *assetName)
{
  int result; // eax
  int v4; // edi
  int i; // ebx
  char *v6; // eax

  result = this->m_usedAssets.m_Size;
  if ( result != 0 )
  {
    v4 = 0;
    if ( result <= 0 )
    {
      return 0;
    }
    else
    {
      for ( i = 0; ; ++i )
      {
        v6 = CUtlString::Get(this: &this->m_usedAssets.m_Memory.m_pMemory[i].m_assetName);
        if ( V_stristr(pStr: v6, pSearch: assetName) != nullptr )
          break;
        if ( ++v4 >= this->m_usedAssets.m_Size )
          return 0;
      }
      return this->m_usedAssets.m_Memory.m_pMemory[v4].m_nTimesUsed;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102073B0
// Name: private: bool CAssetCache::DoesExtensionMatch(struct CAssetCache::CachedAssetList_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::DoesExtensionMatch(
        CAssetCache *this,
        CAssetCache::CachedAssetList_t *info,
        const char *pFileName)
{
  int m_Size; // edi
  int v4; // esi
  char pChildExt[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_stristr(pStr: pFileName, pSearch: ".360.") != nullptr
    || V_stristr(pStr: pFileName, pSearch: ".ps3.") != nullptr )
  {
    return 0;
  }
  V_ExtractFileExtension(path: pFileName, dest: pChildExt, destSize: 260);
  m_Size = info->m_Ext.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: info->m_Ext.m_Memory.m_pMemory[v4], s2: pChildExt) != 0 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10207450
// Name: public: struct CacheModInfo_t const __near & CBaseAssetPicker::ModInfo(int)const
// Source: json
//------------------------------------------------------------------------------
const CacheModInfo_t *__thiscall CBaseAssetPicker::ModInfo(CBaseAssetPicker *this, int nIndex)
{
  return &s_AssetCache.m_ModList.m_Memory.m_pMemory[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10207B70
// Name: private: void CAssetTreeView::AddDirectoryToTreeView(int,char const __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::AddDirectoryToTreeView(
        CAssetTreeView *this,
        int nParentItemIndex,
        const char *pFullParentPath,
        int hPath)
{
  int v5; // ebx
  const char *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  unsigned __int16 m_FirstChild; // bx
  int v10; // ebx
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // edx
  char pFullPath[260]; // [esp+Ch] [ebp-108h] BYREF
  const char *pDirName; // [esp+110h] [ebp-4h]

  v5 = (unsigned __int16)hPath;
  v6 = CUtlString::Get(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_Element);
  pDirName = v6;
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "text", firstValue: v6);
  else
    v8 = nullptr;
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s/%s", pFullParentPath, pDirName);
  V_FixSlashes(pname: pFullPath, separator: 92);
  _V_strlower(start: pFullPath);
  m_FirstChild = this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_FirstChild;
  KeyValues::SetString(this: v8, keyName: "path", value: pFullPath);
  KeyValues::SetInt(this: v8, keyName: "expand", value: m_FirstChild != 0xFFFF);
  KeyValues::SetInt(this: v8, keyName: "image", value: 0);
  KeyValues::SetInt(this: v8, keyName: "dirHandle", value: (unsigned __int16)hPath);
  v10 = this->AddItem(this, a2: v8, a3: nParentItemIndex);
  KeyValues::deleteThis(this: v8);
  SetItemFgColor = this->SetItemFgColor;
  hPath = -16727840;
  SetItemFgColor(this, a2: v10, a3: (const Color *)&hPath);
}

//------------------------------------------------------------------------------
// Address: 0x10207C90
// Name: public: virtual void CAssetTreeView::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::GenerateChildrenOfNode(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v3; // esi
  int Int; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // eax
  unsigned __int16 i; // cx
  unsigned int v7; // ebx
  const char *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // eax
  char pDest[260]; // [esp+8h] [ebp-114h] BYREF
  const char *pFullParentPath; // [esp+10Ch] [ebp-10h]
  int value; // [esp+110h] [ebp-Ch]
  const char *m_FirstChild; // [esp+114h] [ebp-8h]
  int v16; // [esp+118h] [ebp-4h] BYREF

  v3 = this->GetItemData(this, a2: nItemIndex);
  pFullParentPath = KeyValues::GetString(this: v3, keyName: "path", defaultValue: nullptr);
  if ( pFullParentPath != nullptr )
  {
    Int = (unsigned __int16)KeyValues::GetInt(this: v3, keyName: "dirHandle", defaultValue: 0xFFFF);
    if ( (_WORD)Int != 0xFFFF )
    {
      m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      for ( i = m_pMemory[Int].m_FirstChild; i != 0xFFFF; i = m_pMemory[v7].m_NextSibling )
      {
        value = i;
        v7 = i;
        v8 = CUtlString::Get(this: &m_pMemory[v7].m_Element);
        m_FirstChild = v8;
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "text", firstValue: v8);
        else
          v10 = nullptr;
        V_snprintf(pDest, maxLen: 260, pFormat: "%s/%s", pFullParentPath, m_FirstChild);
        V_FixSlashes(pname: pDest, separator: 92);
        _V_strlower(start: pDest);
        m_FirstChild = (const char *)this->m_DirectoryStructure.m_Memory.m_pMemory[v7].m_FirstChild;
        KeyValues::SetString(this: v10, keyName: "path", value: pDest);
        KeyValues::SetInt(this: v10, keyName: "expand", value: (_WORD)m_FirstChild != 0xFFFF);
        KeyValues::SetInt(this: v10, keyName: "image", value: 0);
        KeyValues::SetInt(this: v10, keyName: "dirHandle", value);
        value = this->AddItem(this, a2: v10, a3: nItemIndex);
        KeyValues::deleteThis(this: v10);
        SetItemFgColor = this->SetItemFgColor;
        v16 = -16727840;
        SetItemFgColor(this, a2: value, a3: (const Color *)&v16);
        m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207E40
// Name: private: unsigned short CAssetTreeView::RefreshTreeViewItem(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::RefreshTreeViewItem(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v4; // edi
  const char *String; // eax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  bool v7; // zf
  BOOL v8; // ebx
  bool (__thiscall *ModifyItem)(vgui::TreeView *, int, KeyValues *); // edx
  int v10; // edi
  int v11; // ebx
  void *v12; // esp
  int i; // edi
  int v14; // eax
  unsigned __int16 refreshed; // ax
  int m_NextSibling; // edi
  unsigned __int16 *v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // dx
  KeyValues *v20; // [esp-4h] [ebp-20h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-1Ch] BYREF
  const char *pFullParentPath; // [esp+Ch] [ebp-10h]
  int hPath; // [esp+10h] [ebp-Ch]
  unsigned __int16 *pFoundHandles; // [esp+14h] [ebp-8h]
  int v25; // [esp+18h] [ebp-4h]

  if ( nItemIndex < 0 )
    return -1;
  v4 = this->GetItemData(this, a2: nItemIndex);
  hPath = (unsigned __int16)KeyValues::GetInt(this: v4, keyName: "dirHandle", defaultValue: 0xFFFF);
  String = KeyValues::GetString(this: v4, keyName: "path", defaultValue: nullptr);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  pFullParentPath = String;
  v7 = m_pMemory[hPath].m_FirstChild == 0xFFFF;
  v25 = 24 * hPath;
  v8 = !v7;
  if ( v8 == (KeyValues::GetInt(this: v4, keyName: "expand", defaultValue: 0) != 0) )
  {
    v10 = nItemIndex;
  }
  else
  {
    KeyValues::SetInt(this: v4, keyName: "expand", value: v8);
    ModifyItem = this->ModifyItem;
    v20 = v4;
    v10 = nItemIndex;
    ModifyItem(this, a2: nItemIndex, a3: v20);
  }
  if ( this->IsItemExpanded(this, a2: v10) )
  {
    v11 = this->GetNumChildren(this, a2: v10);
    v12 = alloca(2 * v11);
    pFoundHandles = (unsigned __int16 *)v21;
    memset(dst: v21, value: 0xFFu, count: 2 * v11);
    for ( i = 0; i < v11; ++i )
    {
      v14 = this->GetChild(this, a2: nItemIndex, a3: i);
      refreshed = CAssetTreeView::RefreshTreeViewItem(this, nItemIndex: v14);
      pFoundHandles[i] = refreshed;
    }
    m_NextSibling = *(unsigned __int16 *)((char *)&this->m_DirectoryStructure.m_Memory.m_pMemory->m_FirstChild + v25);
    if ( (_WORD)m_NextSibling != 0xFFFF )
    {
      v17 = pFoundHandles;
      v25 = (int)&pFoundHandles[v11 - 1];
      do
      {
        v18 = 0;
        if ( v11 <= 0 )
        {
LABEL_14:
          CAssetTreeView::AddDirectoryToTreeView(
            this,
            nParentItemIndex: nItemIndex,
            pFullParentPath,
            hPath: m_NextSibling);
          v17 = pFoundHandles;
        }
        else
        {
          while ( v17[v18] != (_WORD)m_NextSibling )
          {
            if ( ++v18 >= v11 )
              goto LABEL_14;
          }
          v19 = *(_WORD *)v25;
          --v11;
          v25 -= 2;
          v17[v18] = v19;
        }
        m_NextSibling = this->m_DirectoryStructure.m_Memory.m_pMemory[(unsigned __int16)m_NextSibling].m_NextSibling;
      }
      while ( (_WORD)m_NextSibling != 0xFFFF );
    }
  }
  return hPath;
}

//------------------------------------------------------------------------------
// Address: 0x10207FF0
// Name: private: bool CAssetTreeView::SelectFolder_R(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetTreeView::SelectFolder_R(CAssetTreeView *this, int nItemID, const char *pPath)
{
  KeyValues *v6; // eax
  const char *String; // ebx
  const char *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // [esp-8h] [ebp-20h]
  CUtlString str; // [esp+8h] [ebp-10h] BYREF
  int nChildCount; // [esp+20h] [ebp+8h]

  if ( nItemID < 0 )
    return 0;
  v6 = this->GetItemData(this, a2: nItemID);
  String = KeyValues::GetString(this: v6, keyName: "path", defaultValue: &var);
  if ( _V_stricmp(s1: String, s2: pPath) != 0 )
  {
    CUtlString::CUtlString(this: &str, pString: String);
    CUtlString::operator+=(this: &str, c: 92);
    v11 = CUtlString::Length(this: &str);
    v8 = CUtlString::operator char const *(this: &str);
    if ( V_strnicmp(s1: v8, s2: pPath, n: v11) != 0 )
    {
      CUtlString::~CUtlString(this: &str);
      return 0;
    }
    else
    {
      this->ExpandItem(this, a2: nItemID, a3: true);
      v9 = 0;
      nChildCount = this->GetNumChildren(this, a2: nItemID);
      if ( nChildCount <= 0 )
      {
LABEL_10:
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 0;
      }
      else
      {
        while ( 1 )
        {
          v10 = this->GetChild(this, a2: nItemID, a3: v9);
          if ( CAssetTreeView::SelectFolder_R(this, nItemID: v10, pPath) )
            break;
          if ( ++v9 >= nChildCount )
            goto LABEL_10;
        }
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 1;
      }
    }
  }
  else
  {
    this->AddSelectedItem(this, a2: nItemID, a3: true, a4: false, a5: true);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208150
// Name: public: virtual void CBaseAssetPicker::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::GetUserConfigSettings(CBaseAssetPicker *this, KeyValues *pUserConfig)
{
  const char *v3; // eax
  const char *v4; // eax
  int m_nCurrentModFilter; // eax
  char v6; // bl
  CUtlString *v7; // eax
  const char *v8; // eax
  CUtlString v9; // [esp+Ch] [ebp-24h] BYREF
  CUtlString v10; // [esp+1Ch] [ebp-14h] BYREF
  int v11; // [esp+2Ch] [ebp-4h]

  v11 = 0;
  vgui::EditablePanel::GetUserConfigSettings(this, userConfig: pUserConfig);
  v3 = CUtlString::operator char const *(this: &this->m_Filter);
  KeyValues::SetString(this: pUserConfig, keyName: "filter", value: v3);
  v4 = CUtlString::operator char const *(this: &this->m_FolderFilter);
  KeyValues::SetString(this: pUserConfig, keyName: "folderfilter", value: v4);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  if ( m_nCurrentModFilter < 0 )
  {
    v6 = 2;
    v7 = CUtlString::CUtlString(this: &v10, pString: &var);
  }
  else
  {
    v6 = 1;
    v7 = CUtlString::CUtlString(
           this: &v9,
           string: &s_AssetCache.m_ModList.m_Memory.m_pMemory[m_nCurrentModFilter].m_ModName);
  }
  v8 = CUtlString::operator char const *(this: v7);
  KeyValues::SetString(this: pUserConfig, keyName: "mod", value: v8);
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    v10.m_Storage.m_nActualLength = 0;
    if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
        v10.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v10.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
  }
  if ( (v6 & 1) != 0 )
  {
    v9.m_Storage.m_nActualLength = 0;
    if ( v9.m_Storage.m_Memory.m_nGrowSize >= 0 && v9.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208240
// Name: public: virtual struct CachedAssetInfo_t const __near & CBaseAssetPicker::GetCachedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const CachedAssetInfo_t *__thiscall CBaseAssetPicker::GetCachedAsset(CBaseAssetPicker *this, int nAssetIndex)
{
  return &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[nAssetIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10208270
// Name: public: virtual int CBaseAssetPicker::GetCachedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetCachedAssetCount(CBaseAssetPicker *this)
{
  AssetList_t__ *m_hAssetList; // eax

  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    return 0;
  else
    return s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102082A0
// Name: protected: void CBaseAssetPicker::RescanAssets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::RescanAssets(CBaseAssetPicker *this)
{
  char v2; // al
  vgui::IVGui *v3; // ebx
  vgui::IVGui_vtbl *v4; // edi
  int v5; // eax

  this->m_pAssetBrowser->RemoveAll(this: this->m_pAssetBrowser);
  this->m_AssetList.m_Size = 0;
  this->BeginCacheAssets(this, a2: true);
  *((_BYTE *)this + 544) |= 2u;
  v2 = *((_BYTE *)this + 544);
  this->m_nMatchingAssets = 0;
  if ( (v2 & 4) != 0 )
  {
    *((_BYTE *)this + 544) = v2 & 0xFB;
    v3 = g_pVGui;
    v4 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v4->AddTickSignal)(a1: v3, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208310
// Name: public: virtual void CBaseAssetPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnCommand(CBaseAssetPicker *this, const char *pCommand)
{
  const char *v2; // esi
  KeyValues *v4; // eax
  int v5; // esi
  void *v6; // esp
  KeyValues *v7; // esi
  char v8[12]; // [esp+0h] [ebp-10h] BYREF
  KeyValues *pKeyValues; // [esp+Ch] [ebp-4h]

  v2 = pCommand;
  if ( _V_stricmp(s1: pCommand, s2: "AssetRescan") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "FindAsset") == 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        pKeyValues = KeyValues::KeyValues(this: v4, setName: "AssetPickerFind");
      else
        pKeyValues = nullptr;
      v5 = this->m_pFullPath->GetTextLength(this: this->m_pFullPath);
      v6 = alloca(v5 + 1);
      if ( v5 <= 0 )
        v8[0] = 0;
      else
        this->m_pFullPath->GetText_2(this: this->m_pFullPath, a2: v8, a3: v5 + 1);
      v7 = pKeyValues;
      KeyValues::SetString(this: pKeyValues, keyName: "asset", value: v8);
      this->PostActionSignal(this, a2: v7);
      v2 = pCommand;
    }
    vgui::Panel::OnCommand(this, command: v2);
  }
  else
  {
    CBaseAssetPicker::RescanAssets(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102083F0
// Name: public: virtual class CUtlString CBaseAssetPicker::GetSelectedAssetFullPath(int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CBaseAssetPicker::GetSelectedAssetFullPath(
        CBaseAssetPicker *this,
        CUtlString *result,
        int nIndex)
{
  const char *SelectedAsset; // edi
  int Int; // eax
  int v6; // eax
  KeyValues *v7; // eax
  const char *v8; // eax
  const char *m_pAssetSubDir; // [esp-8h] [ebp-114h]
  char pBuf[260]; // [esp+8h] [ebp-104h] BYREF

  SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: nIndex - 1);
  Int = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  if ( Int != 0 )
  {
    v6 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: 0);
    v7 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v6);
    Int = KeyValues::GetInt(this: v7, keyName: "modIndex", defaultValue: 0);
  }
  m_pAssetSubDir = this->m_pAssetSubDir;
  v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[Int].m_Path);
  V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "%s\\%s\\%s", v8, m_pAssetSubDir, SelectedAsset);
  V_FixSlashes(pname: pBuf, separator: 92);
  CUtlString::CUtlString(this: result, pString: pBuf);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102084B0
// Name: protected: virtual void CBaseAssetPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemSelected(CBaseAssetPicker *this, KeyValues *kv)
{
  int v3; // edi
  vgui::TextEntry_vtbl *v4; // ebx
  CUtlString *v5; // eax
  const char *v6; // eax
  _DWORD v7[4]; // [esp+4h] [ebp-10h] BYREF
  const char *pSelectedAsset; // [esp+1Ch] [ebp+8h]

  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
  {
    v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) - 1;
    pSelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: v3);
    v4 = this->m_pFullPath->__vftable;
    v5 = this->GetSelectedAssetFullPath(this, result: v7, a3: v3);
    v6 = CUtlString::operator char const *(this: v5);
    v4->SetText(this: this->m_pFullPath, a2: v6);
    v7[3] = 0;
    if ( v7[2] >= 0 && v7[0] != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v7[0]);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
    this->OnSelectedAssetPicked(this, a2: pSelectedAsset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208580
// Name: public: virtual char const __near * CBaseAssetPicker::GetAssetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetAssetName(CBaseAssetPicker *this, int nAssetIndex)
{
  return CUtlString::operator char const *(this: &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[this->m_AssetList.m_Memory.m_pMemory[nAssetIndex].m_nAssetIndex].m_AssetName);
}

//------------------------------------------------------------------------------
// Address: 0x10209150
// Name: public: unsigned short CAssetTreeView::AddSubDirectory(unsigned short,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::AddSubDirectory(
        CAssetTreeView *this,
        unsigned __int16 hParent,
        const char *pDirName)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v4; // bx
  int v5; // edi
  CUtlString *p_m_Element; // ecx
  char *v7; // eax

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  v4 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  v5 = v4;
  p_m_Element = &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element;
  if ( p_m_Element != nullptr )
    CUtlString::CUtlString(this: p_m_Element);
  CUtlString::operator=(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element, src: pDirName);
  v7 = CUtlString::Get(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element);
  _V_strlower(start: v7);
  CUtlNTree<CUtlString,unsigned short>::LinkChildBefore(
    this: p_m_DirectoryStructure,
    parent: hParent,
    before: p_m_DirectoryStructure->m_Memory.m_pMemory[hParent].m_FirstChild,
    elem: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x102092D0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x10209360
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x102093F0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x10209480
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x10209510
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x102095A0
// Name: protected: void CBaseAssetPicker::AddExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AddExtension(CBaseAssetPicker *this, CCullTreeNode *pExtension)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_ExtraAssetExt; // esi
  int m_Size; // edi
  CCullTreeNode **m_pMemory; // ecx
  int v6; // eax
  CCullTreeNode **v7; // eax

  m_nAllocationCount = this->m_ExtraAssetExt.m_Memory.m_nAllocationCount;
  p_m_ExtraAssetExt = (CUtlMemory<CCullTreeNode *,int> *)&this->m_ExtraAssetExt;
  m_Size = this->m_ExtraAssetExt.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_ExtraAssetExt, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ExtraAssetExt[1].m_pMemory;
  m_pMemory = p_m_ExtraAssetExt->m_pMemory;
  v6 = (int)p_m_ExtraAssetExt[1].m_pMemory - m_Size - 1;
  p_m_ExtraAssetExt[1].m_nAllocationCount = (int)p_m_ExtraAssetExt->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_ExtraAssetExt->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pExtension;
}

//------------------------------------------------------------------------------
// Address: 0x10209610
// Name: protected: void CBaseAssetPicker::AddAssetToList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AddAssetToList(CBaseAssetPicker *this, int nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ebx
  char *v4; // eax
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  KeyValues *m_pInsertHelper; // esi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int v12; // esi
  const char *v13; // eax
  const char *v14; // eax
  KeyValues *v15; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBaseAssetPicker::AssetInfo_t *m_pMemory; // ecx
  int v19; // eax
  const char *v20; // [esp-4h] [ebp-1Ch]
  KeyValues *v21; // [esp+10h] [ebp-8h]
  bool bInRootDir; // [esp+17h] [ebp-1h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  v4 = (char *)CUtlString::operator char const *(this: &v3->m_AssetName);
  strchr(string: v4, chr: 0x5Cu);
  if ( v5 != 0
    || (v6 = (char *)CUtlString::operator char const *(this: &v3->m_AssetName),
        strchr(string: v6, chr: 0x2Fu),
        bInRootDir = true,
        v7 != 0) )
  {
    bInRootDir = false;
  }
  m_pInsertHelper = this->m_pInsertHelper;
  v9 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetName(this: m_pInsertHelper, setName: v9);
  v10 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "asset", value: v10);
  v11 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v3->m_nModIndex].m_ModName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "mod", value: v11);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "modIndex", value: v3->m_nModIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "root", value: bInRootDir);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "assetIndex", value: nAssetIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "timesused", value: v3->m_nTimesUsed);
  v12 = this->m_pAssetBrowser->AddItem(this: this->m_pAssetBrowser, a2: m_pInsertHelper, a3: 0, a4: false, a5: false);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0 )
  {
    v20 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v13 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
    if ( _V_strcmp(s1: v13, s2: v20) == 0 )
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v12, a3: 0);
  }
  v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v21 != nullptr )
  {
    v14 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v15 = KeyValues::KeyValues(this: v21, setName: "drag", firstKey: "text", firstValue: v14);
  }
  else
  {
    v15 = nullptr;
  }
  if ( this->m_pAssetTextType != nullptr )
    KeyValues::SetString(this: v15, keyName: "texttype", value: this->m_pAssetTextType);
  vgui::ListPanel::SetItemDragData(this: this->m_pAssetBrowser, itemID: v12, data: v15);
  m_Size = this->m_AssetList.m_Size;
  m_nAllocationCount = this->m_AssetList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_AssetList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_AssetList.m_Size;
  m_pMemory = this->m_AssetList.m_Memory.m_pMemory;
  v19 = this->m_AssetList.m_Size - m_Size - 1;
  this->m_AssetList.m_pElements = m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v19);
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nAssetIndex = nAssetIndex;
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nItemId = v12;
  LOBYTE(nAssetIndex) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)m_Size);
  this->m_pAssetBrowser->SetItemVisible(this: this->m_pAssetBrowser, a2: v12, a3: nAssetIndex);
  if ( (_BYTE)nAssetIndex != 0 )
    ++this->m_nMatchingAssets;
}

//------------------------------------------------------------------------------
// Address: 0x102099C0
// Name: public: void CAssetTreeView::ClearDirectories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ClearDirectories(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v3; // ax
  int v4; // edi
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  unsigned __int16 v6; // [esp+Ch] [ebp-4h]

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  v3 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: p_m_DirectoryStructure);
  v4 = v3;
  v6 = v3;
  if ( &p_m_DirectoryStructure->m_Memory.m_pMemory[v4] != nullptr )
  {
    CUtlString::CUtlString(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v4].m_Element);
    v3 = v6;
  }
  m_pMemory = p_m_DirectoryStructure->m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v3;
  CUtlString::operator=(this: &m_pMemory[v4].m_Element, src: &this->m_RootDirectory);
}

//------------------------------------------------------------------------------
// Address: 0x10209C30
// Name: public: CAssetTreeView::CAssetTreeView(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetTreeView *__thiscall CAssetTreeView::CAssetTreeView(
        CAssetTreeView *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pRootFolderName,
        const char *pRootDir)
{
  vgui::PanelMessageMap *v6; // esi
  PanelAnimationMap *v7; // esi
  vgui::PanelKeyBindingMap *v8; // esi
  unsigned __int16 v9; // ax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  int v11; // ebx
  bool v12; // zf
  CUtlString *p_m_Element; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *v14; // ecx
  vgui::IImage *v15; // eax
  unsigned __int16 pNamea; // [esp+18h] [ebp+Ch]

  vgui::TreeView::TreeView(this, parent: pParent, panelName: pName);
  this->__vftable = (CAssetTreeView_vtbl *)&CAssetTreeView::`vftable';
  if ( `CAssetTreeView::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
    v6->pfnClassName = CAssetTreeView::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CAssetTreeView");
    v7->pfnClassName = CAssetTreeView::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
    v8->pfnClassName = CAssetTreeView::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TreeView");
  }
  CUtlString::CUtlString(this: &this->m_RootFolderName);
  CUtlString::CUtlString(this: &this->m_RootDirectory);
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
  this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoryStructure.m_Memory.m_nGrowSize = 0;
  *(_DWORD *)&this->m_DirectoryStructure.m_Root = -1;
  *(_DWORD *)&this->m_DirectoryStructure.m_ElementCount = 0;
  this->m_DirectoryStructure.m_pElements = nullptr;
  vgui::TreeView::SetSortFunc(this, pSortFunc: AssetTreeViewSortFunc);
  CUtlString::operator=(this: &this->m_RootFolderName, src: pRootFolderName);
  CUtlString::operator=(this: &this->m_RootDirectory, src: pRootDir);
  v9 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  v11 = v9;
  v12 = &m_pMemory[v11] == nullptr;
  p_m_Element = &m_pMemory[v11].m_Element;
  pNamea = v9;
  if ( !v12 )
  {
    CUtlString::CUtlString(this: p_m_Element);
    v9 = pNamea;
  }
  v14 = this->m_DirectoryStructure.m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v9;
  CUtlString::operator=(this: &v14[v11].m_Element, src: &this->m_RootDirectory);
  v15 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "resource/icon_folder", a3: 0);
  vgui::ImageList::AddImage(this: &this->m_Images, image: v15);
  vgui::TreeView::SetImageList(this, imageList: &this->m_Images, deleteImageListWhenDone: false);
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209DE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetTreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetTreeView::GetMessageMap(CAssetTreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetTreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetMessageMap'::`2'::s_pMap;
  `CAssetTreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
  `CAssetTreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10209E10
// Name: public: virtual struct PanelAnimationMap __near * CAssetTreeView::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetTreeView::GetAnimMap(CAssetTreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetTreeView");
}

//------------------------------------------------------------------------------
// Address: 0x10209E20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetTreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetTreeView::GetKBMap(CAssetTreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetTreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetKBMap'::`2'::s_pMap;
  `CAssetTreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
  `CAssetTreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10209E50
// Name: public: virtual CAssetTreeView::~CAssetTreeView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::~CAssetTreeView(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  if ( this->m_DirectoryStructure.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoryStructure.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoryStructure.m_Memory.m_pMemory);
      this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  }
  vgui::ImageList::~ImageList(this: &this->m_Images);
  this->m_RootDirectory.m_Storage.m_nActualLength = 0;
  if ( this->m_RootDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootDirectory.m_Storage.m_Memory.m_pMemory);
      this->m_RootDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RootFolderName.m_Storage.m_nActualLength = 0;
  if ( this->m_RootFolderName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootFolderName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootFolderName.m_Storage.m_Memory.m_pMemory);
      this->m_RootFolderName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootFolderName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::TreeView::~TreeView(this);
}

//------------------------------------------------------------------------------
// Address: 0x10209F10
// Name: public: void CAssetCache::BuildModList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::BuildModList(CAssetCache *this, const char *pSearchPathName)
{
  int v3; // edi
  void *v4; // esp
  char *v5; // ebx
  char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CacheModInfo_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // edi
  _BYTE v12[12]; // [esp+0h] [ebp-114h] BYREF
  char pModName[260]; // [esp+Ch] [ebp-108h] BYREF
  char *pSemiColon; // [esp+110h] [ebp-4h]
  CacheModInfo_t *pSearchPathNamea; // [esp+11Ch] [ebp+8h]

  if ( !this->m_bBuiltModList )
  {
    this->m_pAssetSearchPath = pSearchPathName;
    this->m_bBuiltModList = true;
    CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::RemoveAll(this: &this->m_ModList);
    v3 = g_pFullFileSystem->GetSearchPath(
           this: g_pFullFileSystem,
           a2: this->m_pAssetSearchPath,
           a3: false,
           a4: nullptr,
           a5: 0);
    v4 = alloca(v3);
    v5 = v12;
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: this->m_pAssetSearchPath, a3: false, a4: v12, a5: v3);
    if ( v12 != nullptr )
    {
      do
      {
        strchr(string: v5, chr: 0x3Bu);
        pSemiColon = v6;
        if ( v6 != nullptr )
          *v6 = 0;
        V_StripTrailingSlash(ppath: v5);
        V_FixSlashes(pname: v5, separator: 92);
        V_FileBase(in: v5, out: pModName, maxlen: 260);
        m_Size = this->m_ModList.m_Size;
        m_nAllocationCount = this->m_ModList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
            (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_ModList.m_Size;
        m_pMemory = this->m_ModList.m_Memory.m_pMemory;
        v10 = this->m_ModList.m_Size - m_Size - 1;
        this->m_ModList.m_pElements = this->m_ModList.m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v10);
        v11 = m_Size;
        pSearchPathNamea = &this->m_ModList.m_Memory.m_pMemory[v11];
        if ( pSearchPathNamea != nullptr )
        {
          CUtlString::CUtlString(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName);
          CUtlString::CUtlString(this: &pSearchPathNamea->m_Path);
        }
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName, pValue: pModName);
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_Path, pValue: v5);
        if ( pSemiColon == nullptr )
          break;
        v5 = pSemiColon + 1;
      }
      while ( pSemiColon != (char *)-1 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A050
// Name: private: bool CAssetCache::AddFilesInDirectory(struct CAssetCache::CachedAssetList_t __near &,char const __near *,char const __near *,unsigned short,float,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAssetCache::AddFilesInDirectory@<al>(
        CAssetCache *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *list,
        char *pStartingFile,
        const char *pFilePath,
        unsigned __int16 hCurrentDir,
        float flStartTime,
        float flDuration)
{
  bool v9; // zf
  CAssetCache *v10; // ebx
  const char *v12; // eax
  char *v13; // edi
  int v14; // eax
  const char *v15; // eax
  int v16; // edi
  int v17; // edi
  CacheModInfo_t *v18; // ebx
  const char *v19; // eax
  char *v20; // edi
  const char *v21; // eax
  int AssetUsageCount; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CachedAssetInfo_t *v25; // ecx
  int v26; // eax
  CachedAssetInfo_t *v27; // ecx
  CachedAssetInfo_t *v28; // edi
  int v29; // eax
  int v30; // [esp-8h] [ebp-228h]
  int v31; // [esp-8h] [ebp-228h]
  int v32; // [esp-4h] [ebp-224h]
  int v33; // [esp+0h] [ebp-220h]
  int v34; // [esp+4h] [ebp-21Ch]
  char pFullAssetPath[260]; // [esp+8h] [ebp-218h] BYREF
  char pRelativeChildPath[260]; // [esp+10Ch] [ebp-114h] BYREF
  int nTimesUsed; // [esp+210h] [ebp-10h]
  int nModCount; // [esp+214h] [ebp-Ch]
  CAssetCache *v39; // [esp+218h] [ebp-8h]
  int nSubDirLen; // [esp+21Ch] [ebp-4h]
  unsigned __int16 ia; // [esp+228h] [ebp+8h]
  int i; // [esp+228h] [ebp+8h]
  const char *pAssetName; // [esp+22Ch] [ebp+Ch]

  v9 = list[7].m_nAllocationCount == -1;
  v10 = this;
  v39 = this;
  if ( v9 )
    return 1;
  v32 = a2;
  nModCount = this->m_ModList.m_Size;
  if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
  {
    v12 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
    nSubDirLen = std::char_traits<char>::length(str: v12);
  }
  else
  {
    nSubDirLen = 0;
  }
  v13 = pStartingFile;
  if ( pStartingFile == nullptr )
    return 1;
  while ( 1 )
  {
    V_snprintf(pDest: pRelativeChildPath, maxLen: 260, pFormat: "%s\\%s", pFilePath, v13);
    if ( !g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount) )
      break;
    strstr(str1: (unsigned __int8 *)v13, str2: ".svn");
    if ( v14 == 0 )
    {
      if ( V_strnicmp(s1: v13, s2: ".", n: 2) != 0 && V_strnicmp(s1: v13, s2: "..", n: 3) != 0 )
      {
        ia = CAssetTreeView::AddSubDirectory(
               this: (CAssetTreeView *)list[1].m_nGrowSize,
               hParent: hCurrentDir,
               pDirName: v13);
        v16 = (unsigned __int16)CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(this: (CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *)&list[5]);
        CUtlString::operator=(this: (CUtlString *)&list[5].m_pMemory[v16], src: pRelativeChildPath);
        LOWORD(list[5].m_pMemory[v16].m_Data.key) = ia;
      }
      goto LABEL_30;
    }
    v15 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
LABEL_32:
    v13 = (char *)v15;
    if ( v15 == nullptr )
      return 1;
  }
  if ( CAssetCache::DoesExtensionMatch(this: v10, info: (CAssetCache::CachedAssetList_t *)list, pFileName: v13) != 0 )
  {
    v17 = 0;
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: pRelativeChildPath,
      a3: v10->m_pAssetSearchPath,
      a4: pFullAssetPath,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    i = 0;
    if ( nModCount > 0 )
    {
      while ( 1 )
      {
        v18 = &v39->m_ModList.m_Memory.m_pMemory[v17];
        v30 = CUtlString::Length(this: &v18->m_Path);
        v19 = CUtlString::operator char const *(this: &v18->m_Path);
        if ( V_strnicmp(s1: pFullAssetPath, s2: v19, n: v30) == 0 )
          break;
        ++v17;
        if ( ++i >= nModCount )
          goto LABEL_30;
      }
      if ( i >= 0 )
      {
        v20 = pRelativeChildPath;
        pAssetName = pRelativeChildPath;
        if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
        {
          v31 = nSubDirLen;
          v21 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
          if ( V_strnicmp(s1: v21, s2: pRelativeChildPath, n: v31) == 0 && pRelativeChildPath[nSubDirLen] == 92 )
          {
            pAssetName = &pRelativeChildPath[nSubDirLen + 1];
            v20 = &pRelativeChildPath[nSubDirLen + 1];
          }
        }
        strlwr(string: v20);
        AssetUsageCount = CAssetCache::GetAssetUsageCount(this: v39, assetName: v20);
        m_pMemory = (int)list[1].m_pMemory;
        nTimesUsed = AssetUsageCount;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
            this: list,
            num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v25 = (CachedAssetInfo_t *)list->m_pMemory;
        v26 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v26 > 0 )
          _V_memmove(dest: (void *)&v25[m_pMemory + 1], src: &v25[m_pMemory], count: 24 * v26);
        v27 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        if ( v27 != nullptr )
          CUtlString::CUtlString(this: &v27->m_AssetName);
        v28 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        CUtlString::Set(this: &v28->m_AssetName, pValue: pAssetName);
        v29 = nTimesUsed;
        v28->m_nModIndex = i;
        v28->m_nTimesUsed = v29;
      }
    }
  }
LABEL_30:
  if ( _Plat_FloatTime(a1: v32, a2: v33, a3: v34, a4: *(_DWORD *)pFullAssetPath, a5: *(_DWORD *)&pFullAssetPath[4])
     - flStartTime < flDuration )
  {
    v15 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
    v10 = v39;
    goto LABEL_32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020A340
// Name: public: bool CAssetCache::BeginAssetScan(struct AssetList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::BeginAssetScan(CAssetCache *this, AssetList_t__ *hList, bool bForceRescan)
{
  int v3; // eax
  CAssetCache::CachedAssetList_t *p_m_Data; // esi
  int m_hFind; // eax
  unsigned __int16 v7; // ax
  int v8; // ebx
  unsigned __int16 v9; // ax
  CUtlString *p_m_DirName; // ecx
  int v11; // ebx

  v3 = (unsigned __int16)hList;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data;
  if ( bForceRescan )
  {
    m_hFind = this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data.m_hFind;
    p_m_Data->m_bAssetScanComplete = false;
    if ( m_hFind != -1 )
    {
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: m_hFind);
      p_m_Data->m_hFind = -1;
    }
    CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_Data->m_DirectoriesToCheck);
  }
  if ( p_m_Data->m_bAssetScanComplete )
    return 1;
  if ( p_m_Data->m_hFind == -1 )
  {
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int> > *)p_m_Data);
    CAssetTreeView::ClearDirectories(this: p_m_Data->m_pFileTree);
    v7 = CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &p_m_Data->m_DirectoriesToCheck,
           multilist: false);
    v8 = v7;
    if ( v7 == 0xFFFF )
    {
      v9 = -1;
    }
    else
    {
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &p_m_Data->m_DirectoriesToCheck,
        before: 0xFFFFu,
        elem: v7);
      p_m_DirName = &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v8].m_Element.m_DirName;
      if ( p_m_DirName != nullptr )
        CUtlString::CUtlString(this: p_m_DirName);
      v9 = v8;
    }
    v11 = v9;
    CUtlString::operator=(
      this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_DirName,
      src: &p_m_Data->m_pSubDir);
    p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_hDirHandle = p_m_Data->m_pFileTree->m_DirectoryStructure.m_Root;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020A420
// Name: public: void CAssetCache::SetUsedAssetList(class CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::SetUsedAssetList(
        CAssetCache *this,
        CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *usedAssets)
{
  int v3; // ebx
  int v4; // ecx
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *v5; // eax
  int m_Size; // eax
  int v7; // edi
  int v8; // ebx
  char *v9; // eax
  int m_nTimesUsed; // eax
  char *pSearch; // [esp+8h] [ebp-10h]
  int v12; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int cache; // [esp+20h] [ebp+8h]

  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::RemoveAll(this: &this->m_usedAssets);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::AddVectorToTail(
    this: &this->m_usedAssets,
    src: usedAssets);
  for ( cache = (unsigned __int16)CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_CachedAssets);
        cache != 0xFFFF;
        cache = (unsigned __int16)CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &this->m_CachedAssets,
                                    i: cache) )
  {
    v3 = (unsigned __int16)cache;
    v4 = 0;
    v5 = &this->m_CachedAssets.m_Elements.m_pMemory[v3];
    i = 0;
    if ( v5->m_Data.m_AssetList.m_Size > 0 )
    {
      v12 = 0;
      do
      {
        pSearch = CUtlString::Get(this: (CUtlString *)((char *)&v5->m_Data.m_AssetList.m_Memory.m_pMemory->m_AssetName
                                                     + v4));
        m_Size = this->m_usedAssets.m_Size;
        if ( m_Size != 0 && (v7 = 0, m_Size > 0) )
        {
          v8 = 0;
          while ( 1 )
          {
            v9 = CUtlString::Get(this: &this->m_usedAssets.m_Memory.m_pMemory[v8].m_assetName);
            if ( V_stristr(pStr: v9, pSearch) != nullptr )
              break;
            ++v7;
            ++v8;
            if ( v7 >= this->m_usedAssets.m_Size )
            {
              v3 = (unsigned __int16)cache;
              goto LABEL_10;
            }
          }
          v3 = (unsigned __int16)cache;
          m_nTimesUsed = this->m_usedAssets.m_Memory.m_pMemory[v7].m_nTimesUsed;
        }
        else
        {
LABEL_10:
          m_nTimesUsed = 0;
        }
        this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data.m_AssetList.m_Memory.m_pMemory[v12].m_nTimesUsed = m_nTimesUsed;
        v4 = v12 * 24 + 24;
        v5 = &this->m_CachedAssets.m_Elements.m_pMemory[v3];
        ++i;
        ++v12;
      }
      while ( i < v5->m_Data.m_AssetList.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A530
// Name: public: void CBaseAssetPicker::SetUsedAssetList(class CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::SetUsedAssetList(
        CBaseAssetPicker *this,
        CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *usedAssets)
{
  CAssetCache::SetUsedAssetList(this: &s_AssetCache, usedAssets);
  LOBYTE(usedAssets) = usedAssets->m_Size > 0;
  this->m_pOnlyUsedCheck->SetEnabled(this: this->m_pOnlyUsedCheck, a2: (bool)usedAssets);
  if ( (_BYTE)usedAssets == 0 )
  {
    this->m_pOnlyUsedCheck->SetSelected(this: this->m_pOnlyUsedCheck, a2: false);
    *((_BYTE *)this + 544) &= ~0x10u;
  }
  this->m_pFindAssetButton->SetEnabled(this: this->m_pFindAssetButton, a2: (bool)usedAssets);
}

//------------------------------------------------------------------------------
// Address: 0x1020A5A0
// Name: public: virtual bool CBaseAssetPicker::BeginCacheAssets(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAssetPicker::BeginCacheAssets(CBaseAssetPicker *this, bool bForceRecache)
{
  return CAssetCache::BeginAssetScan(this: &s_AssetCache, hList: this->m_hAssetList, bForceRescan: bForceRecache);
}

//------------------------------------------------------------------------------
// Address: 0x1020A5C0
// Name: protected: void CBaseAssetPicker::BuildAssetNameList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::BuildAssetNameList(CBaseAssetPicker *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  int v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int v7; // edi
  KeyValues *v8; // eax
  const KeyValues *v9; // eax
  bool v10; // zf
  char v11; // al
  CBaseAssetPicker_vtbl *v12; // edx
  vgui::IVGui *v13; // ebx
  vgui::IVGui_vtbl *v14; // edi
  int v15; // eax
  int v16; // ebx
  int i; // edi
  const char *m_pAssetSearchPath; // [esp-8h] [ebp-14h]
  int nModCount; // [esp+4h] [ebp-8h]
  const char *pModName; // [esp+8h] [ebp-4h]

  v3 = *((_BYTE *)this + 544);
  if ( (v3 & 1) == 0 )
  {
    *((_BYTE *)this + 544) = v3 | 1;
    v4 = 0;
    m_pAssetSearchPath = this->m_pAssetSearchPath;
    this->m_nMatchingAssets = 0;
    this->m_nCurrentModFilter = -1;
    CAssetCache::BuildModList(this: &s_AssetCache, pSearchPathName: m_pAssetSearchPath);
    vgui::ComboBox::RemoveAll(this: this->m_pModSelector);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "Mod", firstKey: "mod", firstValue: -1);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::ComboBox *, const char *, KeyValues *, int))this->m_pModSelector->AddItem_2)(
      a1: this->m_pModSelector,
      a2: "All Mods",
      a3: v6,
      a4: a2);
    v7 = 0;
    for ( nModCount = s_AssetCache.m_ModList.m_Size; v7 < nModCount; ++v4 )
    {
      pModName = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v4].m_ModName);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "Mod", firstKey: "mod", firstValue: v7);
      else
        v9 = nullptr;
      this->m_pModSelector->AddItem_2(this: this->m_pModSelector, a2: pModName, a3: v9);
      ++v7;
    }
    vgui::ComboBox::ActivateItemByRow(this: this->m_pModSelector, row: 0);
    v10 = !this->BeginCacheAssets(this, a2: false);
    v11 = *((_BYTE *)this + 544);
    if ( v10 )
    {
      v12 = this->__vftable;
      *((_BYTE *)this + 544) = v11 & 0xF9 | 2;
      v13 = g_pVGui;
      v14 = g_pVGui->__vftable;
      v15 = ((int (__thiscall *)(CBaseAssetPicker *, int))v12->GetVPanel)(a1: this, a2: 10);
      ((void (__thiscall *)(vgui::IVGui *, int))v14->AddTickSignal)(a1: v13, a2: v15);
    }
    else
    {
      *((_BYTE *)this + 544) = v11 & 0xF9 | 4;
    }
    v16 = this->GetCachedAssetCount(this);
    for ( i = 0; i < v16; ++i )
      CBaseAssetPicker::AddAssetToList(this, nAssetIndex: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A740
// Name: protected: void CBaseAssetPicker::RefreshAssetList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::RefreshAssetList(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // eax
  int v5; // edi
  const CachedAssetInfo_t *v6; // eax
  vgui::ListPanel *m_pAssetBrowser; // ecx
  vgui::ListPanelItem *(__thiscall *GetItemData)(vgui::ListPanel *, int); // edx
  int v9; // ebx
  vgui::ListPanelItem *v10; // eax
  KeyValues *kv; // ecx
  const char *v12; // eax
  int v13; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v15; // eax
  char pDest[512]; // [esp+8h] [ebp-210h] BYREF
  const CachedAssetInfo_t *info; // [esp+208h] [ebp-10h]
  int nCount; // [esp+20Ch] [ebp-Ch]
  vgui::ListPanelItem *pItem; // [esp+210h] [ebp-8h]
  int bIsVisible; // [esp+214h] [ebp-4h]

  CBaseAssetPicker::BuildAssetNameList(this, a2: a3);
  v5 = 0;
  nCount = this->m_AssetList.m_Size;
  v4 = nCount;
  this->m_nMatchingAssets = 0;
  if ( v4 > 0 )
  {
    do
    {
      LOBYTE(bIsVisible) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)v5);
      v6 = (const CachedAssetInfo_t *)((int (__thiscall *)(CBaseAssetPicker *, int, int))this->GetCachedAsset)(
                                        a1: this,
                                        a2: v5,
                                        a3: a2);
      m_pAssetBrowser = this->m_pAssetBrowser;
      GetItemData = m_pAssetBrowser->GetItemData;
      info = v6;
      v9 = v5;
      v10 = GetItemData(this: m_pAssetBrowser, a2: this->m_AssetList.m_Memory.m_pMemory[v5].m_nItemId);
      kv = v10->kv;
      pItem = v10;
      if ( KeyValues::GetInt(this: kv, keyName: "timesused", defaultValue: 0) != info->m_nTimesUsed )
      {
        KeyValues::SetInt(this: pItem->kv, keyName: "timesused", value: info->m_nTimesUsed);
        this->m_pAssetBrowser->ApplyItemChanges(
          this: this->m_pAssetBrowser,
          a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      }
      a2 = bIsVisible;
      ((void (__thiscall *)(vgui::ListPanel *, int))this->m_pAssetBrowser->SetItemVisible)(
        a1: this->m_pAssetBrowser,
        a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      if ( (_BYTE)bIsVisible != 0 )
        ++this->m_nMatchingAssets;
      ++v5;
    }
    while ( v5 < nCount );
  }
  v12 = &var;
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
    v12 = " ...";
  V_snprintf(
    pDest,
    maxLen: 512,
    pFormat: "%s (%d/%d)%s",
    this->m_pAssetType,
    this->m_nMatchingAssets,
    this->m_AssetList.m_Size,
    v12);
  this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: pDest);
  this->m_pAssetBrowser->SortList(this: this->m_pAssetBrowser);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0
    && this->m_pAssetBrowser->GetItemCount(this: this->m_pAssetBrowser) > 0 )
  {
    this->OnNextSelectionIsDefault(this);
    v13 = this->m_pAssetBrowser->GetItemIDFromRow(this: this->m_pAssetBrowser, a2: 0);
    this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v13, a3: 0);
  }
  m_pFileTree = this->m_pFileTree;
  v15 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
  CAssetTreeView::RefreshTreeViewItem(this: m_pFileTree, nItemIndex: v15);
  m_pFileTree->InvalidateLayout(this: m_pFileTree, a2: false, a3: false);
  this->OnAssetListChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020A930
// Name: protected: virtual void CBaseAssetPicker::OnFileSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::OnFileSelected(CBaseAssetPicker *this@<ecx>, int a2@<ebx>)
{
  const char *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  const char *String; // esi
  const char *v7; // eax
  signed int nLen; // [esp+Ch] [ebp-4h]

  v3 = &var;
  v4 = this->m_pFileTree->GetFirstSelectedItem(this: this->m_pFileTree);
  if ( v4 >= 0 )
  {
    v5 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: v4);
    String = KeyValues::GetString(this: v5, keyName: "path", defaultValue: &var);
    v3 = &String[std::char_traits<char>::length(str: this->m_pAssetSubDir)];
    if ( *v3 != 0 )
      ++v3;
  }
  v7 = CUtlString::Get(this: &this->m_FolderFilter);
  if ( _V_stricmp(s1: v3, s2: v7) != 0 )
  {
    nLen = std::char_traits<char>::length(str: v3);
    CUtlString::operator=(this: &this->m_FolderFilter, src: v3);
    if ( nLen > 0 )
      CUtlString::operator+=(this: &this->m_FolderFilter, c: 92);
    CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A9E0
// Name: protected: virtual void CBaseAssetPicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnTextChanged(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *pKeyValues)
{
  vgui::ComboBox *Ptr; // eax
  vgui::TextEntry *m_pFilter; // ecx
  int v7; // edi
  void *v8; // esp
  const char *v9; // eax
  vgui::ComboBox *m_pModSelector; // ecx
  KeyValues *ActiveItemUserData; // eax
  char v12[12]; // [esp+0h] [ebp-Ch] BYREF

  Ptr = (vgui::ComboBox *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  m_pFilter = this->m_pFilter;
  if ( Ptr == m_pFilter )
  {
    v7 = m_pFilter->GetTextLength(this: m_pFilter);
    v8 = alloca(v7 + 1);
    if ( v7 <= 0 )
      v12[0] = 0;
    else
      this->m_pFilter->GetText_2(this: this->m_pFilter, a2: v12, a3: v7 + 1);
    v9 = CUtlString::Get(this: &this->m_Filter);
    if ( _V_stricmp(s1: v12, s2: v9) != 0 )
    {
      CUtlString::SetLength(this: &this->m_Filter, nLen: v7);
      CUtlString::operator=(this: &this->m_Filter, src: v12);
      CBaseAssetPicker::RefreshAssetList(this, a2: (int)v12, a3: v7);
    }
  }
  else
  {
    m_pModSelector = this->m_pModSelector;
    if ( Ptr == m_pModSelector )
    {
      ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: m_pModSelector);
      if ( ActiveItemUserData != nullptr )
      {
        this->m_nCurrentModFilter = KeyValues::GetInt(this: ActiveItemUserData, keyName: "mod", defaultValue: -1);
        CBaseAssetPicker::RefreshAssetList(this, a2, a3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AAC0
// Name: protected: virtual void CBaseAssetPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnCheckButtonChecked(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *kv)
{
  vgui::CheckButton *Ptr; // eax
  vgui::CheckButton *m_pSubDirCheck; // ecx
  vgui::CheckButton *m_pOnlyUsedCheck; // ecx

  Ptr = (vgui::CheckButton *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSubDirCheck = this->m_pSubDirCheck;
  if ( Ptr == m_pSubDirCheck )
  {
    *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                             ^ (8
                              * ((int (__thiscall *)(vgui::CheckButton *))m_pSubDirCheck->IsSelected)(a1: m_pSubDirCheck)))
                            & 8;
    CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  }
  else
  {
    m_pOnlyUsedCheck = this->m_pOnlyUsedCheck;
    if ( Ptr == m_pOnlyUsedCheck )
    {
      *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                               ^ (16
                                * ((int (__thiscall *)(vgui::CheckButton *))m_pOnlyUsedCheck->IsSelected)(a1: m_pOnlyUsedCheck)))
                              & 0x10;
      CBaseAssetPicker::RefreshAssetList(this, a2, a3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020ABD0
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020AC30
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const char *pSearchSubDir,
        int nExtCount,
        const char **ppSearchExt)
{
  unsigned int v5; // eax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // eax

  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  v5 = std::char_traits<char>::length(str: pSearchSubDir);
  CUtlString::CUtlString(this: &this->m_pSubDir, pMemory: pSearchSubDir, nSizeInBytes: v5 + 1);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  this->m_DirectoriesToCheck.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
    this: &this->m_Ext,
    elem: this->m_Ext.m_Size,
    num: nExtCount,
    pToInsert: ppSearchExt);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020ACC0
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const CAssetCache::CachedAssetList_t *__formal)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020AD20
// Name: public: bool CAssetCache::ContinueSearchForAssets(struct AssetList_t__ __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAssetCache::ContinueSearchForAssets@<al>(
        CAssetCache *this@<ecx>,
        int a2@<edi>,
        AssetList_t__ *hList,
        float flDuration)
{
  CAssetCache::CachedAssetList_t *p_m_Data; // ebx
  const char *v5; // eax
  int m_hDirHandle; // ecx
  int m_hFind; // edx
  int *p_m_hFind; // esi
  char *v9; // eax
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  bool v12; // sf
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v13; // esi
  unsigned __int16 v14; // dx
  int v16; // [esp+8h] [ebp-11Ch]
  int v17; // [esp+Ch] [ebp-118h]
  int v18; // [esp+10h] [ebp-114h]
  char pDest[12]; // [esp+14h] [ebp-110h] BYREF
  char pSearchString[260]; // [esp+20h] [ebp-104h]
  float pFilePath; // [esp+12Ch] [ebp+8h]

  *(_DWORD *)&pSearchString[252] = this;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)hList].m_Data;
  pFilePath = _Plat_FloatTime(a1: v16, a2: v17, a3: v18, a4: *(_DWORD *)pDest, a5: *(_DWORD *)&pDest[4]);
  if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount != 0 )
  {
    while ( 1 )
    {
      v5 = CUtlString::operator char const *(this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_DirName);
      m_hDirHandle = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_hDirHandle;
      m_hFind = p_m_Data->m_hFind;
      p_m_hFind = &p_m_Data->m_hFind;
      *(_DWORD *)&pSearchString[256] = v5;
      *(_DWORD *)&pSearchString[248] = m_hDirHandle;
      if ( m_hFind == -1 )
      {
        V_snprintf(pDest, maxLen: 260, pFormat: "%s\\*", v5);
        v9 = (char *)g_pFullFileSystem->FindFirstEx(
                       this: g_pFullFileSystem,
                       a2: pDest,
                       a3: *(_DWORD *)(*(_DWORD *)&pSearchString[252] + 68),
                       a4: &p_m_Data->m_hFind);
      }
      else
      {
        v9 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: m_hFind);
      }
      if ( CAssetCache::AddFilesInDirectory(
             this: *(CAssetCache **)&pSearchString[252],
             a2,
             list: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)p_m_Data,
             pStartingFile: v9,
             pFilePath: *(const char **)&pSearchString[256],
             hCurrentDir: *(unsigned __int16 *)&pSearchString[248],
             flStartTime: pFilePath,
             flDuration) == 0 )
        return 0;
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: *p_m_hFind);
      *p_m_hFind = -1;
      m_Head = p_m_Data->m_DirectoriesToCheck.m_Head;
      *(_DWORD *)&pSearchString[256] = m_Head;
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
        this: &p_m_Data->m_DirectoriesToCheck,
        elem: m_Head);
      m_pMemory = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory;
      v12 = m_pMemory[m_Head].m_Element.m_DirName.m_Storage.m_Memory.m_nGrowSize < 0;
      v13 = &m_pMemory[m_Head];
      v13->m_Element.m_DirName.m_Storage.m_nActualLength = 0;
      if ( !v12 )
      {
        if ( v13->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory);
          v13->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v13->m_Element.m_DirName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v14 = *(_WORD *)&pSearchString[256];
      v13->m_Next = p_m_Data->m_DirectoriesToCheck.m_FirstFree;
      p_m_Data->m_DirectoriesToCheck.m_FirstFree = v14;
      if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount == 0 )
        goto LABEL_11;
    }
  }
  else
  {
LABEL_11:
    p_m_Data->m_bAssetScanComplete = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AEA0
// Name: public: CAssetCache::CachedAssetList_t::~CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::CachedAssetList_t::~CachedAssetList_t(CAssetCache::CachedAssetList_t *this)
{
  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirectoriesToCheck);
  if ( this->m_DirectoriesToCheck.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoriesToCheck.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoriesToCheck.m_Memory.m_pMemory);
      this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&this->m_Ext);
  this->m_pSubDir.m_Storage.m_nActualLength = 0;
  if ( this->m_pSubDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pSubDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSubDir.m_Storage.m_Memory.m_pMemory);
      this->m_pSubDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pSubDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>::~CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>(this: &this->m_AssetList);
}

//------------------------------------------------------------------------------
// Address: 0x1020AF10
// Name: public: CBaseAssetPicker::CBaseAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPicker *__thiscall CBaseAssetPicker::CBaseAssetPicker(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType,
        const char *pAssetSearchPath)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  char v11; // al
  KeyValues *v12; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "AssetPicker");
  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  if ( `CBaseAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    v8->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
    v9->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
    v10->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FolderFilter);
  CUtlString::CUtlString(this: &this->m_Filter);
  CUtlString::CUtlString(this: &this->m_SelectedAsset);
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_pMemory = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_nAllocationCount = 0;
  this->m_ExtraAssetExt.m_Memory.m_nGrowSize = 0;
  this->m_ExtraAssetExt.m_Size = 0;
  this->m_ExtraAssetExt.m_pElements = nullptr;
  this->m_usedAssets.m_Memory.m_pMemory = nullptr;
  this->m_usedAssets.m_Memory.m_nAllocationCount = 0;
  this->m_usedAssets.m_Memory.m_nGrowSize = 0;
  this->m_usedAssets.m_Size = 0;
  this->m_usedAssets.m_pElements = nullptr;
  this->m_pAssetExt = pExt;
  v11 = *((_BYTE *)this + 544) & 0xE8;
  this->m_pAssetType = pAssetType;
  this->m_pAssetTextType = pTextType;
  this->m_pAssetSubDir = pSubDir;
  this->m_pAssetSearchPath = pAssetSearchPath;
  this->m_nMatchingAssets = 0;
  *((_BYTE *)this + 544) = v11 | 8;
  this->m_hAssetList = (AssetList_t__ *)0xFFFF;
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    this->m_pInsertHelper = KeyValues::KeyValues(this: v12, setName: "node");
  else
    this->m_pInsertHelper = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020B0E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPicker::GetMessageMap(CBaseAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B110
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPicker::GetAnimMap(CBaseAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x1020B120
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPicker::GetKBMap(CBaseAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B150
// Name: public: virtual CBaseAssetPicker::~CBaseAssetPicker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::~CBaseAssetPicker(CBaseAssetPicker *this)
{
  KeyValues *m_pInsertHelper; // ecx

  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  this->m_pFileTree->RemoveActionSignalTarget(this: this->m_pFileTree, a2: this);
  this->m_pFileTree->SetParent_2(this: this->m_pFileTree, a2: nullptr);
  m_pInsertHelper = this->m_pInsertHelper;
  this->m_pFileTree = nullptr;
  if ( m_pInsertHelper != nullptr )
    KeyValues::deleteThis(this: m_pInsertHelper);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &this->m_usedAssets);
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&this->m_ExtraAssetExt);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_AssetList);
  this->m_SelectedAsset.m_Storage.m_nActualLength = 0;
  if ( this->m_SelectedAsset.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory);
      this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SelectedAsset.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Filter.m_Storage.m_nActualLength = 0;
  if ( this->m_Filter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Filter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Filter.m_Storage.m_Memory.m_pMemory);
      this->m_Filter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Filter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FolderFilter.m_Storage.m_nActualLength = 0;
  if ( this->m_FolderFilter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FolderFilter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FolderFilter.m_Storage.m_Memory.m_pMemory);
      this->m_FolderFilter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FolderFilter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020B260
// Name: public: virtual void CBaseAssetPicker::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::ApplyUserConfigSettings(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pUserConfig)
{
  const char *String; // ebx
  const char *v5; // eax
  const char *v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int v9; // ebx
  int ItemIDFromRow; // edi
  KeyValues *ItemUserData; // eax
  int nItemCount; // [esp+Ch] [ebp-4h]
  int nItemCounta; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig: pUserConfig);
  CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)pUserConfig);
  String = KeyValues::GetString(this: pUserConfig, keyName: "filter", defaultValue: &var);
  v5 = KeyValues::GetString(this: pUserConfig, keyName: "folderfilter", defaultValue: &var);
  CUtlString::operator=(this: &this->m_FolderFilter, src: v5);
  v6 = KeyValues::GetString(this: pUserConfig, keyName: "mod", defaultValue: &var);
  CUtlString::operator=(this: &this->m_Filter, src: String);
  this->m_pFilter->SetText(this: this->m_pFilter, a2: String);
  v7 = 0;
  this->m_nCurrentModFilter = -1;
  if ( v6 != nullptr && *v6 != 0 )
  {
    nItemCount = s_AssetCache.m_ModList.m_Size;
    i = 0;
    if ( s_AssetCache.m_ModList.m_Size > 0 )
    {
      while ( 1 )
      {
        v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v7].m_ModName);
        if ( _V_stricmp(s1: v6, s2: v8) == 0 )
          break;
        ++v7;
        if ( ++i >= nItemCount )
          return;
      }
      v9 = 0;
      nItemCounta = this->m_pModSelector->GetItemCount(this: this->m_pModSelector);
      if ( nItemCounta > 0 )
      {
        while ( 1 )
        {
          ItemIDFromRow = vgui::ComboBox::GetItemIDFromRow(this: this->m_pModSelector, row: v9);
          ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pModSelector, itemID: ItemIDFromRow);
          if ( KeyValues::GetInt(this: ItemUserData, keyName: "mod", defaultValue: 0) == i )
            break;
          if ( ++v9 >= nItemCounta )
            return;
        }
        this->m_nCurrentModFilter = i;
        this->m_pModSelector->ActivateItem(this: this->m_pModSelector, a2: ItemIDFromRow);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B3C0
// Name: public: virtual void CBaseAssetPicker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::Activate(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax

  CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pFilter, status: true);
  this->m_pFilter->RequestFocus(this: this->m_pFilter, a2: 0);
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
  {
    v4 = g_pVGui;
    v5 = g_pVGui->__vftable;
    v6 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v5->AddTickSignal)(a1: v4, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B420
// Name: public: virtual bool CBaseAssetPicker::IncrementalCacheAssets(float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBaseAssetPicker::IncrementalCacheAssets@<al>(
        CBaseAssetPicker *this@<ecx>,
        int a2@<edi>,
        float flTimeAllowed)
{
  char v4; // bl

  v4 = CAssetCache::ContinueSearchForAssets(
         this: &s_AssetCache,
         a2,
         hList: this->m_hAssetList,
         flDuration: flTimeAllowed);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    CAssetTreeView::OpenRoot(this: this->m_pFileTree);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1020B470
// Name: public: virtual void CBaseAssetPicker::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnTick(CBaseAssetPicker *this)
{
  int v2; // edi
  int v3; // xmm0_4
  char v4; // al
  int i; // ebx
  vgui::IVGui *v6; // ebx
  vgui::IVGui_vtbl *v7; // edi
  int v8; // eax
  const char *v9; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v11; // eax
  const char *v12; // eax
  char v13[4]; // [esp+10h] [ebp-204h] BYREF
  char ppath[4]; // [esp+10Ch] [ebp-108h] BYREF
  char v15; // [esp+213h] [ebp-1h]

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  v2 = this->GetCachedAssetCount(this);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    v3 = 1048576000;
  else
    v3 = 1020054733;
  v4 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->IncrementalCacheAssets)(a1: this, a2: v3);
  *((_BYTE *)this + 544) &= ~2u;
  v15 = v4;
  for ( i = this->GetCachedAssetCount(this); v2 < i; ++v2 )
    CBaseAssetPicker::AddAssetToList(this, nAssetIndex: v2);
  if ( v15 != 0 )
  {
    v6 = g_pVGui;
    v7 = g_pVGui->__vftable;
    v8 = this->GetVPanel(this);
    v7->RemoveTickSignal(this: v6, a2: v8);
    *((_BYTE *)this + 544) |= 4u;
    v9 = CUtlString::operator char const *(this: &this->m_FolderFilter);
    m_pFileTree = this->m_pFileTree;
    V_snprintf(pDest: ppath, maxLen: 260, pFormat: "%s\\%s", this->m_pAssetSubDir, v9);
    V_StripTrailingSlash(ppath);
    v11 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
    CAssetTreeView::SelectFolder_R(this: m_pFileTree, nItemID: v11, pPath: ppath);
    CBaseAssetPicker::RefreshAssetList(this, a2: (int)v6, a3: (int)m_pFileTree);
  }
  else
  {
    v12 = &var;
    if ( (*((_BYTE *)this + 544) & 4) == 0 )
      v12 = " ...";
    V_snprintf(
      pDest: v13,
      maxLen: 512,
      pFormat: "%s (%d/%d)%s",
      this->m_pAssetType,
      this->m_nMatchingAssets,
      this->m_AssetList.m_Size,
      v12);
    this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B840
// Name: public: struct AssetList_t__ __near * CAssetCache::FindAssetList(char const __near *,char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
AssetList_t__ *__thiscall CAssetCache::FindAssetList(
        CAssetCache *this,
        const char *pAssetType,
        const char *pSubDir,
        int nExtCount,
        const char **ppExt)
{
  int v6; // edi
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // eax
  int p_m_Data; // esi
  CAssetTreeView *v9; // eax
  CAssetTreeView *v10; // eax
  CAssetCache::CachedAssetList_t search; // [esp+Ch] [ebp-60h] BYREF

  CAssetCache::CachedAssetList_t::CachedAssetList_t(
    this: &search,
    pSearchSubDir: pSubDir,
    nExtCount,
    ppSearchExt: ppExt);
  v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_CachedAssets,
         &search);
  if ( v6 == 0xFFFF )
  {
    v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_CachedAssets,
           insert: &search);
    m_pMemory = this->m_CachedAssets.m_Elements.m_pMemory;
    p_m_Data = (int)&m_pMemory[v6].m_Data;
    CUtlString::operator=(this: &m_pMemory[v6].m_Data.m_pSubDir, src: pSubDir);
    CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
      this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)(p_m_Data + 40),
      elem: *(_DWORD *)(p_m_Data + 52),
      num: nExtCount,
      pToInsert: ppExt);
    *(_DWORD *)(p_m_Data + 88) = -1;
    *(_BYTE *)(p_m_Data + 92) = 0;
    v9 = (CAssetTreeView *)operator new(nSize: 0x210u);
    if ( v9 != nullptr )
      v10 = CAssetTreeView::CAssetTreeView(
              this: v9,
              pParent: nullptr,
              pName: "FolderFilter",
              pRootFolderName: pAssetType,
              pRootDir: pSubDir);
    else
      v10 = nullptr;
    *(_DWORD *)(p_m_Data + 20) = v10;
  }
  CAssetCache::CachedAssetList_t::~CachedAssetList_t(this: &search);
  return (AssetList_t__ *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x1020B900
// Name: protected: void CBaseAssetPicker::CreateStandardControls(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::CreateStandardControls(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        bool bAllowMultiselect)
{
  int v4; // edi
  void *v5; // esp
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v9; // ebx
  vgui::ComboBox *v10; // eax
  vgui::ComboBox *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  AssetList_t__ *m_hAssetList; // eax
  CAssetTreeView *m_pFileTree; // ecx
  vgui::CheckButton *v16; // eax
  vgui::CheckButton *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::ListPanel *v19; // eax
  vgui::Panel *v20; // edi
  vgui::TextEntry *v21; // eax
  vgui::TextEntry *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  BOOL v25; // ecx
  vgui::TextEntry *v26; // eax
  vgui::TextEntry *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  const char *m_pAssetExt; // [esp+0h] [ebp-20Ch] BYREF
  unsigned __int8 v31[8]; // [esp+4h] [ebp-208h] BYREF
  char pDest[512]; // [esp+Ch] [ebp-200h] BYREF

  v4 = this->m_ExtraAssetExt.m_Size + 1;
  v5 = alloca(4 * v4);
  m_pAssetExt = this->m_pAssetExt;
  if ( v4 > 1 )
    memcpy(dst: v31, src: (unsigned __int8 *)this->m_ExtraAssetExt.m_Memory.m_pMemory, count: v4 - 1);
  this->m_hAssetList = CAssetCache::FindAssetList(
                         this: &s_AssetCache,
                         pAssetType: this->m_pAssetType,
                         pSubDir: this->m_pAssetSubDir,
                         nExtCount: v4,
                         ppExt: &m_pAssetExt);
  v6 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: pParent,
           name: "AssetSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  else
    v7 = nullptr;
  this->m_pAssetSplitter = v7;
  vgui::Panel::SetAutoResize(
    this: v7,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  Child = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v10 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v10 != nullptr )
    v11 = vgui::ComboBox::ComboBox(this: v10, parent: Child, panelName: "ModFilter", numLines: 5, allowEdit: false);
  else
    v11 = nullptr;
  this->m_pModSelector = v11;
  v11->AddActionSignalTarget_2(this: v11, a2: this);
  v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: Child,
            panelName: "RescanButton",
            text: "Rescan",
            pActionSignalTarget: this,
            pCmd: "AssetRescan");
  else
    v13 = nullptr;
  this->m_pRescanButton = v13;
  vgui::Panel::SetWide(this: v13, wide: 75);
  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    m_pFileTree = nullptr;
  else
    m_pFileTree = s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_pFileTree;
  this->m_pFileTree = m_pFileTree;
  m_pFileTree->SetParent_2(this: m_pFileTree, a2: Child);
  this->m_pFileTree->AddActionSignalTarget_2(this: this->m_pFileTree, a2: this);
  v16 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v16 != nullptr )
    v17 = vgui::CheckButton::CheckButton(
            this: v16,
            parent: Child,
            panelName: "SubDirCheck",
            text: "Check subfolders for files?");
  else
    v17 = nullptr;
  this->m_pSubDirCheck = v17;
  v17->SetSelected(this: v17, a2: true);
  this->m_pSubDirCheck->SetEnabled(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->SetVisible(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->AddActionSignalTarget_2(this: this->m_pSubDirCheck, a2: this);
  V_snprintf(pDest, maxLen: 512, pFormat: "No .%s files", this->m_pAssetExt);
  v18 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v18 != nullptr )
    v19 = vgui::ListPanel::ListPanel(this: v18, parent: v9, panelName: "AssetBrowser");
  else
    v19 = nullptr;
  this->m_pAssetBrowser = v19;
  v19->AddColumnHeader(this: v19, a2: 0, a3: "mod", a4: "Mod", a5: 52, a6: 0);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 1,
    a3: "asset",
    a4: this->m_pAssetType,
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 2,
    a3: "timesused",
    a4: "Times Used",
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->SetSelectIndividualCells(this: this->m_pAssetBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pAssetBrowser, bState: bAllowMultiselect);
  this->m_pAssetBrowser->SetEmptyListText_2(this: this->m_pAssetBrowser, a2: pDest);
  this->m_pAssetBrowser->SetDragEnabled(this: this->m_pAssetBrowser, a2: true);
  this->m_pAssetBrowser->AddActionSignalTarget_2(this: this->m_pAssetBrowser, a2: this);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 0, a3: AssetBrowserModSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 1, a3: AssetBrowserSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 2, a3: AssetBrowserTimesUsedSortFunc);
  this->m_pAssetBrowser->SetSortColumn(this: this->m_pAssetBrowser, a2: 1);
  v20 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v21 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v21 != nullptr )
    v22 = vgui::TextEntry::TextEntry(this: v21, parent: v20, panelName: "FilterList");
  else
    v22 = nullptr;
  this->m_pFilter = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(
            this: v23,
            parent: v20,
            panelName: "OnlyUsedCheck",
            text: "Show used assets only");
  else
    v24 = nullptr;
  v25 = (*((_BYTE *)this + 544) & 0x10) != 0;
  this->m_pOnlyUsedCheck = v24;
  v24->SetSelected(this: v24, a2: v25);
  this->m_pOnlyUsedCheck->AddActionSignalTarget_2(this: this->m_pOnlyUsedCheck, a2: this);
  v26 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v26 != nullptr )
    v27 = vgui::TextEntry::TextEntry(this: v26, parent: v20, panelName: "FullPath");
  else
    v27 = nullptr;
  this->m_pFullPath = v27;
  v27->SetEnabled(this: v27, a2: false);
  this->m_pFullPath->SetEditable(this: this->m_pFullPath, a2: false);
  v28 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: v20,
            panelName: "FindButton",
            text: "Find Asset",
            pActionSignalTarget: this,
            pCmd: "FindAsset");
  else
    v29 = nullptr;
  this->m_nCurrentModFilter = -1;
  this->m_pFindAssetButton = v29;
}

//------------------------------------------------------------------------------
// Address: 0x10307080
// Name: public: class vgui::ScrollBar __near * vgui::TreeView::SetScrollBarExternal(bool,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::TreeView::SetScrollBarExternal(
        vgui::TreeView *this,
        bool vertical,
        vgui::Panel *newParent)
{
  vgui::ScrollBar *m_pVertScrollBar; // ecx
  vgui::ScrollBar *m_pHorzScrollBar; // ecx

  if ( vertical )
  {
    m_pVertScrollBar = this->m_pVertScrollBar;
    this->m_bScrollbarExternal[0] = true;
    m_pVertScrollBar->SetParent_2(this: m_pVertScrollBar, a2: newParent);
    return this->m_pVertScrollBar;
  }
  else
  {
    m_pHorzScrollBar = this->m_pHorzScrollBar;
    this->m_bScrollbarExternal[1] = true;
    m_pHorzScrollBar->SetParent_2(this: m_pHorzScrollBar, a2: newParent);
    return this->m_pHorzScrollBar;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030A4A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TreeView::GetMessageMap(vgui::TreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetMessageMap'::`2'::s_pMap;
  `vgui::TreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  `vgui::TreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030A4D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TreeView::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TreeView::GetAnimMap(vgui::TreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "TreeView");
}

//------------------------------------------------------------------------------
// Address: 0x1030A4E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TreeView::GetKBMap(vgui::TreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetKBMap'::`2'::s_pMap;
  `vgui::TreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  `vgui::TreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0040EE00
// Name: public: static char const __near * CBaseAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPicker::GetPanelClassName()
{
  return "CBaseAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x0040EE10
// Name: public: static char const __near * CBaseAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPickerFrame::GetPanelClassName()
{
  return "CBaseAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x0040EE20
// Name: bool AssetTreeViewSortFunc(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AssetTreeViewSortFunc(KeyValues *node1, KeyValues *node2)
{
  const char *String; // esi
  const char *v3; // eax

  String = KeyValues::GetString(this: node1, keyName: "text", defaultValue: nullptr);
  v3 = KeyValues::GetString(this: node2, keyName: "text", defaultValue: nullptr);
  return _V_stricmp(s1: String, s2: v3) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040EE60
// Name: public: static char const __near * CAssetTreeView::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetTreeView::GetPanelClassName()
{
  return "CAssetTreeView";
}

//------------------------------------------------------------------------------
// Address: 0x0040EE70
// Name: AssetBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  bool v3; // bl
  const char *String; // esi
  const char *v6; // eax

  v3 = KeyValues::GetInt(this: item1->kv, keyName: "root", defaultValue: 0) != 0;
  if ( v3 != (KeyValues::GetInt(this: item2->kv, keyName: "root", defaultValue: 0) != 0) )
    return 2 * !v3 - 1;
  String = KeyValues::GetString(this: item1->kv, keyName: "asset", defaultValue: defaultValue);
  v6 = KeyValues::GetString(this: item2->kv, keyName: "asset", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0040EEF0
// Name: AssetBrowserModSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserModSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "modIndex", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "modIndex", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040EF40
// Name: AssetBrowserTimesUsedSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserTimesUsedSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "timesused", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "timesused", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040EF90
// Name: public: virtual void CBaseAssetPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnKeyCodeTyped(CBaseAssetPicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  vgui::IPanel *v5; // esi
  vgui::ListPanel *m_pAssetBrowser; // edi
  int v7; // eax
  int v8; // eax
  vgui::IPanel_vtbl *codea; // [esp+14h] [ebp+8h]

  if ( code == KEY_UP || code == KEY_DOWN || code == KEY_PAGEUP || code == KEY_PAGEDOWN )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "KeyCodeTyped", firstKey: "code", firstValue: code);
    else
      v4 = nullptr;
    v5 = g_pVGuiPanel;
    m_pAssetBrowser = this->m_pAssetBrowser;
    codea = g_pVGuiPanel->__vftable;
    v7 = this->GetVPanel(this);
    v8 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pAssetBrowser->GetVPanel)(
           a1: m_pAssetBrowser,
           a2: v4,
           a3: v7);
    ((void (__thiscall *)(vgui::IPanel *, int))codea->SendMessage)(a1: v5, a2: v8);
    KeyValues::deleteThis(this: v4);
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F030
// Name: protected: bool CBaseAssetPicker::IsAssetVisible(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAssetPicker::IsAssetVisible(CBaseAssetPicker *this, const CachedAssetInfo_t *nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ecx
  int m_nCurrentModFilter; // eax
  const char *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-Ch] [ebp-10h]
  const CachedAssetInfo_t *info; // [esp+Ch] [ebp+8h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  info = v3;
  if ( m_nCurrentModFilter >= 0 && m_nCurrentModFilter != v3->m_nModIndex )
    return false;
  v6 = CUtlString::operator char const *(this: &v3->m_AssetName);
  v7 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
  if ( _V_strcmp(s1: v6, s2: v7) == 0 )
    return true;
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
  {
    v8 = CUtlString::Get(this: &this->m_Filter);
    if ( V_stristr(pStr: v6, pSearch: v8) == nullptr )
      return false;
  }
  if ( CUtlString::Length(this: &this->m_FolderFilter) != 0 )
  {
    v12 = CUtlString::Length(this: &this->m_FolderFilter);
    v9 = CUtlString::Get(this: &this->m_FolderFilter);
    if ( V_strnicmp(s1: v6, s2: v9, n: v12) != 0 )
      return false;
  }
  if ( (*((_BYTE *)this + 544) & 8) == 0 )
  {
    v10 = CUtlString::Length(this: &this->m_FolderFilter);
    strchr(string: (unsigned __int8 *)&v6[v10], chr: 0x5Cu);
    if ( v11 != 0 )
      return false;
  }
  return (*((_BYTE *)this + 544) & 0x10) == 0 || info->m_nTimesUsed != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040F130
// Name: protected: virtual void CBaseAssetPicker::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemDeselected(CBaseAssetPicker *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
    this->OnSelectedAssetPicked(this, a2: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0040F170
// Name: public: int CBaseAssetPicker::GetSelectedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetSelectedAssetCount(CBaseAssetPicker *this)
{
  return this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x0040F180
// Name: public: char const __near * CBaseAssetPicker::GetSelectedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetSelectedAsset(CBaseAssetPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  v4 = nSelectionIndex;
  if ( nSelectionIndex < 0 )
    v4 = v3 - 1;
  if ( v3 <= v4 || v4 < 0 )
    return nullptr;
  v5 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: v4);
  v6 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v5);
  return KeyValues::GetString(this: v6, keyName: "asset", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0040F1F0
// Name: protected: void CBaseAssetPickerFrame::SetAssetPicker(class CBaseAssetPicker __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::SetAssetPicker(CBaseAssetPickerFrame *this, CBaseAssetPicker *pPicker)
{
  this->m_pPicker = pPicker;
  pPicker->AddActionSignalTarget_2(this: pPicker, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x0040F210
// Name: public: void CBaseAssetPickerFrame::DoModal(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::DoModal(CBaseAssetPickerFrame *this, KeyValues *pKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  KeyValues *v4; // ecx
  CBaseAssetPicker *m_pPicker; // ecx

  vgui::Frame::DoModal(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  v4 = this->m_pContextKeyValues;
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pKeyValues;
  m_pPicker->Activate(this: m_pPicker);
}

//------------------------------------------------------------------------------
// Address: 0x0040F270
// Name: public: virtual void CBaseAssetPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPickerFrame::OnCommand(CBaseAssetPickerFrame *this@<ecx>, int a2@<ebx>, KeyValues *pCommand)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  CBaseAssetPicker *m_pPicker; // esi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  KeyValues *v10; // eax
  const char *String; // eax
  int v12; // ebx
  int i; // esi
  const char *SelectedAsset; // eax
  char pBuf[512]; // [esp+8h] [ebp-204h] BYREF
  KeyValues *pAssetKeys; // [esp+208h] [ebp-4h]
  KeyValues *pActionKeys; // [esp+214h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "AssetSelected");
      pActionKeys = v5;
    }
    else
    {
      pActionKeys = nullptr;
      v5 = nullptr;
    }
    if ( vgui::ListPanel::IsMultiselectEnabled(this: this->m_pPicker->m_pAssetBrowser) )
    {
      pAssetKeys = KeyValues::FindKey(this: v5, keyName: "assets", bCreate: true);
      v12 = ((int (__thiscall *)(vgui::ListPanel *, int))this->m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
              a1: this->m_pPicker->m_pAssetBrowser,
              a2);
      for ( i = 0; i < v12; ++i )
      {
        V_snprintf(pDest: pBuf, maxLen: 512, pFormat: "asset%d", i);
        SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this: this->m_pPicker, nSelectionIndex: i);
        KeyValues::SetString(this: pAssetKeys, keyName: pBuf, value: SelectedAsset);
      }
      v5 = pActionKeys;
    }
    else
    {
      m_pPicker = this->m_pPicker;
      v7 = ((int (__thiscall *)(vgui::ListPanel *, int))m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
             a1: m_pPicker->m_pAssetBrowser,
             a2);
      v8 = v7 - 1;
      if ( __OFSUB__(v7, v7 - 1) || v8 < 0 )
      {
        KeyValues::SetString(this: v5, keyName: "asset", value: nullptr);
      }
      else
      {
        v9 = m_pPicker->m_pAssetBrowser->GetSelectedItem(this: m_pPicker->m_pAssetBrowser, a2: v8);
        v10 = m_pPicker->m_pAssetBrowser->GetItem(this: m_pPicker->m_pAssetBrowser, a2: v9);
        String = KeyValues::GetString(this: v10, keyName: "asset", defaultValue: defaultValue);
        KeyValues::SetString(this: v5, keyName: "asset", value: String);
      }
    }
    this->m_pPicker->CustomizeSelectionMessage(this: this->m_pPicker, a2: v5);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->CloseModal(this);
    ((void (__thiscall *)(CBaseAssetPickerFrame *))this->PostActionSignal)(a1: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F450
// Name: protected: virtual void CBaseAssetPickerFrame::CloseModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::CloseModal(CBaseAssetPickerFrame *this)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  unsigned int v4; // eax

  v2 = g_pVGui;
  v3 = g_pVGui->__vftable;
  v4 = this->m_pPicker->GetVPanel(this: this->m_pPicker);
  v3->RemoveTickSignal(this: v2, a2: v4);
  vgui::Frame::CloseModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040F4B0
// Name: public: virtual void CAssetTreeView::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ApplySchemeSettings(CAssetTreeView *this, vgui::IScheme *pScheme)
{
  CAssetTreeView_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultSmall", a3: false);
  v3->SetFont(this, a2: v4);
  ((void (__thiscall *)(CAssetTreeView *, int))this->SetFgColor)(a1: this, a2: -2892072);
}

//------------------------------------------------------------------------------
// Address: 0x0040F500
// Name: public: virtual int CBaseAssetPicker::GetAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetAssetCount(CBaseAssetPicker *this)
{
  return this->m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040F510
// Name: public: CBaseAssetPickerFrame::CBaseAssetPickerFrame(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPickerFrame *__thiscall CBaseAssetPickerFrame::CBaseAssetPickerFrame(
        CBaseAssetPickerFrame *this,
        vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "AssetPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( `CBaseAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
    v3->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
    v4->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
    v5->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v6 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "OpenButton",
           text: "#FileOpenDialog_Open",
           pActionSignalTarget: this,
           pCmd: "Open");
  else
    v7 = nullptr;
  this->m_pOpenButton = v7;
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#FileOpenDialog_Cancel",
           pActionSignalTarget: this,
           pCmd: "Cancel");
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F660
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPickerFrame::GetMessageMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F690
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPickerFrame::GetAnimMap(CBaseAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x0040F6A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPickerFrame::GetKBMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F6D0
// Name: public: virtual CBaseAssetPickerFrame::~CBaseAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::~CBaseAssetPickerFrame(CBaseAssetPickerFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040F700
// Name: public: void CUtlNTree<class CUtlString,unsigned short>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CUtlString,unsigned short>::Unlink(
        CUtlNTree<CUtlString,unsigned short> *this,
        unsigned __int16 elem)
{
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // edx
  int m_PrevSibling; // esi
  CUtlNTree<CUtlString,unsigned short>::Node_t *v4; // eax
  int m_Parent; // esi
  int m_NextSibling; // edx

  m_pMemory = this->m_Memory.m_pMemory;
  m_PrevSibling = this->m_Memory.m_pMemory[elem].m_PrevSibling;
  v4 = &this->m_Memory.m_pMemory[elem];
  if ( (_WORD)m_PrevSibling == 0xFFFF )
  {
    m_Parent = v4->m_Parent;
    if ( (_WORD)m_Parent == 0xFFFF )
    {
      if ( this->m_Root == elem )
        this->m_Root = v4->m_NextSibling;
    }
    else
    {
      m_pMemory[m_Parent].m_FirstChild = v4->m_NextSibling;
    }
  }
  else
  {
    m_pMemory[m_PrevSibling].m_NextSibling = v4->m_NextSibling;
  }
  m_NextSibling = v4->m_NextSibling;
  if ( (_WORD)m_NextSibling != 0xFFFF )
    this->m_Memory.m_pMemory[m_NextSibling].m_PrevSibling = v4->m_PrevSibling;
  *(_DWORD *)&v4->m_PrevSibling = -1;
  v4->m_Parent = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040F790
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F8D0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F980
// Name: public: void CAssetTreeView::OpenRoot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::OpenRoot(CAssetTreeView *this)
{
  const char *v2; // ebx
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  CAssetTreeView_vtbl *v6; // ebx
  int v7; // eax
  int v8; // ebx

  this->RemoveAll(this);
  v2 = CUtlString::operator char const *(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[this->m_DirectoryStructure.m_Root].m_Element);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "root");
  else
    v4 = nullptr;
  v5 = CUtlString::Get(this: &this->m_RootFolderName);
  KeyValues::SetString(this: v4, keyName: "text", value: v5);
  KeyValues::SetInt(this: v4, keyName: "root", value: 1);
  KeyValues::SetInt(this: v4, keyName: "expand", value: 1);
  KeyValues::SetInt(this: v4, keyName: "dirHandle", value: this->m_DirectoryStructure.m_Root);
  KeyValues::SetString(this: v4, keyName: "path", value: v2);
  v6 = this->__vftable;
  v7 = this->GetRootItemIndex(this);
  v8 = v6->AddItem(this, a2: v4, a3: v7);
  KeyValues::deleteThis(this: v4);
  this->ExpandItem(this, a2: v8, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0040FA60
// Name: private: static bool CAssetCache::CachedAssetLessFunc(struct CAssetCache::CachedAssetList_t const __near &,struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAssetCache::CachedAssetLessFunc(
        const CAssetCache::CachedAssetList_t *src1,
        const CAssetCache::CachedAssetList_t *src2)
{
  const char *v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  const char *v9; // [esp-4h] [ebp-Ch]
  int nCount; // [esp+14h] [ebp+Ch]

  v9 = CUtlString::operator char const *(this: &src2->m_pSubDir);
  v3 = CUtlString::operator char const *(this: &src1->m_pSubDir);
  v4 = _V_stricmp(s1: v3, s2: v9) > 0;
  if ( v4 != 0 )
    return v4 > 0;
  v6 = src1->m_Ext.m_Size - src2->m_Ext.m_Size;
  nCount = src1->m_Ext.m_Size;
  if ( v6 != 0 )
    return v6 > 0;
  v7 = 0;
  if ( src1->m_Ext.m_Size <= 0 )
    return false;
  while ( 1 )
  {
    v8 = _V_stricmp(s1: src1->m_Ext.m_Memory.m_pMemory[v7], s2: src2->m_Ext.m_Memory.m_pMemory[v7]);
    if ( v8 != 0 )
      break;
    if ( ++v7 >= nCount )
      return false;
  }
  return v8 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040FB00
// Name: private: int CAssetCache::GetAssetUsageCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAssetCache::GetAssetUsageCount(CAssetCache *this, const char *assetName)
{
  int result; // eax
  int v4; // edi
  int i; // ebx
  char *v6; // eax

  result = this->m_usedAssets.m_Size;
  if ( result != 0 )
  {
    v4 = 0;
    if ( result <= 0 )
    {
      return 0;
    }
    else
    {
      for ( i = 0; ; ++i )
      {
        v6 = CUtlString::Get(this: &this->m_usedAssets.m_Memory.m_pMemory[i].m_assetName);
        if ( V_stristr(pStr: v6, pSearch: assetName) != nullptr )
          break;
        if ( ++v4 >= this->m_usedAssets.m_Size )
          return 0;
      }
      return this->m_usedAssets.m_Memory.m_pMemory[v4].m_nTimesUsed;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FB60
// Name: private: bool CAssetCache::DoesExtensionMatch(struct CAssetCache::CachedAssetList_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::DoesExtensionMatch(
        CAssetCache *this,
        CAssetCache::CachedAssetList_t *info,
        const char *pFileName)
{
  int m_Size; // edi
  int v4; // esi
  char pChildExt[260]; // [esp+Ch] [ebp-104h] BYREF

  V_ExtractFileExtension(path: pFileName, dest: pChildExt, destSize: 260);
  m_Size = info->m_Ext.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: info->m_Ext.m_Memory.m_pMemory[v4], s2: pChildExt) != 0 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FC20
// Name: public: void CUtlNTree<class CUtlString,unsigned short>::LinkChildAfter(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CUtlString,unsigned short>::LinkChildAfter(
        CUtlNTree<CUtlString,unsigned short> *this,
        unsigned __int16 parent,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  CUtlNTree<CUtlString,unsigned short>::Node_t *v5; // eax
  CUtlNTree<CUtlString,unsigned short>::Node_t *v6; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *v7; // ecx
  int m_Root; // ecx
  int m_NextSibling; // eax

  CUtlNTree<CUtlString,unsigned short>::Unlink(this, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Parent = parent;
  v5->m_PrevSibling = after;
  if ( after == 0xFFFF )
  {
    if ( parent == 0xFFFF )
    {
      v5->m_NextSibling = this->m_Root;
      m_Root = this->m_Root;
      if ( (_WORD)m_Root != 0xFFFF )
        this->m_Memory.m_pMemory[m_Root].m_PrevSibling = elem;
      this->m_Root = elem;
    }
    else
    {
      v7 = &this->m_Memory.m_pMemory[parent];
      v5->m_NextSibling = v7->m_FirstChild;
      v7->m_FirstChild = elem;
    }
  }
  else
  {
    v6 = &this->m_Memory.m_pMemory[after];
    v5->m_NextSibling = v6->m_NextSibling;
    v6->m_NextSibling = elem;
  }
  m_NextSibling = v5->m_NextSibling;
  if ( (_WORD)m_NextSibling != 0xFFFF )
    this->m_Memory.m_pMemory[m_NextSibling].m_PrevSibling = elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040FCD0
// Name: protected: unsigned short CUtlNTree<class CUtlString,unsigned short>::AllocInternal(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlNTree<CUtlString,unsigned short>::AllocInternal(
        CUtlNTree<CUtlString,unsigned short> *this)
{
  int m_FirstFree; // eax
  unsigned __int16 m_MaxElementIndex; // di
  CUtlNTree<CUtlString,unsigned short>::Node_t *v4; // eax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // eax

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    if ( this->m_MaxElementIndex == this->m_Memory.m_nAllocationCount )
      CUtlMemory<CachedAssetInfo_t,int>::Grow(
        (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
        num: 1);
    m_MaxElementIndex = this->m_MaxElementIndex;
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    if ( m_MaxElementIndex == 0xFFFF )
      _Error(a1: "CUtlNTree overflow!\n");
  }
  else
  {
    m_MaxElementIndex = this->m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_NextSibling;
  }
  v4 = &this->m_Memory.m_pMemory[m_MaxElementIndex];
  *(_DWORD *)&v4->m_Parent = -1;
  *(_DWORD *)&v4->m_PrevSibling = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  ++this->m_ElementCount;
  this->m_pElements = m_pMemory;
  return m_MaxElementIndex;
}

//------------------------------------------------------------------------------
// Address: 0x0040FF70
// Name: protected: unsigned short CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x004102D0
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410310
// Name: private: void CAssetTreeView::AddDirectoryToTreeView(int,char const __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::AddDirectoryToTreeView(
        CAssetTreeView *this,
        int nParentItemIndex,
        const char *pFullParentPath,
        int hPath)
{
  int v5; // ebx
  const char *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  unsigned __int16 m_FirstChild; // bx
  int v10; // ebx
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // edx
  char pFullPath[260]; // [esp+Ch] [ebp-108h] BYREF
  const char *pDirName; // [esp+110h] [ebp-4h]

  v5 = (unsigned __int16)hPath;
  v6 = CUtlString::Get(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_Element);
  pDirName = v6;
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "text", firstValue: v6);
  else
    v8 = nullptr;
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s/%s", pFullParentPath, pDirName);
  V_FixSlashes(pname: pFullPath, separator: 92);
  _V_strlower(start: pFullPath);
  m_FirstChild = this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_FirstChild;
  KeyValues::SetString(this: v8, keyName: "path", value: pFullPath);
  KeyValues::SetInt(this: v8, keyName: "expand", value: m_FirstChild != 0xFFFF);
  KeyValues::SetInt(this: v8, keyName: "image", value: 0);
  KeyValues::SetInt(this: v8, keyName: "dirHandle", value: (unsigned __int16)hPath);
  v10 = this->AddItem(this, a2: v8, a3: nParentItemIndex);
  KeyValues::deleteThis(this: v8);
  SetItemFgColor = this->SetItemFgColor;
  hPath = -16727840;
  SetItemFgColor(this, a2: v10, a3: (const Color *)&hPath);
}

//------------------------------------------------------------------------------
// Address: 0x00410430
// Name: public: virtual void CAssetTreeView::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::GenerateChildrenOfNode(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v3; // esi
  int Int; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // eax
  unsigned __int16 i; // cx
  unsigned int v7; // ebx
  const char *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // eax
  char pDest[260]; // [esp+8h] [ebp-114h] BYREF
  const char *pFullParentPath; // [esp+10Ch] [ebp-10h]
  int value; // [esp+110h] [ebp-Ch]
  const char *m_FirstChild; // [esp+114h] [ebp-8h]
  int v16; // [esp+118h] [ebp-4h] BYREF

  v3 = this->GetItemData(this, a2: nItemIndex);
  pFullParentPath = KeyValues::GetString(this: v3, keyName: "path", defaultValue: nullptr);
  if ( pFullParentPath != nullptr )
  {
    Int = (unsigned __int16)KeyValues::GetInt(this: v3, keyName: "dirHandle", defaultValue: 0xFFFF);
    if ( (_WORD)Int != 0xFFFF )
    {
      m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      for ( i = m_pMemory[Int].m_FirstChild; i != 0xFFFF; i = m_pMemory[v7].m_NextSibling )
      {
        value = i;
        v7 = i;
        v8 = CUtlString::Get(this: &m_pMemory[v7].m_Element);
        m_FirstChild = v8;
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "text", firstValue: v8);
        else
          v10 = nullptr;
        V_snprintf(pDest, maxLen: 260, pFormat: "%s/%s", pFullParentPath, m_FirstChild);
        V_FixSlashes(pname: pDest, separator: 92);
        _V_strlower(start: pDest);
        m_FirstChild = (const char *)this->m_DirectoryStructure.m_Memory.m_pMemory[v7].m_FirstChild;
        KeyValues::SetString(this: v10, keyName: "path", value: pDest);
        KeyValues::SetInt(this: v10, keyName: "expand", value: (_WORD)m_FirstChild != 0xFFFF);
        KeyValues::SetInt(this: v10, keyName: "image", value: 0);
        KeyValues::SetInt(this: v10, keyName: "dirHandle", value);
        value = this->AddItem(this, a2: v10, a3: nItemIndex);
        KeyValues::deleteThis(this: v10);
        SetItemFgColor = this->SetItemFgColor;
        v16 = -16727840;
        SetItemFgColor(this, a2: value, a3: (const Color *)&v16);
        m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004105E0
// Name: private: unsigned short CAssetTreeView::RefreshTreeViewItem(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::RefreshTreeViewItem(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v4; // edi
  const char *String; // eax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  bool v7; // zf
  BOOL v8; // ebx
  bool (__thiscall *ModifyItem)(vgui::TreeView *, int, KeyValues *); // edx
  int v10; // edi
  int v11; // ebx
  void *v12; // esp
  int i; // edi
  int v14; // eax
  unsigned __int16 refreshed; // ax
  int m_NextSibling; // edi
  unsigned __int16 *v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // dx
  KeyValues *v20; // [esp-4h] [ebp-20h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-1Ch] BYREF
  const char *pFullParentPath; // [esp+Ch] [ebp-10h]
  int hPath; // [esp+10h] [ebp-Ch]
  unsigned __int16 *pFoundHandles; // [esp+14h] [ebp-8h]
  int v25; // [esp+18h] [ebp-4h]

  if ( nItemIndex < 0 )
    return -1;
  v4 = this->GetItemData(this, a2: nItemIndex);
  hPath = (unsigned __int16)KeyValues::GetInt(this: v4, keyName: "dirHandle", defaultValue: 0xFFFF);
  String = KeyValues::GetString(this: v4, keyName: "path", defaultValue: nullptr);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  pFullParentPath = String;
  v7 = m_pMemory[hPath].m_FirstChild == 0xFFFF;
  v25 = 24 * hPath;
  v8 = !v7;
  if ( v8 == (KeyValues::GetInt(this: v4, keyName: "expand", defaultValue: 0) != 0) )
  {
    v10 = nItemIndex;
  }
  else
  {
    KeyValues::SetInt(this: v4, keyName: "expand", value: v8);
    ModifyItem = this->ModifyItem;
    v20 = v4;
    v10 = nItemIndex;
    ModifyItem(this, a2: nItemIndex, a3: v20);
  }
  if ( this->IsItemExpanded(this, a2: v10) )
  {
    v11 = this->GetNumChildren(this, a2: v10);
    v12 = alloca(2 * v11);
    pFoundHandles = (unsigned __int16 *)v21;
    memset(dst: v21, value: 0xFFu, count: 2 * v11);
    for ( i = 0; i < v11; ++i )
    {
      v14 = this->GetChild(this, a2: nItemIndex, a3: i);
      refreshed = CAssetTreeView::RefreshTreeViewItem(this, nItemIndex: v14);
      pFoundHandles[i] = refreshed;
    }
    m_NextSibling = *(unsigned __int16 *)((char *)&this->m_DirectoryStructure.m_Memory.m_pMemory->m_FirstChild + v25);
    if ( (_WORD)m_NextSibling != 0xFFFF )
    {
      v17 = pFoundHandles;
      v25 = (int)&pFoundHandles[v11 - 1];
      do
      {
        v18 = 0;
        if ( v11 <= 0 )
        {
LABEL_14:
          CAssetTreeView::AddDirectoryToTreeView(
            this,
            nParentItemIndex: nItemIndex,
            pFullParentPath,
            hPath: m_NextSibling);
          v17 = pFoundHandles;
        }
        else
        {
          while ( v17[v18] != (_WORD)m_NextSibling )
          {
            if ( ++v18 >= v11 )
              goto LABEL_14;
          }
          v19 = *(_WORD *)v25;
          --v11;
          v25 -= 2;
          v17[v18] = v19;
        }
        m_NextSibling = this->m_DirectoryStructure.m_Memory.m_pMemory[(unsigned __int16)m_NextSibling].m_NextSibling;
      }
      while ( (_WORD)m_NextSibling != 0xFFFF );
    }
  }
  return hPath;
}

//------------------------------------------------------------------------------
// Address: 0x00410790
// Name: private: bool CAssetTreeView::SelectFolder_R(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetTreeView::SelectFolder_R(CAssetTreeView *this, int nItemID, const char *pPath)
{
  KeyValues *v6; // eax
  const char *String; // ebx
  const char *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // [esp-8h] [ebp-20h]
  CUtlString str; // [esp+8h] [ebp-10h] BYREF
  int nChildCount; // [esp+20h] [ebp+8h]

  if ( nItemID < 0 )
    return 0;
  v6 = this->GetItemData(this, a2: nItemID);
  String = KeyValues::GetString(this: v6, keyName: "path", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: pPath) != 0 )
  {
    CUtlString::CUtlString(this: &str, pString: String);
    CUtlString::operator+=(this: &str, c: 92);
    v11 = CUtlString::Length(this: &str);
    v8 = CUtlString::operator char const *(this: &str);
    if ( V_strnicmp(s1: v8, s2: pPath, n: v11) != 0 )
    {
      CUtlString::~CUtlString(this: &str);
      return 0;
    }
    else
    {
      this->ExpandItem(this, a2: nItemID, a3: true);
      v9 = 0;
      nChildCount = this->GetNumChildren(this, a2: nItemID);
      if ( nChildCount <= 0 )
      {
LABEL_10:
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 0;
      }
      else
      {
        while ( 1 )
        {
          v10 = this->GetChild(this, a2: nItemID, a3: v9);
          if ( CAssetTreeView::SelectFolder_R(this, nItemID: v10, pPath) )
            break;
          if ( ++v9 >= nChildCount )
            goto LABEL_10;
        }
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 1;
      }
    }
  }
  else
  {
    this->AddSelectedItem(this, a2: nItemID, a3: true, a4: false, a5: true);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004108F0
// Name: public: virtual void CBaseAssetPicker::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::GetUserConfigSettings(CBaseAssetPicker *this, KeyValues *pUserConfig)
{
  const char *v3; // eax
  const char *v4; // eax
  int m_nCurrentModFilter; // eax
  char v6; // bl
  CUtlString *v7; // eax
  const char *v8; // eax
  CUtlString v9; // [esp+Ch] [ebp-24h] BYREF
  CUtlString v10; // [esp+1Ch] [ebp-14h] BYREF
  int v11; // [esp+2Ch] [ebp-4h]

  v11 = 0;
  vgui::EditablePanel::GetUserConfigSettings(this, userConfig: pUserConfig);
  v3 = CUtlString::operator char const *(this: &this->m_Filter);
  KeyValues::SetString(this: pUserConfig, keyName: "filter", value: v3);
  v4 = CUtlString::operator char const *(this: &this->m_FolderFilter);
  KeyValues::SetString(this: pUserConfig, keyName: "folderfilter", value: v4);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  if ( m_nCurrentModFilter < 0 )
  {
    v6 = 2;
    v7 = CUtlString::CUtlString(this: &v10, pString: defaultValue);
  }
  else
  {
    v6 = 1;
    v7 = CUtlString::CUtlString(
           this: &v9,
           string: &s_AssetCache.m_ModList.m_Memory.m_pMemory[m_nCurrentModFilter].m_ModName);
  }
  v8 = CUtlString::operator char const *(this: v7);
  KeyValues::SetString(this: pUserConfig, keyName: "mod", value: v8);
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    v10.m_Storage.m_nActualLength = 0;
    if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
        v10.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v10.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
  }
  if ( (v6 & 1) != 0 )
  {
    v9.m_Storage.m_nActualLength = 0;
    if ( v9.m_Storage.m_Memory.m_nGrowSize >= 0 && v9.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004109E0
// Name: public: virtual struct CachedAssetInfo_t const __near & CBaseAssetPicker::GetCachedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const CachedAssetInfo_t *__thiscall CBaseAssetPicker::GetCachedAsset(CBaseAssetPicker *this, int nAssetIndex)
{
  return &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[nAssetIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00410A10
// Name: public: virtual int CBaseAssetPicker::GetCachedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetCachedAssetCount(CBaseAssetPicker *this)
{
  AssetList_t__ *m_hAssetList; // eax

  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    return 0;
  else
    return s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00410A40
// Name: protected: void CBaseAssetPicker::RescanAssets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::RescanAssets(CBaseAssetPicker *this)
{
  char v2; // al
  vgui::IVGui *v3; // ebx
  vgui::IVGui_vtbl *v4; // edi
  int v5; // eax

  this->m_pAssetBrowser->RemoveAll(this: this->m_pAssetBrowser);
  this->m_AssetList.m_Size = 0;
  this->BeginCacheAssets(this, a2: true);
  *((_BYTE *)this + 544) |= 2u;
  v2 = *((_BYTE *)this + 544);
  this->m_nMatchingAssets = 0;
  if ( (v2 & 4) != 0 )
  {
    *((_BYTE *)this + 544) = v2 & 0xFB;
    v3 = g_pVGui;
    v4 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v4->AddTickSignal)(a1: v3, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410AB0
// Name: public: virtual void CBaseAssetPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnCommand(CBaseAssetPicker *this, const char *pCommand)
{
  const char *v2; // esi
  KeyValues *v4; // eax
  int v5; // esi
  void *v6; // esp
  KeyValues *v7; // esi
  char v8[12]; // [esp+0h] [ebp-10h] BYREF
  KeyValues *pKeyValues; // [esp+Ch] [ebp-4h]

  v2 = pCommand;
  if ( _V_stricmp(s1: pCommand, s2: "AssetRescan") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "FindAsset") == 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        pKeyValues = KeyValues::KeyValues(this: v4, setName: "AssetPickerFind");
      else
        pKeyValues = nullptr;
      v5 = this->m_pFullPath->GetTextLength(this: this->m_pFullPath);
      v6 = alloca(v5 + 1);
      if ( v5 <= 0 )
        v8[0] = 0;
      else
        this->m_pFullPath->GetText_2(this: this->m_pFullPath, a2: v8, a3: v5 + 1);
      v7 = pKeyValues;
      KeyValues::SetString(this: pKeyValues, keyName: "asset", value: v8);
      this->PostActionSignal(this, a2: v7);
      v2 = pCommand;
    }
    vgui::Panel::OnCommand(this, command: v2);
  }
  else
  {
    CBaseAssetPicker::RescanAssets(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410B90
// Name: public: virtual class CUtlString CBaseAssetPicker::GetSelectedAssetFullPath(int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CBaseAssetPicker::GetSelectedAssetFullPath(
        CBaseAssetPicker *this,
        CUtlString *result,
        int nIndex)
{
  const char *SelectedAsset; // edi
  int Int; // eax
  int v6; // eax
  KeyValues *v7; // eax
  const char *v8; // eax
  const char *m_pAssetSubDir; // [esp-8h] [ebp-114h]
  char pBuf[260]; // [esp+8h] [ebp-104h] BYREF

  SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: nIndex - 1);
  Int = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  if ( Int != 0 )
  {
    v6 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: 0);
    v7 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v6);
    Int = KeyValues::GetInt(this: v7, keyName: "modIndex", defaultValue: 0);
  }
  m_pAssetSubDir = this->m_pAssetSubDir;
  v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[Int].m_Path);
  V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "%s\\%s\\%s", v8, m_pAssetSubDir, SelectedAsset);
  V_FixSlashes(pname: pBuf, separator: 92);
  CUtlString::CUtlString(this: result, pString: pBuf);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410C50
// Name: protected: virtual void CBaseAssetPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemSelected(CBaseAssetPicker *this, KeyValues *kv)
{
  int v3; // edi
  vgui::TextEntry_vtbl *v4; // ebx
  CUtlString *v5; // eax
  const char *v6; // eax
  _DWORD v7[4]; // [esp+4h] [ebp-10h] BYREF
  const char *pSelectedAsset; // [esp+1Ch] [ebp+8h]

  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
  {
    v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) - 1;
    pSelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: v3);
    v4 = this->m_pFullPath->__vftable;
    v5 = this->GetSelectedAssetFullPath(this, result: v7, a3: v3);
    v6 = CUtlString::operator char const *(this: v5);
    v4->SetText(this: this->m_pFullPath, a2: v6);
    v7[3] = 0;
    if ( v7[2] >= 0 && v7[0] != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v7[0]);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
    this->OnSelectedAssetPicked(this, a2: pSelectedAsset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410D20
// Name: public: virtual char const __near * CBaseAssetPicker::GetAssetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetAssetName(CBaseAssetPicker *this, int nAssetIndex)
{
  return CUtlString::operator char const *(this: &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[this->m_AssetList.m_Memory.m_pMemory[nAssetIndex].m_nAssetIndex].m_AssetName);
}

//------------------------------------------------------------------------------
// Address: 0x00410D60
// Name: public: void CUtlNTree<class CUtlString,unsigned short>::LinkChildBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CUtlString,unsigned short>::LinkChildBefore(
        CUtlNTree<CUtlString,unsigned short> *this,
        unsigned __int16 parent,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  unsigned __int16 m_Root; // dx
  unsigned __int16 i; // ax

  if ( before == 0xFFFF )
  {
    if ( parent == 0xFFFF )
      m_Root = this->m_Root;
    else
      m_Root = this->m_Memory.m_pMemory[parent].m_FirstChild;
    if ( m_Root == 0xFFFF )
    {
      CUtlNTree<CUtlString,unsigned short>::LinkChildAfter(this, parent, after: 0xFFFFu, elem);
    }
    else
    {
      for ( i = this->m_Memory.m_pMemory[m_Root].m_NextSibling; i != 0xFFFF; i = this->m_Memory.m_pMemory[i].m_NextSibling )
        m_Root = i;
      CUtlNTree<CUtlString,unsigned short>::LinkChildAfter(this, parent, after: m_Root, elem);
    }
  }
  else
  {
    CUtlNTree<CUtlString,unsigned short>::LinkChildAfter(
      this,
      parent,
      after: this->m_Memory.m_pMemory[before].m_PrevSibling,
      elem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410FB0
// Name: public: void CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411630
// Name: public: unsigned short CAssetTreeView::AddSubDirectory(unsigned short,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::AddSubDirectory(
        CAssetTreeView *this,
        unsigned __int16 hParent,
        const char *pDirName)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v4; // bx
  int v5; // edi
  CUtlString *p_m_Element; // ecx
  char *v7; // eax

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  v4 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  v5 = v4;
  p_m_Element = &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element;
  if ( p_m_Element != nullptr )
    CUtlString::CUtlString(this: p_m_Element);
  CUtlString::operator=(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element, src: pDirName);
  v7 = CUtlString::Get(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element);
  _V_strlower(start: v7);
  CUtlNTree<CUtlString,unsigned short>::LinkChildBefore(
    this: p_m_DirectoryStructure,
    parent: hParent,
    before: p_m_DirectoryStructure->m_Memory.m_pMemory[hParent].m_FirstChild,
    elem: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004116A0
// Name: public: void CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004117B0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x00411840
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x004118D0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x00411960
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x004119F0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x00411A80
// Name: protected: void CBaseAssetPicker::AddAssetToList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AddAssetToList(CBaseAssetPicker *this, int nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ebx
  unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  KeyValues *m_pInsertHelper; // esi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int v12; // esi
  const char *v13; // eax
  const char *v14; // eax
  KeyValues *v15; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBaseAssetPicker::AssetInfo_t *m_pMemory; // ecx
  int v19; // eax
  const char *v20; // [esp-4h] [ebp-1Ch]
  KeyValues *v21; // [esp+10h] [ebp-8h]
  bool bInRootDir; // [esp+17h] [ebp-1h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  v4 = (unsigned __int8 *)CUtlString::operator char const *(this: &v3->m_AssetName);
  strchr(string: v4, chr: 0x5Cu);
  if ( v5 != 0
    || (v6 = (unsigned __int8 *)CUtlString::operator char const *(this: &v3->m_AssetName),
        strchr(string: v6, chr: 0x2Fu),
        bInRootDir = true,
        v7 != 0) )
  {
    bInRootDir = false;
  }
  m_pInsertHelper = this->m_pInsertHelper;
  v9 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetName(this: m_pInsertHelper, setName: v9);
  v10 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "asset", value: v10);
  v11 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v3->m_nModIndex].m_ModName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "mod", value: v11);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "modIndex", value: v3->m_nModIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "root", value: bInRootDir);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "assetIndex", value: nAssetIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "timesused", value: v3->m_nTimesUsed);
  v12 = this->m_pAssetBrowser->AddItem(this: this->m_pAssetBrowser, a2: m_pInsertHelper, a3: 0, a4: false, a5: false);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0 )
  {
    v20 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v13 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
    if ( _V_strcmp(s1: v13, s2: v20) == 0 )
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v12, a3: 0);
  }
  v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v21 != nullptr )
  {
    v14 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v15 = KeyValues::KeyValues(this: v21, setName: "drag", firstKey: "text", firstValue: v14);
  }
  else
  {
    v15 = nullptr;
  }
  if ( this->m_pAssetTextType != nullptr )
    KeyValues::SetString(this: v15, keyName: "texttype", value: this->m_pAssetTextType);
  vgui::ListPanel::SetItemDragData(this: this->m_pAssetBrowser, itemID: v12, data: v15);
  m_Size = this->m_AssetList.m_Size;
  m_nAllocationCount = this->m_AssetList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::RanEvent_t,int>::Grow(
      this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_AssetList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_AssetList.m_Size;
  m_pMemory = this->m_AssetList.m_Memory.m_pMemory;
  v19 = this->m_AssetList.m_Size - m_Size - 1;
  this->m_AssetList.m_pElements = m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v19);
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nAssetIndex = nAssetIndex;
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nItemId = v12;
  LOBYTE(nAssetIndex) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)m_Size);
  this->m_pAssetBrowser->SetItemVisible(this: this->m_pAssetBrowser, a2: v12, a3: nAssetIndex);
  if ( (_BYTE)nAssetIndex != 0 )
    ++this->m_nMatchingAssets;
}

//------------------------------------------------------------------------------
// Address: 0x00411CC0
// Name: public: void CUtlNTree<class CUtlString,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CUtlString,unsigned short>::RemoveAll(CUtlNTree<CUtlString,unsigned short> *this)
{
  int m_MaxElementIndex; // eax
  int v2; // ebx
  __int16 v3; // di
  CUtlNTree<CUtlString,unsigned short>::Node_t *v4; // esi
  CUtlNTree<CUtlString,unsigned short> *v5; // [esp+0h] [ebp-8h]
  __int16 prev; // [esp+4h] [ebp-4h]

  m_MaxElementIndex = this->m_MaxElementIndex;
  v5 = this;
  if ( (_WORD)m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    prev = -1;
    do
    {
      v3 = v2;
      v4 = &this->m_Memory.m_pMemory[(unsigned __int16)v2];
      if ( (unsigned __int16)v2 < this->m_MaxElementIndex && v4->m_PrevSibling != (_WORD)v2 )
      {
        v4->m_Element.m_Storage.m_nActualLength = 0;
        if ( v4->m_Element.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4->m_Element.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_Storage.m_Memory.m_pMemory);
            this = v5;
            v4->m_Element.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Element.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      --v2;
      v4->m_NextSibling = prev;
      v4->m_FirstChild = -1;
      v4->m_Parent = -1;
      v4->m_PrevSibling = v3;
      prev = v3;
    }
    while ( v2 >= 0 );
    *(_DWORD *)&this->m_Root = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411D70
// Name: public: void CAssetTreeView::ClearDirectories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ClearDirectories(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v3; // ax
  int v4; // edi
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  unsigned __int16 v6; // [esp+Ch] [ebp-4h]

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  v3 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: p_m_DirectoryStructure);
  v4 = v3;
  v6 = v3;
  if ( &p_m_DirectoryStructure->m_Memory.m_pMemory[v4] != nullptr )
  {
    CUtlString::CUtlString(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v4].m_Element);
    v3 = v6;
  }
  m_pMemory = p_m_DirectoryStructure->m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v3;
  CUtlString::operator=(this: &m_pMemory[v4].m_Element, src: &this->m_RootDirectory);
}

//------------------------------------------------------------------------------
// Address: 0x00411EB0
// Name: public: unsigned short CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v4; // ecx

  v2 = (unsigned __int16)CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      CUtlString::CUtlString(this: &v4->m_Element.m_DirName);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411EF0
// Name: public: void CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  bool v2; // sf
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v4; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v6; // ax
  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *v7; // [esp+0h] [ebp-4h]

  v7 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = this->m_Memory.m_pMemory[m_Head].m_Element.m_DirName.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v4 = &this->m_Memory.m_pMemory[m_Head];
        v4->m_Element.m_DirName.m_Storage.m_nActualLength = 0;
        if ( !v2 )
        {
          if ( v4->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory);
            this = v7;
            v4->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Element.m_DirName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v4->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v4->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v6 = this->m_Head;
    if ( v6 != 0xFFFF )
      this->m_FirstFree = v6;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412050
// Name: public: CAssetTreeView::CAssetTreeView(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetTreeView *__thiscall CAssetTreeView::CAssetTreeView(
        CAssetTreeView *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pRootFolderName,
        const char *pRootDir)
{
  vgui::PanelMessageMap *v6; // esi
  PanelAnimationMap *v7; // esi
  vgui::PanelKeyBindingMap *v8; // esi
  unsigned __int16 v9; // ax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  int v11; // ebx
  bool v12; // zf
  CUtlString *p_m_Element; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *v14; // ecx
  vgui::IImage *v15; // eax
  unsigned __int16 pNamea; // [esp+18h] [ebp+Ch]

  vgui::TreeView::TreeView(this, parent: pParent, panelName: pName);
  this->__vftable = (CAssetTreeView_vtbl *)&CAssetTreeView::`vftable';
  if ( `CAssetTreeView::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
    v6->pfnClassName = CAssetTreeView::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CAssetTreeView");
    v7->pfnClassName = CAssetTreeView::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
    v8->pfnClassName = CAssetTreeView::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TreeView");
  }
  CUtlString::CUtlString(this: &this->m_RootFolderName);
  CUtlString::CUtlString(this: &this->m_RootDirectory);
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
  this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoryStructure.m_Memory.m_nGrowSize = 0;
  *(_DWORD *)&this->m_DirectoryStructure.m_Root = -1;
  *(_DWORD *)&this->m_DirectoryStructure.m_ElementCount = 0;
  this->m_DirectoryStructure.m_pElements = nullptr;
  vgui::TreeView::SetSortFunc(this, pSortFunc: AssetTreeViewSortFunc);
  CUtlString::operator=(this: &this->m_RootFolderName, src: pRootFolderName);
  CUtlString::operator=(this: &this->m_RootDirectory, src: pRootDir);
  v9 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  v11 = v9;
  v12 = &m_pMemory[v11] == nullptr;
  p_m_Element = &m_pMemory[v11].m_Element;
  pNamea = v9;
  if ( !v12 )
  {
    CUtlString::CUtlString(this: p_m_Element);
    v9 = pNamea;
  }
  v14 = this->m_DirectoryStructure.m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v9;
  CUtlString::operator=(this: &v14[v11].m_Element, src: &this->m_RootDirectory);
  v15 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "resource/icon_folder", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: (vgui::Dar<unsigned long> *)&this->m_Images, elem: (unsigned int)v15);
  vgui::TreeView::SetImageList(this, imageList: &this->m_Images, deleteImageListWhenDone: false);
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412200
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetTreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetTreeView::GetMessageMap(CAssetTreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetTreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetMessageMap'::`2'::s_pMap;
  `CAssetTreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
  `CAssetTreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412230
// Name: public: virtual struct PanelAnimationMap __near * CAssetTreeView::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetTreeView::GetAnimMap(CAssetTreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetTreeView");
}

//------------------------------------------------------------------------------
// Address: 0x00412240
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetTreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetTreeView::GetKBMap(CAssetTreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetTreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetKBMap'::`2'::s_pMap;
  `CAssetTreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
  `CAssetTreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412270
// Name: public: virtual CAssetTreeView::~CAssetTreeView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::~CAssetTreeView(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  if ( this->m_DirectoryStructure.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoryStructure.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoryStructure.m_Memory.m_pMemory);
      this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  }
  vgui::ImageList::~ImageList(this: &this->m_Images);
  this->m_RootDirectory.m_Storage.m_nActualLength = 0;
  if ( this->m_RootDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootDirectory.m_Storage.m_Memory.m_pMemory);
      this->m_RootDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RootFolderName.m_Storage.m_nActualLength = 0;
  if ( this->m_RootFolderName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootFolderName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootFolderName.m_Storage.m_Memory.m_pMemory);
      this->m_RootFolderName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootFolderName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::TreeView::~TreeView(this);
}

//------------------------------------------------------------------------------
// Address: 0x00412330
// Name: public: void CAssetCache::BuildModList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::BuildModList(CAssetCache *this, const char *pSearchPathName)
{
  int v3; // edi
  void *v4; // esp
  unsigned __int8 *v5; // ebx
  char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CacheModInfo_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // edi
  _BYTE v12[12]; // [esp+0h] [ebp-114h] BYREF
  char pModName[260]; // [esp+Ch] [ebp-108h] BYREF
  char *pSemiColon; // [esp+110h] [ebp-4h]
  CacheModInfo_t *pSearchPathNamea; // [esp+11Ch] [ebp+8h]

  if ( !this->m_bBuiltModList )
  {
    this->m_pAssetSearchPath = pSearchPathName;
    this->m_bBuiltModList = true;
    CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::RemoveAll(this: &this->m_ModList);
    v3 = g_pFullFileSystem->GetSearchPath(
           this: g_pFullFileSystem,
           a2: this->m_pAssetSearchPath,
           a3: false,
           a4: nullptr,
           a5: 0);
    v4 = alloca(v3);
    v5 = v12;
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: this->m_pAssetSearchPath, a3: false, a4: v12, a5: v3);
    if ( v12 != nullptr )
    {
      do
      {
        strchr(string: v5, chr: 0x3Bu);
        pSemiColon = v6;
        if ( v6 != nullptr )
          *v6 = 0;
        V_StripTrailingSlash(ppath: (char *)v5);
        V_FixSlashes(pname: (char *)v5, separator: 92);
        V_FileBase(in: (const char *)v5, out: pModName, maxlen: 260);
        m_Size = this->m_ModList.m_Size;
        m_nAllocationCount = this->m_ModList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(
            (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_ModList.m_Size;
        m_pMemory = this->m_ModList.m_Memory.m_pMemory;
        v10 = this->m_ModList.m_Size - m_Size - 1;
        this->m_ModList.m_pElements = this->m_ModList.m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v10);
        v11 = m_Size;
        pSearchPathNamea = &this->m_ModList.m_Memory.m_pMemory[v11];
        if ( pSearchPathNamea != nullptr )
        {
          CUtlString::CUtlString(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName);
          CUtlString::CUtlString(this: &pSearchPathNamea->m_Path);
        }
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName, pValue: pModName);
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_Path, pValue: (const char *)v5);
        if ( pSemiColon == nullptr )
          break;
        v5 = (unsigned __int8 *)(pSemiColon + 1);
      }
      while ( pSemiColon != (char *)-1 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412470
// Name: private: bool CAssetCache::AddFilesInDirectory(struct CAssetCache::CachedAssetList_t __near &,char const __near *,char const __near *,unsigned short,float,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::AddFilesInDirectory(
        CAssetCache *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *list,
        char *pStartingFile,
        const char *pFilePath,
        unsigned __int16 hCurrentDir,
        float flStartTime,
        float flDuration)
{
  bool v8; // zf
  CAssetCache *v9; // ebx
  const char *v11; // eax
  char *v12; // edi
  int v13; // eax
  const char *v14; // eax
  int v15; // edi
  int v16; // edi
  CacheModInfo_t *v17; // ebx
  const char *v18; // eax
  char *v19; // edi
  const char *v20; // eax
  int AssetUsageCount; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CachedAssetInfo_t *v24; // ecx
  int v25; // eax
  CachedAssetInfo_t *v26; // ecx
  CachedAssetInfo_t *v27; // edi
  int v28; // eax
  int v29; // [esp-8h] [ebp-228h]
  int v30; // [esp-8h] [ebp-228h]
  char pFullAssetPath[260]; // [esp+8h] [ebp-218h] BYREF
  char pRelativeChildPath[260]; // [esp+10Ch] [ebp-114h] BYREF
  int nTimesUsed; // [esp+210h] [ebp-10h]
  int nModCount; // [esp+214h] [ebp-Ch]
  CAssetCache *v35; // [esp+218h] [ebp-8h]
  int nSubDirLen; // [esp+21Ch] [ebp-4h]
  unsigned __int16 ia; // [esp+228h] [ebp+8h]
  int i; // [esp+228h] [ebp+8h]
  const char *pAssetName; // [esp+22Ch] [ebp+Ch]

  v8 = list[7].m_nAllocationCount == -1;
  v9 = this;
  v35 = this;
  if ( v8 )
    return 1;
  nModCount = this->m_ModList.m_Size;
  if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
  {
    v11 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
    nSubDirLen = _V_strlen(str: v11);
  }
  else
  {
    nSubDirLen = 0;
  }
  v12 = pStartingFile;
  if ( pStartingFile == nullptr )
    return 1;
  while ( 1 )
  {
    V_snprintf(pDest: pRelativeChildPath, maxLen: 260, pFormat: "%s\\%s", pFilePath, v12);
    if ( !g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount) )
      break;
    strstr(str1: (unsigned __int8 *)v12, str2: ".svn");
    if ( v13 == 0 )
    {
      if ( V_strnicmp(s1: v12, s2: ".", n: 2) != 0 && V_strnicmp(s1: v12, s2: "..", n: 3) != 0 )
      {
        ia = CAssetTreeView::AddSubDirectory(
               this: (CAssetTreeView *)list[1].m_nGrowSize,
               hParent: hCurrentDir,
               pDirName: v12);
        v15 = (unsigned __int16)CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(this: (CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *)&list[5]);
        CUtlString::operator=(this: (CUtlString *)&list[5].m_pMemory[v15], src: pRelativeChildPath);
        LOWORD(list[5].m_pMemory[v15].m_Data.key) = ia;
      }
      goto LABEL_30;
    }
    v14 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
LABEL_32:
    v12 = (char *)v14;
    if ( v14 == nullptr )
      return 1;
  }
  if ( CAssetCache::DoesExtensionMatch(this: v9, info: (CAssetCache::CachedAssetList_t *)list, pFileName: v12) != 0 )
  {
    v16 = 0;
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: pRelativeChildPath,
      a3: v9->m_pAssetSearchPath,
      a4: pFullAssetPath,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    i = 0;
    if ( nModCount > 0 )
    {
      while ( 1 )
      {
        v17 = &v35->m_ModList.m_Memory.m_pMemory[v16];
        v29 = CUtlString::Length(this: &v17->m_Path);
        v18 = CUtlString::operator char const *(this: &v17->m_Path);
        if ( V_strnicmp(s1: pFullAssetPath, s2: v18, n: v29) == 0 )
          break;
        ++v16;
        if ( ++i >= nModCount )
          goto LABEL_30;
      }
      if ( i >= 0 )
      {
        v19 = pRelativeChildPath;
        pAssetName = pRelativeChildPath;
        if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
        {
          v30 = nSubDirLen;
          v20 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
          if ( V_strnicmp(s1: v20, s2: pRelativeChildPath, n: v30) == 0 && pRelativeChildPath[nSubDirLen] == 92 )
          {
            pAssetName = &pRelativeChildPath[nSubDirLen + 1];
            v19 = &pRelativeChildPath[nSubDirLen + 1];
          }
        }
        strlwr(string: v19);
        AssetUsageCount = CAssetCache::GetAssetUsageCount(this: v35, assetName: v19);
        m_pMemory = (int)list[1].m_pMemory;
        nTimesUsed = AssetUsageCount;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CachedAssetInfo_t,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v24 = (CachedAssetInfo_t *)list->m_pMemory;
        v25 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v25 > 0 )
          _V_memmove(dest: (void *)&v24[m_pMemory + 1], src: &v24[m_pMemory], count: 24 * v25);
        v26 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        if ( v26 != nullptr )
          CUtlString::CUtlString(this: &v26->m_AssetName);
        v27 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        CUtlString::Set(this: &v27->m_AssetName, pValue: pAssetName);
        v28 = nTimesUsed;
        v27->m_nModIndex = i;
        v27->m_nTimesUsed = v28;
      }
    }
  }
LABEL_30:
  if ( _Plat_FloatTime() - flStartTime < flDuration )
  {
    v14 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
    v9 = v35;
    goto LABEL_32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412760
// Name: public: bool CAssetCache::BeginAssetScan(struct AssetList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::BeginAssetScan(CAssetCache *this, AssetList_t__ *hList, bool bForceRescan)
{
  int v3; // eax
  CAssetCache::CachedAssetList_t *p_m_Data; // esi
  int m_hFind; // eax
  unsigned __int16 v7; // ax
  int v8; // ebx
  unsigned __int16 v9; // ax
  CUtlString *p_m_DirName; // ecx
  int v11; // ebx

  v3 = (unsigned __int16)hList;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data;
  if ( bForceRescan )
  {
    m_hFind = this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data.m_hFind;
    p_m_Data->m_bAssetScanComplete = false;
    if ( m_hFind != -1 )
    {
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: m_hFind);
      p_m_Data->m_hFind = -1;
    }
    CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_Data->m_DirectoriesToCheck);
  }
  if ( p_m_Data->m_bAssetScanComplete )
    return 1;
  if ( p_m_Data->m_hFind == -1 )
  {
    CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>::RemoveAll(this: &p_m_Data->m_AssetList);
    CAssetTreeView::ClearDirectories(this: p_m_Data->m_pFileTree);
    v7 = CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &p_m_Data->m_DirectoriesToCheck,
           multilist: false);
    v8 = v7;
    if ( v7 == 0xFFFF )
    {
      v9 = -1;
    }
    else
    {
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &p_m_Data->m_DirectoriesToCheck,
        before: 0xFFFFu,
        elem: v7);
      p_m_DirName = &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v8].m_Element.m_DirName;
      if ( p_m_DirName != nullptr )
        CUtlString::CUtlString(this: p_m_DirName);
      v9 = v8;
    }
    v11 = v9;
    CUtlString::operator=(
      this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_DirName,
      src: &p_m_Data->m_pSubDir);
    p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_hDirHandle = p_m_Data->m_pFileTree->m_DirectoryStructure.m_Root;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412840
// Name: public: virtual bool CBaseAssetPicker::BeginCacheAssets(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAssetPicker::BeginCacheAssets(CBaseAssetPicker *this, bool bForceRecache)
{
  return CAssetCache::BeginAssetScan(this: &s_AssetCache, hList: this->m_hAssetList, bForceRescan: bForceRecache);
}

//------------------------------------------------------------------------------
// Address: 0x00412860
// Name: protected: void CBaseAssetPicker::BuildAssetNameList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::BuildAssetNameList(CBaseAssetPicker *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  int v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int v7; // edi
  KeyValues *v8; // eax
  const KeyValues *v9; // eax
  bool v10; // zf
  char v11; // al
  CBaseAssetPicker_vtbl *v12; // edx
  vgui::IVGui *v13; // ebx
  vgui::IVGui_vtbl *v14; // edi
  int v15; // eax
  int v16; // ebx
  int i; // edi
  const char *m_pAssetSearchPath; // [esp-8h] [ebp-14h]
  int nModCount; // [esp+4h] [ebp-8h]
  const char *pModName; // [esp+8h] [ebp-4h]

  v3 = *((_BYTE *)this + 544);
  if ( (v3 & 1) == 0 )
  {
    *((_BYTE *)this + 544) = v3 | 1;
    v4 = 0;
    m_pAssetSearchPath = this->m_pAssetSearchPath;
    this->m_nMatchingAssets = 0;
    this->m_nCurrentModFilter = -1;
    CAssetCache::BuildModList(this: &s_AssetCache, pSearchPathName: m_pAssetSearchPath);
    vgui::ComboBox::RemoveAll(this: this->m_pModSelector);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "Mod", firstKey: "mod", firstValue: -1);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::ComboBox *, const char *, KeyValues *, int))this->m_pModSelector->AddItem_2)(
      a1: this->m_pModSelector,
      a2: "All Mods",
      a3: v6,
      a4: a2);
    v7 = 0;
    for ( nModCount = s_AssetCache.m_ModList.m_Size; v7 < nModCount; ++v4 )
    {
      pModName = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v4].m_ModName);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "Mod", firstKey: "mod", firstValue: v7);
      else
        v9 = nullptr;
      this->m_pModSelector->AddItem_2(this: this->m_pModSelector, a2: pModName, a3: v9);
      ++v7;
    }
    vgui::ComboBox::ActivateItemByRow(this: this->m_pModSelector, row: 0);
    v10 = !this->BeginCacheAssets(this, a2: false);
    v11 = *((_BYTE *)this + 544);
    if ( v10 )
    {
      v12 = this->__vftable;
      *((_BYTE *)this + 544) = v11 & 0xF9 | 2;
      v13 = g_pVGui;
      v14 = g_pVGui->__vftable;
      v15 = ((int (__thiscall *)(CBaseAssetPicker *, int))v12->GetVPanel)(a1: this, a2: 10);
      ((void (__thiscall *)(vgui::IVGui *, int))v14->AddTickSignal)(a1: v13, a2: v15);
    }
    else
    {
      *((_BYTE *)this + 544) = v11 & 0xF9 | 4;
    }
    v16 = this->GetCachedAssetCount(this);
    for ( i = 0; i < v16; ++i )
      CBaseAssetPicker::AddAssetToList(this, nAssetIndex: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004129E0
// Name: protected: void CBaseAssetPicker::RefreshAssetList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::RefreshAssetList(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // eax
  int v5; // edi
  const CachedAssetInfo_t *v6; // eax
  vgui::ListPanel *m_pAssetBrowser; // ecx
  vgui::ListPanelItem *(__thiscall *GetItemData)(vgui::ListPanel *, int); // edx
  int v9; // ebx
  vgui::ListPanelItem *v10; // eax
  KeyValues *kv; // ecx
  const char *v12; // eax
  int v13; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v15; // eax
  char pDest[512]; // [esp+8h] [ebp-210h] BYREF
  const CachedAssetInfo_t *info; // [esp+208h] [ebp-10h]
  int nCount; // [esp+20Ch] [ebp-Ch]
  vgui::ListPanelItem *pItem; // [esp+210h] [ebp-8h]
  int bIsVisible; // [esp+214h] [ebp-4h]

  CBaseAssetPicker::BuildAssetNameList(this, a2: a3);
  v5 = 0;
  nCount = this->m_AssetList.m_Size;
  v4 = nCount;
  this->m_nMatchingAssets = 0;
  if ( v4 > 0 )
  {
    do
    {
      LOBYTE(bIsVisible) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)v5);
      v6 = (const CachedAssetInfo_t *)((int (__thiscall *)(CBaseAssetPicker *, int, int))this->GetCachedAsset)(
                                        a1: this,
                                        a2: v5,
                                        a3: a2);
      m_pAssetBrowser = this->m_pAssetBrowser;
      GetItemData = m_pAssetBrowser->GetItemData;
      info = v6;
      v9 = v5;
      v10 = GetItemData(this: m_pAssetBrowser, a2: this->m_AssetList.m_Memory.m_pMemory[v5].m_nItemId);
      kv = v10->kv;
      pItem = v10;
      if ( KeyValues::GetInt(this: kv, keyName: "timesused", defaultValue: 0) != info->m_nTimesUsed )
      {
        KeyValues::SetInt(this: pItem->kv, keyName: "timesused", value: info->m_nTimesUsed);
        this->m_pAssetBrowser->ApplyItemChanges(
          this: this->m_pAssetBrowser,
          a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      }
      a2 = bIsVisible;
      ((void (__thiscall *)(vgui::ListPanel *, int))this->m_pAssetBrowser->SetItemVisible)(
        a1: this->m_pAssetBrowser,
        a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      if ( (_BYTE)bIsVisible != 0 )
        ++this->m_nMatchingAssets;
      ++v5;
    }
    while ( v5 < nCount );
  }
  v12 = defaultValue;
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
    v12 = " ...";
  V_snprintf(
    pDest,
    maxLen: 512,
    pFormat: "%s (%d/%d)%s",
    this->m_pAssetType,
    this->m_nMatchingAssets,
    this->m_AssetList.m_Size,
    v12);
  this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: pDest);
  this->m_pAssetBrowser->SortList(this: this->m_pAssetBrowser);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0
    && this->m_pAssetBrowser->GetItemCount(this: this->m_pAssetBrowser) > 0 )
  {
    this->OnNextSelectionIsDefault(this);
    v13 = this->m_pAssetBrowser->GetItemIDFromRow(this: this->m_pAssetBrowser, a2: 0);
    this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v13, a3: 0);
  }
  m_pFileTree = this->m_pFileTree;
  v15 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
  CAssetTreeView::RefreshTreeViewItem(this: m_pFileTree, nItemIndex: v15);
  m_pFileTree->InvalidateLayout(this: m_pFileTree, a2: false, a3: false);
  this->OnAssetListChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x00412BD0
// Name: protected: virtual void CBaseAssetPicker::OnFileSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::OnFileSelected(CBaseAssetPicker *this@<ecx>, int a2@<ebx>)
{
  const char *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  const char *String; // esi
  const char *v7; // eax
  int nLen; // [esp+Ch] [ebp-4h]

  v3 = defaultValue;
  v4 = this->m_pFileTree->GetFirstSelectedItem(this: this->m_pFileTree);
  if ( v4 >= 0 )
  {
    v5 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: v4);
    String = KeyValues::GetString(this: v5, keyName: "path", defaultValue: defaultValue);
    v3 = &String[_V_strlen(str: this->m_pAssetSubDir)];
    if ( *v3 != 0 )
      ++v3;
  }
  v7 = CUtlString::Get(this: &this->m_FolderFilter);
  if ( _V_stricmp(s1: v3, s2: v7) != 0 )
  {
    nLen = _V_strlen(str: v3);
    CUtlString::operator=(this: &this->m_FolderFilter, src: v3);
    if ( nLen > 0 )
      CUtlString::operator+=(this: &this->m_FolderFilter, c: 92);
    CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412C80
// Name: protected: virtual void CBaseAssetPicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnTextChanged(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *pKeyValues)
{
  vgui::ComboBox *Ptr; // eax
  vgui::TextEntry *m_pFilter; // ecx
  int v7; // edi
  void *v8; // esp
  const char *v9; // eax
  vgui::ComboBox *m_pModSelector; // ecx
  KeyValues *ActiveItemUserData; // eax
  char v12[12]; // [esp+0h] [ebp-Ch] BYREF

  Ptr = (vgui::ComboBox *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  m_pFilter = this->m_pFilter;
  if ( Ptr == m_pFilter )
  {
    v7 = m_pFilter->GetTextLength(this: m_pFilter);
    v8 = alloca(v7 + 1);
    if ( v7 <= 0 )
      v12[0] = 0;
    else
      this->m_pFilter->GetText_2(this: this->m_pFilter, a2: v12, a3: v7 + 1);
    v9 = CUtlString::Get(this: &this->m_Filter);
    if ( _V_stricmp(s1: v12, s2: v9) != 0 )
    {
      CUtlString::SetLength(this: &this->m_Filter, nLen: v7);
      CUtlString::operator=(this: &this->m_Filter, src: v12);
      CBaseAssetPicker::RefreshAssetList(this, a2: (int)v12, a3: v7);
    }
  }
  else
  {
    m_pModSelector = this->m_pModSelector;
    if ( Ptr == m_pModSelector )
    {
      ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: m_pModSelector);
      if ( ActiveItemUserData != nullptr )
      {
        this->m_nCurrentModFilter = KeyValues::GetInt(this: ActiveItemUserData, keyName: "mod", defaultValue: -1);
        CBaseAssetPicker::RefreshAssetList(this, a2, a3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412D60
// Name: protected: virtual void CBaseAssetPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnCheckButtonChecked(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *kv)
{
  vgui::CheckButton *Ptr; // eax
  vgui::CheckButton *m_pSubDirCheck; // ecx
  vgui::CheckButton *m_pOnlyUsedCheck; // ecx

  Ptr = (vgui::CheckButton *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSubDirCheck = this->m_pSubDirCheck;
  if ( Ptr == m_pSubDirCheck )
  {
    *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                             ^ (8
                              * ((int (__thiscall *)(vgui::CheckButton *))m_pSubDirCheck->IsSelected)(a1: m_pSubDirCheck)))
                            & 8;
    CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  }
  else
  {
    m_pOnlyUsedCheck = this->m_pOnlyUsedCheck;
    if ( Ptr == m_pOnlyUsedCheck )
    {
      *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                               ^ (16
                                * ((int (__thiscall *)(vgui::CheckButton *))m_pOnlyUsedCheck->IsSelected)(a1: m_pOnlyUsedCheck)))
                              & 0x10;
      CBaseAssetPicker::RefreshAssetList(this, a2, a3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412F30
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412F90
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const char *pSearchSubDir,
        int nExtCount,
        const char **ppSearchExt)
{
  int v5; // eax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // eax

  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  v5 = _V_strlen(str: pSearchSubDir);
  CUtlString::CUtlString(this: &this->m_pSubDir, pMemory: pSearchSubDir, nSizeInBytes: v5 + 1);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  this->m_DirectoriesToCheck.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
    this: &this->m_Ext,
    elem: this->m_Ext.m_Size,
    num: nExtCount,
    pToInsert: ppSearchExt);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413020
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const CAssetCache::CachedAssetList_t *__formal)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413080
// Name: public: bool CAssetCache::ContinueSearchForAssets(struct AssetList_t__ __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::ContinueSearchForAssets(CAssetCache *this, AssetList_t__ *hList, float flDuration)
{
  CAssetCache::CachedAssetList_t *p_m_Data; // ebx
  const char *v4; // eax
  int m_hDirHandle; // ecx
  int m_hFind; // edx
  int *p_m_hFind; // esi
  char *v8; // eax
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  bool v11; // sf
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v12; // esi
  unsigned __int16 v13; // dx
  char pSearchString[260]; // [esp+18h] [ebp-110h] BYREF
  int hCurrentDir; // [esp+11Ch] [ebp-Ch]
  CAssetCache *v17; // [esp+120h] [ebp-8h]
  const char *pFilePath; // [esp+124h] [ebp-4h]
  float flStartTime; // [esp+130h] [ebp+8h]

  v17 = this;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)hList].m_Data;
  flStartTime = _Plat_FloatTime();
  if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount != 0 )
  {
    while ( 1 )
    {
      v4 = CUtlString::operator char const *(this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_DirName);
      m_hDirHandle = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_hDirHandle;
      m_hFind = p_m_Data->m_hFind;
      p_m_hFind = &p_m_Data->m_hFind;
      pFilePath = v4;
      hCurrentDir = m_hDirHandle;
      if ( m_hFind == -1 )
      {
        V_snprintf(pDest: pSearchString, maxLen: 260, pFormat: "%s\\*", v4);
        v8 = (char *)g_pFullFileSystem->FindFirstEx(
                       this: g_pFullFileSystem,
                       a2: pSearchString,
                       a3: v17->m_pAssetSearchPath,
                       a4: &p_m_Data->m_hFind);
      }
      else
      {
        v8 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: m_hFind);
      }
      if ( CAssetCache::AddFilesInDirectory(
             this: v17,
             list: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)p_m_Data,
             pStartingFile: v8,
             pFilePath,
             hCurrentDir,
             flStartTime,
             flDuration) == 0 )
        return 0;
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: *p_m_hFind);
      *p_m_hFind = -1;
      m_Head = p_m_Data->m_DirectoriesToCheck.m_Head;
      pFilePath = (const char *)m_Head;
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
        this: &p_m_Data->m_DirectoriesToCheck,
        elem: m_Head);
      m_pMemory = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory;
      v11 = m_pMemory[m_Head].m_Element.m_DirName.m_Storage.m_Memory.m_nGrowSize < 0;
      v12 = &m_pMemory[m_Head];
      v12->m_Element.m_DirName.m_Storage.m_nActualLength = 0;
      if ( !v11 )
      {
        if ( v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory);
          v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v12->m_Element.m_DirName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v13 = (unsigned __int16)pFilePath;
      v12->m_Next = p_m_Data->m_DirectoriesToCheck.m_FirstFree;
      p_m_Data->m_DirectoriesToCheck.m_FirstFree = v13;
      if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount == 0 )
        goto LABEL_11;
    }
  }
  else
  {
LABEL_11:
    p_m_Data->m_bAssetScanComplete = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413200
// Name: public: CAssetCache::CachedAssetList_t::~CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::CachedAssetList_t::~CachedAssetList_t(CAssetCache::CachedAssetList_t *this)
{
  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirectoriesToCheck);
  if ( this->m_DirectoriesToCheck.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoriesToCheck.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoriesToCheck.m_Memory.m_pMemory);
      this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Ext);
  this->m_pSubDir.m_Storage.m_nActualLength = 0;
  if ( this->m_pSubDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pSubDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSubDir.m_Storage.m_Memory.m_pMemory);
      this->m_pSubDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pSubDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>::~CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>(this: &this->m_AssetList);
}

//------------------------------------------------------------------------------
// Address: 0x00413270
// Name: public: CBaseAssetPicker::CBaseAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPicker *__thiscall CBaseAssetPicker::CBaseAssetPicker(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType,
        const char *pAssetSearchPath)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  char v11; // al
  KeyValues *v12; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "AssetPicker");
  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  if ( `CBaseAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    v8->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
    v9->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
    v10->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FolderFilter);
  CUtlString::CUtlString(this: &this->m_Filter);
  CUtlString::CUtlString(this: &this->m_SelectedAsset);
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_pMemory = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_nAllocationCount = 0;
  this->m_ExtraAssetExt.m_Memory.m_nGrowSize = 0;
  this->m_ExtraAssetExt.m_Size = 0;
  this->m_ExtraAssetExt.m_pElements = nullptr;
  this->m_usedAssets.m_Memory.m_pMemory = nullptr;
  this->m_usedAssets.m_Memory.m_nAllocationCount = 0;
  this->m_usedAssets.m_Memory.m_nGrowSize = 0;
  this->m_usedAssets.m_Size = 0;
  this->m_usedAssets.m_pElements = nullptr;
  this->m_pAssetExt = pExt;
  v11 = *((_BYTE *)this + 544) & 0xE8;
  this->m_pAssetType = pAssetType;
  this->m_pAssetTextType = pTextType;
  this->m_pAssetSubDir = pSubDir;
  this->m_pAssetSearchPath = pAssetSearchPath;
  this->m_nMatchingAssets = 0;
  *((_BYTE *)this + 544) = v11 | 8;
  this->m_hAssetList = (AssetList_t__ *)0xFFFF;
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    this->m_pInsertHelper = KeyValues::KeyValues(this: v12, setName: "node");
  else
    this->m_pInsertHelper = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413440
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPicker::GetMessageMap(CBaseAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413470
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPicker::GetAnimMap(CBaseAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x00413480
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPicker::GetKBMap(CBaseAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004134B0
// Name: public: virtual CBaseAssetPicker::~CBaseAssetPicker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::~CBaseAssetPicker(CBaseAssetPicker *this)
{
  KeyValues *m_pInsertHelper; // ecx

  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  this->m_pFileTree->RemoveActionSignalTarget(this: this->m_pFileTree, a2: this);
  this->m_pFileTree->SetParent_2(this: this->m_pFileTree, a2: nullptr);
  m_pInsertHelper = this->m_pInsertHelper;
  this->m_pFileTree = nullptr;
  if ( m_pInsertHelper != nullptr )
    KeyValues::deleteThis(this: m_pInsertHelper);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &this->m_usedAssets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ExtraAssetExt);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_AssetList);
  this->m_SelectedAsset.m_Storage.m_nActualLength = 0;
  if ( this->m_SelectedAsset.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory);
      this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SelectedAsset.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Filter.m_Storage.m_nActualLength = 0;
  if ( this->m_Filter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Filter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Filter.m_Storage.m_Memory.m_pMemory);
      this->m_Filter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Filter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FolderFilter.m_Storage.m_nActualLength = 0;
  if ( this->m_FolderFilter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FolderFilter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FolderFilter.m_Storage.m_Memory.m_pMemory);
      this->m_FolderFilter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FolderFilter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004135C0
// Name: public: virtual void CBaseAssetPicker::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::ApplyUserConfigSettings(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pUserConfig)
{
  const char *String; // ebx
  const char *v5; // eax
  const char *v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int v9; // ebx
  int ItemIDFromRow; // edi
  KeyValues *ItemUserData; // eax
  int nItemCount; // [esp+Ch] [ebp-4h]
  int nItemCounta; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig: pUserConfig);
  CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)pUserConfig);
  String = KeyValues::GetString(this: pUserConfig, keyName: "filter", defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: pUserConfig, keyName: "folderfilter", defaultValue: defaultValue);
  CUtlString::operator=(this: &this->m_FolderFilter, src: v5);
  v6 = KeyValues::GetString(this: pUserConfig, keyName: "mod", defaultValue: defaultValue);
  CUtlString::operator=(this: &this->m_Filter, src: String);
  this->m_pFilter->SetText(this: this->m_pFilter, a2: String);
  v7 = 0;
  this->m_nCurrentModFilter = -1;
  if ( v6 != nullptr && *v6 != 0 )
  {
    nItemCount = s_AssetCache.m_ModList.m_Size;
    i = 0;
    if ( s_AssetCache.m_ModList.m_Size > 0 )
    {
      while ( 1 )
      {
        v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v7].m_ModName);
        if ( _V_stricmp(s1: v6, s2: v8) == 0 )
          break;
        ++v7;
        if ( ++i >= nItemCount )
          return;
      }
      v9 = 0;
      nItemCounta = this->m_pModSelector->GetItemCount(this: this->m_pModSelector);
      if ( nItemCounta > 0 )
      {
        while ( 1 )
        {
          ItemIDFromRow = vgui::ComboBox::GetItemIDFromRow(this: this->m_pModSelector, row: v9);
          ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pModSelector, itemID: ItemIDFromRow);
          if ( KeyValues::GetInt(this: ItemUserData, keyName: "mod", defaultValue: 0) == i )
            break;
          if ( ++v9 >= nItemCounta )
            return;
        }
        this->m_nCurrentModFilter = i;
        this->m_pModSelector->ActivateItem(this: this->m_pModSelector, a2: ItemIDFromRow);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413720
// Name: public: virtual void CBaseAssetPicker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::Activate(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax

  CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pFilter, status: true);
  this->m_pFilter->RequestFocus(this: this->m_pFilter, a2: 0);
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
  {
    v4 = g_pVGui;
    v5 = g_pVGui->__vftable;
    v6 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v5->AddTickSignal)(a1: v4, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413780
// Name: public: virtual bool CBaseAssetPicker::IncrementalCacheAssets(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAssetPicker::IncrementalCacheAssets(CBaseAssetPicker *this, float flTimeAllowed)
{
  char v3; // bl

  v3 = CAssetCache::ContinueSearchForAssets(this: &s_AssetCache, hList: this->m_hAssetList, flDuration: flTimeAllowed);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    CAssetTreeView::OpenRoot(this: this->m_pFileTree);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004137D0
// Name: public: virtual void CBaseAssetPicker::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnTick(CBaseAssetPicker *this)
{
  int v2; // edi
  int v3; // xmm0_4
  char v4; // al
  int i; // ebx
  vgui::IVGui *v6; // ebx
  vgui::IVGui_vtbl *v7; // edi
  int v8; // eax
  const char *v9; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v11; // eax
  const char *v12; // eax
  char v13[252]; // [esp+10h] [ebp-204h] BYREF
  char pDest[263]; // [esp+10Ch] [ebp-108h] BYREF
  char v15; // [esp+213h] [ebp-1h]

  CSteamApplication::PostShutdown((vgui::PropertyPage *)this);
  v2 = this->GetCachedAssetCount(this);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    v3 = 1048576000;
  else
    v3 = 1020054733;
  v4 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->IncrementalCacheAssets)(a1: this, a2: v3);
  *((_BYTE *)this + 544) &= ~2u;
  v15 = v4;
  for ( i = this->GetCachedAssetCount(this); v2 < i; ++v2 )
    CBaseAssetPicker::AddAssetToList(this, nAssetIndex: v2);
  if ( v15 != 0 )
  {
    v6 = g_pVGui;
    v7 = g_pVGui->__vftable;
    v8 = this->GetVPanel(this);
    v7->RemoveTickSignal(this: v6, a2: v8);
    *((_BYTE *)this + 544) |= 4u;
    v9 = CUtlString::operator char const *(this: &this->m_FolderFilter);
    m_pFileTree = this->m_pFileTree;
    V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", this->m_pAssetSubDir, v9);
    V_StripTrailingSlash(ppath: pDest);
    v11 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
    CAssetTreeView::SelectFolder_R(this: m_pFileTree, nItemID: v11, pPath: pDest);
    CBaseAssetPicker::RefreshAssetList(this, a2: (int)v6, a3: (int)m_pFileTree);
  }
  else
  {
    v12 = defaultValue;
    if ( (*((_BYTE *)this + 544) & 4) == 0 )
      v12 = " ...";
    V_snprintf(
      pDest: v13,
      maxLen: 512,
      pFormat: "%s (%d/%d)%s",
      this->m_pAssetType,
      this->m_nMatchingAssets,
      this->m_AssetList.m_Size,
      v12);
    this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413BA0
// Name: public: struct AssetList_t__ __near * CAssetCache::FindAssetList(char const __near *,char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
AssetList_t__ *__thiscall CAssetCache::FindAssetList(
        CAssetCache *this,
        const char *pAssetType,
        const char *pSubDir,
        int nExtCount,
        const char **ppExt)
{
  int v6; // edi
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // eax
  int p_m_Data; // esi
  CAssetTreeView *v9; // eax
  CAssetTreeView *v10; // eax
  CAssetCache::CachedAssetList_t search; // [esp+Ch] [ebp-60h] BYREF

  CAssetCache::CachedAssetList_t::CachedAssetList_t(
    this: &search,
    pSearchSubDir: pSubDir,
    nExtCount,
    ppSearchExt: ppExt);
  v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_CachedAssets,
         &search);
  if ( v6 == 0xFFFF )
  {
    v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_CachedAssets,
           insert: &search);
    m_pMemory = this->m_CachedAssets.m_Elements.m_pMemory;
    p_m_Data = (int)&m_pMemory[v6].m_Data;
    CUtlString::operator=(this: &m_pMemory[v6].m_Data.m_pSubDir, src: pSubDir);
    CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
      this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)(p_m_Data + 40),
      elem: *(_DWORD *)(p_m_Data + 52),
      num: nExtCount,
      pToInsert: ppExt);
    *(_DWORD *)(p_m_Data + 88) = -1;
    *(_BYTE *)(p_m_Data + 92) = 0;
    v9 = (CAssetTreeView *)operator new(nSize: 0x210u);
    if ( v9 != nullptr )
      v10 = CAssetTreeView::CAssetTreeView(
              this: v9,
              pParent: nullptr,
              pName: "FolderFilter",
              pRootFolderName: pAssetType,
              pRootDir: pSubDir);
    else
      v10 = nullptr;
    *(_DWORD *)(p_m_Data + 20) = v10;
  }
  CAssetCache::CachedAssetList_t::~CachedAssetList_t(this: &search);
  return (AssetList_t__ *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x00413C60
// Name: protected: void CBaseAssetPicker::CreateStandardControls(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::CreateStandardControls(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        bool bAllowMultiselect)
{
  int v4; // edi
  void *v5; // esp
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v9; // ebx
  vgui::ComboBox *v10; // eax
  vgui::ComboBox *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  AssetList_t__ *m_hAssetList; // eax
  CAssetTreeView *m_pFileTree; // ecx
  vgui::CheckButton *v16; // eax
  vgui::CheckButton *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::ListPanel *v19; // eax
  vgui::Panel *v20; // edi
  vgui::TextEntry *v21; // eax
  vgui::TextEntry *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  BOOL v25; // ecx
  vgui::TextEntry *v26; // eax
  vgui::TextEntry *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  const char *m_pAssetExt; // [esp+0h] [ebp-20Ch] BYREF
  unsigned __int8 v31[8]; // [esp+4h] [ebp-208h] BYREF
  char pDest[512]; // [esp+Ch] [ebp-200h] BYREF

  v4 = this->m_ExtraAssetExt.m_Size + 1;
  v5 = alloca(4 * v4);
  m_pAssetExt = this->m_pAssetExt;
  if ( v4 > 1 )
    memcpy(dst: v31, src: (unsigned __int8 *)this->m_ExtraAssetExt.m_Memory.m_pMemory, count: v4 - 1);
  this->m_hAssetList = CAssetCache::FindAssetList(
                         this: &s_AssetCache,
                         pAssetType: this->m_pAssetType,
                         pSubDir: this->m_pAssetSubDir,
                         nExtCount: v4,
                         ppExt: &m_pAssetExt);
  v6 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: pParent,
           name: "AssetSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  else
    v7 = nullptr;
  this->m_pAssetSplitter = v7;
  vgui::Panel::SetAutoResize(
    this: v7,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  Child = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v10 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v10 != nullptr )
    v11 = vgui::ComboBox::ComboBox(this: v10, parent: Child, panelName: "ModFilter", numLines: 5, allowEdit: false);
  else
    v11 = nullptr;
  this->m_pModSelector = v11;
  v11->AddActionSignalTarget_2(this: v11, a2: this);
  v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: Child,
            panelName: "RescanButton",
            text: "Rescan",
            pActionSignalTarget: this,
            pCmd: "AssetRescan");
  else
    v13 = nullptr;
  this->m_pRescanButton = v13;
  vgui::Panel::SetWide(this: v13, wide: 75);
  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    m_pFileTree = nullptr;
  else
    m_pFileTree = s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_pFileTree;
  this->m_pFileTree = m_pFileTree;
  m_pFileTree->SetParent_2(this: m_pFileTree, a2: Child);
  this->m_pFileTree->AddActionSignalTarget_2(this: this->m_pFileTree, a2: this);
  v16 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v16 != nullptr )
    v17 = vgui::CheckButton::CheckButton(
            this: v16,
            parent: Child,
            panelName: "SubDirCheck",
            text: "Check subfolders for files?");
  else
    v17 = nullptr;
  this->m_pSubDirCheck = v17;
  v17->SetSelected(this: v17, a2: true);
  this->m_pSubDirCheck->SetEnabled(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->SetVisible(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->AddActionSignalTarget_2(this: this->m_pSubDirCheck, a2: this);
  V_snprintf(pDest, maxLen: 512, pFormat: "No .%s files", this->m_pAssetExt);
  v18 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v18 != nullptr )
    v19 = vgui::ListPanel::ListPanel(this: v18, parent: v9, panelName: "AssetBrowser");
  else
    v19 = nullptr;
  this->m_pAssetBrowser = v19;
  v19->AddColumnHeader(this: v19, a2: 0, a3: "mod", a4: "Mod", a5: 52, a6: 0);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 1,
    a3: "asset",
    a4: this->m_pAssetType,
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 2,
    a3: "timesused",
    a4: "Times Used",
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->SetSelectIndividualCells(this: this->m_pAssetBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pAssetBrowser, bState: bAllowMultiselect);
  this->m_pAssetBrowser->SetEmptyListText_2(this: this->m_pAssetBrowser, a2: pDest);
  this->m_pAssetBrowser->SetDragEnabled(this: this->m_pAssetBrowser, a2: true);
  this->m_pAssetBrowser->AddActionSignalTarget_2(this: this->m_pAssetBrowser, a2: this);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 0, a3: AssetBrowserModSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 1, a3: AssetBrowserSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 2, a3: AssetBrowserTimesUsedSortFunc);
  this->m_pAssetBrowser->SetSortColumn(this: this->m_pAssetBrowser, a2: 1);
  v20 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v21 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v21 != nullptr )
    v22 = vgui::TextEntry::TextEntry(this: v21, parent: v20, panelName: "FilterList");
  else
    v22 = nullptr;
  this->m_pFilter = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(
            this: v23,
            parent: v20,
            panelName: "OnlyUsedCheck",
            text: "Show used assets only");
  else
    v24 = nullptr;
  v25 = (*((_BYTE *)this + 544) & 0x10) != 0;
  this->m_pOnlyUsedCheck = v24;
  v24->SetSelected(this: v24, a2: v25);
  this->m_pOnlyUsedCheck->AddActionSignalTarget_2(this: this->m_pOnlyUsedCheck, a2: this);
  v26 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v26 != nullptr )
    v27 = vgui::TextEntry::TextEntry(this: v26, parent: v20, panelName: "FullPath");
  else
    v27 = nullptr;
  this->m_pFullPath = v27;
  v27->SetEnabled(this: v27, a2: false);
  this->m_pFullPath->SetEditable(this: this->m_pFullPath, a2: false);
  v28 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: v20,
            panelName: "FindButton",
            text: "Find Asset",
            pActionSignalTarget: this,
            pCmd: "FindAsset");
  else
    v29 = nullptr;
  this->m_nCurrentModFilter = -1;
  this->m_pFindAssetButton = v29;
}

//------------------------------------------------------------------------------
// Address: 0x0044DBC0
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0044DD20
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0044F620
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004500A0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450120
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450740
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451550
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004515C0
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00451A60
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452E90
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00454660
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455C10
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x004562E0
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00458950
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046C270
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0046DAF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TreeView::GetMessageMap(vgui::TreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetMessageMap'::`2'::s_pMap;
  `vgui::TreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  `vgui::TreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046DB20
// Name: public: virtual struct PanelAnimationMap __near * vgui::TreeView::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TreeView::GetAnimMap(vgui::TreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "TreeView");
}

//------------------------------------------------------------------------------
// Address: 0x0046DB30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TreeView::GetKBMap(vgui::TreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TreeView::GetKBMap'::`2'::s_pMap;
  `vgui::TreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  `vgui::TreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480B60
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00480C90
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480CF0
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5120
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5190
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x004B5310
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5520
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004C9FE0
// Name: public: static char const __near * CBaseAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPicker::GetPanelClassName()
{
  return "CBaseAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004C9FF0
// Name: public: static char const __near * CBaseAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAssetPickerFrame::GetPanelClassName()
{
  return "CBaseAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004CA000
// Name: bool AssetTreeViewSortFunc(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AssetTreeViewSortFunc(KeyValues *node1, KeyValues *node2)
{
  const char *String; // esi
  const char *v3; // eax

  String = KeyValues::GetString(this: node1, keyName: "text", defaultValue: nullptr);
  v3 = KeyValues::GetString(this: node2, keyName: "text", defaultValue: nullptr);
  return _V_stricmp(s1: String, s2: v3) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CA040
// Name: public: static char const __near * CAssetTreeView::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetTreeView::GetPanelClassName()
{
  return "CAssetTreeView";
}

//------------------------------------------------------------------------------
// Address: 0x004CA050
// Name: AssetBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  bool v3; // bl
  const char *String; // esi
  const char *v6; // eax

  v3 = KeyValues::GetInt(this: item1->kv, keyName: "root", defaultValue: 0) != 0;
  if ( v3 != (KeyValues::GetInt(this: item2->kv, keyName: "root", defaultValue: 0) != 0) )
    return 2 * !v3 - 1;
  String = KeyValues::GetString(this: item1->kv, keyName: "asset", defaultValue: defaultValue);
  v6 = KeyValues::GetString(this: item2->kv, keyName: "asset", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004CA0D0
// Name: AssetBrowserModSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserModSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "modIndex", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "modIndex", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x004CA120
// Name: AssetBrowserTimesUsedSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AssetBrowserTimesUsedSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: item1->kv, keyName: "timesused", defaultValue: -1);
  v4 = KeyValues::GetInt(this: item2->kv, keyName: "timesused", defaultValue: -1);
  if ( Int == v4 )
    return AssetBrowserSortFunc(pPanel, item1, item2);
  else
    return Int - v4;
}

//------------------------------------------------------------------------------
// Address: 0x004CA170
// Name: public: bool CBaseAssetPicker::IsMultiselectEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAssetPicker::IsMultiselectEnabled(CBaseAssetPicker *this)
{
  return vgui::ListPanel::IsMultiselectEnabled(this: this->m_pAssetBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x004CA180
// Name: public: virtual void CBaseAssetPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnKeyCodeTyped(CBaseAssetPicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  vgui::IPanel *v5; // esi
  vgui::ListPanel *m_pAssetBrowser; // edi
  int v7; // eax
  int v8; // eax
  vgui::IPanel_vtbl *codea; // [esp+14h] [ebp+8h]

  if ( code == KEY_UP || code == KEY_DOWN || code == KEY_PAGEUP || code == KEY_PAGEDOWN )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "KeyCodeTyped", firstKey: "code", firstValue: code);
    else
      v4 = nullptr;
    v5 = g_pVGuiPanel;
    m_pAssetBrowser = this->m_pAssetBrowser;
    codea = g_pVGuiPanel->__vftable;
    v7 = this->GetVPanel(this);
    v8 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pAssetBrowser->GetVPanel)(
           a1: m_pAssetBrowser,
           a2: v4,
           a3: v7);
    ((void (__thiscall *)(vgui::IPanel *, int))codea->SendMessage)(a1: v5, a2: v8);
    KeyValues::deleteThis(this: v4);
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CA220
// Name: protected: bool CBaseAssetPicker::IsAssetVisible(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAssetPicker::IsAssetVisible(CBaseAssetPicker *this, const CachedAssetInfo_t *nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ecx
  int m_nCurrentModFilter; // eax
  const char *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-Ch] [ebp-10h]
  const CachedAssetInfo_t *info; // [esp+Ch] [ebp+8h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  info = v3;
  if ( m_nCurrentModFilter >= 0 && m_nCurrentModFilter != v3->m_nModIndex )
    return false;
  v6 = CUtlString::operator char const *(this: &v3->m_AssetName);
  v7 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
  if ( _V_strcmp(s1: v6, s2: v7) == 0 )
    return true;
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
  {
    v8 = CUtlString::Get(this: &this->m_Filter);
    if ( V_stristr(pStr: v6, pSearch: v8) == nullptr )
      return false;
  }
  if ( CUtlString::Length(this: &this->m_FolderFilter) != 0 )
  {
    v12 = CUtlString::Length(this: &this->m_FolderFilter);
    v9 = CUtlString::Get(this: &this->m_FolderFilter);
    if ( V_strnicmp(s1: v6, s2: v9, n: v12) != 0 )
      return false;
  }
  if ( (*((_BYTE *)this + 544) & 8) == 0 )
  {
    v10 = CUtlString::Length(this: &this->m_FolderFilter);
    strchr(string: (unsigned __int8 *)&v6[v10], chr: 0x5Cu);
    if ( v11 != 0 )
      return false;
  }
  return (*((_BYTE *)this + 544) & 0x10) == 0 || info->m_nTimesUsed != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CA320
// Name: protected: void CBaseAssetPicker::RequestFilterFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::RequestFilterFocus(CBaseAssetPicker *this)
{
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pFilter, status: true);
  this->m_pFilter->RequestFocus(this: this->m_pFilter, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004CA350
// Name: protected: virtual void CBaseAssetPicker::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemDeselected(CBaseAssetPicker *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
    this->OnSelectedAssetPicked(this, a2: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x004CA390
// Name: public: int CBaseAssetPicker::GetSelectedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetSelectedAssetCount(CBaseAssetPicker *this)
{
  return this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x004CA3A0
// Name: public: char const __near * CBaseAssetPicker::GetSelectedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetSelectedAsset(CBaseAssetPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  v4 = nSelectionIndex;
  if ( nSelectionIndex < 0 )
    v4 = v3 - 1;
  if ( v3 <= v4 || v4 < 0 )
    return nullptr;
  v5 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: v4);
  v6 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v5);
  return KeyValues::GetString(this: v6, keyName: "asset", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x004CA410
// Name: protected: void CBaseAssetPickerFrame::SetAssetPicker(class CBaseAssetPicker __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::SetAssetPicker(CBaseAssetPickerFrame *this, CBaseAssetPicker *pPicker)
{
  this->m_pPicker = pPicker;
  pPicker->AddActionSignalTarget_2(this: pPicker, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x004CA430
// Name: public: void CBaseAssetPickerFrame::DoModal(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::DoModal(CBaseAssetPickerFrame *this, KeyValues *pKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  KeyValues *v4; // ecx
  CBaseAssetPicker *m_pPicker; // ecx

  vgui::Frame::DoModal(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  v4 = this->m_pContextKeyValues;
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pKeyValues;
  m_pPicker->Activate(this: m_pPicker);
}

//------------------------------------------------------------------------------
// Address: 0x004CA490
// Name: protected: void CBaseAssetPickerFrame::PostMessageAndClose(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::PostMessageAndClose(CBaseAssetPickerFrame *this, KeyValues *pKeyValues)
{
  if ( this->m_pContextKeyValues != nullptr )
  {
    KeyValues::AddSubKey(this: pKeyValues, pSubkey: this->m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->CloseModal(this);
  this->PostActionSignal(this, a2: pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004CA4E0
// Name: public: virtual void CBaseAssetPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPickerFrame::OnCommand(CBaseAssetPickerFrame *this@<ecx>, int a2@<ebx>, KeyValues *pCommand)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  CBaseAssetPicker *m_pPicker; // esi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  KeyValues *v10; // eax
  const char *String; // eax
  int v12; // ebx
  int i; // esi
  const char *SelectedAsset; // eax
  char pBuf[512]; // [esp+8h] [ebp-204h] BYREF
  KeyValues *pAssetKeys; // [esp+208h] [ebp-4h]
  KeyValues *pActionKeys; // [esp+214h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "AssetSelected");
      pActionKeys = v5;
    }
    else
    {
      pActionKeys = nullptr;
      v5 = nullptr;
    }
    if ( vgui::ListPanel::IsMultiselectEnabled(this: this->m_pPicker->m_pAssetBrowser) )
    {
      pAssetKeys = KeyValues::FindKey(this: v5, keyName: "assets", bCreate: true);
      v12 = ((int (__thiscall *)(vgui::ListPanel *, int))this->m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
              a1: this->m_pPicker->m_pAssetBrowser,
              a2);
      for ( i = 0; i < v12; ++i )
      {
        V_snprintf(pDest: pBuf, maxLen: 512, pFormat: "asset%d", i);
        SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this: this->m_pPicker, nSelectionIndex: i);
        KeyValues::SetString(this: pAssetKeys, keyName: pBuf, value: SelectedAsset);
      }
      v5 = pActionKeys;
    }
    else
    {
      m_pPicker = this->m_pPicker;
      v7 = ((int (__thiscall *)(vgui::ListPanel *, int))m_pPicker->m_pAssetBrowser->GetSelectedItemsCount)(
             a1: m_pPicker->m_pAssetBrowser,
             a2);
      v8 = v7 - 1;
      if ( __OFSUB__(v7, v7 - 1) || v8 < 0 )
      {
        KeyValues::SetString(this: v5, keyName: "asset", value: nullptr);
      }
      else
      {
        v9 = m_pPicker->m_pAssetBrowser->GetSelectedItem(this: m_pPicker->m_pAssetBrowser, a2: v8);
        v10 = m_pPicker->m_pAssetBrowser->GetItem(this: m_pPicker->m_pAssetBrowser, a2: v9);
        String = KeyValues::GetString(this: v10, keyName: "asset", defaultValue: defaultValue);
        KeyValues::SetString(this: v5, keyName: "asset", value: String);
      }
    }
    this->m_pPicker->CustomizeSelectionMessage(this: this->m_pPicker, a2: v5);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->CloseModal(this);
    ((void (__thiscall *)(CBaseAssetPickerFrame *))this->PostActionSignal)(a1: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CA6C0
// Name: protected: virtual void CBaseAssetPickerFrame::CloseModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::CloseModal(CBaseAssetPickerFrame *this)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  unsigned int v4; // eax

  v2 = g_pVGui;
  v3 = g_pVGui->__vftable;
  v4 = this->m_pPicker->GetVPanel(this: this->m_pPicker);
  v3->RemoveTickSignal(this: v2, a2: v4);
  vgui::Frame::CloseModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CA6F0
// Name: public: virtual void CAssetTreeView::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ApplySchemeSettings(CAssetTreeView *this, vgui::IScheme *pScheme)
{
  CAssetTreeView_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultSmall", a3: false);
  v3->SetFont(this, a2: v4);
  ((void (__thiscall *)(CAssetTreeView *, int))this->SetFgColor)(a1: this, a2: -2892072);
}

//------------------------------------------------------------------------------
// Address: 0x004CA740
// Name: public: void CBaseAssetPicker::SetInitialSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::SetInitialSelection(CBaseAssetPicker *this, const char *pAssetName)
{
  int v3; // edi

  CUtlString::operator=(this: &this->m_SelectedAsset, src: pAssetName);
  if ( pAssetName != nullptr )
  {
    v3 = this->m_pAssetBrowser->GetItem_2(this: this->m_pAssetBrowser, a2: pAssetName);
    if ( v3 != -1 )
    {
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v3, a3: 0);
      vgui::ListPanel::ScrollToItem(this: this->m_pAssetBrowser, nItemID: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CA7A0
// Name: public: virtual int CBaseAssetPicker::GetAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetAssetCount(CBaseAssetPicker *this)
{
  return this->m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004CA7B0
// Name: public: CBaseAssetPickerFrame::CBaseAssetPickerFrame(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPickerFrame *__thiscall CBaseAssetPickerFrame::CBaseAssetPickerFrame(
        CBaseAssetPickerFrame *this,
        vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "AssetPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( `CBaseAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
    v3->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
    v4->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
    v5->pfnClassName = CBaseAssetPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "OpenButton",
           text: "#FileOpenDialog_Open",
           pActionSignalTarget: this,
           pCmd: "Open");
  else
    v7 = nullptr;
  this->m_pOpenButton = v7;
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#FileOpenDialog_Cancel",
           pActionSignalTarget: this,
           pCmd: "Cancel");
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CA900
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPickerFrame::GetMessageMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CA930
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPickerFrame::GetAnimMap(CBaseAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004CA940
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPickerFrame::GetKBMap(CBaseAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  `CBaseAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CA970
// Name: public: virtual CBaseAssetPickerFrame::~CBaseAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::~CBaseAssetPickerFrame(CBaseAssetPickerFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (CBaseAssetPickerFrame_vtbl *)&CBaseAssetPickerFrame::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CA9A0
// Name: public: void CBaseAssetPickerFrame::SetInitialSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPickerFrame::SetInitialSelection(CBaseAssetPickerFrame *this, const char *pAssetName)
{
  CBaseAssetPicker *m_pPicker; // esi
  int v3; // edi

  m_pPicker = this->m_pPicker;
  CUtlString::operator=(this: &m_pPicker->m_SelectedAsset, src: pAssetName);
  if ( pAssetName != nullptr )
  {
    v3 = m_pPicker->m_pAssetBrowser->GetItem_2(this: m_pPicker->m_pAssetBrowser, a2: pAssetName);
    if ( v3 != -1 )
    {
      m_pPicker->m_pAssetBrowser->SetSelectedCell(this: m_pPicker->m_pAssetBrowser, a2: v3, a3: 0);
      vgui::ListPanel::ScrollToItem(this: m_pPicker->m_pAssetBrowser, nItemID: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CAA90
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CAB40
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CABF0
// Name: public: void CAssetTreeView::OpenRoot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::OpenRoot(CAssetTreeView *this)
{
  const char *v2; // ebx
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  CAssetTreeView_vtbl *v6; // ebx
  int v7; // eax
  int v8; // ebx

  this->RemoveAll(this);
  v2 = CUtlString::operator char const *(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[this->m_DirectoryStructure.m_Root].m_Element);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "root");
  else
    v4 = nullptr;
  v5 = CUtlString::Get(this: &this->m_RootFolderName);
  KeyValues::SetString(this: v4, keyName: "text", value: v5);
  KeyValues::SetInt(this: v4, keyName: "root", value: 1);
  KeyValues::SetInt(this: v4, keyName: "expand", value: 1);
  KeyValues::SetInt(this: v4, keyName: "dirHandle", value: this->m_DirectoryStructure.m_Root);
  KeyValues::SetString(this: v4, keyName: "path", value: v2);
  v6 = this->__vftable;
  v7 = this->GetRootItemIndex(this);
  v8 = v6->AddItem(this, a2: v4, a3: v7);
  KeyValues::deleteThis(this: v4);
  this->ExpandItem(this, a2: v8, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x004CACD0
// Name: private: static bool CAssetCache::CachedAssetLessFunc(struct CAssetCache::CachedAssetList_t const __near &,struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAssetCache::CachedAssetLessFunc(
        const CAssetCache::CachedAssetList_t *src1,
        const CAssetCache::CachedAssetList_t *src2)
{
  const char *v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  const char *v9; // [esp-4h] [ebp-Ch]
  int nCount; // [esp+14h] [ebp+Ch]

  v9 = CUtlString::operator char const *(this: &src2->m_pSubDir);
  v3 = CUtlString::operator char const *(this: &src1->m_pSubDir);
  v4 = _V_stricmp(s1: v3, s2: v9) > 0;
  if ( v4 != 0 )
    return v4 > 0;
  v6 = src1->m_Ext.m_Size - src2->m_Ext.m_Size;
  nCount = src1->m_Ext.m_Size;
  if ( v6 != 0 )
    return v6 > 0;
  v7 = 0;
  if ( src1->m_Ext.m_Size <= 0 )
    return false;
  while ( 1 )
  {
    v8 = _V_stricmp(s1: src1->m_Ext.m_Memory.m_pMemory[v7], s2: src2->m_Ext.m_Memory.m_pMemory[v7]);
    if ( v8 != 0 )
      break;
    if ( ++v7 >= nCount )
      return false;
  }
  return v8 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CAD70
// Name: private: int CAssetCache::GetAssetUsageCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAssetCache::GetAssetUsageCount(CAssetCache *this, const char *assetName)
{
  int result; // eax
  int v4; // edi
  int i; // ebx
  char *v6; // eax

  result = this->m_usedAssets.m_Size;
  if ( result != 0 )
  {
    v4 = 0;
    if ( result <= 0 )
    {
      return 0;
    }
    else
    {
      for ( i = 0; ; ++i )
      {
        v6 = CUtlString::Get(this: &this->m_usedAssets.m_Memory.m_pMemory[i].m_assetName);
        if ( V_stristr(pStr: v6, pSearch: assetName) != nullptr )
          break;
        if ( ++v4 >= this->m_usedAssets.m_Size )
          return 0;
      }
      return this->m_usedAssets.m_Memory.m_pMemory[v4].m_nTimesUsed;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CADD0
// Name: private: bool CAssetCache::DoesExtensionMatch(struct CAssetCache::CachedAssetList_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::DoesExtensionMatch(
        CAssetCache *this,
        CAssetCache::CachedAssetList_t *info,
        const char *pFileName)
{
  int m_Size; // edi
  int v4; // esi
  char pChildExt[260]; // [esp+Ch] [ebp-104h] BYREF

  V_ExtractFileExtension(path: pFileName, dest: pChildExt, destSize: 260);
  m_Size = info->m_Ext.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: info->m_Ext.m_Memory.m_pMemory[v4], s2: pChildExt) != 0 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CB540
// Name: private: void CAssetTreeView::AddDirectoryToTreeView(int,char const __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::AddDirectoryToTreeView(
        CAssetTreeView *this,
        int nParentItemIndex,
        const char *pFullParentPath,
        int hPath)
{
  int v5; // ebx
  const char *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  unsigned __int16 m_FirstChild; // bx
  int v10; // ebx
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // edx
  char pFullPath[260]; // [esp+Ch] [ebp-108h] BYREF
  const char *pDirName; // [esp+110h] [ebp-4h]

  v5 = (unsigned __int16)hPath;
  v6 = CUtlString::Get(this: &this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_Element);
  pDirName = v6;
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "text", firstValue: v6);
  else
    v8 = nullptr;
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s/%s", pFullParentPath, pDirName);
  V_FixSlashes(pname: pFullPath, separator: 92);
  _V_strlower(start: pFullPath);
  m_FirstChild = this->m_DirectoryStructure.m_Memory.m_pMemory[v5].m_FirstChild;
  KeyValues::SetString(this: v8, keyName: "path", value: pFullPath);
  KeyValues::SetInt(this: v8, keyName: "expand", value: m_FirstChild != 0xFFFF);
  KeyValues::SetInt(this: v8, keyName: "image", value: 0);
  KeyValues::SetInt(this: v8, keyName: "dirHandle", value: (unsigned __int16)hPath);
  v10 = this->AddItem(this, a2: v8, a3: nParentItemIndex);
  KeyValues::deleteThis(this: v8);
  SetItemFgColor = this->SetItemFgColor;
  hPath = -16727840;
  SetItemFgColor(this, a2: v10, a3: (const Color *)&hPath);
}

//------------------------------------------------------------------------------
// Address: 0x004CB660
// Name: public: virtual void CAssetTreeView::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::GenerateChildrenOfNode(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v3; // esi
  int Int; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // eax
  unsigned __int16 i; // cx
  unsigned int v7; // ebx
  const char *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // eax
  char pDest[260]; // [esp+8h] [ebp-114h] BYREF
  const char *pFullParentPath; // [esp+10Ch] [ebp-10h]
  int value; // [esp+110h] [ebp-Ch]
  const char *m_FirstChild; // [esp+114h] [ebp-8h]
  int v16; // [esp+118h] [ebp-4h] BYREF

  v3 = this->GetItemData(this, a2: nItemIndex);
  pFullParentPath = KeyValues::GetString(this: v3, keyName: "path", defaultValue: nullptr);
  if ( pFullParentPath != nullptr )
  {
    Int = (unsigned __int16)KeyValues::GetInt(this: v3, keyName: "dirHandle", defaultValue: 0xFFFF);
    if ( (_WORD)Int != 0xFFFF )
    {
      m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      for ( i = m_pMemory[Int].m_FirstChild; i != 0xFFFF; i = m_pMemory[v7].m_NextSibling )
      {
        value = i;
        v7 = i;
        v8 = CUtlString::Get(this: &m_pMemory[v7].m_Element);
        m_FirstChild = v8;
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(this: v9, setName: "node", firstKey: "text", firstValue: v8);
        else
          v10 = nullptr;
        V_snprintf(pDest, maxLen: 260, pFormat: "%s/%s", pFullParentPath, m_FirstChild);
        V_FixSlashes(pname: pDest, separator: 92);
        _V_strlower(start: pDest);
        m_FirstChild = (const char *)this->m_DirectoryStructure.m_Memory.m_pMemory[v7].m_FirstChild;
        KeyValues::SetString(this: v10, keyName: "path", value: pDest);
        KeyValues::SetInt(this: v10, keyName: "expand", value: (_WORD)m_FirstChild != 0xFFFF);
        KeyValues::SetInt(this: v10, keyName: "image", value: 0);
        KeyValues::SetInt(this: v10, keyName: "dirHandle", value);
        value = this->AddItem(this, a2: v10, a3: nItemIndex);
        KeyValues::deleteThis(this: v10);
        SetItemFgColor = this->SetItemFgColor;
        v16 = -16727840;
        SetItemFgColor(this, a2: value, a3: (const Color *)&v16);
        m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CB810
// Name: private: unsigned short CAssetTreeView::RefreshTreeViewItem(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::RefreshTreeViewItem(CAssetTreeView *this, int nItemIndex)
{
  KeyValues *v4; // edi
  const char *String; // eax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  bool v7; // zf
  BOOL v8; // ebx
  bool (__thiscall *ModifyItem)(vgui::TreeView *, int, KeyValues *); // edx
  int v10; // edi
  int v11; // ebx
  void *v12; // esp
  int i; // edi
  int v14; // eax
  unsigned __int16 refreshed; // ax
  int m_NextSibling; // edi
  unsigned __int16 *v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // dx
  KeyValues *v20; // [esp-4h] [ebp-20h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-1Ch] BYREF
  const char *pFullParentPath; // [esp+Ch] [ebp-10h]
  int hPath; // [esp+10h] [ebp-Ch]
  unsigned __int16 *pFoundHandles; // [esp+14h] [ebp-8h]
  int v25; // [esp+18h] [ebp-4h]

  if ( nItemIndex < 0 )
    return -1;
  v4 = this->GetItemData(this, a2: nItemIndex);
  hPath = (unsigned __int16)KeyValues::GetInt(this: v4, keyName: "dirHandle", defaultValue: 0xFFFF);
  String = KeyValues::GetString(this: v4, keyName: "path", defaultValue: nullptr);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  pFullParentPath = String;
  v7 = m_pMemory[hPath].m_FirstChild == 0xFFFF;
  v25 = 24 * hPath;
  v8 = !v7;
  if ( v8 == (KeyValues::GetInt(this: v4, keyName: "expand", defaultValue: 0) != 0) )
  {
    v10 = nItemIndex;
  }
  else
  {
    KeyValues::SetInt(this: v4, keyName: "expand", value: v8);
    ModifyItem = this->ModifyItem;
    v20 = v4;
    v10 = nItemIndex;
    ModifyItem(this, a2: nItemIndex, a3: v20);
  }
  if ( this->IsItemExpanded(this, a2: v10) )
  {
    v11 = this->GetNumChildren(this, a2: v10);
    v12 = alloca(2 * v11);
    pFoundHandles = (unsigned __int16 *)v21;
    memset(dst: v21, value: 0xFFu, count: 2 * v11);
    for ( i = 0; i < v11; ++i )
    {
      v14 = this->GetChild(this, a2: nItemIndex, a3: i);
      refreshed = CAssetTreeView::RefreshTreeViewItem(this, nItemIndex: v14);
      pFoundHandles[i] = refreshed;
    }
    m_NextSibling = *(unsigned __int16 *)((char *)&this->m_DirectoryStructure.m_Memory.m_pMemory->m_FirstChild + v25);
    if ( (_WORD)m_NextSibling != 0xFFFF )
    {
      v17 = pFoundHandles;
      v25 = (int)&pFoundHandles[v11 - 1];
      do
      {
        v18 = 0;
        if ( v11 <= 0 )
        {
LABEL_14:
          CAssetTreeView::AddDirectoryToTreeView(
            this,
            nParentItemIndex: nItemIndex,
            pFullParentPath,
            hPath: m_NextSibling);
          v17 = pFoundHandles;
        }
        else
        {
          while ( v17[v18] != (_WORD)m_NextSibling )
          {
            if ( ++v18 >= v11 )
              goto LABEL_14;
          }
          v19 = *(_WORD *)v25;
          --v11;
          v25 -= 2;
          v17[v18] = v19;
        }
        m_NextSibling = this->m_DirectoryStructure.m_Memory.m_pMemory[(unsigned __int16)m_NextSibling].m_NextSibling;
      }
      while ( (_WORD)m_NextSibling != 0xFFFF );
    }
  }
  return hPath;
}

//------------------------------------------------------------------------------
// Address: 0x004CB9C0
// Name: private: bool CAssetTreeView::SelectFolder_R(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetTreeView::SelectFolder_R(CAssetTreeView *this, int nItemID, const char *pPath)
{
  KeyValues *v6; // eax
  const char *String; // ebx
  const char *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // [esp-8h] [ebp-20h]
  CUtlString str; // [esp+8h] [ebp-10h] BYREF
  int nChildCount; // [esp+20h] [ebp+8h]

  if ( nItemID < 0 )
    return 0;
  v6 = this->GetItemData(this, a2: nItemID);
  String = KeyValues::GetString(this: v6, keyName: "path", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: pPath) != 0 )
  {
    CUtlString::CUtlString(this: &str, pString: String);
    CUtlString::operator+=(this: &str, c: 92);
    v11 = CUtlString::Length(this: &str);
    v8 = CUtlString::operator char const *(this: &str);
    if ( V_strnicmp(s1: v8, s2: pPath, n: v11) != 0 )
    {
      CUtlString::~CUtlString(this: &str);
      return 0;
    }
    else
    {
      this->ExpandItem(this, a2: nItemID, a3: true);
      v9 = 0;
      nChildCount = this->GetNumChildren(this, a2: nItemID);
      if ( nChildCount <= 0 )
      {
LABEL_10:
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 0;
      }
      else
      {
        while ( 1 )
        {
          v10 = this->GetChild(this, a2: nItemID, a3: v9);
          if ( CAssetTreeView::SelectFolder_R(this, nItemID: v10, pPath) )
            break;
          if ( ++v9 >= nChildCount )
            goto LABEL_10;
        }
        str.m_Storage.m_nActualLength = 0;
        if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        return 1;
      }
    }
  }
  else
  {
    this->AddSelectedItem(this, a2: nItemID, a3: true, a4: false, a5: true);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBB20
// Name: public: virtual void CBaseAssetPicker::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::GetUserConfigSettings(CBaseAssetPicker *this, KeyValues *pUserConfig)
{
  const char *v3; // eax
  const char *v4; // eax
  int m_nCurrentModFilter; // eax
  char v6; // bl
  CUtlString *v7; // eax
  const char *v8; // eax
  CUtlString v9; // [esp+Ch] [ebp-24h] BYREF
  CUtlString v10; // [esp+1Ch] [ebp-14h] BYREF
  int v11; // [esp+2Ch] [ebp-4h]

  v11 = 0;
  vgui::EditablePanel::GetUserConfigSettings(this, userConfig: pUserConfig);
  v3 = CUtlString::operator char const *(this: &this->m_Filter);
  KeyValues::SetString(this: pUserConfig, keyName: "filter", value: v3);
  v4 = CUtlString::operator char const *(this: &this->m_FolderFilter);
  KeyValues::SetString(this: pUserConfig, keyName: "folderfilter", value: v4);
  m_nCurrentModFilter = this->m_nCurrentModFilter;
  if ( m_nCurrentModFilter < 0 )
  {
    v6 = 2;
    v7 = CUtlString::CUtlString(this: &v10, pString: defaultValue);
  }
  else
  {
    v6 = 1;
    v7 = CUtlString::CUtlString(
           this: &v9,
           string: &s_AssetCache.m_ModList.m_Memory.m_pMemory[m_nCurrentModFilter].m_ModName);
  }
  v8 = CUtlString::operator char const *(this: v7);
  KeyValues::SetString(this: pUserConfig, keyName: "mod", value: v8);
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    v10.m_Storage.m_nActualLength = 0;
    if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
        v10.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v10.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
  }
  if ( (v6 & 1) != 0 )
  {
    v9.m_Storage.m_nActualLength = 0;
    if ( v9.m_Storage.m_Memory.m_nGrowSize >= 0 && v9.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBC10
// Name: public: virtual struct CachedAssetInfo_t const __near & CBaseAssetPicker::GetCachedAsset(int)
// Source: json
//------------------------------------------------------------------------------
const CachedAssetInfo_t *__thiscall CBaseAssetPicker::GetCachedAsset(CBaseAssetPicker *this, int nAssetIndex)
{
  return &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[nAssetIndex];
}

//------------------------------------------------------------------------------
// Address: 0x004CBC40
// Name: public: virtual int CBaseAssetPicker::GetCachedAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAssetPicker::GetCachedAssetCount(CBaseAssetPicker *this)
{
  AssetList_t__ *m_hAssetList; // eax

  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    return 0;
  else
    return s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_AssetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004CBC70
// Name: protected: void CBaseAssetPicker::RescanAssets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::RescanAssets(CBaseAssetPicker *this)
{
  char v2; // al
  vgui::IVGui *v3; // ebx
  vgui::IVGui_vtbl *v4; // edi
  int v5; // eax

  this->m_pAssetBrowser->RemoveAll(this: this->m_pAssetBrowser);
  this->m_AssetList.m_Size = 0;
  this->BeginCacheAssets(this, a2: true);
  *((_BYTE *)this + 544) |= 2u;
  v2 = *((_BYTE *)this + 544);
  this->m_nMatchingAssets = 0;
  if ( (v2 & 4) != 0 )
  {
    *((_BYTE *)this + 544) = v2 & 0xFB;
    v3 = g_pVGui;
    v4 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v4->AddTickSignal)(a1: v3, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBCE0
// Name: public: virtual void CBaseAssetPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnCommand(CBaseAssetPicker *this, const char *pCommand)
{
  const char *v2; // esi
  KeyValues *v4; // eax
  int v5; // esi
  void *v6; // esp
  KeyValues *v7; // esi
  char v8[12]; // [esp+0h] [ebp-10h] BYREF
  KeyValues *pKeyValues; // [esp+Ch] [ebp-4h]

  v2 = pCommand;
  if ( _V_stricmp(s1: pCommand, s2: "AssetRescan") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "FindAsset") == 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        pKeyValues = KeyValues::KeyValues(this: v4, setName: "AssetPickerFind");
      else
        pKeyValues = nullptr;
      v5 = this->m_pFullPath->GetTextLength(this: this->m_pFullPath);
      v6 = alloca(v5 + 1);
      if ( v5 <= 0 )
        v8[0] = 0;
      else
        this->m_pFullPath->GetText_2(this: this->m_pFullPath, a2: v8, a3: v5 + 1);
      v7 = pKeyValues;
      KeyValues::SetString(this: pKeyValues, keyName: "asset", value: v8);
      this->PostActionSignal(this, a2: v7);
      v2 = pCommand;
    }
    vgui::Panel::OnCommand(this, command: v2);
  }
  else
  {
    CBaseAssetPicker::RescanAssets(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBDC0
// Name: public: virtual class CUtlString CBaseAssetPicker::GetSelectedAssetFullPath(int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CBaseAssetPicker::GetSelectedAssetFullPath(
        CBaseAssetPicker *this,
        CUtlString *result,
        int nIndex)
{
  const char *SelectedAsset; // edi
  int Int; // eax
  int v6; // eax
  KeyValues *v7; // eax
  const char *v8; // eax
  const char *m_pAssetSubDir; // [esp-8h] [ebp-114h]
  char pBuf[260]; // [esp+8h] [ebp-104h] BYREF

  SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: nIndex - 1);
  Int = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser);
  if ( Int != 0 )
  {
    v6 = this->m_pAssetBrowser->GetSelectedItem(this: this->m_pAssetBrowser, a2: 0);
    v7 = this->m_pAssetBrowser->GetItem(this: this->m_pAssetBrowser, a2: v6);
    Int = KeyValues::GetInt(this: v7, keyName: "modIndex", defaultValue: 0);
  }
  m_pAssetSubDir = this->m_pAssetSubDir;
  v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[Int].m_Path);
  V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "%s\\%s\\%s", v8, m_pAssetSubDir, SelectedAsset);
  V_FixSlashes(pname: pBuf, separator: 92);
  CUtlString::CUtlString(this: result, pString: pBuf);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CBE80
// Name: protected: virtual void CBaseAssetPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnItemSelected(CBaseAssetPicker *this, KeyValues *kv)
{
  int v3; // edi
  vgui::TextEntry_vtbl *v4; // ebx
  CUtlString *v5; // eax
  const char *v6; // eax
  _DWORD v7[4]; // [esp+4h] [ebp-10h] BYREF
  const char *pSelectedAsset; // [esp+1Ch] [ebp+8h]

  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pAssetBrowser )
  {
    v3 = this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) - 1;
    pSelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: v3);
    v4 = this->m_pFullPath->__vftable;
    v5 = this->GetSelectedAssetFullPath(this, result: v7, a3: v3);
    v6 = CUtlString::operator char const *(this: v5);
    v4->SetText(this: this->m_pFullPath, a2: v6);
    v7[3] = 0;
    if ( v7[2] >= 0 && v7[0] != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v7[0]);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
    this->OnSelectedAssetPicked(this, a2: pSelectedAsset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBF50
// Name: public: virtual char const __near * CBaseAssetPicker::GetAssetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAssetPicker::GetAssetName(CBaseAssetPicker *this, int nAssetIndex)
{
  return CUtlString::operator char const *(this: &s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[LOWORD(this->m_hAssetList)].m_Data.m_AssetList.m_Memory.m_pMemory[this->m_AssetList.m_Memory.m_pMemory[nAssetIndex].m_nAssetIndex].m_AssetName);
}

//------------------------------------------------------------------------------
// Address: 0x004CC860
// Name: public: unsigned short CAssetTreeView::AddSubDirectory(unsigned short,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAssetTreeView::AddSubDirectory(
        CAssetTreeView *this,
        unsigned __int16 hParent,
        const char *pDirName)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v4; // bx
  int v5; // edi
  CUtlString *p_m_Element; // ecx
  char *v7; // eax

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  v4 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  v5 = v4;
  p_m_Element = &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element;
  if ( p_m_Element != nullptr )
    CUtlString::CUtlString(this: p_m_Element);
  CUtlString::operator=(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element, src: pDirName);
  v7 = CUtlString::Get(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v5].m_Element);
  _V_strlower(start: v7);
  CUtlNTree<CUtlString,unsigned short>::LinkChildBefore(
    this: p_m_DirectoryStructure,
    parent: hParent,
    before: p_m_DirectoryStructure->m_Memory.m_pMemory[hParent].m_FirstChild,
    elem: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004CC9E0
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x004CCA70
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x004CCB00
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x004CCB90
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x004CCC20
// Name: public: static void CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
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
// Address: 0x004CCCB0
// Name: protected: void CBaseAssetPicker::AddExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AddExtension(CBaseAssetPicker *this, vgui::TreeNode *pExtension)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_ExtraAssetExt; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_ExtraAssetExt.m_Memory.m_nAllocationCount;
  p_m_ExtraAssetExt = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ExtraAssetExt;
  m_Size = this->m_ExtraAssetExt.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_ExtraAssetExt, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ExtraAssetExt[1].m_pMemory;
  m_pMemory = p_m_ExtraAssetExt->m_pMemory;
  v6 = (int)p_m_ExtraAssetExt[1].m_pMemory - m_Size - 1;
  p_m_ExtraAssetExt[1].m_nAllocationCount = (int)p_m_ExtraAssetExt->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_ExtraAssetExt->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pExtension;
}

//------------------------------------------------------------------------------
// Address: 0x004CCD20
// Name: protected: void CBaseAssetPicker::AddAssetToList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::AddAssetToList(CBaseAssetPicker *this, int nAssetIndex)
{
  const CachedAssetInfo_t *v3; // ebx
  unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  KeyValues *m_pInsertHelper; // esi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int v12; // esi
  const char *v13; // eax
  const char *v14; // eax
  KeyValues *v15; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBaseAssetPicker::AssetInfo_t *m_pMemory; // ecx
  int v19; // eax
  const char *v20; // [esp-4h] [ebp-1Ch]
  KeyValues *v21; // [esp+10h] [ebp-8h]
  bool bInRootDir; // [esp+17h] [ebp-1h]

  v3 = this->GetCachedAsset(this, a2: nAssetIndex);
  v4 = (unsigned __int8 *)CUtlString::operator char const *(this: &v3->m_AssetName);
  strchr(string: v4, chr: 0x5Cu);
  if ( v5 != 0
    || (v6 = (unsigned __int8 *)CUtlString::operator char const *(this: &v3->m_AssetName),
        strchr(string: v6, chr: 0x2Fu),
        bInRootDir = true,
        v7 != 0) )
  {
    bInRootDir = false;
  }
  m_pInsertHelper = this->m_pInsertHelper;
  v9 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetName(this: m_pInsertHelper, setName: v9);
  v10 = CUtlString::operator char const *(this: &v3->m_AssetName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "asset", value: v10);
  v11 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v3->m_nModIndex].m_ModName);
  KeyValues::SetString(this: m_pInsertHelper, keyName: "mod", value: v11);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "modIndex", value: v3->m_nModIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "root", value: bInRootDir);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "assetIndex", value: nAssetIndex);
  KeyValues::SetInt(this: m_pInsertHelper, keyName: "timesused", value: v3->m_nTimesUsed);
  v12 = this->m_pAssetBrowser->AddItem(this: this->m_pAssetBrowser, a2: m_pInsertHelper, a3: 0, a4: false, a5: false);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0 )
  {
    v20 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v13 = CUtlString::operator char const *(this: &this->m_SelectedAsset);
    if ( _V_strcmp(s1: v13, s2: v20) == 0 )
      this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v12, a3: 0);
  }
  v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v21 != nullptr )
  {
    v14 = CUtlString::operator char const *(this: &v3->m_AssetName);
    v15 = KeyValues::KeyValues(this: v21, setName: "drag", firstKey: "text", firstValue: v14);
  }
  else
  {
    v15 = nullptr;
  }
  if ( this->m_pAssetTextType != nullptr )
    KeyValues::SetString(this: v15, keyName: "texttype", value: this->m_pAssetTextType);
  vgui::ListPanel::SetItemDragData(this: this->m_pAssetBrowser, itemID: v12, data: v15);
  m_Size = this->m_AssetList.m_Size;
  m_nAllocationCount = this->m_AssetList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MDLSquenceLayer_t,int>::Grow(
      this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_AssetList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_AssetList.m_Size;
  m_pMemory = this->m_AssetList.m_Memory.m_pMemory;
  v19 = this->m_AssetList.m_Size - m_Size - 1;
  this->m_AssetList.m_pElements = m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v19);
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nAssetIndex = nAssetIndex;
  this->m_AssetList.m_Memory.m_pMemory[m_Size].m_nItemId = v12;
  LOBYTE(nAssetIndex) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)m_Size);
  this->m_pAssetBrowser->SetItemVisible(this: this->m_pAssetBrowser, a2: v12, a3: nAssetIndex);
  if ( (_BYTE)nAssetIndex != 0 )
    ++this->m_nMatchingAssets;
}

//------------------------------------------------------------------------------
// Address: 0x004CD010
// Name: public: void CAssetTreeView::ClearDirectories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::ClearDirectories(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short> *p_m_DirectoryStructure; // esi
  unsigned __int16 v3; // ax
  int v4; // edi
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  unsigned __int16 v6; // [esp+Ch] [ebp-4h]

  p_m_DirectoryStructure = &this->m_DirectoryStructure;
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  v3 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: p_m_DirectoryStructure);
  v4 = v3;
  v6 = v3;
  if ( &p_m_DirectoryStructure->m_Memory.m_pMemory[v4] != nullptr )
  {
    CUtlString::CUtlString(this: &p_m_DirectoryStructure->m_Memory.m_pMemory[v4].m_Element);
    v3 = v6;
  }
  m_pMemory = p_m_DirectoryStructure->m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v3;
  CUtlString::operator=(this: &m_pMemory[v4].m_Element, src: &this->m_RootDirectory);
}

//------------------------------------------------------------------------------
// Address: 0x004CD280
// Name: public: CAssetTreeView::CAssetTreeView(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetTreeView *__thiscall CAssetTreeView::CAssetTreeView(
        CAssetTreeView *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pRootFolderName,
        const char *pRootDir)
{
  vgui::PanelMessageMap *v6; // esi
  PanelAnimationMap *v7; // esi
  vgui::PanelKeyBindingMap *v8; // esi
  unsigned __int16 v9; // ax
  CUtlNTree<CUtlString,unsigned short>::Node_t *m_pMemory; // ecx
  int v11; // ebx
  bool v12; // zf
  CUtlString *p_m_Element; // ecx
  CUtlNTree<CUtlString,unsigned short>::Node_t *v14; // ecx
  vgui::IImage *v15; // eax
  unsigned __int16 pNamea; // [esp+18h] [ebp+Ch]

  vgui::TreeView::TreeView(this, parent: pParent, panelName: pName);
  this->__vftable = (CAssetTreeView_vtbl *)&CAssetTreeView::`vftable';
  if ( `CAssetTreeView::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
    v6->pfnClassName = CAssetTreeView::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CAssetTreeView");
    v7->pfnClassName = CAssetTreeView::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TreeView");
  }
  if ( `CAssetTreeView::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetTreeView::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
    v8->pfnClassName = CAssetTreeView::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TreeView");
  }
  CUtlString::CUtlString(this: &this->m_RootFolderName);
  CUtlString::CUtlString(this: &this->m_RootDirectory);
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
  this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoryStructure.m_Memory.m_nGrowSize = 0;
  *(_DWORD *)&this->m_DirectoryStructure.m_Root = -1;
  *(_DWORD *)&this->m_DirectoryStructure.m_ElementCount = 0;
  this->m_DirectoryStructure.m_pElements = nullptr;
  vgui::TreeView::SetSortFunc(this, pSortFunc: AssetTreeViewSortFunc);
  CUtlString::operator=(this: &this->m_RootFolderName, src: pRootFolderName);
  CUtlString::operator=(this: &this->m_RootDirectory, src: pRootDir);
  v9 = CUtlNTree<CUtlString,unsigned short>::AllocInternal(this: &this->m_DirectoryStructure);
  m_pMemory = this->m_DirectoryStructure.m_Memory.m_pMemory;
  v11 = v9;
  v12 = &m_pMemory[v11] == nullptr;
  p_m_Element = &m_pMemory[v11].m_Element;
  pNamea = v9;
  if ( !v12 )
  {
    CUtlString::CUtlString(this: p_m_Element);
    v9 = pNamea;
  }
  v14 = this->m_DirectoryStructure.m_Memory.m_pMemory;
  this->m_DirectoryStructure.m_Root = v9;
  CUtlString::operator=(this: &v14[v11].m_Element, src: &this->m_RootDirectory);
  v15 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "resource/icon_folder", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: (vgui::Dar<unsigned long> *)&this->m_Images, elem: (unsigned int)v15);
  vgui::TreeView::SetImageList(this, imageList: &this->m_Images, deleteImageListWhenDone: false);
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CD430
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetTreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetTreeView::GetMessageMap(CAssetTreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetTreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetMessageMap'::`2'::s_pMap;
  `CAssetTreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetTreeView");
  `CAssetTreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD460
// Name: public: virtual struct PanelAnimationMap __near * CAssetTreeView::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetTreeView::GetAnimMap(CAssetTreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetTreeView");
}

//------------------------------------------------------------------------------
// Address: 0x004CD470
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetTreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetTreeView::GetKBMap(CAssetTreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetTreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetTreeView::GetKBMap'::`2'::s_pMap;
  `CAssetTreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetTreeView");
  `CAssetTreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD4A0
// Name: public: virtual CAssetTreeView::~CAssetTreeView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetTreeView::~CAssetTreeView(CAssetTreeView *this)
{
  CUtlNTree<CUtlString,unsigned short>::RemoveAll(this: &this->m_DirectoryStructure);
  if ( this->m_DirectoryStructure.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoryStructure.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoryStructure.m_Memory.m_pMemory);
      this->m_DirectoryStructure.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoryStructure.m_Memory.m_nAllocationCount = 0;
  }
  vgui::ImageList::~ImageList(this: &this->m_Images);
  this->m_RootDirectory.m_Storage.m_nActualLength = 0;
  if ( this->m_RootDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootDirectory.m_Storage.m_Memory.m_pMemory);
      this->m_RootDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RootFolderName.m_Storage.m_nActualLength = 0;
  if ( this->m_RootFolderName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RootFolderName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RootFolderName.m_Storage.m_Memory.m_pMemory);
      this->m_RootFolderName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RootFolderName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::TreeView::~TreeView(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CD560
// Name: public: void CAssetCache::BuildModList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::BuildModList(CAssetCache *this, const char *pSearchPathName)
{
  int v3; // edi
  void *v4; // esp
  unsigned __int8 *v5; // ebx
  char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CacheModInfo_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // edi
  _BYTE v12[12]; // [esp+0h] [ebp-114h] BYREF
  char pModName[260]; // [esp+Ch] [ebp-108h] BYREF
  char *pSemiColon; // [esp+110h] [ebp-4h]
  CacheModInfo_t *pSearchPathNamea; // [esp+11Ch] [ebp+8h]

  if ( !this->m_bBuiltModList )
  {
    this->m_pAssetSearchPath = pSearchPathName;
    this->m_bBuiltModList = true;
    CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::RemoveAll(this: &this->m_ModList);
    v3 = g_pFullFileSystem->GetSearchPath(
           this: g_pFullFileSystem,
           a2: this->m_pAssetSearchPath,
           a3: false,
           a4: nullptr,
           a5: 0);
    v4 = alloca(v3);
    v5 = v12;
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: this->m_pAssetSearchPath, a3: false, a4: v12, a5: v3);
    if ( v12 != nullptr )
    {
      do
      {
        strchr(string: v5, chr: 0x3Bu);
        pSemiColon = v6;
        if ( v6 != nullptr )
          *v6 = 0;
        V_StripTrailingSlash(ppath: (char *)v5);
        V_FixSlashes(pname: (char *)v5, separator: 92);
        V_FileBase(in: (const char *)v5, out: pModName, maxlen: 260);
        m_Size = this->m_ModList.m_Size;
        m_nAllocationCount = this->m_ModList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
            (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_ModList.m_Size;
        m_pMemory = this->m_ModList.m_Memory.m_pMemory;
        v10 = this->m_ModList.m_Size - m_Size - 1;
        this->m_ModList.m_pElements = this->m_ModList.m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v10);
        v11 = m_Size;
        pSearchPathNamea = &this->m_ModList.m_Memory.m_pMemory[v11];
        if ( pSearchPathNamea != nullptr )
        {
          CUtlString::CUtlString(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName);
          CUtlString::CUtlString(this: &pSearchPathNamea->m_Path);
        }
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_ModName, pValue: pModName);
        CUtlString::Set(this: &this->m_ModList.m_Memory.m_pMemory[v11].m_Path, pValue: (const char *)v5);
        if ( pSemiColon == nullptr )
          break;
        v5 = (unsigned __int8 *)(pSemiColon + 1);
      }
      while ( pSemiColon != (char *)-1 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD6A0
// Name: private: bool CAssetCache::AddFilesInDirectory(struct CAssetCache::CachedAssetList_t __near &,char const __near *,char const __near *,unsigned short,float,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::AddFilesInDirectory(
        CAssetCache *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *list,
        char *pStartingFile,
        const char *pFilePath,
        unsigned __int16 hCurrentDir,
        float flStartTime,
        float flDuration)
{
  bool v8; // zf
  CAssetCache *v9; // ebx
  const char *v11; // eax
  char *v12; // edi
  int v13; // eax
  const char *v14; // eax
  int v15; // edi
  int v16; // edi
  CacheModInfo_t *v17; // ebx
  const char *v18; // eax
  char *v19; // edi
  const char *v20; // eax
  int AssetUsageCount; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CachedAssetInfo_t *v24; // ecx
  int v25; // eax
  CachedAssetInfo_t *v26; // ecx
  CachedAssetInfo_t *v27; // edi
  int v28; // eax
  int v29; // [esp-8h] [ebp-228h]
  int v30; // [esp-8h] [ebp-228h]
  char pFullAssetPath[260]; // [esp+8h] [ebp-218h] BYREF
  char pRelativeChildPath[260]; // [esp+10Ch] [ebp-114h] BYREF
  int nTimesUsed; // [esp+210h] [ebp-10h]
  int nModCount; // [esp+214h] [ebp-Ch]
  CAssetCache *v35; // [esp+218h] [ebp-8h]
  int nSubDirLen; // [esp+21Ch] [ebp-4h]
  unsigned __int16 ia; // [esp+228h] [ebp+8h]
  int i; // [esp+228h] [ebp+8h]
  const char *pAssetName; // [esp+22Ch] [ebp+Ch]

  v8 = list[7].m_nAllocationCount == -1;
  v9 = this;
  v35 = this;
  if ( v8 )
    return 1;
  nModCount = this->m_ModList.m_Size;
  if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
  {
    v11 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
    nSubDirLen = _V_strlen(str: v11);
  }
  else
  {
    nSubDirLen = 0;
  }
  v12 = pStartingFile;
  if ( pStartingFile == nullptr )
    return 1;
  while ( 1 )
  {
    V_snprintf(pDest: pRelativeChildPath, maxLen: 260, pFormat: "%s\\%s", pFilePath, v12);
    if ( !g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount) )
      break;
    strstr(str1: (unsigned __int8 *)v12, str2: ".svn");
    if ( v13 == 0 )
    {
      if ( V_strnicmp(s1: v12, s2: ".", n: 2) != 0 && V_strnicmp(s1: v12, s2: "..", n: 3) != 0 )
      {
        ia = CAssetTreeView::AddSubDirectory(
               this: (CAssetTreeView *)list[1].m_nGrowSize,
               hParent: hCurrentDir,
               pDirName: v12);
        v15 = CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(this: (CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *)&list[5]);
        CUtlString::operator=(this: (CUtlString *)&list[5].m_pMemory[v15], src: pRelativeChildPath);
        LOWORD(list[5].m_pMemory[v15].m_Data.key) = ia;
      }
      goto LABEL_30;
    }
    v14 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
LABEL_32:
    v12 = (char *)v14;
    if ( v14 == nullptr )
      return 1;
  }
  if ( CAssetCache::DoesExtensionMatch(this: v9, info: (CAssetCache::CachedAssetList_t *)list, pFileName: v12) != 0 )
  {
    v16 = 0;
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: pRelativeChildPath,
      a3: v9->m_pAssetSearchPath,
      a4: pFullAssetPath,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    i = 0;
    if ( nModCount > 0 )
    {
      while ( 1 )
      {
        v17 = &v35->m_ModList.m_Memory.m_pMemory[v16];
        v29 = CUtlString::Length(this: &v17->m_Path);
        v18 = CUtlString::operator char const *(this: &v17->m_Path);
        if ( V_strnicmp(s1: pFullAssetPath, s2: v18, n: v29) == 0 )
          break;
        ++v16;
        if ( ++i >= nModCount )
          goto LABEL_30;
      }
      if ( i >= 0 )
      {
        v19 = pRelativeChildPath;
        pAssetName = pRelativeChildPath;
        if ( CUtlString::operator char const *(this: (CUtlString *)&list[2]) != nullptr )
        {
          v30 = nSubDirLen;
          v20 = CUtlString::operator char const *(this: (CUtlString *)&list[2]);
          if ( V_strnicmp(s1: v20, s2: pRelativeChildPath, n: v30) == 0 && pRelativeChildPath[nSubDirLen] == 92 )
          {
            pAssetName = &pRelativeChildPath[nSubDirLen + 1];
            v19 = &pRelativeChildPath[nSubDirLen + 1];
          }
        }
        strlwr(string: v19);
        AssetUsageCount = CAssetCache::GetAssetUsageCount(this: v35, assetName: v19);
        m_pMemory = (int)list[1].m_pMemory;
        nTimesUsed = AssetUsageCount;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
            this: list,
            num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v24 = (CachedAssetInfo_t *)list->m_pMemory;
        v25 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v25 > 0 )
          _V_memmove(dest: (void *)&v24[m_pMemory + 1], src: &v24[m_pMemory], count: 24 * v25);
        v26 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        if ( v26 != nullptr )
          CUtlString::CUtlString(this: &v26->m_AssetName);
        v27 = (CachedAssetInfo_t *)&list->m_pMemory[m_pMemory];
        CUtlString::Set(this: &v27->m_AssetName, pValue: pAssetName);
        v28 = nTimesUsed;
        v27->m_nModIndex = i;
        v27->m_nTimesUsed = v28;
      }
    }
  }
LABEL_30:
  if ( _Plat_FloatTime() - flStartTime < flDuration )
  {
    v14 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: list[7].m_nAllocationCount);
    v9 = v35;
    goto LABEL_32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CD990
// Name: public: bool CAssetCache::BeginAssetScan(struct AssetList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::BeginAssetScan(CAssetCache *this, AssetList_t__ *hList, bool bForceRescan)
{
  int v3; // eax
  CAssetCache::CachedAssetList_t *p_m_Data; // esi
  int m_hFind; // eax
  unsigned __int16 v7; // ax
  int v8; // ebx
  unsigned __int16 v9; // ax
  CUtlString *p_m_DirName; // ecx
  int v11; // ebx

  v3 = (unsigned __int16)hList;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data;
  if ( bForceRescan )
  {
    m_hFind = this->m_CachedAssets.m_Elements.m_pMemory[v3].m_Data.m_hFind;
    p_m_Data->m_bAssetScanComplete = false;
    if ( m_hFind != -1 )
    {
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: m_hFind);
      p_m_Data->m_hFind = -1;
    }
    CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_Data->m_DirectoriesToCheck);
  }
  if ( p_m_Data->m_bAssetScanComplete )
    return 1;
  if ( p_m_Data->m_hFind == -1 )
  {
    CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int>>::RemoveAll(this: (CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int> > *)p_m_Data);
    CAssetTreeView::ClearDirectories(this: p_m_Data->m_pFileTree);
    v7 = CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &p_m_Data->m_DirectoriesToCheck,
           multilist: false);
    v8 = v7;
    if ( v7 == 0xFFFF )
    {
      v9 = -1;
    }
    else
    {
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &p_m_Data->m_DirectoriesToCheck,
        before: 0xFFFFu,
        elem: v7);
      p_m_DirName = &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v8].m_Element.m_DirName;
      if ( p_m_DirName != nullptr )
        CUtlString::CUtlString(this: p_m_DirName);
      v9 = v8;
    }
    v11 = v9;
    CUtlString::operator=(
      this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_DirName,
      src: &p_m_Data->m_pSubDir);
    p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[v11].m_Element.m_hDirHandle = p_m_Data->m_pFileTree->m_DirectoryStructure.m_Root;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CDA70
// Name: public: virtual bool CBaseAssetPicker::BeginCacheAssets(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAssetPicker::BeginCacheAssets(CBaseAssetPicker *this, bool bForceRecache)
{
  return CAssetCache::BeginAssetScan(this: &s_AssetCache, hList: this->m_hAssetList, bForceRescan: bForceRecache);
}

//------------------------------------------------------------------------------
// Address: 0x004CDA90
// Name: protected: void CBaseAssetPicker::BuildAssetNameList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::BuildAssetNameList(CBaseAssetPicker *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  int v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int v7; // edi
  KeyValues *v8; // eax
  const KeyValues *v9; // eax
  bool v10; // zf
  char v11; // al
  CBaseAssetPicker_vtbl *v12; // edx
  vgui::IVGui *v13; // ebx
  vgui::IVGui_vtbl *v14; // edi
  int v15; // eax
  int v16; // ebx
  int i; // edi
  const char *m_pAssetSearchPath; // [esp-8h] [ebp-14h]
  int nModCount; // [esp+4h] [ebp-8h]
  const char *pModName; // [esp+8h] [ebp-4h]

  v3 = *((_BYTE *)this + 544);
  if ( (v3 & 1) == 0 )
  {
    *((_BYTE *)this + 544) = v3 | 1;
    v4 = 0;
    m_pAssetSearchPath = this->m_pAssetSearchPath;
    this->m_nMatchingAssets = 0;
    this->m_nCurrentModFilter = -1;
    CAssetCache::BuildModList(this: &s_AssetCache, pSearchPathName: m_pAssetSearchPath);
    vgui::ComboBox::RemoveAll(this: this->m_pModSelector);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "Mod", firstKey: "mod", firstValue: -1);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::ComboBox *, const char *, KeyValues *, int))this->m_pModSelector->AddItem_2)(
      a1: this->m_pModSelector,
      a2: "All Mods",
      a3: v6,
      a4: a2);
    v7 = 0;
    for ( nModCount = s_AssetCache.m_ModList.m_Size; v7 < nModCount; ++v4 )
    {
      pModName = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v4].m_ModName);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "Mod", firstKey: "mod", firstValue: v7);
      else
        v9 = nullptr;
      this->m_pModSelector->AddItem_2(this: this->m_pModSelector, a2: pModName, a3: v9);
      ++v7;
    }
    vgui::ComboBox::ActivateItemByRow(this: this->m_pModSelector, row: 0);
    v10 = !this->BeginCacheAssets(this, a2: false);
    v11 = *((_BYTE *)this + 544);
    if ( v10 )
    {
      v12 = this->__vftable;
      *((_BYTE *)this + 544) = v11 & 0xF9 | 2;
      v13 = g_pVGui;
      v14 = g_pVGui->__vftable;
      v15 = ((int (__thiscall *)(CBaseAssetPicker *, int))v12->GetVPanel)(a1: this, a2: 10);
      ((void (__thiscall *)(vgui::IVGui *, int))v14->AddTickSignal)(a1: v13, a2: v15);
    }
    else
    {
      *((_BYTE *)this + 544) = v11 & 0xF9 | 4;
    }
    v16 = this->GetCachedAssetCount(this);
    for ( i = 0; i < v16; ++i )
      CBaseAssetPicker::AddAssetToList(this, nAssetIndex: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CDC10
// Name: protected: void CBaseAssetPicker::RefreshAssetList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::RefreshAssetList(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // eax
  int v5; // edi
  const CachedAssetInfo_t *v6; // eax
  vgui::ListPanel *m_pAssetBrowser; // ecx
  vgui::ListPanelItem *(__thiscall *GetItemData)(vgui::ListPanel *, int); // edx
  int v9; // ebx
  vgui::ListPanelItem *v10; // eax
  KeyValues *kv; // ecx
  const char *v12; // eax
  int v13; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v15; // eax
  char pDest[512]; // [esp+8h] [ebp-210h] BYREF
  const CachedAssetInfo_t *info; // [esp+208h] [ebp-10h]
  int nCount; // [esp+20Ch] [ebp-Ch]
  vgui::ListPanelItem *pItem; // [esp+210h] [ebp-8h]
  int bIsVisible; // [esp+214h] [ebp-4h]

  CBaseAssetPicker::BuildAssetNameList(this, a2: a3);
  v5 = 0;
  nCount = this->m_AssetList.m_Size;
  v4 = nCount;
  this->m_nMatchingAssets = 0;
  if ( v4 > 0 )
  {
    do
    {
      LOBYTE(bIsVisible) = CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: (const CachedAssetInfo_t *)v5);
      v6 = (const CachedAssetInfo_t *)((int (__thiscall *)(CBaseAssetPicker *, int, int))this->GetCachedAsset)(
                                        a1: this,
                                        a2: v5,
                                        a3: a2);
      m_pAssetBrowser = this->m_pAssetBrowser;
      GetItemData = m_pAssetBrowser->GetItemData;
      info = v6;
      v9 = v5;
      v10 = GetItemData(this: m_pAssetBrowser, a2: this->m_AssetList.m_Memory.m_pMemory[v5].m_nItemId);
      kv = v10->kv;
      pItem = v10;
      if ( KeyValues::GetInt(this: kv, keyName: "timesused", defaultValue: 0) != info->m_nTimesUsed )
      {
        KeyValues::SetInt(this: pItem->kv, keyName: "timesused", value: info->m_nTimesUsed);
        this->m_pAssetBrowser->ApplyItemChanges(
          this: this->m_pAssetBrowser,
          a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      }
      a2 = bIsVisible;
      ((void (__thiscall *)(vgui::ListPanel *, int))this->m_pAssetBrowser->SetItemVisible)(
        a1: this->m_pAssetBrowser,
        a2: this->m_AssetList.m_Memory.m_pMemory[v9].m_nItemId);
      if ( (_BYTE)bIsVisible != 0 )
        ++this->m_nMatchingAssets;
      ++v5;
    }
    while ( v5 < nCount );
  }
  v12 = defaultValue;
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
    v12 = " ...";
  V_snprintf(
    pDest,
    maxLen: 512,
    pFormat: "%s (%d/%d)%s",
    this->m_pAssetType,
    this->m_nMatchingAssets,
    this->m_AssetList.m_Size,
    v12);
  this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: pDest);
  this->m_pAssetBrowser->SortList(this: this->m_pAssetBrowser);
  if ( this->m_pAssetBrowser->GetSelectedItemsCount(this: this->m_pAssetBrowser) == 0
    && this->m_pAssetBrowser->GetItemCount(this: this->m_pAssetBrowser) > 0 )
  {
    this->OnNextSelectionIsDefault(this);
    v13 = this->m_pAssetBrowser->GetItemIDFromRow(this: this->m_pAssetBrowser, a2: 0);
    this->m_pAssetBrowser->SetSelectedCell(this: this->m_pAssetBrowser, a2: v13, a3: 0);
  }
  m_pFileTree = this->m_pFileTree;
  v15 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
  CAssetTreeView::RefreshTreeViewItem(this: m_pFileTree, nItemIndex: v15);
  m_pFileTree->InvalidateLayout(this: m_pFileTree, a2: false, a3: false);
  this->OnAssetListChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CDE00
// Name: protected: virtual void CBaseAssetPicker::OnFileSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::OnFileSelected(CBaseAssetPicker *this@<ecx>, int a2@<ebx>)
{
  const char *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  const char *String; // esi
  const char *v7; // eax
  int nLen; // [esp+Ch] [ebp-4h]

  v3 = defaultValue;
  v4 = this->m_pFileTree->GetFirstSelectedItem(this: this->m_pFileTree);
  if ( v4 >= 0 )
  {
    v5 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: v4);
    String = KeyValues::GetString(this: v5, keyName: "path", defaultValue: defaultValue);
    v3 = &String[_V_strlen(str: this->m_pAssetSubDir)];
    if ( *v3 != 0 )
      ++v3;
  }
  v7 = CUtlString::Get(this: &this->m_FolderFilter);
  if ( _V_stricmp(s1: v3, s2: v7) != 0 )
  {
    nLen = _V_strlen(str: v3);
    CUtlString::operator=(this: &this->m_FolderFilter, src: v3);
    if ( nLen > 0 )
      CUtlString::operator+=(this: &this->m_FolderFilter, c: 92);
    CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CDEB0
// Name: protected: virtual void CBaseAssetPicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnTextChanged(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *pKeyValues)
{
  vgui::ComboBox *Ptr; // eax
  vgui::TextEntry *m_pFilter; // ecx
  int v7; // edi
  void *v8; // esp
  const char *v9; // eax
  vgui::ComboBox *m_pModSelector; // ecx
  KeyValues *ActiveItemUserData; // eax
  char v12[12]; // [esp+0h] [ebp-Ch] BYREF

  Ptr = (vgui::ComboBox *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  m_pFilter = this->m_pFilter;
  if ( Ptr == m_pFilter )
  {
    v7 = m_pFilter->GetTextLength(this: m_pFilter);
    v8 = alloca(v7 + 1);
    if ( v7 <= 0 )
      v12[0] = 0;
    else
      this->m_pFilter->GetText_2(this: this->m_pFilter, a2: v12, a3: v7 + 1);
    v9 = CUtlString::Get(this: &this->m_Filter);
    if ( _V_stricmp(s1: v12, s2: v9) != 0 )
    {
      CUtlString::SetLength(this: &this->m_Filter, nLen: v7);
      CUtlString::operator=(this: &this->m_Filter, src: v12);
      CBaseAssetPicker::RefreshAssetList(this, a2: (int)v12, a3: v7);
    }
  }
  else
  {
    m_pModSelector = this->m_pModSelector;
    if ( Ptr == m_pModSelector )
    {
      ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: m_pModSelector);
      if ( ActiveItemUserData != nullptr )
      {
        this->m_nCurrentModFilter = KeyValues::GetInt(this: ActiveItemUserData, keyName: "mod", defaultValue: -1);
        CBaseAssetPicker::RefreshAssetList(this, a2, a3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CDF90
// Name: protected: virtual void CBaseAssetPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::OnCheckButtonChecked(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *kv)
{
  vgui::CheckButton *Ptr; // eax
  vgui::CheckButton *m_pSubDirCheck; // ecx
  vgui::CheckButton *m_pOnlyUsedCheck; // ecx

  Ptr = (vgui::CheckButton *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSubDirCheck = this->m_pSubDirCheck;
  if ( Ptr == m_pSubDirCheck )
  {
    *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                             ^ (8
                              * ((int (__thiscall *)(vgui::CheckButton *))m_pSubDirCheck->IsSelected)(a1: m_pSubDirCheck)))
                            & 8;
    CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  }
  else
  {
    m_pOnlyUsedCheck = this->m_pOnlyUsedCheck;
    if ( Ptr == m_pOnlyUsedCheck )
    {
      *((_BYTE *)this + 544) ^= (*((_BYTE *)this + 544)
                               ^ (16
                                * ((int (__thiscall *)(vgui::CheckButton *))m_pOnlyUsedCheck->IsSelected)(a1: m_pOnlyUsedCheck)))
                              & 0x10;
      CBaseAssetPicker::RefreshAssetList(this, a2, a3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE100
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CE160
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const char *pSearchSubDir,
        int nExtCount,
        const char **ppSearchExt)
{
  int v5; // eax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // eax

  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  v5 = _V_strlen(str: pSearchSubDir);
  CUtlString::CUtlString(this: &this->m_pSubDir, pMemory: pSearchSubDir, nSizeInBytes: v5 + 1);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  this->m_DirectoriesToCheck.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
    this: (CUtlVector<int,CUtlMemory<int,int> > *)&this->m_Ext,
    elem: this->m_Ext.m_Size,
    num: nExtCount,
    pToInsert: (const int *)ppSearchExt);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CE1F0
// Name: public: CAssetCache::CachedAssetList_t::CachedAssetList_t(struct CAssetCache::CachedAssetList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAssetCache::CachedAssetList_t *__thiscall CAssetCache::CachedAssetList_t::CachedAssetList_t(
        CAssetCache::CachedAssetList_t *this,
        const CAssetCache::CachedAssetList_t *__formal)
{
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pSubDir);
  this->m_Ext.m_Memory.m_pMemory = nullptr;
  this->m_Ext.m_Memory.m_nAllocationCount = 0;
  this->m_Ext.m_Memory.m_nGrowSize = 0;
  this->m_Ext.m_Size = 0;
  this->m_Ext.m_pElements = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
  this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  this->m_DirectoriesToCheck.m_Memory.m_nGrowSize = 0;
  this->m_DirectoriesToCheck.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_FirstFree = 0xFFFF;
  this->m_DirectoriesToCheck.m_pElements = this->m_DirectoriesToCheck.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DirectoriesToCheck.m_Head = -1;
  this->m_DirectoriesToCheck.m_NumAlloced = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CE250
// Name: public: bool CAssetCache::ContinueSearchForAssets(struct AssetList_t__ __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAssetCache::ContinueSearchForAssets(CAssetCache *this, AssetList_t__ *hList, float flDuration)
{
  CAssetCache::CachedAssetList_t *p_m_Data; // ebx
  const char *v4; // eax
  int m_hDirHandle; // ecx
  int m_hFind; // edx
  int *p_m_hFind; // esi
  char *v8; // eax
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  bool v11; // sf
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v12; // esi
  unsigned __int16 v13; // dx
  char pSearchString[260]; // [esp+18h] [ebp-110h] BYREF
  int hCurrentDir; // [esp+11Ch] [ebp-Ch]
  CAssetCache *v17; // [esp+120h] [ebp-8h]
  const char *pFilePath; // [esp+124h] [ebp-4h]
  float flStartTime; // [esp+130h] [ebp+8h]

  v17 = this;
  p_m_Data = &this->m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)hList].m_Data;
  flStartTime = _Plat_FloatTime();
  if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount != 0 )
  {
    while ( 1 )
    {
      v4 = CUtlString::operator char const *(this: &p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_DirName);
      m_hDirHandle = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory[p_m_Data->m_DirectoriesToCheck.m_Head].m_Element.m_hDirHandle;
      m_hFind = p_m_Data->m_hFind;
      p_m_hFind = &p_m_Data->m_hFind;
      pFilePath = v4;
      hCurrentDir = m_hDirHandle;
      if ( m_hFind == -1 )
      {
        V_snprintf(pDest: pSearchString, maxLen: 260, pFormat: "%s\\*", v4);
        v8 = (char *)g_pFullFileSystem->FindFirstEx(
                       this: g_pFullFileSystem,
                       a2: pSearchString,
                       a3: v17->m_pAssetSearchPath,
                       a4: &p_m_Data->m_hFind);
      }
      else
      {
        v8 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: m_hFind);
      }
      if ( CAssetCache::AddFilesInDirectory(
             this: v17,
             list: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)p_m_Data,
             pStartingFile: v8,
             pFilePath,
             hCurrentDir,
             flStartTime,
             flDuration) == 0 )
        return 0;
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: *p_m_hFind);
      *p_m_hFind = -1;
      m_Head = p_m_Data->m_DirectoriesToCheck.m_Head;
      pFilePath = (const char *)m_Head;
      CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
        this: &p_m_Data->m_DirectoriesToCheck,
        elem: m_Head);
      m_pMemory = p_m_Data->m_DirectoriesToCheck.m_Memory.m_pMemory;
      v11 = m_pMemory[m_Head].m_Element.m_DirName.m_Storage.m_Memory.m_nGrowSize < 0;
      v12 = &m_pMemory[m_Head];
      v12->m_Element.m_DirName.m_Storage.m_nActualLength = 0;
      if ( !v11 )
      {
        if ( v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory);
          v12->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v12->m_Element.m_DirName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v13 = (unsigned __int16)pFilePath;
      v12->m_Next = p_m_Data->m_DirectoriesToCheck.m_FirstFree;
      p_m_Data->m_DirectoriesToCheck.m_FirstFree = v13;
      if ( p_m_Data->m_DirectoriesToCheck.m_ElementCount == 0 )
        goto LABEL_11;
    }
  }
  else
  {
LABEL_11:
    p_m_Data->m_bAssetScanComplete = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE3D0
// Name: public: CAssetCache::CachedAssetList_t::~CachedAssetList_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssetCache::CachedAssetList_t::~CachedAssetList_t(CAssetCache::CachedAssetList_t *this)
{
  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirectoriesToCheck);
  if ( this->m_DirectoriesToCheck.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirectoriesToCheck.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirectoriesToCheck.m_Memory.m_pMemory);
      this->m_DirectoriesToCheck.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirectoriesToCheck.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Ext);
  this->m_pSubDir.m_Storage.m_nActualLength = 0;
  if ( this->m_pSubDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pSubDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSubDir.m_Storage.m_Memory.m_pMemory);
      this->m_pSubDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pSubDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>::~CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>(this: &this->m_AssetList);
}

//------------------------------------------------------------------------------
// Address: 0x004CE440
// Name: public: CBaseAssetPicker::CBaseAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAssetPicker *__thiscall CBaseAssetPicker::CBaseAssetPicker(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType,
        const char *pAssetSearchPath)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  char v11; // al
  KeyValues *v12; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "AssetPicker");
  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  if ( `CBaseAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
    v8->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
    v9->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
    v10->pfnClassName = CBaseAssetPicker::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAssetPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CBaseAssetPicker::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FolderFilter);
  CUtlString::CUtlString(this: &this->m_Filter);
  CUtlString::CUtlString(this: &this->m_SelectedAsset);
  this->m_AssetList.m_Memory.m_pMemory = nullptr;
  this->m_AssetList.m_Memory.m_nAllocationCount = 0;
  this->m_AssetList.m_Memory.m_nGrowSize = 0;
  this->m_AssetList.m_Size = 0;
  this->m_AssetList.m_pElements = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_pMemory = nullptr;
  this->m_ExtraAssetExt.m_Memory.m_nAllocationCount = 0;
  this->m_ExtraAssetExt.m_Memory.m_nGrowSize = 0;
  this->m_ExtraAssetExt.m_Size = 0;
  this->m_ExtraAssetExt.m_pElements = nullptr;
  this->m_usedAssets.m_Memory.m_pMemory = nullptr;
  this->m_usedAssets.m_Memory.m_nAllocationCount = 0;
  this->m_usedAssets.m_Memory.m_nGrowSize = 0;
  this->m_usedAssets.m_Size = 0;
  this->m_usedAssets.m_pElements = nullptr;
  this->m_pAssetExt = pExt;
  v11 = *((_BYTE *)this + 544) & 0xE8;
  this->m_pAssetType = pAssetType;
  this->m_pAssetTextType = pTextType;
  this->m_pAssetSubDir = pSubDir;
  this->m_pAssetSearchPath = pAssetSearchPath;
  this->m_nMatchingAssets = 0;
  *((_BYTE *)this + 544) = v11 | 8;
  this->m_hAssetList = (AssetList_t__ *)0xFFFF;
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    this->m_pInsertHelper = KeyValues::KeyValues(this: v12, setName: "node");
  else
    this->m_pInsertHelper = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CE610
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAssetPicker::GetMessageMap(CBaseAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CE640
// Name: public: virtual struct PanelAnimationMap __near * CBaseAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAssetPicker::GetAnimMap(CBaseAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004CE650
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAssetPicker::GetKBMap(CBaseAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAssetPicker::GetKBMap'::`2'::s_pMap;
  `CBaseAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  `CBaseAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CE680
// Name: public: virtual CBaseAssetPicker::~CBaseAssetPicker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::~CBaseAssetPicker(CBaseAssetPicker *this)
{
  KeyValues *m_pInsertHelper; // ecx

  this->__vftable = (CBaseAssetPicker_vtbl *)&CBaseAssetPicker::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  this->m_pFileTree->RemoveActionSignalTarget(this: this->m_pFileTree, a2: this);
  this->m_pFileTree->SetParent_2(this: this->m_pFileTree, a2: nullptr);
  m_pInsertHelper = this->m_pInsertHelper;
  this->m_pFileTree = nullptr;
  if ( m_pInsertHelper != nullptr )
    KeyValues::deleteThis(this: m_pInsertHelper);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &this->m_usedAssets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ExtraAssetExt);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_AssetList);
  this->m_SelectedAsset.m_Storage.m_nActualLength = 0;
  if ( this->m_SelectedAsset.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory);
      this->m_SelectedAsset.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SelectedAsset.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Filter.m_Storage.m_nActualLength = 0;
  if ( this->m_Filter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Filter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Filter.m_Storage.m_Memory.m_pMemory);
      this->m_Filter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Filter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FolderFilter.m_Storage.m_nActualLength = 0;
  if ( this->m_FolderFilter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FolderFilter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FolderFilter.m_Storage.m_Memory.m_pMemory);
      this->m_FolderFilter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FolderFilter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CE790
// Name: public: virtual void CBaseAssetPicker::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAssetPicker::ApplyUserConfigSettings(
        CBaseAssetPicker *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pUserConfig)
{
  const char *String; // ebx
  const char *v5; // eax
  const char *v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int v9; // ebx
  int ItemIDFromRow; // edi
  KeyValues *ItemUserData; // eax
  int nItemCount; // [esp+Ch] [ebp-4h]
  int nItemCounta; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig: pUserConfig);
  CBaseAssetPicker::RefreshAssetList(this, a2, a3: (int)pUserConfig);
  String = KeyValues::GetString(this: pUserConfig, keyName: "filter", defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: pUserConfig, keyName: "folderfilter", defaultValue: defaultValue);
  CUtlString::operator=(this: &this->m_FolderFilter, src: v5);
  v6 = KeyValues::GetString(this: pUserConfig, keyName: "mod", defaultValue: defaultValue);
  CUtlString::operator=(this: &this->m_Filter, src: String);
  this->m_pFilter->SetText(this: this->m_pFilter, a2: String);
  v7 = 0;
  this->m_nCurrentModFilter = -1;
  if ( v6 != nullptr && *v6 != 0 )
  {
    nItemCount = s_AssetCache.m_ModList.m_Size;
    i = 0;
    if ( s_AssetCache.m_ModList.m_Size > 0 )
    {
      while ( 1 )
      {
        v8 = CUtlString::operator char const *(this: &s_AssetCache.m_ModList.m_Memory.m_pMemory[v7].m_ModName);
        if ( _V_stricmp(s1: v6, s2: v8) == 0 )
          break;
        ++v7;
        if ( ++i >= nItemCount )
          return;
      }
      v9 = 0;
      nItemCounta = this->m_pModSelector->GetItemCount(this: this->m_pModSelector);
      if ( nItemCounta > 0 )
      {
        while ( 1 )
        {
          ItemIDFromRow = vgui::ComboBox::GetItemIDFromRow(this: this->m_pModSelector, row: v9);
          ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pModSelector, itemID: ItemIDFromRow);
          if ( KeyValues::GetInt(this: ItemUserData, keyName: "mod", defaultValue: 0) == i )
            break;
          if ( ++v9 >= nItemCounta )
            return;
        }
        this->m_nCurrentModFilter = i;
        this->m_pModSelector->ActivateItem(this: this->m_pModSelector, a2: ItemIDFromRow);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE8F0
// Name: public: virtual void CBaseAssetPicker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAssetPicker::Activate(CBaseAssetPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax

  CBaseAssetPicker::RefreshAssetList(this, a2, a3);
  if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pFilter, status: true);
  this->m_pFilter->RequestFocus(this: this->m_pFilter, a2: 0);
  if ( (*((_BYTE *)this + 544) & 4) == 0 )
  {
    v4 = g_pVGui;
    v5 = g_pVGui->__vftable;
    v6 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->GetVPanel)(a1: this, a2: 10);
    ((void (__thiscall *)(vgui::IVGui *, int))v5->AddTickSignal)(a1: v4, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE950
// Name: public: virtual bool CBaseAssetPicker::IncrementalCacheAssets(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAssetPicker::IncrementalCacheAssets(CBaseAssetPicker *this, float flTimeAllowed)
{
  char v3; // bl

  v3 = CAssetCache::ContinueSearchForAssets(this: &s_AssetCache, hList: this->m_hAssetList, flDuration: flTimeAllowed);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    CAssetTreeView::OpenRoot(this: this->m_pFileTree);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004CE9A0
// Name: public: virtual void CBaseAssetPicker::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::OnTick(CBaseAssetPicker *this)
{
  int v2; // edi
  int v3; // xmm0_4
  char v4; // al
  int i; // ebx
  vgui::IVGui *v6; // ebx
  vgui::IVGui_vtbl *v7; // edi
  int v8; // eax
  const char *v9; // eax
  CAssetTreeView *m_pFileTree; // edi
  int v11; // eax
  const char *v12; // eax
  char v13[252]; // [esp+10h] [ebp-204h] BYREF
  char pDest[263]; // [esp+10Ch] [ebp-108h] BYREF
  char v15; // [esp+213h] [ebp-1h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = this->GetCachedAssetCount(this);
  if ( (*((_BYTE *)this + 544) & 2) != 0 )
    v3 = 1048576000;
  else
    v3 = 1020054733;
  v4 = ((int (__thiscall *)(CBaseAssetPicker *, int))this->IncrementalCacheAssets)(a1: this, a2: v3);
  *((_BYTE *)this + 544) &= ~2u;
  v15 = v4;
  for ( i = this->GetCachedAssetCount(this); v2 < i; ++v2 )
    CBaseAssetPicker::AddAssetToList(this, nAssetIndex: v2);
  if ( v15 != 0 )
  {
    v6 = g_pVGui;
    v7 = g_pVGui->__vftable;
    v8 = this->GetVPanel(this);
    v7->RemoveTickSignal(this: v6, a2: v8);
    *((_BYTE *)this + 544) |= 4u;
    v9 = CUtlString::operator char const *(this: &this->m_FolderFilter);
    m_pFileTree = this->m_pFileTree;
    V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", this->m_pAssetSubDir, v9);
    V_StripTrailingSlash(ppath: pDest);
    v11 = m_pFileTree->GetRootItemIndex(this: m_pFileTree);
    CAssetTreeView::SelectFolder_R(this: m_pFileTree, nItemID: v11, pPath: pDest);
    CBaseAssetPicker::RefreshAssetList(this, a2: (int)v6, a3: (int)m_pFileTree);
  }
  else
  {
    v12 = defaultValue;
    if ( (*((_BYTE *)this + 544) & 4) == 0 )
      v12 = " ...";
    V_snprintf(
      pDest: v13,
      maxLen: 512,
      pFormat: "%s (%d/%d)%s",
      this->m_pAssetType,
      this->m_nMatchingAssets,
      this->m_AssetList.m_Size,
      v12);
    this->m_pAssetBrowser->SetColumnHeaderText_2(this: this->m_pAssetBrowser, a2: 1, a3: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEDA0
// Name: public: struct AssetList_t__ __near * CAssetCache::FindAssetList(char const __near *,char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
AssetList_t__ *__thiscall CAssetCache::FindAssetList(
        CAssetCache *this,
        const char *pAssetType,
        const char *pSubDir,
        int nExtCount,
        const char **ppExt)
{
  int v6; // edi
  UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short> *m_pMemory; // eax
  int p_m_Data; // esi
  CAssetTreeView *v9; // eax
  CAssetTreeView *v10; // eax
  CAssetCache::CachedAssetList_t search; // [esp+Ch] [ebp-60h] BYREF

  CAssetCache::CachedAssetList_t::CachedAssetList_t(
    this: &search,
    pSearchSubDir: pSubDir,
    nExtCount,
    ppSearchExt: ppExt);
  v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_CachedAssets,
         &search);
  if ( v6 == 0xFFFF )
  {
    v6 = CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_CachedAssets,
           insert: &search);
    m_pMemory = this->m_CachedAssets.m_Elements.m_pMemory;
    p_m_Data = (int)&m_pMemory[v6].m_Data;
    CUtlString::operator=(this: &m_pMemory[v6].m_Data.m_pSubDir, src: pSubDir);
    CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
      this: (CUtlVector<int,CUtlMemory<int,int> > *)(p_m_Data + 40),
      elem: *(_DWORD *)(p_m_Data + 52),
      num: nExtCount,
      pToInsert: (const int *)ppExt);
    *(_DWORD *)(p_m_Data + 88) = -1;
    *(_BYTE *)(p_m_Data + 92) = 0;
    v9 = (CAssetTreeView *)MemAlloc_Alloc(nSize: 0x210u);
    if ( v9 != nullptr )
      v10 = CAssetTreeView::CAssetTreeView(
              this: v9,
              pParent: nullptr,
              pName: "FolderFilter",
              pRootFolderName: pAssetType,
              pRootDir: pSubDir);
    else
      v10 = nullptr;
    *(_DWORD *)(p_m_Data + 20) = v10;
  }
  CAssetCache::CachedAssetList_t::~CachedAssetList_t(this: &search);
  return (AssetList_t__ *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x004CEE60
// Name: protected: void CBaseAssetPicker::CreateStandardControls(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAssetPicker::CreateStandardControls(
        CBaseAssetPicker *this,
        vgui::Panel *pParent,
        bool bAllowMultiselect)
{
  int v4; // edi
  void *v5; // esp
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v9; // ebx
  vgui::ComboBox *v10; // eax
  vgui::ComboBox *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  AssetList_t__ *m_hAssetList; // eax
  CAssetTreeView *m_pFileTree; // ecx
  vgui::CheckButton *v16; // eax
  vgui::CheckButton *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::ListPanel *v19; // eax
  vgui::Panel *v20; // edi
  vgui::TextEntry *v21; // eax
  vgui::TextEntry *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  BOOL v25; // ecx
  vgui::TextEntry *v26; // eax
  vgui::TextEntry *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  const char *m_pAssetExt; // [esp+0h] [ebp-20Ch] BYREF
  unsigned __int8 v31[8]; // [esp+4h] [ebp-208h] BYREF
  char pDest[512]; // [esp+Ch] [ebp-200h] BYREF

  v4 = this->m_ExtraAssetExt.m_Size + 1;
  v5 = alloca(4 * v4);
  m_pAssetExt = this->m_pAssetExt;
  if ( v4 > 1 )
    memcpy(dst: v31, src: (unsigned __int8 *)this->m_ExtraAssetExt.m_Memory.m_pMemory, count: v4 - 1);
  this->m_hAssetList = CAssetCache::FindAssetList(
                         this: &s_AssetCache,
                         pAssetType: this->m_pAssetType,
                         pSubDir: this->m_pAssetSubDir,
                         nExtCount: v4,
                         ppExt: &m_pAssetExt);
  v6 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: pParent,
           name: "AssetSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  else
    v7 = nullptr;
  this->m_pAssetSplitter = v7;
  vgui::Panel::SetAutoResize(
    this: v7,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  Child = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v10 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v10 != nullptr )
    v11 = vgui::ComboBox::ComboBox(this: v10, parent: Child, panelName: "ModFilter", numLines: 5, allowEdit: false);
  else
    v11 = nullptr;
  this->m_pModSelector = v11;
  v11->AddActionSignalTarget_2(this: v11, a2: this);
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: Child,
            panelName: "RescanButton",
            text: "Rescan",
            pActionSignalTarget: this,
            pCmd: "AssetRescan");
  else
    v13 = nullptr;
  this->m_pRescanButton = v13;
  vgui::Panel::SetWide(this: v13, wide: 75);
  m_hAssetList = this->m_hAssetList;
  if ( m_hAssetList == (AssetList_t__ *)0xFFFF )
    m_pFileTree = nullptr;
  else
    m_pFileTree = s_AssetCache.m_CachedAssets.m_Elements.m_pMemory[(unsigned __int16)m_hAssetList].m_Data.m_pFileTree;
  this->m_pFileTree = m_pFileTree;
  m_pFileTree->SetParent_2(this: m_pFileTree, a2: Child);
  this->m_pFileTree->AddActionSignalTarget_2(this: this->m_pFileTree, a2: this);
  v16 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v16 != nullptr )
    v17 = vgui::CheckButton::CheckButton(
            this: v16,
            parent: Child,
            panelName: "SubDirCheck",
            text: "Check subfolders for files?");
  else
    v17 = nullptr;
  this->m_pSubDirCheck = v17;
  v17->SetSelected(this: v17, a2: true);
  this->m_pSubDirCheck->SetEnabled(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->SetVisible(this: this->m_pSubDirCheck, a2: false);
  this->m_pSubDirCheck->AddActionSignalTarget_2(this: this->m_pSubDirCheck, a2: this);
  V_snprintf(pDest, maxLen: 512, pFormat: "No .%s files", this->m_pAssetExt);
  v18 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v18 != nullptr )
    v19 = vgui::ListPanel::ListPanel(this: v18, parent: v9, panelName: "AssetBrowser");
  else
    v19 = nullptr;
  this->m_pAssetBrowser = v19;
  v19->AddColumnHeader(this: v19, a2: 0, a3: "mod", a4: "Mod", a5: 52, a6: 0);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 1,
    a3: "asset",
    a4: this->m_pAssetType,
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->AddColumnHeader(
    this: this->m_pAssetBrowser,
    a2: 2,
    a3: "timesused",
    a4: "Times Used",
    a5: 128,
    a6: 2);
  this->m_pAssetBrowser->SetSelectIndividualCells(this: this->m_pAssetBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pAssetBrowser, bState: bAllowMultiselect);
  this->m_pAssetBrowser->SetEmptyListText_2(this: this->m_pAssetBrowser, a2: pDest);
  this->m_pAssetBrowser->SetDragEnabled(this: this->m_pAssetBrowser, a2: true);
  this->m_pAssetBrowser->AddActionSignalTarget_2(this: this->m_pAssetBrowser, a2: this);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 0, a3: AssetBrowserModSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 1, a3: AssetBrowserSortFunc);
  this->m_pAssetBrowser->SetSortFunc(this: this->m_pAssetBrowser, a2: 2, a3: AssetBrowserTimesUsedSortFunc);
  this->m_pAssetBrowser->SetSortColumn(this: this->m_pAssetBrowser, a2: 1);
  v20 = vgui::Panel::GetChild(this: this->m_pAssetSplitter, index: 1);
  v21 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v21 != nullptr )
    v22 = vgui::TextEntry::TextEntry(this: v21, parent: v20, panelName: "FilterList");
  else
    v22 = nullptr;
  this->m_pFilter = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(
            this: v23,
            parent: v20,
            panelName: "OnlyUsedCheck",
            text: "Show used assets only");
  else
    v24 = nullptr;
  v25 = (*((_BYTE *)this + 544) & 0x10) != 0;
  this->m_pOnlyUsedCheck = v24;
  v24->SetSelected(this: v24, a2: v25);
  this->m_pOnlyUsedCheck->AddActionSignalTarget_2(this: this->m_pOnlyUsedCheck, a2: this);
  v26 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v26 != nullptr )
    v27 = vgui::TextEntry::TextEntry(this: v26, parent: v20, panelName: "FullPath");
  else
    v27 = nullptr;
  this->m_pFullPath = v27;
  v27->SetEnabled(this: v27, a2: false);
  this->m_pFullPath->SetEditable(this: this->m_pFullPath, a2: false);
  v28 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: v20,
            panelName: "FindButton",
            text: "Find Asset",
            pActionSignalTarget: this,
            pCmd: "FindAsset");
  else
    v29 = nullptr;
  this->m_nCurrentModFilter = -1;
  this->m_pFindAssetButton = v29;
}

} // namespace sceneviewer
