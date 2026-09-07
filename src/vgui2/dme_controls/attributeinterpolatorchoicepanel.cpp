// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeinterpolatorchoicepanel.cpp
// Functions: 8
// ============================================================

#include "vgui2\dme_controls\attributeinterpolatorchoicepanel.h"

//------------------------------------------------------------------------------
// Address: 0x00472480
// Name: public: static char const __near * CAttributeInterpolatorChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeInterpolatorChoicePanel::GetPanelClassName()
{
  return "CAttributeInterpolatorChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00472490
// Name: private: virtual void CAttributeInterpolatorChoicePanel::PopulateComboBoxes(class vgui::ComboBox __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::PopulateComboBoxes(
        CAttributeInterpolatorChoicePanel *this,
        vgui::ComboBox **pComboBox)
{
  int i; // esi
  KeyValues *v4; // eax
  vgui::ComboBox_vtbl *v5; // edi
  const char *v6; // eax
  KeyValues *v7; // eax
  vgui::ComboBox_vtbl *v8; // edi
  const char *v9; // eax
  KeyValues *kv; // [esp+14h] [ebp+8h]
  KeyValues *kva; // [esp+14h] [ebp+8h]

  vgui::ComboBox::RemoveAll(this: *pComboBox);
  vgui::ComboBox::RemoveAll(this: pComboBox[1]);
  for ( i = 0; i < 16; ++i )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      kv = KeyValues::KeyValues(this: v4, setName: "entry");
    else
      kv = nullptr;
    KeyValues::SetInt(this: kv, keyName: "value", value: i);
    v5 = (*pComboBox)->__vftable;
    v6 = Interpolator_NameForInterpolator(type: i, printname: true);
    v5->AddItem_2(this: *pComboBox, a2: v6, a3: kv);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      kva = KeyValues::KeyValues(this: v7, setName: "entry");
    else
      kva = nullptr;
    KeyValues::SetInt(this: kva, keyName: "value", value: i);
    v8 = pComboBox[1]->__vftable;
    v9 = Interpolator_NameForInterpolator(type: i, printname: true);
    v8->AddItem_2(this: pComboBox[1], a2: v9, a3: kva);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472570
// Name: private: virtual void CAttributeInterpolatorChoicePanel::SetAttributeFromComboBoxes(class vgui::ComboBox __near * __near * const,class KeyValues __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::SetAttributeFromComboBoxes(
        CAttributeInterpolatorChoicePanel *this,
        vgui::ComboBox **pComboBox,
        KeyValues **pKeyValues)
{
  int m_Storage; // ebx
  unsigned __int8 Int; // si
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v7; // esi
  int nValue; // [esp+Ch] [ebp-4h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  Int = KeyValues::GetInt(this: *pKeyValues, keyName: "value", defaultValue: 0);
  nValue = (Int << 8) | (unsigned __int8)KeyValues::GetInt(this: pKeyValues[1], keyName: "value", defaultValue: 0);
  if ( m_Storage != nValue )
  {
    m_pNotify = this->m_pNotify;
    v7 = nullptr;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v7 = m_pNotify;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &nValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v7 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472670
// Name: private: virtual void CAttributeInterpolatorChoicePanel::SetComboBoxesFromAttribute(class vgui::ComboBox __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::SetComboBoxesFromAttribute(
        CAttributeInterpolatorChoicePanel *this,
        vgui::TextEntry **pComboBox)
{
  int m_Storage; // esi
  vgui::TextEntry *v3; // edi
  vgui::ComboBox_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::ComboBox *v6; // edi
  vgui::ComboBox_vtbl *v7; // ebx
  const char *v8; // eax

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  v3 = *pComboBox;
  v4 = (vgui::ComboBox_vtbl *)(*pComboBox)->__vftable;
  v5 = Interpolator_NameForInterpolator(type: BYTE1(m_Storage), printname: true);
  v4->SetText(this: v3, a2: v5);
  v6 = (vgui::ComboBox *)pComboBox[1];
  v7 = v6->__vftable;
  v8 = Interpolator_NameForInterpolator(type: (unsigned __int8)m_Storage, printname: true);
  v7->SetText(this: v6, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x004726D0
// Name: public: CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeInterpolatorChoicePanel *__thiscall CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(
        CAttributeInterpolatorChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(this, parent, info);
  this->__vftable = (CAttributeInterpolatorChoicePanel_vtbl *)&CAttributeInterpolatorChoicePanel::`vftable';
  if ( `CAttributeInterpolatorChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeInterpolatorChoicePanel");
    v4->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  if ( `CAttributeInterpolatorChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeInterpolatorChoicePanel");
    v5->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  if ( `CAttributeInterpolatorChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeInterpolatorChoicePanel");
    v6->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00472790
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeInterpolatorChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeInterpolatorChoicePanel::GetMessageMap(
        CAttributeInterpolatorChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeInterpolatorChoicePanel");
  `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004727C0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeInterpolatorChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeInterpolatorChoicePanel::GetAnimMap(CAttributeInterpolatorChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeInterpolatorChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004727D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeInterpolatorChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeInterpolatorChoicePanel::GetKBMap(
        CAttributeInterpolatorChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeInterpolatorChoicePanel");
  `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104959B0
// Name: public: static char const __near * CAttributeInterpolatorChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeInterpolatorChoicePanel::GetPanelClassName()
{
  return "CAttributeInterpolatorChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x104959C0
// Name: private: virtual void CAttributeInterpolatorChoicePanel::PopulateComboBoxes(class vgui::ComboBox __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::PopulateComboBoxes(
        CAttributeInterpolatorChoicePanel *this,
        vgui::ComboBox **pComboBox)
{
  int i; // esi
  KeyValues *v4; // eax
  vgui::ComboBox_vtbl *v5; // edi
  const char *v6; // eax
  KeyValues *v7; // eax
  vgui::ComboBox_vtbl *v8; // edi
  const char *v9; // eax
  KeyValues *kv; // [esp+14h] [ebp+8h]
  KeyValues *kva; // [esp+14h] [ebp+8h]

  vgui::ComboBox::RemoveAll(this: *pComboBox);
  vgui::ComboBox::RemoveAll(this: pComboBox[1]);
  for ( i = 0; i < 16; ++i )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      kv = KeyValues::KeyValues(this: v4, setName: "entry");
    else
      kv = nullptr;
    KeyValues::SetInt(this: kv, keyName: "value", value: i);
    v5 = (*pComboBox)->__vftable;
    v6 = Interpolator_NameForInterpolator(type: i, printname: true);
    v5->AddItem_2(this: *pComboBox, a2: v6, a3: kv);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      kva = KeyValues::KeyValues(this: v7, setName: "entry");
    else
      kva = nullptr;
    KeyValues::SetInt(this: kva, keyName: "value", value: i);
    v8 = pComboBox[1]->__vftable;
    v9 = Interpolator_NameForInterpolator(type: i, printname: true);
    v8->AddItem_2(this: pComboBox[1], a2: v9, a3: kva);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10495AA0
// Name: private: virtual void CAttributeInterpolatorChoicePanel::SetAttributeFromComboBoxes(class vgui::ComboBox __near * __near * const,class KeyValues __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::SetAttributeFromComboBoxes(
        CAttributeInterpolatorChoicePanel *this,
        vgui::ComboBox **pComboBox,
        KeyValues **pKeyValues)
{
  int m_Storage; // ebx
  unsigned __int8 Int; // si
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v7; // esi
  int nValue; // [esp+Ch] [ebp-4h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  Int = KeyValues::GetInt(this: *pKeyValues, keyName: "value", defaultValue: 0);
  nValue = (Int << 8) | (unsigned __int8)KeyValues::GetInt(this: pKeyValues[1], keyName: "value", defaultValue: 0);
  if ( m_Storage != nValue )
  {
    m_pNotify = this->m_pNotify;
    v7 = nullptr;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v7 = m_pNotify;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &nValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v7 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10495BA0
// Name: private: virtual void CAttributeInterpolatorChoicePanel::SetComboBoxesFromAttribute(class vgui::ComboBox __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::SetComboBoxesFromAttribute(
        CAttributeInterpolatorChoicePanel *this,
        vgui::TextEntry **pComboBox)
{
  int m_Storage; // esi
  vgui::TextEntry *v3; // edi
  vgui::ComboBox_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::ComboBox *v6; // edi
  vgui::ComboBox_vtbl *v7; // ebx
  const char *v8; // eax

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  v3 = *pComboBox;
  v4 = (vgui::ComboBox_vtbl *)(*pComboBox)->__vftable;
  v5 = Interpolator_NameForInterpolator(type: BYTE1(m_Storage), printname: true);
  v4->SetText(this: v3, a2: v5);
  v6 = (vgui::ComboBox *)pComboBox[1];
  v7 = v6->__vftable;
  v8 = Interpolator_NameForInterpolator(type: (unsigned __int8)m_Storage, printname: true);
  v7->SetText(this: v6, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10495C00
// Name: public: CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeInterpolatorChoicePanel *__thiscall CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(
        CAttributeInterpolatorChoicePanel *this,
        vgui::Panel *parent,
        vgui::Panel *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(this, parent, info);
  this->__vftable = (CAttributeInterpolatorChoicePanel_vtbl *)&CAttributeInterpolatorChoicePanel::`vftable';
  if ( `CAttributeInterpolatorChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeInterpolatorChoicePanel");
    v4->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  if ( `CAttributeInterpolatorChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeInterpolatorChoicePanel");
    v5->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  if ( `CAttributeInterpolatorChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeInterpolatorChoicePanel");
    v6->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10495CC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeInterpolatorChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeInterpolatorChoicePanel::GetMessageMap(
        CAttributeInterpolatorChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeInterpolatorChoicePanel");
  `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10495CF0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeInterpolatorChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeInterpolatorChoicePanel::GetAnimMap(CAttributeInterpolatorChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeInterpolatorChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10495D00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeInterpolatorChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeInterpolatorChoicePanel::GetKBMap(
        CAttributeInterpolatorChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeInterpolatorChoicePanel");
  `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0049C070
// Name: public: static char const __near * CAttributeInterpolatorChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeInterpolatorChoicePanel::GetPanelClassName()
{
  return "CAttributeInterpolatorChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049C080
// Name: private: virtual void CAttributeInterpolatorChoicePanel::PopulateComboBoxes(class vgui::ComboBox __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::PopulateComboBoxes(
        CAttributeInterpolatorChoicePanel *this,
        vgui::ComboBox **pComboBox)
{
  int i; // esi
  KeyValues *v4; // eax
  vgui::ComboBox_vtbl *v5; // edi
  const char *v6; // eax
  KeyValues *v7; // eax
  vgui::ComboBox_vtbl *v8; // edi
  const char *v9; // eax
  KeyValues *kv; // [esp+14h] [ebp+8h]
  KeyValues *kva; // [esp+14h] [ebp+8h]

  vgui::ComboBox::RemoveAll(this: *pComboBox);
  vgui::ComboBox::RemoveAll(this: pComboBox[1]);
  for ( i = 0; i < 16; ++i )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      kv = KeyValues::KeyValues(this: v4, setName: "entry");
    else
      kv = nullptr;
    KeyValues::SetInt(this: kv, keyName: "value", value: i);
    v5 = (*pComboBox)->__vftable;
    v6 = Interpolator_NameForInterpolator(type: i, printname: true);
    v5->AddItem_2(this: *pComboBox, a2: v6, a3: kv);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      kva = KeyValues::KeyValues(this: v7, setName: "entry");
    else
      kva = nullptr;
    KeyValues::SetInt(this: kva, keyName: "value", value: i);
    v8 = pComboBox[1]->__vftable;
    v9 = Interpolator_NameForInterpolator(type: i, printname: true);
    v8->AddItem_2(this: pComboBox[1], a2: v9, a3: kva);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C160
// Name: private: virtual void CAttributeInterpolatorChoicePanel::SetAttributeFromComboBoxes(class vgui::ComboBox __near * __near * const,class KeyValues __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::SetAttributeFromComboBoxes(
        CAttributeInterpolatorChoicePanel *this,
        vgui::ComboBox **pComboBox,
        KeyValues **pKeyValues)
{
  int m_Storage; // ebx
  unsigned __int8 Int; // si
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v7; // esi
  int nValue; // [esp+Ch] [ebp-4h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  Int = KeyValues::GetInt(this: *pKeyValues, keyName: "value", defaultValue: 0);
  nValue = (Int << 8) | (unsigned __int8)KeyValues::GetInt(this: pKeyValues[1], keyName: "value", defaultValue: 0);
  if ( m_Storage != nValue )
  {
    m_pNotify = this->m_pNotify;
    v7 = nullptr;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v7 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4,
      a4: 256);
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &nValue);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    if ( v7 != nullptr )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C260
// Name: private: virtual void CAttributeInterpolatorChoicePanel::SetComboBoxesFromAttribute(class vgui::ComboBox __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeInterpolatorChoicePanel::SetComboBoxesFromAttribute(
        CAttributeInterpolatorChoicePanel *this,
        vgui::TextEntry **pComboBox)
{
  int m_Storage; // esi
  vgui::TextEntry *v3; // edi
  vgui::ComboBox_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::ComboBox *v6; // edi
  vgui::ComboBox_vtbl *v7; // ebx
  const char *v8; // eax

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  v3 = *pComboBox;
  v4 = (vgui::ComboBox_vtbl *)(*pComboBox)->__vftable;
  v5 = Interpolator_NameForInterpolator(type: BYTE1(m_Storage), printname: true);
  v4->SetText(this: v3, a2: v5);
  v6 = (vgui::ComboBox *)pComboBox[1];
  v7 = v6->__vftable;
  v8 = Interpolator_NameForInterpolator(type: (unsigned __int8)m_Storage, printname: true);
  v7->SetText(this: v6, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x0049C2C0
// Name: public: CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeInterpolatorChoicePanel *__thiscall CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(
        CAttributeInterpolatorChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(this, parent, info);
  this->__vftable = (CAttributeInterpolatorChoicePanel_vtbl *)&CAttributeInterpolatorChoicePanel::`vftable';
  if ( `CAttributeInterpolatorChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeInterpolatorChoicePanel");
    v4->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  if ( `CAttributeInterpolatorChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeInterpolatorChoicePanel");
    v5->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  if ( `CAttributeInterpolatorChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeInterpolatorChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeInterpolatorChoicePanel");
    v6->pfnClassName = CAttributeInterpolatorChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049C380
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeInterpolatorChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeInterpolatorChoicePanel::GetMessageMap(
        CAttributeInterpolatorChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeInterpolatorChoicePanel");
  `CAttributeInterpolatorChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C3B0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeInterpolatorChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeInterpolatorChoicePanel::GetAnimMap(CAttributeInterpolatorChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeInterpolatorChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049C3C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeInterpolatorChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeInterpolatorChoicePanel::GetKBMap(
        CAttributeInterpolatorChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeInterpolatorChoicePanel");
  `CAttributeInterpolatorChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
