// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributestringchoicepanel.cpp
// Functions: 46
// ============================================================

#include "vgui2\dme_controls\attributestringchoicepanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046E8F0
// Name: public: static char const __near * CAttributeStringChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeStringChoicePanel::GetPanelClassName()
{
  return "CAttributeStringChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046E900
// Name: public: char const __near * CDmeEditorStringChoicesInfo::GetChoiceValue(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorStringChoicesInfo::GetChoiceValue(CDmeEditorStringChoicesInfo *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t *v6; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 == nullptr || !v2->IsA(this: v2, a2: CDmElement::m_classType) )
    return nullptr;
  if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
  if ( Attribute == nullptr )
    return `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id != -1
         ? (const char *)`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id
         : nullptr;
  v6 = CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
  return *v6 != DMELEMENT_HANDLE_INVALID ? (const char *)*v6 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046E9B0
// Name: private: virtual void CAttributeStringChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeStringChoicePanel::PopulateComboBox(
        CAttributeStringChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CAttributeStringChoicePanel *v2; // esi
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  const char *ChoiceValue; // eax
  vgui::ComboBox_vtbl *v8; // esi
  const char *ChoiceString; // eax
  KeyValues *v10; // eax
  bool v11; // sf
  DmElementHandle_t m_handle; // eax
  CDmElement *v13; // eax
  int v14; // edi
  const char *ChoiceType; // eax
  int v16; // edi
  int i; // esi
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  StringChoice_t *m_pMemory; // eax
  CDmElement *v21; // [esp-10h] [ebp-3Ch]
  CAttributeStringChoicePanel *v22; // [esp-8h] [ebp-34h]
  CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  CAttributeStringChoicePanel *v24; // [esp+20h] [ebp-Ch]
  int c; // [esp+24h] [ebp-8h]
  KeyValues *kv; // [esp+28h] [ebp-4h]

  v2 = this;
  v24 = this;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this: v2);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorStringChoicesInfo::m_classType) )
  {
    v5 = 0;
    c = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
    if ( c > 0 )
    {
      do
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          kv = KeyValues::KeyValues(this: v6, setName: "entry");
        else
          kv = nullptr;
        ChoiceValue = CDmeEditorStringChoicesInfo::GetChoiceValue(this: (CDmeEditorStringChoicesInfo *)v4, nIndex: v5);
        KeyValues::SetString(this: kv, keyName: "value", value: ChoiceValue);
        v8 = pComboBox->__vftable;
        ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: (CDmeEditorChoicesInfo *)v4, nIndex: v5);
        v8->AddItem_2(this: pComboBox, a2: ChoiceString, a3: kv);
        ++v5;
      }
      while ( v5 < c );
      v2 = v24;
    }
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: (CDmeEditorChoicesInfo *)v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v10 = (KeyValues *)vgui::ElementPropertiesChoices();
      v11 = v2->m_nArrayIndex < 0;
      kv = v10;
      m_handle = v2->m_hObject.m_handle;
      LOBYTE(v24) = !v11;
      v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v14 = *(_DWORD *)kv;
      v22 = v24;
      v21 = v13;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: (CDmeEditorChoicesInfo *)v4);
      if ( (*(unsigned __int8 (__thiscall **)(KeyValues *, const char *, CDmElement *, char *, CAttributeStringChoicePanel *, CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > *))(v14 + 8))(
             a1: kv,
             a2: ChoiceType,
             a3: v21,
             a4: v2->m_szAttributeName,
             a5: v22,
             a6: &choices) != 0 )
      {
        v16 = 0;
        for ( i = choices.m_Size; v16 < i; ++v16 )
        {
          v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v18 != nullptr )
            v19 = KeyValues::KeyValues(this: v18, setName: "entry");
          else
            v19 = nullptr;
          KeyValues::SetString(this: v19, keyName: "value", value: choices.m_Memory.m_pMemory[v16].m_pValue);
          pComboBox->AddItem_2(this: pComboBox, a2: choices.m_Memory.m_pMemory[v16].m_pChoiceString, a3: v19);
        }
      }
      m_pMemory = choices.m_Memory.m_pMemory;
      choices.m_Size = 0;
      if ( choices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( choices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          choices.m_Memory.m_pMemory = nullptr;
        }
        choices.m_Memory.m_nAllocationCount = 0;
      }
      choices.m_pElements = m_pMemory;
      if ( choices.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046EC20
// Name: private: virtual void CAttributeStringChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeStringChoicePanel::SetAttributeFromComboBox(
        CAttributeStringChoicePanel *this@<ecx>,
        int a2@<ebx>,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  DmElementHandle_t v5; // eax
  const char *v6; // esi
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v8; // esi
  const char *pNewString; // [esp+14h] [ebp+Ch]

  v5 = *CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this);
  v6 = defaultValue;
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    v6 = (const char *)v5;
  pNewString = KeyValues::GetString(this: pKeyValues, keyName: "value", defaultValue: defaultValue);
  if ( v6 != pNewString )
  {
    m_pNotify = this->m_pNotify;
    v8 = nullptr;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v8 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue(this, pValue: pNewString);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v8 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ED00
// Name: private: virtual void CAttributeStringChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeStringChoicePanel::SetComboBoxFromAttribute(
        CAttributeStringChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // esi
  const char *v5; // eax
  int ChoiceCount; // ebx
  int v7; // edi
  const char *ChoiceValue; // eax
  IElementPropertiesChoices *v9; // ebx
  DmElementHandle_t m_handle; // eax
  CDmElement *v11; // eax
  IElementPropertiesChoices_vtbl *v12; // edi
  const char *ChoiceType; // eax
  int v14; // esi
  int m_Size; // edi
  StringChoice_t *v16; // eax
  vgui::ComboBox_vtbl *v17; // ebx
  const char *ChoiceString; // eax
  StringChoice_t *m_pMemory; // eax
  CDmElement *v20; // [esp-10h] [ebp-3Ch]
  char *m_szAttributeName; // [esp-Ch] [ebp-38h]
  BOOL v22; // [esp-8h] [ebp-34h]
  CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  BOOL v24; // [esp+20h] [ebp-Ch]
  CAttributeStringChoicePanel *v25; // [esp+24h] [ebp-8h]
  const char *pValue; // [esp+28h] [ebp-4h]

  v25 = this;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo == nullptr || !EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorStringChoicesInfo::m_classType) )
    return;
  v5 = (const char *)*CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this);
  pValue = defaultValue;
  if ( v5 != (const char *)-1 )
    pValue = v5;
  ChoiceCount = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
  v7 = 0;
  if ( ChoiceCount <= 0 )
  {
LABEL_8:
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: (CDmeEditorChoicesInfo *)v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v9 = vgui::ElementPropertiesChoices();
      m_handle = v25->m_hObject.m_handle;
      LOBYTE(v24) = v25->m_nArrayIndex >= 0;
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v12 = v9->__vftable;
      v22 = v24;
      m_szAttributeName = v25->m_szAttributeName;
      v20 = v11;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: (CDmeEditorChoicesInfo *)v4);
      if ( v12->GetStringChoiceList(this: v9, a2: ChoiceType, a3: v20, a4: m_szAttributeName, a5: v22, a6: &choices) )
      {
        v14 = 0;
        m_Size = choices.m_Size;
        if ( choices.m_Size > 0 )
        {
          while ( _V_stricmp(s1: pValue, s2: choices.m_Memory.m_pMemory[v14].m_pValue) != 0 )
          {
            if ( ++v14 >= m_Size )
              goto LABEL_13;
          }
          pComboBox->SetText(this: pComboBox, a2: choices.m_Memory.m_pMemory[v14].m_pChoiceString);
          m_pMemory = choices.m_Memory.m_pMemory;
          choices.m_Size = 0;
          if ( choices.m_Memory.m_nGrowSize >= 0 )
          {
            if ( choices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              choices.m_Memory.m_pMemory = nullptr;
            }
            choices.m_Memory.m_nAllocationCount = 0;
          }
          choices.m_pElements = m_pMemory;
          if ( choices.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          return;
        }
      }
LABEL_13:
      v16 = choices.m_Memory.m_pMemory;
      choices.m_Size = 0;
      if ( choices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( choices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
          v16 = nullptr;
          choices.m_Memory.m_pMemory = nullptr;
        }
        choices.m_Memory.m_nAllocationCount = 0;
      }
      choices.m_pElements = v16;
      if ( choices.m_Memory.m_nGrowSize >= 0 && v16 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
    }
    pComboBox->SetText(this: pComboBox, a2: "Unknown value");
    return;
  }
  while ( 1 )
  {
    ChoiceValue = CDmeEditorStringChoicesInfo::GetChoiceValue(this: (CDmeEditorStringChoicesInfo *)v4, nIndex: v7);
    if ( _V_stricmp(s1: pValue, s2: ChoiceValue) == 0 )
      break;
    if ( ++v7 >= ChoiceCount )
      goto LABEL_8;
  }
  v17 = pComboBox->__vftable;
  ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: (CDmeEditorChoicesInfo *)v4, nIndex: v7);
  v17->SetText(this: pComboBox, a2: ChoiceString);
}

