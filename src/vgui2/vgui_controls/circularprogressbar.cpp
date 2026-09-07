// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/circularprogressbar.cpp
// Functions: 12
// ============================================================

#include "vgui2\vgui_controls\circularprogressbar.h"

//------------------------------------------------------------------------------
// Address: 0x102CAB90
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102CABA0
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CAC70
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x102CAD10
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102CADA0
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        Color c,
        float flEndProgress,
        bool bClockwise)
{
  int v7; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v9; // bl
  double v10; // xmm0_8
  int *p_swipe_dir_x; // esi
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  long double v45; // [esp-8h] [ebp-54h]
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  float flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    v45 = COERCE_DOUBLE(__PAIR64__(a2, a3));
    vgui::Panel::GetSize(this, &wide, &tall);
    v7 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v7);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v9 = 0;
    v10 = flEndProgress * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v29 = v10;
      flEndProgressRadiansa = v29;
      do
      {
        v30 = *((float *)p_swipe_dir_x - 5);
        if ( v29 > v30 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          v33 = v29 - v30;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( v33 >= 0.7853981633974483 )
          {
            v42 = *((float *)p_swipe_dir_x - 2);
            v39 = flTall;
            v[2].m_Position.x = (float)((float)(v42 - 0.5) * flWide) + flHalfWide.x;
            v41 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v41 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v9 & 1) != 0 )
              v33 = 0.7853981633974483 - v33;
            __libm_sse2_tan(x: v45);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v34 = v33;
            if ( (v9 & 1) == 1 )
            {
              v35 = (float)(flHalfWide.x - (float)(v33 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v36 = flHalfWide.y - (float)(v34 * flHalfWide.x);
              v37 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v35 = (float)(v33 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v36 = (float)p_swipe_dir_x[1];
              v37 = v34 * flHalfWide.x;
            }
            v38 = *((float *)p_swipe_dir_x - 4);
            v39 = flTall;
            v40 = v36 * v37;
            v[2].m_Position.x = (float)(v38 * flWide) + v35;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v40;
            v41 = (float)((float)(v40 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v42 = (float)((float)(v35 / flHalfWide.x) * 0.5) + v38;
          }
          v[2].m_TexCoord.y = v41;
          v[2].m_TexCoord.x = v42;
          v43 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v43 - 0.5) * flWide) + x;
          v44 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v44 - 0.5) * v39) + y;
          v[1].m_TexCoord.x = v43;
          v[1].m_TexCoord.y = v44;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v29 = flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v9;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_160.w );
    }
    else
    {
      v12 = v10;
      flEndProgressRadians = v12;
      do
      {
        v13 = *((float *)p_swipe_dir_x - 5) + 0.7853981633974483;
        if ( v13 > v12 )
        {
          v14 = flHalfWide.x;
          v15 = flHalfWide.y;
          v16 = v13 - v12;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( v16 >= 0.7853981633974483 )
          {
            v26 = *((float *)p_swipe_dir_x - 4);
            v23 = flTall;
            v[1].m_Position.x = (float)((float)(v26 - 0.5) * flWide) + flHalfWide.x;
            v25 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v25 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v17 = 0.7853981633974483 - v16;
            if ( (v9 & 1) != 0 )
              v17 = 0.7853981633974483 - v17;
            __libm_sse2_tan(x: v45);
            v15 = flHalfWide.y;
            v14 = flHalfWide.x;
            v18 = v17;
            if ( (v9 & 1) == 1 )
            {
              v19 = (float)(flHalfWide.x - (float)(v17 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v20 = flHalfWide.y - (float)(v18 * flHalfWide.x);
              v21 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v19 = (float)(v17 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v20 = (float)p_swipe_dir_x[1];
              v21 = v18 * flHalfWide.x;
            }
            v22 = *((float *)p_swipe_dir_x - 4);
            v23 = flTall;
            v24 = v20 * v21;
            v[1].m_Position.x = (float)(v22 * flWide) + v19;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v24;
            v25 = (float)((float)(v24 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v26 = (float)((float)(v19 / flHalfWide.x) * 0.5) + v22;
          }
          v[1].m_TexCoord.y = v25;
          v[1].m_TexCoord.x = v26;
          v27 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v27 - 0.5) * flWide) + v14;
          v28 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v28 - 0.5) * v23) + v15;
          v[2].m_TexCoord.x = v27;
          v[2].m_TexCoord.y = v28;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v12 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v9;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_160.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CB250
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CB280
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102CB290
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CB2C0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CB410
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102CB4A0
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+10h] [ebp-8h] BYREF
  float Progress; // [esp+14h] [ebp-4h]

  Progress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - Progress;
  else
    v3 = Progress;
  GetFgColor = this->GetFgColor;
  Progress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: Progress,
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x102CB510
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x100553F0
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x10055400
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100554D0
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10055570
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10055600
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_53.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_53.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055AE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x10055AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055B20
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10055C70
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10055D00
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10055D70
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0043BE60
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043BE70
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BF40
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0043BFF0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0043C080
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        Color c,
        float flEndProgress,
        bool bClockwise)
{
  int v7; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v9; // bl
  double v10; // xmm0_8
  int *p_swipe_dir_x; // esi
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  long double v45; // [esp-8h] [ebp-54h]
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  float flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    v45 = COERCE_DOUBLE(__PAIR64__(a2, a3));
    vgui::Panel::GetSize(this, &wide, &tall);
    v7 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v7);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v9 = 0;
    v10 = flEndProgress * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v29 = v10;
      flEndProgressRadiansa = v29;
      do
      {
        v30 = *((float *)p_swipe_dir_x - 5);
        if ( v29 > v30 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          v33 = v29 - v30;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( v33 >= 0.7853981633974483 )
          {
            v42 = *((float *)p_swipe_dir_x - 2);
            v39 = flTall;
            v[2].m_Position.x = (float)((float)(v42 - 0.5) * flWide) + flHalfWide.x;
            v41 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v41 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v9 & 1) != 0 )
              v33 = 0.7853981633974483 - v33;
            __libm_sse2_tan(x: v45);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v34 = v33;
            if ( (v9 & 1) == 1 )
            {
              v35 = (float)(flHalfWide.x - (float)(v33 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v36 = flHalfWide.y - (float)(v34 * flHalfWide.x);
              v37 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v35 = (float)(v33 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v36 = (float)p_swipe_dir_x[1];
              v37 = v34 * flHalfWide.x;
            }
            v38 = *((float *)p_swipe_dir_x - 4);
            v39 = flTall;
            v40 = v36 * v37;
            v[2].m_Position.x = (float)(v38 * flWide) + v35;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v40;
            v41 = (float)((float)(v40 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v42 = (float)((float)(v35 / flHalfWide.x) * 0.5) + v38;
          }
          v[2].m_TexCoord.y = v41;
          v[2].m_TexCoord.x = v42;
          v43 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v43 - 0.5) * flWide) + x;
          v44 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v44 - 0.5) * v39) + y;
          v[1].m_TexCoord.x = v43;
          v[1].m_TexCoord.y = v44;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v29 = flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v9;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_26.w );
    }
    else
    {
      v12 = v10;
      flEndProgressRadians = v12;
      do
      {
        v13 = *((float *)p_swipe_dir_x - 5) + 0.7853981633974483;
        if ( v13 > v12 )
        {
          v14 = flHalfWide.x;
          v15 = flHalfWide.y;
          v16 = v13 - v12;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( v16 >= 0.7853981633974483 )
          {
            v26 = *((float *)p_swipe_dir_x - 4);
            v23 = flTall;
            v[1].m_Position.x = (float)((float)(v26 - 0.5) * flWide) + flHalfWide.x;
            v25 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v25 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v17 = 0.7853981633974483 - v16;
            if ( (v9 & 1) != 0 )
              v17 = 0.7853981633974483 - v17;
            __libm_sse2_tan(x: v45);
            v15 = flHalfWide.y;
            v14 = flHalfWide.x;
            v18 = v17;
            if ( (v9 & 1) == 1 )
            {
              v19 = (float)(flHalfWide.x - (float)(v17 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v20 = flHalfWide.y - (float)(v18 * flHalfWide.x);
              v21 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v19 = (float)(v17 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v20 = (float)p_swipe_dir_x[1];
              v21 = v18 * flHalfWide.x;
            }
            v22 = *((float *)p_swipe_dir_x - 4);
            v23 = flTall;
            v24 = v20 * v21;
            v[1].m_Position.x = (float)(v22 * flWide) + v19;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v24;
            v25 = (float)((float)(v24 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v26 = (float)((float)(v19 / flHalfWide.x) * 0.5) + v22;
          }
          v[1].m_TexCoord.y = v25;
          v[1].m_TexCoord.x = v26;
          v27 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v27 - 0.5) * flWide) + v14;
          v28 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v28 - 0.5) * v23) + v15;
          v[2].m_TexCoord.x = v27;
          v[2].m_TexCoord.y = v28;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v12 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v9;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_26.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C530
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C560
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043C570
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C5A0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043C6F0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0043C780
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this@<ecx>, unsigned int a2@<ebx>)
{
  unsigned int m_iProgressDirection; // edi
  float v4; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v6; // eax
  Color v7; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v4 = 1.0 - flProgress;
  else
    v4 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v4;
  v6 = GetFgColor(this, result: &v7);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    a2,
    a3: m_iProgressDirection,
    c: *v6,
    flEndProgress: flProgress,
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043C7F0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1006B9F0
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x1006BA00
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BAD0
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1006BB70
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1006BC00
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_38.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_38.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C0B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006C0E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1006C0F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006C120
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006C270
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1006C300
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006C370
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00613F10
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00613F20
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613FF0
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x00614090
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00614120
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_185.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_185.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006145D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00614600
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00614610
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00614640
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00614790
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00614820
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x00614890
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102CACC0
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102CACD0
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CAE40
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102CAED0
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(a1: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_160.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((long double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(a1: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_160.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CB380
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CB3B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102CB3C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CB3F0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        __m128i *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CB540
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102CB5D0
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+10h] [ebp-8h] BYREF
  float Progress; // [esp+14h] [ebp-4h]

  Progress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - Progress;
  else
    v3 = Progress;
  GetFgColor = this->GetFgColor;
  Progress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(Progress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x102CB640
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1031F260
// Name: _dynamic_initializer_for__progress_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__progress_enable__()
{
  ConCommand::ConCommand(
    this: &progress_enable,
    pName: "progress_enable",
    callback: BaseUI_ProgressEnabled_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__progress_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10327400
// Name: _dynamic_atexit_destructor_for__progress_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__progress_enable__()
{
  ConCommand::~ConCommand(this: &progress_enable);
}

//------------------------------------------------------------------------------
// Address: 0x1031F290
// Name: _dynamic_initializer_for__g_EngineVGuiImp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EngineVGuiImp__()
{
  __int128 v1; // [esp+0h] [ebp-1Ch]

  *(_QWORD *)&v1 = 0;
  *((_QWORD *)&v1 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CEngineVGui>::CConCommandMemberAccessor<CEngineVGui>(
    this: &g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "debugsystemui",
    callback: (unsigned int)CEngineVGui::ToggleDebugSystemUI,
    pHelpString: "Show/hide the debug system UI.",
    flags: 0x4000,
    completionFunc: v1);
  *((_BYTE *)&g_EngineVGuiImp + 220) &= 0xF0u;
  g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor.m_pOwner = &g_EngineVGuiImp;
  g_EngineVGuiImp.m_LoadingProgress.m_Memory.m_pMemory = nullptr;
  g_EngineVGuiImp.m_LoadingProgress.m_Memory.m_nAllocationCount = 0;
  g_EngineVGuiImp.m_LoadingProgress.m_Memory.m_nGrowSize = 0;
  g_EngineVGuiImp.m_LoadingProgress.m_Size = 0;
  g_EngineVGuiImp.m_LoadingProgress.m_pElements = nullptr;
  g_EngineVGuiImp.staticPanel = nullptr;
  g_EngineVGuiImp.staticClientDLLToolsPanel = nullptr;
  g_EngineVGuiImp.staticClientDLLPanel = nullptr;
  g_EngineVGuiImp.staticGameDLLPanel = nullptr;
  g_EngineVGuiImp.staticGameUIPanel = nullptr;
  g_EngineVGuiImp.staticGameUIBackgroundPanel = nullptr;
  g_EngineVGuiImp.staticEngineToolsPanel = nullptr;
  g_EngineVGuiImp.staticDebugSystemPanel = nullptr;
  g_EngineVGuiImp.staticSteamOverlayPanel = nullptr;
  g_EngineVGuiImp.staticFocusOverlayPanel = nullptr;
  g_EngineVGuiImp.staticTransitionPanel = nullptr;
  g_EngineVGuiImp.m_hGameUIInputContext = nullptr;
  g_EngineVGuiImp.m_hStaticGameUIModule = nullptr;
  g_EngineVGuiImp.m_GameUIFactory = nullptr;
  g_EngineVGuiImp.m_pVProfPanel = nullptr;
  g_EngineVGuiImp.m_bShowProgressDialog = false;
  g_EngineVGuiImp.m_pInputInternal = nullptr;
  g_EngineVGuiImp.m_ProgressBias = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_EngineVGuiImp__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F390
// Name: _dynamic_initializer_for____g_CreateCEngineVGuiIEngineVGui_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineVGuiIEngineVGui_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineVGuiIEngineVGui_reg,
           fn: (void *(__cdecl *)())EngineVGui,
           pName: "VEngineVGui001");
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102FFA80
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102FFA90
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FFB60
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = std::char_traits<char>::length(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    operator delete(p: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x102FFC00
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102FFC90
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        Color c,
        float flEndProgress,
        bool bClockwise)
{
  int v7; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v9; // bl
  double v10; // xmm0_8
  int *p_swipe_dir_x; // esi
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  long double v45; // [esp-8h] [ebp-54h]
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  float flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    v45 = COERCE_DOUBLE(__PAIR64__(a2, a3));
    vgui::Panel::GetSize(this, &wide, &tall);
    v7 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v7);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v9 = 0;
    v10 = flEndProgress * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v29 = v10;
      flEndProgressRadiansa = v29;
      do
      {
        v30 = *((float *)p_swipe_dir_x - 5);
        if ( v29 > v30 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          v33 = v29 - v30;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( v33 >= 0.7853981633974483 )
          {
            v42 = *((float *)p_swipe_dir_x - 2);
            v39 = flTall;
            v[2].m_Position.x = (float)((float)(v42 - 0.5) * flWide) + flHalfWide.x;
            v41 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v41 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v9 & 1) != 0 )
              v33 = 0.7853981633974483 - v33;
            __libm_sse2_tan(x: v45);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v34 = v33;
            if ( (v9 & 1) == 1 )
            {
              v35 = (float)(flHalfWide.x - (float)(v33 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v36 = flHalfWide.y - (float)(v34 * flHalfWide.x);
              v37 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v35 = (float)(v33 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v36 = (float)p_swipe_dir_x[1];
              v37 = v34 * flHalfWide.x;
            }
            v38 = *((float *)p_swipe_dir_x - 4);
            v39 = flTall;
            v40 = v36 * v37;
            v[2].m_Position.x = (float)(v38 * flWide) + v35;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v40;
            v41 = (float)((float)(v40 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v42 = (float)((float)(v35 / flHalfWide.x) * 0.5) + v38;
          }
          v[2].m_TexCoord.y = v41;
          v[2].m_TexCoord.x = v42;
          v43 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v43 - 0.5) * flWide) + x;
          v44 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v44 - 0.5) * v39) + y;
          v[1].m_TexCoord.x = v43;
          v[1].m_TexCoord.y = v44;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v29 = flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v9;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_268.w );
    }
    else
    {
      v12 = v10;
      flEndProgressRadians = v12;
      do
      {
        v13 = *((float *)p_swipe_dir_x - 5) + 0.7853981633974483;
        if ( v13 > v12 )
        {
          v14 = flHalfWide.x;
          v15 = flHalfWide.y;
          v16 = v13 - v12;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( v16 >= 0.7853981633974483 )
          {
            v26 = *((float *)p_swipe_dir_x - 4);
            v23 = flTall;
            v[1].m_Position.x = (float)((float)(v26 - 0.5) * flWide) + flHalfWide.x;
            v25 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v25 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v17 = 0.7853981633974483 - v16;
            if ( (v9 & 1) != 0 )
              v17 = 0.7853981633974483 - v17;
            __libm_sse2_tan(x: v45);
            v15 = flHalfWide.y;
            v14 = flHalfWide.x;
            v18 = v17;
            if ( (v9 & 1) == 1 )
            {
              v19 = (float)(flHalfWide.x - (float)(v17 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v20 = flHalfWide.y - (float)(v18 * flHalfWide.x);
              v21 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v19 = (float)(v17 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v20 = (float)p_swipe_dir_x[1];
              v21 = v18 * flHalfWide.x;
            }
            v22 = *((float *)p_swipe_dir_x - 4);
            v23 = flTall;
            v24 = v20 * v21;
            v[1].m_Position.x = (float)(v22 * flWide) + v19;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v24;
            v25 = (float)((float)(v24 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v26 = (float)((float)(v19 / flHalfWide.x) * 0.5) + v22;
          }
          v[1].m_TexCoord.y = v25;
          v[1].m_TexCoord.x = v26;
          v27 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v27 - 0.5) * flWide) + v14;
          v28 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v28 - 0.5) * v23) + v15;
          v[2].m_TexCoord.x = v27;
          v[2].m_TexCoord.y = v28;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v12 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v9;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_268.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300140
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10300170
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x10300180
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103001B0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10300300
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    operator delete(p: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: &var);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: &var);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10300390
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this@<ecx>, unsigned int a2@<ebx>)
{
  unsigned int m_iProgressDirection; // edi
  float v4; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v6; // eax
  Color v7; // [esp+10h] [ebp-8h] BYREF
  float Progress; // [esp+14h] [ebp-4h]

  Progress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v4 = 1.0 - Progress;
  else
    v4 = Progress;
  GetFgColor = this->GetFgColor;
  Progress = v4;
  v6 = GetFgColor(this, result: &v7);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    a2,
    a3: m_iProgressDirection,
    c: *v6,
    flEndProgress: Progress,
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10300400
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100C7320
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x100C7330
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7400
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100C74A0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x100C7530
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(a1: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_83.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(a1: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_83.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C79E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7A10
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x100C7A20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7A50
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C7BA0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: szDescription);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: szDescription);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x100C7C30
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+10h] [ebp-8h] BYREF
  float Progress; // [esp+14h] [ebp-4h]

  Progress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - Progress;
  else
    v3 = Progress;
  GetFgColor = this->GetFgColor;
  Progress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(Progress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C7CA0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0045C500
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0045C510
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C5E0
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0045C680
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0045C710
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_42.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_42.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CBC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CBF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0045CC00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CC30
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045CD80
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0045CE10
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045CE80
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00443310
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00443320
// Name: public: virtual vgui::CircularProgressBar::~CircularProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CircularProgressBar::~CircularProgressBar(vgui::CircularProgressBar *this@<ecx>, int a2@<ebp>)
{
  int *m_lenImageName; // esi
  int i; // edi

  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  m_lenImageName = this->m_lenImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: (void *)*(m_lenImageName - 2));
    *m_lenImageName++ = 0;
  }
  vgui::ProgressBar::~ProgressBar(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00443360
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443430
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = strlen("vgui/") + _V_strlen(str: imageName) + 1;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x004434F0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  _BYTE v8[4]; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v8);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, wide: &v7, tall: &wide);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: v7, a5: wide);
}

//------------------------------------------------------------------------------
// Address: 0x00443580
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // ebx
  __m128d v6; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v8; // xmm1
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  __m128d v14; // xmm2
  __m128i v15; // xmm0
  double v16; // xmm0_8
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  __m128i v27; // xmm0
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  double v31; // xmm0_8
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float flHalfWide; // [esp+8h] [ebp-48h]
  float flWide; // [esp+Ch] [ebp-44h]
  float flTall; // [esp+10h] [ebp-40h]
  float wide; // [esp+14h] [ebp-3Ch]
  int tall; // [esp+18h] [ebp-38h] BYREF
  FontVertex_t v[3]; // [esp+1Ch] [ebp-34h] BYREF
  float v48; // [esp+4Ch] [ebp-4h]
  float flEndProgressRadians; // [esp+5Ch] [ebp+Ch]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+Ch]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, wide: &tall, tall: (int *)v);
    flTall = (float)tall;
    wide = (float)SLODWORD(v[0].m_Position.x);
    flWide = (float)tall * 0.5;
    flHalfWide = (float)SLODWORD(v[0].m_Position.x) * 0.5;
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nTextureId[0]);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v5 = 0;
    v6 = _mm_cvtps_pd((__m128)flEndProgress);
    v6.m128d_f64[0] = v6.m128d_f64[0] * 6.283185307179586;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v27 = (__m128i)_mm_cvtpd_ps(v6);
      flEndProgressRadiansa = v27.m128i_i32[0];
      do
      {
        v28 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v27.m128i_i32 > v28 )
        {
          v29 = flWide;
          v30 = flHalfWide;
          *(float *)v27.m128i_i32 = *(float *)v27.m128i_i32 - v28;
          v[0].m_Position.y = flWide;
          v[0].m_TexCoord.x = flHalfWide;
          v[0].m_TexCoord.y = 0.5;
          v[1].m_Position.x = 0.5;
          if ( *(float *)v27.m128i_i32 >= 0.7853981633974483 )
          {
            v38 = *((float *)p_swipe_dir_x - 2);
            v37 = wide;
            v[2].m_Position.y = (float)((float)(v38 - 0.5) * flTall) + flWide;
            v39 = *((float *)p_swipe_dir_x - 1);
            v[2].m_TexCoord.x = (float)((float)(v39 - 0.5) * wide) + flHalfWide;
          }
          else
          {
            if ( v5 % 2 == 1 )
              *(float *)v27.m128i_i32 = 0.7853981633974483 - *(float *)v27.m128i_i32;
            *(double *)v27.m128i_i64 = *(float *)v27.m128i_i32;
            __libm_sse2_tan(X: v27);
            v30 = flHalfWide;
            v29 = flWide;
            v32 = v31;
            if ( v5 % 2 == 1 )
            {
              v33 = (float)(flWide - (float)(v32 * flHalfWide)) * (float)*p_swipe_dir_x;
              v34 = (float)(flHalfWide - (float)(v32 * flWide)) * (float)p_swipe_dir_x[1];
            }
            else
            {
              v33 = (float)((float)*p_swipe_dir_x * v32) * flHalfWide;
              v34 = (float)((float)p_swipe_dir_x[1] * v32) * flWide;
            }
            v35 = *((float *)p_swipe_dir_x - 4);
            v36 = *((float *)p_swipe_dir_x - 3);
            v37 = wide;
            v[2].m_Position.y = (float)(v35 * flTall) + v33;
            v[2].m_TexCoord.x = (float)(v36 * wide) + v34;
            v38 = (float)((float)(v33 / flWide) * 0.5) + v35;
            v39 = (float)((float)(v34 / flHalfWide) * 0.5) + v36;
          }
          v48 = v39;
          v[2].m_TexCoord.y = v38;
          v40 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.y = (float)((float)(v40 - 0.5) * flTall) + v29;
          v41 = *((float *)p_swipe_dir_x - 3);
          v[1].m_TexCoord.x = (float)((float)(v41 - 0.5) * v37) + v30;
          v[1].m_TexCoord.y = v40;
          v[2].m_Position.x = v41;
          g_pVGuiSurface->DrawTexturedPolygon(
            this: g_pVGuiSurface,
            a2: 3,
            a3: (FontVertex_t *)&v[0].m_Position.y,
            a4: true);
          v27 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v5;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_29.w );
    }
    else
    {
      v8 = 0x3FE921FB54442D18uLL;
      v9 = v6.m128d_f64[0];
      flEndProgressRadians = v9;
      do
      {
        v10 = *((float *)p_swipe_dir_x - 5) + *(double *)&v8;
        if ( v10 > v9 )
        {
          v11 = flWide;
          v12 = flHalfWide;
          v13 = v10 - v9;
          v[0].m_Position.y = flWide;
          v[0].m_TexCoord.x = flHalfWide;
          v[0].m_TexCoord.y = 0.5;
          v[1].m_Position.x = 0.5;
          if ( *(double *)&v8 <= v13 )
          {
            v23 = *((float *)p_swipe_dir_x - 4);
            v22 = wide;
            v[1].m_Position.y = (float)((float)(v23 - 0.5) * flTall) + flWide;
            v24 = *((float *)p_swipe_dir_x - 3);
            v[1].m_TexCoord.x = (float)((float)(v24 - 0.5) * wide) + flHalfWide;
          }
          else
          {
            v14.m128d_f64[1] = *((double *)&v8 + 1);
            v14.m128d_f64[0] = *(double *)&v8 - v13;
            v15 = (__m128i)_mm_cvtpd_ps(v14);
            if ( v5 % 2 == 1 )
              *(float *)v15.m128i_i32 = *(double *)&v8 - *(float *)v15.m128i_i32;
            *(double *)v15.m128i_i64 = *(float *)v15.m128i_i32;
            __libm_sse2_tan(X: v15);
            v12 = flHalfWide;
            v11 = flWide;
            v17 = v16;
            if ( v5 % 2 == 1 )
            {
              v18 = (float)(flWide - (float)(v17 * flHalfWide)) * (float)*p_swipe_dir_x;
              v19 = (float)(flHalfWide - (float)(v17 * flWide)) * (float)p_swipe_dir_x[1];
            }
            else
            {
              v18 = (float)((float)*p_swipe_dir_x * v17) * flHalfWide;
              v19 = (float)((float)p_swipe_dir_x[1] * v17) * flWide;
            }
            v20 = *((float *)p_swipe_dir_x - 4);
            v21 = *((float *)p_swipe_dir_x - 3);
            v22 = wide;
            v[1].m_Position.y = (float)(v20 * flTall) + v18;
            v[1].m_TexCoord.x = (float)(v21 * wide) + v19;
            v23 = (float)((float)(v18 / flWide) * 0.5) + v20;
            v24 = (float)((float)(v19 / flHalfWide) * 0.5) + v21;
          }
          v[2].m_Position.x = v24;
          v[1].m_TexCoord.y = v23;
          v25 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.y = (float)((float)(v25 - 0.5) * flTall) + v11;
          v26 = *((float *)p_swipe_dir_x - 1);
          v[2].m_TexCoord.x = (float)((float)(v26 - 0.5) * v22) + v12;
          v[2].m_TexCoord.y = v25;
          v48 = v26;
          g_pVGuiSurface->DrawTexturedPolygon(
            this: g_pVGuiSurface,
            a2: 3,
            a3: (FontVertex_t *)&v[0].m_Position.y,
            a4: true);
          v8 = 0x3FE921FB54442D18uLL;
          v9 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v5;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_29.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443A60
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00443A90
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00443AA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00443AD0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  char **m_pszImageName; // eax
  int i; // ecx

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    *(m_pszImageName - 2) = (char *)-1;
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00443BE0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  const char *String; // eax
  const char *v6; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v6 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v6, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00443C70
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float flEndProgress; // xmm0_4
  Color *v4; // eax
  float Progress; // [esp+14h] [ebp-8h]
  _BYTE v6[4]; // [esp+18h] [ebp-4h] BYREF

  Progress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    flEndProgress = 1.0 - Progress;
  else
    flEndProgress = Progress;
  v4 = this->GetFgColor(this, result: v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v4,
    flEndProgress: LODWORD(flEndProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x00443CE0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0064A040
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0064A050
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064A120
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0064A1C0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0064A250
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_244.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_244.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064A700
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064A730
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0064A740
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064A770
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0064A8C0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0064A950
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x0064A9C0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10067F80
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x10067F90
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068060
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10068100
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10068190
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_54.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_54.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068640
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068670
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x10068680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100686B0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068800
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10068890
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068900
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1007A620
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x1007A630
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A700
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1007A7A0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1007A830
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_34.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_34.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ACE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007AD10
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1007AD20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007AD50
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007AEA0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1007AF30
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007AFA0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0044C090
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0044C0A0
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C170
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0044C210
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0044C2A0
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_42.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_42.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C750
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C780
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0044C790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C7C0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044C910
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: &defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: &defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0044C9A0
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x0044CA10
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00495250
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00495260
// Name: public: virtual vgui::CircularProgressBar::~CircularProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CircularProgressBar::~CircularProgressBar(vgui::CircularProgressBar *this@<ecx>, int a2@<ebp>)
{
  int *m_lenImageName; // esi
  int i; // edi

  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  m_lenImageName = this->m_lenImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: (void *)*(m_lenImageName - 2));
    *m_lenImageName++ = 0;
  }
  vgui::ProgressBar::~ProgressBar(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004952A0
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495370
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = strlen("vgui/") + _V_strlen(str: imageName) + 1;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x00495430
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  _BYTE v8[4]; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v8);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, wide: &v7, tall: &wide);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: v7, a5: wide);
}

//------------------------------------------------------------------------------
// Address: 0x004954C0
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // ebx
  __m128d v6; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v8; // xmm1
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  __m128d v14; // xmm2
  __m128i v15; // xmm0
  double v16; // xmm0_8
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  __m128i v27; // xmm0
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  double v31; // xmm0_8
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float flHalfWide; // [esp+8h] [ebp-48h]
  float flWide; // [esp+Ch] [ebp-44h]
  float flTall; // [esp+10h] [ebp-40h]
  float wide; // [esp+14h] [ebp-3Ch]
  int tall; // [esp+18h] [ebp-38h] BYREF
  FontVertex_t v[3]; // [esp+1Ch] [ebp-34h] BYREF
  float v48; // [esp+4Ch] [ebp-4h]
  float flEndProgressRadians; // [esp+5Ch] [ebp+Ch]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+Ch]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, wide: &tall, tall: (int *)v);
    flTall = (float)tall;
    wide = (float)SLODWORD(v[0].m_Position.x);
    flWide = (float)tall * 0.5;
    flHalfWide = (float)SLODWORD(v[0].m_Position.x) * 0.5;
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nTextureId[0]);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v5 = 0;
    v6 = _mm_cvtps_pd((__m128)flEndProgress);
    v6.m128d_f64[0] = v6.m128d_f64[0] * 6.283185307179586;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v27 = (__m128i)_mm_cvtpd_ps(v6);
      flEndProgressRadiansa = v27.m128i_i32[0];
      do
      {
        v28 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v27.m128i_i32 > v28 )
        {
          v29 = flWide;
          v30 = flHalfWide;
          *(float *)v27.m128i_i32 = *(float *)v27.m128i_i32 - v28;
          v[0].m_Position.y = flWide;
          v[0].m_TexCoord.x = flHalfWide;
          v[0].m_TexCoord.y = 0.5;
          v[1].m_Position.x = 0.5;
          if ( *(float *)v27.m128i_i32 >= 0.7853981633974483 )
          {
            v38 = *((float *)p_swipe_dir_x - 2);
            v37 = wide;
            v[2].m_Position.y = (float)((float)(v38 - 0.5) * flTall) + flWide;
            v39 = *((float *)p_swipe_dir_x - 1);
            v[2].m_TexCoord.x = (float)((float)(v39 - 0.5) * wide) + flHalfWide;
          }
          else
          {
            if ( v5 % 2 == 1 )
              *(float *)v27.m128i_i32 = 0.7853981633974483 - *(float *)v27.m128i_i32;
            *(double *)v27.m128i_i64 = *(float *)v27.m128i_i32;
            __libm_sse2_tan(X: v27);
            v30 = flHalfWide;
            v29 = flWide;
            v32 = v31;
            if ( v5 % 2 == 1 )
            {
              v33 = (float)(flWide - (float)(v32 * flHalfWide)) * (float)*p_swipe_dir_x;
              v34 = (float)(flHalfWide - (float)(v32 * flWide)) * (float)p_swipe_dir_x[1];
            }
            else
            {
              v33 = (float)((float)*p_swipe_dir_x * v32) * flHalfWide;
              v34 = (float)((float)p_swipe_dir_x[1] * v32) * flWide;
            }
            v35 = *((float *)p_swipe_dir_x - 4);
            v36 = *((float *)p_swipe_dir_x - 3);
            v37 = wide;
            v[2].m_Position.y = (float)(v35 * flTall) + v33;
            v[2].m_TexCoord.x = (float)(v36 * wide) + v34;
            v38 = (float)((float)(v33 / flWide) * 0.5) + v35;
            v39 = (float)((float)(v34 / flHalfWide) * 0.5) + v36;
          }
          v48 = v39;
          v[2].m_TexCoord.y = v38;
          v40 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.y = (float)((float)(v40 - 0.5) * flTall) + v29;
          v41 = *((float *)p_swipe_dir_x - 3);
          v[1].m_TexCoord.x = (float)((float)(v41 - 0.5) * v37) + v30;
          v[1].m_TexCoord.y = v40;
          v[2].m_Position.x = v41;
          g_pVGuiSurface->DrawTexturedPolygon(
            this: g_pVGuiSurface,
            a2: 3,
            a3: (FontVertex_t *)&v[0].m_Position.y,
            a4: true);
          v27 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v5;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_61.w );
    }
    else
    {
      v8 = 0x3FE921FB54442D18uLL;
      v9 = v6.m128d_f64[0];
      flEndProgressRadians = v9;
      do
      {
        v10 = *((float *)p_swipe_dir_x - 5) + *(double *)&v8;
        if ( v10 > v9 )
        {
          v11 = flWide;
          v12 = flHalfWide;
          v13 = v10 - v9;
          v[0].m_Position.y = flWide;
          v[0].m_TexCoord.x = flHalfWide;
          v[0].m_TexCoord.y = 0.5;
          v[1].m_Position.x = 0.5;
          if ( *(double *)&v8 <= v13 )
          {
            v23 = *((float *)p_swipe_dir_x - 4);
            v22 = wide;
            v[1].m_Position.y = (float)((float)(v23 - 0.5) * flTall) + flWide;
            v24 = *((float *)p_swipe_dir_x - 3);
            v[1].m_TexCoord.x = (float)((float)(v24 - 0.5) * wide) + flHalfWide;
          }
          else
          {
            v14.m128d_f64[1] = *((double *)&v8 + 1);
            v14.m128d_f64[0] = *(double *)&v8 - v13;
            v15 = (__m128i)_mm_cvtpd_ps(v14);
            if ( v5 % 2 == 1 )
              *(float *)v15.m128i_i32 = *(double *)&v8 - *(float *)v15.m128i_i32;
            *(double *)v15.m128i_i64 = *(float *)v15.m128i_i32;
            __libm_sse2_tan(X: v15);
            v12 = flHalfWide;
            v11 = flWide;
            v17 = v16;
            if ( v5 % 2 == 1 )
            {
              v18 = (float)(flWide - (float)(v17 * flHalfWide)) * (float)*p_swipe_dir_x;
              v19 = (float)(flHalfWide - (float)(v17 * flWide)) * (float)p_swipe_dir_x[1];
            }
            else
            {
              v18 = (float)((float)*p_swipe_dir_x * v17) * flHalfWide;
              v19 = (float)((float)p_swipe_dir_x[1] * v17) * flWide;
            }
            v20 = *((float *)p_swipe_dir_x - 4);
            v21 = *((float *)p_swipe_dir_x - 3);
            v22 = wide;
            v[1].m_Position.y = (float)(v20 * flTall) + v18;
            v[1].m_TexCoord.x = (float)(v21 * wide) + v19;
            v23 = (float)((float)(v18 / flWide) * 0.5) + v20;
            v24 = (float)((float)(v19 / flHalfWide) * 0.5) + v21;
          }
          v[2].m_Position.x = v24;
          v[1].m_TexCoord.y = v23;
          v25 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.y = (float)((float)(v25 - 0.5) * flTall) + v11;
          v26 = *((float *)p_swipe_dir_x - 1);
          v[2].m_TexCoord.x = (float)((float)(v26 - 0.5) * v22) + v12;
          v[2].m_TexCoord.y = v25;
          v48 = v26;
          g_pVGuiSurface->DrawTexturedPolygon(
            this: g_pVGuiSurface,
            a2: 3,
            a3: (FontVertex_t *)&v[0].m_Position.y,
            a4: true);
          v8 = 0x3FE921FB54442D18uLL;
          v9 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v5;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_61.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004959A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004959D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x004959E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495A10
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  char **m_pszImageName; // eax
  int i; // ecx

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    *(m_pszImageName - 2) = (char *)-1;
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00495B20
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  const char *String; // eax
  const char *v6; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v6 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v6, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, a2: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00495BB0
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float flEndProgress; // xmm0_4
  Color *v4; // eax
  float Progress; // [esp+14h] [ebp-8h]
  _BYTE v6[4]; // [esp+18h] [ebp-4h] BYREF

  Progress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    flEndProgress = 1.0 - Progress;
  else
    flEndProgress = Progress;
  v4 = this->GetFgColor(this, result: v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v4,
    flEndProgress: LODWORD(flEndProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x00495C20
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0043AA40
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043AA50
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AB20
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0043ABC0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0043AC50
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_26.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_26.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B100
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B130
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043B140
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B170
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043B2C0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0043B350
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043B3C0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0043E550
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043E560
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E630
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0043E6D0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0043E760
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_27.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_27.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EC10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043EC40
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043EC50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043EC80
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043EDD0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  const char *String; // eax
  const char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: defaultValue);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: defaultValue);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0043EE60
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043EED0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103B40C0
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x103B40D0
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B41A0
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    C_BaseEntity::operator delete(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x103B4240
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103B42D0
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_125.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((long double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_125.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B4780
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B47B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x103B47C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B47F0
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B4940
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    C_BaseEntity::operator delete(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: prType);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: prType);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x103B49D0
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x103B4A40
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103AC460
// Name: public: static char const __near * vgui::CircularProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CircularProgressBar::GetPanelClassName()
{
  return "CircularProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x103AC470
// Name: public: virtual void vgui::CircularProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySchemeSettings(vgui::CircularProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CircularProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CircularProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  int *m_nTextureId; // esi
  int i; // edi
  const char *v10; // eax

  v2 = pScheme;
  vgui::ProgressBar::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "CircularProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::CircularProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  this->SetBorder(this, a2: nullptr);
  m_nTextureId = this->m_nTextureId;
  for ( i = 2; i != 0; --i )
  {
    v10 = (const char *)m_nTextureId[2];
    if ( v10 != nullptr && strlen(v10) != 0 )
    {
      if ( *m_nTextureId == -1 )
        *m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
      g_pVGuiSurface->DrawSetTextureFile(
        this: g_pVGuiSurface,
        a2: *m_nTextureId,
        a3: (const char *)m_nTextureId[2],
        a4: 1,
        a5: false);
    }
    ++m_nTextureId;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AC540
// Name: protected: void vgui::CircularProgressBar::SetImage(char const __near *,enum progress_textures_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::SetImage(
        vgui::CircularProgressBar *this,
        const char *imageName,
        progress_textures_t iPos)
{
  signed int v4; // edi

  v4 = _V_strlen(str: imageName) + 6;
  if ( this->m_pszImageName[iPos] != nullptr && this->m_lenImageName[iPos] < v4 )
  {
    free(pMem: this->m_pszImageName[iPos]);
    this->m_pszImageName[iPos] = nullptr;
    this->m_lenImageName[iPos] = 0;
  }
  if ( this->m_pszImageName[iPos] == nullptr )
  {
    this->m_pszImageName[iPos] = (char *)operator new(nSize: v4);
    this->m_lenImageName[iPos] = v4;
  }
  V_snprintf(pDest: this->m_pszImageName[iPos], maxLen: v4, pFormat: "%s%s", "vgui/", imageName);
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x103AC5E0
// Name: protected: virtual void vgui::CircularProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::PaintBackground(vgui::CircularProgressBar *this)
{
  int v2; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v2 = this->m_nTextureId[1];
  if ( v2 == -1 )
    v2 = this->m_nTextureId[0];
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: v2);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = this->GetBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v4->DrawSetColor)(a1: v3, a2: *v5);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103AC670
// Name: protected: void vgui::CircularProgressBar::DrawCircleSegment(class Color,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall vgui::CircularProgressBar::DrawCircleSegment(
        vgui::CircularProgressBar *this,
        Color c,
        unsigned int flEndProgress,
        bool bClockwise)
{
  int v5; // eax
  void (__thiscall *DrawSetTexture)(vgui::ISurface *, int); // edx
  char v7; // bl
  __m128d v8; // xmm0
  int *p_swipe_dir_x; // esi
  __int128 v10; // xmm1
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  __m128d v16; // xmm2
  __m128 v17; // xmm0
  double v18; // xmm1_8
  double v19; // xmm0_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  __m128i v31; // xmm0
  float v32; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  double v35; // xmm5_8
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  FontVertex_t v[3]; // [esp+4h] [ebp-48h] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int wide; // [esp+38h] [ebp-14h] BYREF
  float flTall; // [esp+3Ch] [ebp-10h]
  float flWide; // [esp+40h] [ebp-Ch]
  Vector2D flHalfWide; // [esp+44h] [ebp-8h] OVERLAPPED
  float flEndProgressRadians; // [esp+5Ch] [ebp+10h]
  int flEndProgressRadiansa; // [esp+5Ch] [ebp+10h]

  if ( this->m_nTextureId[0] != -1 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v5 = this->m_nTextureId[0];
    DrawSetTexture = g_pVGuiSurface->DrawSetTexture;
    flWide = (float)wide;
    flTall = (float)tall;
    flHalfWide.x = (float)wide * 0.5;
    flHalfWide.y = (float)tall * 0.5;
    DrawSetTexture(this: g_pVGuiSurface, a2: v5);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: c);
    v7 = 0;
    v8 = _mm_cvtps_pd((__m128)flEndProgress);
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
    p_swipe_dir_x = &vgui::Segments[0].swipe_dir_x;
    if ( bClockwise )
    {
      v31 = (__m128i)_mm_cvtpd_ps(v8);
      flEndProgressRadiansa = v31.m128i_i32[0];
      do
      {
        v32 = *((float *)p_swipe_dir_x - 5);
        if ( *(float *)v31.m128i_i32 > v32 )
        {
          x = flHalfWide.x;
          y = flHalfWide.y;
          *(float *)v31.m128i_i32 = *(float *)v31.m128i_i32 - v32;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(float *)v31.m128i_i32 >= 0.7853981633974483 )
          {
            v45 = *((float *)p_swipe_dir_x - 2);
            v42 = flTall;
            v[2].m_Position.x = (float)((float)(v45 - 0.5) * flWide) + flHalfWide.x;
            v44 = *((float *)p_swipe_dir_x - 1);
            v[2].m_Position.y = (float)((float)(v44 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            if ( (v7 & 1) != 0 )
            {
              v35 = 0.7853981633974483 - *(float *)v31.m128i_i32;
              v31 = 0;
              *(float *)v31.m128i_i32 = v35;
            }
            *(double *)v31.m128i_i64 = *(float *)v31.m128i_i32;
            __libm_sse2_tan(X: v31);
            y = flHalfWide.y;
            x = flHalfWide.x;
            v37 = v36;
            if ( (v7 & 1) == 1 )
            {
              v38 = (float)(flHalfWide.x - (float)(v37 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v39 = flHalfWide.y - (float)(v37 * flHalfWide.x);
              v40 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v38 = (float)(v37 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v39 = (float)p_swipe_dir_x[1];
              v40 = v37 * flHalfWide.x;
            }
            v41 = *((float *)p_swipe_dir_x - 4);
            v42 = flTall;
            v43 = v39 * v40;
            v[2].m_Position.x = (float)(v41 * flWide) + v38;
            v[2].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v43;
            v44 = (float)((float)(v43 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v45 = (float)((float)(v38 / flHalfWide.x) * 0.5) + v41;
          }
          v[2].m_TexCoord.y = v44;
          v[2].m_TexCoord.x = v45;
          v46 = *((float *)p_swipe_dir_x - 4);
          v[1].m_Position.x = (float)((float)(v46 - 0.5) * flWide) + x;
          v47 = *((float *)p_swipe_dir_x - 3);
          v[1].m_Position.y = (float)((float)(v47 - 0.5) * v42) + y;
          v[1].m_TexCoord.x = v46;
          v[1].m_TexCoord.y = v47;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v31 = (__m128i)(unsigned int)flEndProgressRadiansa;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_47.w );
    }
    else
    {
      v10 = 0x3FE921FB54442D18uLL;
      v11 = v8.m128d_f64[0];
      flEndProgressRadians = v11;
      do
      {
        v12 = *((float *)p_swipe_dir_x - 5) + *(double *)&v10;
        if ( v12 > v11 )
        {
          v13 = flHalfWide.x;
          v14 = flHalfWide.y;
          v15 = v12 - v11;
          v[0].m_Position = flHalfWide;
          v[0].m_TexCoord.x = 0.5;
          v[0].m_TexCoord.y = 0.5;
          if ( *(double *)&v10 <= v15 )
          {
            v28 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v[1].m_Position.x = (float)((float)(v28 - 0.5) * flWide) + flHalfWide.x;
            v27 = *((float *)p_swipe_dir_x - 3);
            v[1].m_Position.y = (float)((float)(v27 - 0.5) * flTall) + flHalfWide.y;
          }
          else
          {
            v16.m128d_f64[1] = *((long double *)&v10 + 1);
            v16.m128d_f64[0] = *(double *)&v10 - v15;
            v17 = _mm_cvtpd_ps(v16);
            if ( (v7 & 1) != 0 )
            {
              v18 = *(double *)&v10 - v17.m128_f32[0];
              v17 = 0;
              v17.m128_f32[0] = v18;
            }
            __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v17));
            v14 = flHalfWide.y;
            v13 = flHalfWide.x;
            v20 = v19;
            if ( (v7 & 1) == 1 )
            {
              v21 = (float)(flHalfWide.x - (float)(v20 * flHalfWide.y)) * (float)*p_swipe_dir_x;
              v22 = flHalfWide.y - (float)(v20 * flHalfWide.x);
              v23 = (float)p_swipe_dir_x[1];
            }
            else
            {
              v21 = (float)(v20 * flHalfWide.y) * (float)*p_swipe_dir_x;
              v22 = (float)p_swipe_dir_x[1];
              v23 = v20 * flHalfWide.x;
            }
            v24 = *((float *)p_swipe_dir_x - 4);
            v25 = flTall;
            v26 = v22 * v23;
            v[1].m_Position.x = (float)(v24 * flWide) + v21;
            v[1].m_Position.y = (float)(*((float *)p_swipe_dir_x - 3) * flTall) + v26;
            v27 = (float)((float)(v26 / flHalfWide.y) * 0.5) + *((float *)p_swipe_dir_x - 3);
            v28 = (float)((float)(v21 / flHalfWide.x) * 0.5) + v24;
          }
          v[1].m_TexCoord.y = v27;
          v[1].m_TexCoord.x = v28;
          v29 = *((float *)p_swipe_dir_x - 2);
          v[2].m_Position.x = (float)((float)(v29 - 0.5) * flWide) + v13;
          v30 = *((float *)p_swipe_dir_x - 1);
          v[2].m_Position.y = (float)((float)(v30 - 0.5) * v25) + v14;
          v[2].m_TexCoord.x = v29;
          v[2].m_TexCoord.y = v30;
          g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          v10 = 0x3FE921FB54442D18uLL;
          v11 = flEndProgressRadians;
        }
        p_swipe_dir_x += 7;
        ++v7;
      }
      while ( (int)p_swipe_dir_x < (int)&vec4_invalid_47.w );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ACB20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CircularProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CircularProgressBar::GetMessageMap(vgui::CircularProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103ACB50
// Name: public: virtual struct PanelAnimationMap __near * vgui::CircularProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CircularProgressBar::GetAnimMap(vgui::CircularProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CircularProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x103ACB60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CircularProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CircularProgressBar::GetKBMap(vgui::CircularProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::CircularProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
  `vgui::CircularProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103ACB90
// Name: public: vgui::CircularProgressBar::CircularProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__thiscall vgui::CircularProgressBar::CircularProgressBar(
        vgui::CircularProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::CircularProgressBar_vtbl *)&vgui::CircularProgressBar::`vftable';
  if ( `vgui::CircularProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CircularProgressBar");
    v4->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CircularProgressBar");
    v5->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CircularProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CircularProgressBar");
    v6->pfnClassName = vgui::CircularProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  this->m_iProgressDirection = 1;
  this->m_pszImageName[0] = nullptr;
  this->m_lenImageName[0] = 0;
  this->m_pszImageName[1] = nullptr;
  this->m_lenImageName[1] = 0;
  this->m_nTextureId[0] = -1;
  this->m_nTextureId[1] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103ACCE0
// Name: public: virtual void vgui::CircularProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::ApplySettings(vgui::CircularProgressBar *this, KeyValues *inResourceData)
{
  char **m_pszImageName; // esi
  int i; // edi
  char *String; // eax
  char *v5; // eax

  m_pszImageName = this->m_pszImageName;
  for ( i = 2; i != 0; --i )
  {
    free(pMem: *m_pszImageName);
    *m_pszImageName = nullptr;
    m_pszImageName[2] = nullptr;
    ++m_pszImageName;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "fg_image", defaultValue: locale);
  if ( *String != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: String, iPos: PROGRESS_TEXTURE_FG);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "bg_image", defaultValue: locale);
  if ( *v5 != 0 )
    vgui::CircularProgressBar::SetImage(this, imageName: v5, iPos: PROGRESS_TEXTURE_BG);
  vgui::ProgressBar::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x103ACD70
// Name: protected: virtual void vgui::CircularProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CircularProgressBar::Paint(vgui::CircularProgressBar *this)
{
  int m_iProgressDirection; // edi
  float v3; // xmm0_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  Color *v5; // eax
  Color v6; // [esp+14h] [ebp-8h] BYREF
  float flProgress; // [esp+18h] [ebp-4h]

  flProgress = vgui::ProgressBar::GetProgress(this);
  m_iProgressDirection = this->m_iProgressDirection;
  if ( m_iProgressDirection != 0 )
    v3 = 1.0 - flProgress;
  else
    v3 = flProgress;
  GetFgColor = this->GetFgColor;
  flProgress = v3;
  v5 = GetFgColor(this, result: &v6);
  vgui::CircularProgressBar::DrawCircleSegment(
    this,
    c: *v5,
    flEndProgress: LODWORD(flProgress),
    bClockwise: m_iProgressDirection == 0);
}

//------------------------------------------------------------------------------
// Address: 0x103ACDE0
// Name: Create_CircularProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::CircularProgressBar *__cdecl Create_CircularProgressBar()
{
  vgui::CircularProgressBar *v0; // eax

  v0 = (vgui::CircularProgressBar *)operator new(nSize: 0x194u);
  if ( v0 != nullptr )
    return vgui::CircularProgressBar::CircularProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace server
