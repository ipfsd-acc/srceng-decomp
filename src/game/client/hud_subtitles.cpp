// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_subtitles.cpp
// Functions: 10
// ============================================================

#include "game\client\hud_subtitles.h"

//------------------------------------------------------------------------------
// Address: 0x10110100
// Name: public: static char const __near * CHudSubtitles::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudSubtitles::GetPanelClassName()
{
  return "CHudSubtitles";
}

//------------------------------------------------------------------------------
// Address: 0x10110120
// Name: protected: virtual void CHudSubtitles::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudSubtitles::Reset(CHudSubtitles *this)
{
  CSubtitlePanel *m_pSubtitlePanel; // ecx

  m_pSubtitlePanel = this->m_pSubtitlePanel;
  if ( m_pSubtitlePanel != nullptr )
    ((void (__thiscall *)(CSubtitlePanel *, int))m_pSubtitlePanel->dtr_Panel)(a1: m_pSubtitlePanel, a2: 1);
  this->m_pSubtitlePanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10110150
// Name: protected: virtual bool CHudSubtitles::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudSubtitles::ShouldDraw(CHudSubtitles *this)
{
  bool v2; // al
  CSubtitlePanel *m_pSubtitlePanel; // ecx
  CSubtitlePanel *v4; // ecx
  bool v5; // bl
  char result; // al

  v2 = engine->IsPaused(this: engine);
  if ( this->m_bIsPaused != v2 )
  {
    m_pSubtitlePanel = this->m_pSubtitlePanel;
    this->m_bIsPaused = v2;
    if ( m_pSubtitlePanel != nullptr )
      CSubtitlePanel::Pause(this: m_pSubtitlePanel, bPause: v2);
  }
  v4 = this->m_pSubtitlePanel;
  v5 = v4 != nullptr && CSubtitlePanel::HasCaptions(this: v4);
  result = CHudElement::ShouldDraw(this);
  if ( result != 0 )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101101D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudSubtitles::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudSubtitles::GetMessageMap(CHudSubtitles *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudSubtitles::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudSubtitles::GetMessageMap'::`2'::s_pMap;
  `CHudSubtitles::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudSubtitles");
  `CHudSubtitles::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10110200
// Name: public: virtual struct PanelAnimationMap __near * CHudSubtitles::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudSubtitles::GetAnimMap(CHudSubtitles *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudSubtitles");
}

//------------------------------------------------------------------------------
// Address: 0x10110210
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudSubtitles::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudSubtitles::GetKBMap(CHudSubtitles *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudSubtitles::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudSubtitles::GetKBMap'::`2'::s_pMap;
  `CHudSubtitles::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudSubtitles");
  `CHudSubtitles::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10110240
// Name: public: CHudSubtitles::CHudSubtitles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudSubtitles *__thiscall CHudSubtitles::CHudSubtitles(CHudSubtitles *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax
  int nScreenWide; // [esp+Ch] [ebp-4h] BYREF

  CHudElement::CHudElement(this, pElementName);
  vgui::EditablePanel::EditablePanel(this: &this->vgui::EditablePanel, parent: nullptr, panelName: "HudSubtitles");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudSubtitles_vtbl *)&CHudSubtitles::`vftable'{for `CHudElement'};
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::EditablePanel_vtbl *)&CHudSubtitles::`vftable'{for `vgui::EditablePanel'};
  if ( `CHudSubtitles::ChainToMap'::`2'::chained == 0 )
  {
    `CHudSubtitles::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudSubtitles");
    v3->pfnClassName = CHudSubtitles::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CHudSubtitles::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudSubtitles::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudSubtitles");
    v4->pfnClassName = CHudSubtitles::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CHudSubtitles::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudSubtitles::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudSubtitles");
    v5->pfnClassName = CHudSubtitles::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::EditablePanel, newParent: v7);
  vgui::Panel::SetScheme(this: &this->vgui::EditablePanel, tag: "basemodui_scheme");
  vgui::Panel::SetProportional(this: &this->vgui::EditablePanel, state: true);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &nScreenWide, a3: (int *)&pElementName);
  vgui::Panel::SetPos(this: &this->vgui::EditablePanel, x: 0, y: 0);
  vgui::Panel::SetSize(this: &this->vgui::EditablePanel, wide: nScreenWide, tall: (int)pElementName);
  this->m_pSubtitlePanel = nullptr;
  this->m_bIsPaused = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101103F0
// Name: public: void CHudSubtitles::StartCaptions(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudSubtitles::StartCaptions(CHudSubtitles *this, const char *pFilename)
{
  CSubtitlePanel *m_pSubtitlePanel; // ecx
  CSubtitlePanel *v4; // ebx
  int Tall; // eax
  CSubtitlePanel *v6; // eax
  CSubtitlePanel *v7; // ecx

  if ( ShouldUseCaptioning() )
  {
    m_pSubtitlePanel = this->m_pSubtitlePanel;
    if ( m_pSubtitlePanel != nullptr )
      ((void (__thiscall *)(CSubtitlePanel *, int))m_pSubtitlePanel->dtr_Panel)(a1: m_pSubtitlePanel, a2: 1);
    this->m_pSubtitlePanel = nullptr;
    v4 = (CSubtitlePanel *)MemAlloc_Alloc(nSize: 0x2B0u);
    if ( v4 != nullptr )
    {
      Tall = vgui::Panel::GetTall(this: &this->vgui::EditablePanel);
      v6 = CSubtitlePanel::CSubtitlePanel(
             this: v4,
             pParent: &this->vgui::EditablePanel,
             pCaptionFile: pFilename,
             nPlaybackHeight: Tall);
    }
    else
    {
      v6 = nullptr;
    }
    this->m_pSubtitlePanel = v6;
    if ( !CSubtitlePanel::StartCaptions(this: v6) )
    {
      v7 = this->m_pSubtitlePanel;
      if ( v7 != nullptr )
        ((void (__thiscall *)(CSubtitlePanel *, int))v7->dtr_Panel)(a1: v7, a2: 1);
      this->m_pSubtitlePanel = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110490
// Name: hud_subtitles
// Source: json
//------------------------------------------------------------------------------
void __cdecl hud_subtitles(const CCommand *args)
{
  CHud *Hud; // eax
  CHudSubtitles *Element; // eax
  const char *v3; // edx

  if ( args->m_nArgc >= 2 )
  {
    Hud = GetHud(nSlot: 0);
    Element = (CHudSubtitles *)CHud::FindElement(this: Hud, pName: "CHudSubtitles");
    if ( Element != nullptr )
    {
      v3 = prType;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      CHudSubtitles::StartCaptions(this: Element, pFilename: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101104E0
// Name: Create_CHudSubtitles
// Source: json
//------------------------------------------------------------------------------
CHudSubtitles *__cdecl Create_CHudSubtitles()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 448);
  memset(dst: v0, value: 0, count: 0x1C0u);
  if ( v0 != nullptr )
    return CHudSubtitles::CHudSubtitles(this: (CHudSubtitles *)v0, pElementName: "CHudSubtitles");
  else
    return nullptr;
}
