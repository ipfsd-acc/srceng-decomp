// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/animatingimagepanel.cpp
// Functions: 17
// ============================================================

#include "vgui2\vgui_controls\animatingimagepanel.h"

//------------------------------------------------------------------------------
// Address: 0x102BB890
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C66A0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102C66B0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x102C66E0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ApplySettings(vgui::AnimatingImagePanel *this, KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  int v6; // edi
  char *v7; // eax
  vgui::AnimatingImagePanel_vtbl *v8; // edi
  int v9; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  const char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    this->m_pImageName = v7;
    V_strncpy(pDest: v7, pSrc: imageName, maxLen: v6);
    v8 = this->__vftable;
    v9 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v8->LoadAnimation(this, a2: this->m_pImageName, a3: v9);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x102C6790
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_10, maxLen: 1024, pFormat: "%s, string image", Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x102C67C0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x102C67D0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x102C67E0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6850
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6890
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6970
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 512, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C69F0
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C6B10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6B40
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x102C6B50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6B80
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C6BD0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x100420B0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100420C0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100420E0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x10042110
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  unsigned int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  unsigned int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x100421C0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_4, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x100421F0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x10042200
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x10042210
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042280
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100422C0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100423A0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042420
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10042540
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042570
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10042580
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100425B0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10042600
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x004269B0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004269C0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x004269F0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x00426AA0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_4, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x00426AD0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x00426AE0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x00426AF0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426B60
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426BA0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426C80
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426D00
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00426E20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426E50
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00426E60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426E90
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00426EE0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D570
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10058DD0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10058DE0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058E00
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x10058E30
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x10058EE0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_5, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x10058F10
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x10058F20
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x10058F30
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058FA0
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058FE0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100590C0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059140
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10059260
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059290
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100592A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100592D0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10059320
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006034B0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x006034C0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x006034E0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00603510
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)MemAlloc_Alloc(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x006035C0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_4, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x006035F0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x00603600
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x00603610
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00603680
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006036C0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006037A0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00603890
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006039B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006039E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x006039F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00603A20
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00603A70
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C6750
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102C6760
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C6780
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x102C67B0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  const char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)MemAlloc_Alloc(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x102C6860
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_10, maxLen: 1024, pFormat: "%s, string image", Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x102C68A0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x102C68B0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6920
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6960
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6A40
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 512, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6AC0
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        __m128i *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C6BE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6C10
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x102C6C20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6C50
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C6CA0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EA320
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102EA330
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EA350
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x102EA380
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    operator delete(p: m_pImageName);
    v7 = std::char_traits<char>::length(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x102EA430
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_8, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x102EA460
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x102EA470
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x102EA480
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA4F0
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA530
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA610
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA690
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EA7B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EA7E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x102EA7F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EA820
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102EA870
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100BAA40
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100BAA50
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BAA70
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x100BAAA0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x100BAB50
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_9, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB80
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x100BAB90
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x100BABA0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAC10
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAC50
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAD30
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BADB0
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BAED0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BAF00
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100BAF10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BAF40
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BAF90
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00446F40
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00446F50
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00446F70
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00446FA0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x00447050
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_5, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x00447080
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x00447090
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x004470A0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447110
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447150
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447230
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004472B0
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004473D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447400
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00447410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447440
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00447490
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B86A0
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x004B8D60
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x004B9340
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

//------------------------------------------------------------------------------
// Address: 0x004B94F0
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x004B8D90
// Name: _dynamic_initializer_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMXAllocator__()
{
  CMemoryStack::CMemoryStack(this: &s_DMXAllocator);
  return atexit(func: dynamic_atexit_destructor_for__s_DMXAllocator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B9500
// Name: _dynamic_atexit_destructor_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMXAllocator__()
{
  CMemoryStack::~CMemoryStack(this: &s_DMXAllocator);
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042E4A0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0042E4B0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0042E4E0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ApplySettings(vgui::AnimatingImagePanel *this, KeyValues *inResourceData)
{
  char *String; // ebp
  int Int; // eax
  unsigned int v5; // edi
  char *v6; // eax
  vgui::AnimatingImagePanel_vtbl *v7; // edi
  int v8; // eax
  char *m_pImageName; // [esp-8h] [ebp-14h]

  vgui::Panel::ApplySettings(this, inResourceData);
  String = (char *)KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v5 = _V_strlen(str: String) + 1;
    v6 = (char *)operator new(nSize: v5);
    this->m_pImageName = v6;
    V_strncpy(pDest: v6, pSrc: String, maxLen: v5);
    v7 = this->__vftable;
    v8 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v7->LoadAnimation(this, a2: this->m_pImageName, a3: v8);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x0042E590
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_5, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x0042E5C0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x0042E5D0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x0042E5E0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E650
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E690
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  int wide; // [esp+2Ch] [ebp-10h] BYREF
  int imageTall; // [esp+30h] [ebp-Ch] BYREF
  int imageWide; // [esp+34h] [ebp-8h] BYREF
  int v11; // [esp+38h] [ebp-4h] BYREF

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &v11, a3: &imageWide);
        vgui::Panel::GetSize(this, wide: &imageTall, tall: &wide);
        v6->SetSize(this: v6, a2: imageTall, a3: wide);
        ((void (__thiscall *)(vgui::IImage *, int))v6->SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: v11, a3: imageWide);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E780
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  void (__thiscall **p_AddImage)(vgui::AnimatingImagePanel *, vgui::IImage *); // esi
  int v6; // eax
  char imageName[516]; // [esp+8h] [ebp-204h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: &imageName[4], maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    p_AddImage = &this->AddImage;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: &imageName[4], a2: this->m_bFiltered);
    (*p_AddImage)(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E810
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  this->m_bFiltered = false;
  this->m_bScaleImage = false;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042E930
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E960
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0042E970
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E9A0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042E9F0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int v3; // [esp+8h] [ebp-4h] BYREF

  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Frames,
    elem: this->m_Frames.m_Size,
    src: (vgui::TreeNode **)&image);
  if ( !this->m_bScaleImage && image != nullptr )
  {
    image->GetSize(this: image, a2: &v3, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide: v3, tall: (int)image);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444A70
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004879D0
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x00488150
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063ABA0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0063ABB0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063ABD0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0063AC00
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)MemAlloc_Alloc(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x0063ACB0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_5, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x0063ACE0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x0063ACF0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x0063AD00
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063AD70
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063ADB0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063AE90
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063AF10
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063B030
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063B060
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0063B070
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063B0A0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0063B0F0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10061710
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10061720
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x10061750
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x10061800
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_9, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x10061830
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x10061840
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x10061850
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100618C0
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061900
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100619E0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061A60
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061B80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061BB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10061BC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061BF0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10061C40
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068B30
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10065250
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10065260
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10065280
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x100652B0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x10065360
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_4, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x10065390
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x100653A0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x100653B0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065420
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065460
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065540
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100655C0
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100656E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065710
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10065720
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065750
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100657A0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00436CB0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00436CC0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00436CF0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x00436DA0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_5, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x00436DD0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x00436DE0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x00436DF0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436E60
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436EA0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436F80
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437000
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00437120
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437150
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00437160
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437190
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004371E0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D770
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004803C0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004803D0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004803F0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00480420
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        KeyValues *inResourceData)
{
  char *String; // ebp
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-8h] [ebp-14h]
  int v12; // [esp+0h] [ebp-Ch]
  BOOL v13; // [esp+4h] [ebp-8h]
  char *v14; // [esp+8h] [ebp-4h]

  vgui::Panel::ApplySettings(
    this,
    a2: (int)inResourceData,
    a3: a2,
    a4: a3,
    (int)inResourceData,
    a6: v12,
    a7: v13,
    nptr: v14);
  String = (char *)KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)MemAlloc_Alloc(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: String, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x004804D0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_4, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x00480500
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x00480510
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x00480520
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480590
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004805D0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  int wide; // [esp+2Ch] [ebp-10h] BYREF
  int imageTall; // [esp+30h] [ebp-Ch] BYREF
  int imageWide; // [esp+34h] [ebp-8h] BYREF
  int v11; // [esp+38h] [ebp-4h] BYREF

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &v11, a3: &imageWide);
        vgui::Panel::GetSize(this, wide: &imageTall, tall: &wide);
        v6->SetSize(this: v6, a2: imageTall, a3: wide);
        ((void (__thiscall *)(vgui::IImage *, int))v6->SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: v11, a3: imageWide);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004806C0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  void (__thiscall **p_AddImage)(vgui::AnimatingImagePanel *, vgui::IImage *); // esi
  int v6; // eax
  char imageName[516]; // [esp+8h] [ebp-204h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: &imageName[4], maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    p_AddImage = &this->AddImage;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: &imageName[4], a2: this->m_bFiltered);
    (*p_AddImage)(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480750
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  this->m_bFiltered = false;
  this->m_bScaleImage = false;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00480870
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004808A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004808B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004808E0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00480930
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int v3; // [esp+8h] [ebp-4h] BYREF

  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Frames,
    elem: this->m_Frames.m_Size,
    src: (vgui::TreeNode **)&image);
  if ( !this->m_bScaleImage && image != nullptr )
  {
    image->GetSize(this: image, a2: &v3, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide: v3, tall: (int)image);
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004255D0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004255E0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00425610
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x004256C0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_4, maxLen: 1024, pFormat: "%s, string image", Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x004256F0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x00425700
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x00425710
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425780
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004257C0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004258A0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 512, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425920
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425A40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425A70
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00425A80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425AB0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00425B00
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C140
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00428FE0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00428FF0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00429010
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00429040
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  const char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = (char *)String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x004290F0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_4, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_4;
}

//------------------------------------------------------------------------------
// Address: 0x00429120
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x00429130
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x00429140
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004291B0
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004291F0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004292D0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429350
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429470
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004294A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004294B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004294E0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00429530
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10397ED0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039F7A0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1039F7B0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x1039F7E0
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    C_BaseEntity::operator delete(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)MemAlloc_Alloc(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x1039F890
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_9, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x1039F8C0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x1039F8D0
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x1039F8E0
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039F950
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039F990
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039FA70
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039FAF0
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039FC10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039FC40
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1039FC50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039FC80
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1039FCD0
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103971B0
// Name: public: static char const __near * vgui::AnimatingImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::AnimatingImagePanel::GetPanelClassName()
{
  return "AnimatingImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x103971C0
// Name: protected: virtual void vgui::AnimatingImagePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PerformLayout(vgui::RichText *this)
{
  vgui::Panel::PerformLayout(this);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103971E0
// Name: protected: virtual void vgui::AnimatingImagePanel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::GetSettings(vgui::AnimatingImagePanel *this, KeyValues *outResourceData)
{
  char *m_pImageName; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  m_pImageName = this->m_pImageName;
  if ( m_pImageName != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "image", value: m_pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x10397210
// Name: protected: virtual void vgui::AnimatingImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::AnimatingImagePanel::ApplySettings(
        vgui::AnimatingImagePanel *this@<ecx>,
        int a2@<edi>,
        KeyValues *inResourceData)
{
  char *String; // edi
  int Int; // eax
  unsigned int v7; // edi
  char *v8; // eax
  vgui::AnimatingImagePanel_vtbl *v9; // edi
  int v10; // eax
  char *m_pImageName; // [esp-4h] [ebp-10h]
  char *imageName; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: nullptr);
  imageName = String;
  if ( String != nullptr )
  {
    Int = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0);
    m_pImageName = this->m_pImageName;
    this->m_bScaleImage = Int == 1;
    free(pMem: m_pImageName);
    v7 = _V_strlen(str: String) + 1;
    v8 = (char *)operator new(nSize: v7);
    this->m_pImageName = v8;
    V_strncpy(pDest: v8, pSrc: imageName, maxLen: v7);
    v9 = this->__vftable;
    v10 = KeyValues::GetInt(this: inResourceData, keyName: "frames", defaultValue: 0);
    v9->LoadAnimation(this, a2: this->m_pImageName, a3: v10);
  }
  this->m_iFrameTimeMillis = KeyValues::GetInt(this: inResourceData, keyName: "anim_framerate", defaultValue: 100);
}

//------------------------------------------------------------------------------
// Address: 0x103972C0
// Name: protected: virtual char const __near * vgui::AnimatingImagePanel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::AnimatingImagePanel::GetDescription(vgui::AnimatingImagePanel *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_5, maxLen: 0x400u, pFormat: "%s, string image", Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x103972F0
// Name: public: virtual void vgui::AnimatingImagePanel::StartAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StartAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = true;
}

//------------------------------------------------------------------------------
// Address: 0x10397300
// Name: public: virtual void vgui::AnimatingImagePanel::StopAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::StopAnimation(vgui::AnimatingImagePanel *this)
{
  this->m_bAnimating = false;
}

//------------------------------------------------------------------------------
// Address: 0x10397310
// Name: protected: virtual void vgui::AnimatingImagePanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::OnTick(vgui::AnimatingImagePanel *this)
{
  int v2; // eax
  bool v3; // sf

  if ( this->m_bAnimating && g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) >= this->m_iNextFrameTime )
  {
    v2 = this->m_iFrameTimeMillis + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    v3 = ++this->m_iCurrentImage < 0;
    this->m_iNextFrameTime = v2;
    if ( v3 || this->m_iCurrentImage >= this->m_Frames.m_Size )
      this->m_iCurrentImage = 0;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10397380
// Name: public: virtual void vgui::AnimatingImagePanel::ResetAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::ResetAnimation(vgui::AnimatingImagePanel *this, int frame)
{
  void (*Repaint)(void); // edx

  if ( frame < 0 || frame >= this->m_Frames.m_Size )
  {
    Repaint = (void (*)(void))this->Repaint;
    this->m_iCurrentImage = 0;
    Repaint();
  }
  else
  {
    this->m_iCurrentImage = frame;
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103973C0
// Name: protected: virtual void vgui::AnimatingImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::PaintBackground(vgui::AnimatingImagePanel *this)
{
  int m_iCurrentImage; // eax
  vgui::IImage **m_pMemory; // ecx
  bool v4; // zf
  vgui::IImage **v5; // eax
  vgui::IImage *v6; // esi
  vgui::IImage_vtbl *v7; // edx
  void (__thiscall *SetColor)(vgui::IImage *, Color); // edx
  int imageWide; // [esp+4h] [ebp-14h] BYREF
  int imageTall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  m_iCurrentImage = this->m_iCurrentImage;
  if ( m_iCurrentImage >= 0 && m_iCurrentImage < this->m_Frames.m_Size )
  {
    m_pMemory = this->m_Frames.m_Memory.m_pMemory;
    v4 = m_pMemory[m_iCurrentImage] == nullptr;
    v5 = &m_pMemory[m_iCurrentImage];
    if ( !v4 )
    {
      v6 = *v5;
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
      v6->SetPos(this: v6, a2: 0, a3: 0);
      v7 = v6->__vftable;
      if ( this->m_bScaleImage )
      {
        v7->GetSize(this: v6, a2: &imageWide, a3: &imageTall);
        vgui::Panel::GetSize(this, &wide, &tall);
        v6->SetSize(this: v6, a2: wide, a3: tall);
        SetColor = v6->SetColor;
        v13 = -1;
        ((void (__thiscall *)(vgui::IImage *, int))SetColor)(a1: v6, a2: -1);
        v6->Paint(this: v6);
        v6->SetSize(this: v6, a2: imageWide, a3: imageTall);
      }
      else
      {
        v7->Paint(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103974A0
// Name: public: virtual void vgui::AnimatingImagePanel::LoadAnimation(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::LoadAnimation(
        vgui::AnimatingImagePanel *this,
        const char *baseName,
        int frameCount)
{
  int v3; // ebx
  vgui::AnimatingImagePanel_vtbl *v5; // esi
  int v6; // eax
  char imageName[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 1;
  for ( this->m_Frames.m_Size = 0; v3 <= frameCount; ++v3 )
  {
    V_snprintf(pDest: imageName, maxLen: 0x200u, pFormat: "%s%d", baseName, v3);
    v5 = this->__vftable;
    v6 = ((int (__stdcall *)(char *, bool))g_pVGuiSchemeManager->GetImage)(a1: imageName, a2: this->m_bFiltered);
    v5->AddImage(this, a2: (vgui::IImage *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10397520
// Name: public: vgui::AnimatingImagePanel::AnimatingImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__thiscall vgui::AnimatingImagePanel::AnimatingImagePanel(
        vgui::AnimatingImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::AnimatingImagePanel_vtbl *)&vgui::AnimatingImagePanel::`vftable';
  if ( `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
    v4->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
    v5->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::AnimatingImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
    v6->pfnClassName = vgui::AnimatingImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Frames.m_Memory.m_pMemory = nullptr;
  this->m_Frames.m_Memory.m_nAllocationCount = 0;
  this->m_Frames.m_Memory.m_nGrowSize = 0;
  this->m_Frames.m_Size = 0;
  this->m_Frames.m_pElements = nullptr;
  vpanel = this->_vpanel;
  this->m_iCurrentImage = 0;
  this->m_iFrameTimeMillis = 100;
  this->m_iNextFrameTime = 0;
  this->m_pImageName = nullptr;
  *(_WORD *)&this->m_bFiltered = 0;
  this->m_bAnimating = false;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10397640
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::AnimatingImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::AnimatingImagePanel::GetMessageMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10397670
// Name: public: virtual struct PanelAnimationMap __near * vgui::AnimatingImagePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::AnimatingImagePanel::GetAnimMap(vgui::AnimatingImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "AnimatingImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10397680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::AnimatingImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::AnimatingImagePanel::GetKBMap(vgui::AnimatingImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "AnimatingImagePanel");
  `vgui::AnimatingImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103976B0
// Name: Create_AnimatingImagePanel
// Source: json
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *__cdecl Create_AnimatingImagePanel()
{
  vgui::AnimatingImagePanel *v0; // eax

  v0 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::AnimatingImagePanel::AnimatingImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10397700
// Name: public: virtual void vgui::AnimatingImagePanel::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::AnimatingImagePanel::AddImage(vgui::AnimatingImagePanel *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax
  vgui::IImage *v8; // ecx
  int wide; // [esp+Ch] [ebp-4h] BYREF

  m_nAllocationCount = this->m_Frames.m_Memory.m_nAllocationCount;
  m_Size = this->m_Frames.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Frames,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Frames.m_Size;
  m_pMemory = this->m_Frames.m_Memory.m_pMemory;
  v6 = this->m_Frames.m_Size - m_Size - 1;
  this->m_Frames.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Frames.m_Memory.m_pMemory[m_Size];
  v8 = image;
  if ( v7 != nullptr )
    *v7 = image;
  if ( !this->m_bScaleImage && v8 != nullptr )
  {
    v8->GetSize(this: v8, a2: &wide, a3: (int *)&image);
    vgui::Panel::SetSize(this, wide, tall: (int)image);
  }
}

} // namespace server
