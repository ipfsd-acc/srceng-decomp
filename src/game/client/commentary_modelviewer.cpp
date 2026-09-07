// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/commentary_modelviewer.cpp
// Functions: 14
// ============================================================

#include "game\client\commentary_modelviewer.h"

//------------------------------------------------------------------------------
// Address: 0x100C4B60
// Name: public: static char const __near * CCommentaryModelViewer::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCommentaryModelViewer::GetPanelClassName()
{
  return "CCommentaryModelViewer";
}

//------------------------------------------------------------------------------
// Address: 0x100C4B70
// Name: public: virtual char const __near * CCommentaryModelViewer::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCommentaryModelViewer::GetName(CCommentaryModelViewer *this)
{
  return "commentary_modelviewer";
}

//------------------------------------------------------------------------------
// Address: 0x100C4B80
// Name: public: virtual void CCommentaryModelViewer::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryModelViewer::ApplySchemeSettings(CCommentaryModelViewer *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(this, a2: "Resource/UI/CommentaryModelViewer.res", a3: nullptr, a4: nullptr, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100C4BB0
// Name: public: virtual void CCommentaryModelViewer::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryModelViewer::PerformLayout(CCommentaryModelViewer *this)
{
  vgui::Panel *v2; // eax
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  v2 = this->GetParent(this);
  vgui::Panel::GetSize(this: v2, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: w, tall: h);
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C4C00
// Name: public: virtual void CCommentaryModelViewer::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryModelViewer::ShowPanel(CCommentaryModelViewer *this, int bShow)
{
  int v3; // eax
  char *v4; // ecx

  if ( vgui::Panel::IsVisible(this: (CCommentaryModelViewer *)((char *)this - 528)) != (_BYTE)bShow )
  {
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
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_OnCommand_register + 16))(
      a1: *(_DWORD *)&this->m_OnCommand_register,
      a2: bShow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4C70
// Name: public: virtual void CCommentaryModelViewer::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryModelViewer::OnCommand(CCommentaryModelViewer *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "vguicancel") != 0 )
    engine->ClientCmd(this: engine, a2: command);
  this->Close(this);
  this->m_pViewPort->ShowBackGround(this: this->m_pViewPort, a2: false);
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x100C4CD0
// Name: public: virtual void CCommentaryModelViewer::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryModelViewer::OnKeyCodePressed(CCommentaryModelViewer *this, ButtonCode_t code)
{
  switch ( code )
  {
    case KEY_ENTER:
      this->Close(this);
      this->m_pViewPort->ShowBackGround(this: this->m_pViewPort, a2: false);
      break;
    case KEY_SPACE:
      this->m_bTranslating = !this->m_bTranslating;
      break;
    case KEY_R:
LABEL_9:
      break;
    default:
      vgui::Panel::OnKeyCodePressed(this, code);
      goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4D30
// Name: public: void CCommentaryModelViewer::HandleMovementInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryModelViewer::HandleMovementInput(CCommentaryModelViewer *this)
{
  bool v2; // bl
  bool v3; // al
  float v4; // xmm0_4
  double v5; // xmm0_8
  float v6; // xmm0_4
  float m_flYawSpeed; // xmm0_4
  double v8; // xmm0_8
  double v9; // xmm0_8
  bool v10; // cc
  float v11; // xmm0_4
  double v12; // xmm0_8
  float v13; // xmm0_4
  float m_flZoomSpeed; // xmm0_4
  double v15; // xmm0_8
  double v16; // xmm0_8
  bool v17; // cc
  bool bForwardDown; // [esp+Ah] [ebp-2h]
  bool bRightDown; // [esp+Bh] [ebp-1h]

  v2 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LEFT);
  bRightDown = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RIGHT);
  bForwardDown = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_UP);
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_DOWN);
  if ( v2 )
  {
    if ( this->m_flYawSpeed > 0.0 )
      this->m_flYawSpeed = 0.0;
    v4 = this->m_flYawSpeed - 0.050000001;
    if ( v4 <= -3.0 )
      v5 = -3.0;
    else
      v5 = v4;
LABEL_13:
    this->m_flYawSpeed = v5;
    goto LABEL_14;
  }
  if ( bRightDown )
  {
    if ( this->m_flYawSpeed < 0.0 )
      this->m_flYawSpeed = 0.0;
    v6 = this->m_flYawSpeed + 0.050000001;
    if ( v6 >= 3.0 )
      v5 = 3.0;
    else
      v5 = v6;
    goto LABEL_13;
  }
LABEL_14:
  m_flYawSpeed = this->m_flYawSpeed;
  if ( m_flYawSpeed != 0.0 && !v2 && !bRightDown )
  {
    v10 = m_flYawSpeed <= 0.0;
    v8 = m_flYawSpeed;
    if ( v10 )
    {
      v9 = v8 + 0.1;
      v10 = v9 <= 0.0;
    }
    else
    {
      v9 = v8 - 0.1;
      v10 = v9 >= 0.0;
    }
    if ( !v10 )
      v9 = 0.0;
    this->m_flYawSpeed = v9;
  }
  if ( bForwardDown )
  {
    if ( this->m_flZoomSpeed > 0.0 )
      this->m_flZoomSpeed = 0.0;
    v11 = this->m_flZoomSpeed - 0.050000001;
    if ( v11 <= -3.0 )
      v12 = -3.0;
    else
      v12 = v11;
LABEL_35:
    this->m_flZoomSpeed = v12;
    goto LABEL_36;
  }
  if ( v3 )
  {
    if ( this->m_flZoomSpeed < 0.0 )
      this->m_flZoomSpeed = 0.0;
    v13 = this->m_flZoomSpeed + 0.050000001;
    if ( v13 >= 3.0 )
      v12 = 3.0;
    else
      v12 = v13;
    goto LABEL_35;
  }
LABEL_36:
  m_flZoomSpeed = this->m_flZoomSpeed;
  if ( m_flZoomSpeed != 0.0 && !bForwardDown && !v3 )
  {
    v10 = m_flZoomSpeed <= 0.0;
    v15 = m_flZoomSpeed;
    if ( v10 )
    {
      v16 = v15 + 0.1;
      v17 = v16 <= 0.0;
    }
    else
    {
      v16 = v15 - 0.1;
      v17 = v16 >= 0.0;
    }
    if ( !v17 )
      v16 = 0.0;
    this->m_flZoomSpeed = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4F30
// Name: public: virtual struct vgui::PanelMessageMap __near * CCommentaryModelViewer::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCommentaryModelViewer::GetMessageMap(CCommentaryModelViewer *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCommentaryModelViewer::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryModelViewer::GetMessageMap'::`2'::s_pMap;
  `CCommentaryModelViewer::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCommentaryModelViewer");
  `CCommentaryModelViewer::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4F60
// Name: public: virtual struct PanelAnimationMap __near * CCommentaryModelViewer::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCommentaryModelViewer::GetAnimMap(CCommentaryModelViewer *this)
{
  return FindOrAddPanelAnimationMap(className: "CCommentaryModelViewer");
}

//------------------------------------------------------------------------------
// Address: 0x100C4F70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCommentaryModelViewer::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCommentaryModelViewer::GetKBMap(CCommentaryModelViewer *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCommentaryModelViewer::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryModelViewer::GetKBMap'::`2'::s_pMap;
  `CCommentaryModelViewer::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryModelViewer");
  `CCommentaryModelViewer::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4FA0
// Name: public: CCommentaryModelViewer::CCommentaryModelViewer(class IViewPort __near *)
// Source: json
//------------------------------------------------------------------------------
CCommentaryModelViewer *__thiscall CCommentaryModelViewer::CCommentaryModelViewer(
        CCommentaryModelViewer *this,
        IViewPort *pViewPort)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  vgui::Frame::Frame(this, parent: nullptr, panelName: "commentary_modelviewer", showTaskbarIcon: true, bPopup: true);
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CCommentaryModelViewer_vtbl *)&CCommentaryModelViewer::`vftable'{for `vgui::Frame'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CCommentaryModelViewer::`vftable'{for `IViewPortPanel'};
  if ( `CCommentaryModelViewer::ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryModelViewer::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CCommentaryModelViewer");
    v3->pfnClassName = CCommentaryModelViewer::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CCommentaryModelViewer::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCommentaryModelViewer::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CCommentaryModelViewer");
    v4->pfnClassName = CCommentaryModelViewer::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CCommentaryModelViewer::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryModelViewer::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryModelViewer");
    v5->pfnClassName = CCommentaryModelViewer::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pViewPort = pViewPort;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C50F0
// Name: public: virtual void CCommentaryModelViewer::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryModelViewer::OnThink(CCommentaryModelViewer *this)
{
  CCommentaryModelViewer::HandleMovementInput(this);
  vgui::Frame::OnThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C5100
// Name: void CommentaryShowModelViewer(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommentaryShowModelViewer(const CCommand *args)
{
  IClientMode *ClientMode; // eax
  vgui::Panel *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v5; // edi

  if ( args->m_nArgc >= 2 )
  {
    ClientMode = GetClientMode();
    v2 = ClientMode->GetViewport(this: ClientMode);
    v3 = __RTDynamicCast(
           inptr: v2,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &CBaseViewport `RTTI Type Descriptor',
           isReference: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v5 = (*(int (__thiscall **)(_DWORD *, const char *))(v3[95] + 20))(a1: v3 + 95, a2: "commentary_modelviewer");
      if ( v5 != 0
        || (v5 = (*(int (__thiscall **)(_DWORD *, const char *))(*v4 + 944))(a1: v4, a2: "commentary_modelviewer"),
            (*(void (__thiscall **)(_DWORD *, int, const char *))(*v4 + 952))(
              a1: v4,
              a2: v5,
              a3: "PANEL_COMMENTARY_MODELVIEWER"),
            v5 != 0) )
      {
        (*(void (__thiscall **)(_DWORD *, int, int))(v4[95] + 4))(a1: v4 + 95, a2: v5, a3: 1);
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage: commentary_showmodelviewer <model name> <optional attached model name>\n");
  }
}
