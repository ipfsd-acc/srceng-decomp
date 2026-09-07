// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmepicker.cpp
// Functions: 18
// ============================================================

#include "vgui2\dme_controls\dmepicker.h"

//------------------------------------------------------------------------------
// Address: 0x00480650
// Name: public: static char const __near * CDmePicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePicker::GetPanelClassName()
{
  return "CDmePicker";
}

//------------------------------------------------------------------------------
// Address: 0x00480660
// Name: public: static char const __near * CDmePickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePickerFrame::GetPanelClassName()
{
  return "CDmePickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x00480670
// Name: DmeBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DmeBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "dme", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "dme", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00480750
// Name: private: void CDmePicker::RefreshDmeList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePicker::RefreshDmeList(CDmePicker *this@<ecx>, int a2@<ebx>)
{
  vgui::ListPanel *m_pDmeBrowser; // ecx
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
  BOOL bIsVisible; // [esp+208h] [ebp-Ch]
  int nTotalCount; // [esp+20Ch] [ebp-8h]
  int nMatchingElements; // [esp+210h] [ebp-4h]

  m_pDmeBrowser = this->m_pDmeBrowser;
  nMatchingElements = 0;
  nTotalCount = 0;
  for ( i = m_pDmeBrowser->FirstItem(this: m_pDmeBrowser);
        i != this->m_pDmeBrowser->InvalidItemID(this: this->m_pDmeBrowser);
        i = ((int (__thiscall *)(vgui::ListPanel *))NextItem)(a1: v11) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pDmeBrowser->GetItem)(
                        a1: this->m_pDmeBrowser,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "dme", defaultValue: defaultValue);
    v8 = true;
    if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    {
      v7 = CUtlString::Get(this: &this->m_Filter);
      if ( V_stristr(pStr: String, pSearch: v7) == nullptr )
        v8 = false;
    }
    v9 = this->m_pDmeBrowser;
    SetItemVisible = v9->SetItemVisible;
    LOBYTE(bIsVisible) = v8;
    SetItemVisible(this: v9, a2: i, a3: bIsVisible);
    if ( v8 )
      ++nMatchingElements;
    v11 = this->m_pDmeBrowser;
    NextItem = v11->NextItem;
    ++nTotalCount;
    a2 = i;
  }
  this->m_pDmeBrowser->SortList(this: this->m_pDmeBrowser);
  V_snprintf(pDest: pColumnTitle, maxLen: 512, pFormat: "%s (%d/%d)", "Dme Elements", nMatchingElements, nTotalCount);
  this->m_pDmeBrowser->SetColumnHeaderText_2(this: this->m_pDmeBrowser, a2: 0, a3: pColumnTitle);
  if ( this->m_pDmeBrowser->GetItemCount(this: this->m_pDmeBrowser) > 0
    && this->m_pDmeBrowser->GetSelectedItemsCount(this: this->m_pDmeBrowser) == 0 )
  {
    v13 = this->m_pDmeBrowser->GetItemIDFromRow(this: this->m_pDmeBrowser, a2: 0);
    this->m_pDmeBrowser->SetSelectedCell(this: this->m_pDmeBrowser, a2: v13, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004808E0
// Name: private: virtual void CDmePicker::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePicker::OnTextChanged(CDmePicker *this@<ecx>, int a2@<ebx>)
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
  CDmePicker::RefreshDmeList(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00480950
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePickerFrame::GetMessageMap(CDmePickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePickerFrame::GetMessageMap'::`2'::s_pMap;
  `CDmePickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePickerFrame");
  `CDmePickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480980
// Name: public: virtual struct PanelAnimationMap __near * CDmePickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePickerFrame::GetAnimMap(CDmePickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00480990
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePickerFrame::GetKBMap(CDmePickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePickerFrame::GetKBMap'::`2'::s_pMap;
  `CDmePickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePickerFrame");
  `CDmePickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004809C0
// Name: public: void CDmePickerFrame::DoModal(class CUtlVector<struct DmePickerInfo_t,class CUtlMemory<struct DmePickerInfo_t,int>> const __near &,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePickerFrame::DoModal(
        CDmePickerFrame *this,
        const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *vec,
        KeyValues *pKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  CDmePicker *m_pPicker; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pKeyValues;
  m_pPicker->Activate(this: m_pPicker, a2: vec);
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: vec->m_Size != 0);
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x00480A30
// Name: public: virtual void CDmePicker::Activate(class CUtlVector<struct DmePickerInfo_t,class CUtlMemory<struct DmePickerInfo_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePicker::Activate(
        CDmePicker *this,
        const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *vec)
{
  CDmePicker *v2; // esi
  const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  const char *m_pAsString; // esi
  const char *m_pChoiceString; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  int nCount; // [esp+Ch] [ebp-Ch]
  const char *pElementName; // [esp+14h] [ebp-4h]

  v2 = this;
  this->m_pDmeBrowser->RemoveAll(this: this->m_pDmeBrowser);
  v3 = vec;
  v4 = 0;
  nCount = vec->m_Size;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Memory.m_pMemory[v4].m_hElement);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        pElementName = m_pAsString;
      }
      else
      {
        pElementName = "<null element>";
      }
      m_pChoiceString = v3->m_Memory.m_pMemory[v4].m_pChoiceString;
      if ( m_pChoiceString == nullptr )
        m_pChoiceString = pElementName;
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v10 = v9 != nullptr
          ? KeyValues::KeyValues(this: v9, setName: "node", firstKey: "dme", firstValue: m_pChoiceString)
          : nullptr;
      KeyValues::SetInt(this: v10, keyName: "dmeHandle", value: v3->m_Memory.m_pMemory[v4].m_hElement);
      v3 = (const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *)this->m_pDmeBrowser->AddItem(
                                                                                   this: this->m_pDmeBrowser,
                                                                                   a2: v10,
                                                                                   a3: 0,
                                                                                   a4: false,
                                                                                   a5: false);
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v12 = v11 != nullptr
          ? KeyValues::KeyValues(this: v11, setName: "drag", firstKey: "text", firstValue: pElementName)
          : nullptr;
      KeyValues::SetString(this: v12, keyName: "texttype", value: "dmeName");
      KeyValues::SetInt(this: v12, keyName: "dmeelement", value: vec->m_Memory.m_pMemory[v4].m_hElement);
      vgui::ListPanel::SetItemDragData(this: this->m_pDmeBrowser, itemID: (int)v3, data: v12);
      if ( ++v4 >= nCount )
        break;
      v3 = vec;
    }
    v2 = this;
  }
  CDmePicker::RefreshDmeList(this: v2, a2: (int)v3);
}

