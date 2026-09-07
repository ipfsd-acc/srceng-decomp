// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseattributechoicepanel.cpp
// Functions: 11
// ============================================================

#include "vgui2\dme_controls\baseattributechoicepanel.h"

//------------------------------------------------------------------------------
// Address: 0x004802F0
// Name: public: static char const __near * CBaseAttributeChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributeChoicePanel::GetPanelClassName()
{
  return "CBaseAttributeChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00480300
// Name: public: virtual void CBaseAttributeChoicePanel::PostConstructor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::PostConstructor(CBaseAttributeChoicePanel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->PopulateComboBox(this, a2: this->m_pData);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x00480330
// Name: public: virtual void CBaseAttributeChoicePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::ApplySchemeSettings(CBaseAttributeChoicePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al
  unsigned int v5; // eax

  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  v5 = v3->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v4);
  this->m_pData->SetFont(this: this->m_pData, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00480380
// Name: private: virtual void CBaseAttributeChoicePanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::Apply(CBaseAttributeChoicePanel *this)
{
  KeyValues *ActiveItemUserData; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pData);
  this->SetAttributeFromComboBox(this, a2: this->m_pData, a3: ActiveItemUserData);
}

//------------------------------------------------------------------------------
// Address: 0x004803B0
// Name: protected: virtual void CBaseAttributeChoicePanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::Refresh(CBaseAttributeChoicePanel *this)
{
  this->SetComboBoxFromAttribute(this, a2: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x004803D0
// Name: private: virtual void CBaseAttributeChoicePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::OnTextChanged(CBaseAttributeChoicePanel *this, vgui::Panel *panel)
{
  if ( (this->m_nFlags & 0x10) != 0 )
    this->Apply(this);
  else
    CBaseAttributePanel::SetDirty(this, dirty: true);
}

//------------------------------------------------------------------------------
// Address: 0x00480400
// Name: public: static void CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004804A0
// Name: public: CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributeChoicePanel *__thiscall CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(
        CBaseAttributeChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  BOOL v9; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CBaseAttributeChoicePanel_vtbl *)&CBaseAttributeChoicePanel::`vftable';
  if ( `CBaseAttributeChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
    v4->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
    v5->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
    v6->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  vgui::Panel::SetDropEnabled(this, enabled: false, flHoverContextTime: 0.0);
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "AttributeValue", numLines: 10, allowEdit: false);
  else
    v8 = nullptr;
  v9 = (this->m_nFlags & 0x20) == 0;
  this->m_pData = v8;
  v8->SetEnabled(this: v8, a2: v9);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004805E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributeChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributeChoicePanel::GetMessageMap(CBaseAttributeChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributeChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributeChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  `CBaseAttributeChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480610
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributeChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributeChoicePanel::GetAnimMap(CBaseAttributeChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00480620
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributeChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributeChoicePanel::GetKBMap(CBaseAttributeChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributeChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeChoicePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributeChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  `CBaseAttributeChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104A35C0
// Name: public: static char const __near * CBaseAttributeChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributeChoicePanel::GetPanelClassName()
{
  return "CBaseAttributeChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x104A35D0
// Name: public: virtual void CBaseAttributeChoicePanel::PostConstructor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::PostConstructor(CBaseAttributeChoicePanel *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->PopulateComboBox(this, a2: this->m_pData);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A3600
// Name: public: virtual void CBaseAttributeChoicePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::ApplySchemeSettings(CBaseAttributeChoicePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al
  unsigned int v5; // eax

  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  v5 = v3->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v4);
  this->m_pData->SetFont(this: this->m_pData, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x104A3650
// Name: private: virtual void CBaseAttributeChoicePanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::Apply(CBaseAttributeChoicePanel *this)
{
  KeyValues *ActiveItemUserData; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pData);
  this->SetAttributeFromComboBox(this, a2: this->m_pData, a3: ActiveItemUserData);
}

//------------------------------------------------------------------------------
// Address: 0x104A3680
// Name: protected: virtual void CBaseAttributeChoicePanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::Refresh(CBaseAttributeChoicePanel *this)
{
  this->SetComboBoxFromAttribute(this, a2: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x104A36A0
// Name: private: virtual void CBaseAttributeChoicePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::OnTextChanged(CBaseAttributeChoicePanel *this, vgui::Panel *panel)
{
  if ( (this->m_nFlags & 0x10) != 0 )
    this->Apply(this);
  else
    CBaseAttributePanel::SetDirty(this, dirty: true);
}

//------------------------------------------------------------------------------
// Address: 0x104A36D0
// Name: public: static void CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A3770
// Name: public: CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributeChoicePanel *__userpurge CBaseAttributeChoicePanel::CBaseAttributeChoicePanel@<eax>(
        CBaseAttributeChoicePanel *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Panel *parent,
        vgui::Panel *info)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  BOOL v10; // ecx
  int _C; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, a2, parent, (const AttributeWidgetInfo_t *)info);
  this->__vftable = (CBaseAttributeChoicePanel_vtbl *)&CBaseAttributeChoicePanel::`vftable';
  if ( `CBaseAttributeChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
    v5->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
    v6->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
    v7->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&_C);
  this->m_pData = nullptr;
  vgui::Panel::SetDropEnabled(this, enabled: false, flHoverContextTime: 0.0);
  v8 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(
           this: v8,
           parent: this,
           panelName: (vgui::Panel *)"AttributeValue",
           numLines: 10,
           allowEdit: false);
  else
    v9 = nullptr;
  v10 = (this->m_nFlags & 0x20) == 0;
  this->m_pData = v9;
  v9->SetEnabled(this: v9, a2: v10);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A38B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributeChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributeChoicePanel::GetMessageMap(CBaseAttributeChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributeChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributeChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  `CBaseAttributeChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A38E0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributeChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributeChoicePanel::GetAnimMap(CBaseAttributeChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x104A38F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributeChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributeChoicePanel::GetKBMap(CBaseAttributeChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributeChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeChoicePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributeChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  `CBaseAttributeChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004A3D10
// Name: public: static char const __near * CBaseAttributeChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributeChoicePanel::GetPanelClassName()
{
  return "CBaseAttributeChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004A3D20
// Name: public: virtual void CBaseAttributeChoicePanel::PostConstructor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::PostConstructor(CBaseAttributeChoicePanel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->PopulateComboBox(this, a2: this->m_pData);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A3D50
// Name: public: virtual void CBaseAttributeChoicePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::ApplySchemeSettings(CBaseAttributeChoicePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al
  unsigned int v5; // eax

  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  v5 = v3->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v4);
  this->m_pData->SetFont(this: this->m_pData, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004A3DA0
// Name: private: virtual void CBaseAttributeChoicePanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::Apply(CBaseAttributeChoicePanel *this)
{
  KeyValues *ActiveItemUserData; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pData);
  this->SetAttributeFromComboBox(this, a2: this->m_pData, a3: ActiveItemUserData);
}

//------------------------------------------------------------------------------
// Address: 0x004A3DD0
// Name: protected: virtual void CBaseAttributeChoicePanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::Refresh(CBaseAttributeChoicePanel *this)
{
  this->SetComboBoxFromAttribute(this, a2: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x004A3DF0
// Name: private: virtual void CBaseAttributeChoicePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeChoicePanel::OnTextChanged(CBaseAttributeChoicePanel *this, vgui::Panel *panel)
{
  if ( (this->m_nFlags & 0x10) != 0 )
    this->Apply(this);
  else
    CBaseAttributePanel::SetDirty(this, dirty: true);
}

//------------------------------------------------------------------------------
// Address: 0x004A3E20
// Name: public: static void CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A3EC0
// Name: public: CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributeChoicePanel *__thiscall CBaseAttributeChoicePanel::CBaseAttributeChoicePanel(
        CBaseAttributeChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  BOOL v9; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CBaseAttributeChoicePanel_vtbl *)&CBaseAttributeChoicePanel::`vftable';
  if ( `CBaseAttributeChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
    v4->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
    v5->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
    v6->pfnClassName = CBaseAttributeChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CBaseAttributeChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  vgui::Panel::SetDropEnabled(this, enabled: false, flHoverContextTime: 0.0);
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "AttributeValue", numLines: 10, allowEdit: false);
  else
    v8 = nullptr;
  v9 = (this->m_nFlags & 0x20) == 0;
  this->m_pData = v8;
  v8->SetEnabled(this: v8, a2: v9);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A4000
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributeChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributeChoicePanel::GetMessageMap(CBaseAttributeChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributeChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributeChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeChoicePanel");
  `CBaseAttributeChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A4030
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributeChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributeChoicePanel::GetAnimMap(CBaseAttributeChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributeChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004A4040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributeChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributeChoicePanel::GetKBMap(CBaseAttributeChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributeChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeChoicePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributeChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeChoicePanel");
  `CBaseAttributeChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
