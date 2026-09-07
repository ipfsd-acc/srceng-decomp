// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubportal.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\gameui\optionssubportal.h"

//------------------------------------------------------------------------------
// Address: 0x101E02A0
// Name: public: static char const __near * COptionsSubPortal::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubPortal::GetPanelClassName()
{
  return "COptionsSubPortal";
}

//------------------------------------------------------------------------------
// Address: 0x101E02B0
// Name: public: virtual void COptionsSubPortal::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubPortal::OnResetData(COptionsSubPortal *this)
{
  ConVarRef r_portal_stencil_depth; // [esp+4h] [ebp-8h] BYREF

  CCvarToggleCheckButton::Reset(this: this->m_pPortalFunnelCheckBox);
  ConVarRef::ConVarRef(this: &r_portal_stencil_depth, pName: "r_portal_stencil_depth");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&r_portal_stencil_depth) )
    this->m_pPortalDepthCombo->ActivateItem(
      this: this->m_pPortalDepthCombo,
      a2: r_portal_stencil_depth.m_pConVarState->m_Value.m_nValue);
}

//------------------------------------------------------------------------------
// Address: 0x101E0300
// Name: public: virtual void COptionsSubPortal::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubPortal::OnApplyChanges(COptionsSubPortal *this)
{
  int ActiveItem; // eax
  ConVarRef r_portal_stencil_depth; // [esp+4h] [ebp-8h] BYREF

  CCvarToggleCheckButton::ApplyChanges(this: this->m_pPortalFunnelCheckBox);
  if ( this->m_pPortalDepthCombo->IsEnabled(this: this->m_pPortalDepthCombo) )
  {
    ConVarRef::ConVarRef(this: &r_portal_stencil_depth, pName: "r_portal_stencil_depth");
    ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pPortalDepthCombo);
    r_portal_stencil_depth.m_pConVar->SetValue_2(this: r_portal_stencil_depth.m_pConVar, a2: ActiveItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0370
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubPortal::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubPortal::GetMessageMap(COptionsSubPortal *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubPortal::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubPortal::GetMessageMap'::`2'::s_pMap;
  `COptionsSubPortal::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubPortal");
  `COptionsSubPortal::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E03A0
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubPortal::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubPortal::GetAnimMap(COptionsSubPortal *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubPortal");
}

//------------------------------------------------------------------------------
// Address: 0x101E03B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubPortal::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubPortal::GetKBMap(COptionsSubPortal *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubPortal::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubPortal::GetKBMap'::`2'::s_pMap;
  `COptionsSubPortal::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubPortal");
  `COptionsSubPortal::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E0410
// Name: public: static void COptionsSubPortal::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubPortal::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubPortal::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `COptionsSubPortal::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubPortal");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E04A0
// Name: public: static void COptionsSubPortal::PanelMessageFunc_OnControlModified::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubPortal::PanelMessageFunc_OnControlModified::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubPortal::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded )
  {
    `COptionsSubPortal::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubPortal");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0530
// Name: public: static void COptionsSubPortal::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubPortal::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubPortal::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COptionsSubPortal::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubPortal");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E05C0
// Name: public: COptionsSubPortal::COptionsSubPortal(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubPortal *__thiscall COptionsSubPortal::COptionsSubPortal(COptionsSubPortal *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CCvarToggleCheckButton *v6; // eax
  CCvarToggleCheckButton *v7; // eax
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  KeyValues *v29; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: nullptr);
  this->__vftable = (COptionsSubPortal_vtbl *)&COptionsSubPortal::`vftable';
  if ( `COptionsSubPortal::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubPortal::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubPortal");
    v3->pfnClassName = COptionsSubPortal::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubPortal::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubPortal::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubPortal");
    v4->pfnClassName = COptionsSubPortal::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubPortal::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubPortal::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubPortal");
    v5->pfnClassName = COptionsSubPortal::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubPortal::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  COptionsSubPortal::PanelMessageFunc_OnControlModified::InitVar(a1: (int)&savedregs);
  COptionsSubPortal::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  v6 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v6 != nullptr )
    v7 = CCvarToggleCheckButton::CCvarToggleCheckButton(
           this: v6,
           parent: this,
           panelName: "PortalFunnel",
           text: "#GameUI_PortalFunnel",
           cvarname: "sv_player_funnel_into_portals");
  else
    v7 = nullptr;
  this->m_pPortalFunnelCheckBox = v7;
  v8 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(this: v8, parent: this, panelName: "PortalDepth", numLines: 6, allowEdit: false);
  else
    v9 = nullptr;
  this->m_pPortalDepthCombo = v9;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "PortalDepth", firstKey: "depth", firstValue: 0);
  else
    v11 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth0", a3: v11);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "PortalDepth", firstKey: "depth", firstValue: 1);
  else
    v13 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth1", a3: v13);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "PortalDepth", firstKey: "depth", firstValue: 2);
  else
    v15 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth2", a3: v15);
  v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v16 != nullptr )
    v17 = KeyValues::KeyValues(this: v16, setName: "PortalDepth", firstKey: "depth", firstValue: 3);
  else
    v17 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth3", a3: v17);
  v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v18 != nullptr )
    v19 = KeyValues::KeyValues(this: v18, setName: "PortalDepth", firstKey: "depth", firstValue: 4);
  else
    v19 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth4", a3: v19);
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "PortalDepth", firstKey: "depth", firstValue: 5);
  else
    v21 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth5", a3: v21);
  v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v22 != nullptr )
    v23 = KeyValues::KeyValues(this: v22, setName: "PortalDepth", firstKey: "depth", firstValue: 6);
  else
    v23 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth6", a3: v23);
  v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v24 != nullptr )
    v25 = KeyValues::KeyValues(this: v24, setName: "PortalDepth", firstKey: "depth", firstValue: 7);
  else
    v25 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth7", a3: v25);
  v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v26 != nullptr )
    v27 = KeyValues::KeyValues(this: v26, setName: "PortalDepth", firstKey: "depth", firstValue: 8);
  else
    v27 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth8", a3: v27);
  v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v28 != nullptr )
    v29 = KeyValues::KeyValues(this: v28, setName: "PortalDepth", firstKey: "depth", firstValue: 9);
  else
    v29 = nullptr;
  this->m_pPortalDepthCombo->AddItem_2(this: this->m_pPortalDepthCombo, a2: "#GameUI_PortalDepth9", a3: v29);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\OptionsSubPortal.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E4DF0
// Name: private: virtual void COptionsSubPortal::OnControlModified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubPortal::OnControlModified(vgui::PropertySheet *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "ApplyButtonEnable");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A3210
// Name: private: virtual void COptionsSubPortal::OnCheckButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubPortal::OnCheckButtonChecked(vgui::ListPanel *this)
{
  this->RemoveAll(this);
}