//------------------------------------------------------------------------------
// Address: 0x0046EF70
// Name: public: CAttributeStringChoicePanel::CAttributeStringChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeStringChoicePanel *__thiscall CAttributeStringChoicePanel::CAttributeStringChoicePanel(
        CAttributeStringChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeStringChoicePanel_vtbl *)&CAttributeStringChoicePanel::`vftable';
  if ( `CAttributeStringChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeStringChoicePanel");
    v4->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeStringChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeStringChoicePanel");
    v5->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeStringChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeStringChoicePanel");
    v6->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046F030
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeStringChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeStringChoicePanel::GetMessageMap(CAttributeStringChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeStringChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeStringChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeStringChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeStringChoicePanel");
  `CAttributeStringChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F060
// Name: public: virtual struct PanelAnimationMap __near * CAttributeStringChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeStringChoicePanel::GetAnimMap(CAttributeStringChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeStringChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046F070
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeStringChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeStringChoicePanel::GetKBMap(CAttributeStringChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeStringChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeStringChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeStringChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeStringChoicePanel");
  `CAttributeStringChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F0A0
// Name: public: virtual bool CDmeEditorStringChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorStringChoicesInfo::IsA(CDmeEditorStringChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorStringChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046F0E0
// Name: public: virtual int CDmeEditorStringChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorStringChoicesInfo::GetInheritanceDepth(
        CDmeEditorStringChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorStringChoicesInfo::m_classType.u.m_Id )
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
// Address: 0x0067C430
// Name: _dynamic_initializer_for__CDmeEditorStringChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorStringChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorStringChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorStringChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681AB0
// Name: _dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorStringChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067C460
// Name: _dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C470
// Name: _dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorStringChoicesInfo_Helper,
           classname: "DmeEditorStringChoicesInfo",
           pFactory: &g_CDmeEditorStringChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067C490
