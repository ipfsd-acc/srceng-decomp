// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/game_controls/navprogress.cpp
// Functions: 12
// ============================================================

#include "game\client\game_controls\navprogress.h"

//------------------------------------------------------------------------------
// Address: 0x1023CA70
// Name: public: virtual void CNavProgress::SetParent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavProgress::SetParent(CCommentaryModelViewer *this, unsigned int parent)
{
  vgui::Panel::SetParent(this, newParent: parent);
}

//------------------------------------------------------------------------------
// Address: 0x1023D400
// Name: public: static char const __near * CNavProgress::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNavProgress::GetPanelClassName()
{
  return "CNavProgress";
}

//------------------------------------------------------------------------------
// Address: 0x1023D410
// Name: public: virtual char const __near * CNavProgress::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNavProgress::GetName(CNavProgress *this)
{
  return "nav_progress";
}

//------------------------------------------------------------------------------
// Address: 0x1023D420
// Name: public: virtual bool CNavProgress::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CNavProgress::IsVisible(CCommentaryModelViewer *this)
{
  return vgui::Panel::IsVisible(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023D430
// Name: public: virtual void CNavProgress::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavProgress::PerformLayout(CNavProgress *this)
{
  int Wide; // eax

  vgui::Frame::PerformLayout(this);
  if ( this->m_numTicks != 0 )
  {
    Wide = vgui::Panel::GetWide(this: this->m_pProgressBarSizer);
    vgui::Panel::SetWide(this: this->m_pProgressBar, wide: Wide * this->m_currentTick / this->m_numTicks);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D470
// Name: public: virtual void CNavProgress::SetData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavProgress::SetData(CNavProgress *this, KeyValues *data)
{
  int Int; // edi
  char *String; // eax
  int v6; // ecx
  void (__thiscall *v7)(char *, _DWORD, _DWORD); // eax
  KeyValues *dataa; // [esp+14h] [ebp+8h]

  dataa = (KeyValues *)KeyValues::GetInt(this: data, keyName: "current", defaultValue: 0);
  Int = KeyValues::GetInt(this: data, keyName: "total", defaultValue: 0);
  String = KeyValues::GetString(this: data, keyName: "msg", defaultValue: prType);
  (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)&this->m_InternalCursorMoved_register + 848))(
    a1: *(_DWORD *)&this->m_InternalCursorMoved_register,
    a2: String);
  if ( Int < 1 )
    Int = 1;
  *(_DWORD *)&this->m_OnDelete_register = Int;
  v6 = Int;
  if ( Int >= (int)dataa )
    v6 = (int)dataa;
  if ( v6 >= 0 )
  {
    if ( Int >= (int)dataa )
      Int = (int)dataa;
  }
  else
  {
    Int = 0;
  }
  v7 = *(void (__thiscall **)(char *, _DWORD, _DWORD))(*((_DWORD *)this - 132) + 264);
  *(_DWORD *)&this->m_OnNavigateFrom_register = Int;
  v7(a1: (char *)this - 528, a2: 0, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1023D510
// Name: public: virtual void CNavProgress::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavProgress::ShowPanel(CNavProgress *this, int bShow)
{
  int v3; // eax
  char *v4; // ecx

  if ( vgui::Panel::IsVisible(this: (CNavProgress *)((char *)this - 528)) != (_BYTE)bShow )
  {
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_OnCommand_register + 16))(
      a1: *(_DWORD *)&this->m_OnCommand_register,
      a2: bShow);
    v3 = *((_DWORD *)this - 132);
    v4 = (char *)this - 528;
    if ( (_BYTE)bShow != 0 )
    {
      (*(void (__thiscall **)(char *))(v3 + 952))(a1: v4);
      (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 132) + 540))(a1: (char *)this - 528, a2: 1);
    }
    else
    {
      (*(void (__thiscall **)(char *, _DWORD))(v3 + 132))(a1: v4, a2: 0);
      (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 132) + 540))(a1: (char *)this - 528, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023D580
// Name: public: virtual struct vgui::PanelMessageMap __near * CNavProgress::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNavProgress::GetMessageMap(CNavProgress *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNavProgress::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNavProgress::GetMessageMap'::`2'::s_pMap;
  `CNavProgress::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNavProgress");
  `CNavProgress::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023D5B0
// Name: public: virtual struct PanelAnimationMap __near * CNavProgress::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNavProgress::GetAnimMap(CNavProgress *this)
{
  return FindOrAddPanelAnimationMap(className: "CNavProgress");
}

//------------------------------------------------------------------------------
// Address: 0x1023D5C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNavProgress::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNavProgress::GetKBMap(CNavProgress *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNavProgress::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNavProgress::GetKBMap'::`2'::s_pMap;
  `CNavProgress::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNavProgress");
  `CNavProgress::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023D5F0
// Name: public: CNavProgress::CNavProgress(class IViewPort __near *)
// Source: json
//------------------------------------------------------------------------------
CNavProgress *__thiscall CNavProgress::CNavProgress(CNavProgress *this, IViewPort *pViewPort)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Label *v6; // eax
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  vgui::Frame::Frame(this, parent: nullptr, panelName: "nav_progress", showTaskbarIcon: 1, bPopup: true);
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CNavProgress_vtbl *)&CNavProgress::`vftable'{for `vgui::Frame'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CNavProgress::`vftable'{for `IViewPortPanel'};
  if ( `CNavProgress::ChainToMap'::`2'::chained == 0 )
  {
    `CNavProgress::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CNavProgress");
    v3->pfnClassName = CNavProgress::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CNavProgress::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNavProgress::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CNavProgress");
    v4->pfnClassName = CNavProgress::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CNavProgress::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNavProgress::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CNavProgress");
    v5->pfnClassName = CNavProgress::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pViewPort = pViewPort;
  vgui::Panel::SetScheme(this, tag: "ClientScheme");
  vgui::Frame::SetMoveable(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Panel::SetProportional(this, state: true);
  vgui::Frame::SetTitleBarVisible(this, state: false);
  v6 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v6 != nullptr )
    v7 = vgui::Label::Label(this: v6, parent: this, panelName: "TitleLabel", text: prType);
  else
    v7 = nullptr;
  this->m_pTitle = v7;
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "TextLabel", text: prType);
  else
    v9 = nullptr;
  this->m_pText = v9;
  v10 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v10 != nullptr )
    v11 = vgui::Panel::Panel(this: v10, parent: this, panelName: "ProgressBarBorder");
  else
    v11 = nullptr;
  this->m_pProgressBarBorder = v11;
  v12 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v12 != nullptr )
    v13 = vgui::Panel::Panel(this: v12, parent: this, panelName: "ProgressBar");
  else
    v13 = nullptr;
  this->m_pProgressBar = v13;
  v14 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v14 != nullptr )
    v15 = vgui::Panel::Panel(this: v14, parent: this, panelName: "ProgressBarSizer");
  else
    v15 = nullptr;
  this->m_pProgressBarSizer = v15;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/UI/NavProgress.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1023D870
// Name: public: virtual void CNavProgress::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavProgress::ApplySchemeSettings(CNavProgress *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IBorder *(__thiscall *GetBorder)(vgui::IScheme *, const char *); // eax
  int v5; // eax
  vgui::Panel *m_pProgressBarBorder; // ecx
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  vgui::IBorder *(__thiscall *v8)(vgui::IScheme *, const char *); // eax
  int v9; // eax
  vgui::Panel *m_pProgressBar; // ecx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  vgui::Panel_vtbl *v12; // ebx
  _DWORD *v13; // eax

  v2 = pScheme;
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->SetPaintBackgroundType(this, a2: 2);
  this->m_pProgressBarSizer->SetVisible(this: this->m_pProgressBarSizer, a2: false);
  GetBorder = v2->GetBorder;
  pScheme = (vgui::IScheme *)this->m_pProgressBarBorder->__vftable;
  v5 = (int)GetBorder(this: v2, a2: "ButtonDepressedBorder");
  ((void (__thiscall *)(vgui::Panel *, int))pScheme[68].__vftable)(a1: this->m_pProgressBarBorder, a2: v5);
  m_pProgressBarBorder = this->m_pProgressBarBorder;
  SetBgColor = m_pProgressBarBorder->SetBgColor;
  pScheme = nullptr;
  ((void (__thiscall *)(vgui::Panel *, _DWORD))SetBgColor)(a1: m_pProgressBarBorder, a2: 0);
  v8 = v2->GetBorder;
  pScheme = (vgui::IScheme *)this->m_pProgressBar->__vftable;
  v9 = (int)v8(this: v2, a2: "ButtonBorder");
  ((void (__thiscall *)(vgui::Panel *, int))pScheme[68].__vftable)(a1: this->m_pProgressBar, a2: v9);
  m_pProgressBar = this->m_pProgressBar;
  GetColor = v2->GetColor;
  pScheme = nullptr;
  v12 = m_pProgressBar->__vftable;
  v13 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, _DWORD))GetColor)(
                    a1: v2,
                    a2: &pScheme,
                    a3: "ProgressBar.FgColor",
                    a4: 0);
  ((void (__thiscall *)(vgui::Panel *, _DWORD))v12->SetBgColor)(a1: this->m_pProgressBar, a2: *v13);
}
