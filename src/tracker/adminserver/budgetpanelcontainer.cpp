// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/budgetpanelcontainer.cpp
// Functions: 88
// ============================================================

#include "tracker\adminserver\budgetpanelcontainer.h"

//------------------------------------------------------------------------------
// Address: 0x10009CB0
// Name: public: static char const __near * CBudgetPanelContainer::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBudgetPanelContainer::GetPanelClassName()
{
  return "CBudgetPanelContainer";
}

//------------------------------------------------------------------------------
// Address: 0x10009CC0
// Name: public: virtual void CBudgetPanelAdmin::SetupCustomConfigData(class CBudgetPanelConfigData __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelAdmin::SetupCustomConfigData(CBudgetPanelAdmin *this, CBudgetPanelConfigData *data)
{
  vgui::Panel::GetBounds(this, x: &data->m_xCoord, y: &data->m_yCoord, wide: &data->m_Width, tall: &data->m_Height);
}

//------------------------------------------------------------------------------
// Address: 0x10009CE0
// Name: public: void CBudgetPanelAdmin::DrawColoredText(unsigned long,int,int,int,int,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBudgetPanelAdmin::DrawColoredText(
        CBudgetPanelAdmin *this,
        unsigned int font,
        int x,
        int y,
        int r,
        int g,
        int b,
        int a,
        char *pText,
        ...)
{
  int v9; // esi
  char v10[8192]; // [esp+4h] [ebp-3000h] BYREF
  char string[4096]; // [esp+2004h] [ebp-1000h] BYREF
  va_list ap; // [esp+3030h] [ebp+2Ch] BYREF

  va_start(ap, pText);
  _vsnprintf(string, count: 0x1000u, format: pText, ap);
  v9 = g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: string, a3: (wchar_t *)v10, a4: 0x2000) - 1;
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x, a3: y);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: (const wchar_t *)v10, a3: v9, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10009D90
// Name: public: virtual void CBudgetPanelAdmin::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelAdmin::PostChildPaint(CBudgetPanelAdmin *this)
{
  float v2; // [esp+Ch] [ebp-8h]

  v2 = CBudgetPanelShared::g_fFrameRate;
  CBudgetPanelAdmin::DrawColoredText(
    this,
    font: this->m_hFont,
    x: 0,
    y: 0,
    r: this->m_budgetTextColor._color[0],
    g: this->m_budgetTextColor._color[1],
    b: this->m_budgetTextColor._color[2],
    a: this->m_budgetTextColor._color[3],
    pText: "%i fps (showbudget 3D driver time included)",
    (int)v2);
  CBudgetPanelAdmin::DrawColoredText(
    this,
    font: this->m_hFont,
    x: 0,
    y: 16,
    r: this->m_budgetTextColor._color[0],
    g: this->m_budgetTextColor._color[1],
    b: this->m_budgetTextColor._color[2],
    a: this->m_budgetTextColor._color[3],
    pText: "%.1f ms",
    (double)(CBudgetPanelShared::g_fFrameTimeLessBudget * 1000.0));
  CBudgetPanelShared::PostChildPaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009E50
// Name: public: virtual void CBudgetPanelAdmin::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelAdmin::OnTick(CBudgetPanelAdmin *this)
{
  if ( this->IsVisible(this) )
  {
    ((void (__thiscall *)(CBudgetPanelAdmin *, _DWORD))this->SnapshotVProfHistory)(a1: this, a2: 0);
    CBaseBudgetPanel::MarkForFullRepaint(this);
  }
  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10009E90
// Name: public: virtual void CBudgetPanelContainer::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelContainer::PerformLayout(CBudgetPanelContainer *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetBounds(this, &x, &y, &wide, &tall);
  vgui::Panel::SetBounds(this: this->m_pBudgetPanelAdmin, x: 12, y: 12, wide: wide - 24, tall: tall - 24);
  CBudgetPanelShared::SendConfigDataToBase(this: this->m_pBudgetPanelAdmin);
}

//------------------------------------------------------------------------------
// Address: 0x10009EF0
// Name: public: virtual void CBudgetPanelContainer::OnPageShow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelContainer::OnPageShow(CBudgetPanelContainer *this)
{
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->AddListener(this: g_pVProfExport);
  this->m_pBudgetPanelAdmin->SetVisible(this: this->m_pBudgetPanelAdmin, a2: true);
  vgui::PropertyPage::OnPageHide(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009F20
// Name: public: virtual void CBudgetPanelContainer::OnPageHide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelContainer::OnPageHide(CBudgetPanelContainer *this)
{
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->RemoveListener(this: g_pVProfExport);
  this->m_pBudgetPanelAdmin->SetVisible(this: this->m_pBudgetPanelAdmin, a2: false);
  vgui::PropertyPage::OnPageHide(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009F50
// Name: public: virtual struct vgui::PanelMessageMap __near * CBudgetPanelContainer::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBudgetPanelContainer::GetMessageMap(CBudgetPanelContainer *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBudgetPanelContainer::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBudgetPanelContainer::GetMessageMap'::`2'::s_pMap;
  `CBudgetPanelContainer::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBudgetPanelContainer");
  `CBudgetPanelContainer::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009F80
// Name: public: virtual struct PanelAnimationMap __near * CBudgetPanelContainer::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBudgetPanelContainer::GetAnimMap(CBudgetPanelContainer *this)
{
  return FindOrAddPanelAnimationMap(className: "CBudgetPanelContainer");
}

//------------------------------------------------------------------------------
// Address: 0x10009F90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBudgetPanelContainer::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBudgetPanelContainer::GetKBMap(CBudgetPanelContainer *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBudgetPanelContainer::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBudgetPanelContainer::GetKBMap'::`2'::s_pMap;
  `CBudgetPanelContainer::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBudgetPanelContainer");
  `CBudgetPanelContainer::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009FF0
// Name: public: virtual void CBudgetPanelAdmin::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelAdmin::ApplySchemeSettings(CBudgetPanelAdmin *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax

  v2 = (vgui::IScheme *)pScheme;
  CBaseBudgetPanel::ApplySchemeSettings(this, pScheme);
  GetColor = v2->GetColor;
  pScheme = -16711936;
  this->m_budgetTextColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                                        a1: v2,
                                        a2: &pScheme,
                                        a3: "BrightControlText",
                                        a4: -16711936);
}

//------------------------------------------------------------------------------
// Address: 0x1000A030
// Name: public: CBudgetPanelContainer::CBudgetPanelContainer(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelContainer *__thiscall CBudgetPanelContainer::CBudgetPanelContainer(
        CBudgetPanelContainer *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CBudgetPanelShared *v7; // eax
  CBudgetPanelAdmin *v8; // edi
  CBudgetPanelAdmin *v9; // ecx

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&IServerDataResponse::`vftable';
  this->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBudgetPanelContainer_vtbl *)&CBudgetPanelContainer::`vftable'{for `vgui::PropertyPage'};
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CBudgetPanelContainer::`vftable'{for `IServerDataResponse'};
  if ( `CBudgetPanelContainer::ChainToMap'::`2'::chained == 0 )
  {
    `CBudgetPanelContainer::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBudgetPanelContainer");
    v4->pfnClassName = CBudgetPanelContainer::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CBudgetPanelContainer::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBudgetPanelContainer::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBudgetPanelContainer");
    v5->pfnClassName = CBudgetPanelContainer::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CBudgetPanelContainer::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBudgetPanelContainer::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBudgetPanelContainer");
    v6->pfnClassName = CBudgetPanelContainer::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Admin/BudgetPanel.res",
    pathID: "PLATFORM",
    pKeyValues: nullptr,
    pConditions: nullptr);
  v7 = (CBudgetPanelShared *)operator new(nSize: 0x208u);
  v8 = (CBudgetPanelAdmin *)v7;
  if ( v7 != nullptr )
  {
    CBudgetPanelShared::CBudgetPanelShared(
      this: v7,
      pParent: this,
      pElementName: "AdminBudgetPanel",
      budgetFlagsFilter: 2);
    v8->__vftable = (CBudgetPanelAdmin_vtbl *)&CBudgetPanelAdmin::`vftable';
    v8->m_budgetTextColor = 0;
    v8->m_bDedicated = true;
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pBudgetPanelAdmin = v9;
  v9->SetVisible(this: v9, a2: false);
  vgui::Panel::InvalidateLayout(this, layoutNow: false, reloadScheme: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092970
// Name: _dynamic_initializer_for__budget_bargraph_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_bargraph_background_alpha__()
{
  ConVar::ConVar(
    this: &budget_bargraph_background_alpha,
    pName: "budget_bargraph_background_alpha",
    pDefaultValue: "128",
    flags: 128,
    pHelpString: "how translucent the budget panel is");
  return atexit(func: dynamic_atexit_destructor_for__budget_bargraph_background_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x100929A0
// Name: _dynamic_initializer_for__budget_peaks_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_peaks_window__()
{
  ConVar::ConVar(
    this: &budget_peaks_window,
    pName: "budget_peaks_window",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "number of frames to look at when figuring out peak frametimes");
  return atexit(func: dynamic_atexit_destructor_for__budget_peaks_window__);
}

//------------------------------------------------------------------------------
// Address: 0x100929D0
// Name: _dynamic_initializer_for__budget_averages_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_averages_window__()
{
  ConVar::ConVar(
    this: &budget_averages_window,
    pName: "budget_averages_window",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "number of frames to look at when figuring out average frametimes");
  return atexit(func: dynamic_atexit_destructor_for__budget_averages_window__);
}

//------------------------------------------------------------------------------
// Address: 0x10092A00
// Name: _dynamic_initializer_for__budget_show_peaks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_peaks__()
{
  ConVar::ConVar(
    this: &budget_show_peaks,
    pName: "budget_show_peaks",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "enable/disable peaks in the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_peaks__);
}

//------------------------------------------------------------------------------
// Address: 0x10092A30
// Name: _dynamic_initializer_for__budget_show_averages__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_averages__()
{
  ConVar::ConVar(
    this: &budget_show_averages,
    pName: "budget_show_averages",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "enable/disable averages in the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_averages__);
}

//------------------------------------------------------------------------------
// Address: 0x10092A60
// Name: _dynamic_initializer_for__budget_show_history__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_history__()
{
  ConVar::ConVar(
    this: &budget_show_history,
    pName: "budget_show_history",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "turn history graph off and on. . good to turn off on low end");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_history__);
}

//------------------------------------------------------------------------------
// Address: 0x10092A90
// Name: _dynamic_initializer_for__budget_history_numsamplesvisible__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_history_numsamplesvisible__()
{
  ConVar::ConVar(
    this: &budget_history_numsamplesvisible,
    pName: "budget_history_numsamplesvisible",
    pDefaultValue: "100",
    flags: 128,
    pHelpString: "number of samples to draw in the budget history window.  The lower the better as far as rendering overhead of the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_history_numsamplesvisible__);
}

//------------------------------------------------------------------------------
// Address: 0x10092AC0
// Name: _dynamic_initializer_for__budget_history_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_history_range_ms__()
{
  ConVar::ConVar(
    this: &budget_history_range_ms,
    pName: "budget_history_range_ms",
    pDefaultValue: "66.666666667",
    flags: 128,
    pHelpString: "budget history range in milliseconds",
    callback: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_history_range_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x10092AF0
// Name: _dynamic_initializer_for__budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_bottom_of_history_fraction__()
{
  ConVar::ConVar(
    this: &budget_panel_bottom_of_history_fraction,
    pName: "budget_panel_bottom_of_history_fraction",
    pDefaultValue: ".25",
    flags: 128,
    pHelpString: "number between 0 and 1",
    callback: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_bottom_of_history_fraction__);
}

//------------------------------------------------------------------------------
// Address: 0x10092B20
// Name: _dynamic_initializer_for__budget_bargraph_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_bargraph_range_ms__()
{
  ConVar::ConVar(
    this: &budget_bargraph_range_ms,
    pName: "budget_bargraph_range_ms",
    pDefaultValue: "16.6666666667",
    flags: 128,
    pHelpString: "budget bargraph range in milliseconds",
    callback: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_bargraph_range_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x10092B50
// Name: _dynamic_initializer_for__budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_background_alpha__()
{
  ConVar::ConVar(
    this: &budget_background_alpha,
    pName: "budget_background_alpha",
    pDefaultValue: "128",
    flags: 128,
    pHelpString: "how translucent the budget panel is");
  return atexit(func: dynamic_atexit_destructor_for__budget_background_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x10092B80
// Name: _dynamic_initializer_for__budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_x__()
{
  ConVar::ConVar(
    this: &budget_panel_x,
    pName: "budget_panel_x",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "number of pixels from the left side of the game screen to draw the budget panel",
    callback: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_x__);
}

//------------------------------------------------------------------------------
// Address: 0x10092BB0
// Name: _dynamic_initializer_for__budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_y__()
{
  ConVar::ConVar(
    this: &budget_panel_y,
    pName: "budget_panel_y",
    pDefaultValue: "50",
    flags: 128,
    pHelpString: "number of pixels from the top side of the game screen to draw the budget panel",
    callback: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_y__);
}

//------------------------------------------------------------------------------
// Address: 0x10092BE0
// Name: _dynamic_initializer_for__budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_width__()
{
  ConVar::ConVar(
    this: &budget_panel_width,
    pName: "budget_panel_width",
    pDefaultValue: "512",
    flags: 128,
    pHelpString: "width in pixels of the budget panel",
    callback: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_width__);
}

//------------------------------------------------------------------------------
// Address: 0x10092C10
// Name: _dynamic_initializer_for__budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_height__()
{
  ConVar::ConVar(
    this: &budget_panel_height,
    pName: "budget_panel_height",
    pDefaultValue: "384",
    flags: 128,
    pHelpString: "height in pixels of the budget panel",
    callback: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_height__);
}

//------------------------------------------------------------------------------
// Address: 0x10093680
// Name: _dynamic_atexit_destructor_for__budget_bargraph_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_bargraph_background_alpha__()
{
  ConVar::~ConVar(this: &budget_bargraph_background_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x10093690
// Name: _dynamic_atexit_destructor_for__budget_peaks_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_peaks_window__()
{
  ConVar::~ConVar(this: &budget_peaks_window);
}

//------------------------------------------------------------------------------
// Address: 0x100936A0
// Name: _dynamic_atexit_destructor_for__budget_averages_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_averages_window__()
{
  ConVar::~ConVar(this: &budget_averages_window);
}

//------------------------------------------------------------------------------
// Address: 0x100936B0
// Name: _dynamic_atexit_destructor_for__budget_show_peaks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_show_peaks__()
{
  ConVar::~ConVar(this: &budget_show_peaks);
}

//------------------------------------------------------------------------------
// Address: 0x100936C0
// Name: _dynamic_atexit_destructor_for__budget_show_averages__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_show_averages__()
{
  ConVar::~ConVar(this: &budget_show_averages);
}

//------------------------------------------------------------------------------
// Address: 0x100936D0
// Name: _dynamic_atexit_destructor_for__budget_show_history__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_show_history__()
{
  ConVar::~ConVar(this: &budget_show_history);
}

//------------------------------------------------------------------------------
// Address: 0x100936E0
// Name: _dynamic_atexit_destructor_for__budget_history_numsamplesvisible__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_history_numsamplesvisible__()
{
  ConVar::~ConVar(this: &budget_history_numsamplesvisible);
}

//------------------------------------------------------------------------------
// Address: 0x10093710
// Name: _dynamic_atexit_destructor_for__budget_history_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_history_range_ms__()
{
  ConVar::~ConVar(this: &budget_history_range_ms);
}

//------------------------------------------------------------------------------
// Address: 0x10093720
// Name: _dynamic_atexit_destructor_for__budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_bottom_of_history_fraction__()
{
  ConVar::~ConVar(this: &budget_panel_bottom_of_history_fraction);
}

//------------------------------------------------------------------------------
// Address: 0x10093730
// Name: _dynamic_atexit_destructor_for__budget_bargraph_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_bargraph_range_ms__()
{
  ConVar::~ConVar(this: &budget_bargraph_range_ms);
}

//------------------------------------------------------------------------------
// Address: 0x10093740
// Name: _dynamic_atexit_destructor_for__budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_background_alpha__()
{
  ConVar::~ConVar(this: &budget_background_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x10093750
// Name: _dynamic_atexit_destructor_for__budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_x__()
{
  ConVar::~ConVar(this: &budget_panel_x);
}

//------------------------------------------------------------------------------
// Address: 0x10093760
// Name: _dynamic_atexit_destructor_for__budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_y__()
{
  ConVar::~ConVar(this: &budget_panel_y);
}

//------------------------------------------------------------------------------
// Address: 0x10093770
// Name: _dynamic_atexit_destructor_for__budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_width__()
{
  ConVar::~ConVar(this: &budget_panel_width);
}

//------------------------------------------------------------------------------
// Address: 0x10093780
// Name: _dynamic_atexit_destructor_for__budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_height__()
{
  ConVar::~ConVar(this: &budget_panel_height);
}

//------------------------------------------------------------------------------
// Address: 0x10092C40
// Name: _dynamic_initializer_for__g_TempBudgetGroupSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TempBudgetGroupSpace__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__);
}

//------------------------------------------------------------------------------
// Address: 0x10092C50
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092C60
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092C70
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092C80
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092C90
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092CA0
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092CB0
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092CC0
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092CD0
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092CE0
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092CF0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D00
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D10
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D20
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D30
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D40
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D50
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D60
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D70
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D80
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092D90
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092DA0
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092DB0
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092DC0
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092DD0
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092DE0
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092DF0
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092E00
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092E10
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092E20
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092E30
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092E40
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092E50
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10092E60
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10092E80
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x10092EA0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10092EB0
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10092EC0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092F20
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092F50
// Name: _dynamic_initializer_for__g_Menu_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Menu_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(this: &g_Menu_Helper, className: "Menu", func: Create_Menu);
}

//------------------------------------------------------------------------------
// Address: 0x10093790
// Name: _dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_TempBudgetGroupSpace);
}

//------------------------------------------------------------------------------
// Address: 0x100937A0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100937F0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10093800
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}
