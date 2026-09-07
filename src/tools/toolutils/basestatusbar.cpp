// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/basestatusbar.cpp
// Functions: 8
// ============================================================

#include "tools\toolutils\basestatusbar.h"

//------------------------------------------------------------------------------
// Address: 0x102C30F0
// Name: public: static char const __near * CBaseStatusBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseStatusBar::GetPanelClassName()
{
  return "CBaseStatusBar";
}

//------------------------------------------------------------------------------
// Address: 0x102C3100
// Name: private: virtual void CBaseStatusBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseStatusBar::PerformLayout(CBaseStatusBar *this)
{
  int v2; // eax
  vgui::Label *m_pLabel; // ecx
  int v4; // edi
  int v5; // [esp+8h] [ebp-10h] BYREF
  int cw; // [esp+Ch] [ebp-Ch] BYREF
  int w; // [esp+10h] [ebp-8h] BYREF
  int h; // [esp+14h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v2 = w;
  m_pLabel = this->m_pLabel;
  w = (int)(float)((float)w * 0.44999999);
  v4 = v2;
  m_pLabel->GetContentSize(this: m_pLabel, a2: &cw, a3: &v5);
  vgui::Panel::SetBounds(this: this->m_pLabel, x: 8, y: 4, wide: cw, tall: h - 8);
  vgui::Panel::SetBounds(this: this->m_pConsole, x: cw + 12, y: 2, wide: w - (cw + 12) - 8, tall: h - 4);
  v4 -= 95;
  vgui::Panel::SetBounds(this: this->m_pFPS, x: v4, y: 2, wide: 73, tall: h - 8);
  v4 -= 85;
  vgui::Panel::SetBounds(this: this->m_pGameTime, x: v4, y: 2, wide: 83, tall: h - 8);
  vgui::Panel::SetBounds(this: this->m_pMemory, x: v4 - 85, y: 2, wide: 83, tall: h - 8);
}

