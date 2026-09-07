// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/menu.cpp
// Functions: 39
// ============================================================

#include "game\client\menu.h"

//------------------------------------------------------------------------------
// Address: 0x1011E200
// Name: public: static char const __near * CHudMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudMenu::GetPanelClassName()
{
  return "CHudMenu";
}

//------------------------------------------------------------------------------
// Address: 0x1011E210
// Name: private: static void __near * CHudMenu::GetVar_m_flOpenCloseTime(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudMenu::GetVar_m_flOpenCloseTime(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_infoFont;
  else
    return (void *)452;
}

//------------------------------------------------------------------------------
// Address: 0x1011E230
// Name: private: static void __near * CHudMenu::GetVar_m_flBlur(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudMenu::GetVar_m_flBlur(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._vpanel;
  else
    return (void *)460;
}

//------------------------------------------------------------------------------
// Address: 0x1011E250
// Name: private: static void __near * CHudMenu::GetVar_m_flTextScan(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudMenu::GetVar_m_flTextScan(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._panelName.m_Storage.m_Memory.m_nAllocationCount;
  else
    return (void *)468;
}

//------------------------------------------------------------------------------
// Address: 0x1011E270
// Name: private: static void __near * CHudMenu::GetVar_m_flAlphaOverride(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudMenu::GetVar_m_flAlphaOverride(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._panelName.m_Storage.m_nActualLength;
  else
    return (void *)476;
}

//------------------------------------------------------------------------------
// Address: 0x1011E290
// Name: private: static void __near * CHudMenu::GetVar_m_flSelectionAlphaOverride(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFlags<unsigned short> *__cdecl CHudMenu::GetVar_m_flSelectionAlphaOverride(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._flags;
  else
    return (CUtlFlags<unsigned short> *)484;
}

//------------------------------------------------------------------------------
// Address: 0x1011E2B0
// Name: private: static void __near * CHudMenu::GetVar_m_hTextFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudMenu::GetVar_m_hTextFont(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._actionSignalTargetDar.m_Memory.m_nAllocationCount;
  else
    return (void *)492;
}

//------------------------------------------------------------------------------
// Address: 0x1011E2D0
// Name: private: static void __near * CHudMenu::GetVar_m_hItemFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudMenu::GetVar_m_hItemFont(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._actionSignalTargetDar.m_Size;
  else
    return (void *)500;
}

//------------------------------------------------------------------------------
// Address: 0x1011E2F0
// Name: private: static void __near * CHudMenu::GetVar_m_hItemFontPulsing(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *__cdecl CHudMenu::GetVar_m_hItemFontPulsing(
        vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OverridableColorEntries;
  else
    return (CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *)508;
}

//------------------------------------------------------------------------------
// Address: 0x1011E310
// Name: private: static void __near * CHudMenu::GetVar_m_MenuColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudMenu::GetVar_m_MenuColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1].m_OverridableColorEntries.m_Memory.m_nAllocationCount + 1;
  else
    return 513;
}

//------------------------------------------------------------------------------
// Address: 0x1011E330
// Name: private: static void __near * CHudMenu::GetVar_m_ItemColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudMenu::GetVar_m_ItemColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1].m_OverridableColorEntries.m_Memory.m_nGrowSize + 2;
  else
    return 518;
}

//------------------------------------------------------------------------------
// Address: 0x1011E350
// Name: private: static void __near * CHudMenu::GetVar_m_BoxColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudMenu::GetVar_m_BoxColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1].m_OverridableColorEntries.m_Size + 3;
  else
    return 523;
}