// Name: _dynamic_initializer_for__g_CDmeSourceSkinPanel_DmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeSourceSkinPanel_DmeSourceSkin_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeSourceSkinPanel_DmeSourceSkin_Factory,
             pElementType: "DmeSourceSkin",
             pEditorName: "DmeSourceSkinDefault",
             pEditorDisplayName: "MDL Skin Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CDmeSourceSkinPanel_DmeSourceSkin_Factory.__vftable = (CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>_vtbl *)&CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C4C0
// Name: _dynamic_initializer_for__g_CAssetBuilder_DmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CAssetBuilder_DmeMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CAssetBuilder_DmeMakefile_Factory,
             pElementType: "DmeMakefile",
             pEditorName: "DmeMakeFileDefault",
             pEditorDisplayName: "MakeFile Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CAssetBuilder_DmeMakefile_Factory.__vftable = (CDmePanelFactory<CAssetBuilder,CDmeMakefile>_vtbl *)&CDmePanelFactory<CAssetBuilder,CDmeMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C4F0
// Name: _dynamic_initializer_for__s_AssetTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_AssetTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_AssetTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C500
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory,
             pElementType: "DmeSourceDCCFile",
             pEditorName: "DmeSourceDCCFileDefault",
             pEditorDisplayName: "Maya/XSI Source File Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory.__vftable = (CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>_vtbl *)&CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C530
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDag_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeDag_Factory,
             pElementType: "DmeDag",
             pEditorName: "DmeDagRenderer",
             pEditorDisplayName: "DmeDag Preview Renderer",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeDag_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C560
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceSkin_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeSourceSkin_Factory,
             pElementType: "DmeSourceSkin",
             pEditorName: "DmeSourceSkinPreview",
             pEditorDisplayName: "MDL Skin Previewer",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeSourceSkin_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C590
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceAnimation_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeSourceAnimation_Factory,
             pElementType: "DmeSourceAnimation",
             pEditorName: "DmeSourceAnimationPreview",
             pEditorDisplayName: "MDL Animation Previewer",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeSourceAnimation_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C5C0
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDCCMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeDCCMakefile_Factory,
             pElementType: "DmeDCCMakefile",
             pEditorName: "DmeMakeFileOutputPreview",
             pEditorDisplayName: "DCC MakeFile Output Preview",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeDCCMakefile_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C5F0
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeDag_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeDag_Factory,
             pElementType: "DmeDag",
             pEditorName: "DmeDagPreview2",
             pEditorDisplayName: "DmeDag Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeDag_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeDag>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C620
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceSkin_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeSourceSkin_Factory,
             pElementType: "DmeSourceSkin",
             pEditorName: "DmeSourceSkinPreview2",
             pEditorDisplayName: "MDL Skin Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeSourceSkin_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C650
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceAnimation_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeSourceAnimation_Factory,
             pElementType: "DmeSourceAnimation",
             pEditorName: "DmeSourceAnimationPreview2",
             pEditorDisplayName: "MDL Animation Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeSourceAnimation_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C680
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeDCCMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeDCCMakefile_Factory,
             pElementType: "DmeDCCMakefile",
             pEditorName: "DmeMakeFileOutputPreview2",
             pEditorDisplayName: "DCC MakeFile Output Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeDCCMakefile_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C6B0
// Name: _dynamic_initializer_for__g_CDmeMDLPanel_DmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeMDLPanel_DmeMDLMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeMDLPanel_DmeMDLMakefile_Factory,
             pElementType: "DmeMDLMakefile",
             pEditorName: "DmeMakeFileOutputPreview",
             pEditorDisplayName: "MDL MakeFile Output Preview",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeMDLPanel_DmeMDLMakefile_Factory.__vftable = (CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>_vtbl *)&CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C6E0
// Name: _dynamic_initializer_for__SelectionInfo_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__SelectionInfo_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &SelectionInfo_t::s_Allocator,
    blockSize: 12,
    numElements: 256,
    growMode: 2,
    pszAllocOwner: "SelectionInfo_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__SelectionInfo_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C710
