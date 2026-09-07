// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmedageditpanel.cpp
// Functions: 61
// ============================================================

#include "vgui2\dme_controls\dmedageditpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0047BA40
// Name: public: static char const __near * CDmeDagEditPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeDagEditPanel::GetPanelClassName()
{
  return "CDmeDagEditPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0047BA50
// Name: public: static char const __near * CDmeAnimationListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeAnimationListPanel::GetPanelClassName()
{
  return "CDmeAnimationListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0047BA60
// Name: public: char const __near * CDmeAnimationListPanel::GetSelectedAnimation(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeAnimationListPanel::GetSelectedAnimation(CDmeAnimationListPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pAnimationList->GetSelectedItemsCount(this: this->m_pAnimationList) == 0 )
    return defaultValue;
  v3 = this->m_pAnimationList->GetSelectedItem(this: this->m_pAnimationList, a2: 0);
  v4 = this->m_pAnimationList->GetItem(this: this->m_pAnimationList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "name", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0047BAC0
// Name: private: virtual void CDmeAnimationListPanel::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::OnItemSelected(CDmeAnimationListPanel *this)
{
  const char *String; // edi
  int v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pAnimationList->GetSelectedItemsCount(this: this->m_pAnimationList) != 0 )
  {
    v3 = this->m_pAnimationList->GetSelectedItem(this: this->m_pAnimationList, a2: 0);
    v4 = this->m_pAnimationList->GetItem(this: this->m_pAnimationList, a2: v3);
    String = KeyValues::GetString(this: v4, keyName: "name", defaultValue: defaultValue);
  }
  else
  {
    String = defaultValue;
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(this: v5, setName: "AnimationSelected", firstKey: "animationName", firstValue: String);
    this->PostActionSignal(this, a2: v6);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BB60
// Name: private: virtual void CDmeAnimationListPanel::OnItemDeselected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::OnItemDeselected(CDmeAnimationListPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "AnimationDeselected");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BBA0
// Name: public: static char const __near * CDmeCombinationOperatorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeCombinationOperatorPanel::GetPanelClassName()
{
  return "CDmeCombinationOperatorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0047BBB0
// Name: public: virtual void CDmeDagEditPanel::SetDmeElement(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetDmeElement(CDmeDagEditPanel *this, CDmeDag *pScene)
{
  CDmeDagRenderPanel::SetDmeElement(this: this->m_pDagRenderPanel, pScene);
}

//------------------------------------------------------------------------------
// Address: 0x0047BBC0
// Name: protected: virtual void CDmeDagEditPanel::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnPageChanged(CDmeDagEditPanel *this)
{
  const char *v2; // eax
  const char *SelectedAnimation; // [esp-4h] [ebp-8h]

  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pCombinationPage )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
LABEL_3:
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
    return;
  }
  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pAnimationPage )
  {
    SelectedAnimation = CDmeAnimationListPanel::GetSelectedAnimation(this: this->m_pAnimationListPanel);
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: SelectedAnimation);
    goto LABEL_3;
  }
  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pVertexAnimationPage )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
    v2 = CDmeAnimationListPanel::GetSelectedAnimation(this: this->m_pVertexAnimationListPanel);
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BC70
// Name: protected: virtual void CDmeDagEditPanel::OnAnimationSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnAnimationSelected(CDmeDagEditPanel *this, KeyValues *pKeyValues)
{
  CDmeAnimationListPanel *Ptr; // edi
  const char *String; // eax

  Ptr = (CDmeAnimationListPanel *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  String = KeyValues::GetString(this: pKeyValues, keyName: "animationName", defaultValue: defaultValue);
  if ( Ptr == this->m_pAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: String);
  }
  else if ( Ptr == this->m_pVertexAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BCE0
// Name: protected: virtual void CDmeDagEditPanel::OnAnimationDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnAnimationDeselected(CDmeDagEditPanel *this, KeyValues *pKeyValues)
{
  CDmeAnimationListPanel *Ptr; // eax

  Ptr = (CDmeAnimationListPanel *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  }
  else if ( Ptr == this->m_pVertexAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BDC0
// Name: public: class CDmAttribute __near * CDmElement::InitValue<float>(char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<float>(CDmElement *this, const char *pAttributeName, const float *value)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047BE40
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeDagEditPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeDagEditPanel::GetMessageMap(CDmeDagEditPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeDagEditPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagEditPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeDagEditPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
  `CDmeDagEditPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047BE70
// Name: public: virtual struct PanelAnimationMap __near * CDmeDagEditPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeDagEditPanel::GetAnimMap(CDmeDagEditPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeDagEditPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0047BE80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeDagEditPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeDagEditPanel::GetKBMap(CDmeDagEditPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeDagEditPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagEditPanel::GetKBMap'::`2'::s_pMap;
  `CDmeDagEditPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagEditPanel");
  `CDmeDagEditPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047BEB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeAnimationListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeAnimationListPanel::GetMessageMap(CDmeAnimationListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeAnimationListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeAnimationListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeAnimationListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
  `CDmeAnimationListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047BEE0
// Name: public: virtual struct PanelAnimationMap __near * CDmeAnimationListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeAnimationListPanel::GetAnimMap(CDmeAnimationListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeAnimationListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0047BEF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeAnimationListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeAnimationListPanel::GetKBMap(CDmeAnimationListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeAnimationListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeAnimationListPanel::GetKBMap'::`2'::s_pMap;
  `CDmeAnimationListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeAnimationListPanel");
  `CDmeAnimationListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047BFA0
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(
        CDmeCombinationOperatorPanel *this,
        CDmElement *pControlElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // edi
  CDmElement *v5; // eax
  CDmeCombinationOperator *v6; // eax
  int ComboOpControlIndexForAnimSetControl; // edi
  CDmElement *v8; // eax
  CDmeCombinationOperator *v9; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v14; // eax
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // eax
  CDmeCombinationOperator *v19; // ecx
  CDmAttribute *v20; // eax
  int v21; // eax
  CDmeCombinationOperator *v22; // ecx
  const Vector2D *StereoControlValue; // edi
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-1Ch]
  DmElementHandle_t v28; // [esp-4h] [ebp-1Ch]
  float flDefaultValue; // [esp+Ch] [ebp-Ch] BYREF
  float flValue; // [esp+10h] [ebp-8h] BYREF
  bool bIsStereoControl; // [esp+17h] [ebp-1h]

  v2 = pControlElement;
  m_pAsString = defaultValue;
  if ( pControlElement->m_Name.m_Storage.u.m_Id != -1 )
    m_pAsString = pControlElement->m_Name.m_Storage.u.m_pAsString;
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
  if ( v5 != nullptr )
    v6 = (CDmeCombinationOperator *)((char *)&v5[-1] + 64);
  else
    v6 = nullptr;
  ComboOpControlIndexForAnimSetControl = FindComboOpControlIndexForAnimSetControl(
                                           pComboOp: v6,
                                           pControlName: m_pAsString,
                                           pIsMulti: (bool *)&pControlElement + 3);
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
  if ( v8 != nullptr )
    v9 = (CDmeCombinationOperator *)((char *)&v8[-1] + 64);
  else
    v9 = nullptr;
  flDefaultValue = CDmeCombinationOperator::GetControlDefaultValue(
                     this: v9,
                     nControl: ComboOpControlIndexForAnimSetControl);
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hCombinationOperator.m_handle;
  if ( HIBYTE(pControlElement) != 0 )
  {
    v11 = ((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
    if ( v11 != 0 )
      v12 = (CDmeCombinationOperator *)(v11 - 4);
    else
      v12 = nullptr;
    flValue = CDmeCombinationOperator::GetMultiControlLevel(
                this: v12,
                nControlIndex: ComboOpControlIndexForAnimSetControl,
                type: COMBO_CONTROL_FIRST);
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "value");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v2, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value: &flValue);
    }
    flValue = 0.5;
    v14 = CDmElement::FindAttribute(this: v2, pAttributeName: "defaultValue");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: v2, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v14, value: &flValue);
    }
  }
  else
  {
    v15 = ((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
    if ( v15 != 0 )
      v16 = (CDmeCombinationOperator *)(v15 - 4);
    else
      v16 = nullptr;
    bIsStereoControl = CDmeCombinationOperator::IsStereoControl(
                         this: v16,
                         nControlIndex: ComboOpControlIndexForAnimSetControl);
    if ( CDmElement::HasAttribute(this: v2, pAttributeName: "rightValue", type: AT_UNKNOWN) != bIsStereoControl )
    {
      v17 = g_pDataModel->GetElement;
      v28 = this->m_hCombinationOperator.m_handle;
      if ( bIsStereoControl )
      {
        v21 = ((int (__stdcall *)(DmElementHandle_t))v17)(a1: v28);
        if ( v21 != 0 )
          v22 = (CDmeCombinationOperator *)(v21 - 4);
        else
          v22 = nullptr;
        StereoControlValue = CDmeCombinationOperator::GetStereoControlValue(
                               this: v22,
                               nControlIndex: ComboOpControlIndexForAnimSetControl,
                               type: COMBO_CONTROL_FIRST);
        v24 = CDmElement::FindAttribute(this: v2, pAttributeName: "leftValue");
        if ( v24 != nullptr
          || (v24 = CDmElement::CreateAttribute(this: v2, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v24, value: &StereoControlValue->x);
        }
        v25 = CDmElement::FindAttribute(this: v2, pAttributeName: "rightValue");
        if ( v25 != nullptr
          || (v25 = CDmElement::CreateAttribute(this: v2, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v25, value: &StereoControlValue->y);
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "value");
      }
      else
      {
        v18 = ((int (__stdcall *)(DmElementHandle_t))v17)(a1: v28);
        if ( v18 != 0 )
          v19 = (CDmeCombinationOperator *)(v18 - 4);
        else
          v19 = nullptr;
        flValue = CDmeCombinationOperator::GetControlValue(
                    this: v19,
                    nControlIndex: ComboOpControlIndexForAnimSetControl,
                    type: COMBO_CONTROL_FIRST);
        v20 = CDmElement::FindAttribute(this: v2, pAttributeName: "value");
        if ( v20 != nullptr
          || (v20 = CDmElement::CreateAttribute(this: v2, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v20, value: &flValue);
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "leftValue");
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "rightValue");
      }
    }
    v26 = CDmElement::FindAttribute(this: v2, pAttributeName: "defaultValue");
    if ( v26 != nullptr
      || (v26 = CDmElement::CreateAttribute(this: v2, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v26, value: &flDefaultValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C210
// Name: private: void CDmeCombinationOperatorPanel::SortAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::SortAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeCombinationOperatorPanel *v1; // edi
  CBaseAnimationSetControl *m_pController; // ecx
  CDmeTransform *v3; // ebx
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // esi
  CDmElement *v6; // eax
  CDmeCombinationOperator *v7; // ecx
  void *v8; // esp
  DmElementHandle_t *v9; // eax
  _DWORD *v10; // esi
  CDmElement *v11; // eax
  CDmeCombinationOperator *v12; // ecx
  const char *ControlName; // edi
  CExpressionCalculator *Control; // eax
  CDmElement *v15; // eax
  CDmeCombinationOperator *v16; // ecx
  CExpressionCalculator *v17; // eax
  _BYTE v18[12]; // [esp+0h] [ebp-12Ch] BYREF
  char pMultiControlName[256]; // [esp+Ch] [ebp-120h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+10Ch] [ebp-20h] BYREF
  DmElementHandle_t *pElements; // [esp+114h] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+118h] [ebp-14h]
  int nControlCount; // [esp+11Ch] [ebp-10h]
  int nCombinationControlCount; // [esp+120h] [ebp-Ch]
  CDmeCombinationOperatorPanel *v25; // [esp+124h] [ebp-8h]
  int i; // [esp+128h] [ebp-4h]

  v1 = this;
  m_pController = this->m_pController;
  v25 = v1;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  v3 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  v3->OnElementUnserialized(this: v3);
  Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v3);
  m_Size = Position->m_Storage.m_Size;
  controls = Position;
  nControlCount = m_Size;
  if ( m_Size != 0 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
    if ( v6 != nullptr )
      v7 = (CDmeCombinationOperator *)((char *)&v6[-1] + 64);
    else
      v7 = nullptr;
    nCombinationControlCount = CDmeCombinationOperator::GetControlCount(this: v7);
    v8 = alloca(4 * m_Size);
    v9 = (DmElementHandle_t *)v18;
    pElements = (DmElementHandle_t *)v18;
    i = 0;
    if ( nCombinationControlCount > 0 )
    {
      v10 = v18;
      while ( 1 )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
        v12 = v11 != nullptr ? (CDmeCombinationOperator *)((char *)&v11[-1] + 64) : nullptr;
        ControlName = CDmeCombinationOperator::GetControlName(this: v12, i);
        Control = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                             this: (CDmeAnimationSet *)v3,
                                             pControlName: ControlName);
        *v10++ = CCodecBuffer_Block::GetBufferType(this: Control);
        v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v25->m_hCombinationOperator.m_handle);
        v16 = v15 != nullptr ? (CDmeCombinationOperator *)((char *)&v15[-1] + 64) : nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v16, nControlIndex: i) )
        {
          V_snprintf(pDest: pMultiControlName, maxLen: 256, pFormat: "multi_%s", ControlName);
          v17 = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                           this: (CDmeAnimationSet *)v3,
                                           pControlName: pMultiControlName);
          *v10++ = CCodecBuffer_Block::GetBufferType(this: v17);
        }
        if ( ++i >= nCombinationControlCount )
          break;
        v1 = v25;
      }
      m_Size = nControlCount;
      v9 = pElements;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::SetMultiple(
      this: controls,
      i: 0,
      nCount: m_Size,
      pValue: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C390
// Name: public: void CDmeAnimationListPanel::RefreshAnimationList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::RefreshAnimationList(CDmeAnimationListPanel *this)
{
  int v2; // edi
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  KeyValues *v6; // eax
  const char *m_pAsString; // edx
  const KeyValues *v8; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  this->m_pAnimationList->RemoveAll(this: this->m_pAnimationList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle) != nullptr )
  {
    v2 = 0;
    nCount = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle)[1].m_Id.m_Value[8];
    if ( nCount > 0 )
    {
      do
      {
        v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v3[1].OnAttributeChanged + v2));
        v5 = v4;
        if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
          v5 = nullptr;
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
        {
          m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          v8 = KeyValues::KeyValues(this: v6, setName: "node", firstKey: "name", firstValue: m_pAsString);
        }
        else
        {
          v8 = nullptr;
        }
        this->m_pAnimationList->AddItem(this: this->m_pAnimationList, a2: v8, a3: 0, a4: false, a5: false);
        ++v2;
      }
      while ( v2 < nCount );
    }
    this->m_pAnimationList->SortList(this: this->m_pAnimationList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C4B0
// Name: private: void CDmeCombinationOperatorPanel::CreateFakeAnimationSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::CreateFakeAnimationSet(CDmeCombinationOperatorPanel *this)
{
  DmElementHandle_t v1; // eax
  CDmElement *v2; // eax
  CDmeFilmClip *v3; // esi
  CDmeFilmClip *v4; // ebx
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // edi
  CDmAttribute *Attribute; // eax
  CDmaElementArray<CDmeAnimationSet> *AnimationSets; // esi
  IDataModel_vtbl *v10; // edi
  int BufferType; // eax
  DmElementHandle_t value; // [esp+10h] [ebp-4h] BYREF

  v1 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeFilmClip::m_classType.u.m_Id,
         a3: "fakeFilmClip",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1);
  v3 = (CDmeFilmClip *)v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeFilmClip::m_classType) )
    v4 = v3;
  else
    v4 = nullptr;
  v5 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeAnimationSet::m_classType.u.m_Id,
         a3: "fakeAnimSet",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  v7 = v6;
  if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeAnimationSet::m_classType) )
    v7 = nullptr;
  value = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "gameModel");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v7, pAttributeName: "gameModel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
  }
  AnimationSets = CDmeFilmClip::GetAnimationSets(this: v4);
  if ( v7 != nullptr )
    value = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
  else
    value = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: AnimationSets,
    src: &value);
  v10 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v4);
  v10->DontAutoDelete(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  CBaseAnimationSetEditor::ChangeAnimationSetClip(this, pFilmClip: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0047C5F0
// Name: private: void CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(
        CDmeCombinationOperatorPanel *this,
        const char *pControlName)
{
  int v2; // edi
  CDmeAnimationSet *v3; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // esi
  CDmAttribute *m_pAttribute; // eax
  DmElementArray_t *m_pData; // eax
  int v7; // ebx
  CDmElement *v8; // eax
  CDmeTransformControl *v9; // esi
  CDmeTransformControl *v10; // ecx
  const Vector *Position; // esi
  float x; // eax
  DmElementArray_t *v13; // eax
  CDmElement *v14; // eax
  CDmeTransform *v15; // esi
  CDmeTransform *v16; // ecx
  const Vector *v17; // esi
  float v18; // eax
  DmElementArray_t *m_pStorage; // eax
  int v20; // ebx
  CDmElement *v21; // eax
  CDmElement *v22; // esi
  const char *m_pAsString; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-30h] BYREF
  CDmrElementArray<CDmePreset> presetList; // [esp+14h] [ebp-28h] BYREF
  CDmrElementArray<CDmePresetGroup> presetGroupList; // [esp+1Ch] [ebp-20h] BYREF
  CDmrElementArray<CDmElement> controlValues; // [esp+24h] [ebp-18h] BYREF
  int i; // [esp+2Ch] [ebp-10h]
  int m_Size; // [esp+30h] [ebp-Ch]
  int v30; // [esp+34h] [ebp-8h]
  int j; // [esp+38h] [ebp-4h]

  v2 = 0;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v3);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupList);
  m_pAttribute = PresetGroups->m_pAttribute;
  if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    presetGroupList.m_pAttribute = PresetGroups->m_pAttribute;
    m_pData = (DmElementArray_t *)m_pAttribute->m_pData;
    presetGroupList.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    presetGroupList.m_pAttribute = nullptr;
    presetGroupList.m_pStorage = nullptr;
    m_Size = 0;
  }
  v7 = 0;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v7]);
      v9 = (CDmeTransformControl *)v8;
      if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmePresetGroup::m_classType) )
        v10 = v9;
      else
        v10 = nullptr;
      Position = CDmeTransformControl::GetPosition(this: v10);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetList);
      x = Position[2].x;
      if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
      {
        v13 = nullptr;
        presetList.m_pAttribute = nullptr;
        presetList.m_pStorage = nullptr;
        v30 = 0;
      }
      else
      {
        presetList.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
        v13 = *(DmElementArray_t **)(LODWORD(x) + 4);
        presetList.m_pStorage = v13;
        v30 = v13->m_Size;
      }
      j = 0;
      if ( v30 > 0 )
      {
        while ( 1 )
        {
          v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13->m_Memory.m_pMemory[j]);
          v15 = (CDmeTransform *)v14;
          if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmePreset::m_classType) )
            v16 = v15;
          else
            v16 = nullptr;
          v17 = CDmeTransform::GetPosition(this: v16);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controlValues);
          v18 = v17[2].x;
          if ( v18 == 0.0 || (*(_BYTE *)(LODWORD(v18) + 16) & 0x1F) != 0xF )
          {
            m_pStorage = nullptr;
            controlValues.m_pAttribute = nullptr;
            controlValues.m_pStorage = nullptr;
            v20 = 0;
          }
          else
          {
            controlValues.m_pAttribute = (CDmAttribute *)LODWORD(v17[2].x);
            m_pStorage = *(DmElementArray_t **)(LODWORD(v18) + 4);
            controlValues.m_pStorage = m_pStorage;
            v20 = m_pStorage->m_Size;
          }
          if ( v20 > 0 )
          {
            while ( 1 )
            {
              v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v2]);
              v22 = v21;
              if ( v21 == nullptr || !v21->IsA(this: v21, a2: CDmElement::m_classType) )
                v22 = nullptr;
              m_pAsString = v22->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = defaultValue;
              if ( _V_stricmp(s1: m_pAsString, s2: pControlName) == 0 )
                break;
              if ( ++v2 >= v20 )
                goto LABEL_39;
              m_pStorage = controlValues.m_pStorage;
            }
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::FastRemove(
              this: &controlValues,
              elem: v2);
          }
LABEL_39:
          v2 = 0;
          if ( ++j >= v30 )
            break;
          v13 = presetList.m_pStorage;
        }
        v7 = i;
      }
      i = ++v7;
      if ( v7 >= m_Size )
        break;
      m_pData = presetGroupList.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C800
// Name: private: void CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  const Vector *Position; // esi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // esi
  CDmElement *v10; // eax
  CDmeCombinationOperator *v11; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> controls; // [esp+14h] [ebp-Ch] BYREF
  CDmeAnimationSet *pAnimationSet; // [esp+1Ch] [ebp-4h]

  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  pAnimationSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  Position = CDmeTransform::GetPosition(this: (CDmeTransform *)pAnimationSet);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
  x = Position[2].x;
  if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    controls.m_pAttribute = nullptr;
    controls.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    controls.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
    m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
    controls.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v6 = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v6]);
      v8 = v7;
      if ( v7 != nullptr
        && v7->IsA(this: v7, a2: CDmElement::m_classType)
        && !v8->IsA(this: v8, a2: CDmeTransformControl::m_classType) )
      {
        m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
        if ( v10 != nullptr )
          v11 = (CDmeCombinationOperator *)((char *)&v10[-1] + 64);
        else
          v11 = nullptr;
        if ( FindComboOpControlIndexForAnimSetControl(pComboOp: v11, pControlName: m_pAsString, pIsMulti: nullptr) < 0 )
        {
          CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(this, pControlName: m_pAsString);
          CDmeAnimationSet::RemoveControlFromGroups(
            this: pAnimationSet,
            pchControlName: m_pAsString,
            bRemoveEmpty: false);
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::FastRemove(
            this: &controls,
            elem: v6);
        }
      }
      if ( --v6 < 0 )
        break;
      m_pStorage = controls.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C930
// Name: public: float const __near & CDmElement::GetValue<float>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CDmElement::GetValue<float>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<float>(this: Attribute);
  else
    return &`CDmElement::GetValue<float>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0047C980
// Name: struct SelectionInfo_t __near * FindSelectionInfoForControl<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
SelectionInfo_t *__cdecl FindSelectionInfoForControl<SelectionInfo_t>(
        CUtlVector<SelectionInfo_t *,CUtlMemory<SelectionInfo_t *,int> > *controlList,
        const CDmElement *pControl)
{
  int v3; // esi
  SelectionInfo_t *v4; // edi
  int nControls; // [esp+0h] [ebp-4h]

  if ( pControl == nullptr )
    return nullptr;
  v3 = 0;
  nControls = controlList->m_Size;
  if ( nControls <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = controlList->m_Memory.m_pMemory[v3];
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_hControl.m_handle) == pControl )
      break;
    if ( ++v3 >= nControls )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047C9E0
// Name: protected: virtual struct SelectionInfo_t __near * CCombinationOperatorControl::FindSelectionInfoForControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
SelectionInfo_t *__thiscall CCombinationOperatorControl::FindSelectionInfoForControl(
        CCombinationOperatorControl *this,
        const CDmElement *pControl)
{
  return FindSelectionInfoForControl<SelectionInfo_t>(controlList: &this->m_FullControlList, pControl);
}

//------------------------------------------------------------------------------
// Address: 0x0047CA00
// Name: void RemoveNullControls<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveNullControls<SelectionInfo_t>(
        CUtlVector<SelectionInfo_t *,CUtlMemory<SelectionInfo_t *,int> > *controlList)
{
  int i; // esi
  CDmeElementRefHelper *v2; // ebx

  for ( i = controlList->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: controlList->m_Memory.m_pMemory[i]->m_hControl.m_handle) == nullptr )
    {
      v2 = (CDmeElementRefHelper *)controlList->m_Memory.m_pMemory[i];
      if ( v2 != nullptr )
      {
        if ( g_pDataModel != nullptr )
        {
          CDmeElementRefHelper::Unref(this: v2 + 4, hElement: *(DmElementHandle_t *)&v2[4], handleType: HT_WEAK);
          if ( g_pDataModel != nullptr )
            CDmeElementRefHelper::Unref(this: v2, hElement: *(_DWORD *)v2, handleType: HT_WEAK);
        }
        CUtlMemoryPool::Free(this: &SelectionInfo_t::s_Allocator, memBlock: v2);
      }
      if ( controlList->m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &controlList->m_Memory.m_pMemory[i],
          src: &controlList->m_Memory.m_pMemory[i + 1],
          count: 4 * (controlList->m_Size - i - 1));
      --controlList->m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CAA0
// Name: public: CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetControl __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperatorPanel *__thiscall CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(
        CDmeCombinationOperatorPanel *this,
        vgui::Panel *parent,
        const char *panelName,
        CBaseAnimationSetControl *pAnimationSetController)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  CBaseAnimationSetEditor::CBaseAnimationSetEditor(this, parent, className: panelName, pAnimationSetController);
  this->__vftable = (CDmeCombinationOperatorPanel_vtbl *)&CDmeCombinationOperatorPanel::`vftable';
  if ( `CDmeCombinationOperatorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationOperatorPanel");
    v5->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
  }
  if ( `CDmeCombinationOperatorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmeCombinationOperatorPanel");
    v6->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
  }
  if ( `CDmeCombinationOperatorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationOperatorPanel");
    v7->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
  }
  this->m_hCombinationOperator.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_operatorList.m_Memory.m_pMemory = nullptr;
  this->m_operatorList.m_Memory.m_nAllocationCount = 0;
  this->m_operatorList.m_Memory.m_nGrowSize = 0;
  this->m_operatorList.m_Size = 0;
  this->m_operatorList.m_pElements = nullptr;
  CDmeCombinationOperatorPanel::CreateFakeAnimationSet(this);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047CBB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeCombinationOperatorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeCombinationOperatorPanel::GetMessageMap(CDmeCombinationOperatorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeCombinationOperatorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationOperatorPanel");
  `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047CBE0
// Name: public: virtual struct PanelAnimationMap __near * CDmeCombinationOperatorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeCombinationOperatorPanel::GetAnimMap(CDmeCombinationOperatorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeCombinationOperatorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0047CBF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeCombinationOperatorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeCombinationOperatorPanel::GetKBMap(CDmeCombinationOperatorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeCombinationOperatorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationOperatorPanel::GetKBMap'::`2'::s_pMap;
  `CDmeCombinationOperatorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationOperatorPanel");
  `CDmeCombinationOperatorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047CC20
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(
        CDmeCombinationOperatorPanel *this,
        CDmElement *pControlElement)
{
  char *m_Id; // eax
  CDmeAnimationSet *v3; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // esi
  CDmAttribute *m_pAttribute; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // eax
  int m_Size; // ecx
  CDmElement *v8; // eax
  CDmeTransformControl *v9; // esi
  CDmeTransformControl *v10; // ecx
  const Vector *Position; // esi
  float x; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *v13; // eax
  int v14; // ecx
  CDmElement *v15; // eax
  CDmeTransform *v16; // esi
  const Vector *v17; // esi
  float v18; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pStorage; // eax
  int v20; // ecx
  int v21; // ecx
  CDmElement *v22; // eax
  CDmElement *v23; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v26; // edi
  CDmaVar<float> *v27; // edi
  CDmAttribute *v28; // eax
  CDmAttribute *v29; // eax
  CDmAttribute *v30; // eax
  CDmAttribute *v31; // edi
  CDmaVar<float> *v32; // edi
  CDmAttribute *v33; // eax
  CDmAttribute *v34; // edi
  CDmaVar<float> *v35; // edi
  const float *p_flLeftValue; // edi
  CDmAttribute *v37; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-48h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v39; // [esp+14h] [ebp-40h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v40; // [esp+1Ch] [ebp-38h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v41; // [esp+24h] [ebp-30h] BYREF
  int v42; // [esp+2Ch] [ebp-28h]
  int v43; // [esp+30h] [ebp-24h]
  int v44; // [esp+34h] [ebp-20h]
  float flRightValue; // [esp+38h] [ebp-1Ch] BYREF
  float flLeftValue; // [esp+3Ch] [ebp-18h] BYREF
  float flValue; // [esp+40h] [ebp-14h] BYREF
  char *s2; // [esp+44h] [ebp-10h]
  int g; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int j; // [esp+50h] [ebp-4h]

  m_Id = (char *)pControlElement->m_Name.m_Storage.u.m_Id;
  s2 = (char *)defaultValue;
  if ( m_Id != (char *)-1 )
    s2 = m_Id;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v3);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v41);
  m_pAttribute = PresetGroups->m_pAttribute;
  if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    v41.m_pAttribute = PresetGroups->m_pAttribute;
    m_pData = (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)m_pAttribute->m_pData;
    v41.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    v41.m_pAttribute = nullptr;
    v41.m_pStorage = nullptr;
    m_Size = 0;
  }
  v42 = m_Size;
  g = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[g].m_tms);
      v9 = (CDmeTransformControl *)v8;
      if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmePresetGroup::m_classType) )
        v10 = v9;
      else
        v10 = nullptr;
      Position = CDmeTransformControl::GetPosition(this: v10);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v40);
      x = Position[2].x;
      if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
      {
        v13 = nullptr;
        v40.m_pAttribute = nullptr;
        v40.m_pStorage = nullptr;
        v14 = 0;
      }
      else
      {
        v40.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
        v13 = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(x) + 4);
        v40.m_pStorage = v13;
        v14 = v13->m_Size;
      }
      v43 = v14;
      i = 0;
      if ( v14 > 0 )
      {
        while ( 1 )
        {
          v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13->m_Memory.m_pMemory[i].m_tms);
          v16 = (CDmeTransform *)v15;
          if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmePreset::m_classType) )
            v16 = nullptr;
          if ( !CDmePreset::IsAnimated(this: (CDmePreset *)v16) )
          {
            v17 = CDmeTransform::GetPosition(this: v16);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v39);
            v18 = v17[2].x;
            if ( v18 == 0.0 || (*(_BYTE *)(LODWORD(v18) + 16) & 0x1F) != 0xF )
            {
              m_pStorage = nullptr;
              v39.m_pAttribute = nullptr;
              v39.m_pStorage = nullptr;
              v20 = 0;
            }
            else
            {
              v39.m_pAttribute = (CDmAttribute *)LODWORD(v17[2].x);
              m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(v18) + 4);
              v39.m_pStorage = m_pStorage;
              v20 = m_pStorage->m_Size;
            }
            v44 = v20;
            j = 0;
            if ( v20 > 0 )
            {
              v21 = 0;
              while ( 1 )
              {
                v22 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v21].m_tms);
                v23 = v22;
                if ( v22 == nullptr || !v22->IsA(this: v22, a2: CDmElement::m_classType) )
                  v23 = nullptr;
                m_pAsString = v23->m_Name.m_Storage.u.m_pAsString;
                if ( m_pAsString == (const char *)-1 )
                  m_pAsString = defaultValue;
                if ( _V_stricmp(s1: m_pAsString, s2) == 0 )
                {
                  if ( CDmElement::HasAttribute(this: pControlElement, pAttributeName: "rightValue", type: AT_UNKNOWN) )
                  {
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    Attribute = CDmElement::FindAttribute(this: v23, pAttributeName: "value");
                    v26 = Attribute;
                    if ( Attribute != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (Attribute->m_nFlags & 0x1F) == 3 )
                      {
                        v27 = (CDmaVar<float> *)Attribute->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v26,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v27 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v27 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v27 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flValue = v27->m_Storage;
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "value");
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue") == nullptr )
                    {
                      v28 = CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue");
                      if ( v28 != nullptr
                        || (v28 = CDmElement::CreateAttribute(this: v23, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v28, value: &flValue);
                      }
                    }
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue") == nullptr )
                    {
                      v29 = CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue");
                      if ( v29 != nullptr
                        || (v29 = CDmElement::CreateAttribute(this: v23, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v29, value: &flValue);
                      }
                    }
                  }
                  else
                  {
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    v30 = CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue");
                    v31 = v30;
                    if ( v30 != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (v30->m_nFlags & 0x1F) == 3 )
                      {
                        v32 = (CDmaVar<float> *)v30->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v30) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v31,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v32 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v32 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v32 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flLeftValue = v32->m_Storage;
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    v33 = CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue");
                    v34 = v33;
                    if ( v33 != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (v33->m_nFlags & 0x1F) == 3 )
                      {
                        v35 = (CDmaVar<float> *)v33->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v33) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v34,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v35 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v35 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v35 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flRightValue = v35->m_Storage;
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "leftValue");
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "rightValue");
                    p_flLeftValue = &flLeftValue;
                    if ( flLeftValue <= flRightValue )
                      p_flLeftValue = &flRightValue;
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "value") == nullptr )
                    {
                      v37 = CDmElement::FindAttribute(this: v23, pAttributeName: "value");
                      if ( v37 != nullptr
                        || (v37 = CDmElement::CreateAttribute(this: v23, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v37, value: p_flLeftValue);
                      }
                    }
                  }
                }
                v21 = j + 1;
                j = v21;
                if ( v21 >= v44 )
                  break;
                m_pStorage = v39.m_pStorage;
              }
            }
          }
          if ( ++i >= v43 )
            break;
          v13 = v40.m_pStorage;
        }
      }
      if ( ++g >= v42 )
        break;
      m_pData = v41.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D130
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeTransform *v1; // eax
  const Vector *Position; // esi
  float x; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pStorage; // eax
  int m_Size; // ecx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-14h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v10; // [esp+10h] [ebp-Ch] BYREF
  CDmeCombinationOperatorPanel *v11; // [esp+18h] [ebp-4h]

  v11 = this;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v1 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  Position = CDmeTransform::GetPosition(this: v1);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v10);
  x = Position[2].x;
  if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    v10.m_pAttribute = nullptr;
    v10.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    v10.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
    m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(x) + 4);
    v10.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v6 = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v6].m_tms);
      v8 = v7;
      if ( v7 != nullptr
        && v7->IsA(this: v7, a2: CDmElement::m_classType)
        && !v8->IsA(this: v8, a2: CDmeTransformControl::m_classType) )
      {
        CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(this: v11, pControlElement: v8);
        CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(this: v11, pControlElement: v8);
      }
      if ( --v6 < 0 )
        break;
      m_pStorage = v10.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D210
