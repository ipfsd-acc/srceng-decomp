// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hl2/hud_filmdemo.cpp
// Functions: 26
// ============================================================

#include "game\client\hl2\hud_filmdemo.h"

//------------------------------------------------------------------------------
// Address: 0x10101BB0
// Name: public: static char const __near * CHudFilmDemo::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudFilmDemo::GetPanelClassName()
{
  return "CHudFilmDemo";
}

//------------------------------------------------------------------------------
// Address: 0x10101BC0
// Name: private: static void __near * CHudFilmDemo::GetVar_m_BorderColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudFilmDemo::GetVar_m_BorderColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[2].m_pinSibling.m_iPanelID + 1;
  else
    return 905;
}

//------------------------------------------------------------------------------
// Address: 0x10101BE0
// Name: private: static void __near * CHudFilmDemo::GetVar_m_TextColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudFilmDemo::GetVar_m_TextColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[2].m_hMouseEventHandler.m_iPanelID + 2;
  else
    return 910;
}

//------------------------------------------------------------------------------
// Address: 0x10101C00
// Name: private: static void __near * CHudFilmDemo::GetVar_m_iBorderLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl CHudFilmDemo::GetVar_m_iBorderLeft(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[2].m_sNavUpName;
  else
    return (CUtlString *)916;
}

//------------------------------------------------------------------------------
// Address: 0x10101C20
// Name: private: static void __near * CHudFilmDemo::GetVar_m_iBorderRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudFilmDemo::GetVar_m_iBorderRight(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[2].m_sNavUpName.m_Storage.m_Memory.m_nGrowSize;
  else
    return (void *)924;
}

//------------------------------------------------------------------------------
// Address: 0x10101C40
// Name: private: static void __near * CHudFilmDemo::GetVar_m_iBorderTop(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PHandle *__cdecl CHudFilmDemo::GetVar_m_iBorderTop(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[2].m_NavUp;
  else
    return (vgui::PHandle *)932;
}

//------------------------------------------------------------------------------
// Address: 0x10101C60
// Name: private: static void __near * CHudFilmDemo::GetVar_m_iBorderBottom(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudFilmDemo::GetVar_m_iBorderBottom(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[2].m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount;
  else
    return (void *)940;
}

//------------------------------------------------------------------------------
// Address: 0x10101C80
// Name: private: static void __near * CHudFilmDemo::GetVar_m_iBorderCenter(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudFilmDemo::GetVar_m_iBorderCenter(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[2].m_sNavDownName.m_Storage.m_nActualLength;
  else
    return (void *)948;
}

//------------------------------------------------------------------------------
// Address: 0x10101CA0
// Name: private: static void __near * CHudFilmDemo::GetVar_m_iLeftY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl CHudFilmDemo::GetVar_m_iLeftY(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[2].m_sNavLeftName;
  else
    return (CUtlString *)956;
}

//------------------------------------------------------------------------------
// Address: 0x10101CC0
// Name: private: static void __near * CHudFilmDemo::GetVar_m_iRightY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudFilmDemo::GetVar_m_iRightY(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[2].m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize;
  else
    return (void *)964;
}

//------------------------------------------------------------------------------
// Address: 0x10101CE0
// Name: public: virtual void CHudFilmDemo::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudFilmDemo::Paint(CHudFilmDemo *this)
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
    a2: *(_DWORD *)&this->m_pRightStringID[201]);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: 0,
    a3: 0,
    a4: *(_DWORD *)&this->m_pRightStringID[212],
    a5: tall);
  ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
    a1: wide - *(_DWORD *)&this->m_pRightStringID[220],
    a2: 0,
    a3: wide,
    a4: tall);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_pRightStringID[212],
    a3: 0,
    a4: wide - *(_DWORD *)&this->m_pRightStringID[220],
    a5: *(_DWORD *)&this->m_pRightStringID[228]);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_pRightStringID[212],
    a3: tall - *(_DWORD *)&this->m_pRightStringID[236],
    a4: wide - *(_DWORD *)&this->m_pRightStringID[220],
    a5: tall);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: (wide - *(_DWORD *)&this->m_pRightStringID[244]) / 2,
    a3: *(_DWORD *)&this->m_pRightStringID[228],
    a4: (*(_DWORD *)&this->m_pRightStringID[244] + wide) / 2,
    a5: tall - *(_DWORD *)&this->m_pRightStringID[236]);
  v2 = g_pVGuiSchemeManager->GetScheme(this: g_pVGuiSchemeManager, a2: "ClientScheme");
  v3 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v2);
  v4 = v3->GetFont(this: v3, a2: "MenuTitle", a3: false);
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: v4);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_pRightStringID[206]);
  v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: &this->m_flAlpha);
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
    v10 = *(_DWORD *)&this->m_pRightStringID[252];
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
  v15 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: &this->m_pLeftStringID[200]);
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
// Address: 0x10102030
// Name: public: virtual bool CHudFilmDemo::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudFilmDemo::ShouldDraw(CHudFilmDemo *this)
{
  return this->m_bFilmDemoActive;
}

