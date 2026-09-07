// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_hintdisplay.cpp
// Functions: 43
// ============================================================

#include "game\client\hud_hintdisplay.h"

//------------------------------------------------------------------------------
// Address: 0x10103030
// Name: public: static char const __near * CHudHintDisplay::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudHintDisplay::GetPanelClassName()
{
  return "CHudHintDisplay";
}

//------------------------------------------------------------------------------
// Address: 0x10103040
// Name: private: static void __near * CHudHintKeyDisplay::GetVar_m_iYOffset(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CHudHintKeyDisplay::GetVar_m_iYOffset(vgui::Panel *panel)
{
  return &panel[1].m_OverridableColorEntries.m_Memory.m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x10103050
// Name: protected: virtual void CHudHintDisplay::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintDisplay::ApplySchemeSettings(CHudHintDisplay *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  CHudHintDisplay_vtbl *v4; // ebx
  Color *v5; // eax
  unsigned int v6; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  vgui::Label_vtbl *v8; // ebx
  _DWORD *v9; // eax
  int Tall; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->vgui::Panel::vgui::IClientPanel::__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "HintMessageFg", a4: v2);
  ((void (__thiscall *)(CHudHintDisplay *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = v2->GetFont(this: v2, a2: "HudHintText", a3: true);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  this->m_hFont = v6;
  v8 = this->m_pLabel->__vftable;
  v9 = (_DWORD *)GetSchemeColor_2(this, result: (Color *)&pScheme, a3: "HintMessageBg", a4: v2);
  ((void (__thiscall *)(vgui::Label *, _DWORD))v8->SetBgColor)(a1: this->m_pLabel, a2: *v9);
  this->m_pLabel->SetPaintBackgroundType(this: this->m_pLabel, a2: 2);
  Tall = vgui::Panel::GetTall(this);
  vgui::Panel::SetSize(this: this->m_pLabel, wide: 0, tall: Tall);
}

//------------------------------------------------------------------------------
// Address: 0x10103100
// Name: public: static char const __near * CHudHintKeyDisplay::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudHintKeyDisplay::GetPanelClassName()
{
  return "CHudHintKeyDisplay";
}

//------------------------------------------------------------------------------
// Address: 0x10103110
// Name: protected: static void __near * CHudHintDisplay::GetVar_m_iTextX(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFlags<unsigned short> *__cdecl CHudHintDisplay::GetVar_m_iTextX(vgui::Panel *panel)
{
  return &panel[1]._flags;
}

//------------------------------------------------------------------------------
// Address: 0x10103120
// Name: protected: static void __near * CHudHintDisplay::GetVar_m_iTextY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CHudHintDisplay::GetVar_m_iTextY(vgui::Panel *panel)
{
  return &panel[1]._actionSignalTargetDar.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x10103130
// Name: private: static void __near * CHudHintKeyDisplay::GetVar_m_iTextGapX(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CHudHintKeyDisplay::GetVar_m_iTextGapX(vgui::Panel *panel)
{
  return &panel[1]._actionSignalTargetDar.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10103140
// Name: private: static void __near * CHudHintKeyDisplay::GetVar_m_iTextGapY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *__cdecl CHudHintKeyDisplay::GetVar_m_iTextGapY(
        vgui::Panel *panel)
{
  return &panel[1].m_OverridableColorEntries;
}

//------------------------------------------------------------------------------
// Address: 0x10103150
// Name: protected: virtual void CHudHintKeyDisplay::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintKeyDisplay::ApplySchemeSettings(CHudHintKeyDisplay *this, vgui::IScheme *pScheme)
{
  this->m_hSmallFont = pScheme->GetFont(this: pScheme, a2: "HudHintTextSmall", a3: true);
  this->m_hLargeFont = pScheme->GetFont(this: pScheme, a2: "HudHintTextLarge", a3: true);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x101031A0
// Name: public: virtual void CHudHintDisplay::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintDisplay::PerformLayout(CHudHintDisplay *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edx
  int m_iCenterX; // eax
  float v6; // xmm0_4
  int v7; // edi
  int v8; // ecx
  int m_iCenterY; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // eax
  int fontTall; // [esp+Ch] [ebp-14h]
  int y; // [esp+10h] [ebp-10h]
  int wide; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h]

  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < this->m_Labels.m_Size; ++i )
  {
    v3 = i;
    if ( v2 <= vgui::Panel::GetWide(this: this->m_Labels.m_Memory.m_pMemory[i]) )
      v2 = vgui::Panel::GetWide(this: this->m_Labels.m_Memory.m_pMemory[v3]);
  }
  fontTall = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
  v4 = fontTall * this->m_Labels.m_Size + 2 * this->m_iTextY;
  m_iCenterX = this->m_iCenterX;
  v6 = (float)(v2 + 2 * this->m_iTextX) * this->m_flLabelSizePercentage;
  i = v4;
  v7 = (int)v6;
  if ( m_iCenterX >= 0 )
  {
    if ( m_iCenterX <= 0 )
    {
      v4 = i;
      v8 = (wide - v7) / 2;
    }
    else
    {
      v8 = wide - v7;
    }
  }
  else
  {
    v8 = 0;
  }
  m_iCenterY = this->m_iCenterY;
  if ( m_iCenterY <= 0 )
  {
    if ( m_iCenterY >= 0 )
      v10 = (tall - v4) / 2;
    else
      v10 = tall - v4;
  }
  else
  {
    v10 = 0;
  }
  v11 = v8 <= 0 ? 0 : v8;
  v12 = v10 <= 0 ? 0 : v10;
  if ( v7 >= wide )
    v7 = wide;
  y = v12;
  vgui::Panel::SetBounds(this: this->m_pLabel, x: v11, y: v12, wide: v7, tall: i);
  v13 = 0;
  if ( this->m_Labels.m_Size > 0 )
  {
    i = 0;
    do
    {
      v14 = vgui::Panel::GetWide(this: this->m_Labels.m_Memory.m_pMemory[v13]);
      vgui::Panel::SetPos(
        this: this->m_Labels.m_Memory.m_pMemory[v13],
        x: (int)((double)(wide - v14) * 0.5),
        y: y + i + this->m_iTextY);
      i += fontTall;
      ++v13;
    }
    while ( v13 < this->m_Labels.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103340
// Name: protected: virtual void CHudHintDisplay::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintDisplay::OnThink(CHudHintDisplay *this)
{
  vgui::Label_vtbl *v2; // edi
  Color *v3; // eax
  int i; // ebx
  vgui::Label_vtbl *v5; // edi
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v7; // eax
  float m_flLabelSizePercentage; // xmm0_4
  bool v9; // al
  Color v10; // [esp+Ch] [ebp-8h] BYREF
  vgui::Label *v11; // [esp+10h] [ebp-4h] BYREF

  v2 = this->m_pLabel->__vftable;
  v3 = this->GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::Label *, _DWORD))v2->SetFgColor)(a1: this->m_pLabel, a2: *v3);
  for ( i = 0; i < this->m_Labels.m_Size; ++i )
  {
    v5 = this->m_Labels.m_Memory.m_pMemory[i]->__vftable;
    GetFgColor = this->GetFgColor;
    v11 = this->m_Labels.m_Memory.m_pMemory[i];
    v7 = (_DWORD *)GetFgColor(this, result: &v10);
    ((void (__thiscall *)(vgui::Label *, _DWORD))v5->SetFgColor)(a1: v11, a2: *v7);
  }
  m_flLabelSizePercentage = this->m_flLabelSizePercentage;
  if ( m_flLabelSizePercentage != 0.0 && m_flLabelSizePercentage != 1.0 || this->m_bLastLabelUpdateHack )
  {
    v9 = m_flLabelSizePercentage != 0.0 && m_flLabelSizePercentage != 1.0;
    this->m_bLastLabelUpdateHack = v9;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103420
// Name: protected: virtual void CHudHintKeyDisplay::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintKeyDisplay::OnThink(CHudHintKeyDisplay *this)
{
  int i; // ebx
  vgui::Label_vtbl *v3; // edi
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v5; // eax
  int oy; // [esp+8h] [ebp-10h] BYREF
  Color v7; // [esp+Ch] [ebp-Ch] BYREF
  int ox; // [esp+10h] [ebp-8h] BYREF
  vgui::Label *v9; // [esp+14h] [ebp-4h]

  for ( i = 0; i < this->m_Labels.m_Size; ++i )
  {
    v3 = this->m_Labels.m_Memory.m_pMemory[i]->__vftable;
    GetFgColor = this->GetFgColor;
    v9 = this->m_Labels.m_Memory.m_pMemory[i];
    v5 = (_DWORD *)GetFgColor(this, result: &v7);
    ((void (__thiscall *)(vgui::Label *, _DWORD))v3->SetFgColor)(a1: v9, a2: *v5);
  }
  vgui::Panel::GetPos(this, x: &ox, y: &oy);
  vgui::Panel::SetPos(this, x: ox, y: (int)(float)((float)this->m_iBaseY + this->m_iYOffset));
}

//------------------------------------------------------------------------------
// Address: 0x101034B0
// Name: public: static void CHudHintDisplay::PanelAnimationVar_m_iTextX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintDisplay::PanelAnimationVar_m_iTextX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintDisplay::PanelAnimationVar_m_iTextX::InitVar'::`2'::bAdded )
  {
    `CHudHintDisplay::PanelAnimationVar_m_iTextX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "text_xpos";
    src.m_pszVariable = "m_iTextX";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintDisplay::GetVar_m_iTextX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103510
// Name: public: static void CHudHintDisplay::PanelAnimationVar_m_iTextY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintDisplay::PanelAnimationVar_m_iTextY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintDisplay::PanelAnimationVar_m_iTextY::InitVar'::`2'::bAdded )
  {
    `CHudHintDisplay::PanelAnimationVar_m_iTextY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "text_ypos";
    src.m_pszVariable = "m_iTextY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintDisplay::GetVar_m_iTextY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103570
// Name: public: static void CHudHintDisplay::PanelAnimationVar_m_iCenterX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintDisplay::PanelAnimationVar_m_iCenterX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintDisplay::PanelAnimationVar_m_iCenterX::InitVar'::`2'::bAdded )
  {
    `CHudHintDisplay::PanelAnimationVar_m_iCenterX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "center_x";
    src.m_pszVariable = "m_iCenterX";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintKeyDisplay::GetVar_m_iTextGapX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101035D0
// Name: public: static void CHudHintDisplay::PanelAnimationVar_m_iCenterY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintDisplay::PanelAnimationVar_m_iCenterY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintDisplay::PanelAnimationVar_m_iCenterY::InitVar'::`2'::bAdded )
  {
    `CHudHintDisplay::PanelAnimationVar_m_iCenterY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "center_y";
    src.m_pszVariable = "m_iCenterY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintKeyDisplay::GetVar_m_iTextGapY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103630
// Name: public: static void CHudHintDisplay::PanelAnimationVar_m_flLabelSizePercentage::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintDisplay::PanelAnimationVar_m_flLabelSizePercentage::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintDisplay::PanelAnimationVar_m_flLabelSizePercentage::InitVar'::`2'::bAdded )
  {
    `CHudHintDisplay::PanelAnimationVar_m_flLabelSizePercentage::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "HintSize";
    src.m_pszVariable = "m_flLabelSizePercentage";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintKeyDisplay::GetVar_m_iYOffset;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103690
// Name: public: CHudHintDisplay::CHudHintDisplay(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudHintDisplay *__thiscall CHudHintDisplay::CHudHintDisplay(CHudHintDisplay *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax
  vgui::Label *v8; // eax

  vgui::Panel::Panel(this, parent: nullptr, panelName: "HudHintDisplay");
  CHudElement::CHudElement(this: &this->CHudElement, pElementName);
  this->vgui::Panel::vgui::IClientPanel::__vftable = (CHudHintDisplay_vtbl *)&CHudHintDisplay::`vftable'{for `vgui::Panel'};
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudElement_vtbl *)&CHudHintDisplay::`vftable'{for `CHudElement'};
  if ( `CHudHintDisplay::ChainToMap'::`2'::chained == 0 )
  {
    `CHudHintDisplay::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudHintDisplay");
    v3->pfnClassName = CHudHintDisplay::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudHintDisplay::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudHintDisplay::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudHintDisplay");
    v4->pfnClassName = CHudHintDisplay::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudHintDisplay::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudHintDisplay::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudHintDisplay");
    v5->pfnClassName = CHudHintDisplay::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_bgColor = 0;
  this->m_Labels.m_Memory.m_pMemory = nullptr;
  this->m_Labels.m_Memory.m_nAllocationCount = 0;
  this->m_Labels.m_Memory.m_nGrowSize = 0;
  this->m_Labels.m_Size = 0;
  this->m_Labels.m_pElements = nullptr;
  CHudHintDisplay::PanelAnimationVar_m_iTextX::InitVar();
  CHudHintDisplay::PanelAnimationVar_m_iTextY::InitVar();
  CHudHintDisplay::PanelAnimationVar_m_iCenterX::InitVar();
  CHudHintDisplay::PanelAnimationVar_m_iCenterY::InitVar();
  CHudHintDisplay::PanelAnimationVar_m_flLabelSizePercentage::InitVar();
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this, newParent: v7);
  vgui::Panel::SetVisible(this, state: 0);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    this->m_pLabel = vgui::Label::Label(this: v8, parent: this, panelName: "HudHintDisplayLabel", text: prType);
  else
    this->m_pLabel = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10103810
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudHintDisplay::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudHintDisplay::GetMessageMap(CHudHintDisplay *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudHintDisplay::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudHintDisplay::GetMessageMap'::`2'::s_pMap;
  `CHudHintDisplay::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudHintDisplay");
  `CHudHintDisplay::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10103840
// Name: public: virtual struct PanelAnimationMap __near * CHudHintDisplay::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudHintDisplay::GetAnimMap(CHudHintDisplay *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudHintDisplay");
}

//------------------------------------------------------------------------------
// Address: 0x10103850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudHintDisplay::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudHintDisplay::GetKBMap(CHudHintDisplay *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudHintDisplay::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudHintDisplay::GetKBMap'::`2'::s_pMap;
  `CHudHintDisplay::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudHintDisplay");
  `CHudHintDisplay::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101038C0
// Name: public: bool CHudHintDisplay::SetHintText(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudHintDisplay::SetHintText(CHudHintDisplay *this, wchar_t *text)
{
  CHudHintDisplay *v2; // ebx
  int v3; // esi
  vgui::Label *v4; // ecx
  wchar_t *v5; // esi
  CUtlMemory<vgui::TreeNode *,int> *p_m_Labels; // edi
  unsigned __int16 *v7; // eax
  int v8; // ecx
  vgui::Label *v9; // eax
  vgui::Label *v10; // esi
  vgui::Label_vtbl *v11; // ebx
  Color *v12; // eax
  vgui::TreeNode **m_pMemory; // ebx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  vgui::Label **v17; // ebx
  wchar_t buf[512]; // [esp+Ch] [ebp-408h] BYREF
  Color v20; // [esp+40Ch] [ebp-8h] BYREF
  CHudHintDisplay *i; // [esp+410h] [ebp-4h]
  wchar_t *p; // [esp+41Ch] [ebp+8h]

  v2 = this;
  v3 = 0;
  for ( i = this; v3 < v2->m_Labels.m_Size; ++v3 )
  {
    v4 = v2->m_Labels.m_Memory.m_pMemory[v3];
    v4->MarkForDeletion(this: v4);
  }
  v5 = text;
  p_m_Labels = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Labels;
  v2->m_Labels.m_Size = 0;
  if ( text != nullptr )
  {
    while ( 1 )
    {
      v7 = wcschr(string: v5, ch: 0xAu);
      v8 = 0;
      if ( v7 != nullptr )
      {
        p = v7 + 1;
        v8 = 2 * (v7 - v5);
      }
      else
      {
        p = nullptr;
      }
      UTIL_ReplaceKeyBindings(a1: (char *)v5, inbuf: v5, inbufsizebytes: v8, outbuf: buf);
      v9 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
      if ( v9 != nullptr )
        v10 = vgui::Label::Label(this: v9, parent: v2, panelName: nullptr, wszText: buf);
      else
        v10 = nullptr;
      vgui::Panel::MakeReadyForUse(this: v10);
      v10->SetFont(this: v10, a2: v2->m_hFont);
      v10->SetPaintBackgroundEnabled(this: v10, a2: false);
      v10->SetPaintBorderEnabled(this: v10, a2: false);
      v10->SizeToContents(this: v10);
      v10->SetContentAlignment(this: v10, a2: a_west);
      v11 = v10->__vftable;
      v12 = i->GetFgColor(this: i, result: &v20);
      ((void (__thiscall *)(vgui::Label *, _DWORD))v11->SetFgColor)(a1: v10, a2: *v12);
      vgui::Panel::MakeReadyForUse(this: v10);
      m_pMemory = p_m_Labels[1].m_pMemory;
      m_nAllocationCount = p_m_Labels->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Labels, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_Labels[1].m_pMemory;
      v15 = p_m_Labels->m_pMemory;
      v16 = (char *)p_m_Labels[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_Labels[1].m_nAllocationCount = (int)p_m_Labels->m_pMemory;
      if ( v16 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v15[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v15[(_DWORD)m_pMemory],
          count: 4 * v16);
      v17 = (vgui::Label **)&p_m_Labels->m_pMemory[(_DWORD)m_pMemory];
      if ( v17 != nullptr )
        *v17 = v10;
      v2 = i;
      if ( p == nullptr )
        break;
      v5 = p;
    }
  }
  v2->InvalidateLayout(this: v2, a2: true, a3: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10103A70
// Name: public: void CHudHintDisplay::LocalizeAndDisplay(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintDisplay::LocalizeAndDisplay(
        CHudHintDisplay *this,
        const char *pszHudTxtMsg,
        const char *szRawString)
{
  vgui::ILocalize_vtbl *v4; // edx
  wchar_t *v5; // eax
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v7; // eax
  C_BasePlayer *LocalPlayer; // esi
  CHintSystem *v9; // eax
  IClientMode *v10; // eax
  vgui::AnimationController *v11; // eax

  szBuf_0[0] = 0;
  v4 = g_pVGuiLocalize->__vftable;
  pszBuf = szBuf_0;
  if ( pszHudTxtMsg != nullptr )
    v5 = (wchar_t *)((int (__stdcall *)(const char *))v4->Find)(a1: pszHudTxtMsg);
  else
    v5 = (wchar_t *)((int (__stdcall *)(const char *))v4->Find)(a1: szRawString);
  pszBuf = v5;
  if ( v5 == nullptr )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szRawString, a3: szBuf_0, a4: 256);
    v5 = szBuf_0;
    pszBuf = szBuf_0;
  }
  if ( CHudHintDisplay::SetHintText(this, text: v5) != 0 )
  {
    ((void (__thiscall *)(CHudHintDisplay *))this->SetVisible)(a1: this);
    ClientMode = GetClientMode();
    v7 = (vgui::AnimationController *)((int (__thiscall *)(IClientMode *, const char *))ClientMode->GetViewportAnimationController)(
                                        a1: ClientMode,
                                        a2: "HintMessageShow");
    vgui::AnimationController::StartAnimationSequence(this: v7, sequenceName: (const char *)1);
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      if ( sv_hudhint_sound.m_pParent != nullptr && sv_hudhint_sound.m_pParent->m_Value.m_nValue != 0 )
        C_BaseEntity::EmitSound(this: LocalPlayer, soundname: "Hud.Hint", soundtime: 0, duration: nullptr);
      if ( LocalPlayer->Hints(this: LocalPlayer) != nullptr )
      {
        v9 = LocalPlayer->Hints(this: LocalPlayer);
        CHintSystem::PlayedAHint(this: v9);
      }
    }
  }
  else
  {
    v10 = GetClientMode();
    v11 = v10->GetViewportAnimationController(this: v10);
    vgui::AnimationController::StartAnimationSequence(this: v11, sequenceName: "HintMessageHide");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103B90
// Name: public: static void CHudHintKeyDisplay::PanelAnimationVar_m_iTextX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintKeyDisplay::PanelAnimationVar_m_iTextX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintKeyDisplay::PanelAnimationVar_m_iTextX::InitVar'::`2'::bAdded )
  {
    `CHudHintKeyDisplay::PanelAnimationVar_m_iTextX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintKeyDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "text_xpos";
    src.m_pszVariable = "m_iTextX";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintDisplay::GetVar_m_iTextX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103BF0
// Name: public: static void CHudHintKeyDisplay::PanelAnimationVar_m_iTextY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintKeyDisplay::PanelAnimationVar_m_iTextY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintKeyDisplay::PanelAnimationVar_m_iTextY::InitVar'::`2'::bAdded )
  {
    `CHudHintKeyDisplay::PanelAnimationVar_m_iTextY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintKeyDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "text_ypos";
    src.m_pszVariable = "m_iTextY";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintDisplay::GetVar_m_iTextY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103C50
// Name: public: static void CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapX::InitVar'::`2'::bAdded )
  {
    `CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintKeyDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "text_xgap";
    src.m_pszVariable = "m_iTextGapX";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintKeyDisplay::GetVar_m_iTextGapX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103CB0
// Name: public: static void CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapY::InitVar'::`2'::bAdded )
  {
    `CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintKeyDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "text_ygap";
    src.m_pszVariable = "m_iTextGapY";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintKeyDisplay::GetVar_m_iTextGapY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103D10
// Name: public: static void CHudHintKeyDisplay::PanelAnimationVar_m_iYOffset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHintKeyDisplay::PanelAnimationVar_m_iYOffset::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHintKeyDisplay::PanelAnimationVar_m_iYOffset::InitVar'::`2'::bAdded )
  {
    `CHudHintKeyDisplay::PanelAnimationVar_m_iYOffset::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHintKeyDisplay");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "YOffset";
    src.m_pszVariable = "m_iYOffset";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudHintKeyDisplay::GetVar_m_iYOffset;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103D70
// Name: public: CHudHintKeyDisplay::CHudHintKeyDisplay(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudHintKeyDisplay *__thiscall CHudHintKeyDisplay::CHudHintKeyDisplay(
        CHudHintKeyDisplay *this,
        const char *pElementName)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  vgui::Panel::Panel(this, parent: nullptr, panelName: "HudHintKeyDisplay");
  CHudElement::CHudElement(this: &this->CHudElement, pElementName);
  this->vgui::Panel::vgui::IClientPanel::__vftable = (CHudHintKeyDisplay_vtbl *)&CHudHintKeyDisplay::`vftable'{for `vgui::Panel'};
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudElement_vtbl *)&CHudHintKeyDisplay::`vftable'{for `CHudElement'};
  if ( `CHudHintKeyDisplay::ChainToMap'::`2'::chained == 0 )
  {
    `CHudHintKeyDisplay::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudHintKeyDisplay");
    v3->pfnClassName = CHudHintKeyDisplay::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudHintKeyDisplay::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudHintKeyDisplay::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudHintKeyDisplay");
    v4->pfnClassName = CHudHintKeyDisplay::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudHintKeyDisplay::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudHintKeyDisplay::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudHintKeyDisplay");
    v5->pfnClassName = CHudHintKeyDisplay::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_Labels.m_Memory.m_pMemory = nullptr;
  this->m_Labels.m_Memory.m_nAllocationCount = 0;
  this->m_Labels.m_Memory.m_nGrowSize = 0;
  this->m_Labels.m_Size = 0;
  this->m_Labels.m_pElements = nullptr;
  CHudHintKeyDisplay::PanelAnimationVar_m_iTextX::InitVar();
  CHudHintKeyDisplay::PanelAnimationVar_m_iTextY::InitVar();
  CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapX::InitVar();
  CHudHintKeyDisplay::PanelAnimationVar_m_iTextGapY::InitVar();
  CHudHintKeyDisplay::PanelAnimationVar_m_iYOffset::InitVar();
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this, newParent: v7);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetAlpha(this, alpha: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10103EC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudHintKeyDisplay::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudHintKeyDisplay::GetMessageMap(CHudHintKeyDisplay *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudHintKeyDisplay::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudHintKeyDisplay::GetMessageMap'::`2'::s_pMap;
  `CHudHintKeyDisplay::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudHintKeyDisplay");
  `CHudHintKeyDisplay::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10103EF0
// Name: public: virtual struct PanelAnimationMap __near * CHudHintKeyDisplay::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudHintKeyDisplay::GetAnimMap(CHudHintKeyDisplay *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudHintKeyDisplay");
}

//------------------------------------------------------------------------------
// Address: 0x10103F00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudHintKeyDisplay::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudHintKeyDisplay::GetKBMap(CHudHintKeyDisplay *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudHintKeyDisplay::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudHintKeyDisplay::GetKBMap'::`2'::s_pMap;
  `CHudHintKeyDisplay::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudHintKeyDisplay");
  `CHudHintKeyDisplay::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10103F70
// Name: public: bool CHudHintKeyDisplay::SetHintText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CHudHintKeyDisplay::SetHintText@<al>(CHudHintKeyDisplay *this@<ecx>, int a2@<esi>, const char *text)
{
  int j; // esi
  vgui::Label *v5; // ecx
  wchar_t *v6; // eax
  wchar_t *v7; // ecx
  wchar_t *v8; // esi
  __int16 v9; // dx
  const wchar_t *v10; // edi
  unsigned __int16 *v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // eax
  vgui::Label *v14; // eax
  _DWORD *v15; // ebx
  vgui::Label *v16; // esi
  void (__thiscall *SetFont)(vgui::Label *, unsigned int); // edx
  char *v18; // eax
  const char *v19; // eax
  const unsigned __int16 *v20; // eax
  void (__thiscall *SetText)(vgui::Label *, const wchar_t *, bool); // eax
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  vgui::Label_vtbl *v23; // edi
  _DWORD *v24; // ebx
  int v25; // edi
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  vgui::Label **v29; // edi
  int v30; // edi
  int v31; // ebx
  vgui::Panel *v32; // esi
  int Wide; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // edi
  int v37; // ebx
  vgui::Panel *v38; // esi
  int Tall; // eax
  int v40; // ebx
  float v41; // xmm0_4
  int v42; // esi
  int v43; // kr00_4
  int v44; // edi
  int v45; // eax
  vgui::Panel *v46; // ecx
  int v47; // edi
  int v48; // eax
  int v49; // eax
  const unsigned __int16 *v51; // [esp-Ch] [ebp-4B4h]
  int v53; // [esp-4h] [ebp-4ACh]
  wchar_t wszBuf[256]; // [esp+8h] [ebp-4A0h] BYREF
  wchar_t token[256]; // [esp+208h] [ebp-2A0h] BYREF
  char friendlyName[64]; // [esp+408h] [ebp-A0h] BYREF
  char binding[64]; // [esp+448h] [ebp-60h] BYREF
  _BYTE v58[4]; // [esp+488h] [ebp-20h] BYREF
  int widest2; // [esp+48Ch] [ebp-1Ch]
  int ox; // [esp+490h] [ebp-18h] BYREF
  int oy; // [esp+494h] [ebp-14h] BYREF
  int tallest; // [esp+498h] [ebp-10h]
  bool bIsBitmap; // [esp+49Fh] [ebp-9h]
  int col2_x; // [esp+4A0h] [ebp-8h]
  int col1_x; // [esp+4A4h] [ebp-4h]
  int i; // [esp+4B0h] [ebp+8h]
  int ia; // [esp+4B0h] [ebp+8h]
  char i_3; // [esp+4B3h] [ebp+Bh]

  col1_x = (int)this;
  if ( text == nullptr || *text == 0 )
    return 0;
  for ( j = 0; j < this->m_Labels.m_Size; ++j )
  {
    v5 = this->m_Labels.m_Memory.m_pMemory[j];
    v5->MarkForDeletion(this: v5);
  }
  this->m_Labels.m_Size = 0;
  v6 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: text);
  v7 = v6;
  tallest = (int)v6;
  if ( v6 == nullptr )
    goto LABEL_9;
  v8 = v6 + 1;
  do
    v9 = *v6++;
  while ( v9 != 0 );
  if ( v6 - v8 == 0 )
  {
LABEL_9:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: text, a3: wszBuf, a4: 512);
    v7 = wszBuf;
    tallest = (int)wszBuf;
  }
  if ( *v7 != 0 )
  {
    do
    {
      v10 = (const wchar_t *)tallest;
      i_3 = 0;
      if ( *(_WORD *)tallest == 37 )
      {
        i_3 = 1;
        v10 = (const wchar_t *)(tallest + 2);
      }
      v11 = wcschr(string: v10, ch: 0x25u);
      if ( v11 != nullptr )
      {
        v12 = v11 - v10;
        v13 = v12;
        if ( v12 >= 0x100 )
          v13 = 256;
        wcsncpy(dest: token, source: v10, count: v13);
        token[v12] = 0;
      }
      else
      {
        wcsncpy(dest: token, source: v10, count: 0x100u);
        token[255] = 0;
      }
      tallest = (int)&v10[wcslen(token)];
      if ( i_3 != 0 )
        tallest += 2;
      v14 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
      v15 = (_DWORD *)col1_x;
      if ( v14 != nullptr )
        v16 = vgui::Label::Label(this: v14, parent: (vgui::Panel *)col1_x, panelName: nullptr, wszText: token);
      else
        v16 = nullptr;
      vgui::Panel::MakeReadyForUse(this: v16);
      SetFont = v16->SetFont;
      bIsBitmap = false;
      if ( i_3 != 0 )
      {
        ((void (__thiscall *)(vgui::Label *, _DWORD, int))SetFont)(a1: v16, a2: v15[104], a3: a2);
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: token, a3: binding, a4: 64);
        v18 = &binding[1];
        if ( binding[0] != 43 )
          v18 = binding;
        v19 = engine->Key_LookupBinding(this: engine, a2: v18);
        if ( v19 == nullptr )
          v19 = "< not bound >";
        V_snprintf(pDest: friendlyName, maxLen: 0x40u, pFormat: "#%s", v19);
        _V_strupr(start: friendlyName);
        v20 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: friendlyName);
        if ( v20 != nullptr && wcslen(v20) != 0 )
        {
          v51 = v20;
          SetText = v16->SetText;
          bIsBitmap = true;
          ((void (__thiscall *)(vgui::Label *, const unsigned __int16 *, _DWORD, int))SetText)(
            a1: v16,
            a2: v51,
            a3: 0,
            a4: v53);
        }
        else
        {
          ((void (__thiscall *)(vgui::Label *, char *, int))v16->SetText)(a1: v16, a2: &friendlyName[1], a3: v53);
        }
      }
      else
      {
        ((void (__thiscall *)(vgui::Label *, _DWORD, int))SetFont)(a1: v16, a2: v15[103], a3: a2);
      }
      v16->SetPaintBackgroundEnabled(this: v16, a2: false);
      v16->SetPaintBorderEnabled(this: v16, a2: false);
      v16->SizeToContents(this: v16);
      v16->SetContentAlignment(this: v16, a2: a_west);
      if ( bIsBitmap && i_3 != 0 )
      {
        SetFgColor = v16->SetFgColor;
        col2_x = -1;
        a2 = -1;
        ((void (__thiscall *)(vgui::Label *))SetFgColor)(a1: v16);
      }
      else
      {
        v23 = v16->__vftable;
        a2 = *(_DWORD *)(*(int (__thiscall **)(_DWORD *, _BYTE *))(*v15 + 248))(a1: v15, a2: v58);
        ((void (__thiscall *)(vgui::Label *))v23->SetFgColor)(a1: v16);
      }
      vgui::Panel::MakeReadyForUse(this: v16);
      v24 = (_DWORD *)col1_x;
      v25 = *(_DWORD *)(col1_x + 404);
      v26 = *(_DWORD *)(col1_x + 396);
      if ( v25 + 1 > v26 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)(col1_x + 392),
          num: v25 - v26 + 1);
      ++v24[101];
      v27 = v24[98];
      v28 = v24[101] - v25 - 1;
      v24[102] = v27;
      if ( v28 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)(v27 + 4 * v25 + 4),
          src: (unsigned __int8 *)(v27 + 4 * v25),
          count: 4 * v28);
      v29 = (vgui::Label **)(v24[98] + 4 * v25);
      if ( v29 != nullptr )
        *v29 = v16;
    }
    while ( *(_WORD *)tallest != 0 );
  }
  v30 = 0;
  v31 = 0;
  col2_x = 0;
  widest2 = 0;
  if ( *(int *)(col1_x + 404) > 0 )
  {
    do
    {
      v32 = *(vgui::Panel **)(*(_DWORD *)(col1_x + 392) + 4 * v31);
      Wide = vgui::Panel::GetWide(this: v32);
      if ( (v31 & 1) != 0 )
      {
        if ( Wide > v30 )
          v30 = vgui::Panel::GetWide(this: v32);
      }
      else if ( Wide > col2_x )
      {
        col2_x = vgui::Panel::GetWide(this: v32);
      }
      ++v31;
    }
    while ( v31 < *(_DWORD *)(col1_x + 404) );
    widest2 = v30;
  }
  v34 = col1_x;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  i = 0;
  if ( *(int *)(col1_x + 404) <= 0 )
    goto LABEL_60;
  do
  {
    v38 = *(vgui::Panel **)(*(_DWORD *)(v34 + 392) + 4 * v37);
    Tall = vgui::Panel::GetTall(this: v38);
    if ( (v37 & 1) != 0 )
    {
      if ( Tall > i )
        i = vgui::Panel::GetTall(this: v38);
    }
    else if ( Tall > v36 )
    {
      v36 = vgui::Panel::GetTall(this: v38);
    }
    v34 = col1_x;
    ++v37;
  }
  while ( v37 < *(_DWORD *)(col1_x + 404) );
  v35 = i;
  tallest = v36;
  if ( v36 <= i )
LABEL_60:
    tallest = v35;
  v40 = col1_x;
  v41 = *(float *)(col1_x + 428);
  v42 = (int)*(float *)(col1_x + 436);
  col2_x = (int)(float)((float)((float)col2_x + v41) + *(float *)(col1_x + 444));
  col1_x = (int)v41;
  v43 = v36 - v35;
  v44 = (v36 - v35) / 2;
  if ( v43 / 2 < 0 )
    v42 -= v44;
  v45 = 0;
  ia = 0;
  if ( *(int *)(v40 + 404) > 0 )
  {
    while ( 1 )
    {
      v46 = *(vgui::Panel **)(*(_DWORD *)(v40 + 392) + 4 * v45);
      if ( (v45 & 1) != 0 )
      {
        vgui::Panel::SetPos(this: v46, x: col2_x, y: v44 + v42);
        v42 = (int)(float)((float)(tallest + v42) + *(float *)(v40 + 452));
      }
      else
      {
        vgui::Panel::SetPos(this: v46, x: col1_x, y: v42);
      }
      if ( ++ia >= *(_DWORD *)(v40 + 404) )
        break;
      v45 = ia;
    }
  }
  v47 = (int)(float)((float)(widest2 + col2_x) + *(float *)(v40 + 428));
  vgui::Panel::GetPos(this: (vgui::Panel *)v40, x: &ox, y: &oy);
  if ( vgui::Panel::IsRightAligned(this: (vgui::Panel *)v40) )
  {
    v48 = vgui::Panel::GetWide(this: (vgui::Panel *)v40);
    ox -= v47 - v48;
  }
  if ( vgui::Panel::IsBottomAligned(this: (vgui::Panel *)v40) )
  {
    v49 = vgui::Panel::GetTall(this: (vgui::Panel *)v40);
    oy -= v42 - v49;
  }
  vgui::Panel::SetPos(this: (vgui::Panel *)v40, x: ox, y: oy);
  vgui::Panel::SetSize(this: (vgui::Panel *)v40, wide: v47, tall: v42);
  *(_DWORD *)(v40 + 420) = oy;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101044C0
// Name: public: void CHudHintKeyDisplay::MsgFunc_KeyHintText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintKeyDisplay::MsgFunc_KeyHintText(CHudHintKeyDisplay *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v5; // esi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // edi
  int v11; // edx
  const unsigned int *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v16; // eax
  const char *v17; // [esp-4h] [ebp-814h]
  char szString[2048]; // [esp+Ch] [ebp-804h] BYREF
  CHudHintKeyDisplay *v19; // [esp+80Ch] [ebp-4h]

  m_nBitsAvail = msg->m_nBitsAvail;
  v19 = this;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = msg->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    msg->m_nBitsAvail = m_nBitsAvail - 8;
    if ( m_nBitsAvail == 8 )
    {
      m_pDataIn = msg->m_pDataIn;
      m_pBufferEnd = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v8 = *m_pDataIn;
        msg->m_pDataIn = m_pDataIn + 1;
        msg->m_nInBufWord = v8;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    else
    {
      msg->m_nInBufWord = m_nInBufWord >> 8;
    }
    goto LABEL_17;
  }
  v9 = msg->m_pBufferEnd;
  v10 = msg->m_nInBufWord;
  v11 = 8 - m_nBitsAvail;
  v12 = msg->m_pDataIn;
  if ( v12 == v9 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
LABEL_14:
    msg->m_pDataIn = v12 + 1;
    goto LABEL_15;
  }
  if ( v12 <= v9 )
  {
    msg->m_nInBufWord = *v12;
    goto LABEL_14;
  }
  msg->m_bOverflow = true;
  msg->m_nInBufWord = 0;
LABEL_15:
  if ( msg->m_bOverflow )
  {
LABEL_18:
    DevMsg(a1: "CHudHintKeyDisplay::MsgFunc_KeyHintText: string count != 1.\n");
    return;
  }
  v13 = msg->m_nInBufWord;
  v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
  msg->m_nBitsAvail = 32 - v11;
  msg->m_nInBufWord = v13 >> v11;
  v5 = v14 | v10;
  this = v19;
LABEL_17:
  if ( v5 != 1 )
    goto LABEL_18;
  CBitRead::ReadString(this: msg, pStr: szString, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
  if ( CHudHintKeyDisplay::SetHintText(this, a2: 1, text: szString) != 0 )
  {
    this->SetVisible(this, a2: true);
    ClientMode = GetClientMode();
    v17 = "KeyHintMessageShow";
  }
  else
  {
    ClientMode = GetClientMode();
    v17 = "KeyHintMessageHide";
  }
  v16 = ClientMode->GetViewportAnimationController(this: ClientMode);
  vgui::AnimationController::StartAnimationSequence(this: v16, sequenceName: v17);
}

//------------------------------------------------------------------------------
// Address: 0x10104630
// Name: Create_CHudHintDisplay
// Source: json
//------------------------------------------------------------------------------
CHudElement *__cdecl Create_CHudHintDisplay()
{
  unsigned __int8 *v0; // esi
  CHudHintDisplay *v1; // eax

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 464);
  memset(dst: v0, value: 0, count: 0x1D0u);
  if ( v0 != nullptr
    && (v1 = CHudHintDisplay::CHudHintDisplay(this: (CHudHintDisplay *)v0, pElementName: "CHudHintDisplay")) != nullptr )
  {
    return &v1->CHudElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104680
// Name: public: virtual void CHudHintDisplay::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintDisplay::Reset(CHudHintDisplay *this)
{
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v3; // eax

  CHudHintDisplay::SetHintText(this: (CHudHintDisplay *)((char *)this - 332), text: nullptr);
  ClientMode = GetClientMode();
  v3 = ClientMode->GetViewportAnimationController(this: ClientMode);
  vgui::AnimationController::StartAnimationSequence(this: v3, sequenceName: "HintMessageHide");
  LOBYTE(this->m_OverridableColorEntries.m_Memory.m_nAllocationCount) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101046B0
// Name: public: virtual void CHudHintDisplay::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintDisplay::FireGameEvent(CHudHintDisplay *this, IGameEvent *event)
{
  const char *v3; // esi
  const char *v4; // eax

  v3 = event->GetString(this: event, a2: "hintmessage", a3: prType);
  v4 = hudtextmessage->LookupString(this: hudtextmessage, a2: v3, a3: 0);
  CHudHintDisplay::LocalizeAndDisplay(this: (CHudHintDisplay *)((char *)this - 332), pszHudTxtMsg: v4, szRawString: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101046F0
// Name: Create_CHudHintKeyDisplay
// Source: json
//------------------------------------------------------------------------------
CHudElement *__cdecl Create_CHudHintKeyDisplay()
{
  unsigned __int8 *v0; // esi
  CHudHintKeyDisplay *v1; // eax

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 464);
  memset(dst: v0, value: 0, count: 0x1D0u);
  if ( v0 != nullptr
    && (v1 = CHudHintKeyDisplay::CHudHintKeyDisplay(this: (CHudHintKeyDisplay *)v0, pElementName: "CHudHintKeyDisplay")) != nullptr )
  {
    return &v1->CHudElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104740
// Name: void __MsgFunc_CHudHintKeyDisplay_KeyHintText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudHintKeyDisplay_KeyHintText(bf_read *msg)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudHintKeyDisplay");
  if ( Element != nullptr )
    CHudHintKeyDisplay::MsgFunc_KeyHintText(this: (CHudHintKeyDisplay *)&Element[-6].m_nDebugID, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10104770
// Name: public: virtual void CHudHintKeyDisplay::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintKeyDisplay::Init(CHudHintKeyDisplay *this)
{
  CUserMessages::HookMessage(this: usermessages, name: "KeyHintText", hook: __MsgFunc_CHudHintKeyDisplay_KeyHintText);
}

//------------------------------------------------------------------------------
// Address: 0x10104790
// Name: public: virtual void CHudHintKeyDisplay::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintKeyDisplay::Reset(CHudHintKeyDisplay *this)
{
  vgui::Panel::SetAlpha(this: (CHudHintKeyDisplay *)((char *)this - 332), alpha: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101047A0
// Name: void __MsgFunc_CHudHintDisplay_HintText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudHintDisplay_HintText(bf_read *msg)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHudHintDisplay *p_m_nDebugID; // esi
  const char *v4; // eax
  char pStr[256]; // [esp+0h] [ebp-100h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudHintDisplay");
  if ( Element != nullptr )
  {
    p_m_nDebugID = (CHudHintDisplay *)&Element[-6].m_nDebugID;
    CBitRead::ReadString(this: msg, pStr, maxLen: 255, bLine: false, pOutNumChars: nullptr);
    v4 = hudtextmessage->LookupString(this: hudtextmessage, a2: pStr, a3: 0);
    CHudHintDisplay::LocalizeAndDisplay(this: p_m_nDebugID, pszHudTxtMsg: v4, szRawString: pStr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104810
// Name: public: virtual void CHudHintDisplay::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHintDisplay::Init(CHudHintDisplay *this)
{
  CUserMessages::HookMessage(this: usermessages, name: "HintText", hook: __MsgFunc_CHudHintDisplay_HintText);
  this->m_OnCommand_register = (vgui::Panel::PanelMessageFunc_OnCommand)1;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: (IGameEventListener2 *)this,
    a3: "player_hintmessage",
    a4: false);
}
