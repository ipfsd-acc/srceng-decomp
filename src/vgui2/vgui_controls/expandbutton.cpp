// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/expandbutton.cpp
// Functions: 11
// ============================================================

#include "vgui2\vgui_controls\expandbutton.h"

//------------------------------------------------------------------------------
// Address: 0x102BB3A0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7C40
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C7C50
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C7CC0
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7D30
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102C7E00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7E30
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C7E40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7EA0
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Expanded";
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
// Address: 0x102C7F40
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar();
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C8020
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)MemAlloc_Alloc(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1004F650
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x1004F660
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1004F6D0
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F740
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1004F830
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F860
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x1004F870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F8D0
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F970
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA50
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00429F10
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x00429F20
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00429F90
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A000
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0042A0D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A100
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x0042A110
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A170
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A210
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042A2F0
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1005A390
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x1005A3A0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1005A410
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A480
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1005A550
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005A580
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x1005A590
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005A5F0
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBox::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A690
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005A770
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00606B20
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x00606B30
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00606BA0
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606C10
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00606CE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00606D10
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x00606D20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00606D80
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ExpandButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Expanded";
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
// Address: 0x00606E20
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00606F00
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)MemAlloc_Alloc(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102BB450
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7D10
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C7D20
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C7D90
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7EE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7F10
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C7F20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7F80
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ExpandButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Expanded";
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
// Address: 0x102C8100
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)MemAlloc_Alloc(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102ED8B0
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x102ED8C0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102ED930
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED9A0
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102EDA90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EDAC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x102EDAD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EDB30
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Expanded";
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
// Address: 0x102EDBD0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: &var);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EDCB0
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100BC000
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x100BC010
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100BC080
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC0F0
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100BC1C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BC1F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x100BC200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BC260
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC300
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: szDescription);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BC3E0
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0044A4A0
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x0044A4B0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044A520
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A590
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0044A670
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A6A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x0044A6B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A710
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Expanded";
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
// Address: 0x0044A7B0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044A890
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00431A10
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x00431A20
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  int v5; // eax

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = ((int (__thiscall *)(vgui::ExpandButton *))this->IsProportional)(a1: this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00431A80
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431AE0
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  int v2; // edi
  int h; // [esp+14h] [ebp-14h] BYREF
  int th; // [esp+18h] [ebp-10h] BYREF
  int w; // [esp+1Ch] [ebp-Ch] BYREF
  int tw; // [esp+20h] [ebp-8h] BYREF
  int v7; // [esp+24h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = (unsigned __int16)(this->IsSelected(this) ? 54 : 52);
  h = v2;
  vgui::Panel::GetSize(this, wide: &tw, tall: &th);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: (const wchar_t *)&h, a4: &v7, a5: &w);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (tw - v7) / 2, a3: (th - w) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v2, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00431BC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431BF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x00431C00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431C60
