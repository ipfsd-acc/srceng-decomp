// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/presetpicker.cpp
// Functions: 10
// ============================================================

#include "vgui2\dme_controls\presetpicker.h"

//------------------------------------------------------------------------------
// Address: 0x0049C2A0
// Name: public: static char const __near * CPresetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetPickerFrame::GetPanelClassName()
{
  return "CPresetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x0049C2B0
// Name: PresetNameSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl PresetNameSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "name", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0049C2F0
// Name: public: CPresetPickerFrame::CPresetPickerFrame(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPresetPickerFrame *__thiscall CPresetPickerFrame::CPresetPickerFrame(
        CPresetPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        bool bAllowMultiSelect)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PresetPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPresetPickerFrame_vtbl *)&CPresetPickerFrame::`vftable';
  if ( `CPresetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPresetPickerFrame");
    v5->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPresetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPresetPickerFrame");
    v6->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPresetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetPickerFrame");
    v7->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  this->m_pContextKeyValues = nullptr;
  v8 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "PresetList");
  else
    v9 = nullptr;
  this->m_pPresetList = v9;
  v9->AddColumnHeader(this: v9, a2: 0, a3: "name", a4: "Preset Name", a5: 52, a6: 0);
  this->m_pPresetList->SetSelectIndividualCells(this: this->m_pPresetList, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pPresetList, bState: bAllowMultiSelect);
  this->m_pPresetList->SetEmptyListText_2(this: this->m_pPresetList, a2: "No presets");
  this->m_pPresetList->AddActionSignalTarget_2(this: this->m_pPresetList, a2: this);
  this->m_pPresetList->SetSortFunc(this: this->m_pPresetList, a2: 0, a3: PresetNameSortFunc);
  this->m_pPresetList->SetSortColumn(this: this->m_pPresetList, a2: 0);
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "OkButton",
            text: "#MessageBox_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v11 = nullptr;
  this->m_pOpenButton = v11;
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "CancelButton",
            text: "#MessageBox_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v13 = nullptr;
  this->m_pCancelButton = v13;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/presetpicker.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049C510
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetPickerFrame::GetMessageMap(CPresetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CPresetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetPickerFrame");
  `CPresetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C540
// Name: public: virtual struct PanelAnimationMap __near * CPresetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetPickerFrame::GetAnimMap(CPresetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x0049C550
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetPickerFrame::GetKBMap(CPresetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CPresetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetPickerFrame");
  `CPresetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C620
// Name: public: virtual void CPresetPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::OnCommand(CPresetPickerFrame *this, KeyValues *pCommand)
{
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  int v6; // ebx
  int v7; // eax
  KeyValues *v8; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CExpressionCalculator *v11; // edi
  int BufferType; // eax
  int v13; // eax
  KeyValues *v14; // eax
  CExpressionCalculator *ElementKey; // eax
  int v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // edi
  char pBuf[32]; // [esp+Ch] [ebp-24h] BYREF
  int nSelectedItemCount; // [esp+2Ch] [ebp-4h]
  KeyValues *pActionKeys; // [esp+38h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Ok") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
    {
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    }
    else
    {
      v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v17 != nullptr )
        v18 = KeyValues::KeyValues(this: v17, setName: "PresetPickCancelled");
      else
        v18 = nullptr;
      if ( this->m_pContextKeyValues != nullptr )
      {
        KeyValues::AddSubKey(this: v18, pSubkey: this->m_pContextKeyValues);
        this->m_pContextKeyValues = nullptr;
      }
      this->PostActionSignal(this, a2: v18);
      this->CloseModal(this);
    }
  }
  else
  {
    v3 = this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList);
    nSelectedItemCount = v3;
    if ( v3 != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "PresetPicked");
        pActionKeys = v5;
      }
      else
      {
        pActionKeys = nullptr;
        v5 = nullptr;
      }
      if ( vgui::ListPanel::IsMultiselectEnabled(this: this->m_pPresetList) )
      {
        KeyValues::SetInt(this: v5, keyName: "count", value: v3);
        v6 = 0;
        if ( v3 > 0 )
        {
          do
          {
            V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", v6);
            v7 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: v6);
            v8 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v7);
            Int = KeyValues::GetInt(this: v8, keyName: "preset", defaultValue: -1);
            v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
            v11 = (CExpressionCalculator *)v10;
            if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmePreset::m_classType) )
              BufferType = CCodecBuffer_Block::GetBufferType(this: v11);
            else
              BufferType = -1;
            KeyValues::SetInt(this: pActionKeys, keyName: pBuf, value: BufferType);
            ++v6;
          }
          while ( v6 < nSelectedItemCount );
        }
        v5 = pActionKeys;
      }
      else
      {
        v13 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
        v14 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v13);
        ElementKey = (CExpressionCalculator *)GetElementKeyValue<CDmePreset>(pKeyValues: v14, pName: "preset");
        if ( ElementKey != nullptr )
        {
          v16 = CCodecBuffer_Block::GetBufferType(this: ElementKey);
          KeyValues::SetInt(this: v5, keyName: "preset", value: v16);
        }
        else
        {
          KeyValues::SetInt(this: v5, keyName: "preset", value: -1);
        }
      }
      if ( this->m_pContextKeyValues != nullptr )
      {
        KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
        this->m_pContextKeyValues = nullptr;
      }
      this->PostActionSignal(this, a2: v5);
      this->CloseModal(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C870
// Name: private: void CPresetPickerFrame::RefreshPresetList(class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::RefreshPresetList(
        CPresetPickerFrame *this,
        CDmElement *pPresetGroup,
        bool bSelectAll)
{
  CPresetPickerFrame *v3; // esi
  vgui::ListPanel *m_pPresetList; // ecx
  void (__thiscall *RemoveAll)(vgui::ListPanel *); // edx
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  CExpressionCalculator *v10; // ebx
  const char *m_nAllocationCount; // eax
  const char *v12; // edi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  int v15; // eax
  CPresetPickerFrame *v16; // edi
  int v17; // eax
  CDmrElementArray<CDmePreset> presets; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  CPresetPickerFrame *v20; // [esp+18h] [ebp-4h]
  int i; // [esp+24h] [ebp+8h]

  v3 = this;
  m_pPresetList = this->m_pPresetList;
  RemoveAll = m_pPresetList->RemoveAll;
  v20 = v3;
  RemoveAll(this: m_pPresetList);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
  if ( pPresetGroup != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pPresetGroup, pAttributeName: "presets");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      presets.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      presets.m_pStorage = m_pData;
      nCount = m_pData->m_Size;
      if ( nCount != 0 )
      {
        i = 0;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
            v9 = v8;
            if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmePreset::m_classType) )
              v10 = (CExpressionCalculator *)v9;
            else
              v10 = nullptr;
            m_nAllocationCount = (const char *)v10->m_varNames.m_Memory.m_nAllocationCount;
            if ( m_nAllocationCount == (const char *)-1 )
              m_nAllocationCount = defaultValue;
            v12 = m_nAllocationCount;
            if ( m_nAllocationCount == nullptr || *m_nAllocationCount == 0 )
              v12 = "<no name>";
            v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            v14 = v13 != nullptr ? KeyValues::KeyValues(this: v13, setName: "node") : nullptr;
            KeyValues::SetString(this: v14, keyName: "name", value: v12);
            v15 = v10 != nullptr ? CCodecBuffer_Block::GetBufferType(this: v10) : -1;
            KeyValues::SetInt(this: v14, keyName: "preset", value: v15);
            v16 = v20;
            v17 = v20->m_pPresetList->AddItem(this: v20->m_pPresetList, a2: v14, a3: 0, a4: false, a5: false);
            if ( bSelectAll )
              v16->m_pPresetList->AddSelectedItem(this: v16->m_pPresetList, a2: v17);
            if ( ++i >= nCount )
              break;
            m_pData = presets.m_pStorage;
          }
          v3 = v16;
        }
        v3->m_pPresetList->SortList(this: v3->m_pPresetList);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C9F0
