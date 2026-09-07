// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeelementpickerpanel.cpp
// Functions: 12
// ============================================================

#include "vgui2\dme_controls\attributeelementpickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046F760
// Name: public: static char const __near * CAttributeElementPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeElementPickerPanel::GetPanelClassName()
{
  return "CAttributeElementPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046F770
// Name: private: virtual class vgui::Panel __near * CAttributeElementPickerPanel::GetDataPanel(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextEntry *__thiscall CAttributeElementPickerPanel::GetDataPanel(CAttributeElementPickerPanel *this)
{
  return this->m_pData;
}

//------------------------------------------------------------------------------
// Address: 0x0046F780
// Name: public: virtual void CAttributeElementPickerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::OnCommand(CAttributeElementPickerPanel *this, const char *cmd)
{
  if ( _V_stricmp(s1: cmd, s2: "open") != 0 )
    vgui::Panel::OnCommand(this, command: cmd);
  else
    this->ShowPickerDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046F7C0
// Name: public: virtual void CAttributeElementPickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::PerformLayout(CAttributeElementPickerPanel *this)
{
  vgui::IImage *v2; // edi
  vgui::DHANDLE<vgui::Button> *p_m_hEdit; // esi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  int viewWidth; // [esp+8h] [ebp-8h] BYREF
  int viewHeight; // [esp+Ch] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  v2 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_properties_linkarrow", a3: 0);
  if ( v2 != nullptr )
  {
    p_m_hEdit = &this->m_hEdit;
    v4 = vgui::PHandle::Get(this: p_m_hEdit);
    ((void (__thiscall *)(vgui::Panel *, vgui::IImage *, _DWORD))v4->__vftable[1].GetClassName)(a1: v4, a2: v2, a3: 0);
    v5 = vgui::PHandle::Get(this: p_m_hEdit);
    v5->SetPaintBorderEnabled(this: v5, a2: false);
    v6 = vgui::PHandle::Get(this: p_m_hEdit);
    ((void (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].IsWithinTraverse)(a1: v6, a2: 4);
    v7 = vgui::PHandle::Get(this: p_m_hEdit);
    vgui::Panel::SetBounds(this: v7, x: 6, y: (int)((double)(viewHeight - 16) * 0.5), wide: 16, tall: 16);
  }
  else
  {
    v8 = vgui::PHandle::Get(this: &this->m_hEdit);
    vgui::Panel::SetBounds(this: v8, x: 0, y: 0, wide: 100, tall: 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F8A0
// Name: private: virtual void CAttributeElementPickerPanel::OnDmeSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::OnDmeSelected(CAttributeElementPickerPanel *this, KeyValues *pKeyValues)
{
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: "dme", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = v4;
  if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
    v5 = nullptr;
  CBaseAttributePanel::SetAttributeValueElement(this, pElement: v5);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046F900
// Name: private: virtual void CAttributeElementPickerPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::Refresh(CAttributeElementPickerPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v4; // eax
  CDmElement *AttributeValueElement; // eax
  CDmElement *v6; // esi
  bool v7; // zf
  const char *m_pAsString; // ebx
  int v9; // eax
  const char *v10; // esi
  double v11; // [esp+Ch] [ebp-23Ch]
  char elemText[512]; // [esp+20h] [ebp-228h] BYREF
  char idstr[40]; // [esp+220h] [ebp-28h] BYREF

  elemText[0] = 0;
  if ( CBaseAttributePanel::GetEditorInfo(this) == nullptr )
    goto LABEL_24;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  Attribute = CDmElement::FindAttribute(this: EditorInfo, pAttributeName: "hideText");
  v4 = Attribute != nullptr
     ? CDmAttribute::GetValue<bool>(this: Attribute)
     : &`CDmElement::GetValue<bool>'::`2'::defaultVal;
  if ( !v4->m_Storage )
  {
LABEL_24:
    if ( CBaseAttributePanel::HasAttribute(this) )
      AttributeValueElement = CBaseAttributePanel::GetAttributeValueElement(this);
    else
      AttributeValueElement = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    v6 = AttributeValueElement;
    if ( AttributeValueElement != nullptr )
    {
      v7 = !this->m_bShowUniqueID;
      memset(idstr, 0, 37);
      if ( !v7 )
        UniqueIdToString(id: &AttributeValueElement->m_Id, pBuf: idstr, nMaxLen: 37);
      if ( this->m_bShowMemoryUsage )
      {
        m_pAsString = v6->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        v11 = (float)((float)CDmElement::EstimateMemoryUsage(this: v6, depth: TD_NONE) * 0.0009765625);
        v9 = CDmElement::EstimateMemoryUsage(this: v6, depth: TD_DEEP);
        V_snprintf(
          pDest: elemText,
          maxLen: 512,
          pFormat: "%s %s (%.3fMB total / %.3fKB self)",
          m_pAsString,
          idstr,
          (float)((float)v9 * 0.00000095367432),
          v11);
      }
      else
      {
        v10 = v6->m_Type.u.m_pAsString;
        if ( v10 == (const char *)-1 )
          v10 = defaultValue;
        V_snprintf(pDest: elemText, maxLen: 512, pFormat: "%s %s", v10, idstr);
      }
    }
  }
  this->m_pData->SetText(this: this->m_pData, a2: elemText);
  this->m_pData->SetEditable(this: this->m_pData, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046FAC0
// Name: public: static void CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DmeSelected";
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
// Address: 0x0046FB50
// Name: private: virtual void CAttributeElementPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::ShowPickerDialog(CAttributeElementPickerPanel *this)
{
  CAttributeElementPickerPanel *v1; // esi
  CDmeEditorChoicesInfo *EditorInfo; // eax
  IElementPropertiesChoices *v3; // edi
  DmElementHandle_t m_handle; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v6; // eax
  IElementPropertiesChoices_vtbl *v7; // edi
  const char *ChoiceType; // eax
  int v9; // edi
  int m_Size; // eax
  int v11; // esi
  DmePickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  const char *m_pChoiceString; // eax
  CDmePickerFrame *v15; // eax
  CDmePickerFrame *v16; // edi
  DmePickerInfo_t *v17; // eax
  ElementChoice_t *v18; // eax
  int v19; // [esp-10h] [ebp-54h]
  int v20; // [esp-8h] [ebp-4Ch]
  CUtlVector<ElementChoice_t,CUtlMemory<ElementChoice_t,int> > choices; // [esp+Ch] [ebp-38h] BYREF
  CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > vec; // [esp+20h] [ebp-24h] BYREF
  CAttributeElementPickerPanel *v23; // [esp+34h] [ebp-10h]
  IElementPropertiesChoices *v24; // [esp+38h] [ebp-Ch]
  CDmeEditorChoicesInfo *v25; // [esp+3Ch] [ebp-8h]
  int c; // [esp+40h] [ebp-4h]

  v1 = this;
  v23 = this;
  EditorInfo = (CDmeEditorChoicesInfo *)CBaseAttributePanel::GetEditorInfo(this);
  v25 = EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorChoicesInfo::m_classType) )
  {
    memset(&choices, 0, sizeof(choices));
    memset((void *)&vec, 0, sizeof(vec));
    v3 = vgui::ElementPropertiesChoices();
    m_handle = v1->m_hObject.m_handle;
    LOBYTE(c) = v1->m_nArrayIndex >= 0;
    GetElement = g_pDataModel->GetElement;
    v24 = v3;
    v6 = (int)GetElement(this: g_pDataModel, a2: m_handle);
    v7 = v3->__vftable;
    v20 = c;
    v19 = v6;
    ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v25);
    if ( v7->GetElementChoiceList(
           this: v24,
           a2: ChoiceType,
           a3: (CDmElement *)v19,
           a4: v1->m_szAttributeName,
           a5: v20,
           a6: &choices) )
    {
      c = choices.m_Size;
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(this: &vec, num: choices.m_Size);
      v9 = 0;
      if ( c > 0 )
      {
        do
        {
          m_Size = vec.m_Size;
          v11 = vec.m_Size;
          if ( vec.m_Size + 1 > vec.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<MDLSquenceLayer_t,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&vec,
              num: vec.m_Size - vec.m_Memory.m_nAllocationCount + 1);
            m_Size = vec.m_Size;
          }
          m_pMemory = vec.m_Memory.m_pMemory;
          vec.m_Size = m_Size + 1;
          v13 = m_Size - v11;
          vec.m_pElements = vec.m_Memory.m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(dest: &vec.m_Memory.m_pMemory[v11 + 1], src: &vec.m_Memory.m_pMemory[v11], count: 8 * v13);
            m_pMemory = vec.m_Memory.m_pMemory;
          }
          m_pMemory[v11].m_hElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)choices.m_Memory.m_pMemory[v9].m_pValue);
          m_pChoiceString = choices.m_Memory.m_pMemory[v9++].m_pChoiceString;
          vec.m_Memory.m_pMemory[v11].m_pChoiceString = m_pChoiceString;
        }
        while ( v9 < c );
        v1 = v23;
      }
    }
    v15 = (CDmePickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v15 != nullptr )
      v16 = CDmePickerFrame::CDmePickerFrame(this: v15, pParent: v1, pTitle: "Select DME Element");
    else
      v16 = nullptr;
    v16->AddActionSignalTarget_2(this: v16, a2: v1);
    CDmePickerFrame::DoModal(this: v16, &vec, pKeyValues: nullptr);
    v17 = vec.m_Memory.m_pMemory;
    vec.m_Size = 0;
    if ( vec.m_Memory.m_nGrowSize >= 0 )
    {
      if ( vec.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_Memory.m_pMemory);
        v17 = nullptr;
        vec.m_Memory.m_pMemory = nullptr;
      }
      vec.m_Memory.m_nAllocationCount = 0;
    }
    vec.m_pElements = v17;
    if ( vec.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v17 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
        vec.m_Memory.m_pMemory = nullptr;
      }
      vec.m_Memory.m_nAllocationCount = 0;
    }
    v18 = choices.m_Memory.m_pMemory;
    choices.m_Size = 0;
    if ( choices.m_Memory.m_nGrowSize >= 0 )
    {
      if ( choices.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
        v18 = nullptr;
        choices.m_Memory.m_pMemory = nullptr;
      }
      choices.m_Memory.m_nAllocationCount = 0;
    }
    choices.m_pElements = v18;
    if ( choices.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FD60
// Name: public: CAttributeElementPickerPanel::CAttributeElementPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPickerPanel *__thiscall CAttributeElementPickerPanel::CAttributeElementPickerPanel(
        CAttributeElementPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  CAttributeTextEntry *v9; // eax
  CAttributeTextEntry *v10; // eax
  BOOL v11; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CAttributeElementPickerPanel_vtbl *)&CAttributeElementPickerPanel::`vftable';
  if ( `CAttributeElementPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
    v4->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeElementPickerPanel");
    v5->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPickerPanel");
    v6->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(a1: (int)&savedregs);
  this->m_hEdit.m_iPanelID = -1;
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "Open",
           text: "...",
           pActionSignalTarget: this,
           pCmd: "open");
  else
    v8 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEdit, pPanel: v8);
  v9 = (CAttributeTextEntry *)MemAlloc_Alloc(nSize: 0x848u);
  if ( v9 != nullptr )
    v10 = CAttributeTextEntry::CAttributeTextEntry(this: v9, parent: this, panelName: "AttributeValue");
  else
    v10 = nullptr;
  v11 = (this->m_nFlags & 4) == 0;
  this->m_pData = v10;
  v10->SetEnabled(this: v10, a2: v11);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  this->m_pType->SetText_2(this: this->m_pType, a2: "element");
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  this->m_bShowUniqueID = info->m_bShowMemoryUsage;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046FEF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeElementPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeElementPickerPanel::GetMessageMap(CAttributeElementPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeElementPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeElementPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
  `CAttributeElementPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046FF20
// Name: public: virtual struct PanelAnimationMap __near * CAttributeElementPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeElementPickerPanel::GetAnimMap(CAttributeElementPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeElementPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046FF30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeElementPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeElementPickerPanel::GetKBMap(CAttributeElementPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeElementPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeElementPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPickerPanel");
  `CAttributeElementPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10492C30
// Name: public: static char const __near * CAttributeElementPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeElementPickerPanel::GetPanelClassName()
{
  return "CAttributeElementPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10492C40
// Name: private: virtual class vgui::Panel __near * CAttributeElementPickerPanel::GetDataPanel(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextEntry *__thiscall CAttributeElementPickerPanel::GetDataPanel(CAttributeElementPickerPanel *this)
{
  return this->m_pData;
}

//------------------------------------------------------------------------------
// Address: 0x10492C50
// Name: public: virtual void CAttributeElementPickerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::OnCommand(CAttributeElementPickerPanel *this, const char *cmd)
{
  if ( _V_stricmp(s1: cmd, s2: "open") != 0 )
    vgui::Panel::OnCommand(this, command: cmd);
  else
    this->ShowPickerDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10492C90
// Name: public: virtual void CAttributeElementPickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::PerformLayout(CAttributeElementPickerPanel *this)
{
  vgui::IImage *v2; // edi
  vgui::DHANDLE<vgui::Button> *p_m_hEdit; // esi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  int viewWidth; // [esp+8h] [ebp-8h] BYREF
  int viewHeight; // [esp+Ch] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  v2 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_properties_linkarrow", a3: 0);
  if ( v2 != nullptr )
  {
    p_m_hEdit = &this->m_hEdit;
    v4 = vgui::PHandle::Get(this: p_m_hEdit);
    ((void (__thiscall *)(vgui::Panel *, vgui::IImage *, _DWORD))v4->__vftable[1].GetClassName)(a1: v4, a2: v2, a3: 0);
    v5 = vgui::PHandle::Get(this: p_m_hEdit);
    v5->SetPaintBorderEnabled(this: v5, a2: false);
    v6 = vgui::PHandle::Get(this: p_m_hEdit);
    ((void (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].IsWithinTraverse)(a1: v6, a2: 4);
    v7 = vgui::PHandle::Get(this: p_m_hEdit);
    vgui::Panel::SetBounds(this: v7, x: 6, y: (int)((double)(viewHeight - 16) * 0.5), wide: 16, tall: 16);
  }
  else
  {
    v8 = vgui::PHandle::Get(this: &this->m_hEdit);
    vgui::Panel::SetBounds(this: v8, x: 0, y: 0, wide: 100, tall: 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10492D70
// Name: private: virtual void CAttributeElementPickerPanel::OnDmeSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::OnDmeSelected(CAttributeElementPickerPanel *this, KeyValues *pKeyValues)
{
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: "dme", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = v4;
  if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
    v5 = nullptr;
  CBaseAttributePanel::SetAttributeValueElement(this, pElement: v5);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x10492DD0
// Name: private: virtual void CAttributeElementPickerPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CAttributeElementPickerPanel::Refresh(CAttributeElementPickerPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v4; // eax
  CDmElement *AttributeValueElement; // eax
  CDmElement *v6; // esi
  bool v7; // zf
  const char *m_pAsString; // ebx
  int v9; // eax
  const char *v10; // esi
  double v11; // [esp+8h] [ebp-23Ch]
  char pDest[32]; // [esp+18h] [ebp-22Ch] BYREF
  _BYTE elemText_484[37]; // [esp+21Ch] [ebp-28h] OVERLAPPED BYREF

  pDest[4] = 0;
  if ( CBaseAttributePanel::GetEditorInfo(this) == nullptr )
    goto LABEL_24;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  Attribute = CDmElement::FindAttribute(this: EditorInfo, pAttributeName: "hideText");
  v4 = Attribute != nullptr
     ? CDmAttribute::GetValue<bool>(this: Attribute)
     : &`CDmElement::GetValue<bool>'::`2'::defaultVal;
  if ( !v4->m_Storage )
  {
LABEL_24:
    if ( CBaseAttributePanel::HasAttribute(this) )
      AttributeValueElement = CBaseAttributePanel::GetAttributeValueElement(this);
    else
      AttributeValueElement = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    v6 = AttributeValueElement;
    if ( AttributeValueElement != nullptr )
    {
      v7 = !this->m_bShowUniqueID;
      memset(elemText_484, 0, sizeof(elemText_484));
      if ( !v7 )
        UniqueIdToString(id: &AttributeValueElement->m_Id, pBuf: elemText_484, nMaxLen: 37);
      if ( this->m_bShowMemoryUsage )
      {
        m_pAsString = v6->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        v11 = (float)((float)CDmElement::EstimateMemoryUsage(this: v6, depth: TD_NONE) * 0.0009765625);
        v9 = CDmElement::EstimateMemoryUsage(this: v6, depth: TD_DEEP);
        V_snprintf(
          pDest: &pDest[4],
          maxLen: 0x200u,
          pFormat: "%s %s (%.3fMB total / %.3fKB self)",
          m_pAsString,
          elemText_484,
          (float)((float)v9 * 0.00000095367432),
          v11);
      }
      else
      {
        v10 = v6->m_Type.u.m_pAsString;
        if ( v10 == (const char *)-1 )
          v10 = &var;
        V_snprintf(pDest: &pDest[4], maxLen: 0x200u, pFormat: "%s %s", v10, elemText_484);
      }
    }
  }
  this->m_pData->SetText(this: this->m_pData, a2: &pDest[4]);
  this->m_pData->SetEditable(this: this->m_pData, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10492FA0
// Name: public: static void CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DmeSelected";
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
// Address: 0x10493030
// Name: private: virtual void CAttributeElementPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::ShowPickerDialog(CAttributeElementPickerPanel *this)
{
  CAttributeElementPickerPanel *v1; // esi
  CDmeEditorChoicesInfo *EditorInfo; // eax
  IElementPropertiesChoices *v3; // edi
  DmElementHandle_t m_handle; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v6; // eax
  IElementPropertiesChoices_vtbl *v7; // edi
  const char *ChoiceType; // eax
  int v9; // edi
  int m_Size; // eax
  int v11; // esi
  DmePickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  const char *m_pChoiceString; // eax
  CDmePickerFrame *v15; // eax
  CDmePickerFrame *v16; // edi
  DmePickerInfo_t *v17; // eax
  ElementChoice_t *v18; // eax
  int v19; // [esp-10h] [ebp-54h]
  int v20; // [esp-8h] [ebp-4Ch]
  CUtlVector<ElementChoice_t,CUtlMemory<ElementChoice_t,int> > choices; // [esp+Ch] [ebp-38h] BYREF
  CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > vec; // [esp+20h] [ebp-24h] BYREF
  CAttributeElementPickerPanel *v23; // [esp+34h] [ebp-10h]
  IElementPropertiesChoices *v24; // [esp+38h] [ebp-Ch]
  CDmeEditorChoicesInfo *v25; // [esp+3Ch] [ebp-8h]
  int c; // [esp+40h] [ebp-4h]

  v1 = this;
  v23 = this;
  EditorInfo = (CDmeEditorChoicesInfo *)CBaseAttributePanel::GetEditorInfo(this);
  v25 = EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorChoicesInfo::m_classType) )
  {
    memset(&choices, 0, sizeof(choices));
    memset((void *)&vec, 0, sizeof(vec));
    v3 = vgui::ElementPropertiesChoices();
    m_handle = v1->m_hObject.m_handle;
    LOBYTE(c) = v1->m_nArrayIndex >= 0;
    GetElement = g_pDataModel->GetElement;
    v24 = v3;
    v6 = (int)GetElement(this: g_pDataModel, a2: m_handle);
    v7 = v3->__vftable;
    v20 = c;
    v19 = v6;
    ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v25);
    if ( v7->GetElementChoiceList(
           this: v24,
           a2: ChoiceType,
           a3: (CDmElement *)v19,
           a4: v1->m_szAttributeName,
           a5: v20,
           a6: &choices) )
    {
      c = choices.m_Size;
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(this: &vec, num: choices.m_Size);
      v9 = 0;
      if ( c > 0 )
      {
        do
        {
          m_Size = vec.m_Size;
          v11 = vec.m_Size;
          if ( vec.m_Size + 1 > vec.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CacheOptimizedKDNode,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&vec,
              num: vec.m_Size - vec.m_Memory.m_nAllocationCount + 1);
            m_Size = vec.m_Size;
          }
          m_pMemory = vec.m_Memory.m_pMemory;
          vec.m_Size = m_Size + 1;
          v13 = m_Size - v11;
          vec.m_pElements = vec.m_Memory.m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(
              dest: (unsigned __int8 *)&vec.m_Memory.m_pMemory[v11 + 1],
              src: (unsigned __int8 *)&vec.m_Memory.m_pMemory[v11],
              count: 8 * v13);
            m_pMemory = vec.m_Memory.m_pMemory;
          }
          m_pMemory[v11].m_hElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)choices.m_Memory.m_pMemory[v9].m_pValue);
          m_pChoiceString = choices.m_Memory.m_pMemory[v9++].m_pChoiceString;
          vec.m_Memory.m_pMemory[v11].m_pChoiceString = m_pChoiceString;
        }
        while ( v9 < c );
        v1 = v23;
      }
    }
    v15 = (CDmePickerFrame *)operator new(nSize: 0x224u);
    if ( v15 != nullptr )
      v16 = CDmePickerFrame::CDmePickerFrame(this: v15, pParent: v1, pTitle: "Select DME Element");
    else
      v16 = nullptr;
    v16->AddActionSignalTarget_2(this: v16, a2: v1);
    CDmePickerFrame::DoModal(this: v16, &vec, pKeyValues: nullptr);
    v17 = vec.m_Memory.m_pMemory;
    vec.m_Size = 0;
    if ( vec.m_Memory.m_nGrowSize >= 0 )
    {
      if ( vec.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_Memory.m_pMemory);
        v17 = nullptr;
        vec.m_Memory.m_pMemory = nullptr;
      }
      vec.m_Memory.m_nAllocationCount = 0;
    }
    vec.m_pElements = v17;
    if ( vec.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v17 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
        vec.m_Memory.m_pMemory = nullptr;
      }
      vec.m_Memory.m_nAllocationCount = 0;
    }
    v18 = choices.m_Memory.m_pMemory;
    choices.m_Size = 0;
    if ( choices.m_Memory.m_nGrowSize >= 0 )
    {
      if ( choices.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
        v18 = nullptr;
        choices.m_Memory.m_pMemory = nullptr;
      }
      choices.m_Memory.m_nAllocationCount = 0;
    }
    choices.m_pElements = v18;
    if ( choices.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10493240
// Name: public: CAttributeElementPickerPanel::CAttributeElementPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPickerPanel *__userpurge CAttributeElementPickerPanel::CAttributeElementPickerPanel@<eax>(
        CAttributeElementPickerPanel *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  CAttributeTextEntry *v10; // eax
  CAttributeTextEntry *v11; // eax
  BOOL v12; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, a2, parent, info);
  this->__vftable = (CAttributeElementPickerPanel_vtbl *)&CAttributeElementPickerPanel::`vftable';
  if ( `CAttributeElementPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
    v5->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CAttributeElementPickerPanel");
    v6->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPickerPanel");
    v7->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(a1: (int)&savedregs);
  this->m_hEdit.m_iPanelID = -1;
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "Open",
           text: "...",
           pActionSignalTarget: this,
           pCmd: "open");
  else
    v9 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hEdit,
    pPanel: (CDragDropHelperPanel *)v9);
  v10 = (CAttributeTextEntry *)operator new(nSize: 0x848u);
  if ( v10 != nullptr )
    v11 = CAttributeTextEntry::CAttributeTextEntry(this: v10, parent: this, panelName: "AttributeValue");
  else
    v11 = nullptr;
  v12 = (this->m_nFlags & 4) == 0;
  this->m_pData = v11;
  v11->SetEnabled(this: v11, a2: v12);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  this->m_pType->SetText(this: this->m_pType, a2: "element");
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  this->m_bShowUniqueID = info->m_bShowMemoryUsage;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104933D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeElementPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeElementPickerPanel::GetMessageMap(CAttributeElementPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeElementPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeElementPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
  `CAttributeElementPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10493400
// Name: public: virtual struct PanelAnimationMap __near * CAttributeElementPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeElementPickerPanel::GetAnimMap(CAttributeElementPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeElementPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10493410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeElementPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeElementPickerPanel::GetKBMap(CAttributeElementPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeElementPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeElementPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPickerPanel");
  `CAttributeElementPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004971E0
// Name: public: virtual void CAttributeElementPickerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::OnCommand(CAttributeElementPickerPanel *this, const char *cmd)
{
  if ( _V_stricmp(s1: cmd, s2: "open") != 0 )
    vgui::Panel::OnCommand(this, command: cmd);
  else
    this->ShowPickerDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x004993A0
// Name: public: static char const __near * CAttributeElementPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeElementPickerPanel::GetPanelClassName()
{
  return "CAttributeElementPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004993B0
// Name: private: virtual class vgui::Panel __near * CAttributeElementPickerPanel::GetDataPanel(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextEntry *__thiscall CAttributeElementPickerPanel::GetDataPanel(CAttributeElementPickerPanel *this)
{
  return this->m_pData;
}

//------------------------------------------------------------------------------
// Address: 0x004993C0
// Name: public: virtual void CAttributeElementPickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::PerformLayout(CAttributeElementPickerPanel *this)
{
  vgui::IImage *v2; // edi
  vgui::DHANDLE<vgui::Button> *p_m_hEdit; // esi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  int viewWidth; // [esp+8h] [ebp-8h] BYREF
  int viewHeight; // [esp+Ch] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  v2 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_properties_linkarrow", a3: 0);
  if ( v2 != nullptr )
  {
    p_m_hEdit = &this->m_hEdit;
    v4 = vgui::PHandle::Get(this: p_m_hEdit);
    ((void (__thiscall *)(vgui::Panel *, vgui::IImage *, _DWORD))v4->__vftable[1].GetClassName)(a1: v4, a2: v2, a3: 0);
    v5 = vgui::PHandle::Get(this: p_m_hEdit);
    v5->SetPaintBorderEnabled(this: v5, a2: false);
    v6 = vgui::PHandle::Get(this: p_m_hEdit);
    ((void (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].IsWithinTraverse)(a1: v6, a2: 4);
    v7 = vgui::PHandle::Get(this: p_m_hEdit);
    vgui::Panel::SetBounds(this: v7, x: 6, y: (int)((double)(viewHeight - 16) * 0.5), wide: 16, tall: 16);
  }
  else
  {
    v8 = vgui::PHandle::Get(this: &this->m_hEdit);
    vgui::Panel::SetBounds(this: v8, x: 0, y: 0, wide: 100, tall: 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004994A0
// Name: private: virtual void CAttributeElementPickerPanel::OnDmeSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::OnDmeSelected(CAttributeElementPickerPanel *this, KeyValues *pKeyValues)
{
  int Int; // eax
  int v4; // eax
  CDmElement *v5; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: "dme", defaultValue: -1);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v5 = (CDmElement *)v4;
  if ( v4 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v5 = nullptr;
  }
  CBaseAttributePanel::SetAttributeValueElement(this, pElement: v5);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x00499500
// Name: private: virtual void CAttributeElementPickerPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::Refresh(CAttributeElementPickerPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v4; // eax
  CDmElement *AttributeValueElement; // eax
  CDmElement *v6; // esi
  bool v7; // zf
  const char *m_pAsString; // ebx
  int v9; // eax
  const char *v10; // esi
  double v11; // [esp+Ch] [ebp-23Ch]
  char elemText[512]; // [esp+20h] [ebp-228h] BYREF
  char idstr[40]; // [esp+220h] [ebp-28h] BYREF

  elemText[0] = 0;
  if ( CBaseAttributePanel::GetEditorInfo(this) == nullptr )
    goto LABEL_24;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  Attribute = CDmElement::FindAttribute(this: EditorInfo, pAttributeName: "hideText");
  v4 = Attribute != nullptr
     ? CDmAttribute::GetValue<bool>(this: Attribute)
     : &`CDmElement::GetValue<bool>'::`2'::defaultVal;
  if ( !v4->m_Storage )
  {
LABEL_24:
    if ( CBaseAttributePanel::HasAttribute(this) )
      AttributeValueElement = CBaseAttributePanel::GetAttributeValueElement(this);
    else
      AttributeValueElement = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hObject.m_handle);
    v6 = AttributeValueElement;
    if ( AttributeValueElement != nullptr )
    {
      v7 = !this->m_bShowUniqueID;
      memset(idstr, 0, 37);
      if ( !v7 )
        UniqueIdToString(id: &AttributeValueElement->m_Id, pBuf: idstr, nMaxLen: 37);
      if ( this->m_bShowMemoryUsage )
      {
        m_pAsString = v6->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        v11 = (float)((float)CDmElement::EstimateMemoryUsage(this: v6, depth: TD_NONE) * 0.0009765625);
        v9 = CDmElement::EstimateMemoryUsage(this: v6, depth: TD_DEEP);
        V_snprintf(
          pDest: elemText,
          maxLen: 512,
          pFormat: "%s %s (%.3fMB total / %.3fKB self)",
          m_pAsString,
          idstr,
          (float)((float)v9 * 0.00000095367432),
          v11);
      }
      else
      {
        v10 = v6->m_Type.u.m_pAsString;
        if ( v10 == (const char *)-1 )
          v10 = defaultValue;
        V_snprintf(pDest: elemText, maxLen: 512, pFormat: "%s %s", v10, idstr);
      }
    }
  }
  this->m_pData->SetText(this: this->m_pData, a2: elemText);
  this->m_pData->SetEditable(this: this->m_pData, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004996C0
// Name: public: static void CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DmeSelected";
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
// Address: 0x00499750
// Name: private: virtual void CAttributeElementPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPickerPanel::ShowPickerDialog(CAttributeElementPickerPanel *this)
{
  CAttributeElementPickerPanel *v1; // esi
  CDmeEditorChoicesInfo *EditorInfo; // eax
  IElementPropertiesChoices *v3; // edi
  DmElementHandle_t m_handle; // eax
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  int v6; // eax
  IElementPropertiesChoices_vtbl *v7; // edi
  const char *ChoiceType; // eax
  int v9; // edi
  int m_Size; // eax
  int v11; // esi
  DmePickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  const char *m_pChoiceString; // eax
  CDmePickerFrame *v15; // eax
  CDmePickerFrame *v16; // edi
  DmePickerInfo_t *v17; // eax
  ElementChoice_t *v18; // eax
  int v19; // [esp-10h] [ebp-54h]
  int v20; // [esp-8h] [ebp-4Ch]
  CUtlVector<ElementChoice_t,CUtlMemory<ElementChoice_t,int> > choices; // [esp+Ch] [ebp-38h] BYREF
  CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > vec; // [esp+20h] [ebp-24h] BYREF
  CAttributeElementPickerPanel *v23; // [esp+34h] [ebp-10h]
  IElementPropertiesChoices *v24; // [esp+38h] [ebp-Ch]
  CDmeEditorChoicesInfo *v25; // [esp+3Ch] [ebp-8h]
  int c; // [esp+40h] [ebp-4h]

  v1 = this;
  v23 = this;
  EditorInfo = (CDmeEditorChoicesInfo *)CBaseAttributePanel::GetEditorInfo(this);
  v25 = EditorInfo;
  if ( EditorInfo != nullptr && EditorInfo->IsA(this: EditorInfo, a2: CDmeEditorChoicesInfo::m_classType) )
  {
    memset(&choices, 0, sizeof(choices));
    memset((void *)&vec, 0, sizeof(vec));
    v3 = vgui::ElementPropertiesChoices();
    m_handle = v1->m_hObject.m_handle;
    LOBYTE(c) = v1->m_nArrayIndex >= 0;
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    v24 = v3;
    v6 = ((int (__thiscall *)(_DWORD, _DWORD))v5)(
           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
           a2: m_handle);
    v7 = v3->__vftable;
    v20 = c;
    v19 = v6;
    ChoiceType = CDmeEditorChoicesInfo::GetChoiceType(this: v25);
    if ( v7->GetElementChoiceList(
           this: v24,
           a2: ChoiceType,
           a3: (CDmElement *)v19,
           a4: v1->m_szAttributeName,
           a5: v20,
           a6: &choices) )
    {
      c = choices.m_Size;
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(this: &vec, num: choices.m_Size);
      v9 = 0;
      if ( c > 0 )
      {
        do
        {
          m_Size = vec.m_Size;
          v11 = vec.m_Size;
          if ( vec.m_Size + 1 > vec.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<MDLSquenceLayer_t,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&vec,
              num: vec.m_Size - vec.m_Memory.m_nAllocationCount + 1);
            m_Size = vec.m_Size;
          }
          m_pMemory = vec.m_Memory.m_pMemory;
          vec.m_Size = m_Size + 1;
          v13 = m_Size - v11;
          vec.m_pElements = vec.m_Memory.m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(dest: &vec.m_Memory.m_pMemory[v11 + 1], src: &vec.m_Memory.m_pMemory[v11], count: 8 * v13);
            m_pMemory = vec.m_Memory.m_pMemory;
          }
          m_pMemory[v11].m_hElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)choices.m_Memory.m_pMemory[v9].m_pValue);
          m_pChoiceString = choices.m_Memory.m_pMemory[v9++].m_pChoiceString;
          vec.m_Memory.m_pMemory[v11].m_pChoiceString = m_pChoiceString;
        }
        while ( v9 < c );
        v1 = v23;
      }
    }
    v15 = (CDmePickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v15 != nullptr )
      v16 = CDmePickerFrame::CDmePickerFrame(this: v15, pParent: v1, pTitle: "Select DME Element");
    else
      v16 = nullptr;
    v16->AddActionSignalTarget_2(this: v16, a2: v1);
    CDmePickerFrame::DoModal(this: v16, &vec, pKeyValues: nullptr);
    v17 = vec.m_Memory.m_pMemory;
    vec.m_Size = 0;
    if ( vec.m_Memory.m_nGrowSize >= 0 )
    {
      if ( vec.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_Memory.m_pMemory);
        v17 = nullptr;
        vec.m_Memory.m_pMemory = nullptr;
      }
      vec.m_Memory.m_nAllocationCount = 0;
    }
    vec.m_pElements = v17;
    if ( vec.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v17 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
        vec.m_Memory.m_pMemory = nullptr;
      }
      vec.m_Memory.m_nAllocationCount = 0;
    }
    v18 = choices.m_Memory.m_pMemory;
    choices.m_Size = 0;
    if ( choices.m_Memory.m_nGrowSize >= 0 )
    {
      if ( choices.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: choices.m_Memory.m_pMemory);
        v18 = nullptr;
        choices.m_Memory.m_pMemory = nullptr;
      }
      choices.m_Memory.m_nAllocationCount = 0;
    }
    choices.m_pElements = v18;
    if ( choices.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499960
// Name: public: CAttributeElementPickerPanel::CAttributeElementPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPickerPanel *__thiscall CAttributeElementPickerPanel::CAttributeElementPickerPanel(
        CAttributeElementPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  CAttributeTextEntry *v9; // eax
  CAttributeTextEntry *v10; // eax
  BOOL v11; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CAttributeElementPickerPanel_vtbl *)&CAttributeElementPickerPanel::`vftable';
  if ( `CAttributeElementPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
    v4->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeElementPickerPanel");
    v5->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPickerPanel");
    v6->pfnClassName = CAttributeElementPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeElementPickerPanel::PanelMessageFunc_OnDmeSelected::InitVar(a1: (int)&savedregs);
  this->m_hEdit.m_iPanelID = -1;
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "Open",
           text: "...",
           pActionSignalTarget: this,
           pCmd: "open");
  else
    v8 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEdit, pPanel: v8);
  v9 = (CAttributeTextEntry *)MemAlloc_Alloc(nSize: 0x848u);
  if ( v9 != nullptr )
    v10 = CAttributeTextEntry::CAttributeTextEntry(this: v9, parent: this, panelName: "AttributeValue");
  else
    v10 = nullptr;
  v11 = (this->m_nFlags & 4) == 0;
  this->m_pData = v10;
  v10->SetEnabled(this: v10, a2: v11);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  this->m_pType->SetText_2(this: this->m_pType, a2: "element");
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  this->m_bShowUniqueID = info->m_bShowMemoryUsage;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00499AF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeElementPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeElementPickerPanel::GetMessageMap(CAttributeElementPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeElementPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeElementPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPickerPanel");
  `CAttributeElementPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00499B20
// Name: public: virtual struct PanelAnimationMap __near * CAttributeElementPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeElementPickerPanel::GetAnimMap(CAttributeElementPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeElementPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00499B30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeElementPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeElementPickerPanel::GetKBMap(CAttributeElementPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeElementPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeElementPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPickerPanel");
  `CAttributeElementPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