//------------------------------------------------------------------------------
// Address: 0x1011E370
// Name: public: virtual void CHudMenu::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMenu::Reset(CHudMenu *this)
{
  g_szPrelocalisedMenuString[0] = 0;
  this->m_fWaitingForMore = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011E380
// Name: public: bool CHudMenu::IsMenuOpen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHudMenu::IsMenuOpen(CHudMenu *this)
{
  return this->m_bMenuDisplayed && this->m_bMenuTakesInput;
}

//------------------------------------------------------------------------------
// Address: 0x1011E3A0
// Name: private: virtual void CHudMenu::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMenu::OnThink(CHudMenu *this)
{
  if ( *(_BYTE *)&this->m_m_nBgTextureId3_register != 0
    && (float)(*(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_RegisterClass) > 5.0 )
  {
    this->m_m_nBgTextureId3_register = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E3D0
// Name: public: virtual bool CHudMenu::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudMenu::ShouldDraw(CHudMenu *this)
{
  float m_flShutoffTime; // xmm0_4

  if ( CHudElement::ShouldDraw(this) == 0 || !this->m_bMenuDisplayed )
    return 0;
  m_flShutoffTime = this->m_flShutoffTime;
  if ( m_flShutoffTime > 0.0 && *(float *)gpGlobals.m_Index >= m_flShutoffTime )
  {
    this->m_bMenuDisplayed = false;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011E420
// Name: public: void CHudMenu::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMenu::SelectMenuItem(CHudMenu *this, int menu_item)
{
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v4; // eax
  float m_flOpenCloseTime; // xmm0_4
  IClientMode *v6; // eax
  vgui::AnimationController *v7; // eax
  char szbuf[32]; // [esp+8h] [ebp-20h] BYREF

  if ( menu_item > 0 && ((1 << (menu_item - 1)) & this->m_bitsValidSlots) != 0 )
  {
    V_snprintf(pDest: szbuf, maxLen: 0x20u, pFormat: "menuselect %d\n", menu_item);
    ((void (__thiscall *)(IVEngineClient *))engine->ClientCmd)(a1: engine);
    this->m_nSelectedItem = menu_item;
    ClientMode = GetClientMode();
    v4 = (vgui::AnimationController *)((int (__thiscall *)(IClientMode *, const char *))ClientMode->GetViewportAnimationController)(
                                        a1: ClientMode,
                                        a2: "MenuPulse");
    vgui::AnimationController::StartAnimationSequence(this: v4, sequenceName: szbuf);
    m_flOpenCloseTime = this->m_flOpenCloseTime;
    this->m_bMenuTakesInput = false;
    this->m_flShutoffTime = m_flOpenCloseTime + *(float *)gpGlobals.m_Index;
    v6 = GetClientMode();
    v7 = v6->GetViewportAnimationController(this: v6);
    vgui::AnimationController::StartAnimationSequence(this: v7, sequenceName: "MenuClose");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E4E0
// Name: private: virtual void CHudMenu::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHudMenu::Paint(CHudMenu *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  Color v4; // eax
  Color v5; // ecx
  int v6; // edx
  int m_nBgTextureId2; // esi
  int v8; // edi
  int v9; // eax
  void (__thiscall *SetHiddenBits)(struct CHudMenu *, int); // edx
  float v11; // xmm0_4
  CHudMenu::ProcessedLine *v12; // edi
  Color *p_itemColor; // ecx
  int menuitem; // eax
  Color v15; // edx
  int v16; // ecx
  int length; // esi
  float m_flSelectionTime; // eax
  unsigned int *p_m_flSelectionTime; // eax
  int m_Size; // xmm0_4
  int j; // edi
  int i; // edi
  int v23; // [esp-4h] [ebp-44h]
  float v24; // [esp+0h] [ebp-40h]
  wchar_t *v27; // [esp+14h] [ebp-2Ch]
  wchar_t *v28; // [esp+14h] [ebp-2Ch]
  wchar_t *v29; // [esp+14h] [ebp-2Ch]
  int c; // [esp+18h] [ebp-28h]
  CHudMenu::ProcessedLine *line; // [esp+1Ch] [ebp-24h]
  float fl; // [esp+20h] [ebp-20h]
  Color clr; // [esp+24h] [ebp-1Ch]
  int v34; // [esp+28h] [ebp-18h]
  Color col; // [esp+2Ch] [ebp-14h]
  Color cola; // [esp+2Ch] [ebp-14h]
  Color menuColor; // [esp+30h] [ebp-10h] BYREF
  Color itemColor; // [esp+34h] [ebp-Ch] BYREF
  int y; // [esp+38h] [ebp-8h]
  bool canblur; // [esp+3Fh] [ebp-1h]

  if ( *(_BYTE *)&this->m_m_nBgTextureId3_register != 0 )
  {
    v4 = *(Color *)(&this->m_m_flBlur_register + 1);
    v5 = *(Color *)((char *)&this->m_flBlur + 2);
    v6 = *(_DWORD *)&this->m_m_nBgTextureId1_register;
    m_nBgTextureId2 = this->m_nBgTextureId2;
    v8 = *(_DWORD *)&this->m_m_nBgTextureId2_register;
    menuColor = v4;
    itemColor = v5;
    c = v6;
    m_nBgTextureId2 += 20;
    v9 = ScreenHeight();
    SetHiddenBits = this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[7].SetHiddenBits;
    v24 = this->m_flShutoffTime * 0.0039215689;
    v23 = *(_DWORD *)(&this->m_m_flTextScan_register + 3);
    y = (int)(float)((float)(v9 - m_nBgTextureId2) * 0.5);
    ((void (__thiscall *)(CHudMenu *, int, int, int, int, int, _DWORD, _DWORD))SetHiddenBits)(
      a1: this,
      a2: 10,
      a3: y - 10,
      a4: v8 + 20,
      a5: m_nBgTextureId2,
      a6: v23,
      a7: LODWORD(v24),
      a8: 0);
    v11 = this->m_flShutoffTime * 0.0039215689;
    itemColor._color[3] = (int)(float)((float)itemColor._color[3] * v11);
    menuColor._color[3] = (int)(float)((float)menuColor._color[3] * v11);
    if ( c > 0 )
    {
      v34 = 0;
      do
      {
        v12 = (CHudMenu::ProcessedLine *)(v34 + LODWORD(this->m_flAlpha));
        p_itemColor = &itemColor;
        menuitem = v12->menuitem;
        line = v12;
        if ( v12->menuitem == 0 )
          p_itemColor = &menuColor;
        v15 = *p_itemColor;
        clr = *p_itemColor;
        canblur = false;
        if ( menuitem != 0 )
        {
          v16 = *(_DWORD *)&this->m_roundedCorners;
          if ( v16 >= 0 )
            canblur = menuitem == v16;
        }
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
          a1: g_pVGuiSurface,
          a2: v15,
          a3: a2,
          a4: a3);
        length = v12->length;
        if ( v12->menuitem != 0 )
        {
          m_flSelectionTime = this->m_flSelectionTime;
          length = (int)(float)((float)length * *(float *)&this->m_nMaxPixels);
        }
        else
        {
          m_flSelectionTime = *(float *)&this->m_nSelectedItem;
        }
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: LODWORD(m_flSelectionTime));
        p_m_flSelectionTime = (unsigned int *)&this->m_flSelectionTime;
        if ( v12->menuitem == 0 )
          p_m_flSelectionTime = (unsigned int *)&this->m_nSelectedItem;
        v27 = &g_szMenuString[v12->startchar];
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: *p_m_flSelectionTime);
        a3 = y;
        a2 = 20;
        ((void (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->DrawSetTextPos)(a1: g_pVGuiSurface);
        for ( col = 0; *(_DWORD *)&col < length; ++*(_DWORD *)&col )
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v27[*(_DWORD *)&col], a3: FONT_DRAW_DEFAULT);
        if ( canblur )
        {
          m_Size = this->m_Processed.m_Size;
          for ( fl = *(float *)&m_Size; fl > 0.0; fl = fl - 1.0 )
          {
            if ( *(float *)&m_Size < 1.0 )
            {
              cola = clr;
              cola._color[3] = (int)(float)((float)clr._color[3] * *(float *)&m_Size);
              ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: cola);
              v29 = &g_szMenuString[v12->startchar];
              g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: LODWORD(this->m_flOpenCloseTime));
              g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: 20, a3: y);
              for ( i = 0; i < length; ++i )
                ((void (__stdcall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawUnicodeChar)(a1: v29[i], a2: 0);
            }
            else
            {
              v28 = &g_szMenuString[v12->startchar];
              g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: LODWORD(this->m_flOpenCloseTime));
              g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: 20, a3: y);
              for ( j = 0; j < length; ++j )
                ((void (__stdcall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawUnicodeChar)(a1: v28[j], a2: 0);
            }
            v12 = line;
            *(float *)&m_Size = fl - 1.0;
          }
        }
        y += v12->height;
        v34 += 20;
        --c;
      }
      while ( c != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E830
// Name: public: static void CHudMenu::PanelAnimationVar_m_flOpenCloseTime::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_flOpenCloseTime::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_flOpenCloseTime::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_flOpenCloseTime::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "OpenCloseTime";
    src.m_pszVariable = "m_flOpenCloseTime";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "1";
    src.m_pfnLookup = CHudMenu::GetVar_m_flOpenCloseTime;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E890
// Name: public: static void CHudMenu::PanelAnimationVar_m_flBlur::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_flBlur::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_flBlur::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_flBlur::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "Blur";
    src.m_pszVariable = "m_flBlur";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = CHudMenu::GetVar_m_flBlur;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E8F0
// Name: public: static void CHudMenu::PanelAnimationVar_m_flTextScan::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_flTextScan::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_flTextScan::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_flTextScan::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextScane";
    src.m_pszVariable = "m_flTextScan";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "1";
    src.m_pfnLookup = CHudMenu::GetVar_m_flTextScan;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E950
// Name: public: static void CHudMenu::PanelAnimationVar_m_flAlphaOverride::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_flAlphaOverride::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_flAlphaOverride::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_flAlphaOverride::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "Alpha";
    src.m_pszVariable = "m_flAlphaOverride";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "255.0";
    src.m_pfnLookup = CHudMenu::GetVar_m_flAlphaOverride;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E9B0
// Name: public: static void CHudMenu::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "SelectionAlpha";
    src.m_pszVariable = "m_flSelectionAlphaOverride";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "255.0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudMenu::GetVar_m_flSelectionAlphaOverride;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EA10
// Name: public: static void CHudMenu::PanelAnimationVar_m_hTextFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_hTextFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_hTextFont::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_hTextFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextFont";
    src.m_pszVariable = "m_hTextFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "MenuTextFont";
    src.m_pfnLookup = CHudMenu::GetVar_m_hTextFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EA70
// Name: public: static void CHudMenu::PanelAnimationVar_m_hItemFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_hItemFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_hItemFont::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_hItemFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemFont";
    src.m_pszVariable = "m_hItemFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "MenuItemFont";
    src.m_pfnLookup = CHudMenu::GetVar_m_hItemFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EAD0
// Name: public: static void CHudMenu::PanelAnimationVar_m_hItemFontPulsing::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_hItemFontPulsing::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_hItemFontPulsing::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_hItemFontPulsing::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemFontPulsing";
    src.m_pszVariable = "m_hItemFontPulsing";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "MenuItemFontPulsing";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudMenu::GetVar_m_hItemFontPulsing;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EB30
// Name: public: static void CHudMenu::PanelAnimationVar_m_ItemColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_ItemColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_ItemColor::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_ItemColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "MenuItemColor";
    src.m_pszVariable = "m_ItemColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "ItemColor";
    src.m_pfnLookup = CHudMenu::GetVar_m_ItemColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EB90
// Name: public: static void CHudMenu::PanelAnimationVar_m_BoxColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudMenu::PanelAnimationVar_m_BoxColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudMenu::PanelAnimationVar_m_BoxColor::InitVar'::`2'::bAdded )
  {
    `CHudMenu::PanelAnimationVar_m_BoxColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "MenuBoxColor";
    src.m_pszVariable = "m_BoxColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "MenuBoxBg";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudMenu::GetVar_m_BoxColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EBF0
// Name: public: CHudMenu::CHudMenu(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudMenu *__thiscall CHudMenu::CHudMenu(CHudMenu *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  PanelAnimationMap *v6; // eax
  int m_Size; // edx
  IClientMode *ClientMode; // eax
  vgui::Panel *v9; // eax
  PanelAnimationMapEntry src; // [esp+Ch] [ebp-18h] BYREF

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudMenu");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudMenu_vtbl *)&CHudMenu::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudMenu::`vftable'{for `vgui::Panel'};
  if ( `CHudMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CHudMenu::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudMenu");
    v3->pfnClassName = CHudMenu::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudMenu::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    v4->pfnClassName = CHudMenu::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudMenu::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudMenu");
    v5->pfnClassName = CHudMenu::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_Processed.m_Memory.m_pMemory = nullptr;
  this->m_Processed.m_Memory.m_nAllocationCount = 0;
  this->m_Processed.m_Memory.m_nGrowSize = 0;
  this->m_Processed.m_Size = 0;
  this->m_Processed.m_pElements = nullptr;
  CHudMenu::PanelAnimationVar_m_flOpenCloseTime::InitVar();
  CHudMenu::PanelAnimationVar_m_flBlur::InitVar();
  CHudMenu::PanelAnimationVar_m_flTextScan::InitVar();
  CHudMenu::PanelAnimationVar_m_flAlphaOverride::InitVar();
  CHudMenu::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar();
  CHudMenu::PanelAnimationVar_m_hTextFont::InitVar();
  CHudMenu::PanelAnimationVar_m_hItemFont::InitVar();
  CHudMenu::PanelAnimationVar_m_hItemFontPulsing::InitVar();
  if ( `CHudMenu::PanelAnimationVar_m_MenuColor::InitVar'::`2'::bAdded == 0 )
  {
    `CHudMenu::PanelAnimationVar_m_MenuColor::InitVar'::`2'::bAdded = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CHudMenu");
    m_Size = v6->entries.m_Size;
    src.m_pszScriptName = "MenuColor";
    src.m_pszDefaultValue = "MenuColor";
    src.m_pszVariable = "m_MenuColor";
    src.m_pszType = "Color";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudMenu::GetVar_m_MenuColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v6->entries,
      elem: m_Size,
      &src);
  }
  this->m_MenuColor = 0;
  CHudMenu::PanelAnimationVar_m_ItemColor::InitVar();
  this->m_ItemColor = 0;
  CHudMenu::PanelAnimationVar_m_BoxColor::InitVar();
  this->m_BoxColor = 0;
  this->m_nSelectedItem = -1;
  ClientMode = GetClientMode();
  v9 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v9);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011EDC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudMenu::GetMessageMap(CHudMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudMenu::GetMessageMap'::`2'::s_pMap;
  `CHudMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudMenu");
  `CHudMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011EDF0
// Name: public: virtual struct PanelAnimationMap __near * CHudMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudMenu::GetAnimMap(CHudMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudMenu");
}

//------------------------------------------------------------------------------
// Address: 0x1011EE00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudMenu::GetKBMap(CHudMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudMenu::GetKBMap'::`2'::s_pMap;
  `CHudMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudMenu");
  `CHudMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011EE70
// Name: private: void CHudMenu::ProcessText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMenu::ProcessText(CHudMenu *this)
{
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Processed; // ebx
  int v2; // edi
  int v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v10; // ecx
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  int v14; // edi
  int m_Size; // eax
  vgui::CTreeViewListControl::CColumnInfo *v16; // esi
  int v17; // edi
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  CHudMenu *v21; // eax
  int v22; // [esp-8h] [ebp-40h]
  CHudMenu::ProcessedLine line; // [esp+Ch] [ebp-2Ch] BYREF
  int i; // [esp+20h] [ebp-18h]
  unsigned int v25; // [esp+24h] [ebp-14h]
  unsigned int font; // [esp+28h] [ebp-10h]
  int menuitem; // [esp+2Ch] [ebp-Ch] BYREF
  CHudMenu *v28; // [esp+30h] [ebp-8h]
  int pixels; // [esp+34h] [ebp-4h]

  p_m_Processed = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Processed;
  this->m_Processed.m_Size = 0;
  v28 = this;
  this->m_nMaxPixels = 0;
  this->m_nHeight = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  menuitem = 0;
  do
  {
    v5 = g_szMenuString[v2];
    if ( (_WORD)v5 == 0 )
      break;
    if ( v2 == v3 && v5 == 45 && word_10649232[v2] == 62 )
    {
      swscanf(string: &word_10649234[v2], format: L"%d", &menuitem);
      v4 = menuitem;
      v2 += 2;
      v3 += 2;
    }
    else
    {
      do
      {
        v6 = g_szMenuString[v2];
        if ( (_WORD)v6 == 0 )
          break;
        if ( v6 == 10 )
          break;
        ++v2;
      }
      while ( v2 < 512 );
      v7 = v2 - v3;
      if ( v2 - v3 >= 1 )
      {
        line.startchar = v3;
        m_pMemory = p_m_Processed[1].m_pMemory;
        line.length = v7;
        m_nAllocationCount = p_m_Processed->m_nAllocationCount;
        line.pixels = 0;
        line.menuitem = v4;
        if ( (int)&m_pMemory->m_Title.m_Id + 1 > m_nAllocationCount )
          CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
            this: p_m_Processed,
            num: (int)&m_pMemory->m_Title.m_Id - m_nAllocationCount + 1);
        ++p_m_Processed[1].m_pMemory;
        v10 = p_m_Processed->m_pMemory;
        v11 = (char *)p_m_Processed[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_Processed[1].m_nAllocationCount = (int)p_m_Processed->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v10[(int)m_pMemory + 1],
            src: (unsigned __int8 *)&v10[(_DWORD)m_pMemory],
            count: 20 * v11);
        v12 = (int)&p_m_Processed->m_pMemory[(_DWORD)m_pMemory];
        if ( v12 != 0 )
        {
          *(_QWORD *)v12 = *(_QWORD *)&line.menuitem;
          *(_QWORD *)(v12 + 8) = *(_QWORD *)&line.length;
          *(_DWORD *)(v12 + 16) = 0;
        }
      }
      v4 = 0;
      v13 = g_szMenuString[v2] == 10;
      menuitem = 0;
      if ( v13 )
        ++v2;
      v3 = v2;
    }
  }
  while ( v2 < 512 );
  v14 = v2 - v3;
  if ( v14 >= 1 )
  {
    line.menuitem = v4;
    v22 = (int)p_m_Processed[1].m_pMemory;
    line.startchar = v3;
    line.length = v14;
    line.pixels = 0;
    line.height = 0;
    CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
      this: (CUtlVector<CHudMenu::ProcessedLine,CUtlMemory<CHudMenu::ProcessedLine,int> > *)p_m_Processed,
      elem: v22,
      src: &line);
  }
  m_Size = v28->m_Processed.m_Size;
  if ( m_Size > 0 )
  {
    v25 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v16 = &p_m_Processed->m_pMemory[v25 / 0x14];
      v17 = 0;
      pixels = 0;
      if ( *(_DWORD *)&v16->m_Title.m_Id != 0 )
        font = v28->m_hItemFont;
      else
        font = v28->m_hTextFont;
      if ( v16->m_Left > 0 )
      {
        do
        {
          v18 = ((int (__stdcall *)(unsigned int, _DWORD))g_pVGuiSurface->GetCharacterWidth)(
                  a1: font,
                  a2: g_szMenuString[v17 + v16->m_Width]);
          pixels += v18;
          ++v17;
        }
        while ( v17 < v16->m_Left );
      }
      v16->m_Right = pixels;
      v19 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: font);
      v20 = pixels;
      v16->m_ciFlags = v19;
      v21 = v28;
      if ( v20 > v28->m_nMaxPixels )
        v28->m_nMaxPixels = v20;
      v21->m_nHeight += v16->m_ciFlags;
      v25 += 20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F0B0
// Name: public: void CHudMenu::ShowMenu(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CHudMenu::ShowMenu(CHudMenu *this@<ecx>, int a2@<esi>, char *menuName, int validSlots)
{
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v6; // eax
  char *v7; // eax
  char *i; // ecx
  int (__thiscall *ConvertANSIToUnicode)(ILocalize *, const char *, wchar_t *, int); // edx
  char szMenuString[512]; // [esp+0h] [ebp-200h] BYREF
  const char *savedregs; // [esp+200h] [ebp+0h]

  this->m_flShutoffTime = -1.0;
  this->m_bitsValidSlots = validSlots;
  this->m_fWaitingForMore = 0;
  V_strncpy(pDest: g_szPrelocalisedMenuString, pSrc: menuName, maxLen: 512);
  ClientMode = GetClientMode();
  v6 = (vgui::AnimationController *)((int (__thiscall *)(IClientMode *, const char *, int))ClientMode->GetViewportAnimationController)(
                                      a1: ClientMode,
                                      a2: "MenuOpen",
                                      a3: a2);
  vgui::AnimationController::StartAnimationSequence(this: v6, sequenceName: savedregs);
  this->m_nSelectedItem = -1;
  v7 = hudtextmessage->BufferedLocaliseTextString(this: hudtextmessage, a2: g_szPrelocalisedMenuString);
  for ( i = v7; *i != 0; ++i )
  {
    if ( *i == 13 )
      *i = 10;
  }
  V_strncpy(pDest: szMenuString, pSrc: v7, maxLen: 512);
  ConvertANSIToUnicode = g_pVGuiLocalize->ConvertANSIToUnicode;
  *(_DWORD *)&szMenuString[508] = 1024;
  ((void (__thiscall *)(vgui::ILocalize *, char *, wchar_t *))ConvertANSIToUnicode)(
    a1: g_pVGuiLocalize,
    a2: szMenuString,
    a3: g_szMenuString);
  CHudMenu::ProcessText(this);
  this->m_bMenuDisplayed = true;
  this->m_bMenuTakesInput = true;
  this->m_flSelectionTime = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x1011F1A0
// Name: public: void CHudMenu::MsgFunc_ShowMenu(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMenu::MsgFunc_ShowMenu(CHudMenu *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  __int16 v5; // si
  int v6; // ecx
  __int16 v7; // cx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v13; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // ecx
  unsigned int v18; // edx
  char v19; // si
  int v20; // ecx
  char v21; // cl
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  int v31; // ebx
  int v32; // ecx
  unsigned int v33; // edx
  int v34; // esi
  int v35; // ecx
  int v36; // edi
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  unsigned int v39; // edx
  const unsigned int *v40; // esi
  unsigned int v41; // edi
  int v42; // edx
  const unsigned int *v43; // ecx
  unsigned int v44; // esi
  unsigned int v45; // ebx
  CHudMenu *v46; // esi
  CHudMenu *v47; // ecx
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v49; // eax
  char *v50; // eax
  char *i; // ecx
  double v52; // st7
  float m_flOpenCloseTime; // xmm0_4
  IClientMode *v54; // eax
  vgui::AnimationController *v55; // eax
  const char *v56; // [esp+0h] [ebp-A10h]
  char szString[2048]; // [esp+Ch] [ebp-A04h] BYREF
  char szMenuString[512]; // [esp+80Ch] [ebp-204h] BYREF
  CHudMenu *v59; // [esp+A0Ch] [ebp-4h]
  int DisplayTime; // [esp+A18h] [ebp+8h]

  v59 = this;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v13 = 16 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      v7 = 0;
    }
    else
    {
      v15 = msg->m_nInBufWord;
      v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v13;
      v7 = v16 | m_nInBufWord;
      msg->m_nInBufWord = v15 >> v13;
    }
    goto LABEL_19;
  }
  v4 = msg->m_nInBufWord;
  v5 = v4;
  v6 = m_nBitsAvail - 16;
  msg->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v4);
    v7 = v4;
  }
  else
  {
    v8 = msg->m_pDataIn;
    v9 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msg->m_pDataIn = v8 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v7 = v5;
    }
    else
    {
      if ( v8 <= v9 )
      {
        v10 = *v8;
        msg->m_pDataIn = v8 + 1;
        msg->m_nInBufWord = v10;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v7 = v5;
    }
  }
LABEL_19:
  v59->m_bitsValidSlots = v7;
  v17 = msg->m_nBitsAvail;
  if ( v17 < 8 )
  {
    v25 = msg->m_pBufferEnd;
    v26 = msg->m_nInBufWord;
    v27 = 8 - v17;
    v28 = msg->m_pDataIn;
    if ( v28 == v25 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v28;
    }
    msg->m_pDataIn = v28 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      v21 = 0;
    }
    else
    {
      v29 = msg->m_nInBufWord;
      v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v27;
      v21 = v30 | v26;
      msg->m_nInBufWord = v29 >> v27;
    }
    goto LABEL_37;
  }
  v18 = msg->m_nInBufWord;
  v19 = v18;
  v20 = v17 - 8;
  msg->m_nBitsAvail = v20;
  if ( v20 != 0 )
  {
    msg->m_nInBufWord = v18 >> 8;
    v21 = v18;
  }
  else
  {
    v22 = msg->m_pDataIn;
    v23 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      msg->m_pDataIn = v22 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v21 = v19;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v24 = *v22;
        msg->m_pDataIn = v22 + 1;
        msg->m_nInBufWord = v24;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v21 = v19;
    }
  }
