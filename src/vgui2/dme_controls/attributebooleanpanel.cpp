// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributebooleanpanel.cpp
// Functions: 12
// ============================================================

#include "vgui2\dme_controls\attributebooleanpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046B230
// Name: public: static char const __near * CAttributeBooleanPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBooleanPanel::GetPanelClassName()
{
  return "CAttributeBooleanPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046B240
// Name: public: virtual void CAttributeBooleanPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::ApplySchemeSettings(CAttributeBooleanPanel *this, vgui::IScheme *pScheme)
{
  vgui::CheckButton *m_pValueButton; // ecx
  vgui::CheckButton_vtbl *v4; // edi
  int v5; // eax

  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  this->m_pValueButton->SetBorder(this: this->m_pValueButton, a2: nullptr);
  this->m_pValueButton->SetPaintBorderEnabled(this: this->m_pValueButton, a2: false);
  m_pValueButton = this->m_pValueButton;
  v4 = m_pValueButton->__vftable;
  v5 = ((int (__stdcall *)(_DWORD, _DWORD))m_pValueButton->GetImageAtIndex)(a1: 0, a2: 0);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, int))v4->SetImageAtIndex)(a1: this->m_pValueButton, a2: 0, a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0046B2B0
// Name: public: virtual void CAttributeBooleanPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::PerformLayout(CAttributeBooleanPanel *this)
{
  int viewWidth; // [esp+4h] [ebp-8h] BYREF
  int viewHeight; // [esp+8h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  vgui::Panel::SetBounds(
    this: this->m_pValueButton,
    x: 6,
    y: (int)((double)(viewHeight - 16) * 0.5),
    wide: 16,
    tall: 16);
}

