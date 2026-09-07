// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/curveeditorpanel.cpp
// Functions: 11
// ============================================================

#include "vgui2\matsys_controls\curveeditorpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10263A20
// Name: public: static char const __near * CCurveEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCurveEditorPanel::GetPanelClassName()
{
  return "CCurveEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10263A30
// Name: public: virtual CCurveEditorPanel::~CCurveEditorPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::~CCurveEditorPanel(CCurveEditorPanel *this)
{
  this->__vftable = (CCurveEditorPanel_vtbl *)&CCurveEditorPanel::`vftable';
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10263A40
// Name: public: virtual void CCurveEditorPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::OnMousePressed(CCurveEditorPanel *this, const char *code)
{
  const char *v2; // edi
  const char *v4; // edi
  int v5; // ebx
  int v6; // [esp+18h] [ebp-14h] BYREF
  int v7; // [esp+1Ch] [ebp-10h] BYREF
  int v8; // [esp+20h] [ebp-Ch] BYREF
  int v9; // [esp+24h] [ebp-8h] BYREF
  int var4[2]; // [esp+28h] [ebp-4h] BYREF

  v2 = code;
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: var4, a3: (int *)&code);
  vgui::Panel::ScreenToLocal(this, x: var4, y: (int *)&code);
  if ( v2 == (const char *)107 )
  {
    vgui::Panel::GetSize(this, wide: &v9, tall: &v6);
    v4 = code;
    v5 = var4[0];
    vgui::Panel::GetSize(this, wide: &v7, tall: &v8);
    this->m_nSelectedPoint = ((int (__thiscall *)(CCurveEditorPanel *, _DWORD, _DWORD, _DWORD))this->FindOrAddControlPoint)(
                               a1: this,
                               a2: (float)v5 / (float)(v7 - 1),
                               a3: 5.0 / (float)(v9 - 1),
                               a4: 1.0 - (float)((float)(int)v4 / (float)(v8 - 1)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263B30
// Name: public: virtual void CCurveEditorPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::OnMouseReleased(CCurveEditorPanel *this, const char *code)
{
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( code == (const char *)107 )
    this->m_nSelectedPoint = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10263B60
// Name: public: virtual void CCurveEditorPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::OnCursorMoved(CCurveEditorPanel *this, int x, int y)
{
  int v3; // ebx
  int v4; // edi
  int m_nSelectedPoint; // eax
  int v7; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h] BYREF

  v3 = y;
  v4 = x;
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: (KeyValues *)y);
  vgui::Panel::GetSize(this, wide: &y, tall: &v8);
  *(float *)&y = (float)v4 / (float)(y - 1);
  vgui::Panel::GetSize(this, wide: &x, tall: &v7);
  this->m_nHighlightedPoint = ((int (__thiscall *)(CCurveEditorPanel *, int, _DWORD))this->FindControlPoint)(
                                a1: this,
                                a2: y,
                                a3: 5.0 / (float)(x - 1));
  m_nSelectedPoint = this->m_nSelectedPoint;
  if ( m_nSelectedPoint >= 0 )
    this->m_nSelectedPoint = ((int (__thiscall *)(CCurveEditorPanel *, int, int, _DWORD))this->ModifyControlPoint)(
                               a1: this,
                               a2: m_nSelectedPoint,
                               a3: y,
                               a4: 1.0 - (float)((float)v3 / (float)(v8 - 1)));
}

//------------------------------------------------------------------------------
// Address: 0x10263C50
// Name: public: virtual void CCurveEditorPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::OnKeyCodePressed(CCurveEditorPanel *this, ButtonCode_t code)
{
  vgui::Panel::OnKeyCodePressed(this, code);
  if ( this->m_nSelectedPoint >= 0 )
  {
    this->RemoveControlPoint(this, a2: this->m_nSelectedPoint);
    this->m_nSelectedPoint = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263E40
// Name: public: virtual struct vgui::PanelMessageMap __near * CCurveEditorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCurveEditorPanel::GetMessageMap(CCurveEditorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCurveEditorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCurveEditorPanel::GetMessageMap'::`2'::s_pMap;
  `CCurveEditorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCurveEditorPanel");
  `CCurveEditorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10263E70
// Name: public: virtual struct PanelAnimationMap __near * CCurveEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCurveEditorPanel::GetAnimMap(CCurveEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CCurveEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10263E80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCurveEditorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCurveEditorPanel::GetKBMap(CCurveEditorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCurveEditorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCurveEditorPanel::GetKBMap'::`2'::s_pMap;
  `CCurveEditorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCurveEditorPanel");
  `CCurveEditorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10263EB0
// Name: public: CCurveEditorPanel::CCurveEditorPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCurveEditorPanel *__thiscall CCurveEditorPanel::CCurveEditorPanel(
        CCurveEditorPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CCurveEditorPanel_vtbl *)&CCurveEditorPanel::`vftable';
  if ( `CCurveEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CCurveEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CCurveEditorPanel");
    v4->pfnClassName = CCurveEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CCurveEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCurveEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CCurveEditorPanel");
    v5->pfnClassName = CCurveEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CCurveEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCurveEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CCurveEditorPanel");
    v6->pfnClassName = CCurveEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_nSelectedPoint = -1;
  vgui::Panel::SetMouseInputEnabled(this, state: 1);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  this->m_nHighlightedPoint = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10263FC0
// Name: public: virtual void CCurveEditorPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::Paint(CCurveEditorPanel *this)
{
  void (__thiscall *DrawSetColor_2)(vgui::ISurface *, int, int, int, int); // eax
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int m_nSelectedPoint; // eax
  float v11; // [esp+10h] [ebp-24h]
  int v12; // [esp+14h] [ebp-20h] BYREF
  float v13; // [esp+18h] [ebp-1Ch]
  int v14; // [esp+1Ch] [ebp-18h] BYREF
  float v15; // [esp+20h] [ebp-14h] BYREF
  int v16; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int v18; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &tall, tall: &v16);
  DrawSetColor_2 = g_pVGuiSurface->DrawSetColor_2;
  v3 = 0;
  wide = 0;
  v18 = 0;
  DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  v4 = tall;
  if ( tall > 0 )
  {
    do
    {
      v15 = ((double (__thiscall *)(CCurveEditorPanel *, _DWORD))this->GetValue)(
              a1: this,
              a2: (float)v3 / (float)(v4 - 1));
      v5 = v16 - (int)(float)((float)((float)(v16 - 1) * v15) + 0.5) - 1;
      if ( v5 >= 0 )
      {
        v6 = v16 - 1;
        if ( v5 <= v16 - 1 )
          v6 = v16 - (int)(float)((float)((float)(v16 - 1) * v15) + 0.5) - 1;
      }
      else
      {
        v6 = 0;
      }
      if ( v3 != 0 )
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: wide, a3: v18, a4: v3, a5: v6);
      v4 = tall;
      wide = v3++;
      v18 = v6;
    }
    while ( v3 < tall );
  }
  v7 = this->ControlPointCount(this) - 1;
  wide = v7;
  if ( v7 >= 0 )
  {
    while ( 1 )
    {
      this->GetControlPoint(this, a2: v7, a3: &v15, a4: (float *)&v18);
      v13 = v15;
      v11 = *(float *)&v18;
      vgui::Panel::GetSize(this, wide: &v14, tall: &v12);
      v8 = (int)(float)((float)((float)(v14 - 1) * v13) + 0.5);
      v9 = v12 - (int)(float)((float)((float)(v12 - 1) * v11) + 0.5) - 1;
      m_nSelectedPoint = this->m_nSelectedPoint;
      if ( wide == m_nSelectedPoint || m_nSelectedPoint == -1 && wide == this->m_nHighlightedPoint )
      {
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v8 - 3, a3: v9 - 3, a4: v8 + 3, a5: v9 + 3);
      }
      else
      {
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v8 - 3, a3: v9 - 3, a4: v8 + 3, a5: v9 + 3);
      }
      if ( --wide < 0 )
        break;
      v7 = wide;
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10263A50
// Name: public: static char const __near * CCurveEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCurveEditorPanel::GetPanelClassName()
{
  return "CCurveEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10263A60
// Name: public: virtual CCurveEditorPanel::~CCurveEditorPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::~CCurveEditorPanel(CCurveEditorPanel *this)
{
  this->__vftable = (CCurveEditorPanel_vtbl *)&CCurveEditorPanel::`vftable';
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10263A70
// Name: public: virtual void CCurveEditorPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::OnMousePressed(CCurveEditorPanel *this, const char *code)
{
  const char *v2; // edi
  const char *v4; // edi
  int v5; // ebx
  int v6; // [esp+18h] [ebp-14h] BYREF
  int v7; // [esp+1Ch] [ebp-10h] BYREF
  int v8; // [esp+20h] [ebp-Ch] BYREF
  int v9; // [esp+24h] [ebp-8h] BYREF
  int var4[2]; // [esp+28h] [ebp-4h] BYREF

  v2 = code;
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: var4, a3: (int *)&code);
  vgui::Panel::ScreenToLocal(this, x: var4, y: (int *)&code);
  if ( v2 == (const char *)107 )
  {
    vgui::Panel::GetSize(this, wide: &v9, tall: &v6);
    v4 = code;
    v5 = var4[0];
    vgui::Panel::GetSize(this, wide: &v7, tall: &v8);
    this->m_nSelectedPoint = ((int (__thiscall *)(CCurveEditorPanel *, _DWORD, _DWORD, _DWORD))this->FindOrAddControlPoint)(
                               a1: this,
                               a2: (float)v5 / (float)(v7 - 1),
                               a3: 5.0 / (float)(v9 - 1),
                               a4: 1.0 - (float)((float)(int)v4 / (float)(v8 - 1)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263B90
// Name: public: virtual void CCurveEditorPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::OnCursorMoved(CCurveEditorPanel *this, int x, int y)
{
  int v3; // ebx
  int v4; // edi
  int m_nSelectedPoint; // eax
  int v7; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h] BYREF

  v3 = y;
  v4 = x;
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: (KeyValues *)y);
  vgui::Panel::GetSize(this, wide: &y, tall: &v8);
  *(float *)&y = (float)v4 / (float)(y - 1);
  vgui::Panel::GetSize(this, wide: &x, tall: &v7);
  this->m_nHighlightedPoint = ((int (__thiscall *)(CCurveEditorPanel *, int, _DWORD))this->FindControlPoint)(
                                a1: this,
                                a2: y,
                                a3: 5.0 / (float)(x - 1));
  m_nSelectedPoint = this->m_nSelectedPoint;
  if ( m_nSelectedPoint >= 0 )
    this->m_nSelectedPoint = ((int (__thiscall *)(CCurveEditorPanel *, int, int, _DWORD))this->ModifyControlPoint)(
                               a1: this,
                               a2: m_nSelectedPoint,
                               a3: y,
                               a4: 1.0 - (float)((float)v3 / (float)(v8 - 1)));
}

//------------------------------------------------------------------------------
// Address: 0x10263C80
// Name: public: virtual void CCurveEditorPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::OnKeyCodePressed(CCurveEditorPanel *this, ButtonCode_t code)
{
  vgui::Panel::OnKeyCodePressed(this, code);
  if ( this->m_nSelectedPoint >= 0 )
  {
    this->RemoveControlPoint(this, a2: this->m_nSelectedPoint);
    this->m_nSelectedPoint = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263EA0
// Name: public: virtual struct PanelAnimationMap __near * CCurveEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCurveEditorPanel::GetAnimMap(CCurveEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CCurveEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10263EE0
// Name: public: CCurveEditorPanel::CCurveEditorPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCurveEditorPanel *__thiscall CCurveEditorPanel::CCurveEditorPanel(
        CCurveEditorPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CCurveEditorPanel_vtbl *)&CCurveEditorPanel::`vftable';
  if ( `CCurveEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CCurveEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CCurveEditorPanel");
    v4->pfnClassName = CCurveEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CCurveEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCurveEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CCurveEditorPanel");
    v5->pfnClassName = CCurveEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CCurveEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCurveEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CCurveEditorPanel");
    v6->pfnClassName = CCurveEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_nSelectedPoint = -1;
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: true);
  this->m_nHighlightedPoint = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10263FF0
// Name: public: virtual void CCurveEditorPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorPanel::Paint(CCurveEditorPanel *this)
{
  void (__thiscall *DrawSetColor_2)(vgui::ISurface *, int, int, int, int); // eax
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int m_nSelectedPoint; // eax
  float v11; // [esp+10h] [ebp-24h]
  int v12; // [esp+14h] [ebp-20h] BYREF
  float v13; // [esp+18h] [ebp-1Ch]
  int v14; // [esp+1Ch] [ebp-18h] BYREF
  float v15; // [esp+20h] [ebp-14h] BYREF
  int v16; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int v18; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &tall, tall: &v16);
  DrawSetColor_2 = g_pVGuiSurface->DrawSetColor_2;
  v3 = 0;
  wide = 0;
  v18 = 0;
  DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  v4 = tall;
  if ( tall > 0 )
  {
    do
    {
      v15 = ((double (__thiscall *)(CCurveEditorPanel *, _DWORD))this->GetValue)(
              a1: this,
              a2: (float)v3 / (float)(v4 - 1));
      v5 = v16 - (int)(float)((float)((float)(v16 - 1) * v15) + 0.5) - 1;
      if ( v5 >= 0 )
      {
        v6 = v16 - 1;
        if ( v5 <= v16 - 1 )
          v6 = v16 - (int)(float)((float)((float)(v16 - 1) * v15) + 0.5) - 1;
      }
      else
      {
        v6 = 0;
      }
      if ( v3 != 0 )
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: wide, a3: v18, a4: v3, a5: v6);
      v4 = tall;
      wide = v3++;
      v18 = v6;
    }
    while ( v3 < tall );
  }
  v7 = this->ControlPointCount(this) - 1;
  wide = v7;
  if ( v7 >= 0 )
  {
    while ( 1 )
    {
      this->GetControlPoint(this, a2: v7, a3: &v15, a4: (float *)&v18);
      v13 = v15;
      v11 = *(float *)&v18;
      vgui::Panel::GetSize(this, wide: &v14, tall: &v12);
      v8 = (int)(float)((float)((float)(v14 - 1) * v13) + 0.5);
      v9 = v12 - (int)(float)((float)((float)(v12 - 1) * v11) + 0.5) - 1;
      m_nSelectedPoint = this->m_nSelectedPoint;
      if ( wide == m_nSelectedPoint || m_nSelectedPoint == -1 && wide == this->m_nHighlightedPoint )
      {
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v8 - 3, a3: v9 - 3, a4: v8 + 3, a5: v9 + 3);
      }
      else
      {
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v8 - 3, a3: v9 - 3, a4: v8 + 3, a5: v9 + 3);
      }
      if ( --wide < 0 )
        break;
      v7 = wide;
    }
  }
}

} // namespace engine_xlsp