// Name: private: void CDmeCombinationOperatorPanel::AddNewAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::AddNewAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeCombinationOperatorPanel *v1; // ebx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  int v3; // eax
  int v4; // edi
  CDmeAnimationSet *v5; // esi
  CDmaElementArray<CDmElement> *Position; // eax
  CDmElement *(__thiscall *v7)(IDataModel *, DmElementHandle_t); // edx
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  CDmElement *v10; // eax
  CDmeCombinationOperator *v11; // ecx
  CDmElement *v12; // eax
  CDmeCombinationOperator *v13; // ecx
  bool IsStereoControl; // bl
  CDmElement *v15; // eax
  CDmeCombinationOperator *v16; // ecx
  DmElementHandle_t v17; // eax
  CDmElement *v18; // eax
  CExpressionCalculator *v19; // esi
  CDmElement *v20; // eax
  CDmeCombinationOperator *v21; // ecx
  const Vector2D *StereoControlValue; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  CDmElement *v26; // eax
  CDmeCombinationOperator *v27; // ecx
  CDmElement *v28; // eax
  CDmeCombinationOperator *v29; // ecx
  CDmAttribute *v30; // eax
  DmElementHandle_t v31; // eax
  CDmElement *v32; // eax
  CExpressionCalculator *v33; // esi
  CDmElement *v34; // eax
  CDmeCombinationOperator *v35; // ecx
  CDmAttribute *v36; // eax
  CDmAttribute *v37; // eax
  int m_Size; // ebx
  CDmeControlGroup *v39; // esi
  CDmAttribute *v40; // eax
  int j; // edi
  CDmElement *v42; // eax
  CExpressionCalculator *v43; // esi
  DmElementHandle_t m_handle; // [esp-4h] [ebp-158h]
  char pMultiControlName[256]; // [esp+Ch] [ebp-148h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+10Ch] [ebp-48h] BYREF
  float MultiControlLevel; // [esp+114h] [ebp-40h] BYREF
  float v48; // [esp+118h] [ebp-3Ch] BYREF
  float flDefaultValue; // [esp+11Ch] [ebp-38h] BYREF
  int nCombinationControlCount; // [esp+120h] [ebp-34h]
  float value; // [esp+124h] [ebp-30h] BYREF
  const char *pControlName; // [esp+128h] [ebp-2Ch]
  CDmrElementArray<CDmElement> groups; // [esp+12Ch] [ebp-28h] BYREF
  DmElementHandle_t src; // [esp+134h] [ebp-20h] BYREF
  int nFirstControl; // [esp+138h] [ebp-1Ch]
  int i; // [esp+13Ch] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+140h] [ebp-14h]
  CDmeAnimationSet *pAnimationSet; // [esp+144h] [ebp-10h]
  DmElementHandle_t BufferType; // [esp+148h] [ebp-Ch] BYREF
  int iCurrentAnimSetControl; // [esp+14Ch] [ebp-8h]
  CDmeCombinationOperatorPanel *v61; // [esp+150h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hCombinationOperator.m_handle;
  v61 = this;
  v3 = (int)GetElement(this: g_pDataModel, a2: m_handle);
  v4 = 0;
  if ( v3 != 0 && v3 != 4 )
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: v1->m_pController);
    traversal.m_nIndex = 0;
    v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    pAnimationSet = v5;
    Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: (CDmeTransform *)v5);
    nFirstControl = Position->m_Storage.m_Size;
    v7 = g_pDataModel->GetElement;
    controls = Position;
    v8 = (int)v7(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
    if ( v8 != 0 )
      v9 = (CDmeCombinationOperator *)(v8 - 4);
    else
      v9 = nullptr;
    nCombinationControlCount = CDmeCombinationOperator::GetControlCount(this: v9);
    iCurrentAnimSetControl = 0;
    i = 0;
    if ( nCombinationControlCount > 0 )
    {
      do
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
        if ( v10 != nullptr )
          v11 = (CDmeCombinationOperator *)((char *)&v10[-1] + 64);
        else
          v11 = nullptr;
        pControlName = CDmeCombinationOperator::GetControlName(this: v11, i: v4);
        if ( CDmeAnimationSet::FindControl(this: v5, pControlName) == nullptr )
        {
          v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
          if ( v12 != nullptr )
            v13 = (CDmeCombinationOperator *)((char *)&v12[-1] + 64);
          else
            v13 = nullptr;
          IsStereoControl = CDmeCombinationOperator::IsStereoControl(this: v13, nControlIndex: v4);
          v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
          if ( v15 != nullptr )
            v16 = (CDmeCombinationOperator *)((char *)&v15[-1] + 64);
          else
            v16 = nullptr;
          flDefaultValue = CDmeCombinationOperator::GetControlDefaultValue(this: v16, nControl: v4);
          v17 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                  a1: g_pDataModel,
                  a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
                  a3: pControlName,
                  a4: v5->m_fileId,
                  a5: nullptr);
          v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: v17);
          v19 = (CExpressionCalculator *)v18;
          if ( v18 != nullptr && v18->IsA(this: v18, a2: CDmElement::m_classType) )
          {
            src = CCodecBuffer_Block::GetBufferType(this: v19);
          }
          else
          {
            v19 = nullptr;
            src = DMELEMENT_HANDLE_INVALID;
          }
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
            this: controls,
            elem: (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)iCurrentAnimSetControl,
            &src);
          if ( IsStereoControl )
          {
            v20 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
            if ( v20 != nullptr )
              v21 = (CDmeCombinationOperator *)((char *)&v20[-1] + 64);
            else
              v21 = nullptr;
            StereoControlValue = CDmeCombinationOperator::GetStereoControlValue(
                                   this: v21,
                                   nControlIndex: v4,
                                   type: COMBO_CONTROL_FIRST);
            Attribute = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "leftValue");
            if ( Attribute != nullptr
              || (Attribute = CDmElement::CreateAttribute(
                                this: (CDmElement *)v19,
                                pAttributeName: "leftValue",
                                type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: Attribute, value: &StereoControlValue->x);
            }
            v24 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "rightValue");
            if ( v24 != nullptr
              || (v24 = CDmElement::CreateAttribute(
                          this: (CDmElement *)v19,
                          pAttributeName: "rightValue",
                          type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v24, value: &StereoControlValue->y);
            }
            v4 = i;
          }
          else
          {
            v28 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
            if ( v28 != nullptr )
              v29 = (CDmeCombinationOperator *)((char *)&v28[-1] + 64);
            else
              v29 = nullptr;
            value = CDmeCombinationOperator::GetControlValue(this: v29, nControlIndex: v4, type: COMBO_CONTROL_FIRST);
            v30 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "value");
            if ( v30 != nullptr
              || (v30 = CDmElement::CreateAttribute(this: (CDmElement *)v19, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v30, &value);
            }
          }
          v25 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "defaultValue");
          if ( v25 != nullptr
            || (v25 = CDmElement::CreateAttribute(
                        this: (CDmElement *)v19,
                        pAttributeName: "defaultValue",
                        type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v25, value: &flDefaultValue);
          }
          v1 = v61;
          v5 = pAnimationSet;
        }
        v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
        if ( v26 != nullptr )
          v27 = (CDmeCombinationOperator *)((char *)&v26[-1] + 64);
        else
          v27 = nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v27, nControlIndex: v4) )
        {
          ++iCurrentAnimSetControl;
          V_snprintf(pDest: pMultiControlName, maxLen: 256, pFormat: "multi_%s", pControlName);
          if ( CDmeAnimationSet::FindControl(this: v5, pControlName: pMultiControlName) == nullptr )
          {
            v31 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                    a1: g_pDataModel,
                    a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
                    a3: pMultiControlName,
                    a4: v5->m_fileId,
                    a5: nullptr);
            v32 = g_pDataModel->GetElement(this: g_pDataModel, a2: v31);
            v33 = (CExpressionCalculator *)v32;
            if ( v32 != nullptr && v32->IsA(this: v32, a2: CDmElement::m_classType) )
            {
              BufferType = CCodecBuffer_Block::GetBufferType(this: v33);
            }
            else
            {
              v33 = nullptr;
              BufferType = DMELEMENT_HANDLE_INVALID;
            }
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
              this: controls,
              elem: (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)iCurrentAnimSetControl,
              src: &BufferType);
            v34 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
            if ( v34 != nullptr )
              v35 = (CDmeCombinationOperator *)((char *)&v34[-1] + 64);
            else
              v35 = nullptr;
            MultiControlLevel = CDmeCombinationOperator::GetMultiControlLevel(
                                  this: v35,
                                  nControlIndex: v4,
                                  type: COMBO_CONTROL_FIRST);
            v36 = CDmElement::FindAttribute(this: (CDmElement *)v33, pAttributeName: "value");
            if ( v36 != nullptr
              || (v36 = CDmElement::CreateAttribute(this: (CDmElement *)v33, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v36, value: &MultiControlLevel);
            }
            v48 = 0.5;
            v37 = CDmElement::FindAttribute(this: (CDmElement *)v33, pAttributeName: "defaultValue");
            if ( v37 != nullptr
              || (v37 = CDmElement::CreateAttribute(
                          this: (CDmElement *)v33,
                          pAttributeName: "defaultValue",
                          type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v37, value: &v48);
            }
            v1 = v61;
            v5 = pAnimationSet;
          }
        }
        ++iCurrentAnimSetControl;
        i = ++v4;
      }
      while ( v4 < nCombinationControlCount );
    }
    m_Size = controls->m_Storage.m_Size;
    if ( m_Size != nFirstControl )
    {
      v39 = CDmeAnimationSet::FindOrAddControlGroup(this: v5, pParentGroup: nullptr, pControlGroupName: "Root");
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&groups);
      if ( v39 != nullptr
        && (v40 = CDmElement::FindAttribute(this: v39, pAttributeName: "controls")) != nullptr
        && (v40->m_nFlags & 0x1F) == 0xF )
      {
        groups.m_pAttribute = v40;
        groups.m_pStorage = (DmElementArray_t *)v40->m_pData;
      }
      else
      {
        groups.m_pAttribute = nullptr;
        groups.m_pStorage = nullptr;
      }
      for ( j = nFirstControl; j < m_Size; ++j )
      {
        v42 = g_pDataModel->GetElement(this: g_pDataModel, a2: controls->m_Storage.m_Memory.m_pMemory[j]);
        v43 = (CExpressionCalculator *)v42;
        if ( v42 != nullptr && v42->IsA(this: v42, a2: CDmElement::m_classType) )
          BufferType = CCodecBuffer_Block::GetBufferType(this: v43);
        else
          BufferType = DMELEMENT_HANDLE_INVALID;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &groups,
          src: &BufferType);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D710
// Name: public: void CDmeDagEditPanel::SetAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetAnimationList(CDmeDagEditPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeAnimationListPanel *m_pAnimationListPanel; // esi
  DmElementHandle_t BufferType; // eax

  CDmeDagRenderPanel::SetAnimationList(this: this->m_pDagRenderPanel, (CExpressionCalculator *)pAnimationList);
  CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  m_pAnimationListPanel = this->m_pAnimationListPanel;
  if ( pAnimationList != g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: m_pAnimationListPanel->m_hAnimationList.m_handle) )
  {
    if ( pAnimationList != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeAnimationList,0>::Set(this: &m_pAnimationListPanel->m_hAnimationList, h: BufferType);
    CDmeAnimationListPanel::RefreshAnimationList(this: m_pAnimationListPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D780
// Name: public: void CDmeDagEditPanel::SetVertexAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetVertexAnimationList(CDmeDagEditPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeAnimationListPanel *m_pVertexAnimationListPanel; // esi
  DmElementHandle_t BufferType; // eax

  CDmeDagRenderPanel::SetVertexAnimationList(this: this->m_pDagRenderPanel, (CExpressionCalculator *)pAnimationList);
  CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  m_pVertexAnimationListPanel = this->m_pVertexAnimationListPanel;
  if ( pAnimationList != g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: m_pVertexAnimationListPanel->m_hAnimationList.m_handle) )
  {
    if ( pAnimationList != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeAnimationList,0>::Set(this: &m_pVertexAnimationListPanel->m_hAnimationList, h: BufferType);
    CDmeAnimationListPanel::RefreshAnimationList(this: m_pVertexAnimationListPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D880
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D910
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AnimationSelected";
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
// Address: 0x0047D9A0
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AnimationDeselected";
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
// Address: 0x0047DA30
// Name: public: static void CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DAC0
// Name: public: static void CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemDeselected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DB50
// Name: public: CDmeAnimationListPanel::CDmeAnimationListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationListPanel *__thiscall CDmeAnimationListPanel::CDmeAnimationListPanel(
        CDmeAnimationListPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeAnimationListPanel_vtbl *)&CDmeAnimationListPanel::`vftable';
  if ( `CDmeAnimationListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v4->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeAnimationListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeAnimationListPanel");
    v5->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeAnimationListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeAnimationListPanel");
    v6->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  this->m_hAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "AnimationList");
  else
    v8 = nullptr;
  this->m_pAnimationList = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "name", a4: "name", a5: 100, a6: 0);
  this->m_pAnimationList->AddActionSignalTarget_2(this: this->m_pAnimationList, a2: this);
  this->m_pAnimationList->SetSortFunc(this: this->m_pAnimationList, a2: 0, a3: PresetNameSortFunc);
  this->m_pAnimationList->SetSortColumn(this: this->m_pAnimationList, a2: 0);
  this->m_pAnimationList->SetEmptyListText_2(this: this->m_pAnimationList, a2: "No animations");
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pAnimationList, bState: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmeanimationlistpanel.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047DD40
// Name: public: void CDmeCombinationOperatorPanel::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::SetCombinationOperator(
        CDmeCombinationOperatorPanel *this,
        CDmeCombinationOperator *pOp)
{
  CDmeCombinationOperatorPanel *v2; // ebx
  CDmAttribute *AnimationSetClip; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_operatorList; // esi
  CDmElement *v5; // eax
  CDmeCombinationOperator *v6; // eax
  CDmElement *v7; // ecx
  DmElementHandle_t BufferType; // eax
  CDmElement *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  int *v14; // edi
  CDmElement *OperationTarget; // eax
  CDmElement *v16; // edi
  vgui::TreeNode **v17; // edi
  int v18; // eax
  vgui::TreeNode **v19; // ecx
  int v20; // eax
  CDmeFlexRules **v21; // eax
  CDmeFlexRules *v22; // ecx
  int v23; // eax
  int j; // ebx
  CDmElement *v25; // eax
  CDmElement *v26; // edi
  vgui::TreeNode **v27; // edi
  int v28; // eax
  vgui::TreeNode **v29; // ecx
  int v30; // eax
  vgui::TreeNode **v31; // eax
  CDmeFilmClip *v32; // eax
  vgui::TreeNode *v33; // [esp+10h] [ebp-10h]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  CDmeFlexRules *pDmeFlexRules; // [esp+1Ch] [ebp-4h]

  v2 = this;
  AnimationSetClip = (CDmAttribute *)CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  DestroyElement(pElement: AnimationSetClip, depth: TD_DEEP);
  CDmeCombinationOperatorPanel::CreateFakeAnimationSet(this: v2);
  v2->m_operatorList.m_Size = 0;
  p_m_operatorList = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_operatorList;
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hCombinationOperator.m_handle);
  if ( v5 != nullptr )
    v6 = (CDmeCombinationOperator *)((char *)&v5[-1] + 64);
  else
    v6 = nullptr;
  if ( pOp != v6 )
  {
    if ( pOp != nullptr )
      v7 = &pOp->CDmElement;
    else
      v7 = nullptr;
    if ( v7 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeCombinationOperator,0>::Set(this: &v2->m_hCombinationOperator, h: BufferType);
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hCombinationOperator.m_handle);
    if ( v9 != nullptr )
      i = (int)&v9[-1] + 64;
    else
      i = 0;
    m_Size = v2->m_operatorList.m_Size;
    m_nAllocationCount = v2->m_operatorList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_operatorList,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_operatorList.m_Size;
    m_pMemory = p_m_operatorList->m_pMemory;
    v13 = v2->m_operatorList.m_Size - m_Size - 1;
    v2->m_operatorList.m_pElements = v2->m_operatorList.m_Memory.m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
    v14 = (int *)&p_m_operatorList->m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = i;
    for ( ia = 0; ia < CDmeCombinationOperator::GetOperationTargetCount(this: pOp); ++ia )
    {
      OperationTarget = CDmeCombinationOperator::GetOperationTarget(this: pOp, nTargetIndex: ia);
      v16 = OperationTarget;
      if ( OperationTarget != nullptr && OperationTarget->IsA(this: OperationTarget, a2: CDmeFlexRules::m_classType) )
      {
        pDmeFlexRules = (CDmeFlexRules *)((char *)&v16[-1] + 64);
        if ( v16 != (CDmElement *)4 )
        {
          v17 = p_m_operatorList[1].m_pMemory;
          v18 = p_m_operatorList->m_nAllocationCount;
          if ( (int)v17 + 1 > v18 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_operatorList, num: (int)v17 - v18 + 1);
          ++p_m_operatorList[1].m_pMemory;
          v19 = p_m_operatorList->m_pMemory;
          v20 = (char *)p_m_operatorList[1].m_pMemory - (char *)v17 - 1;
          p_m_operatorList[1].m_nAllocationCount = (int)p_m_operatorList->m_pMemory;
          if ( v20 > 0 )
            _V_memmove(dest: &v19[(_DWORD)v17 + 1], src: &v19[(_DWORD)v17], count: 4 * v20);
          v21 = (CDmeFlexRules **)&p_m_operatorList->m_pMemory[(_DWORD)v17];
          if ( v21 != nullptr )
            *v21 = pDmeFlexRules;
          v22 = pDmeFlexRules;
          v23 = pDmeFlexRules->m_eDeltaStates.m_Storage.m_Size;
          for ( j = 0; j < v23; ++j )
          {
            if ( j >= 0 && j < v23 )
            {
              v25 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: v22->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[j]);
              v26 = v25;
              if ( v25 != nullptr && v25->IsA(this: v25, a2: CDmeFlexRuleBase::m_classType) )
              {
                v33 = (vgui::TreeNode *)((char *)&v26[-1] + 64);
                if ( v26 != (CDmElement *)4 )
                {
                  v27 = p_m_operatorList[1].m_pMemory;
                  v28 = p_m_operatorList->m_nAllocationCount;
                  if ( (int)v27 + 1 > v28 )
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_operatorList, num: (int)v27 - v28 + 1);
                  ++p_m_operatorList[1].m_pMemory;
                  v29 = p_m_operatorList->m_pMemory;
                  v30 = (char *)p_m_operatorList[1].m_pMemory - (char *)v27 - 1;
                  p_m_operatorList[1].m_nAllocationCount = (int)p_m_operatorList->m_pMemory;
                  if ( v30 > 0 )
                    _V_memmove(dest: &v29[(_DWORD)v27 + 1], src: &v29[(_DWORD)v27], count: 4 * v30);
                  v31 = &p_m_operatorList->m_pMemory[(_DWORD)v27];
                  if ( v31 != nullptr )
                    *v31 = v33;
                }
              }
            }
            v22 = pDmeFlexRules;
            v23 = pDmeFlexRules->m_eDeltaStates.m_Storage.m_Size;
          }
          v2 = this;
        }
      }
    }
    if ( CBaseAnimationSetControl::GetAnimationSetClip(this: v2->m_pController) != nullptr )
    {
      LOBYTE(v33) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
      CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::AddNewAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::SortAnimationSetControls(this: v2);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: (bool)v33);
    }
    v32 = CBaseAnimationSetControl::GetAnimationSetClip(this: v2->m_pController);
    CBaseAnimationSetEditor::ChangeAnimationSetClip(this: v2, pFilmClip: v32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E040
// Name: public: virtual void CDmeCombinationOperatorPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationOperatorPanel::OnTick(
        CDmeCombinationOperatorPanel *this@<ecx>,
        DmElementHandle_t m_handle@<edi>)
{
  CDmElement *v3; // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  CDmElement *v6; // eax
  CDmeCombinationOperator *v7; // ecx
  int v8; // edi
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  bool SliderValues; // al
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  int v13; // eax
  CDmeCombinationOperator *v14; // ecx
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  CDmElement *v17; // eax
  CDmeCombinationOperator *v18; // ecx
  CBaseAnimSetAttributeSliderPanel *v19; // eax
  bool v20; // al
  CDmElement *v21; // eax
  CDmeCombinationOperator *v22; // ecx
  DmElementHandle_t v23; // eax
  CDmElement *v24; // eax
  vgui::TreeNode *v25; // edi
  int m_Size; // eax
  int v27; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v29; // eax
  vgui::TreeNode **v30; // eax
  bool v31; // al
  IDataModel_vtbl *v32; // edx
  int v33; // [esp+20h] [ebp-70h]
  int v34; // [esp+20h] [ebp-70h]
  AttributeValue_t multiValue; // [esp+30h] [ebp-60h] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > operators; // [esp+58h] [ebp-38h] BYREF
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > v38; // [esp+6Ch] [ebp-24h] BYREF
  CDisableUndoScopeGuard guard; // [esp+80h] [ebp-10h]
  int nCombinationControlCount; // [esp+88h] [ebp-8h]
  int iCurrentControlIndex; // [esp+8Ch] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
  if ( v3 != nullptr && v3 != (CDmElement *)4 )
  {
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    guard.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
    if ( v6 != nullptr )
      v7 = (CDmeCombinationOperator *)((char *)&v6[-1] + 64);
    else
      v7 = nullptr;
    v8 = 0;
    nCombinationControlCount = CDmeCombinationOperator::GetControlCount(this: v7);
    iCurrentControlIndex = 0;
    if ( nCombinationControlCount > 0 )
    {
      do
      {
        memset(&operators, 0, sizeof(operators));
        v38.m_Memory.m_pMemory = nullptr;
        v33 = iCurrentControlIndex;
        *(Quaternion *)&v38.m_Memory.m_nAllocationCount = quat_identity;
        AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this);
        SliderValues = CBaseAnimSetAttributeSliderPanel::GetSliderValues(
                         this: AttributeSlider,
                         pValue: (AttributeValue_t *)&operators,
                         nIndex: v33);
        ++iCurrentControlIndex;
        if ( SliderValues )
        {
          v11 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, DmElementHandle_t))g_pDataModel->GetElement)(
                  a1: g_pDataModel,
                  a2: this->m_hCombinationOperator.m_handle,
                  a3: m_handle);
          if ( v11 != 0 )
            v12 = (CDmeCombinationOperator *)(v11 - 4);
          else
            v12 = nullptr;
          if ( CDmeCombinationOperator::IsStereoControl(this: v12, nControlIndex: v8) )
          {
            m_handle = this->m_hCombinationOperator.m_handle;
            v13 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
            if ( v13 != 0 )
              v14 = (CDmeCombinationOperator *)(v13 - 4);
            else
              v14 = nullptr;
            CDmeCombinationOperator::SetControlValue(
              this: v14,
              nControlIndex: v8,
              flLeftValue: *(float *)&operators.m_Memory.m_nGrowSize,
              flRightValue: *(float *)&operators.m_Memory.m_nAllocationCount,
              type: COMBO_CONTROL_FIRST);
          }
          else
          {
            m_handle = this->m_hCombinationOperator.m_handle;
            v15 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
            if ( v15 != 0 )
              v16 = (CDmeCombinationOperator *)(v15 - 4);
            else
              v16 = nullptr;
            CDmeCombinationOperator::SetControlValue(
              this: v16,
              nControlIndex: v8,
              flValue: *(float *)&operators.m_Memory.m_pMemory,
              type: COMBO_CONTROL_FIRST);
          }
        }
        v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
        if ( v17 != nullptr )
          v18 = (CDmeCombinationOperator *)((char *)&v17[-1] + 64);
        else
          v18 = nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v18, nControlIndex: v8) )
        {
          memset(&multiValue, 0, 24);
          v34 = iCurrentControlIndex;
          multiValue.m_Quaternion = quat_identity;
          v19 = CBaseAnimationSetEditor::GetAttributeSlider(this);
          v20 = CBaseAnimSetAttributeSliderPanel::GetSliderValues(this: v19, pValue: &multiValue, nIndex: v34);
          ++iCurrentControlIndex;
          if ( v20 )
          {
            v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
            if ( v21 != nullptr )
              v22 = (CDmeCombinationOperator *)((char *)&v21[-1] + 64);
            else
              v22 = nullptr;
            CDmeCombinationOperator::SetMultiControlLevel(
              this: v22,
              nControlIndex: v8,
              flMultiLevel: multiValue.m_pValue[0],
              type: COMBO_CONTROL_FIRST);
          }
        }
        ++v8;
      }
      while ( v8 < nCombinationControlCount );
    }
    ((void (__thiscall *)(IDataModel *, _DWORD, DmElementHandle_t))g_pDataModel->SetUndoEnabled)(
      a1: g_pDataModel,
      a2: *(_DWORD *)&guard.m_bOldValue,
      a3: m_handle);
    if ( this->m_operatorList.m_Size != 0 )
    {
      guard.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
      g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: &this->m_operatorList);
      g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
      g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
      return;
    }
    v23 = this->m_hCombinationOperator.m_handle;
    memset(&v38, 0, sizeof(v38));
    v24 = g_pDataModel->GetElement(this: g_pDataModel, a2: v23);
    if ( v24 != nullptr )
      v25 = (vgui::TreeNode *)((char *)&v24[-1] + 64);
    else
      v25 = nullptr;
    m_Size = v38.m_Size;
    v27 = v38.m_Size;
    if ( v38.m_Size + 1 > v38.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: &v38.m_Memory,
        num: v38.m_Size - v38.m_Memory.m_nAllocationCount + 1);
      m_Size = v38.m_Size;
    }
    m_pMemory = v38.m_Memory.m_pMemory;
    v38.m_Size = m_Size + 1;
    v29 = m_Size - v27;
    v38.m_pElements = v38.m_Memory.m_pMemory;
    if ( v29 > 0 )
    {
      _V_memmove(dest: &v38.m_Memory.m_pMemory[v27 + 1], src: &v38.m_Memory.m_pMemory[v27], count: 4 * v29);
      m_pMemory = v38.m_Memory.m_pMemory;
    }
    v30 = &m_pMemory[v27];
    if ( v30 != nullptr )
      *v30 = v25;
    v31 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v32 = g_pDataModel->__vftable;
    guard.m_bOldValue = v31;
    v32->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDmElementFramework->SetOperators(
      this: g_pDmElementFramework,
      a2: (const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)&v38);
    g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: &v38);
  }
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
}

