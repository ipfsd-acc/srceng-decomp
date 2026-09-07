// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hl2/hud_hdrdemo.cpp
// Functions: 43
// ============================================================

#include "game\client\hl2\hud_hdrdemo.h"

//------------------------------------------------------------------------------
// Address: 0x10102590
// Name: public: static char const __near * CHudHDRDemo::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudHDRDemo::GetPanelClassName()
{
  return "CHudHDRDemo";
}

//------------------------------------------------------------------------------
// Address: 0x101025A0
// Name: private: static void __near * CHudHDRDemo::GetVar_m_BorderColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::Panel_Register *__cdecl CHudHDRDemo::GetVar_m_BorderColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_RegisterAnimationClass;
  else
    return (vgui::Panel::Panel_Register *)393;
}

//------------------------------------------------------------------------------
// Address: 0x101025C0
// Name: private: static void __near * CHudHDRDemo::GetVar_m_TextColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_OnSetFocus *__cdecl CHudHDRDemo::GetVar_m_TextColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OnSetFocus_register;
  else
    return (vgui::Panel::PanelMessageFunc_OnSetFocus *)398;
}

//------------------------------------------------------------------------------
// Address: 0x101025E0
// Name: private: static void __near * CHudHDRDemo::GetVar_m_iBorderLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_OnNavigateFrom *__cdecl CHudHDRDemo::GetVar_m_iBorderLeft(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OnNavigateFrom_register;
  else
    return (vgui::Panel::PanelMessageFunc_OnNavigateFrom *)404;
}

//------------------------------------------------------------------------------
// Address: 0x10102600
// Name: private: static void __near * CHudHDRDemo::GetVar_m_iBorderRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalCursorMoved *__cdecl CHudHDRDemo::GetVar_m_iBorderRight(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_InternalCursorMoved_register;
  else
    return (vgui::Panel::PanelMessageFunc_InternalCursorMoved *)412;
}

//------------------------------------------------------------------------------
// Address: 0x10102620
// Name: private: static void __near * CHudHDRDemo::GetVar_m_iBorderTop(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *__cdecl CHudHDRDemo::GetVar_m_iBorderTop(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_InternalKeyCodePressed_register;
  else
    return (vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *)420;
}

//------------------------------------------------------------------------------
// Address: 0x10102640
// Name: private: static void __near * CHudHDRDemo::GetVar_m_iBorderBottom(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t **__cdecl CHudHDRDemo::GetVar_m_iBorderBottom(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_pDragDrop;
  else
    return (vgui::DragDrop_t **)428;
}

//------------------------------------------------------------------------------
// Address: 0x10102660
// Name: private: static void __near * CHudHDRDemo::GetVar_m_iBorderCenter(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__cdecl CHudHDRDemo::GetVar_m_iBorderCenter(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_clrDropFrame;
  else
    return (Color *)436;
}

//------------------------------------------------------------------------------
// Address: 0x10102680
// Name: private: static void __near * CHudHDRDemo::GetVar_m_iLeftY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PHandle *__cdecl CHudHDRDemo::GetVar_m_iLeftY(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_SkipChild;
  else
    return (vgui::PHandle *)444;
}

