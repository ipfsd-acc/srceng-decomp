// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/picker.cpp
// Functions: 20
// ============================================================

#include "vgui2\matsys_controls\picker.h"

//------------------------------------------------------------------------------
// Address: 0x004806B0
// Name: public: virtual void CPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPicker::OnKeyCodeTyped(CPicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  vgui::IPanel *v5; // esi
  vgui::ListPanel *m_pPickerBrowser; // edi
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
    m_pPickerBrowser = this->m_pPickerBrowser;
    codea = g_pVGuiPanel->__vftable;
    v7 = this->GetVPanel(this);
    v8 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pPickerBrowser->GetVPanel)(
           a1: m_pPickerBrowser,
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
// Address: 0x004C1880
// Name: public: static char const __near * CPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPicker::GetPanelClassName()
{
  return "CPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004C1890
// Name: public: static char const __near * CPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPickerFrame::GetPanelClassName()
{
  return "CPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004C18A0
// Name: PickerBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl PickerBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "choice", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "choice", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004C18E0
// Name: private: void CPicker::RefreshChoiceList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPicker::RefreshChoiceList(CPicker *this@<ecx>, int a2@<ebx>)
{
  vgui::ListPanel *m_pPickerBrowser; // ecx
  int i; // edi
  KeyValues *v5; // eax
  const char *String; // ebx
  const char *v7; // eax
  bool v8; // bl
  vgui::ListPanel *v9; // ecx
  void (__thiscall *SetItemVisible)(vgui::ListPanel *, int, bool); // eax
  vgui::ListPanel *v11; // ecx
  int (__thiscall *NextItem)(vgui::ListPanel *, int); // eax
  int v13; // eax
  char pColumnTitle[512]; // [esp+8h] [ebp-20Ch] BYREF
  BOOL bVisible; // [esp+208h] [ebp-Ch]
  int nTotalCount; // [esp+20Ch] [ebp-8h]
  int nMatchingCount; // [esp+210h] [ebp-4h]

  m_pPickerBrowser = this->m_pPickerBrowser;
  nMatchingCount = 0;
  nTotalCount = 0;
  for ( i = m_pPickerBrowser->FirstItem(this: m_pPickerBrowser);
        i != this->m_pPickerBrowser->InvalidItemID(this: this->m_pPickerBrowser);
        i = ((int (__thiscall *)(vgui::ListPanel *))NextItem)(a1: v11) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pPickerBrowser->GetItem)(
                        a1: this->m_pPickerBrowser,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "choice", defaultValue: defaultValue);
    v8 = true;
    if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    {
      v7 = CUtlString::Get(this: &this->m_Filter);
      if ( V_stristr(pStr: String, pSearch: v7) == nullptr )
        v8 = false;
    }
    v9 = this->m_pPickerBrowser;
    SetItemVisible = v9->SetItemVisible;
    LOBYTE(bVisible) = v8;
    SetItemVisible(this: v9, a2: i, a3: bVisible);
    if ( v8 )
      ++nMatchingCount;
    v11 = this->m_pPickerBrowser;
    NextItem = v11->NextItem;
    ++nTotalCount;
    a2 = i;
  }
  V_snprintf(pDest: pColumnTitle, maxLen: 512, pFormat: "%s (%d/%d)", this->m_pPickerType, nMatchingCount, nTotalCount);
  this->m_pPickerBrowser->SetColumnHeaderText_2(this: this->m_pPickerBrowser, a2: 0, a3: pColumnTitle);
  this->m_pPickerBrowser->SortList(this: this->m_pPickerBrowser);
  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    && this->m_pPickerBrowser->GetItemCount(this: this->m_pPickerBrowser) > 0 )
  {
    v13 = this->m_pPickerBrowser->GetItemIDFromRow(this: this->m_pPickerBrowser, a2: 0);
    this->m_pPickerBrowser->SetSelectedCell(this: this->m_pPickerBrowser, a2: v13, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1A70
// Name: private: virtual void CPicker::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPicker::OnTextChanged(CPicker *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // [esp+Ch] [ebp-4h]

  v3 = this->m_pFilterList->GetTextLength(this: this->m_pFilterList);
  CUtlString::SetLength(this: &this->m_Filter, nLen: v3);
  if ( v3 > 0 )
  {
    v5 = this->m_pFilterList->__vftable;
    v4 = CUtlString::Get(this: &this->m_Filter);
    v5->GetText_2(this: this->m_pFilterList, a2: v4, a3: v3 + 1);
  }
  CPicker::RefreshChoiceList(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004C1AE0
// Name: public: char const __near * CPicker::GetSelectedString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPicker::GetSelectedString(CPicker *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    || this->m_Type != PICKER_CHOICE_STRING )
  {
    return nullptr;
  }
  v3 = this->m_pPickerBrowser->GetSelectedItem(this: this->m_pPickerBrowser, a2: 0);
  v4 = this->m_pPickerBrowser->GetItem(this: this->m_pPickerBrowser, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "value", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x004C1B40
// Name: public: void __near * CPicker::GetSelectedPtr(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CPicker::GetSelectedPtr(CPicker *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    || this->m_Type != PICKER_CHOICE_PTR )
  {
    return nullptr;
  }
  v3 = this->m_pPickerBrowser->GetSelectedItem(this: this->m_pPickerBrowser, a2: 0);
  v4 = this->m_pPickerBrowser->GetItem(this: this->m_pPickerBrowser, a2: v3);
  return KeyValues::GetPtr(this: v4, keyName: "value", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C1BA0
// Name: public: virtual void CPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickerFrame::OnCommand(CPickerFrame *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  CPicker *m_pPicker; // ebx
  int v6; // eax
  CPicker *v7; // ecx
  const char *SelectedString; // eax
  void *SelectedPtr; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Picked");
    else
      v4 = nullptr;
    m_pPicker = this->m_pPicker;
    if ( m_pPicker->m_pPickerBrowser->GetSelectedItemsCount(this: m_pPicker->m_pPickerBrowser) != 0 )
      v6 = m_pPicker->m_pPickerBrowser->GetSelectedItem(this: m_pPicker->m_pPickerBrowser, a2: 0);
    else
      v6 = -1;
    KeyValues::SetInt(this: v4, keyName: "choiceIndex", value: v6);
    v7 = this->m_pPicker;
    if ( v7->m_Type != PICKER_CHOICE_STRING )
    {
      SelectedPtr = CPicker::GetSelectedPtr(this: v7);
      KeyValues::SetPtr(this: v4, keyName: "choice", value: SelectedPtr);
    }
    else
    {
      SelectedString = CPicker::GetSelectedString(this: v7);
      KeyValues::SetString(this: v4, keyName: "choice", value: SelectedString);
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v4, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v4);
    this->CloseModal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1CC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPickerFrame::GetMessageMap(CPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPickerFrame");
  `CPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1CF0
// Name: public: virtual struct PanelAnimationMap __near * CPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPickerFrame::GetAnimMap(CPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004C1D00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPickerFrame::GetKBMap(CPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPickerFrame::GetKBMap'::`2'::s_pMap;
  `CPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPickerFrame");
  `CPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1D30
// Name: public: void CPicker::SetStringList(struct PickerList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPicker::SetStringList(CPicker *this, const PickerList_t *list)
{
  CPicker *v3; // esi
  vgui::ListPanel *m_pPickerBrowser; // ecx
  int v5; // esi
  const char *m_pChoiceString; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  int nCount; // [esp+8h] [ebp-Ch]
  int nItemID; // [esp+Ch] [ebp-8h]
  CPicker *v13; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = this;
  m_pPickerBrowser = this->m_pPickerBrowser;
  v3->m_Type = list->m_Type;
  v13 = v3;
  m_pPickerBrowser->RemoveAll(this: m_pPickerBrowser);
  nCount = list->m_Choices.m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v5 = i;
      m_pChoiceString = list->m_Choices.m_Memory.m_pMemory[i].m_pChoiceString;
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "choice", firstValue: m_pChoiceString);
      else
        v8 = nullptr;
      if ( v13->m_Type != PICKER_CHOICE_STRING )
        KeyValues::SetPtr(this: v8, keyName: "value", value: list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValuePtr);
      else
        KeyValues::SetString(this: v8, keyName: "value", value: list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValue);
      nItemID = v13->m_pPickerBrowser->AddItem(this: v13->m_pPickerBrowser, a2: v8, a3: 0, a4: false, a5: false);
      if ( v13->m_Type == PICKER_CHOICE_STRING )
      {
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(
                  this: v9,
                  setName: "drag",
                  firstKey: "text",
                  firstValue: list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValue);
        else
          v10 = nullptr;
        if ( v13->m_pPickerTextType != nullptr )
          KeyValues::SetString(this: v10, keyName: "texttype", value: v13->m_pPickerTextType);
        vgui::ListPanel::SetItemDragData(this: v13->m_pPickerBrowser, itemID: nItemID, data: v10);
      }
      ++i;
    }
    while ( i < nCount );
    v3 = v13;
  }
  CPicker::RefreshChoiceList(this: v3, a2: (int)list);
}

//------------------------------------------------------------------------------
// Address: 0x004C1ED0
// Name: public: void CPickerFrame::DoModal(struct PickerList_t const __near &,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickerFrame::DoModal(CPickerFrame *this, const PickerList_t *list, KeyValues *pContextKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  CPicker *m_pPicker; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pContextKeyValues;
  CPicker::SetStringList(this: m_pPicker, list);
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C1F20
// Name: public: virtual struct vgui::PanelMessageMap __near * CPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPicker::GetMessageMap(CPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPicker::GetMessageMap'::`2'::s_pMap;
  `CPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPicker");
  `CPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1F50
// Name: public: virtual struct PanelAnimationMap __near * CPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPicker::GetAnimMap(CPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004C1F60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPicker::GetKBMap(CPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPicker::GetKBMap'::`2'::s_pMap;
  `CPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPicker");
  `CPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C2000
// Name: public: static void CPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPicker");
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
// Address: 0x004C2090
// Name: public: CPicker::CPicker(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPicker *__thiscall CPicker::CPicker(
        CPicker *this,
        vgui::Panel *pParent,
        const char *pColumnHeader,
        const char *pTextType)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  const char *m_pPickerType; // [esp-Ch] [ebp-14h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "Picker");
  this->__vftable = (CPicker_vtbl *)&CPicker::`vftable';
  if ( `CPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CPicker::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPicker");
    v5->pfnClassName = CPicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPicker::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPicker");
    v6->pfnClassName = CPicker::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPicker::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPicker");
    v7->pfnClassName = CPicker::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  this->m_pPickerType = pColumnHeader;
  this->m_pPickerTextType = pTextType;
  v8 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "Browser");
  else
    v9 = nullptr;
  m_pPickerType = this->m_pPickerType;
  this->m_pPickerBrowser = v9;
  v9->AddColumnHeader(this: v9, a2: 0, a3: "choice", a4: m_pPickerType, a5: 52, a6: 0);
  this->m_pPickerBrowser->SetSelectIndividualCells(this: this->m_pPickerBrowser, a2: true);
  this->m_pPickerBrowser->SetEmptyListText_2(this: this->m_pPickerBrowser, a2: "Nothing to pick");
  this->m_pPickerBrowser->SetDragEnabled(this: this->m_pPickerBrowser, a2: true);
  this->m_pPickerBrowser->AddActionSignalTarget_2(this: this->m_pPickerBrowser, a2: this);
  this->m_pPickerBrowser->SetSortFunc(this: this->m_pPickerBrowser, a2: 0, a3: PickerBrowserSortFunc);
  this->m_pPickerBrowser->SetSortColumn(this: this->m_pPickerBrowser, a2: 0);
  v10 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v10 != nullptr )
    v11 = vgui::TextEntry::TextEntry(this: v10, parent: this, panelName: "FilterList");
  else
    v11 = nullptr;
  this->m_pFilterList = v11;
  v11->AddActionSignalTarget_2(this: v11, a2: this);
  this->m_pFilterList->RequestFocus(this: this->m_pFilterList, a2: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/picker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C2280
// Name: public: CPickerFrame::CPickerFrame(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPickerFrame *__thiscall CPickerFrame::CPickerFrame(
        CPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pPickerType,
        const char *pTextType)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  CPicker *v9; // eax
  CPicker *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPickerFrame_vtbl *)&CPickerFrame::`vftable';
  if ( `CPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPickerFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CPickerFrame");
    v6->pfnClassName = CPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPickerFrame");
    v7->pfnClassName = CPickerFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CPickerFrame");
    v8->pfnClassName = CPickerFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v9 = (CPicker *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v9 != nullptr )
    v10 = CPicker::CPicker(this: v9, pParent: this, pColumnHeader: pPickerType, pTextType);
  else
    v10 = nullptr;
  this->m_pPicker = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v12 = nullptr;
  this->m_pOpenButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v14 = nullptr;
  this->m_pCancelButton = v14;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/pickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104C90E0
// Name: public: static char const __near * CPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPicker::GetPanelClassName()
{
  return "CPicker";
}

//------------------------------------------------------------------------------
// Address: 0x104C90F0
// Name: public: static char const __near * CPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPickerFrame::GetPanelClassName()
{
  return "CPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104C9100
// Name: PickerBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl PickerBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "choice", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "choice", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104C9140
// Name: public: virtual void CPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPicker::OnKeyCodeTyped(CPicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  vgui::IPanel *v5; // esi
  vgui::ListPanel *m_pPickerBrowser; // edi
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
    m_pPickerBrowser = this->m_pPickerBrowser;
    codea = g_pVGuiPanel->__vftable;
    v7 = this->GetVPanel(this);
    v8 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pPickerBrowser->GetVPanel)(
           a1: m_pPickerBrowser,
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
// Address: 0x104C91E0
// Name: private: void CPicker::RefreshChoiceList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPicker::RefreshChoiceList(CPicker *this@<ecx>, int a2@<ebx>)
{
  vgui::ListPanel *m_pPickerBrowser; // ecx
  int i; // edi
  KeyValues *v5; // eax
  char *String; // ebx
  const char *v7; // eax
  const char *v8; // ecx
  bool v9; // bl
  vgui::ListPanel *v10; // ecx
  void (__thiscall *SetItemVisible)(vgui::ListPanel *, int, bool); // eax
  vgui::ListPanel *v12; // ecx
  int (__thiscall *NextItem)(vgui::ListPanel *, int); // eax
  int v14; // eax
  char pColumnTitle[512]; // [esp+8h] [ebp-20Ch] BYREF
  BOOL bVisible; // [esp+208h] [ebp-Ch]
  int nTotalCount; // [esp+20Ch] [ebp-8h]
  int nMatchingCount; // [esp+210h] [ebp-4h]

  m_pPickerBrowser = this->m_pPickerBrowser;
  nMatchingCount = 0;
  nTotalCount = 0;
  for ( i = m_pPickerBrowser->FirstItem(this: m_pPickerBrowser);
        i != this->m_pPickerBrowser->InvalidItemID(this: this->m_pPickerBrowser);
        i = ((int (__thiscall *)(vgui::ListPanel *))NextItem)(a1: v12) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pPickerBrowser->GetItem)(
                        a1: this->m_pPickerBrowser,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "choice", defaultValue: &var);
    v9 = true;
    if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    {
      v7 = CUtlString::Get(this: &this->m_Filter);
      if ( V_stristr(a1: v8, a2: String, pStr: String, pSearch: v7) == nullptr )
        v9 = false;
    }
    v10 = this->m_pPickerBrowser;
    SetItemVisible = v10->SetItemVisible;
    LOBYTE(bVisible) = v9;
    SetItemVisible(this: v10, a2: i, a3: bVisible);
    if ( v9 )
      ++nMatchingCount;
    v12 = this->m_pPickerBrowser;
    NextItem = v12->NextItem;
    ++nTotalCount;
    a2 = i;
  }
  V_snprintf(
    pDest: pColumnTitle,
    maxLen: 0x200u,
    pFormat: "%s (%d/%d)",
    this->m_pPickerType,
    nMatchingCount,
    nTotalCount);
  this->m_pPickerBrowser->SetColumnHeaderText_2(this: this->m_pPickerBrowser, a2: 0, a3: pColumnTitle);
  this->m_pPickerBrowser->SortList(this: this->m_pPickerBrowser);
  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    && this->m_pPickerBrowser->GetItemCount(this: this->m_pPickerBrowser) > 0 )
  {
    v14 = this->m_pPickerBrowser->GetItemIDFromRow(this: this->m_pPickerBrowser, a2: 0);
    this->m_pPickerBrowser->SetSelectedCell(this: this->m_pPickerBrowser, a2: v14, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C9370
// Name: private: virtual void CPicker::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPicker::OnTextChanged(CPicker *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // [esp+Ch] [ebp-4h]

  v3 = this->m_pFilterList->GetTextLength(this: this->m_pFilterList);
  CUtlString::SetLength(this: &this->m_Filter, nLen: v3);
  if ( v3 > 0 )
  {
    v5 = this->m_pFilterList->__vftable;
    v4 = CUtlString::Get(this: &this->m_Filter);
    v5->GetText_2(this: this->m_pFilterList, a2: v4, a3: v3 + 1);
  }
  CPicker::RefreshChoiceList(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104C93E0
// Name: public: char const __near * CPicker::GetSelectedString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CPicker::GetSelectedString(CPicker *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    || this->m_Type != PICKER_CHOICE_STRING )
  {
    return nullptr;
  }
  v3 = this->m_pPickerBrowser->GetSelectedItem(this: this->m_pPickerBrowser, a2: 0);
  v4 = this->m_pPickerBrowser->GetItem(this: this->m_pPickerBrowser, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "value", defaultValue: &var);
}

//------------------------------------------------------------------------------
// Address: 0x104C9440
// Name: public: void __near * CPicker::GetSelectedPtr(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CPicker::GetSelectedPtr(CPicker *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    || this->m_Type != PICKER_CHOICE_PTR )
  {
    return nullptr;
  }
  v3 = this->m_pPickerBrowser->GetSelectedItem(this: this->m_pPickerBrowser, a2: 0);
  v4 = this->m_pPickerBrowser->GetItem(this: this->m_pPickerBrowser, a2: v3);
  return KeyValues::GetPtr(this: v4, keyName: "value", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104C94A0
// Name: public: virtual void CPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickerFrame::OnCommand(CPickerFrame *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  CPicker *m_pPicker; // ebx
  int v6; // eax
  CPicker *v7; // ecx
  char *SelectedString; // eax
  void *SelectedPtr; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Picked");
    else
      v4 = nullptr;
    m_pPicker = this->m_pPicker;
    if ( m_pPicker->m_pPickerBrowser->GetSelectedItemsCount(this: m_pPicker->m_pPickerBrowser) != 0 )
      v6 = m_pPicker->m_pPickerBrowser->GetSelectedItem(this: m_pPicker->m_pPickerBrowser, a2: 0);
    else
      v6 = -1;
    KeyValues::SetInt(this: v4, keyName: "choiceIndex", value: v6);
    v7 = this->m_pPicker;
    if ( v7->m_Type != PICKER_CHOICE_STRING )
    {
      SelectedPtr = CPicker::GetSelectedPtr(this: v7);
      KeyValues::SetPtr(this: v4, keyName: "choice", value: SelectedPtr);
    }
    else
    {
      SelectedString = CPicker::GetSelectedString(this: v7);
      KeyValues::SetString(this: v4, keyName: "choice", value: SelectedString);
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v4, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v4);
    this->CloseModal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C95C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPickerFrame::GetMessageMap(CPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPickerFrame");
  `CPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C95F0
// Name: public: virtual struct PanelAnimationMap __near * CPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPickerFrame::GetAnimMap(CPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104C9600
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPickerFrame::GetKBMap(CPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPickerFrame::GetKBMap'::`2'::s_pMap;
  `CPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPickerFrame");
  `CPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C9630
// Name: public: void CPicker::SetStringList(struct PickerList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPicker::SetStringList(CPicker *this, const PickerList_t *list)
{
  CPicker *v3; // esi
  vgui::ListPanel *m_pPickerBrowser; // ecx
  int v5; // esi
  char *m_pChoiceString; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  int nCount; // [esp+8h] [ebp-Ch]
  int nItemID; // [esp+Ch] [ebp-8h]
  CPicker *v13; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = this;
  m_pPickerBrowser = this->m_pPickerBrowser;
  v3->m_Type = list->m_Type;
  v13 = v3;
  m_pPickerBrowser->RemoveAll(this: m_pPickerBrowser);
  nCount = list->m_Choices.m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v5 = i;
      m_pChoiceString = (char *)list->m_Choices.m_Memory.m_pMemory[i].m_pChoiceString;
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "choice", firstValue: m_pChoiceString);
      else
        v8 = nullptr;
      if ( v13->m_Type != PICKER_CHOICE_STRING )
        KeyValues::SetPtr(this: v8, keyName: "value", value: list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValuePtr);
      else
        KeyValues::SetString(
          this: v8,
          keyName: "value",
          value: (char *)list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValue);
      nItemID = v13->m_pPickerBrowser->AddItem(this: v13->m_pPickerBrowser, a2: v8, a3: 0, a4: false, a5: false);
      if ( v13->m_Type == PICKER_CHOICE_STRING )
      {
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(
                  this: v9,
                  setName: "drag",
                  firstKey: "text",
                  firstValue: (char *)list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValue);
        else
          v10 = nullptr;
        if ( v13->m_pPickerTextType != nullptr )
          KeyValues::SetString(this: v10, keyName: "texttype", value: (char *)v13->m_pPickerTextType);
        vgui::ListPanel::SetItemDragData(this: v13->m_pPickerBrowser, itemID: nItemID, data: v10);
      }
      ++i;
    }
    while ( i < nCount );
    v3 = v13;
  }
  CPicker::RefreshChoiceList(this: v3, a2: (int)list);
}

//------------------------------------------------------------------------------
// Address: 0x104C97D0
// Name: public: void CPickerFrame::DoModal(struct PickerList_t const __near &,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickerFrame::DoModal(CPickerFrame *this, const PickerList_t *list, KeyValues *pContextKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  CPicker *m_pPicker; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pContextKeyValues;
  CPicker::SetStringList(this: m_pPicker, list);
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x104C9820
// Name: public: virtual struct vgui::PanelMessageMap __near * CPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPicker::GetMessageMap(CPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPicker::GetMessageMap'::`2'::s_pMap;
  `CPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPicker");
  `CPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C9850
// Name: public: virtual struct PanelAnimationMap __near * CPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPicker::GetAnimMap(CPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CPicker");
}

//------------------------------------------------------------------------------
// Address: 0x104C9860
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPicker::GetKBMap(CPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPicker::GetKBMap'::`2'::s_pMap;
  `CPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPicker");
  `CPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C9900
// Name: public: static void CPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPicker");
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
// Address: 0x104C9990
// Name: public: CPicker::CPicker(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPicker *__thiscall CPicker::CPicker(
        CPicker *this,
        vgui::Panel *pParent,
        const char *pColumnHeader,
        const char *pTextType)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  const char *m_pPickerType; // [esp-Ch] [ebp-14h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "Picker");
  this->__vftable = (CPicker_vtbl *)&CPicker::`vftable';
  if ( `CPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CPicker::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPicker");
    v5->pfnClassName = CPicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPicker::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPicker");
    v6->pfnClassName = CPicker::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPicker::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPicker");
    v7->pfnClassName = CPicker::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  this->m_pPickerType = pColumnHeader;
  this->m_pPickerTextType = pTextType;
  v8 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "Browser");
  else
    v9 = nullptr;
  m_pPickerType = this->m_pPickerType;
  this->m_pPickerBrowser = v9;
  v9->AddColumnHeader(this: v9, a2: 0, a3: "choice", a4: m_pPickerType, a5: 52, a6: 0);
  this->m_pPickerBrowser->SetSelectIndividualCells(this: this->m_pPickerBrowser, a2: true);
  this->m_pPickerBrowser->SetEmptyListText_2(this: this->m_pPickerBrowser, a2: "Nothing to pick");
  this->m_pPickerBrowser->SetDragEnabled(this: this->m_pPickerBrowser, a2: true);
  this->m_pPickerBrowser->AddActionSignalTarget_2(this: this->m_pPickerBrowser, a2: this);
  this->m_pPickerBrowser->SetSortFunc(this: this->m_pPickerBrowser, a2: 0, a3: PickerBrowserSortFunc);
  this->m_pPickerBrowser->SetSortColumn(this: this->m_pPickerBrowser, a2: 0);
  v10 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v10 != nullptr )
    v11 = vgui::TextEntry::TextEntry(this: v10, parent: this, panelName: (vgui::Panel *)"FilterList");
  else
    v11 = nullptr;
  this->m_pFilterList = v11;
  v11->AddActionSignalTarget_2(this: v11, a2: this);
  this->m_pFilterList->RequestFocus(this: this->m_pFilterList, a2: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/picker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C9B80
// Name: public: CPickerFrame::CPickerFrame(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPickerFrame *__thiscall CPickerFrame::CPickerFrame(
        CPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pPickerType,
        const char *pTextType)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  CPicker *v9; // eax
  CPicker *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPickerFrame_vtbl *)&CPickerFrame::`vftable';
  if ( `CPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPickerFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CPickerFrame");
    v6->pfnClassName = CPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPickerFrame");
    v7->pfnClassName = CPickerFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CPickerFrame");
    v8->pfnClassName = CPickerFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v9 = (CPicker *)operator new(nSize: 0x1ACu);
  if ( v9 != nullptr )
    v10 = CPicker::CPicker(this: v9, pParent: this, pColumnHeader: pPickerType, pTextType);
  else
    v10 = nullptr;
  this->m_pPicker = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v12 = nullptr;
  this->m_pOpenButton = v12;
  v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v14 = nullptr;
  this->m_pCancelButton = v14;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/pickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004A40D0