//------------------------------------------------------------------------------
// Address: 0x0047E400
// Name: public: CDmeDagEditPanel::CDmeDagEditPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmeDagEditPanel::CDmeDagEditPanel(
        CDmeDagEditPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v10; // edi
  CDmeDagRenderPanel *v11; // eax
  CDmeDagRenderPanel *v12; // eax
  vgui::PropertySheet *v13; // eax
  vgui::PropertySheet *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  vgui::PropertyPage *v17; // eax
  vgui::PropertyPage *v18; // eax
  vgui::PropertyPage *v19; // eax
  vgui::PropertyPage *v20; // eax
  CBaseAnimationSetControl *v21; // eax
  CBaseAnimationSetControl *v22; // edi
  CDmeCombinationOperatorPanel *v23; // eax
  CDmeCombinationOperatorPanel *v24; // eax
  CDmeAnimationListPanel *v25; // eax
  CDmeAnimationListPanel *v26; // eax
  CDmeAnimationListPanel *v27; // eax
  CDmeAnimationListPanel *v28; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeDagEditPanel_vtbl *)&CDmeDagEditPanel::`vftable';
  if ( `CDmeDagEditPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    v4->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeDagEditPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeDagEditPanel");
    v5->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeDagEditPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagEditPanel");
    v6->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(a1: (int)&savedregs);
  CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(a1: (int)&savedregs);
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PropertiesSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPropertiesSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pPropertiesSplitter, index: 1);
  v11 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v11 != nullptr )
    v12 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v11, pParent: v10, pName: "DagRenderPanel");
  else
    v12 = nullptr;
  this->m_pDagRenderPanel = v12;
  v13 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v13 != nullptr )
    v14 = vgui::PropertySheet::PropertySheet(this: v13, parent: Child, panelName: "EditorSheet", draggableTabs: false);
  else
    v14 = nullptr;
  this->m_pEditorSheet = v14;
  v14->AddActionSignalTarget_2(this: v14, a2: this);
  v15 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v15 != nullptr )
    v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pEditorSheet, panelName: "AnimationPage");
  else
    v16 = nullptr;
  this->m_pAnimationPage = v16;
  v17 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v17 != nullptr )
    v18 = vgui::PropertyPage::PropertyPage(this: v17, parent: this->m_pEditorSheet, panelName: "AnimationSetEditor");
  else
    v18 = nullptr;
  this->m_pCombinationPage = v18;
  v19 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v19 != nullptr )
    v20 = vgui::PropertyPage::PropertyPage(this: v19, parent: this->m_pEditorSheet, panelName: "VertexAnimationPage");
  else
    v20 = nullptr;
  this->m_pVertexAnimationPage = v20;
  v21 = (CBaseAnimationSetControl *)MemAlloc_Alloc(nSize: 0xB4u);
  v22 = v21;
  if ( v21 != nullptr )
  {
    CBaseAnimationSetControl::CBaseAnimationSetControl(this: v21);
    v22->__vftable = (CBaseAnimationSetControl_vtbl *)&CCombinationOperatorControl::`vftable';
    v22[1].__vftable = nullptr;
    v22[1].m_hFilmClip.m_handle = 0;
    v22[1].m_pEditor = nullptr;
    v22[1].m_SelectionHistory.m_Memory.m_pMemory = nullptr;
    v22[1].m_SelectionHistory.m_Memory.m_nAllocationCount = 0;
  }
  else
  {
    v22 = nullptr;
  }
  v23 = (CDmeCombinationOperatorPanel *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v23 != nullptr )
    v24 = CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(
            this: v23,
            parent: this->m_pCombinationPage,
            panelName: "AnimationSetEditorPanel",
            pAnimationSetController: v22);
  else
    v24 = nullptr;
  this->m_pCombinationPanel = v24;
  v24->CreateToolsSubPanels(this: v24);
  v25 = (CDmeAnimationListPanel *)MemAlloc_Alloc(nSize: 0x18Cu);
  if ( v25 != nullptr )
    v26 = CDmeAnimationListPanel::CDmeAnimationListPanel(
            this: v25,
            pParent: this->m_pAnimationPage,
            pName: "AnimationListPanel");
  else
    v26 = nullptr;
  this->m_pAnimationListPanel = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  v27 = (CDmeAnimationListPanel *)MemAlloc_Alloc(nSize: 0x18Cu);
  if ( v27 != nullptr )
    v28 = CDmeAnimationListPanel::CDmeAnimationListPanel(
            this: v27,
            pParent: this->m_pVertexAnimationPage,
            pName: "VertexAnimationListPanel");
  else
    v28 = nullptr;
  this->m_pVertexAnimationListPanel = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  this->m_pCombinationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pCombinationPage,
    a2: "resource/dmedageditpanel_animationseteditorpage.res",
    a3: 0);
  this->m_pAnimationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pAnimationPage,
    a2: "resource/dmedageditpanel_animationpage.res",
    a3: 0);
  this->m_pVertexAnimationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pVertexAnimationPage,
    a2: "resource/dmedageditpanel_vertexanimationpage.res",
    a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmedageditpanel.res",
    dialogID: 0);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pAnimationPage,
    a3: "Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pCombinationPage,
    a3: "Combination",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pVertexAnimationPage,
    a3: "Vertex Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->SetActivePage(this: this->m_pEditorSheet, a2: this->m_pCombinationPage);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047E830
// Name: void RebuildControlList<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RebuildControlList<SelectionInfo_t>(
        CUtlMemory<vgui::TreeNode *,int> *controlList,
        CDmeFilmClip *pFilmClip)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // esi
  int m_pMemory; // eax
  int v4; // ebx
  CDmeElementRefHelper *v5; // edi
  CDmeTransform *v6; // eax
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v9; // ecx
  CDmElement *v10; // eax
  CExpressionCalculator *v11; // ebx
  CDmeElementRefHelper *v12; // eax
  CDmeElementRefHelper *v13; // edi
  DmElementHandle_t BufferType; // esi
  CDmElement *v15; // eax
  DmElementHandle_t v16; // ebx
  DmElementHandle_t v17; // eax
  CDmElement *v18; // eax
  vgui::TreeNode *v19; // ebx
  vgui::TreeNode **v20; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v22; // ecx
  int v23; // eax
  vgui::TreeNode **v24; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  int v26; // [esp+14h] [ebp-Ch]
  CDmaElementArray<CDmElement> *controls; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  CDmeAnimationSet *pAnimSet; // [esp+2Ch] [ebp+Ch]

  v2 = controlList;
  m_pMemory = (int)controlList[1].m_pMemory;
  v4 = 0;
  for ( i = m_pMemory; v4 < m_pMemory; ++v4 )
  {
    v5 = (CDmeElementRefHelper *)controlList->m_pMemory[v4];
    if ( v5 != nullptr )
    {
      if ( g_pDataModel != nullptr )
      {
        CDmeElementRefHelper::Unref(this: v5 + 4, hElement: *(DmElementHandle_t *)&v5[4], handleType: HT_WEAK);
        if ( g_pDataModel != nullptr )
          CDmeElementRefHelper::Unref(this: v5, hElement: *(_DWORD *)v5, handleType: HT_WEAK);
      }
      CUtlMemoryPool::Free(this: &SelectionInfo_t::s_Allocator, memBlock: v5);
      m_pMemory = i;
    }
  }
  traversal.m_pFilmClip = pFilmClip;
  controlList[1].m_pMemory = nullptr;
  traversal.m_nIndex = 0;
  v6 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pAnimSet = (CDmeAnimationSet *)v6;
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v6);
      m_Size = Position->m_Storage.m_Size;
      v9 = 0;
      controls = Position;
      v26 = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Position->m_Storage.m_Memory.m_pMemory[v9]);
          v11 = (CExpressionCalculator *)v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            v12 = (CDmeElementRefHelper *)CUtlMemoryPool::Alloc(this: &SelectionInfo_t::s_Allocator, amount: 0xCu);
            v13 = v12;
            if ( v12 != nullptr )
            {
              *(_DWORD *)v12 = -1;
              if ( pAnimSet != nullptr )
                BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
              else
                BufferType = DMELEMENT_HANDLE_INVALID;
              if ( BufferType != *(_DWORD *)v13 )
              {
                CDmeElementRefHelper::Unref(this: v13, hElement: *(_DWORD *)v13, handleType: HT_WEAK);
                *(_DWORD *)v13 = BufferType;
                if ( BufferType != DMELEMENT_HANDLE_INVALID )
                {
                  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
                  if ( v15 != nullptr && !v15->IsA(this: v15, a2: CDmeAnimationSet::m_classType) )
                    *(_DWORD *)v13 = -1;
                }
                CDmeElementRefHelper::Ref(this: v13, hElement: *(_DWORD *)v13, handleType: HT_WEAK);
              }
              *(_DWORD *)&v13[4] = -1;
              v16 = CCodecBuffer_Block::GetBufferType(this: v11);
              v17 = *(_DWORD *)&v13[4];
              if ( v16 != v17 )
              {
                CDmeElementRefHelper::Unref(this: v13 + 4, hElement: v17, handleType: HT_WEAK);
                *(_DWORD *)&v13[4] = v16;
                if ( v16 != DMELEMENT_HANDLE_INVALID )
                {
                  v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: v16);
                  if ( v18 != nullptr && !v18->IsA(this: v18, a2: CDmElement::m_classType) )
                    *(_DWORD *)&v13[4] = -1;
                }
                CDmeElementRefHelper::Ref(this: v13 + 4, hElement: *(DmElementHandle_t *)&v13[4], handleType: HT_WEAK);
              }
              v2 = controlList;
              *(_DWORD *)&v13[8] = 0;
              v19 = (vgui::TreeNode *)v13;
            }
            else
            {
              v19 = nullptr;
            }
            v20 = v2[1].m_pMemory;
            m_nAllocationCount = v2->m_nAllocationCount;
            if ( (int)v20 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v2, num: (int)v20 - m_nAllocationCount + 1);
            ++v2[1].m_pMemory;
            v22 = v2->m_pMemory;
            v23 = (char *)v2[1].m_pMemory - (char *)v20 - 1;
            v2[1].m_nAllocationCount = (int)v2->m_pMemory;
            if ( v23 > 0 )
              _V_memmove(dest: &v22[(_DWORD)v20 + 1], src: &v22[(_DWORD)v20], count: 4 * v23);
            v24 = &v2->m_pMemory[(_DWORD)v20];
            if ( v24 != nullptr )
              *v24 = v19;
          }
          v9 = i + 1;
          i = v9;
          if ( v9 >= v26 )
            break;
          Position = controls;
        }
      }
      pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( pAnimSet == nullptr )
        break;
      v6 = (CDmeTransform *)pAnimSet;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EAA0
// Name: void AddMissingControls<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddMissingControls<SelectionInfo_t>(
        CUtlMemory<vgui::TreeNode *,int> *controlList,
        CDmeFilmClip *pFilmClip)
{
  CDmeTransform *v2; // eax
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v5; // ecx
  CDmElement *v6; // eax
  CExpressionCalculator *v7; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  int v9; // edi
  CDmeElementRefHelper *v10; // eax
  CDmeElementRefHelper *v11; // edi
  DmElementHandle_t BufferType; // esi
  CDmElement *v13; // eax
  DmElementHandle_t v14; // ebx
  DmElementHandle_t v15; // eax
  CDmElement *v16; // eax
  vgui::TreeNode *v17; // ebx
  vgui::TreeNode **v18; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // edi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-18h] BYREF
  int nControls; // [esp+14h] [ebp-10h]
  int m_pMemory; // [esp+18h] [ebp-Ch]
  CDmaElementArray<CDmElement> *controls; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  CDmeAnimationSet *pAnimSet; // [esp+30h] [ebp+Ch]

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v2 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pAnimSet = (CDmeAnimationSet *)v2;
  if ( v2 != nullptr )
  {
    while ( 1 )
    {
      Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v2);
      m_Size = Position->m_Storage.m_Size;
      v5 = 0;
      controls = Position;
      nControls = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Position->m_Storage.m_Memory.m_pMemory[v5]);
          v7 = (CExpressionCalculator *)v6;
          if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
          {
            v8 = controlList;
            v9 = 0;
            m_pMemory = (int)controlList[1].m_pMemory;
            if ( m_pMemory <= 0 )
            {
LABEL_12:
              v10 = (CDmeElementRefHelper *)CUtlMemoryPool::Alloc(this: &SelectionInfo_t::s_Allocator, amount: 0xCu);
              v11 = v10;
              if ( v10 != nullptr )
              {
                *(_DWORD *)v10 = -1;
                if ( pAnimSet != nullptr )
                  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
                else
                  BufferType = DMELEMENT_HANDLE_INVALID;
                if ( BufferType != *(_DWORD *)v11 )
                {
                  CDmeElementRefHelper::Unref(this: v11, hElement: *(_DWORD *)v11, handleType: HT_WEAK);
                  *(_DWORD *)v11 = BufferType;
                  if ( BufferType != DMELEMENT_HANDLE_INVALID )
                  {
                    v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
                    if ( v13 != nullptr && !v13->IsA(this: v13, a2: CDmeAnimationSet::m_classType) )
                      *(_DWORD *)v11 = -1;
                  }
                  CDmeElementRefHelper::Ref(this: v11, hElement: *(_DWORD *)v11, handleType: HT_WEAK);
                }
                *(_DWORD *)&v11[4] = -1;
                v14 = CCodecBuffer_Block::GetBufferType(this: v7);
                v15 = *(_DWORD *)&v11[4];
                if ( v14 != v15 )
                {
                  CDmeElementRefHelper::Unref(this: v11 + 4, hElement: v15, handleType: HT_WEAK);
                  *(_DWORD *)&v11[4] = v14;
                  if ( v14 != DMELEMENT_HANDLE_INVALID )
                  {
                    v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
                    if ( v16 != nullptr && !v16->IsA(this: v16, a2: CDmElement::m_classType) )
                      *(_DWORD *)&v11[4] = -1;
                  }
                  CDmeElementRefHelper::Ref(this: v11 + 4, hElement: *(DmElementHandle_t *)&v11[4], handleType: HT_WEAK);
                }
                v8 = controlList;
                *(_DWORD *)&v11[8] = 0;
                v17 = (vgui::TreeNode *)v11;
              }
              else
              {
                v17 = nullptr;
              }
              v18 = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)v18 + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)v18 - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v20 = v8->m_pMemory;
              v21 = (char *)v8[1].m_pMemory - (char *)v18 - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v21 > 0 )
                _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
              v22 = &v8->m_pMemory[(_DWORD)v18];
              if ( v22 != nullptr )
                *v22 = v17;
            }
            else
            {
              while ( (CExpressionCalculator *)g_pDataModel->GetElement(
                                                 this: g_pDataModel,
                                                 a2: *(_DWORD *)&controlList->m_pMemory[v9]->vgui::Panel::m_RegisterClass) != v7 )
              {
                if ( ++v9 >= m_pMemory )
                  goto LABEL_12;
              }
            }
          }
          v5 = i + 1;
          i = v5;
          if ( v5 >= nControls )
            break;
          Position = controls;
        }
      }
      pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( pAnimSet == nullptr )
        break;
      v2 = (CDmeTransform *)pAnimSet;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047ECE0
// Name: public: virtual void CCombinationOperatorControl::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombinationOperatorControl::ChangeAnimationSetClip(
        CCombinationOperatorControl *this,
        CDmeFilmClip *pFilmClip)
{
  RebuildControlList<SelectionInfo_t>(
    controlList: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FullControlList,
    pFilmClip);
  CBaseAnimationSetControl::ChangeAnimationSetClip(this, pFilmClip);
}

//------------------------------------------------------------------------------
// Address: 0x0047ED10
// Name: public: virtual void CCombinationOperatorControl::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombinationOperatorControl::OnControlsAddedOrRemoved(CCombinationOperatorControl *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_FullControlList; // edi
  CDmeFilmClip *v3; // eax

  p_m_FullControlList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FullControlList;
  RemoveNullControls<SelectionInfo_t>(controlList: &this->m_FullControlList);
  v3 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  AddMissingControls<SelectionInfo_t>(controlList: p_m_FullControlList, pFilmClip: v3);
  CBaseAnimationSetControl::OnControlsAddedOrRemoved(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047ED50
// Name: protected: void CDmeDagEditPanel::SetMakefileRootElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetMakefileRootElement(CDmeDagEditPanel *this, CDmElement *pRoot)
{
  CDmeAnimationList *Value; // eax
  CDmeAnimationList *v4; // eax
  CDmeCombinationOperator *v5; // eax

  Value = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "animationList");
  CDmeDagEditPanel::SetAnimationList(this, pAnimationList: Value);
  v4 = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "vertexAnimationList");
  CDmeDagEditPanel::SetVertexAnimationList(this, pAnimationList: v4);
  v5 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: pRoot, pAttributeName: "combinationOperator");
  CDmeCombinationOperatorPanel::SetCombinationOperator(this: this->m_pCombinationPanel, pOp: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0047EDA0
// Name: public: void CDmeDagEditPanel::SetDmeElement(class CDmeDCCMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetDmeElement(CDmeDagEditPanel *this, CDmeDag *pDCCMakefile)
{
  CDmElement *OutputElement; // eax
  CDmElement *v4; // edi
  CDmeAnimationList *Value; // eax
  CDmeAnimationList *v6; // eax
  CDmeCombinationOperator *v7; // eax

  CDmeDagRenderPanel::SetDmeElement(this: this->m_pDagRenderPanel, pDCCMakefile);
  OutputElement = CDmeMakefile::GetOutputElement(this: (CDmeMakefile *)pDCCMakefile, bCreateIfNecessary: true);
  v4 = OutputElement;
  if ( OutputElement != nullptr )
  {
    Value = CDmElement::GetValueElement<CDmeAnimationList>(this: OutputElement, pAttributeName: "animationList");
    CDmeDagEditPanel::SetAnimationList(this, pAnimationList: Value);
    v6 = CDmElement::GetValueElement<CDmeAnimationList>(this: v4, pAttributeName: "vertexAnimationList");
    CDmeDagEditPanel::SetVertexAnimationList(this, pAnimationList: v6);
    v7 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: v4, pAttributeName: "combinationOperator");
    CDmeCombinationOperatorPanel::SetCombinationOperator(this: this->m_pCombinationPanel, pOp: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484450
// Name: protected: void CBaseAnimationSetControl::ApplyTransformSliderValue<class Quaternion>(class CAttributeSlider __near *,class CDmeTransformControl __near *,bool,bool,bool __near &,enum AnimationControlType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyTransformSliderValue<Quaternion>(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        vgui::BuildGroup *pTranformControl,
        DmeTime_t bUsePreviewValue,
        bool bForce,
        bool *valuesChanged,
        AnimationControlType_t type)
{
  AnimationControlType_t v7; // ebx
  CDmAttribute *PositionAttr; // esi
  CDmeChannel *PositionChannel; // eax
  CDmeChannel *v10; // edi
  ChannelMode_t Mode; // eax
  char v12; // cl
  DmeTime_t *CurrentTime; // eax
  Quaternion *v14; // eax
  LogComponents_t v15; // eax
  Quaternion maskedValue; // [esp+Ch] [ebp-30h] BYREF
  Quaternion currentValue; // [esp+1Ch] [ebp-20h] BYREF
  Quaternion value; // [esp+2Ch] [ebp-10h] BYREF

  v7 = type;
  if ( type == ANIM_CONTROL_COUNT )
  {
    PositionAttr = (CDmAttribute *)CDmeTransformControl::GetPositionAttr(this: pTranformControl);
    PositionChannel = CDmeTransformControl::GetPositionChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  else
  {
    if ( type != ANIM_CONTROL_TXFORM_ORIENTATION )
      return;
    PositionAttr = CDmeTransformControl::GetOrientationAttr(this: (CDmeTransformControl *)pTranformControl);
    PositionChannel = CDmeTransformControl::GetOrientationChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  v10 = PositionChannel;
  if ( PositionAttr != nullptr )
  {
    if ( PositionChannel != nullptr )
    {
      Mode = CDmeChannel::GetMode(this: PositionChannel);
      if ( Mode != CM_PASS && Mode != CM_RECORD )
      {
        v12 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      Mode = CM_PASS;
    }
    v12 = 1;
LABEL_12:
    if ( Mode == CM_PLAY )
    {
      value = *CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
      CurrentTime = CDmeChannel::GetCurrentTime(this: v10, result: &bUsePreviewValue);
      CDmeChannel::GetPlaybackValueAtTime<Quaternion>(this: v10, time: (DmeTime_t)CurrentTime->m_tms, &value);
      CAttributeSlider::SetValue(this: pSlider, type: v7, quat: &value);
      CDmAttribute::SetValue<Quaternion>(this: PositionAttr, &value);
    }
    else if ( v12 != 0 )
    {
      if ( LOBYTE(bUsePreviewValue.m_tms) != 0 )
        CAttributeSlider::GetPreview(this: pSlider, type: v7, out: &value);
      else
        CAttributeSlider::GetValue(this: pSlider, type: v7, out: &value);
      v14 = (Quaternion *)CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
      if ( Quaternion::operator!=(this: v14, src: &value) || bForce )
      {
        *valuesChanged = bForce;
        currentValue = *CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
        v15 = CAttributeSlider::VisibleComponents(this: pSlider);
        MaskValue<Quaternion>(result: &maskedValue, &value, curQuat: &currentValue, componentFlags: v15);
        CDmAttribute::SetValue<Quaternion>(this: PositionAttr, value: &maskedValue);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004845B0
// Name: protected: void CBaseAnimationSetControl::ApplyTransformSliderValue<class Vector>(class CAttributeSlider __near *,class CDmeTransformControl __near *,bool,bool,bool __near &,enum AnimationControlType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyTransformSliderValue<Vector>(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        vgui::BuildGroup *pTranformControl,
        DmeTime_t bUsePreviewValue,
        bool bForce,
        bool *valuesChanged,
        AnimationControlType_t type)
{
  AnimationControlType_t v7; // ebx
  CDmAttribute *PositionAttr; // edi
  CDmeChannel *PositionChannel; // eax
  CDmeChannel *v10; // esi
  ChannelMode_t Mode; // eax
  char v12; // cl
  DmeTime_t *CurrentTime; // eax
  CDmaVar<Vector> *v14; // eax
  char v15; // al
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  Vector maskedValue; // [esp+18h] [ebp-18h] BYREF
  Vector out; // [esp+24h] [ebp-Ch] BYREF
  Vector currentValue; // 0:^14.12

  v7 = type;
  if ( type == ANIM_CONTROL_COUNT )
  {
    PositionAttr = (CDmAttribute *)CDmeTransformControl::GetPositionAttr(this: pTranformControl);
    PositionChannel = CDmeTransformControl::GetPositionChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  else
  {
    if ( type != ANIM_CONTROL_TXFORM_ORIENTATION )
      return;
    PositionAttr = CDmeTransformControl::GetOrientationAttr(this: (CDmeTransformControl *)pTranformControl);
    PositionChannel = CDmeTransformControl::GetOrientationChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  v10 = PositionChannel;
  if ( PositionAttr != nullptr )
  {
    if ( PositionChannel != nullptr )
    {
      Mode = CDmeChannel::GetMode(this: PositionChannel);
      if ( Mode != CM_PASS && Mode != CM_RECORD )
      {
        v12 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      Mode = CM_PASS;
    }
    v12 = 1;
LABEL_12:
    if ( Mode == CM_PLAY )
    {
      maskedValue = CDmAttribute::GetValue<Vector>(this: PositionAttr)->m_Storage;
      CurrentTime = CDmeChannel::GetCurrentTime(this: v10, result: &bUsePreviewValue);
      CDmeChannel::GetPlaybackValueAtTime<Vector>(this: v10, time: (DmeTime_t)CurrentTime->m_tms, value: &maskedValue);
      CAttributeSlider::SetValue(this: pSlider, type: v7, vec: &maskedValue);
      CDmAttribute::SetValue<Vector>(this: PositionAttr, value: &maskedValue);
    }
    else if ( v12 != 0 )
    {
      if ( LOBYTE(bUsePreviewValue.m_tms) != 0 )
        CAttributeSlider::GetPreview(this: pSlider, type: v7, &out);
      else
        CAttributeSlider::GetValue(this: pSlider, type: v7, &out);
      v14 = CDmAttribute::GetValue<Vector>(this: PositionAttr);
      if ( out.x != v14->m_Storage.x || out.y != v14->m_Storage.y || out.z != v14->m_Storage.z || bForce )
      {
        *valuesChanged = bForce;
        currentValue = CDmAttribute::GetValue<Vector>(this: PositionAttr)->m_Storage;
        v15 = CAttributeSlider::VisibleComponents(this: pSlider);
        if ( (v15 & 1) != 0 )
          x = out.x;
        else
          x = currentValue.x;
        maskedValue.x = x;
        if ( (v15 & 2) != 0 )
          y = out.y;
        else
          y = currentValue.y;
        maskedValue.y = y;
        if ( (v15 & 4) != 0 )
          z = out.z;
        else
          z = currentValue.z;
        maskedValue.z = z;
        CDmAttribute::SetValue<Vector>(this: PositionAttr, value: &maskedValue);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00681AF0
// Name: _CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__()
{
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    sg.m_pControl->FireControlSelectionChangedListeners(this: sg.m_pControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BE10
// Name: class CDmeAnimationSet __near * CastElement<class CDmeAnimationSet>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl CastElement<CDmeAnimationSet>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeAnimationSet::m_classType.u.m_Id) )
  {
    return (CDmeAnimationSet *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00681B10
// Name: _dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__()
{
  ConVar::~ConVar(this: &ifm_attributeslider_sensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x00681B20
// Name: _dynamic_atexit_destructor_for__ifm_attributeslider_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_attributeslider_legacy__()
{
  ConVar::~ConVar(this: &ifm_attributeslider_legacy);
}

//------------------------------------------------------------------------------
// Address: 0x00681B30
// Name: _dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__()
{
  ConVar::~ConVar(this: &ifm_threaded_updatecontrolvalues);
}

//------------------------------------------------------------------------------
// Address: 0x00681B70
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

//------------------------------------------------------------------------------
// Address: 0x00681B80
// Name: _dynamic_atexit_destructor_for__s_AssetCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_AssetCache__()
{
  CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::~CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>(this: &s_AssetCache.m_CachedAssets);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &s_AssetCache.m_usedAssets);
  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::~CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>(this: &s_AssetCache.m_ModList);
}

//------------------------------------------------------------------------------
// Address: 0x00681BA0
// Name: _dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__()
{
  CTextureReference::~CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104813C0
// Name: public: static char const __near * CDmeDagEditPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeDagEditPanel::GetPanelClassName()
{
  return "CDmeDagEditPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104813D0
// Name: public: static char const __near * CDmeAnimationListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeAnimationListPanel::GetPanelClassName()
{
  return "CDmeAnimationListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104813E0
// Name: public: char const __near * CDmeAnimationListPanel::GetSelectedAnimation(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDmeAnimationListPanel::GetSelectedAnimation(CDmeAnimationListPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pAnimationList->GetSelectedItemsCount(this: this->m_pAnimationList) == 0 )
    return (char *)&var;
  v3 = this->m_pAnimationList->GetSelectedItem(this: this->m_pAnimationList, a2: 0);
  v4 = this->m_pAnimationList->GetItem(this: this->m_pAnimationList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "name", defaultValue: &var);
}

//------------------------------------------------------------------------------
// Address: 0x10481440
// Name: private: virtual void CDmeAnimationListPanel::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::OnItemSelected(CDmeAnimationListPanel *this)
{
  char *String; // edi
  int v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pAnimationList->GetSelectedItemsCount(this: this->m_pAnimationList) != 0 )
  {
    v3 = this->m_pAnimationList->GetSelectedItem(this: this->m_pAnimationList, a2: 0);
    v4 = this->m_pAnimationList->GetItem(this: this->m_pAnimationList, a2: v3);
    String = KeyValues::GetString(this: v4, keyName: "name", defaultValue: &var);
  }
  else
  {
    String = (char *)&var;
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(this: v5, setName: "AnimationSelected", firstKey: "animationName", firstValue: String);
    this->PostActionSignal(this, a2: v6);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104814E0
// Name: private: virtual void CDmeAnimationListPanel::OnItemDeselected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::OnItemDeselected(CDmeAnimationListPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "AnimationDeselected");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481520
// Name: public: static char const __near * CDmeCombinationOperatorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeCombinationOperatorPanel::GetPanelClassName()
{
  return "CDmeCombinationOperatorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10481530
// Name: public: virtual void CDmeDagEditPanel::SetDmeElement(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetDmeElement(CDmeDagEditPanel *this, CDmeDag *pScene)
{
  CDmeDagRenderPanel::SetDmeElement(this: this->m_pDagRenderPanel, pScene);
}

//------------------------------------------------------------------------------
// Address: 0x10481540
// Name: protected: virtual void CDmeDagEditPanel::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnPageChanged(CDmeDagEditPanel *this)
{
  char *v2; // eax
  char *SelectedAnimation; // [esp-4h] [ebp-8h]

  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pCombinationPage )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: &var);
LABEL_3:
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: &var);
    return;
  }
  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pAnimationPage )
  {
    SelectedAnimation = CDmeAnimationListPanel::GetSelectedAnimation(this: this->m_pAnimationListPanel);
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: SelectedAnimation);
    goto LABEL_3;
  }
  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pVertexAnimationPage )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: &var);
    v2 = CDmeAnimationListPanel::GetSelectedAnimation(this: this->m_pVertexAnimationListPanel);
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104815F0
// Name: protected: virtual void CDmeDagEditPanel::OnAnimationSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnAnimationSelected(CDmeDagEditPanel *this, KeyValues *pKeyValues)
{
  CDmeAnimationListPanel *Ptr; // edi
  char *String; // eax

  Ptr = (CDmeAnimationListPanel *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  String = KeyValues::GetString(this: pKeyValues, keyName: "animationName", defaultValue: &var);
  if ( Ptr == this->m_pAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: String);
  }
  else if ( Ptr == this->m_pVertexAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481660
// Name: protected: virtual void CDmeDagEditPanel::OnAnimationDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnAnimationDeselected(CDmeDagEditPanel *this, KeyValues *pKeyValues)
{
  CDmeAnimationListPanel *Ptr; // eax

  Ptr = (CDmeAnimationListPanel *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: &var);
  }
  else if ( Ptr == this->m_pVertexAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: &var);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481740
// Name: public: class CDmAttribute __near * CDmElement::InitValue<float>(char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<float>(CDmElement *this, const char *pAttributeName, float *value)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104817C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeDagEditPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeDagEditPanel::GetMessageMap(CDmeDagEditPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeDagEditPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagEditPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeDagEditPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
  `CDmeDagEditPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104817F0
// Name: public: virtual struct PanelAnimationMap __near * CDmeDagEditPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeDagEditPanel::GetAnimMap(CDmeDagEditPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeDagEditPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10481800
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeDagEditPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeDagEditPanel::GetKBMap(CDmeDagEditPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeDagEditPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagEditPanel::GetKBMap'::`2'::s_pMap;
  `CDmeDagEditPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagEditPanel");
  `CDmeDagEditPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10481830
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeAnimationListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeAnimationListPanel::GetMessageMap(CDmeAnimationListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeAnimationListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeAnimationListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeAnimationListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
  `CDmeAnimationListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10481860
// Name: public: virtual struct PanelAnimationMap __near * CDmeAnimationListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeAnimationListPanel::GetAnimMap(CDmeAnimationListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeAnimationListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10481870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeAnimationListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeAnimationListPanel::GetKBMap(CDmeAnimationListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeAnimationListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeAnimationListPanel::GetKBMap'::`2'::s_pMap;
  `CDmeAnimationListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeAnimationListPanel");
  `CDmeAnimationListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10481920
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(
        CDmeCombinationOperatorPanel *this,
        CDmElement *pControlElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // edi
  CDmElement *v5; // eax
  CDmeCombinationOperator *v6; // eax
  int ComboOpControlIndexForAnimSetControl; // edi
  CDmElement *v8; // eax
  CDmeCombinationOperator *v9; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v14; // eax
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // eax
  CDmeCombinationOperator *v19; // ecx
  CDmAttribute *v20; // eax
  int v21; // eax
  CDmeCombinationOperator *v22; // ecx
  Vector *StereoControlValue; // edi
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-1Ch]
  DmElementHandle_t v28; // [esp-4h] [ebp-1Ch]
  float flDefaultValue; // [esp+Ch] [ebp-Ch] BYREF
  float flValue; // [esp+10h] [ebp-8h] BYREF
  bool bIsStereoControl; // [esp+17h] [ebp-1h]

  v2 = pControlElement;
  m_pAsString = &var;
  if ( pControlElement->m_Name.m_Storage.u.m_Id != -1 )
    m_pAsString = pControlElement->m_Name.m_Storage.u.m_pAsString;
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
  if ( v5 != nullptr )
    v6 = (CDmeCombinationOperator *)((char *)&v5[-1] + 64);
  else
    v6 = nullptr;
  ComboOpControlIndexForAnimSetControl = FindComboOpControlIndexForAnimSetControl(
                                           pComboOp: v6,
                                           pControlName: m_pAsString,
                                           pIsMulti: (bool *)&pControlElement + 3);
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
  if ( v8 != nullptr )
    v9 = (CDmeCombinationOperator *)((char *)&v8[-1] + 64);
  else
    v9 = nullptr;
  flDefaultValue = CDmeCombinationOperator::GetControlDefaultValue(
                     this: v9,
                     nControl: ComboOpControlIndexForAnimSetControl);
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hCombinationOperator.m_handle;
  if ( HIBYTE(pControlElement) != 0 )
  {
    v11 = ((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
    if ( v11 != 0 )
      v12 = (CDmeCombinationOperator *)(v11 - 4);
    else
      v12 = nullptr;
    flValue = CDmeCombinationOperator::GetMultiControlLevel(
                this: v12,
                nControlIndex: ComboOpControlIndexForAnimSetControl,
                type: COMBO_CONTROL_FIRST);
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "value");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v2, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value: &flValue);
    }
    flValue = 0.5;
    v14 = CDmElement::FindAttribute(this: v2, pAttributeName: "defaultValue");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: v2, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v14, value: &flValue);
    }
  }
  else
  {
    v15 = ((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
    if ( v15 != 0 )
      v16 = (CDmeCombinationOperator *)(v15 - 4);
    else
      v16 = nullptr;
    bIsStereoControl = CDmeCombinationOperator::IsStereoControl(
                         this: v16,
                         nControlIndex: ComboOpControlIndexForAnimSetControl);
    if ( CDmElement::HasAttribute(this: v2, pAttributeName: "rightValue", type: AT_UNKNOWN) != bIsStereoControl )
    {
      v17 = g_pDataModel->GetElement;
      v28 = this->m_hCombinationOperator.m_handle;
      if ( bIsStereoControl )
      {
        v21 = ((int (__stdcall *)(DmElementHandle_t))v17)(a1: v28);
        if ( v21 != 0 )
          v22 = (CDmeCombinationOperator *)(v21 - 4);
        else
          v22 = nullptr;
        StereoControlValue = CDmeCombinationOperator::GetStereoControlValue(
                               this: v22,
                               nControlIndex: ComboOpControlIndexForAnimSetControl,
                               type: COMBO_CONTROL_FIRST);
        v24 = CDmElement::FindAttribute(this: v2, pAttributeName: "leftValue");
        if ( v24 != nullptr
          || (v24 = CDmElement::CreateAttribute(this: v2, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v24, value: &StereoControlValue->x);
        }
        v25 = CDmElement::FindAttribute(this: v2, pAttributeName: "rightValue");
        if ( v25 != nullptr
          || (v25 = CDmElement::CreateAttribute(this: v2, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v25, value: &StereoControlValue->y);
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "value");
      }
      else
      {
        v18 = ((int (__stdcall *)(DmElementHandle_t))v17)(a1: v28);
        if ( v18 != 0 )
          v19 = (CDmeCombinationOperator *)(v18 - 4);
        else
          v19 = nullptr;
        flValue = CDmeCombinationOperator::GetControlValue(
                    this: v19,
                    nControlIndex: ComboOpControlIndexForAnimSetControl,
                    type: COMBO_CONTROL_FIRST);
        v20 = CDmElement::FindAttribute(this: v2, pAttributeName: "value");
        if ( v20 != nullptr
          || (v20 = CDmElement::CreateAttribute(this: v2, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v20, value: &flValue);
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "leftValue");
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "rightValue");
      }
    }
    v26 = CDmElement::FindAttribute(this: v2, pAttributeName: "defaultValue");
    if ( v26 != nullptr
      || (v26 = CDmElement::CreateAttribute(this: v2, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v26, value: &flDefaultValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481B90
// Name: private: void CDmeCombinationOperatorPanel::SortAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::SortAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeCombinationOperatorPanel *v1; // edi
  CBaseAnimationSetControl *m_pController; // ecx
  CDmeTransform *v3; // ebx
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // esi
  CDmElement *v6; // eax
  CDmeCombinationOperator *v7; // ecx
  void *v8; // esp
  DmElementHandle_t *v9; // eax
  _DWORD *v10; // esi
  CDmElement *v11; // eax
  CDmeCombinationOperator *v12; // ecx
  const char *ControlName; // edi
  CExpressionCalculator *Control; // eax
  CDmElement *v15; // eax
  CDmeCombinationOperator *v16; // ecx
  CExpressionCalculator *v17; // eax
  _BYTE v18[12]; // [esp+0h] [ebp-12Ch] BYREF
  char pMultiControlName[256]; // [esp+Ch] [ebp-120h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+10Ch] [ebp-20h] BYREF
  DmElementHandle_t *pElements; // [esp+114h] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+118h] [ebp-14h]
  int nControlCount; // [esp+11Ch] [ebp-10h]
  int nCombinationControlCount; // [esp+120h] [ebp-Ch]
  CDmeCombinationOperatorPanel *v25; // [esp+124h] [ebp-8h]
  int i; // [esp+128h] [ebp-4h]

  v1 = this;
  m_pController = this->m_pController;
  v25 = v1;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  v3 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  v3->OnElementUnserialized(this: v3);
  Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v3);
  m_Size = Position->m_Storage.m_Size;
  controls = Position;
  nControlCount = m_Size;
  if ( m_Size != 0 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
    if ( v6 != nullptr )
      v7 = (CDmeCombinationOperator *)((char *)&v6[-1] + 64);
    else
      v7 = nullptr;
    nCombinationControlCount = CDmeCombinationOperator::GetControlCount(this: v7);
    v8 = alloca(4 * m_Size);
    v9 = (DmElementHandle_t *)v18;
    pElements = (DmElementHandle_t *)v18;
    i = 0;
    if ( nCombinationControlCount > 0 )
    {
      v10 = v18;
      while ( 1 )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
        v12 = v11 != nullptr ? (CDmeCombinationOperator *)((char *)&v11[-1] + 64) : nullptr;
        ControlName = CDmeCombinationOperator::GetControlName(this: v12, i);
        Control = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                             this: (CDmeAnimationSet *)v3,
                                             pControlName: ControlName);
        *v10++ = CCodecBuffer_Block::GetBufferType(this: Control);
        v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v25->m_hCombinationOperator.m_handle);
        v16 = v15 != nullptr ? (CDmeCombinationOperator *)((char *)&v15[-1] + 64) : nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v16, nControlIndex: i) )
        {
          V_snprintf(pDest: pMultiControlName, maxLen: 0x100u, pFormat: "multi_%s", ControlName);
          v17 = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                           this: (CDmeAnimationSet *)v3,
                                           pControlName: pMultiControlName);
          *v10++ = CCodecBuffer_Block::GetBufferType(this: v17);
        }
        if ( ++i >= nCombinationControlCount )
          break;
        v1 = v25;
      }
      m_Size = nControlCount;
      v9 = pElements;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::SetMultiple(
      this: controls,
      i: 0,
      nCount: m_Size,
      pValue: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481D10
// Name: public: void CDmeAnimationListPanel::RefreshAnimationList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::RefreshAnimationList(CDmeAnimationListPanel *this)
{
  int v2; // edi
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  KeyValues *v6; // eax
  char *m_Id; // edx
  KeyValues *v8; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  this->m_pAnimationList->RemoveAll(this: this->m_pAnimationList);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle) != nullptr )
  {
    v2 = 0;
    nCount = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle)[1].m_Id.m_Value[8];
    if ( nCount > 0 )
    {
      do
      {
        v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v3[1].OnAttributeChanged + v2));
        v5 = v4;
        if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
          v5 = nullptr;
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
        {
          m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
          if ( m_Id == (char *)-1 )
            m_Id = (char *)&var;
          v8 = KeyValues::KeyValues(this: v6, setName: "node", firstKey: "name", firstValue: m_Id);
        }
        else
        {
          v8 = nullptr;
        }
        this->m_pAnimationList->AddItem(this: this->m_pAnimationList, a2: v8, a3: 0, a4: false, a5: false);
        ++v2;
      }
      while ( v2 < nCount );
    }
    this->m_pAnimationList->SortList(this: this->m_pAnimationList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481E30
// Name: private: void CDmeCombinationOperatorPanel::CreateFakeAnimationSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::CreateFakeAnimationSet(CDmeCombinationOperatorPanel *this)
{
  DmElementHandle_t v1; // eax
  CDmElement *v2; // eax
  CDmeFilmClip *v3; // esi
  CDmeFilmClip *v4; // ebx
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // edi
  CDmAttribute *Attribute; // eax
  CDmaElementArray<CDmeAnimationSet> *AnimationSets; // esi
  IDataModel_vtbl *v10; // edi
  int BufferType; // eax
  DmElementHandle_t value; // [esp+10h] [ebp-4h] BYREF

  v1 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeFilmClip::m_classType.u.m_Id,
         a3: "fakeFilmClip",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1);
  v3 = (CDmeFilmClip *)v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeFilmClip::m_classType) )
    v4 = v3;
  else
    v4 = nullptr;
  v5 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeAnimationSet::m_classType.u.m_Id,
         a3: "fakeAnimSet",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  v7 = v6;
  if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeAnimationSet::m_classType) )
    v7 = nullptr;
  value = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "gameModel");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v7, pAttributeName: "gameModel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
  }
  AnimationSets = CDmeFilmClip::GetAnimationSets(this: v4);
  if ( v7 != nullptr )
    value = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
  else
    value = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: AnimationSets,
    src: &value);
  v10 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v4);
  v10->DontAutoDelete(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  CBaseAnimationSetEditor::ChangeAnimationSetClip(this, pFilmClip: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10481F70
// Name: private: void CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(
        CDmeCombinationOperatorPanel *this,
        const char *pControlName)
{
  int v2; // edi
  CDmeAnimationSet *v3; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // esi
  CDmAttribute *m_pAttribute; // eax
  DmElementArray_t *m_pData; // eax
  int v7; // ebx
  CDmElement *v8; // eax
  CDmeTransformControl *v9; // esi
  CDmeTransformControl *v10; // ecx
  CDmaVar<Vector> *Position; // esi
  float z; // eax
  DmElementArray_t *v13; // eax
  CDmElement *v14; // eax
  CDmeTransform *v15; // esi
  CDmeTransform *v16; // ecx
  const Vector *v17; // esi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  int v20; // ebx
  CDmElement *v21; // eax
  CDmElement *v22; // esi
  const char *m_pAsString; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-30h] BYREF
  CDmrElementArray<CDmePreset> presetList; // [esp+14h] [ebp-28h] BYREF
  CDmrElementArray<CDmePresetGroup> presetGroupList; // [esp+1Ch] [ebp-20h] BYREF
  CDmrElementArray<CDmElement> controlValues; // [esp+24h] [ebp-18h] BYREF
  int i; // [esp+2Ch] [ebp-10h]
  int m_Size; // [esp+30h] [ebp-Ch]
  int v30; // [esp+34h] [ebp-8h]
  int j; // [esp+38h] [ebp-4h]

  v2 = 0;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v3);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupList);
  m_pAttribute = PresetGroups->m_pAttribute;
  if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    presetGroupList.m_pAttribute = PresetGroups->m_pAttribute;
    m_pData = (DmElementArray_t *)m_pAttribute->m_pData;
    presetGroupList.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    presetGroupList.m_pAttribute = nullptr;
    presetGroupList.m_pStorage = nullptr;
    m_Size = 0;
  }
  v7 = 0;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v7]);
      v9 = (CDmeTransformControl *)v8;
      if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmePresetGroup::m_classType) )
        v10 = v9;
      else
        v10 = nullptr;
      Position = CDmeTransformControl::GetPosition(this: v10);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetList);
      z = Position[1].m_Storage.z;
      if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
      {
        v13 = nullptr;
        presetList.m_pAttribute = nullptr;
        presetList.m_pStorage = nullptr;
        v30 = 0;
      }
      else
      {
        presetList.m_pAttribute = (CDmAttribute *)LODWORD(Position[1].m_Storage.z);
        v13 = *(DmElementArray_t **)(LODWORD(z) + 4);
        presetList.m_pStorage = v13;
        v30 = v13->m_Size;
      }
      j = 0;
      if ( v30 > 0 )
      {
        while ( 1 )
        {
          v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13->m_Memory.m_pMemory[j]);
          v15 = (CDmeTransform *)v14;
          if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmePreset::m_classType) )
            v16 = v15;
          else
            v16 = nullptr;
          v17 = CDmeTransform::GetPosition(this: v16);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controlValues);
          x = v17[2].x;
          if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
          {
            m_pStorage = nullptr;
            controlValues.m_pAttribute = nullptr;
            controlValues.m_pStorage = nullptr;
            v20 = 0;
          }
          else
          {
            controlValues.m_pAttribute = (CDmAttribute *)LODWORD(v17[2].x);
            m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
            controlValues.m_pStorage = m_pStorage;
            v20 = m_pStorage->m_Size;
          }
          if ( v20 > 0 )
          {
            while ( 1 )
            {
              v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v2]);
              v22 = v21;
              if ( v21 == nullptr || !v21->IsA(this: v21, a2: CDmElement::m_classType) )
                v22 = nullptr;
              m_pAsString = v22->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = &var;
              if ( _V_stricmp(s1: m_pAsString, s2: pControlName) == 0 )
                break;
              if ( ++v2 >= v20 )
                goto LABEL_39;
              m_pStorage = controlValues.m_pStorage;
            }
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::FastRemove(
              this: &controlValues,
              elem: v2);
          }
