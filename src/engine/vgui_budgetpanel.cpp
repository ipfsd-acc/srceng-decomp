// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_budgetpanel.cpp
// Functions: 9
// ============================================================

#include "engine\vgui_budgetpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10118420
// Name: public: bool CBudgetPanelEngine::IsBudgetPanelShown(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBudgetPanelEngine::IsBudgetPanelShown(CBaseClient *this)
{
  return this->m_nForceWaitForTick;
}

//------------------------------------------------------------------------------
// Address: 0x10209A00
// Name: class CBudgetPanelEngine __near * GetBudgetPanel(void)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelEngine *__cdecl GetBudgetPanel()
{
  return g_pBudgetPanel;
}

//------------------------------------------------------------------------------
// Address: 0x10209A10
// Name: public: CBudgetPanelEngine::CBudgetPanelEngine(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelEngine *__thiscall CBudgetPanelEngine::CBudgetPanelEngine(
        CBudgetPanelEngine *this,
        vgui::Panel *pParent,
        const char *pElementName)
{
  CBudgetPanelShared::CBudgetPanelShared(this, pParent, pElementName, budgetFlagsFilter: 32773);
  this->__vftable = (CBudgetPanelEngine_vtbl *)&CBudgetPanelEngine::`vftable';
  g_pBudgetPanel = this;
  this->m_bShowBudgetPanelHeld = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209A50
// Name: vprof_adddebuggroup1
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_adddebuggroup1()
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "vprof_adddebuggroup1",
    a3: 0,
    a4: "vprof_adddebuggroup1",
    a5: false,
    a6: 4);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10209A80
// Name: void IN_BudgetDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IN_BudgetDown(vgui::CTreeViewListControl *this)
{
  CBudgetPanelEngine *v1; // esi
  ECommandTarget_t TraceType; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  v1 = g_pBudgetPanel;
  if ( g_pBudgetPanel != nullptr )
  {
    TraceType = CTraceFilter::GetTraceType(this);
    Cbuf_AddText(eTarget: TraceType, pText: "vprof_on\n", nTickDelay: 0);
    SetVisible = v1->SetVisible;
    v1->m_bShowBudgetPanelHeld = true;
    SetVisible(this: v1, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209AC0
// Name: void IN_BudgetUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IN_BudgetUp(vgui::CTreeViewListControl *this)
{
  CBudgetPanelEngine *v1; // esi
  ECommandTarget_t TraceType; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  v1 = g_pBudgetPanel;
  if ( g_pBudgetPanel != nullptr )
  {
    TraceType = CTraceFilter::GetTraceType(this);
    Cbuf_AddText(eTarget: TraceType, pText: "vprof_off\n", nTickDelay: 0);
    SetVisible = v1->SetVisible;
    v1->m_bShowBudgetPanelHeld = false;
    SetVisible(this: v1, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209B40
// Name: public: virtual void CBudgetPanelEngine::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelEngine::PostChildPaint(CBudgetPanelEngine *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int CurrentTick; // edi
  double v6; // st7
  char pDest[8]; // [esp+Ch] [ebp-208h] BYREF
  char str[512]; // [esp+14h] [ebp-200h]

  v2 = 255;
  v3 = 0;
  v4 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
  if ( CBudgetPanelShared::g_fFrameRate >= 60.0
    || v4 <= 92 && CBudgetPanelShared::g_fFrameRate >= 30.0
    || v4 <= 90 && CBudgetPanelShared::g_fFrameRate >= 20.0 )
  {
    v2 = 0;
    v3 = 255;
  }
  *(float *)&str[504] = CBudgetPanelShared::g_fFrameRate;
  *(_DWORD *)&str[508] = (int)*(float *)&str[504];
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: this->m_hFont,
    a3: 600,
    a4: 20,
    a5: v2,
    a6: v3,
    a7: 0,
    a8: 255,
    a9: "%3i fps (showbudget 3D driver time included)",
    *(_DWORD *)&str[508]);
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: this->m_hFont,
    a3: 600,
    a4: 34,
    a5: v2,
    a6: v3,
    a7: 0,
    a8: 255,
    a9: "%5.1f ms",
    CBudgetPanelShared::g_fFrameTimeLessBudget * 1000.0);
  if ( VProfRecord_IsPlayingBack() )
  {
    CurrentTick = VProfPlayback_GetCurrentTick();
    v6 = VProfPlayback_GetCurrentPercent() * 100.0;
    V_snprintf(pDest, maxLen: 512, pFormat: "VPROF playback (tick %d, %d%%)", CurrentTick, (int)v6);
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFont,
      a3: 600,
      a4: 48,
      a5: 255,
      a6: 0,
      a7: 0,
      a8: 255,
      a9: "%s",
      pDest);
  }
  CBudgetPanelShared::PostChildPaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10209CA0
// Name: public: virtual void CBudgetPanelEngine::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelEngine::OnTick(CBudgetPanelEngine *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  if ( this->m_bShowBudgetPanelHeld
    && (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive() )
  {
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: "vprof_off\n", nTickDelay: 0);
    SetVisible = this->SetVisible;
    this->m_bShowBudgetPanelHeld = false;
    SetVisible(this, a2: false);
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  this->SetVisible(this, a2: this->m_bShowBudgetPanelHeld);
}

//------------------------------------------------------------------------------
// Address: 0x10209D10
// Name: public: virtual void CBudgetPanelEngine::SetTimeLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelEngine::SetTimeLabelText(CBudgetPanelEngine *this)
{
  int i; // esi
  vgui::Label *v3; // ecx
  char text[512]; // [esp+8h] [ebp-200h] BYREF

  for ( i = 0; i < this->m_TimeLabels.m_Size; ++i )
  {
    V_snprintf(
      pDest: text,
      maxLen: 512,
      pFormat: "%dms",
      (int)(float)((float)i * this->m_ConfigData.m_flTimeLabelInterval));
    v3 = this->m_TimeLabels.m_Memory.m_pMemory[i];
    v3->SetText(this: v3, a2: text);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101184E0
// Name: public: bool CBudgetPanelEngine::IsBudgetPanelShown(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBudgetPanelEngine::IsBudgetPanelShown(CBaseClient *this)
{
  return this->m_nForceWaitForTick;
}

//------------------------------------------------------------------------------
// Address: 0x10209B50
// Name: class CBudgetPanelEngine __near * GetBudgetPanel(void)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelEngine *__cdecl GetBudgetPanel()
{
  return g_pBudgetPanel;
}

//------------------------------------------------------------------------------
// Address: 0x10209B60
// Name: public: CBudgetPanelEngine::CBudgetPanelEngine(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelEngine *__thiscall CBudgetPanelEngine::CBudgetPanelEngine(
        CBudgetPanelEngine *this,
        vgui::Panel *pParent,
        const char *pElementName)
{
  CBudgetPanelShared::CBudgetPanelShared(this, pParent, pElementName, budgetFlagsFilter: 32773);
  this->__vftable = (CBudgetPanelEngine_vtbl *)&CBudgetPanelEngine::`vftable';
  g_pBudgetPanel = this;
  this->m_bShowBudgetPanelHeld = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209BA0
// Name: vprof_adddebuggroup1
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_adddebuggroup1()
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "vprof_adddebuggroup1",
    a3: 0,
    a4: "vprof_adddebuggroup1",
    a5: false,
    a6: 4);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10209BD0
