// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/vtfpicker.cpp
// Functions: 11
// ============================================================

#include "vgui2\matsys_controls\vtfpicker.h"

//------------------------------------------------------------------------------
// Address: 0x004C10D0
// Name: public: static char const __near * CVTFPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPicker::GetPanelClassName()
{
  return "CVTFPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004C10E0
// Name: public: static char const __near * CVTFPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPickerFrame::GetPanelClassName()
{
  return "CVTFPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004C10F0
// Name: private: virtual void CVTFPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPicker::OnSelectedAssetPicked(CVTFPicker *this, const char *pAssetName)
{
  CVTFPreviewPanel::SetVTF(this: this->m_pVTFPreview, pFullPath: pAssetName, bLoadImmediately: true);
}

//------------------------------------------------------------------------------
// Address: 0x004C1110
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPicker::GetMessageMap(CVTFPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPicker::GetMessageMap'::`2'::s_pMap;
  `CVTFPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPicker");
  `CVTFPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1140
// Name: public: virtual struct PanelAnimationMap __near * CVTFPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPicker::GetAnimMap(CVTFPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004C1150
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPicker::GetKBMap(CVTFPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPicker::GetKBMap'::`2'::s_pMap;
  `CVTFPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPicker");
  `CVTFPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1180
// Name: public: CVTFPicker::CVTFPicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPicker *__thiscall CVTFPicker::CVTFPicker(CVTFPicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v9; // edi
  CVTFPreviewPanel *v10; // eax
  CVTFPreviewPanel *v11; // eax

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "VTF Files",
    pExt: "vtf",
    pSubDir: "materials",
    pTextType: "vtfName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CVTFPicker_vtbl *)&CVTFPicker::`vftable';
  if ( `CVTFPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CVTFPicker");
    v3->pfnClassName = CVTFPicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CVTFPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CVTFPicker");
    v4->pfnClassName = CVTFPicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CVTFPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPicker");
    v5->pfnClassName = CVTFPicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  v6 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v7 = nullptr;
  this->m_pPreviewSplitter = v7;
  Child = vgui::Panel::GetChild(this: v7, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (CVTFPreviewPanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v10 != nullptr )
    v11 = CVTFPreviewPanel::CVTFPreviewPanel(this: v10, pParent: v9, pName: "VTFPreview");
  else
    v11 = nullptr;
  this->m_pVTFPreview = v11;
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/vtfpicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1310
// Name: public: CVTFPickerFrame::CVTFPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPickerFrame *__thiscall CVTFPickerFrame::CVTFPickerFrame(
        CVTFPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CVTFPicker *v7; // eax
  CVTFPicker *v8; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CVTFPickerFrame_vtbl *)&CVTFPickerFrame::`vftable';
  if ( `CVTFPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVTFPickerFrame");
    v4->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVTFPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVTFPickerFrame");
    v5->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVTFPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPickerFrame");
    v6->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v7 = (CVTFPicker *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = CVTFPicker::CVTFPicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v8);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/vtfpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1410
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPickerFrame::GetMessageMap(CVTFPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CVTFPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPickerFrame");
  `CVTFPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1440
// Name: public: virtual struct PanelAnimationMap __near * CVTFPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPickerFrame::GetAnimMap(CVTFPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004C1450
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPickerFrame::GetKBMap(CVTFPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPickerFrame::GetKBMap'::`2'::s_pMap;
  `CVTFPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPickerFrame");
  `CVTFPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104CDED0
// Name: public: static char const __near * CVTFPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPicker::GetPanelClassName()
{
  return "CVTFPicker";
}

//------------------------------------------------------------------------------
// Address: 0x104CDEE0
// Name: public: static char const __near * CVTFPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPickerFrame::GetPanelClassName()
{
  return "CVTFPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104CDEF0
// Name: private: virtual void CVTFPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPicker::OnSelectedAssetPicked(CVTFPicker *this, const char *pAssetName)
{
  CVTFPreviewPanel::SetVTF(this: this->m_pVTFPreview, pFullPath: pAssetName, bLoadImmediately: true);
}

//------------------------------------------------------------------------------
// Address: 0x104CDF10
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPicker::GetMessageMap(CVTFPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPicker::GetMessageMap'::`2'::s_pMap;
  `CVTFPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPicker");
  `CVTFPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CDF40
// Name: public: virtual struct PanelAnimationMap __near * CVTFPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPicker::GetAnimMap(CVTFPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPicker");
}

//------------------------------------------------------------------------------
// Address: 0x104CDF50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPicker::GetKBMap(CVTFPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPicker::GetKBMap'::`2'::s_pMap;
  `CVTFPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPicker");
  `CVTFPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CDF80
// Name: public: CVTFPicker::CVTFPicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPicker *__thiscall CVTFPicker::CVTFPicker(CVTFPicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v9; // edi
  CVTFPreviewPanel *v10; // eax
  CVTFPreviewPanel *v11; // eax

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "VTF Files",
    pExt: "vtf",
    pSubDir: "materials",
    pTextType: "vtfName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CVTFPicker_vtbl *)&CVTFPicker::`vftable';
  if ( `CVTFPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CVTFPicker");
    v3->pfnClassName = CVTFPicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CVTFPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CVTFPicker");
    v4->pfnClassName = CVTFPicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CVTFPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPicker");
    v5->pfnClassName = CVTFPicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  v6 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v7 = nullptr;
  this->m_pPreviewSplitter = v7;
  Child = vgui::Panel::GetChild(this: v7, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (CVTFPreviewPanel *)operator new(nSize: 0x17Cu);
  if ( v10 != nullptr )
    v11 = CVTFPreviewPanel::CVTFPreviewPanel(this: v10, pParent: v9, pName: "VTFPreview");
  else
    v11 = nullptr;
  this->m_pVTFPreview = v11;
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/vtfpicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CE110
// Name: public: CVTFPickerFrame::CVTFPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPickerFrame *__thiscall CVTFPickerFrame::CVTFPickerFrame(
        CVTFPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CVTFPicker *v7; // eax
  CVTFPicker *v8; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CVTFPickerFrame_vtbl *)&CVTFPickerFrame::`vftable';
  if ( `CVTFPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVTFPickerFrame");
    v4->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVTFPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVTFPickerFrame");
    v5->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVTFPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPickerFrame");
    v6->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v7 = (CVTFPicker *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = CVTFPicker::CVTFPicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v8);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/vtfpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CE210
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPickerFrame::GetMessageMap(CVTFPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CVTFPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPickerFrame");
  `CVTFPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CE240
// Name: public: virtual struct PanelAnimationMap __near * CVTFPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPickerFrame::GetAnimMap(CVTFPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104CE250
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPickerFrame::GetKBMap(CVTFPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPickerFrame::GetKBMap'::`2'::s_pMap;
  `CVTFPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPickerFrame");
  `CVTFPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004D5670
// Name: public: static char const __near * CVTFPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPicker::GetPanelClassName()
{
  return "CVTFPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004D5680
// Name: public: static char const __near * CVTFPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPickerFrame::GetPanelClassName()
{
  return "CVTFPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004D5690
// Name: private: virtual void CVTFPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPicker::OnSelectedAssetPicked(CVTFPicker *this, const char *pAssetName)
{
  CVTFPreviewPanel::SetVTF(this: this->m_pVTFPreview, pFullPath: pAssetName, bLoadImmediately: true);
}

//------------------------------------------------------------------------------
// Address: 0x004D56B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPicker::GetMessageMap(CVTFPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPicker::GetMessageMap'::`2'::s_pMap;
  `CVTFPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPicker");
  `CVTFPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D56E0
// Name: public: virtual struct PanelAnimationMap __near * CVTFPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPicker::GetAnimMap(CVTFPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004D56F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPicker::GetKBMap(CVTFPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPicker::GetKBMap'::`2'::s_pMap;
  `CVTFPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPicker");
  `CVTFPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5720
// Name: public: CVTFPicker::CVTFPicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPicker *__thiscall CVTFPicker::CVTFPicker(CVTFPicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v9; // edi
  CVTFPreviewPanel *v10; // eax
  CVTFPreviewPanel *v11; // eax

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "VTF Files",
    pExt: "vtf",
    pSubDir: "materials",
    pTextType: "vtfName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CVTFPicker_vtbl *)&CVTFPicker::`vftable';
  if ( `CVTFPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CVTFPicker");
    v3->pfnClassName = CVTFPicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CVTFPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CVTFPicker");
    v4->pfnClassName = CVTFPicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CVTFPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPicker");
    v5->pfnClassName = CVTFPicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  v6 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v7 = nullptr;
  this->m_pPreviewSplitter = v7;
  Child = vgui::Panel::GetChild(this: v7, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (CVTFPreviewPanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v10 != nullptr )
    v11 = CVTFPreviewPanel::CVTFPreviewPanel(this: v10, pParent: v9, pName: "VTFPreview");
  else
    v11 = nullptr;
  this->m_pVTFPreview = v11;
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/vtfpicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D58B0
// Name: public: CVTFPickerFrame::CVTFPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPickerFrame *__thiscall CVTFPickerFrame::CVTFPickerFrame(
        CVTFPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CVTFPicker *v7; // eax
  CVTFPicker *v8; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CVTFPickerFrame_vtbl *)&CVTFPickerFrame::`vftable';
  if ( `CVTFPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVTFPickerFrame");
    v4->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVTFPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVTFPickerFrame");
    v5->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVTFPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPickerFrame");
    v6->pfnClassName = CVTFPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v7 = (CVTFPicker *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = CVTFPicker::CVTFPicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v8);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/vtfpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D59B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPickerFrame::GetMessageMap(CVTFPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CVTFPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPickerFrame");
  `CVTFPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D59E0
// Name: public: virtual struct PanelAnimationMap __near * CVTFPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPickerFrame::GetAnimMap(CVTFPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004D59F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPickerFrame::GetKBMap(CVTFPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPickerFrame::GetKBMap'::`2'::s_pMap;
  `CVTFPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPickerFrame");
  `CVTFPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