LABEL_39:
          v2 = 0;
          if ( ++j >= v30 )
            break;
          v13 = presetList.m_pStorage;
        }
        v7 = i;
      }
      i = ++v7;
      if ( v7 >= m_Size )
        break;
      m_pData = presetGroupList.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10482180
// Name: private: void CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  const Vector *Position; // esi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // esi
  CDmElement *v10; // eax
  CDmeCombinationOperator *v11; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> controls; // [esp+14h] [ebp-Ch] BYREF
  CDmeAnimationSet *pAnimationSet; // [esp+1Ch] [ebp-4h]

  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  pAnimationSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  Position = CDmeTransform::GetPosition(this: (CDmeTransform *)pAnimationSet);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
  x = Position[2].x;
  if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    controls.m_pAttribute = nullptr;
    controls.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    controls.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
    m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
    controls.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v6 = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v6]);
      v8 = v7;
      if ( v7 != nullptr
        && v7->IsA(this: v7, a2: CDmElement::m_classType)
        && !v8->IsA(this: v8, a2: CDmeTransformControl::m_classType) )
      {
        m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
        if ( v10 != nullptr )
          v11 = (CDmeCombinationOperator *)((char *)&v10[-1] + 64);
        else
          v11 = nullptr;
        if ( FindComboOpControlIndexForAnimSetControl(pComboOp: v11, pControlName: m_pAsString, pIsMulti: nullptr) < 0 )
        {
          CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(this, pControlName: m_pAsString);
          CDmeAnimationSet::RemoveControlFromGroups(
            this: pAnimationSet,
            pchControlName: m_pAsString,
            bRemoveEmpty: false);
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::FastRemove(
            this: &controls,
            elem: v6);
        }
      }
      if ( --v6 < 0 )
        break;
      m_pStorage = controls.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104822B0
// Name: public: float const __near & CDmElement::GetValue<float>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CDmElement::GetValue<float>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<float>(this: Attribute);
  else
    return &`CDmElement::GetValue<float>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10482300
// Name: struct SelectionInfo_t __near * FindSelectionInfoForControl<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
SelectionInfo_t *__cdecl FindSelectionInfoForControl<SelectionInfo_t>(
        CUtlVector<SelectionInfo_t *,CUtlMemory<SelectionInfo_t *,int> > *controlList,
        const CDmElement *pControl)
{
  int v3; // esi
  SelectionInfo_t *v4; // edi
  int nControls; // [esp+0h] [ebp-4h]

  if ( pControl == nullptr )
    return nullptr;
  v3 = 0;
  nControls = controlList->m_Size;
  if ( nControls <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = controlList->m_Memory.m_pMemory[v3];
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_hControl.m_handle) == pControl )
      break;
    if ( ++v3 >= nControls )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10482360
// Name: protected: virtual struct SelectionInfo_t __near * CCombinationOperatorControl::FindSelectionInfoForControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
SelectionInfo_t *__thiscall CCombinationOperatorControl::FindSelectionInfoForControl(
        CCombinationOperatorControl *this,
        const CDmElement *pControl)
{
  return FindSelectionInfoForControl<SelectionInfo_t>(controlList: &this->m_FullControlList, pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10482380
// Name: void RemoveNullControls<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveNullControls<SelectionInfo_t>(
        CUtlVector<SelectionInfo_t *,CUtlMemory<SelectionInfo_t *,int> > *controlList)
{
  int i; // esi
  CDmeElementRefHelper *v2; // ebx

  for ( i = controlList->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: controlList->m_Memory.m_pMemory[i]->m_hControl.m_handle) == nullptr )
    {
      v2 = (CDmeElementRefHelper *)controlList->m_Memory.m_pMemory[i];
      if ( v2 != nullptr )
      {
        if ( g_pDataModel != nullptr )
        {
          CDmeElementRefHelper::Unref(this: v2 + 4, hElement: *(DmElementHandle_t *)&v2[4], handleType: HT_WEAK);
          if ( g_pDataModel != nullptr )
            CDmeElementRefHelper::Unref(this: v2, hElement: *(_DWORD *)v2, handleType: HT_WEAK);
        }
        CUtlMemoryPool::Free(this: &SelectionInfo_t::s_Allocator, memBlock: v2);
      }
      if ( controlList->m_Size - i - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&controlList->m_Memory.m_pMemory[i],
          src: (unsigned __int8 *)&controlList->m_Memory.m_pMemory[i + 1],
          count: 4 * (controlList->m_Size - i - 1));
      --controlList->m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10482420
// Name: public: CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetControl __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperatorPanel *__thiscall CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(
        CDmeCombinationOperatorPanel *this,
        vgui::Panel *parent,
        vgui::Panel *panelName,
        CBaseAnimationSetControl *pAnimationSetController)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  CBaseAnimationSetEditor::CBaseAnimationSetEditor(this, parent, className: panelName, pAnimationSetController);
  this->__vftable = (CDmeCombinationOperatorPanel_vtbl *)&CDmeCombinationOperatorPanel::`vftable';
  if ( `CDmeCombinationOperatorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationOperatorPanel");
    v5->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
  }
  if ( `CDmeCombinationOperatorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmeCombinationOperatorPanel");
    v6->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
  }
  if ( `CDmeCombinationOperatorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationOperatorPanel");
    v7->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
  }
  this->m_hCombinationOperator.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_operatorList.m_Memory.m_pMemory = nullptr;
  this->m_operatorList.m_Memory.m_nAllocationCount = 0;
  this->m_operatorList.m_Memory.m_nGrowSize = 0;
  this->m_operatorList.m_Size = 0;
  this->m_operatorList.m_pElements = nullptr;
  CDmeCombinationOperatorPanel::CreateFakeAnimationSet(this);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10482530
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeCombinationOperatorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeCombinationOperatorPanel::GetMessageMap(CDmeCombinationOperatorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeCombinationOperatorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationOperatorPanel");
  `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10482560
// Name: public: virtual struct PanelAnimationMap __near * CDmeCombinationOperatorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeCombinationOperatorPanel::GetAnimMap(CDmeCombinationOperatorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeCombinationOperatorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10482570
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeCombinationOperatorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeCombinationOperatorPanel::GetKBMap(CDmeCombinationOperatorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeCombinationOperatorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationOperatorPanel::GetKBMap'::`2'::s_pMap;
  `CDmeCombinationOperatorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationOperatorPanel");
  `CDmeCombinationOperatorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104825A0
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(
        CDmeCombinationOperatorPanel *this,
        CDmElement *pControlElement)
{
  char *m_Id; // eax
  CDmeAnimationSet *v3; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // esi
  CDmAttribute *m_pAttribute; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // eax
  int m_Size; // ecx
  CDmElement *v8; // eax
  CDmeTransformControl *v9; // esi
  CDmeTransformControl *v10; // ecx
  CDmaVar<Vector> *Position; // esi
  float z; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *v13; // eax
  int v14; // ecx
  CDmElement *v15; // eax
  CDmeTransform *v16; // esi
  const Vector *v17; // esi
  float x; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pStorage; // eax
  int v20; // ecx
  int v21; // ecx
  CDmElement *v22; // eax
  CDmElement *v23; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v26; // edi
  CDmaVar<float> *v27; // edi
  CDmAttribute *v28; // eax
  CDmAttribute *v29; // eax
  CDmAttribute *v30; // eax
  CDmAttribute *v31; // edi
  CDmaVar<float> *v32; // edi
  CDmAttribute *v33; // eax
  CDmAttribute *v34; // edi
  CDmaVar<float> *v35; // edi
  float *p_flLeftValue; // edi
  CDmAttribute *v37; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-48h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v39; // [esp+14h] [ebp-40h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v40; // [esp+1Ch] [ebp-38h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v41; // [esp+24h] [ebp-30h] BYREF
  int v42; // [esp+2Ch] [ebp-28h]
  int v43; // [esp+30h] [ebp-24h]
  int v44; // [esp+34h] [ebp-20h]
  float flRightValue; // [esp+38h] [ebp-1Ch] BYREF
  float flLeftValue; // [esp+3Ch] [ebp-18h] BYREF
  float flValue; // [esp+40h] [ebp-14h] BYREF
  char *s2; // [esp+44h] [ebp-10h]
  int g; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int j; // [esp+50h] [ebp-4h]

  m_Id = (char *)pControlElement->m_Name.m_Storage.u.m_Id;
  s2 = (char *)&var;
  if ( m_Id != (char *)-1 )
    s2 = m_Id;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v3);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v41);
  m_pAttribute = PresetGroups->m_pAttribute;
  if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    v41.m_pAttribute = PresetGroups->m_pAttribute;
    m_pData = (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)m_pAttribute->m_pData;
    v41.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    v41.m_pAttribute = nullptr;
    v41.m_pStorage = nullptr;
    m_Size = 0;
  }
  v42 = m_Size;
  g = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[g].m_tms);
      v9 = (CDmeTransformControl *)v8;
      if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmePresetGroup::m_classType) )
        v10 = v9;
      else
        v10 = nullptr;
      Position = CDmeTransformControl::GetPosition(this: v10);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v40);
      z = Position[1].m_Storage.z;
      if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
      {
        v13 = nullptr;
        v40.m_pAttribute = nullptr;
        v40.m_pStorage = nullptr;
        v14 = 0;
      }
      else
      {
        v40.m_pAttribute = (CDmAttribute *)LODWORD(Position[1].m_Storage.z);
        v13 = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(z) + 4);
        v40.m_pStorage = v13;
        v14 = v13->m_Size;
      }
      v43 = v14;
      i = 0;
      if ( v14 > 0 )
      {
        while ( 1 )
        {
          v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13->m_Memory.m_pMemory[i].m_tms);
          v16 = (CDmeTransform *)v15;
          if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmePreset::m_classType) )
            v16 = nullptr;
          if ( !CDmePreset::IsAnimated(this: (CDmePreset *)v16) )
          {
            v17 = CDmeTransform::GetPosition(this: v16);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v39);
            x = v17[2].x;
            if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
            {
              m_pStorage = nullptr;
              v39.m_pAttribute = nullptr;
              v39.m_pStorage = nullptr;
              v20 = 0;
            }
            else
            {
              v39.m_pAttribute = (CDmAttribute *)LODWORD(v17[2].x);
              m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(x) + 4);
              v39.m_pStorage = m_pStorage;
              v20 = m_pStorage->m_Size;
            }
            v44 = v20;
            j = 0;
            if ( v20 > 0 )
            {
              v21 = 0;
              while ( 1 )
              {
                v22 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v21].m_tms);
                v23 = v22;
                if ( v22 == nullptr || !v22->IsA(this: v22, a2: CDmElement::m_classType) )
                  v23 = nullptr;
                m_pAsString = v23->m_Name.m_Storage.u.m_pAsString;
                if ( m_pAsString == (const char *)-1 )
                  m_pAsString = &var;
                if ( _V_stricmp(s1: m_pAsString, s2) == 0 )
                {
                  if ( CDmElement::HasAttribute(this: pControlElement, pAttributeName: "rightValue", type: AT_UNKNOWN) )
                  {
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    Attribute = CDmElement::FindAttribute(this: v23, pAttributeName: "value");
                    v26 = Attribute;
                    if ( Attribute != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (Attribute->m_nFlags & 0x1F) == 3 )
                      {
                        v27 = (CDmaVar<float> *)Attribute->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v26,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v27 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v27 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v27 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flValue = v27->m_Storage;
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "value");
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue") == nullptr )
                    {
                      v28 = CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue");
                      if ( v28 != nullptr
                        || (v28 = CDmElement::CreateAttribute(this: v23, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v28, value: &flValue);
                      }
                    }
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue") == nullptr )
                    {
                      v29 = CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue");
                      if ( v29 != nullptr
                        || (v29 = CDmElement::CreateAttribute(this: v23, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v29, value: &flValue);
                      }
                    }
                  }
                  else
                  {
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    v30 = CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue");
                    v31 = v30;
                    if ( v30 != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (v30->m_nFlags & 0x1F) == 3 )
                      {
                        v32 = (CDmaVar<float> *)v30->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v30) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v31,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v32 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v32 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v32 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flLeftValue = v32->m_Storage;
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    v33 = CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue");
                    v34 = v33;
                    if ( v33 != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (v33->m_nFlags & 0x1F) == 3 )
                      {
                        v35 = (CDmaVar<float> *)v33->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v33) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v34,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v35 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v35 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v35 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flRightValue = v35->m_Storage;
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "leftValue");
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "rightValue");
                    p_flLeftValue = &flLeftValue;
                    if ( flLeftValue <= flRightValue )
                      p_flLeftValue = &flRightValue;
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "value") == nullptr )
                    {
                      v37 = CDmElement::FindAttribute(this: v23, pAttributeName: "value");
                      if ( v37 != nullptr
                        || (v37 = CDmElement::CreateAttribute(this: v23, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v37, value: p_flLeftValue);
                      }
                    }
                  }
                }
                v21 = j + 1;
                j = v21;
                if ( v21 >= v44 )
                  break;
                m_pStorage = v39.m_pStorage;
              }
            }
          }
          if ( ++i >= v43 )
            break;
          v13 = v40.m_pStorage;
        }
      }
      if ( ++g >= v42 )
        break;
      m_pData = v41.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10482AB0
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeTransform *v1; // eax
  const Vector *Position; // esi
  float x; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pStorage; // eax
  int m_Size; // ecx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-14h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v10; // [esp+10h] [ebp-Ch] BYREF
  CDmeCombinationOperatorPanel *v11; // [esp+18h] [ebp-4h]

  v11 = this;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v1 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  Position = CDmeTransform::GetPosition(this: v1);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v10);
  x = Position[2].x;
  if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    v10.m_pAttribute = nullptr;
    v10.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    v10.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
    m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(x) + 4);
    v10.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v6 = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v6].m_tms);
      v8 = v7;
      if ( v7 != nullptr
        && v7->IsA(this: v7, a2: CDmElement::m_classType)
        && !v8->IsA(this: v8, a2: CDmeTransformControl::m_classType) )
      {
        CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(this: v11, pControlElement: v8);
        CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(this: v11, pControlElement: v8);
      }
      if ( --v6 < 0 )
        break;
      m_pStorage = v10.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10482B90
// Name: private: void CDmeCombinationOperatorPanel::AddNewAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::AddNewAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeCombinationOperatorPanel *v1; // ebx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  int v3; // eax
  int v4; // edi
  CDmeAnimationSet *v5; // esi
  CDmaElementArray<CDmElement> *Position; // eax
  CDmElement *(__thiscall *v7)(IDataModel *, DmElementHandle_t); // edx
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  CDmElement *v10; // eax
  CDmeCombinationOperator *v11; // ecx
  CDmElement *v12; // eax
  CDmeCombinationOperator *v13; // ecx
  bool IsStereoControl; // bl
  CDmElement *v15; // eax
  CDmeCombinationOperator *v16; // ecx
  DmElementHandle_t v17; // eax
  CDmElement *v18; // eax
  CExpressionCalculator *v19; // esi
  CDmElement *v20; // eax
  CDmeCombinationOperator *v21; // ecx
  Vector *StereoControlValue; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  CDmElement *v26; // eax
  CDmeCombinationOperator *v27; // ecx
  CDmElement *v28; // eax
  CDmeCombinationOperator *v29; // ecx
  CDmAttribute *v30; // eax
  DmElementHandle_t v31; // eax
  CDmElement *v32; // eax
  CExpressionCalculator *v33; // esi
  CDmElement *v34; // eax
  CDmeCombinationOperator *v35; // ecx
  CDmAttribute *v36; // eax
  CDmAttribute *v37; // eax
  int m_Size; // ebx
  CDmeControlGroup *v39; // esi
  CDmAttribute *v40; // eax
  int j; // edi
  CDmElement *v42; // eax
  CExpressionCalculator *v43; // esi
  DmElementHandle_t m_handle; // [esp-4h] [ebp-158h]
  char pMultiControlName[256]; // [esp+Ch] [ebp-148h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+10Ch] [ebp-48h] BYREF
  float MultiControlLevel; // [esp+114h] [ebp-40h] BYREF
  float v48; // [esp+118h] [ebp-3Ch] BYREF
  float flDefaultValue; // [esp+11Ch] [ebp-38h] BYREF
  int nCombinationControlCount; // [esp+120h] [ebp-34h]
  float value; // [esp+124h] [ebp-30h] BYREF
  const char *pControlName; // [esp+128h] [ebp-2Ch]
  CDmrElementArray<CDmElement> groups; // [esp+12Ch] [ebp-28h] BYREF
  DmElementHandle_t src; // [esp+134h] [ebp-20h] BYREF
  int nFirstControl; // [esp+138h] [ebp-1Ch]
  int i; // [esp+13Ch] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+140h] [ebp-14h]
  CDmeAnimationSet *pAnimationSet; // [esp+144h] [ebp-10h]
  DmElementHandle_t BufferType; // [esp+148h] [ebp-Ch] BYREF
  int iCurrentAnimSetControl; // [esp+14Ch] [ebp-8h]
  CDmeCombinationOperatorPanel *v61; // [esp+150h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hCombinationOperator.m_handle;
  v61 = this;
  v3 = (int)GetElement(this: g_pDataModel, a2: m_handle);
  v4 = 0;
  if ( v3 != 0 && v3 != 4 )
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: v1->m_pController);
    traversal.m_nIndex = 0;
    v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    pAnimationSet = v5;
    Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: (CDmeTransform *)v5);
    nFirstControl = Position->m_Storage.m_Size;
    v7 = g_pDataModel->GetElement;
    controls = Position;
    v8 = (int)v7(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
    if ( v8 != 0 )
      v9 = (CDmeCombinationOperator *)(v8 - 4);
    else
      v9 = nullptr;
    nCombinationControlCount = CDmeCombinationOperator::GetControlCount(this: v9);
    iCurrentAnimSetControl = 0;
    i = 0;
    if ( nCombinationControlCount > 0 )
    {
      do
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
        if ( v10 != nullptr )
          v11 = (CDmeCombinationOperator *)((char *)&v10[-1] + 64);
        else
          v11 = nullptr;
        pControlName = CDmeCombinationOperator::GetControlName(this: v11, i: v4);
        if ( CDmeAnimationSet::FindControl(this: v5, pControlName) == nullptr )
        {
          v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
          if ( v12 != nullptr )
            v13 = (CDmeCombinationOperator *)((char *)&v12[-1] + 64);
          else
            v13 = nullptr;
          IsStereoControl = CDmeCombinationOperator::IsStereoControl(this: v13, nControlIndex: v4);
          v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
          if ( v15 != nullptr )
            v16 = (CDmeCombinationOperator *)((char *)&v15[-1] + 64);
          else
            v16 = nullptr;
          flDefaultValue = CDmeCombinationOperator::GetControlDefaultValue(this: v16, nControl: v4);
          v17 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                  a1: g_pDataModel,
                  a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
                  a3: pControlName,
                  a4: v5->m_fileId,
                  a5: nullptr);
          v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: v17);
          v19 = (CExpressionCalculator *)v18;
          if ( v18 != nullptr && v18->IsA(this: v18, a2: CDmElement::m_classType) )
          {
            src = CCodecBuffer_Block::GetBufferType(this: v19);
          }
          else
          {
            v19 = nullptr;
            src = DMELEMENT_HANDLE_INVALID;
          }
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
            this: controls,
            elem: (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)iCurrentAnimSetControl,
            &src);
          if ( IsStereoControl )
          {
            v20 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
            if ( v20 != nullptr )
              v21 = (CDmeCombinationOperator *)((char *)&v20[-1] + 64);
            else
              v21 = nullptr;
            StereoControlValue = CDmeCombinationOperator::GetStereoControlValue(
                                   this: v21,
                                   nControlIndex: v4,
                                   type: COMBO_CONTROL_FIRST);
            Attribute = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "leftValue");
            if ( Attribute != nullptr
              || (Attribute = CDmElement::CreateAttribute(
                                this: (CDmElement *)v19,
                                pAttributeName: "leftValue",
                                type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: Attribute, value: &StereoControlValue->x);
            }
            v24 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "rightValue");
            if ( v24 != nullptr
              || (v24 = CDmElement::CreateAttribute(
                          this: (CDmElement *)v19,
                          pAttributeName: "rightValue",
                          type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v24, value: &StereoControlValue->y);
            }
            v4 = i;
          }
          else
          {
            v28 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
            if ( v28 != nullptr )
              v29 = (CDmeCombinationOperator *)((char *)&v28[-1] + 64);
            else
              v29 = nullptr;
            value = CDmeCombinationOperator::GetControlValue(this: v29, nControlIndex: v4, type: COMBO_CONTROL_FIRST);
            v30 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "value");
            if ( v30 != nullptr
              || (v30 = CDmElement::CreateAttribute(this: (CDmElement *)v19, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v30, &value);
            }
          }
          v25 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "defaultValue");
          if ( v25 != nullptr
            || (v25 = CDmElement::CreateAttribute(
                        this: (CDmElement *)v19,
                        pAttributeName: "defaultValue",
                        type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v25, value: &flDefaultValue);
          }
          v1 = v61;
          v5 = pAnimationSet;
        }
        v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_hCombinationOperator.m_handle);
        if ( v26 != nullptr )
          v27 = (CDmeCombinationOperator *)((char *)&v26[-1] + 64);
        else
          v27 = nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v27, nControlIndex: v4) )
        {
          ++iCurrentAnimSetControl;
          V_snprintf(pDest: pMultiControlName, maxLen: 0x100u, pFormat: "multi_%s", pControlName);
          if ( CDmeAnimationSet::FindControl(this: v5, pControlName: pMultiControlName) == nullptr )
          {
            v31 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                    a1: g_pDataModel,
                    a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
                    a3: pMultiControlName,
                    a4: v5->m_fileId,
                    a5: nullptr);
            v32 = g_pDataModel->GetElement(this: g_pDataModel, a2: v31);
            v33 = (CExpressionCalculator *)v32;
            if ( v32 != nullptr && v32->IsA(this: v32, a2: CDmElement::m_classType) )
            {
              BufferType = CCodecBuffer_Block::GetBufferType(this: v33);
            }
            else
            {
              v33 = nullptr;
              BufferType = DMELEMENT_HANDLE_INVALID;
            }
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
              this: controls,
              elem: (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)iCurrentAnimSetControl,
              src: &BufferType);
            v34 = g_pDataModel->GetElement(this: g_pDataModel, a2: v61->m_hCombinationOperator.m_handle);
            if ( v34 != nullptr )
              v35 = (CDmeCombinationOperator *)((char *)&v34[-1] + 64);
            else
              v35 = nullptr;
            MultiControlLevel = CDmeCombinationOperator::GetMultiControlLevel(
                                  this: v35,
                                  nControlIndex: v4,
                                  type: COMBO_CONTROL_FIRST);
            v36 = CDmElement::FindAttribute(this: (CDmElement *)v33, pAttributeName: "value");
            if ( v36 != nullptr
              || (v36 = CDmElement::CreateAttribute(this: (CDmElement *)v33, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v36, value: &MultiControlLevel);
            }
            v48 = 0.5;
            v37 = CDmElement::FindAttribute(this: (CDmElement *)v33, pAttributeName: "defaultValue");
            if ( v37 != nullptr
              || (v37 = CDmElement::CreateAttribute(
                          this: (CDmElement *)v33,
                          pAttributeName: "defaultValue",
                          type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v37, value: &v48);
            }
            v1 = v61;
            v5 = pAnimationSet;
          }
        }
        ++iCurrentAnimSetControl;
        i = ++v4;
      }
      while ( v4 < nCombinationControlCount );
    }
    m_Size = controls->m_Storage.m_Size;
    if ( m_Size != nFirstControl )
    {
      v39 = CDmeAnimationSet::FindOrAddControlGroup(this: v5, pParentGroup: nullptr, pControlGroupName: "Root");
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&groups);
      if ( v39 != nullptr
        && (v40 = CDmElement::FindAttribute(this: v39, pAttributeName: "controls")) != nullptr
        && (v40->m_nFlags & 0x1F) == 0xF )
      {
        groups.m_pAttribute = v40;
        groups.m_pStorage = (DmElementArray_t *)v40->m_pData;
      }
      else
      {
        groups.m_pAttribute = nullptr;
        groups.m_pStorage = nullptr;
      }
      for ( j = nFirstControl; j < m_Size; ++j )
      {
        v42 = g_pDataModel->GetElement(this: g_pDataModel, a2: controls->m_Storage.m_Memory.m_pMemory[j]);
        v43 = (CExpressionCalculator *)v42;
        if ( v42 != nullptr && v42->IsA(this: v42, a2: CDmElement::m_classType) )
          BufferType = CCodecBuffer_Block::GetBufferType(this: v43);
        else
          BufferType = DMELEMENT_HANDLE_INVALID;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &groups,
          src: &BufferType);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10483090