//------------------------------------------------------------------------------
// Address: 0x00480BE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePicker::GetMessageMap(CDmePicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePicker::GetMessageMap'::`2'::s_pMap;
  `CDmePicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
  `CDmePicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480C10
// Name: public: virtual struct PanelAnimationMap __near * CDmePicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePicker::GetAnimMap(CDmePicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePicker");
}

//------------------------------------------------------------------------------
// Address: 0x00480C20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePicker::GetKBMap(CDmePicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePicker::GetKBMap'::`2'::s_pMap;
  `CDmePicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePicker");
  `CDmePicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480C50
// Name: public: class CDmElement __near * CDmePicker::GetSelectedDme(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmePicker::GetSelectedDme(CDmePicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  if ( this->m_pDmeBrowser->GetSelectedItemsCount(this: this->m_pDmeBrowser) != 0
    && (v2 = this->m_pDmeBrowser->GetSelectedItem(this: this->m_pDmeBrowser, a2: 0),
        v3 = this->m_pDmeBrowser->GetItem(this: this->m_pDmeBrowser, a2: v2),
        Int = KeyValues::GetInt(this: v3, keyName: "dmeHandle", defaultValue: -1),
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
        v6 = v5,
        v5 != nullptr)
    && v5->IsA(this: v5, a2: CDmElement::m_classType) )
  {
    return v6;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480CD0
// Name: public: virtual void CDmePickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePickerFrame::OnCommand(CDmePickerFrame *this, const char *pCommand)
{
  CExpressionCalculator *SelectedDme; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  int BufferType; // eax
  KeyValues *v7; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Open") == 0 )
  {
    SelectedDme = (CExpressionCalculator *)CDmePicker::GetSelectedDme(this: this->m_pPicker);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DmeSelected");
    else
      v5 = nullptr;
    if ( SelectedDme != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: SelectedDme);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v5, keyName: "dme", value: BufferType);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_10:
    this->PostActionSignal(this, a2: v5);
    this->CloseModal(this);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Cancel") == 0 )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v5 = KeyValues::KeyValues(this: v7, setName: "DmeSelectionCancelled");
    else
      v5 = nullptr;
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_10;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x00480E70
// Name: public: static void CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
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
// Address: 0x00480F00
// Name: public: CDmePicker::CDmePicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePicker *__thiscall CDmePicker::CDmePicker(CDmePicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ListPanel *v6; // eax
  vgui::ListPanel *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "DmePicker");
  this->__vftable = (CDmePicker_vtbl *)&CDmePicker::`vftable';
  if ( `CDmePicker::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
    v3->pfnClassName = CDmePicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDmePicker");
    v4->pfnClassName = CDmePicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePicker");
    v5->pfnClassName = CDmePicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  v6 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v6 != nullptr )
    v7 = vgui::ListPanel::ListPanel(this: v6, parent: this, panelName: "DmeBrowser");
  else
    v7 = nullptr;
  this->m_pDmeBrowser = v7;
  v7->AddColumnHeader(this: v7, a2: 0, a3: "dme", a4: "Dme Elements", a5: 52, a6: 0);
  this->m_pDmeBrowser->SetSelectIndividualCells(this: this->m_pDmeBrowser, a2: true);
  this->m_pDmeBrowser->SetEmptyListText_2(this: this->m_pDmeBrowser, a2: "No Dme Elements");
  this->m_pDmeBrowser->SetDragEnabled(this: this->m_pDmeBrowser, a2: true);
  this->m_pDmeBrowser->AddActionSignalTarget_2(this: this->m_pDmeBrowser, a2: this);
  this->m_pDmeBrowser->SetSortFunc(this: this->m_pDmeBrowser, a2: 0, a3: DmeBrowserSortFunc);
  this->m_pDmeBrowser->SetSortColumn(this: this->m_pDmeBrowser, a2: 0);
  v8 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "FilterList");
  else
    v9 = nullptr;
  this->m_pFilterList = v9;
  v9->AddActionSignalTarget_2(this: v9, a2: this);
  this->m_pFilterList->RequestFocus(this: this->m_pFilterList, a2: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/dmepicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004810E0
// Name: public: CDmePickerFrame::CDmePickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePickerFrame *__thiscall CDmePickerFrame::CDmePickerFrame(
        CDmePickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmePicker *v7; // eax
  CDmePicker *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "DmePickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDmePickerFrame_vtbl *)&CDmePickerFrame::`vftable';
  if ( `CDmePickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePickerFrame");
    v4->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDmePickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePickerFrame");
    v5->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDmePickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePickerFrame");
    v6->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CDmePicker *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = CDmePicker::CDmePicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104A3920
// Name: public: static char const __near * CDmePicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePicker::GetPanelClassName()
{
  return "CDmePicker";
}

//------------------------------------------------------------------------------
// Address: 0x104A3930
// Name: public: static char const __near * CDmePickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePickerFrame::GetPanelClassName()
{
  return "CDmePickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104A3940
// Name: DmeBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DmeBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "dme", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "dme", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104A3980
// Name: private: void CDmePicker::RefreshDmeList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePicker::RefreshDmeList(CDmePicker *this@<ecx>, int a2@<ebx>)
{
  vgui::ListPanel *m_pDmeBrowser; // ecx
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
  BOOL bIsVisible; // [esp+208h] [ebp-Ch]
  int nTotalCount; // [esp+20Ch] [ebp-8h]
  int nMatchingElements; // [esp+210h] [ebp-4h]

  m_pDmeBrowser = this->m_pDmeBrowser;
  nMatchingElements = 0;
  nTotalCount = 0;
  for ( i = m_pDmeBrowser->FirstItem(this: m_pDmeBrowser);
        i != this->m_pDmeBrowser->InvalidItemID(this: this->m_pDmeBrowser);
        i = ((int (__thiscall *)(vgui::ListPanel *))NextItem)(a1: v12) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pDmeBrowser->GetItem)(
                        a1: this->m_pDmeBrowser,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "dme", defaultValue: &var);
    v9 = true;
    if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    {
      v7 = CUtlString::Get(this: &this->m_Filter);
      if ( V_stristr(a1: v8, a2: String, pStr: String, pSearch: v7) == nullptr )
        v9 = false;
    }
    v10 = this->m_pDmeBrowser;
    SetItemVisible = v10->SetItemVisible;
    LOBYTE(bIsVisible) = v9;
    SetItemVisible(this: v10, a2: i, a3: bIsVisible);
    if ( v9 )
      ++nMatchingElements;
    v12 = this->m_pDmeBrowser;
    NextItem = v12->NextItem;
    ++nTotalCount;
    a2 = i;
  }
  this->m_pDmeBrowser->SortList(this: this->m_pDmeBrowser);
  V_snprintf(pDest: pColumnTitle, maxLen: 0x200u, pFormat: "%s (%d/%d)", "Dme Elements", nMatchingElements, nTotalCount);
  this->m_pDmeBrowser->SetColumnHeaderText_2(this: this->m_pDmeBrowser, a2: 0, a3: pColumnTitle);
  if ( this->m_pDmeBrowser->GetItemCount(this: this->m_pDmeBrowser) > 0
    && this->m_pDmeBrowser->GetSelectedItemsCount(this: this->m_pDmeBrowser) == 0 )
  {
    v14 = this->m_pDmeBrowser->GetItemIDFromRow(this: this->m_pDmeBrowser, a2: 0);
    this->m_pDmeBrowser->SetSelectedCell(this: this->m_pDmeBrowser, a2: v14, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A3B10
// Name: private: virtual void CDmePicker::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePicker::OnTextChanged(CDmePicker *this@<ecx>, int a2@<ebx>)
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
  CDmePicker::RefreshDmeList(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104A3B80
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePickerFrame::GetMessageMap(CDmePickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePickerFrame::GetMessageMap'::`2'::s_pMap;
  `CDmePickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePickerFrame");
  `CDmePickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A3BB0
// Name: public: virtual struct PanelAnimationMap __near * CDmePickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePickerFrame::GetAnimMap(CDmePickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104A3BC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePickerFrame::GetKBMap(CDmePickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePickerFrame::GetKBMap'::`2'::s_pMap;
  `CDmePickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePickerFrame");
  `CDmePickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A3BF0
// Name: public: void CDmePickerFrame::DoModal(class CUtlVector<struct DmePickerInfo_t,class CUtlMemory<struct DmePickerInfo_t,int>> const __near &,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePickerFrame::DoModal(
        CDmePickerFrame *this,
        const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *vec,
        KeyValues *pKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  CDmePicker *m_pPicker; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pKeyValues;
  m_pPicker->Activate(this: m_pPicker, a2: vec);
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: vec->m_Size != 0);
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A3C60
// Name: public: virtual void CDmePicker::Activate(class CUtlVector<struct DmePickerInfo_t,class CUtlMemory<struct DmePickerInfo_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePicker::Activate(
        CDmePicker *this,
        const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *vec)
{
  CDmePicker *v2; // esi
  const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  const char *m_pAsString; // esi
  char *m_pChoiceString; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  int nCount; // [esp+Ch] [ebp-Ch]
  char *pElementName; // [esp+14h] [ebp-4h]

  v2 = this;
  this->m_pDmeBrowser->RemoveAll(this: this->m_pDmeBrowser);
  v3 = vec;
  v4 = 0;
  nCount = vec->m_Size;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Memory.m_pMemory[v4].m_hElement);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        pElementName = (char *)m_pAsString;
      }
      else
      {
        pElementName = "<null element>";
      }
      m_pChoiceString = (char *)v3->m_Memory.m_pMemory[v4].m_pChoiceString;
      if ( m_pChoiceString == nullptr )
        m_pChoiceString = pElementName;
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v10 = v9 != nullptr
          ? KeyValues::KeyValues(this: v9, setName: "node", firstKey: "dme", firstValue: m_pChoiceString)
          : nullptr;
      KeyValues::SetInt(this: v10, keyName: "dmeHandle", value: v3->m_Memory.m_pMemory[v4].m_hElement);
      v3 = (const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *)this->m_pDmeBrowser->AddItem(
                                                                                   this: this->m_pDmeBrowser,
                                                                                   a2: v10,
                                                                                   a3: 0,
                                                                                   a4: false,
                                                                                   a5: false);
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v12 = v11 != nullptr
          ? KeyValues::KeyValues(this: v11, setName: "drag", firstKey: "text", firstValue: pElementName)
          : nullptr;
      KeyValues::SetString(this: v12, keyName: "texttype", value: "dmeName");
      KeyValues::SetInt(this: v12, keyName: "dmeelement", value: vec->m_Memory.m_pMemory[v4].m_hElement);
      vgui::ListPanel::SetItemDragData(this: this->m_pDmeBrowser, itemID: (int)v3, data: v12);
      if ( ++v4 >= nCount )
        break;
      v3 = vec;
    }
    v2 = this;
  }
  CDmePicker::RefreshDmeList(this: v2, a2: (int)v3);
}

