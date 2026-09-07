// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/vgui_c4panel.cpp
// Functions: 4
// ============================================================

#include "game\client\cstrike15\vgui_c4panel.h"

//------------------------------------------------------------------------------
// Address: 0x10227CF0
// Name: public: virtual bool CC4Panel::Init(class KeyValues __near *,struct VGuiScreenInitData_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CC4Panel::Init(CSlideshowDisplayScreen *this, KeyValues *pKeyValues, VGuiScreenInitData_t *pInitData)
{
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax

  v4 = g_pVGui;
  v5 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(CSlideshowDisplayScreen *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v5->AddTickSignal)(a1: v4, a2: v6);
  return CVGuiScreenPanel::Init(this, pKeyValues, pInitData) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10227D30
// Name: public: CC4Panel::CC4Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CC4Panel *__thiscall CC4Panel::CC4Panel(CC4Panel *this, vgui::Panel *parent, const char *panelName)
{
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  int v6; // eax
  unsigned int v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax

  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v6 = ((int (__thiscall *)(IEngineVGui *, int, const char *, const char *))enginevgui->GetPanel)(
         a1: enginevgui,
         a2: 2,
         a3: "resource/C4Panel.res",
         a4: "ClientScheme");
  v7 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v4->LoadSchemeFromFileEx)(a1: v3, a2: v6);
  CVGuiScreenPanel::CVGuiScreenPanel(this, parent, panelName: "CC4Panel", hScheme: v7);
  this->__vftable = (CC4Panel_vtbl *)&CC4Panel::`vftable';
  this->m_cArmed = 0;
  this->m_cDefused = 0;
  this->m_cInvisible = 0;
  vgui::Panel::SetSize(this, wide: 10, tall: 10);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "TimerLabel", text: prType);
  else
    v9 = nullptr;
  this->m_iLastRandomInt = 0;
  this->m_pTimeLabel = v9;
  this->m_flNextDigitRandomizeTime = 0.0;
  this->m_bInitLabelColor = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10227E20
// Name: public: virtual void CC4Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4Panel::ApplySchemeSettings(CC4Panel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v3; // edi
  vgui::IScheme_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme_vtbl *v6; // ebx
  Color *v7; // eax
  Color v8; // eax
  Color v9; // [esp+Ch] [ebp-4h] BYREF

  v3 = pScheme;
  v4 = pScheme->__vftable;
  v5 = this->GetFgColor(this, result: &pScheme);
  this->m_cArmed = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v4->GetColor)(
                      a1: v3,
                      a2: &v9,
                      a3: "C4Panel_Armed",
                      a4: *v5);
  v6 = v3->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  v8 = *v6->GetColor(this: v3, result: &v9, a3: "C4Panel_Defused", a4: *v7);
  pScheme = nullptr;
  this->m_cDefused = v8;
  this->m_cInvisible = 0;
  if ( this->m_bInitLabelColor )
  {
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pTimeLabel->SetFgColor)(
      a1: this->m_pTimeLabel,
      a2: *(_DWORD *)&this->m_cArmed);
    this->m_bInitLabelColor = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227F40
// Name: public: virtual void CC4Panel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4Panel::OnTick(CC4Panel *this)
{
  float v2; // xmm0_4
  C_PlantedC4 *v3; // eax
  float m_Value; // xmm1_4
  vgui::Label *m_pTimeLabel; // ecx
  Color m_cDefused; // eax
  IUniformRandomStream *v7; // ecx
  float v8; // xmm2_4
  float v9; // xmm0_4
  int v10; // edi
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  bool v14; // cc
  int v15; // eax
  double v16; // xmm1_8
  float v17; // xmm1_4
  char buf[8]; // [esp+4h] [ebp-Ch] BYREF
  float flPercentDecoding; // [esp+Ch] [ebp-4h]

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  this->SetVisible(this, a2: true);
  v2 = 1.0;
  flPercentDecoding = 1.0;
  if ( g_PlantedC4s.m_Size > 0 )
  {
    v3 = *g_PlantedC4s.m_Memory.m_pMemory;
    if ( *g_PlantedC4s.m_Memory.m_pMemory == nullptr )
      return;
    m_Value = v3->m_flDefuseLength.m_Value;
    if ( m_Value > 0.0 )
      v2 = (float)(v3->m_flDefuseCountDown.m_Value - *(float *)(gpGlobals.m_Index + 12)) / m_Value;
    flPercentDecoding = v2;
  }
  ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pTimeLabel->SetFgColor)(
    a1: this->m_pTimeLabel,
    a2: *(_DWORD *)&this->m_cArmed);
  if ( flPercentDecoding < 0.0 )
  {
    if ( flPercentDecoding <= -0.2 )
    {
      m_pTimeLabel = this->m_pTimeLabel;
      m_cDefused = this->m_cDefused;
    }
    else
    {
      m_pTimeLabel = this->m_pTimeLabel;
      if ( (int)(float)(flPercentDecoding * 100.0) % 2 != 0 )
      {
        ((void (__thiscall *)(vgui::Label *, _DWORD))m_pTimeLabel->SetFgColor)(
          a1: m_pTimeLabel,
          a2: *(_DWORD *)&this->m_cDefused);
LABEL_13:
        this->m_pTimeLabel->SetText(this: this->m_pTimeLabel, a2: cDefuseCode);
        return;
      }
      m_cDefused = this->m_cInvisible;
    }
    m_pTimeLabel->SetFgColor(this: m_pTimeLabel, a2: m_cDefused);
    goto LABEL_13;
  }
  if ( flPercentDecoding >= 1.0 )
  {
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pTimeLabel->SetFgColor)(
      a1: this->m_pTimeLabel,
      a2: *(_DWORD *)&this->m_cArmed);
    this->m_pTimeLabel->SetText(this: this->m_pTimeLabel, a2: cArmedDisplay);
  }
  else
  {
    V_strncpy(pDest: buf, pSrc: cArmedDisplay, maxLen: 8);
    v8 = flTransitionTimes[0];
    v9 = flPercentDecoding;
    v10 = 0;
    if ( flTransitionTimes[0] > flPercentDecoding )
    {
      do
      {
        LOBYTE(v7) = cDefuseCode[v10];
        v11 = dword_105B4FCC[v10];
        buf[v10++] = (char)v7;
      }
      while ( v11 > v9 );
    }
    v12 = 1.0 - v8;
    if ( v10 > 0 )
      v12 = *(float *)&dword_105B4FC4[v10] - flTransitionTimes[v10];
    v13 = (float)(v9 - flTransitionTimes[v10]) / v12;
    v14 = *(float *)(gpGlobals.m_Index + 12) <= this->m_flNextDigitRandomizeTime;
    flPercentDecoding = v13;
    if ( !v14 )
    {
      v15 = _RandomInt(this: v7, a2: 0, a3: 9);
      v13 = flPercentDecoding;
      v16 = flPercentDecoding;
      this->m_iLastRandomInt = v15;
      if ( v16 <= 0.7 )
      {
        if ( v13 <= 0.5 )
        {
          if ( v13 <= 0.3 )
            v17 = *(float *)(gpGlobals.m_Index + 12) + 0.3;
          else
            v17 = *(float *)(gpGlobals.m_Index + 12) + 0.15;
        }
        else
        {
          v17 = *(float *)(gpGlobals.m_Index + 12) + 0.1;
        }
      }
      else
      {
        v17 = *(float *)(gpGlobals.m_Index + 12) + 0.05;
      }
      this->m_flNextDigitRandomizeTime = v17;
    }
    if ( v13 >= 0.2 )
      buf[v10] = LOBYTE(this->m_iLastRandomInt) + 48;
    else
      buf[v10] = cDefuseCode[v10];
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pTimeLabel->SetFgColor)(
      a1: this->m_pTimeLabel,
      a2: *(_DWORD *)&this->m_cArmed);
    this->m_pTimeLabel->SetText(this: this->m_pTimeLabel, a2: buf);
  }
}
