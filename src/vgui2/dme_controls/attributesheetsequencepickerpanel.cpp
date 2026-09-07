// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributesheetsequencepickerpanel.cpp
// Functions: 33
// ============================================================

#include "vgui2\dme_controls\attributesheetsequencepickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004514D0
// Name: public: class CDmElement __near * CAttributeReferenceIterator::FilterReference<class CDmElement>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAttributeReferenceIterator::FilterReference<CDmElement>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *result; // eax
  CDmElement *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_18;
    case TD_DEEP:
      goto $LN11_12;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_12:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_18:
      m_pOwner = v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmElement::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472800
// Name: public: static char const __near * CAttributeSheetSequencePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSheetSequencePickerPanel::GetPanelClassName()
{
  return "CAttributeSheetSequencePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00472810
// Name: public: static char const __near * CNotifyMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNotifyMenuButton::GetPanelClassName()
{
  return "CNotifyMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00472820
// Name: public: virtual void CAttributeSheetSequencePickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::PerformLayout(CAttributeSheetSequencePickerPanel *this)
{
  int y; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int w; // [esp+10h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetBounds(this: this->m_pType, &x, &y, wide: &w, tall: &h);
  vgui::Panel::SetWide(this: this->m_pType, wide: w - 25);
  vgui::Panel::SetBounds(this: this->m_pSequenceSelection, x: x + w - 25, y, wide: 25, tall: h - 2);
}

//------------------------------------------------------------------------------
// Address: 0x004728A0
// Name: public: CNotifyMenuButton::CNotifyMenuButton(class CAttributeSheetSequencePickerPanel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNotifyMenuButton *__thiscall CNotifyMenuButton::CNotifyMenuButton(
        CNotifyMenuButton *this,
        CAttributeSheetSequencePickerPanel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CNotifyMenuButton_vtbl *)&CNotifyMenuButton::`vftable';
  if ( `CNotifyMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CNotifyMenuButton");
    v5->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuButton");
  }
  if ( `CNotifyMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CNotifyMenuButton");
    v6->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuButton");
  }
  if ( `CNotifyMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CNotifyMenuButton");
    v7->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuButton");
  }
  this->m_pParent = parent;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00472970
// Name: public: virtual struct vgui::PanelMessageMap __near * CNotifyMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNotifyMenuButton::GetMessageMap(CNotifyMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNotifyMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNotifyMenuButton::GetMessageMap'::`2'::s_pMap;
  `CNotifyMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNotifyMenuButton");
  `CNotifyMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004729A0
// Name: public: virtual struct PanelAnimationMap __near * CNotifyMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNotifyMenuButton::GetAnimMap(CNotifyMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CNotifyMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x004729B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNotifyMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNotifyMenuButton::GetKBMap(CNotifyMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNotifyMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNotifyMenuButton::GetKBMap'::`2'::s_pMap;
  `CNotifyMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNotifyMenuButton");
  `CNotifyMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004729E0