// Name: public: static void vgui::ExpandButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ExpandButton::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00431CE0
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    vgui::ExpandButton::AddToMap(
      scriptname: "Expanded",
      function: (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)4,
      p1name: "panel",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431D40
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar();
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00431E20
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063E1A0
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x0063E1B0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0063E220
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063E290
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0063E360
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063E390
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x0063E3A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063E400
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Expanded";
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
// Address: 0x0063E4A0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063E580
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)MemAlloc_Alloc(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1004B620
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062CC0
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x10062CD0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10062D40
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062DB0
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10062E80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062EB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x10062EC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062F20
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062FC0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100630A0
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100687B0
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x100687C0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10068830
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100688A0
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10068970
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100689A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x100689B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068A10
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068AB0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068B90
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0043A220
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x0043A230
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043A2A0
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A310
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0043A3E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A410
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x0043A420
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A480
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A520
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: &defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A600
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00483980
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x00483990
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  int v5; // eax

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = ((int (__thiscall *)(vgui::ExpandButton *))this->IsProportional)(a1: this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004839F0
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483A50
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  int v2; // edi
  int h; // [esp+14h] [ebp-14h] BYREF
  int th; // [esp+18h] [ebp-10h] BYREF
  int w; // [esp+1Ch] [ebp-Ch] BYREF
  int tw; // [esp+20h] [ebp-8h] BYREF
  int v7; // [esp+24h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = (unsigned __int16)(this->IsSelected(this) ? 54 : 52);
  h = v2;
  vgui::Panel::GetSize(this, wide: &tw, tall: &th);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: (const wchar_t *)&h, a4: &v7, a5: &w);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (tw - v7) / 2, a3: (th - w) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v2, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00483B30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483B60
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x00483B70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483BD0
// Name: public: static void vgui::ExpandButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ExpandButton::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00483C50
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    vgui::ExpandButton::AddToMap(
      scriptname: "Expanded",
      function: (unsigned int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)4,
      p1name: "panel",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483CB0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar();
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483D90
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)MemAlloc_Alloc(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00428B10
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x00428B20
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00428B90
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428C00
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00428CE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428D10
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x00428D20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428D80
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428E20
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428F00
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0042C550
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x0042C560
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042C5D0
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C640
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0042C710
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C740
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x0042C750
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C7B0
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C850
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: defaultValue);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042C930
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103A22B0
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x103A22C0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x103A2330
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A23A0
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x103A2470
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A24A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x103A24B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A2510
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Expanded";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A25B0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: prType);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar();
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A2690
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)MemAlloc_Alloc(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1039A6C0
// Name: public: static char const __near * vgui::ExpandButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ExpandButton::GetPanelClassName()
{
  return "ExpandButton";
}

//------------------------------------------------------------------------------
// Address: 0x1039A6D0
// Name: protected: virtual void vgui::ExpandButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::ApplySchemeSettings(vgui::ExpandButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  this->m_Color = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ExpandButton.Color", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  this->m_hFont = v4.GetFont(this: v2, a2: "Marlett", a3: v5);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1039A750
// Name: public: virtual void vgui::ExpandButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::SetSelected(vgui::ExpandButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bExpandable && state != this->IsSelected(this) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Expanded", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039A7C0
// Name: public: virtual void vgui::ExpandButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ExpandButton::Paint(vgui::ExpandButton *this)
{
  bool v2; // al
  int v3; // edi
  int tw; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int th; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  wchar_t pString[2]; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFont);
  v2 = this->IsSelected(this);
  pString[1] = 0;
  v3 = (unsigned __int16)(2 * v2 + 52);
  pString[0] = 2 * v2 + 52;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: this->m_hFont, a3: pString, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_Color);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (w - tw) / 2, a3: (h - th) / 2);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v3, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1039A890
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ExpandButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ExpandButton::GetMessageMap(vgui::ExpandButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
  `vgui::ExpandButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A8C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ExpandButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ExpandButton::GetAnimMap(vgui::ExpandButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ExpandButton");
}

//------------------------------------------------------------------------------
// Address: 0x1039A8D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ExpandButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ExpandButton::GetKBMap(vgui::ExpandButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ExpandButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ExpandButton::GetKBMap'::`2'::s_pMap;
  `vgui::ExpandButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
  `vgui::ExpandButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A930
// Name: public: static void vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded )
  {
    `vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "Expanded";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039A9D0
// Name: public: vgui::ExpandButton::ExpandButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__thiscall vgui::ExpandButton::ExpandButton(
        vgui::ExpandButton *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text: locale);
  this->__vftable = (vgui::ExpandButton_vtbl *)&vgui::ExpandButton::`vftable';
  if ( `vgui::ExpandButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ExpandButton");
    v4->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ExpandButton");
    v5->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::ExpandButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ExpandButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ExpandButton");
    v6->pfnClassName = vgui::ExpandButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::ExpandButton::PanelMessageFunc_OnExpanded::InitVar(a1: (int)&savedregs);
  this->m_Color = 0;
  this->m_hFont = 0;
  this->m_bExpandable = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039AAB0
// Name: Create_ExpandButton
// Source: json
//------------------------------------------------------------------------------
vgui::ExpandButton *__cdecl Create_ExpandButton()
{
  vgui::ExpandButton *v0; // eax

  v0 = (vgui::ExpandButton *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return vgui::ExpandButton::ExpandButton(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace server
