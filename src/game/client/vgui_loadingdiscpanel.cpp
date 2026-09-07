// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_loadingdiscpanel.cpp
// Functions: 12
// ============================================================

#include "game\client\vgui_loadingdiscpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10063F30
// Name: public: virtual void CLoadingDisc::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingDisc::Create(CBaseResourcePrecacher *this, IResourcePrecacher *pNext)
{
  this->m_pNext = pNext;
}

//------------------------------------------------------------------------------
// Address: 0x101849D0
// Name: DrawRoundedBackground
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawRoundedBackground(Color bgColor, int wide, int tall)
{
  int *v3; // edi
  int *v4; // esi
  int v5; // ecx
  int v6; // eax
  int *v7; // edi
  int *v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int *v12; // esi
  int *v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  int *v17; // eax
  int *v18; // esi
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int *v22; // [esp+Ch] [ebp-Ch]
  int x1; // [esp+10h] [ebp-8h]
  int x1a; // [esp+10h] [ebp-8h]
  int x1b; // [esp+10h] [ebp-8h]
  int x1c; // [esp+10h] [ebp-8h]
  int x2; // [esp+14h] [ebp-4h]
  int x2a; // [esp+14h] [ebp-4h]
  int x2b; // [esp+14h] [ebp-4h]
  int x2c; // [esp+14h] [ebp-4h]

  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: bgColor);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: bgColor);
  v3 = &coord[7];
  v4 = &coord[1];
  do
  {
    v5 = *(v4 - 1);
    x1 = v5;
    if ( v5 < *v4 || (x1 = *v4, x2 = *(v4 - 1), v5 <= *v4) )
      x2 = *v4;
    v6 = *v3;
    if ( *(v3 - 1) > *v3 )
      v6 = *(v3 - 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x1, a3: v6, a4: x2, a5: coord[7]);
    ++v4;
    --v3;
  }
  while ( (int)v4 < (int)&loadingdisc );
  v7 = &coord[7];
  v8 = &coord[1];
  do
  {
    v9 = wide - *(v8 - 1);
    v10 = wide - *v8;
    x1a = v9;
    if ( v9 < v10 || (x1a = wide - *v8, x2a = wide - *(v8 - 1), v9 <= v10) )
      x2a = wide - *v8;
    v11 = *(v7 - 1);
    if ( v11 <= *v7 )
      v11 = *v7;
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x1a, a3: v11, a4: x2a, a5: coord[7]);
    ++v8;
    --v7;
  }
  while ( (int)v8 < (int)&loadingdisc );
  v12 = &coord[7];
  v13 = &coord[1];
  do
  {
    v14 = wide - *(v13 - 1);
    v15 = wide - *v13;
    x1b = v14;
    if ( v14 < v15 || (x1b = wide - *v13, x2b = wide - *(v13 - 1), v14 <= v15) )
      x2b = wide - *v13;
    v16 = tall - *(v12 - 1);
    if ( v16 >= tall - *v12 )
      v16 = tall - *v12;
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x1b, a3: tall - coord[7], a4: x2b, a5: v16);
    ++v13;
    --v12;
  }
  while ( (int)v13 < (int)&loadingdisc );
  v17 = &coord[1];
  v18 = &coord[7];
  v22 = &coord[1];
  do
  {
    v19 = *v17;
    v20 = *(v17 - 1);
    x1c = v20;
    if ( v20 < v19 || (x1c = v19, x2c = v20, v20 <= v19) )
      x2c = v19;
    v21 = tall - *(v18 - 1);
    if ( v21 >= tall - *v18 )
      v21 = tall - *v18;
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x1c, a3: tall - coord[7], a4: x2c, a5: v21);
    v17 = v22 + 1;
    --v18;
    v22 = v17;
  }
  while ( (int)v17 < (int)&loadingdisc );
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: coord[7], a4: coord[7], a5: tall - coord[7]);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: coord[7], a3: 0, a4: wide - coord[7], a5: tall);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide - coord[7], a3: coord[7], a4: wide, a5: tall - coord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x10184BF0
// Name: public: virtual void CLoadingDiscPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingDiscPanel::ApplySchemeSettings(CLoadingDiscPanel *this, vgui::IScheme *pScheme)
{
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  void (__thiscall *LoadControlSettings)(vgui::EditablePanel *, const char *, const char *, KeyValues *, KeyValues *); // eax
  int wide; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = ScreenWidth();
  v4 = ScreenHeight();
  v5 = v4;
  if ( v3 != this->m_ScreenSize[0] || v4 != this->m_ScreenSize[1] )
  {
    LoadControlSettings = this->LoadControlSettings;
    this->m_ScreenSize[0] = v3;
    this->m_ScreenSize[1] = v5;
    LoadControlSettings(this, a2: "resource/LoadingDiscPanel.res", a3: nullptr, a4: nullptr, a5: nullptr);
  }
  vgui::Panel::GetSize(this, &wide, tall: (int *)&pScheme);
  vgui::Panel::SetPos(this, x: (v3 - wide) / 2, y: (v5 - (int)pScheme) / 2);
}

