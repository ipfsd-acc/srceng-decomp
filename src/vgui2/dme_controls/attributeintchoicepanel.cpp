// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeintchoicepanel.cpp
// Functions: 18
// ============================================================

#include "vgui2\dme_controls\attributeintchoicepanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046E060
// Name: public: static char const __near * CAttributeIntChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeIntChoicePanel::GetPanelClassName()
{
  return "CAttributeIntChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046E070
// Name: public: int const __near & CDmElement::GetValue<int>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmElement::GetValue<int>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute);
  else
    return &`CDmElement::GetValue<int>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0046E0C0
// Name: public: int CDmeEditorIntChoicesInfo::GetChoiceValue(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorIntChoicesInfo::GetChoiceValue(CDmeEditorIntChoicesInfo *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 == nullptr || !v2->IsA(this: v2, a2: CDmElement::m_classType) )
    return 0;
  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute)->m_Storage;
  else
    return `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0046E160
// Name: private: virtual void CAttributeIntChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::PopulateComboBox(CAttributeIntChoicePanel *this, vgui::ComboBox *pComboBox)
{
  CAttributeIntChoicePanel *v2; // esi
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  int ChoiceValue; // eax
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
  IntChoice_t *m_pMemory; // eax
  CDmElement *v21; // [esp-10h] [ebp-3Ch]
  CAttributeIntChoicePanel *v22; // [esp-8h] [ebp-34h]
  CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  CAttributeIntChoicePanel *v24; // [esp+20h] [ebp-Ch]
  int c; // [esp+24h] [ebp-8h]
  KeyValues *kv; // [esp+28h] [ebp-4h]

  v2 = this;
  v24 = this;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this: v2);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorIntChoicesInfo::m_classType) )
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
        ChoiceValue = CDmeEditorIntChoicesInfo::GetChoiceValue(this: (CDmeEditorIntChoicesInfo *)v4, nIndex: v5);
        KeyValues::SetInt(this: kv, keyName: "value", value: ChoiceValue);
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
      if ( (*(unsigned __int8 (__thiscall **)(KeyValues *, const char *, CDmElement *, char *, CAttributeIntChoicePanel *, CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > *))(v14 + 4))(
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
          KeyValues::SetInt(this: v19, keyName: "value", value: choices.m_Memory.m_pMemory[v16].m_nValue);
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
// Address: 0x0046E330
// Name: public: int const __near & CBaseAttributePanel::GetAttributeValue<int>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CBaseAttributePanel::GetAttributeValue<int>(CBaseAttributePanel *this)
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
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<int> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<int>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<int>'::`5'::temp = 0;
    return (CDmaVar<int> *)&`CBaseAttributePanel::GetAttributeValue<int>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E3B0
// Name: private: virtual void CAttributeIntChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::SetAttributeFromComboBox(
        CAttributeIntChoicePanel *this,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  int m_Storage; // edi
  int nValue; // [esp+8h] [ebp-4h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  nValue = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0);
  if ( m_Storage != nValue )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &nValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E450
// Name: private: virtual void CAttributeIntChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::SetComboBoxFromAttribute(
        CAttributeIntChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // esi
  int v5; // edi
  IElementPropertiesChoices *v6; // eax
  bool v7; // sf
  DmElementHandle_t m_handle; // eax
  CDmElement *v9; // eax
  int v10; // edi
  const char *ChoiceType; // eax
  char v12; // al
  IntChoice_t *m_pMemory; // edx
  int v14; // eax
  vgui::ComboBox_vtbl *v15; // ebx
  const char *ChoiceString; // eax
  IntChoice_t *v17; // eax
  CDmElement *v18; // [esp-10h] [ebp-3Ch]
  int v19; // [esp-8h] [ebp-34h]
  CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  int v21; // [esp+20h] [ebp-Ch]
  int nValue; // [esp+24h] [ebp-8h]
  int c; // [esp+28h] [ebp-4h]

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo == nullptr || !EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorIntChoicesInfo::m_classType) )
    return;
  nValue = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  v5 = 0;
  c = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
  if ( c <= 0 )
  {
LABEL_6:
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: (CDmeEditorChoicesInfo *)v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v6 = vgui::ElementPropertiesChoices();
      v7 = this->m_nArrayIndex < 0;
      c = (int)v6;
      m_handle = this->m_hObject.m_handle;
      LOBYTE(v21) = !v7;
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v10 = *(_DWORD *)c;
      v19 = v21;
      v18 = v9;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: (CDmeEditorChoicesInfo *)v4);
      v12 = (*(int (__thiscall **)(int, const char *, CDmElement *, char *, int, CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > *))(v10 + 4))(
              a1: c,
              a2: ChoiceType,
              a3: v18,
              a4: this->m_szAttributeName,
              a5: v19,
              a6: &choices);
      m_pMemory = choices.m_Memory.m_pMemory;
      if ( v12 != 0 )
      {
        v14 = 0;
        if ( choices.m_Size > 0 )
        {
          while ( nValue != choices.m_Memory.m_pMemory[v14].m_nValue )
          {
            if ( ++v14 >= choices.m_Size )
              goto LABEL_20;
          }
          pComboBox->SetText(this: pComboBox, a2: choices.m_Memory.m_pMemory[v14].m_pChoiceString);
          v17 = choices.m_Memory.m_pMemory;
          choices.m_Size = 0;
          if ( choices.m_Memory.m_nGrowSize >= 0 )
          {
            if ( choices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
              v17 = nullptr;
              choices.m_Memory.m_pMemory = nullptr;
            }
            choices.m_Memory.m_nAllocationCount = 0;
          }
          choices.m_pElements = v17;
          if ( choices.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
          return;
        }
      }
LABEL_20:
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
    pComboBox->SetText(this: pComboBox, a2: "Unknown value");
    return;
  }
  while ( nValue != CDmeEditorIntChoicesInfo::GetChoiceValue(this: (CDmeEditorIntChoicesInfo *)v4, nIndex: v5) )
  {
    if ( ++v5 >= c )
      goto LABEL_6;
  }
  v15 = pComboBox->__vftable;
  ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: (CDmeEditorChoicesInfo *)v4, nIndex: v5);
  v15->SetText(this: pComboBox, a2: ChoiceString);
}

//------------------------------------------------------------------------------
// Address: 0x0046E690
// Name: public: CAttributeIntChoicePanel::CAttributeIntChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeIntChoicePanel *__thiscall CAttributeIntChoicePanel::CAttributeIntChoicePanel(
        CAttributeIntChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeIntChoicePanel_vtbl *)&CAttributeIntChoicePanel::`vftable';
  if ( `CAttributeIntChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeIntChoicePanel");
    v4->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeIntChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeIntChoicePanel");
    v5->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeIntChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeIntChoicePanel");
    v6->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046E750
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeIntChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeIntChoicePanel::GetMessageMap(CAttributeIntChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeIntChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeIntChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeIntChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeIntChoicePanel");
  `CAttributeIntChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046E780
// Name: public: virtual struct PanelAnimationMap __near * CAttributeIntChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeIntChoicePanel::GetAnimMap(CAttributeIntChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeIntChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046E790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeIntChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeIntChoicePanel::GetKBMap(CAttributeIntChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeIntChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeIntChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeIntChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeIntChoicePanel");
  `CAttributeIntChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046E7C0
// Name: public: virtual bool CDmeEditorIntChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorIntChoicesInfo::IsA(CDmeEditorIntChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorIntChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046E800
// Name: public: virtual int CDmeEditorIntChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorIntChoicesInfo::GetInheritanceDepth(
        CDmeEditorIntChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorIntChoicesInfo::m_classType.u.m_Id )
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
// Address: 0x0067C3D0
// Name: _dynamic_initializer_for__CDmeEditorIntChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorIntChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorIntChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorIntChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681A90
// Name: _dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorIntChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067C400
// Name: _dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C410
// Name: _dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorIntChoicesInfo_Helper,
           classname: "DmeEditorIntChoicesInfo",
           pFactory: &g_CDmeEditorIntChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681AA0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorIntChoicesInfo_Factory.m_CallBackList);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10491520
// Name: public: static char const __near * CAttributeIntChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeIntChoicePanel::GetPanelClassName()
{
  return "CAttributeIntChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10491530
// Name: public: int const __near & CDmElement::GetValue<int>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmElement::GetValue<int>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute);
  else
    return &`CDmElement::GetValue<int>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10491580
// Name: public: int CDmeEditorIntChoicesInfo::GetChoiceValue(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorIntChoicesInfo::GetChoiceValue(CDmeEditorIntChoicesInfo *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 == nullptr || !v2->IsA(this: v2, a2: CDmElement::m_classType) )
    return 0;
  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute)->m_Storage;
  else
    return `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x10491620
// Name: private: virtual void CAttributeIntChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::PopulateComboBox(CAttributeIntChoicePanel *this, vgui::ComboBox *pComboBox)
{
  CAttributeIntChoicePanel *v2; // esi
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorIntChoicesInfo *v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  int ChoiceValue; // eax
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
  IntChoice_t *m_pMemory; // eax
  CDmElement *v21; // [esp-10h] [ebp-3Ch]
  CAttributeIntChoicePanel *v22; // [esp-8h] [ebp-34h]
  CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  CAttributeIntChoicePanel *v24; // [esp+20h] [ebp-Ch]
  int c; // [esp+24h] [ebp-8h]
  KeyValues *kv; // [esp+28h] [ebp-4h]

  v2 = this;
  v24 = this;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this: v2);
  v4 = (CDmeEditorIntChoicesInfo *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorIntChoicesInfo::m_classType) )
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
        ChoiceValue = CDmeEditorIntChoicesInfo::GetChoiceValue(this: v4, nIndex: v5);
        KeyValues::SetInt(this: kv, keyName: "value", value: ChoiceValue);
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
      if ( (*(unsigned __int8 (__thiscall **)(KeyValues *, const char *, CDmElement *, char *, CAttributeIntChoicePanel *, CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > *))(v14 + 4))(
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
          KeyValues::SetInt(this: v19, keyName: "value", value: choices.m_Memory.m_pMemory[v16].m_nValue);
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
// Address: 0x104917F0
// Name: public: int const __near & CBaseAttributePanel::GetAttributeValue<int>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CBaseAttributePanel::GetAttributeValue<int>(CBaseAttributePanel *this)
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
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<int> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<int>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<int>'::`5'::temp = 0;
    return (CDmaVar<int> *)&`CBaseAttributePanel::GetAttributeValue<int>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10491870
// Name: private: virtual void CAttributeIntChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::SetAttributeFromComboBox(
        CAttributeIntChoicePanel *this,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  int m_Storage; // edi
  int nValue; // [esp+8h] [ebp-4h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  nValue = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0);
  if ( m_Storage != nValue )
  {
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &nValue);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10491910
// Name: private: virtual void CAttributeIntChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::SetComboBoxFromAttribute(
        CAttributeIntChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeEditorIntChoicesInfo *v4; // esi
  int v5; // edi
  IElementPropertiesChoices *v6; // eax
  bool v7; // sf
  DmElementHandle_t m_handle; // eax
  CDmElement *v9; // eax
  int v10; // edi
  const char *ChoiceType; // eax
  char v12; // al
  IntChoice_t *m_pMemory; // edx
  int v14; // eax
  vgui::ComboBox_vtbl *v15; // ebx
  const char *ChoiceString; // eax
  IntChoice_t *v17; // eax
  CDmElement *v18; // [esp-10h] [ebp-3Ch]
  int v19; // [esp-8h] [ebp-34h]
  CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  int v21; // [esp+20h] [ebp-Ch]
  int nValue; // [esp+24h] [ebp-8h]
  int c; // [esp+28h] [ebp-4h]

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeEditorIntChoicesInfo *)EditorInfo;
  if ( EditorInfo == nullptr || !EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorIntChoicesInfo::m_classType) )
    return;
  nValue = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  v5 = 0;
  c = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
  if ( c <= 0 )
  {
LABEL_6:
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v6 = vgui::ElementPropertiesChoices();
      v7 = this->m_nArrayIndex < 0;
      c = (int)v6;
      m_handle = this->m_hObject.m_handle;
      LOBYTE(v21) = !v7;
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      v10 = *(_DWORD *)c;
      v19 = v21;
      v18 = v9;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v4);
      v12 = (*(int (__thiscall **)(int, const char *, CDmElement *, char *, int, CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > *))(v10 + 4))(
              a1: c,
              a2: ChoiceType,
              a3: v18,
              a4: this->m_szAttributeName,
              a5: v19,
              a6: &choices);
      m_pMemory = choices.m_Memory.m_pMemory;
      if ( v12 != 0 )
      {
        v14 = 0;
        if ( choices.m_Size > 0 )
        {
          while ( nValue != choices.m_Memory.m_pMemory[v14].m_nValue )
          {
            if ( ++v14 >= choices.m_Size )
              goto LABEL_20;
          }
          pComboBox->SetText(this: pComboBox, a2: choices.m_Memory.m_pMemory[v14].m_pChoiceString);
          v17 = choices.m_Memory.m_pMemory;
          choices.m_Size = 0;
          if ( choices.m_Memory.m_nGrowSize >= 0 )
          {
            if ( choices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
              v17 = nullptr;
              choices.m_Memory.m_pMemory = nullptr;
            }
            choices.m_Memory.m_nAllocationCount = 0;
          }
          choices.m_pElements = v17;
          if ( choices.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
          return;
        }
      }
LABEL_20:
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
    pComboBox->SetText(this: pComboBox, a2: "Unknown value");
    return;
  }
  while ( nValue != CDmeEditorIntChoicesInfo::GetChoiceValue(this: v4, nIndex: v5) )
  {
    if ( ++v5 >= c )
      goto LABEL_6;
  }
  v15 = pComboBox->__vftable;
  ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: v4, nIndex: v5);
  v15->SetText(this: pComboBox, a2: ChoiceString);
}

//------------------------------------------------------------------------------
// Address: 0x10491B50
// Name: public: CAttributeIntChoicePanel::CAttributeIntChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeIntChoicePanel *__thiscall CAttributeIntChoicePanel::CAttributeIntChoicePanel(
        CAttributeIntChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeIntChoicePanel_vtbl *)&CAttributeIntChoicePanel::`vftable';
  if ( `CAttributeIntChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeIntChoicePanel");
    v4->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeIntChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeIntChoicePanel");
    v5->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeIntChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeIntChoicePanel");
    v6->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10491C10
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeIntChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeIntChoicePanel::GetMessageMap(CAttributeIntChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeIntChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeIntChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeIntChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeIntChoicePanel");
  `CAttributeIntChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10491C40
// Name: public: virtual struct PanelAnimationMap __near * CAttributeIntChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeIntChoicePanel::GetAnimMap(CAttributeIntChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeIntChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10491C50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeIntChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeIntChoicePanel::GetKBMap(CAttributeIntChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeIntChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeIntChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeIntChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeIntChoicePanel");
  `CAttributeIntChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10491C80
// Name: public: virtual bool CDmeEditorIntChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorIntChoicesInfo::IsA(CDmeEditorIntChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorIntChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10491CC0
// Name: public: virtual int CDmeEditorIntChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorIntChoicesInfo::GetInheritanceDepth(
        CDmeEditorIntChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorIntChoicesInfo::m_classType.u.m_Id )
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
// Address: 0x105C6660
// Name: _dynamic_initializer_for__CDmeEditorIntChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorIntChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorIntChoicesInfo::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorIntChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC980
// Name: _dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorIntChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C6690
// Name: _dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C66A0
// Name: _dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorIntChoicesInfo_Helper,
           classname: "DmeEditorIntChoicesInfo",
           pFactory: &g_CDmeEditorIntChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CC990
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeEditorIntChoicesInfo_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00497CE0
// Name: public: static char const __near * CAttributeIntChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeIntChoicePanel::GetPanelClassName()
{
  return "CAttributeIntChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00497CF0
// Name: public: int const __near & CDmElement::GetValue<int>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmElement::GetValue<int>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute);
  else
    return &`CDmElement::GetValue<int>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00497D40
// Name: public: int CDmeEditorIntChoicesInfo::GetChoiceValue(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorIntChoicesInfo::GetChoiceValue(CDmeEditorIntChoicesInfo *this, int nIndex)
{
  int v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = (CDmElement *)v2;
  if ( v2 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmElement::m_classType.u) == 0 )
  {
    return 0;
  }
  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute)->m_Storage;
  else
    return `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00497DE0
// Name: private: virtual void CAttributeIntChoicePanel::PopulateComboBox(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::PopulateComboBox(CAttributeIntChoicePanel *this, vgui::ComboBox *pComboBox)
{
  CAttributeIntChoicePanel *v2; // esi
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  int ChoiceValue; // eax
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
  IntChoice_t *m_pMemory; // eax
  int v21; // [esp-10h] [ebp-3Ch]
  CAttributeIntChoicePanel *v22; // [esp-8h] [ebp-34h]
  CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  CAttributeIntChoicePanel *v24; // [esp+20h] [ebp-Ch]
  int c; // [esp+24h] [ebp-8h]
  KeyValues *kv; // [esp+28h] [ebp-4h]

  v2 = this;
  v24 = this;
  vgui::ComboBox::RemoveAll(this: pComboBox);
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this: v2);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorIntChoicesInfo::m_classType) )
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
        ChoiceValue = CDmeEditorIntChoicesInfo::GetChoiceValue(this: (CDmeEditorIntChoicesInfo *)v4, nIndex: v5);
        KeyValues::SetInt(this: kv, keyName: "value", value: ChoiceValue);
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
      if ( (*(unsigned __int8 (__thiscall **)(KeyValues *, const char *, int, char *, CAttributeIntChoicePanel *, CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > *))(v14 + 4))(
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
          KeyValues::SetInt(this: v19, keyName: "value", value: choices.m_Memory.m_pMemory[v16].m_nValue);
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
// Address: 0x00497FB0
// Name: public: int const __near & CBaseAttributePanel::GetAttributeValue<int>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CBaseAttributePanel::GetAttributeValue<int>(CBaseAttributePanel *this)
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
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<int> *)&v6.m_pStorage->m_Memory.m_pMemory[m_nArrayIndex];
    }
    else
    {
      return CDmElement::GetValue<int>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<int>'::`5'::temp = 0;
    return (CDmaVar<int> *)&`CBaseAttributePanel::GetAttributeValue<int>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498030
// Name: private: virtual void CAttributeIntChoicePanel::SetAttributeFromComboBox(class vgui::ComboBox __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::SetAttributeFromComboBox(
        CAttributeIntChoicePanel *this,
        vgui::ComboBox *pComboBox,
        KeyValues *pKeyValues)
{
  int m_Storage; // edi
  int nValue; // [esp+8h] [ebp-4h] BYREF

  m_Storage = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  nValue = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0);
  if ( m_Storage != nValue )
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
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &nValue);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004980D0
// Name: private: virtual void CAttributeIntChoicePanel::SetComboBoxFromAttribute(class vgui::ComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeIntChoicePanel::SetComboBoxFromAttribute(
        CAttributeIntChoicePanel *this,
        vgui::ComboBox *pComboBox)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmeMesh *v4; // esi
  int v5; // edi
  IElementPropertiesChoices *v6; // eax
  bool v7; // sf
  DmElementHandle_t m_handle; // eax
  int v9; // eax
  int v10; // edi
  const char *ChoiceType; // eax
  char v12; // al
  IntChoice_t *m_pMemory; // edx
  int v14; // eax
  vgui::ComboBox_vtbl *v15; // ebx
  const char *ChoiceString; // eax
  IntChoice_t *v17; // eax
  int v18; // [esp-10h] [ebp-3Ch]
  int v19; // [esp-8h] [ebp-34h]
  CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > choices; // [esp+Ch] [ebp-20h] BYREF
  int v21; // [esp+20h] [ebp-Ch]
  int nValue; // [esp+24h] [ebp-8h]
  int c; // [esp+28h] [ebp-4h]

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  v4 = (CDmeMesh *)EditorInfo;
  if ( EditorInfo == nullptr || !EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorIntChoicesInfo::m_classType) )
    return;
  nValue = CBaseAttributePanel::GetAttributeValue<int>(this)->m_Storage;
  v5 = 0;
  c = CDmeEditorChoicesInfo::GetChoiceCount(this: v4);
  if ( c <= 0 )
  {
LABEL_6:
    if ( CDmeEditorChoicesInfo::HasChoiceType(this: (CDmeEditorChoicesInfo *)v4) )
    {
      memset(&choices, 0, sizeof(choices));
      v6 = vgui::ElementPropertiesChoices();
      v7 = this->m_nArrayIndex < 0;
      c = (int)v6;
      m_handle = this->m_hObject.m_handle;
      LOBYTE(v21) = !v7;
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_handle);
      v10 = *(_DWORD *)c;
      v19 = v21;
      v18 = v9;
      ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: (CDmeEditorChoicesInfo *)v4);
      v12 = (*(int (__thiscall **)(int, const char *, int, char *, int, CUtlVector<IntChoice_t,CUtlMemory<IntChoice_t,int> > *))(v10 + 4))(
              a1: c,
              a2: ChoiceType,
              a3: v18,
              a4: this->m_szAttributeName,
              a5: v19,
              a6: &choices);
      m_pMemory = choices.m_Memory.m_pMemory;
      if ( v12 != 0 )
      {
        v14 = 0;
        if ( choices.m_Size > 0 )
        {
          while ( nValue != choices.m_Memory.m_pMemory[v14].m_nValue )
          {
            if ( ++v14 >= choices.m_Size )
              goto LABEL_20;
          }
          pComboBox->SetText(this: pComboBox, a2: choices.m_Memory.m_pMemory[v14].m_pChoiceString);
          v17 = choices.m_Memory.m_pMemory;
          choices.m_Size = 0;
          if ( choices.m_Memory.m_nGrowSize >= 0 )
          {
            if ( choices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
              v17 = nullptr;
              choices.m_Memory.m_pMemory = nullptr;
            }
            choices.m_Memory.m_nAllocationCount = 0;
          }
          choices.m_pElements = v17;
          if ( choices.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
          return;
        }
      }
LABEL_20:
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
    pComboBox->SetText(this: pComboBox, a2: "Unknown value");
    return;
  }
  while ( nValue != CDmeEditorIntChoicesInfo::GetChoiceValue(this: (CDmeEditorIntChoicesInfo *)v4, nIndex: v5) )
  {
    if ( ++v5 >= c )
      goto LABEL_6;
  }
  v15 = pComboBox->__vftable;
  ChoiceString = CDmeEditorChoicesInfo::GetChoiceString(this: (CDmeEditorChoicesInfo *)v4, nIndex: v5);
  v15->SetText(this: pComboBox, a2: ChoiceString);
}

//------------------------------------------------------------------------------
// Address: 0x00498310
// Name: public: CAttributeIntChoicePanel::CAttributeIntChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeIntChoicePanel *__thiscall CAttributeIntChoicePanel::CAttributeIntChoicePanel(
        CAttributeIntChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(this, parent, info);
  this->__vftable = (CAttributeIntChoicePanel_vtbl *)&CAttributeIntChoicePanel::`vftable';
  if ( `CAttributeIntChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeIntChoicePanel");
    v4->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeIntChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeIntChoicePanel");
    v5->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
  }
  if ( `CAttributeIntChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeIntChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeIntChoicePanel");
    v6->pfnClassName = CAttributeIntChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004983D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeIntChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeIntChoicePanel::GetMessageMap(CAttributeIntChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeIntChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeIntChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeIntChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeIntChoicePanel");
  `CAttributeIntChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00498400
// Name: public: virtual struct PanelAnimationMap __near * CAttributeIntChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeIntChoicePanel::GetAnimMap(CAttributeIntChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeIntChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00498410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeIntChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeIntChoicePanel::GetKBMap(CAttributeIntChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeIntChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeIntChoicePanel::GetKBMap'::`2'::s_pMap;
  `CAttributeIntChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeIntChoicePanel");
  `CAttributeIntChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00498440
// Name: public: virtual bool CDmeEditorIntChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorIntChoicesInfo::IsA(CDmeEditorIntChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorIntChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00498480
// Name: public: virtual int CDmeEditorIntChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorIntChoicesInfo::GetInheritanceDepth(
        CDmeEditorIntChoicesInfo *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorIntChoicesInfo::m_classType.u.m_Id )
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
// Address: 0x006ABDE0
// Name: _dynamic_initializer_for__CDmeEditorIntChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorIntChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorIntChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorIntChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3880
// Name: _dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorIntChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorIntChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ABE10
// Name: _dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ABE20
// Name: _dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorIntChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorIntChoicesInfo_Helper,
           classname: "DmeEditorIntChoicesInfo",
           pFactory: &g_CDmeEditorIntChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3890
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorIntChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorIntChoicesInfo_Factory.m_CallBackList);
}

} // namespace sceneviewer
