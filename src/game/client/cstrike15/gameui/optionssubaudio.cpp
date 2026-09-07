// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubaudio.cpp
// Functions: 24
// ============================================================

#include "game\client\cstrike15\gameui\optionssubaudio.h"

//------------------------------------------------------------------------------
// Address: 0x101D8410
// Name: public: static char const __near * COptionsSubAudio::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubAudio::GetPanelClassName()
{
  return "COptionsSubAudio";
}

//------------------------------------------------------------------------------
// Address: 0x101D8420
// Name: public: static char const __near * COptionsSubAudioThirdPartyCreditsDlg::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubAudioThirdPartyCreditsDlg::GetPanelClassName()
{
  return "COptionsSubAudioThirdPartyCreditsDlg";
}

//------------------------------------------------------------------------------
// Address: 0x101D8430
// Name: private: virtual void COptionsSubAudio::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubAudio::OnTextChanged(COptionsSubAudio *this)
{
  this->OnControlModified(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D8440
// Name: public: virtual void COptionsSubAudio::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COptionsSubAudio::OnApplyChanges(COptionsSubAudio *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // esi
  int GameUIActiveSplitScreenPlayerSlot; // eax
  int v6; // eax
  KeyValues *ActiveItemUserData; // eax
  int Int; // esi
  int v9; // eax
  KeyValues *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int ActiveItem; // eax
  KeyValues *ItemUserData; // eax
  ELanguage v20; // eax
  vgui::QueryBox *v21; // esi
  vgui::Panel *v22; // eax
  int v23; // eax
  vgui::Panel *v24; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  vgui::Panel *v28; // eax
  int v29; // eax
  vgui::QueryBox_vtbl *v30; // edi
  int v31; // eax
  char cmd[64]; // [esp+8h] [ebp-90h] BYREF
  CGameUIConVarRef snd_surround_speakers; // [esp+48h] [ebp-50h] BYREF
  CGameUIConVarRef dsp_enhance_stereo; // [esp+58h] [ebp-40h] BYREF
  CGameUIConVarRef cc_subtitles; // [esp+68h] [ebp-30h] BYREF
  CGameUIConVarRef dsp_slow_cpu; // [esp+78h] [ebp-20h] BYREF
  CGameUIConVarRef Snd_PitchQuality; // [esp+88h] [ebp-10h] BYREF

  CCvarSlider::ApplyChanges(this: this->m_pSFXSlider);
  CCvarSlider::ApplyChanges(this: this->m_pMusicSlider);
  CGameUIConVarRef::CGameUIConVarRef(this: &cc_subtitles, pName: "cc_subtitles");
  v3 = vgui::ComboBox::GetActiveItem(this: this->m_pCloseCaptionCombo) - 1;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
    {
      v4 = 1;
      GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
      cc_subtitles.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar->SetValue_2(
        this: cc_subtitles.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar,
        a2: 1);
      goto LABEL_7;
    }
    v4 = 0;
  }
  else
  {
    v4 = 1;
  }
  v6 = GetGameUIActiveSplitScreenPlayerSlot();
  cc_subtitles.m_Info[v6].m_pConVar->SetValue_2(this: cc_subtitles.m_Info[v6].m_pConVar, a2: 0);
LABEL_7:
  V_snprintf(pDest: cmd, maxLen: 0x40u, pFormat: "closecaption %i\n", v4);
  ((void (__thiscall *)(IVEngineClient *, char *, int))engine->ClientCmd_Unrestricted)(a1: engine, a2: cmd, a3: a2);
  CGameUIConVarRef::CGameUIConVarRef(this: &snd_surround_speakers, pName: "Snd_Surround_Speakers");
  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pSpeakerSetupCombo);
  Int = KeyValues::GetInt(this: ActiveItemUserData, keyName: "speakers", defaultValue: 0);
  v9 = GetGameUIActiveSplitScreenPlayerSlot();
  snd_surround_speakers.m_Info[v9].m_pConVar->SetValue_2(this: snd_surround_speakers.m_Info[v9].m_pConVar, a2: Int);
  CGameUIConVarRef::CGameUIConVarRef(this: &Snd_PitchQuality, pName: "Snd_PitchQuality");
  CGameUIConVarRef::CGameUIConVarRef(this: &dsp_slow_cpu, pName: "dsp_slow_cpu");
  v10 = vgui::ComboBox::GetActiveItemUserData(this: this->m_pSoundQualityCombo);
  v11 = KeyValues::GetInt(this: v10, keyName: "quality", defaultValue: 0);
  if ( v11 != 0 )
  {
    if ( v11 != 1 )
    {
      v12 = GetGameUIActiveSplitScreenPlayerSlot();
      dsp_slow_cpu.m_Info[v12].m_pConVar->SetValue_2(this: dsp_slow_cpu.m_Info[v12].m_pConVar, a2: 0);
      v13 = GetGameUIActiveSplitScreenPlayerSlot();
      Snd_PitchQuality.m_Info[v13].m_pConVar->SetValue_2(this: Snd_PitchQuality.m_Info[v13].m_pConVar, a2: 1);
      goto LABEL_13;
    }
    v14 = GetGameUIActiveSplitScreenPlayerSlot();
    dsp_slow_cpu.m_Info[v14].m_pConVar->SetValue_2(this: dsp_slow_cpu.m_Info[v14].m_pConVar, a2: 0);
  }
  else
  {
    v15 = GetGameUIActiveSplitScreenPlayerSlot();
    dsp_slow_cpu.m_Info[v15].m_pConVar->SetValue_2(this: dsp_slow_cpu.m_Info[v15].m_pConVar, a2: 1);
  }
  v16 = GetGameUIActiveSplitScreenPlayerSlot();
  Snd_PitchQuality.m_Info[v16].m_pConVar->SetValue_2(this: Snd_PitchQuality.m_Info[v16].m_pConVar, a2: 0);
