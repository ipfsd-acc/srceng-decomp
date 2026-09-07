// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_bitmapimage.cpp
// Functions: 15
// ============================================================

#include "game\client\vgui_bitmapimage.h"

//------------------------------------------------------------------------------
// Address: 0x10180200
// Name: public: virtual BitmapImage::~BitmapImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::~BitmapImage(BitmapImage *this)
{
  this->__vftable = (BitmapImage_vtbl *)&BitmapImage::`vftable';
  if ( g_pVGuiSurface != nullptr && this->m_nTextureId != -1 )
  {
    ((void (__stdcall *)(int))g_pVGuiSurface->DestroyTextureID)(a1: this->m_nTextureId);
    this->m_nTextureId = -1;
  }
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x10180240
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x10180260
// Name: public: void BitmapImage::SetColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::SetColor(BitmapImage *this, const Color *clr)
{
  this->m_clr = *clr;
}

//------------------------------------------------------------------------------
// Address: 0x10180270
// Name: public: virtual class Color BitmapImage::GetColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall BitmapImage::GetColor(BitmapImage *this, Color *result)
{
  *result = this->m_clr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10180280
// Name: public: void BitmapImage::GetColor(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::GetColor(BitmapImage *this, int *r, int *g, int *b, int *a)
{
  *r = this->m_clr._color[0];
  *g = this->m_clr._color[1];
  *b = this->m_clr._color[2];
  *a = this->m_clr._color[3];
}

//------------------------------------------------------------------------------
// Address: 0x101802B0
// Name: public: virtual void BitmapImage::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::GetSize(BitmapImage *this, int *wide, int *tall)
{
  g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_nTextureId, a3: wide, a4: tall);
}

//------------------------------------------------------------------------------
// Address: 0x101802E0
// Name: public: virtual void BitmapImage::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::SetPos(BitmapImage *this, int x, int y)
{
  this->m_pos[0] = x;
  this->m_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x10180300
// Name: public: BitmapImage::BitmapImage(void)
// Source: json
//------------------------------------------------------------------------------
BitmapImage *__thiscall BitmapImage::BitmapImage(BitmapImage *this)
{
  vgui::Image::Image(this);
  this->__vftable = (BitmapImage_vtbl *)&BitmapImage::`vftable';
  this->m_clr = (Color)-1;
  this->m_pos[1] = 0;
  this->m_pos[0] = 0;
  this->m_pPanelSize = 0;
  this->m_bUseViewport = false;
  this->m_nTextureId = -1;
  this->m_rgViewport[0] = 0.0;
  this->m_rgViewport[1] = 0.0;
  this->m_rgViewport[2] = 0.0;
  this->m_rgViewport[3] = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101803A0
// Name: public: bool BitmapImage::Init(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall BitmapImage::Init(BitmapImage *this, unsigned int pParent, const char *pFileName)
{
  bool v4; // zf

  v4 = this->m_nTextureId == -1;
  this->m_pPanelSize = pParent;
  if ( v4 )
    this->m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: this->m_nTextureId, a3: pFileName, a4: 1, a5: true);
  this->GetSize(this, a2: this->m_Size, a3: &this->m_Size[1]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10180400
// Name: public: bool BitmapImage::Init(unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall BitmapImage::Init(BitmapImage *this, unsigned int pParent, Color pInitData)
{
  KeyValues *v3; // ebx
  char *String; // eax
  const char *v6; // esi

  v3 = (KeyValues *)pInitData;
  String = KeyValues::GetString(this: *(KeyValues **)&pInitData, keyName: "material", defaultValue: prType);
  v6 = String;
  if ( String == nullptr || *String == 0 )
    return 0;
  pInitData = 0;
  if ( ParseRGBA(pValues: v3, pFieldName: "color", c: &pInitData) == 0 )
    pInitData = (Color)-1;
  BitmapImage::Init(this, pParent, pFileName: v6);
  this->m_clr = pInitData;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10180470
// Name: public: void BitmapImage::DoPaint(int,int,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::DoPaint(
        BitmapImage *this,
        int x,
        int y,
        int wide,
        int tall,
        unsigned int yaw,
        float flAlphaModulate)
{
  __m128d v8; // xmm0
  __m128i v9; // xmm0
  double v10; // xmm0_8
  double v11; // xmm0_8
  float v12; // xmm1_4
  float v13; // xmm3_4
  FontVertex_t verts[4]; // [esp+2Ch] [ebp-58h] BYREF
  Vector2D axis[2]; // [esp+6Ch] [ebp-18h]
  Vector2D center; // [esp+7Ch] [ebp-8h]
  int yawRadians; // [esp+94h] [ebp+10h]
  float flAlphaModulatea; // [esp+A0h] [ebp+1Ch]

  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nTextureId);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int))g_pVGuiSurface->DrawSetColor_2)(
    a1: this->m_clr._color[0],
    a2: this->m_clr._color[1],
    a3: this->m_clr._color[2],
    a4: (int)(float)((float)this->m_clr._color[3] * flAlphaModulate));
  if ( *(float *)&yaw == 0.0 )
  {
    if ( this->m_bUseViewport )
      ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawTexturedSubRect)(
        a1: g_pVGuiSurface,
        a2: x,
        a3: y,
        a4: x + wide,
        a5: y + tall,
        a6: LODWORD(this->m_rgViewport[0]),
        a7: LODWORD(this->m_rgViewport[1]),
        a8: LODWORD(this->m_rgViewport[2]),
        a9: LODWORD(this->m_rgViewport[3]));
    else
      g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  }
  else
  {
    flAlphaModulatea = (float)wide;
    center.x = (float)((float)wide * 0.5) + (float)x;
    center.y = (float)((float)tall * 0.5) + (float)y;
    v8 = _mm_cvtps_pd(_mm_xor_ps((__m128)yaw, (__m128)_mask__NegFloat_));
    v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 0.005555555555555556;
    v9 = (__m128i)_mm_cvtpd_ps(v8);
    yawRadians = v9.m128i_i32[0];
    *(double *)v9.m128i_i64 = *(float *)v9.m128i_i32;
    __libm_sse2_cos(X: v9);
    *(float *)&v10 = v10;
    axis[0].x = *(float *)&v10;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)yawRadians));
    v12 = v11;
    verts[0].m_TexCoord.x = 0.0;
    verts[0].m_TexCoord.y = 0.0;
    axis[0].y = v12;
    v13 = (float)((float)((float)tall * -0.5) * COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_))
        + (float)((float)((float)(flAlphaModulatea * -0.5) * axis[0].x) + center.x);
    verts[1].m_TexCoord.y = 0.0;
    verts[0].m_Position.y = (float)((float)((float)(flAlphaModulatea * -0.5) * v12) + center.y)
                          + (float)((float)((float)tall * -0.5) * axis[0].x);
    *(float *)&v11 = (float)tall * COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_);
    verts[2].m_Position.x = *(float *)&v11 + (float)((float)(flAlphaModulatea * axis[0].x) + v13);
    verts[1].m_Position.y = (float)(flAlphaModulatea * v12) + verts[0].m_Position.y;
    verts[0].m_Position.x = v13;
    verts[1].m_TexCoord.x = 1.0;
    verts[1].m_Position.x = (float)(flAlphaModulatea * axis[0].x) + v13;
    verts[2].m_TexCoord.x = 1.0;
    verts[2].m_TexCoord.y = 1.0;
    verts[2].m_Position.y = (float)((float)tall * axis[0].x) + verts[1].m_Position.y;
    verts[3].m_TexCoord.x = 0.0;
    verts[3].m_TexCoord.y = 1.0;
    verts[3].m_Position.x = *(float *)&v11 + v13;
    verts[3].m_Position.y = (float)((float)tall * axis[0].x) + verts[0].m_Position.y;
    g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180700