// Name: public: class CDmeParticleSystemDefinition __near * CAttributeReferenceIterator::FilterReference<class CDmeParticleSystemDefinition>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__thiscall CAttributeReferenceIterator::FilterReference<CDmeParticleSystemDefinition>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeParticleSystemDefinition *result; // eax
  CDmeParticleSystemDefinition *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_20;
    case TD_DEEP:
      goto $LN11_13;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_13:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_20:
      m_pOwner = (CDmeParticleSystemDefinition *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeParticleSystemDefinition::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472B20
// Name: public: void CAttributeSheetSequencePickerPanel::UpdateSheetPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::UpdateSheetPanel(CAttributeSheetSequencePickerPanel *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // esi
  CUtlSymbolLarge *v4; // eax
  CDmeParticleSystemDefinition *Referring; // eax
  const char *v6; // eax
  _BYTE v7[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "material");
  if ( this->m_bIsSecondView )
  {
    CSheetSequencePanel::SetSecondSequenceView(this: this->m_pSheetPanel, bIsSecondSequenceView: true);
    this->m_pSequenceSelection->SetText_2(this: this->m_pSequenceSelection, a2: "sq2");
  }
  if ( Attribute != nullptr
    || (v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v7, a3: "initializers"),
        (Referring = FindReferringElement<CDmeParticleSystemDefinition>(
                       pElement: v2,
                       symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
                       bMustBeInSameFile: true,
                       depth: TD_ALL)) != nullptr)
    && (Attribute = CDmElement::FindAttribute(this: Referring, pAttributeName: "material")) != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v6 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      CSheetSequencePanel::SetFromMaterialName(this: this->m_pSheetPanel, pMaterialName: v6);
    }
    else
    {
      CSheetSequencePanel::SetFromMaterialName(this: this->m_pSheetPanel, pMaterialName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472C10
// Name: public: static void CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(
        int a1@<ebp>)
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
  if ( !`CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SheetSequenceSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "nSequenceNumber";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472CB0
// Name: public: virtual void CNotifyMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyMenuButton::OnShowMenu(CNotifyMenuButton *this, vgui::Menu *menu)
{
  CAttributeSheetSequencePickerPanel *m_pParent; // ecx

  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr )
    CAttributeSheetSequencePickerPanel::UpdateSheetPanel(this: m_pParent);
}

//------------------------------------------------------------------------------
// Address: 0x00472CD0
// Name: private: virtual void CAttributeSheetSequencePickerPanel::OnSheetSequenceSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::OnSheetSequenceSelected(
        CAttributeSheetSequencePickerPanel *this,
        int nSequenceNumber)
{
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v4; // edi

  m_pNotify = this->m_pNotify;
  v4 = nullptr;
  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Select Sheet Sequence", a3: "Select Sheet Sequence", a4: 0);
  if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
    v4 = m_pNotify;
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Select Sheet Sequence", a3: 0, a4: 256);
  CBaseAttributePanel::SetAttributeValue<int>(this, value: &nSequenceNumber);
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v4 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00472D80
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSheetSequencePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSheetSequencePickerPanel::GetMessageMap(
        CAttributeSheetSequencePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
  `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472DB0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSheetSequencePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSheetSequencePickerPanel::GetAnimMap(CAttributeSheetSequencePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSheetSequencePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00472DC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSheetSequencePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSheetSequencePickerPanel::GetKBMap(
        CAttributeSheetSequencePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSheetSequencePickerPanel");
  `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472DF0
// Name: public: CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSheetSequencePickerPanel *__thiscall CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(
        CAttributeSheetSequencePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmeEditorAttributeInfo *m_pEditorInfo; // ecx
  const char *WidgetName; // eax
  CSheetSequencePanel *v9; // eax
  CSheetSequencePanel *v10; // eax
  CNotifyMenuButton *v11; // eax
  CNotifyMenuButton *v12; // eax
  CSheetSequencePanel *m_pSheetPanel; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeSheetSequencePickerPanel_vtbl *)&CAttributeSheetSequencePickerPanel::`vftable';
  if ( `CAttributeSheetSequencePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
    v4->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeSheetSequencePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSheetSequencePickerPanel");
    v5->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeSheetSequencePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSheetSequencePickerPanel");
    v6->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(a1: (int)&savedregs);
  m_pEditorInfo = info->m_pEditorInfo;
  if ( m_pEditorInfo != nullptr )
  {
    WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: m_pEditorInfo);
    this->m_bIsSecondView = _V_stricmp(s1: WidgetName, s2: "sheetsequencepicker_second") == 0;
  }
  else
  {
    this->m_bIsSecondView = false;
  }
  v9 = (CSheetSequencePanel *)MemAlloc_Alloc(nSize: 0x438u);
  if ( v9 != nullptr )
    v10 = CSheetSequencePanel::CSheetSequencePanel(this: v9, pParent: this, pPanelName: "sheetsequencepanel");
  else
    v10 = nullptr;
  this->m_pSheetPanel = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (CNotifyMenuButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v11 != nullptr )
    v12 = CNotifyMenuButton::CNotifyMenuButton(this: v11, parent: this, panelName: "SequenceSelection", text: "seq");
  else
    v12 = nullptr;
  m_pSheetPanel = this->m_pSheetPanel;
  this->m_pSequenceSelection = v12;
  v12->SetMenu(this: v12, a2: m_pSheetPanel);
  this->m_pSheetPanel->AddActionSignalTarget_2(this: this->m_pSheetPanel, a2: this);
  CAttributeSheetSequencePickerPanel::UpdateSheetPanel(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483200
// Name: public: class CDmeChannelsClip __near * CAttributeReferenceIterator::FilterReference<class CDmeChannelsClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannelsClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeChannelsClip *result; // eax
  CDmeChannelsClip *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_23;
    case TD_DEEP:
      goto $LN11_14;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_14:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_23:
      m_pOwner = (CDmeChannelsClip *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeChannelsClip::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00491FE0
// Name: public: class CDmeAnimationSet __near * CAttributeReferenceIterator::FilterReference<class CDmeAnimationSet>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CAttributeReferenceIterator::FilterReference<CDmeAnimationSet>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeAnimationSet *result; // eax
  CDmeAnimationSet *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_25;
    case TD_DEEP:
      goto $LN11_15;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_15:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_25:
      m_pOwner = (CDmeAnimationSet *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeAnimationSet::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F8F20
// Name: public: class CDmeDag __near * CAttributeReferenceIterator::FilterReference<class CDmeDag>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAttributeReferenceIterator::FilterReference<CDmeDag>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeDag *result; // eax
  CDmeDag *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_43;
    case TD_DEEP:
      goto $LN11_19;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_19:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_43:
      m_pOwner = (CDmeDag *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeDag::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00501AB0
// Name: public: class CDmeChannel __near * CAttributeReferenceIterator::FilterReference<class CDmeChannel>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannel>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeChannel *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_44;
      case TD_DEEP:
        goto $LN11_20;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_20:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_44:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeChannel::m_classType) )
          return nullptr;
        result = (CDmeChannel *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00501B60
// Name: public: class CDmeConstraintSlave __near * CAttributeReferenceIterator::FilterReference<class CDmeConstraintSlave>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeConstraintSlave *__thiscall CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeConstraintSlave *result; // eax
  CDmeConstraintSlave *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_45;
    case TD_DEEP:
      goto $LN11_21;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_21:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_45:
      m_pOwner = (CDmeConstraintSlave *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050F120
// Name: public: class CDmeClip __near * CAttributeReferenceIterator::FilterReference<class CDmeClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeClip *result; // eax
  CDmeClip *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_46;
    case TD_DEEP:
      goto $LN11_22;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_22:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_46:
      m_pOwner = (CDmeClip *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeClip::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BC1D0
// Name: public: class CDmeControlGroup __near * CAttributeReferenceIterator::FilterReference<class CDmeControlGroup>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeControlGroup *result; // eax
  CDmeControlGroup *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_48;
    case TD_DEEP:
      goto $LN11_36;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_36:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_48:
      m_pOwner = (CDmeControlGroup *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeControlGroup::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BE090
// Name: public: class CDmeRigBaseConstraintOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeRigBaseConstraintOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeRigBaseConstraintOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeRigBaseConstraintOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeRigBaseConstraintOperator *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_49;
      case TD_DEEP:
        goto $LN11_37;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_37:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_49:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeRigBaseConstraintOperator::m_classType) )
          return nullptr;
        result = (CDmeRigBaseConstraintOperator *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C2CA0
// Name: public: class CDmeFlexRules __near * CAttributeReferenceIterator::FilterReference<class CDmeFlexRules>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeFlexRules *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_50;
      case TD_DEEP:
        goto $LN11_38;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_38:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_50:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeFlexRules::m_classType) )
          return nullptr;
        result = (CDmeFlexRules *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C6F30
// Name: public: class CDmeOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeOperator *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_51;
      case TD_DEEP:
        goto $LN11_39;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_39:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_51:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          return nullptr;
        result = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00611120
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x00611140
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00611170
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x00611180
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472A90
// Name: class CDmeParticleSystemDefinition __near * FindReferringElement<class CDmeParticleSystemDefinition>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__cdecl FindReferringElement<CDmeParticleSystemDefinition>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeParticleSystemDefinition *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeParticleSystemDefinition>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C6FE0
// Name: class CDmeOperator __near * FindReferringElement<class CDmeOperator>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeOperator *__cdecl FindReferringElement<CDmeOperator>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeOperator *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeOperator>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104669C0
// Name: public: class CDmElement __near * CAttributeReferenceIterator::FilterReference<class CDmElement>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAttributeReferenceIterator::FilterReference<CDmElement>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *result; // eax
  CDmElement *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_127;
    case TD_DEEP:
      goto $LN11_92;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_92:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_127:
      m_pOwner = v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmElement::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104870F0
// Name: public: class CDmeChannelsClip __near * CAttributeReferenceIterator::FilterReference<class CDmeChannelsClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannelsClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeChannelsClip *result; // eax
  CDmeChannelsClip *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_129;
    case TD_DEEP:
      goto $LN11_93;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_93:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_129:
      m_pOwner = (CDmeChannelsClip *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeChannelsClip::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10495D30
// Name: public: static char const __near * CAttributeSheetSequencePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSheetSequencePickerPanel::GetPanelClassName()
{
  return "CAttributeSheetSequencePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10495D40
// Name: public: static char const __near * CNotifyMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNotifyMenuButton::GetPanelClassName()
{
  return "CNotifyMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x10495D50
// Name: public: virtual void CAttributeSheetSequencePickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::PerformLayout(CAttributeSheetSequencePickerPanel *this)
{
  int y; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int w; // [esp+10h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetBounds(this: this->m_pType, &x, &y, wide: &w, tall: &h);
  vgui::Panel::SetWide(this: this->m_pType, wide: w - 25);
  vgui::Panel::SetBounds(this: this->m_pSequenceSelection, x: x + w - 25, y, wide: 25, tall: h - 2);
}

//------------------------------------------------------------------------------
// Address: 0x10495DC0
// Name: public: CNotifyMenuButton::CNotifyMenuButton(class CAttributeSheetSequencePickerPanel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNotifyMenuButton *__thiscall CNotifyMenuButton::CNotifyMenuButton(
        CNotifyMenuButton *this,
        CAttributeSheetSequencePickerPanel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CNotifyMenuButton_vtbl *)&CNotifyMenuButton::`vftable';
  if ( `CNotifyMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CNotifyMenuButton");
    v5->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuButton");
  }
  if ( `CNotifyMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CNotifyMenuButton");
    v6->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuButton");
  }
  if ( `CNotifyMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CNotifyMenuButton");
    v7->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuButton");
  }
  this->m_pParent = parent;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10495E90
// Name: public: virtual struct vgui::PanelMessageMap __near * CNotifyMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNotifyMenuButton::GetMessageMap(CNotifyMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNotifyMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNotifyMenuButton::GetMessageMap'::`2'::s_pMap;
  `CNotifyMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNotifyMenuButton");
  `CNotifyMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10495EC0
// Name: public: virtual struct PanelAnimationMap __near * CNotifyMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNotifyMenuButton::GetAnimMap(CNotifyMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CNotifyMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x10495ED0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNotifyMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNotifyMenuButton::GetKBMap(CNotifyMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNotifyMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNotifyMenuButton::GetKBMap'::`2'::s_pMap;
  `CNotifyMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNotifyMenuButton");
  `CNotifyMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10495F30
// Name: public: class CDmeParticleSystemDefinition __near * CAttributeReferenceIterator::FilterReference<class CDmeParticleSystemDefinition>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__thiscall CAttributeReferenceIterator::FilterReference<CDmeParticleSystemDefinition>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeParticleSystemDefinition *result; // eax
  CDmeParticleSystemDefinition *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_130;
    case TD_DEEP:
      goto $LN11_94;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_94:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_130:
      m_pOwner = (CDmeParticleSystemDefinition *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeParticleSystemDefinition::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10496070
// Name: public: void CAttributeSheetSequencePickerPanel::UpdateSheetPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::UpdateSheetPanel(CAttributeSheetSequencePickerPanel *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // esi
  CUtlSymbolLarge *v4; // eax
  CDmeParticleSystemDefinition *Referring; // eax
  const char *v6; // eax
  _BYTE v7[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "material");
  if ( this->m_bIsSecondView )
  {
    CSheetSequencePanel::SetSecondSequenceView(this: this->m_pSheetPanel, bIsSecondSequenceView: true);
    this->m_pSequenceSelection->SetText(this: this->m_pSequenceSelection, a2: "sq2");
  }
  if ( Attribute != nullptr
    || (v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v7, a3: "initializers"),
        (Referring = FindReferringElement<CDmeParticleSystemDefinition>(
                       pElement: v2,
                       symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
                       bMustBeInSameFile: true,
                       depth: TD_ALL)) != nullptr)
    && (Attribute = CDmElement::FindAttribute(this: Referring, pAttributeName: "material")) != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v6 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v6 == (const char *)-1 )
        v6 = &var;
      CSheetSequencePanel::SetFromMaterialName(this: this->m_pSheetPanel, pMaterialName: v6);
    }
    else
    {
      CSheetSequencePanel::SetFromMaterialName(this: this->m_pSheetPanel, pMaterialName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10496160
// Name: public: static void CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(
        int a1@<ebp>)
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
  if ( !`CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SheetSequenceSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "nSequenceNumber";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10496200
// Name: public: virtual void CNotifyMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyMenuButton::OnShowMenu(CNotifyMenuButton *this, vgui::Menu *menu)
{
  CAttributeSheetSequencePickerPanel *m_pParent; // ecx

  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr )
    CAttributeSheetSequencePickerPanel::UpdateSheetPanel(this: m_pParent);
}

//------------------------------------------------------------------------------
// Address: 0x10496220
// Name: private: virtual void CAttributeSheetSequencePickerPanel::OnSheetSequenceSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::OnSheetSequenceSelected(
        CAttributeSheetSequencePickerPanel *this,
        int nSequenceNumber)
{
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v4; // edi

  m_pNotify = this->m_pNotify;
  v4 = nullptr;
  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Select Sheet Sequence", a3: "Select Sheet Sequence", a4: 0);
  if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
    v4 = m_pNotify;
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Select Sheet Sequence", a3: 0, a4: 256);
  CBaseAttributePanel::SetAttributeValue<int>(this, value: &nSequenceNumber);
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v4 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104962D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSheetSequencePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSheetSequencePickerPanel::GetMessageMap(
        CAttributeSheetSequencePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
  `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10496300
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSheetSequencePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSheetSequencePickerPanel::GetAnimMap(CAttributeSheetSequencePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSheetSequencePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10496310
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSheetSequencePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSheetSequencePickerPanel::GetKBMap(
        CAttributeSheetSequencePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSheetSequencePickerPanel");
  `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10496340
// Name: public: CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSheetSequencePickerPanel *__thiscall CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(
        CAttributeSheetSequencePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmeEditorAttributeInfo *m_pEditorInfo; // ecx
  const char *WidgetName; // eax
  CSheetSequencePanel *v9; // eax
  CSheetSequencePanel *v10; // eax
  CNotifyMenuButton *v11; // eax
  CNotifyMenuButton *v12; // eax
  CSheetSequencePanel *m_pSheetPanel; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeSheetSequencePickerPanel_vtbl *)&CAttributeSheetSequencePickerPanel::`vftable';
  if ( `CAttributeSheetSequencePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
    v4->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeSheetSequencePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSheetSequencePickerPanel");
    v5->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeSheetSequencePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSheetSequencePickerPanel");
    v6->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(a1: (int)&savedregs);
  m_pEditorInfo = info->m_pEditorInfo;
  if ( m_pEditorInfo != nullptr )
  {
    WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: m_pEditorInfo);
    this->m_bIsSecondView = _V_stricmp(s1: WidgetName, s2: "sheetsequencepicker_second") == 0;
  }
  else
  {
    this->m_bIsSecondView = false;
  }
  v9 = (CSheetSequencePanel *)operator new(nSize: 0x438u);
  if ( v9 != nullptr )
    v10 = CSheetSequencePanel::CSheetSequencePanel(this: v9, pParent: this, pPanelName: "sheetsequencepanel");
  else
    v10 = nullptr;
  this->m_pSheetPanel = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (CNotifyMenuButton *)operator new(nSize: 0x21Cu);
  if ( v11 != nullptr )
    v12 = CNotifyMenuButton::CNotifyMenuButton(this: v11, parent: this, panelName: "SequenceSelection", text: "seq");
  else
    v12 = nullptr;
  m_pSheetPanel = this->m_pSheetPanel;
  this->m_pSequenceSelection = v12;
  v12->SetMenu(this: v12, a2: m_pSheetPanel);
  this->m_pSheetPanel->AddActionSignalTarget_2(this: this->m_pSheetPanel, a2: this);
  CAttributeSheetSequencePickerPanel::UpdateSheetPanel(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1049E3B0
// Name: public: class CDmeAnimationSet __near * CAttributeReferenceIterator::FilterReference<class CDmeAnimationSet>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CAttributeReferenceIterator::FilterReference<CDmeAnimationSet>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeAnimationSet *result; // eax
  CDmeAnimationSet *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_131;
    case TD_DEEP:
      goto $LN11_95;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_95:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_131:
      m_pOwner = (CDmeAnimationSet *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeAnimationSet::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D8DA0
// Name: public: class CDmeChannel __near * CAttributeReferenceIterator::FilterReference<class CDmeChannel>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannel>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeChannel *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_143;
      case TD_DEEP:
        goto $LN11_102;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_102:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_143:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeChannel::m_classType) )
          return nullptr;
        result = (CDmeChannel *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D8E50
// Name: public: class CDmeDag __near * CAttributeReferenceIterator::FilterReference<class CDmeDag>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAttributeReferenceIterator::FilterReference<CDmeDag>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeDag *result; // eax
  CDmeDag *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_144;
    case TD_DEEP:
      goto $LN11_103;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_103:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_144:
      m_pOwner = (CDmeDag *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeDag::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D8F00
// Name: public: class CDmeConstraintSlave __near * CAttributeReferenceIterator::FilterReference<class CDmeConstraintSlave>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeConstraintSlave *__thiscall CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeConstraintSlave *result; // eax
  CDmeConstraintSlave *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_145;
    case TD_DEEP:
      goto $LN11_104;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_104:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_145:
      m_pOwner = (CDmeConstraintSlave *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104EFD90
// Name: public: class CDmeFlexRules __near * CAttributeReferenceIterator::FilterReference<class CDmeFlexRules>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeFlexRules *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_146;
      case TD_DEEP:
        goto $LN11_105;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_105:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_146:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeFlexRules::m_classType) )
          return nullptr;
        result = (CDmeFlexRules *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104F1880
// Name: public: class CDmeControlGroup __near * CAttributeReferenceIterator::FilterReference<class CDmeControlGroup>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeControlGroup *result; // eax
  CDmeControlGroup *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_147;
    case TD_DEEP:
      goto $LN11_106;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_106:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_147:
      m_pOwner = (CDmeControlGroup *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeControlGroup::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1058F4E0
// Name: public: class CDmeRigBaseConstraintOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeRigBaseConstraintOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeRigBaseConstraintOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeRigBaseConstraintOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeRigBaseConstraintOperator *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_149;
      case TD_DEEP:
        goto $LN11_120;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_120:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_149:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeRigBaseConstraintOperator::m_classType) )
          return nullptr;
        result = (CDmeRigBaseConstraintOperator *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10593F70
// Name: public: class CDmeOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeOperator *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_150;
      case TD_DEEP:
        goto $LN11_121;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_121:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_150:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          return nullptr;
        result = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10596660
// Name: public: class CDmeClip __near * CAttributeReferenceIterator::FilterReference<class CDmeClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeClip *result; // eax
  CDmeClip *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_151;
    case TD_DEEP:
      goto $LN11_122;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_122:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_151:
      m_pOwner = (CDmeClip *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeClip::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10495FE0
// Name: class CDmeParticleSystemDefinition __near * FindReferringElement<class CDmeParticleSystemDefinition>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__cdecl FindReferringElement<CDmeParticleSystemDefinition>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeParticleSystemDefinition *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeParticleSystemDefinition>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10594020
// Name: class CDmeOperator __near * FindReferringElement<class CDmeOperator>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeOperator *__cdecl FindReferringElement<CDmeOperator>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeOperator *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeOperator>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004598A0
// Name: public: class CDmElement __near * CAttributeReferenceIterator::FilterReference<class CDmElement>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAttributeReferenceIterator::FilterReference<CDmElement>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmElement *result; // eax
  CDmElement *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_19;
    case TD_DEEP:
      goto $LN11_12;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_12:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_19:
      v7 = *(CDmElement **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmElement::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00478A80
// Name: public: class CDmeChannelsClip __near * CAttributeReferenceIterator::FilterReference<class CDmeChannelsClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannelsClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeChannelsClip *result; // eax
  CDmeChannelsClip *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_21;
    case TD_DEEP:
      goto $LN11_13;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_13:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_21:
      v7 = *(CDmeChannelsClip **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeChannelsClip::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490300
// Name: public: class CDmeAnimationSet __near * CAttributeReferenceIterator::FilterReference<class CDmeAnimationSet>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CAttributeReferenceIterator::FilterReference<CDmeAnimationSet>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeAnimationSet *result; // eax
  CDmeAnimationSet *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_25;
    case TD_DEEP:
      goto $LN11_14;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_14:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_25:
      v7 = *(CDmeAnimationSet **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeAnimationSet::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C3F0
// Name: public: static char const __near * CAttributeSheetSequencePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSheetSequencePickerPanel::GetPanelClassName()
{
  return "CAttributeSheetSequencePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049C400
// Name: public: static char const __near * CNotifyMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNotifyMenuButton::GetPanelClassName()
{
  return "CNotifyMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x0049C410
// Name: public: virtual void CAttributeSheetSequencePickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::PerformLayout(CAttributeSheetSequencePickerPanel *this)
{
  int y; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int w; // [esp+10h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetBounds(this: this->m_pType, &x, &y, wide: &w, tall: &h);
  vgui::Panel::SetWide(this: this->m_pType, wide: w - 25);
  vgui::Panel::SetBounds(this: this->m_pSequenceSelection, x: x + w - 25, y, wide: 25, tall: h - 2);
}

//------------------------------------------------------------------------------
// Address: 0x0049C490
// Name: public: CNotifyMenuButton::CNotifyMenuButton(class CAttributeSheetSequencePickerPanel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNotifyMenuButton *__thiscall CNotifyMenuButton::CNotifyMenuButton(
        CNotifyMenuButton *this,
        CAttributeSheetSequencePickerPanel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CNotifyMenuButton_vtbl *)&CNotifyMenuButton::`vftable';
  if ( `CNotifyMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CNotifyMenuButton");
    v5->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuButton");
  }
  if ( `CNotifyMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CNotifyMenuButton");
    v6->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuButton");
  }
  if ( `CNotifyMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNotifyMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CNotifyMenuButton");
    v7->pfnClassName = CNotifyMenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuButton");
  }
  this->m_pParent = parent;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049C560
// Name: public: virtual struct vgui::PanelMessageMap __near * CNotifyMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNotifyMenuButton::GetMessageMap(CNotifyMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNotifyMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNotifyMenuButton::GetMessageMap'::`2'::s_pMap;
  `CNotifyMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNotifyMenuButton");
  `CNotifyMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C590
// Name: public: virtual struct PanelAnimationMap __near * CNotifyMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNotifyMenuButton::GetAnimMap(CNotifyMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CNotifyMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x0049C5A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNotifyMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNotifyMenuButton::GetKBMap(CNotifyMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNotifyMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNotifyMenuButton::GetKBMap'::`2'::s_pMap;
  `CNotifyMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNotifyMenuButton");
  `CNotifyMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C600
// Name: public: class CDmeParticleSystemDefinition __near * CAttributeReferenceIterator::FilterReference<class CDmeParticleSystemDefinition>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__thiscall CAttributeReferenceIterator::FilterReference<CDmeParticleSystemDefinition>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeParticleSystemDefinition *result; // eax
  CDmeParticleSystemDefinition *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_29;
    case TD_DEEP:
      goto $LN11_15;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_15:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_29:
      v7 = *(CDmeParticleSystemDefinition **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeParticleSystemDefinition::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C740
// Name: public: void CAttributeSheetSequencePickerPanel::UpdateSheetPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::UpdateSheetPanel(CAttributeSheetSequencePickerPanel *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // esi
  CUtlSymbolLarge *v4; // eax
  CDmeParticleSystemDefinition *Referring; // eax
  const char *m_Id; // eax
  _BYTE v7[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "material");
  if ( this->m_bIsSecondView )
  {
    CSheetSequencePanel::SetSecondSequenceView(this: this->m_pSheetPanel, bIsSecondSequenceView: true);
    this->m_pSequenceSelection->SetText_2(this: this->m_pSequenceSelection, a2: "sq2");
  }
  if ( Attribute != nullptr
    || (v4 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v7,
                                  a3: "initializers"),
        (Referring = FindReferringElement<CDmeParticleSystemDefinition>(
                       pElement: v2,
                       symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
                       bMustBeInSameFile: true,
                       depth: TD_ALL)) != nullptr)
    && (Attribute = CDmElement::FindAttribute(this: Referring, pAttributeName: "material")) != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = defaultValue;
      CSheetSequencePanel::SetFromMaterialName(this: this->m_pSheetPanel, pMaterialName: m_Id);
    }
    else
    {
      CSheetSequencePanel::SetFromMaterialName(this: this->m_pSheetPanel, pMaterialName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C830
// Name: public: static void CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(
        int a1@<ebp>)
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
  if ( !`CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SheetSequenceSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "nSequenceNumber";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C8D0
// Name: public: virtual void CNotifyMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyMenuButton::OnShowMenu(CNotifyMenuButton *this, vgui::Menu *menu)
{
  CAttributeSheetSequencePickerPanel *m_pParent; // ecx

  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr )
    CAttributeSheetSequencePickerPanel::UpdateSheetPanel(this: m_pParent);
}

//------------------------------------------------------------------------------
// Address: 0x0049C8F0
// Name: private: virtual void CAttributeSheetSequencePickerPanel::OnSheetSequenceSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSheetSequencePickerPanel::OnSheetSequenceSelected(
        CAttributeSheetSequencePickerPanel *this,
        int nSequenceNumber)
{
  IDmNotify *m_pNotify; // ebx
  IDmNotify *v4; // edi

  m_pNotify = this->m_pNotify;
  v4 = nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 256))(
    a1: g_pDataModel.u,
    a2: "Select Sheet Sequence",
    a3: "Select Sheet Sequence",
    a4: 0);
  if ( m_pNotify != nullptr
    && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 444))(
         a1: g_pDataModel.u,
         a2: m_pNotify) != 0 )
  {
    v4 = m_pNotify;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 460))(
    a1: g_pDataModel.u,
    a2: "Select Sheet Sequence",
    a3: 0,
    a4: 256);
  CBaseAttributePanel::SetAttributeValue<int>(this, value: &nSequenceNumber);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
  if ( v4 != nullptr )
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
      a1: g_pDataModel.u,
      a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0049C9A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSheetSequencePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSheetSequencePickerPanel::GetMessageMap(
        CAttributeSheetSequencePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
  `CAttributeSheetSequencePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049C9D0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSheetSequencePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSheetSequencePickerPanel::GetAnimMap(CAttributeSheetSequencePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSheetSequencePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049C9E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSheetSequencePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSheetSequencePickerPanel::GetKBMap(
        CAttributeSheetSequencePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSheetSequencePickerPanel");
  `CAttributeSheetSequencePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049CA10
// Name: public: CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSheetSequencePickerPanel *__thiscall CAttributeSheetSequencePickerPanel::CAttributeSheetSequencePickerPanel(
        CAttributeSheetSequencePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmeEditorAttributeInfo *m_pEditorInfo; // ecx
  const char *WidgetName; // eax
  CSheetSequencePanel *v9; // eax
  CSheetSequencePanel *v10; // eax
  CNotifyMenuButton *v11; // eax
  CNotifyMenuButton *v12; // eax
  CSheetSequencePanel *m_pSheetPanel; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeSheetSequencePickerPanel_vtbl *)&CAttributeSheetSequencePickerPanel::`vftable';
  if ( `CAttributeSheetSequencePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSheetSequencePickerPanel");
    v4->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeSheetSequencePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSheetSequencePickerPanel");
    v5->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeSheetSequencePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSheetSequencePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSheetSequencePickerPanel");
    v6->pfnClassName = CAttributeSheetSequencePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeSheetSequencePickerPanel::PanelMessageFunc_OnSheetSequenceSelected::InitVar(a1: (int)&savedregs);
  m_pEditorInfo = info->m_pEditorInfo;
  if ( m_pEditorInfo != nullptr )
  {
    WidgetName = CDmeEditorAttributeInfo::GetWidgetName(this: m_pEditorInfo);
    this->m_bIsSecondView = _V_stricmp(s1: WidgetName, s2: "sheetsequencepicker_second") == 0;
  }
  else
  {
    this->m_bIsSecondView = false;
  }
  v9 = (CSheetSequencePanel *)MemAlloc_Alloc(nSize: 0x438u);
  if ( v9 != nullptr )
    v10 = CSheetSequencePanel::CSheetSequencePanel(this: v9, pParent: this, pPanelName: "sheetsequencepanel");
  else
    v10 = nullptr;
  this->m_pSheetPanel = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (CNotifyMenuButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v11 != nullptr )
    v12 = CNotifyMenuButton::CNotifyMenuButton(this: v11, parent: this, panelName: "SequenceSelection", text: "seq");
  else
    v12 = nullptr;
  m_pSheetPanel = this->m_pSheetPanel;
  this->m_pSequenceSelection = v12;
  v12->SetMenu(this: v12, a2: m_pSheetPanel);
  this->m_pSheetPanel->AddActionSignalTarget_2(this: this->m_pSheetPanel, a2: this);
  CAttributeSheetSequencePickerPanel::UpdateSheetPanel(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00514B10
// Name: public: class CDmeDag __near * CAttributeReferenceIterator::FilterReference<class CDmeDag>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAttributeReferenceIterator::FilterReference<CDmeDag>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeDag *result; // eax
  CDmeDag *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_46;
    case TD_DEEP:
      goto $LN11_20;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_20:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_46:
      v7 = *(CDmeDag **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeDag::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051DC90
// Name: public: class CDmeChannel __near * CAttributeReferenceIterator::FilterReference<class CDmeChannel>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannel>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeChannel *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_47;
      case TD_DEEP:
        goto $LN11_21;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_21:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_47:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeChannel::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeChannel *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0051E440
// Name: public: class CDmeConstraintSlave __near * CAttributeReferenceIterator::FilterReference<class CDmeConstraintSlave>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeConstraintSlave *__thiscall CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeConstraintSlave *result; // eax
  CDmeConstraintSlave *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_48;
    case TD_DEEP:
      goto $LN11_22;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_22:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_48:
      v7 = *(CDmeConstraintSlave **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeConstraintSlave::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051FE10
// Name: public: class CDmeMayaMakefile __near * CAttributeReferenceIterator::FilterReference<class CDmeMayaMakefile>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeMayaMakefile *__thiscall CAttributeReferenceIterator::FilterReference<CDmeMayaMakefile>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeMayaMakefile *result; // eax
  CDmeMayaMakefile *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_49;
    case TD_DEEP:
      goto $LN11_23;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_23:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_49:
      v7 = *(CDmeMayaMakefile **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeMayaMakefile::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D8750
// Name: public: class CDmeClip __near * CAttributeReferenceIterator::FilterReference<class CDmeClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeClip *result; // eax
  CDmeClip *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_52;
    case TD_DEEP:
      goto $LN11_38;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_38:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_52:
      v7 = *(CDmeClip **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeClip::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E99E0
// Name: public: class CDmeControlGroup __near * CAttributeReferenceIterator::FilterReference<class CDmeControlGroup>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeControlGroup *result; // eax
  CDmeControlGroup *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_53;
    case TD_DEEP:
      goto $LN11_39;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_39:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_53:
      v7 = *(CDmeControlGroup **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeControlGroup::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EB880
// Name: public: class CDmeRigBaseConstraintOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeRigBaseConstraintOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeRigBaseConstraintOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeRigBaseConstraintOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeRigBaseConstraintOperator *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_54;
      case TD_DEEP:
        goto $LN11_40;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_40:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_54:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeRigBaseConstraintOperator::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeRigBaseConstraintOperator *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005F0490
// Name: public: class CDmeFlexRules __near * CAttributeReferenceIterator::FilterReference<class CDmeFlexRules>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeFlexRules *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_55;
      case TD_DEEP:
        goto $LN11_41;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_41:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_55:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeFlexRules::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeFlexRules *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005F3110
// Name: public: class CDmeOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeOperator *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_56;
      case TD_DEEP:
        goto $LN11_42;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_42:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_56:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeOperator::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeOperator *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049C6B0
// Name: class CDmeParticleSystemDefinition __near * FindReferringElement<class CDmeParticleSystemDefinition>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__cdecl FindReferringElement<CDmeParticleSystemDefinition>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeParticleSystemDefinition *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeParticleSystemDefinition>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F31C0
// Name: class CDmeOperator __near * FindReferringElement<class CDmeOperator>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeOperator *__cdecl FindReferringElement<CDmeOperator>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeOperator *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeOperator>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

} // namespace sceneviewer