//------------------------------------------------------------------------------
// Address: 0x101026A0
// Name: public: virtual void CHudHDRDemo::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHDRDemo::ApplySchemeSettings(CHudFilmDemo *this, vgui::IScheme *pScheme)
{
  int v3; // eax
  int v4; // [esp-4h] [ebp-8h]

  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  v4 = ScreenHeight();
  v3 = ScreenWidth();
  vgui::Panel::SetSize((vgui::Panel *)this, wide: v3, tall: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101026D0
// Name: public: virtual void CHudHDRDemo::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudHDRDemo::Paint(CHudHDRDemo *this)
{
  unsigned int v2; // eax
  vgui::IScheme *v3; // eax
  unsigned int v4; // ebx
  wchar_t *v5; // eax
  wchar_t *v6; // edi
  wchar_t v7; // ax
  int v8; // eax
  __m128d v9; // xmm2
  int v10; // ecx
  __m128d v11; // xmm0
  __m128d v12; // xmm3
  double v13; // xmm1_8
  long double v14; // xmm1_8
  wchar_t *v15; // eax
  wchar_t *v16; // edi
  wchar_t v17; // ax
  int v18; // eax
  vgui::ISurface *v19; // ebx
  vgui::ISurface_vtbl *v20; // edi
  double v21; // st7
  int v22; // [esp+A0h] [ebp-2Ch]
  int x; // [esp+B0h] [ebp-1Ch] BYREF
  int y; // [esp+B4h] [ebp-18h] BYREF
  wchar_t *tempString; // [esp+B8h] [ebp-14h]
  wchar_t *wch; // [esp+BCh] [ebp-10h]
  int iLength; // [esp+C0h] [ebp-Ch]
  int tall; // [esp+C4h] [ebp-8h] BYREF
  int wide; // [esp+C8h] [ebp-4h] BYREF

  vgui::Panel::GetBounds((vgui::Panel *)this, &x, &y, &wide, &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)((char *)&this->m_flAlpha + 1));
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: 0,
    a3: 0,
    a4: *(_DWORD *)&this->m_m_nBgTextureId1_register,
    a5: tall);
  ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
    a1: wide - *(_DWORD *)&this->m_m_nBgTextureId2_register,
    a2: 0,
    a3: wide,
    a4: tall);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_m_nBgTextureId1_register,
    a3: 0,
    a4: wide - *(_DWORD *)&this->m_m_nBgTextureId2_register,
    a5: *(_DWORD *)&this->m_m_nBgTextureId3_register);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_m_nBgTextureId1_register,
    a3: tall - *(_DWORD *)&this->m_m_nBgTextureId4_register,
    a4: wide - *(_DWORD *)&this->m_m_nBgTextureId2_register,
    a5: tall);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: (wide - *(_DWORD *)&this->m_roundedCorners) / 2,
    a3: *(_DWORD *)&this->m_m_nBgTextureId3_register,
    a4: (*(_DWORD *)&this->m_roundedCorners + wide) / 2,
    a5: tall - *(_DWORD *)&this->m_m_nBgTextureId4_register);
  v2 = g_pVGuiSchemeManager->GetScheme(this: g_pVGuiSchemeManager, a2: "ClientScheme");
  v3 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v2);
  v4 = v3->GetFont(this: v3, a2: "HDRDemoText", a3: false);
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: v4);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)(&this->m_m_nPaintBackgroundType_register + 2));
  v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Valve_HDRDEMO_LeftTitle");
  v6 = v5;
  if ( v5 != nullptr )
  {
    v7 = *v5;
    iLength = 0;
    wch = v6;
    if ( v7 != 0 )
    {
      do
      {
        v8 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v4, a3: v7);
        iLength += v8;
        v7 = *++wch;
      }
      while ( *wch != 0 );
    }
    v9.m128d_f64[0] = 4.503599627370496e15;
    v10 = *(_DWORD *)&this->m_RegisterClass;
    v11 = (__m128d)COERCE_UNSIGNED_INT64((double)wide);
    v11.m128d_f64[0] = v11.m128d_f64[0] * 0.25;
    v12 = _mm_and_pd((__m128d)0x8000000000000000uLL, v11);
    wch = (wchar_t *)g_pVGuiSurface->__vftable;
    v13 = _mm_cmplt_sd(_mm_xor_pd(v11, v12), v9).m128d_f64[0];
    v14 = v11.m128d_f64[0]
        + COERCE_DOUBLE(*(_QWORD *)&v13 & 0x4330000000000000LL | *(_QWORD *)&v12.m128d_f64[0])
        - COERCE_DOUBLE(*(_QWORD *)&v13 & 0x4330000000000000LL | *(_QWORD *)&v12.m128d_f64[0]);
    (*((void (__thiscall **)(vgui::ISurface *, int, int))wch + 25))(
      a1: g_pVGuiSurface,
      a2: (int)(v14
          - COERCE_DOUBLE(
              *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v14 - v11.m128d_f64[0]), v12).m128d_f64[0]
            & 0x3FF0000000000000LL)
          - (double)(iLength / 2)),
      a3: v10);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: v6, a3: wcslen(v6), a4: FONT_DRAW_DEFAULT);
  }
  v15 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Valve_HDRDEMO_RightTitle");
  tempString = v15;
  if ( v15 != nullptr )
  {
    v16 = v15;
    v17 = *v15;
    for ( iLength = 0; v17 != 0; ++v16 )
    {
      v18 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v4, a3: v17);
      iLength += v18;
      v17 = v16[1];
    }
    v19 = g_pVGuiSurface;
    v20 = g_pVGuiSurface->__vftable;
    v22 = *(int *)((char *)&this->m_BorderColor + 3);
    v21 = ceil(X: (double)wide * 0.75);
    wch = (wchar_t *)(iLength / 2);
    v20->DrawSetTextPos(this: v19, a2: (int)(v21 - (double)(iLength / 2)), a3: v22);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: tempString, a3: wcslen(tempString), a4: FONT_DRAW_DEFAULT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102A20
