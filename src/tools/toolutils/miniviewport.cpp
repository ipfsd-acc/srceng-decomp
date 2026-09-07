// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/miniviewport.cpp
// Functions: 28
// ============================================================

#include "tools\toolutils\miniviewport.h"

//------------------------------------------------------------------------------
// Address: 0x102BFB70
// Name: public: static char const __near * CMiniViewport::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMiniViewport::GetPanelClassName()
{
  return "CMiniViewport";
}

//------------------------------------------------------------------------------
// Address: 0x102BFB80
// Name: public: static char const __near * CMiniViewportPropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMiniViewportPropertyPage::GetPanelClassName()
{
  return "CMiniViewportPropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x102BFB90
// Name: public: static char const __near * CMiniViewportEngineRenderArea::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMiniViewportEngineRenderArea::GetPanelClassName()
{
  return "CMiniViewportEngineRenderArea";
}

//------------------------------------------------------------------------------
// Address: 0x102BFBA0
// Name: protected: void CMiniViewportEngineRenderArea::InitSceneMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMiniViewportEngineRenderArea::InitSceneMaterials(
        CMiniViewportEngineRenderArea *this@<ecx>,
        int a2@<esi>)
{
  CMiniViewportEngineRenderArea *v2; // ebx
  CTextureReference *p_m_ScreenBuffer; // edi
  bool v4; // zf
  IMaterialSystem_vtbl *v5; // eax
  ITexture *v6; // eax
  int v7; // esi
  IMaterialSystem_vtbl *v8; // ebx
  int v9; // eax
  ITexture *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  char *v13; // eax
  float flAspect; // [esp+Ch] [ebp-Ch]
  int nBackBufferHeight; // [esp+10h] [ebp-8h] BYREF
  int nBackBufferWidth; // [esp+14h] [ebp-4h] BYREF

  v2 = this;
  p_m_ScreenBuffer = &this->m_ScreenBuffer;
  if ( this->m_ScreenBuffer.m_pTexture == nullptr )
  {
    v4 = ((unsigned __int8 (__thiscall *)(IMaterialSystem *, const char *, int))g_pMaterialSystem->IsTextureLoaded)(
           a1: g_pMaterialSystem,
           a2: "_rt_LayoffResult",
           a3: a2) == 0;
    v5 = g_pMaterialSystem->__vftable;
    if ( v4 )
    {
      ((void (__stdcall *)(int *, int *))v5->GetBackBufferDimensions)(a1: &nBackBufferWidth, a2: &nBackBufferHeight);
      v7 = nBackBufferWidth;
      flAspect = (float)nBackBufferWidth / (float)nBackBufferHeight;
      if ( nBackBufferWidth > 1280 )
        v7 = 1280;
      g_pMaterialSystem->BeginRenderTargetAllocation(this: g_pMaterialSystem);
      v8 = g_pMaterialSystem->__vftable;
      v9 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, _DWORD))g_pMaterialSystem->GetBackBufferFormat)(
             a1: g_pMaterialSystem,
             a2: 0,
             a3: 0x20000000,
             a4: 0);
      v10 = (ITexture *)((int (__thiscall *)(IMaterialSystem *, const char *, int, int, int, int))v8->CreateNamedRenderTargetTextureEx2)(
                          a1: g_pMaterialSystem,
                          a2: "_rt_LayoffResult",
                          a3: v7,
                          a4: (int)(float)((float)((float)v7 / flAspect) + 0.5),
                          a5: 5,
                          a6: v9);
      CTextureReference::Init(this: p_m_ScreenBuffer, pTexture: v10);
      g_pMaterialSystem->EndRenderTargetAllocation(this: g_pMaterialSystem);
      v2 = this;
    }
    else
    {
      v6 = (ITexture *)((int (__stdcall *)(const char *, const char *, int))v5->FindTexture)(
                         a1: "_rt_LayoffResult",
                         a2: "RenderTargets",
                         a3: 1);
      CTextureReference::Init(this: p_m_ScreenBuffer, pTexture: v6);
    }
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "UnlitGeneric");
    else
      v12 = nullptr;
    v13 = (char *)p_m_ScreenBuffer->m_pTexture->GetName(this: p_m_ScreenBuffer->m_pTexture);
    KeyValues::SetString(this: v12, keyName: "$basetexture", value: v13);
    KeyValues::SetInt(this: v12, keyName: "$nofog", value: 1);
    CMaterialReference::Init(
      this: &v2->m_ScreenMaterial,
      pMaterialName: "MiniViewportEngineRenderAreaSceneMaterial",
      pVMTKeyValues: v12);
    v2->m_ScreenMaterial.m_pMaterial->Refresh(this: v2->m_ScreenMaterial.m_pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BFD20
// Name: public: virtual void CMiniViewportEngineRenderArea::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewportEngineRenderArea::ApplySchemeSettings(
        CMiniViewportEngineRenderArea *this,
        vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_OverlayTextFont = pScheme->GetFont(this: pScheme, a2: "DefaultLargeOutline", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102BFD50
// Name: protected: void CMiniViewportEngineRenderArea::PaintOverlayText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewportEngineRenderArea::PaintOverlayText(CMiniViewportEngineRenderArea *this)
{
  int v2; // esi
  void *v3; // esp
  const char *v4; // eax
  int v5; // edi
  int v6; // esi
  char *v7; // eax
  wchar_t v8[6]; // [esp+0h] [ebp-20h] BYREF
  IMatSystemSurface_vtbl *v9; // [esp+Ch] [ebp-14h]
  int nTextHeight; // [esp+10h] [ebp-10h] BYREF
  int nTextWidth; // [esp+14h] [ebp-Ch] BYREF
  int cw; // [esp+18h] [ebp-8h] BYREF
  int tall; // [esp+1Ch] [ebp-4h] BYREF

  if ( CUtlString::Length(this: &this->m_OverlayText) != 0 )
  {
    vgui::Panel::GetSize(this, wide: &cw, &tall);
    v2 = CUtlString::Length(this: &this->m_OverlayText) + 1;
    v3 = alloca(2 * v2);
    v4 = CUtlString::Get(this: &this->m_OverlayText);
    MultiByteToWideChar(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      lpMultiByteStr: v4,
      cbMultiByte: -1,
      lpWideCharStr: v8,
      cchWideChar: v2);
    g_pMatSystemSurface->GetTextSize(
      this: g_pMatSystemSurface,
      a2: this->m_OverlayTextFont,
      a3: v8,
      a4: &nTextWidth,
      a5: &nTextHeight);
    v5 = (cw - nTextWidth) / 2;
    if ( v5 < 10 )
      v5 = 10;
    v9 = g_pMatSystemSurface->__vftable;
    v6 = tall - nTextHeight - 10;
    v7 = CUtlString::Get(this: &this->m_OverlayText);
    v9->DrawColoredTextRect(
      this: g_pMatSystemSurface,
      a2: this->m_OverlayTextFont,
      a3: v5,
      a4: v6,
      a5: cw - v5,
      a6: tall - v6,
      a7: 255,
      a8: 255,
      a9: 255,
      a10: 255,
      a11: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BFE50
// Name: public: virtual void CMiniViewportEngineRenderArea::GetEngineBounds(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewportEngineRenderArea::GetEngineBounds(
        CMiniViewportEngineRenderArea *this,
        int *x,
        int *y,
        int *w,
        int *h)
{
  int *v5; // eax
  int *v6; // ebx
  int *v7; // esi
  int *v8; // edi
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // ecx
  int v13; // ecx
  int *v14; // [esp-4h] [ebp-10h]

  v5 = y;
  v6 = x;
  v7 = w;
  v8 = h;
  v14 = h;
  *x = 0;
  *v5 = 0;
  vgui::Panel::GetSize(this, wide: v7, tall: v14);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: (int *)&h, a3: (int *)&x);
  if ( (int)x > 0 )
  {
    v9 = *v8;
    if ( *v8 > 0 )
    {
      v10 = (float)(int)h / (float)(int)x;
      v11 = (float)*v7;
      if ( (float)(v10 / (float)(v11 / (float)v9)) <= 1.0 )
      {
        v13 = (int)(float)((float)v9 * v10);
        *v6 = (*v7 - v13) / 2;
        *v7 = v13;
      }
      else
      {
        v12 = (int)(float)(v11 / v10);
        *y = (v9 - v12) / 2;
        *v8 = v12;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BFF10
// Name: private: virtual void CMiniViewportPropertyPage::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewportPropertyPage::PerformLayout(CMiniViewportPropertyPage *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pViewportArea, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x102BFF50
// Name: public: virtual class Color CMiniViewportPropertyPage::GetBgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CMiniViewportPropertyPage::GetBgColor(CMiniViewportPropertyPage *this, Color *result)
{
  *result = this->m_bgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BFF70
// Name: protected: void CMiniViewportEngineRenderArea::PaintEngineBorders(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewportEngineRenderArea::PaintEngineBorders(
        CMiniViewportEngineRenderArea *this,
        int x,
        int y,
        int w,
        int h)
{
  ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
  if ( x != 0 )
  {
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: x, a5: h);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: w + x, a3: 0, a4: w + 2 * x, a5: h);
  }
  else if ( y != 0 )
  {
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: y);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: h + y, a4: w, a5: h + 2 * y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0000
// Name: public: void CMiniViewport::GetViewport(bool __near &,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewport::GetViewport(CMiniViewport *this, bool *enabled, int *x, int *y, int *w, int *h)
{
  int *v6; // esi
  int *v7; // edi
  bool *enableda; // [esp+18h] [ebp+8h]

  v6 = y;
  *enabled = false;
  v7 = h;
  *h = 0;
  *w = 0;
  *v6 = 0;
  *x = 0;
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: (int *)&y, a3: (int *)&h);
  enableda = (bool *)vgui::PHandle::Get(this: &this->m_hPage);
  (*(void (__thiscall **)(_DWORD, int *, int *, int *, int *))(**((_DWORD **)enableda + 97) + 944))(
    a1: *((_DWORD *)enableda + 97),
    a2: x,
    a3: v6,
    a4: w,
    a5: v7);
  vgui::Panel::LocalToScreen(this: *((vgui::Panel **)enableda + 97), x, y: v6);
  *v6 = (int)h - *v6 - *v7;
}

//------------------------------------------------------------------------------
// Address: 0x102C00A0
// Name: public: void CMiniViewportEngineRenderArea::RenderFrameBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMiniViewportEngineRenderArea::RenderFrameBegin(
        CMiniViewportEngineRenderArea *this@<ecx>,
        int a2@<esi>)
{
  void (__thiscall *GetEngineBounds)(CMiniViewportEngineRenderArea *, int *, int *, int *, int *); // eax
  IMatRenderContext *v4; // esi
  CViewSetup playerViewSetup; // [esp+4h] [ebp-104h] BYREF
  int x; // [esp+F8h] [ebp-10h] BYREF
  int y; // [esp+FCh] [ebp-Ch] BYREF
  int w; // [esp+100h] [ebp-8h] BYREF
  int h; // [esp+104h] [ebp-4h] BYREF

  if ( enginetools->IsInGame(this: enginetools) )
  {
    CMiniViewportEngineRenderArea::InitSceneMaterials(this, a2);
    playerViewSetup.m_flAspectRatio = 0.0;
    playerViewSetup.m_flNearBlurDepth = 20.0;
    playerViewSetup.m_flNearFocusDepth = 100.0;
    playerViewSetup.m_flFarFocusDepth = 250.0;
    playerViewSetup.m_flFarBlurDepth = 1000.0;
    *((_BYTE *)&playerViewSetup + 240) = 4;
    GetEngineBounds = this->GetEngineBounds;
    playerViewSetup.m_flNearBlurRadius = 10.0;
    playerViewSetup.m_flFarBlurRadius = 5.0;
    playerViewSetup.m_nDoFQuality = 0;
    playerViewSetup.m_nMotionBlurMode = MOTION_BLUR_GAME;
    playerViewSetup.m_bCustomViewMatrix = false;
    ((void (__thiscall *)(CMiniViewportEngineRenderArea *, int *, int *, int *, int *, int))GetEngineBounds)(
      a1: this,
      a2: &x,
      a3: &y,
      a4: &w,
      a5: &h,
      a6: a2);
    enginetools->GetPlayerView(this: enginetools, a2: &playerViewSetup, a3: 0, a4: 0, a5: w, a6: h);
    v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    ((void (__thiscall *)(IMatRenderContext *, ITexture *, _DWORD, _DWORD, int))v4->PushRenderTargetAndViewport_2)(
      a1: v4,
      a2: this->m_ScreenBuffer.m_pTexture,
      a3: 0,
      a4: 0,
      a5: w);
    enginetools->SetMainView(this: enginetools, a2: &playerViewSetup.origin, a3: &playerViewSetup.angles);
    enginetools->RenderView(this: enginetools, a2: &playerViewSetup, a3: 3, a4: 3);
    v4->PopRenderTargetAndViewport(this: v4);
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0220
// Name: protected: void CMiniViewportEngineRenderArea::PaintEngineWindow(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMiniViewportEngineRenderArea::PaintEngineWindow(
        CMiniViewportEngineRenderArea *this@<ecx>,
        int a2@<ebx>,
        int x,
        int y,
        int w,
        int h)
{
  int v7; // eax
  int v8; // eax
  int v9; // [esp+1Ch] [ebp-8h]
  float v10; // [esp+20h] [ebp-4h]

  if ( enginetools->IsInGame(this: enginetools) )
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    v9 = v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    ((void (__thiscall *)(IMatSystemSurface *, int))g_pMatSystemSurface->DrawSetTextureMaterial)(
      a1: g_pMatSystemSurface,
      a2: this->m_nEngineOutputTexture);
    ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
    v10 = 1.0 / (float)this->m_ScreenBuffer.m_pTexture->GetActualWidth(this: this->m_ScreenBuffer.m_pTexture);
    v8 = this->m_ScreenBuffer.m_pTexture->GetActualHeight(this: this->m_ScreenBuffer.m_pTexture);
    ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawTexturedSubRect)(
      a1: g_pVGuiSurface,
      a2: x,
      a3: y,
      a4: x + w,
      a5: y + h,
      a6: v10 * 0.5,
      a7: (float)(1.0 / (float)v8) * 0.5,
      a8: (float)((float)w - 0.5) * v10,
      a9: (float)((float)h - 0.5) * (float)(1.0 / (float)v8));
    CMiniViewportEngineRenderArea::PaintOverlayText(this);
    if ( v9 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    }
  }
  else
  {
    ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: 1070104447);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + w, a5: y + h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C03C0
// Name: public: virtual void CMiniViewportEngineRenderArea::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMiniViewportEngineRenderArea::PaintBackground(CMiniViewportEngineRenderArea *this@<ecx>, int a2@<ebx>)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  this->GetEngineBounds(this, a2: &x, a3: &y, a4: &w, a5: &h);
  CMiniViewportEngineRenderArea::PaintEngineBorders(this, x, y, w, h);
  CMiniViewportEngineRenderArea::PaintEngineWindow(this, a2, x, y, w, h);
}

//------------------------------------------------------------------------------
// Address: 0x102C0420
// Name: public: void CMiniViewport::RenderFrameBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewport::RenderFrameBegin(CMiniViewport *this)
{
  vgui::DHANDLE<CMiniViewportPropertyPage> *p_m_hPage; // esi
  vgui::Panel *v2; // eax

  p_m_hPage = &this->m_hPage;
  if ( vgui::PHandle::Get(this: &this->m_hPage) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_hPage);
    CMiniViewportEngineRenderArea::RenderFrameBegin(
      this: (CMiniViewportEngineRenderArea *)v2[1].m_SkipChild.m_iPanelID,
      a2: (int)p_m_hPage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0450
// Name: public: virtual CMiniViewportEngineRenderArea::~CMiniViewportEngineRenderArea(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewportEngineRenderArea::~CMiniViewportEngineRenderArea(CMiniViewportEngineRenderArea *this)
{
  this->__vftable = (CMiniViewportEngineRenderArea_vtbl *)&CMiniViewportEngineRenderArea::`vftable';
  CTextureReference::Shutdown(this: &this->m_ScreenBuffer, bDeleteIfUnReferenced: false);
  CMaterialReference::Shutdown(this: &this->m_ScreenMaterial, bDeleteIfUnreferenced: false);
  CMaterialReference::~CMaterialReference(this: &this->m_ScreenMaterial);
  CTextureReference::~CTextureReference(this: &this->m_ScreenBuffer);
  this->m_OverlayText.m_Storage.m_nActualLength = 0;
  if ( this->m_OverlayText.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OverlayText.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OverlayText.m_Storage.m_Memory.m_pMemory);
      this->m_OverlayText.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OverlayText.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C04D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMiniViewportEngineRenderArea::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMiniViewportEngineRenderArea::GetMessageMap(CMiniViewportEngineRenderArea *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMiniViewportEngineRenderArea::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMiniViewportEngineRenderArea::GetMessageMap'::`2'::s_pMap;
  `CMiniViewportEngineRenderArea::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMiniViewportEngineRenderArea");
  `CMiniViewportEngineRenderArea::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0500
// Name: public: virtual struct PanelAnimationMap __near * CMiniViewportEngineRenderArea::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMiniViewportEngineRenderArea::GetAnimMap(CMiniViewportEngineRenderArea *this)
{
  return FindOrAddPanelAnimationMap(className: "CMiniViewportEngineRenderArea");
}

//------------------------------------------------------------------------------
// Address: 0x102C0510
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMiniViewportEngineRenderArea::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMiniViewportEngineRenderArea::GetKBMap(CMiniViewportEngineRenderArea *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMiniViewportEngineRenderArea::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMiniViewportEngineRenderArea::GetKBMap'::`2'::s_pMap;
  `CMiniViewportEngineRenderArea::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMiniViewportEngineRenderArea");
  `CMiniViewportEngineRenderArea::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0540
// Name: public: CMiniViewportEngineRenderArea::CMiniViewportEngineRenderArea(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMiniViewportEngineRenderArea *__thiscall CMiniViewportEngineRenderArea::CMiniViewportEngineRenderArea(
        CMiniViewportEngineRenderArea *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (CMiniViewportEngineRenderArea_vtbl *)&CMiniViewportEngineRenderArea::`vftable';
  if ( `CMiniViewportEngineRenderArea::ChainToMap'::`2'::chained == 0 )
  {
    `CMiniViewportEngineRenderArea::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMiniViewportEngineRenderArea");
    v4->pfnClassName = CMiniViewportEngineRenderArea::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CMiniViewportEngineRenderArea::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMiniViewportEngineRenderArea::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMiniViewportEngineRenderArea");
    v5->pfnClassName = CMiniViewportEngineRenderArea::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CMiniViewportEngineRenderArea::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMiniViewportEngineRenderArea::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMiniViewportEngineRenderArea");
    v6->pfnClassName = CMiniViewportEngineRenderArea::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CUtlString::CUtlString(this: &this->m_OverlayText);
  CTextureReference::CTextureReference(this: &this->m_ScreenBuffer);
  CMaterialReference::CMaterialReference(
    this: &this->m_ScreenMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  this->m_nEngineOutputTexture = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C0690
// Name: public: CMiniViewportPropertyPage::CMiniViewportPropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMiniViewportPropertyPage *__thiscall CMiniViewportPropertyPage::CMiniViewportPropertyPage(
        CMiniViewportPropertyPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CMiniViewportEngineRenderArea *v7; // eax

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (CMiniViewportPropertyPage_vtbl *)&CMiniViewportPropertyPage::`vftable';
  if ( `CMiniViewportPropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `CMiniViewportPropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMiniViewportPropertyPage");
    v4->pfnClassName = CMiniViewportPropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CMiniViewportPropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMiniViewportPropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMiniViewportPropertyPage");
    v5->pfnClassName = CMiniViewportPropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CMiniViewportPropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMiniViewportPropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMiniViewportPropertyPage");
    v6->pfnClassName = CMiniViewportPropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_bgColor = 0;
  this->m_bgColor = 0;
  v7 = (CMiniViewportEngineRenderArea *)operator new(nSize: 0x1A0u);
  if ( v7 != nullptr )
    this->m_pViewportArea = CMiniViewportEngineRenderArea::CMiniViewportEngineRenderArea(
                              this: v7,
                              parent: this,
                              panelName: "Engine");
  else
    this->m_pViewportArea = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C07A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMiniViewportPropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMiniViewportPropertyPage::GetMessageMap(CMiniViewportPropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMiniViewportPropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMiniViewportPropertyPage::GetMessageMap'::`2'::s_pMap;
  `CMiniViewportPropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMiniViewportPropertyPage");
  `CMiniViewportPropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C07D0
// Name: public: virtual struct PanelAnimationMap __near * CMiniViewportPropertyPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMiniViewportPropertyPage::GetAnimMap(CMiniViewportPropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CMiniViewportPropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x102C07E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMiniViewportPropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMiniViewportPropertyPage::GetKBMap(CMiniViewportPropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMiniViewportPropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMiniViewportPropertyPage::GetKBMap'::`2'::s_pMap;
  `CMiniViewportPropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMiniViewportPropertyPage");
  `CMiniViewportPropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0810
// Name: public: CMiniViewport::CMiniViewport(class vgui::Panel __near *,bool,class vgui::IToolWindowFactory __near *,class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMiniViewport *__thiscall CMiniViewport::CMiniViewport(
        CMiniViewport *this,
        vgui::Panel *parent,
        bool contextLabel,
        vgui::IToolWindowFactory *factory,
        vgui::Panel *page,
        const char *title,
        bool contextMenu)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  vgui::PropertySheet *PropertySheet; // eax
  CMiniViewportPropertyPage *v12; // eax
  CDragDropHelperPanel *v13; // eax
  vgui::Panel *v14; // eax

  vgui::ToolWindow::ToolWindow(
    this,
    parent,
    contextlabel: contextLabel,
    factory,
    page,
    title,
    contextMenu,
    inGlobalList: false);
  this->__vftable = (CMiniViewport_vtbl *)&CMiniViewport::`vftable';
  if ( `CMiniViewport::ChainToMap'::`2'::chained == 0 )
  {
    `CMiniViewport::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CMiniViewport");
    v8->pfnClassName = CMiniViewport::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ToolWindow");
  }
  if ( `CMiniViewport::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMiniViewport::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CMiniViewport");
    v9->pfnClassName = CMiniViewport::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ToolWindow");
  }
  if ( `CMiniViewport::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMiniViewport::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CMiniViewport");
    v10->pfnClassName = CMiniViewport::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ToolWindow");
  }
  this->m_hPage.m_iPanelID = -1;
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  PropertySheet = vgui::ToolWindow::GetPropertySheet(this);
  vgui::PropertySheet::SetDraggableTabs(this: PropertySheet, state: false);
  v12 = (CMiniViewportPropertyPage *)operator new(nSize: 0x188u);
  if ( v12 != nullptr )
    v13 = (CDragDropHelperPanel *)CMiniViewportPropertyPage::CMiniViewportPropertyPage(
                                    this: v12,
                                    parent: this,
                                    panelName: "ViewportPage");
  else
    v13 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hPage,
    pPanel: v13);
  v14 = vgui::PHandle::Get(this: &this->m_hPage);
  vgui::ToolWindow::AddPage(this, page: v14, title: "#ToolMiniViewport", contextMenu: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C0950
// Name: public: virtual struct vgui::PanelMessageMap __near * CMiniViewport::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMiniViewport::GetMessageMap(CMiniViewport *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMiniViewport::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMiniViewport::GetMessageMap'::`2'::s_pMap;
  `CMiniViewport::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMiniViewport");
  `CMiniViewport::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0980
// Name: public: virtual struct PanelAnimationMap __near * CMiniViewport::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMiniViewport::GetAnimMap(CMiniViewport *this)
{
  return FindOrAddPanelAnimationMap(className: "CMiniViewport");
}

//------------------------------------------------------------------------------
// Address: 0x102C0990
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMiniViewport::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMiniViewport::GetKBMap(CMiniViewport *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMiniViewport::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMiniViewport::GetKBMap'::`2'::s_pMap;
  `CMiniViewport::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMiniViewport");
  `CMiniViewport::GetKBMap'::`2'::s_pMap = result;
  return result;
}
