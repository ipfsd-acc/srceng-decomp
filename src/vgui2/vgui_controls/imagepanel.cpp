// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/imagepanel.cpp
// Functions: 16
// ============================================================

#include "vgui2\vgui_controls\imagepanel.h"

//------------------------------------------------------------------------------
// Address: 0x102BEF10
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102BEF20
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BEF60
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x102BEF70
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102BEF90
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, const char *imageName)
{
  int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF000
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x102BF010
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BF030
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF280
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  const char *v4; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    v4 = v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value: v4);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x102BF390
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF3F0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_8,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x102BF420
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BF460
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BF4E0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  bool v3; // al
  int Int; // eax
  bool v5; // zf
  char *String; // eax
  char *v7; // eax
  const char *v8; // edi
  char *v9; // eax
  vgui::ImagePanel_vtbl *v10; // edx
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, int *, const char *, _DWORD); // edx
  char *v14; // eax
  unsigned int v15; // edi
  char *v16; // eax
  const char *v17; // edi
  int v18; // eax
  vgui::ISchemeManager *v19; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v21; // eax
  int v22; // eax
  int (__thiscall *v23)(int, int *, int, _DWORD); // edx
  char *v24; // edi
  vgui::ISchemeManager *v25; // ebx
  unsigned int (__thiscall *v26)(vgui::IClientPanel *); // eax
  int v27; // eax
  int v28; // eax
  vgui::ImagePanel_vtbl *v29; // ebx
  int v30; // eax
  const char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int maxLen; // [esp+10h] [ebp-18h] BYREF
  int len; // [esp+14h] [ebp-14h] BYREF
  int a; // [esp+18h] [ebp-10h] BYREF
  int b; // [esp+1Ch] [ebp-Ch] BYREF
  int g; // [esp+20h] [ebp-8h] BYREF
  int r; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v3 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v3;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v3);
  v5 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v5) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v7 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v8 = v7;
  if ( *v7 != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    len = 255;
    maxLen = _V_strlen(str: v7) + 1;
    v9 = (char *)MemAlloc_Alloc(nSize: maxLen);
    v32 = maxLen;
    this->m_pszFillColorName = v9;
    V_strncpy(pDest: v9, pSrc: v8, maxLen: v32);
    if ( sscanf(string: v8, format: "%d %d %d %d", &g, &b, &a, &len) < 3 )
    {
      v10 = this->__vftable;
      maxLen = (int)g_pVGuiSchemeManager;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v11 = v10->GetScheme(this);
      v12 = (*(int (__thiscall **)(int, int))(r + 32))(a1: maxLen, a2: v11);
      v13 = *(int (__thiscall **)(int, int *, const char *, _DWORD))(*(_DWORD *)v12 + 20);
      r = 0;
      this->m_FillColor = *(Color *)v13(a1: v12, a2: &maxLen, a3: v8, a4: 0);
    }
    else
    {
      LOBYTE(r) = g;
      BYTE1(r) = b;
      BYTE2(r) = a;
      HIBYTE(r) = len;
      this->m_FillColor = (Color)r;
    }
  }
  v14 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  maxLen = (int)v14;
  if ( *v14 != 0 )
  {
    len = 0;
    a = 0;
    b = 0;
    g = 255;
    v15 = _V_strlen(str: v14) + 1;
    v16 = (char *)MemAlloc_Alloc(nSize: v15);
    v33 = v15;
    v17 = (const char *)maxLen;
    v31 = (const char *)maxLen;
    this->m_pszDrawColorName = v16;
    V_strncpy(pDest: v16, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v17, format: "%d %d %d %d", &len, &a, &b, &g) < 3 )
    {
      v19 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v21 = GetScheme(this);
      v22 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(r + 32))(a1: v19, a2: v21);
      v23 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v22 + 20);
      r = 0;
      v18 = *(_DWORD *)v23(a1: v22, a2: &maxLen, a3: maxLen, a4: 0);
    }
    else
    {
      LOBYTE(r) = len;
      BYTE1(r) = a;
      BYTE2(r) = b;
      HIBYTE(r) = g;
      v18 = r;
    }
    this->m_DrawColor = (Color)v18;
  }
  v24 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v24 != 0 )
  {
    v25 = g_pVGuiSchemeManager;
    v26 = this->GetScheme;
    maxLen = (int)g_pVGuiSchemeManager->__vftable;
    v27 = v26(this);
    v28 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(maxLen + 32))(a1: v25, a2: v27);
    v29 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v28 + 8))(a1: v28, a2: v24);
    v29->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102BF810
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BF990
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1004D910
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1004D920
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004D960
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x1004D970
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x1004D990
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DA00
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004DA20
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x1004DA30
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DC80
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x1004DD90
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DDF0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x1004DE20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004DE60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004DEE0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  unsigned int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1004E210
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(vgui::ImagePanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004E390
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10061590
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00412000
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00412010
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00412050
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x00412060
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00412080
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004120F0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412110
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x00412120
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412370
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x00412480
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004124E0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_2,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x00412510
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412550
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004125D0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  const char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (const char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00412900
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412A80
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044EC80
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10055CE0
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10055CF0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055D30
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x10055D40
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10055D60
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055DD0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055DF0
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x10055E00
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056050
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x10056160
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100561C0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_3,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x100561F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100562B0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  const char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (const char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x100565E0
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056760
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007E660
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006003F0
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00600400
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00600440
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x00600450
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00600470
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006004E0
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x006004F0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00600510
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x00600520
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00600770
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x00600880
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006008E0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_2,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x00600910
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00600950
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006009D0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  const char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)MemAlloc_Alloc(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)MemAlloc_Alloc(nSize: v16);
    v33 = v16;
    v18 = (const char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00600D00
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(vgui::ImagePanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00600E80
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102BEFF0
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102BF040
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x102BF050
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102BF070
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, const char *imageName)
{
  int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF0E0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BF110
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF360
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  const char *v4; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    v4 = v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value: v4);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x102BF470
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF4D0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_8,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x102BF500
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BF540
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BF5C0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  int v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  const char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int maxLen; // [esp+10h] [ebp-18h] BYREF
  int len; // [esp+14h] [ebp-14h] BYREF
  int a; // [esp+18h] [ebp-10h] BYREF
  int b; // [esp+1Ch] [ebp-Ch] BYREF
  int g; // [esp+20h] [ebp-8h] BYREF
  int r; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    len = 255;
    maxLen = _V_strlen(str: v8) + 1;
    v10 = (char *)MemAlloc_Alloc(nSize: maxLen);
    v32 = maxLen;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &g, &b, &a, &len) < 3 )
    {
      v11 = this->__vftable;
      maxLen = (int)g_pVGuiSchemeManager;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (*(int (__thiscall **)(int, int))(r + 32))(a1: maxLen, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      r = 0;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &maxLen, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(r) = g;
      BYTE1(r) = b;
      BYTE2(r) = a;
      HIBYTE(r) = len;
      this->m_FillColor = (Color)r;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  maxLen = (int)v15;
  if ( *v15 != 0 )
  {
    len = 0;
    a = 0;
    b = 0;
    g = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)MemAlloc_Alloc(nSize: v16);
    v33 = v16;
    v18 = (char *)maxLen;
    v31 = (const char *)maxLen;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &len, &a, &b, &g) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(r + 32))(a1: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      r = 0;
      v19 = *(_DWORD *)v24(a1: v23, a2: &maxLen, a3: maxLen, a4: 0);
    }
    else
    {
      LOBYTE(r) = len;
      BYTE1(r) = a;
      BYTE2(r) = b;
      HIBYTE(r) = g;
      v19 = r;
    }
    this->m_DrawColor = (Color)v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    maxLen = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(maxLen + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102BF8F0
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(vgui::ImagePanel *this, vgui::Panel *parent, __m128i *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BFA70
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D1120
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1007DCC0
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x102E7270
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102E7280
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  operator delete(p: m_pszImageName);
  operator delete(p: this->m_pszFillColorName);
  operator delete(p: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E72C0
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102E72E0
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, const char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = std::char_traits<char>::length(str: imageName) + 1;
    operator delete(p: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E7380
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E75D0
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  const char *v4; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    v4 = v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value: v4);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x102E76E0
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E7740
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_6,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x102E7770
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E77B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E7830
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  bool v3; // al
  int Int; // eax
  bool v5; // zf
  const char *String; // eax
  const char *v7; // eax
  const char *v8; // edi
  char *v9; // eax
  vgui::ImagePanel_vtbl *v10; // edx
  int v11; // eax
  int v12; // eax
  int (__thiscall *v13)(int, int *, const char *, _DWORD); // edx
  const char *v14; // eax
  unsigned int v15; // edi
  char *v16; // eax
  const char *v17; // edi
  int v18; // eax
  vgui::ISchemeManager *v19; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v21; // eax
  int v22; // eax
  int (__thiscall *v23)(int, int *, int, _DWORD); // edx
  const char *v24; // edi
  vgui::ISchemeManager *v25; // ebx
  unsigned int (__thiscall *v26)(vgui::IClientPanel *); // eax
  int v27; // eax
  int v28; // eax
  vgui::ImagePanel_vtbl *v29; // ebx
  int v30; // eax
  const char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int maxLen; // [esp+10h] [ebp-18h] BYREF
  int len; // [esp+14h] [ebp-14h] BYREF
  int a; // [esp+18h] [ebp-10h] BYREF
  int b; // [esp+1Ch] [ebp-Ch] BYREF
  int g; // [esp+20h] [ebp-8h] BYREF
  int r; // [esp+24h] [ebp-4h]

  operator delete(p: this->m_pszImageName);
  operator delete(p: this->m_pszFillColorName);
  operator delete(p: this->m_pszDrawColorName);
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v3 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v3;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v3);
  v5 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v5) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: &var);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v7 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: &var);
  v8 = v7;
  if ( *v7 != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    len = 255;
    maxLen = std::char_traits<char>::length(str: v7) + 1;
    v9 = (char *)operator new(nSize: maxLen);
    v32 = maxLen;
    this->m_pszFillColorName = v9;
    V_strncpy(pDest: v9, pSrc: v8, maxLen: v32);
    if ( sscanf(string: v8, format: "%d %d %d %d", &g, &b, &a, &len) < 3 )
    {
      v10 = this->__vftable;
      maxLen = (int)g_pVGuiSchemeManager;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v11 = v10->GetScheme(this);
      v12 = (*(int (__thiscall **)(int, int))(r + 32))(a1: maxLen, a2: v11);
      v13 = *(int (__thiscall **)(int, int *, const char *, _DWORD))(*(_DWORD *)v12 + 20);
      r = 0;
      this->m_FillColor = *(Color *)v13(a1: v12, a2: &maxLen, a3: v8, a4: 0);
    }
    else
    {
      LOBYTE(r) = g;
      BYTE1(r) = b;
      BYTE2(r) = a;
      HIBYTE(r) = len;
      this->m_FillColor = (Color)r;
    }
  }
  v14 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: &var);
  maxLen = (int)v14;
  if ( *v14 != 0 )
  {
    len = 0;
    a = 0;
    b = 0;
    g = 255;
    v15 = std::char_traits<char>::length(str: v14) + 1;
    v16 = (char *)operator new(nSize: v15);
    v33 = v15;
    v17 = (const char *)maxLen;
    v31 = (const char *)maxLen;
    this->m_pszDrawColorName = v16;
    V_strncpy(pDest: v16, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v17, format: "%d %d %d %d", &len, &a, &b, &g) < 3 )
    {
      v19 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v21 = GetScheme(this);
      v22 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(r + 32))(a1: v19, a2: v21);
      v23 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v22 + 20);
      r = 0;
      v18 = *(_DWORD *)v23(a1: v22, a2: &maxLen, a3: maxLen, a4: 0);
    }
    else
    {
      LOBYTE(r) = len;
      BYTE1(r) = a;
      BYTE2(r) = b;
      HIBYTE(r) = g;
      v18 = r;
    }
    this->m_DrawColor = (Color)v18;
  }
  v24 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: &var);
  if ( *v24 != 0 )
  {
    v25 = g_pVGuiSchemeManager;
    v26 = this->GetScheme;
    maxLen = (int)g_pVGuiSchemeManager->__vftable;
    v27 = v26(this);
    v28 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(maxLen + 32))(a1: v25, a2: v27);
    v29 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v28 + 8))(a1: v28, a2: v24);
    v29->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102E7B60
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E7CE0
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1030BE50
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100B1C60
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B1C90
// Name: public: virtual struct PanelAnimationMap __near * vgui::ImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ImagePanel::GetAnimMap(vgui::ImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100B1CA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6790
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B67D0
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x100B67E0
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x100B6800
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6870
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6890
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x100B68A0
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6AF0
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *v4; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    v4 = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value: v4);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x100B6C00
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6C60
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_7,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x100B6C90
// Name: public: void vgui::ImagePanel::SetShouldScaleImage(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetShouldScaleImage(vgui::ImagePanel *this, bool state)
{
  this->m_bScaleImage = state;
}