// Name: public: void CDmeDagEditPanel::SetAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetAnimationList(CDmeDagEditPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeAnimationListPanel *m_pAnimationListPanel; // esi
  DmElementHandle_t BufferType; // eax

  CDmeDagRenderPanel::SetAnimationList(this: this->m_pDagRenderPanel, pAnimationList);
  CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: &var);
  m_pAnimationListPanel = this->m_pAnimationListPanel;
  if ( pAnimationList != g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: m_pAnimationListPanel->m_hAnimationList.m_handle) )
  {
    if ( pAnimationList != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeAnimationList,0>::Set(this: &m_pAnimationListPanel->m_hAnimationList, h: BufferType);
    CDmeAnimationListPanel::RefreshAnimationList(this: m_pAnimationListPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10483100
// Name: public: void CDmeDagEditPanel::SetVertexAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetVertexAnimationList(CDmeDagEditPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeAnimationListPanel *m_pVertexAnimationListPanel; // esi
  DmElementHandle_t BufferType; // eax

  CDmeDagRenderPanel::SetVertexAnimationList(this: this->m_pDagRenderPanel, pAnimationList);
  CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: &var);
  m_pVertexAnimationListPanel = this->m_pVertexAnimationListPanel;
  if ( pAnimationList != g_pDataModel->GetElement(
                           this: g_pDataModel,
                           a2: m_pVertexAnimationListPanel->m_hAnimationList.m_handle) )
  {
    if ( pAnimationList != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeAnimationList,0>::Set(this: &m_pVertexAnimationListPanel->m_hAnimationList, h: BufferType);
    CDmeAnimationListPanel::RefreshAnimationList(this: m_pVertexAnimationListPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10483200
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10483290
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AnimationSelected";
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
// Address: 0x10483320
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AnimationDeselected";
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
// Address: 0x104833B0
// Name: public: static void CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10483440
// Name: public: static void CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemDeselected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104834D0
// Name: public: CDmeAnimationListPanel::CDmeAnimationListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationListPanel *__thiscall CDmeAnimationListPanel::CDmeAnimationListPanel(
        CDmeAnimationListPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeAnimationListPanel_vtbl *)&CDmeAnimationListPanel::`vftable';
  if ( `CDmeAnimationListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v4->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeAnimationListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeAnimationListPanel");
    v5->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeAnimationListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeAnimationListPanel");
    v6->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  this->m_hAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "AnimationList");
  else
    v8 = nullptr;
  this->m_pAnimationList = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "name", a4: "name", a5: 100, a6: 0);
  this->m_pAnimationList->AddActionSignalTarget_2(this: this->m_pAnimationList, a2: this);
  this->m_pAnimationList->SetSortFunc(this: this->m_pAnimationList, a2: 0, a3: PresetNameSortFunc);
  this->m_pAnimationList->SetSortColumn(this: this->m_pAnimationList, a2: 0);
  this->m_pAnimationList->SetEmptyListText_2(this: this->m_pAnimationList, a2: "No animations");
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pAnimationList, bState: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmeanimationlistpanel.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104836C0
// Name: public: void CDmeCombinationOperatorPanel::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::SetCombinationOperator(
        CDmeCombinationOperatorPanel *this,
        CDmeCombinationOperator *pOp)
{
  CDmeCombinationOperatorPanel *v2; // ebx
  CDmAttribute *AnimationSetClip; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_operatorList; // esi
  CDmElement *v5; // eax
  CDmeCombinationOperator *v6; // eax
  CDmElement *v7; // ecx
  DmElementHandle_t BufferType; // eax
  CDmElement *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  int *v14; // edi
  CDmElement *OperationTarget; // eax
  CDmElement *v16; // edi
  vgui::TreeNode **v17; // edi
  int v18; // eax
  vgui::TreeNode **v19; // ecx
  int v20; // eax
  CDmeFlexRules **v21; // eax
  CDmeFlexRules *v22; // ecx
  int v23; // eax
  int j; // ebx
  CDmElement *v25; // eax
  CDmElement *v26; // edi
  vgui::TreeNode **v27; // edi
  int v28; // eax
  vgui::TreeNode **v29; // ecx
  int v30; // eax
  vgui::TreeNode **v31; // eax
  CDmeFilmClip *v32; // eax
  vgui::TreeNode *v33; // [esp+10h] [ebp-10h]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  CDmeFlexRules *pDmeFlexRules; // [esp+1Ch] [ebp-4h]

  v2 = this;
  AnimationSetClip = (CDmAttribute *)CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  DestroyElement(pElement: AnimationSetClip, depth: TD_DEEP);
  CDmeCombinationOperatorPanel::CreateFakeAnimationSet(this: v2);
  v2->m_operatorList.m_Size = 0;
  p_m_operatorList = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_operatorList;
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hCombinationOperator.m_handle);
  if ( v5 != nullptr )
    v6 = (CDmeCombinationOperator *)((char *)&v5[-1] + 64);
  else
    v6 = nullptr;
  if ( pOp != v6 )
  {
    if ( pOp != nullptr )
      v7 = &pOp->CDmElement;
    else
      v7 = nullptr;
    if ( v7 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeCombinationOperator,0>::Set(this: &v2->m_hCombinationOperator, h: BufferType);
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hCombinationOperator.m_handle);
    if ( v9 != nullptr )
      i = (int)&v9[-1] + 64;
    else
      i = 0;
    m_Size = v2->m_operatorList.m_Size;
    m_nAllocationCount = v2->m_operatorList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_operatorList,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_operatorList.m_Size;
    m_pMemory = p_m_operatorList->m_pMemory;
    v13 = v2->m_operatorList.m_Size - m_Size - 1;
    v2->m_operatorList.m_pElements = v2->m_operatorList.m_Memory.m_pMemory;
    if ( v13 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v13);
    v14 = (int *)&p_m_operatorList->m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = i;
    for ( ia = 0; ia < CDmeCombinationOperator::GetOperationTargetCount(this: pOp); ++ia )
    {
      OperationTarget = CDmeCombinationOperator::GetOperationTarget(this: pOp, nTargetIndex: ia);
      v16 = OperationTarget;
      if ( OperationTarget != nullptr && OperationTarget->IsA(this: OperationTarget, a2: CDmeFlexRules::m_classType) )
      {
        pDmeFlexRules = (CDmeFlexRules *)((char *)&v16[-1] + 64);
        if ( v16 != (CDmElement *)4 )
        {
          v17 = p_m_operatorList[1].m_pMemory;
          v18 = p_m_operatorList->m_nAllocationCount;
          if ( (int)v17 + 1 > v18 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_operatorList, num: (int)v17 - v18 + 1);
          ++p_m_operatorList[1].m_pMemory;
          v19 = p_m_operatorList->m_pMemory;
          v20 = (char *)p_m_operatorList[1].m_pMemory - (char *)v17 - 1;
          p_m_operatorList[1].m_nAllocationCount = (int)p_m_operatorList->m_pMemory;
          if ( v20 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v19[(_DWORD)v17 + 1],
              src: (unsigned __int8 *)&v19[(_DWORD)v17],
              count: 4 * v20);
          v21 = (CDmeFlexRules **)&p_m_operatorList->m_pMemory[(_DWORD)v17];
          if ( v21 != nullptr )
            *v21 = pDmeFlexRules;
          v22 = pDmeFlexRules;
          v23 = pDmeFlexRules->m_eDeltaStates.m_Storage.m_Size;
          for ( j = 0; j < v23; ++j )
          {
            if ( j >= 0 && j < v23 )
            {
              v25 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: v22->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[j]);
              v26 = v25;
              if ( v25 != nullptr && v25->IsA(this: v25, a2: CDmeFlexRuleBase::m_classType) )
              {
                v33 = (vgui::TreeNode *)((char *)&v26[-1] + 64);
                if ( v26 != (CDmElement *)4 )
                {
                  v27 = p_m_operatorList[1].m_pMemory;
                  v28 = p_m_operatorList->m_nAllocationCount;
                  if ( (int)v27 + 1 > v28 )
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_operatorList, num: (int)v27 - v28 + 1);
                  ++p_m_operatorList[1].m_pMemory;
                  v29 = p_m_operatorList->m_pMemory;
                  v30 = (char *)p_m_operatorList[1].m_pMemory - (char *)v27 - 1;
                  p_m_operatorList[1].m_nAllocationCount = (int)p_m_operatorList->m_pMemory;
                  if ( v30 > 0 )
                    _V_memmove(
                      dest: (unsigned __int8 *)&v29[(_DWORD)v27 + 1],
                      src: (unsigned __int8 *)&v29[(_DWORD)v27],
                      count: 4 * v30);
                  v31 = &p_m_operatorList->m_pMemory[(_DWORD)v27];
                  if ( v31 != nullptr )
                    *v31 = v33;
                }
              }
            }
            v22 = pDmeFlexRules;
            v23 = pDmeFlexRules->m_eDeltaStates.m_Storage.m_Size;
          }
          v2 = this;
        }
      }
    }
    if ( CBaseAnimationSetControl::GetAnimationSetClip(this: v2->m_pController) != nullptr )
    {
      LOBYTE(v33) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
      CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::AddNewAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::SortAnimationSetControls(this: v2);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: (bool)v33);
    }
    v32 = CBaseAnimationSetControl::GetAnimationSetClip(this: v2->m_pController);
    CBaseAnimationSetEditor::ChangeAnimationSetClip(this: v2, pFilmClip: v32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104839C0
// Name: public: virtual void CDmeCombinationOperatorPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationOperatorPanel::OnTick(
        CDmeCombinationOperatorPanel *this@<ecx>,
        DmElementHandle_t m_handle@<edi>)
{
  CDmElement *v3; // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  CDmElement *v6; // eax
  CDmeCombinationOperator *v7; // ecx
  int v8; // edi
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  bool SliderValues; // al
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  int v13; // eax
  CDmeCombinationOperator *v14; // ecx
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  CDmElement *v17; // eax
  CDmeCombinationOperator *v18; // ecx
  CBaseAnimSetAttributeSliderPanel *v19; // eax
  bool v20; // al
  CDmElement *v21; // eax
  CDmeCombinationOperator *v22; // ecx
  DmElementHandle_t v23; // eax
  CDmElement *v24; // eax
  char *v25; // edi
  float z; // eax
  float v27; // esi
  float v28; // ecx
  int v29; // eax
  _DWORD *v30; // eax
  bool v31; // al
  IDataModel_vtbl *v32; // edx
  int m_Size; // [esp+8h] [ebp-70h]
  int v34; // [esp+8h] [ebp-70h]
  AttributeValue_t pValue; // [esp+18h] [ebp-60h] BYREF
  AttributeValue_t multiValue; // [esp+40h] [ebp-38h] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > operators; // [esp+68h] [ebp-10h]

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
  if ( v3 != nullptr && v3 != (CDmElement *)4 )
  {
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    LOBYTE(operators.m_Memory.m_nAllocationCount) = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
    if ( v6 != nullptr )
      v7 = (CDmeCombinationOperator *)((char *)&v6[-1] + 64);
    else
      v7 = nullptr;
    v8 = 0;
    operators.m_Memory.m_nGrowSize = CDmeCombinationOperator::GetControlCount(this: v7);
    for ( operators.m_Size = 0; v8 < operators.m_Memory.m_nGrowSize; ++v8 )
    {
      memset(&multiValue, 0, 24);
      m_Size = operators.m_Size;
      multiValue.m_Quaternion = quat_identity;
      AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this);
      SliderValues = CBaseAnimSetAttributeSliderPanel::GetSliderValues(
                       this: AttributeSlider,
                       pValue: &multiValue,
                       nIndex: m_Size);
      ++operators.m_Size;
      if ( SliderValues )
      {
        v11 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, DmElementHandle_t))g_pDataModel->GetElement)(
                a1: g_pDataModel,
                a2: this->m_hCombinationOperator.m_handle,
                a3: m_handle);
        if ( v11 != 0 )
          v12 = (CDmeCombinationOperator *)(v11 - 4);
        else
          v12 = nullptr;
        if ( CDmeCombinationOperator::IsStereoControl(this: v12, nControlIndex: v8) )
        {
          m_handle = this->m_hCombinationOperator.m_handle;
          v13 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
          if ( v13 != 0 )
            v14 = (CDmeCombinationOperator *)(v13 - 4);
          else
            v14 = nullptr;
          CDmeCombinationOperator::SetControlValue(
            this: v14,
            nControlIndex: v8,
            flLeftValue: multiValue.m_pValue[2],
            flRightValue: multiValue.m_pValue[1],
            type: COMBO_CONTROL_FIRST);
        }
        else
        {
          m_handle = this->m_hCombinationOperator.m_handle;
          v15 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
          if ( v15 != 0 )
            v16 = (CDmeCombinationOperator *)(v15 - 4);
          else
            v16 = nullptr;
          CDmeCombinationOperator::SetControlValue(
            this: v16,
            nControlIndex: v8,
            flValue: multiValue.m_pValue[0],
            type: COMBO_CONTROL_FIRST);
        }
      }
      v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
      if ( v17 != nullptr )
        v18 = (CDmeCombinationOperator *)((char *)&v17[-1] + 64);
      else
        v18 = nullptr;
      if ( CDmeCombinationOperator::IsMultiControl(this: v18, nControlIndex: v8) )
      {
        memset(&pValue, 0, 24);
        v34 = operators.m_Size;
        pValue.m_Quaternion = quat_identity;
        v19 = CBaseAnimationSetEditor::GetAttributeSlider(this);
        v20 = CBaseAnimSetAttributeSliderPanel::GetSliderValues(this: v19, &pValue, nIndex: v34);
        ++operators.m_Size;
        if ( v20 )
        {
          v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCombinationOperator.m_handle);
          if ( v21 != nullptr )
            v22 = (CDmeCombinationOperator *)((char *)&v21[-1] + 64);
          else
            v22 = nullptr;
          CDmeCombinationOperator::SetMultiControlLevel(
            this: v22,
            nControlIndex: v8,
            flMultiLevel: pValue.m_pValue[0],
            type: COMBO_CONTROL_FIRST);
        }
      }
    }
    ((void (__thiscall *)(IDataModel *, int, DmElementHandle_t))g_pDataModel->SetUndoEnabled)(
      a1: g_pDataModel,
      a2: operators.m_Memory.m_nAllocationCount,
      a3: m_handle);
    if ( this->m_operatorList.m_Size != 0 )
    {
      LOBYTE(operators.m_Memory.m_nAllocationCount) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
      g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: &this->m_operatorList);
      g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
      g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: operators.m_Memory.m_nAllocationCount);
      g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
      return;
    }
    v23 = this->m_hCombinationOperator.m_handle;
    memset(&multiValue.m_Vector.z, 0, 20);
    v24 = g_pDataModel->GetElement(this: g_pDataModel, a2: v23);
    if ( v24 != nullptr )
      v25 = (char *)&v24[-1] + 64;
    else
      v25 = nullptr;
    z = multiValue.m_Quaternion.z;
    v27 = multiValue.m_Quaternion.z;
    if ( LODWORD(multiValue.m_Quaternion.z) + 1 > SLODWORD(multiValue.m_Quaternion.x) )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&multiValue.m_Vector.z,
        num: LODWORD(multiValue.m_Quaternion.z) - LODWORD(multiValue.m_Quaternion.x) + 1);
      z = multiValue.m_Quaternion.z;
    }
    v28 = multiValue.m_Vector.z;
    LODWORD(multiValue.m_Quaternion.z) = LODWORD(z) + 1;
    v29 = LODWORD(z) - LODWORD(v27);
    multiValue.m_Quaternion.w = multiValue.m_Vector.z;
    if ( v29 > 0 )
    {
      _V_memmove(
        dest: (unsigned __int8 *)(LODWORD(multiValue.m_Vector.z) + 4 * LODWORD(v27) + 4),
        src: (unsigned __int8 *)(LODWORD(multiValue.m_Vector.z) + 4 * LODWORD(v27)),
        count: 4 * v29);
      v28 = multiValue.m_Vector.z;
    }
    v30 = (_DWORD *)(LODWORD(v28) + 4 * LODWORD(v27));
    if ( v30 != nullptr )
      *v30 = v25;
    v31 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v32 = g_pDataModel->__vftable;
    LOBYTE(operators.m_Memory.m_nAllocationCount) = v31;
    v32->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDmElementFramework->SetOperators(
      this: g_pDmElementFramework,
      a2: (const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)&multiValue.m_Vector.z);
    g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: operators.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&multiValue.m_Vector.z);
  }
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
}