// Name: void IN_BudgetDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IN_BudgetDown(vgui::CTreeViewListControl *this)
{
  CBudgetPanelEngine *v1; // esi
  ECommandTarget_t TraceType; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  v1 = g_pBudgetPanel;
  if ( g_pBudgetPanel != nullptr )
  {
    TraceType = CTraceFilter::GetTraceType(this);
    Cbuf_AddText(eTarget: TraceType, pText: "vprof_on\n", nTickDelay: 0);
    SetVisible = v1->SetVisible;
    v1->m_bShowBudgetPanelHeld = true;
    SetVisible(this: v1, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209C10
// Name: void IN_BudgetUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IN_BudgetUp(vgui::CTreeViewListControl *this)
{
  CBudgetPanelEngine *v1; // esi
  ECommandTarget_t TraceType; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  v1 = g_pBudgetPanel;
  if ( g_pBudgetPanel != nullptr )
  {
    TraceType = CTraceFilter::GetTraceType(this);
    Cbuf_AddText(eTarget: TraceType, pText: "vprof_off\n", nTickDelay: 0);
    SetVisible = v1->SetVisible;
    v1->m_bShowBudgetPanelHeld = false;
    SetVisible(this: v1, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209C90
// Name: public: virtual void CBudgetPanelEngine::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelEngine::PostChildPaint(CBudgetPanelEngine *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int CurrentTick; // edi
  double v6; // st7
  char str[512]; // [esp+14h] [ebp-208h] BYREF
  float v8; // [esp+214h] [ebp-8h]
  int v9; // [esp+218h] [ebp-4h]

  v2 = 255;
  v3 = 0;
  v4 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
  if ( CBudgetPanelShared::g_fFrameRate >= 60.0
    || v4 <= 92 && CBudgetPanelShared::g_fFrameRate >= 30.0
    || v4 <= 90 && CBudgetPanelShared::g_fFrameRate >= 20.0 )
  {
    v2 = 0;
    v3 = 255;
  }
  v8 = CBudgetPanelShared::g_fFrameRate;
  v9 = (int)v8;
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: this->m_hFont,
    a3: 600,
    a4: 20,
    a5: v2,
    a6: v3,
    a7: 0,
    a8: 255,
    a9: "%3i fps (showbudget 3D driver time included)",
    v9);
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: this->m_hFont,
    a3: 600,
    a4: 34,
    a5: v2,
    a6: v3,
    a7: 0,
    a8: 255,
    a9: "%5.1f ms",
    CBudgetPanelShared::g_fFrameTimeLessBudget * 1000.0);
  if ( VProfRecord_IsPlayingBack() )
  {
    CurrentTick = VProfPlayback_GetCurrentTick();
    v6 = VProfPlayback_GetCurrentPercent() * 100.0;
    V_snprintf(pDest: str, maxLen: 512, pFormat: "VPROF playback (tick %d, %d%%)", CurrentTick, (int)v6);
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFont,
      a3: 600,
      a4: 48,
      a5: 255,
      a6: 0,
      a7: 0,
      a8: 255,
      a9: "%s",
      str);
  }
  CBudgetPanelShared::PostChildPaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10209DF0
// Name: public: virtual void CBudgetPanelEngine::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelEngine::OnTick(CBudgetPanelEngine *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  if ( this->m_bShowBudgetPanelHeld
    && (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive() )
  {
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: "vprof_off\n", nTickDelay: 0);
    SetVisible = this->SetVisible;
    this->m_bShowBudgetPanelHeld = false;
    SetVisible(this, a2: false);
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  this->SetVisible(this, a2: this->m_bShowBudgetPanelHeld);
}

//------------------------------------------------------------------------------
// Address: 0x10209E60
// Name: public: virtual void CBudgetPanelEngine::SetTimeLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelEngine::SetTimeLabelText(CBudgetPanelEngine *this)
{
  int i; // esi
  vgui::Label *v3; // ecx
  char text[512]; // [esp+8h] [ebp-200h] BYREF

  for ( i = 0; i < this->m_TimeLabels.m_Size; ++i )
  {
    V_snprintf(
      pDest: text,
      maxLen: 512,
      pFormat: "%dms",
      (int)(float)((float)i * this->m_ConfigData.m_flTimeLabelInterval));
    v3 = this->m_TimeLabels.m_Memory.m_pMemory[i];
    v3->SetText(this: v3, a2: text);
  }
}

} // namespace engine_xlsp