// Name: public: void BitmapImage::DoPaint(unsigned int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::DoPaint(BitmapImage *this, int pPanel, unsigned int yaw, float flAlphaModulate)
{
  int v5; // edx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  if ( pPanel != 0 )
  {
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: pPanel, a3: &wide, a4: &pPanel);
  }
  else
  {
    v5 = this->m_Size[1];
    wide = this->m_Size[0];
    pPanel = v5;
  }
  BitmapImage::DoPaint(this, x: this->m_pos[0], y: this->m_pos[1], wide, tall: pPanel, yaw, flAlphaModulate);
}

//------------------------------------------------------------------------------
// Address: 0x10180770
// Name: public: virtual void BitmapImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BitmapImage::Paint(BitmapImage *this)
{
  unsigned int m_pPanelSize; // eax
  int v3; // edx
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  m_pPanelSize = this->m_pPanelSize;
  if ( m_pPanelSize != 0 )
  {
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: m_pPanelSize, a3: &wide, a4: &tall);
  }
  else
  {
    v3 = this->m_Size[1];
    wide = this->m_Size[0];
    tall = v3;
  }
  BitmapImage::DoPaint(this, x: this->m_pos[0], y: this->m_pos[1], wide, tall, yaw: 0, flAlphaModulate: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x101807E0
// Name: bool InitializeImage(class KeyValues __near *,char const __near *,class vgui::Panel __near *,class BitmapImage __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl InitializeImage(
        KeyValues *pInitData,
        const char *pSectionName,
        vgui::Panel *pParent,
        BitmapImage *pBitmapImage)
{
  KeyValues *Key; // eax
  unsigned int v6; // eax
  KeyValues *v7; // [esp-4h] [ebp-4h]

  if ( pSectionName != nullptr )
  {
    Key = KeyValues::FindKey(this: pInitData, keyName: pSectionName, bCreate: false);
    if ( Key == nullptr )
      return false;
  }
  else
  {
    Key = pInitData;
  }
  v7 = Key;
  v6 = pParent->GetVPanel(this: pParent);
  return BitmapImage::Init(this: pBitmapImage, pParent: v6, pInitData: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10180820
// Name: public: BitmapImage::BitmapImage(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BitmapImage *__thiscall BitmapImage::BitmapImage(BitmapImage *this, unsigned int parent, const char *filename)
{
  vgui::Image::Image(this);
  this->m_nTextureId = -1;
  this->__vftable = (BitmapImage_vtbl *)&BitmapImage::`vftable';
  this->m_clr = (Color)-1;
  this->m_pos[1] = 0;
  this->m_pos[0] = 0;
  this->m_pPanelSize = parent;
  if ( this->m_nTextureId == -1 )
    this->m_nTextureId = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: this->m_nTextureId, a3: filename, a4: 1, a5: true);
  this->GetSize(this, a2: this->m_Size, a3: &this->m_Size[1]);
  this->m_bUseViewport = false;
  this->m_rgViewport[0] = 0.0;
  this->m_rgViewport[1] = 0.0;
  this->m_rgViewport[2] = 0.0;
  this->m_rgViewport[3] = 0.0;
  return this;
}
