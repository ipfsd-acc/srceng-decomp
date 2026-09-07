// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseattributedoublechoicepanel.cpp
// Functions: 18
// ============================================================

#include "vgui2\dme_controls\baseattributedoublechoicepanel.h"

//------------------------------------------------------------------------------
// Address: 0x004828B0
// Name: public: static char const __near * CDoubleComboBoxContainerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDoubleComboBoxContainerPanel::GetPanelClassName()
{
  return "CDoubleComboBoxContainerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004828C0
// Name: public: static char const __near * CBaseAttributeDoubleChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributeDoubleChoicePanel::GetPanelClassName()
{
  return "CBaseAttributeDoubleChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004828D0
// Name: private: virtual void CDoubleComboBoxContainerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDoubleComboBoxContainerPanel::PerformLayout(CDoubleComboBoxContainerPanel *this)
{
  vgui::ComboBox *v2; // ecx
  vgui::ComboBox *v3; // ecx
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v2 = this->m_pBoxes[0];
  if ( v2 != nullptr )
    vgui::Panel::SetBounds(this: v2, x: 0, y: 0, wide: w / 2, tall: h);
  v3 = this->m_pBoxes[1];
  if ( v3 != nullptr )
    vgui::Panel::SetBounds(this: v3, x: w / 2, y: 0, wide: w / 2, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x00482940
// Name: public: virtual void CBaseAttributeDoubleChoicePanel::PostConstructor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::PostConstructor(CBaseAttributeDoubleChoicePanel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->PopulateComboBoxes(this, a2: this->m_pData);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482970
// Name: public: virtual void CBaseAttributeDoubleChoicePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::ApplySchemeSettings(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al
  unsigned int v5; // edi

  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  v5 = v3->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v4);
  this->m_pData[0]->SetFont(this: this->m_pData[0], a2: v5);
  this->m_pData[1]->SetFont(this: this->m_pData[1], a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004829D0
// Name: private: virtual class vgui::Panel __near * CBaseAttributeDoubleChoicePanel::GetDataPanel(void)
// Source: json
//------------------------------------------------------------------------------
CDoubleComboBoxContainerPanel *__thiscall CBaseAttributeDoubleChoicePanel::GetDataPanel(
        CBaseAttributeDoubleChoicePanel *this)
{
  return this->m_pContainerPanel;
}

//------------------------------------------------------------------------------
// Address: 0x004829E0
// Name: private: virtual void CBaseAttributeDoubleChoicePanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::Apply(CBaseAttributeDoubleChoicePanel *this)
{
  KeyValues *ActiveItemUserData; // eax
  vgui::ComboBox *v3; // ecx
  KeyValues *kv[2]; // [esp+8h] [ebp-8h] BYREF

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pData[0]);
  v3 = this->m_pData[1];
  kv[0] = ActiveItemUserData;
  kv[1] = vgui::ComboBox::GetActiveItemUserData(this: v3);
  this->SetAttributeFromComboBoxes(this, a2: this->m_pData, a3: kv);
}

//------------------------------------------------------------------------------
// Address: 0x00482A30
// Name: protected: virtual void CBaseAttributeDoubleChoicePanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::Refresh(CBaseAttributeDoubleChoicePanel *this)
{
  ((void (__stdcall *)(vgui::ComboBox **))this->SetComboBoxesFromAttribute)(a1: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x00482A50
// Name: private: virtual void CBaseAttributeDoubleChoicePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::OnTextChanged(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::Panel *panel)
{
  CBaseAttributePanel::SetDirty(this, dirty: true);
  if ( (this->m_nFlags & 0x10) != 0 )
    this->Apply(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482A80
// Name: public: CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDoubleComboBoxContainerPanel *__thiscall CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(
        CDoubleComboBoxContainerPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CDoubleComboBoxContainerPanel_vtbl *)&CDoubleComboBoxContainerPanel::`vftable';
  if ( `CDoubleComboBoxContainerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDoubleComboBoxContainerPanel");
    v4->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CDoubleComboBoxContainerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDoubleComboBoxContainerPanel");
    v5->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CDoubleComboBoxContainerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDoubleComboBoxContainerPanel");
    v6->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_pBoxes[1] = nullptr;
  this->m_pBoxes[0] = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00482B50
// Name: public: virtual struct vgui::PanelMessageMap __near * CDoubleComboBoxContainerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDoubleComboBoxContainerPanel::GetMessageMap(CDoubleComboBoxContainerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::s_pMap;
  `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDoubleComboBoxContainerPanel");
  `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482B80
// Name: public: virtual struct PanelAnimationMap __near * CDoubleComboBoxContainerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDoubleComboBoxContainerPanel::GetAnimMap(CDoubleComboBoxContainerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDoubleComboBoxContainerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00482B90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDoubleComboBoxContainerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDoubleComboBoxContainerPanel::GetKBMap(CDoubleComboBoxContainerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDoubleComboBoxContainerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::s_pMap;
  `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDoubleComboBoxContainerPanel");
  `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482BC0
// Name: public: static void CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
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
// Address: 0x00482C60
// Name: public: CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributeDoubleChoicePanel *__thiscall CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDoubleComboBoxContainerPanel *v7; // eax
  CDoubleComboBoxContainerPanel *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  BOOL v11; // ecx
  vgui::ComboBox *v12; // eax
  vgui::ComboBox *v13; // eax
  BOOL v14; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CBaseAttributeDoubleChoicePanel_vtbl *)&CBaseAttributeDoubleChoicePanel::`vftable';
  if ( `CBaseAttributeDoubleChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
    v4->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeDoubleChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
    v5->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeDoubleChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
    v6->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetDropEnabled(this, enabled: false, flHoverContextTime: 0.0);
  v7 = (CDoubleComboBoxContainerPanel *)MemAlloc_Alloc(nSize: 0x158u);
  if ( v7 != nullptr )
    v8 = CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(this: v7, parent: this, name: "Container");
  else
    v8 = nullptr;
  this->m_pContainerPanel = v8;
  v9 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(
            this: v9,
            parent: this->m_pContainerPanel,
            panelName: "AttributeValue",
            numLines: 10,
            allowEdit: false);
  else
    v10 = nullptr;
  v11 = (this->m_nFlags & 0x20) == 0;
  this->m_pData[0] = v10;
  v10->SetEnabled(this: v10, a2: v11);
  this->m_pData[0]->AddActionSignalTarget_2(this: this->m_pData[0], a2: this);
  this->m_pContainerPanel->m_pBoxes[0] = this->m_pData[0];
  v12 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v12 != nullptr )
    v13 = vgui::ComboBox::ComboBox(
            this: v12,
            parent: this->m_pContainerPanel,
            panelName: "AttributeValue",
            numLines: 10,
            allowEdit: false);
  else
    v13 = nullptr;
  v14 = (this->m_nFlags & 0x20) == 0;
  this->m_pData[1] = v13;
  v13->SetEnabled(this: v13, a2: v14);
  this->m_pData[1]->AddActionSignalTarget_2(this: this->m_pData[1], a2: this);
  this->m_pContainerPanel->m_pBoxes[1] = this->m_pData[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00482E50
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributeDoubleChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributeDoubleChoicePanel::GetMessageMap(CBaseAttributeDoubleChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
  `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482E80
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributeDoubleChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributeDoubleChoicePanel::GetAnimMap(CBaseAttributeDoubleChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00482E90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributeDoubleChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributeDoubleChoicePanel::GetKBMap(CBaseAttributeDoubleChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
  `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1048DDC0
// Name: private: virtual class vgui::Panel __near * CBaseAttributeDoubleChoicePanel::GetDataPanel(void)
// Source: json
//------------------------------------------------------------------------------
CDoubleComboBoxContainerPanel *__thiscall CBaseAttributeDoubleChoicePanel::GetDataPanel(
        CBaseAttributeDoubleChoicePanel *this)
{
  return this->m_pContainerPanel;
}

//------------------------------------------------------------------------------
// Address: 0x104A5A90
// Name: public: static char const __near * CDoubleComboBoxContainerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDoubleComboBoxContainerPanel::GetPanelClassName()
{
  return "CDoubleComboBoxContainerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104A5AA0
// Name: public: static char const __near * CBaseAttributeDoubleChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributeDoubleChoicePanel::GetPanelClassName()
{
  return "CBaseAttributeDoubleChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x104A5AB0
// Name: private: virtual void CDoubleComboBoxContainerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDoubleComboBoxContainerPanel::PerformLayout(CDoubleComboBoxContainerPanel *this)
{
  vgui::ComboBox *v2; // ecx
  vgui::ComboBox *v3; // ecx
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v2 = this->m_pBoxes[0];
  if ( v2 != nullptr )
    vgui::Panel::SetBounds(this: v2, x: 0, y: 0, wide: w / 2, tall: h);
  v3 = this->m_pBoxes[1];
  if ( v3 != nullptr )
    vgui::Panel::SetBounds(this: v3, x: w / 2, y: 0, wide: w / 2, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x104A5B20
// Name: public: virtual void CBaseAttributeDoubleChoicePanel::PostConstructor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::PostConstructor(CBaseAttributeDoubleChoicePanel *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->PopulateComboBoxes(this, a2: this->m_pData);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A5B50
// Name: public: virtual void CBaseAttributeDoubleChoicePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::ApplySchemeSettings(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al
  unsigned int v5; // edi

  CBaseAttributePanel::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  v5 = v3->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v4);
  this->m_pData[0]->SetFont(this: this->m_pData[0], a2: v5);
  this->m_pData[1]->SetFont(this: this->m_pData[1], a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x104A5BB0
// Name: private: virtual void CBaseAttributeDoubleChoicePanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::Apply(CBaseAttributeDoubleChoicePanel *this)
{
  KeyValues *ActiveItemUserData; // eax
  vgui::ComboBox *v3; // ecx
  KeyValues *kv[2]; // [esp+8h] [ebp-8h] BYREF

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pData[0]);
  v3 = this->m_pData[1];
  kv[0] = ActiveItemUserData;
  kv[1] = vgui::ComboBox::GetActiveItemUserData(this: v3);
  this->SetAttributeFromComboBoxes(this, a2: this->m_pData, a3: kv);
}

//------------------------------------------------------------------------------
// Address: 0x104A5C00
// Name: protected: virtual void CBaseAttributeDoubleChoicePanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::Refresh(CBaseAttributeDoubleChoicePanel *this)
{
  ((void (__stdcall *)(vgui::ComboBox **))this->SetComboBoxesFromAttribute)(a1: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x104A5C20
// Name: private: virtual void CBaseAttributeDoubleChoicePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::OnTextChanged(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::Panel *panel)
{
  CBaseAttributePanel::SetDirty(this, dirty: true);
  if ( (this->m_nFlags & 0x10) != 0 )
    this->Apply(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A5C50
// Name: public: CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDoubleComboBoxContainerPanel *__thiscall CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(
        CDoubleComboBoxContainerPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CDoubleComboBoxContainerPanel_vtbl *)&CDoubleComboBoxContainerPanel::`vftable';
  if ( `CDoubleComboBoxContainerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDoubleComboBoxContainerPanel");
    v4->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CDoubleComboBoxContainerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDoubleComboBoxContainerPanel");
    v5->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CDoubleComboBoxContainerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDoubleComboBoxContainerPanel");
    v6->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_pBoxes[1] = nullptr;
  this->m_pBoxes[0] = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A5D20
// Name: public: virtual struct vgui::PanelMessageMap __near * CDoubleComboBoxContainerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDoubleComboBoxContainerPanel::GetMessageMap(CDoubleComboBoxContainerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::s_pMap;
  `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDoubleComboBoxContainerPanel");
  `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A5D50
// Name: public: virtual struct PanelAnimationMap __near * CDoubleComboBoxContainerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDoubleComboBoxContainerPanel::GetAnimMap(CDoubleComboBoxContainerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDoubleComboBoxContainerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104A5D60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDoubleComboBoxContainerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDoubleComboBoxContainerPanel::GetKBMap(CDoubleComboBoxContainerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDoubleComboBoxContainerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::s_pMap;
  `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDoubleComboBoxContainerPanel");
  `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A5D90
// Name: public: static void CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
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
// Address: 0x104A5E30
// Name: public: CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributeDoubleChoicePanel *__thiscall CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::Panel *parent,
        vgui::Panel *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDoubleComboBoxContainerPanel *v7; // eax
  CDoubleComboBoxContainerPanel *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  BOOL v11; // ecx
  vgui::ComboBox *v12; // eax
  vgui::ComboBox *v13; // eax
  BOOL v14; // ecx
  int _C; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, (const AttributeWidgetInfo_t *)info);
  this->__vftable = (CBaseAttributeDoubleChoicePanel_vtbl *)&CBaseAttributeDoubleChoicePanel::`vftable';
  if ( `CBaseAttributeDoubleChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
    v4->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeDoubleChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
    v5->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeDoubleChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
    v6->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&_C);
  vgui::Panel::SetDropEnabled(this, enabled: false, flHoverContextTime: 0.0);
  v7 = (CDoubleComboBoxContainerPanel *)operator new(nSize: 0x158u);
  if ( v7 != nullptr )
    v8 = CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(this: v7, parent: this, name: "Container");
  else
    v8 = nullptr;
  this->m_pContainerPanel = v8;
  v9 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(
            this: v9,
            parent: this->m_pContainerPanel,
            panelName: (vgui::Panel *)"AttributeValue",
            numLines: 10,
            allowEdit: false);
  else
    v10 = nullptr;
  v11 = (this->m_nFlags & 0x20) == 0;
  this->m_pData[0] = v10;
  v10->SetEnabled(this: v10, a2: v11);
  this->m_pData[0]->AddActionSignalTarget_2(this: this->m_pData[0], a2: this);
  this->m_pContainerPanel->m_pBoxes[0] = this->m_pData[0];
  v12 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v12 != nullptr )
    v13 = vgui::ComboBox::ComboBox(
            this: v12,
            parent: this->m_pContainerPanel,
            panelName: (vgui::Panel *)"AttributeValue",
            numLines: 10,
            allowEdit: false);
  else
    v13 = nullptr;
  v14 = (this->m_nFlags & 0x20) == 0;
  this->m_pData[1] = v13;
  v13->SetEnabled(this: v13, a2: v14);
  this->m_pData[1]->AddActionSignalTarget_2(this: this->m_pData[1], a2: this);
  this->m_pContainerPanel->m_pBoxes[1] = this->m_pData[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A6020
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributeDoubleChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributeDoubleChoicePanel::GetMessageMap(CBaseAttributeDoubleChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
  `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A6050
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributeDoubleChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributeDoubleChoicePanel::GetAnimMap(CBaseAttributeDoubleChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x104A6060
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributeDoubleChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributeDoubleChoicePanel::GetKBMap(CBaseAttributeDoubleChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
  `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00498EA0
// Name: private: virtual class vgui::Panel __near * CBaseAttributeDoubleChoicePanel::GetDataPanel(void)
// Source: json
//------------------------------------------------------------------------------
CDoubleComboBoxContainerPanel *__thiscall CBaseAttributeDoubleChoicePanel::GetDataPanel(
        CBaseAttributeDoubleChoicePanel *this)
{
  return this->m_pContainerPanel;
}

//------------------------------------------------------------------------------
// Address: 0x004A62D0
// Name: public: static char const __near * CDoubleComboBoxContainerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDoubleComboBoxContainerPanel::GetPanelClassName()
{
  return "CDoubleComboBoxContainerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004A62E0
// Name: public: static char const __near * CBaseAttributeDoubleChoicePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributeDoubleChoicePanel::GetPanelClassName()
{
  return "CBaseAttributeDoubleChoicePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004A62F0
// Name: private: virtual void CDoubleComboBoxContainerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDoubleComboBoxContainerPanel::PerformLayout(CDoubleComboBoxContainerPanel *this)
{
  vgui::ComboBox *v2; // ecx
  vgui::ComboBox *v3; // ecx
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v2 = this->m_pBoxes[0];
  if ( v2 != nullptr )
    vgui::Panel::SetBounds(this: v2, x: 0, y: 0, wide: w / 2, tall: h);
  v3 = this->m_pBoxes[1];
  if ( v3 != nullptr )
    vgui::Panel::SetBounds(this: v3, x: w / 2, y: 0, wide: w / 2, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x004A6360
// Name: public: virtual void CBaseAttributeDoubleChoicePanel::PostConstructor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::PostConstructor(CBaseAttributeDoubleChoicePanel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->PopulateComboBoxes(this, a2: this->m_pData);
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A6390
// Name: public: virtual void CBaseAttributeDoubleChoicePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::ApplySchemeSettings(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al
  unsigned int v5; // edi

  CBaseAttributePanel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  v5 = v3->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v4);
  this->m_pData[0]->SetFont(this: this->m_pData[0], a2: v5);
  this->m_pData[1]->SetFont(this: this->m_pData[1], a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004A63F0
// Name: private: virtual void CBaseAttributeDoubleChoicePanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::Apply(CBaseAttributeDoubleChoicePanel *this)
{
  KeyValues *ActiveItemUserData; // eax
  vgui::ComboBox *v3; // ecx
  KeyValues *kv[2]; // [esp+8h] [ebp-8h] BYREF

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pData[0]);
  v3 = this->m_pData[1];
  kv[0] = ActiveItemUserData;
  kv[1] = vgui::ComboBox::GetActiveItemUserData(this: v3);
  this->SetAttributeFromComboBoxes(this, a2: this->m_pData, a3: kv);
}

//------------------------------------------------------------------------------
// Address: 0x004A6440
// Name: protected: virtual void CBaseAttributeDoubleChoicePanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::Refresh(CBaseAttributeDoubleChoicePanel *this)
{
  ((void (__stdcall *)(vgui::ComboBox **))this->SetComboBoxesFromAttribute)(a1: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x004A6460
// Name: private: virtual void CBaseAttributeDoubleChoicePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributeDoubleChoicePanel::OnTextChanged(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::Panel *panel)
{
  CBaseAttributePanel::SetDirty(this, dirty: true);
  if ( (this->m_nFlags & 0x10) != 0 )
    this->Apply(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A6490
// Name: public: CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDoubleComboBoxContainerPanel *__thiscall CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(
        CDoubleComboBoxContainerPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CDoubleComboBoxContainerPanel_vtbl *)&CDoubleComboBoxContainerPanel::`vftable';
  if ( `CDoubleComboBoxContainerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDoubleComboBoxContainerPanel");
    v4->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CDoubleComboBoxContainerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDoubleComboBoxContainerPanel");
    v5->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CDoubleComboBoxContainerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDoubleComboBoxContainerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDoubleComboBoxContainerPanel");
    v6->pfnClassName = CDoubleComboBoxContainerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_pBoxes[1] = nullptr;
  this->m_pBoxes[0] = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A6560
// Name: public: virtual struct vgui::PanelMessageMap __near * CDoubleComboBoxContainerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDoubleComboBoxContainerPanel::GetMessageMap(CDoubleComboBoxContainerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::s_pMap;
  `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDoubleComboBoxContainerPanel");
  `CDoubleComboBoxContainerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A6590
// Name: public: virtual struct PanelAnimationMap __near * CDoubleComboBoxContainerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDoubleComboBoxContainerPanel::GetAnimMap(CDoubleComboBoxContainerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDoubleComboBoxContainerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004A65A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDoubleComboBoxContainerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDoubleComboBoxContainerPanel::GetKBMap(CDoubleComboBoxContainerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDoubleComboBoxContainerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::s_pMap;
  `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDoubleComboBoxContainerPanel");
  `CDoubleComboBoxContainerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A65D0
// Name: public: static void CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
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
// Address: 0x004A6670
// Name: public: CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributeDoubleChoicePanel *__thiscall CBaseAttributeDoubleChoicePanel::CBaseAttributeDoubleChoicePanel(
        CBaseAttributeDoubleChoicePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDoubleComboBoxContainerPanel *v7; // eax
  CDoubleComboBoxContainerPanel *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  BOOL v11; // ecx
  vgui::ComboBox *v12; // eax
  vgui::ComboBox *v13; // eax
  BOOL v14; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CBaseAttributeDoubleChoicePanel_vtbl *)&CBaseAttributeDoubleChoicePanel::`vftable';
  if ( `CBaseAttributeDoubleChoicePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
    v4->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeDoubleChoicePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
    v5->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CBaseAttributeDoubleChoicePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributeDoubleChoicePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
    v6->pfnClassName = CBaseAttributeDoubleChoicePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CBaseAttributeDoubleChoicePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetDropEnabled(this, enabled: false, flHoverContextTime: 0.0);
  v7 = (CDoubleComboBoxContainerPanel *)MemAlloc_Alloc(nSize: 0x158u);
  if ( v7 != nullptr )
    v8 = CDoubleComboBoxContainerPanel::CDoubleComboBoxContainerPanel(this: v7, parent: this, name: "Container");
  else
    v8 = nullptr;
  this->m_pContainerPanel = v8;
  v9 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(
            this: v9,
            parent: this->m_pContainerPanel,
            panelName: "AttributeValue",
            numLines: 10,
            allowEdit: false);
  else
    v10 = nullptr;
  v11 = (this->m_nFlags & 0x20) == 0;
  this->m_pData[0] = v10;
  v10->SetEnabled(this: v10, a2: v11);
  this->m_pData[0]->AddActionSignalTarget_2(this: this->m_pData[0], a2: this);
  this->m_pContainerPanel->m_pBoxes[0] = this->m_pData[0];
  v12 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v12 != nullptr )
    v13 = vgui::ComboBox::ComboBox(
            this: v12,
            parent: this->m_pContainerPanel,
            panelName: "AttributeValue",
            numLines: 10,
            allowEdit: false);
  else
    v13 = nullptr;
  v14 = (this->m_nFlags & 0x20) == 0;
  this->m_pData[1] = v13;
  v13->SetEnabled(this: v13, a2: v14);
  this->m_pData[1]->AddActionSignalTarget_2(this: this->m_pData[1], a2: this);
  this->m_pContainerPanel->m_pBoxes[1] = this->m_pData[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A6860
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributeDoubleChoicePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributeDoubleChoicePanel::GetMessageMap(CBaseAttributeDoubleChoicePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributeDoubleChoicePanel");
  `CBaseAttributeDoubleChoicePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A6890
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributeDoubleChoicePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributeDoubleChoicePanel::GetAnimMap(CBaseAttributeDoubleChoicePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributeDoubleChoicePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004A68A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributeDoubleChoicePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributeDoubleChoicePanel::GetKBMap(CBaseAttributeDoubleChoicePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributeDoubleChoicePanel");
  `CBaseAttributeDoubleChoicePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