//------------------------------------------------------------------------------
// Address: 0x10184C80
// Name: public: virtual void CLoadingDiscPanel::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingDiscPanel::SetText(CLoadingDiscPanel *this, const char *text)
{
  this->m_pLoadingLabel->SetText(this: this->m_pLoadingLabel, a2: text);
}

//------------------------------------------------------------------------------
// Address: 0x10184CA0
// Name: public: virtual void CLoadingDiscPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingDiscPanel::PaintBackground(CLoadingDiscPanel *this)
{
  int wide; // [esp+0h] [ebp-Ch] BYREF
  int tall; // [esp+4h] [ebp-8h] BYREF
  Color bgColor; // [esp+8h] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  bgColor = (Color)-16777216;
  DrawRoundedBackground(bgColor: (Color)-16777216, wide, tall);
}

//------------------------------------------------------------------------------
// Address: 0x10184CE0
// Name: public: CLoadingDiscPanel::CLoadingDiscPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CLoadingDiscPanel *__thiscall CLoadingDiscPanel::CLoadingDiscPanel(CLoadingDiscPanel *this, unsigned int parent)
{
  int v3; // ebx
  vgui::Label *v4; // eax
  vgui::Label *v5; // edi
  vgui::ProgressBar *v6; // eax
  vgui::ProgressBar *v7; // edi
  int v8; // edi
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int h; // [esp+14h] [ebp-4h]

  vgui::EditablePanel::EditablePanel(this, parent: nullptr, panelName: "CLoadingDiscPanel");
  this->__vftable = (CLoadingDiscPanel_vtbl *)&CLoadingDiscPanel::`vftable';
  v3 = ScreenWidth();
  h = ScreenHeight();
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetProportional(this, state: true);
  vgui::Panel::SetScheme(this, tag: "ClientScheme");
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetCursor(this, cursor: 0);
  v4 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v4 != nullptr )
    v5 = vgui::Label::Label(this: v4, parent: this, panelName: "LoadingLabel", text: prType);
  else
    v5 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v5);
  this->m_pLoadingLabel = v5;
  v5->SetPaintBackgroundEnabled(this: v5, a2: false);
  v6 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v6 != nullptr )
    v7 = vgui::ProgressBar::ProgressBar(this: v6, parent: this, panelName: "LoadingProgress");
  else
    v7 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v7);
  this->m_pProgressBar = v7;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/LoadingDiscPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetSize(this, &wide, &tall);
  v8 = h;
  vgui::Panel::SetPos(this, x: (v3 - wide) / 2, y: (h - tall) / 2);
  this->m_ScreenSize[1] = v8;
  this->m_ScreenSize[0] = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10184E40
// Name: public: bool CLoadingDiscPanel::UpdateProgressBar(float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLoadingDiscPanel::UpdateProgressBar(CLoadingDiscPanel *this, float progress, const char *statusText)
{
  float currentProgress; // [esp+8h] [ebp-4h]

  vgui::ProgressBar::SetBarInset(this: this->m_pProgressBar, pixels: 2);
  currentProgress = vgui::ProgressBar::GetProgress(this: this->m_pProgressBar);
  ((void (__cdecl *)(_DWORD))this->m_pProgressBar->SetProgress)(a1: LODWORD(progress));
  return vgui::ProgressBar::GetProgress(this: this->m_pProgressBar) != currentProgress;
}

//------------------------------------------------------------------------------
// Address: 0x10184EB0
// Name: public: virtual void CLoadingDisc::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingDisc::Destroy(CLoadingDisc *this)
{
  CLoadingDiscPanel *loadingDiscPanel; // ecx
  CLoadingDiscPanel *m_pPauseDiscPanel; // ecx

  if ( this->loadingDiscPanel != nullptr )
  {
    this->loadingDiscPanel->SetParent_2(this: this->loadingDiscPanel, a2: nullptr);
    loadingDiscPanel = this->loadingDiscPanel;
    if ( loadingDiscPanel != nullptr )
      ((void (__thiscall *)(CLoadingDiscPanel *, int))loadingDiscPanel->dtr_Panel)(a1: loadingDiscPanel, a2: 1);
  }
  if ( this->m_pPauseDiscPanel != nullptr )
  {
    this->m_pPauseDiscPanel->SetParent_2(this: this->m_pPauseDiscPanel, a2: nullptr);
    m_pPauseDiscPanel = this->m_pPauseDiscPanel;
    if ( m_pPauseDiscPanel != nullptr )
      ((void (__thiscall *)(CLoadingDiscPanel *, int))m_pPauseDiscPanel->dtr_Panel)(a1: m_pPauseDiscPanel, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184F10
// Name: public: virtual bool CLoadingDisc::UpdateProgressBar(float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLoadingDisc::UpdateProgressBar(CLoadingDisc *this, float progress, const char *statusText)
{
  return this->loadingDiscPanel != nullptr
      && this->loadingDiscPanel->IsVisible(this: this->loadingDiscPanel)
      && CLoadingDiscPanel::UpdateProgressBar(this: this->loadingDiscPanel, progress, statusText);
}

//------------------------------------------------------------------------------
// Address: 0x10184F50
// Name: public: virtual unsigned int CLoadingDisc::GetLoadingVPANEL(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLoadingDisc::GetLoadingVPANEL(CLoadingDisc *this)
{
  CLoadingDiscPanel *loadingDiscPanel; // eax

  loadingDiscPanel = this->loadingDiscPanel;
  if ( loadingDiscPanel != nullptr && loadingDiscPanel->m_pProgressBar != nullptr )
    return loadingDiscPanel->m_pProgressBar->GetVPanel(this: loadingDiscPanel->m_pProgressBar);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10184F80
// Name: public: virtual void CLoadingDisc::SetLoadingVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingDisc::SetLoadingVisible(CLoadingDisc *this, BOOL bVisible)
{
  CLoadingDiscPanel *v3; // eax
  CLoadingDiscPanel *v4; // edi
  CLoadingDiscPanel *loadingDiscPanel; // ecx

  if ( bVisible && this->loadingDiscPanel == nullptr )
  {
    v3 = (CLoadingDiscPanel *)MemAlloc_Alloc(nSize: 0x18Cu);
    if ( v3 != nullptr )
      v4 = CLoadingDiscPanel::CLoadingDiscPanel(this: v3, parent: this->m_hParent);
    else
      v4 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v4);
    this->loadingDiscPanel = v4;
  }
  loadingDiscPanel = this->loadingDiscPanel;
  if ( loadingDiscPanel != nullptr )
    loadingDiscPanel->SetVisible(this: loadingDiscPanel, a2: bVisible);
}

//------------------------------------------------------------------------------
// Address: 0x10184FE0
// Name: public: virtual void CLoadingDisc::SetPausedVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingDisc::SetPausedVisible(CLoadingDisc *this, BOOL bVisible)
{
  CLoadingDiscPanel *v3; // eax
  CLoadingDiscPanel *v4; // esi
  CLoadingDiscPanel *m_pPauseDiscPanel; // ecx

  if ( bVisible && this->m_pPauseDiscPanel == nullptr )
  {
    v3 = (CLoadingDiscPanel *)MemAlloc_Alloc(nSize: 0x18Cu);
    if ( v3 != nullptr )
      v4 = CLoadingDiscPanel::CLoadingDiscPanel(this: v3, parent: this->m_hParent);
    else
      v4 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v4);
    this->m_pPauseDiscPanel = v4;
    v4->SetText(this: v4, a2: "#gameui_paused");
  }
  m_pPauseDiscPanel = this->m_pPauseDiscPanel;
  if ( m_pPauseDiscPanel != nullptr )
    m_pPauseDiscPanel->SetVisible(this: m_pPauseDiscPanel, a2: bVisible);
}
