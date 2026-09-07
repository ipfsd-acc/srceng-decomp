// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributewidgetfactory.cpp
// Functions: 72
// ============================================================

#include "vgui2\dme_controls\attributewidgetfactory.h"

//------------------------------------------------------------------------------
// Address: 0x00466BC0
// Name: public: virtual void CAttributeWidgetFactoryList::ApplyChanges(class vgui::Panel __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeWidgetFactoryList::ApplyChanges(
        CAttributeWidgetFactoryList *this,
        vgui::Panel *pWidget,
        vgui::Panel *pSender)
{
  _DWORD *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::IPanel *v7; // esi
  vgui::IPanel_vtbl *v8; // edi
  int v9; // eax
  vgui::Panel *pWidgeta; // [esp+Ch] [ebp+8h]

  v4 = __RTDynamicCast(
         inptr: pWidget,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CBaseAttributePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr && (v4[156] & 8) != 0 )
  {
    if ( pSender != nullptr )
      pWidgeta = (vgui::Panel *)pSender->GetVPanel(this: pSender);
    else
      pWidgeta = nullptr;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ApplyChanges");
    else
      v6 = nullptr;
    v7 = g_pVGuiPanel;
    v8 = g_pVGuiPanel->__vftable;
    v9 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, vgui::Panel *))pWidget->GetVPanel)(
           a1: pWidget,
           a2: v6,
           a3: pWidgeta);
    ((void (__thiscall *)(vgui::IPanel *, int))v8->SendMessage)(a1: v7, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466C50
// Name: public: virtual void CAttributeWidgetFactoryList::Refresh(class vgui::Panel __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeWidgetFactoryList::Refresh(
        CAttributeWidgetFactoryList *this,
        vgui::Panel *pWidget,
        vgui::Panel *pSender)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  vgui::IPanel *v6; // esi
  vgui::IPanel_vtbl *v7; // ebx
  int v8; // eax
  vgui::Panel *pWidgeta; // [esp+Ch] [ebp+8h]

  if ( pWidget != nullptr )
  {
    if ( pSender != nullptr )
      pWidgeta = (vgui::Panel *)pWidget->GetVPanel(this: pWidget);
    else
      pWidgeta = nullptr;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Refresh");
    else
      v5 = nullptr;
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, vgui::Panel *))pWidget->GetVPanel)(
           a1: pWidget,
           a2: v5,
           a3: pWidgeta);
    ((void (__thiscall *)(vgui::IPanel *, int))v7->SendMessage)(a1: v6, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467820
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetWidgetFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetWidgetFactory(
        CAttributeWidgetFactoryList *this,
        const char *pWidgetName)
{
  unsigned __int16 v3; // ax
  CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pWidgetName == nullptr )
    return nullptr;
  search.key = pWidgetName;
  v3 = CUtlRBTree<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Factories.m_Elements.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x00467870
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetWidgetFactory(class CDmElement __near *,class CDmAttribute __near *,class CDmeEditorTypeDictionary __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetWidgetFactory(
        CAttributeWidgetFactoryList *this,
        CDmElement *object,
        CDmAttribute *pAttribute,
        CDmeEditorTypeDictionary *pTypeDictionary)
{
  IAttributeWidgetFactory *factory; // edi
  const char *m_pAsString; // eax
  CDmeEditorAttributeInfo *AttributeInfo; // eax
  CDmeEditorAttributeInfo *v8; // esi
  const char *WidgetName; // eax
  IAttributeWidgetFactory *WidgetFactory; // eax

  if ( object == nullptr )
    return nullptr;
  factory = g_AttributeWidgetFactories[pAttribute->m_nFlags & 0x1F].factory;
  if ( pTypeDictionary != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    AttributeInfo = CDmeEditorTypeDictionary::GetAttributeInfo(
                      this: pTypeDictionary,
                      pElement: object,
                      pAttributeName: m_pAsString);
    v8 = AttributeInfo;
    if ( AttributeInfo != nullptr )
    {
      if ( !AttributeInfo->m_bIsVisible.m_Storage )
        return nullptr;
      if ( CDmeEditorAttributeInfo::GetWidgetName(this: AttributeInfo) != nullptr )
      {
        WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: v8);
        WidgetFactory = CAttributeWidgetFactoryList::GetWidgetFactory(
                          this: g_pWidgetFactoryFactoryList,
                          pWidgetName: WidgetName);
        if ( WidgetFactory != nullptr )
          return WidgetFactory;
      }
    }
  }
  return factory;
}

//------------------------------------------------------------------------------
// Address: 0x004678F0
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetArrayWidgetFactory(class CDmElement __near *,class CDmAttribute __near *,class CDmeEditorTypeDictionary __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetArrayWidgetFactory(
        CAttributeWidgetFactoryList *this,
        CDmElement *object,
        CDmAttribute *pAttribute,
        CDmeEditorTypeDictionary *pTypeDictionary)
{
  int v5; // edi
  const char *m_pAsString; // eax
  CDmeEditorAttributeInfo *AttributeArrayInfo; // eax
  CDmeEditorAttributeInfo *v8; // esi
  const char *WidgetName; // eax
  IAttributeWidgetFactory *WidgetFactory; // eax

  if ( object == nullptr )
    return nullptr;
  v5 = *((_DWORD *)&vec4_invalid_18.y + 2 * (pAttribute->m_nFlags & 0x1F));
  if ( pTypeDictionary != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    AttributeArrayInfo = CDmeEditorTypeDictionary::GetAttributeArrayInfo(
                           this: pTypeDictionary,
                           pElement: object,
                           pAttributeName: m_pAsString);
    v8 = AttributeArrayInfo;
    if ( AttributeArrayInfo != nullptr )
    {
      if ( !AttributeArrayInfo->m_bIsVisible.m_Storage )
        return nullptr;
      if ( CDmeEditorAttributeInfo::GetWidgetName(this: AttributeArrayInfo) != nullptr )
      {
        WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: v8);
        WidgetFactory = CAttributeWidgetFactoryList::GetWidgetFactory(
                          this: g_pWidgetFactoryFactoryList,
                          pWidgetName: WidgetName);
        if ( WidgetFactory != nullptr )
          return WidgetFactory;
      }
    }
  }
  return (IAttributeWidgetFactory *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004679E0
// Name: public: CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeWidgetFactoryList *__thiscall CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(
        CAttributeWidgetFactoryList *this)
{
  CAttributeWidgetFactoryList *result; // eax

  result = this;
  this->__vftable = (CAttributeWidgetFactoryList_vtbl *)&CAttributeWidgetFactoryList::`vftable';
  this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Factories.m_Elements.m_Tree.m_Root = -1;
  this->m_Factories.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Factories.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Factories.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Factories.m_Elements.m_Tree.m_pElements = this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467AA0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeTextPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextPanel *__thiscall CAttributeWidgetFactory<CAttributeTextPanel>::Create(
        CAttributeWidgetFactory<CAttributeTextPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeTextPanel *v3; // eax
  CAttributeTextPanel *result; // eax
  CAttributeTextPanel *v5; // esi

  v3 = (CAttributeTextPanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeTextPanel::CAttributeTextPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467AF0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBooleanPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBooleanPanel *__thiscall CAttributeWidgetFactory<CAttributeBooleanPanel>::Create(
        CAttributeWidgetFactory<CAttributeBooleanPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBooleanPanel *v3; // eax
  CAttributeBooleanPanel *result; // eax
  CAttributeBooleanPanel *v5; // esi

  v3 = (CAttributeBooleanPanel *)MemAlloc_Alloc(nSize: 0x2B0u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBooleanPanel::CAttributeBooleanPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467B40
// Name: public: static char const __near * CAttributeDmeFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeDmeFilePickerPanel::GetPanelClassName()
{
  return "CAttributeDmeFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00467B50
// Name: public: CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDmeFilePickerPanel *__thiscall CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(
        CAttributeDmeFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeDmeFilePickerPanel_vtbl *)&CAttributeDmeFilePickerPanel::`vftable';
  if ( `CAttributeDmeFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeDmeFilePickerPanel");
    v4->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeDmeFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeDmeFilePickerPanel");
    v5->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeDmeFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDmeFilePickerPanel");
    v6->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00467C10
// Name: protected: virtual void CAttributeTextPanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::OnTextChanged(CAttributeTextPanel *this)
{
  CBaseAttributePanel::SetDirty(this, dirty: true);
}

//------------------------------------------------------------------------------
// Address: 0x00467C20
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeDmeFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeDmeFilePickerPanel::GetMessageMap(CAttributeDmeFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeDmeFilePickerPanel");
  `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467C50
// Name: public: virtual struct PanelAnimationMap __near * CAttributeDmeFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeDmeFilePickerPanel::GetAnimMap(CAttributeDmeFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeDmeFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00467C60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeDmeFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeDmeFilePickerPanel::GetKBMap(CAttributeDmeFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeDmeFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDmeFilePickerPanel");
  `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467C90
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeDmeFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDmeFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeDmeFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeDmeFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeDmeFilePickerPanel *v3; // eax
  CAttributeDmeFilePickerPanel *result; // eax
  CAttributeDmeFilePickerPanel *v5; // esi

  v3 = (CAttributeDmeFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467CE0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBoolChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBoolChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeBoolChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeBoolChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBoolChoicePanel *v3; // eax
  CAttributeBoolChoicePanel *result; // eax
  CAttributeBoolChoicePanel *v5; // esi

  v3 = (CAttributeBoolChoicePanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467D30
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeIntChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeIntChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeIntChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeIntChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeIntChoicePanel *v3; // eax
  CAttributeIntChoicePanel *result; // eax
  CAttributeIntChoicePanel *v5; // esi

  v3 = (CAttributeIntChoicePanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeIntChoicePanel::CAttributeIntChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467D80
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeStringChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeStringChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeStringChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeStringChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeStringChoicePanel *v3; // eax
  CAttributeStringChoicePanel *result; // eax
  CAttributeStringChoicePanel *v5; // esi

  v3 = (CAttributeStringChoicePanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeStringChoicePanel::CAttributeStringChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467DD0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeElementPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPanel *__thiscall CAttributeWidgetFactory<CAttributeElementPanel>::Create(
        CAttributeWidgetFactory<CAttributeElementPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeElementPanel *v3; // eax
  CAttributeElementPanel *result; // eax
  CAttributeElementPanel *v5; // esi

  v3 = (CAttributeElementPanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeElementPanel::CAttributeElementPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467E20
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeElementPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeElementPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeElementPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeElementPickerPanel *v3; // eax
  CAttributeElementPickerPanel *result; // eax
  CAttributeElementPickerPanel *v5; // esi

  v3 = (CAttributeElementPickerPanel *)MemAlloc_Alloc(nSize: 0x2ACu);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeElementPickerPanel::CAttributeElementPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467E70
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeMDLPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeMDLPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeMDLPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeMDLPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeMDLPickerPanel *v3; // eax
  CAttributeMDLPickerPanel *result; // eax
  CAttributeMDLPickerPanel *v5; // esi

  v3 = (CAttributeMDLPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467EC0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSequencePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSequencePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSequencePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSequencePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSequencePickerPanel *v3; // eax
  CAttributeSequencePickerPanel *result; // eax
  CAttributeSequencePickerPanel *v5; // esi

  v3 = (CAttributeSequencePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467F10
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSoundPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSoundPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSoundPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSoundPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSoundPickerPanel *v3; // eax
  CAttributeSoundPickerPanel *result; // eax
  CAttributeSoundPickerPanel *v5; // esi

  v3 = (CAttributeSoundPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467F60
// Name: public: static char const __near * CAttributeBspPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBspPickerPanel::GetPanelClassName()
{
  return "CAttributeBspPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00467F70
// Name: public: CAttributeBspPickerPanel::CAttributeBspPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBspPickerPanel *__thiscall CAttributeBspPickerPanel::CAttributeBspPickerPanel(
        CAttributeBspPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeBspPickerPanel_vtbl *)&CAttributeBspPickerPanel::`vftable';
  if ( `CAttributeBspPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBspPickerPanel");
    v4->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeBspPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBspPickerPanel");
    v5->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeBspPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBspPickerPanel");
    v6->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00468030
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBspPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBspPickerPanel::GetMessageMap(CAttributeBspPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBspPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBspPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBspPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBspPickerPanel");
  `CAttributeBspPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468060
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBspPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBspPickerPanel::GetAnimMap(CAttributeBspPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBspPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00468070
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBspPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBspPickerPanel::GetKBMap(CAttributeBspPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBspPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBspPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBspPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBspPickerPanel");
  `CAttributeBspPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004680D0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBspPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBspPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeBspPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeBspPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBspPickerPanel *v3; // eax
  CAttributeBspPickerPanel *result; // eax
  CAttributeBspPickerPanel *v5; // esi

  v3 = (CAttributeBspPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBspPickerPanel::CAttributeBspPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468120
// Name: public: static char const __near * CAttributeVmtPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeVmtPickerPanel::GetPanelClassName()
{
  return "CAttributeVmtPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00468130
// Name: public: static void CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x004681C0
// Name: public: CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVmtPickerPanel *__thiscall CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(
        CAttributeVmtPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeVmtPickerPanel_vtbl *)&CAttributeVmtPickerPanel::`vftable';
  if ( `CAttributeVmtPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
    v4->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVmtPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeVmtPickerPanel");
    v5->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVmtPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVmtPickerPanel");
    v6->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00468290
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeVmtPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeVmtPickerPanel::GetMessageMap(CAttributeVmtPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeVmtPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVmtPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeVmtPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
  `CAttributeVmtPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004682C0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeVmtPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeVmtPickerPanel::GetAnimMap(CAttributeVmtPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeVmtPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004682D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeVmtPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeVmtPickerPanel::GetKBMap(CAttributeVmtPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeVmtPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVmtPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeVmtPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVmtPickerPanel");
  `CAttributeVmtPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468300
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeVmtPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVmtPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeVmtPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeVmtPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeVmtPickerPanel *v3; // eax
  CAttributeVmtPickerPanel *result; // eax
  CAttributeVmtPickerPanel *v5; // esi

  v3 = (CAttributeVmtPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468350
// Name: public: static char const __near * CAttributeVtfPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeVtfPickerPanel::GetPanelClassName()
{
  return "CAttributeVtfPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00468360
// Name: public: CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVtfPickerPanel *__thiscall CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(
        CAttributeVtfPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeVtfPickerPanel_vtbl *)&CAttributeVtfPickerPanel::`vftable';
  if ( `CAttributeVtfPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeVtfPickerPanel");
    v4->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVtfPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeVtfPickerPanel");
    v5->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVtfPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVtfPickerPanel");
    v6->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00468420
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeVtfPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeVtfPickerPanel::GetMessageMap(CAttributeVtfPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeVtfPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVtfPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeVtfPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeVtfPickerPanel");
  `CAttributeVtfPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468450
// Name: public: virtual struct PanelAnimationMap __near * CAttributeVtfPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeVtfPickerPanel::GetAnimMap(CAttributeVtfPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeVtfPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00468460
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeVtfPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeVtfPickerPanel::GetKBMap(CAttributeVtfPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeVtfPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVtfPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeVtfPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVtfPickerPanel");
  `CAttributeVtfPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468490
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeVtfPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVtfPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeVtfPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeVtfPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeVtfPickerPanel *v3; // eax
  CAttributeVtfPickerPanel *result; // eax
  CAttributeVtfPickerPanel *v5; // esi

  v3 = (CAttributeVtfPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004684E0
// Name: public: static char const __near * CAttributeTgaPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTgaPickerPanel::GetPanelClassName()
{
  return "CAttributeTgaPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004684F0
// Name: public: CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTgaPickerPanel *__thiscall CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(
        CAttributeTgaPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeTgaPickerPanel_vtbl *)&CAttributeTgaPickerPanel::`vftable';
  if ( `CAttributeTgaPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTgaPickerPanel");
    v4->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeTgaPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTgaPickerPanel");
    v5->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeTgaPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTgaPickerPanel");
    v6->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004685B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTgaPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTgaPickerPanel::GetMessageMap(CAttributeTgaPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTgaPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTgaPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeTgaPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTgaPickerPanel");
  `CAttributeTgaPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004685E0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTgaPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTgaPickerPanel::GetAnimMap(CAttributeTgaPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTgaPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004685F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTgaPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTgaPickerPanel::GetKBMap(CAttributeTgaPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTgaPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTgaPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeTgaPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTgaPickerPanel");
  `CAttributeTgaPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468620
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeTgaPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTgaPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeTgaPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeTgaPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeTgaPickerPanel *v3; // eax
  CAttributeTgaPickerPanel *result; // eax
  CAttributeTgaPickerPanel *v5; // esi

  v3 = (CAttributeTgaPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468670
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeShaderPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShaderPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeShaderPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeShaderPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeShaderPickerPanel *v3; // eax
  CAttributeShaderPickerPanel *result; // eax
  CAttributeShaderPickerPanel *v5; // esi

  v3 = (CAttributeShaderPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004686C0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSurfacePropertyPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSurfacePropertyPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSurfacePropertyPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSurfacePropertyPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSurfacePropertyPickerPanel *v3; // eax
  CAttributeSurfacePropertyPickerPanel *result; // eax
  CAttributeSurfacePropertyPickerPanel *v5; // esi

  v3 = (CAttributeSurfacePropertyPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468710
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeColorPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeColorPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeColorPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeColorPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeColorPickerPanel *v3; // eax
  CAttributeColorPickerPanel *result; // eax
  CAttributeColorPickerPanel *v5; // esi

  v3 = (CAttributeColorPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeColorPickerPanel::CAttributeColorPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468760
// Name: public: static char const __near * CAttributeAviFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeAviFilePickerPanel::GetPanelClassName()
{
  return "CAttributeAviFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00468770
// Name: public: CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAviFilePickerPanel *__thiscall CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(
        CAttributeAviFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeAviFilePickerPanel_vtbl *)&CAttributeAviFilePickerPanel::`vftable';
  if ( `CAttributeAviFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeAviFilePickerPanel");
    v4->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeAviFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeAviFilePickerPanel");
    v5->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeAviFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAviFilePickerPanel");
    v6->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00468830
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeAviFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeAviFilePickerPanel::GetMessageMap(CAttributeAviFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeAviFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeAviFilePickerPanel");
  `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468860
// Name: public: virtual struct PanelAnimationMap __near * CAttributeAviFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeAviFilePickerPanel::GetAnimMap(CAttributeAviFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeAviFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00468870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeAviFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeAviFilePickerPanel::GetKBMap(CAttributeAviFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeAviFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAviFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeAviFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAviFilePickerPanel");
  `CAttributeAviFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004688D0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeAviFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAviFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeAviFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeAviFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeAviFilePickerPanel *v3; // eax
  CAttributeAviFilePickerPanel *result; // eax
  CAttributeAviFilePickerPanel *v5; // esi

  v3 = (CAttributeAviFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468920
// Name: public: static char const __near * CAttributeShtFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeShtFilePickerPanel::GetPanelClassName()
{
  return "CAttributeShtFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00468930
// Name: public: CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShtFilePickerPanel *__thiscall CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(
        CAttributeShtFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeShtFilePickerPanel_vtbl *)&CAttributeShtFilePickerPanel::`vftable';
  if ( `CAttributeShtFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeShtFilePickerPanel");
    v4->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeShtFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeShtFilePickerPanel");
    v5->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeShtFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShtFilePickerPanel");
    v6->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004689F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeShtFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeShtFilePickerPanel::GetMessageMap(CAttributeShtFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeShtFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeShtFilePickerPanel");
  `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468A20
// Name: public: virtual struct PanelAnimationMap __near * CAttributeShtFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeShtFilePickerPanel::GetAnimMap(CAttributeShtFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeShtFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00468A30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeShtFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeShtFilePickerPanel::GetKBMap(CAttributeShtFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeShtFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShtFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeShtFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShtFilePickerPanel");
  `CAttributeShtFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468A60
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeShtFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShtFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeShtFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeShtFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeShtFilePickerPanel *v3; // eax
  CAttributeShtFilePickerPanel *result; // eax
  CAttributeShtFilePickerPanel *v5; // esi

  v3 = (CAttributeShtFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468AB0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeDetailTypePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDetailTypePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeDetailTypePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeDetailTypePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeDetailTypePickerPanel *v3; // eax
  CAttributeDetailTypePickerPanel *result; // eax
  CAttributeDetailTypePickerPanel *v5; // esi

  v3 = (CAttributeDetailTypePickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468B00
// Name: public: static char const __near * CAttributeRawFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeRawFilePickerPanel::GetPanelClassName()
{
  return "CAttributeRawFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00468B10
// Name: public: CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeRawFilePickerPanel *__thiscall CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(
        CAttributeRawFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeRawFilePickerPanel_vtbl *)&CAttributeRawFilePickerPanel::`vftable';
  if ( `CAttributeRawFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeRawFilePickerPanel");
    v4->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeRawFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeRawFilePickerPanel");
    v5->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeRawFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeRawFilePickerPanel");
    v6->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00468BD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeRawFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeRawFilePickerPanel::GetMessageMap(CAttributeRawFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeRawFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeRawFilePickerPanel");
  `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468C00
// Name: public: virtual struct PanelAnimationMap __near * CAttributeRawFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeRawFilePickerPanel::GetAnimMap(CAttributeRawFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeRawFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00468C10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeRawFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeRawFilePickerPanel::GetKBMap(CAttributeRawFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeRawFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeRawFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeRawFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeRawFilePickerPanel");
  `CAttributeRawFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468C40
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeRawFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeRawFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeRawFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeRawFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeRawFilePickerPanel *v3; // eax
  CAttributeRawFilePickerPanel *result; // eax
  CAttributeRawFilePickerPanel *v5; // esi

  v3 = (CAttributeRawFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468C90
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeInterpolatorChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeInterpolatorChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeInterpolatorChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeInterpolatorChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeInterpolatorChoicePanel *v3; // eax
  CAttributeInterpolatorChoicePanel *result; // eax
  CAttributeInterpolatorChoicePanel *v5; // esi

  v3 = (CAttributeInterpolatorChoicePanel *)MemAlloc_Alloc(nSize: 0x2B0u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468CE0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSheetSequencePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSheetSequencePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSheetSequencePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSheetSequencePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSheetSequencePickerPanel *v3; // eax
  CAttributeSheetSequencePickerPanel *result; // eax
  CAttributeSheetSequencePickerPanel *v5; // esi

  v3 = (CAttributeSheetSequencePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10484C30
// Name: public: virtual void CAttributeWidgetFactoryList::ApplyChanges(class vgui::Panel __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeWidgetFactoryList::ApplyChanges(
        CAttributeWidgetFactoryList *this,
        vgui::Panel *pWidget,
        vgui::Panel *pSender)
{
  _DWORD *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::IPanel *v7; // esi
  vgui::IPanel_vtbl *v8; // edi
  int v9; // eax
  vgui::Panel *pWidgeta; // [esp+Ch] [ebp+8h]

  v4 = __RTDynamicCast(
         inptr: pWidget,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CBaseAttributePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr && (v4[156] & 8) != 0 )
  {
    if ( pSender != nullptr )
      pWidgeta = (vgui::Panel *)pSender->GetVPanel(this: pSender);
    else
      pWidgeta = nullptr;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ApplyChanges");
    else
      v6 = nullptr;
    v7 = g_pVGuiPanel;
    v8 = g_pVGuiPanel->__vftable;
    v9 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, vgui::Panel *))pWidget->GetVPanel)(
           a1: pWidget,
           a2: v6,
           a3: pWidgeta);
    ((void (__thiscall *)(vgui::IPanel *, int))v8->SendMessage)(a1: v7, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10484CC0
// Name: public: virtual void CAttributeWidgetFactoryList::Refresh(class vgui::Panel __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeWidgetFactoryList::Refresh(
        CAttributeWidgetFactoryList *this,
        vgui::Panel *pWidget,
        vgui::Panel *pSender)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  vgui::IPanel *v6; // esi
  vgui::IPanel_vtbl *v7; // ebx
  int v8; // eax
  vgui::Panel *pWidgeta; // [esp+Ch] [ebp+8h]

  if ( pWidget != nullptr )
  {
    if ( pSender != nullptr )
      pWidgeta = (vgui::Panel *)pWidget->GetVPanel(this: pWidget);
    else
      pWidgeta = nullptr;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Refresh");
    else
      v5 = nullptr;
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, vgui::Panel *))pWidget->GetVPanel)(
           a1: pWidget,
           a2: v5,
           a3: pWidgeta);
    ((void (__thiscall *)(vgui::IPanel *, int))v7->SendMessage)(a1: v6, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10485890
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetWidgetFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetWidgetFactory(
        CAttributeWidgetFactoryList *this,
        const char *pWidgetName)
{
  unsigned __int16 v3; // ax
  CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pWidgetName == nullptr )
    return nullptr;
  search.key = pWidgetName;
  v3 = CUtlRBTree<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Factories.m_Elements.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x104858E0
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetWidgetFactory(class CDmElement __near *,class CDmAttribute __near *,class CDmeEditorTypeDictionary __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetWidgetFactory(
        CAttributeWidgetFactoryList *this,
        CDmElement *object,
        CDmAttribute *pAttribute,
        CDmeEditorTypeDictionary *pTypeDictionary)
{
  IAttributeWidgetFactory *factory; // edi
  const char *m_pAsString; // eax
  CDmeEditorAttributeInfo *AttributeInfo; // eax
  CDmeEditorAttributeInfo *v8; // esi
  const char *WidgetName; // eax
  IAttributeWidgetFactory *WidgetFactory; // eax

  if ( object == nullptr )
    return nullptr;
  factory = g_AttributeWidgetFactories[pAttribute->m_nFlags & 0x1F].factory;
  if ( pTypeDictionary != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    AttributeInfo = CDmeEditorTypeDictionary::GetAttributeInfo(
                      this: pTypeDictionary,
                      pElement: object,
                      pAttributeName: m_pAsString);
    v8 = AttributeInfo;
    if ( AttributeInfo != nullptr )
    {
      if ( !AttributeInfo->m_bIsVisible.m_Storage )
        return nullptr;
      if ( CDmeEditorAttributeInfo::GetWidgetName(this: AttributeInfo) != nullptr )
      {
        WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: v8);
        WidgetFactory = CAttributeWidgetFactoryList::GetWidgetFactory(
                          this: g_pWidgetFactoryFactoryList,
                          pWidgetName: WidgetName);
        if ( WidgetFactory != nullptr )
          return WidgetFactory;
      }
    }
  }
  return factory;
}

//------------------------------------------------------------------------------
// Address: 0x10485960
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetArrayWidgetFactory(class CDmElement __near *,class CDmAttribute __near *,class CDmeEditorTypeDictionary __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetArrayWidgetFactory(
        CAttributeWidgetFactoryList *this,
        CDmElement *object,
        CDmAttribute *pAttribute,
        CDmeEditorTypeDictionary *pTypeDictionary)
{
  int v5; // edi
  const char *m_pAsString; // eax
  CDmeEditorAttributeInfo *AttributeArrayInfo; // eax
  CDmeEditorAttributeInfo *v8; // esi
  const char *WidgetName; // eax
  IAttributeWidgetFactory *WidgetFactory; // eax

  if ( object == nullptr )
    return nullptr;
  v5 = dword_107768B4[2 * (pAttribute->m_nFlags & 0x1F)];
  if ( pTypeDictionary != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    AttributeArrayInfo = CDmeEditorTypeDictionary::GetAttributeArrayInfo(
                           this: pTypeDictionary,
                           pElement: object,
                           pAttributeName: m_pAsString);
    v8 = AttributeArrayInfo;
    if ( AttributeArrayInfo != nullptr )
    {
      if ( !AttributeArrayInfo->m_bIsVisible.m_Storage )
        return nullptr;
      if ( CDmeEditorAttributeInfo::GetWidgetName(this: AttributeArrayInfo) != nullptr )
      {
        WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: v8);
        WidgetFactory = CAttributeWidgetFactoryList::GetWidgetFactory(
                          this: g_pWidgetFactoryFactoryList,
                          pWidgetName: WidgetName);
        if ( WidgetFactory != nullptr )
          return WidgetFactory;
      }
    }
  }
  return (IAttributeWidgetFactory *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10485A50
// Name: public: CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeWidgetFactoryList *__thiscall CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(
        CAttributeWidgetFactoryList *this)
{
  CAttributeWidgetFactoryList *result; // eax

  result = this;
  this->__vftable = (CAttributeWidgetFactoryList_vtbl *)&CAttributeWidgetFactoryList::`vftable';
  this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Factories.m_Elements.m_Tree.m_Root = -1;
  this->m_Factories.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Factories.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Factories.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Factories.m_Elements.m_Tree.m_pElements = this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485B10
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeTextPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextPanel *__thiscall CAttributeWidgetFactory<CAttributeTextPanel>::Create(
        CAttributeWidgetFactory<CAttributeTextPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeTextPanel *v3; // eax
  CAttributeTextPanel *result; // eax
  CAttributeTextPanel *v5; // esi

  v3 = (CAttributeTextPanel *)operator new(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeTextPanel::CAttributeTextPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485B60
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBooleanPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBooleanPanel *__thiscall CAttributeWidgetFactory<CAttributeBooleanPanel>::Create(
        CAttributeWidgetFactory<CAttributeBooleanPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBooleanPanel *v3; // eax
  CAttributeBooleanPanel *result; // eax
  CAttributeBooleanPanel *v5; // esi

  v3 = (CAttributeBooleanPanel *)operator new(nSize: 0x2B0u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBooleanPanel::CAttributeBooleanPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485BB0
// Name: public: static char const __near * CAttributeDmeFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeDmeFilePickerPanel::GetPanelClassName()
{
  return "CAttributeDmeFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10485BC0
// Name: public: CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDmeFilePickerPanel *__thiscall CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(
        CAttributeDmeFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeDmeFilePickerPanel_vtbl *)&CAttributeDmeFilePickerPanel::`vftable';
  if ( `CAttributeDmeFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeDmeFilePickerPanel");
    v4->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeDmeFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeDmeFilePickerPanel");
    v5->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeDmeFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDmeFilePickerPanel");
    v6->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10485C80
// Name: protected: virtual void CAttributeTextPanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::OnTextChanged(CAttributeTextPanel *this)
{
  CBaseAttributePanel::SetDirty(this, dirty: true);
}

//------------------------------------------------------------------------------
// Address: 0x10485C90
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeDmeFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeDmeFilePickerPanel::GetMessageMap(CAttributeDmeFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeDmeFilePickerPanel");
  `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485CC0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeDmeFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeDmeFilePickerPanel::GetAnimMap(CAttributeDmeFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeDmeFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10485CD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeDmeFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeDmeFilePickerPanel::GetKBMap(CAttributeDmeFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeDmeFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDmeFilePickerPanel");
  `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485D00
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeDmeFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDmeFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeDmeFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeDmeFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeDmeFilePickerPanel *v3; // eax
  CAttributeDmeFilePickerPanel *result; // eax
  CAttributeDmeFilePickerPanel *v5; // esi

  v3 = (CAttributeDmeFilePickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485D50
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBoolChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBoolChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeBoolChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeBoolChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBoolChoicePanel *v3; // eax
  CAttributeBoolChoicePanel *result; // eax
  CAttributeBoolChoicePanel *v5; // esi

  v3 = (CAttributeBoolChoicePanel *)operator new(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485DA0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeIntChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeIntChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeIntChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeIntChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeIntChoicePanel *v3; // eax
  CAttributeIntChoicePanel *result; // eax
  CAttributeIntChoicePanel *v5; // esi

  v3 = (CAttributeIntChoicePanel *)operator new(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeIntChoicePanel::CAttributeIntChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485DF0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeStringChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeStringChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeStringChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeStringChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeStringChoicePanel *v3; // eax
  CAttributeStringChoicePanel *result; // eax
  CAttributeStringChoicePanel *v5; // esi

  v3 = (CAttributeStringChoicePanel *)operator new(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeStringChoicePanel::CAttributeStringChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485E40
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeElementPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPanel *__thiscall CAttributeWidgetFactory<CAttributeElementPanel>::Create(
        CAttributeWidgetFactory<CAttributeElementPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeElementPanel *v3; // eax
  CAttributeElementPanel *result; // eax
  CAttributeElementPanel *v5; // esi

  v3 = (CAttributeElementPanel *)operator new(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeElementPanel::CAttributeElementPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485E90
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeElementPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeElementPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeElementPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeElementPickerPanel *v3; // eax
  CAttributeElementPickerPanel *result; // eax
  CAttributeElementPickerPanel *v5; // esi

  v3 = (CAttributeElementPickerPanel *)operator new(nSize: 0x2ACu);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeElementPickerPanel::CAttributeElementPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485EE0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeMDLPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeMDLPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeMDLPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeMDLPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeMDLPickerPanel *v3; // eax
  CAttributeMDLPickerPanel *result; // eax
  CAttributeMDLPickerPanel *v5; // esi

  v3 = (CAttributeMDLPickerPanel *)operator new(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485F30
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSequencePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSequencePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSequencePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSequencePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSequencePickerPanel *v3; // eax
  CAttributeSequencePickerPanel *result; // eax
  CAttributeSequencePickerPanel *v5; // esi

  v3 = (CAttributeSequencePickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485F80
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSoundPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSoundPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSoundPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSoundPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSoundPickerPanel *v3; // eax
  CAttributeSoundPickerPanel *result; // eax
  CAttributeSoundPickerPanel *v5; // esi

  v3 = (CAttributeSoundPickerPanel *)operator new(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10485FD0
// Name: public: static char const __near * CAttributeBspPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBspPickerPanel::GetPanelClassName()
{
  return "CAttributeBspPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10485FF0
// Name: public: CAttributeBspPickerPanel::CAttributeBspPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBspPickerPanel *__thiscall CAttributeBspPickerPanel::CAttributeBspPickerPanel(
        CAttributeBspPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeBspPickerPanel_vtbl *)&CAttributeBspPickerPanel::`vftable';
  if ( `CAttributeBspPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBspPickerPanel");
    v4->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeBspPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBspPickerPanel");
    v5->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeBspPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBspPickerPanel");
    v6->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104860B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBspPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBspPickerPanel::GetMessageMap(CAttributeBspPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBspPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBspPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBspPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBspPickerPanel");
  `CAttributeBspPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104860E0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBspPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBspPickerPanel::GetAnimMap(CAttributeBspPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBspPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104860F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBspPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBspPickerPanel::GetKBMap(CAttributeBspPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBspPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBspPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBspPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBspPickerPanel");
  `CAttributeBspPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486120
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBspPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBspPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeBspPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeBspPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBspPickerPanel *v3; // eax
  CAttributeBspPickerPanel *result; // eax
  CAttributeBspPickerPanel *v5; // esi

  v3 = (CAttributeBspPickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBspPickerPanel::CAttributeBspPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486170
// Name: public: static char const __near * CAttributeVmtPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeVmtPickerPanel::GetPanelClassName()
{
  return "CAttributeVmtPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10486180
// Name: public: static void CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x10486210
// Name: public: CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVmtPickerPanel *__thiscall CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(
        CAttributeVmtPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeVmtPickerPanel_vtbl *)&CAttributeVmtPickerPanel::`vftable';
  if ( `CAttributeVmtPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
    v4->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVmtPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeVmtPickerPanel");
    v5->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVmtPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVmtPickerPanel");
    v6->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104862E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeVmtPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeVmtPickerPanel::GetMessageMap(CAttributeVmtPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeVmtPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVmtPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeVmtPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
  `CAttributeVmtPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486310
// Name: public: virtual struct PanelAnimationMap __near * CAttributeVmtPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeVmtPickerPanel::GetAnimMap(CAttributeVmtPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeVmtPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10486320
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeVmtPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeVmtPickerPanel::GetKBMap(CAttributeVmtPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeVmtPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVmtPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeVmtPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVmtPickerPanel");
  `CAttributeVmtPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486350
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeVmtPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVmtPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeVmtPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeVmtPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeVmtPickerPanel *v3; // eax
  CAttributeVmtPickerPanel *result; // eax
  CAttributeVmtPickerPanel *v5; // esi

  v3 = (CAttributeVmtPickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104863A0
// Name: public: static char const __near * CAttributeVtfPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeVtfPickerPanel::GetPanelClassName()
{
  return "CAttributeVtfPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104863B0
// Name: public: CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVtfPickerPanel *__thiscall CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(
        CAttributeVtfPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeVtfPickerPanel_vtbl *)&CAttributeVtfPickerPanel::`vftable';
  if ( `CAttributeVtfPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeVtfPickerPanel");
    v4->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVtfPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeVtfPickerPanel");
    v5->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVtfPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVtfPickerPanel");
    v6->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10486470
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeVtfPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeVtfPickerPanel::GetMessageMap(CAttributeVtfPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeVtfPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVtfPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeVtfPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeVtfPickerPanel");
  `CAttributeVtfPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104864A0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeVtfPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeVtfPickerPanel::GetAnimMap(CAttributeVtfPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeVtfPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104864B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeVtfPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeVtfPickerPanel::GetKBMap(CAttributeVtfPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeVtfPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVtfPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeVtfPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVtfPickerPanel");
  `CAttributeVtfPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486510
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeVtfPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVtfPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeVtfPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeVtfPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeVtfPickerPanel *v3; // eax
  CAttributeVtfPickerPanel *result; // eax
  CAttributeVtfPickerPanel *v5; // esi

  v3 = (CAttributeVtfPickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486560
// Name: public: static char const __near * CAttributeTgaPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTgaPickerPanel::GetPanelClassName()
{
  return "CAttributeTgaPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10486570
// Name: public: CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTgaPickerPanel *__thiscall CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(
        CAttributeTgaPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeTgaPickerPanel_vtbl *)&CAttributeTgaPickerPanel::`vftable';
  if ( `CAttributeTgaPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTgaPickerPanel");
    v4->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeTgaPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTgaPickerPanel");
    v5->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeTgaPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTgaPickerPanel");
    v6->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10486630
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTgaPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTgaPickerPanel::GetMessageMap(CAttributeTgaPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTgaPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTgaPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeTgaPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTgaPickerPanel");
  `CAttributeTgaPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486660
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTgaPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTgaPickerPanel::GetAnimMap(CAttributeTgaPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTgaPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10486670
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTgaPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTgaPickerPanel::GetKBMap(CAttributeTgaPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTgaPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTgaPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeTgaPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTgaPickerPanel");
  `CAttributeTgaPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104866A0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeTgaPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTgaPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeTgaPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeTgaPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeTgaPickerPanel *v3; // eax
  CAttributeTgaPickerPanel *result; // eax
  CAttributeTgaPickerPanel *v5; // esi

  v3 = (CAttributeTgaPickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104866F0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeShaderPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShaderPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeShaderPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeShaderPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeShaderPickerPanel *v3; // eax
  CAttributeShaderPickerPanel *result; // eax
  CAttributeShaderPickerPanel *v5; // esi

  v3 = (CAttributeShaderPickerPanel *)operator new(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486740
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSurfacePropertyPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSurfacePropertyPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSurfacePropertyPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSurfacePropertyPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSurfacePropertyPickerPanel *v3; // eax
  CAttributeSurfacePropertyPickerPanel *result; // eax
  CAttributeSurfacePropertyPickerPanel *v5; // esi

  v3 = (CAttributeSurfacePropertyPickerPanel *)operator new(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486790
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeColorPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeColorPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeColorPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeColorPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeColorPickerPanel *v3; // eax
  CAttributeColorPickerPanel *result; // eax
  CAttributeColorPickerPanel *v5; // esi

  v3 = (CAttributeColorPickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeColorPickerPanel::CAttributeColorPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104867E0
// Name: public: static char const __near * CAttributeAviFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeAviFilePickerPanel::GetPanelClassName()
{
  return "CAttributeAviFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104867F0
// Name: public: CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAviFilePickerPanel *__thiscall CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(
        CAttributeAviFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeAviFilePickerPanel_vtbl *)&CAttributeAviFilePickerPanel::`vftable';
  if ( `CAttributeAviFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeAviFilePickerPanel");
    v4->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeAviFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeAviFilePickerPanel");
    v5->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeAviFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAviFilePickerPanel");
    v6->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104868B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeAviFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeAviFilePickerPanel::GetMessageMap(CAttributeAviFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeAviFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeAviFilePickerPanel");
  `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104868E0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeAviFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeAviFilePickerPanel::GetAnimMap(CAttributeAviFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeAviFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104868F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeAviFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeAviFilePickerPanel::GetKBMap(CAttributeAviFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeAviFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAviFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeAviFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAviFilePickerPanel");
  `CAttributeAviFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486920
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeAviFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAviFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeAviFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeAviFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeAviFilePickerPanel *v3; // eax
  CAttributeAviFilePickerPanel *result; // eax
  CAttributeAviFilePickerPanel *v5; // esi

  v3 = (CAttributeAviFilePickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486970
// Name: public: static char const __near * CAttributeShtFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeShtFilePickerPanel::GetPanelClassName()
{
  return "CAttributeShtFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10486980
// Name: public: CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShtFilePickerPanel *__thiscall CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(
        CAttributeShtFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeShtFilePickerPanel_vtbl *)&CAttributeShtFilePickerPanel::`vftable';
  if ( `CAttributeShtFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeShtFilePickerPanel");
    v4->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeShtFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeShtFilePickerPanel");
    v5->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeShtFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShtFilePickerPanel");
    v6->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10486A40
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeShtFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeShtFilePickerPanel::GetMessageMap(CAttributeShtFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeShtFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeShtFilePickerPanel");
  `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486A70
// Name: public: virtual struct PanelAnimationMap __near * CAttributeShtFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeShtFilePickerPanel::GetAnimMap(CAttributeShtFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeShtFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10486A80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeShtFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeShtFilePickerPanel::GetKBMap(CAttributeShtFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeShtFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShtFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeShtFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShtFilePickerPanel");
  `CAttributeShtFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486AE0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeShtFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShtFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeShtFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeShtFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeShtFilePickerPanel *v3; // eax
  CAttributeShtFilePickerPanel *result; // eax
  CAttributeShtFilePickerPanel *v5; // esi

  v3 = (CAttributeShtFilePickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486B30
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeDetailTypePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDetailTypePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeDetailTypePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeDetailTypePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeDetailTypePickerPanel *v3; // eax
  CAttributeDetailTypePickerPanel *result; // eax
  CAttributeDetailTypePickerPanel *v5; // esi

  v3 = (CAttributeDetailTypePickerPanel *)operator new(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486B80
// Name: public: static char const __near * CAttributeRawFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeRawFilePickerPanel::GetPanelClassName()
{
  return "CAttributeRawFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10486B90
// Name: public: CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeRawFilePickerPanel *__thiscall CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(
        CAttributeRawFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeRawFilePickerPanel_vtbl *)&CAttributeRawFilePickerPanel::`vftable';
  if ( `CAttributeRawFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeRawFilePickerPanel");
    v4->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeRawFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeRawFilePickerPanel");
    v5->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeRawFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeRawFilePickerPanel");
    v6->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10486C50
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeRawFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeRawFilePickerPanel::GetMessageMap(CAttributeRawFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeRawFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeRawFilePickerPanel");
  `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486C80
// Name: public: virtual struct PanelAnimationMap __near * CAttributeRawFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeRawFilePickerPanel::GetAnimMap(CAttributeRawFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeRawFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10486C90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeRawFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeRawFilePickerPanel::GetKBMap(CAttributeRawFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeRawFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeRawFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeRawFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeRawFilePickerPanel");
  `CAttributeRawFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486CC0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeRawFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeRawFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeRawFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeRawFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeRawFilePickerPanel *v3; // eax
  CAttributeRawFilePickerPanel *result; // eax
  CAttributeRawFilePickerPanel *v5; // esi

  v3 = (CAttributeRawFilePickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486D10
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeInterpolatorChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeInterpolatorChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeInterpolatorChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeInterpolatorChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeInterpolatorChoicePanel *v3; // eax
  CAttributeInterpolatorChoicePanel *result; // eax
  CAttributeInterpolatorChoicePanel *v5; // esi

  v3 = (CAttributeInterpolatorChoicePanel *)operator new(nSize: 0x2B0u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486D60
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSheetSequencePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSheetSequencePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSheetSequencePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSheetSequencePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSheetSequencePickerPanel *v3; // eax
  CAttributeSheetSequencePickerPanel *result; // eax
  CAttributeSheetSequencePickerPanel *v5; // esi

  v3 = (CAttributeSheetSequencePickerPanel *)operator new(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004841D0
// Name: public: virtual void CAttributeWidgetFactoryList::ApplyChanges(class vgui::Panel __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeWidgetFactoryList::ApplyChanges(
        CAttributeWidgetFactoryList *this,
        vgui::Panel *pWidget,
        vgui::Panel *pSender)
{
  _DWORD *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::IPanel *v7; // esi
  vgui::IPanel_vtbl *v8; // edi
  int v9; // eax
  vgui::Panel *pWidgeta; // [esp+Ch] [ebp+8h]

  v4 = __RTDynamicCast(
         inptr: pWidget,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CBaseAttributePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr && (v4[156] & 8) != 0 )
  {
    if ( pSender != nullptr )
      pWidgeta = (vgui::Panel *)pSender->GetVPanel(this: pSender);
    else
      pWidgeta = nullptr;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ApplyChanges");
    else
      v6 = nullptr;
    v7 = g_pVGuiPanel;
    v8 = g_pVGuiPanel->__vftable;
    v9 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, vgui::Panel *))pWidget->GetVPanel)(
           a1: pWidget,
           a2: v6,
           a3: pWidgeta);
    ((void (__thiscall *)(vgui::IPanel *, int))v8->SendMessage)(a1: v7, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484260
// Name: public: virtual void CAttributeWidgetFactoryList::Refresh(class vgui::Panel __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeWidgetFactoryList::Refresh(
        CAttributeWidgetFactoryList *this,
        vgui::Panel *pWidget,
        vgui::Panel *pSender)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  vgui::IPanel *v6; // esi
  vgui::IPanel_vtbl *v7; // ebx
  int v8; // eax
  vgui::Panel *pWidgeta; // [esp+Ch] [ebp+8h]

  if ( pWidget != nullptr )
  {
    if ( pSender != nullptr )
      pWidgeta = (vgui::Panel *)pWidget->GetVPanel(this: pWidget);
    else
      pWidgeta = nullptr;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Refresh");
    else
      v5 = nullptr;
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, vgui::Panel *))pWidget->GetVPanel)(
           a1: pWidget,
           a2: v5,
           a3: pWidgeta);
    ((void (__thiscall *)(vgui::IPanel *, int))v7->SendMessage)(a1: v6, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484FE0
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetWidgetFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetWidgetFactory(
        CAttributeWidgetFactoryList *this,
        const char *pWidgetName)
{
  unsigned __int16 v3; // ax
  CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pWidgetName == nullptr )
    return nullptr;
  search.key = pWidgetName;
  v3 = CUtlRBTree<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Factories.m_Elements.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x00485030
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetWidgetFactory(class CDmElement __near *,class CDmAttribute __near *,class CDmeEditorTypeDictionary __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetWidgetFactory(
        CAttributeWidgetFactoryList *this,
        CDmElement *object,
        CDmAttribute *pAttribute,
        CDmeEditorTypeDictionary *pTypeDictionary)
{
  IAttributeWidgetFactory *factory; // edi
  const char *m_pAsString; // eax
  CDmeEditorAttributeInfo *AttributeInfo; // eax
  CDmeEditorAttributeInfo *v8; // esi
  const char *WidgetName; // eax
  IAttributeWidgetFactory *WidgetFactory; // eax

  if ( object == nullptr )
    return nullptr;
  factory = g_AttributeWidgetFactories[pAttribute->m_nFlags & 0x1F].factory;
  if ( pTypeDictionary != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    AttributeInfo = CDmeEditorTypeDictionary::GetAttributeInfo(
                      this: pTypeDictionary,
                      pElement: object,
                      pAttributeName: m_pAsString);
    v8 = AttributeInfo;
    if ( AttributeInfo != nullptr )
    {
      if ( !AttributeInfo->m_bIsVisible.m_Storage )
        return nullptr;
      if ( CDmeEditorAttributeInfo::GetWidgetName(this: AttributeInfo) != nullptr )
      {
        WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: v8);
        WidgetFactory = CAttributeWidgetFactoryList::GetWidgetFactory(
                          this: g_pWidgetFactoryFactoryList,
                          pWidgetName: WidgetName);
        if ( WidgetFactory != nullptr )
          return WidgetFactory;
      }
    }
  }
  return factory;
}

//------------------------------------------------------------------------------
// Address: 0x004850B0
// Name: public: virtual class IAttributeWidgetFactory __near * CAttributeWidgetFactoryList::GetArrayWidgetFactory(class CDmElement __near *,class CDmAttribute __near *,class CDmeEditorTypeDictionary __near *)
// Source: json
//------------------------------------------------------------------------------
IAttributeWidgetFactory *__thiscall CAttributeWidgetFactoryList::GetArrayWidgetFactory(
        CAttributeWidgetFactoryList *this,
        CDmElement *object,
        CDmAttribute *pAttribute,
        CDmeEditorTypeDictionary *pTypeDictionary)
{
  int v5; // edi
  const char *m_pAsString; // eax
  CDmeEditorAttributeInfo *AttributeArrayInfo; // eax
  CDmeEditorAttributeInfo *v8; // esi
  const char *WidgetName; // eax
  IAttributeWidgetFactory *WidgetFactory; // eax

  if ( object == nullptr )
    return nullptr;
  v5 = dword_78588C[2 * (pAttribute->m_nFlags & 0x1F)];
  if ( pTypeDictionary != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    AttributeArrayInfo = CDmeEditorTypeDictionary::GetAttributeArrayInfo(
                           this: pTypeDictionary,
                           pElement: object,
                           pAttributeName: m_pAsString);
    v8 = AttributeArrayInfo;
    if ( AttributeArrayInfo != nullptr )
    {
      if ( !AttributeArrayInfo->m_bIsVisible.m_Storage )
        return nullptr;
      if ( CDmeEditorAttributeInfo::GetWidgetName(this: AttributeArrayInfo) != nullptr )
      {
        WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: v8);
        WidgetFactory = CAttributeWidgetFactoryList::GetWidgetFactory(
                          this: g_pWidgetFactoryFactoryList,
                          pWidgetName: WidgetName);
        if ( WidgetFactory != nullptr )
          return WidgetFactory;
      }
    }
  }
  return (IAttributeWidgetFactory *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004851A0
// Name: public: CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeWidgetFactoryList *__thiscall CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(
        CAttributeWidgetFactoryList *this)
{
  CAttributeWidgetFactoryList *result; // eax

  result = this;
  this->__vftable = (CAttributeWidgetFactoryList_vtbl *)&CAttributeWidgetFactoryList::`vftable';
  this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Factories.m_Elements.m_Tree.m_Root = -1;
  this->m_Factories.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Factories.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Factories.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Factories.m_Elements.m_Tree.m_pElements = this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485260
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeTextPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextPanel *__thiscall CAttributeWidgetFactory<CAttributeTextPanel>::Create(
        CAttributeWidgetFactory<CAttributeTextPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeTextPanel *v3; // eax
  CAttributeTextPanel *result; // eax
  CAttributeTextPanel *v5; // esi

  v3 = (CAttributeTextPanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeTextPanel::CAttributeTextPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004852B0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBooleanPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBooleanPanel *__thiscall CAttributeWidgetFactory<CAttributeBooleanPanel>::Create(
        CAttributeWidgetFactory<CAttributeBooleanPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBooleanPanel *v3; // eax
  CAttributeBooleanPanel *result; // eax
  CAttributeBooleanPanel *v5; // esi

  v3 = (CAttributeBooleanPanel *)MemAlloc_Alloc(nSize: 0x2B0u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBooleanPanel::CAttributeBooleanPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485300
// Name: public: static char const __near * CAttributeDmeFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeDmeFilePickerPanel::GetPanelClassName()
{
  return "CAttributeDmeFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00485310
// Name: public: CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDmeFilePickerPanel *__thiscall CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(
        CAttributeDmeFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeDmeFilePickerPanel_vtbl *)&CAttributeDmeFilePickerPanel::`vftable';
  if ( `CAttributeDmeFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeDmeFilePickerPanel");
    v4->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeDmeFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeDmeFilePickerPanel");
    v5->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeDmeFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDmeFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDmeFilePickerPanel");
    v6->pfnClassName = CAttributeDmeFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004853D0
// Name: protected: virtual void CAttributeTextPanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::OnTextChanged(CAttributeTextPanel *this)
{
  CBaseAttributePanel::SetDirty(this, dirty: true);
}

//------------------------------------------------------------------------------
// Address: 0x004853E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeDmeFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeDmeFilePickerPanel::GetMessageMap(CAttributeDmeFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeDmeFilePickerPanel");
  `CAttributeDmeFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485410
// Name: public: virtual struct PanelAnimationMap __near * CAttributeDmeFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeDmeFilePickerPanel::GetAnimMap(CAttributeDmeFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeDmeFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00485420
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeDmeFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeDmeFilePickerPanel::GetKBMap(CAttributeDmeFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeDmeFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDmeFilePickerPanel");
  `CAttributeDmeFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485450
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeDmeFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDmeFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeDmeFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeDmeFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeDmeFilePickerPanel *v3; // eax
  CAttributeDmeFilePickerPanel *result; // eax
  CAttributeDmeFilePickerPanel *v5; // esi

  v3 = (CAttributeDmeFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeDmeFilePickerPanel::CAttributeDmeFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004854A0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBoolChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBoolChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeBoolChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeBoolChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBoolChoicePanel *v3; // eax
  CAttributeBoolChoicePanel *result; // eax
  CAttributeBoolChoicePanel *v5; // esi

  v3 = (CAttributeBoolChoicePanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBoolChoicePanel::CAttributeBoolChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004854F0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeIntChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeIntChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeIntChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeIntChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeIntChoicePanel *v3; // eax
  CAttributeIntChoicePanel *result; // eax
  CAttributeIntChoicePanel *v5; // esi

  v3 = (CAttributeIntChoicePanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeIntChoicePanel::CAttributeIntChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485540
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeStringChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeStringChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeStringChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeStringChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeStringChoicePanel *v3; // eax
  CAttributeStringChoicePanel *result; // eax
  CAttributeStringChoicePanel *v5; // esi

  v3 = (CAttributeStringChoicePanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeStringChoicePanel::CAttributeStringChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485590
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeElementPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPanel *__thiscall CAttributeWidgetFactory<CAttributeElementPanel>::Create(
        CAttributeWidgetFactory<CAttributeElementPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeElementPanel *v3; // eax
  CAttributeElementPanel *result; // eax
  CAttributeElementPanel *v5; // esi

  v3 = (CAttributeElementPanel *)MemAlloc_Alloc(nSize: 0x2A8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeElementPanel::CAttributeElementPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004855E0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeElementPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeElementPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeElementPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeElementPickerPanel *v3; // eax
  CAttributeElementPickerPanel *result; // eax
  CAttributeElementPickerPanel *v5; // esi

  v3 = (CAttributeElementPickerPanel *)MemAlloc_Alloc(nSize: 0x2ACu);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeElementPickerPanel::CAttributeElementPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485630
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeMDLPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeMDLPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeMDLPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeMDLPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeMDLPickerPanel *v3; // eax
  CAttributeMDLPickerPanel *result; // eax
  CAttributeMDLPickerPanel *v5; // esi

  v3 = (CAttributeMDLPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeMDLPickerPanel::CAttributeMDLPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485680
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSequencePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSequencePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSequencePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSequencePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSequencePickerPanel *v3; // eax
  CAttributeSequencePickerPanel *result; // eax
  CAttributeSequencePickerPanel *v5; // esi

  v3 = (CAttributeSequencePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSequencePickerPanel::CAttributeSequencePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004856D0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSoundPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSoundPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSoundPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSoundPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSoundPickerPanel *v3; // eax
  CAttributeSoundPickerPanel *result; // eax
  CAttributeSoundPickerPanel *v5; // esi

  v3 = (CAttributeSoundPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485720
// Name: public: static char const __near * CAttributeBspPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBspPickerPanel::GetPanelClassName()
{
  return "CAttributeBspPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00485730
// Name: public: CAttributeBspPickerPanel::CAttributeBspPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBspPickerPanel *__thiscall CAttributeBspPickerPanel::CAttributeBspPickerPanel(
        CAttributeBspPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeBspPickerPanel_vtbl *)&CAttributeBspPickerPanel::`vftable';
  if ( `CAttributeBspPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBspPickerPanel");
    v4->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeBspPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBspPickerPanel");
    v5->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeBspPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBspPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBspPickerPanel");
    v6->pfnClassName = CAttributeBspPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004857F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBspPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBspPickerPanel::GetMessageMap(CAttributeBspPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBspPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBspPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBspPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBspPickerPanel");
  `CAttributeBspPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485820
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBspPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBspPickerPanel::GetAnimMap(CAttributeBspPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBspPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00485830
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBspPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBspPickerPanel::GetKBMap(CAttributeBspPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBspPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBspPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBspPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBspPickerPanel");
  `CAttributeBspPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485860
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeBspPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBspPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeBspPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeBspPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeBspPickerPanel *v3; // eax
  CAttributeBspPickerPanel *result; // eax
  CAttributeBspPickerPanel *v5; // esi

  v3 = (CAttributeBspPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeBspPickerPanel::CAttributeBspPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004858B0
// Name: public: static char const __near * CAttributeVmtPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeVmtPickerPanel::GetPanelClassName()
{
  return "CAttributeVmtPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004858C0
// Name: public: static void CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x00485950
// Name: public: CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVmtPickerPanel *__thiscall CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(
        CAttributeVmtPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeVmtPickerPanel_vtbl *)&CAttributeVmtPickerPanel::`vftable';
  if ( `CAttributeVmtPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
    v4->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVmtPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeVmtPickerPanel");
    v5->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVmtPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVmtPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVmtPickerPanel");
    v6->pfnClassName = CAttributeVmtPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  CAttributeVmtPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00485A20
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeVmtPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeVmtPickerPanel::GetMessageMap(CAttributeVmtPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeVmtPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVmtPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeVmtPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeVmtPickerPanel");
  `CAttributeVmtPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485A50
// Name: public: virtual struct PanelAnimationMap __near * CAttributeVmtPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeVmtPickerPanel::GetAnimMap(CAttributeVmtPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeVmtPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00485A60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeVmtPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeVmtPickerPanel::GetKBMap(CAttributeVmtPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeVmtPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVmtPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeVmtPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVmtPickerPanel");
  `CAttributeVmtPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485A90
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeVmtPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVmtPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeVmtPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeVmtPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeVmtPickerPanel *v3; // eax
  CAttributeVmtPickerPanel *result; // eax
  CAttributeVmtPickerPanel *v5; // esi

  v3 = (CAttributeVmtPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeVmtPickerPanel::CAttributeVmtPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485AE0
// Name: public: static char const __near * CAttributeVtfPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeVtfPickerPanel::GetPanelClassName()
{
  return "CAttributeVtfPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00485AF0
// Name: public: CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVtfPickerPanel *__thiscall CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(
        CAttributeVtfPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeVtfPickerPanel_vtbl *)&CAttributeVtfPickerPanel::`vftable';
  if ( `CAttributeVtfPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeVtfPickerPanel");
    v4->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVtfPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeVtfPickerPanel");
    v5->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeVtfPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeVtfPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVtfPickerPanel");
    v6->pfnClassName = CAttributeVtfPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00485BB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeVtfPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeVtfPickerPanel::GetMessageMap(CAttributeVtfPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeVtfPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVtfPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeVtfPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeVtfPickerPanel");
  `CAttributeVtfPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485BE0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeVtfPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeVtfPickerPanel::GetAnimMap(CAttributeVtfPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeVtfPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00485BF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeVtfPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeVtfPickerPanel::GetKBMap(CAttributeVtfPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeVtfPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeVtfPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeVtfPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeVtfPickerPanel");
  `CAttributeVtfPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485C50
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeVtfPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeVtfPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeVtfPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeVtfPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeVtfPickerPanel *v3; // eax
  CAttributeVtfPickerPanel *result; // eax
  CAttributeVtfPickerPanel *v5; // esi

  v3 = (CAttributeVtfPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeVtfPickerPanel::CAttributeVtfPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485CA0
// Name: public: static char const __near * CAttributeTgaPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTgaPickerPanel::GetPanelClassName()
{
  return "CAttributeTgaPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00485CB0
// Name: public: CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTgaPickerPanel *__thiscall CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(
        CAttributeTgaPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(this, parent, info);
  this->__vftable = (CAttributeTgaPickerPanel_vtbl *)&CAttributeTgaPickerPanel::`vftable';
  if ( `CAttributeTgaPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTgaPickerPanel");
    v4->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeTgaPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTgaPickerPanel");
    v5->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
  }
  if ( `CAttributeTgaPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTgaPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTgaPickerPanel");
    v6->pfnClassName = CAttributeTgaPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00485D70
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTgaPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTgaPickerPanel::GetMessageMap(CAttributeTgaPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTgaPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTgaPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeTgaPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTgaPickerPanel");
  `CAttributeTgaPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485DA0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTgaPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTgaPickerPanel::GetAnimMap(CAttributeTgaPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTgaPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00485DB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTgaPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTgaPickerPanel::GetKBMap(CAttributeTgaPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTgaPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTgaPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeTgaPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTgaPickerPanel");
  `CAttributeTgaPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485DE0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeTgaPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTgaPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeTgaPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeTgaPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeTgaPickerPanel *v3; // eax
  CAttributeTgaPickerPanel *result; // eax
  CAttributeTgaPickerPanel *v5; // esi

  v3 = (CAttributeTgaPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeTgaPickerPanel::CAttributeTgaPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485E30
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeShaderPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShaderPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeShaderPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeShaderPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeShaderPickerPanel *v3; // eax
  CAttributeShaderPickerPanel *result; // eax
  CAttributeShaderPickerPanel *v5; // esi

  v3 = (CAttributeShaderPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485E80
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSurfacePropertyPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSurfacePropertyPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSurfacePropertyPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSurfacePropertyPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSurfacePropertyPickerPanel *v3; // eax
  CAttributeSurfacePropertyPickerPanel *result; // eax
  CAttributeSurfacePropertyPickerPanel *v5; // esi

  v3 = (CAttributeSurfacePropertyPickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485ED0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeColorPickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeColorPickerPanel *__thiscall CAttributeWidgetFactory<CAttributeColorPickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeColorPickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeColorPickerPanel *v3; // eax
  CAttributeColorPickerPanel *result; // eax
  CAttributeColorPickerPanel *v5; // esi

  v3 = (CAttributeColorPickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeColorPickerPanel::CAttributeColorPickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00485F20
// Name: public: static char const __near * CAttributeAviFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeAviFilePickerPanel::GetPanelClassName()
{
  return "CAttributeAviFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00485F30
// Name: public: CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAviFilePickerPanel *__thiscall CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(
        CAttributeAviFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeAviFilePickerPanel_vtbl *)&CAttributeAviFilePickerPanel::`vftable';
  if ( `CAttributeAviFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeAviFilePickerPanel");
    v4->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeAviFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeAviFilePickerPanel");
    v5->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeAviFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAviFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAviFilePickerPanel");
    v6->pfnClassName = CAttributeAviFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00486000
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeAviFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeAviFilePickerPanel::GetMessageMap(CAttributeAviFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeAviFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeAviFilePickerPanel");
  `CAttributeAviFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486030
// Name: public: virtual struct PanelAnimationMap __near * CAttributeAviFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeAviFilePickerPanel::GetAnimMap(CAttributeAviFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeAviFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00486040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeAviFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeAviFilePickerPanel::GetKBMap(CAttributeAviFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeAviFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAviFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeAviFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAviFilePickerPanel");
  `CAttributeAviFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004860A0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeAviFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAviFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeAviFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeAviFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeAviFilePickerPanel *v3; // eax
  CAttributeAviFilePickerPanel *result; // eax
  CAttributeAviFilePickerPanel *v5; // esi

  v3 = (CAttributeAviFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeAviFilePickerPanel::CAttributeAviFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004860F0
// Name: public: static char const __near * CAttributeShtFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeShtFilePickerPanel::GetPanelClassName()
{
  return "CAttributeShtFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00486100
// Name: public: CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShtFilePickerPanel *__thiscall CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(
        CAttributeShtFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeShtFilePickerPanel_vtbl *)&CAttributeShtFilePickerPanel::`vftable';
  if ( `CAttributeShtFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeShtFilePickerPanel");
    v4->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeShtFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeShtFilePickerPanel");
    v5->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeShtFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShtFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShtFilePickerPanel");
    v6->pfnClassName = CAttributeShtFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004861C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeShtFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeShtFilePickerPanel::GetMessageMap(CAttributeShtFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeShtFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeShtFilePickerPanel");
  `CAttributeShtFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004861F0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeShtFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeShtFilePickerPanel::GetAnimMap(CAttributeShtFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeShtFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00486200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeShtFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeShtFilePickerPanel::GetKBMap(CAttributeShtFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeShtFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShtFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeShtFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShtFilePickerPanel");
  `CAttributeShtFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486230
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeShtFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShtFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeShtFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeShtFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeShtFilePickerPanel *v3; // eax
  CAttributeShtFilePickerPanel *result; // eax
  CAttributeShtFilePickerPanel *v5; // esi

  v3 = (CAttributeShtFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeShtFilePickerPanel::CAttributeShtFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486280
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeDetailTypePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDetailTypePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeDetailTypePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeDetailTypePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeDetailTypePickerPanel *v3; // eax
  CAttributeDetailTypePickerPanel *result; // eax
  CAttributeDetailTypePickerPanel *v5; // esi

  v3 = (CAttributeDetailTypePickerPanel *)MemAlloc_Alloc(nSize: 0x2B4u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004862D0
// Name: public: static char const __near * CAttributeRawFilePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeRawFilePickerPanel::GetPanelClassName()
{
  return "CAttributeRawFilePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004862E0
// Name: public: CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeRawFilePickerPanel *__thiscall CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(
        CAttributeRawFilePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CAttributeFilePickerPanel::CAttributeFilePickerPanel(this, parent, info);
  this->__vftable = (CAttributeRawFilePickerPanel_vtbl *)&CAttributeRawFilePickerPanel::`vftable';
  if ( `CAttributeRawFilePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeRawFilePickerPanel");
    v4->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeRawFilePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeRawFilePickerPanel");
    v5->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeFilePickerPanel");
  }
  if ( `CAttributeRawFilePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeRawFilePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeRawFilePickerPanel");
    v6->pfnClassName = CAttributeRawFilePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeFilePickerPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004863A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeRawFilePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeRawFilePickerPanel::GetMessageMap(CAttributeRawFilePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeRawFilePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeRawFilePickerPanel");
  `CAttributeRawFilePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004863D0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeRawFilePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeRawFilePickerPanel::GetAnimMap(CAttributeRawFilePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeRawFilePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004863E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeRawFilePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeRawFilePickerPanel::GetKBMap(CAttributeRawFilePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeRawFilePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeRawFilePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeRawFilePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeRawFilePickerPanel");
  `CAttributeRawFilePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486410
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeRawFilePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeRawFilePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeRawFilePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeRawFilePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeRawFilePickerPanel *v3; // eax
  CAttributeRawFilePickerPanel *result; // eax
  CAttributeRawFilePickerPanel *v5; // esi

  v3 = (CAttributeRawFilePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeRawFilePickerPanel::CAttributeRawFilePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486460
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeInterpolatorChoicePanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeInterpolatorChoicePanel *__thiscall CAttributeWidgetFactory<CAttributeInterpolatorChoicePanel>::Create(
        CAttributeWidgetFactory<CAttributeInterpolatorChoicePanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeInterpolatorChoicePanel *v3; // eax
  CAttributeInterpolatorChoicePanel *result; // eax
  CAttributeInterpolatorChoicePanel *v5; // esi

  v3 = (CAttributeInterpolatorChoicePanel *)MemAlloc_Alloc(nSize: 0x2B0u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeInterpolatorChoicePanel::CAttributeInterpolatorChoicePanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004864B0
// Name: public: virtual class vgui::Panel __near * CAttributeWidgetFactory<class CAttributeSheetSequencePickerPanel>::Create(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSheetSequencePickerPanel *__thiscall CAttributeWidgetFactory<CAttributeSheetSequencePickerPanel>::Create(
        CAttributeWidgetFactory<CAttributeSheetSequencePickerPanel> *this,
        vgui::Panel *pParent,
        const AttributeWidgetInfo_t *info)
{
  CAttributeSheetSequencePickerPanel *v3; // eax
  CAttributeSheetSequencePickerPanel *result; // eax
  CAttributeSheetSequencePickerPanel *v5; // esi

  v3 = (CAttributeSheetSequencePickerPanel *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v3 == nullptr )
    return nullptr;
  result = CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(this: v3, parent: pParent, info);
  v5 = result;
  if ( result != nullptr )
  {
    result->PostConstructor(this: result);
    return v5;
  }
  return result;
}

} // namespace sceneviewer
