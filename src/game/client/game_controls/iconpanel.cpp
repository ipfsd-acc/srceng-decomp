// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/game_controls/iconpanel.cpp
// Functions: 11
// ============================================================

#include "game\client\game_controls\iconpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1023D0B0
// Name: public: static char const __near * CIconPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CIconPanel::GetPanelClassName()
{
  return "CIconPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1023D0C0
// Name: private: static void __near * CIconPanel::GetVar_m_IconColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CIconPanel::GetVar_m_IconColor(vgui::Panel *panel)
{
  return (char *)&panel[1].m_OverridableColorEntries.m_pElements + 2;
}

//------------------------------------------------------------------------------
// Address: 0x1023D0D0
// Name: public: virtual void CIconPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconPanel::Paint(CIconPanel *this)
{
  CHudTexture *m_icon; // ecx
  Color *p_m_IconColor; // [esp-4h] [ebp-1Ch]
  int x; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int w; // [esp+10h] [ebp-8h] BYREF
  int h; // [esp+14h] [ebp-4h] BYREF

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( this->m_icon != nullptr )
  {
    vgui::Panel::GetBounds(this, &x, &y, wide: &w, tall: &h);
    p_m_IconColor = &this->m_IconColor;
    m_icon = this->m_icon;
    if ( this->m_bScaleImage )
      CHudTexture::DrawSelf(this: m_icon, x: 0, y: 0, w, h, clr: p_m_IconColor, flApparentZ: 1.0);
    else
      CHudTexture::DrawSelf(this: m_icon, x: 0, y: 0, clr: p_m_IconColor, flApparentZ: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D150
// Name: public: virtual void CIconPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconPanel::ApplySettings(CIconPanel *this, KeyValues *inResourceData)
{
  char *m_szIcon; // edi
  char *String; // eax
  CHudIcons *v5; // eax

  m_szIcon = this->m_szIcon;
  String = KeyValues::GetString(this: inResourceData, keyName: "icon", defaultValue: prType);
  V_strncpy(pDest: this->m_szIcon, pSrc: String, maxLen: 128);
  v5 = HudIcons();
  this->m_icon = CHudIcons::GetIcon(this: v5, szIcon: this->m_szIcon);
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)m_szIcon, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1023D1C0
// Name: public: virtual void CIconPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconPanel::ApplySchemeSettings(CIconPanel *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  CHudIcons *v4; // eax
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  CIconPanel_vtbl *v6; // ebx
  _DWORD *v7; // eax

  v2 = (vgui::IScheme *)pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  if ( this->m_szIcon[0] != 0 )
  {
    v4 = HudIcons();
    this->m_icon = CHudIcons::GetIcon(this: v4, szIcon: this->m_szIcon);
  }
  GetColor = v2->GetColor;
  v6 = this->__vftable;
  pScheme = -1;
  v7 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "FgColor",
                   a4: -1);
  ((void (__thiscall *)(CIconPanel *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
}

//------------------------------------------------------------------------------
// Address: 0x1023D230
// Name: public: static void CIconPanel::PanelAnimationVar_m_IconColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CIconPanel::PanelAnimationVar_m_IconColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CIconPanel::PanelAnimationVar_m_IconColor::InitVar'::`2'::bAdded )
  {
    `CIconPanel::PanelAnimationVar_m_IconColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CIconPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "iconColor";
    src.m_pszVariable = "m_IconColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "255 255 255 255";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CIconPanel::GetVar_m_IconColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D290
// Name: public: CIconPanel::CIconPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CIconPanel *__thiscall CIconPanel::CIconPanel(CIconPanel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CIconPanel_vtbl *)&CIconPanel::`vftable';
  if ( `CIconPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CIconPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CIconPanel");
    v4->pfnClassName = CIconPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CIconPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CIconPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CIconPanel");
    v5->pfnClassName = CIconPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CIconPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CIconPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CIconPanel");
    v6->pfnClassName = CIconPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CIconPanel::PanelAnimationVar_m_IconColor::InitVar();
  this->m_IconColor = 0;
  this->m_szIcon[0] = 0;
  this->m_icon = nullptr;
  this->m_bScaleImage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1023D370
// Name: public: virtual struct vgui::PanelMessageMap __near * CIconPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CIconPanel::GetMessageMap(CIconPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CIconPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CIconPanel::GetMessageMap'::`2'::s_pMap;
  `CIconPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CIconPanel");
  `CIconPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023D3A0
// Name: public: virtual struct PanelAnimationMap __near * CIconPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CIconPanel::GetAnimMap(CIconPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CIconPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1023D3B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CIconPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CIconPanel::GetKBMap(CIconPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CIconPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CIconPanel::GetKBMap'::`2'::s_pMap;
  `CIconPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CIconPanel");
  `CIconPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023D3E0
// Name: Create_CIconPanel
// Source: json
//------------------------------------------------------------------------------
CIconPanel *__cdecl Create_CIconPanel()
{
  CIconPanel *v0; // eax

  v0 = (CIconPanel *)MemAlloc_Alloc(nSize: 0x1DCu);
  if ( v0 != nullptr )
    return CIconPanel::CIconPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}
