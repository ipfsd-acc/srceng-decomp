// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/serverconfigpanel.cpp
// Functions: 3
// ============================================================

#include "tracker\adminserver\serverconfigpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1000D470
// Name: public: CServerConfigPanel::CServerConfigPanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerConfigPanel *__thiscall CServerConfigPanel::CServerConfigPanel(
        CServerConfigPanel *this,
        vgui::Panel *parent,
        const char *name,
        const char *mod)
{
  CVarListPropertyPage::CVarListPropertyPage(this, parent, name);
  this->CVarListPropertyPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CServerConfigPanel_vtbl *)&CServerConfigPanel::`vftable'{for `vgui::PropertyPage'};
  this->CVarListPropertyPage::IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CServerConfigPanel::`vftable'{for `IServerDataResponse'};
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 500, tall: 170);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Admin\\ServerConfigPanel.res",
    pathID: "PLATFORM",
    pKeyValues: nullptr,
    pConditions: nullptr);
  CVarListPropertyPage::LoadVarList(this, varfile: "scripts/GameServerConfig.vdf");
  this->m_flUpdateTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000D4E0
// Name: protected: virtual void CServerConfigPanel::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerConfigPanel::OnResetData(CServerConfigPanel *this)
{
  this->RefreshVarList(this);
  this->m_flUpdateTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) + 60.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D510
// Name: protected: virtual void CServerConfigPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerConfigPanel::OnThink(CServerConfigPanel *this)
{
  long double m_flUpdateTime; // [esp+4h] [ebp-8h]

  m_flUpdateTime = this->m_flUpdateTime;
  if ( g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) > m_flUpdateTime )
    this->OnResetData(this);
}