//------------------------------------------------------------------------------
// Address: 0x10483D80
// Name: public: CDmeDagEditPanel::CDmeDagEditPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmeDagEditPanel::CDmeDagEditPanel(
        CDmeDagEditPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v10; // edi
  CDmeDagRenderPanel *v11; // eax
  CDmeDagRenderPanel *v12; // eax
  vgui::PropertySheet *v13; // eax
  vgui::PropertySheet *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  vgui::PropertyPage *v17; // eax
  vgui::PropertyPage *v18; // eax
  vgui::PropertyPage *v19; // eax
  vgui::PropertyPage *v20; // eax
  CBaseAnimationSetControl *v21; // eax
  CBaseAnimationSetControl *v22; // edi
  CDmeCombinationOperatorPanel *v23; // eax
  CDmeCombinationOperatorPanel *v24; // eax
  CDmeAnimationListPanel *v25; // eax
  CDmeAnimationListPanel *v26; // eax
  CDmeAnimationListPanel *v27; // eax
  CDmeAnimationListPanel *v28; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeDagEditPanel_vtbl *)&CDmeDagEditPanel::`vftable';
  if ( `CDmeDagEditPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    v4->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeDagEditPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeDagEditPanel");
    v5->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeDagEditPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagEditPanel");
    v6->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(a1: (int)&savedregs);
  CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(a1: (int)&savedregs);
  v7 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PropertiesSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPropertiesSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pPropertiesSplitter, index: 1);
  v11 = (CDmeDagRenderPanel *)operator new(nSize: 0x524u);
  if ( v11 != nullptr )
    v12 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v11, pParent: v10, pName: "DagRenderPanel");
  else
    v12 = nullptr;
  this->m_pDagRenderPanel = v12;
  v13 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v13 != nullptr )
    v14 = vgui::PropertySheet::PropertySheet(
            this: v13,
            parent: Child,
            panelName: (vgui::Panel *)"EditorSheet",
            draggableTabs: false);
  else
    v14 = nullptr;
  this->m_pEditorSheet = v14;
  v14->AddActionSignalTarget_2(this: v14, a2: this);
  v15 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v15 != nullptr )
    v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pEditorSheet, panelName: "AnimationPage");
  else
    v16 = nullptr;
  this->m_pAnimationPage = v16;
  v17 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v17 != nullptr )
    v18 = vgui::PropertyPage::PropertyPage(this: v17, parent: this->m_pEditorSheet, panelName: "AnimationSetEditor");
  else
    v18 = nullptr;
  this->m_pCombinationPage = v18;
  v19 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v19 != nullptr )
    v20 = vgui::PropertyPage::PropertyPage(this: v19, parent: this->m_pEditorSheet, panelName: "VertexAnimationPage");
  else
    v20 = nullptr;
  this->m_pVertexAnimationPage = v20;
  v21 = (CBaseAnimationSetControl *)operator new(nSize: 0xB4u);
  v22 = v21;
  if ( v21 != nullptr )
  {
    CBaseAnimationSetControl::CBaseAnimationSetControl(this: v21);
    v22->__vftable = (CBaseAnimationSetControl_vtbl *)&CCombinationOperatorControl::`vftable';
    v22[1].__vftable = nullptr;
    v22[1].m_hFilmClip.m_handle = 0;
    v22[1].m_pEditor = nullptr;
    v22[1].m_SelectionHistory.m_Memory.m_pMemory = nullptr;
    v22[1].m_SelectionHistory.m_Memory.m_nAllocationCount = 0;
  }
  else
  {
    v22 = nullptr;
  }
  v23 = (CDmeCombinationOperatorPanel *)operator new(nSize: 0x1BCu);
  if ( v23 != nullptr )
    v24 = CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(
            this: v23,
            parent: this->m_pCombinationPage,
            panelName: (vgui::Panel *)"AnimationSetEditorPanel",
            pAnimationSetController: v22);
  else
    v24 = nullptr;
  this->m_pCombinationPanel = v24;
  v24->CreateToolsSubPanels(this: v24);
  v25 = (CDmeAnimationListPanel *)operator new(nSize: 0x18Cu);
  if ( v25 != nullptr )
    v26 = CDmeAnimationListPanel::CDmeAnimationListPanel(
            this: v25,
            pParent: this->m_pAnimationPage,
            pName: "AnimationListPanel");
  else
    v26 = nullptr;
  this->m_pAnimationListPanel = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  v27 = (CDmeAnimationListPanel *)operator new(nSize: 0x18Cu);
  if ( v27 != nullptr )
    v28 = CDmeAnimationListPanel::CDmeAnimationListPanel(
            this: v27,
            pParent: this->m_pVertexAnimationPage,
            pName: "VertexAnimationListPanel");
  else
    v28 = nullptr;
  this->m_pVertexAnimationListPanel = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  this->m_pCombinationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pCombinationPage,
    a2: "resource/dmedageditpanel_animationseteditorpage.res",
    a3: 0);
  this->m_pAnimationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pAnimationPage,
    a2: "resource/dmedageditpanel_animationpage.res",
    a3: 0);
  this->m_pVertexAnimationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pVertexAnimationPage,
    a2: "resource/dmedageditpanel_vertexanimationpage.res",
    a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmedageditpanel.res",
    dialogID: 0);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pAnimationPage,
    a3: "Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pCombinationPage,
    a3: "Combination",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pVertexAnimationPage,
    a3: "Vertex Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->SetActivePage(this: this->m_pEditorSheet, a2: this->m_pCombinationPage);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104841B0
// Name: void RebuildControlList<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RebuildControlList<SelectionInfo_t>(
        CUtlMemory<vgui::TreeNode *,int> *controlList,
        CDmeFilmClip *pFilmClip)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // esi
  int m_pMemory; // eax
  int v4; // ebx
  CDmeElementRefHelper *v5; // edi
  CDmeTransform *v6; // eax
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v9; // ecx
  CDmElement *v10; // eax
  CExpressionCalculator *v11; // ebx
  void **v12; // eax
  void **v13; // edi
  DmElementHandle_t BufferType; // esi
  CDmElement *v15; // eax
  DmElementHandle_t v16; // ebx
  DmElementHandle_t v17; // eax
  CDmElement *v18; // eax
  vgui::TreeNode *v19; // ebx
  vgui::TreeNode **v20; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v22; // ecx
  int v23; // eax
  vgui::TreeNode **v24; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  int v26; // [esp+14h] [ebp-Ch]
  CDmaElementArray<CDmElement> *controls; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  CDmeAnimationSet *pAnimSet; // [esp+2Ch] [ebp+Ch]

  v2 = controlList;
  m_pMemory = (int)controlList[1].m_pMemory;
  v4 = 0;
  for ( i = m_pMemory; v4 < m_pMemory; ++v4 )
  {
    v5 = (CDmeElementRefHelper *)controlList->m_pMemory[v4];
    if ( v5 != nullptr )
    {
      if ( g_pDataModel != nullptr )
      {
        CDmeElementRefHelper::Unref(this: v5 + 4, hElement: *(DmElementHandle_t *)&v5[4], handleType: HT_WEAK);
        if ( g_pDataModel != nullptr )
          CDmeElementRefHelper::Unref(this: v5, hElement: *(_DWORD *)v5, handleType: HT_WEAK);
      }
      CUtlMemoryPool::Free(this: &SelectionInfo_t::s_Allocator, memBlock: v5);
      m_pMemory = i;
    }
  }
  traversal.m_pFilmClip = pFilmClip;
  controlList[1].m_pMemory = nullptr;
  traversal.m_nIndex = 0;
  v6 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pAnimSet = (CDmeAnimationSet *)v6;
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v6);
      m_Size = Position->m_Storage.m_Size;
      v9 = 0;
      controls = Position;
      v26 = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Position->m_Storage.m_Memory.m_pMemory[v9]);
          v11 = (CExpressionCalculator *)v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            v12 = CUtlMemoryPool::Alloc(this: &SelectionInfo_t::s_Allocator, amount: 0xCu);
            v13 = v12;
            if ( v12 != nullptr )
            {
              *v12 = (void *)-1;
              if ( pAnimSet != nullptr )
                BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
              else
                BufferType = DMELEMENT_HANDLE_INVALID;
              if ( (void *)BufferType != *v13 )
              {
                CDmeElementRefHelper::Unref(
                  this: (CDmeElementRefHelper *)v13,
                  hElement: (DmElementHandle_t)*v13,
                  handleType: HT_WEAK);
                *v13 = (void *)BufferType;
                if ( BufferType != DMELEMENT_HANDLE_INVALID )
                {
                  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
                  if ( v15 != nullptr && !v15->IsA(this: v15, a2: CDmeAnimationSet::m_classType) )
                    *v13 = (void *)-1;
                }
                CDmeElementRefHelper::Ref(
                  this: (CDmeElementRefHelper *)v13,
                  hElement: (DmElementHandle_t)*v13,
                  handleType: HT_WEAK);
              }
              v13[1] = (void *)-1;
              v16 = CCodecBuffer_Block::GetBufferType(this: v11);
              v17 = (DmElementHandle_t)v13[1];
              if ( v16 != v17 )
              {
                CDmeElementRefHelper::Unref(this: (CDmeElementRefHelper *)v13 + 4, hElement: v17, handleType: HT_WEAK);
                v13[1] = (void *)v16;
                if ( v16 != DMELEMENT_HANDLE_INVALID )
                {
                  v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: v16);
                  if ( v18 != nullptr && !v18->IsA(this: v18, a2: CDmElement::m_classType) )
                    v13[1] = (void *)-1;
                }
                CDmeElementRefHelper::Ref(
                  this: (CDmeElementRefHelper *)v13 + 4,
                  hElement: (DmElementHandle_t)v13[1],
                  handleType: HT_WEAK);
              }
              v2 = controlList;
              v13[2] = nullptr;
              v19 = (vgui::TreeNode *)v13;
            }
            else
            {
              v19 = nullptr;
            }
            v20 = v2[1].m_pMemory;
            m_nAllocationCount = v2->m_nAllocationCount;
            if ( (int)v20 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v2, num: (int)v20 - m_nAllocationCount + 1);
            ++v2[1].m_pMemory;
            v22 = v2->m_pMemory;
            v23 = (char *)v2[1].m_pMemory - (char *)v20 - 1;
            v2[1].m_nAllocationCount = (int)v2->m_pMemory;
            if ( v23 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&v22[(_DWORD)v20 + 1],
                src: (unsigned __int8 *)&v22[(_DWORD)v20],
                count: 4 * v23);
            v24 = &v2->m_pMemory[(_DWORD)v20];
            if ( v24 != nullptr )
              *v24 = v19;
          }
          v9 = i + 1;
          i = v9;
          if ( v9 >= v26 )
            break;
          Position = controls;
        }
      }
      pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( pAnimSet == nullptr )
        break;
      v6 = (CDmeTransform *)pAnimSet;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10484420
// Name: void AddMissingControls<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddMissingControls<SelectionInfo_t>(
        CUtlMemory<vgui::TreeNode *,int> *controlList,
        CDmeFilmClip *pFilmClip)
{
  CDmeTransform *v2; // eax
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v5; // ecx
  CDmElement *v6; // eax
  CExpressionCalculator *v7; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  int v9; // edi
  void **v10; // eax
  void **v11; // edi
  DmElementHandle_t BufferType; // esi
  CDmElement *v13; // eax
  DmElementHandle_t v14; // ebx
  DmElementHandle_t v15; // eax
  CDmElement *v16; // eax
  vgui::TreeNode *v17; // ebx
  vgui::TreeNode **v18; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // edi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-18h] BYREF
  int nControls; // [esp+14h] [ebp-10h]
  int m_pMemory; // [esp+18h] [ebp-Ch]
  CDmaElementArray<CDmElement> *controls; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  CDmeAnimationSet *pAnimSet; // [esp+30h] [ebp+Ch]

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v2 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pAnimSet = (CDmeAnimationSet *)v2;
  if ( v2 != nullptr )
  {
    while ( 1 )
    {
      Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v2);
      m_Size = Position->m_Storage.m_Size;
      v5 = 0;
      controls = Position;
      nControls = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: Position->m_Storage.m_Memory.m_pMemory[v5]);
          v7 = (CExpressionCalculator *)v6;
          if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
          {
            v8 = controlList;
            v9 = 0;
            m_pMemory = (int)controlList[1].m_pMemory;
            if ( m_pMemory <= 0 )
            {
LABEL_12:
              v10 = CUtlMemoryPool::Alloc(this: &SelectionInfo_t::s_Allocator, amount: 0xCu);
              v11 = v10;
              if ( v10 != nullptr )
              {
                *v10 = (void *)-1;
                if ( pAnimSet != nullptr )
                  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
                else
                  BufferType = DMELEMENT_HANDLE_INVALID;
                if ( (void *)BufferType != *v11 )
                {
                  CDmeElementRefHelper::Unref(
                    this: (CDmeElementRefHelper *)v11,
                    hElement: (DmElementHandle_t)*v11,
                    handleType: HT_WEAK);
                  *v11 = (void *)BufferType;
                  if ( BufferType != DMELEMENT_HANDLE_INVALID )
                  {
                    v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
                    if ( v13 != nullptr && !v13->IsA(this: v13, a2: CDmeAnimationSet::m_classType) )
                      *v11 = (void *)-1;
                  }
                  CDmeElementRefHelper::Ref(
                    this: (CDmeElementRefHelper *)v11,
                    hElement: (DmElementHandle_t)*v11,
                    handleType: HT_WEAK);
                }
                v11[1] = (void *)-1;
                v14 = CCodecBuffer_Block::GetBufferType(this: v7);
                v15 = (DmElementHandle_t)v11[1];
                if ( v14 != v15 )
                {
                  CDmeElementRefHelper::Unref(this: (CDmeElementRefHelper *)v11 + 4, hElement: v15, handleType: HT_WEAK);
                  v11[1] = (void *)v14;
                  if ( v14 != DMELEMENT_HANDLE_INVALID )
                  {
                    v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
                    if ( v16 != nullptr && !v16->IsA(this: v16, a2: CDmElement::m_classType) )
                      v11[1] = (void *)-1;
                  }
                  CDmeElementRefHelper::Ref(
                    this: (CDmeElementRefHelper *)v11 + 4,
                    hElement: (DmElementHandle_t)v11[1],
                    handleType: HT_WEAK);
                }
                v8 = controlList;
                v11[2] = nullptr;
                v17 = (vgui::TreeNode *)v11;
              }
              else
              {
                v17 = nullptr;
              }
              v18 = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)v18 + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)v18 - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v20 = v8->m_pMemory;
              v21 = (char *)v8[1].m_pMemory - (char *)v18 - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v21 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&v20[(_DWORD)v18 + 1],
                  src: (unsigned __int8 *)&v20[(_DWORD)v18],
                  count: 4 * v21);
              v22 = &v8->m_pMemory[(_DWORD)v18];
              if ( v22 != nullptr )
                *v22 = v17;
            }
            else
            {
              while ( (CExpressionCalculator *)g_pDataModel->GetElement(
                                                 this: g_pDataModel,
                                                 a2: *(_DWORD *)&controlList->m_pMemory[v9]->vgui::Panel::m_RegisterClass) != v7 )
              {
                if ( ++v9 >= m_pMemory )
                  goto LABEL_12;
              }
            }
          }
          v5 = i + 1;
          i = v5;
          if ( v5 >= nControls )
            break;
          Position = controls;
        }
      }
      pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( pAnimSet == nullptr )
        break;
      v2 = (CDmeTransform *)pAnimSet;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10484660
// Name: public: virtual void CCombinationOperatorControl::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombinationOperatorControl::ChangeAnimationSetClip(
        CCombinationOperatorControl *this,
        CDmeFilmClip *pFilmClip)
{
  RebuildControlList<SelectionInfo_t>(
    controlList: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FullControlList,
    pFilmClip);
  CBaseAnimationSetControl::ChangeAnimationSetClip(this, pFilmClip);
}

//------------------------------------------------------------------------------
// Address: 0x10484690
// Name: public: virtual void CCombinationOperatorControl::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombinationOperatorControl::OnControlsAddedOrRemoved(CCombinationOperatorControl *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_FullControlList; // edi
  CDmeFilmClip *v3; // eax

  p_m_FullControlList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FullControlList;
  RemoveNullControls<SelectionInfo_t>(controlList: &this->m_FullControlList);
  v3 = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  AddMissingControls<SelectionInfo_t>(controlList: p_m_FullControlList, pFilmClip: v3);
  CBaseAnimationSetControl::OnControlsAddedOrRemoved(this);
}

//------------------------------------------------------------------------------
// Address: 0x104846D0
// Name: protected: void CDmeDagEditPanel::SetMakefileRootElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetMakefileRootElement(CDmeDagEditPanel *this, CDmElement *pRoot)
{
  CDmeAnimationList *Value; // eax
  CDmeAnimationList *v4; // eax
  CDmeCombinationOperator *v5; // eax

  Value = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "animationList");
  CDmeDagEditPanel::SetAnimationList(this, pAnimationList: Value);
  v4 = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "vertexAnimationList");
  CDmeDagEditPanel::SetVertexAnimationList(this, pAnimationList: v4);
  v5 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: pRoot, pAttributeName: "combinationOperator");
  CDmeCombinationOperatorPanel::SetCombinationOperator(this: this->m_pCombinationPanel, pOp: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10484720
// Name: public: void CDmeDagEditPanel::SetDmeElement(class CDmeDCCMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetDmeElement(CDmeDagEditPanel *this, CDmeDCCMakefile *pDCCMakefile)
{
  CDmElement *OutputElement; // eax
  CDmElement *v4; // edi
  CDmeAnimationList *Value; // eax
  CDmeAnimationList *v6; // eax
  CDmeCombinationOperator *v7; // eax

  CDmeDagRenderPanel::SetDmeElement(this: this->m_pDagRenderPanel, pDCCMakefile);
  OutputElement = CDmeMakefile::GetOutputElement(this: pDCCMakefile, bCreateIfNecessary: true);
  v4 = OutputElement;
  if ( OutputElement != nullptr )
  {
    Value = CDmElement::GetValueElement<CDmeAnimationList>(this: OutputElement, pAttributeName: "animationList");
    CDmeDagEditPanel::SetAnimationList(this, pAnimationList: Value);
    v6 = CDmElement::GetValueElement<CDmeAnimationList>(this: v4, pAttributeName: "vertexAnimationList");
    CDmeDagEditPanel::SetVertexAnimationList(this, pAnimationList: v6);
    v7 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: v4, pAttributeName: "combinationOperator");
    CDmeCombinationOperatorPanel::SetCombinationOperator(this: this->m_pCombinationPanel, pOp: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10488340
// Name: protected: void CBaseAnimationSetControl::ApplyTransformSliderValue<class Quaternion>(class CAttributeSlider __near *,class CDmeTransformControl __near *,bool,bool,bool __near &,enum AnimationControlType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyTransformSliderValue<Quaternion>(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        vgui::BuildGroup *pTranformControl,
        DmeTime_t bUsePreviewValue,
        bool bForce,
        bool *valuesChanged,
        AnimationControlType_t type)
{
  AnimationControlType_t v7; // ebx
  CDmAttribute *PositionAttr; // esi
  CDmeChannel *PositionChannel; // eax
  CDmeChannel *v10; // edi
  ChannelMode_t Mode; // eax
  char v12; // cl
  DmeTime_t *CurrentTime; // eax
  Quaternion *v14; // eax
  LogComponents_t v15; // eax
  Quaternion maskedValue; // [esp+Ch] [ebp-30h] BYREF
  Quaternion currentValue; // [esp+1Ch] [ebp-20h] BYREF
  Quaternion value; // [esp+2Ch] [ebp-10h] BYREF

  v7 = type;
  if ( type == ANIM_CONTROL_COUNT )
  {
    PositionAttr = (CDmAttribute *)CDmeTransformControl::GetPositionAttr(this: pTranformControl);
    PositionChannel = CDmeTransformControl::GetPositionChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  else
  {
    if ( type != ANIM_CONTROL_TXFORM_ORIENTATION )
      return;
    PositionAttr = CDmeTransformControl::GetOrientationAttr(this: (CDmeTransformControl *)pTranformControl);
    PositionChannel = CDmeTransformControl::GetOrientationChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  v10 = PositionChannel;
  if ( PositionAttr != nullptr )
  {
    if ( PositionChannel != nullptr )
    {
      Mode = CDmeChannel::GetMode(this: PositionChannel);
      if ( Mode != CM_PASS && Mode != CM_RECORD )
      {
        v12 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      Mode = CM_PASS;
    }
    v12 = 1;
LABEL_12:
    if ( Mode == CM_PLAY )
    {
      value = *CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
      CurrentTime = CDmeChannel::GetCurrentTime(this: v10, result: &bUsePreviewValue);
      CDmeChannel::GetPlaybackValueAtTime<Quaternion>(this: v10, time: (DmeTime_t)CurrentTime->m_tms, &value);
      CAttributeSlider::SetValue(this: pSlider, type: v7, quat: &value);
      CDmAttribute::SetValue<Quaternion>(this: PositionAttr, &value);
    }
    else if ( v12 != 0 )
    {
      if ( LOBYTE(bUsePreviewValue.m_tms) != 0 )
        CAttributeSlider::GetPreview(this: pSlider, type: v7, out: &value);
      else
        CAttributeSlider::GetValue(this: pSlider, type: v7, out: &value);
      v14 = (Quaternion *)CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
      if ( Quaternion::operator!=(this: v14, src: &value) || bForce )
      {
        *valuesChanged = bForce;
        currentValue = *CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
        v15 = CAttributeSlider::VisibleComponents(this: pSlider);
        MaskValue<Quaternion>(result: &maskedValue, &value, curQuat: &currentValue, componentFlags: v15);
        CDmAttribute::SetValue<Quaternion>(this: PositionAttr, value: &maskedValue);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104884A0
// Name: protected: void CBaseAnimationSetControl::ApplyTransformSliderValue<class Vector>(class CAttributeSlider __near *,class CDmeTransformControl __near *,bool,bool,bool __near &,enum AnimationControlType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyTransformSliderValue<Vector>(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        vgui::BuildGroup *pTranformControl,
        DmeTime_t bUsePreviewValue,
        bool bForce,
        bool *valuesChanged,
        AnimationControlType_t type)
{
  AnimationControlType_t v7; // ebx
  CDmAttribute *PositionAttr; // edi
  CDmeChannel *PositionChannel; // eax
  CDmeChannel *v10; // esi
  ChannelMode_t Mode; // eax
  char v12; // cl
  DmeTime_t *CurrentTime; // eax
  CDmaVar<Vector> *v14; // eax
  char v15; // al
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  Vector maskedValue; // [esp+18h] [ebp-18h] BYREF
  Vector out; // [esp+24h] [ebp-Ch] BYREF
  Vector currentValue; // 0:^14.12

  v7 = type;
  if ( type == ANIM_CONTROL_COUNT )
  {
    PositionAttr = (CDmAttribute *)CDmeTransformControl::GetPositionAttr(this: pTranformControl);
    PositionChannel = CDmeTransformControl::GetPositionChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  else
  {
    if ( type != ANIM_CONTROL_TXFORM_ORIENTATION )
      return;
    PositionAttr = CDmeTransformControl::GetOrientationAttr(this: (CDmeTransformControl *)pTranformControl);
    PositionChannel = CDmeTransformControl::GetOrientationChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  v10 = PositionChannel;
  if ( PositionAttr != nullptr )
  {
    if ( PositionChannel != nullptr )
    {
      Mode = CDmeChannel::GetMode(this: PositionChannel);
      if ( Mode != CM_PASS && Mode != CM_RECORD )
      {
        v12 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      Mode = CM_PASS;
    }
    v12 = 1;
LABEL_12:
    if ( Mode == CM_PLAY )
    {
      maskedValue = CDmAttribute::GetValue<Vector>(this: PositionAttr)->m_Storage;
      CurrentTime = CDmeChannel::GetCurrentTime(this: v10, result: &bUsePreviewValue);
      CDmeChannel::GetPlaybackValueAtTime<Vector>(this: v10, time: (DmeTime_t)CurrentTime->m_tms, value: &maskedValue);
      CAttributeSlider::SetValue(this: pSlider, type: v7, vec: &maskedValue);
      CDmAttribute::SetValue<Vector>(this: PositionAttr, value: &maskedValue);
    }
    else if ( v12 != 0 )
    {
      if ( LOBYTE(bUsePreviewValue.m_tms) != 0 )
        CAttributeSlider::GetPreview(this: pSlider, type: v7, &out);
      else
        CAttributeSlider::GetValue(this: pSlider, type: v7, &out);
      v14 = CDmAttribute::GetValue<Vector>(this: PositionAttr);
      if ( out.x != v14->m_Storage.x || out.y != v14->m_Storage.y || out.z != v14->m_Storage.z || bForce )
      {
        *valuesChanged = bForce;
        currentValue = CDmAttribute::GetValue<Vector>(this: PositionAttr)->m_Storage;
        v15 = CAttributeSlider::VisibleComponents(this: pSlider);
        if ( (v15 & 1) != 0 )
          x = out.x;
        else
          x = currentValue.x;
        maskedValue.x = x;
        if ( (v15 & 2) != 0 )
          y = out.y;
        else
          y = currentValue.y;
        maskedValue.y = y;
        if ( (v15 & 4) != 0 )
          z = out.z;
        else
          z = currentValue.z;
        maskedValue.z = z;
        CDmAttribute::SetValue<Vector>(this: PositionAttr, value: &maskedValue);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CC940
// Name: _CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__()
{
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    sg.m_pControl->FireControlSelectionChangedListeners(this: sg.m_pControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481790
// Name: class CDmeAnimationSet __near * CastElement<class CDmeAnimationSet>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl CastElement<CDmeAnimationSet>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeAnimationSet::m_classType.u.m_Id) )
  {
    return (CDmeAnimationSet *)pElement;
  }
  else
  {
    return nullptr;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004549C0
// Name: public: static char const __near * CDmeDagEditPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeDagEditPanel::GetPanelClassName()
{
  return "CDmeDagEditPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004549D0
// Name: public: static char const __near * CDmeAnimationListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeAnimationListPanel::GetPanelClassName()
{
  return "CDmeAnimationListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004549E0
// Name: public: char const __near * CDmeAnimationListPanel::GetSelectedAnimation(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeAnimationListPanel::GetSelectedAnimation(CDmeAnimationListPanel *this)
{
  int v3; // eax
  KeyValues *v4; // eax

  if ( this->m_pAnimationList->GetSelectedItemsCount(this: this->m_pAnimationList) == 0 )
    return defaultValue;
  v3 = this->m_pAnimationList->GetSelectedItem(this: this->m_pAnimationList, a2: 0);
  v4 = this->m_pAnimationList->GetItem(this: this->m_pAnimationList, a2: v3);
  return KeyValues::GetString(this: v4, keyName: "name", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x00454A40
// Name: private: virtual void CDmeAnimationListPanel::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::OnItemSelected(CDmeAnimationListPanel *this)
{
  const char *String; // edi
  int v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pAnimationList->GetSelectedItemsCount(this: this->m_pAnimationList) != 0 )
  {
    v3 = this->m_pAnimationList->GetSelectedItem(this: this->m_pAnimationList, a2: 0);
    v4 = this->m_pAnimationList->GetItem(this: this->m_pAnimationList, a2: v3);
    String = KeyValues::GetString(this: v4, keyName: "name", defaultValue: defaultValue);
  }
  else
  {
    String = defaultValue;
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(this: v5, setName: "AnimationSelected", firstKey: "animationName", firstValue: String);
    this->PostActionSignal(this, a2: v6);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454AE0
// Name: private: virtual void CDmeAnimationListPanel::OnItemDeselected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::OnItemDeselected(CDmeAnimationListPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "AnimationDeselected");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454B20
// Name: public: static char const __near * CDmeCombinationOperatorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeCombinationOperatorPanel::GetPanelClassName()
{
  return "CDmeCombinationOperatorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00454B30
// Name: public: virtual CDmeDagEditPanel::~CDmeDagEditPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::~CDmeDagEditPanel(CDmeDagEditPanel *this)
{
  this->__vftable = (CDmeDagEditPanel_vtbl *)&CDmeDagEditPanel::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00454B40
// Name: public: virtual void CDmeDagEditPanel::SetDmeElement(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetDmeElement(CDmeDagEditPanel *this, CDmeDag *pScene)
{
  CDmeDagRenderPanel::SetDmeElement(this: this->m_pDagRenderPanel, pScene);
}

//------------------------------------------------------------------------------
// Address: 0x00454B50
// Name: public: class CDmeDag __near * CDmeDagEditPanel::GetDmeElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDagEditPanel::GetDmeElement(CDmeDagEditPanel *this)
{
  return CDmeDagRenderPanel::GetDmeElement(this: this->m_pDagRenderPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00454B60
// Name: protected: virtual void CDmeDagEditPanel::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnPageChanged(CDmeDagEditPanel *this)
{
  const char *v2; // eax
  const char *SelectedAnimation; // [esp-4h] [ebp-8h]

  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pCombinationPage )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
LABEL_3:
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
    return;
  }
  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pAnimationPage )
  {
    SelectedAnimation = CDmeAnimationListPanel::GetSelectedAnimation(this: this->m_pAnimationListPanel);
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: SelectedAnimation);
    goto LABEL_3;
  }
  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) == this->m_pVertexAnimationPage )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
    v2 = CDmeAnimationListPanel::GetSelectedAnimation(this: this->m_pVertexAnimationListPanel);
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454C10
// Name: protected: virtual void CDmeDagEditPanel::OnAnimationSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnAnimationSelected(CDmeDagEditPanel *this, KeyValues *pKeyValues)
{
  CDmeAnimationListPanel *Ptr; // edi
  const char *String; // eax

  Ptr = (CDmeAnimationListPanel *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  String = KeyValues::GetString(this: pKeyValues, keyName: "animationName", defaultValue: defaultValue);
  if ( Ptr == this->m_pAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: String);
  }
  else if ( Ptr == this->m_pVertexAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454C80
// Name: protected: virtual void CDmeDagEditPanel::OnAnimationDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::OnAnimationDeselected(CDmeDagEditPanel *this, KeyValues *pKeyValues)
{
  CDmeAnimationListPanel *Ptr; // eax

  Ptr = (CDmeAnimationListPanel *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  }
  else if ( Ptr == this->m_pVertexAnimationListPanel )
  {
    CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454DD0
// Name: public: class CDmAttribute __near * CDmElement::InitValue<float>(char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<float>(CDmElement *this, const char *pAttributeName, const float *value)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00454E50
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeDagEditPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeDagEditPanel::GetMessageMap(CDmeDagEditPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeDagEditPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagEditPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeDagEditPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
  `CDmeDagEditPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00454E80
// Name: public: virtual struct PanelAnimationMap __near * CDmeDagEditPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeDagEditPanel::GetAnimMap(CDmeDagEditPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeDagEditPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00454E90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeDagEditPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeDagEditPanel::GetKBMap(CDmeDagEditPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeDagEditPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagEditPanel::GetKBMap'::`2'::s_pMap;
  `CDmeDagEditPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagEditPanel");
  `CDmeDagEditPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00454EC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeAnimationListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeAnimationListPanel::GetMessageMap(CDmeAnimationListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeAnimationListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeAnimationListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeAnimationListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
  `CDmeAnimationListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00454EF0
// Name: public: virtual struct PanelAnimationMap __near * CDmeAnimationListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeAnimationListPanel::GetAnimMap(CDmeAnimationListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeAnimationListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00454F00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeAnimationListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeAnimationListPanel::GetKBMap(CDmeAnimationListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeAnimationListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeAnimationListPanel::GetKBMap'::`2'::s_pMap;
  `CDmeAnimationListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeAnimationListPanel");
  `CDmeAnimationListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00454FB0
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(
        CDmeCombinationOperatorPanel *this,
        CDmElement *pControlElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // edi
  int v5; // eax
  CDmeCombinationOperator *v6; // eax
  int ComboOpControlIndexForAnimSetControl; // edi
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  int (__stdcall *v10)(DmElementHandle_t); // eax
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v14; // eax
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  int (__stdcall *v17)(DmElementHandle_t); // edx
  int v18; // eax
  CDmeCombinationOperator *v19; // ecx
  CDmAttribute *v20; // eax
  int v21; // eax
  CDmeCombinationOperator *v22; // ecx
  const Vector2D *StereoControlValue; // edi
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-1Ch]
  DmElementHandle_t v28; // [esp-4h] [ebp-1Ch]
  float flDefaultValue; // [esp+Ch] [ebp-Ch] BYREF
  float flValue; // [esp+10h] [ebp-8h] BYREF
  bool bIsStereoControl; // [esp+17h] [ebp-1h]

  v2 = pControlElement;
  m_pAsString = defaultValue;
  if ( pControlElement->m_Name.m_Storage.u.m_Id != -1 )
    m_pAsString = pControlElement->m_Name.m_Storage.u.m_pAsString;
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v5 != 0 )
    v6 = (CDmeCombinationOperator *)(v5 - 4);
  else
    v6 = nullptr;
  ComboOpControlIndexForAnimSetControl = FindComboOpControlIndexForAnimSetControl(
                                           pComboOp: v6,
                                           pControlName: m_pAsString,
                                           pIsMulti: (bool *)&pControlElement + 3);
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v8 != 0 )
    v9 = (CDmeCombinationOperator *)(v8 - 4);
  else
    v9 = nullptr;
  flDefaultValue = CDmeCombinationOperator::GetControlDefaultValue(
                     this: v9,
                     nControl: ComboOpControlIndexForAnimSetControl);
  v10 = *(int (__stdcall **)(DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_handle = this->m_hCombinationOperator.m_handle;
  if ( HIBYTE(pControlElement) != 0 )
  {
    v11 = v10(a1: m_handle);
    if ( v11 != 0 )
      v12 = (CDmeCombinationOperator *)(v11 - 4);
    else
      v12 = nullptr;
    flValue = CDmeCombinationOperator::GetMultiControlLevel(
                this: v12,
                nControlIndex: ComboOpControlIndexForAnimSetControl,
                type: COMBO_CONTROL_FIRST);
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "value");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v2, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: Attribute, value: &flValue);
    }
    flValue = 0.5;
    v14 = CDmElement::FindAttribute(this: v2, pAttributeName: "defaultValue");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: v2, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v14, value: &flValue);
    }
  }
  else
  {
    v15 = v10(a1: m_handle);
    if ( v15 != 0 )
      v16 = (CDmeCombinationOperator *)(v15 - 4);
    else
      v16 = nullptr;
    bIsStereoControl = CDmeCombinationOperator::IsStereoControl(
                         this: v16,
                         nControlIndex: ComboOpControlIndexForAnimSetControl);
    if ( CDmElement::HasAttribute(this: v2, pAttributeName: "rightValue", type: AT_UNKNOWN) != bIsStereoControl )
    {
      v17 = *(int (__stdcall **)(DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
      v28 = this->m_hCombinationOperator.m_handle;
      if ( bIsStereoControl )
      {
        v21 = v17(a1: v28);
        if ( v21 != 0 )
          v22 = (CDmeCombinationOperator *)(v21 - 4);
        else
          v22 = nullptr;
        StereoControlValue = CDmeCombinationOperator::GetStereoControlValue(
                               this: v22,
                               nControlIndex: ComboOpControlIndexForAnimSetControl,
                               type: COMBO_CONTROL_FIRST);
        v24 = CDmElement::FindAttribute(this: v2, pAttributeName: "leftValue");
        if ( v24 != nullptr
          || (v24 = CDmElement::CreateAttribute(this: v2, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v24, value: &StereoControlValue->x);
        }
        v25 = CDmElement::FindAttribute(this: v2, pAttributeName: "rightValue");
        if ( v25 != nullptr
          || (v25 = CDmElement::CreateAttribute(this: v2, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v25, value: &StereoControlValue->y);
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "value");
      }
      else
      {
        v18 = v17(a1: v28);
        if ( v18 != 0 )
          v19 = (CDmeCombinationOperator *)(v18 - 4);
        else
          v19 = nullptr;
        flValue = CDmeCombinationOperator::GetControlValue(
                    this: v19,
                    nControlIndex: ComboOpControlIndexForAnimSetControl,
                    type: COMBO_CONTROL_FIRST);
        v20 = CDmElement::FindAttribute(this: v2, pAttributeName: "value");
        if ( v20 != nullptr
          || (v20 = CDmElement::CreateAttribute(this: v2, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v20, value: &flValue);
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "leftValue");
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "rightValue");
      }
    }
    v26 = CDmElement::FindAttribute(this: v2, pAttributeName: "defaultValue");
    if ( v26 != nullptr
      || (v26 = CDmElement::CreateAttribute(this: v2, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v26, value: &flDefaultValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455220
// Name: private: void CDmeCombinationOperatorPanel::SortAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::SortAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeCombinationOperatorPanel *v1; // edi
  CBaseAnimationSetControl *m_pController; // ecx
  CDmeTransform *v3; // ebx
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // esi
  int v6; // eax
  CDmeCombinationOperator *v7; // ecx
  void *v8; // esp
  DmElementHandle_t *v9; // eax
  _DWORD *v10; // esi
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  const char *ControlName; // edi
  CExpressionCalculator *Control; // eax
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  CExpressionCalculator *v17; // eax
  _BYTE v18[12]; // [esp+0h] [ebp-12Ch] BYREF
  char pMultiControlName[256]; // [esp+Ch] [ebp-120h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+10Ch] [ebp-20h] BYREF
  DmElementHandle_t *pElements; // [esp+114h] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+118h] [ebp-14h]
  int nControlCount; // [esp+11Ch] [ebp-10h]
  int nCombinationControlCount; // [esp+120h] [ebp-Ch]
  CDmeCombinationOperatorPanel *v25; // [esp+124h] [ebp-8h]
  int i; // [esp+128h] [ebp-4h]

  v1 = this;
  m_pController = this->m_pController;
  v25 = v1;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  v3 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  v3->OnElementUnserialized(this: v3);
  Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v3);
  m_Size = Position->m_Storage.m_Size;
  controls = Position;
  nControlCount = m_Size;
  if ( m_Size != 0 )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v1->m_hCombinationOperator.m_handle);
    if ( v6 != 0 )
      v7 = (CDmeCombinationOperator *)(v6 - 4);
    else
      v7 = nullptr;
    nCombinationControlCount = CDmeMaterialGroup::GetListAttr(this: v7);
    v8 = alloca(4 * m_Size);
    v9 = (DmElementHandle_t *)v18;
    pElements = (DmElementHandle_t *)v18;
    i = 0;
    if ( nCombinationControlCount > 0 )
    {
      v10 = v18;
      while ( 1 )
      {
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v1->m_hCombinationOperator.m_handle);
        v12 = v11 != 0 ? (CDmeCombinationOperator *)(v11 - 4) : nullptr;
        ControlName = CDmeCombinationOperator::GetControlName(this: v12, i);
        Control = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                             this: (CDmeAnimationSet *)v3,
                                             pControlName: ControlName);
        *v10++ = CCodecBuffer_Block::GetBufferType(this: Control);
        v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v25->m_hCombinationOperator.m_handle);
        v16 = v15 != 0 ? (CDmeCombinationOperator *)(v15 - 4) : nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v16, nControlIndex: i) )
        {
          V_snprintf(pDest: pMultiControlName, maxLen: 256, pFormat: "multi_%s", ControlName);
          v17 = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                           this: (CDmeAnimationSet *)v3,
                                           pControlName: pMultiControlName);
          *v10++ = CCodecBuffer_Block::GetBufferType(this: v17);
        }
        if ( ++i >= nCombinationControlCount )
          break;
        v1 = v25;
      }
      m_Size = nControlCount;
      v9 = pElements;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::SetMultiple(
      this: controls,
      i: 0,
      nCount: m_Size,
      pValue: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455440
// Name: public: void CDmeAnimationListPanel::RefreshAnimationList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationListPanel::RefreshAnimationList(CDmeAnimationListPanel *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // esi
  KeyValues *v6; // eax
  const char *v7; // edx
  const KeyValues *v8; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  this->m_pAnimationList->RemoveAll(this: this->m_pAnimationList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hAnimationList.m_handle) != 0 )
  {
    v2 = 0;
    nCount = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hAnimationList.m_handle)
                       + 80);
    if ( nCount > 0 )
    {
      do
      {
        v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_hAnimationList.m_handle);
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * v2));
        v5 = v4;
        if ( v4 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
               a1: v4,
               a2: CDmeChannelsClip::m_classType.u) == 0 )
        {
          v5 = 0;
        }
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
        {
          v7 = *(const char **)(v5 + 20);
          if ( v7 == (const char *)-1 )
            v7 = defaultValue;
          v8 = KeyValues::KeyValues(this: v6, setName: "node", firstKey: "name", firstValue: v7);
        }
        else
        {
          v8 = nullptr;
        }
        this->m_pAnimationList->AddItem(this: this->m_pAnimationList, a2: v8, a3: 0, a4: false, a5: false);
        ++v2;
      }
      while ( v2 < nCount );
    }
    this->m_pAnimationList->SortList(this: this->m_pAnimationList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455560
// Name: private: void CDmeCombinationOperatorPanel::CreateFakeAnimationSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::CreateFakeAnimationSet(CDmeCombinationOperatorPanel *this)
{
  int v1; // eax
  int v2; // eax
  CDmeFilmClip *v3; // esi
  CDmeFilmClip *v4; // ebx
  int v5; // eax
  int v6; // eax
  CDmElement *v7; // edi
  CDmAttribute *Attribute; // eax
  CDmaElementArray<CDmeAnimationSet> *AnimationSets; // esi
  int v10; // edi
  int BufferType; // eax
  DmElementHandle_t value; // [esp+10h] [ebp-4h] BYREF

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeFilmClip::m_classType.u,
         a3: "fakeFilmClip",
         a4: -1,
         a5: 0);
  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v1);
  v3 = (CDmeFilmClip *)v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeFilmClip::m_classType.u) != 0 )
  {
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeAnimationSet::m_classType.u,
         a3: "fakeAnimSet",
         a4: -1,
         a5: 0);
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v5);
  v7 = (CDmElement *)v6;
  if ( v6 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeAnimationSet::m_classType.u) == 0 )
  {
    v7 = nullptr;
  }
  value = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "gameModel");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v7, pAttributeName: "gameModel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
  }
  AnimationSets = CDmeFilmClip::GetAnimationSets(this: v4);
  if ( v7 != nullptr )
    value = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
  else
    value = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: AnimationSets,
    src: &value);
  v10 = *(_DWORD *)g_pDataModel.u.m_Id;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v4);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v10 + 416))(a1: g_pDataModel.u, a2: BufferType);
  CBaseAnimationSetEditor::ChangeAnimationSetClip(this, pFilmClip: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004556A0
// Name: private: void CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(
        CDmeCombinationOperatorPanel *this,
        const char *pControlName)
{
  int v2; // edi
  CDmeAnimationSet *v3; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // esi
  CDmAttribute *m_pAttribute; // eax
  DmElementArray_t *m_pData; // eax
  int v7; // ebx
  int v8; // eax
  CDmeTransformControl *v9; // esi
  CDmeTransformControl *v10; // ecx
  const Vector *Position; // esi
  float x; // eax
  DmElementArray_t *v13; // eax
  int v14; // eax
  CDmeTransform *v15; // esi
  CDmeTransform *v16; // ecx
  const Vector *v17; // esi
  float v18; // eax
  DmElementArray_t *m_pStorage; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // esi
  const char *v23; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-30h] BYREF
  CDmrElementArray<CDmePreset> presetList; // [esp+14h] [ebp-28h] BYREF
  CDmrElementArray<CDmePresetGroup> presetGroupList; // [esp+1Ch] [ebp-20h] BYREF
  CDmrElementArray<CDmElement> controlValues; // [esp+24h] [ebp-18h] BYREF
  int i; // [esp+2Ch] [ebp-10h]
  int m_Size; // [esp+30h] [ebp-Ch]
  int v30; // [esp+34h] [ebp-8h]
  int j; // [esp+38h] [ebp-4h]

  v2 = 0;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v3);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupList);
  m_pAttribute = PresetGroups->m_pAttribute;
  if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    presetGroupList.m_pAttribute = PresetGroups->m_pAttribute;
    m_pData = (DmElementArray_t *)m_pAttribute->m_pData;
    presetGroupList.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    presetGroupList.m_pAttribute = nullptr;
    presetGroupList.m_pStorage = nullptr;
    m_Size = 0;
  }
  v7 = 0;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[v7]);
      v9 = (CDmeTransformControl *)v8;
      if ( v8 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmePresetGroup::m_classType.u) != 0 )
      {
        v10 = v9;
      }
      else
      {
        v10 = nullptr;
      }
      Position = CDmeTransformControl::GetPosition(this: v10);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetList);
      x = Position[2].x;
      if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
      {
        v13 = nullptr;
        presetList.m_pAttribute = nullptr;
        presetList.m_pStorage = nullptr;
        v30 = 0;
      }
      else
      {
        presetList.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
        v13 = *(DmElementArray_t **)(LODWORD(x) + 4);
        presetList.m_pStorage = v13;
        v30 = v13->m_Size;
      }
      j = 0;
      if ( v30 > 0 )
      {
        while ( 1 )
        {
          v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: v13->m_Memory.m_pMemory[j]);
          v15 = (CDmeTransform *)v14;
          if ( v14 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
                 a1: v14,
                 a2: CDmePreset::m_classType.u) != 0 )
          {
            v16 = v15;
          }
          else
          {
            v16 = nullptr;
          }
          v17 = CDmeTransform::GetPosition(this: v16);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controlValues);
          v18 = v17[2].x;
          if ( v18 == 0.0 || (*(_BYTE *)(LODWORD(v18) + 16) & 0x1F) != 0xF )
          {
            m_pStorage = nullptr;
            controlValues.m_pAttribute = nullptr;
            controlValues.m_pStorage = nullptr;
            v20 = 0;
          }
          else
          {
            controlValues.m_pAttribute = (CDmAttribute *)LODWORD(v17[2].x);
            m_pStorage = *(DmElementArray_t **)(LODWORD(v18) + 4);
            controlValues.m_pStorage = m_pStorage;
            v20 = m_pStorage->m_Size;
          }
          if ( v20 > 0 )
          {
            while ( 1 )
            {
              v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: m_pStorage->m_Memory.m_pMemory[v2]);
              v22 = v21;
              if ( v21 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v21 + 16))(
                     a1: v21,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v22 = 0;
              }
              v23 = *(const char **)(v22 + 20);
              if ( v23 == (const char *)-1 )
                v23 = defaultValue;
              if ( _V_stricmp(s1: v23, s2: pControlName) == 0 )
                break;
              if ( ++v2 >= v20 )
                goto LABEL_39;
              m_pStorage = controlValues.m_pStorage;
            }
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::FastRemove(
              this: &controlValues,
              elem: v2);
          }
LABEL_39:
          v2 = 0;
          if ( ++j >= v30 )
            break;
          v13 = presetList.m_pStorage;
        }
        v7 = i;
      }
      i = ++v7;
      if ( v7 >= m_Size )
        break;
      m_pData = presetGroupList.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004558B0
// Name: private: void CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  const Vector *Position; // esi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  int v6; // edi
  int v7; // eax
  _DWORD *v8; // esi
  const char *v9; // esi
  int v10; // eax
  CDmeCombinationOperator *v11; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> controls; // [esp+14h] [ebp-Ch] BYREF
  CDmeAnimationSet *pAnimationSet; // [esp+1Ch] [ebp-4h]

  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  pAnimationSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  Position = CDmeTransform::GetPosition(this: (CDmeTransform *)pAnimationSet);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
  x = Position[2].x;
  if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    controls.m_pAttribute = nullptr;
    controls.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    controls.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
    m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
    controls.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v6 = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pStorage->m_Memory.m_pMemory[v6]);
      v8 = (_DWORD *)v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmElement::m_classType.u) != 0
        && (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v8 + 16))(
             a1: v8,
             a2: CDmeTransformControl::m_classType.u) == 0 )
      {
        v9 = (const char *)v8[5];
        if ( v9 == (const char *)-1 )
          v9 = defaultValue;
        v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_hCombinationOperator.m_handle);
        if ( v10 != 0 )
          v11 = (CDmeCombinationOperator *)(v10 - 4);
        else
          v11 = nullptr;
        if ( FindComboOpControlIndexForAnimSetControl(pComboOp: v11, pControlName: v9, pIsMulti: nullptr) < 0 )
        {
          CDmeCombinationOperatorPanel::RemoveAnimationControlFromPresets(this, pControlName: v9);
          CDmeAnimationSet::RemoveControlFromGroups(this: pAnimationSet, pchControlName: v9, bRemoveEmpty: false);
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::FastRemove(
            this: &controls,
            elem: v6);
        }
      }
      if ( --v6 < 0 )
        break;
      m_pStorage = controls.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004559E0