LABEL_37:
  v31 = v21;
  v32 = msg->m_nBitsAvail;
  DisplayTime = v31;
  if ( v32 < 8 )
  {
    v40 = msg->m_pBufferEnd;
    v41 = msg->m_nInBufWord;
    v42 = 8 - v32;
    v43 = msg->m_pDataIn;
    if ( v43 == v40 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v43 > v40 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v43;
    }
    msg->m_pDataIn = v43 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      v36 = 0;
    }
    else
    {
      v44 = msg->m_nInBufWord;
      v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v42;
      v36 = v45 | v41;
      v31 = DisplayTime;
      msg->m_nInBufWord = v44 >> v42;
    }
    goto LABEL_55;
  }
  v33 = msg->m_nInBufWord;
  v34 = (unsigned __int8)v33;
  v35 = v32 - 8;
  msg->m_nBitsAvail = v35;
  if ( v35 != 0 )
  {
    msg->m_nInBufWord = v33 >> 8;
    v36 = (unsigned __int8)v33;
  }
  else
  {
    v37 = msg->m_pDataIn;
    v38 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v37 == v38 )
    {
      msg->m_nInBufWord = 0;
      msg->m_nBitsAvail = 1;
      msg->m_pDataIn = v37 + 1;
      v36 = v34;
    }
    else
    {
      if ( v37 <= v38 )
      {
        v39 = *v37;
        msg->m_pDataIn = v37 + 1;
        msg->m_nInBufWord = v39;
      }
      else
      {
        msg->m_nInBufWord = 0;
        msg->m_bOverflow = true;
      }
      v36 = v34;
    }
  }
