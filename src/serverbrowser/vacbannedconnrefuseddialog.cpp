// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/vacbannedconnrefuseddialog.cpp
// Functions: 6
// ============================================================

#include "serverbrowser\vacbannedconnrefuseddialog.h"

//------------------------------------------------------------------------------
// Address: 0x10017510
// Name: public: static char const __near * CVACBannedConnRefusedDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVACBannedConnRefusedDialog::GetPanelClassName()
{
  return "CVACBannedConnRefusedDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10017520
// Name: public: CVACBannedConnRefusedDialog::CVACBannedConnRefusedDialog(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVACBannedConnRefusedDialog *__thiscall CVACBannedConnRefusedDialog::CVACBannedConnRefusedDialog(
        CVACBannedConnRefusedDialog *this,
        unsigned int hVParent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Frame::Frame(this, parent: nullptr, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CVACBannedConnRefusedDialog_vtbl *)&CVACBannedConnRefusedDialog::`vftable';
  if ( `CVACBannedConnRefusedDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CVACBannedConnRefusedDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVACBannedConnRefusedDialog");
    v4->pfnClassName = CVACBannedConnRefusedDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CVACBannedConnRefusedDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVACBannedConnRefusedDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVACBannedConnRefusedDialog");
    v5->pfnClassName = CVACBannedConnRefusedDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CVACBannedConnRefusedDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVACBannedConnRefusedDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVACBannedConnRefusedDialog");
    v6->pfnClassName = CVACBannedConnRefusedDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Panel::SetParent(this, newParent: hVParent);
  vgui::Panel::SetSize(this, wide: 480, tall: 220);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "servers/VACBannedConnRefusedDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017620
// Name: public: virtual struct vgui::PanelMessageMap __near * CVACBannedConnRefusedDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVACBannedConnRefusedDialog::GetMessageMap(CVACBannedConnRefusedDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVACBannedConnRefusedDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVACBannedConnRefusedDialog::GetMessageMap'::`2'::s_pMap;
  `CVACBannedConnRefusedDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVACBannedConnRefusedDialog");
  `CVACBannedConnRefusedDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017650
// Name: public: virtual struct PanelAnimationMap __near * CVACBannedConnRefusedDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVACBannedConnRefusedDialog::GetAnimMap(CVACBannedConnRefusedDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CVACBannedConnRefusedDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10017660
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVACBannedConnRefusedDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVACBannedConnRefusedDialog::GetKBMap(CVACBannedConnRefusedDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVACBannedConnRefusedDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVACBannedConnRefusedDialog::GetKBMap'::`2'::s_pMap;
  `CVACBannedConnRefusedDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVACBannedConnRefusedDialog");
  `CVACBannedConnRefusedDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001768C
// Name: htonl(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
u_long __stdcall htonl(u_long hostlong)
{
  return __imp__htonl@4(hostlong);
}
