// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/bitmapimagepanel.cpp
// Functions: 11
// ============================================================

#include "vgui2\vgui_controls\bitmapimagepanel.h"

//------------------------------------------------------------------------------
// Address: 0x102C6CB0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6EF0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102C6F50
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6FF0
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString_0(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7070
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102C7090
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  const char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x102C7180
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySettings(vgui::CBitmapImagePanel *this, KeyValues *inResourceData)
{
  KeyValues *v3; // esi
  char *String; // eax
  char *v5; // eax
  const char *v6; // edi
  char *v7; // eax
  vgui::CBitmapImagePanel_vtbl *v8; // edx
  char *v9; // eax
  const char *v10; // esi
  vgui::Label::Alignment v11; // eax
  char *v12; // eax
  char *v13; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v3 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v5 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v6 = v5;
  if ( *v5 != 0 )
  {
    v7 = (char *)MemAlloc_Alloc(nSize: strlen(v5) + 1);
    strcpy(v7, v6);
    v8 = this->__vftable;
    this->m_pszColorName = v7;
    v8->InvalidateLayout(this, a2: false, a3: true);
    v3 = inResourceData;
  }
  v9 = KeyValues::GetString(this: v3, keyName: "imageAlignment", defaultValue: defaultValue);
  v10 = v9;
  if ( v9 != nullptr && *v9 != 0 )
  {
    v11 = _V_stricmp(s1: v9, s2: "north-west");
    if ( v11 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v11);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v10, s2: "north") == 0 )
    {
      v11 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v10, s2: "north-east") == 0 )
    {
      v11 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v10, s2: "west") == 0 )
    {
      v11 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v10, s2: "center") == 0 )
    {
      v11 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v10, s2: "east") == 0 )
    {
      v11 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v10, s2: "south-west") == 0 )
    {
      v11 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v10, s2: "south") == 0 )
    {
      v11 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v10, s2: "south-east") == 0 )
    {
      v11 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v12 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v12 != nullptr && *v12 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v12) != 0;
  v13 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v13 != nullptr && *v13 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v13) != 0;
  vgui::Panel::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102C73D0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x102C7410
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_11,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x102C7440
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString_0(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C7530
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1004E6A0
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E6D0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E910
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004E970
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EA10
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EA90
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x1004EAB0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x1004EBA0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1004EDF0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x1004EE30
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_7,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x1004EE60
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004EF50
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00426F90
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426FC0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427200
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00427260
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427300
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427380
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x004273A0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x00427490
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004276E0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x00427720
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_5,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x00427750
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00427840
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100593D0
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059400
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059640
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100596A0
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059740
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100597C0
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x100597E0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x100598D0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10059B20
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x10059B60
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x10059B90
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10059C80
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00603B20
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)MemAlloc_Alloc(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00603B50
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00603D90
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00603DF0
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00603E90
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00603F10
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00603F30
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x00604020
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)MemAlloc_Alloc(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00604270
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x006042B0
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_5,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x006042E0
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006043D0
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C6D80
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6FC0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102C7020
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C70C0
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString_0(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7140
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102C7160
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  const char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x102C7250
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)MemAlloc_Alloc(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102C74A0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x102C74E0
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_11,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x102C7510
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        __m128i *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString_0(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C7600
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EA920
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EA950
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EAB90
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102EABF0
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EAC90
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    operator delete(p: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EAD10
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102EAD30
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x102EAE20
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    operator delete(p: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    operator delete(p: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: &var);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: &var);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: &var);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: &var);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: &var);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102EB070
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x102EB0B0
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_9,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x102EB0E0
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EB1D0
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100BB040
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BB070
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB2B0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100BB310
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB3B0
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB430
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x100BB450
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x100BB540
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: szDescription);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: szDescription);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: szDescription);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: szDescription);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: szDescription);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x100BB790
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x100BB7D0
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x100BB800
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BB8F0
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00447540
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447570
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004477B0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00447810
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004478B0
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447930
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00447950
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x00447A40
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00447C90
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x00447CD0
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x00447D00
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00447DF0
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042EA50
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EA90
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int panelTall; // [esp+8h] [ebp-10h] BYREF
  int imageWide; // [esp+Ch] [ebp-Ch] BYREF
  int imageTall; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelTall, tall: &imageWide);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageTall, a3: &v14);
      v6 = panelTall;
      v7 = imageWide;
      if ( panelTall <= 0 || imageWide <= 0 || imageTall <= 0 || v14 <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)v14;
        v9 = (float)panelTall / (float)imageTall;
        if ( (float)((float)imageWide / (float)v14) <= v9 )
          v9 = (float)imageWide / (float)v14;
        *w = (int)(float)((float)imageTall * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ECF0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int h; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int w; // [esp+18h] [ebp-8h] BYREF
  int v6; // [esp+1Ch] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &w, a3: &h, a4: &v6, a5: &x);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: w, a3: h, a4: w + v6, a5: h + x, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0042ED60
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int x; // [esp+10h] [ebp-10h] BYREF
  int h; // [esp+14h] [ebp-Ch] BYREF
  int w; // [esp+18h] [ebp-8h] BYREF
  int v5; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &h, a3: &x, a4: &v5, a5: &w);
    this->m_pImage->SetPos(this: this->m_pImage, a2: h, a3: x);
    this->m_pImage->SetSize(this: this->m_pImage, a2: v5, a3: w);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EE00
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EE80
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x0042EEA0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x0042EF90
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySettings(vgui::CBitmapImagePanel *this, KeyValues *inResourceData)
{
  const char *String; // eax
  const char *v4; // eax
  char *v5; // eax
  vgui::CBitmapImagePanel_vtbl *v6; // edx
  const char *v7; // eax
  const char *v8; // edi
  vgui::Label::Alignment v9; // eax
  const char *v10; // eax
  const char *v11; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  if ( *v4 != 0 )
  {
    v5 = CloneString(str: v4);
    v6 = this->__vftable;
    this->m_pszColorName = v5;
    v6->InvalidateLayout(this, a2: false, a3: true);
  }
  v7 = KeyValues::GetString(this: inResourceData, keyName: "imageAlignment", defaultValue: defaultValue);
  v8 = v7;
  if ( v7 != nullptr && *v7 != 0 )
  {
    v9 = _V_stricmp(s1: v7, s2: "north-west");
    if ( v9 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v9);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v8, s2: "north") == 0 )
    {
      v9 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v8, s2: "north-east") == 0 )
    {
      v9 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v8, s2: "west") == 0 )
    {
      v9 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v8, s2: "center") == 0 )
    {
      v9 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v8, s2: "east") == 0 )
    {
      v9 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v8, s2: "south-west") == 0 )
    {
      v9 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v8, s2: "south") == 0 )
    {
      v9 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v8, s2: "south-east") == 0 )
    {
      v9 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v10 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v10 != nullptr && *v10 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v10) != 0;
  v11 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v11 != nullptr && *v11 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v11) != 0;
  vgui::Panel::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0042F1B0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x0042F1F0
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x0042F220
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  this->m_hardwareFiltered = false;
  this->m_preserveAspectRatio = false;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042F320
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063B1A0
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)MemAlloc_Alloc(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063B1D0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063B410
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0063B470
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063B510
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063B590
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x0063B5B0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  const char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x0063B6A0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)MemAlloc_Alloc(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0063B8F0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x0063B930
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x0063B960
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063BA50
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10061D20
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061F60
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061FC0
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062060
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100620E0
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10062100
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  const char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x100621F0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10062440
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x10062480
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x100624B0
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100625A0
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10065850
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065880
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065AC0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065B20
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065BC0
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065C40
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10065C60
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x10065D50
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10065FA0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x10065FF0
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_5,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x10066020
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066110
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00437290
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004372C0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437500
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00437560
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437600
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437680
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x004376A0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x00437790
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: &defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: &defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: &defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: &defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: &defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004379E0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x00437A20
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x00437A50
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00437B40
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00480990
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)MemAlloc_Alloc(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004809D0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int panelTall; // [esp+8h] [ebp-10h] BYREF
  int imageWide; // [esp+Ch] [ebp-Ch] BYREF
  int imageTall; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelTall, tall: &imageWide);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageTall, a3: &v14);
      v6 = panelTall;
      v7 = imageWide;
      if ( panelTall <= 0 || imageWide <= 0 || imageTall <= 0 || v14 <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)v14;
        v9 = (float)panelTall / (float)imageTall;
        if ( (float)((float)imageWide / (float)v14) <= v9 )
          v9 = (float)imageWide / (float)v14;
        *w = (int)(float)((float)imageTall * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480C30
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int h; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int w; // [esp+18h] [ebp-8h] BYREF
  int v6; // [esp+1Ch] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &w, a3: &h, a4: &v6, a5: &x);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: w, a3: h, a4: w + v6, a5: h + x, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00480CA0
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int x; // [esp+10h] [ebp-10h] BYREF
  int h; // [esp+14h] [ebp-Ch] BYREF
  int w; // [esp+18h] [ebp-8h] BYREF
  int v5; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &h, a3: &x, a4: &v5, a5: &w);
    this->m_pImage->SetPos(this: this->m_pImage, a2: h, a3: x);
    this->m_pImage->SetSize(this: this->m_pImage, a2: v5, a3: w);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480D40
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480DC0
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00480DE0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x00480ED0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004810F0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x00481130
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_5,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x00481160
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  this->m_hardwareFiltered = false;
  this->m_preserveAspectRatio = false;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00481260
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00533F20
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
// Address: 0x005353A0
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00425BB0
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425BE0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425E20
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00425E80
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425F20
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425FA0
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00425FC0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  const char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x004260B0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00426300
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x00426340
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_5,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x00426370
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00426460
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00429610
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429850
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004298B0
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429950
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004299D0
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x004299F0
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  const char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x00429AE0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  const char *String; // eax
  const char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  const char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  const char *v14; // eax
  const char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: defaultValue);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: defaultValue);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: defaultValue);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: defaultValue);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00429D30
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x00429D70
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_5,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x00429DA0
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429E90
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039FD80
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)MemAlloc_Alloc(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039FDB0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039FFF0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A0050
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A00F0
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    C_BaseEntity::operator delete(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A0170
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x103A0190
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x103A0280
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    C_BaseEntity::operator delete(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    C_BaseEntity::operator delete(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: prType);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: prType);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)MemAlloc_Alloc(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: prType);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: prType);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: prType);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x103A04D0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x103A0510
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_10,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x103A0540
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A0630
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103977B0
// Name: private: virtual void vgui::CBitmapImagePanel::ComputeImagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ComputeImagePosition(
        vgui::CBitmapImagePanel *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int v6; // eax
  int v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // eax
  int imageTall; // [esp+4h] [ebp-10h] BYREF
  int imageWide; // [esp+8h] [ebp-Ch] BYREF
  int panelTall; // [esp+Ch] [ebp-8h] BYREF
  int panelWide; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    if ( this->m_preserveAspectRatio )
    {
      vgui::Panel::GetSize(this, wide: &panelWide, tall: &panelTall);
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      v6 = panelWide;
      v7 = panelTall;
      if ( panelWide <= 0 || panelTall <= 0 || imageWide <= 0 || imageTall <= 0 )
      {
        *y = 0;
        *x = 0;
        *w = v6;
        *h = v7;
      }
      else
      {
        v8 = (float)imageTall;
        v9 = (float)panelWide / (float)imageWide;
        if ( (float)((float)panelTall / (float)imageTall) <= v9 )
          v9 = (float)panelTall / (float)imageTall;
        *w = (int)(float)((float)imageWide * v9);
        *h = (int)(float)(v8 * v9);
        switch ( this->m_contentAlignment )
        {
          case a_northwest:
            *y = 0;
            *x = 0;
            break;
          case a_north:
            *x = (v6 - *w) / 2;
            *y = 0;
            break;
          case a_northeast:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_west:
            *x = 0;
            *y = (v7 - *h) / 2;
            break;
          case a_center:
            v10 = (v6 - *w) / 2;
            goto LABEL_19;
          case a_east:
          case a_south:
            v10 = v6 - *w;
LABEL_19:
            *x = v10;
            *y = (v7 - *h) / 2;
            break;
          case a_southwest:
            *x = v6 - *w;
            *y = 0;
            break;
          case a_southeast:
            *x = v6 - *w;
            *y = v7 - *h;
            break;
          default:
            *y = 0;
            *x = 0;
            break;
        }
      }
    }
    else
    {
      *y = 0;
      *x = 0;
      vgui::Panel::GetSize(this, wide: w, tall: h);
    }
  }
  else
  {
    *h = 0;
    *w = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103979F0
// Name: protected: virtual void vgui::CBitmapImagePanel::PaintBorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBorder(vgui::CBitmapImagePanel *this)
{
  vgui::IBorder *v2; // eax
  int w; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
  v2 = this->GetBorder(this);
  if ( v2 != nullptr )
    v2->Paint(this: v2, a2: x, a3: y, a4: x + w, a5: y + h, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10397A50
// Name: public: virtual void vgui::CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::PaintBackground(vgui::CBitmapImagePanel *this)
{
  int w; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pImage != nullptr )
  {
    this->ComputeImagePosition(this, a2: &x, a3: &y, a4: &w, a5: &h);
    this->m_pImage->SetPos(this: this->m_pImage, a2: x, a3: y);
    this->m_pImage->SetSize(this: this->m_pImage, a2: w, a3: h);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pImage->SetColor)(
      a1: this->m_pImage,
      a2: *(_DWORD *)&this->m_bgColor);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_bgColor);
    this->m_pImage->Paint(this: this->m_pImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10397AF0
// Name: public: virtual void vgui::CBitmapImagePanel::setTexture(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::setTexture(
        vgui::CBitmapImagePanel *this,
        const char *filename,
        bool hardwareFiltered)
{
  this->m_hardwareFiltered = hardwareFiltered;
  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = (vgui::IImage *)((int (__stdcall *)(const char *, bool))g_pVGuiSchemeManager->GetImage)(
                                       a1: filename,
                                       a2: this->m_hardwareFiltered);
    this->m_pszImageName = CloneString(str: filename);
  }
  else
  {
    this->m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10397B70
// Name: public: virtual void vgui::CBitmapImagePanel::SetContentAlignment(enum vgui::Label::Alignment)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::SetContentAlignment(
        vgui::CBitmapImagePanel *this,
        vgui::Label::Alignment alignment)
{
  vgui::CBitmapImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_contentAlignment = alignment;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10397B90
// Name: protected: virtual void vgui::CBitmapImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::GetSettings(vgui::CBitmapImagePanel *this, KeyValues *outResourceData)
{
  char *v3; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "imagecolor", value: this->m_pszColorName);
  switch ( this->m_contentAlignment )
  {
    case a_northwest:
      v3 = "north-west";
      break;
    case a_north:
      v3 = "north";
      break;
    case a_northeast:
      v3 = "north-east";
      break;
    case a_east:
      v3 = "east";
      break;
    case a_southwest:
      v3 = "south-west";
      break;
    case a_south:
      v3 = "south";
      break;
    case a_southeast:
      v3 = "south-east";
      break;
    default:
      v3 = "center";
      break;
  }
  KeyValues::SetString(this: outResourceData, keyName: "imageAlignment", value: v3);
  KeyValues::SetInt(this: outResourceData, keyName: "preserveAspectRatio", value: this->m_preserveAspectRatio);
  KeyValues::SetInt(this: outResourceData, keyName: "filtered", value: this->m_hardwareFiltered);
}

//------------------------------------------------------------------------------
// Address: 0x10397C80
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CBitmapImagePanel::ApplySettings(
        vgui::CBitmapImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  char *String; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  vgui::CBitmapImagePanel_vtbl *v9; // edx
  char *v10; // eax
  const char *v11; // esi
  int v12; // edi
  vgui::Label::Alignment v13; // eax
  char *v14; // eax
  char *v15; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( this->m_pszColorName != nullptr )
  {
    free(pMem: this->m_pszColorName);
    this->m_pszColorName = nullptr;
  }
  v4 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: locale);
  if ( *String != 0 )
    this->setTexture(this, a2: String, a3: true);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "imagecolor", defaultValue: locale);
  v7 = v6;
  if ( *v6 != 0 )
  {
    v8 = (char *)operator new(nSize: strlen(v6) + 1);
    strcpy(v8, v7);
    v9 = this->__vftable;
    this->m_pszColorName = v8;
    v9->InvalidateLayout(this, a2: false, a3: true);
    v4 = inResourceData;
  }
  v10 = KeyValues::GetString(this: v4, keyName: "imageAlignment", defaultValue: locale);
  v11 = v10;
  v12 = a2;
  if ( v10 != nullptr && *v10 != 0 )
  {
    v13 = _V_stricmp(s1: v10, s2: "north-west");
    if ( v13 == a_northwest )
    {
LABEL_28:
      this->SetContentAlignment(this, a2: v13);
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: v11, s2: "north") == 0 )
    {
      v13 = a_north;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "north-east") == 0 )
    {
      v13 = a_northeast;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "west") == 0 )
    {
      v13 = a_west;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "center") == 0 )
    {
      v13 = a_center;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "east") == 0 )
    {
      v13 = a_east;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-west") == 0 )
    {
      v13 = a_southwest;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south") == 0 )
    {
      v13 = a_south;
      goto LABEL_28;
    }
    if ( _V_stricmp(s1: v11, s2: "south-east") == 0 )
    {
      v13 = a_southeast;
      goto LABEL_28;
    }
  }
LABEL_29:
  v14 = KeyValues::GetString(this: inResourceData, keyName: "preserveAspectRatio", defaultValue: locale);
  if ( v14 != nullptr && *v14 != 0 )
    this->m_preserveAspectRatio = atoi(nptr: v14) != 0;
  v15 = KeyValues::GetString(this: inResourceData, keyName: "filtered", defaultValue: locale);
  if ( v15 != nullptr && *v15 != 0 )
    this->m_hardwareFiltered = atoi(nptr: v15) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)this, a3: v12, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10397ED0