//------------------------------------------------------------------------------
// Address: 0x100B6CF0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  const char *v18; // edi
  int v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int maxLen; // [esp+10h] [ebp-18h] BYREF
  int len; // [esp+14h] [ebp-14h] BYREF
  int a; // [esp+18h] [ebp-10h] BYREF
  int b; // [esp+1Ch] [ebp-Ch] BYREF
  int g; // [esp+20h] [ebp-8h] BYREF
  int r; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: szDescription);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: szDescription);
  v9 = v8;
  if ( *v8 != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    len = 255;
    maxLen = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: maxLen);
    v32 = maxLen;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &g, &b, &a, &len) < 3 )
    {
      v11 = this->__vftable;
      maxLen = (int)g_pVGuiSchemeManager;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (*(int (__thiscall **)(int, int))(r + 32))(a1: maxLen, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      r = 0;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &maxLen, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(r) = g;
      BYTE1(r) = b;
      BYTE2(r) = a;
      HIBYTE(r) = len;
      this->m_FillColor = (Color)r;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: szDescription);
  maxLen = (int)v15;
  if ( *v15 != 0 )
  {
    len = 0;
    a = 0;
    b = 0;
    g = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (const char *)maxLen;
    v31 = (char *)maxLen;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &len, &a, &b, &g) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      r = (int)g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(r + 32))(a1: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      r = 0;
      v19 = *(_DWORD *)v24(a1: v23, a2: &maxLen, a3: maxLen, a4: 0);
    }
    else
    {
      LOBYTE(r) = len;
      BYTE1(r) = a;
      BYTE2(r) = b;
      HIBYTE(r) = g;
      v19 = r;
    }
    this->m_DrawColor = (Color)v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: szDescription);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    maxLen = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(maxLen + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x100B7020
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(vgui::ImagePanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B71A0
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C90E0
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00443E30
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00443E40
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00443E80
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x00443E90
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00443EB0
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443F20
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x00443F30
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00443F50
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x00443F60
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004441B0
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x004442C0
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444320
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_3,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x00444350
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00444390
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00444410
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00444740
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(vgui::ImagePanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004448C0
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042B3D0
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0042B3E0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this@<ecx>, int a2@<ebp>)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042B420
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x0042B430
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x0042B450
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B4C0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B4D0
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x0042B4E0
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4)
{
  void (__thiscall **p_SetColor)(vgui::IImage *, Color); // edi
  _DWORD *v6; // eax
  float m_fScaleAmount; // xmm0_4
  int v8; // eax
  void (__thiscall **v9)(vgui::IImage *, Color); // edi
  Color *v10; // eax
  int v11; // ebx
  int v12; // edi
  int imageWide; // [esp+3Ch] [ebp-10h] BYREF
  int tall; // [esp+40h] [ebp-Ch] BYREF
  int wide; // [esp+44h] [ebp-8h] BYREF
  int v17; // [esp+48h] [ebp-4h] BYREF
  int retaddr; // [esp+4Ch] [ebp+0h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageWide, &tall);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageWide, a5: tall);
  }
  if ( this->m_pImage != nullptr )
  {
    p_SetColor = &this->m_pImage->SetColor;
    v6 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &v17, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))*p_SetColor)(a1: this->m_pImage, a2: *v6);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &wide, a3: &tall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, wide: &retaddr, tall: &v17);
        v8 = retaddr;
      }
      else
      {
        v8 = (int)(float)((float)wide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v8);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: tall, a3: imageWide);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, &wide, &tall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &retaddr,
        a3: &v17,
        a4: a2);
      v11 = 0;
      if ( wide > 0 )
      {
        do
        {
          v12 = 0;
          if ( v17 > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v12, a3: v11);
              this->m_pImage->Paint(this: this->m_pImage);
              v12 += a4;
            }
            while ( this->m_bTileHorizontally && v12 < v17 );
          }
          v11 += retaddr;
        }
        while ( this->m_bTileVertically && v11 < wide );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v9 = &this->m_pImage->SetColor;
      v10 = this->GetDrawColor(this, result: &retaddr);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))*v9)(a1: this->m_pImage, a2: *v10);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B740
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x0042B840
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B8A0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_3,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x0042B8D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B910
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B990
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, vgui::ISchemeManager_vtbl *inResourceData)
{
  KeyValues *v3; // ebp
  KeyValues *v4; // ecx
  bool v5; // al
  bool v6; // zf
  bool m_bTileImage; // al
  const char *String; // eax
  const char *v9; // eax
  char *v10; // edi
  char *v11; // eax
  vgui::ImagePanel_vtbl *v12; // edx
  int v13; // eax
  int v14; // eax
  int (__thiscall *v15)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  char *v16; // eax
  unsigned int v17; // edi
  char *v18; // eax
  char *v19; // edi
  KeyValues *v20; // eax
  vgui::ISchemeManager *v21; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v23; // eax
  int v24; // eax
  int (__thiscall *v25)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  const char *v26; // edi
  vgui::ISchemeManager *v27; // ebx
  unsigned int (__thiscall *v28)(vgui::IClientPanel *); // eax
  int v29; // eax
  int v30; // eax
  vgui::ImagePanel_vtbl *v31; // ebx
  int v32; // eax
  char *v33; // [esp-Ch] [ebp-34h]
  KeyValues *v34; // [esp-8h] [ebp-30h]
  int v35; // [esp-8h] [ebp-30h]
  int g; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int a; // [esp+1Ch] [ebp-Ch] BYREF
  const char *pszDrawColor; // [esp+20h] [ebp-8h] BYREF
  char *pSrc; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = (KeyValues *)inResourceData;
  v4 = (KeyValues *)inResourceData;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: v4, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: v3, keyName: "scaleAmount", defaultValue: 0.0);
  v5 = KeyValues::GetInt(this: v3, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v5;
  v6 = KeyValues::GetInt(this: v3, keyName: "tileHorizontally", defaultValue: v5) == 0;
  m_bTileImage = this->m_bTileImage;
  this->m_bTileHorizontally = !v6;
  this->m_bTileVertically = KeyValues::GetInt(this: v3, keyName: "tileVertically", defaultValue: m_bTileImage) != 0;
  String = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: v3, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: v3, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v9 = KeyValues::GetString(this: v3, keyName: "fillcolor", defaultValue: defaultValue);
  v10 = (char *)v9;
  if ( *v9 != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    pszDrawColor = (const char *)255;
    inResourceData = (vgui::ISchemeManager_vtbl *)(_V_strlen(str: v9) + 1);
    v11 = (char *)operator new(nSize: (unsigned int)inResourceData);
    v34 = (KeyValues *)inResourceData;
    this->m_pszFillColorName = v11;
    V_strncpy(pDest: v11, pSrc: v10, maxLen: (int)v34);
    if ( sscanf(string: v10, format: "%d %d %d %d", &g, &b, &a, &pszDrawColor) < 3 )
    {
      v12 = this->__vftable;
      inResourceData = (vgui::ISchemeManager_vtbl *)g_pVGuiSchemeManager;
      pSrc = (char *)g_pVGuiSchemeManager->__vftable;
      v13 = v12->GetScheme(this);
      v14 = (*((int (__thiscall **)(vgui::ISchemeManager_vtbl *, int))pSrc + 8))(a1: inResourceData, a2: v13);
      v15 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v14 + 20);
      inResourceData = nullptr;
      this->m_FillColor = *(Color *)v15(a1: v14, a2: &inResourceData, a3: v10, a4: 0);
    }
    else
    {
      LOBYTE(inResourceData) = g;
      BYTE1(inResourceData) = b;
      BYTE2(inResourceData) = a;
      HIBYTE(inResourceData) = (_BYTE)pszDrawColor;
      this->m_FillColor = (Color)inResourceData;
    }
  }
  v16 = (char *)KeyValues::GetString(this: v3, keyName: "drawcolor", defaultValue: defaultValue);
  v6 = *v16 == 0;
  pSrc = v16;
  if ( !v6 )
  {
    pszDrawColor = nullptr;
    a = 0;
    b = 0;
    g = 255;
    v17 = _V_strlen(str: v16) + 1;
    v18 = (char *)operator new(nSize: v17);
    v35 = v17;
    v19 = pSrc;
    v33 = pSrc;
    this->m_pszDrawColorName = v18;
    V_strncpy(pDest: v18, pSrc: v33, maxLen: v35);
    if ( sscanf(string: v19, format: "%d %d %d %d", &pszDrawColor, &a, &b, &g) < 3 )
    {
      v21 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      inResourceData = g_pVGuiSchemeManager->__vftable;
      v23 = GetScheme(this);
      v24 = (int)inResourceData->GetIScheme(this: v21, a2: v23);
      v25 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v24 + 20);
      inResourceData = nullptr;
      v20 = *(KeyValues **)v25(a1: v24, a2: &inResourceData, a3: pSrc, a4: 0);
    }
    else
    {
      LOBYTE(inResourceData) = (_BYTE)pszDrawColor;
      BYTE1(inResourceData) = a;
      BYTE2(inResourceData) = b;
      HIBYTE(inResourceData) = g;
      v20 = (KeyValues *)inResourceData;
    }
    this->m_DrawColor = (Color)v20;
  }
  v26 = KeyValues::GetString(this: v3, keyName: "border", defaultValue: defaultValue);
  if ( *v26 != 0 )
  {
    v27 = g_pVGuiSchemeManager;
    v28 = this->GetScheme;
    inResourceData = g_pVGuiSchemeManager->__vftable;
    v29 = v28(this);
    v30 = (int)inResourceData->GetIScheme(this: v27, a2: v29);
    v31 = this->__vftable;
    v32 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v30 + 8))(a1: v30, a2: v26);
    v31->SetBorder(this, a2: (vgui::IBorder *)v32);
  }
  vgui::Panel::ApplySettings(this, inResourceData: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0042BD10
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *p_m_OverridableColorEntries; // edi
  int v9; // eax
  int v10; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = false;
  this->m_bTileImage = false;
  this->m_bTileHorizontally = false;
  this->m_bTileVertically = false;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  p_m_OverridableColorEntries = &this->m_OverridableColorEntries;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v9].m_pszScriptName = "fillcolor_override";
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v9].m_pColor = &this->m_FillColor;
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v9].m_bOverridden = false;
  v10 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
          this: &this->m_OverridableColorEntries,
          elem: this->m_OverridableColorEntries.m_Size);
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v10].m_pszScriptName = "drawcolor_override";
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v10].m_pColor = &this->m_DrawColor;
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v10].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042BEB0
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00455470
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00639E00
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00639E10
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00639E50
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x00639E60
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00639E80
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00639EF0
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x00639F00
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00639F20
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x00639F30
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063A180
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  const char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x0063A290
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063A2F0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_4,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x0063A320
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063A360
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063A3E0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  const char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)MemAlloc_Alloc(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)MemAlloc_Alloc(nSize: v16);
    v33 = v16;
    v18 = (const char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0063A710
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063A890
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10060B90
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10060BA0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10060BE0
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x10060BF0
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10060C10
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060C80
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x10060C90
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10060CB0
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x10060CC0
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060F10
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  const char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x10061020
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061080
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_8,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x100610B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100610F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061170
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x100614A0
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061620
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10062090
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100620A0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100620E0
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x100620F0
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10062110
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062180
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x10062190
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100621B0
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x100621C0
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062410
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x10062520
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062580
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_2,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x100625B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100625F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062670
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x100629A0
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062B20
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00433BE0
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00433BF0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00433C30
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x00433C40
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00433C60
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433CD0
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x00433CE0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433D00
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x00433D10
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433F60
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x00434070
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004340D0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_3,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x00434100
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00434140
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004341C0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: &defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: &defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: &defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: &defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004344F0
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(vgui::ImagePanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00434670
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0046CAC0
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046CAD0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046CB10
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x0046CB20
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x0046CB40
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CBC0
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x0046CBD0
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4)
{
  void (__thiscall **p_SetColor)(vgui::IImage *, Color); // edi
  _DWORD *v6; // eax
  float m_fScaleAmount; // xmm0_4
  int v8; // eax
  void (__thiscall **v9)(vgui::IImage *, Color); // edi
  Color *v10; // eax
  int v11; // ebx
  int v12; // edi
  int imageWide; // [esp+3Ch] [ebp-10h] BYREF
  int tall; // [esp+40h] [ebp-Ch] BYREF
  int wide; // [esp+44h] [ebp-8h] BYREF
  int v17; // [esp+48h] [ebp-4h] BYREF
  int retaddr; // [esp+4Ch] [ebp+0h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageWide, &tall);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageWide, a5: tall);
  }
  if ( this->m_pImage != nullptr )
  {
    p_SetColor = &this->m_pImage->SetColor;
    v6 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &v17, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))*p_SetColor)(a1: this->m_pImage, a2: *v6);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &wide, a3: &tall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, wide: &retaddr, tall: &v17);
        v8 = retaddr;
      }
      else
      {
        v8 = (int)(float)((float)wide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v8);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: tall, a3: imageWide);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, &wide, &tall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &retaddr,
        a3: &v17,
        a4: a2);
      v11 = 0;
      if ( wide > 0 )
      {
        do
        {
          v12 = 0;
          if ( v17 > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v12, a3: v11);
              this->m_pImage->Paint(this: this->m_pImage);
              v12 += a4;
            }
            while ( this->m_bTileHorizontally && v12 < v17 );
          }
          v11 += retaddr;
        }
        while ( this->m_bTileVertically && v11 < wide );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v9 = &this->m_pImage->SetColor;
      v10 = this->GetDrawColor(this, result: &retaddr);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))*v9)(a1: this->m_pImage, a2: *v10);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CE30
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x0046CF30
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CF90
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_2,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x0046CFC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D080
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, vgui::ISchemeManager_vtbl *inResourceData)
{
  KeyValues *v3; // ebp
  KeyValues *v4; // ecx
  bool v5; // al
  bool v6; // zf
  bool m_bTileImage; // al
  const char *String; // eax
  const char *v9; // eax
  char *v10; // edi
  char *v11; // eax
  vgui::ImagePanel_vtbl *v12; // edx
  int v13; // eax
  int v14; // eax
  int (__thiscall *v15)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  char *v16; // eax
  unsigned int v17; // edi
  char *v18; // eax
  char *v19; // edi
  KeyValues *v20; // eax
  vgui::ISchemeManager *v21; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v23; // eax
  int v24; // eax
  int (__thiscall *v25)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD); // edx
  const char *v26; // edi
  vgui::ISchemeManager *v27; // ebx
  unsigned int (__thiscall *v28)(vgui::IClientPanel *); // eax
  int v29; // eax
  int v30; // eax
  vgui::ImagePanel_vtbl *v31; // ebx
  int v32; // eax
  char *v33; // [esp-Ch] [ebp-34h]
  KeyValues *v34; // [esp-8h] [ebp-30h]
  int v35; // [esp-8h] [ebp-30h]
  int g; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int a; // [esp+1Ch] [ebp-Ch] BYREF
  const char *pszDrawColor; // [esp+20h] [ebp-8h] BYREF
  char *pSrc; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = (KeyValues *)inResourceData;
  v4 = (KeyValues *)inResourceData;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: v4, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: v3, keyName: "scaleAmount", defaultValue: 0.0);
  v5 = KeyValues::GetInt(this: v3, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v5;
  v6 = KeyValues::GetInt(this: v3, keyName: "tileHorizontally", defaultValue: v5) == 0;
  m_bTileImage = this->m_bTileImage;
  this->m_bTileHorizontally = !v6;
  this->m_bTileVertically = KeyValues::GetInt(this: v3, keyName: "tileVertically", defaultValue: m_bTileImage) != 0;
  String = KeyValues::GetString(this: v3, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: v3, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: v3, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v9 = KeyValues::GetString(this: v3, keyName: "fillcolor", defaultValue: defaultValue);
  v10 = (char *)v9;
  if ( *v9 != 0 )
  {
    g = 0;
    b = 0;
    a = 0;
    pszDrawColor = (const char *)255;
    inResourceData = (vgui::ISchemeManager_vtbl *)(_V_strlen(str: v9) + 1);
    v11 = (char *)MemAlloc_Alloc(nSize: (unsigned int)inResourceData);
    v34 = (KeyValues *)inResourceData;
    this->m_pszFillColorName = v11;
    V_strncpy(pDest: v11, pSrc: v10, maxLen: (int)v34);
    if ( sscanf(string: v10, format: "%d %d %d %d", &g, &b, &a, &pszDrawColor) < 3 )
    {
      v12 = this->__vftable;
      inResourceData = (vgui::ISchemeManager_vtbl *)g_pVGuiSchemeManager;
      pSrc = (char *)g_pVGuiSchemeManager->__vftable;
      v13 = v12->GetScheme(this);
      v14 = (*((int (__thiscall **)(vgui::ISchemeManager_vtbl *, int))pSrc + 8))(a1: inResourceData, a2: v13);
      v15 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v14 + 20);
      inResourceData = nullptr;
      this->m_FillColor = *(Color *)v15(a1: v14, a2: &inResourceData, a3: v10, a4: 0);
    }
    else
    {
      LOBYTE(inResourceData) = g;
      BYTE1(inResourceData) = b;
      BYTE2(inResourceData) = a;
      HIBYTE(inResourceData) = (_BYTE)pszDrawColor;
      this->m_FillColor = (Color)inResourceData;
    }
  }
  v16 = (char *)KeyValues::GetString(this: v3, keyName: "drawcolor", defaultValue: defaultValue);
  v6 = *v16 == 0;
  pSrc = v16;
  if ( !v6 )
  {
    pszDrawColor = nullptr;
    a = 0;
    b = 0;
    g = 255;
    v17 = _V_strlen(str: v16) + 1;
    v18 = (char *)MemAlloc_Alloc(nSize: v17);
    v35 = v17;
    v19 = pSrc;
    v33 = pSrc;
    this->m_pszDrawColorName = v18;
    V_strncpy(pDest: v18, pSrc: v33, maxLen: v35);
    if ( sscanf(string: v19, format: "%d %d %d %d", &pszDrawColor, &a, &b, &g) < 3 )
    {
      v21 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      inResourceData = g_pVGuiSchemeManager->__vftable;
      v23 = GetScheme(this);
      v24 = (int)inResourceData->GetIScheme(this: v21, a2: v23);
      v25 = *(int (__thiscall **)(int, vgui::ISchemeManager_vtbl **, char *, _DWORD))(*(_DWORD *)v24 + 20);
      inResourceData = nullptr;
      v20 = *(KeyValues **)v25(a1: v24, a2: &inResourceData, a3: pSrc, a4: 0);
    }
    else
    {
      LOBYTE(inResourceData) = (_BYTE)pszDrawColor;
      BYTE1(inResourceData) = a;
      BYTE2(inResourceData) = b;
      HIBYTE(inResourceData) = g;
      v20 = (KeyValues *)inResourceData;
    }
    this->m_DrawColor = (Color)v20;
  }
  v26 = KeyValues::GetString(this: v3, keyName: "border", defaultValue: defaultValue);
  if ( *v26 != 0 )
  {
    v27 = g_pVGuiSchemeManager;
    v28 = this->GetScheme;
    inResourceData = g_pVGuiSchemeManager->__vftable;
    v29 = v28(this);
    v30 = (int)inResourceData->GetIScheme(this: v27, a2: v29);
    v31 = this->__vftable;
    v32 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v30 + 8))(a1: v30, a2: v26);
    v31->SetBorder(this, a2: (vgui::IBorder *)v32);
  }
  vgui::Panel::ApplySettings(this, inResourceData: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0046D400
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *p_m_OverridableColorEntries; // edi
  int v9; // eax
  int v10; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = false;
  this->m_bTileImage = false;
  this->m_bTileHorizontally = false;
  this->m_bTileVertically = false;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  p_m_OverridableColorEntries = &this->m_OverridableColorEntries;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v9].m_pszScriptName = "fillcolor_override";
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v9].m_pColor = &this->m_FillColor;
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v9].m_bOverridden = false;
  v10 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
          this: &this->m_OverridableColorEntries,
          elem: this->m_OverridableColorEntries.m_Size);
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v10].m_pszScriptName = "drawcolor_override";
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v10].m_pColor = &this->m_DrawColor;
  p_m_OverridableColorEntries->m_Memory.m_pMemory[v10].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046D5A0
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004A7180
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00422490
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004224A0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004224E0
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x004224F0
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00422510
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422580
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004225A0
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x004225B0
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422800
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  const char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x00422910
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422970
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_2,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x004229A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004229E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422A60
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00422D90
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(vgui::ImagePanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00422F10
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044D710
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00425EE0
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00425EF0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425F30
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x00425F40
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00425F60
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425FD0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425FF0
// Name: public: virtual void vgui::ImagePanel::SetDrawColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetDrawColor(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x00426000
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426250
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  const char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x00426360
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004263C0
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_2,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x004263F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426430
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004264B0
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  const char *String; // eax
  const char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  const char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  const char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: defaultValue);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: defaultValue);
  v9 = (char *)v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: defaultValue);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: defaultValue);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004267E0
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00426960
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004514F0
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039E7C0
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  C_BaseEntity::operator delete(pMem: m_pszImageName);
  C_BaseEntity::operator delete(pMem: this->m_pszFillColorName);
  C_BaseEntity::operator delete(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039E800
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x1039E810
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x1039E830
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    C_BaseEntity::operator delete(pMem: this->m_pszImageName);
    v4 = (char *)MemAlloc_Alloc(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039E8A0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039E8D0
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039EB20
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x1039EC30
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039EC90
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_8,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x1039ECC0
// Name: public: void vgui::ImagePanel::SetShouldScaleImage(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetShouldScaleImage(vgui::ImagePanel *this, bool state)
{
  this->m_bScaleImage = state;
}

//------------------------------------------------------------------------------
// Address: 0x1039ECD0
// Name: public: float vgui::ImagePanel::GetScaleAmount(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ImagePanel::GetScaleAmount(vgui::ImagePanel *this)
{
  return this->m_fScaleAmount;
}

//------------------------------------------------------------------------------
// Address: 0x1039ECF0
// Name: public: class Color vgui::ImagePanel::GetFillColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetFillColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_FillColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039ED10
// Name: public: void vgui::ImagePanel::SetFrame(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetFrame(vgui::ImagePanel *this, int nFrame)
{
  this->m_bFrameImage = true;
  this->m_iFrame = nFrame;
}

//------------------------------------------------------------------------------
// Address: 0x1039ED80
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  const char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  C_BaseEntity::operator delete(pMem: this->m_pszImageName);
  C_BaseEntity::operator delete(pMem: this->m_pszFillColorName);
  C_BaseEntity::operator delete(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: prType);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: prType);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)MemAlloc_Alloc(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: prType);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)MemAlloc_Alloc(nSize: v16);
    v33 = v16;
    v18 = (const char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: prType);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1039F0B0
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039F230
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103BF690
// Name: public: int vgui::ImagePanel::GetFrame(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ImagePanel::GetFrame(vgui::Slider *this)
{
  return this->_value;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10382850
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10382860
// Name: public: virtual vgui::ImagePanel::~ImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::~ImagePanel(vgui::ImagePanel *this)
{
  char *m_pszImageName; // [esp-4h] [ebp-8h]

  m_pszImageName = this->m_pszImageName;
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  free(pMem: m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103828A0
// Name: protected: virtual void vgui::ImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::OnSizeChanged(vgui::ImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
}

//------------------------------------------------------------------------------
// Address: 0x103828B0
// Name: public: virtual void vgui::ImagePanel::SetImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, vgui::IImage *image)
{
  vgui::ImagePanel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pImage = image;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x103828D0
// Name: public: virtual void vgui::ImagePanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::SetImage(vgui::ImagePanel *this, char *imageName)
{
  unsigned int v3; // esi
  char *v4; // eax

  if ( imageName == nullptr
    || this->m_pszImageName == nullptr
    || _V_stricmp(s1: imageName, s2: this->m_pszImageName) != 0 )
  {
    v3 = _V_strlen(str: imageName) + 1;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_strncpy(pDest: v4, pSrc: imageName, maxLen: v3);
    this->InvalidateLayout(this, a2: false, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382940
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10382970
// Name: protected: virtual void vgui::ImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ImagePanel::PaintBackground(vgui::ImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::IImage_vtbl *v4; // edi
  _DWORD *v5; // eax
  float m_fScaleAmount; // xmm0_4
  int v7; // eax
  vgui::IImage_vtbl *v8; // edi
  Color *v9; // eax
  int v10; // ebx
  int v11; // edi
  int wide; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int imageWide; // [esp+Ch] [ebp-8h] BYREF
  int imageTall; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FillColor._color[3] != 0 )
  {
    vgui::Panel::GetSize(this, wide: &imageTall, tall: &imageWide);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_FillColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: imageTall, a5: imageWide);
  }
  if ( this->m_pImage != nullptr )
  {
    v4 = this->m_pImage->__vftable;
    v5 = (_DWORD *)((int (__thiscall *)(vgui::ImagePanel *, int *, int))this->GetDrawColor)(a1: this, a2: &wide, a3);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))v4->SetColor)(a1: this->m_pImage, a2: *v5);
    this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    this->m_pImage->SetRotation(this: this->m_pImage, a2: this->m_iRotation);
    if ( this->m_bFrameImage )
      this->m_pImage->SetFrame(this: this->m_pImage, a2: this->m_iFrame);
    if ( this->m_bScaleImage )
    {
      this->m_pImage->GetSize(this: this->m_pImage, a2: &imageWide, a3: &imageTall);
      m_fScaleAmount = this->m_fScaleAmount;
      if ( m_fScaleAmount <= 0.0 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v7 = wide;
      }
      else
      {
        v7 = (int)(float)((float)imageWide * m_fScaleAmount);
      }
      ((void (__thiscall *)(vgui::IImage *, int))this->m_pImage->SetSize)(a1: this->m_pImage, a2: v7);
      this->m_pImage->Paint(this: this->m_pImage);
      this->m_pImage->SetSize(this: this->m_pImage, a2: imageWide, a3: imageTall);
    }
    else if ( this->m_bTileImage || this->m_bTileHorizontally || this->m_bTileVertically )
    {
      vgui::Panel::GetSize(this, wide: &imageWide, tall: &imageTall);
      ((void (__thiscall *)(vgui::IImage *, int *, int *, int))this->m_pImage->GetSize)(
        a1: this->m_pImage,
        a2: &wide,
        a3: &tall,
        a4: a2);
      v10 = 0;
      if ( imageTall > 0 )
      {
        do
        {
          v11 = 0;
          if ( imageWide > 0 )
          {
            do
            {
              this->m_pImage->SetPos(this: this->m_pImage, a2: v11, a3: v10);
              this->m_pImage->Paint(this: this->m_pImage);
              v11 += wide;
            }
            while ( this->m_bTileHorizontally && v11 < imageWide );
          }
          v10 += tall;
        }
        while ( this->m_bTileVertically && v10 < imageTall );
      }
      this->m_pImage->SetPos(this: this->m_pImage, a2: 0, a3: 0);
    }
    else
    {
      v8 = this->m_pImage->__vftable;
      v9 = this->GetDrawColor(this, result: &wide);
      ((void (__thiscall *)(vgui::IImage *, _DWORD))v8->SetColor)(a1: this->m_pImage, a2: *v9);
      this->m_pImage->Paint(this: this->m_pImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382BC0
// Name: protected: virtual void vgui::ImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::GetSettings(vgui::ImagePanel *this, KeyValues *outResourceData)
{
  vgui::IBorder *v3; // eax
  char *value; // eax

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->m_pszImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: this->m_pszImageName);
  if ( this->m_pszFillColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "fillcolor", value: this->m_pszFillColorName);
  if ( this->m_pszDrawColorName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "drawcolor", value: this->m_pszDrawColorName);
  if ( this->GetBorder(this) != nullptr )
  {
    v3 = this->GetBorder(this);
    value = (char *)v3->GetName(this: v3);
    KeyValues::SetString(this: outResourceData, keyName: "border", value);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: this->m_bScaleImage);
  KeyValues::SetFloat(this: outResourceData, keyName: "scaleAmount", value: this->m_fScaleAmount);
  KeyValues::SetInt(this: outResourceData, keyName: "tileImage", value: this->m_bTileImage);
  KeyValues::SetInt(this: outResourceData, keyName: "tileHorizontally", value: this->m_bTileHorizontally);
  KeyValues::SetInt(this: outResourceData, keyName: "tileVertically", value: this->m_bTileVertically);
}

//------------------------------------------------------------------------------
// Address: 0x10382CD0
// Name: protected: virtual void vgui::ImagePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySchemeSettings(vgui::ImagePanel *this, vgui::IScheme *pScheme)
{
  char *m_pszImageName; // edx
  vgui::ImagePanel_vtbl *v4; // edi
  vgui::IImage *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && strlen(this->m_pszImageName) != 0 )
  {
    v4 = this->__vftable;
    v5 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: m_pszImageName, a3: this->m_bScaleImage);
    v4->SetImage(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382D30
// Name: protected: virtual char const __near * vgui::ImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ImagePanel::GetDescription(vgui::ImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(
    string: buf_3,
    count: 0x400u,
    format: "%s, string image, string border, string fillcolor, bool scaleImage",
    Description);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x10382D60
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10382DA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10382E20
// Name: public: virtual void vgui::ImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImagePanel::ApplySettings(vgui::ImagePanel *this, KeyValues *inResourceData)
{
  vgui::ImagePanel_vtbl *v3; // ebx
  bool v4; // al
  int Int; // eax
  bool v6; // zf
  char *String; // eax
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  vgui::ImagePanel_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  int (__thiscall *v14)(int, int *, char *, _DWORD); // edx
  char *v15; // eax
  unsigned int v16; // edi
  char *v17; // eax
  char *v18; // edi
  Color v19; // eax
  vgui::ISchemeManager *v20; // edi
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v22; // eax
  int v23; // eax
  int (__thiscall *v24)(int, int *, int, _DWORD); // edx
  char *v25; // edi
  vgui::ISchemeManager *v26; // ebx
  unsigned int (__thiscall *v27)(vgui::IClientPanel *); // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // [esp-Ch] [ebp-34h]
  int v32; // [esp-8h] [ebp-30h]
  int v33; // [esp-8h] [ebp-30h]
  int len; // [esp+10h] [ebp-18h] BYREF
  int a; // [esp+14h] [ebp-14h] BYREF
  int b; // [esp+18h] [ebp-10h] BYREF
  int g; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  vgui::ISchemeManager_vtbl *v39; // [esp+24h] [ebp-4h]

  free(pMem: this->m_pszImageName);
  free(pMem: this->m_pszFillColorName);
  free(pMem: this->m_pszDrawColorName);
  v3 = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  this->m_fScaleAmount = KeyValues::GetFloat(this: inResourceData, keyName: "scaleAmount", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "tileImage", defaultValue: 0) != 0;
  this->m_bTileImage = v4;
  Int = KeyValues::GetInt(this: inResourceData, keyName: "tileHorizontally", defaultValue: v4);
  v6 = !this->m_bTileImage;
  this->m_bTileHorizontally = Int != 0;
  this->m_bTileVertically = KeyValues::GetInt(this: inResourceData, keyName: "tileVertically", defaultValue: !v6) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: locale);
  if ( *String != 0 )
    this->SetImage(this, a2: String);
  if ( KeyValues::FindKey(this: inResourceData, keyName: "frame", bCreate: false) != nullptr )
  {
    this->m_iFrame = KeyValues::GetInt(this: inResourceData, keyName: "frame", defaultValue: this->m_iFrame);
    this->m_bFrameImage = true;
  }
  v8 = KeyValues::GetString(this: inResourceData, keyName: "fillcolor", defaultValue: locale);
  v9 = v8;
  if ( *v8 != 0 )
  {
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    len = _V_strlen(str: v8) + 1;
    v10 = (char *)operator new(nSize: len);
    v32 = len;
    this->m_pszFillColorName = v10;
    V_strncpy(pDest: v10, pSrc: v9, maxLen: v32);
    if ( sscanf(string: v9, format: "%d %d %d %d", &r, &g, &b, &a) < 3 )
    {
      v11 = this->__vftable;
      len = (int)g_pVGuiSchemeManager;
      v39 = g_pVGuiSchemeManager->__vftable;
      v12 = v11->GetScheme(this);
      v13 = (int)v39->GetIScheme(this: (vgui::ISchemeManager *)len, a2: v12);
      v14 = *(int (__thiscall **)(int, int *, char *, _DWORD))(*(_DWORD *)v13 + 20);
      v39 = nullptr;
      this->m_FillColor = *(Color *)v14(a1: v13, a2: &len, a3: v9, a4: 0);
    }
    else
    {
      LOBYTE(v39) = r;
      BYTE1(v39) = g;
      BYTE2(v39) = b;
      HIBYTE(v39) = a;
      this->m_FillColor = (Color)v39;
    }
  }
  v15 = KeyValues::GetString(this: inResourceData, keyName: "drawcolor", defaultValue: locale);
  len = (int)v15;
  if ( *v15 != 0 )
  {
    a = 0;
    b = 0;
    g = 0;
    r = 255;
    v16 = _V_strlen(str: v15) + 1;
    v17 = (char *)operator new(nSize: v16);
    v33 = v16;
    v18 = (char *)len;
    v31 = (char *)len;
    this->m_pszDrawColorName = v17;
    V_strncpy(pDest: v17, pSrc: v31, maxLen: v33);
    if ( sscanf(string: v18, format: "%d %d %d %d", &a, &b, &g, &r) < 3 )
    {
      v20 = g_pVGuiSchemeManager;
      GetScheme = this->GetScheme;
      v39 = g_pVGuiSchemeManager->__vftable;
      v22 = GetScheme(this);
      v23 = (int)v39->GetIScheme(this: v20, a2: v22);
      v24 = *(int (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v23 + 20);
      v39 = nullptr;
      v19 = *(Color *)v24(a1: v23, a2: &len, a3: len, a4: 0);
    }
    else
    {
      LOBYTE(v39) = a;
      BYTE1(v39) = b;
      BYTE2(v39) = g;
      HIBYTE(v39) = r;
      v19 = (Color)v39;
    }
    this->m_DrawColor = v19;
  }
  v25 = KeyValues::GetString(this: inResourceData, keyName: "border", defaultValue: locale);
  if ( *v25 != 0 )
  {
    v26 = g_pVGuiSchemeManager;
    v27 = this->GetScheme;
    len = (int)g_pVGuiSchemeManager->__vftable;
    v28 = v27(this);
    v29 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(len + 32))(a1: v26, a2: v28);
    v3 = this->__vftable;
    v30 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v29 + 8))(a1: v29, a2: v25);
    v3->SetBorder(this, a2: (vgui::IBorder *)v30);
  }
  vgui::Panel::ApplySettings(this, a2: (int)v3, a3: (int)v25, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10383150
// Name: public: vgui::ImagePanel::ImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__thiscall vgui::ImagePanel::ImagePanel(
        vgui::ImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *Repaint)(vgui::IClientPanel *); // eax
  int v8; // eax
  int v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::ImagePanel_vtbl *)&vgui::ImagePanel::`vftable';
  if ( `vgui::ImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
    v4->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ImagePanel");
    v5->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
    v6->pfnClassName = vgui::ImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_pImage = nullptr;
  this->m_pszImageName = nullptr;
  this->m_pszFillColorName = nullptr;
  this->m_pszDrawColorName = nullptr;
  *(_DWORD *)&this->m_bScaleImage = 0;
  this->m_fScaleAmount = 0.0;
  this->m_FillColor = 0;
  this->m_DrawColor = (Color)-1;
  Repaint = this->Repaint;
  this->m_iRotation = 0;
  this->m_bFrameImage = false;
  this->m_iFrame = 0;
  Repaint(this);
  v8 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pszScriptName = "fillcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_pColor = &this->m_FillColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v8].m_bOverridden = false;
  v9 = CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
         this: &this->m_OverridableColorEntries,
         elem: this->m_OverridableColorEntries.m_Size);
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pszScriptName = "drawcolor_override";
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_pColor = &this->m_DrawColor;
  this->m_OverridableColorEntries.m_Memory.m_pMemory[v9].m_bOverridden = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103832D0
// Name: Create_ImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::ImagePanel *__cdecl Create_ImagePanel()
{
  vgui::ImagePanel *v0; // eax

  v0 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::ImagePanel::ImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10418200
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
// Address: 0x10422DF0
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

} // namespace server
