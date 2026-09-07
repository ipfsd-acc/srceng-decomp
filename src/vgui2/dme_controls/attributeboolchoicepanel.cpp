// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeboolchoicepanel.cpp
// Functions: 40
// ============================================================

#include "vgui2\dme_controls\attributeboolchoicepanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046D7A0
// Name: public: static char const __near * CAttributeBoolChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBoolChoicePanel::GetPanelClassName()
{
  return "CAttributeBoolChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046D7B0
// Name: private: virtual void CAttributeBoolChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::PopulateComboBox(CAttributeBoolChoicePanel *this, vgui::ComboBox *pComboBox)
{
  vgui::ComboBox *v2; // ebx
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorChoicesInfo *v5; // esi
  IElementPropertiesChoices *v6; // ebx
  DmElementHandle_t m_handle; // eax
  CDmElement *v8; // eax
  const char *ChoiceType; // eax
  bool v10; // al
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  CDmElement *v15; // [esp-10h] [ebp-34h]
  BOOL v16; // [esp-8h] [ebp-2Ch]
  const char *choices[2]; // [esp+Ch] [ebp-18h] BYREF
  IElementPropertiesChoices_vtbl *v18; // [esp+14h] [ebp-10h]
  BOOL v19; // [esp+18h] [ebp-Ch]
  const char *pTrueChoice; // [esp+1Ch] [ebp-8h]
  const char *pFalseChoice; // [esp+20h] [ebp-4h]

  v2 = pComboBox;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v5 = (CDmeEditorChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorBoolChoicesInfo::m_classType) )
  {
    pFalseChoice = CDmeEditorChoicesInfo::GetChoiceString(this: v5, nIndex: 0);
    pTrueChoice = CDmeEditorChoicesInfo::GetChoiceString(this: v5, nIndex: 1);
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: v5) )
    {
      v6 = vgui::ElementPropertiesChoices();
      m_handle = this->m_hObject.m_handle;
      LOBYTE(v19) = this->m_nArrayIndex >= 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v18 = v6->__vftable;
      v16 = v19;
      v15 = v8;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v5);
      v10 = v18->GetBoolChoiceList(this: v6, a2: ChoiceType, a3: v15, a4: this->m_szAttributeName, a5: v16, a6: choices);
      v2 = pComboBox;
      if ( v10 )
      {
        pFalseChoice = choices[0];
        pTrueChoice = choices[1];
      }
    }
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "entry");
    else
      v12 = nullptr;
    KeyValues::SetInt(this: v12, keyName: "value", value: 0);
    v2->AddItem_2(this: v2, a2: pFalseChoice, a3: v12);
    v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v13 != nullptr )
      v14 = KeyValues::KeyValues(this: v13, setName: "entry");
    else
      v14 = nullptr;
    KeyValues::SetInt(this: v14, keyName: "value", value: 1);
    v2->AddItem_2(this: v2, a2: pTrueChoice, a3: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D900
// Name: public: void CBaseAttributePanel::SetAttributeValue<bool>(bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<bool>(CBaseAttributePanel *this, bool *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>>::Init(
      this: (CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>::Set(
      this: (CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *)&v9,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D9B0
// Name: private: virtual void CAttributeBoolChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::SetAttributeFromComboBox(
        CAttributeBoolChoicePanel *this,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  bool m_Storage; // bl
  bool bValue; // [esp+Bh] [ebp-1h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
  bValue = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0) != 0;
  if ( m_Storage != bValue )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue<bool>(this, value: &bValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DA50
// Name: private: virtual void CAttributeBoolChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::SetComboBoxFromAttribute(
        CAttributeBoolChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorChoicesInfo *v4; // edi
  IElementPropertiesChoices *v5; // ebx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  int v7; // eax
  const char *ChoiceType; // eax
  vgui::ComboBox_vtbl *v9; // ebx
  const char *ChoiceString; // eax
  int v11; // [esp-10h] [ebp-30h]
  BOOL v12; // [esp-8h] [ebp-28h]
  const char *choices[2]; // [esp+Ch] [ebp-14h] BYREF
  IElementPropertiesChoices_vtbl *v14; // [esp+14h] [ebp-Ch]
  BOOL v15; // [esp+1Bh] [ebp-5h]
  bool bValue; // [esp+1Fh] [ebp-1h]

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeEditorChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorBoolChoicesInfo::m_classType) )
  {
    bValue = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
    if ( !CDmeEditorChoicesInfo::HasChoiceType(this: v4) )
      goto LABEL_6;
    v5 = vgui::ElementPropertiesChoices();
    GetElement = g_pDataModel->GetElement;
    LOBYTE(v15) = this->m_nArrayIndex >= 0;
    v7 = (int)GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    v14 = v5->__vftable;
    v12 = v15;
    v11 = v7;
    ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v4);
    if ( v14->GetBoolChoiceList(
           this: v5,
           a2: ChoiceType,
           a3: (CDmElement *)v11,
           a4: this->m_szAttributeName,
           a5: v12,
           a6: choices) )
    {
      pComboBox->SetText(this: pComboBox, a2: choices[bValue]);
    }
    else
    {
LABEL_6:
      v9 = pComboBox->__vftable;
      ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: v4, nIndex: bValue);
      v9->SetText(this: pComboBox, a2: ChoiceString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DB40
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046DBE0
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DC10
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DC50
// Name: public: CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBoolChoicePanel *__thiscall CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(
        CAttributeBoolChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeBoolChoicePanel_vtbl *)&CAttributeBoolChoicePanel::`vftable';
  if ( `CAttributeBoolChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBoolChoicePanel");
    v4->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeBoolChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBoolChoicePanel");
    v5->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeBoolChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBoolChoicePanel");
    v6->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046DD10
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBoolChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBoolChoicePanel::GetMessageMap(CAttributeBoolChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBoolChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBoolChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBoolChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBoolChoicePanel");
  `CAttributeBoolChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046DD40
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBoolChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBoolChoicePanel::GetAnimMap(CAttributeBoolChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBoolChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046DD50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBoolChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBoolChoicePanel::GetKBMap(CAttributeBoolChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBoolChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBoolChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBoolChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBoolChoicePanel");
  `CAttributeBoolChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046DD80
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046DE00
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorStringChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046DE20
// Name: protected: virtual void CDmeEditorBoolChoicesInfo::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorBoolChoicesInfo::PerformDestruction(CDmeEditorStringChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0046DE40
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DE70
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DF00
// Name: public: virtual bool CDmeEditorBoolChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorBoolChoicesInfo::IsA(CDmeEditorBoolChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorBoolChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DF40
// Name: public: virtual int CDmeEditorBoolChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorBoolChoicesInfo::GetInheritanceDepth(
        CDmeEditorBoolChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorBoolChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DFA0
// Name: protected: virtual void CDmeEditorBoolChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorBoolChoicesInfo::PerformConstruction(CDmeEditorBoolChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::CreateChoice(this, pChoiceString: "false");
  CDmeEditorChoicesInfo::CreateChoice(this, pChoiceString: "true");
}

//------------------------------------------------------------------------------
// Address: 0x0046EB80
// Name: public: class CUtlSymbolLarge const __near & CBaseAttributePanel::GetAttributeValue<class CUtlSymbolLarge>(void)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
        this: (CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (DmElementHandle_t *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<CUtlSymbolLarge>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    if ( (`CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::`local static guard' & 1) == 0 )
      `CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::`local static guard' |= 1u;
    `CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::temp.u.m_Id = -1;
    return (DmElementHandle_t *)&`CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004717F0
// Name: public: class Color const __near & CBaseAttributePanel::GetAttributeValue<class Color>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CBaseAttributePanel::GetAttributeValue<Color>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
        this: (CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<Color> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<Color>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    if ( (`CBaseAttributePanel::GetAttributeValue<Color>'::`5'::`local static guard' & 1) == 0 )
    {
      `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::`local static guard' |= 1u;
      `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp = 0;
    }
    `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp = (Color)-16777216;
    return (CDmaVar<Color> *)&`CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B4C40
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x0067C370
// Name: _dynamic_initializer_for__CDmeEditorBoolChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorBoolChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorBoolChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorBoolChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F740
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F7A0
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681A70
// Name: _dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorBoolChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682B80
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682B90
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067C3A0
// Name: _dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C3B0
// Name: _dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorBoolChoicesInfo_Helper,
           classname: "DmeEditorBoolChoicesInfo",
           pFactory: &g_CDmeEditorBoolChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F770
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F780
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F7D0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F7E0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006819D0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x00681A10
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x00681A50
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x00681A60
// Name: _dynamic_atexit_destructor_for__dme_properties_maxsearchresults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dme_properties_maxsearchresults__()
{
  ConVar::~ConVar(this: &dme_properties_maxsearchresults);
}

//------------------------------------------------------------------------------
// Address: 0x00681A80
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorBoolChoicesInfo_Factory.m_CallBackList);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10490C80
// Name: public: static char const __near * CAttributeBoolChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBoolChoicePanel::GetPanelClassName()
{
  return "CAttributeBoolChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10490C90
// Name: private: virtual void CAttributeBoolChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::PopulateComboBox(CAttributeBoolChoicePanel *this, vgui::ComboBox *pComboBox)
{
  vgui::ComboBox *v2; // ebx
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorChoicesInfo *v5; // esi
  IElementPropertiesChoices *v6; // ebx
  DmElementHandle_t m_handle; // eax
  CDmElement *v8; // eax
  const char *ChoiceType; // eax
  bool v10; // al
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  CDmElement *v15; // [esp-10h] [ebp-34h]
  BOOL v16; // [esp-8h] [ebp-2Ch]
  const char *choices[2]; // [esp+Ch] [ebp-18h] BYREF
  IElementPropertiesChoices_vtbl *v18; // [esp+14h] [ebp-10h]
  BOOL v19; // [esp+18h] [ebp-Ch]
  const char *pTrueChoice; // [esp+1Ch] [ebp-8h]
  const char *pFalseChoice; // [esp+20h] [ebp-4h]

  v2 = pComboBox;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v5 = (CDmeEditorChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorBoolChoicesInfo::m_classType) )
  {
    pFalseChoice = CDmeEditorChoicesInfo::GetChoiceString(this: v5, nIndex: 0);
    pTrueChoice = CDmeEditorChoicesInfo::GetChoiceString(this: v5, nIndex: 1);
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: v5) )
    {
      v6 = vgui::ElementPropertiesChoices();
      m_handle = this->m_hObject.m_handle;
      LOBYTE(v19) = this->m_nArrayIndex >= 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v18 = v6->__vftable;
      v16 = v19;
      v15 = v8;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v5);
      v10 = v18->GetBoolChoiceList(this: v6, a2: ChoiceType, a3: v15, a4: this->m_szAttributeName, a5: v16, a6: choices);
      v2 = pComboBox;
      if ( v10 )
      {
        pFalseChoice = choices[0];
        pTrueChoice = choices[1];
      }
    }
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "entry");
    else
      v12 = nullptr;
    KeyValues::SetInt(this: v12, keyName: "value", value: 0);
    v2->AddItem_2(this: v2, a2: pFalseChoice, a3: v12);
    v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v13 != nullptr )
      v14 = KeyValues::KeyValues(this: v13, setName: "entry");
    else
      v14 = nullptr;
    KeyValues::SetInt(this: v14, keyName: "value", value: 1);
    v2->AddItem_2(this: v2, a2: pTrueChoice, a3: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10490DE0
// Name: public: void CBaseAttributePanel::SetAttributeValue<bool>(bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<bool>(CBaseAttributePanel *this, bool *value)
{
  char *m_szAttributeName; // edi
  CFmtStrN<256> *v4; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  int v8; // eax
  int m_nArrayIndex; // esi
  CDmElement *v10; // ebx
  CFmtStrN<256> v11; // [esp+8h] [ebp-114h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v12; // [esp+114h] [ebp-8h] BYREF

  m_szAttributeName = this->m_szAttributeName;
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "Set %s", this->m_szAttributeName);
  g_pDataModel->StartUndo(this: g_pDataModel, a2: v4->m_szBuf, a3: v4->m_szBuf, a4: 0);
  GetElement = g_pDataModel->GetElement;
  if ( this->m_nArrayIndex >= 0 )
  {
    v8 = ((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v10 = (CDmElement *)v8;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v12);
    CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>>::Init(
      this: (CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > > *)&v12,
      pElement: v10,
      pAttributeName: m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>::Set(
      this: (CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *)&v12,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    v6 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: m_szAttributeName, type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: Attribute, value);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x10490EB0
// Name: private: virtual void CAttributeBoolChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::SetAttributeFromComboBox(
        CAttributeBoolChoicePanel *this,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  bool m_Storage; // bl
  bool bValue; // [esp+Bh] [ebp-1h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
  bValue = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0) != 0;
  if ( m_Storage != bValue )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue<bool>(this, value: &bValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10490F50
// Name: private: virtual void CAttributeBoolChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::SetComboBoxFromAttribute(
        CAttributeBoolChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorChoicesInfo *v4; // edi
  IElementPropertiesChoices *v5; // ebx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  int v7; // eax
  const char *ChoiceType; // eax
  vgui::ComboBox_vtbl *v9; // ebx
  const char *ChoiceString; // eax
  int v11; // [esp-10h] [ebp-30h]
  BOOL v12; // [esp-8h] [ebp-28h]
  const char *choices[2]; // [esp+Ch] [ebp-14h] BYREF
  IElementPropertiesChoices_vtbl *v14; // [esp+14h] [ebp-Ch]
  BOOL v15; // [esp+1Bh] [ebp-5h]
  bool bValue; // [esp+1Fh] [ebp-1h]

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeEditorChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorBoolChoicesInfo::m_classType) )
  {
    bValue = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
    if ( !CDmeEditorChoicesInfo::HasChoiceType(this: v4) )
      goto LABEL_6;
    v5 = vgui::ElementPropertiesChoices();
    GetElement = g_pDataModel->GetElement;
    LOBYTE(v15) = this->m_nArrayIndex >= 0;
    v7 = (int)GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    v14 = v5->__vftable;
    v12 = v15;
    v11 = v7;
    ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v4);
    if ( v14->GetBoolChoiceList(
           this: v5,
           a2: ChoiceType,
           a3: (CDmElement *)v11,
           a4: this->m_szAttributeName,
           a5: v12,
           a6: choices) )
    {
      pComboBox->SetText(this: pComboBox, a2: choices[bValue]);
    }
    else
    {
LABEL_6:
      v9 = pComboBox->__vftable;
      ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: v4, nIndex: bValue);
      v9->SetText(this: pComboBox, a2: ChoiceString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10491040
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104910E0
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10491110
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10491150
// Name: public: CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBoolChoicePanel *__thiscall CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(
        CAttributeBoolChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeBoolChoicePanel_vtbl *)&CAttributeBoolChoicePanel::`vftable';
  if ( `CAttributeBoolChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBoolChoicePanel");
    v4->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeBoolChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBoolChoicePanel");
    v5->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeBoolChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBoolChoicePanel");
    v6->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10491210
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBoolChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBoolChoicePanel::GetMessageMap(CAttributeBoolChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBoolChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBoolChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBoolChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBoolChoicePanel");
  `CAttributeBoolChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10491240
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBoolChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBoolChoicePanel::GetAnimMap(CAttributeBoolChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBoolChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10491250
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBoolChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBoolChoicePanel::GetKBMap(CAttributeBoolChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBoolChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBoolChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBoolChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBoolChoicePanel");
  `CAttributeBoolChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10491280
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10491300
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10491330
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104913C0
// Name: public: virtual bool CDmeEditorBoolChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorBoolChoicesInfo::IsA(CDmeEditorBoolChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorBoolChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10491400
// Name: public: virtual int CDmeEditorBoolChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorBoolChoicesInfo::GetInheritanceDepth(
        CDmeEditorBoolChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorBoolChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10491460
// Name: protected: virtual void CDmeEditorBoolChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorBoolChoicesInfo::PerformConstruction(CDmeEditorBoolChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::CreateChoice(this, pChoiceString: "false");
  CDmeEditorChoicesInfo::CreateChoice(this, pChoiceString: "true");
}

//------------------------------------------------------------------------------
// Address: 0x10491D20
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorStringChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10491D40
// Name: protected: virtual void CDmeEditorBoolChoicesInfo::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorBoolChoicesInfo::PerformDestruction(CDmeEditorStringChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10492080
// Name: public: class CUtlSymbolLarge const __near & CBaseAttributePanel::GetAttributeValue<class CUtlSymbolLarge>(void)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
        this: (CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (DmElementHandle_t *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<CUtlSymbolLarge>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    if ( (`CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::`local static guard' & 1) == 0 )
      `CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::`local static guard' |= 1u;
    `CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::temp.u.m_Id = -1;
    return (DmElementHandle_t *)&`CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10494CD0
// Name: public: class Color const __near & CBaseAttributePanel::GetAttributeValue<class Color>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CBaseAttributePanel::GetAttributeValue<Color>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
        this: (CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<Color> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<Color>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    if ( (`CBaseAttributePanel::GetAttributeValue<Color>'::`5'::`local static guard' & 1) == 0 )
    {
      `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::`local static guard' |= 1u;
      `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp = 0;
    }
    `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp = (Color)-16777216;
    return (CDmaVar<Color> *)&`CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C6600
// Name: _dynamic_initializer_for__CDmeEditorBoolChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorBoolChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorBoolChoicesInfo::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorBoolChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6C30
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6C90
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC960
// Name: _dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorBoolChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC30
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC40
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C6630
// Name: _dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6640
// Name: _dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorBoolChoicesInfo_Helper,
           classname: "DmeEditorBoolChoicesInfo",
           pFactory: &g_CDmeEditorBoolChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6C60
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6C70
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6CC0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6CD0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CC970
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeEditorBoolChoicesInfo_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00497440
// Name: public: static char const __near * CAttributeBoolChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBoolChoicePanel::GetPanelClassName()
{
  return "CAttributeBoolChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00497450
// Name: private: virtual void CAttributeBoolChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::PopulateComboBox(CAttributeBoolChoicePanel *this, vgui::ComboBox *pComboBox)
{
  vgui::ComboBox *v2; // ebx
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorChoicesInfo *v5; // esi
  IElementPropertiesChoices *v6; // ebx
  DmElementHandle_t m_handle; // eax
  int v8; // eax
  const char *ChoiceType; // eax
  bool v10; // al
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  int v15; // [esp-10h] [ebp-34h]
  BOOL v16; // [esp-8h] [ebp-2Ch]
  const char *choices[2]; // [esp+Ch] [ebp-18h] BYREF
  IElementPropertiesChoices_vtbl *v18; // [esp+14h] [ebp-10h]
  BOOL v19; // [esp+18h] [ebp-Ch]
  const char *pTrueChoice; // [esp+1Ch] [ebp-8h]
  const char *pFalseChoice; // [esp+20h] [ebp-4h]

  v2 = pComboBox;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v5 = (CDmeEditorChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorBoolChoicesInfo::m_classType) )
  {
    pFalseChoice = CDmeEditorChoicesInfo::GetChoiceString(this: v5, nIndex: 0);
    pTrueChoice = CDmeEditorChoicesInfo::GetChoiceString(this: v5, nIndex: 1);
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: v5) )
    {
      v6 = vgui::ElementPropertiesChoices();
      m_handle = this->m_hObject.m_handle;
      LOBYTE(v19) = this->m_nArrayIndex >= 0;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_handle);
      v18 = v6->__vftable;
      v16 = v19;
      v15 = v8;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v5);
      v10 = v18->GetBoolChoiceList(
              this: v6,
              a2: ChoiceType,
              a3: (CDmElement *)v15,
              a4: this->m_szAttributeName,
              a5: v16,
              a6: choices);
      v2 = pComboBox;
      if ( v10 )
      {
        pFalseChoice = choices[0];
        pTrueChoice = choices[1];
      }
    }
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "entry");
    else
      v12 = nullptr;
    KeyValues::SetInt(this: v12, keyName: "value", value: 0);
    v2->AddItem_2(this: v2, a2: pFalseChoice, a3: v12);
    v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v13 != nullptr )
      v14 = KeyValues::KeyValues(this: v13, setName: "entry");
    else
      v14 = nullptr;
    KeyValues::SetInt(this: v14, keyName: "value", value: 1);
    v2->AddItem_2(this: v2, a2: pTrueChoice, a3: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004975A0
// Name: public: void CBaseAttributePanel::SetAttributeValue<bool>(bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<bool>(CBaseAttributePanel *this, bool *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  int v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = (CDmElement *)v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>>::Init(
      this: (CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>::Set(
      this: (CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *)&v9,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497650
// Name: private: virtual void CAttributeBoolChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::SetAttributeFromComboBox(
        CAttributeBoolChoicePanel *this,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  bool m_Storage; // bl
  bool bValue; // [esp+Bh] [ebp-1h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
  bValue = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0) != 0;
  if ( m_Storage != bValue )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4,
      a4: 256);
    CBaseAttributePanel::SetAttributeValue<bool>(this, value: &bValue);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004976F0
// Name: private: virtual void CAttributeBoolChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBoolChoicePanel::SetComboBoxFromAttribute(
        CAttributeBoolChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorChoicesInfo *v4; // edi
  IElementPropertiesChoices *v5; // ebx
  int (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  int v7; // eax
  const char *ChoiceType; // eax
  vgui::ComboBox_vtbl *v9; // ebx
  const char *ChoiceString; // eax
  int v11; // [esp-10h] [ebp-30h]
  BOOL v12; // [esp-8h] [ebp-28h]
  const char *choices[2]; // [esp+Ch] [ebp-14h] BYREF
  IElementPropertiesChoices_vtbl *v14; // [esp+14h] [ebp-Ch]
  BOOL v15; // [esp+1Bh] [ebp-5h]
  bool bValue; // [esp+1Fh] [ebp-1h]

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeEditorChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorBoolChoicesInfo::m_classType) )
  {
    bValue = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
    if ( !CDmeEditorChoicesInfo::HasChoiceType(this: v4) )
      goto LABEL_6;
    v5 = vgui::ElementPropertiesChoices();
    v6 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    LOBYTE(v15) = this->m_nArrayIndex >= 0;
    v7 = ((int (__thiscall *)(_DWORD, _DWORD))v6)(
           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
           a2: this->m_hObject.m_handle);
    v14 = v5->__vftable;
    v12 = v15;
    v11 = v7;
    ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v4);
    if ( v14->GetBoolChoiceList(
           this: v5,
           a2: ChoiceType,
           a3: (CDmElement *)v11,
           a4: this->m_szAttributeName,
           a5: v12,
           a6: choices) )
    {
      pComboBox->SetText(this: pComboBox, a2: choices[bValue]);
    }
    else
    {
LABEL_6:
      v9 = pComboBox->__vftable;
      ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: v4, nIndex: bValue);
      v9->SetText(this: pComboBox, a2: ChoiceString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004977E0
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00497880
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004978B0
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004978F0
// Name: public: CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBoolChoicePanel *__thiscall CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(
        CAttributeBoolChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeBoolChoicePanel_vtbl *)&CAttributeBoolChoicePanel::`vftable';
  if ( `CAttributeBoolChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBoolChoicePanel");
    v4->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeBoolChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBoolChoicePanel");
    v5->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeBoolChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBoolChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBoolChoicePanel");
    v6->pfnClassName = CAttributeBoolChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004979B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBoolChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBoolChoicePanel::GetMessageMap(CAttributeBoolChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBoolChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBoolChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBoolChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBoolChoicePanel");
  `CAttributeBoolChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004979E0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBoolChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBoolChoicePanel::GetAnimMap(CAttributeBoolChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBoolChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004979F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBoolChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBoolChoicePanel::GetKBMap(CAttributeBoolChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBoolChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBoolChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBoolChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBoolChoicePanel");
  `CAttributeBoolChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497A20
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00497AA0
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorStringChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00497AC0
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00497AF0
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00497B80
// Name: public: virtual bool CDmeEditorBoolChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorBoolChoicesInfo::IsA(CDmeEditorBoolChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorBoolChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00497BC0
// Name: public: virtual int CDmeEditorBoolChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorBoolChoicesInfo::GetInheritanceDepth(
        CDmeEditorBoolChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorBoolChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00497C20
// Name: protected: virtual void CDmeEditorBoolChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorBoolChoicesInfo::PerformConstruction(CDmeEditorBoolChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::OnConstruction(this);
  CDmeEditorChoicesInfo::CreateChoice(this, pChoiceString: "false");
  CDmeEditorChoicesInfo::CreateChoice(this, pChoiceString: "true");
}

//------------------------------------------------------------------------------
// Address: 0x00498800
// Name: public: class CUtlSymbolLarge const __near & CBaseAttributePanel::GetAttributeValue<class CUtlSymbolLarge>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlSymbolLarge> *__thiscall CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
        this: (CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<CUtlSymbolLarge> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<CUtlSymbolLarge>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    if ( (`CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::`local static guard' & 1) == 0 )
      `CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::`local static guard' |= 1u;
    `CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::temp.u.m_Id = -1;
    return (CDmaVar<CUtlSymbolLarge> *)&`CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B3D0
// Name: public: class Color const __near & CBaseAttributePanel::GetAttributeValue<class Color>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CBaseAttributePanel::GetAttributeValue<Color>(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // edi
  int m_nArrayIndex; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v6; // [esp+8h] [ebp-8h] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    if ( m_nArrayIndex >= 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v6);
      CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
        this: (CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<Color> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<Color>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    if ( (`CBaseAttributePanel::GetAttributeValue<Color>'::`5'::`local static guard' & 1) == 0 )
    {
      `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::`local static guard' |= 1u;
      `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp = 0;
    }
    `CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp = (Color)-16777216;
    return (CDmaVar<Color> *)&`CBaseAttributePanel::GetAttributeValue<Color>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050BFD0
// Name: protected: virtual void CDmeEditorBoolChoicesInfo::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorBoolChoicesInfo::PerformDestruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005D7840
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x006ABD80
// Name: _dynamic_initializer_for__CDmeEditorBoolChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorBoolChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorBoolChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorBoolChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1590
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B15F0
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3860
// Name: _dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorBoolChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorBoolChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5680
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5690
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ABDB0
// Name: _dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ABDC0
// Name: _dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorBoolChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorBoolChoicesInfo_Helper,
           classname: "DmeEditorBoolChoicesInfo",
           pFactory: &g_CDmeEditorBoolChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B15C0
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B15D0
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1620
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1630
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3870
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorBoolChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorBoolChoicesInfo_Factory.m_CallBackList);
}

} // namespace sceneviewer