//------------------------------------------------------------------------------
// Address: 0x10102040
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_BorderColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_BorderColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_BorderColor::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_BorderColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderColor";
    src.m_pszVariable = "m_BorderColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "0 0 0 255";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudFilmDemo::GetVar_m_BorderColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101020A0
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_TextColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_TextColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_TextColor::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_TextColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextColor";
    src.m_pszVariable = "m_TextColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "255 255 255 255";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudFilmDemo::GetVar_m_TextColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102100
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_iBorderLeft::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_iBorderLeft::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_iBorderLeft::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_iBorderLeft::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderLeft";
    src.m_pszVariable = "m_iBorderLeft";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudFilmDemo::GetVar_m_iBorderLeft;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102160
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_iBorderRight::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_iBorderRight::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_iBorderRight::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_iBorderRight::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderRight";
    src.m_pszVariable = "m_iBorderRight";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudFilmDemo::GetVar_m_iBorderRight;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101021C0
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_iBorderTop::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_iBorderTop::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_iBorderTop::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_iBorderTop::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderTop";
    src.m_pszVariable = "m_iBorderTop";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudFilmDemo::GetVar_m_iBorderTop;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102220
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_iBorderBottom::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_iBorderBottom::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_iBorderBottom::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_iBorderBottom::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderBottom";
    src.m_pszVariable = "m_iBorderBottom";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "48";
    src.m_pfnLookup = CHudFilmDemo::GetVar_m_iBorderBottom;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102280
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_iBorderCenter::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_iBorderCenter::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_iBorderCenter::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_iBorderCenter::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BorderCenter";
    src.m_pszVariable = "m_iBorderCenter";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudFilmDemo::GetVar_m_iBorderCenter;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101022E0
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_iLeftY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_iLeftY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_iLeftY::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_iLeftY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LeftTitleY";
    src.m_pszVariable = "m_iLeftY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "440";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudFilmDemo::GetVar_m_iLeftY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102340
// Name: public: static void CHudFilmDemo::PanelAnimationVar_m_iRightY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudFilmDemo::PanelAnimationVar_m_iRightY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudFilmDemo::PanelAnimationVar_m_iRightY::InitVar'::`2'::bAdded )
  {
    `CHudFilmDemo::PanelAnimationVar_m_iRightY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "RightTitleY";
    src.m_pszVariable = "m_iRightY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "440";
    src.m_pfnLookup = CHudFilmDemo::GetVar_m_iRightY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101023A0
// Name: public: CHudFilmDemo::CHudFilmDemo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudFilmDemo *__thiscall CHudFilmDemo::CHudFilmDemo(CHudFilmDemo *this, const char *name)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName: name);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudHDRDemo");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudFilmDemo_vtbl *)&CHudFilmDemo::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudFilmDemo::`vftable'{for `vgui::Panel'};
  if ( `CHudFilmDemo::ChainToMap'::`2'::chained == 0 )
  {
    `CHudFilmDemo::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudFilmDemo");
    v3->pfnClassName = CHudFilmDemo::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudFilmDemo::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudFilmDemo::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
    v4->pfnClassName = CHudFilmDemo::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudFilmDemo::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudFilmDemo::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudFilmDemo");
    v5->pfnClassName = CHudFilmDemo::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CHudFilmDemo::PanelAnimationVar_m_BorderColor::InitVar();
  this->m_BorderColor = 0;
  CHudFilmDemo::PanelAnimationVar_m_TextColor::InitVar();
  this->m_TextColor = 0;
  CHudFilmDemo::PanelAnimationVar_m_iBorderLeft::InitVar();
  CHudFilmDemo::PanelAnimationVar_m_iBorderRight::InitVar();
  CHudFilmDemo::PanelAnimationVar_m_iBorderTop::InitVar();
  CHudFilmDemo::PanelAnimationVar_m_iBorderBottom::InitVar();
  CHudFilmDemo::PanelAnimationVar_m_iBorderCenter::InitVar();
  CHudFilmDemo::PanelAnimationVar_m_iLeftY::InitVar();
  CHudFilmDemo::PanelAnimationVar_m_iRightY::InitVar();
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  vgui::Panel::SetPaintBorderEnabled(this: &this->vgui::Panel, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this: &this->vgui::Panel, state: false);
  this->m_bFilmDemoActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101024E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudFilmDemo::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudFilmDemo::GetMessageMap(CHudFilmDemo *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudFilmDemo::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudFilmDemo::GetMessageMap'::`2'::s_pMap;
  `CHudFilmDemo::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudFilmDemo");
  `CHudFilmDemo::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102510
// Name: public: virtual struct PanelAnimationMap __near * CHudFilmDemo::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudFilmDemo::GetAnimMap(CHudFilmDemo *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudFilmDemo");
}

//------------------------------------------------------------------------------
// Address: 0x10102520
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudFilmDemo::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudFilmDemo::GetKBMap(CHudFilmDemo *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudFilmDemo::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudFilmDemo::GetKBMap'::`2'::s_pMap;
  `CHudFilmDemo::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudFilmDemo");
  `CHudFilmDemo::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10102550
// Name: Create_CHudFilmDemo
// Source: json
//------------------------------------------------------------------------------
CHudFilmDemo *__cdecl Create_CHudFilmDemo()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 968);
  memset(dst: v0, value: 0, count: 0x3C8u);
  if ( v0 != nullptr )
    return CHudFilmDemo::CHudFilmDemo(this: (CHudFilmDemo *)v0, name: "CHudFilmDemo");
  else
    return nullptr;
}