// Name: public: void CPresetPickerFrame::DoModal(class CDmElement __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::DoModal(
        CPresetPickerFrame *this,
        CDmElement *pPresetGroup,
        bool bSelectAll,
        KeyValues *pContextKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  CPresetPickerFrame::RefreshPresetList(this, pPresetGroup, bSelectAll);
  this->m_pContextKeyValues = pContextKeyValues;
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049C5D0
// Name: class CDmePreset __near * GetElementKeyValue<class CDmePreset>(class KeyValues __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePreset *__cdecl GetElementKeyValue<CDmePreset>(KeyValues *pKeyValues, const char *pName)
{
  DmElementHandle_t Int; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: pName, defaultValue: -1);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmePreset::m_classType) )
    return (CDmePreset *)v4;
  else
    return nullptr;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104AC170
// Name: public: static char const __near * CPresetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetPickerFrame::GetPanelClassName()
{
  return "CPresetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104AC180
// Name: PresetNameSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl PresetNameSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "name", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "name", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104AC1C0
// Name: public: CPresetPickerFrame::CPresetPickerFrame(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPresetPickerFrame *__thiscall CPresetPickerFrame::CPresetPickerFrame(
        CPresetPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        bool bAllowMultiSelect)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PresetPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPresetPickerFrame_vtbl *)&CPresetPickerFrame::`vftable';
  if ( `CPresetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPresetPickerFrame");
    v5->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPresetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPresetPickerFrame");
    v6->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPresetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetPickerFrame");
    v7->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  this->m_pContextKeyValues = nullptr;
  v8 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "PresetList");
  else
    v9 = nullptr;
  this->m_pPresetList = v9;
  v9->AddColumnHeader(this: v9, a2: 0, a3: "name", a4: "Preset Name", a5: 52, a6: 0);
  this->m_pPresetList->SetSelectIndividualCells(this: this->m_pPresetList, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pPresetList, bState: bAllowMultiSelect);
  this->m_pPresetList->SetEmptyListText_2(this: this->m_pPresetList, a2: "No presets");
  this->m_pPresetList->AddActionSignalTarget_2(this: this->m_pPresetList, a2: this);
  this->m_pPresetList->SetSortFunc(this: this->m_pPresetList, a2: 0, a3: PresetNameSortFunc);
  this->m_pPresetList->SetSortColumn(this: this->m_pPresetList, a2: 0);
  v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "OkButton",
            text: "#MessageBox_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v11 = nullptr;
  this->m_pOpenButton = v11;
  v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "CancelButton",
            text: "#MessageBox_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v13 = nullptr;
  this->m_pCancelButton = v13;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/presetpicker.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104AC3E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetPickerFrame::GetMessageMap(CPresetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CPresetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetPickerFrame");
  `CPresetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104AC410
// Name: public: virtual struct PanelAnimationMap __near * CPresetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetPickerFrame::GetAnimMap(CPresetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104AC420
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetPickerFrame::GetKBMap(CPresetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CPresetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetPickerFrame");
  `CPresetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104AC4F0
// Name: public: virtual void CPresetPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::OnCommand(CPresetPickerFrame *this, KeyValues *pCommand)
{
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  int v6; // ebx
  int v7; // eax
  KeyValues *v8; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CExpressionCalculator *v11; // edi
  int BufferType; // eax
  int v13; // eax
  KeyValues *v14; // eax
  CExpressionCalculator *ElementKey; // eax
  int v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // edi
  char pBuf[32]; // [esp+Ch] [ebp-24h] BYREF
  int nSelectedItemCount; // [esp+2Ch] [ebp-4h]
  KeyValues *pActionKeys; // [esp+38h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Ok") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
    {
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    }
    else
    {
      v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v17 != nullptr )
        v18 = KeyValues::KeyValues(this: v17, setName: "PresetPickCancelled");
      else
        v18 = nullptr;
      if ( this->m_pContextKeyValues != nullptr )
      {
        KeyValues::AddSubKey(this: v18, pSubkey: this->m_pContextKeyValues);
        this->m_pContextKeyValues = nullptr;
      }
      this->PostActionSignal(this, a2: v18);
      this->CloseModal(this);
    }
  }
  else
  {
    v3 = this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList);
    nSelectedItemCount = v3;
    if ( v3 != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "PresetPicked");
        pActionKeys = v5;
      }
      else
      {
        pActionKeys = nullptr;
        v5 = nullptr;
      }
      if ( vgui::ListPanel::IsMultiselectEnabled(this: this->m_pPresetList) )
      {
        KeyValues::SetInt(this: v5, keyName: "count", value: v3);
        v6 = 0;
        if ( v3 > 0 )
        {
          do
          {
            V_snprintf(pDest: pBuf, maxLen: 0x20u, pFormat: "%d", v6);
            v7 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: v6);
            v8 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v7);
            Int = KeyValues::GetInt(this: v8, keyName: "preset", defaultValue: -1);
            v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
            v11 = (CExpressionCalculator *)v10;
            if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmePreset::m_classType) )
              BufferType = CCodecBuffer_Block::GetBufferType(this: v11);
            else
              BufferType = -1;
            KeyValues::SetInt(this: pActionKeys, keyName: pBuf, value: BufferType);
            ++v6;
          }
          while ( v6 < nSelectedItemCount );
        }
        v5 = pActionKeys;
      }
      else
      {
        v13 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
        v14 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v13);
        ElementKey = (CExpressionCalculator *)GetElementKeyValue<CDmePreset>(pKeyValues: v14, pName: "preset");
        if ( ElementKey != nullptr )
        {
          v16 = CCodecBuffer_Block::GetBufferType(this: ElementKey);
          KeyValues::SetInt(this: v5, keyName: "preset", value: v16);
        }
        else
        {
          KeyValues::SetInt(this: v5, keyName: "preset", value: -1);
        }
      }
      if ( this->m_pContextKeyValues != nullptr )
      {
        KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
        this->m_pContextKeyValues = nullptr;
      }
      this->PostActionSignal(this, a2: v5);
      this->CloseModal(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AC740
// Name: private: void CPresetPickerFrame::RefreshPresetList(class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::RefreshPresetList(
        CPresetPickerFrame *this,
        CDmElement *pPresetGroup,
        bool bSelectAll)
{
  CPresetPickerFrame *v3; // esi
  vgui::ListPanel *m_pPresetList; // ecx
  void (__thiscall *RemoveAll)(vgui::ListPanel *); // edx
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  CExpressionCalculator *v10; // ebx
  const char *m_nAllocationCount; // eax
  char *v12; // edi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  int v15; // eax
  CPresetPickerFrame *v16; // edi
  int v17; // eax
  CDmrElementArray<CDmePreset> presets; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  CPresetPickerFrame *v20; // [esp+18h] [ebp-4h]
  int i; // [esp+24h] [ebp+8h]

  v3 = this;
  m_pPresetList = this->m_pPresetList;
  RemoveAll = m_pPresetList->RemoveAll;
  v20 = v3;
  RemoveAll(this: m_pPresetList);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
  if ( pPresetGroup != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pPresetGroup, pAttributeName: "presets");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      presets.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      presets.m_pStorage = m_pData;
      nCount = m_pData->m_Size;
      if ( nCount != 0 )
      {
        i = 0;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
            v9 = v8;
            if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmePreset::m_classType) )
              v10 = (CExpressionCalculator *)v9;
            else
              v10 = nullptr;
            m_nAllocationCount = (const char *)v10->m_varNames.m_Memory.m_nAllocationCount;
            if ( m_nAllocationCount == (const char *)-1 )
              m_nAllocationCount = &var;
            v12 = (char *)m_nAllocationCount;
            if ( m_nAllocationCount == nullptr || *m_nAllocationCount == 0 )
              v12 = "<no name>";
            v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            v14 = v13 != nullptr ? KeyValues::KeyValues(this: v13, setName: "node") : nullptr;
            KeyValues::SetString(this: v14, keyName: "name", value: v12);
            v15 = v10 != nullptr ? CCodecBuffer_Block::GetBufferType(this: v10) : -1;
            KeyValues::SetInt(this: v14, keyName: "preset", value: v15);
            v16 = v20;
            v17 = v20->m_pPresetList->AddItem(this: v20->m_pPresetList, a2: v14, a3: 0, a4: false, a5: false);
            if ( bSelectAll )
              v16->m_pPresetList->AddSelectedItem(this: v16->m_pPresetList, a2: v17);
            if ( ++i >= nCount )
              break;
            m_pData = presets.m_pStorage;
          }
          v3 = v16;
        }
        v3->m_pPresetList->SortList(this: v3->m_pPresetList);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104AC8C0