// Name: _dynamic_initializer_for__ifm_attributeslider_sensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_attributeslider_sensitivity__()
{
  ConVar::ConVar(
    this: &ifm_attributeslider_sensitivity,
    pName: "ifm_attributeslider_sensitivity",
    pDefaultValue: "3.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C740
// Name: _dynamic_initializer_for__ifm_attributeslider_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_attributeslider_legacy__()
{
  ConVar::ConVar(
    this: &ifm_attributeslider_legacy,
    pName: "ifm_attributeslider_legacy",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Uses old style slider dragging.");
  return atexit(func: dynamic_atexit_destructor_for__ifm_attributeslider_legacy__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C770
// Name: _dynamic_initializer_for__ifm_threaded_updatecontrolvalues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_threaded_updatecontrolvalues__()
{
  ConVar::ConVar(
    this: &ifm_threaded_updatecontrolvalues,
    pName: "ifm_threaded_updatecontrolvalues",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C7A0
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C7C0
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C7E0
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C800
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C820
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C840
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C860
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C880
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067C8A0
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C910
// Name: _dynamic_initializer_for__s_AssetCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_AssetCache__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_AssetCache__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C920
// Name: _dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__()
{
  CTextureReference::CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq);
  return atexit(func: dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__);
}

//------------------------------------------------------------------------------
// Address: 0x00681AC0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorStringChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00681AD0
// Name: _dynamic_atexit_destructor_for__s_AssetTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_AssetTypes__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_AssetTypes.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x00681AE0
// Name: _dynamic_atexit_destructor_for__SelectionInfo_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__SelectionInfo_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &SelectionInfo_t::s_Allocator);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10491DF0
// Name: public: static char const __near * CAttributeStringChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeStringChoicePanel::GetPanelClassName()
{
  return "CAttributeStringChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10491E00
// Name: public: char const __near * CDmeEditorStringChoicesInfo::GetChoiceValue(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorStringChoicesInfo::GetChoiceValue(CDmeEditorStringChoicesInfo *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t *v6; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 == nullptr || !v2->IsA(this: v2, a2: CDmElement::m_classType) )
    return nullptr;
  if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
  if ( Attribute == nullptr )
    return `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id != -1
         ? (const char *)`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id
         : nullptr;
  v6 = CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
  return *v6 != DMELEMENT_HANDLE_INVALID ? (const char *)*v6 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10491EB0
// Name: private: virtual void CAttributeStringChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeStringChoicePanel::PopulateComboBox(
        CAttributeStringChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CAttributeStringChoicePanel *v2; // esi
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorStringChoicesInfo *v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  char *ChoiceValue; // eax
  vgui::ComboBox_vtbl *v8; // esi
  const char *ChoiceString; // eax
  KeyValues *v10; // eax
  bool v11; // sf
  DmElementHandle_t m_handle; // eax
  CDmElement *v13; // eax
  int v14; // edi
  const char *ChoiceType; // eax
  int v16; // edi
  int i; // esi
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  StringChoice_t *m_pMemory; // eax
  CDmElement *v21; // [esp-10h] [ebp-3Ch]
  CAttributeStringChoicePanel *v22; // [esp-8h] [ebp-34h]
  CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  CAttributeStringChoicePanel *v24; // [esp+20h] [ebp-Ch]
  int c; // [esp+24h] [ebp-8h]
  KeyValues *kv; // [esp+28h] [ebp-4h]

  v2 = this;
  v24 = this;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this: v2);
  v4 = (CDmeEditorStringChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorStringChoicesInfo::m_classType) )
  {
    v5 = 0;
    c = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
    if ( c > 0 )
    {
      do
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          kv = KeyValues::KeyValues(this: v6, setName: "entry");
        else
          kv = nullptr;
        ChoiceValue = (char *)CDmeEditorStringChoicesInfo::GetChoiceValue(this: v4, nIndex: v5);
        KeyValues::SetString(this: kv, keyName: "value", value: ChoiceValue);
        v8 = pComboBox->__vftable;
        ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: v4, nIndex: v5);
        v8->AddItem_2(this: pComboBox, a2: ChoiceString, a3: kv);
        ++v5;
      }
      while ( v5 < c );
      v2 = v24;
    }
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v10 = (KeyValues *)vgui::ElementPropertiesChoices();
      v11 = v2->m_nArrayIndex < 0;
      kv = v10;
      m_handle = v2->m_hObject.m_handle;
      LOBYTE(v24) = !v11;
      v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v14 = *(_DWORD *)kv;
      v22 = v24;
      v21 = v13;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v4);
      if ( (*(unsigned __int8 (__thiscall **)(KeyValues *, const char *, CDmElement *, char *, CAttributeStringChoicePanel *, CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > *))(v14 + 8))(
             a1: kv,
             a2: ChoiceType,
             a3: v21,
             a4: v2->m_szAttributeName,
             a5: v22,
             a6: &choices) != 0 )
      {
        v16 = 0;
        for ( i = choices.m_Size; v16 < i; ++v16 )
        {
          v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v18 != nullptr )
            v19 = KeyValues::KeyValues(this: v18, setName: "entry");
          else
            v19 = nullptr;
          KeyValues::SetString(this: v19, keyName: "value", value: (char *)choices.m_Memory.m_pMemory[v16].m_pValue);
          pComboBox->AddItem_2(this: pComboBox, a2: choices.m_Memory.m_pMemory[v16].m_pChoiceString, a3: v19);
        }
      }
      m_pMemory = choices.m_Memory.m_pMemory;
      choices.m_Size = 0;
      if ( choices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( choices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          choices.m_Memory.m_pMemory = nullptr;
        }
        choices.m_Memory.m_nAllocationCount = 0;
      }
      choices.m_pElements = m_pMemory;
      if ( choices.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10492120
// Name: private: virtual void CAttributeStringChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeStringChoicePanel::SetAttributeFromComboBox(
        CAttributeStringChoicePanel *this@<ecx>,
        int a2@<ebx>,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  DmElementHandle_t v5; // eax
  const char *v6; // esi
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v8; // esi
  char *pNewString; // [esp+14h] [ebp+Ch]

  v5 = *CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this);
  v6 = &var;
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    v6 = (const char *)v5;
  pNewString = KeyValues::GetString(this: pKeyValues, keyName: "value", defaultValue: &var);
  if ( v6 != pNewString )
  {
    m_pNotify = this->m_pNotify;
    v8 = nullptr;
    ((void (__thiscall *)(IDataModel *, const char *, const char *, _DWORD, int))g_pDataModel->StartUndo)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v8 = m_pNotify;
    ((void (__thiscall *)(IDataModel *, const char *, int))g_pDataModel->PushNotificationScope)(
      a1: g_pDataModel,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue(this, pValue: pNewString);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v8 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10492200
// Name: private: virtual void CAttributeStringChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeStringChoicePanel::SetComboBoxFromAttribute(
        CAttributeStringChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorStringChoicesInfo *v4; // esi
  const char *v5; // eax
  int ChoiceCount; // ebx
  int v7; // edi
  const char *ChoiceValue; // eax
  IElementPropertiesChoices *v9; // ebx
  DmElementHandle_t m_handle; // eax
  CDmElement *v11; // eax
  IElementPropertiesChoices_vtbl *v12; // edi
  const char *ChoiceType; // eax
  int v14; // esi
  int m_Size; // edi
  StringChoice_t *v16; // eax
  vgui::ComboBox_vtbl *v17; // ebx
  const char *ChoiceString; // eax
  StringChoice_t *m_pMemory; // eax
  CDmElement *v20; // [esp-10h] [ebp-3Ch]
  char *m_szAttributeName; // [esp-Ch] [ebp-38h]
  BOOL v22; // [esp-8h] [ebp-34h]
  CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  BOOL v24; // [esp+20h] [ebp-Ch]
  CAttributeStringChoicePanel *v25; // [esp+24h] [ebp-8h]
  const char *pValue; // [esp+28h] [ebp-4h]

  v25 = this;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeEditorStringChoicesInfo *)EditorInfo;
  if ( EditorInfo == nullptr || !EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorStringChoicesInfo::m_classType) )
    return;
  v5 = (const char *)*CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this);
  pValue = &var;
  if ( v5 != (const char *)-1 )
    pValue = v5;
  ChoiceCount = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
  v7 = 0;
  if ( ChoiceCount <= 0 )
  {
LABEL_8:
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v9 = vgui::ElementPropertiesChoices();
      m_handle = v25->m_hObject.m_handle;
      LOBYTE(v24) = v25->m_nArrayIndex >= 0;
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v12 = v9->__vftable;
      v22 = v24;
      m_szAttributeName = v25->m_szAttributeName;
      v20 = v11;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v4);
      if ( v12->GetStringChoiceList(this: v9, a2: ChoiceType, a3: v20, a4: m_szAttributeName, a5: v22, a6: &choices) )
      {
        v14 = 0;
        m_Size = choices.m_Size;
        if ( choices.m_Size > 0 )
        {
          while ( _V_stricmp(s1: pValue, s2: choices.m_Memory.m_pMemory[v14].m_pValue) != 0 )
          {
            if ( ++v14 >= m_Size )
              goto LABEL_13;
          }
          pComboBox->SetText(this: pComboBox, a2: choices.m_Memory.m_pMemory[v14].m_pChoiceString);
          m_pMemory = choices.m_Memory.m_pMemory;
          choices.m_Size = 0;
          if ( choices.m_Memory.m_nGrowSize >= 0 )
          {
            if ( choices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              choices.m_Memory.m_pMemory = nullptr;
            }
            choices.m_Memory.m_nAllocationCount = 0;
          }
          choices.m_pElements = m_pMemory;
          if ( choices.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          return;
        }
      }
LABEL_13:
      v16 = choices.m_Memory.m_pMemory;
      choices.m_Size = 0;
      if ( choices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( choices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
          v16 = nullptr;
          choices.m_Memory.m_pMemory = nullptr;
        }
        choices.m_Memory.m_nAllocationCount = 0;
      }
      choices.m_pElements = v16;
      if ( choices.m_Memory.m_nGrowSize >= 0 && v16 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
    }
    pComboBox->SetText(this: pComboBox, a2: "Unknown value");
    return;
  }
  while ( 1 )
  {
    ChoiceValue = CDmeEditorStringChoicesInfo::GetChoiceValue(this: v4, nIndex: v7);
    if ( _V_stricmp(s1: pValue, s2: ChoiceValue) == 0 )
      break;
    if ( ++v7 >= ChoiceCount )
      goto LABEL_8;
  }
  v17 = pComboBox->__vftable;
  ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: v4, nIndex: v7);
  v17->SetText(this: pComboBox, a2: ChoiceString);
}