// Name: public: virtual bool CHudHDRDemo::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHudHDRDemo::ShouldDraw(CHudHDRDemo *this)
{
  return g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE
      && this->m_bHDRDemoActive;
}

//------------------------------------------------------------------------------
// Address: 0x10102A50
// Name: void mat_show_ab_hdr_hudelement_changed(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_show_ab_hdr_hudelement_changed(IConVar *pConVar)
{
  CHud *Hud; // eax
  CHudElement *Element; // esi
  bool v3; // bl
  ConVarRef v4; // [esp+4h] [ebp-10h] BYREF
  ConVarRef var; // [esp+Ch] [ebp-8h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudHDRDemo");
  if ( Element != nullptr )
  {
    ConVarRef::ConVarRef(this: &var, pConVar);
    v3 = var.m_pConVarState->m_Value.m_nValue != 0;
    if ( var.m_pConVarState->m_Value.m_nValue != 0 )
    {
      if ( HIBYTE(Element[6].m_pHud) == 0 )
      {
        ConVarRef::ConVarRef(this: &v4, pName: "hidehud");
        v4.m_pConVar->SetValue_2(this: v4.m_pConVar, a2: 15);
      }
    }
    else if ( HIBYTE(Element[6].m_pHud) != 0 )
    {
      ConVarRef::ConVarRef(this: &v4, pName: "hidehud");
      v4.m_pConVar->SetValue_2(this: v4.m_pConVar, a2: 0);
    }
    HIBYTE(Element[6].m_pHud) = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102AE0
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_BorderColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_BorderColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_BorderColor::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_BorderColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderColor";
    src.m_pszVariable = "m_BorderColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "0 0 0 255";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_BorderColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102B40
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_TextColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_TextColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_TextColor::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_TextColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextColor";
    src.m_pszVariable = "m_TextColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "255 255 255 255";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_TextColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102BA0
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_iBorderLeft::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_iBorderLeft::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_iBorderLeft::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_iBorderLeft::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderLeft";
    src.m_pszVariable = "m_iBorderLeft";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_iBorderLeft;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102C00
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_iBorderRight::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_iBorderRight::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_iBorderRight::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_iBorderRight::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderRight";
    src.m_pszVariable = "m_iBorderRight";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_iBorderRight;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102C60
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_iBorderTop::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_iBorderTop::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_iBorderTop::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_iBorderTop::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderTop";
    src.m_pszVariable = "m_iBorderTop";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_iBorderTop;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102CC0
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_iBorderBottom::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_iBorderBottom::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_iBorderBottom::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_iBorderBottom::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderBottom";
    src.m_pszVariable = "m_iBorderBottom";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_iBorderBottom;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102D20
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_iBorderCenter::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_iBorderCenter::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_iBorderCenter::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_iBorderCenter::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderCenter";
    src.m_pszVariable = "m_iBorderCenter";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_iBorderCenter;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102D80
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_iLeftY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_iLeftY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_iLeftY::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_iLeftY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LeftTitleY";
    src.m_pszVariable = "m_iLeftY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudHDRDemo::GetVar_m_iLeftY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102DE0
// Name: public: static void CHudHDRDemo::PanelAnimationVar_m_iRightY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudHDRDemo::PanelAnimationVar_m_iRightY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudHDRDemo::PanelAnimationVar_m_iRightY::InitVar'::`2'::bAdded )
  {
    `CHudHDRDemo::PanelAnimationVar_m_iRightY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "RightTitleY";
    src.m_pszVariable = "m_iRightY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudMenu::GetVar_m_flOpenCloseTime;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102E40
// Name: public: CHudHDRDemo::CHudHDRDemo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudHDRDemo *__thiscall CHudHDRDemo::CHudHDRDemo(CHudHDRDemo *this, const char *name)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName: name);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudHDRDemo");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudHDRDemo_vtbl *)&CHudHDRDemo::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudHDRDemo::`vftable'{for `vgui::Panel'};
  if ( `CHudHDRDemo::ChainToMap'::`2'::chained == 0 )
  {
    `CHudHDRDemo::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudHDRDemo");
    v3->pfnClassName = CHudHDRDemo::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudHDRDemo::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudHDRDemo::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
    v4->pfnClassName = CHudHDRDemo::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudHDRDemo::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudHDRDemo::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudHDRDemo");
    v5->pfnClassName = CHudHDRDemo::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CHudHDRDemo::PanelAnimationVar_m_BorderColor::InitVar();
  this->m_BorderColor = 0;
  CHudHDRDemo::PanelAnimationVar_m_TextColor::InitVar();
  this->m_TextColor = 0;
  CHudHDRDemo::PanelAnimationVar_m_iBorderLeft::InitVar();
  CHudHDRDemo::PanelAnimationVar_m_iBorderRight::InitVar();
  CHudHDRDemo::PanelAnimationVar_m_iBorderTop::InitVar();
  CHudHDRDemo::PanelAnimationVar_m_iBorderBottom::InitVar();
  CHudHDRDemo::PanelAnimationVar_m_iBorderCenter::InitVar();
  CHudHDRDemo::PanelAnimationVar_m_iLeftY::InitVar();
  CHudHDRDemo::PanelAnimationVar_m_iRightY::InitVar();
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  vgui::Panel::SetPaintBorderEnabled(this: &this->vgui::Panel, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this: &this->vgui::Panel, state: false);
  this->m_bHDRDemoActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10102F80
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudHDRDemo::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudHDRDemo::GetMessageMap(CHudHDRDemo *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudHDRDemo::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudHDRDemo::GetMessageMap'::`2'::s_pMap;
  `CHudHDRDemo::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudHDRDemo");
  `CHudHDRDemo::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102FB0
// Name: public: virtual struct PanelAnimationMap __near * CHudHDRDemo::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudHDRDemo::GetAnimMap(CHudHDRDemo *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudHDRDemo");
}

//------------------------------------------------------------------------------
// Address: 0x10102FC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudHDRDemo::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudHDRDemo::GetKBMap(CHudHDRDemo *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudHDRDemo::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudHDRDemo::GetKBMap'::`2'::s_pMap;
  `CHudHDRDemo::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudHDRDemo");
  `CHudHDRDemo::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102FF0
// Name: Create_CHudHDRDemo
// Source: json
//------------------------------------------------------------------------------
CHudHDRDemo *__cdecl Create_CHudHDRDemo()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 456);
  memset(dst: v0, value: 0, count: 0x1C8u);
  if ( v0 != nullptr )
    return CHudHDRDemo::CHudHDRDemo(this: (CHudHDRDemo *)v0, name: "CHudHDRDemo");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10423DA0
// Name: _dynamic_initializer_for__demo_ui_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_ui_enable__()
{
  ConVar::ConVar(
    this: &demo_ui_enable,
    pName: "demo_ui_enable",
    pDefaultValue: prType,
    flags: 2,
    pHelpString: "Suffix for the demo UI");
  return atexit(func: dynamic_atexit_destructor_for__demo_ui_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10423DD0
// Name: _dynamic_initializer_for__demo_connect_string__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_connect_string__()
{
  ConVar::ConVar(
    this: &demo_connect_string,
    pName: "demo_connect_string",
    pDefaultValue: prType,
    flags: 2,
    pHelpString: "Connect string for demo UI");
  return atexit(func: dynamic_atexit_destructor_for__demo_connect_string__);
}

//------------------------------------------------------------------------------
// Address: 0x10435A20
// Name: _dynamic_atexit_destructor_for__demo_ui_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_ui_enable__()
{
  ConVar::~ConVar(this: &demo_ui_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10435A30
// Name: _dynamic_atexit_destructor_for__demo_connect_string__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_connect_string__()
{
  ConVar::~ConVar(this: &demo_connect_string);
}

//------------------------------------------------------------------------------
// Address: 0x10423E00
// Name: _dynamic_initializer_for__mm_ping_max_green__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_ping_max_green__()
{
  ConVar::ConVar(this: &mm_ping_max_green, pName: "ping_max_green", pDefaultValue: "70", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_ping_max_green__);
}

//------------------------------------------------------------------------------
// Address: 0x10423E30
// Name: _dynamic_initializer_for__mm_ping_max_yellow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_ping_max_yellow__()
{
  ConVar::ConVar(this: &mm_ping_max_yellow, pName: "ping_max_yellow", pDefaultValue: "140", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_ping_max_yellow__);
}

//------------------------------------------------------------------------------
// Address: 0x10423E60
// Name: _dynamic_initializer_for__mm_ping_max_red__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_ping_max_red__()
{
  ConVar::ConVar(this: &mm_ping_max_red, pName: "ping_max_red", pDefaultValue: "250", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_ping_max_red__);
}

//------------------------------------------------------------------------------
// Address: 0x10423E90
// Name: _dynamic_initializer_for__ui_reloadscheme_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_reloadscheme_command__()
{
  ConCommand::ConCommand(
    this: &ui_reloadscheme_command,
    pName: "ui_reloadscheme",
    callback: ui_reloadscheme,
    pHelpString: "Reloads the resource files for the active UI window",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ui_reloadscheme_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10423EC0
// Name: _dynamic_initializer_for__g_URLButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_URLButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_URLButton_Helper,
           className: "URLButton",
           func: (vgui::Panel *(__cdecl *)())Create_URLButton);
}

//------------------------------------------------------------------------------
// Address: 0x10423EE0
// Name: _dynamic_initializer_for__g_VModuleLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VModuleLoader__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VModuleLoader__);
}

//------------------------------------------------------------------------------
// Address: 0x10423EF0
// Name: _dynamic_initializer_for____g_CreateCVGuiSystemModuleLoaderIVGuiModuleLoader_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVGuiSystemModuleLoaderIVGuiModuleLoader_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVGuiSystemModuleLoaderIVGuiModuleLoader_reg,
           fn: (void *(__cdecl *)())_CreateCVGuiSystemModuleLoaderIVGuiModuleLoader_interface,
           pName: "VGuiModuleLoader003");
}

//------------------------------------------------------------------------------
// Address: 0x10435A40
// Name: _dynamic_atexit_destructor_for__mm_ping_max_green__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_ping_max_green__()
{
  ConVar::~ConVar(this: &mm_ping_max_green);
}

//------------------------------------------------------------------------------
// Address: 0x10435A50
// Name: _dynamic_atexit_destructor_for__mm_ping_max_yellow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_ping_max_yellow__()
{
  ConVar::~ConVar(this: &mm_ping_max_yellow);
}

//------------------------------------------------------------------------------
// Address: 0x10435A60
// Name: _dynamic_atexit_destructor_for__mm_ping_max_red__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_ping_max_red__()
{
  ConVar::~ConVar(this: &mm_ping_max_red);
}

//------------------------------------------------------------------------------
// Address: 0x10435A70
// Name: _dynamic_atexit_destructor_for__ui_reloadscheme_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_reloadscheme_command__()
{
  ConCommand::~ConCommand(this: &ui_reloadscheme_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435A80
// Name: _dynamic_atexit_destructor_for__g_VModuleLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VModuleLoader__()
{
  g_VModuleLoader.__vftable = (CVGuiSystemModuleLoader_vtbl *)&CVGuiSystemModuleLoader::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_VModuleLoader.m_Modules);
  g_VModuleLoader.__vftable = (CVGuiSystemModuleLoader_vtbl *)&IBaseInterface::`vftable';
}