// Name: public: float const __near & CDmElement::GetValue<float>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CDmElement::GetValue<float>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<float> *)CDmAttribute::GetValue<float>(this: Attribute);
  else
    return &`CDmElement::GetValue<float>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00455AA0
// Name: struct SelectionInfo_t __near * FindSelectionInfoForControl<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
SelectionInfo_t *__cdecl FindSelectionInfoForControl<SelectionInfo_t>(
        CUtlVector<SelectionInfo_t *,CUtlMemory<SelectionInfo_t *,int> > *controlList,
        const CDmElement *pControl)
{
  int v3; // esi
  SelectionInfo_t *v4; // edi
  int nControls; // [esp+0h] [ebp-4h]

  if ( pControl == nullptr )
    return nullptr;
  v3 = 0;
  nControls = controlList->m_Size;
  if ( nControls <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = controlList->m_Memory.m_pMemory[v3];
    if ( (const CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                               a1: g_pDataModel.u,
                               a2: v4->m_hControl.m_handle) == pControl )
      break;
    if ( ++v3 >= nControls )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00455B00
// Name: protected: virtual struct SelectionInfo_t __near * CCombinationOperatorControl::FindSelectionInfoForControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
SelectionInfo_t *__thiscall CCombinationOperatorControl::FindSelectionInfoForControl(
        CCombinationOperatorControl *this,
        const CDmElement *pControl)
{
  return FindSelectionInfoForControl<SelectionInfo_t>(controlList: &this->m_FullControlList, pControl);
}

//------------------------------------------------------------------------------
// Address: 0x00455B20
// Name: void RemoveNullControls<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveNullControls<SelectionInfo_t>(
        CUtlVector<SelectionInfo_t *,CUtlMemory<SelectionInfo_t *,int> > *controlList)
{
  int i; // esi
  CDmeElementRefHelper *v2; // ebx

  for ( i = controlList->m_Size - 1; i >= 0; --i )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: controlList->m_Memory.m_pMemory[i]->m_hControl.m_handle) == 0 )
    {
      v2 = (CDmeElementRefHelper *)controlList->m_Memory.m_pMemory[i];
      if ( v2 != nullptr )
      {
        if ( g_pDataModel.u.m_Id != 0 )
        {
          CDmeElementRefHelper::Unref(this: v2 + 4, hElement: *(DmElementHandle_t *)&v2[4], handleType: HT_WEAK);
          if ( g_pDataModel.u.m_Id != 0 )
            CDmeElementRefHelper::Unref(this: v2, hElement: *(_DWORD *)v2, handleType: HT_WEAK);
        }
        CUtlMemoryPool::Free(this: &SelectionInfo_t::s_Allocator, memBlock: v2);
      }
      if ( controlList->m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &controlList->m_Memory.m_pMemory[i],
          src: &controlList->m_Memory.m_pMemory[i + 1],
          count: 4 * (controlList->m_Size - i - 1));
      --controlList->m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455BC0
// Name: public: CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetControl __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperatorPanel *__thiscall CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(
        CDmeCombinationOperatorPanel *this,
        vgui::Panel *parent,
        const char *panelName,
        CBaseAnimationSetControl *pAnimationSetController)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  CBaseAnimationSetEditor::CBaseAnimationSetEditor(this, parent, className: panelName, pAnimationSetController);
  this->__vftable = (CDmeCombinationOperatorPanel_vtbl *)&CDmeCombinationOperatorPanel::`vftable';
  if ( `CDmeCombinationOperatorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationOperatorPanel");
    v5->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
  }
  if ( `CDmeCombinationOperatorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmeCombinationOperatorPanel");
    v6->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
  }
  if ( `CDmeCombinationOperatorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationOperatorPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationOperatorPanel");
    v7->pfnClassName = CDmeCombinationOperatorPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
  }
  this->m_hCombinationOperator.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_operatorList.m_Memory.m_pMemory = nullptr;
  this->m_operatorList.m_Memory.m_nAllocationCount = 0;
  this->m_operatorList.m_Memory.m_nGrowSize = 0;
  this->m_operatorList.m_Size = 0;
  this->m_operatorList.m_pElements = nullptr;
  CDmeCombinationOperatorPanel::CreateFakeAnimationSet(this);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00455CD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeCombinationOperatorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeCombinationOperatorPanel::GetMessageMap(CDmeCombinationOperatorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeCombinationOperatorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationOperatorPanel");
  `CDmeCombinationOperatorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455D00
// Name: public: virtual struct PanelAnimationMap __near * CDmeCombinationOperatorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeCombinationOperatorPanel::GetAnimMap(CDmeCombinationOperatorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeCombinationOperatorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00455D10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeCombinationOperatorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeCombinationOperatorPanel::GetKBMap(CDmeCombinationOperatorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeCombinationOperatorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationOperatorPanel::GetKBMap'::`2'::s_pMap;
  `CDmeCombinationOperatorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationOperatorPanel");
  `CDmeCombinationOperatorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455D40
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(
        CDmeCombinationOperatorPanel *this,
        CDmElement *pControlElement)
{
  char *m_Id; // eax
  CDmeAnimationSet *v3; // eax
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // esi
  CDmAttribute *m_pAttribute; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // eax
  int m_Size; // ecx
  int v8; // eax
  CDmeTransformControl *v9; // esi
  CDmeTransformControl *v10; // ecx
  const Vector *Position; // esi
  float x; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *v13; // eax
  int v14; // ecx
  int v15; // eax
  CDmeTransform *v16; // esi
  const Vector *v17; // esi
  float v18; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pStorage; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  CDmElement *v23; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v26; // edi
  CDmaVar<float> *v27; // edi
  CDmAttribute *v28; // eax
  CDmAttribute *v29; // eax
  CDmAttribute *v30; // eax
  CDmAttribute *v31; // edi
  CDmaVar<float> *v32; // edi
  CDmAttribute *v33; // eax
  CDmAttribute *v34; // edi
  CDmaVar<float> *v35; // edi
  const float *p_flLeftValue; // edi
  CDmAttribute *v37; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-48h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v39; // [esp+14h] [ebp-40h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v40; // [esp+1Ch] [ebp-38h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v41; // [esp+24h] [ebp-30h] BYREF
  int v42; // [esp+2Ch] [ebp-28h]
  int v43; // [esp+30h] [ebp-24h]
  int v44; // [esp+34h] [ebp-20h]
  float flRightValue; // [esp+38h] [ebp-1Ch] BYREF
  float flLeftValue; // [esp+3Ch] [ebp-18h] BYREF
  float flValue; // [esp+40h] [ebp-14h] BYREF
  char *s2; // [esp+44h] [ebp-10h]
  int g; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int j; // [esp+50h] [ebp-4h]

  m_Id = (char *)pControlElement->m_Name.m_Storage.u.m_Id;
  s2 = (char *)defaultValue;
  if ( m_Id != (char *)-1 )
    s2 = m_Id;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  PresetGroups = CDmeAnimationSet::GetPresetGroups(this: v3);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v41);
  m_pAttribute = PresetGroups->m_pAttribute;
  if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    v41.m_pAttribute = PresetGroups->m_pAttribute;
    m_pData = (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)m_pAttribute->m_pData;
    v41.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    v41.m_pAttribute = nullptr;
    v41.m_pStorage = nullptr;
    m_Size = 0;
  }
  v42 = m_Size;
  g = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[g].m_tms);
      v9 = (CDmeTransformControl *)v8;
      if ( v8 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmePresetGroup::m_classType.u) != 0 )
      {
        v10 = v9;
      }
      else
      {
        v10 = nullptr;
      }
      Position = CDmeTransformControl::GetPosition(this: v10);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v40);
      x = Position[2].x;
      if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
      {
        v13 = nullptr;
        v40.m_pAttribute = nullptr;
        v40.m_pStorage = nullptr;
        v14 = 0;
      }
      else
      {
        v40.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
        v13 = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(x) + 4);
        v40.m_pStorage = v13;
        v14 = v13->m_Size;
      }
      v43 = v14;
      i = 0;
      if ( v14 > 0 )
      {
        while ( 1 )
        {
          v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: v13->m_Memory.m_pMemory[i].m_tms);
          v16 = (CDmeTransform *)v15;
          if ( v15 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
                 a1: v15,
                 a2: CDmePreset::m_classType.u) == 0 )
          {
            v16 = nullptr;
          }
          if ( !CDmePreset::IsAnimated(this: (CDmePreset *)v16) )
          {
            v17 = CDmeTransform::GetPosition(this: v16);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v39);
            v18 = v17[2].x;
            if ( v18 == 0.0 || (*(_BYTE *)(LODWORD(v18) + 16) & 0x1F) != 0xF )
            {
              m_pStorage = nullptr;
              v39.m_pAttribute = nullptr;
              v39.m_pStorage = nullptr;
              v20 = 0;
            }
            else
            {
              v39.m_pAttribute = (CDmAttribute *)LODWORD(v17[2].x);
              m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(v18) + 4);
              v39.m_pStorage = m_pStorage;
              v20 = m_pStorage->m_Size;
            }
            v44 = v20;
            j = 0;
            if ( v20 > 0 )
            {
              v21 = 0;
              while ( 1 )
              {
                v22 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                        a1: g_pDataModel.u,
                        a2: m_pStorage->m_Memory.m_pMemory[v21].m_tms);
                v23 = (CDmElement *)v22;
                if ( v22 == 0
                  || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
                       a1: v22,
                       a2: CDmElement::m_classType.u) == 0 )
                {
                  v23 = nullptr;
                }
                m_pAsString = v23->m_Name.m_Storage.u.m_pAsString;
                if ( m_pAsString == (const char *)-1 )
                  m_pAsString = defaultValue;
                if ( _V_stricmp(s1: m_pAsString, s2) == 0 )
                {
                  if ( CDmElement::HasAttribute(this: pControlElement, pAttributeName: "rightValue", type: AT_UNKNOWN) )
                  {
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    Attribute = CDmElement::FindAttribute(this: v23, pAttributeName: "value");
                    v26 = Attribute;
                    if ( Attribute != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (Attribute->m_nFlags & 0x1F) == 3 )
                      {
                        v27 = (CDmaVar<float> *)Attribute->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v26,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v27 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v27 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v27 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flValue = v27->m_Storage;
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "value");
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue") == nullptr )
                    {
                      v28 = CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue");
                      if ( v28 != nullptr
                        || (v28 = CDmElement::CreateAttribute(this: v23, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v28, value: &flValue);
                      }
                    }
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue") == nullptr )
                    {
                      v29 = CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue");
                      if ( v29 != nullptr
                        || (v29 = CDmElement::CreateAttribute(this: v23, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v29, value: &flValue);
                      }
                    }
                  }
                  else
                  {
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    v30 = CDmElement::FindAttribute(this: v23, pAttributeName: "leftValue");
                    v31 = v30;
                    if ( v30 != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (v30->m_nFlags & 0x1F) == 3 )
                      {
                        v32 = (CDmaVar<float> *)v30->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v30) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v31,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v32 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v32 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v32 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flLeftValue = v32->m_Storage;
                    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                    {
                      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                    }
                    v33 = CDmElement::FindAttribute(this: v23, pAttributeName: "rightValue");
                    v34 = v33;
                    if ( v33 != nullptr )
                    {
                      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
                      {
                        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
                      }
                      if ( (v33->m_nFlags & 0x1F) == 3 )
                      {
                        v35 = (CDmaVar<float> *)v33->m_pData;
                      }
                      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v33) )
                      {
                        CDmAttribute::CopyDataOut<float>(
                          this: v34,
                          value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                        v35 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
                      }
                      else
                      {
                        v35 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
                      }
                    }
                    else
                    {
                      v35 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
                    }
                    flRightValue = v35->m_Storage;
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "leftValue");
                    CDmElement::RemoveAttribute(this: v23, pAttributeName: "rightValue");
                    p_flLeftValue = &flLeftValue;
                    if ( flLeftValue <= flRightValue )
                      p_flLeftValue = &flRightValue;
                    if ( CDmElement::FindAttribute(this: v23, pAttributeName: "value") == nullptr )
                    {
                      v37 = CDmElement::FindAttribute(this: v23, pAttributeName: "value");
                      if ( v37 != nullptr
                        || (v37 = CDmElement::CreateAttribute(this: v23, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
                      {
                        CDmAttribute::SetValue<float>(this: v37, value: p_flLeftValue);
                      }
                    }
                  }
                }
                v21 = j + 1;
                j = v21;
                if ( v21 >= v44 )
                  break;
                m_pStorage = v39.m_pStorage;
              }
            }
          }
          if ( ++i >= v43 )
            break;
          v13 = v40.m_pStorage;
        }
      }
      if ( ++g >= v42 )
        break;
      m_pData = v41.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456250
// Name: private: void CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeTransform *v1; // eax
  const Vector *Position; // esi
  float x; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pStorage; // eax
  int m_Size; // ecx
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-14h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v10; // [esp+10h] [ebp-Ch] BYREF
  CDmeCombinationOperatorPanel *v11; // [esp+18h] [ebp-4h]

  v11 = this;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v1 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  Position = CDmeTransform::GetPosition(this: v1);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v10);
  x = Position[2].x;
  if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    v10.m_pAttribute = nullptr;
    v10.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    v10.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
    m_pStorage = *(CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > **)(LODWORD(x) + 4);
    v10.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v6 = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: m_pStorage->m_Memory.m_pMemory[v6].m_tms);
      v8 = (CDmElement *)v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmElement::m_classType.u) != 0
        && !v8->IsA(this: v8, a2: CDmeTransformControl::m_classType) )
      {
        CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControl(this: v11, pControlElement: v8);
        CDmeCombinationOperatorPanel::ModifyExistingAnimationSetPresets(this: v11, pControlElement: v8);
      }
      if ( --v6 < 0 )
        break;
      m_pStorage = v10.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456330
// Name: private: void CDmeCombinationOperatorPanel::AddNewAnimationSetControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::AddNewAnimationSetControls(CDmeCombinationOperatorPanel *this)
{
  CDmeCombinationOperatorPanel *v1; // ebx
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  int v3; // eax
  int v4; // edi
  CDmeAnimationSet *v5; // esi
  CDmaElementArray<CDmElement> *Position; // eax
  int (__thiscall *v7)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  int v10; // eax
  CDmeCombinationOperator *v11; // ecx
  int v12; // eax
  CDmeCombinationOperator *v13; // ecx
  bool IsStereoControl; // bl
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  int v17; // eax
  int v18; // eax
  CExpressionCalculator *v19; // esi
  int v20; // eax
  CDmeCombinationOperator *v21; // ecx
  const Vector2D *StereoControlValue; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  int v26; // eax
  CDmeCombinationOperator *v27; // ecx
  int v28; // eax
  CDmeCombinationOperator *v29; // ecx
  CDmAttribute *v30; // eax
  int v31; // eax
  int v32; // eax
  CExpressionCalculator *v33; // esi
  int v34; // eax
  CDmeCombinationOperator *v35; // ecx
  CDmAttribute *v36; // eax
  CDmAttribute *v37; // eax
  int m_Size; // ebx
  CDmeControlGroup *v39; // esi
  CDmAttribute *v40; // eax
  int j; // edi
  int v42; // eax
  CExpressionCalculator *v43; // esi
  DmElementHandle_t m_handle; // [esp-4h] [ebp-158h]
  char pMultiControlName[256]; // [esp+Ch] [ebp-148h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+10Ch] [ebp-48h] BYREF
  float MultiControlLevel; // [esp+114h] [ebp-40h] BYREF
  float v48; // [esp+118h] [ebp-3Ch] BYREF
  float flDefaultValue; // [esp+11Ch] [ebp-38h] BYREF
  int nCombinationControlCount; // [esp+120h] [ebp-34h]
  float value; // [esp+124h] [ebp-30h] BYREF
  const char *pControlName; // [esp+128h] [ebp-2Ch]
  CDmrElementArray<CDmElement> groups; // [esp+12Ch] [ebp-28h] BYREF
  DmElementHandle_t src; // [esp+134h] [ebp-20h] BYREF
  int nFirstControl; // [esp+138h] [ebp-1Ch]
  int i; // [esp+13Ch] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+140h] [ebp-14h]
  CDmeAnimationSet *pAnimationSet; // [esp+144h] [ebp-10h]
  DmElementHandle_t BufferType; // [esp+148h] [ebp-Ch] BYREF
  int iCurrentAnimSetControl; // [esp+14Ch] [ebp-8h]
  CDmeCombinationOperatorPanel *v61; // [esp+150h] [ebp-4h]

  v1 = this;
  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_handle = this->m_hCombinationOperator.m_handle;
  v61 = this;
  v3 = ((int (__thiscall *)(_DWORD, _DWORD))v2)(
         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
         a2: m_handle);
  v4 = 0;
  if ( v3 != 0 && v3 != 4 )
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: v1->m_pController);
    traversal.m_nIndex = 0;
    v5 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    pAnimationSet = v5;
    Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: (CDmeTransform *)v5);
    nFirstControl = Position->m_Storage.m_Size;
    v7 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    controls = Position;
    v8 = ((int (__thiscall *)(_DWORD, _DWORD))v7)(
           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
           a2: v1->m_hCombinationOperator.m_handle);
    if ( v8 != 0 )
      v9 = (CDmeCombinationOperator *)(v8 - 4);
    else
      v9 = nullptr;
    nCombinationControlCount = CDmeMaterialGroup::GetListAttr(this: v9);
    iCurrentAnimSetControl = 0;
    i = 0;
    if ( nCombinationControlCount > 0 )
    {
      do
      {
        v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v1->m_hCombinationOperator.m_handle);
        if ( v10 != 0 )
          v11 = (CDmeCombinationOperator *)(v10 - 4);
        else
          v11 = nullptr;
        pControlName = CDmeCombinationOperator::GetControlName(this: v11, i: v4);
        if ( CDmeAnimationSet::FindControl(this: v5, pControlName) == nullptr )
        {
          v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: v1->m_hCombinationOperator.m_handle);
          if ( v12 != 0 )
            v13 = (CDmeCombinationOperator *)(v12 - 4);
          else
            v13 = nullptr;
          IsStereoControl = CDmeCombinationOperator::IsStereoControl(this: v13, nControlIndex: v4);
          v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: v61->m_hCombinationOperator.m_handle);
          if ( v15 != 0 )
            v16 = (CDmeCombinationOperator *)(v15 - 4);
          else
            v16 = nullptr;
          flDefaultValue = CDmeCombinationOperator::GetControlDefaultValue(this: v16, nControl: v4);
          v17 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                  a1: g_pDataModel.u,
                  a2: CDmElement::m_classType.u,
                  a3: pControlName,
                  a4: v5->m_fileId,
                  a5: 0);
          v18 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: v17);
          v19 = (CExpressionCalculator *)v18;
          if ( v18 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v18 + 16))(
                 a1: v18,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            src = CCodecBuffer_Block::GetBufferType(this: v19);
          }
          else
          {
            v19 = nullptr;
            src = DMELEMENT_HANDLE_INVALID;
          }
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
            this: controls,
            elem: iCurrentAnimSetControl,
            &src);
          if ( IsStereoControl )
          {
            v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: v61->m_hCombinationOperator.m_handle);
            if ( v20 != 0 )
              v21 = (CDmeCombinationOperator *)(v20 - 4);
            else
              v21 = nullptr;
            StereoControlValue = CDmeCombinationOperator::GetStereoControlValue(
                                   this: v21,
                                   nControlIndex: v4,
                                   type: COMBO_CONTROL_FIRST);
            Attribute = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "leftValue");
            if ( Attribute != nullptr
              || (Attribute = CDmElement::CreateAttribute(
                                this: (CDmElement *)v19,
                                pAttributeName: "leftValue",
                                type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: Attribute, value: &StereoControlValue->x);
            }
            v24 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "rightValue");
            if ( v24 != nullptr
              || (v24 = CDmElement::CreateAttribute(
                          this: (CDmElement *)v19,
                          pAttributeName: "rightValue",
                          type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v24, value: &StereoControlValue->y);
            }
            v4 = i;
          }
          else
          {
            v28 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: v61->m_hCombinationOperator.m_handle);
            if ( v28 != 0 )
              v29 = (CDmeCombinationOperator *)(v28 - 4);
            else
              v29 = nullptr;
            value = CDmeCombinationOperator::GetControlValue(this: v29, nControlIndex: v4, type: COMBO_CONTROL_FIRST);
            v30 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "value");
            if ( v30 != nullptr
              || (v30 = CDmElement::CreateAttribute(this: (CDmElement *)v19, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v30, &value);
            }
          }
          v25 = CDmElement::FindAttribute(this: (CDmElement *)v19, pAttributeName: "defaultValue");
          if ( v25 != nullptr
            || (v25 = CDmElement::CreateAttribute(
                        this: (CDmElement *)v19,
                        pAttributeName: "defaultValue",
                        type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v25, value: &flDefaultValue);
          }
          v1 = v61;
          v5 = pAnimationSet;
        }
        v26 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v1->m_hCombinationOperator.m_handle);
        if ( v26 != 0 )
          v27 = (CDmeCombinationOperator *)(v26 - 4);
        else
          v27 = nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v27, nControlIndex: v4) )
        {
          ++iCurrentAnimSetControl;
          V_snprintf(pDest: pMultiControlName, maxLen: 256, pFormat: "multi_%s", pControlName);
          if ( CDmeAnimationSet::FindControl(this: v5, pControlName: pMultiControlName) == nullptr )
          {
            v31 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                    a1: g_pDataModel.u,
                    a2: CDmElement::m_classType.u,
                    a3: pMultiControlName,
                    a4: v5->m_fileId,
                    a5: 0);
            v32 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: v31);
            v33 = (CExpressionCalculator *)v32;
            if ( v32 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v32 + 16))(
                   a1: v32,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              BufferType = CCodecBuffer_Block::GetBufferType(this: v33);
            }
            else
            {
              v33 = nullptr;
              BufferType = DMELEMENT_HANDLE_INVALID;
            }
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
              this: controls,
              elem: iCurrentAnimSetControl,
              src: &BufferType);
            v34 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: v61->m_hCombinationOperator.m_handle);
            if ( v34 != 0 )
              v35 = (CDmeCombinationOperator *)(v34 - 4);
            else
              v35 = nullptr;
            MultiControlLevel = CDmeCombinationOperator::GetMultiControlLevel(
                                  this: v35,
                                  nControlIndex: v4,
                                  type: COMBO_CONTROL_FIRST);
            v36 = CDmElement::FindAttribute(this: (CDmElement *)v33, pAttributeName: "value");
            if ( v36 != nullptr
              || (v36 = CDmElement::CreateAttribute(this: (CDmElement *)v33, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v36, value: &MultiControlLevel);
            }
            v48 = 0.5;
            v37 = CDmElement::FindAttribute(this: (CDmElement *)v33, pAttributeName: "defaultValue");
            if ( v37 != nullptr
              || (v37 = CDmElement::CreateAttribute(
                          this: (CDmElement *)v33,
                          pAttributeName: "defaultValue",
                          type: AT_FLOAT)) != nullptr )
            {
              CDmAttribute::SetValue<float>(this: v37, value: &v48);
            }
            v1 = v61;
            v5 = pAnimationSet;
          }
        }
        ++iCurrentAnimSetControl;
        i = ++v4;
      }
      while ( v4 < nCombinationControlCount );
    }
    m_Size = controls->m_Storage.m_Size;
    if ( m_Size != nFirstControl )
    {
      v39 = CDmeAnimationSet::FindOrAddControlGroup(this: v5, pParentGroup: nullptr, pControlGroupName: "Root");
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&groups);
      if ( v39 != nullptr
        && (v40 = CDmElement::FindAttribute(this: v39, pAttributeName: "controls")) != nullptr
        && (v40->m_nFlags & 0x1F) == 0xF )
      {
        groups.m_pAttribute = v40;
        groups.m_pStorage = (DmElementArray_t *)v40->m_pData;
      }
      else
      {
        groups.m_pAttribute = nullptr;
        groups.m_pStorage = nullptr;
      }
      for ( j = nFirstControl; j < m_Size; ++j )
      {
        v42 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: controls->m_Storage.m_Memory.m_pMemory[j]);
        v43 = (CExpressionCalculator *)v42;
        if ( v42 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v42 + 16))(
               a1: v42,
               a2: CDmElement::m_classType.u) != 0 )
        {
          BufferType = CCodecBuffer_Block::GetBufferType(this: v43);
        }
        else
        {
          BufferType = DMELEMENT_HANDLE_INVALID;
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &groups,
          src: &BufferType);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456830
// Name: private: void CDmeCombinationOperatorPanel::RefreshAnimationSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::RefreshAnimationSet(CDmeCombinationOperatorPanel *this)
{
  unsigned __int8 (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  CDisableUndoScopeGuard sg; // [esp+4h] [ebp-8h] BYREF

  if ( CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController) != nullptr )
  {
    v2 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    sg.m_bNotify = false;
    sg.m_pNotify = nullptr;
    *(_WORD *)&sg.m_bOldValue = ((int (__thiscall *)(_DWORD))v2)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(this);
    CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(this);
    CDmeCombinationOperatorPanel::AddNewAnimationSetControls(this);
    CDmeCombinationOperatorPanel::SortAnimationSetControls(this);
    CChangeUndoScopeGuard::Release(this: &sg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004568B0
// Name: public: void CDmeDagEditPanel::SetAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetAnimationList(CDmeDagEditPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeAnimationListPanel *m_pAnimationListPanel; // esi
  DmElementHandle_t BufferType; // eax

  CDmeDagRenderPanel::SetAnimationList(this: this->m_pDagRenderPanel, pAnimationList);
  CDmeDagRenderPanel::SelectAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  m_pAnimationListPanel = this->m_pAnimationListPanel;
  if ( pAnimationList != (CDmeAnimationList *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                                a1: g_pDataModel.u,
                                                a2: m_pAnimationListPanel->m_hAnimationList.m_handle) )
  {
    if ( pAnimationList != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeAnimationList,0>::Set(this: &m_pAnimationListPanel->m_hAnimationList, h: BufferType);
    CDmeAnimationListPanel::RefreshAnimationList(this: m_pAnimationListPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456920
// Name: public: void CDmeDagEditPanel::SetVertexAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetVertexAnimationList(CDmeDagEditPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeAnimationListPanel *m_pVertexAnimationListPanel; // esi
  DmElementHandle_t BufferType; // eax

  CDmeDagRenderPanel::SetVertexAnimationList(this: this->m_pDagRenderPanel, pAnimationList);
  CDmeDagRenderPanel::SelectVertexAnimation(this: this->m_pDagRenderPanel, pAnimName: defaultValue);
  m_pVertexAnimationListPanel = this->m_pVertexAnimationListPanel;
  if ( pAnimationList != (CDmeAnimationList *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                                a1: g_pDataModel.u,
                                                a2: m_pVertexAnimationListPanel->m_hAnimationList.m_handle) )
  {
    if ( pAnimationList != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeAnimationList,0>::Set(this: &m_pVertexAnimationListPanel->m_hAnimationList, h: BufferType);
    CDmeAnimationListPanel::RefreshAnimationList(this: m_pVertexAnimationListPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456990
// Name: public: void CDmeDagEditPanel::RefreshCombinationOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::RefreshCombinationOperator(CDmeDagEditPanel *this)
{
  CDmeCombinationOperatorPanel *m_pCombinationPanel; // esi
  CDmeFilmClip *AnimationSetClip; // eax

  m_pCombinationPanel = this->m_pCombinationPanel;
  CDmeCombinationOperatorPanel::RefreshAnimationSet(this: m_pCombinationPanel);
  AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pCombinationPanel->m_pController);
  CBaseAnimationSetEditor::ChangeAnimationSetClip(this: m_pCombinationPanel, pFilmClip: AnimationSetClip);
}

//------------------------------------------------------------------------------
// Address: 0x004569C0
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456A50
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AnimationSelected";
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
// Address: 0x00456AE0
// Name: public: static void CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AnimationDeselected";
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
// Address: 0x00456B70
// Name: public: static void CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456C00
// Name: public: static void CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemDeselected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456C90
// Name: public: CDmeAnimationListPanel::CDmeAnimationListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationListPanel *__thiscall CDmeAnimationListPanel::CDmeAnimationListPanel(
        CDmeAnimationListPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeAnimationListPanel_vtbl *)&CDmeAnimationListPanel::`vftable';
  if ( `CDmeAnimationListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeAnimationListPanel");
    v4->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeAnimationListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeAnimationListPanel");
    v5->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeAnimationListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeAnimationListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeAnimationListPanel");
    v6->pfnClassName = CDmeAnimationListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeAnimationListPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmeAnimationListPanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  this->m_hAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "AnimationList");
  else
    v8 = nullptr;
  this->m_pAnimationList = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "name", a4: "name", a5: 100, a6: 0);
  this->m_pAnimationList->AddActionSignalTarget_2(this: this->m_pAnimationList, a2: this);
  this->m_pAnimationList->SetSortFunc(this: this->m_pAnimationList, a2: 0, a3: PresetNameSortFunc);
  this->m_pAnimationList->SetSortColumn(this: this->m_pAnimationList, a2: 0);
  this->m_pAnimationList->SetEmptyListText_2(this: this->m_pAnimationList, a2: "No animations");
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pAnimationList, bState: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmeanimationlistpanel.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00456E80
// Name: public: void CDmeCombinationOperatorPanel::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationOperatorPanel::SetCombinationOperator(
        CDmeCombinationOperatorPanel *this,
        CDmeCombinationOperator *pOp)
{
  CDmeCombinationOperatorPanel *v2; // ebx
  CDmAttribute *AnimationSetClip; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_operatorList; // esi
  int v5; // eax
  CDmeCombinationOperator *v6; // eax
  CDmElement *v7; // ecx
  DmElementHandle_t BufferType; // eax
  int v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  int *v14; // edi
  CDmElement *OperationTarget; // eax
  CDmElement *v16; // edi
  vgui::TreeNode **v17; // edi
  int v18; // eax
  vgui::TreeNode **v19; // ecx
  int v20; // eax
  CDmeFlexRules **v21; // eax
  CDmeFlexRules *v22; // ecx
  int v23; // eax
  int j; // ebx
  int v25; // eax
  int v26; // edi
  vgui::TreeNode **v27; // edi
  int v28; // eax
  vgui::TreeNode **v29; // ecx
  int v30; // eax
  vgui::TreeNode **v31; // eax
  CDmeFilmClip *v32; // eax
  vgui::TreeNode *v33; // [esp+10h] [ebp-10h]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  CDmeFlexRules *pDmeFlexRules; // [esp+1Ch] [ebp-4h]

  v2 = this;
  AnimationSetClip = (CDmAttribute *)CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  DestroyElement(pElement: AnimationSetClip, depth: TD_DEEP);
  CDmeCombinationOperatorPanel::CreateFakeAnimationSet(this: v2);
  v2->m_operatorList.m_Size = 0;
  p_m_operatorList = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_operatorList;
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2->m_hCombinationOperator.m_handle);
  if ( v5 != 0 )
    v6 = (CDmeCombinationOperator *)(v5 - 4);
  else
    v6 = nullptr;
  if ( pOp != v6 )
  {
    if ( pOp != nullptr )
      v7 = &pOp->CDmElement;
    else
      v7 = nullptr;
    if ( v7 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeCombinationOperator,0>::Set(this: &v2->m_hCombinationOperator, h: BufferType);
    v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v2->m_hCombinationOperator.m_handle);
    if ( v9 != 0 )
      i = v9 - 4;
    else
      i = 0;
    m_Size = v2->m_operatorList.m_Size;
    m_nAllocationCount = v2->m_operatorList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_operatorList,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_operatorList.m_Size;
    m_pMemory = p_m_operatorList->m_pMemory;
    v13 = v2->m_operatorList.m_Size - m_Size - 1;
    v2->m_operatorList.m_pElements = v2->m_operatorList.m_Memory.m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
    v14 = (int *)&p_m_operatorList->m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = i;
    for ( ia = 0; ia < CDmeCombinationOperator::GetOperationTargetCount(this: pOp); ++ia )
    {
      OperationTarget = CDmeCombinationOperator::GetOperationTarget(this: pOp, nTargetIndex: ia);
      v16 = OperationTarget;
      if ( OperationTarget != nullptr && OperationTarget->IsA(this: OperationTarget, a2: CDmeFlexRules::m_classType) )
      {
        pDmeFlexRules = (CDmeFlexRules *)((char *)&v16[-1] + 64);
        if ( v16 != (CDmElement *)4 )
        {
          v17 = p_m_operatorList[1].m_pMemory;
          v18 = p_m_operatorList->m_nAllocationCount;
          if ( (int)v17 + 1 > v18 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_operatorList, num: (int)v17 - v18 + 1);
          ++p_m_operatorList[1].m_pMemory;
          v19 = p_m_operatorList->m_pMemory;
          v20 = (char *)p_m_operatorList[1].m_pMemory - (char *)v17 - 1;
          p_m_operatorList[1].m_nAllocationCount = (int)p_m_operatorList->m_pMemory;
          if ( v20 > 0 )
            _V_memmove(dest: &v19[(_DWORD)v17 + 1], src: &v19[(_DWORD)v17], count: 4 * v20);
          v21 = (CDmeFlexRules **)&p_m_operatorList->m_pMemory[(_DWORD)v17];
          if ( v21 != nullptr )
            *v21 = pDmeFlexRules;
          v22 = pDmeFlexRules;
          v23 = pDmeFlexRules->m_eDeltaStates.m_Storage.m_Size;
          for ( j = 0; j < v23; ++j )
          {
            if ( j >= 0 && j < v23 )
            {
              v25 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: v22->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[j]);
              v26 = v25;
              if ( v25 != 0
                && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v25 + 16))(
                     a1: v25,
                     a2: CDmeFlexRuleBase::m_classType.u) != 0 )
              {
                v33 = (vgui::TreeNode *)(v26 - 4);
                if ( v26 != 4 )
                {
                  v27 = p_m_operatorList[1].m_pMemory;
                  v28 = p_m_operatorList->m_nAllocationCount;
                  if ( (int)v27 + 1 > v28 )
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_operatorList, num: (int)v27 - v28 + 1);
                  ++p_m_operatorList[1].m_pMemory;
                  v29 = p_m_operatorList->m_pMemory;
                  v30 = (char *)p_m_operatorList[1].m_pMemory - (char *)v27 - 1;
                  p_m_operatorList[1].m_nAllocationCount = (int)p_m_operatorList->m_pMemory;
                  if ( v30 > 0 )
                    _V_memmove(dest: &v29[(_DWORD)v27 + 1], src: &v29[(_DWORD)v27], count: 4 * v30);
                  v31 = &p_m_operatorList->m_pMemory[(_DWORD)v27];
                  if ( v31 != nullptr )
                    *v31 = v33;
                }
              }
            }
            v22 = pDmeFlexRules;
            v23 = pDmeFlexRules->m_eDeltaStates.m_Storage.m_Size;
          }
          v2 = this;
        }
      }
    }
    if ( CBaseAnimationSetControl::GetAnimationSetClip(this: v2->m_pController) != nullptr )
    {
      LOBYTE(v33) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
        a1: g_pDataModel.u,
        a2: 0);
      CDmeCombinationOperatorPanel::RemoveUnusedAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::ModifyExistingAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::AddNewAnimationSetControls(this: v2);
      CDmeCombinationOperatorPanel::SortAnimationSetControls(this: v2);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, vgui::TreeNode *))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
        a1: g_pDataModel.u,
        a2: v33);
    }
    v32 = CBaseAnimationSetControl::GetAnimationSetClip(this: v2->m_pController);
    CBaseAnimationSetEditor::ChangeAnimationSetClip(this: v2, pFilmClip: v32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457180
// Name: public: virtual void CDmeCombinationOperatorPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationOperatorPanel::OnTick(
        CDmeCombinationOperatorPanel *this@<ecx>,
        DmElementHandle_t m_handle@<edi>)
{
  int v3; // eax
  char v4; // al
  int v5; // edx
  int v6; // eax
  CDmeCombinationOperator *v7; // ecx
  int v8; // edi
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  bool SliderValues; // al
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  int v13; // eax
  CDmeCombinationOperator *v14; // ecx
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  int v17; // eax
  CDmeCombinationOperator *v18; // ecx
  CBaseAnimSetAttributeSliderPanel *v19; // eax
  bool v20; // al
  int v21; // eax
  CDmeCombinationOperator *v22; // ecx
  DmElementHandle_t v23; // eax
  int v24; // eax
  int v25; // edi
  int m_Size; // eax
  int v27; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v29; // eax
  vgui::TreeNode **v30; // eax
  char v31; // al
  int v32; // edx
  int v33; // [esp+20h] [ebp-70h]
  int v34; // [esp+20h] [ebp-70h]
  AttributeValue_t multiValue; // [esp+30h] [ebp-60h] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > operators; // [esp+58h] [ebp-38h] BYREF
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > v38; // [esp+6Ch] [ebp-24h] BYREF
  CDisableUndoScopeGuard guard; // [esp+80h] [ebp-10h]
  int nCombinationControlCount; // [esp+88h] [ebp-8h]
  int iCurrentControlIndex; // [esp+8Ch] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v3 != 0 && v3 != 4 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    guard.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v6 != 0 )
      v7 = (CDmeCombinationOperator *)(v6 - 4);
    else
      v7 = nullptr;
    v8 = 0;
    nCombinationControlCount = CDmeMaterialGroup::GetListAttr(this: v7);
    iCurrentControlIndex = 0;
    if ( nCombinationControlCount > 0 )
    {
      do
      {
        memset(&operators, 0, sizeof(operators));
        v38.m_Memory.m_pMemory = nullptr;
        v33 = iCurrentControlIndex;
        *(Quaternion *)&v38.m_Memory.m_nAllocationCount = quat_identity;
        AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this);
        SliderValues = CBaseAnimSetAttributeSliderPanel::GetSliderValues(
                         this: AttributeSlider,
                         pValue: (AttributeValue_t *)&operators,
                         nIndex: v33);
        ++iCurrentControlIndex;
        if ( SliderValues )
        {
          v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: this->m_hCombinationOperator.m_handle,
                  a3: m_handle);
          if ( v11 != 0 )
            v12 = (CDmeCombinationOperator *)(v11 - 4);
          else
            v12 = nullptr;
          if ( CDmeCombinationOperator::IsStereoControl(this: v12, nControlIndex: v8) )
          {
            m_handle = this->m_hCombinationOperator.m_handle;
            v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
            if ( v13 != 0 )
              v14 = (CDmeCombinationOperator *)(v13 - 4);
            else
              v14 = nullptr;
            CDmeCombinationOperator::SetControlValue(
              this: v14,
              nControlIndex: v8,
              flLeftValue: *(float *)&operators.m_Memory.m_nGrowSize,
              flRightValue: *(float *)&operators.m_Memory.m_nAllocationCount,
              type: COMBO_CONTROL_FIRST);
          }
          else
          {
            m_handle = this->m_hCombinationOperator.m_handle;
            v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
            if ( v15 != 0 )
              v16 = (CDmeCombinationOperator *)(v15 - 4);
            else
              v16 = nullptr;
            CDmeCombinationOperator::SetControlValue(
              this: v16,
              nControlIndex: v8,
              flValue: *(float *)&operators.m_Memory.m_pMemory,
              type: COMBO_CONTROL_FIRST);
          }
        }
        v17 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_hCombinationOperator.m_handle);
        if ( v17 != 0 )
          v18 = (CDmeCombinationOperator *)(v17 - 4);
        else
          v18 = nullptr;
        if ( CDmeCombinationOperator::IsMultiControl(this: v18, nControlIndex: v8) )
        {
          memset(&multiValue, 0, 24);
          v34 = iCurrentControlIndex;
          multiValue.m_Quaternion = quat_identity;
          v19 = CBaseAnimationSetEditor::GetAttributeSlider(this);
          v20 = CBaseAnimSetAttributeSliderPanel::GetSliderValues(this: v19, pValue: &multiValue, nIndex: v34);
          ++iCurrentControlIndex;
          if ( v20 )
          {
            v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hCombinationOperator.m_handle);
            if ( v21 != 0 )
              v22 = (CDmeCombinationOperator *)(v21 - 4);
            else
              v22 = nullptr;
            CDmeCombinationOperator::SetMultiControlLevel(
              this: v22,
              nControlIndex: v8,
              flMultiLevel: multiValue.m_pValue[0],
              type: COMBO_CONTROL_FIRST);
          }
        }
        ++v8;
      }
      while ( v8 < nCombinationControlCount );
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&guard.m_bOldValue,
      a3: m_handle);
    if ( this->m_operatorList.m_Size != 0 )
    {
      guard.m_bOldValue = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
        a1: g_pDataModel.u,
        a2: 0);
      g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: &this->m_operatorList);
      g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
        a1: g_pDataModel.u,
        a2: *(_DWORD *)&guard.m_bOldValue);
      g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
      return;
    }
    v23 = this->m_hCombinationOperator.m_handle;
    memset(&v38, 0, sizeof(v38));
    v24 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: v23);
    if ( v24 != 0 )
      v25 = v24 - 4;
    else
      v25 = 0;
    m_Size = v38.m_Size;
    v27 = v38.m_Size;
    if ( v38.m_Size + 1 > v38.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: &v38.m_Memory,
        num: v38.m_Size - v38.m_Memory.m_nAllocationCount + 1);
      m_Size = v38.m_Size;
    }
    m_pMemory = v38.m_Memory.m_pMemory;
    v38.m_Size = m_Size + 1;
    v29 = m_Size - v27;
    v38.m_pElements = v38.m_Memory.m_pMemory;
    if ( v29 > 0 )
    {
      _V_memmove(dest: &v38.m_Memory.m_pMemory[v27 + 1], src: &v38.m_Memory.m_pMemory[v27], count: 4 * v29);
      m_pMemory = v38.m_Memory.m_pMemory;
    }
    v30 = &m_pMemory[v27];
    if ( v30 != nullptr )
      *v30 = (vgui::TreeNode *)v25;
    v31 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    v32 = *(_DWORD *)g_pDataModel.u.m_Id;
    guard.m_bOldValue = v31;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v32 + 232))(a1: g_pDataModel.u, a2: 0);
    g_pDmElementFramework->SetOperators(
      this: g_pDmElementFramework,
      a2: (const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)&v38);
    g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&guard.m_bOldValue);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: &v38);
  }
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
}