//------------------------------------------------------------------------------
// Address: 0x10492470
// Name: public: CAttributeStringChoicePanel::CAttributeStringChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeStringChoicePanel *__thiscall CAttributeStringChoicePanel::CAttributeStringChoicePanel(
        CAttributeStringChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeStringChoicePanel_vtbl *)&CAttributeStringChoicePanel::`vftable';
  if ( `CAttributeStringChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeStringChoicePanel");
    v4->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeStringChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeStringChoicePanel");
    v5->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeStringChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeStringChoicePanel");
    v6->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10492530
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeStringChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeStringChoicePanel::GetMessageMap(CAttributeStringChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeStringChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeStringChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeStringChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeStringChoicePanel");
  `CAttributeStringChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10492560
// Name: public: virtual struct PanelAnimationMap __near * CAttributeStringChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeStringChoicePanel::GetAnimMap(CAttributeStringChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeStringChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10492570
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeStringChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeStringChoicePanel::GetKBMap(CAttributeStringChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeStringChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeStringChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeStringChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeStringChoicePanel");
  `CAttributeStringChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104925A0
// Name: public: virtual bool CDmeEditorStringChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorStringChoicesInfo::IsA(CDmeEditorStringChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorStringChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104925E0
// Name: public: virtual int CDmeEditorStringChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorStringChoicesInfo::GetInheritanceDepth(
        CDmeEditorStringChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorStringChoicesInfo::m_classType.u.m_Id )
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
// Address: 0x105C66C0
// Name: _dynamic_initializer_for__CDmeEditorStringChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorStringChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorStringChoicesInfo::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorStringChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC9A0
// Name: _dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorStringChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C66F0
// Name: _dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6700
// Name: _dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorStringChoicesInfo_Helper,
           classname: "DmeEditorStringChoicesInfo",
           pFactory: &g_CDmeEditorStringChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6720