//------------------------------------------------------------------------------
// Address: 0x0046B300
// Name: public: bool const __near & CBaseAttributePanel::GetAttributeValue<bool>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<bool> *__thiscall CBaseAttributePanel::GetAttributeValue<bool>(CBaseAttributePanel *this)
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
      CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>>::Init(
        this: (CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<bool> *)((char *)v6.m_pStorage->m_Memory.m_pMemory + m_nArrayIndex);
    }
    else
    {
      return CDmElement::GetValue<bool>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<bool>'::`5'::temp = false;
    return (CDmaVar<bool> *)&`CBaseAttributePanel::GetAttributeValue<bool>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B380
// Name: public: void CBaseAttributePanel::SetAttributeValue<int>(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<int>(CBaseAttributePanel *this, int *value)
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
    CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
      this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v9,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B430
// Name: public: static void CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B4D0
// Name: public: virtual void CAttributeBooleanPanel::OnCheckButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::OnCheckButtonChecked(CAttributeBooleanPanel *this, int state)
{
  CDmaVar<bool> *Attribute; // eax

  Attribute = CBaseAttributePanel::GetAttributeValue<bool>(this);
  if ( (state == 1) != Attribute->m_Storage )
  {
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &state);
    this->Refresh(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B510
// Name: public: virtual void CAttributeBooleanPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::Refresh(CAttributeBooleanPanel *this)
{
  bool myValue; // [esp+8h] [ebp-4h]

  CAttributeTextPanel::Refresh(this);
  myValue = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
  if ( myValue != this->m_pValueButton->IsSelected(this: this->m_pValueButton) )
    this->m_pValueButton->SetSelected(this: this->m_pValueButton, a2: myValue);
}

//------------------------------------------------------------------------------
// Address: 0x0046B560
// Name: public: CAttributeBooleanPanel::CAttributeBooleanPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBooleanPanel *__thiscall CAttributeBooleanPanel::CAttributeBooleanPanel(
        CAttributeBooleanPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeBooleanPanel_vtbl *)&CAttributeBooleanPanel::`vftable';
  if ( `CAttributeBooleanPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
    v4->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBooleanPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBooleanPanel");
    v5->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBooleanPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBooleanPanel");
    v6->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  v7 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(this: v7, parent: this, panelName: defaultValue, text: defaultValue);
  else
    v8 = nullptr;
  this->m_pValueButton = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046B660
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBooleanPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBooleanPanel::GetMessageMap(CAttributeBooleanPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBooleanPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBooleanPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBooleanPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
  `CAttributeBooleanPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046B690
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBooleanPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBooleanPanel::GetAnimMap(CAttributeBooleanPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBooleanPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046B6A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBooleanPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBooleanPanel::GetKBMap(CAttributeBooleanPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBooleanPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBooleanPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBooleanPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBooleanPanel");
  `CAttributeBooleanPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1048E6A0
// Name: public: static char const __near * CAttributeBooleanPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBooleanPanel::GetPanelClassName()
{
  return "CAttributeBooleanPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1048E6B0
// Name: public: virtual void CAttributeBooleanPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::ApplySchemeSettings(CAttributeBooleanPanel *this, vgui::IScheme *pScheme)
{
  vgui::CheckButton *m_pValueButton; // ecx
  vgui::CheckButton_vtbl *v4; // edi
  int v5; // eax

  CBaseAttributePanel::ApplySchemeSettings(this, pScheme);
  this->m_pValueButton->SetBorder(this: this->m_pValueButton, a2: nullptr);
  this->m_pValueButton->SetPaintBorderEnabled(this: this->m_pValueButton, a2: false);
  m_pValueButton = this->m_pValueButton;
  v4 = m_pValueButton->__vftable;
  v5 = ((int (__stdcall *)(_DWORD, _DWORD))m_pValueButton->GetImageAtIndex)(a1: 0, a2: 0);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, int))v4->SetImageAtIndex)(a1: this->m_pValueButton, a2: 0, a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1048E720
// Name: public: virtual void CAttributeBooleanPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::PerformLayout(CAttributeBooleanPanel *this)
{
  int viewWidth; // [esp+4h] [ebp-8h] BYREF
  int viewHeight; // [esp+8h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  vgui::Panel::SetBounds(
    this: this->m_pValueButton,
    x: 6,
    y: (int)((double)(viewHeight - 16) * 0.5),
    wide: 16,
    tall: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1048E780
// Name: public: bool const __near & CBaseAttributePanel::GetAttributeValue<bool>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<bool> *__thiscall CBaseAttributePanel::GetAttributeValue<bool>(CBaseAttributePanel *this)
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
      CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>>::Init(
        this: (CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<bool> *)((char *)v6.m_pStorage->m_Memory.m_pMemory + m_nArrayIndex);
    }
    else
    {
      return CDmElement::GetValue<bool>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<bool>'::`5'::temp = false;
    return (CDmaVar<bool> *)&`CBaseAttributePanel::GetAttributeValue<bool>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048E800
// Name: public: void CBaseAttributePanel::SetAttributeValue<int>(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<int>(CBaseAttributePanel *this, int *value)
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
    CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v12,
      pElement: v10,
      pAttributeName: m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
      this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v12,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    v6 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: m_szAttributeName, type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: Attribute, value);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x1048E8D0
// Name: public: static void CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048E970
// Name: public: virtual void CAttributeBooleanPanel::OnCheckButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::OnCheckButtonChecked(CAttributeBooleanPanel *this, int state)
{
  CDmaVar<bool> *Attribute; // eax

  Attribute = CBaseAttributePanel::GetAttributeValue<bool>(this);
  if ( (state == 1) != Attribute->m_Storage )
  {
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &state);
    this->Refresh(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048E9B0
// Name: public: virtual void CAttributeBooleanPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::Refresh(CAttributeBooleanPanel *this)
{
  bool myValue; // [esp+8h] [ebp-4h]

  CAttributeTextPanel::Refresh(this);
  myValue = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
  if ( myValue != this->m_pValueButton->IsSelected(this: this->m_pValueButton) )
    this->m_pValueButton->SetSelected(this: this->m_pValueButton, a2: myValue);
}

//------------------------------------------------------------------------------
// Address: 0x1048EA00
// Name: public: CAttributeBooleanPanel::CAttributeBooleanPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBooleanPanel *__thiscall CAttributeBooleanPanel::CAttributeBooleanPanel(
        CAttributeBooleanPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeBooleanPanel_vtbl *)&CAttributeBooleanPanel::`vftable';
  if ( `CAttributeBooleanPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
    v4->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBooleanPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBooleanPanel");
    v5->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBooleanPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBooleanPanel");
    v6->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  v7 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(this: v7, parent: this, panelName: &var, text: &var);
  else
    v8 = nullptr;
  this->m_pValueButton = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1048EB00
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBooleanPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBooleanPanel::GetMessageMap(CAttributeBooleanPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBooleanPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBooleanPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBooleanPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
  `CAttributeBooleanPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048EB30
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBooleanPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBooleanPanel::GetAnimMap(CAttributeBooleanPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBooleanPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1048EB40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBooleanPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBooleanPanel::GetKBMap(CAttributeBooleanPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBooleanPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBooleanPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBooleanPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBooleanPanel");
  `CAttributeBooleanPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00494DB0
// Name: public: static char const __near * CAttributeBooleanPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBooleanPanel::GetPanelClassName()
{
  return "CAttributeBooleanPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00494DC0
// Name: public: virtual void CAttributeBooleanPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::ApplySchemeSettings(CAttributeBooleanPanel *this, vgui::IScheme *pScheme)
{
  vgui::CheckButton *m_pValueButton; // ecx
  vgui::CheckButton_vtbl *v4; // edi
  int v5; // eax

  CBaseAttributePanel::ApplySchemeSettings(this, pScheme);
  this->m_pValueButton->SetBorder(this: this->m_pValueButton, a2: nullptr);
  this->m_pValueButton->SetPaintBorderEnabled(this: this->m_pValueButton, a2: false);
  m_pValueButton = this->m_pValueButton;
  v4 = m_pValueButton->__vftable;
  v5 = ((int (__stdcall *)(_DWORD, _DWORD))m_pValueButton->GetImageAtIndex)(a1: 0, a2: 0);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, int))v4->SetImageAtIndex)(a1: this->m_pValueButton, a2: 0, a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00494E30
// Name: public: virtual void CAttributeBooleanPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::PerformLayout(CAttributeBooleanPanel *this)
{
  int viewWidth; // [esp+4h] [ebp-8h] BYREF
  int viewHeight; // [esp+8h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  vgui::Panel::SetBounds(
    this: this->m_pValueButton,
    x: 6,
    y: (int)((double)(viewHeight - 16) * 0.5),
    wide: 16,
    tall: 16);
}

//------------------------------------------------------------------------------
// Address: 0x00494E80
// Name: public: bool const __near & CBaseAttributePanel::GetAttributeValue<bool>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<bool> *__thiscall CBaseAttributePanel::GetAttributeValue<bool>(CBaseAttributePanel *this)
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
      CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int>>>>>::Init(
        this: (CDmrDecorator<bool,CDmaArrayBase<bool,CDmaDataExternal<CUtlVector<bool,CUtlMemory<bool,int> > > > > *)&v6,
        pElement: v3,
        pAttributeName: this->m_szAttributeName,
        bAddAttribute: false);
      return (CDmaVar<bool> *)((char *)v6.m_pStorage->m_Memory.m_pMemory + m_nArrayIndex);
    }
    else
    {
      return CDmElement::GetValue<bool>(this: v2, pAttributeName: this->m_szAttributeName);
    }
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<bool>'::`5'::temp = false;
    return (CDmaVar<bool> *)&`CBaseAttributePanel::GetAttributeValue<bool>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494F00
// Name: public: void CBaseAttributePanel::SetAttributeValue<int>(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<int>(CBaseAttributePanel *this, const int *value)
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
    CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
      this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v9,
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
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494FB0
// Name: public: static void CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495050
// Name: public: virtual void CAttributeBooleanPanel::OnCheckButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::OnCheckButtonChecked(CAttributeBooleanPanel *this, int state)
{
  CDmaVar<bool> *Attribute; // eax

  Attribute = CBaseAttributePanel::GetAttributeValue<bool>(this);
  if ( (state == 1) != Attribute->m_Storage )
  {
    CBaseAttributePanel::SetAttributeValue<int>(this, value: &state);
    this->Refresh(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495090
// Name: public: virtual void CAttributeBooleanPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBooleanPanel::Refresh(CAttributeBooleanPanel *this)
{
  bool myValue; // [esp+8h] [ebp-4h]

  CAttributeTextPanel::Refresh(this);
  myValue = CBaseAttributePanel::GetAttributeValue<bool>(this)->m_Storage;
  if ( myValue != this->m_pValueButton->IsSelected(this: this->m_pValueButton) )
    this->m_pValueButton->SetSelected(this: this->m_pValueButton, a2: myValue);
}

//------------------------------------------------------------------------------
// Address: 0x004950E0
// Name: public: CAttributeBooleanPanel::CAttributeBooleanPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBooleanPanel *__thiscall CAttributeBooleanPanel::CAttributeBooleanPanel(
        CAttributeBooleanPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeBooleanPanel_vtbl *)&CAttributeBooleanPanel::`vftable';
  if ( `CAttributeBooleanPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
    v4->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBooleanPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBooleanPanel");
    v5->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBooleanPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBooleanPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBooleanPanel");
    v6->pfnClassName = CAttributeBooleanPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  CAttributeBooleanPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  v7 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(this: v7, parent: this, panelName: defaultValue, text: defaultValue);
  else
    v8 = nullptr;
  this->m_pValueButton = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004951E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBooleanPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBooleanPanel::GetMessageMap(CAttributeBooleanPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBooleanPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBooleanPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBooleanPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBooleanPanel");
  `CAttributeBooleanPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495210
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBooleanPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBooleanPanel::GetAnimMap(CAttributeBooleanPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBooleanPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00495220
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBooleanPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBooleanPanel::GetKBMap(CAttributeBooleanPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBooleanPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBooleanPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBooleanPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBooleanPanel");
  `CAttributeBooleanPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
