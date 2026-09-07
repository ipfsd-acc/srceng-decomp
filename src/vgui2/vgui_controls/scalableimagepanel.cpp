// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/scalableimagepanel.cpp
// Functions: 12
// ============================================================

#include "vgui2\vgui_controls\scalableimagepanel.h"

//------------------------------------------------------------------------------
// Address: 0x102CB530
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102CB540
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CB5C0
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102CB850
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x102CB8E0
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x102CB9A0
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_12,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x102CB9D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBA00
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x102CBA10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBA40
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CBBA0
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CBD90
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1005A5E0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1005A5F0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A670
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005A900
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x1005A990
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1005AA50
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_11,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x1005AA80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005AAB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1005AAC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005AAF0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005AC50
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  unsigned int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1005AE40
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00440DE0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00440DF0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440E70
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00441100
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00441190
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x00441250
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_9,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x00441280
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004412B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004412C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004412F0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441450
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00441640
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100708A0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100708B0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070930
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10070BC0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x10070C50
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10070D10
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x10070D40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10070D70
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10070D80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10070DB0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10070F10
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10071100
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B32C0
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3DA0
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00618CF0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00618D00
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00618D80
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00619010
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x006190A0
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x00619160
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_9,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x00619190
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006191C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x006191D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00619200
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00619360
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00619550
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102CB660
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102CB670
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CB6F0
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102CB980
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x102CBAD0
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_12,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x102CBB00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBB30
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x102CBB40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBB70
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        __m128i *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CBCD0
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CBEC0
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10304BB0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10304BC0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  operator delete(p: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = std::char_traits<char>::length(str: imageName) + 6;
    operator delete(p: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10304C40
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10304ED0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x10304F60
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10305020
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_13,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x10305050
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10305080
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10305090
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103050C0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10305220
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  operator delete(p: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: &var);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = std::char_traits<char>::length(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: &var);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10305410
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100C8800
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100C8810
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8890
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C8B20
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x100C8BB0
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100C8C70
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_12,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x100C8CA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C8CD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100C8CE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C8D10
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C8E70
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: szDescription);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: szDescription);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C9060
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004617B0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004617C0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461840
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00461AD0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00461B60
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x00461C20
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x00461C50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00461C80
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00461C90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00461CC0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00461E20
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00462010
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00447F60
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00447F70
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447FE0
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  vgui::ISurface *v2; // edi
  int v3; // ebx
  vgui::ISurface_vtbl *v4; // ebp
  int Alpha; // eax
  int v6; // ebp
  float v7; // xmm4_4
  int i; // ebx
  int v9; // ecx
  float v10; // xmm3_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm0_4
  float m_iCornerHeight; // xmm2_4
  float v15; // xmm1_4
  int v16; // edi
  float v17; // xmm2_4
  double v18; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm2_4
  void (__thiscall *DrawTexturedPolygon)(vgui::ISurface *, int, FontVertex_t *, bool); // eax
  float uvy; // [esp+20h] [ebp-7Ch]
  float drawW; // [esp+24h] [ebp-78h]
  int v24; // [esp+2Ch] [ebp-70h]
  int talla; // [esp+30h] [ebp-6Ch]
  float tall; // [esp+30h] [ebp-6Ch]
  int wide; // [esp+34h] [ebp-68h] BYREF
  int v28; // [esp+38h] [ebp-64h] BYREF
  float y; // [esp+3Ch] [ebp-60h]
  float v30; // [esp+40h] [ebp-5Ch]
  float v31; // [esp+44h] [ebp-58h]
  float v32; // [esp+48h] [ebp-54h]
  Vector2D uv12; // [esp+50h] [ebp-4Ch]
  FontVertex_t verts[4]; // [esp+58h] [ebp-44h] BYREF
  float v35; // [esp+98h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &v28, tall: &wide);
  v2 = g_pVGuiSurface;
  v3 = this->m_DrawColor._color[2];
  v4 = g_pVGuiSurface->__vftable;
  talla = this->m_DrawColor._color[1];
  v24 = this->m_DrawColor._color[0];
  Alpha = vgui::Panel::GetAlpha(this);
  v4->DrawSetColor_2(this: v2, a2: v24, a3: talla, a4: v3, a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v6 = 0;
  v7 = 0.0;
  drawW = 0.0;
  for ( i = 0; i < 3; ++i )
  {
    v9 = 0;
    v10 = 0.0;
    if ( i == 0 || i == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      m_iCornerHeight = (float)(wide - 2 * this->m_iCornerHeight < 0 ? 0 : wide - 2 * this->m_iCornerHeight);
    }
    uvy = m_flCornerHeightPercent;
    v15 = (float)v6;
    v16 = 0;
    tall = (float)v6 + m_iCornerHeight;
    uv12.x = tall;
    while ( 1 )
    {
      if ( v16 == 0 || v16 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v17 = this->m_flCornerWidthPercent * 2.0;
        v18 = (float)(1.0 - v17) <= 0.0 ? 0.0 : (float)(1.0 - v17);
        m_flCornerWidthPercent = v18;
        m_iCornerWidth = (float)(v28 - 2 * this->m_iCornerWidth < 0 ? 0 : v28 - 2 * this->m_iCornerWidth);
      }
      v30 = m_flCornerWidthPercent + v10;
      verts[0].m_TexCoord.x = v15;
      verts[3].m_Position.x = uvy + v7;
      verts[0].m_Position.x = uvy + v7;
      v32 = (float)v6;
      verts[1].m_Position.x = v7;
      verts[1].m_Position.y = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = v7;
      verts[3].m_TexCoord.x = uv12.x;
      verts[0].m_Position.y = (float)v9;
      verts[0].m_TexCoord.y = v10;
      verts[1].m_TexCoord.x = (float)v6;
      verts[1].m_TexCoord.y = m_flCornerWidthPercent + v10;
      verts[2].m_Position.y = verts[1].m_Position.y;
      verts[2].m_TexCoord.x = tall;
      verts[2].m_TexCoord.y = m_flCornerWidthPercent + v10;
      verts[3].m_Position.y = (float)v9;
      verts[3].m_TexCoord.y = v10;
      v35 = uvy + v7;
      DrawTexturedPolygon = g_pVGuiSurface->DrawTexturedPolygon;
      y = verts[1].m_Position.y;
      v31 = verts[1].m_Position.y;
      DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: (FontVertex_t *)&verts[0].m_Position.y, a4: true);
      v9 = (int)y;
      v10 = v30;
      if ( ++v16 >= 3 )
        break;
      v7 = drawW;
      v15 = (float)v6;
    }
    v7 = uvy + drawW;
    v6 = (int)tall;
    drawW = uvy + drawW;
  }
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004482C0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00448350
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  bool v5; // cc
  int tall; // [esp+1Ch] [ebp-8h] BYREF
  int v7; // [esp+20h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &tall, a4: &v7);
  if ( tall <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)tall;
  v4 = v7;
  v5 = v7 <= 0;
  this->m_flCornerWidthPercent = v3;
  if ( v5 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x00448400
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x00448430
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448460
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00448470
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004484A0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00448610
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        KeyValues *inResourceData,
        int a3)
{
  KeyValues *v3; // ebp
  const char *String; // eax
  char *v6; // edi
  unsigned int v7; // ebp
  char *v8; // eax
  int v9; // eax
  vgui::ISchemeManager *v10; // ebp
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v16; // edx
  vgui::ISchemeManager *v17; // edi
  int v18; // eax
  int v19; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v21; // edx
  vgui::ISchemeManager *v22; // edi
  int v23; // eax
  const char *v24; // eax
  int r; // [esp+10h] [ebp-14h] BYREF
  int g; // [esp+14h] [ebp-10h] BYREF
  int b; // [esp+18h] [ebp-Ch] BYREF
  int a; // [esp+1Ch] [ebp-8h] BYREF
  int v29; // [esp+20h] [ebp-4h] BYREF

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  v6 = (char *)String;
  if ( *String != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    v29 = 255;
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pszDrawColorName = v8;
    V_strncpy(pDest: v8, pSrc: v6, maxLen: v7);
    if ( sscanf(string: v6, format: "%d %d %d %d", &g, &b, &a, &v29) < 3 )
    {
      v10 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v12 = GetScheme(this);
      v13 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(r + 32))(a1: v10, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      r = 0;
      v9 = *(_DWORD *)v14(a1: v13, a2: &r, a3: v6, a4: 0);
    }
    else
    {
      LOBYTE(r) = g;
      BYTE1(r) = b;
      BYTE2(r) = a;
      HIBYTE(r) = v29;
      v9 = r;
    }
    v3 = inResourceData;
    this->m_DrawColor = (Color)v9;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v16 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v16->IsProportional(this) )
  {
    v17 = g_pVGuiSchemeManager;
    v18 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v19 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(a3 + 52))(a1: v17, a2: v18);
    m_iCornerWidth = this->m_iCornerWidth;
    v21 = this->__vftable;
    this->m_iCornerHeight = v19;
    v22 = g_pVGuiSchemeManager;
    v23 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v21->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(a3 + 52))(a1: v22, a2: v23);
  }
  v24 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v24);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00448820
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0064F230
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0064F240
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064F2C0
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0064F550
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0064F5E0
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x0064F6A0
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x0064F6D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064F700
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0064F710
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064F740
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0064F8A0
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0064FA90
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1006C270
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1006C280
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C300
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006C590
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x1006C620
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1006C6E0
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_13,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x1006C710
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006C740
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1006C750
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006C780
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006C8E0
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006CAD0
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1007F4C0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1007F4D0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F550
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007F7E0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x1007F870
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1007F930
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_9,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x1007F960
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F990
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1007F9A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F9D0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007FB30
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD20
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00451410
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00451420
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004514A0
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00451730
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x004517C0
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x00451880
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x004518B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004518E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004518F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00451920
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00451A80
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: &defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: &defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00451C70
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00499D40
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00499D50
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499DC0
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  vgui::ISurface *v2; // edi
  int v3; // ebx
  vgui::ISurface_vtbl *v4; // ebp
  int Alpha; // eax
  int v6; // ebp
  float v7; // xmm4_4
  int i; // ebx
  int v9; // ecx
  float v10; // xmm3_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm0_4
  float m_iCornerHeight; // xmm2_4
  float v15; // xmm1_4
  int v16; // edi
  float v17; // xmm2_4
  double v18; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm2_4
  void (__thiscall *DrawTexturedPolygon)(vgui::ISurface *, int, FontVertex_t *, bool); // eax
  float uvy; // [esp+20h] [ebp-7Ch]
  float drawW; // [esp+24h] [ebp-78h]
  int v24; // [esp+2Ch] [ebp-70h]
  int talla; // [esp+30h] [ebp-6Ch]
  float tall; // [esp+30h] [ebp-6Ch]
  int wide; // [esp+34h] [ebp-68h] BYREF
  int v28; // [esp+38h] [ebp-64h] BYREF
  float y; // [esp+3Ch] [ebp-60h]
  float v30; // [esp+40h] [ebp-5Ch]
  float v31; // [esp+44h] [ebp-58h]
  float v32; // [esp+48h] [ebp-54h]
  Vector2D uv12; // [esp+50h] [ebp-4Ch]
  FontVertex_t verts[4]; // [esp+58h] [ebp-44h] BYREF
  float v35; // [esp+98h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &v28, tall: &wide);
  v2 = g_pVGuiSurface;
  v3 = this->m_DrawColor._color[2];
  v4 = g_pVGuiSurface->__vftable;
  talla = this->m_DrawColor._color[1];
  v24 = this->m_DrawColor._color[0];
  Alpha = vgui::Panel::GetAlpha(this);
  v4->DrawSetColor_2(this: v2, a2: v24, a3: talla, a4: v3, a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v6 = 0;
  v7 = 0.0;
  drawW = 0.0;
  for ( i = 0; i < 3; ++i )
  {
    v9 = 0;
    v10 = 0.0;
    if ( i == 0 || i == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      m_iCornerHeight = (float)(wide - 2 * this->m_iCornerHeight < 0 ? 0 : wide - 2 * this->m_iCornerHeight);
    }
    uvy = m_flCornerHeightPercent;
    v15 = (float)v6;
    v16 = 0;
    tall = (float)v6 + m_iCornerHeight;
    uv12.x = tall;
    while ( 1 )
    {
      if ( v16 == 0 || v16 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v17 = this->m_flCornerWidthPercent * 2.0;
        v18 = (float)(1.0 - v17) <= 0.0 ? 0.0 : (float)(1.0 - v17);
        m_flCornerWidthPercent = v18;
        m_iCornerWidth = (float)(v28 - 2 * this->m_iCornerWidth < 0 ? 0 : v28 - 2 * this->m_iCornerWidth);
      }
      v30 = m_flCornerWidthPercent + v10;
      verts[0].m_TexCoord.x = v15;
      verts[3].m_Position.x = uvy + v7;
      verts[0].m_Position.x = uvy + v7;
      v32 = (float)v6;
      verts[1].m_Position.x = v7;
      verts[1].m_Position.y = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = v7;
      verts[3].m_TexCoord.x = uv12.x;
      verts[0].m_Position.y = (float)v9;
      verts[0].m_TexCoord.y = v10;
      verts[1].m_TexCoord.x = (float)v6;
      verts[1].m_TexCoord.y = m_flCornerWidthPercent + v10;
      verts[2].m_Position.y = verts[1].m_Position.y;
      verts[2].m_TexCoord.x = tall;
      verts[2].m_TexCoord.y = m_flCornerWidthPercent + v10;
      verts[3].m_Position.y = (float)v9;
      verts[3].m_TexCoord.y = v10;
      v35 = uvy + v7;
      DrawTexturedPolygon = g_pVGuiSurface->DrawTexturedPolygon;
      y = verts[1].m_Position.y;
      v31 = verts[1].m_Position.y;
      DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: (FontVertex_t *)&verts[0].m_Position.y, a4: true);
      v9 = (int)y;
      v10 = v30;
      if ( ++v16 >= 3 )
        break;
      v7 = drawW;
      v15 = (float)v6;
    }
    v7 = uvy + drawW;
    v6 = (int)tall;
    drawW = uvy + drawW;
  }
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0049A0A0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0049A130
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  bool v5; // cc
  int tall; // [esp+1Ch] [ebp-8h] BYREF
  int v7; // [esp+20h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &tall, a4: &v7);
  if ( tall <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)tall;
  v4 = v7;
  v5 = v7 <= 0;
  this->m_flCornerWidthPercent = v3;
  if ( v5 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x0049A1E0
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_9,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x0049A210
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A240
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049A250
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A280
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049A3F0
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *inResourceData,
        int a5)
{
  KeyValues *v5; // ebp
  const char *String; // eax
  char *v8; // edi
  unsigned int v9; // ebp
  char *v10; // eax
  int v11; // eax
  vgui::ISchemeManager *v12; // ebp
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v14; // eax
  int v15; // eax
  int (__thiscall *v16)(int, int *, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v18; // edx
  vgui::ISchemeManager *v19; // edi
  int v20; // eax
  int v21; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v23; // edx
  vgui::ISchemeManager *v24; // edi
  int v25; // eax
  const char *v26; // eax
  int v27; // [esp+0h] [ebp-24h]
  BOOL v28; // [esp+4h] [ebp-20h]
  char *v29; // [esp+8h] [ebp-1Ch]
  int r; // [esp+10h] [ebp-14h] BYREF
  int g; // [esp+14h] [ebp-10h] BYREF
  int b; // [esp+18h] [ebp-Ch] BYREF
  int a; // [esp+1Ch] [ebp-8h] BYREF
  int v34; // [esp+20h] [ebp-4h] BYREF

  v5 = inResourceData;
  vgui::Panel::ApplySettings(
    this,
    a2,
    a3: (int)inResourceData,
    a4: a3,
    (int)inResourceData,
    a6: v27,
    a7: v28,
    nptr: v29);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  v8 = (char *)String;
  if ( *String != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    v34 = 255;
    v9 = _V_strlen(str: String) + 1;
    v10 = (char *)MemAlloc_Alloc(nSize: v9);
    this->m_pszDrawColorName = v10;
    V_strncpy(pDest: v10, pSrc: v8, maxLen: v9);
    if ( sscanf(string: v8, format: "%d %d %d %d", &g, &b, &a, &v34) < 3 )
    {
      v12 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v14 = GetScheme(this);
      v15 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(r + 32))(a1: v12, a2: v14);
      v16 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v15 + 20);
      r = 0;
      v11 = *(_DWORD *)v16(a1: v15, a2: &r, a3: v8, a4: 0);
    }
    else
    {
      LOBYTE(r) = g;
      BYTE1(r) = b;
      BYTE2(r) = a;
      HIBYTE(r) = v34;
      v11 = r;
    }
    v5 = inResourceData;
    this->m_DrawColor = (Color)v11;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v5, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v5, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v5, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v5, keyName: "draw_corner_width", defaultValue: 0);
  v18 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v18->IsProportional(this) )
  {
    v19 = g_pVGuiSchemeManager;
    v20 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v21 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(a5 + 52))(a1: v19, a2: v20);
    m_iCornerWidth = this->m_iCornerWidth;
    v23 = this->__vftable;
    this->m_iCornerHeight = v21;
    v24 = g_pVGuiSchemeManager;
    v25 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v23->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(a5 + 52))(a1: v24, a2: v25);
  }
  v26 = KeyValues::GetString(this: v5, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v26);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0049A600
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0043F9B0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0043F9C0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FA40
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043FCD0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0043FD60
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x0043FE20
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_9,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x0043FE50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043FE80
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0043FE90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043FEC0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440020
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00440210
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00485AA0
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x00486260
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x004437E0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004437F0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443870
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00443B00
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00443B90
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x00443C50
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_9,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x00443C80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00443CB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00443CC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00443CF0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00443E50
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  const char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = (char *)KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00444040
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103B55A0
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x103B55B0
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  C_BaseEntity::operator delete(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    C_BaseEntity::operator delete(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B5630
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103B58C0
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x103B5950
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x103B5A10
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_13,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x103B5A40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B5A70
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x103B5A80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B5AB0
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B5C10
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  C_BaseEntity::operator delete(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: prType);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: prType);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B5E00
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103B1310
// Name: public: static char const __near * vgui::ScalableImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScalableImagePanel::GetPanelClassName()
{
  return "ScalableImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x103B1320
// Name: public: virtual void vgui::ScalableImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::SetImage(vgui::ScalableImagePanel *this, const char *imageName)
{
  unsigned int v3; // edi
  char *v4; // eax

  free(pMem: this->m_pszImageName);
  this->m_pszImageName = nullptr;
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B13A0
// Name: protected: virtual void vgui::ScalableImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PaintBackground(vgui::ScalableImagePanel *this)
{
  int v2; // edx
  float v3; // eax
  vgui::ISurface *v4; // edi
  vgui::ISurface_vtbl *v5; // ebx
  int Alpha; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm1_4
  double v12; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // edi
  float v19; // xmm6_4
  double v20; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+Ch] [ebp-74h] BYREF
  Vector2D uv12; // [esp+4Ch] [ebp-34h]
  Vector2D uv22; // [esp+54h] [ebp-2Ch]
  float v26; // [esp+5Ch] [ebp-24h]
  float x; // [esp+60h] [ebp-20h]
  int wide; // [esp+64h] [ebp-1Ch] BYREF
  float v29; // [esp+68h] [ebp-18h]
  int tall; // [esp+6Ch] [ebp-14h] BYREF
  int row; // [esp+70h] [ebp-10h]
  float v32; // [esp+74h] [ebp-Ch]
  float v33; // [esp+78h] [ebp-8h]
  float uvy; // [esp+7Ch] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->m_DrawColor._color[2];
  LODWORD(v3) = this->m_DrawColor._color[1];
  v4 = g_pVGuiSurface;
  v5 = g_pVGuiSurface->__vftable;
  LODWORD(v33) = this->m_DrawColor._color[0];
  row = v2;
  v32 = v3;
  Alpha = vgui::Panel::GetAlpha(this);
  ((void (__thiscall *)(vgui::ISurface *, float, float, int, int))v5->DrawSetColor_2)(
    a1: v4,
    a2: COERCE_FLOAT(LODWORD(v33)),
    a3: COERCE_FLOAT(LODWORD(v32)),
    a4: row,
    a5: Alpha);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
  v7 = 0;
  v8 = 0;
  uvy = 0.0;
  row = 0;
  do
  {
    v9 = 0;
    v10 = 0.0;
    if ( v8 == 0 || v8 == 2 )
    {
      m_flCornerHeightPercent = this->m_flCornerHeightPercent;
      m_iCornerHeight = (float)this->m_iCornerHeight;
    }
    else
    {
      v11 = this->m_flCornerHeightPercent * 2.0;
      if ( (float)(1.0 - v11) <= 0.0 )
        v12 = 0.0;
      else
        v12 = (float)(1.0 - v11);
      m_flCornerHeightPercent = v12;
      v8 = row;
      m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
    }
    v15 = m_flCornerHeightPercent + uvy;
    v16 = (float)v7;
    v17 = (float)v7 + m_iCornerHeight;
    v18 = 0;
    v32 = v15;
    uv12.y = v15;
    v29 = (float)v7;
    v33 = v17;
    while ( 1 )
    {
      if ( v18 == 0 || v18 == 2 )
      {
        m_flCornerWidthPercent = this->m_flCornerWidthPercent;
        m_iCornerWidth = (float)this->m_iCornerWidth;
      }
      else
      {
        v19 = this->m_flCornerWidthPercent * 2.0;
        v20 = (float)(1.0 - v19) <= 0.0 ? 0.0 : (float)(1.0 - v19);
        m_flCornerWidthPercent = v20;
        m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
      }
      v26 = m_flCornerWidthPercent + v10;
      uv22.y = v15;
      verts[0].m_TexCoord.y = uvy;
      verts[1].m_Position.x = (float)v9 + m_iCornerWidth;
      verts[2].m_Position.x = verts[1].m_Position.x;
      x = verts[1].m_Position.x;
      verts[0].m_Position.y = v16;
      verts[1].m_Position.y = v16;
      verts[2].m_TexCoord.y = v15;
      verts[0].m_Position.x = (float)v9;
      verts[0].m_TexCoord.x = v10;
      verts[1].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[1].m_TexCoord.y = uvy;
      verts[2].m_Position.y = v17;
      verts[2].m_TexCoord.x = m_flCornerWidthPercent + v10;
      verts[3].m_Position.x = (float)v9;
      verts[3].m_Position.y = v17;
      verts[3].m_TexCoord.x = v10;
      verts[3].m_TexCoord.y = uv12.y;
      g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
      v9 = (int)x;
      v10 = v26;
      if ( ++v18 >= 3 )
        break;
      v17 = v33;
      v16 = v29;
      v15 = v32;
    }
    v7 = (int)v33;
    ++v8;
    uvy = v32;
    row = v8;
  }
  while ( v8 < 3 );
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103B1630
// Name: protected: virtual void vgui::ScalableImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::GetSettings(vgui::ScalableImagePanel *this, KeyValues *outResourceData)
{
  char *m_pszImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_height", value: this->m_iSrcCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "src_corner_width", value: this->m_iSrcCornerWidth);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_height", value: this->m_iCornerHeight);
  KeyValues::SetInt(this: outResourceData, keyName: "draw_corner_width", value: this->m_iCornerWidth);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pszImageName);
}

//------------------------------------------------------------------------------
// Address: 0x103B16C0
// Name: protected: virtual void vgui::ScalableImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScalableImagePanel::PerformLayout(vgui::ScalableImagePanel *this)
{
  char *m_pszImageName; // eax
  float v3; // xmm0_4
  int v4; // eax
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_iTextureID,
      a3: m_pszImageName,
      a4: 1,
      a5: false);
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
  if ( wide <= 0 )
    v3 = 0.0;
  else
    v3 = (float)this->m_iSrcCornerWidth / (float)wide;
  v4 = tall;
  this->m_flCornerWidthPercent = v3;
  if ( v4 <= 0 )
    this->m_flCornerHeightPercent = 0.0;
  else
    this->m_flCornerHeightPercent = (float)this->m_iSrcCornerHeight / (float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x103B1780
// Name: protected: virtual char const __near * vgui::ScalableImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ScalableImagePanel::GetDescription(vgui::ScalableImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s string image, int src_corner_height, int src_corner_width, int draw_corner_height, int draw_corner_width",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x103B17B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScalableImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScalableImagePanel::GetMessageMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B17E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScalableImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScalableImagePanel::GetAnimMap(vgui::ScalableImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x103B17F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScalableImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScalableImagePanel::GetKBMap(vgui::ScalableImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ScalableImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
  `vgui::ScalableImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B1820
// Name: public: vgui::ScalableImagePanel::ScalableImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__thiscall vgui::ScalableImagePanel::ScalableImagePanel(
        vgui::ScalableImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ScalableImagePanel_vtbl *)&vgui::ScalableImagePanel::`vftable';
  if ( `vgui::ScalableImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ScalableImagePanel");
    v4->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ScalableImagePanel");
    v5->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScalableImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ScalableImagePanel");
    v6->pfnClassName = vgui::ScalableImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_DrawColor = (Color)-1;
  this->m_iTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B1980
// Name: protected: virtual void vgui::ScalableImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ScalableImagePanel::ApplySettings(
        vgui::ScalableImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v3; // ebx
  char *String; // edi
  unsigned int v6; // ebx
  char *v7; // eax
  Color v8; // eax
  vgui::ISchemeManager *v9; // ebx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  int Int; // eax
  vgui::ScalableImagePanel_vtbl *v15; // edx
  vgui::ISchemeManager *v16; // edi
  int v17; // eax
  int v18; // eax
  int m_iCornerWidth; // ecx
  vgui::ScalableImagePanel_vtbl *v20; // edx
  vgui::ISchemeManager *v21; // edi
  int v22; // eax
  char *v23; // eax
  int a; // [esp+Ch] [ebp-14h] BYREF
  int b; // [esp+10h] [ebp-10h] BYREF
  int g; // [esp+14h] [ebp-Ch] BYREF
  int r; // [esp+18h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v28; // [esp+1Ch] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+28h] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+28h] [ebp+8h]

  v3 = inResourceData;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszDrawColorName = nullptr;
  String = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: locale);
  if ( *String != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)operator new(nSize: v6);
    this->m_pszDrawColorName = v7;
    V_strncpy(pDest: v7, pSrc: String, maxLen: v6);
    if ( sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v9 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v28 = g_pVGuiSchemeManager->__vftable;
      v11 = GetScheme(this);
      v12 = (int)v28->GetIScheme(this: v9, a2: v11);
      v13 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v12 + 20);
      v28 = nullptr;
      v8 = *(Color *)v13(a1: v12, a2: &v28, a3: String, a4: 0);
    }
    else
    {
      LOBYTE(v28) = r;
      BYTE1(v28) = g;
      BYTE2(v28) = b;
      HIBYTE(v28) = a;
      v8 = (Color)v28;
    }
    v3 = inResourceData;
    this->m_DrawColor = v8;
  }
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  v15 = this->__vftable;
  this->m_iCornerWidth = Int;
  if ( v15->IsProportional(this) )
  {
    v16 = g_pVGuiSchemeManager;
    inResourceDataa = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v17 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))this->GetScheme)(a1: this, a2: this->m_iCornerHeight);
    v18 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDataa[1].m_iDataType)(a1: v16, a2: v17);
    m_iCornerWidth = this->m_iCornerWidth;
    v20 = this->__vftable;
    this->m_iCornerHeight = v18;
    v21 = g_pVGuiSchemeManager;
    inResourceDatab = (KeyValues *)g_pVGuiSchemeManager->__vftable;
    v22 = ((int (__thiscall *)(vgui::ScalableImagePanel *, int))v20->GetScheme)(a1: this, a2: m_iCornerWidth);
    this->m_iCornerWidth = (*(int (__thiscall **)(vgui::ISchemeManager *, int))&inResourceDatab[1].m_iDataType)(
                             a1: v21,
                             a2: v22);
  }
  v23 = KeyValues::GetString(this: v3, keyName: "image", defaultValue: locale);
  this->SetImage(this, a2: v23);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B1B70
// Name: Create_ScalableImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *__cdecl Create_ScalableImagePanel()
{
  vgui::ScalableImagePanel *v0; // eax

  v0 = (vgui::ScalableImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ScalableImagePanel::ScalableImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace server