// Name: _dynamic_initializer_for__ifm_attributeslider_sensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_attributeslider_sensitivity__()
{
  ConVar::ConVar(
    this: &ifm_attributeslider_sensitivity,
    pName: "ifm_attributeslider_sensitivity",
    pDefaultValue: "3.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6750
// Name: _dynamic_initializer_for__ifm_attributeslider_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_attributeslider_legacy__()
{
  ConVar::ConVar(
    this: &ifm_attributeslider_legacy,
    pName: "ifm_attributeslider_legacy",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Uses old style slider dragging.");
  return atexit(func: dynamic_atexit_destructor_for__ifm_attributeslider_legacy__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6780
// Name: _dynamic_initializer_for__ifm_threaded_updatecontrolvalues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_threaded_updatecontrolvalues__()
{
  ConVar::ConVar(
    this: &ifm_threaded_updatecontrolvalues,
    pName: "ifm_threaded_updatecontrolvalues",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__);
}

//------------------------------------------------------------------------------
// Address: 0x105C67B0
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C67D0
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C67F0
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C6810
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C6830
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C6850
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C6870
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C6890
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C68B0
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CPreviewImagePropertiesCache::PreviewImageLessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6920
// Name: _dynamic_initializer_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMXAllocator__()
{
  CMemoryStack::CMemoryStack(this: &s_DMXAllocator);
  return atexit(func: dynamic_atexit_destructor_for__s_DMXAllocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC9B0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeEditorStringChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CC9C0
// Name: _dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__()
{
  ConVar::~ConVar(this: &ifm_attributeslider_sensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x105CC9D0
// Name: _dynamic_atexit_destructor_for__ifm_attributeslider_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_attributeslider_legacy__()
{
  ConVar::~ConVar(this: &ifm_attributeslider_legacy);
}

//------------------------------------------------------------------------------
// Address: 0x105CC9E0
// Name: _dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__()
{
  ConVar::~ConVar(this: &ifm_threaded_updatecontrolvalues);
}

//------------------------------------------------------------------------------
// Address: 0x105CCA20
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

//------------------------------------------------------------------------------
// Address: 0x105CCA30
// Name: _dynamic_atexit_destructor_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMXAllocator__()
{
  CMemoryStack::~CMemoryStack(this: &s_DMXAllocator);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00498570
// Name: public: static char const __near * CAttributeStringChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeStringChoicePanel::GetPanelClassName()
{
  return "CAttributeStringChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00498580
// Name: public: char const __near * CDmeEditorStringChoicesInfo::GetChoiceValue(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorStringChoicesInfo::GetChoiceValue(CDmeEditorStringChoicesInfo *this, int nIndex)
{
  int v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<CUtlSymbolLarge> *v6; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = (CDmElement *)v2;
  if ( v2 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmElement::m_classType.u) == 0 )
  {
    return nullptr;
  }
  if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
  if ( Attribute == nullptr )
    return `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id != -1
         ? (const char *)`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id
         : nullptr;
  v6 = CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
  return v6->m_Storage.u.m_Id != -1 ? (const char *)v6->m_Storage.u.m_Id : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00498630
// Name: private: virtual void CAttributeStringChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeStringChoicePanel::PopulateComboBox(
        CAttributeStringChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CAttributeStringChoicePanel *v2; // esi
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  const char *ChoiceValue; // eax
  vgui::ComboBox_vtbl *v8; // esi
  const char *ChoiceString; // eax
  KeyValues *v10; // eax
  bool v11; // sf
  DmElementHandle_t m_handle; // eax
  int v13; // eax
  int v14; // edi
  const char *ChoiceType; // eax
  int v16; // edi
  int i; // esi
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  StringChoice_t *m_pMemory; // eax
  int v21; // [esp-10h] [ebp-3Ch]
  CAttributeStringChoicePanel *v22; // [esp-8h] [ebp-34h]
  CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  CAttributeStringChoicePanel *v24; // [esp+20h] [ebp-Ch]
  int c; // [esp+24h] [ebp-8h]
  KeyValues *kv; // [esp+28h] [ebp-4h]

  v2 = this;
  v24 = this;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this: v2);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorStringChoicesInfo::m_classType) )
  {
    v5 = 0;
    c = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
    if ( c > 0 )
    {
      do
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          kv = KeyValues::KeyValues(this: v6, setName: "entry");
        else
          kv = nullptr;
        ChoiceValue = CDmeEditorStringChoicesInfo::GetChoiceValue(this: (CDmeEditorStringChoicesInfo *)v4, nIndex: v5);
        KeyValues::SetString(this: kv, keyName: "value", value: ChoiceValue);
        v8 = pComboBox->__vftable;
        ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: (CDmeEditorChoicesInfo *)v4, nIndex: v5);
        v8->AddItem_2(this: pComboBox, a2: ChoiceString, a3: kv);
        ++v5;
      }
      while ( v5 < c );
      v2 = v24;
    }
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: (CDmeEditorChoicesInfo *)v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v10 = (KeyValues *)vgui::ElementPropertiesChoices();
      v11 = v2->m_nArrayIndex < 0;
      kv = v10;
      m_handle = v2->m_hObject.m_handle;
      LOBYTE(v24) = !v11;
      v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: m_handle);
      v14 = *(_DWORD *)kv;
      v22 = v24;
      v21 = v13;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: (CDmeEditorChoicesInfo *)v4);
      if ( (*(unsigned __int8 (__thiscall **)(KeyValues *, const char *, int, char *, CAttributeStringChoicePanel *, CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > *))(v14 + 8))(
             a1: kv,
             a2: ChoiceType,
             a3: v21,
             a4: v2->m_szAttributeName,
             a5: v22,
             a6: &choices) != 0 )
      {
        v16 = 0;
        for ( i = choices.m_Size; v16 < i; ++v16 )
        {
          v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v18 != nullptr )
            v19 = KeyValues::KeyValues(this: v18, setName: "entry");
          else
            v19 = nullptr;
          KeyValues::SetString(this: v19, keyName: "value", value: choices.m_Memory.m_pMemory[v16].m_pValue);
          pComboBox->AddItem_2(this: pComboBox, a2: choices.m_Memory.m_pMemory[v16].m_pChoiceString, a3: v19);
        }
      }
      m_pMemory = choices.m_Memory.m_pMemory;
      choices.m_Size = 0;
      if ( choices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( choices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          choices.m_Memory.m_pMemory = nullptr;
        }
        choices.m_Memory.m_nAllocationCount = 0;
      }
      choices.m_pElements = m_pMemory;
      if ( choices.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004988A0
// Name: private: virtual void CAttributeStringChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeStringChoicePanel::SetAttributeFromComboBox(
        CAttributeStringChoicePanel *this@<ecx>,
        int a2@<ebx>,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  CUtlSymbolLarge::<unnamed_type_u> v5; // eax
  const char *m_Id; // esi
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v8; // esi
  const char *pNewString; // [esp+14h] [ebp+Ch]

  v5.m_Id = (int)CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this)->m_Storage.u;
  m_Id = defaultValue;
  if ( v5.m_Id != -1 )
    m_Id = (const char *)v5.m_Id;
  pNewString = KeyValues::GetString(this: pKeyValues, keyName: "value", defaultValue: defaultValue);
  if ( m_Id != pNewString )
  {
    m_pNotify = this->m_pNotify;
    v8 = nullptr;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0,
      a5: a2);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v8 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4);
    CBaseAttributePanel::SetAttributeValue(this, pValue: pNewString);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    if ( v8 != nullptr )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498980
// Name: private: virtual void CAttributeStringChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeStringChoicePanel::SetComboBoxFromAttribute(
        CAttributeStringChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // esi
  const char *m_Id; // eax
  int ChoiceCount; // ebx
  int v7; // edi
  const char *ChoiceValue; // eax
  IElementPropertiesChoices *v9; // ebx
  DmElementHandle_t m_handle; // eax
  int v11; // eax
  IElementPropertiesChoices_vtbl *v12; // edi
  const char *ChoiceType; // eax
  int v14; // esi
  int m_Size; // edi
  StringChoice_t *v16; // eax
  vgui::ComboBox_vtbl *v17; // ebx
  const char *ChoiceString; // eax
  StringChoice_t *m_pMemory; // eax
  int v20; // [esp-10h] [ebp-3Ch]
  char *m_szAttributeName; // [esp-Ch] [ebp-38h]
  BOOL v22; // [esp-8h] [ebp-34h]
  CUtlVector<StringChoice_t,CUtlMemory<StringChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  BOOL v24; // [esp+20h] [ebp-Ch]
  CAttributeStringChoicePanel *v25; // [esp+24h] [ebp-8h]
  const char *pValue; // [esp+28h] [ebp-4h]

  v25 = this;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo == nullptr || !EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorStringChoicesInfo::m_classType) )
    return;
  m_Id = (const char *)CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this)->m_Storage.u.m_Id;
  pValue = defaultValue;
  if ( m_Id != (const char *)-1 )
    pValue = m_Id;
  ChoiceCount = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
  v7 = 0;
  if ( ChoiceCount <= 0 )
  {
LABEL_8:
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: (CDmeEditorChoicesInfo *)v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v9 = vgui::ElementPropertiesChoices();
      m_handle = v25->m_hObject.m_handle;
      LOBYTE(v24) = v25->m_nArrayIndex >= 0;
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: m_handle);
      v12 = v9->__vftable;
      v22 = v24;
      m_szAttributeName = v25->m_szAttributeName;
      v20 = v11;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: (CDmeEditorChoicesInfo *)v4);
      if ( v12->GetStringChoiceList(
             this: v9,
             a2: ChoiceType,
             a3: (CDmElement *)v20,
             a4: m_szAttributeName,
             a5: v22,
             a6: &choices) )
      {
        v14 = 0;
        m_Size = choices.m_Size;
        if ( choices.m_Size > 0 )
        {
          while ( _V_stricmp(s1: pValue, s2: choices.m_Memory.m_pMemory[v14].m_pValue) != 0 )
          {
            if ( ++v14 >= m_Size )
              goto LABEL_13;
          }
          pComboBox->SetText(this: pComboBox, a2: choices.m_Memory.m_pMemory[v14].m_pChoiceString);
          m_pMemory = choices.m_Memory.m_pMemory;
          choices.m_Size = 0;
          if ( choices.m_Memory.m_nGrowSize >= 0 )
          {
            if ( choices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              choices.m_Memory.m_pMemory = nullptr;
            }
            choices.m_Memory.m_nAllocationCount = 0;
          }
          choices.m_pElements = m_pMemory;
          if ( choices.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          return;
        }
      }
LABEL_13:
      v16 = choices.m_Memory.m_pMemory;
      choices.m_Size = 0;
      if ( choices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( choices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
          v16 = nullptr;
          choices.m_Memory.m_pMemory = nullptr;
        }
        choices.m_Memory.m_nAllocationCount = 0;
      }
      choices.m_pElements = v16;
      if ( choices.m_Memory.m_nGrowSize >= 0 && v16 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
    }
    pComboBox->SetText(this: pComboBox, a2: "Unknown value");
    return;
  }
  while ( 1 )
  {
    ChoiceValue = CDmeEditorStringChoicesInfo::GetChoiceValue(this: (CDmeEditorStringChoicesInfo *)v4, nIndex: v7);
    if ( _V_stricmp(s1: pValue, s2: ChoiceValue) == 0 )
      break;
    if ( ++v7 >= ChoiceCount )
      goto LABEL_8;
  }
  v17 = pComboBox->__vftable;
  ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: (CDmeEditorChoicesInfo *)v4, nIndex: v7);
  v17->SetText(this: pComboBox, a2: ChoiceString);
}