// Name: protected: virtual void vgui::CBitmapImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CBitmapImagePanel::ApplySchemeSettings(vgui::CBitmapImagePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_pszColorName; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszColorName = this->m_pszColorName;
  if ( m_pszColorName != nullptr )
    this->m_bgColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, char *, _DWORD))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: m_pszColorName,
                                  a4: *(_DWORD *)&this->m_bgColor);
}

//------------------------------------------------------------------------------
// Address: 0x10397F10
// Name: protected: virtual char const __near * vgui::CBitmapImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CBitmapImagePanel::GetDescription(vgui::CBitmapImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string imagecolor, alignment imageAlignment, int preserveAspectRatio, int filtered",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x10397F40
// Name: public: vgui::CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__thiscall vgui::CBitmapImagePanel::CBitmapImagePanel(
        vgui::CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::CBitmapImagePanel_vtbl *)&vgui::CBitmapImagePanel::`vftable';
  this->m_bgColor = 0;
  this->m_pImage = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->m_pszImageName = nullptr;
  this->m_pszColorName = nullptr;
  *(_WORD *)&this->m_preserveAspectRatio = 0;
  this->m_contentAlignment = a_center;
  if ( filename != nullptr && *filename != 0 )
  {
    this->m_pImage = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: filename, a3: 0);
    this->m_pszImageName = CloneString(str: filename);
  }
  this->m_bgColor = (Color)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10398030
// Name: Create_CBitmapImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *__cdecl Create_CBitmapImagePanel()
{
  vgui::CBitmapImagePanel *v0; // eax

  v0 = (vgui::CBitmapImagePanel *)operator new(nSize: 0x164u);
  if ( v0 != nullptr )
    return vgui::CBitmapImagePanel::CBitmapImagePanel(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             filename: "BitmapImagePanel");
  else
    return nullptr;
}

} // namespace server