//------------------------------------------------------------------------------
// Address: 0x104A3E10
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePicker::GetMessageMap(CDmePicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePicker::GetMessageMap'::`2'::s_pMap;
  `CDmePicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
  `CDmePicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A3E40
// Name: public: virtual struct PanelAnimationMap __near * CDmePicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePicker::GetAnimMap(CDmePicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePicker");
}

//------------------------------------------------------------------------------
// Address: 0x104A3E50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePicker::GetKBMap(CDmePicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePicker::GetKBMap'::`2'::s_pMap;
  `CDmePicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePicker");
  `CDmePicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A3E80
// Name: public: class CDmElement __near * CDmePicker::GetSelectedDme(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmePicker::GetSelectedDme(CDmePicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  if ( this->m_pDmeBrowser->GetSelectedItemsCount(this: this->m_pDmeBrowser) != 0
    && (v2 = this->m_pDmeBrowser->GetSelectedItem(this: this->m_pDmeBrowser, a2: 0),
        v3 = this->m_pDmeBrowser->GetItem(this: this->m_pDmeBrowser, a2: v2),
        Int = KeyValues::GetInt(this: v3, keyName: "dmeHandle", defaultValue: -1),
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
        v6 = v5,
        v5 != nullptr)
    && v5->IsA(this: v5, a2: CDmElement::m_classType) )
  {
    return v6;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A3F00
// Name: public: virtual void CDmePickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePickerFrame::OnCommand(CDmePickerFrame *this, const char *pCommand)
{
  CExpressionCalculator *SelectedDme; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  int BufferType; // eax
  KeyValues *v7; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Open") == 0 )
  {
    SelectedDme = (CExpressionCalculator *)CDmePicker::GetSelectedDme(this: this->m_pPicker);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DmeSelected");
    else
      v5 = nullptr;
    if ( SelectedDme != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: SelectedDme);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v5, keyName: "dme", value: BufferType);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_10:
    this->PostActionSignal(this, a2: v5);
    this->CloseModal(this);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Cancel") == 0 )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v5 = KeyValues::KeyValues(this: v7, setName: "DmeSelectionCancelled");
    else
      v5 = nullptr;
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_10;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x104A40A0
// Name: public: static void CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
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
// Address: 0x104A4130
// Name: public: CDmePicker::CDmePicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePicker *__thiscall CDmePicker::CDmePicker(CDmePicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ListPanel *v6; // eax
  vgui::ListPanel *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "DmePicker");
  this->__vftable = (CDmePicker_vtbl *)&CDmePicker::`vftable';
  if ( `CDmePicker::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
    v3->pfnClassName = CDmePicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDmePicker");
    v4->pfnClassName = CDmePicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePicker");
    v5->pfnClassName = CDmePicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  v6 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v6 != nullptr )
    v7 = vgui::ListPanel::ListPanel(this: v6, parent: this, panelName: "DmeBrowser");
  else
    v7 = nullptr;
  this->m_pDmeBrowser = v7;
  v7->AddColumnHeader(this: v7, a2: 0, a3: "dme", a4: "Dme Elements", a5: 52, a6: 0);
  this->m_pDmeBrowser->SetSelectIndividualCells(this: this->m_pDmeBrowser, a2: true);
  this->m_pDmeBrowser->SetEmptyListText_2(this: this->m_pDmeBrowser, a2: "No Dme Elements");
  this->m_pDmeBrowser->SetDragEnabled(this: this->m_pDmeBrowser, a2: true);
  this->m_pDmeBrowser->AddActionSignalTarget_2(this: this->m_pDmeBrowser, a2: this);
  this->m_pDmeBrowser->SetSortFunc(this: this->m_pDmeBrowser, a2: 0, a3: DmeBrowserSortFunc);
  this->m_pDmeBrowser->SetSortColumn(this: this->m_pDmeBrowser, a2: 0);
  v8 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: (vgui::Panel *)"FilterList");
  else
    v9 = nullptr;
  this->m_pFilterList = v9;
  v9->AddActionSignalTarget_2(this: v9, a2: this);
  this->m_pFilterList->RequestFocus(this: this->m_pFilterList, a2: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/dmepicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A4310
// Name: public: CDmePickerFrame::CDmePickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePickerFrame *__thiscall CDmePickerFrame::CDmePickerFrame(
        CDmePickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmePicker *v7; // eax
  CDmePicker *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "DmePickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDmePickerFrame_vtbl *)&CDmePickerFrame::`vftable';
  if ( `CDmePickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePickerFrame");
    v4->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDmePickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePickerFrame");
    v5->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDmePickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePickerFrame");
    v6->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CDmePicker *)operator new(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = CDmePicker::CDmePicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepickerframe.res",
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
// Address: 0x004A4070
// Name: public: static char const __near * CDmePicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePicker::GetPanelClassName()
{
  return "CDmePicker";
}

//------------------------------------------------------------------------------
// Address: 0x004A4080
// Name: public: static char const __near * CDmePickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmePickerFrame::GetPanelClassName()
{
  return "CDmePickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004A4090
// Name: DmeBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DmeBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "dme", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "dme", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004A4170
// Name: private: void CDmePicker::RefreshDmeList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePicker::RefreshDmeList(CDmePicker *this@<ecx>, int a2@<ebx>)
{
  vgui::ListPanel *m_pDmeBrowser; // ecx
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
  BOOL bIsVisible; // [esp+208h] [ebp-Ch]
  int nTotalCount; // [esp+20Ch] [ebp-8h]
  int nMatchingElements; // [esp+210h] [ebp-4h]

  m_pDmeBrowser = this->m_pDmeBrowser;
  nMatchingElements = 0;
  nTotalCount = 0;
  for ( i = m_pDmeBrowser->FirstItem(this: m_pDmeBrowser);
        i != this->m_pDmeBrowser->InvalidItemID(this: this->m_pDmeBrowser);
        i = ((int (__thiscall *)(vgui::ListPanel *))NextItem)(a1: v11) )
  {
    v5 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pDmeBrowser->GetItem)(
                        a1: this->m_pDmeBrowser,
                        a2: i,
                        a3: a2);
    String = KeyValues::GetString(this: v5, keyName: "dme", defaultValue: defaultValue);
    v8 = true;
    if ( CUtlString::Length(this: &this->m_Filter) != 0 )
    {
      v7 = CUtlString::Get(this: &this->m_Filter);
      if ( V_stristr(pStr: String, pSearch: v7) == nullptr )
        v8 = false;
    }
    v9 = this->m_pDmeBrowser;
    SetItemVisible = v9->SetItemVisible;
    LOBYTE(bIsVisible) = v8;
    SetItemVisible(this: v9, a2: i, a3: bIsVisible);
    if ( v8 )
      ++nMatchingElements;
    v11 = this->m_pDmeBrowser;
    NextItem = v11->NextItem;
    ++nTotalCount;
    a2 = i;
  }
  this->m_pDmeBrowser->SortList(this: this->m_pDmeBrowser);
  V_snprintf(pDest: pColumnTitle, maxLen: 512, pFormat: "%s (%d/%d)", "Dme Elements", nMatchingElements, nTotalCount);
  this->m_pDmeBrowser->SetColumnHeaderText_2(this: this->m_pDmeBrowser, a2: 0, a3: pColumnTitle);
  if ( this->m_pDmeBrowser->GetItemCount(this: this->m_pDmeBrowser) > 0
    && this->m_pDmeBrowser->GetSelectedItemsCount(this: this->m_pDmeBrowser) == 0 )
  {
    v13 = this->m_pDmeBrowser->GetItemIDFromRow(this: this->m_pDmeBrowser, a2: 0);
    this->m_pDmeBrowser->SetSelectedCell(this: this->m_pDmeBrowser, a2: v13, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A4300
// Name: private: virtual void CDmePicker::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmePicker::OnTextChanged(CDmePicker *this@<ecx>, int a2@<ebx>)
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
  CDmePicker::RefreshDmeList(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004A4370
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePickerFrame::GetMessageMap(CDmePickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePickerFrame::GetMessageMap'::`2'::s_pMap;
  `CDmePickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePickerFrame");
  `CDmePickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A43A0
// Name: public: virtual struct PanelAnimationMap __near * CDmePickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePickerFrame::GetAnimMap(CDmePickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004A43B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePickerFrame::GetKBMap(CDmePickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePickerFrame::GetKBMap'::`2'::s_pMap;
  `CDmePickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePickerFrame");
  `CDmePickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A43E0
// Name: public: void CDmePickerFrame::DoModal(class CUtlVector<struct DmePickerInfo_t,class CUtlMemory<struct DmePickerInfo_t,int>> const __near &,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePickerFrame::DoModal(
        CDmePickerFrame *this,
        const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *vec,
        KeyValues *pKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx
  CDmePicker *m_pPicker; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pPicker = this->m_pPicker;
  this->m_pContextKeyValues = pKeyValues;
  m_pPicker->Activate(this: m_pPicker, a2: vec);
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: vec->m_Size != 0);
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A4450
// Name: public: virtual void CDmePicker::Activate(class CUtlVector<struct DmePickerInfo_t,class CUtlMemory<struct DmePickerInfo_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePicker::Activate(
        CDmePicker *this,
        const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *vec)
{
  CDmePicker *v2; // esi
  const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // esi
  const char *v7; // esi
  const char *m_pChoiceString; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  int nCount; // [esp+Ch] [ebp-Ch]
  const char *pElementName; // [esp+14h] [ebp-4h]

  v2 = this;
  this->m_pDmeBrowser->RemoveAll(this: this->m_pDmeBrowser);
  v3 = vec;
  v4 = 0;
  nCount = vec->m_Size;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3->m_Memory.m_pMemory[v4].m_hElement);
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        v7 = *(const char **)(v6 + 20);
        if ( v7 == (const char *)-1 )
          v7 = defaultValue;
        pElementName = v7;
      }
      else
      {
        pElementName = "<null element>";
      }
      m_pChoiceString = v3->m_Memory.m_pMemory[v4].m_pChoiceString;
      if ( m_pChoiceString == nullptr )
        m_pChoiceString = pElementName;
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v10 = v9 != nullptr
          ? KeyValues::KeyValues(this: v9, setName: "node", firstKey: "dme", firstValue: m_pChoiceString)
          : nullptr;
      KeyValues::SetInt(this: v10, keyName: "dmeHandle", value: v3->m_Memory.m_pMemory[v4].m_hElement);
      v3 = (const CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *)this->m_pDmeBrowser->AddItem(
                                                                                   this: this->m_pDmeBrowser,
                                                                                   a2: v10,
                                                                                   a3: 0,
                                                                                   a4: false,
                                                                                   a5: false);
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v12 = v11 != nullptr
          ? KeyValues::KeyValues(this: v11, setName: "drag", firstKey: "text", firstValue: pElementName)
          : nullptr;
      KeyValues::SetString(this: v12, keyName: "texttype", value: "dmeName");
      KeyValues::SetInt(this: v12, keyName: "dmeelement", value: vec->m_Memory.m_pMemory[v4].m_hElement);
      vgui::ListPanel::SetItemDragData(this: this->m_pDmeBrowser, itemID: (int)v3, data: v12);
      if ( ++v4 >= nCount )
        break;
      v3 = vec;
    }
    v2 = this;
  }
  CDmePicker::RefreshDmeList(this: v2, a2: (int)v3);
}