// Name: public: void CPresetPickerFrame::DoModal(class CDmElement __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::DoModal(
        CPresetPickerFrame *this,
        CDmElement *pPresetGroup,
        bool bSelectAll,
        KeyValues *pContextKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  CPresetPickerFrame::RefreshPresetList(this, pPresetGroup, bSelectAll);
  this->m_pContextKeyValues = pContextKeyValues;
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x104AC4A0
// Name: class CDmePreset __near * GetElementKeyValue<class CDmePreset>(class KeyValues __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePreset *__cdecl GetElementKeyValue<CDmePreset>(KeyValues *pKeyValues, const char *pName)
{
  DmElementHandle_t Int; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: pName, defaultValue: -1);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmePreset::m_classType) )
    return (CDmePreset *)v4;
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004A6900
// Name: public: static char const __near * CPresetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetPickerFrame::GetPanelClassName()
{
  return "CPresetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004A6910
// Name: PresetNameSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl PresetNameSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "name", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004A6950
// Name: public: CPresetPickerFrame::CPresetPickerFrame(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPresetPickerFrame *__thiscall CPresetPickerFrame::CPresetPickerFrame(
        CPresetPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        bool bAllowMultiSelect)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PresetPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPresetPickerFrame_vtbl *)&CPresetPickerFrame::`vftable';
  if ( `CPresetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPresetPickerFrame");
    v5->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPresetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPresetPickerFrame");
    v6->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPresetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetPickerFrame");
    v7->pfnClassName = CPresetPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  this->m_pContextKeyValues = nullptr;
  v8 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "PresetList");
  else
    v9 = nullptr;
  this->m_pPresetList = v9;
  v9->AddColumnHeader(this: v9, a2: 0, a3: "name", a4: "Preset Name", a5: 52, a6: 0);
  this->m_pPresetList->SetSelectIndividualCells(this: this->m_pPresetList, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pPresetList, bState: bAllowMultiSelect);
  this->m_pPresetList->SetEmptyListText_2(this: this->m_pPresetList, a2: "No presets");
  this->m_pPresetList->AddActionSignalTarget_2(this: this->m_pPresetList, a2: this);
  this->m_pPresetList->SetSortFunc(this: this->m_pPresetList, a2: 0, a3: PresetNameSortFunc);
  this->m_pPresetList->SetSortColumn(this: this->m_pPresetList, a2: 0);
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "OkButton",
            text: "#MessageBox_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v11 = nullptr;
  this->m_pOpenButton = v11;
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "CancelButton",
            text: "#MessageBox_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v13 = nullptr;
  this->m_pCancelButton = v13;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/presetpicker.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A6B70
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetPickerFrame::GetMessageMap(CPresetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CPresetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetPickerFrame");
  `CPresetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A6BA0
// Name: public: virtual struct PanelAnimationMap __near * CPresetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetPickerFrame::GetAnimMap(CPresetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004A6BB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetPickerFrame::GetKBMap(CPresetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CPresetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetPickerFrame");
  `CPresetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A6C80
// Name: public: virtual void CPresetPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::OnCommand(CPresetPickerFrame *this, KeyValues *pCommand)
{
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  int v6; // ebx
  int v7; // eax
  KeyValues *v8; // eax
  int Int; // eax
  int v10; // eax
  CExpressionCalculator *v11; // edi
  int BufferType; // eax
  int v13; // eax
  KeyValues *v14; // eax
  CExpressionCalculator *ElementKey; // eax
  int v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // edi
  char pBuf[32]; // [esp+Ch] [ebp-24h] BYREF
  int nSelectedItemCount; // [esp+2Ch] [ebp-4h]
  KeyValues *pActionKeys; // [esp+38h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Ok") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
    {
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    }
    else
    {
      v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v17 != nullptr )
        v18 = KeyValues::KeyValues(this: v17, setName: "PresetPickCancelled");
      else
        v18 = nullptr;
      if ( this->m_pContextKeyValues != nullptr )
      {
        KeyValues::AddSubKey(this: v18, pSubkey: this->m_pContextKeyValues);
        this->m_pContextKeyValues = nullptr;
      }
      this->PostActionSignal(this, a2: v18);
      this->CloseModal(this);
    }
  }
  else
  {
    v3 = this->m_pPresetList->GetSelectedItemsCount(this: this->m_pPresetList);
    nSelectedItemCount = v3;
    if ( v3 != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "PresetPicked");
        pActionKeys = v5;
      }
      else
      {
        pActionKeys = nullptr;
        v5 = nullptr;
      }
      if ( vgui::ListPanel::IsMultiselectEnabled(this: this->m_pPresetList) )
      {
        KeyValues::SetInt(this: v5, keyName: "count", value: v3);
        v6 = 0;
        if ( v3 > 0 )
        {
          do
          {
            V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", v6);
            v7 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: v6);
            v8 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v7);
            Int = KeyValues::GetInt(this: v8, keyName: "preset", defaultValue: -1);
            v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: Int);
            v11 = (CExpressionCalculator *)v10;
            if ( v10 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                   a1: v10,
                   a2: CDmePreset::m_classType.u) != 0 )
            {
              BufferType = CCodecBuffer_Block::GetBufferType(this: v11);
            }
            else
            {
              BufferType = -1;
            }
            KeyValues::SetInt(this: pActionKeys, keyName: pBuf, value: BufferType);
            ++v6;
          }
          while ( v6 < nSelectedItemCount );
        }
        v5 = pActionKeys;
      }
      else
      {
        v13 = this->m_pPresetList->GetSelectedItem(this: this->m_pPresetList, a2: 0);
        v14 = this->m_pPresetList->GetItem(this: this->m_pPresetList, a2: v13);
        ElementKey = (CExpressionCalculator *)GetElementKeyValue<CDmePreset>(pKeyValues: v14, pName: "preset");
        if ( ElementKey != nullptr )
        {
          v16 = CCodecBuffer_Block::GetBufferType(this: ElementKey);
          KeyValues::SetInt(this: v5, keyName: "preset", value: v16);
        }
        else
        {
          KeyValues::SetInt(this: v5, keyName: "preset", value: -1);
        }
      }
      if ( this->m_pContextKeyValues != nullptr )
      {
        KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeyValues);
        this->m_pContextKeyValues = nullptr;
      }
      this->PostActionSignal(this, a2: v5);
      this->CloseModal(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A6ED0
// Name: private: void CPresetPickerFrame::RefreshPresetList(class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::RefreshPresetList(
        CPresetPickerFrame *this,
        CDmElement *pPresetGroup,
        bool bSelectAll)
{
  CPresetPickerFrame *v3; // esi
  vgui::ListPanel *m_pPresetList; // ecx
  void (__thiscall *RemoveAll)(vgui::ListPanel *); // edx
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v8; // eax
  CExpressionCalculator *v9; // esi
  CExpressionCalculator *v10; // ebx
  const char *m_nAllocationCount; // eax
  const char *v12; // edi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  int v15; // eax
  CPresetPickerFrame *v16; // edi
  int v17; // eax
  CDmrElementArray<CDmePreset> presets; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  CPresetPickerFrame *v20; // [esp+18h] [ebp-4h]
  int i; // [esp+24h] [ebp+8h]

  v3 = this;
  m_pPresetList = this->m_pPresetList;
  RemoveAll = m_pPresetList->RemoveAll;
  v20 = v3;
  RemoveAll(this: m_pPresetList);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
  if ( pPresetGroup != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pPresetGroup, pAttributeName: "presets");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      presets.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      presets.m_pStorage = m_pData;
      nCount = m_pData->m_Size;
      if ( nCount != 0 )
      {
        i = 0;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: m_pData->m_Memory.m_pMemory[i]);
            v9 = (CExpressionCalculator *)v8;
            if ( v8 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                   a1: v8,
                   a2: CDmePreset::m_classType.u) != 0 )
            {
              v10 = v9;
            }
            else
            {
              v10 = nullptr;
            }
            m_nAllocationCount = (const char *)v10->m_varNames.m_Memory.m_nAllocationCount;
            if ( m_nAllocationCount == (const char *)-1 )
              m_nAllocationCount = defaultValue;
            v12 = m_nAllocationCount;
            if ( m_nAllocationCount == nullptr || *m_nAllocationCount == 0 )
              v12 = "<no name>";
            v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            v14 = v13 != nullptr ? KeyValues::KeyValues(this: v13, setName: "node") : nullptr;
            KeyValues::SetString(this: v14, keyName: "name", value: v12);
            v15 = v10 != nullptr ? CCodecBuffer_Block::GetBufferType(this: v10) : -1;
            KeyValues::SetInt(this: v14, keyName: "preset", value: v15);
            v16 = v20;
            v17 = v20->m_pPresetList->AddItem(this: v20->m_pPresetList, a2: v14, a3: 0, a4: false, a5: false);
            if ( bSelectAll )
              v16->m_pPresetList->AddSelectedItem(this: v16->m_pPresetList, a2: v17);
            if ( ++i >= nCount )
              break;
            m_pData = presets.m_pStorage;
          }
          v3 = v16;
        }
        v3->m_pPresetList->SortList(this: v3->m_pPresetList);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7050
// Name: public: void CPresetPickerFrame::DoModal(class CDmElement __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetPickerFrame::DoModal(
        CPresetPickerFrame *this,
        CDmElement *pPresetGroup,
        bool bSelectAll,
        KeyValues *pContextKeyValues)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  CPresetPickerFrame::RefreshPresetList(this, pPresetGroup, bSelectAll);
  this->m_pContextKeyValues = pContextKeyValues;
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A6C30
// Name: class CDmePreset __near * GetElementKeyValue<class CDmePreset>(class KeyValues __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePreset *__cdecl GetElementKeyValue<CDmePreset>(KeyValues *pKeyValues, const char *pName)
{
  int Int; // eax
  int v3; // eax
  int v4; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: pName, defaultValue: -1);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v4 = v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmePreset::m_classType.u) != 0 )
  {
    return (CDmePreset *)v4;
  }
  else
  {
    return nullptr;
  }
}

} // namespace sceneviewer