LABEL_13:
  CGameUIConVarRef::CGameUIConVarRef(this: &dsp_enhance_stereo, pName: "dsp_enhance_stereo");
  v17 = GetGameUIActiveSplitScreenPlayerSlot();
  ((void (__thiscall *)(IConVar *))dsp_enhance_stereo.m_Info[v17].m_pConVar->SetValue_2)(a1: dsp_enhance_stereo.m_Info[v17].m_pConVar);
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pSpokenLanguageCombo);
  ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pSpokenLanguageCombo, itemID: ActiveItem);
  if ( ItemUserData != nullptr )
    v20 = KeyValues::GetInt(this: ItemUserData, keyName: "language", defaultValue: 0);
  else
    v20 = k_Lang_English;
  if ( v20 != this->m_nCurrentAudioLanguage )
  {
    COptionsSubAudio::m_pchUpdatedAudioLanguage = GetLanguageShortName(eLang: v20);
    v21 = (vgui::QueryBox *)MemAlloc_Alloc(nSize: 0x244u);
    if ( v21 != nullptr )
    {
      v22 = this->GetParent(this);
      v23 = (int)v22->GetParent(this: v22);
      v24 = (vgui::Panel *)(*(int (__thiscall **)(int))(*(_DWORD *)v23 + 156))(a1: v23);
      Box = vgui::QueryBox::QueryBox(
              this: v21,
              title: "#GameUI_ChangeLanguageRestart_Title",
              queryText: "#GameUI_ChangeLanguageRestart_Info",
              parent: v24);
      if ( Box != nullptr )
      {
        v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v26 != nullptr )
          v27 = KeyValues::KeyValues(
                  this: v26,
                  setName: "Command",
                  firstKey: "command",
                  firstValue: "RestartWithNewLanguage");
        else
          v27 = nullptr;
        vgui::QueryBox::SetOKCommand(this: Box, keyValues: v27);
        Box->SetOKButtonText_2(this: Box, a2: "#GameUI_ChangeLanguageRestart_OkButton");
        vgui::QueryBox::SetCancelButtonText(this: Box, buttonText: "#GameUI_ChangeLanguageRestart_CancelButton");
        v28 = this->GetParent(this);
        v29 = (int)v28->GetParent(this: v28);
        v30 = Box->__vftable;
        v31 = (*(int (__thiscall **)(int))(*(_DWORD *)v29 + 156))(a1: v29);
        v30->AddActionSignalTarget_2(this: Box, a2: (vgui::Panel *)v31);
        Box->DoModal_2(this: Box, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8700
// Name: public: virtual void COptionsSubAudio::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubAudio::OnCommand(COptionsSubAudio *this, const char *command)
{
  vgui::QueryBox *v3; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( _V_stricmp(s1: command, s2: "TestSpeakers") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "ShowThirdPartyAudioCredits") == 0 )
      this->OpenThirdPartySoundCreditsDialog(this);
    vgui::Panel::OnCommand(this, command);
  }
  else if ( engine->IsConnected(this: engine)
         && (v3 = (vgui::QueryBox *)MemAlloc_Alloc(nSize: 0x244u)) != nullptr
         && (Box = vgui::QueryBox::QueryBox(
                     this: v3,
                     title: "#GameUI_TestSpeakersWarning_Title",
                     queryText: "#GameUI_TestSpeakersWarning_Info",
                     parent: nullptr)) != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "RunTestSpeakers");
    else
      v6 = nullptr;
    vgui::QueryBox::SetOKCommand(this: Box, keyValues: v6);
    Box->SetOKButtonText_2(this: Box, a2: "#GameUI_TestSpeakersWarning_OkButton");
    vgui::QueryBox::SetCancelButtonText(this: Box, buttonText: "#GameUI_TestSpeakersWarning_CancelButton");
    Box->AddActionSignalTarget_2(this: Box, a2: this);
    Box->DoModal_2(this: Box, a2: nullptr);
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    this->RunTestSpeakers(this);
    vgui::Panel::OnCommand(this, command);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8820
// Name: private: virtual void COptionsSubAudio::RunTestSpeakers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubAudio::RunTestSpeakers(COptionsSubAudio *this)
{
  engine->ClientCmd_Unrestricted(
    this: engine,
    a2: "disconnect\n"
    "wait\n"
    "wait\n"
    "sv_lan 1\n"
    "setmaster enable\n"
    "maxplayers 1\n"
    "\n"
    "hostname \"Speaker Test\"\n"
    "progress_enable\n"
    "map test_speakers\n");
}

//------------------------------------------------------------------------------
// Address: 0x101D8840
// Name: protected: virtual void COptionsSubAudioThirdPartyCreditsDlg::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubAudioThirdPartyCreditsDlg::ApplySchemeSettings(
        COptionsSubAudioThirdPartyCreditsDlg *this,
        vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(
    this,
    a2: "resource/OptionsSubAudioThirdPartyDlg.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D8880
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubAudio::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubAudio::GetMessageMap(COptionsSubAudio *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubAudio::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubAudio::GetMessageMap'::`2'::s_pMap;
  `COptionsSubAudio::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudio");
  `COptionsSubAudio::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D88B0
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubAudio::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubAudio::GetAnimMap(COptionsSubAudio *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubAudio");
}

//------------------------------------------------------------------------------
// Address: 0x101D88C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubAudio::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubAudio::GetKBMap(COptionsSubAudio *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubAudio::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubAudio::GetKBMap'::`2'::s_pMap;
  `COptionsSubAudio::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubAudio");
  `COptionsSubAudio::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D8920
// Name: public: COptionsSubAudioThirdPartyCreditsDlg::COptionsSubAudioThirdPartyCreditsDlg(unsigned int)
// Source: json
//------------------------------------------------------------------------------
COptionsSubAudioThirdPartyCreditsDlg *__thiscall COptionsSubAudioThirdPartyCreditsDlg::COptionsSubAudioThirdPartyCreditsDlg(
        COptionsSubAudioThirdPartyCreditsDlg *this,
        unsigned int hParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ISchemeManager *v6; // edi
  vgui::ISchemeManager *v7; // ebx
  unsigned int Scheme; // eax
  unsigned int v9; // eax
  int v10; // eax
  int v12; // [esp-8h] [ebp-1Ch]
  vgui::ISchemeManager_vtbl *v13; // [esp+Ch] [ebp-8h]
  vgui::ISchemeManager_vtbl *v14; // [esp+10h] [ebp-4h]

  vgui::Frame::Frame(this, parent: nullptr, panelName: nullptr, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (COptionsSubAudioThirdPartyCreditsDlg_vtbl *)&COptionsSubAudioThirdPartyCreditsDlg::`vftable';
  if ( `COptionsSubAudioThirdPartyCreditsDlg::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubAudioThirdPartyCreditsDlg::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudioThirdPartyCreditsDlg");
    v3->pfnClassName = COptionsSubAudioThirdPartyCreditsDlg::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COptionsSubAudioThirdPartyCreditsDlg::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubAudioThirdPartyCreditsDlg::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubAudioThirdPartyCreditsDlg");
    v4->pfnClassName = COptionsSubAudioThirdPartyCreditsDlg::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COptionsSubAudioThirdPartyCreditsDlg::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubAudioThirdPartyCreditsDlg::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubAudioThirdPartyCreditsDlg");
    v5->pfnClassName = COptionsSubAudioThirdPartyCreditsDlg::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Panel::SetProportional(this, state: true);
  vgui::Frame::SetTitle(this, title: "#GameUI_ThirdPartyAudio_Title", surfaceTitle: true);
  v6 = g_pVGuiSchemeManager;
  v7 = g_pVGuiSchemeManager;
  v13 = g_pVGuiSchemeManager->__vftable;
  v14 = g_pVGuiSchemeManager->__vftable;
  Scheme = vgui::Panel::GetScheme(this);
  v12 = ((int (__thiscall *)(vgui::ISchemeManager *, unsigned int))v14->GetProportionalScaledValueEx)(
          a1: v6,
          a2: Scheme);
  v9 = vgui::Panel::GetScheme(this);
  v10 = ((int (__thiscall *)(vgui::ISchemeManager *, unsigned int, int, int))v13->GetProportionalScaledValueEx)(
          a1: v7,
          a2: v9,
          a3: 500,
          a4: v12);
  vgui::Panel::SetSize(this, wide: v10, tall: 200);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D8A60
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubAudioThirdPartyCreditsDlg::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubAudioThirdPartyCreditsDlg::GetMessageMap(
        COptionsSubAudioThirdPartyCreditsDlg *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubAudioThirdPartyCreditsDlg::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubAudioThirdPartyCreditsDlg::GetMessageMap'::`2'::s_pMap;
  `COptionsSubAudioThirdPartyCreditsDlg::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudioThirdPartyCreditsDlg");
  `COptionsSubAudioThirdPartyCreditsDlg::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D8A90
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubAudioThirdPartyCreditsDlg::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubAudioThirdPartyCreditsDlg::GetAnimMap(
        COptionsSubAudioThirdPartyCreditsDlg *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubAudioThirdPartyCreditsDlg");
}

//------------------------------------------------------------------------------
// Address: 0x101D8AA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubAudioThirdPartyCreditsDlg::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubAudioThirdPartyCreditsDlg::GetKBMap(
        COptionsSubAudioThirdPartyCreditsDlg *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubAudioThirdPartyCreditsDlg::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubAudioThirdPartyCreditsDlg::GetKBMap'::`2'::s_pMap;
  `COptionsSubAudioThirdPartyCreditsDlg::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubAudioThirdPartyCreditsDlg");
  `COptionsSubAudioThirdPartyCreditsDlg::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D8AD0
// Name: public: virtual void COptionsSubAudio::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COptionsSubAudio::OnResetData(COptionsSubAudio *this@<ecx>, int a2@<ebx>)
{
  CCvarSlider *m_pSFXSlider; // ecx
  bool v4; // zf
  void (__thiscall *ActivateItem)(vgui::ComboBox *, int); // eax
  int m_nValue; // ebx
  int v7; // edi
  KeyValues *ItemUserData; // eax
  int v9; // ebx
  int i; // edi
  KeyValues *v11; // eax
  ISteamApps *m_pSteamApps; // ecx
  char *v13; // eax
  char *v14; // eax
  int j; // ebx
  ELanguage v16; // edi
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  vgui::ComboBox_vtbl *v19; // edi
  char *LanguageVGUILocalization; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  vgui::ComboBox_vtbl *v23; // edi
  char *v24; // eax
  int v25; // edi
  KeyValues *v26; // eax
  KeyValues *v27; // [esp-8h] [ebp-2B0h]
  KeyValues *v28; // [esp-8h] [ebp-2B0h]
  char szAvailableLanguages[512]; // [esp+8h] [ebp-2A0h] BYREF
  char szCurrentLanguage[52]; // [esp+208h] [ebp-A0h] BYREF
  CGameUIConVarRef snd_surround_speakers; // [esp+23Ch] [ebp-6Ch] BYREF
  CGameUIConVarRef closecaption; // [esp+24Ch] [ebp-5Ch] BYREF
  CGameUIConVarRef cc_subtitles; // [esp+25Ch] [ebp-4Ch] BYREF
  CGameUIConVarRef Snd_PitchQuality; // [esp+26Ch] [ebp-3Ch] BYREF
  CGameUIConVarRef dsp_slow_cpu; // [esp+27Ch] [ebp-2Ch] BYREF
  CSplitString languagesList; // [esp+28Ch] [ebp-1Ch] BYREF
  ELanguage languageCode; // [esp+2A4h] [ebp-4h]

  m_pSFXSlider = this->m_pSFXSlider;
  this->m_bRequireRestart = false;
  CCvarSlider::Reset(this: m_pSFXSlider);
  CCvarSlider::Reset(this: this->m_pMusicSlider);
  CGameUIConVarRef::CGameUIConVarRef(this: &closecaption, pName: "closecaption");
  CGameUIConVarRef::CGameUIConVarRef(this: &cc_subtitles, pName: "cc_subtitles");
  if ( closecaption.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue != 0 )
  {
    v4 = cc_subtitles.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue == 0;
    ActivateItem = this->m_pCloseCaptionCombo->ActivateItem;
    if ( v4 )
      ((void (__stdcall *)(int))ActivateItem)(a1: 1);
    else
      ((void (__stdcall *)(int))ActivateItem)(a1: 2);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->m_pCloseCaptionCombo->ActivateItem)(a1: 0);
  }
  CGameUIConVarRef::CGameUIConVarRef(this: &snd_surround_speakers, pName: "Snd_Surround_Speakers");
  m_nValue = snd_surround_speakers.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue;
  v7 = 0;
  if ( ((int (__thiscall *)(vgui::ComboBox *, int))this->m_pSpeakerSetupCombo->GetItemCount)(
         a1: this->m_pSpeakerSetupCombo,
         a2) > 0 )
  {
    do
    {
      ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pSpeakerSetupCombo, itemID: v7);
      if ( ItemUserData != nullptr
        && KeyValues::GetInt(this: ItemUserData, keyName: "speakers", defaultValue: 0) == m_nValue )
      {
        this->m_pSpeakerSetupCombo->ActivateItem(this: this->m_pSpeakerSetupCombo, a2: v7);
      }
      ++v7;
    }
    while ( v7 < this->m_pSpeakerSetupCombo->GetItemCount(this: this->m_pSpeakerSetupCombo) );
  }
  CGameUIConVarRef::CGameUIConVarRef(this: &Snd_PitchQuality, pName: "Snd_PitchQuality");
  CGameUIConVarRef::CGameUIConVarRef(this: &dsp_slow_cpu, pName: "dsp_slow_cpu");
  v9 = dsp_slow_cpu.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue == 0;
  if ( Snd_PitchQuality.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue != 0 )
    v9 = 2;
  for ( i = 0; i < this->m_pSoundQualityCombo->GetItemCount(this: this->m_pSoundQualityCombo); ++i )
  {
    v11 = vgui::ComboBox::GetItemUserData(this: this->m_pSoundQualityCombo, itemID: i);
    if ( v11 != nullptr && KeyValues::GetInt(this: v11, keyName: "quality", defaultValue: 0) == v9 )
      this->m_pSoundQualityCombo->ActivateItem(this: this->m_pSoundQualityCombo, a2: i);
  }
  memset(szCurrentLanguage, 0, 50);
  memset(szAvailableLanguages, 0, sizeof(szAvailableLanguages));
  ((void (__thiscall *)(IVEngineClient *, char *))engine->GetUILanguage)(a1: engine, a2: szCurrentLanguage);
  m_pSteamApps = steamapicontext->m_pSteamApps;
  if ( m_pSteamApps != nullptr )
  {
    v13 = (char *)m_pSteamApps->GetCurrentGameLanguage(this: m_pSteamApps);
    V_strncpy(pDest: szCurrentLanguage, pSrc: v13, maxLen: 50);
    v14 = (char *)steamapicontext->m_pSteamApps->GetAvailableGameLanguages(this: steamapicontext->m_pSteamApps);
    V_strncpy(pDest: szAvailableLanguages, pSrc: v14, maxLen: 512);
  }
  this->m_nCurrentAudioLanguage = PchLanguageToELanguage(pchShortName: szCurrentLanguage);
  if ( _V_strlen(str: szAvailableLanguages) != 0 )
  {
    CSplitString::CSplitString(this: &languagesList, pString: szAvailableLanguages, pSeparator: ",");
    for ( j = 0; j < languagesList.m_Size; ++j )
    {
      v16 = PchLanguageToELanguage(pchShortName: languagesList.m_Memory.m_pMemory[j]);
      languageCode = v16;
      v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v17 != nullptr )
        v18 = KeyValues::KeyValues(this: v17, setName: "Audio Languages", firstKey: "language", firstValue: v16);
      else
        v18 = nullptr;
      v19 = this->m_pSpokenLanguageCombo->__vftable;
      v27 = v18;
      LanguageVGUILocalization = GetLanguageVGUILocalization(eLang: languageCode);
      v19->AddItem_2(this: this->m_pSpokenLanguageCombo, a2: LanguageVGUILocalization, a3: v27);
    }
    CSplitString::~CSplitString(this: &languagesList);
  }
  else
  {
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      v22 = KeyValues::KeyValues(
              this: v21,
              setName: "Audio Languages",
              firstKey: "language",
              firstValue: this->m_nCurrentAudioLanguage);
    else
      v22 = nullptr;
    v23 = this->m_pSpokenLanguageCombo->__vftable;
    v28 = v22;
    v24 = GetLanguageVGUILocalization(eLang: this->m_nCurrentAudioLanguage);
    v23->AddItem_2(this: this->m_pSpokenLanguageCombo, a2: v24, a3: v28);
  }
  v25 = 0;
  if ( this->m_pSpokenLanguageCombo->GetItemCount(this: this->m_pSpokenLanguageCombo) > 0 )
  {
    while ( 1 )
    {
      v26 = vgui::ComboBox::GetItemUserData(this: this->m_pSpokenLanguageCombo, itemID: v25);
      if ( v26 != nullptr
        && KeyValues::GetInt(this: v26, keyName: "language", defaultValue: 0) == this->m_nCurrentAudioLanguage )
      {
        break;
      }
      if ( ++v25 >= this->m_pSpokenLanguageCombo->GetItemCount(this: this->m_pSpokenLanguageCombo) )
        return;
    }
    this->m_pSpokenLanguageCombo->ActivateItem(this: this->m_pSpokenLanguageCombo, a2: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8E90
// Name: private: virtual void COptionsSubAudio::OpenThirdPartySoundCreditsDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubAudio::OpenThirdPartySoundCreditsDialog(COptionsSubAudio *this)
{
  COptionsSubAudioThirdPartyCreditsDlg *v2; // edi
  unsigned int v3; // eax
  COptionsSubAudioThirdPartyCreditsDlg *v4; // eax
  vgui::Panel *v5; // eax

  if ( vgui::PHandle::Get(this: &this->m_OptionsSubAudioThirdPartyCreditsDlg) == nullptr )
  {
    v2 = (COptionsSubAudioThirdPartyCreditsDlg *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v2 != nullptr )
    {
      v3 = this->GetVParent(this);
      v4 = COptionsSubAudioThirdPartyCreditsDlg::COptionsSubAudioThirdPartyCreditsDlg(this: v2, hParent: v3);
    }
    else
    {
      v4 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_OptionsSubAudioThirdPartyCreditsDlg, pPanel: v4);
  }
  v5 = vgui::PHandle::Get(this: &this->m_OptionsSubAudioThirdPartyCreditsDlg);
  v5->__vftable[1].OnTick(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101D8F00
// Name: public: static void COptionsSubAudio::PanelMessageFunc_OnControlModified::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubAudio::PanelMessageFunc_OnControlModified::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubAudio::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded )
  {
    `COptionsSubAudio::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudio");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8F90
// Name: public: static void COptionsSubAudio::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubAudio::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubAudio::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COptionsSubAudio::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudio");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9020
// Name: public: static void COptionsSubAudio::PanelMessageFunc_RunTestSpeakers::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubAudio::PanelMessageFunc_RunTestSpeakers::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubAudio::PanelMessageFunc_RunTestSpeakers::InitVar'::`2'::bAdded )
  {
    `COptionsSubAudio::PanelMessageFunc_RunTestSpeakers::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudio");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RunTestSpeakers";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D90B0
// Name: public: static void COptionsSubAudio::PanelMessageFunc_OpenThirdPartySoundCreditsDialog::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubAudio::PanelMessageFunc_OpenThirdPartySoundCreditsDialog::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubAudio::PanelMessageFunc_OpenThirdPartySoundCreditsDialog::InitVar'::`2'::bAdded )
  {
    `COptionsSubAudio::PanelMessageFunc_OpenThirdPartySoundCreditsDialog::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudio");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OpenThirdPartySoundCreditsDialog";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9140
// Name: public: COptionsSubAudio::COptionsSubAudio(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubAudio *__thiscall COptionsSubAudio::COptionsSubAudio(COptionsSubAudio *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CCvarSlider *v6; // eax
  CCvarSlider *v7; // eax
  CCvarSlider *v8; // eax
  CCvarSlider *v9; // eax
  vgui::ComboBox *v10; // eax
  vgui::ComboBox *v11; // eax
  vgui::ComboBox *v12; // eax
  vgui::ComboBox *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::ComboBox *v20; // eax
  vgui::ComboBox *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  vgui::ComboBox *v32; // eax
  vgui::ComboBox *v33; // eax
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: nullptr);
  this->__vftable = (COptionsSubAudio_vtbl *)&COptionsSubAudio::`vftable';
  if ( `COptionsSubAudio::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubAudio::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubAudio");
    v3->pfnClassName = COptionsSubAudio::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubAudio::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubAudio::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubAudio");
    v4->pfnClassName = COptionsSubAudio::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubAudio::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubAudio::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubAudio");
    v5->pfnClassName = COptionsSubAudio::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubAudio::PanelMessageFunc_OnControlModified::InitVar();
  COptionsSubAudio::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  COptionsSubAudio::PanelMessageFunc_RunTestSpeakers::InitVar();
  COptionsSubAudio::PanelMessageFunc_OpenThirdPartySoundCreditsDialog::InitVar();
  this->m_OptionsSubAudioThirdPartyCreditsDlg.m_iPanelID = -1;
  v6 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v6 != nullptr )
    v7 = CCvarSlider::CCvarSlider(
           this: v6,
           parent: this,
           panelName: "SFXSlider",
           caption: "#GameUI_SoundEffectVolume",
           minValue: 0.0,
           maxValue: 1.0,
           cvarname: "volume",
           bAllowOutOfRange: false);
  else
    v7 = nullptr;
  this->m_pSFXSlider = v7;
  v8 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v8 != nullptr )
    v9 = CCvarSlider::CCvarSlider(
           this: v8,
           parent: this,
           panelName: "MusicSlider",
           caption: "#GameUI_MusicVolume",
           minValue: 0.0,
           maxValue: 1.0,
           cvarname: "Snd_MusicVolume",
           bAllowOutOfRange: false);
  else
    v9 = nullptr;
  this->m_pMusicSlider = v9;
  v10 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v10 != nullptr )
    v11 = vgui::ComboBox::ComboBox(
            this: v10,
            parent: this,
            panelName: "CloseCaptionCheck",
            numLines: 6,
            allowEdit: false);
  else
    v11 = nullptr;
  this->m_pCloseCaptionCombo = v11;
  v11->AddItem_2(this: v11, a2: "#GameUI_NoClosedCaptions", a3: nullptr);
  this->m_pCloseCaptionCombo->AddItem_2(
    this: this->m_pCloseCaptionCombo,
    a2: "#GameUI_SubtitlesAndSoundEffects",
    a3: nullptr);
  this->m_pCloseCaptionCombo->AddItem_2(this: this->m_pCloseCaptionCombo, a2: "#GameUI_Subtitles", a3: nullptr);
  v12 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v12 != nullptr )
    v13 = vgui::ComboBox::ComboBox(this: v12, parent: this, panelName: "SoundQuality", numLines: 6, allowEdit: false);
  else
    v13 = nullptr;
  this->m_pSoundQualityCombo = v13;
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "SoundQuality", firstKey: "quality", firstValue: 2);
  else
    v15 = nullptr;
  this->m_pSoundQualityCombo->AddItem_2(this: this->m_pSoundQualityCombo, a2: "#GameUI_High", a3: v15);
  v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v16 != nullptr )
    v17 = KeyValues::KeyValues(this: v16, setName: "SoundQuality", firstKey: "quality", firstValue: 1);
  else
    v17 = nullptr;
  this->m_pSoundQualityCombo->AddItem_2(this: this->m_pSoundQualityCombo, a2: "#GameUI_Medium", a3: v17);
  v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v18 != nullptr )
    v19 = KeyValues::KeyValues(this: v18, setName: "SoundQuality", firstKey: "quality", firstValue: 0);
  else
    v19 = nullptr;
  this->m_pSoundQualityCombo->AddItem_2(this: this->m_pSoundQualityCombo, a2: "#GameUI_Low", a3: v19);
  v20 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v20 != nullptr )
    v21 = vgui::ComboBox::ComboBox(this: v20, parent: this, panelName: "SpeakerSetup", numLines: 6, allowEdit: false);
  else
    v21 = nullptr;
  this->m_pSpeakerSetupCombo = v21;
  v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v22 != nullptr )
    v23 = KeyValues::KeyValues(this: v22, setName: "SpeakerSetup", firstKey: "speakers", firstValue: 0);
  else
    v23 = nullptr;
  this->m_pSpeakerSetupCombo->AddItem_2(this: this->m_pSpeakerSetupCombo, a2: "#GameUI_Headphones", a3: v23);
  v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v24 != nullptr )
    v25 = KeyValues::KeyValues(this: v24, setName: "SpeakerSetup", firstKey: "speakers", firstValue: 2);
  else
    v25 = nullptr;
  this->m_pSpeakerSetupCombo->AddItem_2(this: this->m_pSpeakerSetupCombo, a2: "#GameUI_2Speakers", a3: v25);
  v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v26 != nullptr )
    v27 = KeyValues::KeyValues(this: v26, setName: "SpeakerSetup", firstKey: "speakers", firstValue: 4);
  else
    v27 = nullptr;
  this->m_pSpeakerSetupCombo->AddItem_2(this: this->m_pSpeakerSetupCombo, a2: "#GameUI_4Speakers", a3: v27);
  v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v28 != nullptr )
    v29 = KeyValues::KeyValues(this: v28, setName: "SpeakerSetup", firstKey: "speakers", firstValue: 5);
  else
    v29 = nullptr;
  this->m_pSpeakerSetupCombo->AddItem_2(this: this->m_pSpeakerSetupCombo, a2: "#GameUI_5Speakers", a3: v29);
  v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v30 != nullptr )
    v31 = KeyValues::KeyValues(this: v30, setName: "SpeakerSetup", firstKey: "speakers", firstValue: 7);
  else
    v31 = nullptr;
  this->m_pSpeakerSetupCombo->AddItem_2(this: this->m_pSpeakerSetupCombo, a2: "#GameUI_7Speakers", a3: v31);
  v32 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v32 != nullptr )
    v33 = vgui::ComboBox::ComboBox(
            this: v32,
            parent: this,
            panelName: "AudioSpokenLanguage",
            numLines: 6,
            allowEdit: false);
  else
    v33 = nullptr;
  this->m_pSpokenLanguageCombo = v33;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\OptionsSubAudio.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10423D60
// Name: _dynamic_initializer_for__COptionsSubAudio::m_pchUpdatedAudioLanguage__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
char *dynamic_initializer_for__COptionsSubAudio::m_pchUpdatedAudioLanguage__()
{
  char *result; // eax

  result = GetLanguageShortName(eLang: k_Lang_English);
  COptionsSubAudio::m_pchUpdatedAudioLanguage = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423D70
// Name: _dynamic_initializer_for____g_CRunGameEngine_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CRunGameEngine_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CRunGameEngine_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x10423D80
// Name: _dynamic_initializer_for____g_CreateCRunGameEngineIRunGameEngine_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCRunGameEngineIRunGameEngine_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCRunGameEngineIRunGameEngine_reg,
           fn: (void *(__cdecl *)())_CreateCRunGameEngineIRunGameEngine_interface,
           pName: "RunGameEngine005");
}
