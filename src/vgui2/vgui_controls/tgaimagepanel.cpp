// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/tgaimagepanel.cpp
// Functions: 11
// ============================================================

#include "vgui2\vgui_controls\tgaimagepanel.h"

//------------------------------------------------------------------------------
// Address: 0x103BD2C0
// Name: public: static char const __near * CTGAImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAImagePanel::GetPanelClassName()
{
  return "CTGAImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x103BD2D0
// Name: public: void CTGAImagePanel::SetTGAFilenameNonMod(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAImagePanel::SetTGAFilenameNonMod(CTGAImagePanel *this, const char *filename)
{
  CUtlString::operator=(this: &this->m_sTGAFilenameWithPath, src: filename);
  CUtlString::operator=(this: &this->m_sTGAFilename, src: filename);
}

//------------------------------------------------------------------------------
// Address: 0x103BD300
// Name: public: virtual void CTGAImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAImagePanel::GetSettings(CTGAImagePanel *this, KeyValues *outResourceData)
{
  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "scaleImage", value: (*((_BYTE *)this + 384) & 4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x103BD330
// Name: public: virtual void CTGAImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTGAImagePanel::ApplySettings(CTGAImagePanel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  *((_BYTE *)this + 384) ^= (*((_BYTE *)this + 384)
                           ^ (4 * (KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0)))
                          & 4;
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x103BD370
// Name: public: void CTGAImagePanel::SetTGAFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAImagePanel::SetTGAFilename(CTGAImagePanel *this, const char *filename)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+8h] [ebp-10Ch] BYREF

  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "//MOD/%s", filename);
  CUtlString::operator=(this: &this->m_sTGAFilenameWithPath, src: v3->m_szBuf);
  CUtlString::operator=(this: &this->m_sTGAFilename, src: filename);
}

//------------------------------------------------------------------------------
// Address: 0x103BD3C0
// Name: public: virtual CTGAImagePanel::~CTGAImagePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAImagePanel::~CTGAImagePanel(CTGAImagePanel *this)
{
  this->__vftable = (CTGAImagePanel_vtbl *)&CTGAImagePanel::`vftable';
  this->m_sTGAFilename.m_Storage.m_nActualLength = 0;
  if ( this->m_sTGAFilename.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sTGAFilename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sTGAFilename.m_Storage.m_Memory.m_pMemory);
      this->m_sTGAFilename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sTGAFilename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_sTGAFilenameWithPath.m_Storage.m_nActualLength = 0;
  if ( this->m_sTGAFilenameWithPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sTGAFilenameWithPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sTGAFilenameWithPath.m_Storage.m_Memory.m_pMemory);
      this->m_sTGAFilenameWithPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sTGAFilenameWithPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BD440
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAImagePanel::GetMessageMap(CTGAImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAImagePanel::GetMessageMap'::`2'::s_pMap;
  `CTGAImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAImagePanel");
  `CTGAImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BD470
// Name: public: virtual struct PanelAnimationMap __near * CTGAImagePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAImagePanel::GetAnimMap(CTGAImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x103BD480
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAImagePanel::GetKBMap(CTGAImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAImagePanel::GetKBMap'::`2'::s_pMap;
  `CTGAImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAImagePanel");
  `CTGAImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BD4B0
// Name: public: virtual void CTGAImagePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAImagePanel::Paint(CTGAImagePanel *this)
{
  char v2; // al
  int v3; // eax
  bool v4; // zf
  int *p_m_iImageHeight; // edi
  int *p_m_iImageWidth; // ebx
  const char *v7; // eax
  int v8; // edi
  int v9; // eax
  CUtlMemory<unsigned char,int> tga; // [esp+8h] [ebp-14h] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int tall; // [esp+18h] [ebp-4h] BYREF

  v2 = *((_BYTE *)this + 384);
  if ( (v2 & 2) == 0 )
  {
    *((_BYTE *)this + 384) = v2 | 2;
    if ( this->m_iTextureID < 0 )
    {
      v3 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: true);
      v4 = (*((_BYTE *)this + 384) & 4) == 0;
      this->m_iTextureID = v3;
      if ( v4 )
        vgui::Panel::SetSize(this, wide: 180, tall: 100);
    }
    memset(&tga, 0, sizeof(tga));
    p_m_iImageHeight = &this->m_iImageHeight;
    p_m_iImageWidth = &this->m_iImageWidth;
    v7 = CUtlString::operator char const *(this: &this->m_sTGAFilenameWithPath);
    if ( TGALoader::LoadRGBA8888(
           pFileName: v7,
           outputData: &tga,
           outWidth: &this->m_iImageWidth,
           outHeight: &this->m_iImageHeight) != 0 )
    {
      g_pVGuiSurface->DrawSetTextureRGBA(
        this: g_pVGuiSurface,
        a2: this->m_iTextureID,
        a3: tga.m_pMemory,
        a4: *p_m_iImageWidth,
        a5: *p_m_iImageHeight);
      *((_BYTE *)this + 384) |= 1u;
      if ( (*((_BYTE *)this + 384) & 4) == 0 )
        vgui::Panel::SetSize(this, wide: *p_m_iImageWidth, tall: *p_m_iImageHeight);
    }
    else
    {
      *((_BYTE *)this + 384) &= ~1u;
    }
    if ( tga.m_nGrowSize >= 0 && tga.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tga.m_pMemory);
  }
  if ( (*((_BYTE *)this + 384) & 1) != 0 )
  {
    g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iTextureID, a3: &wide, a4: &tall);
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_ImageColor);
    if ( (*((_BYTE *)this + 384) & 4) != 0 )
      v8 = vgui::Panel::GetWide(this);
    else
      v8 = wide;
    if ( (*((_BYTE *)this + 384) & 4) != 0 )
      v9 = vgui::Panel::GetTall(this);
    else
      v9 = tall;
    g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: v8, a5: v9);
  }
  else
  {
    wide = 180;
    tall = 100;
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BD680
// Name: public: CTGAImagePanel::CTGAImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAImagePanel *__thiscall CTGAImagePanel::CTGAImagePanel(CTGAImagePanel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CTGAImagePanel_vtbl *)&CTGAImagePanel::`vftable';
  if ( `CTGAImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTGAImagePanel");
    v4->pfnClassName = CTGAImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CTGAImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTGAImagePanel");
    v5->pfnClassName = CTGAImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CTGAImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAImagePanel");
    v6->pfnClassName = CTGAImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_ImageColor = 0;
  CUtlString::CUtlString(this: &this->m_sTGAFilenameWithPath);
  CUtlString::CUtlString(this: &this->m_sTGAFilename);
  *((_BYTE *)this + 384) &= 0xF8u;
  this->m_iTextureID = -1;
  this->m_ImageColor = (Color)-1;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  return this;
}