//------------------------------------------------------------------------------
// Address: 0x00457540
// Name: public: CDmeDagEditPanel::CDmeDagEditPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagEditPanel *__thiscall CDmeDagEditPanel::CDmeDagEditPanel(
        CDmeDagEditPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v10; // edi
  CDmeDagRenderPanel *v11; // eax
  CDmeDagRenderPanel *v12; // eax
  vgui::PropertySheet *v13; // eax
  vgui::PropertySheet *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  vgui::PropertyPage *v17; // eax
  vgui::PropertyPage *v18; // eax
  vgui::PropertyPage *v19; // eax
  vgui::PropertyPage *v20; // eax
  CBaseAnimationSetControl *v21; // eax
  CBaseAnimationSetControl *v22; // edi
  CDmeCombinationOperatorPanel *v23; // eax
  CDmeCombinationOperatorPanel *v24; // eax
  CDmeAnimationListPanel *v25; // eax
  CDmeAnimationListPanel *v26; // eax
  CDmeAnimationListPanel *v27; // eax
  CDmeAnimationListPanel *v28; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeDagEditPanel_vtbl *)&CDmeDagEditPanel::`vftable';
  if ( `CDmeDagEditPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
    v4->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeDagEditPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeDagEditPanel");
    v5->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeDagEditPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagEditPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagEditPanel");
    v6->pfnClassName = CDmeDagEditPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeDagEditPanel::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CDmeDagEditPanel::PanelMessageFunc_OnAnimationSelected::InitVar(a1: (int)&savedregs);
  CDmeDagEditPanel::PanelMessageFunc_OnAnimationDeselected::InitVar(a1: (int)&savedregs);
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PropertiesSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPropertiesSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pPropertiesSplitter, index: 1);
  v11 = (CDmeDagRenderPanel *)MemAlloc_Alloc(nSize: 0x524u);
  if ( v11 != nullptr )
    v12 = CDmeDagRenderPanel::CDmeDagRenderPanel(this: v11, pParent: v10, pName: "DagRenderPanel");
  else
    v12 = nullptr;
  this->m_pDagRenderPanel = v12;
  v13 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v13 != nullptr )
    v14 = vgui::PropertySheet::PropertySheet(this: v13, parent: Child, panelName: "EditorSheet", draggableTabs: false);
  else
    v14 = nullptr;
  this->m_pEditorSheet = v14;
  v14->AddActionSignalTarget_2(this: v14, a2: this);
  v15 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v15 != nullptr )
    v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pEditorSheet, panelName: "AnimationPage");
  else
    v16 = nullptr;
  this->m_pAnimationPage = v16;
  v17 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v17 != nullptr )
    v18 = vgui::PropertyPage::PropertyPage(this: v17, parent: this->m_pEditorSheet, panelName: "AnimationSetEditor");
  else
    v18 = nullptr;
  this->m_pCombinationPage = v18;
  v19 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v19 != nullptr )
    v20 = vgui::PropertyPage::PropertyPage(this: v19, parent: this->m_pEditorSheet, panelName: "VertexAnimationPage");
  else
    v20 = nullptr;
  this->m_pVertexAnimationPage = v20;
  v21 = (CBaseAnimationSetControl *)MemAlloc_Alloc(nSize: 0xB4u);
  v22 = v21;
  if ( v21 != nullptr )
  {
    CBaseAnimationSetControl::CBaseAnimationSetControl(this: v21);
    v22->__vftable = (CBaseAnimationSetControl_vtbl *)&CCombinationOperatorControl::`vftable';
    v22[1].__vftable = nullptr;
    v22[1].m_hFilmClip.m_handle = 0;
    v22[1].m_pEditor = nullptr;
    v22[1].m_SelectionHistory.m_Memory.m_pMemory = nullptr;
    v22[1].m_SelectionHistory.m_Memory.m_nAllocationCount = 0;
  }
  else
  {
    v22 = nullptr;
  }
  v23 = (CDmeCombinationOperatorPanel *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v23 != nullptr )
    v24 = CDmeCombinationOperatorPanel::CDmeCombinationOperatorPanel(
            this: v23,
            parent: this->m_pCombinationPage,
            panelName: "AnimationSetEditorPanel",
            pAnimationSetController: v22);
  else
    v24 = nullptr;
  this->m_pCombinationPanel = v24;
  v24->CreateToolsSubPanels(this: v24);
  v25 = (CDmeAnimationListPanel *)MemAlloc_Alloc(nSize: 0x18Cu);
  if ( v25 != nullptr )
    v26 = CDmeAnimationListPanel::CDmeAnimationListPanel(
            this: v25,
            pParent: this->m_pAnimationPage,
            pName: "AnimationListPanel");
  else
    v26 = nullptr;
  this->m_pAnimationListPanel = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  v27 = (CDmeAnimationListPanel *)MemAlloc_Alloc(nSize: 0x18Cu);
  if ( v27 != nullptr )
    v28 = CDmeAnimationListPanel::CDmeAnimationListPanel(
            this: v27,
            pParent: this->m_pVertexAnimationPage,
            pName: "VertexAnimationListPanel");
  else
    v28 = nullptr;
  this->m_pVertexAnimationListPanel = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  this->m_pCombinationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pCombinationPage,
    a2: "resource/dmedageditpanel_animationseteditorpage.res",
    a3: 0);
  this->m_pAnimationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pAnimationPage,
    a2: "resource/dmedageditpanel_animationpage.res",
    a3: 0);
  this->m_pVertexAnimationPage->LoadControlSettingsAndUserConfig(
    this: this->m_pVertexAnimationPage,
    a2: "resource/dmedageditpanel_vertexanimationpage.res",
    a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmedageditpanel.res",
    dialogID: 0);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pAnimationPage,
    a3: "Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pCombinationPage,
    a3: "Combination",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pVertexAnimationPage,
    a3: "Vertex Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->SetActivePage(this: this->m_pEditorSheet, a2: this->m_pCombinationPage);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00457900
// Name: public: void CDmeDagEditPanel::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetCombinationOperator(CDmeDagEditPanel *this, CDmeCombinationOperator *pComboOp)
{
  CDmeCombinationOperatorPanel::SetCombinationOperator(this: this->m_pCombinationPanel, pOp: pComboOp);
}

//------------------------------------------------------------------------------
// Address: 0x00457980
// Name: void RebuildControlList<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RebuildControlList<SelectionInfo_t>(
        CUtlMemory<vgui::TreeNode *,int> *controlList,
        CDmeFilmClip *pFilmClip)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // esi
  int m_pMemory; // eax
  int v4; // ebx
  CDmeElementRefHelper *v5; // edi
  CDmeTransform *v6; // eax
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v9; // ecx
  int v10; // eax
  CExpressionCalculator *v11; // ebx
  CDmeElementRefHelper *v12; // eax
  CDmeElementRefHelper *v13; // edi
  int BufferType; // esi
  int v15; // eax
  int v16; // ebx
  DmElementHandle_t v17; // eax
  int v18; // eax
  vgui::TreeNode *v19; // ebx
  vgui::TreeNode **v20; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v22; // ecx
  int v23; // eax
  vgui::TreeNode **v24; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  int v26; // [esp+14h] [ebp-Ch]
  CDmaElementArray<CDmElement> *controls; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  CDmeAnimationSet *pAnimSet; // [esp+2Ch] [ebp+Ch]

  v2 = controlList;
  m_pMemory = (int)controlList[1].m_pMemory;
  v4 = 0;
  for ( i = m_pMemory; v4 < m_pMemory; ++v4 )
  {
    v5 = (CDmeElementRefHelper *)controlList->m_pMemory[v4];
    if ( v5 != nullptr )
    {
      if ( g_pDataModel.u.m_Id != 0 )
      {
        CDmeElementRefHelper::Unref(this: v5 + 4, hElement: *(DmElementHandle_t *)&v5[4], handleType: HT_WEAK);
        if ( g_pDataModel.u.m_Id != 0 )
          CDmeElementRefHelper::Unref(this: v5, hElement: *(_DWORD *)v5, handleType: HT_WEAK);
      }
      CUtlMemoryPool::Free(this: &SelectionInfo_t::s_Allocator, memBlock: v5);
      m_pMemory = i;
    }
  }
  traversal.m_pFilmClip = pFilmClip;
  controlList[1].m_pMemory = nullptr;
  traversal.m_nIndex = 0;
  v6 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pAnimSet = (CDmeAnimationSet *)v6;
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v6);
      m_Size = Position->m_Storage.m_Size;
      v9 = 0;
      controls = Position;
      v26 = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: Position->m_Storage.m_Memory.m_pMemory[v9]);
          v11 = (CExpressionCalculator *)v10;
          if ( v10 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            v12 = (CDmeElementRefHelper *)CUtlMemoryPool::Alloc(this: &SelectionInfo_t::s_Allocator, amount: 0xCu);
            v13 = v12;
            if ( v12 != nullptr )
            {
              *(_DWORD *)v12 = -1;
              if ( pAnimSet != nullptr )
                BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
              else
                BufferType = -1;
              if ( BufferType != *(_DWORD *)v13 )
              {
                CDmeElementRefHelper::Unref(this: v13, hElement: *(_DWORD *)v13, handleType: HT_WEAK);
                *(_DWORD *)v13 = BufferType;
                if ( BufferType != -1 )
                {
                  v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
                          a1: g_pDataModel.u,
                          a2: BufferType);
                  if ( v15 != 0
                    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
                         a1: v15,
                         a2: CDmeAnimationSet::m_classType.u) == 0 )
                  {
                    *(_DWORD *)v13 = -1;
                  }
                }
                CDmeElementRefHelper::Ref(this: v13, hElement: *(_DWORD *)v13, handleType: HT_WEAK);
              }
              *(_DWORD *)&v13[4] = -1;
              v16 = CCodecBuffer_Block::GetBufferType(this: v11);
              v17 = *(_DWORD *)&v13[4];
              if ( v16 != v17 )
              {
                CDmeElementRefHelper::Unref(this: v13 + 4, hElement: v17, handleType: HT_WEAK);
                *(_DWORD *)&v13[4] = v16;
                if ( v16 != -1 )
                {
                  v18 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
                          a1: g_pDataModel.u,
                          a2: v16);
                  if ( v18 != 0
                    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v18 + 16))(
                         a1: v18,
                         a2: CDmElement::m_classType.u) == 0 )
                  {
                    *(_DWORD *)&v13[4] = -1;
                  }
                }
                CDmeElementRefHelper::Ref(this: v13 + 4, hElement: *(DmElementHandle_t *)&v13[4], handleType: HT_WEAK);
              }
              v2 = controlList;
              *(_DWORD *)&v13[8] = 0;
              v19 = (vgui::TreeNode *)v13;
            }
            else
            {
              v19 = nullptr;
            }
            v20 = v2[1].m_pMemory;
            m_nAllocationCount = v2->m_nAllocationCount;
            if ( (int)v20 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v2, num: (int)v20 - m_nAllocationCount + 1);
            ++v2[1].m_pMemory;
            v22 = v2->m_pMemory;
            v23 = (char *)v2[1].m_pMemory - (char *)v20 - 1;
            v2[1].m_nAllocationCount = (int)v2->m_pMemory;
            if ( v23 > 0 )
              _V_memmove(dest: &v22[(_DWORD)v20 + 1], src: &v22[(_DWORD)v20], count: 4 * v23);
            v24 = &v2->m_pMemory[(_DWORD)v20];
            if ( v24 != nullptr )
              *v24 = v19;
          }
          v9 = i + 1;
          i = v9;
          if ( v9 >= v26 )
            break;
          Position = controls;
        }
      }
      pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( pAnimSet == nullptr )
        break;
      v6 = (CDmeTransform *)pAnimSet;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457BF0
// Name: void AddMissingControls<struct SelectionInfo_t>(class CUtlVector<struct SelectionInfo_t __near *,class CUtlMemory<struct SelectionInfo_t __near *,int>> __near &,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddMissingControls<SelectionInfo_t>(
        CUtlMemory<vgui::TreeNode *,int> *controlList,
        CDmeFilmClip *pFilmClip)
{
  CDmeTransform *v2; // eax
  CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v5; // ecx
  int v6; // eax
  CExpressionCalculator *v7; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  int v9; // edi
  CDmeElementRefHelper *v10; // eax
  CDmeElementRefHelper *v11; // edi
  int BufferType; // esi
  int v13; // eax
  int v14; // ebx
  DmElementHandle_t v15; // eax
  int v16; // eax
  vgui::TreeNode *v17; // ebx
  vgui::TreeNode **v18; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // edi
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-18h] BYREF
  int nControls; // [esp+14h] [ebp-10h]
  int m_pMemory; // [esp+18h] [ebp-Ch]
  CDmaElementArray<CDmElement> *controls; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  CDmeAnimationSet *pAnimSet; // [esp+30h] [ebp+Ch]

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v2 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  pAnimSet = (CDmeAnimationSet *)v2;
  if ( v2 != nullptr )
  {
    while ( 1 )
    {
      Position = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v2);
      m_Size = Position->m_Storage.m_Size;
      v5 = 0;
      controls = Position;
      nControls = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: Position->m_Storage.m_Memory.m_pMemory[v5]);
          v7 = (CExpressionCalculator *)v6;
          if ( v6 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
                 a1: v6,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            v8 = controlList;
            v9 = 0;
            m_pMemory = (int)controlList[1].m_pMemory;
            if ( m_pMemory <= 0 )
            {
LABEL_12:
              v10 = (CDmeElementRefHelper *)CUtlMemoryPool::Alloc(this: &SelectionInfo_t::s_Allocator, amount: 0xCu);
              v11 = v10;
              if ( v10 != nullptr )
              {
                *(_DWORD *)v10 = -1;
                if ( pAnimSet != nullptr )
                  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
                else
                  BufferType = -1;
                if ( BufferType != *(_DWORD *)v11 )
                {
                  CDmeElementRefHelper::Unref(this: v11, hElement: *(_DWORD *)v11, handleType: HT_WEAK);
                  *(_DWORD *)v11 = BufferType;
                  if ( BufferType != -1 )
                  {
                    v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
                            a1: g_pDataModel.u,
                            a2: BufferType);
                    if ( v13 != 0
                      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v13 + 16))(
                           a1: v13,
                           a2: CDmeAnimationSet::m_classType.u) == 0 )
                    {
                      *(_DWORD *)v11 = -1;
                    }
                  }
                  CDmeElementRefHelper::Ref(this: v11, hElement: *(_DWORD *)v11, handleType: HT_WEAK);
                }
                *(_DWORD *)&v11[4] = -1;
                v14 = CCodecBuffer_Block::GetBufferType(this: v7);
                v15 = *(_DWORD *)&v11[4];
                if ( v14 != v15 )
                {
                  CDmeElementRefHelper::Unref(this: v11 + 4, hElement: v15, handleType: HT_WEAK);
                  *(_DWORD *)&v11[4] = v14;
                  if ( v14 != -1 )
                  {
                    v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
                            a1: g_pDataModel.u,
                            a2: v14);
                    if ( v16 != 0
                      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
                           a1: v16,
                           a2: CDmElement::m_classType.u) == 0 )
                    {
                      *(_DWORD *)&v11[4] = -1;
                    }
                  }
                  CDmeElementRefHelper::Ref(this: v11 + 4, hElement: *(DmElementHandle_t *)&v11[4], handleType: HT_WEAK);
                }
                v8 = controlList;
                *(_DWORD *)&v11[8] = 0;
                v17 = (vgui::TreeNode *)v11;
              }
              else
              {
                v17 = nullptr;
              }
              v18 = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)v18 + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)v18 - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v20 = v8->m_pMemory;
              v21 = (char *)v8[1].m_pMemory - (char *)v18 - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v21 > 0 )
                _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
              v22 = &v8->m_pMemory[(_DWORD)v18];
              if ( v22 != nullptr )
                *v22 = v17;
            }
            else
            {
              while ( (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                                 a1: g_pDataModel.u,
                                                 a2: *(DmElementHandle_t *)&controlList->m_pMemory[v9]->vgui::Panel::m_RegisterClass) != v7 )
              {
                if ( ++v9 >= m_pMemory )
                  goto LABEL_12;
              }
            }
          }
          v5 = i + 1;
          i = v5;
          if ( v5 >= nControls )
            break;
          Position = controls;
        }
      }
      pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( pAnimSet == nullptr )
        break;
      v2 = (CDmeTransform *)pAnimSet;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457E30
// Name: public: virtual void CCombinationOperatorControl::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombinationOperatorControl::ChangeAnimationSetClip(
        CCombinationOperatorControl *this,
        CDmeFilmClip *pFilmClip)
{
  RebuildControlList<SelectionInfo_t>(
    controlList: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FullControlList,
    pFilmClip);
  CBaseAnimationSetControl::ChangeAnimationSetClip(this, pFilmClip);
}

//------------------------------------------------------------------------------
// Address: 0x00457E60
// Name: public: virtual void CCombinationOperatorControl::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombinationOperatorControl::OnControlsAddedOrRemoved(CCombinationOperatorControl *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_FullControlList; // edi
  CDmeFilmClip *v3; // eax

  p_m_FullControlList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FullControlList;
  RemoveNullControls<SelectionInfo_t>(controlList: &this->m_FullControlList);
  v3 = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hFilmClip.m_handle);
  AddMissingControls<SelectionInfo_t>(controlList: p_m_FullControlList, pFilmClip: v3);
  CBaseAnimationSetControl::OnControlsAddedOrRemoved(this);
}

//------------------------------------------------------------------------------
// Address: 0x00457EA0
// Name: protected: void CDmeDagEditPanel::SetMakefileRootElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetMakefileRootElement(CDmeDagEditPanel *this, CDmElement *pRoot)
{
  CDmeAnimationList *Value; // eax
  CDmeAnimationList *v4; // eax
  CDmeCombinationOperator *v5; // eax

  Value = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "animationList");
  CDmeDagEditPanel::SetAnimationList(this, pAnimationList: Value);
  v4 = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "vertexAnimationList");
  CDmeDagEditPanel::SetVertexAnimationList(this, pAnimationList: v4);
  v5 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: pRoot, pAttributeName: "combinationOperator");
  CDmeCombinationOperatorPanel::SetCombinationOperator(this: this->m_pCombinationPanel, pOp: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00457EF0
// Name: public: void CDmeDagEditPanel::SetDmeElement(class CDmeDCCMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagEditPanel::SetDmeElement(CDmeDagEditPanel *this, CDmeDCCMakefile *pDCCMakefile)
{
  CDmElement *OutputElement; // eax
  CDmElement *v4; // edi
  CDmeAnimationList *Value; // eax
  CDmeAnimationList *v6; // eax
  CDmeCombinationOperator *v7; // eax

  CDmeDagRenderPanel::SetDmeElement(this: this->m_pDagRenderPanel, pDCCMakefile);
  OutputElement = CDmeMakefile::GetOutputElement(this: pDCCMakefile, bCreateIfNecessary: true);
  v4 = OutputElement;
  if ( OutputElement != nullptr )
  {
    Value = CDmElement::GetValueElement<CDmeAnimationList>(this: OutputElement, pAttributeName: "animationList");
    CDmeDagEditPanel::SetAnimationList(this, pAnimationList: Value);
    v6 = CDmElement::GetValueElement<CDmeAnimationList>(this: v4, pAttributeName: "vertexAnimationList");
    CDmeDagEditPanel::SetVertexAnimationList(this, pAnimationList: v6);
    v7 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: v4, pAttributeName: "combinationOperator");
    CDmeCombinationOperatorPanel::SetCombinationOperator(this: this->m_pCombinationPanel, pOp: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479D40
// Name: protected: void CBaseAnimationSetControl::ApplyTransformSliderValue<class Quaternion>(class CAttributeSlider __near *,class CDmeTransformControl __near *,bool,bool,bool __near &,enum AnimationControlType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyTransformSliderValue<Quaternion>(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        vgui::BuildGroup *pTranformControl,
        DmeTime_t bUsePreviewValue,
        bool bForce,
        bool *valuesChanged,
        AnimationControlType_t type)
{
  AnimationControlType_t v7; // ebx
  CDmAttribute *PositionAttr; // esi
  CDmeChannel *PositionChannel; // eax
  CDmeChannel *v10; // edi
  ChannelMode_t Mode; // eax
  char v12; // cl
  DmeTime_t *CurrentTime; // eax
  Quaternion *v14; // eax
  LogComponents_t v15; // eax
  Quaternion maskedValue; // [esp+Ch] [ebp-30h] BYREF
  Quaternion currentValue; // [esp+1Ch] [ebp-20h] BYREF
  Quaternion value; // [esp+2Ch] [ebp-10h] BYREF

  v7 = type;
  if ( type == ANIM_CONTROL_COUNT )
  {
    PositionAttr = (CDmAttribute *)CDmeTransformControl::GetPositionAttr(this: pTranformControl);
    PositionChannel = CDmeTransformControl::GetPositionChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  else
  {
    if ( type != ANIM_CONTROL_TXFORM_ORIENTATION )
      return;
    PositionAttr = CDmeTransformControl::GetOrientationAttr(this: (CDmeTransformControl *)pTranformControl);
    PositionChannel = CDmeTransformControl::GetOrientationChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  v10 = PositionChannel;
  if ( PositionAttr != nullptr )
  {
    if ( PositionChannel != nullptr )
    {
      Mode = CDmeChannel::GetMode(this: PositionChannel);
      if ( Mode != CM_PASS && Mode != CM_RECORD )
      {
        v12 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      Mode = CM_PASS;
    }
    v12 = 1;
LABEL_12:
    if ( Mode == CM_PLAY )
    {
      value = *CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
      CurrentTime = CDmeChannel::GetCurrentTime(this: v10, result: &bUsePreviewValue);
      CDmeChannel::GetPlaybackValueAtTime<Quaternion>(this: v10, time: (DmeTime_t)CurrentTime->m_tms, &value);
      CAttributeSlider::SetValue(this: pSlider, type: v7, quat: &value);
      CDmAttribute::SetValue<Quaternion>(this: PositionAttr, &value);
    }
    else if ( v12 != 0 )
    {
      if ( LOBYTE(bUsePreviewValue.m_tms) != 0 )
        CAttributeSlider::GetPreview(this: pSlider, type: v7, out: &value);
      else
        CAttributeSlider::GetValue(this: pSlider, type: v7, out: &value);
      v14 = (Quaternion *)CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
      if ( Quaternion::operator!=(this: v14, src: &value) || bForce )
      {
        *valuesChanged = bForce;
        currentValue = *CDmAttribute::GetValue<Quaternion>(this: PositionAttr);
        v15 = CAttributeSlider::VisibleComponents(this: pSlider);
        MaskValue<Quaternion>(result: &maskedValue, &value, curQuat: &currentValue, componentFlags: v15);
        CDmAttribute::SetValue<Quaternion>(this: PositionAttr, value: &maskedValue);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479EA0
// Name: protected: void CBaseAnimationSetControl::ApplyTransformSliderValue<class Vector>(class CAttributeSlider __near *,class CDmeTransformControl __near *,bool,bool,bool __near &,enum AnimationControlType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyTransformSliderValue<Vector>(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        vgui::BuildGroup *pTranformControl,
        DmeTime_t bUsePreviewValue,
        bool bForce,
        bool *valuesChanged,
        AnimationControlType_t type)
{
  AnimationControlType_t v7; // ebx
  CDmAttribute *PositionAttr; // edi
  CDmeChannel *PositionChannel; // eax
  CDmeChannel *v10; // esi
  ChannelMode_t Mode; // eax
  char v12; // cl
  DmeTime_t *CurrentTime; // eax
  CDmaVar<Vector> *v14; // eax
  char v15; // al
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  Vector maskedValue; // [esp+18h] [ebp-18h] BYREF
  Vector out; // [esp+24h] [ebp-Ch] BYREF
  Vector currentValue; // 0:^14.12

  v7 = type;
  if ( type == ANIM_CONTROL_COUNT )
  {
    PositionAttr = (CDmAttribute *)CDmeTransformControl::GetPositionAttr(this: pTranformControl);
    PositionChannel = CDmeTransformControl::GetPositionChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  else
  {
    if ( type != ANIM_CONTROL_TXFORM_ORIENTATION )
      return;
    PositionAttr = CDmeTransformControl::GetOrientationAttr(this: (CDmeTransformControl *)pTranformControl);
    PositionChannel = CDmeTransformControl::GetOrientationChannel(this: (CDmeTransformControl *)pTranformControl);
  }
  v10 = PositionChannel;
  if ( PositionAttr != nullptr )
  {
    if ( PositionChannel != nullptr )
    {
      Mode = CDmeChannel::GetMode(this: PositionChannel);
      if ( Mode != CM_PASS && Mode != CM_RECORD )
      {
        v12 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      Mode = CM_PASS;
    }
    v12 = 1;
LABEL_12:
    if ( Mode == CM_PLAY )
    {
      maskedValue = CDmAttribute::GetValue<Vector>(this: PositionAttr)->m_Storage;
      CurrentTime = CDmeChannel::GetCurrentTime(this: v10, result: &bUsePreviewValue);
      CDmeChannel::GetPlaybackValueAtTime<Vector>(this: v10, time: (DmeTime_t)CurrentTime->m_tms, value: &maskedValue);
      CAttributeSlider::SetValue(this: pSlider, type: v7, vec: &maskedValue);
      CDmAttribute::SetValue<Vector>(this: PositionAttr, value: &maskedValue);
    }
    else if ( v12 != 0 )
    {
      if ( LOBYTE(bUsePreviewValue.m_tms) != 0 )
        CAttributeSlider::GetPreview(this: pSlider, type: v7, &out);
      else
        CAttributeSlider::GetValue(this: pSlider, type: v7, &out);
      v14 = CDmAttribute::GetValue<Vector>(this: PositionAttr);
      if ( out.x != v14->m_Storage.x || out.y != v14->m_Storage.y || out.z != v14->m_Storage.z || bForce )
      {
        *valuesChanged = bForce;
        currentValue = CDmAttribute::GetValue<Vector>(this: PositionAttr)->m_Storage;
        v15 = CAttributeSlider::VisibleComponents(this: pSlider);
        if ( (v15 & 1) != 0 )
          x = out.x;
        else
          x = currentValue.x;
        maskedValue.x = x;
        if ( (v15 & 2) != 0 )
          y = out.y;
        else
          y = currentValue.y;
        maskedValue.y = y;
        if ( (v15 & 4) != 0 )
          z = out.z;
        else
          z = currentValue.z;
        maskedValue.z = z;
        CDmAttribute::SetValue<Vector>(this: PositionAttr, value: &maskedValue);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B3810
// Name: _CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__()
{
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    sg.m_pControl->FireControlSelectionChangedListeners(this: sg.m_pControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454E20
// Name: class CDmeAnimationSet __near * CastElement<class CDmeAnimationSet>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl CastElement<CDmeAnimationSet>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeAnimationSet::m_classType.u.m_Id) )
  {
    return (CDmeAnimationSet *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B3830
// Name: _dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__()
{
  ConVar::~ConVar(this: &ifm_attributeslider_sensitivity);
}

//------------------------------------------------------------------------------
// Address: 0x006B3840
// Name: _dynamic_atexit_destructor_for__ifm_attributeslider_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_attributeslider_legacy__()
{
  ConVar::~ConVar(this: &ifm_attributeslider_legacy);
}

//------------------------------------------------------------------------------
// Address: 0x006B3850
// Name: _dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__()
{
  ConVar::~ConVar(this: &ifm_threaded_updatecontrolvalues);
}

} // namespace sceneviewer
