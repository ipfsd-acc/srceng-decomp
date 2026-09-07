// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/scalableimageborder.cpp
// Functions: 9
// ============================================================

#include "vgui2\src\scalableimageborder.h"

//------------------------------------------------------------------------------
// Address: 0x10001490
// Name: public: virtual void ScalableImageBorder::Paint(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScalableImageBorder::Paint(vgui::Border *this, int x, int y, int wide, int tall)
{
  this->Paint(this, a2: x, a3: y, a4: wide, a5: tall, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10006BE0
// Name: public: virtual bool ScalableImageBorder::PaintFirst(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScalableImageBorder::PaintFirst(ScalableImageBorder *this)
{
  return this->m_bPaintFirst;
}

//------------------------------------------------------------------------------
// Address: 0x10006BF0
// Name: protected: void ScalableImageBorder::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScalableImageBorder::SetImage(ScalableImageBorder *this, const char *imageName)
{
  const char *v3; // ebx
  int v4; // edi
  char *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  int v8; // eax
  int tall; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  v3 = imageName;
  if ( *imageName != 0 )
  {
    v4 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v5 = (char *)operator new(nSize: v4);
    this->m_pszImageName = v5;
    V_snprintf(pDest: v5, maxLen: v4, pFormat: "vgui/%s", v3);
    vgui::g_pSurface->DrawSetTextureFile(
      this: vgui::g_pSurface,
      a2: this->m_iTextureID,
      a3: this->m_pszImageName,
      a4: 1,
      a5: false);
    vgui::g_pSurface->DrawGetTextureSize(
      this: vgui::g_pSurface,
      a2: this->m_iTextureID,
      a3: (int *)&imageName,
      a4: &tall);
    v6 = 0.0;
    if ( (int)imageName <= 0 )
      v7 = 0.0;
    else
      v7 = (float)this->m_iSrcCornerWidth / (float)(int)imageName;
    v8 = tall;
    this->m_flCornerWidthPercent = v7;
    if ( v8 > 0 )
      v6 = (float)this->m_iSrcCornerHeight / (float)v8;
    this->m_flCornerHeightPercent = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006CD0
// Name: public: virtual void ScalableImageBorder::SetInset(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScalableImageBorder::SetInset(vgui::Border *this, int left, int top, int right, int bottom)
{
  this->_inset[0] = left;
  this->_inset[1] = top;
  this->_inset[2] = right;
  this->_inset[3] = bottom;
}

//------------------------------------------------------------------------------
// Address: 0x10006CF0
// Name: public: virtual void ScalableImageBorder::GetInset(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScalableImageBorder::GetInset(vgui::Border *this, int *left, int *top, int *right, int *bottom)
{
  *(_OWORD *)left = *(_OWORD *)this->_inset;
}

//------------------------------------------------------------------------------
// Address: 0x10006D20
// Name: public: virtual void ScalableImageBorder::Paint(int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ScalableImageBorder::Paint(
        ScalableImageBorder *this@<ecx>,
        int a2@<esi>,
        int x,
        int y,
        int wide,
        int tall,
        int breakSide,
        int breakStart,
        int breakEnd)
{
  char *m_pszImageName; // eax
  int v12; // ebx
  int v13; // ecx
  float v14; // xmm2_4
  float v15; // xmm1_4
  double v16; // xmm0_8
  float m_flCornerHeightPercent; // xmm1_4
  float m_iCornerHeight; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  int v22; // esi
  float v23; // xmm6_4
  double v24; // xmm0_8
  float m_flCornerWidthPercent; // xmm0_4
  float m_iCornerWidth; // xmm7_4
  FontVertex_t verts[4]; // [esp+4h] [ebp-68h] BYREF
  Vector2D uv12; // [esp+44h] [ebp-28h]
  Vector2D uv22; // [esp+4Ch] [ebp-20h]
  float v30; // [esp+54h] [ebp-18h]
  float v31; // [esp+58h] [ebp-14h]
  float v32; // [esp+5Ch] [ebp-10h]
  int row; // [esp+60h] [ebp-Ch]
  float v34; // [esp+64h] [ebp-8h]
  float uvy; // [esp+68h] [ebp-4h]
  int ya; // [esp+78h] [ebp+Ch]

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && *m_pszImageName != 0 )
  {
    ((void (__thiscall *)(vgui::ISurface *, _DWORD, int))vgui::g_pSurface->DrawSetColor)(
      a1: vgui::g_pSurface,
      a2: *(_DWORD *)&this->m_Color,
      a3: a2);
    vgui::g_pSurface->DrawSetTexture(this: vgui::g_pSurface, a2: this->m_iTextureID);
    v12 = 0;
    uvy = 0.0;
    row = 0;
    do
    {
      v13 = 0;
      v14 = 0.0;
      if ( v12 == 0 || v12 == 2 )
      {
        m_flCornerHeightPercent = this->m_flCornerHeightPercent;
        m_iCornerHeight = (float)this->m_iCornerHeight;
      }
      else
      {
        v15 = this->m_flCornerHeightPercent * 2.0;
        if ( (float)(1.0 - v15) <= 0.0 )
          v16 = 0.0;
        else
          v16 = (float)(1.0 - v15);
        m_flCornerHeightPercent = v16;
        v12 = row;
        m_iCornerHeight = (float)(tall - 2 * this->m_iCornerHeight < 0 ? 0 : tall - 2 * this->m_iCornerHeight);
      }
      v19 = m_flCornerHeightPercent + uvy;
      v20 = (float)y;
      v21 = (float)y + m_iCornerHeight;
      v22 = 0;
      v34 = v19;
      uv12.y = v19;
      v32 = (float)y;
      *(float *)&ya = v21;
      while ( 1 )
      {
        if ( v22 == 0 || v22 == 2 )
        {
          m_flCornerWidthPercent = this->m_flCornerWidthPercent;
          m_iCornerWidth = (float)this->m_iCornerWidth;
        }
        else
        {
          v23 = this->m_flCornerWidthPercent * 2.0;
          v24 = (float)(1.0 - v23) <= 0.0 ? 0.0 : (float)(1.0 - v23);
          m_flCornerWidthPercent = v24;
          m_iCornerWidth = (float)(wide - 2 * this->m_iCornerWidth < 0 ? 0 : wide - 2 * this->m_iCornerWidth);
        }
        v30 = m_flCornerWidthPercent + v14;
        uv22.y = v19;
        verts[0].m_TexCoord.y = uvy;
        verts[1].m_Position.x = (float)v13 + m_iCornerWidth;
        verts[2].m_Position.x = verts[1].m_Position.x;
        v31 = verts[1].m_Position.x;
        verts[0].m_Position.y = v20;
        verts[1].m_Position.y = v20;
        verts[2].m_TexCoord.y = v19;
        verts[0].m_Position.x = (float)v13;
        verts[0].m_TexCoord.x = v14;
        verts[1].m_TexCoord.x = m_flCornerWidthPercent + v14;
        verts[1].m_TexCoord.y = uvy;
        verts[2].m_Position.y = v21;
        verts[2].m_TexCoord.x = m_flCornerWidthPercent + v14;
        verts[3].m_Position.x = (float)v13;
        verts[3].m_Position.y = v21;
        verts[3].m_TexCoord.x = v14;
        verts[3].m_TexCoord.y = uv12.y;
        vgui::g_pSurface->DrawTexturedPolygon(this: vgui::g_pSurface, a2: 4, a3: verts, a4: true);
        v13 = (int)v31;
        v14 = v30;
        if ( ++v22 >= 3 )
          break;
        v21 = *(float *)&ya;
        v20 = v32;
        v19 = v34;
      }
      y = (int)*(float *)&ya;
      ++v12;
      uvy = v34;
      row = v12;
    }
    while ( v12 < 3 );
    vgui::g_pSurface->DrawSetTexture(this: vgui::g_pSurface, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006F70
// Name: public: virtual void ScalableImageBorder::Paint(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScalableImageBorder::Paint(ImageBorder *this, int panel)
{
  int wide; // [esp+4h] [ebp-4h] BYREF

  g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: panel, a3: &wide, a4: &panel);
  this->Paint(this, a2: 0, a3: 0, a4: wide, a5: panel, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10006FC0
// Name: public: ScalableImageBorder::ScalableImageBorder(void)
// Source: json
//------------------------------------------------------------------------------
ScalableImageBorder *__thiscall ScalableImageBorder::ScalableImageBorder(ScalableImageBorder *this)
{
  this->__vftable = (ScalableImageBorder_vtbl *)&ScalableImageBorder::`vftable';
  this->m_Color = 0;
  this->_inset[0] = 0;
  this->_inset[1] = 0;
  this->_inset[2] = 0;
  this->_inset[3] = 0;
  this->_name = nullptr;
  this->m_iSrcCornerHeight = 0;
  this->m_iSrcCornerWidth = 0;
  this->m_iCornerHeight = 0;
  this->m_iCornerWidth = 0;
  this->m_pszImageName = nullptr;
  this->m_eBackgroundType = BACKGROUND_TEXTURED;
  this->m_iTextureID = vgui::g_pSurface->CreateNewTextureID(this: vgui::g_pSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007010
// Name: public: virtual void ScalableImageBorder::ApplySchemeSettings(class vgui::IScheme __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScalableImageBorder::ApplySchemeSettings(
        ScalableImageBorder *this,
        vgui::IScheme *pScheme,
        KeyValues *inResourceData)
{
  KeyValues *v3; // edi
  int Int; // eax
  int m_iCornerHeight; // edx
  const char *String; // eax
  const char *v8; // eax
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx

  v3 = inResourceData;
  this->m_eBackgroundType = KeyValues::GetInt(this: inResourceData, keyName: "backgroundtype", defaultValue: 0);
  this->m_iSrcCornerHeight = KeyValues::GetInt(this: v3, keyName: "src_corner_height", defaultValue: 0);
  this->m_iSrcCornerWidth = KeyValues::GetInt(this: v3, keyName: "src_corner_width", defaultValue: 0);
  this->m_iCornerHeight = KeyValues::GetInt(this: v3, keyName: "draw_corner_height", defaultValue: 0);
  Int = KeyValues::GetInt(this: v3, keyName: "draw_corner_width", defaultValue: 0);
  m_iCornerHeight = this->m_iCornerHeight;
  this->m_iCornerWidth = Int;
  this->m_iCornerHeight = g_pVGuiSchemeManager->GetProportionalScaledValue(
                            this: g_pVGuiSchemeManager,
                            a2: m_iCornerHeight);
  this->m_iCornerWidth = g_pVGuiSchemeManager->GetProportionalScaledValue(
                           this: g_pVGuiSchemeManager,
                           a2: this->m_iCornerWidth);
  String = KeyValues::GetString(this: v3, keyName: "image", defaultValue: pHelpString);
  ScalableImageBorder::SetImage(this, imageName: String);
  this->m_bPaintFirst = KeyValues::GetInt(this: v3, keyName: "paintfirst", defaultValue: 1) != 0;
  v8 = KeyValues::GetString(this: v3, keyName: "color", defaultValue: nullptr);
  if ( v8 != nullptr && *v8 != 0 )
  {
    GetColor = pScheme->GetColor;
    inResourceData = (KeyValues *)-1;
    this->m_Color = *(Color *)((int (__thiscall *)(vgui::IScheme *, KeyValues **, const char *, int))GetColor)(
                                a1: pScheme,
                                a2: &inResourceData,
                                a3: v8,
                                a4: -1);
  }
  else
  {
    this->m_Color = (Color)-1;
  }
}