//------------------------------------------------------------------------------
// Address: 0x102C31F0
// Name: private: virtual void CBaseStatusBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseStatusBar::ApplySchemeSettings(CBaseStatusBar *this, vgui::IScheme *pScheme)
{
  CBaseStatusBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  CBaseStatusBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  vgui::Label_vtbl *v9; // ebx
  unsigned int v10; // eax
  vgui::Label_vtbl *v11; // ebx
  unsigned int v12; // eax
  vgui::Label_vtbl *v13; // ebx
  unsigned int v14; // eax
  vgui::Label_vtbl *v15; // ebx
  unsigned int v16; // eax
  _BYTE v17[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v18[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v18);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v17,
                   a3: "StatusBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(CBaseStatusBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
  v9 = this->m_pLabel->__vftable;
  v10 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v9->SetFont(this: this->m_pLabel, a2: v10);
  v11 = this->m_pMemory->__vftable;
  v12 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v11->SetFont(this: this->m_pMemory, a2: v12);
  v13 = this->m_pFPS->__vftable;
  v14 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v13->SetFont(this: this->m_pFPS, a2: v14);
  v15 = this->m_pGameTime->__vftable;
  v16 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v15->SetFont(this: this->m_pGameTime, a2: v16);
}

//------------------------------------------------------------------------------
// Address: 0x102C3300
// Name: public: CBaseStatusBar::CBaseStatusBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseStatusBar *__thiscall CBaseStatusBar::CBaseStatusBar(
        CBaseStatusBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CConsolePage *v7; // eax
  CConsolePage *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::Label *v16; // eax
  char v18[8]; // [esp+10h] [ebp-100h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (CBaseStatusBar_vtbl *)&CBaseStatusBar::`vftable';
  if ( `CBaseStatusBar::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseStatusBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseStatusBar");
    v4->pfnClassName = CBaseStatusBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseStatusBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseStatusBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseStatusBar");
    v5->pfnClassName = CBaseStatusBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseStatusBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseStatusBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseStatusBar");
    v6->pfnClassName = CBaseStatusBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_flLastFPSSnapShot = -1.0;
  vgui::Panel::SetVisible(this, state: 1);
  v7 = (CConsolePage *)operator new(nSize: 0x3D4u);
  if ( v7 != nullptr )
    v8 = CConsolePage::CConsolePage(this: v7, parent: this, bStatusVersion: true);
  else
    v8 = nullptr;
  this->m_pConsole = v8;
  v9 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "Console", text: "#BxConsole");
  else
    v10 = nullptr;
  this->m_pLabel = v10;
  v11 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v11 != nullptr )
    v12 = vgui::Label::Label(this: v11, parent: this, panelName: "Memory", text: &var);
  else
    v12 = nullptr;
  this->m_pMemory = v12;
  v13 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: this, panelName: "FPS", text: &var);
  else
    v14 = nullptr;
  this->m_pFPS = v14;
  v15 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v15 != nullptr )
    v16 = vgui::Label::Label(this: v15, parent: this, panelName: "GameTime", text: &var);
  else
    v16 = nullptr;
  this->m_pGameTime = v16;
  vgui::Panel::MakePopup(this, showTaskbarIcon: 0, disabled: 0);
  V_snprintf(pDest: v18, maxLen: 0x100u, pFormat: "[mem: %.2f Mb]", 9.99899959564209);
  this->m_pMemory->SetText(this: this->m_pMemory, a2: v18);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C3510
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseStatusBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseStatusBar::GetMessageMap(CBaseStatusBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseStatusBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseStatusBar::GetMessageMap'::`2'::s_pMap;
  `CBaseStatusBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseStatusBar");
  `CBaseStatusBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C3540
// Name: public: virtual struct PanelAnimationMap __near * CBaseStatusBar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseStatusBar::GetAnimMap(CBaseStatusBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseStatusBar");
}

//------------------------------------------------------------------------------
// Address: 0x102C3550
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseStatusBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseStatusBar::GetKBMap(CBaseStatusBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseStatusBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseStatusBar::GetKBMap'::`2'::s_pMap;
  `CBaseStatusBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseStatusBar");
  `CBaseStatusBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C35B0
// Name: private: virtual void CBaseStatusBar::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CBaseStatusBar::OnThink(CBaseStatusBar *this@<ecx>, int a2@<ebx>)
{
  double v3; // st7
  double v4; // st7
  HANDLE CurrentProcess; // eax
  float v6; // xmm0_4
  char v7[16]; // [esp+Ch] [ebp-14Ch] BYREF
  char v8[16]; // [esp+10Ch] [ebp-4Ch] BYREF
  char gt[32]; // [esp+11Ch] [ebp-3Ch] BYREF
  float fps_16; // [esp+154h] [ebp-4h] OVERLAPPED

  vgui::Panel::OnThink(this, a2, a3: (int)this);
  fps_16 = enginetools->GetRealTime(this: enginetools);
  v3 = ((double (__thiscall *)(IEngineTool *))enginetools->ServerTime)(a1: enginetools);
  V_snprintf(pDest: v8, maxLen: 0x20u, pFormat: "[game: %.3f]", v3);
  this->m_pGameTime->SetText(this: this->m_pGameTime, a2: v8);
  if ( fps_16 - this->m_flLastFPSSnapShot >= 0.40000001 )
  {
    this->m_flLastFPSSnapShot = fps_16;
    v4 = ((double (__thiscall *)(IEngineTool *))enginetools->GetRealFrameTime)(a1: enginetools);
    fps_16 = v4;
    if ( v4 > 0.0 )
    {
      V_snprintf(pDest: &gt[24], maxLen: 0x20u, pFormat: "[fps:  %.1f]", (float)(1.0 / fps_16));
      ((void (__stdcall *)(char *))this->m_pFPS->SetText)(a1: &gt[24]);
    }
    else
    {
      ((void (__stdcall *)(const char *))this->m_pFPS->SetText)(a1: "[fps: ??]");
    }
    *(_DWORD *)&gt[16] = 40;
    CurrentProcess = GetCurrentProcess();
    if ( GetProcessMemoryInfo(a1: (int)CurrentProcess, a2: (int)&gt[16], a3: 40) != 0 )
    {
      fps_16 = (double)*(unsigned int *)&gt[28] * 0.00000095367432;
      v6 = fps_16;
    }
    else
    {
      v6 = 0.0;
    }
    V_snprintf(pDest: v7, maxLen: 0x100u, pFormat: "[mem: %.2f Mb]", v6);
    this->m_pMemory->SetText(this: this->m_pMemory, a2: v7);
  }
}
