// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/tgapicker.cpp
// Functions: 11
// ============================================================

#include "vgui2\matsys_controls\tgapicker.h"

//------------------------------------------------------------------------------
// Address: 0x004C1480
// Name: public: static char const __near * CTGAPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPicker::GetPanelClassName()
{
  return "CTGAPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004C1490
// Name: public: static char const __near * CTGAPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPickerFrame::GetPanelClassName()
{
  return "CTGAPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004C14A0
// Name: private: virtual void CTGAPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPicker::OnSelectedAssetPicked(CTGAPicker *this, const char *pAssetName)
{
  char pFullPath[260]; // [esp+4h] [ebp-208h] BYREF
  char pRelativePath[260]; // [esp+108h] [ebp-104h] BYREF

  V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "materialsrc\\%s", pAssetName);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: pRelativePath,
    a3: "CONTENT",
    a4: pFullPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  CTGAPreviewPanel::SetTGA(this: this->m_pTGAPreview, pFullPath);
}

//------------------------------------------------------------------------------
// Address: 0x004C1510
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPicker::GetMessageMap(CTGAPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPicker::GetMessageMap'::`2'::s_pMap;
  `CTGAPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPicker");
  `CTGAPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1540
// Name: public: virtual struct PanelAnimationMap __near * CTGAPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPicker::GetAnimMap(CTGAPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004C1550
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPicker::GetKBMap(CTGAPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPicker::GetKBMap'::`2'::s_pMap;
  `CTGAPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPicker");
  `CTGAPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1580
// Name: public: CTGAPicker::CTGAPicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPicker *__thiscall CTGAPicker::CTGAPicker(CTGAPicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v9; // edi
  CTGAPreviewPanel *v10; // eax
  CTGAPreviewPanel *v11; // eax

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "TGA Files",
    pExt: "tga",
    pSubDir: "materialsrc",
    pTextType: "tgaName",
    pAssetSearchPath: "CONTENT");
  this->__vftable = (CTGAPicker_vtbl *)&CTGAPicker::`vftable';
  if ( `CTGAPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CTGAPicker");
    v3->pfnClassName = CTGAPicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CTGAPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CTGAPicker");
    v4->pfnClassName = CTGAPicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CTGAPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPicker");
    v5->pfnClassName = CTGAPicker::GetPanelClassName;
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
  v10 = (CTGAPreviewPanel *)MemAlloc_Alloc(nSize: 0x1D4u);
  if ( v10 != nullptr )
    v11 = CTGAPreviewPanel::CTGAPreviewPanel(this: v10, pParent: v9, pName: "TGAPreview");
  else
    v11 = nullptr;
  this->m_pTGAPreview = v11;
  CProceduralTexturePanel::MaintainProportions(this: v11, bEnable: true);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/tgapicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1710
// Name: public: CTGAPickerFrame::CTGAPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPickerFrame *__thiscall CTGAPickerFrame::CTGAPickerFrame(
        CTGAPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CTGAPicker *v7; // eax
  CTGAPicker *v8; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CTGAPickerFrame_vtbl *)&CTGAPickerFrame::`vftable';
  if ( `CTGAPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTGAPickerFrame");
    v4->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CTGAPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTGAPickerFrame");
    v5->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CTGAPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPickerFrame");
    v6->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v7 = (CTGAPicker *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = CTGAPicker::CTGAPicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v8);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/tgapickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1810
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPickerFrame::GetMessageMap(CTGAPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CTGAPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPickerFrame");
  `CTGAPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1840
// Name: public: virtual struct PanelAnimationMap __near * CTGAPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPickerFrame::GetAnimMap(CTGAPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004C1850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPickerFrame::GetKBMap(CTGAPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPickerFrame::GetKBMap'::`2'::s_pMap;
  `CTGAPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPickerFrame");
  `CTGAPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104CE2B0
// Name: public: static char const __near * CTGAPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPicker::GetPanelClassName()
{
  return "CTGAPicker";
}

//------------------------------------------------------------------------------
// Address: 0x104CE2C0
// Name: public: static char const __near * CTGAPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPickerFrame::GetPanelClassName()
{
  return "CTGAPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104CE2D0
// Name: private: virtual void CTGAPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPicker::OnSelectedAssetPicked(CTGAPicker *this, const char *pAssetName)
{
  char pFullPath[260]; // [esp+4h] [ebp-208h] BYREF
  char pRelativePath[260]; // [esp+108h] [ebp-104h] BYREF

  V_snprintf(pDest: pRelativePath, maxLen: 0x104u, pFormat: "materialsrc\\%s", pAssetName);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: pRelativePath,
    a3: "CONTENT",
    a4: pFullPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  CTGAPreviewPanel::SetTGA(this: this->m_pTGAPreview, pFullPath);
}

//------------------------------------------------------------------------------
// Address: 0x104CE340
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPicker::GetMessageMap(CTGAPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPicker::GetMessageMap'::`2'::s_pMap;
  `CTGAPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPicker");
  `CTGAPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CE370
// Name: public: virtual struct PanelAnimationMap __near * CTGAPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPicker::GetAnimMap(CTGAPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPicker");
}

//------------------------------------------------------------------------------
// Address: 0x104CE380
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPicker::GetKBMap(CTGAPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPicker::GetKBMap'::`2'::s_pMap;
  `CTGAPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPicker");
  `CTGAPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CE3B0
// Name: public: CTGAPicker::CTGAPicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPicker *__thiscall CTGAPicker::CTGAPicker(CTGAPicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v9; // edi
  CTGAPreviewPanel *v10; // eax
  CTGAPreviewPanel *v11; // eax

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "TGA Files",
    pExt: "tga",
    pSubDir: "materialsrc",
    pTextType: "tgaName",
    pAssetSearchPath: "CONTENT");
  this->__vftable = (CTGAPicker_vtbl *)&CTGAPicker::`vftable';
  if ( `CTGAPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CTGAPicker");
    v3->pfnClassName = CTGAPicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CTGAPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CTGAPicker");
    v4->pfnClassName = CTGAPicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CTGAPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPicker");
    v5->pfnClassName = CTGAPicker::GetPanelClassName;
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
  v10 = (CTGAPreviewPanel *)operator new(nSize: 0x1D4u);
  if ( v10 != nullptr )
    v11 = CTGAPreviewPanel::CTGAPreviewPanel(this: v10, pParent: v9, pName: "TGAPreview");
  else
    v11 = nullptr;
  this->m_pTGAPreview = v11;
  CProceduralTexturePanel::MaintainProportions(this: v11, bEnable: true);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/tgapicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CE540
// Name: public: CTGAPickerFrame::CTGAPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPickerFrame *__thiscall CTGAPickerFrame::CTGAPickerFrame(
        CTGAPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CTGAPicker *v7; // eax
  CTGAPicker *v8; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CTGAPickerFrame_vtbl *)&CTGAPickerFrame::`vftable';
  if ( `CTGAPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTGAPickerFrame");
    v4->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CTGAPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTGAPickerFrame");
    v5->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CTGAPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPickerFrame");
    v6->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v7 = (CTGAPicker *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = CTGAPicker::CTGAPicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v8);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/tgapickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CE640
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPickerFrame::GetMessageMap(CTGAPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CTGAPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPickerFrame");
  `CTGAPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CE670
// Name: public: virtual struct PanelAnimationMap __near * CTGAPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPickerFrame::GetAnimMap(CTGAPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104CE680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPickerFrame::GetKBMap(CTGAPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPickerFrame::GetKBMap'::`2'::s_pMap;
  `CTGAPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPickerFrame");
  `CTGAPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004D5A20
// Name: public: static char const __near * CTGAPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPicker::GetPanelClassName()
{
  return "CTGAPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004D5A30
// Name: public: static char const __near * CTGAPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPickerFrame::GetPanelClassName()
{
  return "CTGAPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004D5A40
// Name: private: virtual void CTGAPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPicker::OnSelectedAssetPicked(CTGAPicker *this, const char *pAssetName)
{
  char pFullPath[260]; // [esp+4h] [ebp-208h] BYREF
  char pRelativePath[260]; // [esp+108h] [ebp-104h] BYREF

  V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "materialsrc\\%s", pAssetName);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: pRelativePath,
    a3: "CONTENT",
    a4: pFullPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  CTGAPreviewPanel::SetTGA(this: this->m_pTGAPreview, pFullPath);
}

//------------------------------------------------------------------------------
// Address: 0x004D5AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPicker::GetMessageMap(CTGAPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPicker::GetMessageMap'::`2'::s_pMap;
  `CTGAPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPicker");
  `CTGAPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5AE0
// Name: public: virtual struct PanelAnimationMap __near * CTGAPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPicker::GetAnimMap(CTGAPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004D5AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPicker::GetKBMap(CTGAPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPicker::GetKBMap'::`2'::s_pMap;
  `CTGAPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPicker");
  `CTGAPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5B20
// Name: public: CTGAPicker::CTGAPicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPicker *__thiscall CTGAPicker::CTGAPicker(CTGAPicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // ebx
  vgui::Panel *v9; // edi
  CTGAPreviewPanel *v10; // eax
  CTGAPreviewPanel *v11; // eax

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "TGA Files",
    pExt: "tga",
    pSubDir: "materialsrc",
    pTextType: "tgaName",
    pAssetSearchPath: "CONTENT");
  this->__vftable = (CTGAPicker_vtbl *)&CTGAPicker::`vftable';
  if ( `CTGAPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CTGAPicker");
    v3->pfnClassName = CTGAPicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CTGAPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CTGAPicker");
    v4->pfnClassName = CTGAPicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CTGAPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPicker");
    v5->pfnClassName = CTGAPicker::GetPanelClassName;
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
  v10 = (CTGAPreviewPanel *)MemAlloc_Alloc(nSize: 0x1D4u);
  if ( v10 != nullptr )
    v11 = CTGAPreviewPanel::CTGAPreviewPanel(this: v10, pParent: v9, pName: "TGAPreview");
  else
    v11 = nullptr;
  this->m_pTGAPreview = v11;
  CProceduralTexturePanel::MaintainProportions(this: v11, bEnable: true);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/tgapicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D5CB0
// Name: public: CTGAPickerFrame::CTGAPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPickerFrame *__thiscall CTGAPickerFrame::CTGAPickerFrame(
        CTGAPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CTGAPicker *v7; // eax
  CTGAPicker *v8; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CTGAPickerFrame_vtbl *)&CTGAPickerFrame::`vftable';
  if ( `CTGAPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTGAPickerFrame");
    v4->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CTGAPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTGAPickerFrame");
    v5->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CTGAPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPickerFrame");
    v6->pfnClassName = CTGAPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v7 = (CTGAPicker *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = CTGAPicker::CTGAPicker(this: v7, pParent: this);
  else
    v8 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v8);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/tgapickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D5DB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPickerFrame::GetMessageMap(CTGAPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CTGAPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPickerFrame");
  `CTGAPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5DE0
// Name: public: virtual struct PanelAnimationMap __near * CTGAPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPickerFrame::GetAnimMap(CTGAPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004D5DF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPickerFrame::GetKBMap(CTGAPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPickerFrame::GetKBMap'::`2'::s_pMap;
  `CTGAPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPickerFrame");
  `CTGAPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