LABEL_55:
  if ( v31 <= 0 )
  {
    v47 = v59;
    v59->m_flShutoffTime = -1.0;
    v46 = v47;
  }
  else
  {
    v46 = v59;
    v59->m_flShutoffTime = (float)((float)v31 + v59->m_flOpenCloseTime) + *(float *)gpGlobals.m_Index;
  }
  if ( v46->m_bitsValidSlots != 0 )
  {
    CBitRead::ReadString(this: msg, pStr: szString, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
    if ( v46->m_fWaitingForMore != 0 )
      V_strncat(pDest: g_szPrelocalisedMenuString, pSrc: szString, destBufferSize: 0x200u, max_chars_to_copy: -1);
    else
      V_strncpy(pDest: g_szPrelocalisedMenuString, pSrc: szString, maxLen: 512);
    if ( v36 == 0 )
    {
      ClientMode = GetClientMode();
      v49 = (vgui::AnimationController *)((int (__thiscall *)(IClientMode *, const char *))ClientMode->GetViewportAnimationController)(
                                           a1: ClientMode,
                                           a2: "MenuOpen");
      vgui::AnimationController::StartAnimationSequence(this: v49, sequenceName: v56);
      v46->m_nSelectedItem = -1;
      v50 = hudtextmessage->BufferedLocaliseTextString(this: hudtextmessage, a2: g_szPrelocalisedMenuString);
      for ( i = v50; *i != 0; ++i )
      {
        if ( *i == 13 )
          *i = 10;
      }
      V_strncpy(pDest: szMenuString, pSrc: v50, maxLen: 512);
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szMenuString, a3: g_szMenuString, a4: 1024);
      CHudMenu::ProcessText(this: v46);
    }
    v46->m_bMenuDisplayed = true;
    v46->m_bMenuTakesInput = true;
    v52 = *(float *)(gpGlobals.m_Index + 12);
    v46->m_fWaitingForMore = v36;
    v46->m_flSelectionTime = v52;
  }
  else
  {
    m_flOpenCloseTime = v46->m_flOpenCloseTime;
    v46->m_bMenuTakesInput = false;
    v46->m_flShutoffTime = m_flOpenCloseTime + *(float *)gpGlobals.m_Index;
    v54 = GetClientMode();
    v55 = v54->GetViewportAnimationController(this: v54);
    vgui::AnimationController::StartAnimationSequence(this: v55, sequenceName: "MenuClose");
    v46->m_fWaitingForMore = v36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F610
// Name: private: virtual void CHudMenu::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMenu::ApplySchemeSettings(CHudMenu *this, vgui::IScheme *pScheme)
{
  int x; // [esp+4h] [ebp-Ch] BYREF
  int screenWide; // [esp+8h] [ebp-8h] BYREF
  int y; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  ((void (__thiscall *)(CHudMenu *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].OnSplitScreenStateChanged)(
    a1: this,
    a2: 0);
  vgui::Panel::GetPos((vgui::Panel *)this, &x, &y);
  GetHudSize(w: &screenWide, h: (int *)&pScheme);
  vgui::Panel::SetBounds((vgui::Panel *)this, x: 0, y, wide: screenWide, tall: (int)pScheme - y);
  CHudMenu::ProcessText(this: (CHudMenu *)((char *)this - 56));
}

//------------------------------------------------------------------------------
// Address: 0x1011F680
// Name: Create_CHudMenu
// Source: json
//------------------------------------------------------------------------------
CHudMenu *__cdecl Create_CHudMenu()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 528);
  memset(dst: v0, value: 0, count: 0x210u);
  if ( v0 != nullptr )
    return CHudMenu::CHudMenu(this: (CHudMenu *)v0, pElementName: "CHudMenu");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011F6C0
// Name: void __MsgFunc_CHudMenu_ShowMenu(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudMenu_ShowMenu(bf_read *msg)
{
  CHud *Hud; // eax
  CHudMenu *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudMenu *)CHud::FindElement(this: Hud, pName: "CHudMenu");
  if ( Element != nullptr )
    CHudMenu::MsgFunc_ShowMenu(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x1011F6F0
// Name: public: virtual void CHudMenu::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudMenu::Init(CHudMenu *this)
{
  CUserMessages::HookMessage(this: usermessages, name: "ShowMenu", hook: __MsgFunc_CHudMenu_ShowMenu);
  this->m_bMenuTakesInput = false;
  this->m_bMenuDisplayed = false;
  this->m_bitsValidSlots = 0;
  this->m_Processed.m_Size = 0;
  this->m_nMaxPixels = 0;
  this->m_nHeight = 0;
  this->Reset(this);
}