//------------------------------------------------------------------------------
// Address: 0x004A4600
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmePicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmePicker::GetMessageMap(CDmePicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmePicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePicker::GetMessageMap'::`2'::s_pMap;
  `CDmePicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
  `CDmePicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A4630
// Name: public: virtual struct PanelAnimationMap __near * CDmePicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmePicker::GetAnimMap(CDmePicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmePicker");
}

//------------------------------------------------------------------------------
// Address: 0x004A4640
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmePicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmePicker::GetKBMap(CDmePicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmePicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmePicker::GetKBMap'::`2'::s_pMap;
  `CDmePicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePicker");
  `CDmePicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A4670
// Name: public: class CDmElement __near * CDmePicker::GetSelectedDme(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmePicker::GetSelectedDme(CDmePicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  int Int; // eax
  int v5; // eax
  int v6; // esi

  if ( this->m_pDmeBrowser->GetSelectedItemsCount(this: this->m_pDmeBrowser) != 0
    && (v2 = this->m_pDmeBrowser->GetSelectedItem(this: this->m_pDmeBrowser, a2: 0),
        v3 = this->m_pDmeBrowser->GetItem(this: this->m_pDmeBrowser, a2: v2),
        Int = KeyValues::GetInt(this: v3, keyName: "dmeHandle", defaultValue: -1),
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: Int),
        v6 = v5,
        v5 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v6;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A46F0
// Name: public: virtual void CDmePickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePickerFrame::OnCommand(CDmePickerFrame *this, const char *pCommand)
{
  CExpressionCalculator *SelectedDme; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  int BufferType; // eax
  KeyValues *v7; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Open") == 0 )
  {
    SelectedDme = (CExpressionCalculator *)CDmePicker::GetSelectedDme(this: this->m_pPicker);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DmeSelected");
    else
      v5 = nullptr;
    if ( SelectedDme != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: SelectedDme);
    else
      BufferType = -1;
    KeyValues::SetInt(this: v5, keyName: "dme", value: BufferType);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_10:
    this->PostActionSignal(this, a2: v5);
    this->CloseModal(this);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Cancel") == 0 )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v5 = KeyValues::KeyValues(this: v7, setName: "DmeSelectionCancelled");
    else
      v5 = nullptr;
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_10;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x004A4890
// Name: public: static void CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
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
// Address: 0x004A4920
// Name: public: CDmePicker::CDmePicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePicker *__thiscall CDmePicker::CDmePicker(CDmePicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ListPanel *v6; // eax
  vgui::ListPanel *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "DmePicker");
  this->__vftable = (CDmePicker_vtbl *)&CDmePicker::`vftable';
  if ( `CDmePicker::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDmePicker");
    v3->pfnClassName = CDmePicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDmePicker");
    v4->pfnClassName = CDmePicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmePicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePicker");
    v5->pfnClassName = CDmePicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmePicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  v6 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v6 != nullptr )
    v7 = vgui::ListPanel::ListPanel(this: v6, parent: this, panelName: "DmeBrowser");
  else
    v7 = nullptr;
  this->m_pDmeBrowser = v7;
  v7->AddColumnHeader(this: v7, a2: 0, a3: "dme", a4: "Dme Elements", a5: 52, a6: 0);
  this->m_pDmeBrowser->SetSelectIndividualCells(this: this->m_pDmeBrowser, a2: true);
  this->m_pDmeBrowser->SetEmptyListText_2(this: this->m_pDmeBrowser, a2: "No Dme Elements");
  this->m_pDmeBrowser->SetDragEnabled(this: this->m_pDmeBrowser, a2: true);
  this->m_pDmeBrowser->AddActionSignalTarget_2(this: this->m_pDmeBrowser, a2: this);
  this->m_pDmeBrowser->SetSortFunc(this: this->m_pDmeBrowser, a2: 0, a3: DmeBrowserSortFunc);
  this->m_pDmeBrowser->SetSortColumn(this: this->m_pDmeBrowser, a2: 0);
  v8 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "FilterList");
  else
    v9 = nullptr;
  this->m_pFilterList = v9;
  v9->AddActionSignalTarget_2(this: v9, a2: this);
  this->m_pFilterList->RequestFocus(this: this->m_pFilterList, a2: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/dmepicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A4B00
// Name: public: CDmePickerFrame::CDmePickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePickerFrame *__thiscall CDmePickerFrame::CDmePickerFrame(
        CDmePickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmePicker *v7; // eax
  CDmePicker *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "DmePickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDmePickerFrame_vtbl *)&CDmePickerFrame::`vftable';
  if ( `CDmePickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmePickerFrame");
    v4->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDmePickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmePickerFrame");
    v5->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDmePickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmePickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmePickerFrame");
    v6->pfnClassName = CDmePickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CDmePicker *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = CDmePicker::CDmePicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmepickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

} // namespace sceneviewer
