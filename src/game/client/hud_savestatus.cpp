// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_savestatus.cpp
// Functions: 10
// ============================================================

#include "game\client\hud_savestatus.h"

//------------------------------------------------------------------------------
// Address: 0x1010FAC0
// Name: public: static char const __near * CHudSaveStatus::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudSaveStatus::GetPanelClassName()
{
  return "CHudSaveStatus";
}

//------------------------------------------------------------------------------
// Address: 0x1010FAD0
// Name: public: void CHudSaveStatus::SaveStarted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudSaveStatus::SaveStarted(CHudSaveStatus *this)
{
  int v1; // [esp+0h] [ebp-4h]

  this->m_flSaveStartedTime = _Plat_FloatTime(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1010FAF0
// Name: public: CHudSaveStatus::CHudSaveStatus(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudSaveStatus *__thiscall CHudSaveStatus::CHudSaveStatus(CHudSaveStatus *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::EditablePanel::EditablePanel(this: &this->vgui::EditablePanel, parent: nullptr, panelName: "HudSaveStatus");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudSaveStatus_vtbl *)&CHudSaveStatus::`vftable'{for `CHudElement'};
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::EditablePanel_vtbl *)&CHudSaveStatus::`vftable'{for `vgui::EditablePanel'};
  if ( `CHudSaveStatus::ChainToMap'::`2'::chained == 0 )
  {
    `CHudSaveStatus::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudSaveStatus");
    v3->pfnClassName = CHudSaveStatus::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CHudSaveStatus::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudSaveStatus::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudSaveStatus");
    v4->pfnClassName = CHudSaveStatus::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CHudSaveStatus::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudSaveStatus::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudSaveStatus");
    v5->pfnClassName = CHudSaveStatus::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::EditablePanel, newParent: v7);
  vgui::Panel::SetScheme(this: &this->vgui::EditablePanel, tag: "basemodui_scheme");
  vgui::Panel::SetProportional(this: &this->vgui::EditablePanel, state: true);
  this->m_pSavingIcon = nullptr;
  this->m_pSavingLabel = nullptr;
  this->m_pSavedLabel = nullptr;
  *(_WORD *)&this->m_bNeedsDraw = 0;
  this->m_flLastAnimTime = 0.0;
  this->m_flFadeOutTime = 0.0;
  this->m_flSaveStartedTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010FC40
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudSaveStatus::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudSaveStatus::GetMessageMap(CHudSaveStatus *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudSaveStatus::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudSaveStatus::GetMessageMap'::`2'::s_pMap;
  `CHudSaveStatus::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudSaveStatus");
  `CHudSaveStatus::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010FC70
// Name: public: virtual struct PanelAnimationMap __near * CHudSaveStatus::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudSaveStatus::GetAnimMap(CHudSaveStatus *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudSaveStatus");
}

//------------------------------------------------------------------------------
// Address: 0x1010FC80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudSaveStatus::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudSaveStatus::GetKBMap(CHudSaveStatus *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudSaveStatus::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudSaveStatus::GetKBMap'::`2'::s_pMap;
  `CHudSaveStatus::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudSaveStatus");
  `CHudSaveStatus::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010FCF0
// Name: protected: virtual void CHudSaveStatus::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudSaveStatus::ApplySchemeSettings(CHudSaveStatus *this, vgui::IScheme *pScheme)
{
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v4; // eax
  void *v5; // eax
  vgui::Panel *v6; // eax
  void *v7; // eax
  const char *v8; // eax
  const char *v9; // edi

  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  ((void (__thiscall *)(CHudSaveStatus *, const char *, _DWORD, _DWORD, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[11].SetActive)(
    a1: this,
    a2: "resource/ui/hud_saving.res",
    a3: 0,
    a4: 0,
    a5: 0);
  ChildByName = vgui::Panel::FindChildByName((vgui::Panel *)this, childName: "SavingIcon", recurseDown: false);
  this->m_pSizer = (vgui::CSizerBase *)__RTDynamicCast(
                                         inptr: ChildByName,
                                         VfDelta: 0,
                                         SrcType: &vgui::Panel `RTTI Type Descriptor',
                                         TargetType: &vgui::ImagePanel `RTTI Type Descriptor',
                                         isReference: 0);
  v4 = vgui::Panel::FindChildByName((vgui::Panel *)this, childName: "SavingLabel", recurseDown: false);
  v5 = __RTDynamicCast(
         inptr: v4,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::Label `RTTI Type Descriptor',
         isReference: 0);
  *(_DWORD *)&this->vgui::EditablePanel::m_RegisterClass = v5;
  if ( v5 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v5 + 132))(a1: v5, a2: 0);
  v6 = vgui::Panel::FindChildByName((vgui::Panel *)this, childName: "SavedLabel", recurseDown: false);
  v7 = __RTDynamicCast(
         inptr: v6,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::Label `RTTI Type Descriptor',
         isReference: 0);
  *(_DWORD *)&this->m_OnCurrentDefaultButtonSet_register = v7;
  if ( v7 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v7 + 132))(a1: v7, a2: 0);
  if ( BYTE1(this->m_NavGroup._currentDefaultButton.m_iPanelID) != 0 )
  {
    v8 = "#PORTAL2_Hud_SavingProfile";
    v9 = "#PORTAL2_Hud_ProfileSaved";
  }
  else
  {
    v8 = "#PORTAL2_Hud_SavingGame";
    v9 = "#PORTAL2_Hud_GameSaved";
  }
  if ( *(_DWORD *)&this->vgui::EditablePanel::m_RegisterClass != 0 )
    (*(void (__thiscall **)(_DWORD, const char *))(**(_DWORD **)&this->vgui::EditablePanel::m_RegisterClass + 848))(
      a1: *(_DWORD *)&this->vgui::EditablePanel::m_RegisterClass,
      a2: v8);
  if ( *(_DWORD *)&this->m_OnCurrentDefaultButtonSet_register != 0 )
    (*(void (__thiscall **)(_DWORD, const char *))(**(_DWORD **)&this->m_OnCurrentDefaultButtonSet_register + 848))(
      a1: *(_DWORD *)&this->m_OnCurrentDefaultButtonSet_register,
      a2: v9);
  ((void (__thiscall *)(CHudSaveStatus *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].OnSplitScreenStateChanged)(
    a1: this,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1010FE30
// Name: protected: virtual bool CHudSaveStatus::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudSaveStatus::ShouldDraw(CHudSaveStatus *this)
{
  bool v2; // bl
  vgui::CTreeViewListControl *v3; // ecx
  vgui::Label *m_pSavingLabel; // ecx
  vgui::Label *m_pSavedLabel; // ecx
  bool result; // al
  int v7; // [esp+0h] [ebp-8h]

  v2 = false;
  if ( this->m_flSaveStartedTime != 0.0 )
    v2 = this->m_flSaveStartedTime + 1.0 > _Plat_FloatTime(a1: v7);
  if ( engine->IsSaveInProgress(this: engine) && !engine->IsAutoSaveDangerousInProgress(this: engine) )
  {
    C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v3);
    v2 = true;
  }
  if ( this->m_bNeedsDraw != v2 )
  {
    this->m_bNeedsDraw = v2;
    if ( v2 )
    {
      if ( this->m_flSaveStartedTime == 0.0 )
        this->m_flSaveStartedTime = _Plat_FloatTime(a1: v7);
    }
    else
    {
      this->m_flSaveStartedTime = 0.0;
    }
    m_pSavingLabel = this->m_pSavingLabel;
    if ( m_pSavingLabel != nullptr )
      m_pSavingLabel->SetVisible(this: m_pSavingLabel, a2: this->m_bNeedsDraw);
    m_pSavedLabel = this->m_pSavedLabel;
    if ( m_pSavedLabel != nullptr )
      m_pSavedLabel->SetVisible(this: m_pSavedLabel, a2: !this->m_bNeedsDraw);
    if ( this->m_bNeedsDraw )
    {
      this->m_flFadeOutTime = 0.0;
    }
    else if ( this->m_flFadeOutTime == 0.0 )
    {
      this->m_flFadeOutTime = _Plat_FloatTime(a1: v7);
    }
  }
  if ( this->m_flFadeOutTime != 0.0 && this->m_flFadeOutTime + 1.0 > _Plat_FloatTime(a1: v7) )
    v2 = true;
  if ( CHudElement::ShouldDraw(this) != 0 )
    return v2;
  result = false;
  if ( !this->m_bNeedsDraw && this->m_flFadeOutTime != 0.0 )
    this->m_flFadeOutTime = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010FFC0
// Name: Create_CHudSaveStatus
// Source: json
//------------------------------------------------------------------------------
CHudSaveStatus *__cdecl Create_CHudSaveStatus()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 468);
  memset(dst: v0, value: 0, count: 0x1D4u);
  if ( v0 != nullptr )
    return CHudSaveStatus::CHudSaveStatus(this: (CHudSaveStatus *)v0, pElementName: "CHudSaveStatus");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10110000
// Name: protected: virtual void CHudSaveStatus::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudSaveStatus::OnThink(CHudSaveStatus *this)
{
  double v2; // st7
  vgui::CSizerBase *m_pSizer; // ecx
  int Frame; // eax
  float v5; // xmm3_4
  vgui::FocusNavGroup_vtbl *v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // [esp+0h] [ebp-8h]
  float timea; // [esp+4h] [ebp-4h]
  float time; // [esp+4h] [ebp-4h]

  if ( this->m_pSizer != nullptr )
  {
    v2 = _Plat_FloatTime(a1: v9);
    if ( v2 > *(float *)&this->vgui::EditablePanel::_buildGroup + 0.1 )
    {
      m_pSizer = this->m_pSizer;
      timea = v2;
      *(float *)&this->vgui::EditablePanel::_buildGroup = timea;
      Frame = vgui::ImagePanel::GetFrame(this: (vgui::Slider *)m_pSizer);
      vgui::ImagePanel::SetFrame(this: (vgui::ImagePanel *)this->m_pSizer, nFrame: Frame + 1);
    }
  }
  v5 = 1.0;
  if ( *(float *)&this->m_NavGroup.vgui::EditablePanel::__vftable != 0.0 )
  {
    time = _Plat_FloatTime(a1: v9);
    v5 = 1.0;
    v6 = this->m_NavGroup.vgui::EditablePanel::__vftable;
    v7 = *(float *)&v6 + 1.0;
    if ( *(float *)&v6 == (float)(*(float *)&v6 + 1.0) )
    {
      if ( (float)(time - v7) >= 0.0 )
        v5 = 0.0;
    }
    else
    {
      v8 = (float)(time - *(float *)&v6) / (float)(v7 - *(float *)&v6);
      if ( v8 >= 0.0 )
      {
        if ( v8 > 1.0 )
          v8 = 1.0;
      }
      else
      {
        v8 = 0.0;
      }
      v5 = 1.0 - v8;
    }
  }
  vgui::Panel::SetAlpha((vgui::Panel *)this, alpha: (int)(float)(v5 * 255.0));
}