//------------------------------------------------------------------------------
// Address: 0x00498BF0
// Name: public: CAttributeStringChoicePanel::CAttributeStringChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeStringChoicePanel *__thiscall CAttributeStringChoicePanel::CAttributeStringChoicePanel(
        CAttributeStringChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeStringChoicePanel_vtbl *)&CAttributeStringChoicePanel::`vftable';
  if ( `CAttributeStringChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeStringChoicePanel");
    v4->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeStringChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeStringChoicePanel");
    v5->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeStringChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeStringChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeStringChoicePanel");
    v6->pfnClassName = CAttributeStringChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00498CB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeStringChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeStringChoicePanel::GetMessageMap(CAttributeStringChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeStringChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeStringChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeStringChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeStringChoicePanel");
  `CAttributeStringChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00498CE0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeStringChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeStringChoicePanel::GetAnimMap(CAttributeStringChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeStringChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00498CF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeStringChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeStringChoicePanel::GetKBMap(CAttributeStringChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeStringChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeStringChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeStringChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeStringChoicePanel");
  `CAttributeStringChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00498D20
// Name: public: virtual bool CDmeEditorStringChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorStringChoicesInfo::IsA(CDmeEditorStringChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorStringChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00498D60
// Name: public: virtual int CDmeEditorStringChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorStringChoicesInfo::GetInheritanceDepth(
        CDmeEditorStringChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorStringChoicesInfo::m_classType.u.m_Id )
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
// Address: 0x006ABE40
// Name: _dynamic_initializer_for__CDmeEditorStringChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorStringChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorStringChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorStringChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B38A0
// Name: _dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorStringChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorStringChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ABE70
// Name: _dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ABE80
// Name: _dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorStringChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorStringChoicesInfo_Helper,
           classname: "DmeEditorStringChoicesInfo",
           pFactory: &g_CDmeEditorStringChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ABEA0
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABEC0
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABEE0
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABF00
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABF20
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABF40
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABF60
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABF80
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABFA0
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x006B38B0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorStringChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorStringChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B38F0
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace sceneviewer
