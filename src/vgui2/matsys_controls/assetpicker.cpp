// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/assetpicker.cpp
// Functions: 10
// ============================================================

#include "vgui2\matsys_controls\assetpicker.h"

//------------------------------------------------------------------------------
// Address: 0x004BFD40
// Name: public: static char const __near * CAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPicker::GetPanelClassName()
{
  return "CAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004BFD50
// Name: public: static char const __near * CAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPickerFrame::GetPanelClassName()
{
  return "CAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004BFD60
// Name: public: CAssetPicker::CAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPicker *__thiscall CAssetPicker::CAssetPicker(
        CAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  CBaseAssetPicker::CBaseAssetPicker(this, pParent, pAssetType, pExt, pSubDir, pTextType, pAssetSearchPath: "GAME");
  this->__vftable = (CAssetPicker_vtbl *)&CAssetPicker::`vftable';
  if ( `CAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
    v7->pfnClassName = CAssetPicker::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CAssetPicker");
    v8->pfnClassName = CAssetPicker::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
    v9->pfnClassName = CAssetPicker::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CBaseAssetPicker::CreateStandardControls(this, pParent: this, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpicker.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BFE50
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPicker::GetMessageMap(CAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
  `CAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BFE80
// Name: public: virtual struct PanelAnimationMap __near * CAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPicker::GetAnimMap(CAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004BFE90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPicker::GetKBMap(CAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetKBMap'::`2'::s_pMap;
  `CAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
  `CAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BFEC0
// Name: public: CAssetPickerFrame::CAssetPickerFrame(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPickerFrame *__thiscall CAssetPickerFrame::CAssetPickerFrame(
        CAssetPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  CAssetPicker *v11; // eax
  CAssetPicker *v12; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CAssetPickerFrame_vtbl *)&CAssetPickerFrame::`vftable';
  if ( `CAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
    v8->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
    v9->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
    v10->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v11 = (CAssetPicker *)MemAlloc_Alloc(nSize: 0x244u);
  if ( v11 != nullptr )
    v12 = CAssetPicker::CAssetPicker(this: v11, pParent: this, pAssetType, pExt, pSubDir, pTextType);
  else
    v12 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v12);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BFFD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPickerFrame::GetMessageMap(CAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C0000
// Name: public: virtual struct PanelAnimationMap __near * CAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPickerFrame::GetAnimMap(CAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004C0010
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPickerFrame::GetKBMap(CAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102164B0
// Name: public: static char const __near * CAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPicker::GetPanelClassName()
{
  return "CAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x102164C0
// Name: public: static char const __near * CAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPickerFrame::GetPanelClassName()
{
  return "CAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x102164D0
// Name: public: CAssetPicker::CAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPicker *__thiscall CAssetPicker::CAssetPicker(
        CAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  CBaseAssetPicker::CBaseAssetPicker(this, pParent, pAssetType, pExt, pSubDir, pTextType, pAssetSearchPath: "GAME");
  this->__vftable = (CAssetPicker_vtbl *)&CAssetPicker::`vftable';
  if ( `CAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
    v7->pfnClassName = CAssetPicker::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CAssetPicker");
    v8->pfnClassName = CAssetPicker::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
    v9->pfnClassName = CAssetPicker::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CBaseAssetPicker::CreateStandardControls(this, pParent: this, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpicker.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102165C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPicker::GetMessageMap(CAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
  `CAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102165F0
// Name: public: virtual struct PanelAnimationMap __near * CAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPicker::GetAnimMap(CAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x10216600
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPicker::GetKBMap(CAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetKBMap'::`2'::s_pMap;
  `CAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
  `CAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10216660
// Name: public: CAssetPickerFrame::CAssetPickerFrame(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPickerFrame *__thiscall CAssetPickerFrame::CAssetPickerFrame(
        CAssetPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  CAssetPicker *v11; // eax
  CAssetPicker *v12; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CAssetPickerFrame_vtbl *)&CAssetPickerFrame::`vftable';
  if ( `CAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
    v8->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
    v9->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
    v10->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v11 = (CAssetPicker *)operator new(nSize: 0x244u);
  if ( v11 != nullptr )
    v12 = CAssetPicker::CAssetPicker(this: v11, pParent: this, pAssetType, pExt, pSubDir, pTextType);
  else
    v12 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v12);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10216770
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPickerFrame::GetMessageMap(CAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102167A0
// Name: public: virtual struct PanelAnimationMap __near * CAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPickerFrame::GetAnimMap(CAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x102167B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPickerFrame::GetKBMap(CAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004169C0
// Name: public: static char const __near * CAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPicker::GetPanelClassName()
{
  return "CAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004169D0
// Name: public: static char const __near * CAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPickerFrame::GetPanelClassName()
{
  return "CAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004169E0
// Name: public: CAssetPicker::CAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPicker *__thiscall CAssetPicker::CAssetPicker(
        CAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  CBaseAssetPicker::CBaseAssetPicker(this, pParent, pAssetType, pExt, pSubDir, pTextType, pAssetSearchPath: "GAME");
  this->__vftable = (CAssetPicker_vtbl *)&CAssetPicker::`vftable';
  if ( `CAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
    v7->pfnClassName = CAssetPicker::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CAssetPicker");
    v8->pfnClassName = CAssetPicker::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
    v9->pfnClassName = CAssetPicker::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CBaseAssetPicker::CreateStandardControls(this, pParent: this, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpicker.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416AD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPicker::GetMessageMap(CAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
  `CAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416B00
// Name: public: virtual struct PanelAnimationMap __near * CAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPicker::GetAnimMap(CAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x00416B10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPicker::GetKBMap(CAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetKBMap'::`2'::s_pMap;
  `CAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
  `CAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416B70
// Name: public: CAssetPickerFrame::CAssetPickerFrame(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPickerFrame *__thiscall CAssetPickerFrame::CAssetPickerFrame(
        CAssetPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  CAssetPicker *v11; // eax
  CAssetPicker *v12; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CAssetPickerFrame_vtbl *)&CAssetPickerFrame::`vftable';
  if ( `CAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
    v8->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
    v9->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
    v10->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v11 = (CAssetPicker *)operator new(nSize: 0x244u);
  if ( v11 != nullptr )
    v12 = CAssetPicker::CAssetPicker(this: v11, pParent: this, pAssetType, pExt, pSubDir, pTextType);
  else
    v12 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v12);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416C80
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPickerFrame::GetMessageMap(CAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416CB0
// Name: public: virtual struct PanelAnimationMap __near * CAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPickerFrame::GetAnimMap(CAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00416CC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPickerFrame::GetKBMap(CAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004D4310
// Name: public: static char const __near * CAssetPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPicker::GetPanelClassName()
{
  return "CAssetPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004D4320
// Name: public: static char const __near * CAssetPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAssetPickerFrame::GetPanelClassName()
{
  return "CAssetPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004D4330
// Name: public: CAssetPicker::CAssetPicker(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPicker *__thiscall CAssetPicker::CAssetPicker(
        CAssetPicker *this,
        vgui::Panel *pParent,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  CBaseAssetPicker::CBaseAssetPicker(this, pParent, pAssetType, pExt, pSubDir, pTextType, pAssetSearchPath: "GAME");
  this->__vftable = (CAssetPicker_vtbl *)&CAssetPicker::`vftable';
  if ( `CAssetPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
    v7->pfnClassName = CAssetPicker::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPicker::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CAssetPicker");
    v8->pfnClassName = CAssetPicker::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CAssetPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPicker::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
    v9->pfnClassName = CAssetPicker::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CBaseAssetPicker::CreateStandardControls(this, pParent: this, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpicker.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D4420
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPicker::GetMessageMap(CAssetPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetMessageMap'::`2'::s_pMap;
  `CAssetPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPicker");
  `CAssetPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D4450
// Name: public: virtual struct PanelAnimationMap __near * CAssetPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPicker::GetAnimMap(CAssetPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004D4460
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPicker::GetKBMap(CAssetPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPicker::GetKBMap'::`2'::s_pMap;
  `CAssetPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPicker");
  `CAssetPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D4490
// Name: public: CAssetPickerFrame::CAssetPickerFrame(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAssetPickerFrame *__thiscall CAssetPickerFrame::CAssetPickerFrame(
        CAssetPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pAssetType,
        const char *pExt,
        const char *pSubDir,
        const char *pTextType)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  CAssetPicker *v11; // eax
  CAssetPicker *v12; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CAssetPickerFrame_vtbl *)&CAssetPickerFrame::`vftable';
  if ( `CAssetPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
    v8->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
    v9->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CAssetPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAssetPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
    v10->pfnClassName = CAssetPickerFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v11 = (CAssetPicker *)MemAlloc_Alloc(nSize: 0x244u);
  if ( v11 != nullptr )
    v12 = CAssetPicker::CAssetPicker(this: v11, pParent: this, pAssetType, pExt, pSubDir, pTextType);
  else
    v12 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v12);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/assetpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D45A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAssetPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAssetPickerFrame::GetMessageMap(CAssetPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D45D0
// Name: public: virtual struct PanelAnimationMap __near * CAssetPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAssetPickerFrame::GetAnimMap(CAssetPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CAssetPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004D45E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAssetPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAssetPickerFrame::GetKBMap(CAssetPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAssetPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAssetPickerFrame::GetKBMap'::`2'::s_pMap;
  `CAssetPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAssetPickerFrame");
  `CAssetPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