// Name: public: virtual void CPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPicker::OnKeyCodeTyped(CPicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  vgui::IPanel *v5; // esi
  vgui::ListPanel *m_pPickerBrowser; // edi
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
    m_pPickerBrowser = this->m_pPickerBrowser;
    codea = g_pVGuiPanel->__vftable;
    v7 = this->GetVPanel(this);
    v8 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pPickerBrowser->GetVPanel)(
           a1: m_pPickerBrowser,
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
// Address: 0x004C5630
// Name: public: static char const __near * CPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPicker::GetPanelClassName()
{
  return "CPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004C5640
// Name: public: static char const __near * CPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPickerFrame::GetPanelClassName()
{
  return "CPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004C5650
// Name: PickerBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl PickerBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "choice", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "choice", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004C5690
// Name: private: void CPicker::RefreshChoiceList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPicker::RefreshChoiceList(CPicker *this@<ecx>, int a2@<ebx>)
{
  vgui::ListPanel *m_pPickerBrowser; // ecx
  int i; // edi
  KeyValues *v5; // eax
  const char *String; // ebx
  const char *v7; // eax
  bool v8; // bl
  vgui::ListPanel *v9; // ecx
  void (__thiscall *SetItemVisible)(vgui::ListPanel *, int, bool); // eax
  vgui::ListPanel *v11; // ecx
  int (__thiscall *NextItem)(vgui::ListPanel *, int); // eax
  int v13; // eax
  char pColumnTitle[512]; // [esp+8h] [ebp-20Ch] BYREF
  BOOL bVisible; // [esp+208h] [ebp-Ch]
  int nTotalCount; // [esp+20Ch] [ebp-8h]
  int nMatchingCount; // [esp+210h] [ebp-4h]

  m_pPickerBrowser = this->m_pPickerBrowser;
  nMatchingCount = 0;
  nTotalCount = 0;
  for ( i = m_pPickerBrowser->FirstItem(this: m_pPickerBrowser);
        i != this->m_pPickerBrowser->InvalidItemID(this: this->m_pPickerBrowser);
        i = ((int (__thiscall *)(vgui::ListPanel *))NextItem)(a1: v11) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pPickerBrowser->GetItem)(
                        a1: this->m_pPickerBrowser,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "choice", defaultValue: defaultValue);
    v8 = true;
    if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    {
      v7 = CUtlString::Get(this: &this->m_Filter);
      if ( V_stristr(pStr: String, pSearch: v7) == nullptr )
        v8 = false;
    }
    v9 = this->m_pPickerBrowser;
    SetItemVisible = v9->SetItemVisible;
    LOBYTE(bVisible) = v8;
    SetItemVisible(this: v9, a2: i, a3: bVisible);
    if ( v8 )
      ++nMatchingCount;
    v11 = this->m_pPickerBrowser;
    NextItem = v11->NextItem;
    ++nTotalCount;
    a2 = i;
  }
  V_snprintf(pDest: pColumnTitle, maxLen: 512, pFormat: "%s (%d/%d)", this->m_pPickerType, nMatchingCount, nTotalCount);
  this->m_pPickerBrowser->SetColumnHeaderText_2(this: this->m_pPickerBrowser, a2: 0, a3: pColumnTitle);
  this->m_pPickerBrowser->SortList(this: this->m_pPickerBrowser);
  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    && this->m_pPickerBrowser->GetItemCount(this: this->m_pPickerBrowser) > 0 )
  {
    v13 = this->m_pPickerBrowser->GetItemIDFromRow(this: this->m_pPickerBrowser, a2: 0);
    this->m_pPickerBrowser->SetSelectedCell(this: this->m_pPickerBrowser, a2: v13, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5820
// Name: private: virtual void CPicker::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPicker::OnTextChanged(CPicker *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // [esp+Ch] [ebp-4h]

  v3 = this->m_pFilterList->GetTextLength(this: this->m_pFilterList);
  CUtlString::SetLength(this: &this->m_Filter, nLen: v3);
  if ( v3 > 0 )
  {
    v5 = this->m_pFilterList->__vftable;
    v4 = CUtlString::Get(this: &this->m_Filter);
    v5->GetText_2(this: this->m_pFilterList, a2: v4, a3: v3 + 1);
  }
  CPicker::RefreshChoiceList(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004C5890
// Name: public: char const __near * CPicker::GetSelectedString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPicker::GetSelectedString(CPicker *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    || this->m_Type != PICKER_CHOICE_STRING )
  {
    return nullptr;
  }
  v3 = this->m_pPickerBrowser->GetSelectedItem(this: this->m_pPickerBrowser, a2: 0);
  v4 = this->m_pPickerBrowser->GetItem(this: this->m_pPickerBrowser, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "value", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x004C58F0
// Name: public: void __near * CPicker::GetSelectedPtr(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CPicker::GetSelectedPtr(CPicker *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pPickerBrowser->GetSelectedItemsCount(this: this->m_pPickerBrowser) == 0
    || this->m_Type != PICKER_CHOICE_PTR )
  {
    return nullptr;
  }
  v3 = this->m_pPickerBrowser->GetSelectedItem(this: this->m_pPickerBrowser, a2: 0);
  v4 = this->m_pPickerBrowser->GetItem(this: this->m_pPickerBrowser, a2: v3);
  return KeyValues::GetPtr(this: v4, keyName: "value", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C5950
// Name: public: virtual void CPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickerFrame::OnCommand(CPickerFrame *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  CPicker *m_pPicker; // ebx
  int v6; // eax
  CPicker *v7; // ecx
  const char *SelectedString; // eax
  void *SelectedPtr; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Picked");
    else
      v4 = nullptr;
    m_pPicker = this->m_pPicker;
    if ( m_pPicker->m_pPickerBrowser->GetSelectedItemsCount(this: m_pPicker->m_pPickerBrowser) != 0 )
      v6 = m_pPicker->m_pPickerBrowser->GetSelectedItem(this: m_pPicker->m_pPickerBrowser, a2: 0);
    else
      v6 = -1;
    KeyValues::SetInt(this: v4, keyName: "choiceIndex", value: v6);
    v7 = this->m_pPicker;
    if ( v7->m_Type != PICKER_CHOICE_STRING )
    {
      SelectedPtr = CPicker::GetSelectedPtr(this: v7);
      KeyValues::SetPtr(this: v4, keyName: "choice", value: SelectedPtr);
    }
    else
    {
      SelectedString = CPicker::GetSelectedString(this: v7);
      KeyValues::SetString(this: v4, keyName: "choice", value: SelectedString);
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v4, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v4);
    this->CloseModal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5A70
// Name: public: virtual struct vgui::PanelMessageMap __near * CPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPickerFrame::GetMessageMap(CPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPickerFrame");
  `CPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5AA0
// Name: public: virtual struct PanelAnimationMap __near * CPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPickerFrame::GetAnimMap(CPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004C5AB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPickerFrame::GetKBMap(CPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPickerFrame::GetKBMap'::`2'::s_pMap;
  `CPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPickerFrame");
  `CPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5AE0
// Name: public: void CPicker::SetStringList(struct PickerList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPicker::SetStringList(CPicker *this, const PickerList_t *list)
{
  CPicker *v3; // esi
  vgui::ListPanel *m_pPickerBrowser; // ecx
  int v5; // esi
  const char *m_pChoiceString; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  int nCount; // [esp+8h] [ebp-Ch]
  int nItemID; // [esp+Ch] [ebp-8h]
  CPicker *v13; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = this;
  m_pPickerBrowser = this->m_pPickerBrowser;
  v3->m_Type = list->m_Type;
  v13 = v3;
  m_pPickerBrowser->RemoveAll(this: m_pPickerBrowser);
  nCount = list->m_Choices.m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v5 = i;
      m_pChoiceString = list->m_Choices.m_Memory.m_pMemory[i].m_pChoiceString;
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: "node", firstKey: "choice", firstValue: m_pChoiceString);
      else
        v8 = nullptr;
      if ( v13->m_Type != PICKER_CHOICE_STRING )
        KeyValues::SetPtr(this: v8, keyName: "value", value: list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValuePtr);
      else
        KeyValues::SetString(this: v8, keyName: "value", value: list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValue);
      nItemID = v13->m_pPickerBrowser->AddItem(this: v13->m_pPickerBrowser, a2: v8, a3: 0, a4: false, a5: false);
      if ( v13->m_Type == PICKER_CHOICE_STRING )
      {
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(
                  this: v9,
                  setName: "drag",
                  firstKey: "text",
                  firstValue: list->m_Choices.m_Memory.m_pMemory[v5].m_pChoiceValue);
        else
          v10 = nullptr;
        if ( v13->m_pPickerTextType != nullptr )
          KeyValues::SetString(this: v10, keyName: "texttype", value: v13->m_pPickerTextType);
        vgui::ListPanel::SetItemDragData(this: v13->m_pPickerBrowser, itemID: nItemID, data: v10);
      }
      ++i;
    }
    while ( i < nCount );
    v3 = v13;
  }
  CPicker::RefreshChoiceList(this: v3, a2: (int)list);
}

//------------------------------------------------------------------------------
// Address: 0x004C5C80
// Name: public: void CPickerFrame::DoModal(struct PickerList_t const __near &,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPickerFrame::DoModal(CPickerFrame *this, const PickerList_t *list, KeyValues *pContextKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  CPicker *m_pPicker; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pContextKeyValues;
  CPicker::SetStringList(this: m_pPicker, list);
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C5CD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPicker::GetMessageMap(CPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPicker::GetMessageMap'::`2'::s_pMap;
  `CPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPicker");
  `CPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5D00
// Name: public: virtual struct PanelAnimationMap __near * CPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPicker::GetAnimMap(CPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004C5D10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPicker::GetKBMap(CPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPicker::GetKBMap'::`2'::s_pMap;
  `CPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPicker");
  `CPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5DB0
// Name: public: static void CPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPicker");
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
// Address: 0x004C5E40
// Name: public: CPicker::CPicker(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPicker *__thiscall CPicker::CPicker(
        CPicker *this,
        vgui::Panel *pParent,
        const char *pColumnHeader,
        const char *pTextType)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  const char *m_pPickerType; // [esp-Ch] [ebp-14h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "Picker");
  this->__vftable = (CPicker_vtbl *)&CPicker::`vftable';
  if ( `CPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CPicker::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPicker");
    v5->pfnClassName = CPicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPicker::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPicker");
    v6->pfnClassName = CPicker::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPicker::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPicker");
    v7->pfnClassName = CPicker::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  this->m_pPickerType = pColumnHeader;
  this->m_pPickerTextType = pTextType;
  v8 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "Browser");
  else
    v9 = nullptr;
  m_pPickerType = this->m_pPickerType;
  this->m_pPickerBrowser = v9;
  v9->AddColumnHeader(this: v9, a2: 0, a3: "choice", a4: m_pPickerType, a5: 52, a6: 0);
  this->m_pPickerBrowser->SetSelectIndividualCells(this: this->m_pPickerBrowser, a2: true);
  this->m_pPickerBrowser->SetEmptyListText_2(this: this->m_pPickerBrowser, a2: "Nothing to pick");
  this->m_pPickerBrowser->SetDragEnabled(this: this->m_pPickerBrowser, a2: true);
  this->m_pPickerBrowser->AddActionSignalTarget_2(this: this->m_pPickerBrowser, a2: this);
  this->m_pPickerBrowser->SetSortFunc(this: this->m_pPickerBrowser, a2: 0, a3: PickerBrowserSortFunc);
  this->m_pPickerBrowser->SetSortColumn(this: this->m_pPickerBrowser, a2: 0);
  v10 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v10 != nullptr )
    v11 = vgui::TextEntry::TextEntry(this: v10, parent: this, panelName: "FilterList");
  else
    v11 = nullptr;
  this->m_pFilterList = v11;
  v11->AddActionSignalTarget_2(this: v11, a2: this);
  this->m_pFilterList->RequestFocus(this: this->m_pFilterList, a2: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/picker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C6030
// Name: public: CPickerFrame::CPickerFrame(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPickerFrame *__thiscall CPickerFrame::CPickerFrame(
        CPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pPickerType,
        const char *pTextType)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  CPicker *v9; // eax
  CPicker *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPickerFrame_vtbl *)&CPickerFrame::`vftable';
  if ( `CPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPickerFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CPickerFrame");
    v6->pfnClassName = CPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPickerFrame");
    v7->pfnClassName = CPickerFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CPickerFrame");
    v8->pfnClassName = CPickerFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v9 = (CPicker *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v9 != nullptr )
    v10 = CPicker::CPicker(this: v9, pParent: this, pColumnHeader: pPickerType, pTextType);
  else
    v10 = nullptr;
  this->m_pPicker = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v12 = nullptr;
  this->m_pOpenButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v14 = nullptr;
  this->m_pCancelButton = v14;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/pickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

} // namespace sceneviewer
