// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/tgapreviewpanel.cpp
// Functions: 7
// ============================================================

#include "vgui2\matsys_controls\tgapreviewpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004CE940
// Name: public: static char const __near * CTGAPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPreviewPanel::GetPanelClassName()
{
  return "CTGAPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004CE950
// Name: public: virtual void CTGAPreviewPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPreviewPanel::PerformLayout(CTGAPreviewPanel *this)
{
  Rect_t paintRect; // [esp+4h] [ebp-10h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  paintRect.x = 0;
  paintRect.y = 0;
  paintRect.width = CProceduralTexturePanel::GetImageWidth(this);
  paintRect.height = CElementTreeViewListControl::GetTreeColumnWidth(this);
  CProceduralTexturePanel::SetPaintRect(this, pPaintRect: &paintRect);
}

//------------------------------------------------------------------------------
// Address: 0x004CE990
// Name: public: CTGAPreviewPanel::CTGAPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPreviewPanel *__thiscall CTGAPreviewPanel::CTGAPreviewPanel(
        CTGAPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CTGAPreviewPanel_vtbl *)&CTGAPreviewPanel::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CTGAPreviewPanel::`vftable'{for `ITextureRegenerator'};
  if ( `CTGAPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTGAPreviewPanel");
    v4->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CTGAPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTGAPreviewPanel");
    v5->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CTGAPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPreviewPanel");
    v6->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CUtlString::CUtlString(this: &this->m_TGAName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CEA70
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPreviewPanel::GetMessageMap(CTGAPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CTGAPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPreviewPanel");
  `CTGAPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CEAA0
// Name: public: virtual struct PanelAnimationMap __near * CTGAPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPreviewPanel::GetAnimMap(CTGAPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004CEAB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPreviewPanel::GetKBMap(CTGAPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CTGAPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPreviewPanel");
  `CTGAPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CEB50
// Name: public: void CTGAPreviewPanel::SetTGA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPreviewPanel::SetTGA(CTGAPreviewPanel *this, const char *pFullPath)
{
  unsigned __int8 *ImageBuffer; // eax
  int v4; // [esp+18h] [ebp-5Ch]
  int v5; // [esp+1Ch] [ebp-58h]
  float targetGamma; // [esp+24h] [ebp-50h]
  CUtlBuffer buf; // [esp+34h] [ebp-40h] BYREF
  ImageFormat format; // [esp+64h] [ebp-10h] BYREF
  float flGamma; // [esp+68h] [ebp-Ch] BYREF
  int nWidth; // [esp+6Ch] [ebp-8h] BYREF
  int nHeight; // [esp+70h] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pFullPath,
         a3: nullptr,
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    TGALoader::GetInfo(&buf, width: &nWidth, height: &nHeight, imageFormat: &format, sourceGamma: &flGamma);
    this->Shutdown(this);
    this->Init(this, a2: nWidth, a3: nHeight, a4: true);
    CUtlString::operator=(this: &this->m_TGAName, src: pFullPath);
    CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
    targetGamma = flGamma;
    v5 = nHeight;
    v4 = nWidth;
    ImageBuffer = (unsigned __int8 *)CProceduralTexturePanel::GetImageBuffer((vgui::TreeView *)this);
    if ( TGALoader::Load(
           pOutputImage: ImageBuffer,
           &buf,
           width: v4,
           height: v5,
           imageFormat: IMAGE_FORMAT_BGRA8888,
           targetGamma,
           mipmap: false) )
    {
      CProceduralTexturePanel::DownloadTexture(this);
    }
    else
    {
      this->Shutdown(this);
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
  else
  {
    _Warning(a1: "Can't open TGA file: %s\n", pFullPath);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D3270
// Name: public: static char const __near * CTGAPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPreviewPanel::GetPanelClassName()
{
  return "CTGAPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104D3280
// Name: public: virtual void CTGAPreviewPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPreviewPanel::PerformLayout(CTGAPreviewPanel *this)
{
  Rect_t paintRect; // [esp+4h] [ebp-10h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  paintRect.x = 0;
  paintRect.y = 0;
  paintRect.width = CProceduralTexturePanel::GetImageWidth(this);
  paintRect.height = CElementTreeViewListControl::GetTreeColumnWidth(this);
  CProceduralTexturePanel::SetPaintRect(this, pPaintRect: &paintRect);
}

//------------------------------------------------------------------------------
// Address: 0x104D32C0
// Name: public: CTGAPreviewPanel::CTGAPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPreviewPanel *__thiscall CTGAPreviewPanel::CTGAPreviewPanel(
        CTGAPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CTGAPreviewPanel_vtbl *)&CTGAPreviewPanel::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CTGAPreviewPanel::`vftable'{for `ITextureRegenerator'};
  if ( `CTGAPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTGAPreviewPanel");
    v4->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CTGAPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTGAPreviewPanel");
    v5->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CTGAPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPreviewPanel");
    v6->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CUtlString::CUtlString(this: &this->m_TGAName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104D33A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPreviewPanel::GetMessageMap(CTGAPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CTGAPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPreviewPanel");
  `CTGAPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D33D0
// Name: public: virtual struct PanelAnimationMap __near * CTGAPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPreviewPanel::GetAnimMap(CTGAPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104D33E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPreviewPanel::GetKBMap(CTGAPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CTGAPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPreviewPanel");
  `CTGAPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D3480
// Name: public: void CTGAPreviewPanel::SetTGA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPreviewPanel::SetTGA(CTGAPreviewPanel *this, char *pFullPath)
{
  unsigned __int8 *ImageBuffer; // eax
  int v4; // [esp-Ch] [ebp-5Ch]
  unsigned __int8 *v5; // [esp-8h] [ebp-58h]
  float targetGamma; // [esp+0h] [ebp-50h]
  CUtlBuffer buf; // [esp+10h] [ebp-40h] BYREF
  ImageFormat imageFormat; // [esp+40h] [ebp-10h] BYREF
  float sourceGamma; // [esp+44h] [ebp-Ch] BYREF
  int width; // [esp+48h] [ebp-8h] BYREF
  int height; // [esp+4Ch] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pFullPath,
         a3: nullptr,
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    TGALoader::GetInfo(&buf, &width, &height, &imageFormat, &sourceGamma);
    this->Shutdown(this);
    this->Init(this, a2: width, a3: height, a4: true);
    CUtlString::operator=(this: &this->m_TGAName, src: pFullPath);
    CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
    targetGamma = sourceGamma;
    v5 = (unsigned __int8 *)height;
    v4 = width;
    ImageBuffer = (unsigned __int8 *)CProceduralTexturePanel::GetImageBuffer((vgui::TreeView *)this);
    if ( TGALoader::Load(
           pOutputImage: ImageBuffer,
           &buf,
           width: v4,
           height: v5,
           imageFormat: (CUtlBuffer *)0xC,
           targetGamma,
           mipmap: false) != 0 )
      CProceduralTexturePanel::DownloadTexture(this);
    else
      this->Shutdown(this);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
  else
  {
    _Warning(a1: "Can't open TGA file: %s\n", pFullPath);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004E9C60
// Name: public: static char const __near * CTGAPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTGAPreviewPanel::GetPanelClassName()
{
  return "CTGAPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004E9C70
// Name: public: virtual void CTGAPreviewPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPreviewPanel::PerformLayout(CTGAPreviewPanel *this)
{
  Rect_t paintRect; // [esp+4h] [ebp-10h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  paintRect.x = 0;
  paintRect.y = 0;
  paintRect.width = CProceduralTexturePanel::GetImageWidth(this);
  paintRect.height = CElementTreeViewListControl::GetTreeColumnWidth(this);
  CProceduralTexturePanel::SetPaintRect(this, pPaintRect: &paintRect);
}

//------------------------------------------------------------------------------
// Address: 0x004E9CB0
// Name: public: CTGAPreviewPanel::CTGAPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTGAPreviewPanel *__thiscall CTGAPreviewPanel::CTGAPreviewPanel(
        CTGAPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CTGAPreviewPanel_vtbl *)&CTGAPreviewPanel::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CTGAPreviewPanel::`vftable'{for `ITextureRegenerator'};
  if ( `CTGAPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTGAPreviewPanel");
    v4->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CTGAPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTGAPreviewPanel");
    v5->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CTGAPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTGAPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPreviewPanel");
    v6->pfnClassName = CTGAPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CUtlString::CUtlString(this: &this->m_TGAName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E9D90
// Name: public: virtual struct vgui::PanelMessageMap __near * CTGAPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTGAPreviewPanel::GetMessageMap(CTGAPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTGAPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CTGAPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTGAPreviewPanel");
  `CTGAPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E9DC0
// Name: public: virtual struct PanelAnimationMap __near * CTGAPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTGAPreviewPanel::GetAnimMap(CTGAPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CTGAPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004E9DD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTGAPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTGAPreviewPanel::GetKBMap(CTGAPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTGAPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTGAPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CTGAPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTGAPreviewPanel");
  `CTGAPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E9E70
// Name: public: void CTGAPreviewPanel::SetTGA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGAPreviewPanel::SetTGA(CTGAPreviewPanel *this, const char *pFullPath)
{
  unsigned __int8 *ImageBuffer; // eax
  int v4; // [esp+18h] [ebp-5Ch]
  int v5; // [esp+1Ch] [ebp-58h]
  float targetGamma; // [esp+24h] [ebp-50h]
  CUtlBuffer buf; // [esp+34h] [ebp-40h] BYREF
  ImageFormat format; // [esp+64h] [ebp-10h] BYREF
  float flGamma; // [esp+68h] [ebp-Ch] BYREF
  int nWidth; // [esp+6Ch] [ebp-8h] BYREF
  int nHeight; // [esp+70h] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pFullPath,
         a3: nullptr,
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    TGALoader::GetInfo(&buf, width: &nWidth, height: &nHeight, imageFormat: &format, sourceGamma: &flGamma);
    this->Shutdown(this);
    this->Init(this, a2: nWidth, a3: nHeight, a4: true);
    CUtlString::operator=(this: &this->m_TGAName, src: pFullPath);
    CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
    targetGamma = flGamma;
    v5 = nHeight;
    v4 = nWidth;
    ImageBuffer = (unsigned __int8 *)CProceduralTexturePanel::GetImageBuffer((vgui::TreeView *)this);
    if ( TGALoader::Load(
           pOutputImage: ImageBuffer,
           &buf,
           width: v4,
           height: v5,
           imageFormat: IMAGE_FORMAT_BGRA8888,
           targetGamma,
           mipmap: false) )
    {
      CProceduralTexturePanel::DownloadTexture(this);
    }
    else
    {
      this->Shutdown(this);
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
  else
  {
    _Warning(a1: "Can't open TGA file: %s\n", pFullPath);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

} // namespace sceneviewer
