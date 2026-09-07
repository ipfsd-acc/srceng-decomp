// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/splitter.cpp
// Functions: 31
// ============================================================

#include "vgui2\vgui_controls\splitter.h"

//------------------------------------------------------------------------------
// Address: 0x10079290
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Panel::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Panel::GetUnpackStructure(vgui::Panel *this)
{
  return vgui::Panel::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x10285ED0
// Name: public: virtual class Color vgui::Panel::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetFgColor(vgui::Panel *this, Color *result)
{
  *result = this->_fgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3A00
// Name: public: static char const __near * vgui::Splitter::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Splitter::GetPanelClassName()
{
  return "Splitter";
}

//------------------------------------------------------------------------------
// Address: 0x102E3A10
// Name: public: static char const __near * vgui::SplitterHandle::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterHandle::GetPanelClassName()
{
  return "SplitterHandle";
}

//------------------------------------------------------------------------------
// Address: 0x102E3A20
// Name: public: virtual void vgui::SplitterHandle::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::ApplySchemeSettings(vgui::SplitterHandle *this, vgui::IScheme *pScheme)
{
  vgui::SplitterHandle_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color c; // [esp+Ch] [ebp-4h] BYREF

  this->GetBgColor(this, result: &c);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x102E3A80
// Name: public: virtual void vgui::SplitterHandle::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMousePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  if ( !this->m_bDragging )
  {
    v3 = g_pVGuiInput;
    v4 = g_pVGuiInput->__vftable;
    v5 = this->GetVPanel(this);
    v4->SetMouseCapture(this: v3, a2: v5);
    this->m_bDragging = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3AC0
// Name: public: virtual void vgui::SplitterHandle::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseReleased(vgui::SplitterHandle *this, ButtonCode_t code)
{
  if ( this->m_bDragging )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_bDragging = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3AF0
// Name: public: static char const __near * vgui::SplitterChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterChildPanel::GetPanelClassName()
{
  return "SplitterChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x102E3B00
// Name: public: virtual void vgui::Splitter::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetSettings(vgui::Splitter *this, KeyValues *outResourceData)
{
  vgui::Panel::GetSettings(this, outResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102E3B10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterHandle::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterHandle::GetMessageMap(vgui::SplitterHandle *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3B40
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterHandle::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterHandle::GetAnimMap(vgui::SplitterHandle *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterHandle");
}

//------------------------------------------------------------------------------
// Address: 0x102E3B50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterHandle::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterHandle::GetKBMap(vgui::SplitterHandle *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3B80
// Name: public: vgui::SplitterHandle::SplitterHandle(class vgui::Splitter __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterHandle *__thiscall vgui::SplitterHandle::SplitterHandle(
        vgui::SplitterHandle *this,
        vgui::Splitter *parent,
        char *name,
        vgui::SplitterMode_t mode,
        int nIndex)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::SplitterMode_t v9; // edi
  int v10; // eax
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::SplitterHandle_vtbl *)&vgui::SplitterHandle::`vftable';
  if ( `vgui::SplitterHandle::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
    v6->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "SplitterHandle");
    v7->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
    v8->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::GetSize(this: parent, wide: (int *)&name, tall: &h);
  v9 = mode;
  if ( mode != SPLITTER_MODE_HORIZONTAL )
  {
    vgui::Panel::SetSize(this, wide: 4, tall: h);
    vgui::Panel::SetCursor(this, cursor: 0xAu);
  }
  else
  {
    vgui::Panel::SetSize(this, wide: (int)name, tall: 4);
    vgui::Panel::SetCursor(this, cursor: 0xBu);
  }
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  v10 = nIndex;
  this->m_nMode = v9;
  this->m_nIndex = v10;
  this->m_bDragging = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E3CF0
// Name: public: vgui::SplitterChildPanel::SplitterChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterChildPanel *__thiscall vgui::SplitterChildPanel::SplitterChildPanel(
        vgui::SplitterChildPanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::SplitterChildPanel_vtbl *)&vgui::SplitterChildPanel::`vftable';
  if ( `vgui::SplitterChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
    v4->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
    v5->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
    v6->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E3E00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterChildPanel::GetMessageMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3E30
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterChildPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterChildPanel::GetAnimMap(vgui::SplitterChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102E3E40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterChildPanel::GetKBMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3F10
// Name: public: virtual void vgui::Splitter::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::OnSizeChanged(vgui::Splitter *this, int newWide, int newTall)
{
  vgui::Splitter *v3; // ebx
  int m_Size; // ecx
  float v5; // xmm2_4
  int v6; // eax
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // eax
  float *p_m_flPos; // edx
  char *v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  int v19; // edi
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm3_4
  int v23; // ecx
  unsigned int v24; // esi
  vgui::Splitter::SplitterInfo_t *v25; // eax
  float m_flPos; // xmm4_4
  vgui::Splitter::SplitterInfo_t *v27; // eax
  float m_nLockedSize; // xmm0_4
  float v29; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v30; // eax
  bool v31; // zf
  int v32; // eax
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v37; // eax
  int v38; // edx
  int v39; // eax
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v44; // eax
  int *v45; // eax
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // ecx
  int v50; // edx
  vgui::Splitter::SplitterInfo_t *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  int nCount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int newWidea; // [esp+20h] [ebp+8h]

  v3 = this;
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  if ( newTall > 0 && newWide > 0 )
  {
    m_Size = v3->m_Splitters.m_Size;
    v5 = 0.0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0.0;
    nCount = m_Size;
    v10 = 0.0;
    i = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v3->m_Splitters.m_Memory.m_pMemory;
      p_m_flPos = &m_pMemory->m_flPos;
      v13 = (char *)&m_pMemory[1].m_flPos;
      v14 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * v14;
      do
      {
        if ( *((_BYTE *)p_m_flPos + 4) != 0 )
        {
          v7 += *((_DWORD *)p_m_flPos + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*p_m_flPos - v10) + v9;
        }
        if ( v13[4] != 0 )
        {
          v7 += *((_DWORD *)v13 + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v13 - *p_m_flPos) + v9;
        }
        if ( v13[24] != 0 )
        {
          v7 += *((_DWORD *)v13 + 7);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 5) - *(float *)v13) + v9;
        }
        if ( v13[44] != 0 )
        {
          v7 += *((_DWORD *)v13 + 12);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 10) - *((float *)v13 + 5)) + v9;
        }
        v10 = *((float *)v13 + 10);
        p_m_flPos += 20;
        v13 += 80;
        --v14;
      }
      while ( v14 != 0 );
      v3 = this;
      m_Size = nCount;
      v6 = i;
    }
    if ( v6 < m_Size )
    {
      v15 = m_Size - i;
      v16 = (int)&v3->m_Splitters.m_Memory.m_pMemory[v6].m_flPos;
      do
      {
        if ( *(_BYTE *)(v16 + 4) != 0 )
        {
          v7 += *(_DWORD *)(v16 + 8);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v16 - v10) + v9;
        }
        v10 = *(float *)v16;
        v16 += 20;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( v3->m_Mode != SPLITTER_MODE_HORIZONTAL )
      newTall = newWide;
    v17 = newTall - v7;
    if ( newTall - v7 < 4 * v8 )
      v17 = 4 * v8;
    v18 = (float)v17;
    v19 = nCount - 1;
    v20 = 0;
    v21 = v18 / v9;
    v22 = 0.0;
    if ( nCount - 1 >= 4 )
    {
      v23 = 0;
      v24 = ((unsigned int)(nCount - 5) >> 2) + 1;
      newWidea = 4 * v24;
      do
      {
        v25 = v3->m_Splitters.m_Memory.m_pMemory;
        m_flPos = v25[v23].m_flPos;
        v27 = &v25[v23];
        if ( v27->m_bLocked )
          m_nLockedSize = (float)v27->m_nLockedSize;
        else
          m_nLockedSize = (float)(m_flPos - v5) * v21;
        v29 = m_nLockedSize + v22;
        v27->m_flPos = v29;
        v30 = v3->m_Splitters.m_Memory.m_pMemory;
        v31 = !v30[v23 + 1].m_bLocked;
        v32 = (int)&v30[v23 + 1];
        v33 = v29;
        if ( v31 )
        {
          v35 = (float)(*(float *)(v32 + 8) - m_flPos) * v21;
          v34 = *(float *)(v32 + 8);
        }
        else
        {
          v34 = *(float *)(v32 + 8);
          v35 = (float)*(int *)(v32 + 16);
        }
        v36 = v35 + v33;
        *(float *)(v32 + 8) = v36;
        v37 = v3->m_Splitters.m_Memory.m_pMemory;
        v38 = v23 * 20 + 60;
        v31 = !v37[v23 + 2].m_bLocked;
        v39 = (int)&v37[v23 + 2];
        v40 = v36;
        if ( v31 )
        {
          v42 = (float)(*(float *)(v39 + 8) - v34) * v21;
          v41 = *(float *)(v39 + 8);
        }
        else
        {
          v41 = *(float *)(v39 + 8);
          v42 = (float)*(int *)(v39 + 16);
        }
        v43 = v42 + v40;
        *(float *)(v39 + 8) = v43;
        v44 = v3->m_Splitters.m_Memory.m_pMemory;
        v5 = *(float *)((char *)&v44->m_flPos + v38);
        v45 = (int *)((char *)v44 + v38);
        v46 = v43;
        if ( *((_BYTE *)v45 + 12) != 0 )
          v47 = (float)v45[4];
        else
          v47 = (float)(v5 - v41) * v21;
        v48 = v47 + v46;
        v23 += 4;
        --v24;
        *((float *)v45 + 2) = v48;
        v22 = v48;
      }
      while ( v24 != 0 );
      v20 = newWidea;
    }
    if ( v20 < v19 )
    {
      v49 = v20;
      v50 = v19 - v20;
      do
      {
        v51 = &v3->m_Splitters.m_Memory.m_pMemory[v49];
        if ( v51->m_bLocked )
          v52 = (float)v51->m_nLockedSize;
        else
          v52 = (float)(v51->m_flPos - v5) * v21;
        v5 = v51->m_flPos;
        v53 = v52 + v22;
        ++v49;
        --v50;
        v51->m_flPos = v53;
        v22 = v53;
      }
      while ( v50 != 0 );
    }
    v3->m_Splitters.m_Memory.m_pMemory[nCount - 1].m_flPos = (float)newTall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4220
// Name: private: void vgui::Splitter::SetSplitterPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterPosition(vgui::Splitter *this, int nIndex, int nPos)
{
  int v4; // esi
  int v5; // eax
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  int *i; // ecx
  int v8; // edi
  int *p_m_nLockedSize; // ecx
  int j; // edx
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int m_flPos; // ecx
  int v19; // esi
  int v20; // edx
  char *v21; // edx
  int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  vgui::Splitter *v26; // ebx
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  int c; // [esp+8h] [ebp-10h]
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::Splitter *v33; // [esp+14h] [ebp-4h]
  int nMinPos; // [esp+20h] [ebp+8h]
  int nMinPosa; // [esp+20h] [ebp+8h]
  int nPosa; // [esp+24h] [ebp+Ch]

  v33 = this;
  vgui::Panel::GetSize(this, &wide, &tall);
  v4 = tall;
  if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
    v4 = wide;
  if ( v4 != 0 )
  {
    v5 = nIndex;
    if ( nIndex >= 0 )
    {
      m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
      tall = (int)m_pMemory;
      for ( i = &m_pMemory[nIndex].m_nLockedSize; *((_BYTE *)i - 4) != 0; i -= 5 )
      {
        nPos -= *i;
        if ( --v5 < 0 )
          return;
      }
      if ( v5 >= 0 )
      {
        v8 = 0;
        nMinPos = 0;
        if ( v5 > 0 )
        {
          p_m_nLockedSize = &m_pMemory->m_nLockedSize;
          for ( j = v5; j != 0; --j )
          {
            if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
              v8 += *p_m_nLockedSize;
            else
              v8 += 4;
            p_m_nLockedSize += 5;
          }
          nMinPos = v8;
        }
        v11 = this->m_Splitters.m_Size - 1;
        v12 = v5 + 1;
        v13 = v4 - 4;
        c = v11;
        wide = v5 + 1;
        if ( v5 + 1 < v11 )
        {
          v14 = (_DWORD *)(tall + 20 * v12 + 16);
          v15 = v11 - v12;
          do
          {
            if ( *((_BYTE *)v14 - 4) != 0 )
              v13 -= *v14;
            else
              v13 -= 4;
            v14 += 5;
            --v15;
          }
          while ( v15 != 0 );
          v8 = nMinPos;
        }
        v16 = nPos;
        if ( nPos >= v8 )
        {
          if ( nPos > v13 )
            v16 = v13;
        }
        else
        {
          v16 = v8;
        }
        v17 = v5 - 1;
        m_flPos = v16;
        *(float *)(tall + 20 * v5 + 8) = (float)v16;
        v19 = v16;
        if ( v5 - 1 >= 0 )
        {
          v20 = 20 * v17;
          for ( nMinPosa = 20 * v17; ; v20 = nMinPosa )
          {
            v21 = (char *)v33->m_Splitters.m_Memory.m_pMemory + v20;
            if ( v21[32] != 0 )
            {
              v22 = v19 - *((_DWORD *)v21 + 9);
              v23 = v22;
            }
            else
            {
              v22 = -2147483647;
              v23 = v16 - 4;
            }
            v24 = (int)(float)(*((float *)v21 + 2) + 0.5);
            if ( v23 < v24 || v22 > v24 )
            {
              *((float *)v21 + 2) = (float)v23;
              v19 = v23;
            }
            else
            {
              v19 = (int)*((float *)v21 + 2);
            }
            nMinPosa -= 20;
            if ( --v17 < 0 )
              break;
          }
          m_flPos = v16;
        }
        if ( wide >= c )
        {
          v26 = v33;
        }
        else
        {
          v25 = wide;
          nPosa = c - wide;
          do
          {
            v26 = v33;
            v27 = &v33->m_Splitters.m_Memory.m_pMemory[v25];
            if ( v27->m_bLocked )
            {
              v28 = m_flPos + v27->m_nLockedSize;
              m_flPos = v28;
            }
            else
            {
              m_flPos += 4;
              v28 = 0x7FFFFFFF;
            }
            v29 = (int)(float)(v27->m_flPos + 0.5);
            if ( m_flPos > v29 || v28 < v29 )
              v27->m_flPos = (float)m_flPos;
            else
              m_flPos = (int)v27->m_flPos;
            ++v25;
            --nPosa;
          }
          while ( nPosa != 0 );
        }
        v26->InvalidateLayout(this: v26, a2: false, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4430
// Name: public: void vgui::Splitter::EvenlyRespaceSplitters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::EvenlyRespaceSplitters(vgui::Splitter *this)
{
  int m_Size; // ebx
  int v3; // edi
  int *p_m_nLockedSize; // eax
  int v5; // ecx
  int v6; // eax
  float v7; // xmm2_4
  __int128 v8; // xmm0
  int v9; // edi
  int v10; // eax
  unsigned int v11; // edx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ecx
  __int128 v13; // xmm1
  vgui::Splitter::SplitterInfo_t *v14; // ecx
  __int128 v15; // xmm0
  vgui::Splitter::SplitterInfo_t *v16; // ecx
  __int128 v17; // xmm1
  vgui::Splitter::SplitterInfo_t *v18; // ecx
  int v19; // eax
  int v20; // edx
  vgui::Splitter::SplitterInfo_t *v21; // ecx
  int wide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    v3 = 0;
    if ( m_Size > 0 )
    {
      p_m_nLockedSize = &this->m_Splitters.m_Memory.m_pMemory->m_nLockedSize;
      v5 = this->m_Splitters.m_Size;
      do
      {
        if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
          v3 += *p_m_nLockedSize;
        p_m_nLockedSize += 5;
        --v5;
      }
      while ( v5 != 0 );
    }
    vgui::Panel::GetSize(this, &wide, &tall);
    v6 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v6 = wide;
    v7 = (float)(v6 - v3) / (float)m_Size;
    if ( v7 < 4.0 )
      v7 = 4.0;
    v8 = 0;
    v9 = 0;
    if ( m_Size >= 4 )
    {
      v10 = 0;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v9 = 4 * v11;
      do
      {
        m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
        if ( m_pMemory[v10].m_bLocked )
        {
          v13 = COERCE_UNSIGNED_INT((float)m_pMemory[v10].m_nLockedSize);
          *(float *)&v13 = *(float *)&v13 + *(float *)&v8;
        }
        else
        {
          *(float *)&v8 = *(float *)&v8 + v7;
          v13 = v8;
        }
        LODWORD(m_pMemory[v10].m_flPos) = v13;
        v14 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v14[v10 + 1].m_bLocked )
        {
          v15 = COERCE_UNSIGNED_INT((float)v14[v10 + 1].m_nLockedSize);
          *(float *)&v15 = *(float *)&v15 + *(float *)&v13;
        }
        else
        {
          *(float *)&v13 = *(float *)&v13 + v7;
          v15 = v13;
        }
        LODWORD(v14[v10 + 1].m_flPos) = v15;
        v16 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v16[v10 + 2].m_bLocked )
        {
          v17 = COERCE_UNSIGNED_INT((float)v16[v10 + 2].m_nLockedSize);
          *(float *)&v17 = *(float *)&v17 + *(float *)&v15;
        }
        else
        {
          *(float *)&v15 = *(float *)&v15 + v7;
          v17 = v15;
        }
        LODWORD(v16[v10 + 2].m_flPos) = v17;
        v18 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v18[v10 + 3].m_bLocked )
        {
          v8 = COERCE_UNSIGNED_INT((float)v18[v10 + 3].m_nLockedSize);
          *(float *)&v8 = *(float *)&v8 + *(float *)&v17;
        }
        else
        {
          *(float *)&v17 = *(float *)&v17 + v7;
          v8 = v17;
        }
        LODWORD(v18[v10 + 3].m_flPos) = v8;
        v10 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    if ( v9 < m_Size )
    {
      v19 = v9;
      v20 = m_Size - v9;
      do
      {
        v21 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v21[v19].m_bLocked )
          *(float *)&v8 = *(float *)&v8 + (float)v21[v19].m_nLockedSize;
        else
          *(float *)&v8 = *(float *)&v8 + v7;
        LODWORD(v21[v19++].m_flPos) = v8;
        --v20;
      }
      while ( v20 != 0 );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E45E0
// Name: public: virtual void vgui::Splitter::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplyUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // ebx
  void *v4; // esp
  int v5; // edi
  double Float; // st7
  KeyValues *v7; // eax
  int v8; // edx
  float v9; // xmm2_4
  int v10; // ecx
  float *v11; // eax
  unsigned int v12; // edi
  float v13; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ebx
  float v15; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v16; // ebx
  float v17; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v18; // ebx
  float v19; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v20; // ebx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm0_4
  float defaultValue; // [esp+0h] [ebp-9Ch] BYREF
  char string[4]; // [esp+Ch] [ebp-90h] BYREF
  char name[128]; // [esp+10h] [ebp-8Ch]
  int c; // [esp+90h] [ebp-Ch] BYREF
  int wide; // [esp+94h] [ebp-8h]
  float *pFractions; // [esp+98h] [ebp-4h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig);
  *(_DWORD *)&name[124] = this->m_Splitters.m_Size;
  v3 = *(_DWORD *)&name[124];
  v4 = alloca(4 * *(_DWORD *)&name[124]);
  v5 = 0;
  wide = (int)&defaultValue;
  *(float *)&pFractions = 0.0;
  if ( *(int *)&name[124] > 0 )
  {
    do
    {
      _snprintf(string, count: 0x80u, format: "%d_splitter_pos", v5);
      Float = KeyValues::GetFloat(this: userConfig, keyName: string, defaultValue: *(float *)&pFractions + 5.0);
      *(float *)(wide + 4 * v5++) = Float;
      *(float *)&pFractions = Float;
    }
    while ( v5 < v3 );
    if ( *(float *)&pFractions != 0.0 )
    {
      vgui::Panel::GetSize(this, wide: &c, tall: (int *)&userConfig);
      v7 = userConfig;
      if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
        v7 = (KeyValues *)c;
      v8 = 0;
      userConfig = v7;
      if ( v3 >= 4 )
      {
        v9 = (float)(int)v7;
        v10 = 0;
        v11 = (float *)(wide + 8);
        v12 = ((unsigned int)(v3 - 4) >> 2) + 1;
        v13 = 1.0 / *(float *)&pFractions;
        v8 = 4 * v12;
        do
        {
          m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
          v15 = v13 * *(v11 - 2);
          *(v11 - 2) = v15;
          m_pMemory[v10].m_flPos = v15 * v9;
          v16 = this->m_Splitters.m_Memory.m_pMemory;
          v17 = *(v11 - 1) * v13;
          *(v11 - 1) = v17;
          v16[v10 + 1].m_flPos = v17 * v9;
          v18 = this->m_Splitters.m_Memory.m_pMemory;
          v19 = *v11 * v13;
          *v11 = v19;
          v18[v10 + 2].m_flPos = v19 * v9;
          v20 = this->m_Splitters.m_Memory.m_pMemory;
          v21 = v11[1] * v13;
          v11[1] = v21;
          v20[v10 + 3].m_flPos = v21 * v9;
          v11 += 4;
          v10 += 4;
          --v12;
        }
        while ( v12 != 0 );
        v7 = userConfig;
        v3 = *(_DWORD *)&name[124];
      }
      if ( v8 < v3 )
      {
        v22 = (float)(int)v7;
        v23 = 1.0 / *(float *)&pFractions;
        v24 = v8;
        do
        {
          v25 = *(float *)(wide + 4 * v8) * v23;
          *(float *)(wide + 4 * v8) = v25;
          this->m_Splitters.m_Memory.m_pMemory[v24].m_flPos = v22 * v25;
          ++v8;
          ++v24;
        }
        while ( v8 < v3 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E47C0
// Name: public: virtual void vgui::Splitter::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // esi
  int v4; // edi
  char string[8]; // [esp+8h] [ebp-84h] BYREF
  char name[128]; // [esp+10h] [ebp-7Ch]

  vgui::EditablePanel::GetUserConfigSettings(this, userConfig);
  v3 = 0;
  *(_DWORD *)&name[120] = this->m_Splitters.m_Size;
  if ( *(int *)&name[120] > 0 )
  {
    v4 = 0;
    do
    {
      _snprintf(string, count: 0x80u, format: "%d_splitter_pos", v3);
      KeyValues::SetFloat(this: userConfig, keyName: string, value: this->m_Splitters.m_Memory.m_pMemory[v4].m_flPos);
      ++v3;
      ++v4;
    }
    while ( v3 < *(int *)&name[120] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4840
// Name: public: virtual void vgui::Splitter::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::PerformLayout(vgui::Splitter *this)
{
  vgui::Splitter *v1; // esi
  int m_Size; // edi
  int v3; // ecx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  vgui::Panel *m_pPanel; // ebx
  vgui::Panel *m_pHandle; // esi
  int v7; // edi
  bool v8; // zf
  int v9; // [esp+8h] [ebp-18h]
  int h; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  vgui::Splitter *v12; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  int nLastPos; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v12 = this;
  vgui::EditablePanel::PerformLayout(this);
  m_Size = v1->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    vgui::Panel::GetSize(this: v1, wide: &w, tall: &h);
    v3 = 0;
    nLastPos = 0;
    if ( m_Size > 0 )
    {
      v13 = 0;
      v9 = m_Size;
      while ( 1 )
      {
        m_pMemory = v1->m_Splitters.m_Memory.m_pMemory;
        m_pPanel = m_pMemory[v13 / 0x14].m_pPanel;
        m_pHandle = m_pMemory[v13 / 0x14].m_pHandle;
        v7 = (int)(float)(m_pMemory[v13 / 0x14].m_flPos + 0.5);
        if ( v12->m_Mode != SPLITTER_MODE_HORIZONTAL )
        {
          vgui::Panel::SetPos(this: m_pPanel, x: v3, y: 0);
          vgui::Panel::SetSize(this: m_pPanel, wide: v7 - nLastPos, tall: h);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: v7, y: 0);
            vgui::Panel::SetSize(this: m_pHandle, wide: 4, tall: h);
          }
        }
        else
        {
          vgui::Panel::SetPos(this: m_pPanel, x: 0, y: v3);
          vgui::Panel::SetSize(this: m_pPanel, wide: w, tall: v7 - nLastPos);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: 0, y: v7);
            vgui::Panel::SetSize(this: m_pHandle, wide: w, tall: 4);
          }
        }
        v13 += 20;
        v8 = v9-- == 1;
        nLastPos = v7 + 4;
        if ( v8 )
          break;
        v1 = v12;
        v3 = nLastPos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4950
// Name: public: virtual void vgui::SplitterHandle::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnCursorMoved(vgui::SplitterHandle *this, int x, int y)
{
  vgui::Splitter *v4; // edi
  int v5; // eax

  if ( this->m_bDragging )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    v4 = (vgui::Splitter *)this->GetParent(this);
    vgui::Panel::ScreenToLocal(this: v4, &x, &y);
    v5 = y;
    if ( this->m_nMode != SPLITTER_MODE_HORIZONTAL )
      v5 = x;
    vgui::Splitter::SetSplitterPosition(this: v4, nIndex: this->m_nIndex, nPos: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E49C0
// Name: public: virtual void vgui::SplitterHandle::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseDoublePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::Splitter *v2; // eax

  v2 = (vgui::Splitter *)this->GetParent(this);
  vgui::Splitter::EvenlyRespaceSplitters(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102E49E0
// Name: public: virtual void vgui::Splitter::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplySettings(vgui::Splitter *this, KeyValues *inResourceData)
{
  vgui::Panel *v2; // ebx
  int v3; // esi
  int Int; // eax
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int *p_m_Size; // eax
  int j; // edi
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  int *p_m_nLockedSize; // eax
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int m_flPos; // ecx
  int v20; // eax
  int v21; // edx
  char *v22; // edx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  vgui::Splitter *v26; // edi
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  char pBuffer[512]; // [esp+8h] [ebp-228h] BYREF
  int v31; // [esp+208h] [ebp-28h]
  int nSplitterCount; // [esp+20Ch] [ebp-24h]
  int wide; // [esp+210h] [ebp-20h] BYREF
  int v34; // [esp+214h] [ebp-1Ch]
  int tall; // [esp+218h] [ebp-18h] BYREF
  int v36; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v38; // [esp+224h] [ebp-Ch]
  vgui::Splitter *v39; // [esp+228h] [ebp-8h]
  int k; // [esp+22Ch] [ebp-4h]

  v2 = this;
  v39 = this;
  vgui::EditablePanel::ApplySettings(this, inResourceData);
  v3 = 0;
  nSplitterCount = v2[1].m_infoFont - 1;
  i = 0;
  if ( nSplitterCount > 0 )
  {
    v36 = 0;
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 512, pFormat: "splitter%d", v3);
      Int = KeyValues::GetInt(this: inResourceData, keyName: pBuffer, defaultValue: -1);
      if ( Int >= 0 )
      {
        v5 = Int;
        vgui::Panel::GetSize(this: v2, &wide, &tall);
        v6 = tall;
        if ( v2[1]._vpanel != 0 )
          v6 = wide;
        if ( v6 != 0 && i >= 0 )
        {
          v7 = (int *)((char *)&v2[1].m_pTooltips->m_Text.m_Size + v36);
          while ( *((_BYTE *)v7 - 4) != 0 )
          {
            v5 -= *v7;
            v7 -= 5;
            if ( --v3 < 0 )
              goto LABEL_56;
          }
          v38 = v5;
          if ( v3 >= 0 )
          {
            v8 = 0;
            k = 0;
            if ( v3 > 0 )
            {
              p_m_Size = &v2[1].m_pTooltips->m_Text.m_Size;
              for ( j = v3; j != 0; --j )
              {
                if ( *((_BYTE *)p_m_Size - 4) != 0 )
                  v8 += *p_m_Size;
                else
                  v8 += 4;
                p_m_Size += 5;
              }
              k = v8;
            }
            v11 = v2[1].m_infoFont - 1;
            v12 = v3 + 1;
            v13 = v6 - 4;
            v31 = v11;
            v34 = v3 + 1;
            if ( v3 + 1 < v11 )
            {
              p_m_nLockedSize = &v39->m_Splitters.m_Memory.m_pMemory[v12].m_nLockedSize;
              v15 = v11 - v12;
              do
              {
                if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
                  v13 -= *p_m_nLockedSize;
                else
                  v13 -= 4;
                p_m_nLockedSize += 5;
                --v15;
              }
              while ( v15 != 0 );
              v8 = k;
            }
            v16 = v38;
            if ( v38 >= v8 )
            {
              if ( v38 > v13 )
                v16 = v13;
            }
            else
            {
              v16 = v8;
            }
            v17 = v3;
            v18 = v3 - 1;
            m_flPos = v16;
            v39->m_Splitters.m_Memory.m_pMemory[v17].m_flPos = (float)v16;
            v38 = v16;
            v20 = v16;
            if ( v18 >= 0 )
            {
              v21 = 20 * v18;
              for ( k = 20 * v18; ; v21 = k )
              {
                v22 = (char *)v39->m_Splitters.m_Memory.m_pMemory + v21;
                if ( v22[32] != 0 )
                {
                  v20 -= *((_DWORD *)v22 + 9);
                  v23 = v20;
                }
                else
                {
                  v23 = -2147483647;
                  v20 = v16 - 4;
                }
                v24 = (int)(float)(*((float *)v22 + 2) + 0.5);
                if ( v20 < v24 || v23 > v24 )
                  *((float *)v22 + 2) = (float)v20;
                else
                  v20 = (int)*((float *)v22 + 2);
                k -= 20;
                if ( --v18 < 0 )
                  break;
              }
              v11 = v31;
              m_flPos = v38;
            }
            if ( v34 >= v11 )
            {
              v26 = v39;
            }
            else
            {
              v25 = v34;
              k = v11 - v34;
              do
              {
                v26 = v39;
                v27 = &v39->m_Splitters.m_Memory.m_pMemory[v25];
                if ( v27->m_bLocked )
                {
                  v28 = m_flPos + v27->m_nLockedSize;
                  m_flPos = v28;
                }
                else
                {
                  m_flPos += 4;
                  v28 = 0x7FFFFFFF;
                }
                v29 = (int)(float)(v27->m_flPos + 0.5);
                if ( m_flPos > v29 || v28 < v29 )
                  v27->m_flPos = (float)m_flPos;
                else
                  m_flPos = (int)v27->m_flPos;
                ++v25;
                --k;
              }
              while ( k != 0 );
            }
            v26->InvalidateLayout(this: v26, a2: false, a3: false);
            v2 = v39;
          }
        }
      }
LABEL_56:
      v36 += 20;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < nSplitterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4C60
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Splitter::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Splitter::GetMessageMap(vgui::Splitter *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Splitter::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetMessageMap'::`2'::s_pMap;
  `vgui::Splitter::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Splitter");
  `vgui::Splitter::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E4C90
// Name: public: virtual struct PanelAnimationMap __near * vgui::Splitter::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Splitter::GetAnimMap(vgui::Splitter *this)
{
  return FindOrAddPanelAnimationMap(className: "Splitter");
}

//------------------------------------------------------------------------------
// Address: 0x102E4CA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Splitter::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Splitter::GetKBMap(vgui::Splitter *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Splitter::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetKBMap'::`2'::s_pMap;
  `vgui::Splitter::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
  `vgui::Splitter::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E4D10
// Name: private: void vgui::Splitter::RecreateSplitters(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RecreateSplitters(vgui::Splitter *this, int nCount)
{
  int m_Size; // eax
  int v3; // edi
  int i; // esi
  vgui::SplitterChildPanel *m_pPanel; // eax
  vgui::SplitterHandle *m_pHandle; // eax
  int v7; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Splitters; // esi
  int v9; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v12; // ecx
  int v13; // eax
  vgui::SplitterChildPanel *v14; // eax
  vgui::SplitterChildPanel *v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ebx
  vgui::SplitterHandle *v19; // eax
  vgui::SplitterHandle *v20; // eax
  char pBuffer[512]; // [esp+Ch] [ebp-204h] BYREF
  vgui::Panel *parent; // [esp+20Ch] [ebp-4h]

  m_Size = this->m_Splitters.m_Size;
  parent = this;
  if ( m_Size > 0 )
  {
    v3 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      m_pPanel = this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel;
      if ( m_pPanel != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterChildPanel *, int))m_pPanel->dtr_Panel)(
          a1: this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel,
          a2: 1);
        this = (vgui::Splitter *)parent;
      }
      m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v3].m_pHandle;
      if ( m_pHandle != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterHandle *, int))m_pHandle->dtr_Panel)(a1: m_pHandle, a2: 1);
        this = (vgui::Splitter *)parent;
      }
      ++v3;
    }
  }
  v7 = nCount;
  p_m_Splitters = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Splitters;
  v9 = 0;
  this->m_Splitters.m_Size = 0;
  if ( nCount + 1 > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 512, pFormat: "child%d", v9);
      m_pMemory = (int)p_m_Splitters[1].m_pMemory;
      m_nAllocationCount = p_m_Splitters->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: p_m_Splitters, num: m_pMemory - m_nAllocationCount + 1);
      ++p_m_Splitters[1].m_pMemory;
      v12 = p_m_Splitters->m_pMemory;
      v13 = (int)p_m_Splitters[1].m_pMemory - m_pMemory - 1;
      p_m_Splitters[1].m_nAllocationCount = (int)p_m_Splitters->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 20 * v13);
      v14 = (vgui::SplitterChildPanel *)MemAlloc_Alloc(nSize: 0x180u);
      if ( v14 != nullptr )
        v15 = vgui::SplitterChildPanel::SplitterChildPanel(this: v14, parent, panelName: pBuffer);
      else
        v15 = nullptr;
      v16 = m_pMemory;
      *(_DWORD *)&p_m_Splitters->m_pMemory[v16].m_Title.m_Id = v15;
      LOBYTE(p_m_Splitters->m_pMemory[v16].m_Right) = 0;
      ++v9;
      p_m_Splitters->m_pMemory[v16].m_ciFlags = 0;
    }
    while ( v9 < nCount + 1 );
    v7 = nCount;
  }
  v17 = 0;
  if ( v7 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = (vgui::SplitterHandle *)MemAlloc_Alloc(nSize: 0x15Cu);
      if ( v19 != nullptr )
        v20 = vgui::SplitterHandle::SplitterHandle(
                this: v19,
                (vgui::Splitter *)parent,
                name: "SplitterHandle",
                mode: (vgui::SplitterMode_t)parent[1]._vpanel,
                nIndex: v17);
      else
        v20 = nullptr;
      p_m_Splitters->m_pMemory[v18].m_Width = (int)v20;
      v20->MoveToFront(this: v20);
      ++v17;
      ++v18;
    }
    while ( v17 < nCount );
    v7 = nCount;
  }
  p_m_Splitters->m_pMemory[v7].m_Width = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E4EC0
// Name: public: vgui::Splitter::Splitter(class vgui::Panel __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Splitter *__thiscall vgui::Splitter::Splitter(
        vgui::Splitter *this,
        vgui::Panel *parent,
        const char *name,
        vgui::SplitterMode_t mode,
        int nCount)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (vgui::Splitter_vtbl *)&vgui::Splitter::`vftable';
  if ( `vgui::Splitter::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "Splitter");
    v6->pfnClassName = vgui::Splitter::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "Splitter");
    v7->pfnClassName = vgui::Splitter::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
    v8->pfnClassName = vgui::Splitter::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  this->m_Splitters.m_Memory.m_pMemory = nullptr;
  this->m_Splitters.m_Memory.m_nAllocationCount = 0;
  this->m_Splitters.m_Memory.m_nGrowSize = 0;
  this->m_Splitters.m_Size = 0;
  this->m_Splitters.m_pElements = nullptr;
  this->m_Mode = mode;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Splitter::RecreateSplitters(this, nCount);
  vgui::Splitter::EvenlyRespaceSplitters(this);
  return this;
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0062EA10
// Name: public: static char const __near * vgui::Splitter::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Splitter::GetPanelClassName()
{
  return "Splitter";
}

//------------------------------------------------------------------------------
// Address: 0x0062EA20
// Name: public: static char const __near * vgui::SplitterHandle::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterHandle::GetPanelClassName()
{
  return "SplitterHandle";
}

//------------------------------------------------------------------------------
// Address: 0x0062EA30
// Name: public: virtual void vgui::SplitterHandle::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::ApplySchemeSettings(vgui::SplitterHandle *this, vgui::IScheme *pScheme)
{
  vgui::SplitterHandle_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color c; // [esp+Ch] [ebp-4h] BYREF

  this->GetBgColor(this, result: &c);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x0062EA90
// Name: public: virtual void vgui::SplitterHandle::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMousePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  if ( !this->m_bDragging )
  {
    v3 = g_pVGuiInput;
    v4 = g_pVGuiInput->__vftable;
    v5 = this->GetVPanel(this);
    v4->SetMouseCapture(this: v3, a2: v5);
    this->m_bDragging = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062EAD0
// Name: public: virtual void vgui::SplitterHandle::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseReleased(vgui::SplitterHandle *this, ButtonCode_t code)
{
  if ( this->m_bDragging )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_bDragging = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062EB00
// Name: public: static char const __near * vgui::SplitterChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterChildPanel::GetPanelClassName()
{
  return "SplitterChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0062EB10
// Name: public: virtual void vgui::Splitter::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetSettings(vgui::Splitter *this, KeyValues *outResourceData)
{
  vgui::Panel::GetSettings(this, outResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0062EB20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterHandle::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterHandle::GetMessageMap(vgui::SplitterHandle *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"SplitterHandle");
  `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062EB50
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterHandle::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterHandle::GetAnimMap(vgui::SplitterHandle *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterHandle");
}

//------------------------------------------------------------------------------
// Address: 0x0062EB60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterHandle::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterHandle::GetKBMap(vgui::SplitterHandle *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"SplitterHandle");
  `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062EB90
// Name: public: vgui::SplitterHandle::SplitterHandle(class vgui::Splitter __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterHandle *__thiscall vgui::SplitterHandle::SplitterHandle(
        vgui::SplitterHandle *this,
        vgui::Splitter *parent,
        char *name,
        vgui::SplitterMode_t mode,
        int nIndex)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::SplitterMode_t v9; // edi
  int v10; // eax
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::SplitterHandle_vtbl *)&vgui::SplitterHandle::`vftable';
  if ( `vgui::SplitterHandle::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: (void **)"SplitterHandle");
    v6->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "SplitterHandle");
    v7->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"SplitterHandle");
    v8->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::Panel::GetSize(this: parent, wide: (int *)&name, tall: &h);
  v9 = mode;
  if ( mode != SPLITTER_MODE_HORIZONTAL )
  {
    vgui::Panel::SetSize(this, wide: 4, tall: h);
    vgui::Panel::SetCursor(this, cursor: 0xAu);
  }
  else
  {
    vgui::Panel::SetSize(this, wide: (int)name, tall: 4);
    vgui::Panel::SetCursor(this, cursor: 0xBu);
  }
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  v10 = nIndex;
  this->m_nMode = v9;
  this->m_nIndex = v10;
  this->m_bDragging = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062ED00
// Name: public: vgui::SplitterChildPanel::SplitterChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterChildPanel *__thiscall vgui::SplitterChildPanel::SplitterChildPanel(
        vgui::SplitterChildPanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::SplitterChildPanel_vtbl *)&vgui::SplitterChildPanel::`vftable';
  if ( `vgui::SplitterChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"SplitterChildPanel");
    v4->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
    v5->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"SplitterChildPanel");
    v6->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"EditablePanel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062EE10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterChildPanel::GetMessageMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"SplitterChildPanel");
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062EE40
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterChildPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterChildPanel::GetAnimMap(vgui::SplitterChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0062EE50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterChildPanel::GetKBMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"SplitterChildPanel");
  `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062EE80
// Name: public: void vgui::Splitter::SetSplitterColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterColor(vgui::Splitter *this, Color c)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  vgui::SplitterHandle *m_pHandle; // ecx
  vgui::SplitterHandle *v7; // ecx
  int v8; // esi
  int v9; // ebx
  vgui::SplitterHandle *v10; // ecx

  v3 = this->m_Splitters.m_Size - 1;
  if ( c._color[3] != 0 )
  {
    if ( v3 > 0 )
    {
      v4 = 0;
      v5 = this->m_Splitters.m_Size - 1;
      do
      {
        m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v4].m_pHandle;
        m_pHandle->SetBgColor(this: m_pHandle, a2: c);
        v7 = this->m_Splitters.m_Memory.m_pMemory[v4].m_pHandle;
        v7->SetPaintBackgroundEnabled(this: v7, a2: true);
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( v3 > 0 )
  {
    v8 = 0;
    v9 = this->m_Splitters.m_Size - 1;
    do
    {
      v10 = this->m_Splitters.m_Memory.m_pMemory[v8].m_pHandle;
      v10->SetPaintBackgroundEnabled(this: v10, a2: false);
      ++v8;
      --v9;
    }
    while ( v9 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062EF10
// Name: public: virtual void vgui::Splitter::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::OnSizeChanged(vgui::Splitter *this, int newWide, int newTall)
{
  vgui::Splitter *v3; // ebx
  int m_Size; // ecx
  float v5; // xmm2_4
  int v6; // eax
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // eax
  float *p_m_flPos; // edx
  char *v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  int v19; // edi
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm3_4
  int v23; // ecx
  unsigned int v24; // esi
  vgui::Splitter::SplitterInfo_t *v25; // eax
  float m_flPos; // xmm4_4
  vgui::Splitter::SplitterInfo_t *v27; // eax
  float m_nLockedSize; // xmm0_4
  float v29; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v30; // eax
  bool v31; // zf
  int v32; // eax
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v37; // eax
  int v38; // edx
  int v39; // eax
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v44; // eax
  int *v45; // eax
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // ecx
  int v50; // edx
  vgui::Splitter::SplitterInfo_t *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  int nCount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int newWidea; // [esp+20h] [ebp+8h]

  v3 = this;
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  if ( newTall > 0 && newWide > 0 )
  {
    m_Size = v3->m_Splitters.m_Size;
    v5 = 0.0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0.0;
    nCount = m_Size;
    v10 = 0.0;
    i = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v3->m_Splitters.m_Memory.m_pMemory;
      p_m_flPos = &m_pMemory->m_flPos;
      v13 = (char *)&m_pMemory[1].m_flPos;
      v14 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * v14;
      do
      {
        if ( *((_BYTE *)p_m_flPos + 4) != 0 )
        {
          v7 += *((_DWORD *)p_m_flPos + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*p_m_flPos - v10) + v9;
        }
        if ( v13[4] != 0 )
        {
          v7 += *((_DWORD *)v13 + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v13 - *p_m_flPos) + v9;
        }
        if ( v13[24] != 0 )
        {
          v7 += *((_DWORD *)v13 + 7);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 5) - *(float *)v13) + v9;
        }
        if ( v13[44] != 0 )
        {
          v7 += *((_DWORD *)v13 + 12);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 10) - *((float *)v13 + 5)) + v9;
        }
        v10 = *((float *)v13 + 10);
        p_m_flPos += 20;
        v13 += 80;
        --v14;
      }
      while ( v14 != 0 );
      v3 = this;
      m_Size = nCount;
      v6 = i;
    }
    if ( v6 < m_Size )
    {
      v15 = m_Size - i;
      v16 = (int)&v3->m_Splitters.m_Memory.m_pMemory[v6].m_flPos;
      do
      {
        if ( *(_BYTE *)(v16 + 4) != 0 )
        {
          v7 += *(_DWORD *)(v16 + 8);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v16 - v10) + v9;
        }
        v10 = *(float *)v16;
        v16 += 20;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( v3->m_Mode != SPLITTER_MODE_HORIZONTAL )
      newTall = newWide;
    v17 = newTall - v7;
    if ( newTall - v7 < 4 * v8 )
      v17 = 4 * v8;
    v18 = (float)v17;
    v19 = nCount - 1;
    v20 = 0;
    v21 = v18 / v9;
    v22 = 0.0;
    if ( nCount - 1 >= 4 )
    {
      v23 = 0;
      v24 = ((unsigned int)(nCount - 5) >> 2) + 1;
      newWidea = 4 * v24;
      do
      {
        v25 = v3->m_Splitters.m_Memory.m_pMemory;
        m_flPos = v25[v23].m_flPos;
        v27 = &v25[v23];
        if ( v27->m_bLocked )
          m_nLockedSize = (float)v27->m_nLockedSize;
        else
          m_nLockedSize = (float)(m_flPos - v5) * v21;
        v29 = m_nLockedSize + v22;
        v27->m_flPos = v29;
        v30 = v3->m_Splitters.m_Memory.m_pMemory;
        v31 = !v30[v23 + 1].m_bLocked;
        v32 = (int)&v30[v23 + 1];
        v33 = v29;
        if ( v31 )
        {
          v35 = (float)(*(float *)(v32 + 8) - m_flPos) * v21;
          v34 = *(float *)(v32 + 8);
        }
        else
        {
          v34 = *(float *)(v32 + 8);
          v35 = (float)*(int *)(v32 + 16);
        }
        v36 = v35 + v33;
        *(float *)(v32 + 8) = v36;
        v37 = v3->m_Splitters.m_Memory.m_pMemory;
        v38 = v23 * 20 + 60;
        v31 = !v37[v23 + 2].m_bLocked;
        v39 = (int)&v37[v23 + 2];
        v40 = v36;
        if ( v31 )
        {
          v42 = (float)(*(float *)(v39 + 8) - v34) * v21;
          v41 = *(float *)(v39 + 8);
        }
        else
        {
          v41 = *(float *)(v39 + 8);
          v42 = (float)*(int *)(v39 + 16);
        }
        v43 = v42 + v40;
        *(float *)(v39 + 8) = v43;
        v44 = v3->m_Splitters.m_Memory.m_pMemory;
        v5 = *(float *)((char *)&v44->m_flPos + v38);
        v45 = (int *)((char *)v44 + v38);
        v46 = v43;
        if ( *((_BYTE *)v45 + 12) != 0 )
          v47 = (float)v45[4];
        else
          v47 = (float)(v5 - v41) * v21;
        v48 = v47 + v46;
        v23 += 4;
        --v24;
        *((float *)v45 + 2) = v48;
        v22 = v48;
      }
      while ( v24 != 0 );
      v20 = newWidea;
    }
    if ( v20 < v19 )
    {
      v49 = v20;
      v50 = v19 - v20;
      do
      {
        v51 = &v3->m_Splitters.m_Memory.m_pMemory[v49];
        if ( v51->m_bLocked )
          v52 = (float)v51->m_nLockedSize;
        else
          v52 = (float)(v51->m_flPos - v5) * v21;
        v5 = v51->m_flPos;
        v53 = v52 + v22;
        ++v49;
        --v50;
        v51->m_flPos = v53;
        v22 = v53;
      }
      while ( v50 != 0 );
    }
    v3->m_Splitters.m_Memory.m_pMemory[nCount - 1].m_flPos = (float)newTall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F220
// Name: private: void vgui::Splitter::SetSplitterPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterPosition(vgui::Splitter *this, int nIndex, int nPos)
{
  int v4; // esi
  int v5; // eax
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  int *i; // ecx
  int v8; // edi
  int *p_m_nLockedSize; // ecx
  int j; // edx
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int m_flPos; // ecx
  int v19; // esi
  int v20; // edx
  char *v21; // edx
  int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  vgui::Splitter *v26; // ebx
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  int c; // [esp+8h] [ebp-10h]
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::Splitter *v33; // [esp+14h] [ebp-4h]
  int nMinPos; // [esp+20h] [ebp+8h]
  int nMinPosa; // [esp+20h] [ebp+8h]
  int nPosa; // [esp+24h] [ebp+Ch]

  v33 = this;
  vgui::Panel::GetSize(this, &wide, &tall);
  v4 = tall;
  if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
    v4 = wide;
  if ( v4 != 0 )
  {
    v5 = nIndex;
    if ( nIndex >= 0 )
    {
      m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
      tall = (int)m_pMemory;
      for ( i = &m_pMemory[nIndex].m_nLockedSize; *((_BYTE *)i - 4) != 0; i -= 5 )
      {
        nPos -= *i;
        if ( --v5 < 0 )
          return;
      }
      if ( v5 >= 0 )
      {
        v8 = 0;
        nMinPos = 0;
        if ( v5 > 0 )
        {
          p_m_nLockedSize = &m_pMemory->m_nLockedSize;
          for ( j = v5; j != 0; --j )
          {
            if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
              v8 += *p_m_nLockedSize;
            else
              v8 += 4;
            p_m_nLockedSize += 5;
          }
          nMinPos = v8;
        }
        v11 = this->m_Splitters.m_Size - 1;
        v12 = v5 + 1;
        v13 = v4 - 4;
        c = v11;
        wide = v5 + 1;
        if ( v5 + 1 < v11 )
        {
          v14 = (_DWORD *)(tall + 20 * v12 + 16);
          v15 = v11 - v12;
          do
          {
            if ( *((_BYTE *)v14 - 4) != 0 )
              v13 -= *v14;
            else
              v13 -= 4;
            v14 += 5;
            --v15;
          }
          while ( v15 != 0 );
          v8 = nMinPos;
        }
        v16 = nPos;
        if ( nPos >= v8 )
        {
          if ( nPos > v13 )
            v16 = v13;
        }
        else
        {
          v16 = v8;
        }
        v17 = v5 - 1;
        m_flPos = v16;
        *(float *)(tall + 20 * v5 + 8) = (float)v16;
        v19 = v16;
        if ( v5 - 1 >= 0 )
        {
          v20 = 20 * v17;
          for ( nMinPosa = 20 * v17; ; v20 = nMinPosa )
          {
            v21 = (char *)v33->m_Splitters.m_Memory.m_pMemory + v20;
            if ( v21[32] != 0 )
            {
              v22 = v19 - *((_DWORD *)v21 + 9);
              v23 = v22;
            }
            else
            {
              v22 = -2147483647;
              v23 = v16 - 4;
            }
            v24 = (int)(float)(*((float *)v21 + 2) + 0.5);
            if ( v23 < v24 || v22 > v24 )
            {
              *((float *)v21 + 2) = (float)v23;
              v19 = v23;
            }
            else
            {
              v19 = (int)*((float *)v21 + 2);
            }
            nMinPosa -= 20;
            if ( --v17 < 0 )
              break;
          }
          m_flPos = v16;
        }
        if ( wide >= c )
        {
          v26 = v33;
        }
        else
        {
          v25 = wide;
          nPosa = c - wide;
          do
          {
            v26 = v33;
            v27 = &v33->m_Splitters.m_Memory.m_pMemory[v25];
            if ( v27->m_bLocked )
            {
              v28 = m_flPos + v27->m_nLockedSize;
              m_flPos = v28;
            }
            else
            {
              m_flPos += 4;
              v28 = 0x7FFFFFFF;
            }
            v29 = (int)(float)(v27->m_flPos + 0.5);
            if ( m_flPos > v29 || v28 < v29 )
              v27->m_flPos = (float)m_flPos;
            else
              m_flPos = (int)v27->m_flPos;
            ++v25;
            --nPosa;
          }
          while ( nPosa != 0 );
        }
        v26->InvalidateLayout(this: v26, a2: false, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F430
// Name: public: void vgui::Splitter::EvenlyRespaceSplitters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::EvenlyRespaceSplitters(vgui::Splitter *this)
{
  int m_Size; // ebx
  int v3; // edi
  int *p_m_nLockedSize; // eax
  int v5; // ecx
  int v6; // eax
  float v7; // xmm2_4
  __int128 v8; // xmm0
  int v9; // edi
  int v10; // eax
  unsigned int v11; // edx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ecx
  __int128 v13; // xmm1
  vgui::Splitter::SplitterInfo_t *v14; // ecx
  __int128 v15; // xmm0
  vgui::Splitter::SplitterInfo_t *v16; // ecx
  __int128 v17; // xmm1
  vgui::Splitter::SplitterInfo_t *v18; // ecx
  int v19; // eax
  int v20; // edx
  vgui::Splitter::SplitterInfo_t *v21; // ecx
  int wide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    v3 = 0;
    if ( m_Size > 0 )
    {
      p_m_nLockedSize = &this->m_Splitters.m_Memory.m_pMemory->m_nLockedSize;
      v5 = this->m_Splitters.m_Size;
      do
      {
        if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
          v3 += *p_m_nLockedSize;
        p_m_nLockedSize += 5;
        --v5;
      }
      while ( v5 != 0 );
    }
    vgui::Panel::GetSize(this, &wide, &tall);
    v6 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v6 = wide;
    v7 = (float)(v6 - v3) / (float)m_Size;
    if ( v7 < 4.0 )
      v7 = 4.0;
    v8 = 0;
    v9 = 0;
    if ( m_Size >= 4 )
    {
      v10 = 0;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v9 = 4 * v11;
      do
      {
        m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
        if ( m_pMemory[v10].m_bLocked )
        {
          v13 = COERCE_UNSIGNED_INT((float)m_pMemory[v10].m_nLockedSize);
          *(float *)&v13 = *(float *)&v13 + *(float *)&v8;
        }
        else
        {
          *(float *)&v8 = *(float *)&v8 + v7;
          v13 = v8;
        }
        LODWORD(m_pMemory[v10].m_flPos) = v13;
        v14 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v14[v10 + 1].m_bLocked )
        {
          v15 = COERCE_UNSIGNED_INT((float)v14[v10 + 1].m_nLockedSize);
          *(float *)&v15 = *(float *)&v15 + *(float *)&v13;
        }
        else
        {
          *(float *)&v13 = *(float *)&v13 + v7;
          v15 = v13;
        }
        LODWORD(v14[v10 + 1].m_flPos) = v15;
        v16 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v16[v10 + 2].m_bLocked )
        {
          v17 = COERCE_UNSIGNED_INT((float)v16[v10 + 2].m_nLockedSize);
          *(float *)&v17 = *(float *)&v17 + *(float *)&v15;
        }
        else
        {
          *(float *)&v15 = *(float *)&v15 + v7;
          v17 = v15;
        }
        LODWORD(v16[v10 + 2].m_flPos) = v17;
        v18 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v18[v10 + 3].m_bLocked )
        {
          v8 = COERCE_UNSIGNED_INT((float)v18[v10 + 3].m_nLockedSize);
          *(float *)&v8 = *(float *)&v8 + *(float *)&v17;
        }
        else
        {
          *(float *)&v17 = *(float *)&v17 + v7;
          v8 = v17;
        }
        LODWORD(v18[v10 + 3].m_flPos) = v8;
        v10 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    if ( v9 < m_Size )
    {
      v19 = v9;
      v20 = m_Size - v9;
      do
      {
        v21 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v21[v19].m_bLocked )
          *(float *)&v8 = *(float *)&v8 + (float)v21[v19].m_nLockedSize;
        else
          *(float *)&v8 = *(float *)&v8 + v7;
        LODWORD(v21[v19++].m_flPos) = v8;
        --v20;
      }
      while ( v20 != 0 );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F5E0
// Name: public: void vgui::Splitter::RespaceSplitters(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RespaceSplitters(vgui::Splitter *this, float *flFractions)
{
  int m_Size; // ebx
  int v4; // ecx
  float *v5; // eax
  float v6; // xmm0_4
  int v7; // edi
  float v8; // xmm2_4
  int v9; // ecx
  float *v10; // eax
  unsigned int v11; // edx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // ecx
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  float flPos; // [esp+10h] [ebp-8h]
  int tall; // [esp+14h] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    flPos = 0.0;
    vgui::Panel::GetSize(this, &wide, &tall);
    v4 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v4 = wide;
    v5 = flFractions;
    v6 = flPos;
    v7 = 0;
    tall = v4;
    if ( m_Size >= 4 )
    {
      v8 = (float)v4;
      v9 = 0;
      v10 = flFractions + 2;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v7 = 4 * v11;
      do
      {
        v12 = *(v10 - 2) + v6;
        this->m_Splitters.m_Memory.m_pMemory[v9].m_flPos = v8 * v12;
        v13 = *(v10 - 1) + v12;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 1].m_flPos = v8 * v13;
        v14 = v13 + *v10;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 2].m_flPos = v8 * v14;
        v6 = v14 + v10[1];
        this->m_Splitters.m_Memory.m_pMemory[v9 + 3].m_flPos = v8 * v6;
        v10 += 4;
        v9 += 4;
        --v11;
      }
      while ( v11 != 0 );
      v5 = flFractions;
      v4 = tall;
    }
    if ( v7 < m_Size )
    {
      v15 = (float)v4;
      v16 = v7;
      do
      {
        v6 = v6 + v5[v7];
        this->m_Splitters.m_Memory.m_pMemory[v16].m_flPos = v15 * v6;
        ++v7;
        ++v16;
      }
      while ( v7 < m_Size );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F730
// Name: public: virtual void vgui::Splitter::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplyUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // ebx
  void *v4; // esp
  int v5; // edi
  double Float; // st7
  KeyValues *v7; // eax
  int v8; // edx
  float v9; // xmm2_4
  int v10; // ecx
  float *v11; // eax
  unsigned int v12; // edi
  float v13; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ebx
  float v15; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v16; // ebx
  float v17; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v18; // ebx
  float v19; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v20; // ebx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm0_4
  int v26; // [esp+4h] [ebp-9Ch] BYREF
  char name[128]; // [esp+10h] [ebp-90h] BYREF
  int c; // [esp+90h] [ebp-10h]
  int wide; // [esp+94h] [ebp-Ch] BYREF
  float *pFractions; // [esp+98h] [ebp-8h]
  float flTotalSize; // [esp+9Ch] [ebp-4h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig);
  c = this->m_Splitters.m_Size;
  v3 = c;
  v4 = alloca(4 * c);
  v5 = 0;
  pFractions = (float *)&v26;
  flTotalSize = 0.0;
  if ( c > 0 )
  {
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v5);
      Float = KeyValues::GetFloat(this: userConfig, keyName: name, defaultValue: flTotalSize + 5.0);
      pFractions[v5++] = Float;
      flTotalSize = Float;
    }
    while ( v5 < v3 );
    if ( flTotalSize != 0.0 )
    {
      vgui::Panel::GetSize(this, &wide, tall: (int *)&userConfig);
      v7 = userConfig;
      if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
        v7 = (KeyValues *)wide;
      v8 = 0;
      userConfig = v7;
      if ( v3 >= 4 )
      {
        v9 = (float)(int)v7;
        v10 = 0;
        v11 = pFractions + 2;
        v12 = ((unsigned int)(v3 - 4) >> 2) + 1;
        v13 = 1.0 / flTotalSize;
        v8 = 4 * v12;
        do
        {
          m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
          v15 = v13 * *(v11 - 2);
          *(v11 - 2) = v15;
          m_pMemory[v10].m_flPos = v15 * v9;
          v16 = this->m_Splitters.m_Memory.m_pMemory;
          v17 = *(v11 - 1) * v13;
          *(v11 - 1) = v17;
          v16[v10 + 1].m_flPos = v17 * v9;
          v18 = this->m_Splitters.m_Memory.m_pMemory;
          v19 = *v11 * v13;
          *v11 = v19;
          v18[v10 + 2].m_flPos = v19 * v9;
          v20 = this->m_Splitters.m_Memory.m_pMemory;
          v21 = v11[1] * v13;
          v11[1] = v21;
          v20[v10 + 3].m_flPos = v21 * v9;
          v11 += 4;
          v10 += 4;
          --v12;
        }
        while ( v12 != 0 );
        v7 = userConfig;
        v3 = c;
      }
      if ( v8 < v3 )
      {
        v22 = (float)(int)v7;
        v23 = 1.0 / flTotalSize;
        v24 = v8;
        do
        {
          v25 = pFractions[v8] * v23;
          pFractions[v8] = v25;
          this->m_Splitters.m_Memory.m_pMemory[v24].m_flPos = v22 * v25;
          ++v8;
          ++v24;
        }
        while ( v8 < v3 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F910
// Name: public: virtual void vgui::Splitter::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // esi
  int v4; // edi
  char name[128]; // [esp+10h] [ebp-84h] BYREF
  int c; // [esp+90h] [ebp-4h]

  vgui::EditablePanel::GetUserConfigSettings(this, userConfig);
  v3 = 0;
  c = this->m_Splitters.m_Size;
  if ( c > 0 )
  {
    v4 = 0;
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v3);
      KeyValues::SetFloat(this: userConfig, keyName: name, value: this->m_Splitters.m_Memory.m_pMemory[v4].m_flPos);
      ++v3;
      ++v4;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F990
// Name: public: virtual void vgui::Splitter::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::PerformLayout(vgui::Splitter *this)
{
  vgui::Splitter *v1; // esi
  int m_Size; // edi
  int v3; // ecx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  vgui::Panel *m_pPanel; // ebx
  vgui::Panel *m_pHandle; // esi
  int v7; // edi
  bool v8; // zf
  int v9; // [esp+8h] [ebp-18h]
  int h; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  vgui::Splitter *v12; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  int nLastPos; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v12 = this;
  vgui::EditablePanel::PerformLayout(this);
  m_Size = v1->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    vgui::Panel::GetSize(this: v1, wide: &w, tall: &h);
    v3 = 0;
    nLastPos = 0;
    if ( m_Size > 0 )
    {
      v13 = 0;
      v9 = m_Size;
      while ( 1 )
      {
        m_pMemory = v1->m_Splitters.m_Memory.m_pMemory;
        m_pPanel = m_pMemory[v13 / 0x14].m_pPanel;
        m_pHandle = m_pMemory[v13 / 0x14].m_pHandle;
        v7 = (int)(float)(m_pMemory[v13 / 0x14].m_flPos + 0.5);
        if ( v12->m_Mode != SPLITTER_MODE_HORIZONTAL )
        {
          vgui::Panel::SetPos(this: m_pPanel, x: v3, y: 0);
          vgui::Panel::SetSize(this: m_pPanel, wide: v7 - nLastPos, tall: h);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: v7, y: 0);
            vgui::Panel::SetSize(this: m_pHandle, wide: 4, tall: h);
          }
        }
        else
        {
          vgui::Panel::SetPos(this: m_pPanel, x: 0, y: v3);
          vgui::Panel::SetSize(this: m_pPanel, wide: w, tall: v7 - nLastPos);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: 0, y: v7);
            vgui::Panel::SetSize(this: m_pHandle, wide: w, tall: 4);
          }
        }
        v13 += 20;
        v8 = v9-- == 1;
        nLastPos = v7 + 4;
        if ( v8 )
          break;
        v1 = v12;
        v3 = nLastPos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FAA0
// Name: public: virtual void vgui::SplitterHandle::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnCursorMoved(vgui::SplitterHandle *this, int x, int y)
{
  vgui::Splitter *v4; // edi
  int v5; // eax

  if ( this->m_bDragging )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    v4 = (vgui::Splitter *)this->GetParent(this);
    vgui::Panel::ScreenToLocal(this: v4, &x, &y);
    v5 = y;
    if ( this->m_nMode != SPLITTER_MODE_HORIZONTAL )
      v5 = x;
    vgui::Splitter::SetSplitterPosition(this: v4, nIndex: this->m_nIndex, nPos: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FB10
// Name: public: virtual void vgui::SplitterHandle::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseDoublePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::Splitter *v2; // eax

  v2 = (vgui::Splitter *)this->GetParent(this);
  vgui::Splitter::EvenlyRespaceSplitters(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0062FB30
// Name: public: virtual void vgui::Splitter::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplySettings(vgui::Splitter *this, KeyValues *inResourceData)
{
  vgui::Panel *v2; // ebx
  int v3; // esi
  int Int; // eax
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int *p_m_nGrowSize; // eax
  int j; // edi
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  int *p_m_nLockedSize; // eax
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int m_flPos; // ecx
  int v20; // eax
  int v21; // edx
  char *v22; // edx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  vgui::Splitter *v26; // edi
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  char pBuffer[512]; // [esp+8h] [ebp-228h] BYREF
  int v31; // [esp+208h] [ebp-28h]
  int nSplitterCount; // [esp+20Ch] [ebp-24h]
  int wide; // [esp+210h] [ebp-20h] BYREF
  int v34; // [esp+214h] [ebp-1Ch]
  int tall; // [esp+218h] [ebp-18h] BYREF
  int v36; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v38; // [esp+224h] [ebp-Ch]
  vgui::Splitter *v39; // [esp+228h] [ebp-8h]
  int k; // [esp+22Ch] [ebp-4h]

  v2 = this;
  v39 = this;
  vgui::EditablePanel::ApplySettings(this, a2: (int)this, inResourceData);
  v3 = 0;
  nSplitterCount = v2[1].m_infoFont - 1;
  i = 0;
  if ( nSplitterCount > 0 )
  {
    v36 = 0;
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "splitter%d", v3);
      Int = KeyValues::GetInt(this: inResourceData, keyName: pBuffer, defaultValue: -1);
      if ( Int >= 0 )
      {
        v5 = Int;
        vgui::Panel::GetSize(this: v2, &wide, &tall);
        v6 = tall;
        if ( v2[1]._vpanel != 0 )
          v6 = wide;
        if ( v6 != 0 && i >= 0 )
        {
          v7 = (int *)((char *)&v2[1].m_pTooltips->m_Text.m_Memory.m_nGrowSize + v36);
          while ( *((_BYTE *)v7 - 4) != 0 )
          {
            v5 -= *v7;
            v7 -= 5;
            if ( --v3 < 0 )
              goto LABEL_56;
          }
          v38 = v5;
          if ( v3 >= 0 )
          {
            v8 = 0;
            k = 0;
            if ( v3 > 0 )
            {
              p_m_nGrowSize = &v2[1].m_pTooltips->m_Text.m_Memory.m_nGrowSize;
              for ( j = v3; j != 0; --j )
              {
                if ( *((_BYTE *)p_m_nGrowSize - 4) != 0 )
                  v8 += *p_m_nGrowSize;
                else
                  v8 += 4;
                p_m_nGrowSize += 5;
              }
              k = v8;
            }
            v11 = v2[1].m_infoFont - 1;
            v12 = v3 + 1;
            v13 = v6 - 4;
            v31 = v11;
            v34 = v3 + 1;
            if ( v3 + 1 < v11 )
            {
              p_m_nLockedSize = &v39->m_Splitters.m_Memory.m_pMemory[v12].m_nLockedSize;
              v15 = v11 - v12;
              do
              {
                if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
                  v13 -= *p_m_nLockedSize;
                else
                  v13 -= 4;
                p_m_nLockedSize += 5;
                --v15;
              }
              while ( v15 != 0 );
              v8 = k;
            }
            v16 = v38;
            if ( v38 >= v8 )
            {
              if ( v38 > v13 )
                v16 = v13;
            }
            else
            {
              v16 = v8;
            }
            v17 = v3;
            v18 = v3 - 1;
            m_flPos = v16;
            v39->m_Splitters.m_Memory.m_pMemory[v17].m_flPos = (float)v16;
            v38 = v16;
            v20 = v16;
            if ( v18 >= 0 )
            {
              v21 = 20 * v18;
              for ( k = 20 * v18; ; v21 = k )
              {
                v22 = (char *)v39->m_Splitters.m_Memory.m_pMemory + v21;
                if ( v22[32] != 0 )
                {
                  v20 -= *((_DWORD *)v22 + 9);
                  v23 = v20;
                }
                else
                {
                  v23 = -2147483647;
                  v20 = v16 - 4;
                }
                v24 = (int)(float)(*((float *)v22 + 2) + 0.5);
                if ( v20 < v24 || v23 > v24 )
                  *((float *)v22 + 2) = (float)v20;
                else
                  v20 = (int)*((float *)v22 + 2);
                k -= 20;
                if ( --v18 < 0 )
                  break;
              }
              v11 = v31;
              m_flPos = v38;
            }
            if ( v34 >= v11 )
            {
              v26 = v39;
            }
            else
            {
              v25 = v34;
              k = v11 - v34;
              do
              {
                v26 = v39;
                v27 = &v39->m_Splitters.m_Memory.m_pMemory[v25];
                if ( v27->m_bLocked )
                {
                  v28 = m_flPos + v27->m_nLockedSize;
                  m_flPos = v28;
                }
                else
                {
                  m_flPos += 4;
                  v28 = 0x7FFFFFFF;
                }
                v29 = (int)(float)(v27->m_flPos + 0.5);
                if ( m_flPos > v29 || v28 < v29 )
                  v27->m_flPos = (float)m_flPos;
                else
                  m_flPos = (int)v27->m_flPos;
                ++v25;
                --k;
              }
              while ( k != 0 );
            }
            v26->InvalidateLayout(this: v26, a2: false, a3: false);
            v2 = v39;
          }
        }
      }
LABEL_56:
      v36 += 20;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < nSplitterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FDB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Splitter::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Splitter::GetMessageMap(vgui::Splitter *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Splitter::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetMessageMap'::`2'::s_pMap;
  `vgui::Splitter::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"Splitter");
  `vgui::Splitter::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062FDE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Splitter::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Splitter::GetAnimMap(vgui::Splitter *this)
{
  return FindOrAddPanelAnimationMap(className: "Splitter");
}

//------------------------------------------------------------------------------
// Address: 0x0062FDF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Splitter::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Splitter::GetKBMap(vgui::Splitter *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Splitter::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetKBMap'::`2'::s_pMap;
  `vgui::Splitter::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Splitter");
  `vgui::Splitter::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062FE60
// Name: private: void vgui::Splitter::RecreateSplitters(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RecreateSplitters(vgui::Splitter *this, int nCount)
{
  int m_Size; // eax
  int v3; // edi
  int i; // esi
  vgui::SplitterChildPanel *m_pPanel; // eax
  vgui::SplitterHandle *m_pHandle; // eax
  int v7; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Splitters; // esi
  int v9; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v12; // ecx
  int v13; // eax
  vgui::SplitterChildPanel *v14; // eax
  vgui::SplitterChildPanel *v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ebx
  vgui::SplitterHandle *v19; // eax
  vgui::SplitterHandle *v20; // eax
  char pBuffer[512]; // [esp+Ch] [ebp-204h] BYREF
  vgui::Panel *parent; // [esp+20Ch] [ebp-4h]

  m_Size = this->m_Splitters.m_Size;
  parent = this;
  if ( m_Size > 0 )
  {
    v3 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      m_pPanel = this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel;
      if ( m_pPanel != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterChildPanel *, int))m_pPanel->dtr_Panel)(
          a1: this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel,
          a2: 1);
        this = (vgui::Splitter *)parent;
      }
      m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v3].m_pHandle;
      if ( m_pHandle != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterHandle *, int))m_pHandle->dtr_Panel)(a1: m_pHandle, a2: 1);
        this = (vgui::Splitter *)parent;
      }
      ++v3;
    }
  }
  v7 = nCount;
  p_m_Splitters = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Splitters;
  v9 = 0;
  this->m_Splitters.m_Size = 0;
  if ( nCount + 1 > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "child%d", v9);
      m_pMemory = (int)p_m_Splitters[1].m_pMemory;
      m_nAllocationCount = p_m_Splitters->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: p_m_Splitters,
          num: m_pMemory - m_nAllocationCount + 1);
      ++p_m_Splitters[1].m_pMemory;
      v12 = p_m_Splitters->m_pMemory;
      v13 = (int)p_m_Splitters[1].m_pMemory - m_pMemory - 1;
      p_m_Splitters[1].m_nAllocationCount = (int)p_m_Splitters->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v12[m_pMemory + 1],
          src: (unsigned __int8 *)&v12[m_pMemory],
          count: 20 * v13);
      v14 = (vgui::SplitterChildPanel *)MemAlloc_Alloc(nSize: 0x180u);
      if ( v14 != nullptr )
        v15 = vgui::SplitterChildPanel::SplitterChildPanel(this: v14, parent, panelName: pBuffer);
      else
        v15 = nullptr;
      v16 = m_pMemory;
      *(_DWORD *)&p_m_Splitters->m_pMemory[v16].m_Title.m_Id = v15;
      LOBYTE(p_m_Splitters->m_pMemory[v16].m_Right) = 0;
      ++v9;
      p_m_Splitters->m_pMemory[v16].m_ciFlags = 0;
    }
    while ( v9 < nCount + 1 );
    v7 = nCount;
  }
  v17 = 0;
  if ( v7 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = (vgui::SplitterHandle *)MemAlloc_Alloc(nSize: 0x15Cu);
      if ( v19 != nullptr )
        v20 = vgui::SplitterHandle::SplitterHandle(
                this: v19,
                (vgui::Splitter *)parent,
                name: "SplitterHandle",
                mode: (vgui::SplitterMode_t)parent[1]._vpanel,
                nIndex: v17);
      else
        v20 = nullptr;
      p_m_Splitters->m_pMemory[v18].m_Width = (int)v20;
      v20->MoveToFront(this: v20);
      ++v17;
      ++v18;
    }
    while ( v17 < nCount );
    v7 = nCount;
  }
  p_m_Splitters->m_pMemory[v7].m_Width = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00630010
// Name: public: vgui::Splitter::Splitter(class vgui::Panel __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Splitter *__thiscall vgui::Splitter::Splitter(
        vgui::Splitter *this,
        vgui::Panel *parent,
        char *name,
        vgui::SplitterMode_t mode,
        int nCount)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (vgui::Splitter_vtbl *)&vgui::Splitter::`vftable';
  if ( `vgui::Splitter::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: (void **)"Splitter");
    v6->pfnClassName = vgui::Splitter::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
  }
  if ( `vgui::Splitter::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "Splitter");
    v7->pfnClassName = vgui::Splitter::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Splitter");
    v8->pfnClassName = vgui::Splitter::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"EditablePanel");
  }
  this->m_Splitters.m_Memory.m_pMemory = nullptr;
  this->m_Splitters.m_Memory.m_nAllocationCount = 0;
  this->m_Splitters.m_Memory.m_nGrowSize = 0;
  this->m_Splitters.m_Size = 0;
  this->m_Splitters.m_pElements = nullptr;
  this->m_Mode = mode;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Splitter::RecreateSplitters(this, nCount);
  vgui::Splitter::EvenlyRespaceSplitters(this);
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10078F50
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Panel::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Panel::GetUnpackStructure(vgui::Panel *this)
{
  return vgui::Panel::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x10286030
// Name: public: virtual class Color vgui::Panel::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetFgColor(vgui::Panel *this, Color *result)
{
  *result = this->_fgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3B70
// Name: public: static char const __near * vgui::Splitter::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Splitter::GetPanelClassName()
{
  return "Splitter";
}

//------------------------------------------------------------------------------
// Address: 0x102E3B90
// Name: public: virtual void vgui::SplitterHandle::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::ApplySchemeSettings(vgui::SplitterHandle *this, vgui::IScheme *pScheme)
{
  vgui::SplitterHandle_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color c; // [esp+Ch] [ebp-4h] BYREF

  this->GetBgColor(this, result: &c);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x102E3BF0
// Name: public: virtual void vgui::SplitterHandle::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMousePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  if ( !this->m_bDragging )
  {
    v3 = g_pVGuiInput;
    v4 = g_pVGuiInput->__vftable;
    v5 = this->GetVPanel(this);
    v4->SetMouseCapture(this: v3, a2: v5);
    this->m_bDragging = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3C30
// Name: public: virtual void vgui::SplitterHandle::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseReleased(vgui::SplitterHandle *this, ButtonCode_t code)
{
  if ( this->m_bDragging )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_bDragging = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3C60
// Name: public: static char const __near * vgui::SplitterChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterChildPanel::GetPanelClassName()
{
  return "SplitterChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x102E3C70
// Name: public: virtual void vgui::Splitter::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetSettings(vgui::Splitter *this, KeyValues *outResourceData)
{
  vgui::Panel::GetSettings(this, outResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102E3C80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterHandle::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterHandle::GetMessageMap(vgui::SplitterHandle *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3CB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterHandle::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterHandle::GetAnimMap(vgui::SplitterHandle *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterHandle");
}

//------------------------------------------------------------------------------
// Address: 0x102E3CC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterHandle::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterHandle::GetKBMap(vgui::SplitterHandle *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3E60
// Name: public: vgui::SplitterChildPanel::SplitterChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterChildPanel *__thiscall vgui::SplitterChildPanel::SplitterChildPanel(
        vgui::SplitterChildPanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::SplitterChildPanel_vtbl *)&vgui::SplitterChildPanel::`vftable';
  if ( `vgui::SplitterChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
    v4->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
    v5->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
    v6->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E3F70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterChildPanel::GetMessageMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3FA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterChildPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterChildPanel::GetAnimMap(vgui::SplitterChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102E3FB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterChildPanel::GetKBMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E3FE0
// Name: public: virtual void vgui::Splitter::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::OnSizeChanged(vgui::Splitter *this, int newWide, int newTall)
{
  vgui::Splitter *v3; // ebx
  int m_Size; // ecx
  float v5; // xmm2_4
  int v6; // eax
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // eax
  float *p_m_flPos; // edx
  char *v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  int v19; // edi
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm3_4
  int v23; // ecx
  unsigned int v24; // esi
  vgui::Splitter::SplitterInfo_t *v25; // eax
  float m_flPos; // xmm4_4
  vgui::Splitter::SplitterInfo_t *v27; // eax
  float m_nLockedSize; // xmm0_4
  float v29; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v30; // eax
  bool v31; // zf
  int v32; // eax
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v37; // eax
  int v38; // edx
  int v39; // eax
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v44; // eax
  int *v45; // eax
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // ecx
  int v50; // edx
  vgui::Splitter::SplitterInfo_t *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  int nCount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int newWidea; // [esp+20h] [ebp+8h]

  v3 = this;
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  if ( newTall > 0 && newWide > 0 )
  {
    m_Size = v3->m_Splitters.m_Size;
    v5 = 0.0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0.0;
    nCount = m_Size;
    v10 = 0.0;
    i = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v3->m_Splitters.m_Memory.m_pMemory;
      p_m_flPos = &m_pMemory->m_flPos;
      v13 = (char *)&m_pMemory[1].m_flPos;
      v14 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * v14;
      do
      {
        if ( *((_BYTE *)p_m_flPos + 4) != 0 )
        {
          v7 += *((_DWORD *)p_m_flPos + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*p_m_flPos - v10) + v9;
        }
        if ( v13[4] != 0 )
        {
          v7 += *((_DWORD *)v13 + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v13 - *p_m_flPos) + v9;
        }
        if ( v13[24] != 0 )
        {
          v7 += *((_DWORD *)v13 + 7);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 5) - *(float *)v13) + v9;
        }
        if ( v13[44] != 0 )
        {
          v7 += *((_DWORD *)v13 + 12);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 10) - *((float *)v13 + 5)) + v9;
        }
        v10 = *((float *)v13 + 10);
        p_m_flPos += 20;
        v13 += 80;
        --v14;
      }
      while ( v14 != 0 );
      v3 = this;
      m_Size = nCount;
      v6 = i;
    }
    if ( v6 < m_Size )
    {
      v15 = m_Size - i;
      v16 = (int)&v3->m_Splitters.m_Memory.m_pMemory[v6].m_flPos;
      do
      {
        if ( *(_BYTE *)(v16 + 4) != 0 )
        {
          v7 += *(_DWORD *)(v16 + 8);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v16 - v10) + v9;
        }
        v10 = *(float *)v16;
        v16 += 20;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( v3->m_Mode != SPLITTER_MODE_HORIZONTAL )
      newTall = newWide;
    v17 = newTall - v7;
    if ( newTall - v7 < 4 * v8 )
      v17 = 4 * v8;
    v18 = (float)v17;
    v19 = nCount - 1;
    v20 = 0;
    v21 = v18 / v9;
    v22 = 0.0;
    if ( nCount - 1 >= 4 )
    {
      v23 = 0;
      v24 = ((unsigned int)(nCount - 5) >> 2) + 1;
      newWidea = 4 * v24;
      do
      {
        v25 = v3->m_Splitters.m_Memory.m_pMemory;
        m_flPos = v25[v23].m_flPos;
        v27 = &v25[v23];
        if ( v27->m_bLocked )
          m_nLockedSize = (float)v27->m_nLockedSize;
        else
          m_nLockedSize = (float)(m_flPos - v5) * v21;
        v29 = m_nLockedSize + v22;
        v27->m_flPos = v29;
        v30 = v3->m_Splitters.m_Memory.m_pMemory;
        v31 = !v30[v23 + 1].m_bLocked;
        v32 = (int)&v30[v23 + 1];
        v33 = v29;
        if ( v31 )
        {
          v35 = (float)(*(float *)(v32 + 8) - m_flPos) * v21;
          v34 = *(float *)(v32 + 8);
        }
        else
        {
          v34 = *(float *)(v32 + 8);
          v35 = (float)*(int *)(v32 + 16);
        }
        v36 = v35 + v33;
        *(float *)(v32 + 8) = v36;
        v37 = v3->m_Splitters.m_Memory.m_pMemory;
        v38 = v23 * 20 + 60;
        v31 = !v37[v23 + 2].m_bLocked;
        v39 = (int)&v37[v23 + 2];
        v40 = v36;
        if ( v31 )
        {
          v42 = (float)(*(float *)(v39 + 8) - v34) * v21;
          v41 = *(float *)(v39 + 8);
        }
        else
        {
          v41 = *(float *)(v39 + 8);
          v42 = (float)*(int *)(v39 + 16);
        }
        v43 = v42 + v40;
        *(float *)(v39 + 8) = v43;
        v44 = v3->m_Splitters.m_Memory.m_pMemory;
        v5 = *(float *)((char *)&v44->m_flPos + v38);
        v45 = (int *)((char *)v44 + v38);
        v46 = v43;
        if ( *((_BYTE *)v45 + 12) != 0 )
          v47 = (float)v45[4];
        else
          v47 = (float)(v5 - v41) * v21;
        v48 = v47 + v46;
        v23 += 4;
        --v24;
        *((float *)v45 + 2) = v48;
        v22 = v48;
      }
      while ( v24 != 0 );
      v20 = newWidea;
    }
    if ( v20 < v19 )
    {
      v49 = v20;
      v50 = v19 - v20;
      do
      {
        v51 = &v3->m_Splitters.m_Memory.m_pMemory[v49];
        if ( v51->m_bLocked )
          v52 = (float)v51->m_nLockedSize;
        else
          v52 = (float)(v51->m_flPos - v5) * v21;
        v5 = v51->m_flPos;
        v53 = v52 + v22;
        ++v49;
        --v50;
        v51->m_flPos = v53;
        v22 = v53;
      }
      while ( v50 != 0 );
    }
    v3->m_Splitters.m_Memory.m_pMemory[nCount - 1].m_flPos = (float)newTall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E42F0
// Name: private: void vgui::Splitter::SetSplitterPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterPosition(vgui::Splitter *this, int nIndex, int nPos)
{
  int v4; // esi
  int v5; // eax
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  int *i; // ecx
  int v8; // edi
  int *p_m_nLockedSize; // ecx
  int j; // edx
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int m_flPos; // ecx
  int v19; // esi
  int v20; // edx
  char *v21; // edx
  int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  vgui::Splitter *v26; // ebx
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  int c; // [esp+8h] [ebp-10h]
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::Splitter *v33; // [esp+14h] [ebp-4h]
  int nMinPos; // [esp+20h] [ebp+8h]
  int nMinPosa; // [esp+20h] [ebp+8h]
  int nPosa; // [esp+24h] [ebp+Ch]

  v33 = this;
  vgui::Panel::GetSize(this, &wide, &tall);
  v4 = tall;
  if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
    v4 = wide;
  if ( v4 != 0 )
  {
    v5 = nIndex;
    if ( nIndex >= 0 )
    {
      m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
      tall = (int)m_pMemory;
      for ( i = &m_pMemory[nIndex].m_nLockedSize; *((_BYTE *)i - 4) != 0; i -= 5 )
      {
        nPos -= *i;
        if ( --v5 < 0 )
          return;
      }
      if ( v5 >= 0 )
      {
        v8 = 0;
        nMinPos = 0;
        if ( v5 > 0 )
        {
          p_m_nLockedSize = &m_pMemory->m_nLockedSize;
          for ( j = v5; j != 0; --j )
          {
            if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
              v8 += *p_m_nLockedSize;
            else
              v8 += 4;
            p_m_nLockedSize += 5;
          }
          nMinPos = v8;
        }
        v11 = this->m_Splitters.m_Size - 1;
        v12 = v5 + 1;
        v13 = v4 - 4;
        c = v11;
        wide = v5 + 1;
        if ( v5 + 1 < v11 )
        {
          v14 = (_DWORD *)(tall + 20 * v12 + 16);
          v15 = v11 - v12;
          do
          {
            if ( *((_BYTE *)v14 - 4) != 0 )
              v13 -= *v14;
            else
              v13 -= 4;
            v14 += 5;
            --v15;
          }
          while ( v15 != 0 );
          v8 = nMinPos;
        }
        v16 = nPos;
        if ( nPos >= v8 )
        {
          if ( nPos > v13 )
            v16 = v13;
        }
        else
        {
          v16 = v8;
        }
        v17 = v5 - 1;
        m_flPos = v16;
        *(float *)(tall + 20 * v5 + 8) = (float)v16;
        v19 = v16;
        if ( v5 - 1 >= 0 )
        {
          v20 = 20 * v17;
          for ( nMinPosa = 20 * v17; ; v20 = nMinPosa )
          {
            v21 = (char *)v33->m_Splitters.m_Memory.m_pMemory + v20;
            if ( v21[32] != 0 )
            {
              v22 = v19 - *((_DWORD *)v21 + 9);
              v23 = v22;
            }
            else
            {
              v22 = -2147483647;
              v23 = v16 - 4;
            }
            v24 = (int)(float)(*((float *)v21 + 2) + 0.5);
            if ( v23 < v24 || v22 > v24 )
            {
              *((float *)v21 + 2) = (float)v23;
              v19 = v23;
            }
            else
            {
              v19 = (int)*((float *)v21 + 2);
            }
            nMinPosa -= 20;
            if ( --v17 < 0 )
              break;
          }
          m_flPos = v16;
        }
        if ( wide >= c )
        {
          v26 = v33;
        }
        else
        {
          v25 = wide;
          nPosa = c - wide;
          do
          {
            v26 = v33;
            v27 = &v33->m_Splitters.m_Memory.m_pMemory[v25];
            if ( v27->m_bLocked )
            {
              v28 = m_flPos + v27->m_nLockedSize;
              m_flPos = v28;
            }
            else
            {
              m_flPos += 4;
              v28 = 0x7FFFFFFF;
            }
            v29 = (int)(float)(v27->m_flPos + 0.5);
            if ( m_flPos > v29 || v28 < v29 )
              v27->m_flPos = (float)m_flPos;
            else
              m_flPos = (int)v27->m_flPos;
            ++v25;
            --nPosa;
          }
          while ( nPosa != 0 );
        }
        v26->InvalidateLayout(this: v26, a2: false, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4500
// Name: public: void vgui::Splitter::EvenlyRespaceSplitters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::EvenlyRespaceSplitters(vgui::Splitter *this)
{
  int m_Size; // ebx
  int v3; // edi
  int *p_m_nLockedSize; // eax
  int v5; // ecx
  int v6; // eax
  float v7; // xmm2_4
  __int128 v8; // xmm0
  int v9; // edi
  int v10; // eax
  unsigned int v11; // edx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ecx
  __int128 v13; // xmm1
  vgui::Splitter::SplitterInfo_t *v14; // ecx
  __int128 v15; // xmm0
  vgui::Splitter::SplitterInfo_t *v16; // ecx
  __int128 v17; // xmm1
  vgui::Splitter::SplitterInfo_t *v18; // ecx
  int v19; // eax
  int v20; // edx
  vgui::Splitter::SplitterInfo_t *v21; // ecx
  int wide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    v3 = 0;
    if ( m_Size > 0 )
    {
      p_m_nLockedSize = &this->m_Splitters.m_Memory.m_pMemory->m_nLockedSize;
      v5 = this->m_Splitters.m_Size;
      do
      {
        if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
          v3 += *p_m_nLockedSize;
        p_m_nLockedSize += 5;
        --v5;
      }
      while ( v5 != 0 );
    }
    vgui::Panel::GetSize(this, &wide, &tall);
    v6 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v6 = wide;
    v7 = (float)(v6 - v3) / (float)m_Size;
    if ( v7 < 4.0 )
      v7 = 4.0;
    v8 = 0;
    v9 = 0;
    if ( m_Size >= 4 )
    {
      v10 = 0;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v9 = 4 * v11;
      do
      {
        m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
        if ( m_pMemory[v10].m_bLocked )
        {
          v13 = COERCE_UNSIGNED_INT((float)m_pMemory[v10].m_nLockedSize);
          *(float *)&v13 = *(float *)&v13 + *(float *)&v8;
        }
        else
        {
          *(float *)&v8 = *(float *)&v8 + v7;
          v13 = v8;
        }
        LODWORD(m_pMemory[v10].m_flPos) = v13;
        v14 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v14[v10 + 1].m_bLocked )
        {
          v15 = COERCE_UNSIGNED_INT((float)v14[v10 + 1].m_nLockedSize);
          *(float *)&v15 = *(float *)&v15 + *(float *)&v13;
        }
        else
        {
          *(float *)&v13 = *(float *)&v13 + v7;
          v15 = v13;
        }
        LODWORD(v14[v10 + 1].m_flPos) = v15;
        v16 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v16[v10 + 2].m_bLocked )
        {
          v17 = COERCE_UNSIGNED_INT((float)v16[v10 + 2].m_nLockedSize);
          *(float *)&v17 = *(float *)&v17 + *(float *)&v15;
        }
        else
        {
          *(float *)&v15 = *(float *)&v15 + v7;
          v17 = v15;
        }
        LODWORD(v16[v10 + 2].m_flPos) = v17;
        v18 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v18[v10 + 3].m_bLocked )
        {
          v8 = COERCE_UNSIGNED_INT((float)v18[v10 + 3].m_nLockedSize);
          *(float *)&v8 = *(float *)&v8 + *(float *)&v17;
        }
        else
        {
          *(float *)&v17 = *(float *)&v17 + v7;
          v8 = v17;
        }
        LODWORD(v18[v10 + 3].m_flPos) = v8;
        v10 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    if ( v9 < m_Size )
    {
      v19 = v9;
      v20 = m_Size - v9;
      do
      {
        v21 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v21[v19].m_bLocked )
          *(float *)&v8 = *(float *)&v8 + (float)v21[v19].m_nLockedSize;
        else
          *(float *)&v8 = *(float *)&v8 + v7;
        LODWORD(v21[v19++].m_flPos) = v8;
        --v20;
      }
      while ( v20 != 0 );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E46B0
// Name: public: virtual void vgui::Splitter::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplyUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // ebx
  void *v4; // esp
  int v5; // edi
  double Float; // st7
  KeyValues *v7; // eax
  int v8; // edx
  float v9; // xmm2_4
  int v10; // ecx
  float *v11; // eax
  unsigned int v12; // edi
  float v13; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ebx
  float v15; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v16; // ebx
  float v17; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v18; // ebx
  float v19; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v20; // ebx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm0_4
  int v26; // [esp+4h] [ebp-9Ch] BYREF
  char name[128]; // [esp+10h] [ebp-90h] BYREF
  int c; // [esp+90h] [ebp-10h]
  int wide; // [esp+94h] [ebp-Ch] BYREF
  float *pFractions; // [esp+98h] [ebp-8h]
  float flTotalSize; // [esp+9Ch] [ebp-4h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig);
  c = this->m_Splitters.m_Size;
  v3 = c;
  v4 = alloca(4 * c);
  v5 = 0;
  pFractions = (float *)&v26;
  flTotalSize = 0.0;
  if ( c > 0 )
  {
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v5);
      Float = KeyValues::GetFloat(this: userConfig, keyName: name, defaultValue: flTotalSize + 5.0);
      pFractions[v5++] = Float;
      flTotalSize = Float;
    }
    while ( v5 < v3 );
    if ( flTotalSize != 0.0 )
    {
      vgui::Panel::GetSize(this, &wide, tall: (int *)&userConfig);
      v7 = userConfig;
      if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
        v7 = (KeyValues *)wide;
      v8 = 0;
      userConfig = v7;
      if ( v3 >= 4 )
      {
        v9 = (float)(int)v7;
        v10 = 0;
        v11 = pFractions + 2;
        v12 = ((unsigned int)(v3 - 4) >> 2) + 1;
        v13 = 1.0 / flTotalSize;
        v8 = 4 * v12;
        do
        {
          m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
          v15 = v13 * *(v11 - 2);
          *(v11 - 2) = v15;
          m_pMemory[v10].m_flPos = v15 * v9;
          v16 = this->m_Splitters.m_Memory.m_pMemory;
          v17 = *(v11 - 1) * v13;
          *(v11 - 1) = v17;
          v16[v10 + 1].m_flPos = v17 * v9;
          v18 = this->m_Splitters.m_Memory.m_pMemory;
          v19 = *v11 * v13;
          *v11 = v19;
          v18[v10 + 2].m_flPos = v19 * v9;
          v20 = this->m_Splitters.m_Memory.m_pMemory;
          v21 = v11[1] * v13;
          v11[1] = v21;
          v20[v10 + 3].m_flPos = v21 * v9;
          v11 += 4;
          v10 += 4;
          --v12;
        }
        while ( v12 != 0 );
        v7 = userConfig;
        v3 = c;
      }
      if ( v8 < v3 )
      {
        v22 = (float)(int)v7;
        v23 = 1.0 / flTotalSize;
        v24 = v8;
        do
        {
          v25 = pFractions[v8] * v23;
          pFractions[v8] = v25;
          this->m_Splitters.m_Memory.m_pMemory[v24].m_flPos = v22 * v25;
          ++v8;
          ++v24;
        }
        while ( v8 < v3 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4890
// Name: public: virtual void vgui::Splitter::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // esi
  int v4; // edi
  char name[128]; // [esp+10h] [ebp-84h] BYREF
  int c; // [esp+90h] [ebp-4h]

  vgui::EditablePanel::GetUserConfigSettings(this, userConfig);
  v3 = 0;
  c = this->m_Splitters.m_Size;
  if ( c > 0 )
  {
    v4 = 0;
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v3);
      KeyValues::SetFloat(this: userConfig, keyName: name, value: this->m_Splitters.m_Memory.m_pMemory[v4].m_flPos);
      ++v3;
      ++v4;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4910
// Name: public: virtual void vgui::Splitter::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::PerformLayout(vgui::Splitter *this)
{
  vgui::Splitter *v1; // esi
  int m_Size; // edi
  int v3; // ecx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  vgui::Panel *m_pPanel; // ebx
  vgui::Panel *m_pHandle; // esi
  int v7; // edi
  bool v8; // zf
  int v9; // [esp+8h] [ebp-18h]
  int h; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  vgui::Splitter *v12; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  int nLastPos; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v12 = this;
  vgui::EditablePanel::PerformLayout(this);
  m_Size = v1->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    vgui::Panel::GetSize(this: v1, wide: &w, tall: &h);
    v3 = 0;
    nLastPos = 0;
    if ( m_Size > 0 )
    {
      v13 = 0;
      v9 = m_Size;
      while ( 1 )
      {
        m_pMemory = v1->m_Splitters.m_Memory.m_pMemory;
        m_pPanel = m_pMemory[v13 / 0x14].m_pPanel;
        m_pHandle = m_pMemory[v13 / 0x14].m_pHandle;
        v7 = (int)(float)(m_pMemory[v13 / 0x14].m_flPos + 0.5);
        if ( v12->m_Mode != SPLITTER_MODE_HORIZONTAL )
        {
          vgui::Panel::SetPos(this: m_pPanel, x: v3, y: 0);
          vgui::Panel::SetSize(this: m_pPanel, wide: v7 - nLastPos, tall: h);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: v7, y: 0);
            vgui::Panel::SetSize(this: m_pHandle, wide: 4, tall: h);
          }
        }
        else
        {
          vgui::Panel::SetPos(this: m_pPanel, x: 0, y: v3);
          vgui::Panel::SetSize(this: m_pPanel, wide: w, tall: v7 - nLastPos);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: 0, y: v7);
            vgui::Panel::SetSize(this: m_pHandle, wide: w, tall: 4);
          }
        }
        v13 += 20;
        v8 = v9-- == 1;
        nLastPos = v7 + 4;
        if ( v8 )
          break;
        v1 = v12;
        v3 = nLastPos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4A20
// Name: public: virtual void vgui::SplitterHandle::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnCursorMoved(vgui::SplitterHandle *this, int x, int y)
{
  vgui::Splitter *v4; // edi
  int v5; // eax

  if ( this->m_bDragging )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    v4 = (vgui::Splitter *)this->GetParent(this);
    vgui::Panel::ScreenToLocal(this: v4, &x, &y);
    v5 = y;
    if ( this->m_nMode != SPLITTER_MODE_HORIZONTAL )
      v5 = x;
    vgui::Splitter::SetSplitterPosition(this: v4, nIndex: this->m_nIndex, nPos: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4A90
// Name: public: virtual void vgui::SplitterHandle::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseDoublePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::Splitter *v2; // eax

  v2 = (vgui::Splitter *)this->GetParent(this);
  vgui::Splitter::EvenlyRespaceSplitters(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102E4AB0
// Name: public: virtual void vgui::Splitter::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplySettings(vgui::Splitter *this, KeyValues *inResourceData)
{
  vgui::Panel *v2; // ebx
  int v3; // esi
  int Int; // eax
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int *p_m_Size; // eax
  int j; // edi
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  int *p_m_nLockedSize; // eax
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int m_flPos; // ecx
  int v20; // eax
  int v21; // edx
  char *v22; // edx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  vgui::Splitter *v26; // edi
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  char pBuffer[512]; // [esp+8h] [ebp-228h] BYREF
  int v31; // [esp+208h] [ebp-28h]
  int nSplitterCount; // [esp+20Ch] [ebp-24h]
  int wide; // [esp+210h] [ebp-20h] BYREF
  int v34; // [esp+214h] [ebp-1Ch]
  int tall; // [esp+218h] [ebp-18h] BYREF
  int v36; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v38; // [esp+224h] [ebp-Ch]
  vgui::Splitter *v39; // [esp+228h] [ebp-8h]
  int k; // [esp+22Ch] [ebp-4h]

  v2 = this;
  v39 = this;
  vgui::EditablePanel::ApplySettings(this, inResourceData);
  v3 = 0;
  nSplitterCount = v2[1].m_infoFont - 1;
  i = 0;
  if ( nSplitterCount > 0 )
  {
    v36 = 0;
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 512, pFormat: "splitter%d", v3);
      Int = KeyValues::GetInt(this: inResourceData, keyName: pBuffer, defaultValue: -1);
      if ( Int >= 0 )
      {
        v5 = Int;
        vgui::Panel::GetSize(this: v2, &wide, &tall);
        v6 = tall;
        if ( v2[1]._vpanel != 0 )
          v6 = wide;
        if ( v6 != 0 && i >= 0 )
        {
          v7 = (int *)((char *)&v2[1].m_pTooltips->m_Text.m_Size + v36);
          while ( *((_BYTE *)v7 - 4) != 0 )
          {
            v5 -= *v7;
            v7 -= 5;
            if ( --v3 < 0 )
              goto LABEL_56;
          }
          v38 = v5;
          if ( v3 >= 0 )
          {
            v8 = 0;
            k = 0;
            if ( v3 > 0 )
            {
              p_m_Size = &v2[1].m_pTooltips->m_Text.m_Size;
              for ( j = v3; j != 0; --j )
              {
                if ( *((_BYTE *)p_m_Size - 4) != 0 )
                  v8 += *p_m_Size;
                else
                  v8 += 4;
                p_m_Size += 5;
              }
              k = v8;
            }
            v11 = v2[1].m_infoFont - 1;
            v12 = v3 + 1;
            v13 = v6 - 4;
            v31 = v11;
            v34 = v3 + 1;
            if ( v3 + 1 < v11 )
            {
              p_m_nLockedSize = &v39->m_Splitters.m_Memory.m_pMemory[v12].m_nLockedSize;
              v15 = v11 - v12;
              do
              {
                if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
                  v13 -= *p_m_nLockedSize;
                else
                  v13 -= 4;
                p_m_nLockedSize += 5;
                --v15;
              }
              while ( v15 != 0 );
              v8 = k;
            }
            v16 = v38;
            if ( v38 >= v8 )
            {
              if ( v38 > v13 )
                v16 = v13;
            }
            else
            {
              v16 = v8;
            }
            v17 = v3;
            v18 = v3 - 1;
            m_flPos = v16;
            v39->m_Splitters.m_Memory.m_pMemory[v17].m_flPos = (float)v16;
            v38 = v16;
            v20 = v16;
            if ( v18 >= 0 )
            {
              v21 = 20 * v18;
              for ( k = 20 * v18; ; v21 = k )
              {
                v22 = (char *)v39->m_Splitters.m_Memory.m_pMemory + v21;
                if ( v22[32] != 0 )
                {
                  v20 -= *((_DWORD *)v22 + 9);
                  v23 = v20;
                }
                else
                {
                  v23 = -2147483647;
                  v20 = v16 - 4;
                }
                v24 = (int)(float)(*((float *)v22 + 2) + 0.5);
                if ( v20 < v24 || v23 > v24 )
                  *((float *)v22 + 2) = (float)v20;
                else
                  v20 = (int)*((float *)v22 + 2);
                k -= 20;
                if ( --v18 < 0 )
                  break;
              }
              v11 = v31;
              m_flPos = v38;
            }
            if ( v34 >= v11 )
            {
              v26 = v39;
            }
            else
            {
              v25 = v34;
              k = v11 - v34;
              do
              {
                v26 = v39;
                v27 = &v39->m_Splitters.m_Memory.m_pMemory[v25];
                if ( v27->m_bLocked )
                {
                  v28 = m_flPos + v27->m_nLockedSize;
                  m_flPos = v28;
                }
                else
                {
                  m_flPos += 4;
                  v28 = 0x7FFFFFFF;
                }
                v29 = (int)(float)(v27->m_flPos + 0.5);
                if ( m_flPos > v29 || v28 < v29 )
                  v27->m_flPos = (float)m_flPos;
                else
                  m_flPos = (int)v27->m_flPos;
                ++v25;
                --k;
              }
              while ( k != 0 );
            }
            v26->InvalidateLayout(this: v26, a2: false, a3: false);
            v2 = v39;
          }
        }
      }
LABEL_56:
      v36 += 20;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < nSplitterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4D30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Splitter::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Splitter::GetMessageMap(vgui::Splitter *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Splitter::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetMessageMap'::`2'::s_pMap;
  `vgui::Splitter::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Splitter");
  `vgui::Splitter::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E4D60
// Name: public: virtual struct PanelAnimationMap __near * vgui::Splitter::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Splitter::GetAnimMap(vgui::Splitter *this)
{
  return FindOrAddPanelAnimationMap(className: "Splitter");
}

//------------------------------------------------------------------------------
// Address: 0x102E4D70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Splitter::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Splitter::GetKBMap(vgui::Splitter *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Splitter::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetKBMap'::`2'::s_pMap;
  `vgui::Splitter::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
  `vgui::Splitter::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E4DE0
// Name: private: void vgui::Splitter::RecreateSplitters(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RecreateSplitters(vgui::Splitter *this, int nCount)
{
  int m_Size; // eax
  int v3; // edi
  int i; // esi
  vgui::SplitterChildPanel *m_pPanel; // eax
  vgui::SplitterHandle *m_pHandle; // eax
  int v7; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Splitters; // esi
  int v9; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v12; // ecx
  int v13; // eax
  vgui::SplitterChildPanel *v14; // eax
  vgui::SplitterChildPanel *v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ebx
  vgui::SplitterHandle *v19; // eax
  vgui::SplitterHandle *v20; // eax
  char pBuffer[512]; // [esp+Ch] [ebp-204h] BYREF
  vgui::Panel *parent; // [esp+20Ch] [ebp-4h]

  m_Size = this->m_Splitters.m_Size;
  parent = this;
  if ( m_Size > 0 )
  {
    v3 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      m_pPanel = this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel;
      if ( m_pPanel != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterChildPanel *, int))m_pPanel->dtr_Panel)(
          a1: this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel,
          a2: 1);
        this = (vgui::Splitter *)parent;
      }
      m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v3].m_pHandle;
      if ( m_pHandle != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterHandle *, int))m_pHandle->dtr_Panel)(a1: m_pHandle, a2: 1);
        this = (vgui::Splitter *)parent;
      }
      ++v3;
    }
  }
  v7 = nCount;
  p_m_Splitters = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Splitters;
  v9 = 0;
  this->m_Splitters.m_Size = 0;
  if ( nCount + 1 > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 512, pFormat: "child%d", v9);
      m_pMemory = (int)p_m_Splitters[1].m_pMemory;
      m_nAllocationCount = p_m_Splitters->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: p_m_Splitters, num: m_pMemory - m_nAllocationCount + 1);
      ++p_m_Splitters[1].m_pMemory;
      v12 = p_m_Splitters->m_pMemory;
      v13 = (int)p_m_Splitters[1].m_pMemory - m_pMemory - 1;
      p_m_Splitters[1].m_nAllocationCount = (int)p_m_Splitters->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 20 * v13);
      v14 = (vgui::SplitterChildPanel *)MemAlloc_Alloc(nSize: 0x180u);
      if ( v14 != nullptr )
        v15 = vgui::SplitterChildPanel::SplitterChildPanel(this: v14, parent, panelName: pBuffer);
      else
        v15 = nullptr;
      v16 = m_pMemory;
      *(_DWORD *)&p_m_Splitters->m_pMemory[v16].m_Title.m_Id = v15;
      LOBYTE(p_m_Splitters->m_pMemory[v16].m_Right) = 0;
      ++v9;
      p_m_Splitters->m_pMemory[v16].m_ciFlags = 0;
    }
    while ( v9 < nCount + 1 );
    v7 = nCount;
  }
  v17 = 0;
  if ( v7 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = (vgui::SplitterHandle *)MemAlloc_Alloc(nSize: 0x15Cu);
      if ( v19 != nullptr )
        v20 = vgui::SplitterHandle::SplitterHandle(
                this: v19,
                (vgui::Splitter *)parent,
                name: "SplitterHandle",
                mode: (vgui::SplitterMode_t)parent[1]._vpanel,
                nIndex: v17);
      else
        v20 = nullptr;
      p_m_Splitters->m_pMemory[v18].m_Width = (int)v20;
      v20->MoveToFront(this: v20);
      ++v17;
      ++v18;
    }
    while ( v17 < nCount );
    v7 = nCount;
  }
  p_m_Splitters->m_pMemory[v7].m_Width = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E4F90
// Name: public: vgui::Splitter::Splitter(class vgui::Panel __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Splitter *__thiscall vgui::Splitter::Splitter(
        vgui::Splitter *this,
        vgui::Panel *parent,
        const char *name,
        vgui::SplitterMode_t mode,
        int nCount)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (vgui::Splitter_vtbl *)&vgui::Splitter::`vftable';
  if ( `vgui::Splitter::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "Splitter");
    v6->pfnClassName = vgui::Splitter::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "Splitter");
    v7->pfnClassName = vgui::Splitter::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
    v8->pfnClassName = vgui::Splitter::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  this->m_Splitters.m_Memory.m_pMemory = nullptr;
  this->m_Splitters.m_Memory.m_nAllocationCount = 0;
  this->m_Splitters.m_Memory.m_nGrowSize = 0;
  this->m_Splitters.m_Size = 0;
  this->m_Splitters.m_pElements = nullptr;
  this->m_Mode = mode;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Splitter::RecreateSplitters(this, nCount);
  vgui::Splitter::EvenlyRespaceSplitters(this);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10318360
// Name: public: static char const __near * vgui::Splitter::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Splitter::GetPanelClassName()
{
  return "Splitter";
}

//------------------------------------------------------------------------------
// Address: 0x10318370
// Name: public: static char const __near * vgui::SplitterHandle::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterHandle::GetPanelClassName()
{
  return "SplitterHandle";
}

//------------------------------------------------------------------------------
// Address: 0x10318380
// Name: public: virtual void vgui::SplitterHandle::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::ApplySchemeSettings(vgui::SplitterHandle *this, vgui::IScheme *pScheme)
{
  vgui::SplitterHandle_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color c; // [esp+Ch] [ebp-4h] BYREF

  this->GetBgColor(this, result: &c);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x103183E0
// Name: public: virtual void vgui::SplitterHandle::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMousePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  if ( !this->m_bDragging )
  {
    v3 = g_pVGuiInput;
    v4 = g_pVGuiInput->__vftable;
    v5 = this->GetVPanel(this);
    v4->SetMouseCapture(this: v3, a2: v5);
    this->m_bDragging = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318420
// Name: public: virtual void vgui::SplitterHandle::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseReleased(vgui::SplitterHandle *this, ButtonCode_t code)
{
  if ( this->m_bDragging )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_bDragging = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318450
// Name: public: static char const __near * vgui::SplitterChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterChildPanel::GetPanelClassName()
{
  return "SplitterChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10318460
// Name: public: virtual void vgui::Splitter::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetSettings(vgui::Splitter *this, KeyValues *outResourceData)
{
  vgui::Panel::GetSettings(this, outResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10318470
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterHandle::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterHandle::GetMessageMap(vgui::SplitterHandle *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103184A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterHandle::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterHandle::GetAnimMap(vgui::SplitterHandle *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterHandle");
}

//------------------------------------------------------------------------------
// Address: 0x103184B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterHandle::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterHandle::GetKBMap(vgui::SplitterHandle *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103184E0
// Name: public: vgui::SplitterHandle::SplitterHandle(class vgui::Splitter __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterHandle *__thiscall vgui::SplitterHandle::SplitterHandle(
        vgui::SplitterHandle *this,
        vgui::Splitter *parent,
        const char *name,
        vgui::SplitterMode_t mode,
        int nIndex)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::SplitterMode_t v9; // edi
  int v10; // eax
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::SplitterHandle_vtbl *)&vgui::SplitterHandle::`vftable';
  if ( `vgui::SplitterHandle::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
    v6->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "SplitterHandle");
    v7->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
    v8->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::GetSize(this: parent, wide: (int *)&name, tall: &h);
  v9 = mode;
  if ( mode != SPLITTER_MODE_HORIZONTAL )
  {
    vgui::Panel::SetSize(this, wide: 4, tall: h);
    vgui::Panel::SetCursor(this, cursor: 0xAu);
  }
  else
  {
    vgui::Panel::SetSize(this, wide: (int)name, tall: 4);
    vgui::Panel::SetCursor(this, cursor: 0xBu);
  }
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  v10 = nIndex;
  this->m_nMode = v9;
  this->m_nIndex = v10;
  this->m_bDragging = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10318650
// Name: public: vgui::SplitterChildPanel::SplitterChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterChildPanel *__thiscall vgui::SplitterChildPanel::SplitterChildPanel(
        vgui::SplitterChildPanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::SplitterChildPanel_vtbl *)&vgui::SplitterChildPanel::`vftable';
  if ( `vgui::SplitterChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
    v4->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
    v5->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
    v6->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10318760
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterChildPanel::GetMessageMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10318790
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterChildPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterChildPanel::GetAnimMap(vgui::SplitterChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x103187A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterChildPanel::GetKBMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103187D0
// Name: public: void vgui::Splitter::SetSplitterColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterColor(vgui::Splitter *this, Color c)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  vgui::SplitterHandle *m_pHandle; // ecx
  vgui::SplitterHandle *v7; // ecx
  int v8; // esi
  int v9; // ebx
  vgui::SplitterHandle *v10; // ecx

  v3 = this->m_Splitters.m_Size - 1;
  if ( c._color[3] != 0 )
  {
    if ( v3 > 0 )
    {
      v4 = 0;
      v5 = this->m_Splitters.m_Size - 1;
      do
      {
        m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v4].m_pHandle;
        m_pHandle->SetBgColor(this: m_pHandle, a2: c);
        v7 = this->m_Splitters.m_Memory.m_pMemory[v4].m_pHandle;
        v7->SetPaintBackgroundEnabled(this: v7, a2: true);
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( v3 > 0 )
  {
    v8 = 0;
    v9 = this->m_Splitters.m_Size - 1;
    do
    {
      v10 = this->m_Splitters.m_Memory.m_pMemory[v8].m_pHandle;
      v10->SetPaintBackgroundEnabled(this: v10, a2: false);
      ++v8;
      --v9;
    }
    while ( v9 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318860
// Name: public: virtual void vgui::Splitter::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::OnSizeChanged(vgui::Splitter *this, int newWide, int newTall)
{
  vgui::Splitter *v3; // ebx
  int m_Size; // ecx
  float v5; // xmm2_4
  int v6; // eax
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // eax
  float *p_m_flPos; // edx
  char *v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  int v19; // edi
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm3_4
  int v23; // ecx
  unsigned int v24; // esi
  vgui::Splitter::SplitterInfo_t *v25; // eax
  float m_flPos; // xmm4_4
  vgui::Splitter::SplitterInfo_t *v27; // eax
  float m_nLockedSize; // xmm0_4
  float v29; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v30; // eax
  bool v31; // zf
  int v32; // eax
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v37; // eax
  int v38; // edx
  int v39; // eax
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v44; // eax
  int *v45; // eax
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // ecx
  int v50; // edx
  vgui::Splitter::SplitterInfo_t *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  int nCount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int newWidea; // [esp+20h] [ebp+8h]

  v3 = this;
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  if ( newTall > 0 && newWide > 0 )
  {
    m_Size = v3->m_Splitters.m_Size;
    v5 = 0.0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0.0;
    nCount = m_Size;
    v10 = 0.0;
    i = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v3->m_Splitters.m_Memory.m_pMemory;
      p_m_flPos = &m_pMemory->m_flPos;
      v13 = (char *)&m_pMemory[1].m_flPos;
      v14 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * v14;
      do
      {
        if ( *((_BYTE *)p_m_flPos + 4) != 0 )
        {
          v7 += *((_DWORD *)p_m_flPos + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*p_m_flPos - v10) + v9;
        }
        if ( v13[4] != 0 )
        {
          v7 += *((_DWORD *)v13 + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v13 - *p_m_flPos) + v9;
        }
        if ( v13[24] != 0 )
        {
          v7 += *((_DWORD *)v13 + 7);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 5) - *(float *)v13) + v9;
        }
        if ( v13[44] != 0 )
        {
          v7 += *((_DWORD *)v13 + 12);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 10) - *((float *)v13 + 5)) + v9;
        }
        v10 = *((float *)v13 + 10);
        p_m_flPos += 20;
        v13 += 80;
        --v14;
      }
      while ( v14 != 0 );
      v3 = this;
      m_Size = nCount;
      v6 = i;
    }
    if ( v6 < m_Size )
    {
      v15 = m_Size - i;
      v16 = (int)&v3->m_Splitters.m_Memory.m_pMemory[v6].m_flPos;
      do
      {
        if ( *(_BYTE *)(v16 + 4) != 0 )
        {
          v7 += *(_DWORD *)(v16 + 8);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v16 - v10) + v9;
        }
        v10 = *(float *)v16;
        v16 += 20;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( v3->m_Mode != SPLITTER_MODE_HORIZONTAL )
      newTall = newWide;
    v17 = newTall - v7;
    if ( newTall - v7 < 4 * v8 )
      v17 = 4 * v8;
    v18 = (float)v17;
    v19 = nCount - 1;
    v20 = 0;
    v21 = v18 / v9;
    v22 = 0.0;
    if ( nCount - 1 >= 4 )
    {
      v23 = 0;
      v24 = ((unsigned int)(nCount - 5) >> 2) + 1;
      newWidea = 4 * v24;
      do
      {
        v25 = v3->m_Splitters.m_Memory.m_pMemory;
        m_flPos = v25[v23].m_flPos;
        v27 = &v25[v23];
        if ( v27->m_bLocked )
          m_nLockedSize = (float)v27->m_nLockedSize;
        else
          m_nLockedSize = (float)(m_flPos - v5) * v21;
        v29 = m_nLockedSize + v22;
        v27->m_flPos = v29;
        v30 = v3->m_Splitters.m_Memory.m_pMemory;
        v31 = !v30[v23 + 1].m_bLocked;
        v32 = (int)&v30[v23 + 1];
        v33 = v29;
        if ( v31 )
        {
          v35 = (float)(*(float *)(v32 + 8) - m_flPos) * v21;
          v34 = *(float *)(v32 + 8);
        }
        else
        {
          v34 = *(float *)(v32 + 8);
          v35 = (float)*(int *)(v32 + 16);
        }
        v36 = v35 + v33;
        *(float *)(v32 + 8) = v36;
        v37 = v3->m_Splitters.m_Memory.m_pMemory;
        v38 = v23 * 20 + 60;
        v31 = !v37[v23 + 2].m_bLocked;
        v39 = (int)&v37[v23 + 2];
        v40 = v36;
        if ( v31 )
        {
          v42 = (float)(*(float *)(v39 + 8) - v34) * v21;
          v41 = *(float *)(v39 + 8);
        }
        else
        {
          v41 = *(float *)(v39 + 8);
          v42 = (float)*(int *)(v39 + 16);
        }
        v43 = v42 + v40;
        *(float *)(v39 + 8) = v43;
        v44 = v3->m_Splitters.m_Memory.m_pMemory;
        v5 = *(float *)((char *)&v44->m_flPos + v38);
        v45 = (int *)((char *)v44 + v38);
        v46 = v43;
        if ( *((_BYTE *)v45 + 12) != 0 )
          v47 = (float)v45[4];
        else
          v47 = (float)(v5 - v41) * v21;
        v48 = v47 + v46;
        v23 += 4;
        --v24;
        *((float *)v45 + 2) = v48;
        v22 = v48;
      }
      while ( v24 != 0 );
      v20 = newWidea;
    }
    if ( v20 < v19 )
    {
      v49 = v20;
      v50 = v19 - v20;
      do
      {
        v51 = &v3->m_Splitters.m_Memory.m_pMemory[v49];
        if ( v51->m_bLocked )
          v52 = (float)v51->m_nLockedSize;
        else
          v52 = (float)(v51->m_flPos - v5) * v21;
        v5 = v51->m_flPos;
        v53 = v52 + v22;
        ++v49;
        --v50;
        v51->m_flPos = v53;
        v22 = v53;
      }
      while ( v50 != 0 );
    }
    v3->m_Splitters.m_Memory.m_pMemory[nCount - 1].m_flPos = (float)newTall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318B70
// Name: private: void vgui::Splitter::SetSplitterPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterPosition(vgui::Splitter *this, int nIndex, int nPos)
{
  int v4; // esi
  int v5; // eax
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  int *i; // ecx
  int v8; // edi
  int *p_m_nLockedSize; // ecx
  int j; // edx
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int m_flPos; // ecx
  int v19; // esi
  int v20; // edx
  char *v21; // edx
  int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  vgui::Splitter *v26; // ebx
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  int c; // [esp+8h] [ebp-10h]
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::Splitter *v33; // [esp+14h] [ebp-4h]
  int nMinPos; // [esp+20h] [ebp+8h]
  int nMinPosa; // [esp+20h] [ebp+8h]
  int nPosa; // [esp+24h] [ebp+Ch]

  v33 = this;
  vgui::Panel::GetSize(this, &wide, &tall);
  v4 = tall;
  if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
    v4 = wide;
  if ( v4 != 0 )
  {
    v5 = nIndex;
    if ( nIndex >= 0 )
    {
      m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
      tall = (int)m_pMemory;
      for ( i = &m_pMemory[nIndex].m_nLockedSize; *((_BYTE *)i - 4) != 0; i -= 5 )
      {
        nPos -= *i;
        if ( --v5 < 0 )
          return;
      }
      if ( v5 >= 0 )
      {
        v8 = 0;
        nMinPos = 0;
        if ( v5 > 0 )
        {
          p_m_nLockedSize = &m_pMemory->m_nLockedSize;
          for ( j = v5; j != 0; --j )
          {
            if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
              v8 += *p_m_nLockedSize;
            else
              v8 += 4;
            p_m_nLockedSize += 5;
          }
          nMinPos = v8;
        }
        v11 = this->m_Splitters.m_Size - 1;
        v12 = v5 + 1;
        v13 = v4 - 4;
        c = v11;
        wide = v5 + 1;
        if ( v5 + 1 < v11 )
        {
          v14 = (_DWORD *)(tall + 20 * v12 + 16);
          v15 = v11 - v12;
          do
          {
            if ( *((_BYTE *)v14 - 4) != 0 )
              v13 -= *v14;
            else
              v13 -= 4;
            v14 += 5;
            --v15;
          }
          while ( v15 != 0 );
          v8 = nMinPos;
        }
        v16 = nPos;
        if ( nPos >= v8 )
        {
          if ( nPos > v13 )
            v16 = v13;
        }
        else
        {
          v16 = v8;
        }
        v17 = v5 - 1;
        m_flPos = v16;
        *(float *)(tall + 20 * v5 + 8) = (float)v16;
        v19 = v16;
        if ( v5 - 1 >= 0 )
        {
          v20 = 20 * v17;
          for ( nMinPosa = 20 * v17; ; v20 = nMinPosa )
          {
            v21 = (char *)v33->m_Splitters.m_Memory.m_pMemory + v20;
            if ( v21[32] != 0 )
            {
              v22 = v19 - *((_DWORD *)v21 + 9);
              v23 = v22;
            }
            else
            {
              v22 = -2147483647;
              v23 = v16 - 4;
            }
            v24 = (int)(float)(*((float *)v21 + 2) + 0.5);
            if ( v23 < v24 || v22 > v24 )
            {
              *((float *)v21 + 2) = (float)v23;
              v19 = v23;
            }
            else
            {
              v19 = (int)*((float *)v21 + 2);
            }
            nMinPosa -= 20;
            if ( --v17 < 0 )
              break;
          }
          m_flPos = v16;
        }
        if ( wide >= c )
        {
          v26 = v33;
        }
        else
        {
          v25 = wide;
          nPosa = c - wide;
          do
          {
            v26 = v33;
            v27 = &v33->m_Splitters.m_Memory.m_pMemory[v25];
            if ( v27->m_bLocked )
            {
              v28 = m_flPos + v27->m_nLockedSize;
              m_flPos = v28;
            }
            else
            {
              m_flPos += 4;
              v28 = 0x7FFFFFFF;
            }
            v29 = (int)(float)(v27->m_flPos + 0.5);
            if ( m_flPos > v29 || v28 < v29 )
              v27->m_flPos = (float)m_flPos;
            else
              m_flPos = (int)v27->m_flPos;
            ++v25;
            --nPosa;
          }
          while ( nPosa != 0 );
        }
        v26->InvalidateLayout(this: v26, a2: false, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318D80
// Name: public: void vgui::Splitter::EvenlyRespaceSplitters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::EvenlyRespaceSplitters(vgui::Splitter *this)
{
  int m_Size; // ebx
  int v3; // edi
  int *p_m_nLockedSize; // eax
  int v5; // ecx
  int v6; // eax
  float v7; // xmm2_4
  __int128 v8; // xmm0
  int v9; // edi
  int v10; // eax
  unsigned int v11; // edx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ecx
  __int128 v13; // xmm1
  vgui::Splitter::SplitterInfo_t *v14; // ecx
  __int128 v15; // xmm0
  vgui::Splitter::SplitterInfo_t *v16; // ecx
  __int128 v17; // xmm1
  vgui::Splitter::SplitterInfo_t *v18; // ecx
  int v19; // eax
  int v20; // edx
  vgui::Splitter::SplitterInfo_t *v21; // ecx
  int wide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    v3 = 0;
    if ( m_Size > 0 )
    {
      p_m_nLockedSize = &this->m_Splitters.m_Memory.m_pMemory->m_nLockedSize;
      v5 = this->m_Splitters.m_Size;
      do
      {
        if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
          v3 += *p_m_nLockedSize;
        p_m_nLockedSize += 5;
        --v5;
      }
      while ( v5 != 0 );
    }
    vgui::Panel::GetSize(this, &wide, &tall);
    v6 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v6 = wide;
    v7 = (float)(v6 - v3) / (float)m_Size;
    if ( v7 < 4.0 )
      v7 = 4.0;
    v8 = 0;
    v9 = 0;
    if ( m_Size >= 4 )
    {
      v10 = 0;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v9 = 4 * v11;
      do
      {
        m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
        if ( m_pMemory[v10].m_bLocked )
        {
          v13 = COERCE_UNSIGNED_INT((float)m_pMemory[v10].m_nLockedSize);
          *(float *)&v13 = *(float *)&v13 + *(float *)&v8;
        }
        else
        {
          *(float *)&v8 = *(float *)&v8 + v7;
          v13 = v8;
        }
        LODWORD(m_pMemory[v10].m_flPos) = v13;
        v14 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v14[v10 + 1].m_bLocked )
        {
          v15 = COERCE_UNSIGNED_INT((float)v14[v10 + 1].m_nLockedSize);
          *(float *)&v15 = *(float *)&v15 + *(float *)&v13;
        }
        else
        {
          *(float *)&v13 = *(float *)&v13 + v7;
          v15 = v13;
        }
        LODWORD(v14[v10 + 1].m_flPos) = v15;
        v16 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v16[v10 + 2].m_bLocked )
        {
          v17 = COERCE_UNSIGNED_INT((float)v16[v10 + 2].m_nLockedSize);
          *(float *)&v17 = *(float *)&v17 + *(float *)&v15;
        }
        else
        {
          *(float *)&v15 = *(float *)&v15 + v7;
          v17 = v15;
        }
        LODWORD(v16[v10 + 2].m_flPos) = v17;
        v18 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v18[v10 + 3].m_bLocked )
        {
          v8 = COERCE_UNSIGNED_INT((float)v18[v10 + 3].m_nLockedSize);
          *(float *)&v8 = *(float *)&v8 + *(float *)&v17;
        }
        else
        {
          *(float *)&v17 = *(float *)&v17 + v7;
          v8 = v17;
        }
        LODWORD(v18[v10 + 3].m_flPos) = v8;
        v10 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    if ( v9 < m_Size )
    {
      v19 = v9;
      v20 = m_Size - v9;
      do
      {
        v21 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v21[v19].m_bLocked )
          *(float *)&v8 = *(float *)&v8 + (float)v21[v19].m_nLockedSize;
        else
          *(float *)&v8 = *(float *)&v8 + v7;
        LODWORD(v21[v19++].m_flPos) = v8;
        --v20;
      }
      while ( v20 != 0 );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318F30
// Name: public: void vgui::Splitter::RespaceSplitters(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RespaceSplitters(vgui::Splitter *this, float *flFractions)
{
  int m_Size; // ebx
  int v4; // ecx
  float *v5; // eax
  float v6; // xmm0_4
  int v7; // edi
  float v8; // xmm2_4
  int v9; // ecx
  float *v10; // eax
  unsigned int v11; // edx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // ecx
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  float flPos; // [esp+10h] [ebp-8h]
  int tall; // [esp+14h] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    flPos = 0.0;
    vgui::Panel::GetSize(this, &wide, &tall);
    v4 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v4 = wide;
    v5 = flFractions;
    v6 = flPos;
    v7 = 0;
    tall = v4;
    if ( m_Size >= 4 )
    {
      v8 = (float)v4;
      v9 = 0;
      v10 = flFractions + 2;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v7 = 4 * v11;
      do
      {
        v12 = *(v10 - 2) + v6;
        this->m_Splitters.m_Memory.m_pMemory[v9].m_flPos = v8 * v12;
        v13 = *(v10 - 1) + v12;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 1].m_flPos = v8 * v13;
        v14 = v13 + *v10;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 2].m_flPos = v8 * v14;
        v6 = v14 + v10[1];
        this->m_Splitters.m_Memory.m_pMemory[v9 + 3].m_flPos = v8 * v6;
        v10 += 4;
        v9 += 4;
        --v11;
      }
      while ( v11 != 0 );
      v5 = flFractions;
      v4 = tall;
    }
    if ( v7 < m_Size )
    {
      v15 = (float)v4;
      v16 = v7;
      do
      {
        v6 = v6 + v5[v7];
        this->m_Splitters.m_Memory.m_pMemory[v16].m_flPos = v15 * v6;
        ++v7;
        ++v16;
      }
      while ( v7 < m_Size );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319080
// Name: public: virtual void vgui::Splitter::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplyUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // ebx
  void *v4; // esp
  int v5; // edi
  double Float; // st7
  KeyValues *v7; // eax
  int v8; // edx
  float v9; // xmm2_4
  int v10; // ecx
  float *v11; // eax
  unsigned int v12; // edi
  float v13; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ebx
  float v15; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v16; // ebx
  float v17; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v18; // ebx
  float v19; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v20; // ebx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm0_4
  float defaultValue; // [esp+0h] [ebp-9Ch] BYREF
  char string[4]; // [esp+Ch] [ebp-90h] BYREF
  char name[128]; // [esp+10h] [ebp-8Ch]
  int c; // [esp+90h] [ebp-Ch] BYREF
  int wide; // [esp+94h] [ebp-8h]
  float *pFractions; // [esp+98h] [ebp-4h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig);
  *(_DWORD *)&name[124] = this->m_Splitters.m_Size;
  v3 = *(_DWORD *)&name[124];
  v4 = alloca(4 * *(_DWORD *)&name[124]);
  v5 = 0;
  wide = (int)&defaultValue;
  *(float *)&pFractions = 0.0;
  if ( *(int *)&name[124] > 0 )
  {
    do
    {
      _snprintf(string, count: 0x80u, format: "%d_splitter_pos", v5);
      Float = KeyValues::GetFloat(this: userConfig, keyName: string, defaultValue: *(float *)&pFractions + 5.0);
      *(float *)(wide + 4 * v5++) = Float;
      *(float *)&pFractions = Float;
    }
    while ( v5 < v3 );
    if ( *(float *)&pFractions != 0.0 )
    {
      vgui::Panel::GetSize(this, wide: &c, tall: (int *)&userConfig);
      v7 = userConfig;
      if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
        v7 = (KeyValues *)c;
      v8 = 0;
      userConfig = v7;
      if ( v3 >= 4 )
      {
        v9 = (float)(int)v7;
        v10 = 0;
        v11 = (float *)(wide + 8);
        v12 = ((unsigned int)(v3 - 4) >> 2) + 1;
        v13 = 1.0 / *(float *)&pFractions;
        v8 = 4 * v12;
        do
        {
          m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
          v15 = v13 * *(v11 - 2);
          *(v11 - 2) = v15;
          m_pMemory[v10].m_flPos = v15 * v9;
          v16 = this->m_Splitters.m_Memory.m_pMemory;
          v17 = *(v11 - 1) * v13;
          *(v11 - 1) = v17;
          v16[v10 + 1].m_flPos = v17 * v9;
          v18 = this->m_Splitters.m_Memory.m_pMemory;
          v19 = *v11 * v13;
          *v11 = v19;
          v18[v10 + 2].m_flPos = v19 * v9;
          v20 = this->m_Splitters.m_Memory.m_pMemory;
          v21 = v11[1] * v13;
          v11[1] = v21;
          v20[v10 + 3].m_flPos = v21 * v9;
          v11 += 4;
          v10 += 4;
          --v12;
        }
        while ( v12 != 0 );
        v7 = userConfig;
        v3 = *(_DWORD *)&name[124];
      }
      if ( v8 < v3 )
      {
        v22 = (float)(int)v7;
        v23 = 1.0 / *(float *)&pFractions;
        v24 = v8;
        do
        {
          v25 = *(float *)(wide + 4 * v8) * v23;
          *(float *)(wide + 4 * v8) = v25;
          this->m_Splitters.m_Memory.m_pMemory[v24].m_flPos = v22 * v25;
          ++v8;
          ++v24;
        }
        while ( v8 < v3 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319260
// Name: public: virtual void vgui::Splitter::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // esi
  int v4; // edi
  char string[8]; // [esp+8h] [ebp-84h] BYREF
  char name[128]; // [esp+10h] [ebp-7Ch]

  vgui::EditablePanel::GetUserConfigSettings(this, userConfig);
  v3 = 0;
  *(_DWORD *)&name[120] = this->m_Splitters.m_Size;
  if ( *(int *)&name[120] > 0 )
  {
    v4 = 0;
    do
    {
      _snprintf(string, count: 0x80u, format: "%d_splitter_pos", v3);
      KeyValues::SetFloat(this: userConfig, keyName: string, value: this->m_Splitters.m_Memory.m_pMemory[v4].m_flPos);
      ++v3;
      ++v4;
    }
    while ( v3 < *(int *)&name[120] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103192E0
// Name: public: virtual void vgui::Splitter::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::PerformLayout(vgui::Splitter *this)
{
  vgui::Splitter *v1; // esi
  int m_Size; // edi
  int v3; // ecx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  vgui::Panel *m_pPanel; // ebx
  vgui::Panel *m_pHandle; // esi
  int v7; // edi
  bool v8; // zf
  int v9; // [esp+8h] [ebp-18h]
  int h; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  vgui::Splitter *v12; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  int nLastPos; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v12 = this;
  vgui::EditablePanel::PerformLayout(this);
  m_Size = v1->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    vgui::Panel::GetSize(this: v1, wide: &w, tall: &h);
    v3 = 0;
    nLastPos = 0;
    if ( m_Size > 0 )
    {
      v13 = 0;
      v9 = m_Size;
      while ( 1 )
      {
        m_pMemory = v1->m_Splitters.m_Memory.m_pMemory;
        m_pPanel = m_pMemory[v13 / 0x14].m_pPanel;
        m_pHandle = m_pMemory[v13 / 0x14].m_pHandle;
        v7 = (int)(float)(m_pMemory[v13 / 0x14].m_flPos + 0.5);
        if ( v12->m_Mode != SPLITTER_MODE_HORIZONTAL )
        {
          vgui::Panel::SetPos(this: m_pPanel, x: v3, y: 0);
          vgui::Panel::SetSize(this: m_pPanel, wide: v7 - nLastPos, tall: h);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: v7, y: 0);
            vgui::Panel::SetSize(this: m_pHandle, wide: 4, tall: h);
          }
        }
        else
        {
          vgui::Panel::SetPos(this: m_pPanel, x: 0, y: v3);
          vgui::Panel::SetSize(this: m_pPanel, wide: w, tall: v7 - nLastPos);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: 0, y: v7);
            vgui::Panel::SetSize(this: m_pHandle, wide: w, tall: 4);
          }
        }
        v13 += 20;
        v8 = v9-- == 1;
        nLastPos = v7 + 4;
        if ( v8 )
          break;
        v1 = v12;
        v3 = nLastPos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103193F0
// Name: public: virtual void vgui::SplitterHandle::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnCursorMoved(vgui::SplitterHandle *this, int x, int y)
{
  vgui::Splitter *v4; // edi
  int v5; // eax

  if ( this->m_bDragging )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    v4 = (vgui::Splitter *)this->GetParent(this);
    vgui::Panel::ScreenToLocal(this: v4, &x, &y);
    v5 = y;
    if ( this->m_nMode != SPLITTER_MODE_HORIZONTAL )
      v5 = x;
    vgui::Splitter::SetSplitterPosition(this: v4, nIndex: this->m_nIndex, nPos: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319460
// Name: public: virtual void vgui::SplitterHandle::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseDoublePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::Splitter *v2; // eax

  v2 = (vgui::Splitter *)this->GetParent(this);
  vgui::Splitter::EvenlyRespaceSplitters(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10319480
// Name: public: virtual void vgui::Splitter::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplySettings(vgui::Splitter *this, KeyValues *inResourceData)
{
  vgui::Panel *v2; // ebx
  int v3; // esi
  int Int; // eax
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int *p_m_Size; // eax
  int j; // edi
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  int *p_m_nLockedSize; // eax
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int m_flPos; // ecx
  int v20; // eax
  int v21; // edx
  char *v22; // edx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  vgui::Splitter *v26; // edi
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  char pBuffer[512]; // [esp+8h] [ebp-228h] BYREF
  int v31; // [esp+208h] [ebp-28h]
  int nSplitterCount; // [esp+20Ch] [ebp-24h]
  int wide; // [esp+210h] [ebp-20h] BYREF
  int v34; // [esp+214h] [ebp-1Ch]
  int tall; // [esp+218h] [ebp-18h] BYREF
  int v36; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v38; // [esp+224h] [ebp-Ch]
  vgui::Splitter *v39; // [esp+228h] [ebp-8h]
  int k; // [esp+22Ch] [ebp-4h]

  v2 = this;
  v39 = this;
  vgui::EditablePanel::ApplySettings(this, a2: (int)this, inResourceData);
  v3 = 0;
  nSplitterCount = v2[1].m_infoFont - 1;
  i = 0;
  if ( nSplitterCount > 0 )
  {
    v36 = 0;
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "splitter%d", v3);
      Int = KeyValues::GetInt(this: inResourceData, keyName: pBuffer, defaultValue: -1);
      if ( Int >= 0 )
      {
        v5 = Int;
        vgui::Panel::GetSize(this: v2, &wide, &tall);
        v6 = tall;
        if ( v2[1]._vpanel != 0 )
          v6 = wide;
        if ( v6 != 0 && i >= 0 )
        {
          v7 = (int *)((char *)&v2[1].m_pTooltips->m_Text.m_Size + v36);
          while ( *((_BYTE *)v7 - 4) != 0 )
          {
            v5 -= *v7;
            v7 -= 5;
            if ( --v3 < 0 )
              goto LABEL_56;
          }
          v38 = v5;
          if ( v3 >= 0 )
          {
            v8 = 0;
            k = 0;
            if ( v3 > 0 )
            {
              p_m_Size = &v2[1].m_pTooltips->m_Text.m_Size;
              for ( j = v3; j != 0; --j )
              {
                if ( *((_BYTE *)p_m_Size - 4) != 0 )
                  v8 += *p_m_Size;
                else
                  v8 += 4;
                p_m_Size += 5;
              }
              k = v8;
            }
            v11 = v2[1].m_infoFont - 1;
            v12 = v3 + 1;
            v13 = v6 - 4;
            v31 = v11;
            v34 = v3 + 1;
            if ( v3 + 1 < v11 )
            {
              p_m_nLockedSize = &v39->m_Splitters.m_Memory.m_pMemory[v12].m_nLockedSize;
              v15 = v11 - v12;
              do
              {
                if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
                  v13 -= *p_m_nLockedSize;
                else
                  v13 -= 4;
                p_m_nLockedSize += 5;
                --v15;
              }
              while ( v15 != 0 );
              v8 = k;
            }
            v16 = v38;
            if ( v38 >= v8 )
            {
              if ( v38 > v13 )
                v16 = v13;
            }
            else
            {
              v16 = v8;
            }
            v17 = v3;
            v18 = v3 - 1;
            m_flPos = v16;
            v39->m_Splitters.m_Memory.m_pMemory[v17].m_flPos = (float)v16;
            v38 = v16;
            v20 = v16;
            if ( v18 >= 0 )
            {
              v21 = 20 * v18;
              for ( k = 20 * v18; ; v21 = k )
              {
                v22 = (char *)v39->m_Splitters.m_Memory.m_pMemory + v21;
                if ( v22[32] != 0 )
                {
                  v20 -= *((_DWORD *)v22 + 9);
                  v23 = v20;
                }
                else
                {
                  v23 = -2147483647;
                  v20 = v16 - 4;
                }
                v24 = (int)(float)(*((float *)v22 + 2) + 0.5);
                if ( v20 < v24 || v23 > v24 )
                  *((float *)v22 + 2) = (float)v20;
                else
                  v20 = (int)*((float *)v22 + 2);
                k -= 20;
                if ( --v18 < 0 )
                  break;
              }
              v11 = v31;
              m_flPos = v38;
            }
            if ( v34 >= v11 )
            {
              v26 = v39;
            }
            else
            {
              v25 = v34;
              k = v11 - v34;
              do
              {
                v26 = v39;
                v27 = &v39->m_Splitters.m_Memory.m_pMemory[v25];
                if ( v27->m_bLocked )
                {
                  v28 = m_flPos + v27->m_nLockedSize;
                  m_flPos = v28;
                }
                else
                {
                  m_flPos += 4;
                  v28 = 0x7FFFFFFF;
                }
                v29 = (int)(float)(v27->m_flPos + 0.5);
                if ( m_flPos > v29 || v28 < v29 )
                  v27->m_flPos = (float)m_flPos;
                else
                  m_flPos = (int)v27->m_flPos;
                ++v25;
                --k;
              }
              while ( k != 0 );
            }
            v26->InvalidateLayout(this: v26, a2: false, a3: false);
            v2 = v39;
          }
        }
      }
LABEL_56:
      v36 += 20;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < nSplitterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319700
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Splitter::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Splitter::GetMessageMap(vgui::Splitter *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Splitter::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetMessageMap'::`2'::s_pMap;
  `vgui::Splitter::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Splitter");
  `vgui::Splitter::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10319730
// Name: public: virtual struct PanelAnimationMap __near * vgui::Splitter::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Splitter::GetAnimMap(vgui::Splitter *this)
{
  return FindOrAddPanelAnimationMap(className: "Splitter");
}

//------------------------------------------------------------------------------
// Address: 0x10319740
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Splitter::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Splitter::GetKBMap(vgui::Splitter *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Splitter::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetKBMap'::`2'::s_pMap;
  `vgui::Splitter::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
  `vgui::Splitter::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103197B0
// Name: private: void vgui::Splitter::RecreateSplitters(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RecreateSplitters(vgui::Splitter *this, int nCount)
{
  int m_Size; // eax
  int v3; // edi
  int i; // esi
  vgui::SplitterChildPanel *m_pPanel; // eax
  vgui::SplitterHandle *m_pHandle; // eax
  int v7; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Splitters; // esi
  int v9; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v12; // ecx
  int v13; // eax
  vgui::SplitterChildPanel *v14; // eax
  vgui::SplitterChildPanel *v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ebx
  vgui::SplitterHandle *v19; // eax
  vgui::SplitterHandle *v20; // eax
  char pBuffer[512]; // [esp+Ch] [ebp-204h] BYREF
  vgui::Panel *parent; // [esp+20Ch] [ebp-4h]

  m_Size = this->m_Splitters.m_Size;
  parent = this;
  if ( m_Size > 0 )
  {
    v3 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      m_pPanel = this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel;
      if ( m_pPanel != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterChildPanel *, int))m_pPanel->dtr_Panel)(
          a1: this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel,
          a2: 1);
        this = (vgui::Splitter *)parent;
      }
      m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v3].m_pHandle;
      if ( m_pHandle != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterHandle *, int))m_pHandle->dtr_Panel)(a1: m_pHandle, a2: 1);
        this = (vgui::Splitter *)parent;
      }
      ++v3;
    }
  }
  v7 = nCount;
  p_m_Splitters = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Splitters;
  v9 = 0;
  this->m_Splitters.m_Size = 0;
  if ( nCount + 1 > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "child%d", v9);
      m_pMemory = (int)p_m_Splitters[1].m_pMemory;
      m_nAllocationCount = p_m_Splitters->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: p_m_Splitters,
          num: m_pMemory - m_nAllocationCount + 1);
      ++p_m_Splitters[1].m_pMemory;
      v12 = p_m_Splitters->m_pMemory;
      v13 = (int)p_m_Splitters[1].m_pMemory - m_pMemory - 1;
      p_m_Splitters[1].m_nAllocationCount = (int)p_m_Splitters->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v12[m_pMemory + 1],
          src: (unsigned __int8 *)&v12[m_pMemory],
          count: 20 * v13);
      v14 = (vgui::SplitterChildPanel *)operator new(nSize: 0x180u);
      if ( v14 != nullptr )
        v15 = vgui::SplitterChildPanel::SplitterChildPanel(this: v14, parent, panelName: pBuffer);
      else
        v15 = nullptr;
      v16 = m_pMemory;
      *(_DWORD *)&p_m_Splitters->m_pMemory[v16].m_Title.m_Id = v15;
      LOBYTE(p_m_Splitters->m_pMemory[v16].m_Right) = 0;
      ++v9;
      p_m_Splitters->m_pMemory[v16].m_ciFlags = 0;
    }
    while ( v9 < nCount + 1 );
    v7 = nCount;
  }
  v17 = 0;
  if ( v7 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = (vgui::SplitterHandle *)operator new(nSize: 0x15Cu);
      if ( v19 != nullptr )
        v20 = vgui::SplitterHandle::SplitterHandle(
                this: v19,
                (vgui::Splitter *)parent,
                name: "SplitterHandle",
                mode: (vgui::SplitterMode_t)parent[1]._vpanel,
                nIndex: v17);
      else
        v20 = nullptr;
      p_m_Splitters->m_pMemory[v18].m_Width = (int)v20;
      v20->MoveToFront(this: v20);
      ++v17;
      ++v18;
    }
    while ( v17 < nCount );
    v7 = nCount;
  }
  p_m_Splitters->m_pMemory[v7].m_Width = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10319960
// Name: public: vgui::Splitter::Splitter(class vgui::Panel __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Splitter *__thiscall vgui::Splitter::Splitter(
        vgui::Splitter *this,
        vgui::Panel *parent,
        const char *name,
        vgui::SplitterMode_t mode,
        int nCount)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (vgui::Splitter_vtbl *)&vgui::Splitter::`vftable';
  if ( `vgui::Splitter::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "Splitter");
    v6->pfnClassName = vgui::Splitter::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "Splitter");
    v7->pfnClassName = vgui::Splitter::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
    v8->pfnClassName = vgui::Splitter::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  this->m_Splitters.m_Memory.m_pMemory = nullptr;
  this->m_Splitters.m_Memory.m_nAllocationCount = 0;
  this->m_Splitters.m_Memory.m_nGrowSize = 0;
  this->m_Splitters.m_Size = 0;
  this->m_Splitters.m_pElements = nullptr;
  this->m_Mode = mode;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Splitter::RecreateSplitters(this, nCount);
  vgui::Splitter::EvenlyRespaceSplitters(this);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00474560
// Name: public: static char const __near * vgui::Splitter::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Splitter::GetPanelClassName()
{
  return "Splitter";
}

//------------------------------------------------------------------------------
// Address: 0x00474570
// Name: public: static char const __near * vgui::SplitterHandle::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterHandle::GetPanelClassName()
{
  return "SplitterHandle";
}

//------------------------------------------------------------------------------
// Address: 0x00474580
// Name: public: virtual void vgui::SplitterHandle::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::ApplySchemeSettings(vgui::SplitterHandle *this, vgui::IScheme *pScheme)
{
  vgui::SplitterHandle_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color c; // [esp+Ch] [ebp-4h] BYREF

  this->GetBgColor(this, result: &c);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x004745E0
// Name: public: virtual void vgui::SplitterHandle::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMousePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  if ( !this->m_bDragging )
  {
    v3 = g_pVGuiInput;
    v4 = g_pVGuiInput->__vftable;
    v5 = this->GetVPanel(this);
    v4->SetMouseCapture(this: v3, a2: v5);
    this->m_bDragging = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474620
// Name: public: virtual void vgui::SplitterHandle::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseReleased(vgui::SplitterHandle *this, ButtonCode_t code)
{
  if ( this->m_bDragging )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_bDragging = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474650
// Name: public: static char const __near * vgui::SplitterChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterChildPanel::GetPanelClassName()
{
  return "SplitterChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00474660
// Name: public: virtual void vgui::Splitter::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetSettings(vgui::Splitter *this, KeyValues *outResourceData)
{
  vgui::Panel::GetSettings(this, outResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00474670
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterHandle::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterHandle::GetMessageMap(vgui::SplitterHandle *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004746A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterHandle::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterHandle::GetAnimMap(vgui::SplitterHandle *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterHandle");
}

//------------------------------------------------------------------------------
// Address: 0x004746B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterHandle::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterHandle::GetKBMap(vgui::SplitterHandle *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004746E0
// Name: public: vgui::SplitterHandle::SplitterHandle(class vgui::Splitter __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterHandle *__thiscall vgui::SplitterHandle::SplitterHandle(
        vgui::SplitterHandle *this,
        vgui::Splitter *parent,
        char *name,
        vgui::SplitterMode_t mode,
        int nIndex)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::SplitterMode_t v9; // edi
  int v10; // eax
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::SplitterHandle_vtbl *)&vgui::SplitterHandle::`vftable';
  if ( `vgui::SplitterHandle::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
    v6->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "SplitterHandle");
    v7->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
    v8->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::GetSize(this: parent, wide: (int *)&name, tall: &h);
  v9 = mode;
  if ( mode != SPLITTER_MODE_HORIZONTAL )
  {
    vgui::Panel::SetSize(this, wide: 4, tall: h);
    vgui::Panel::SetCursor(this, cursor: 0xAu);
  }
  else
  {
    vgui::Panel::SetSize(this, wide: (int)name, tall: 4);
    vgui::Panel::SetCursor(this, cursor: 0xBu);
  }
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  v10 = nIndex;
  this->m_nMode = v9;
  this->m_nIndex = v10;
  this->m_bDragging = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00474850
// Name: public: vgui::SplitterChildPanel::SplitterChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterChildPanel *__thiscall vgui::SplitterChildPanel::SplitterChildPanel(
        vgui::SplitterChildPanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::SplitterChildPanel_vtbl *)&vgui::SplitterChildPanel::`vftable';
  if ( `vgui::SplitterChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
    v4->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
    v5->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
    v6->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00474960
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterChildPanel::GetMessageMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474990
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterChildPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterChildPanel::GetAnimMap(vgui::SplitterChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004749A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterChildPanel::GetKBMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004749D0
// Name: public: virtual void vgui::Splitter::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::OnSizeChanged(vgui::Splitter *this, int newWide, int newTall)
{
  vgui::Splitter *v3; // ebx
  int m_Size; // ecx
  float v5; // xmm2_4
  int v6; // eax
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // eax
  float *p_m_flPos; // edx
  char *v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  int v19; // edi
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm3_4
  int v23; // ecx
  unsigned int v24; // esi
  vgui::Splitter::SplitterInfo_t *v25; // eax
  float m_flPos; // xmm4_4
  vgui::Splitter::SplitterInfo_t *v27; // eax
  float m_nLockedSize; // xmm0_4
  float v29; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v30; // eax
  bool v31; // zf
  int v32; // eax
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v37; // eax
  int v38; // edx
  int v39; // eax
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v44; // eax
  int *v45; // eax
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // ecx
  int v50; // edx
  vgui::Splitter::SplitterInfo_t *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  int nCount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int newWidea; // [esp+20h] [ebp+8h]

  v3 = this;
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  if ( newTall > 0 && newWide > 0 )
  {
    m_Size = v3->m_Splitters.m_Size;
    v5 = 0.0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0.0;
    nCount = m_Size;
    v10 = 0.0;
    i = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v3->m_Splitters.m_Memory.m_pMemory;
      p_m_flPos = &m_pMemory->m_flPos;
      v13 = (char *)&m_pMemory[1].m_flPos;
      v14 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * v14;
      do
      {
        if ( *((_BYTE *)p_m_flPos + 4) != 0 )
        {
          v7 += *((_DWORD *)p_m_flPos + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*p_m_flPos - v10) + v9;
        }
        if ( v13[4] != 0 )
        {
          v7 += *((_DWORD *)v13 + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v13 - *p_m_flPos) + v9;
        }
        if ( v13[24] != 0 )
        {
          v7 += *((_DWORD *)v13 + 7);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 5) - *(float *)v13) + v9;
        }
        if ( v13[44] != 0 )
        {
          v7 += *((_DWORD *)v13 + 12);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 10) - *((float *)v13 + 5)) + v9;
        }
        v10 = *((float *)v13 + 10);
        p_m_flPos += 20;
        v13 += 80;
        --v14;
      }
      while ( v14 != 0 );
      v3 = this;
      m_Size = nCount;
      v6 = i;
    }
    if ( v6 < m_Size )
    {
      v15 = m_Size - i;
      v16 = (int)&v3->m_Splitters.m_Memory.m_pMemory[v6].m_flPos;
      do
      {
        if ( *(_BYTE *)(v16 + 4) != 0 )
        {
          v7 += *(_DWORD *)(v16 + 8);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v16 - v10) + v9;
        }
        v10 = *(float *)v16;
        v16 += 20;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( v3->m_Mode != SPLITTER_MODE_HORIZONTAL )
      newTall = newWide;
    v17 = newTall - v7;
    if ( newTall - v7 < 4 * v8 )
      v17 = 4 * v8;
    v18 = (float)v17;
    v19 = nCount - 1;
    v20 = 0;
    v21 = v18 / v9;
    v22 = 0.0;
    if ( nCount - 1 >= 4 )
    {
      v23 = 0;
      v24 = ((unsigned int)(nCount - 5) >> 2) + 1;
      newWidea = 4 * v24;
      do
      {
        v25 = v3->m_Splitters.m_Memory.m_pMemory;
        m_flPos = v25[v23].m_flPos;
        v27 = &v25[v23];
        if ( v27->m_bLocked )
          m_nLockedSize = (float)v27->m_nLockedSize;
        else
          m_nLockedSize = (float)(m_flPos - v5) * v21;
        v29 = m_nLockedSize + v22;
        v27->m_flPos = v29;
        v30 = v3->m_Splitters.m_Memory.m_pMemory;
        v31 = !v30[v23 + 1].m_bLocked;
        v32 = (int)&v30[v23 + 1];
        v33 = v29;
        if ( v31 )
        {
          v35 = (float)(*(float *)(v32 + 8) - m_flPos) * v21;
          v34 = *(float *)(v32 + 8);
        }
        else
        {
          v34 = *(float *)(v32 + 8);
          v35 = (float)*(int *)(v32 + 16);
        }
        v36 = v35 + v33;
        *(float *)(v32 + 8) = v36;
        v37 = v3->m_Splitters.m_Memory.m_pMemory;
        v38 = v23 * 20 + 60;
        v31 = !v37[v23 + 2].m_bLocked;
        v39 = (int)&v37[v23 + 2];
        v40 = v36;
        if ( v31 )
        {
          v42 = (float)(*(float *)(v39 + 8) - v34) * v21;
          v41 = *(float *)(v39 + 8);
        }
        else
        {
          v41 = *(float *)(v39 + 8);
          v42 = (float)*(int *)(v39 + 16);
        }
        v43 = v42 + v40;
        *(float *)(v39 + 8) = v43;
        v44 = v3->m_Splitters.m_Memory.m_pMemory;
        v5 = *(float *)((char *)&v44->m_flPos + v38);
        v45 = (int *)((char *)v44 + v38);
        v46 = v43;
        if ( *((_BYTE *)v45 + 12) != 0 )
          v47 = (float)v45[4];
        else
          v47 = (float)(v5 - v41) * v21;
        v48 = v47 + v46;
        v23 += 4;
        --v24;
        *((float *)v45 + 2) = v48;
        v22 = v48;
      }
      while ( v24 != 0 );
      v20 = newWidea;
    }
    if ( v20 < v19 )
    {
      v49 = v20;
      v50 = v19 - v20;
      do
      {
        v51 = &v3->m_Splitters.m_Memory.m_pMemory[v49];
        if ( v51->m_bLocked )
          v52 = (float)v51->m_nLockedSize;
        else
          v52 = (float)(v51->m_flPos - v5) * v21;
        v5 = v51->m_flPos;
        v53 = v52 + v22;
        ++v49;
        --v50;
        v51->m_flPos = v53;
        v22 = v53;
      }
      while ( v50 != 0 );
    }
    v3->m_Splitters.m_Memory.m_pMemory[nCount - 1].m_flPos = (float)newTall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474CE0
// Name: private: void vgui::Splitter::SetSplitterPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterPosition(vgui::Splitter *this, int nIndex, int nPos)
{
  int v4; // esi
  int v5; // eax
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  int *i; // ecx
  int v8; // edi
  int *p_m_nLockedSize; // ecx
  int j; // edx
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int m_flPos; // ecx
  int v19; // esi
  int v20; // edx
  char *v21; // edx
  int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  vgui::Splitter *v26; // ebx
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  int c; // [esp+8h] [ebp-10h]
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::Splitter *v33; // [esp+14h] [ebp-4h]
  int nMinPos; // [esp+20h] [ebp+8h]
  int nMinPosa; // [esp+20h] [ebp+8h]
  int nPosa; // [esp+24h] [ebp+Ch]

  v33 = this;
  vgui::Panel::GetSize(this, &wide, &tall);
  v4 = tall;
  if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
    v4 = wide;
  if ( v4 != 0 )
  {
    v5 = nIndex;
    if ( nIndex >= 0 )
    {
      m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
      tall = (int)m_pMemory;
      for ( i = &m_pMemory[nIndex].m_nLockedSize; *((_BYTE *)i - 4) != 0; i -= 5 )
      {
        nPos -= *i;
        if ( --v5 < 0 )
          return;
      }
      if ( v5 >= 0 )
      {
        v8 = 0;
        nMinPos = 0;
        if ( v5 > 0 )
        {
          p_m_nLockedSize = &m_pMemory->m_nLockedSize;
          for ( j = v5; j != 0; --j )
          {
            if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
              v8 += *p_m_nLockedSize;
            else
              v8 += 4;
            p_m_nLockedSize += 5;
          }
          nMinPos = v8;
        }
        v11 = this->m_Splitters.m_Size - 1;
        v12 = v5 + 1;
        v13 = v4 - 4;
        c = v11;
        wide = v5 + 1;
        if ( v5 + 1 < v11 )
        {
          v14 = (_DWORD *)(tall + 20 * v12 + 16);
          v15 = v11 - v12;
          do
          {
            if ( *((_BYTE *)v14 - 4) != 0 )
              v13 -= *v14;
            else
              v13 -= 4;
            v14 += 5;
            --v15;
          }
          while ( v15 != 0 );
          v8 = nMinPos;
        }
        v16 = nPos;
        if ( nPos >= v8 )
        {
          if ( nPos > v13 )
            v16 = v13;
        }
        else
        {
          v16 = v8;
        }
        v17 = v5 - 1;
        m_flPos = v16;
        *(float *)(tall + 20 * v5 + 8) = (float)v16;
        v19 = v16;
        if ( v5 - 1 >= 0 )
        {
          v20 = 20 * v17;
          for ( nMinPosa = 20 * v17; ; v20 = nMinPosa )
          {
            v21 = (char *)v33->m_Splitters.m_Memory.m_pMemory + v20;
            if ( v21[32] != 0 )
            {
              v22 = v19 - *((_DWORD *)v21 + 9);
              v23 = v22;
            }
            else
            {
              v22 = -2147483647;
              v23 = v16 - 4;
            }
            v24 = (int)(float)(*((float *)v21 + 2) + 0.5);
            if ( v23 < v24 || v22 > v24 )
            {
              *((float *)v21 + 2) = (float)v23;
              v19 = v23;
            }
            else
            {
              v19 = (int)*((float *)v21 + 2);
            }
            nMinPosa -= 20;
            if ( --v17 < 0 )
              break;
          }
          m_flPos = v16;
        }
        if ( wide >= c )
        {
          v26 = v33;
        }
        else
        {
          v25 = wide;
          nPosa = c - wide;
          do
          {
            v26 = v33;
            v27 = &v33->m_Splitters.m_Memory.m_pMemory[v25];
            if ( v27->m_bLocked )
            {
              v28 = m_flPos + v27->m_nLockedSize;
              m_flPos = v28;
            }
            else
            {
              m_flPos += 4;
              v28 = 0x7FFFFFFF;
            }
            v29 = (int)(float)(v27->m_flPos + 0.5);
            if ( m_flPos > v29 || v28 < v29 )
              v27->m_flPos = (float)m_flPos;
            else
              m_flPos = (int)v27->m_flPos;
            ++v25;
            --nPosa;
          }
          while ( nPosa != 0 );
        }
        v26->InvalidateLayout(this: v26, a2: false, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474EF0
// Name: public: void vgui::Splitter::EvenlyRespaceSplitters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::EvenlyRespaceSplitters(vgui::Splitter *this)
{
  int m_Size; // ebx
  int v3; // edi
  int *p_m_nLockedSize; // eax
  int v5; // ecx
  int v6; // eax
  float v7; // xmm2_4
  __int128 v8; // xmm0
  int v9; // edi
  int v10; // eax
  unsigned int v11; // edx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ecx
  __int128 v13; // xmm1
  vgui::Splitter::SplitterInfo_t *v14; // ecx
  __int128 v15; // xmm0
  vgui::Splitter::SplitterInfo_t *v16; // ecx
  __int128 v17; // xmm1
  vgui::Splitter::SplitterInfo_t *v18; // ecx
  int v19; // eax
  int v20; // edx
  vgui::Splitter::SplitterInfo_t *v21; // ecx
  int wide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    v3 = 0;
    if ( m_Size > 0 )
    {
      p_m_nLockedSize = &this->m_Splitters.m_Memory.m_pMemory->m_nLockedSize;
      v5 = this->m_Splitters.m_Size;
      do
      {
        if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
          v3 += *p_m_nLockedSize;
        p_m_nLockedSize += 5;
        --v5;
      }
      while ( v5 != 0 );
    }
    vgui::Panel::GetSize(this, &wide, &tall);
    v6 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v6 = wide;
    v7 = (float)(v6 - v3) / (float)m_Size;
    if ( v7 < 4.0 )
      v7 = 4.0;
    v8 = 0;
    v9 = 0;
    if ( m_Size >= 4 )
    {
      v10 = 0;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v9 = 4 * v11;
      do
      {
        m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
        if ( m_pMemory[v10].m_bLocked )
        {
          v13 = COERCE_UNSIGNED_INT((float)m_pMemory[v10].m_nLockedSize);
          *(float *)&v13 = *(float *)&v13 + *(float *)&v8;
        }
        else
        {
          *(float *)&v8 = *(float *)&v8 + v7;
          v13 = v8;
        }
        LODWORD(m_pMemory[v10].m_flPos) = v13;
        v14 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v14[v10 + 1].m_bLocked )
        {
          v15 = COERCE_UNSIGNED_INT((float)v14[v10 + 1].m_nLockedSize);
          *(float *)&v15 = *(float *)&v15 + *(float *)&v13;
        }
        else
        {
          *(float *)&v13 = *(float *)&v13 + v7;
          v15 = v13;
        }
        LODWORD(v14[v10 + 1].m_flPos) = v15;
        v16 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v16[v10 + 2].m_bLocked )
        {
          v17 = COERCE_UNSIGNED_INT((float)v16[v10 + 2].m_nLockedSize);
          *(float *)&v17 = *(float *)&v17 + *(float *)&v15;
        }
        else
        {
          *(float *)&v15 = *(float *)&v15 + v7;
          v17 = v15;
        }
        LODWORD(v16[v10 + 2].m_flPos) = v17;
        v18 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v18[v10 + 3].m_bLocked )
        {
          v8 = COERCE_UNSIGNED_INT((float)v18[v10 + 3].m_nLockedSize);
          *(float *)&v8 = *(float *)&v8 + *(float *)&v17;
        }
        else
        {
          *(float *)&v17 = *(float *)&v17 + v7;
          v8 = v17;
        }
        LODWORD(v18[v10 + 3].m_flPos) = v8;
        v10 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    if ( v9 < m_Size )
    {
      v19 = v9;
      v20 = m_Size - v9;
      do
      {
        v21 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v21[v19].m_bLocked )
          *(float *)&v8 = *(float *)&v8 + (float)v21[v19].m_nLockedSize;
        else
          *(float *)&v8 = *(float *)&v8 + v7;
        LODWORD(v21[v19++].m_flPos) = v8;
        --v20;
      }
      while ( v20 != 0 );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004750A0
// Name: public: void vgui::Splitter::RespaceSplitters(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RespaceSplitters(vgui::Splitter *this, float *flFractions)
{
  int m_Size; // ebx
  int v4; // ecx
  float *v5; // eax
  float v6; // xmm0_4
  int v7; // edi
  float v8; // xmm2_4
  int v9; // ecx
  float *v10; // eax
  unsigned int v11; // edx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // ecx
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  float flPos; // [esp+10h] [ebp-8h]
  int tall; // [esp+14h] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    flPos = 0.0;
    vgui::Panel::GetSize(this, &wide, &tall);
    v4 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v4 = wide;
    v5 = flFractions;
    v6 = flPos;
    v7 = 0;
    tall = v4;
    if ( m_Size >= 4 )
    {
      v8 = (float)v4;
      v9 = 0;
      v10 = flFractions + 2;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v7 = 4 * v11;
      do
      {
        v12 = *(v10 - 2) + v6;
        this->m_Splitters.m_Memory.m_pMemory[v9].m_flPos = v8 * v12;
        v13 = *(v10 - 1) + v12;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 1].m_flPos = v8 * v13;
        v14 = v13 + *v10;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 2].m_flPos = v8 * v14;
        v6 = v14 + v10[1];
        this->m_Splitters.m_Memory.m_pMemory[v9 + 3].m_flPos = v8 * v6;
        v10 += 4;
        v9 += 4;
        --v11;
      }
      while ( v11 != 0 );
      v5 = flFractions;
      v4 = tall;
    }
    if ( v7 < m_Size )
    {
      v15 = (float)v4;
      v16 = v7;
      do
      {
        v6 = v6 + v5[v7];
        this->m_Splitters.m_Memory.m_pMemory[v16].m_flPos = v15 * v6;
        ++v7;
        ++v16;
      }
      while ( v7 < m_Size );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004751F0
// Name: public: virtual void vgui::Splitter::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplyUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // ebx
  void *v4; // esp
  int v5; // edi
  double Float; // st7
  KeyValues *v7; // eax
  int v8; // edx
  float v9; // xmm2_4
  int v10; // ecx
  float *v11; // eax
  unsigned int v12; // edi
  float v13; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ebx
  float v15; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v16; // ebx
  float v17; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v18; // ebx
  float v19; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v20; // ebx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm0_4
  int v26; // [esp+4h] [ebp-9Ch] BYREF
  char name[128]; // [esp+10h] [ebp-90h] BYREF
  int c; // [esp+90h] [ebp-10h]
  int wide; // [esp+94h] [ebp-Ch] BYREF
  float *pFractions; // [esp+98h] [ebp-8h]
  float flTotalSize; // [esp+9Ch] [ebp-4h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig);
  c = this->m_Splitters.m_Size;
  v3 = c;
  v4 = alloca(4 * c);
  v5 = 0;
  pFractions = (float *)&v26;
  flTotalSize = 0.0;
  if ( c > 0 )
  {
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v5);
      Float = KeyValues::GetFloat(this: userConfig, keyName: name, defaultValue: flTotalSize + 5.0);
      pFractions[v5++] = Float;
      flTotalSize = Float;
    }
    while ( v5 < v3 );
    if ( flTotalSize != 0.0 )
    {
      vgui::Panel::GetSize(this, &wide, tall: (int *)&userConfig);
      v7 = userConfig;
      if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
        v7 = (KeyValues *)wide;
      v8 = 0;
      userConfig = v7;
      if ( v3 >= 4 )
      {
        v9 = (float)(int)v7;
        v10 = 0;
        v11 = pFractions + 2;
        v12 = ((unsigned int)(v3 - 4) >> 2) + 1;
        v13 = 1.0 / flTotalSize;
        v8 = 4 * v12;
        do
        {
          m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
          v15 = v13 * *(v11 - 2);
          *(v11 - 2) = v15;
          m_pMemory[v10].m_flPos = v15 * v9;
          v16 = this->m_Splitters.m_Memory.m_pMemory;
          v17 = *(v11 - 1) * v13;
          *(v11 - 1) = v17;
          v16[v10 + 1].m_flPos = v17 * v9;
          v18 = this->m_Splitters.m_Memory.m_pMemory;
          v19 = *v11 * v13;
          *v11 = v19;
          v18[v10 + 2].m_flPos = v19 * v9;
          v20 = this->m_Splitters.m_Memory.m_pMemory;
          v21 = v11[1] * v13;
          v11[1] = v21;
          v20[v10 + 3].m_flPos = v21 * v9;
          v11 += 4;
          v10 += 4;
          --v12;
        }
        while ( v12 != 0 );
        v7 = userConfig;
        v3 = c;
      }
      if ( v8 < v3 )
      {
        v22 = (float)(int)v7;
        v23 = 1.0 / flTotalSize;
        v24 = v8;
        do
        {
          v25 = pFractions[v8] * v23;
          pFractions[v8] = v25;
          this->m_Splitters.m_Memory.m_pMemory[v24].m_flPos = v22 * v25;
          ++v8;
          ++v24;
        }
        while ( v8 < v3 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004753D0
// Name: public: virtual void vgui::Splitter::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // esi
  int v4; // edi
  char name[128]; // [esp+10h] [ebp-84h] BYREF
  int c; // [esp+90h] [ebp-4h]

  vgui::EditablePanel::GetUserConfigSettings(this, userConfig);
  v3 = 0;
  c = this->m_Splitters.m_Size;
  if ( c > 0 )
  {
    v4 = 0;
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v3);
      KeyValues::SetFloat(this: userConfig, keyName: name, value: this->m_Splitters.m_Memory.m_pMemory[v4].m_flPos);
      ++v3;
      ++v4;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475450
// Name: public: virtual void vgui::Splitter::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::PerformLayout(vgui::Splitter *this)
{
  vgui::Splitter *v1; // esi
  int m_Size; // edi
  int v3; // ecx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  vgui::Panel *m_pPanel; // ebx
  vgui::Panel *m_pHandle; // esi
  int v7; // edi
  bool v8; // zf
  int v9; // [esp+8h] [ebp-18h]
  int h; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  vgui::Splitter *v12; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  int nLastPos; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v12 = this;
  vgui::EditablePanel::PerformLayout(this);
  m_Size = v1->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    vgui::Panel::GetSize(this: v1, wide: &w, tall: &h);
    v3 = 0;
    nLastPos = 0;
    if ( m_Size > 0 )
    {
      v13 = 0;
      v9 = m_Size;
      while ( 1 )
      {
        m_pMemory = v1->m_Splitters.m_Memory.m_pMemory;
        m_pPanel = m_pMemory[v13 / 0x14].m_pPanel;
        m_pHandle = m_pMemory[v13 / 0x14].m_pHandle;
        v7 = (int)(float)(m_pMemory[v13 / 0x14].m_flPos + 0.5);
        if ( v12->m_Mode != SPLITTER_MODE_HORIZONTAL )
        {
          vgui::Panel::SetPos(this: m_pPanel, x: v3, y: 0);
          vgui::Panel::SetSize(this: m_pPanel, wide: v7 - nLastPos, tall: h);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: v7, y: 0);
            vgui::Panel::SetSize(this: m_pHandle, wide: 4, tall: h);
          }
        }
        else
        {
          vgui::Panel::SetPos(this: m_pPanel, x: 0, y: v3);
          vgui::Panel::SetSize(this: m_pPanel, wide: w, tall: v7 - nLastPos);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: 0, y: v7);
            vgui::Panel::SetSize(this: m_pHandle, wide: w, tall: 4);
          }
        }
        v13 += 20;
        v8 = v9-- == 1;
        nLastPos = v7 + 4;
        if ( v8 )
          break;
        v1 = v12;
        v3 = nLastPos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475560
// Name: public: virtual void vgui::SplitterHandle::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnCursorMoved(vgui::SplitterHandle *this, int x, int y)
{
  vgui::Splitter *v4; // edi
  int v5; // eax

  if ( this->m_bDragging )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    v4 = (vgui::Splitter *)this->GetParent(this);
    vgui::Panel::ScreenToLocal(this: v4, &x, &y);
    v5 = y;
    if ( this->m_nMode != SPLITTER_MODE_HORIZONTAL )
      v5 = x;
    vgui::Splitter::SetSplitterPosition(this: v4, nIndex: this->m_nIndex, nPos: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004755D0
// Name: public: virtual void vgui::SplitterHandle::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseDoublePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::Splitter *v2; // eax

  v2 = (vgui::Splitter *)this->GetParent(this);
  vgui::Splitter::EvenlyRespaceSplitters(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004755F0
// Name: public: virtual void vgui::Splitter::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplySettings(vgui::Splitter *this, KeyValues *inResourceData)
{
  vgui::Panel *v2; // ebx
  int v3; // esi
  int Int; // eax
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int *p_m_nGrowSize; // eax
  int j; // edi
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  int *p_m_nLockedSize; // eax
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int m_flPos; // ecx
  int v20; // eax
  int v21; // edx
  char *v22; // edx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  vgui::Splitter *v26; // edi
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  char pBuffer[512]; // [esp+8h] [ebp-228h] BYREF
  int v31; // [esp+208h] [ebp-28h]
  int nSplitterCount; // [esp+20Ch] [ebp-24h]
  int wide; // [esp+210h] [ebp-20h] BYREF
  int v34; // [esp+214h] [ebp-1Ch]
  int tall; // [esp+218h] [ebp-18h] BYREF
  int v36; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v38; // [esp+224h] [ebp-Ch]
  vgui::Splitter *v39; // [esp+228h] [ebp-8h]
  int k; // [esp+22Ch] [ebp-4h]

  v2 = this;
  v39 = this;
  vgui::EditablePanel::ApplySettings(this, a2: (int)this, inResourceData);
  v3 = 0;
  nSplitterCount = v2[1].m_infoFont - 1;
  i = 0;
  if ( nSplitterCount > 0 )
  {
    v36 = 0;
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "splitter%d", v3);
      Int = KeyValues::GetInt(this: inResourceData, keyName: pBuffer, defaultValue: -1);
      if ( Int >= 0 )
      {
        v5 = Int;
        vgui::Panel::GetSize(this: v2, &wide, &tall);
        v6 = tall;
        if ( v2[1]._vpanel != 0 )
          v6 = wide;
        if ( v6 != 0 && i >= 0 )
        {
          v7 = (int *)((char *)&v2[1].m_pTooltips->m_Text.m_Memory.m_nGrowSize + v36);
          while ( *((_BYTE *)v7 - 4) != 0 )
          {
            v5 -= *v7;
            v7 -= 5;
            if ( --v3 < 0 )
              goto LABEL_56;
          }
          v38 = v5;
          if ( v3 >= 0 )
          {
            v8 = 0;
            k = 0;
            if ( v3 > 0 )
            {
              p_m_nGrowSize = &v2[1].m_pTooltips->m_Text.m_Memory.m_nGrowSize;
              for ( j = v3; j != 0; --j )
              {
                if ( *((_BYTE *)p_m_nGrowSize - 4) != 0 )
                  v8 += *p_m_nGrowSize;
                else
                  v8 += 4;
                p_m_nGrowSize += 5;
              }
              k = v8;
            }
            v11 = v2[1].m_infoFont - 1;
            v12 = v3 + 1;
            v13 = v6 - 4;
            v31 = v11;
            v34 = v3 + 1;
            if ( v3 + 1 < v11 )
            {
              p_m_nLockedSize = &v39->m_Splitters.m_Memory.m_pMemory[v12].m_nLockedSize;
              v15 = v11 - v12;
              do
              {
                if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
                  v13 -= *p_m_nLockedSize;
                else
                  v13 -= 4;
                p_m_nLockedSize += 5;
                --v15;
              }
              while ( v15 != 0 );
              v8 = k;
            }
            v16 = v38;
            if ( v38 >= v8 )
            {
              if ( v38 > v13 )
                v16 = v13;
            }
            else
            {
              v16 = v8;
            }
            v17 = v3;
            v18 = v3 - 1;
            m_flPos = v16;
            v39->m_Splitters.m_Memory.m_pMemory[v17].m_flPos = (float)v16;
            v38 = v16;
            v20 = v16;
            if ( v18 >= 0 )
            {
              v21 = 20 * v18;
              for ( k = 20 * v18; ; v21 = k )
              {
                v22 = (char *)v39->m_Splitters.m_Memory.m_pMemory + v21;
                if ( v22[32] != 0 )
                {
                  v20 -= *((_DWORD *)v22 + 9);
                  v23 = v20;
                }
                else
                {
                  v23 = -2147483647;
                  v20 = v16 - 4;
                }
                v24 = (int)(float)(*((float *)v22 + 2) + 0.5);
                if ( v20 < v24 || v23 > v24 )
                  *((float *)v22 + 2) = (float)v20;
                else
                  v20 = (int)*((float *)v22 + 2);
                k -= 20;
                if ( --v18 < 0 )
                  break;
              }
              v11 = v31;
              m_flPos = v38;
            }
            if ( v34 >= v11 )
            {
              v26 = v39;
            }
            else
            {
              v25 = v34;
              k = v11 - v34;
              do
              {
                v26 = v39;
                v27 = &v39->m_Splitters.m_Memory.m_pMemory[v25];
                if ( v27->m_bLocked )
                {
                  v28 = m_flPos + v27->m_nLockedSize;
                  m_flPos = v28;
                }
                else
                {
                  m_flPos += 4;
                  v28 = 0x7FFFFFFF;
                }
                v29 = (int)(float)(v27->m_flPos + 0.5);
                if ( m_flPos > v29 || v28 < v29 )
                  v27->m_flPos = (float)m_flPos;
                else
                  m_flPos = (int)v27->m_flPos;
                ++v25;
                --k;
              }
              while ( k != 0 );
            }
            v26->InvalidateLayout(this: v26, a2: false, a3: false);
            v2 = v39;
          }
        }
      }
LABEL_56:
      v36 += 20;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < nSplitterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475870
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Splitter::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Splitter::GetMessageMap(vgui::Splitter *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Splitter::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetMessageMap'::`2'::s_pMap;
  `vgui::Splitter::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Splitter");
  `vgui::Splitter::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004758A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Splitter::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Splitter::GetAnimMap(vgui::Splitter *this)
{
  return FindOrAddPanelAnimationMap(className: "Splitter");
}

//------------------------------------------------------------------------------
// Address: 0x004758B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Splitter::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Splitter::GetKBMap(vgui::Splitter *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Splitter::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetKBMap'::`2'::s_pMap;
  `vgui::Splitter::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
  `vgui::Splitter::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475920
// Name: private: void vgui::Splitter::RecreateSplitters(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RecreateSplitters(vgui::Splitter *this, int nCount)
{
  int m_Size; // eax
  int v3; // edi
  int i; // esi
  vgui::SplitterChildPanel *m_pPanel; // eax
  vgui::SplitterHandle *m_pHandle; // eax
  int v7; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Splitters; // esi
  int v9; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v12; // ecx
  int v13; // eax
  vgui::SplitterChildPanel *v14; // eax
  vgui::SplitterChildPanel *v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ebx
  vgui::SplitterHandle *v19; // eax
  vgui::SplitterHandle *v20; // eax
  char pBuffer[512]; // [esp+Ch] [ebp-204h] BYREF
  vgui::Panel *parent; // [esp+20Ch] [ebp-4h]

  m_Size = this->m_Splitters.m_Size;
  parent = this;
  if ( m_Size > 0 )
  {
    v3 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      m_pPanel = this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel;
      if ( m_pPanel != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterChildPanel *, int))m_pPanel->dtr_Panel)(
          a1: this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel,
          a2: 1);
        this = (vgui::Splitter *)parent;
      }
      m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v3].m_pHandle;
      if ( m_pHandle != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterHandle *, int))m_pHandle->dtr_Panel)(a1: m_pHandle, a2: 1);
        this = (vgui::Splitter *)parent;
      }
      ++v3;
    }
  }
  v7 = nCount;
  p_m_Splitters = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Splitters;
  v9 = 0;
  this->m_Splitters.m_Size = 0;
  if ( nCount + 1 > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "child%d", v9);
      m_pMemory = (int)p_m_Splitters[1].m_pMemory;
      m_nAllocationCount = p_m_Splitters->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
          this: p_m_Splitters,
          num: m_pMemory - m_nAllocationCount + 1);
      ++p_m_Splitters[1].m_pMemory;
      v12 = p_m_Splitters->m_pMemory;
      v13 = (int)p_m_Splitters[1].m_pMemory - m_pMemory - 1;
      p_m_Splitters[1].m_nAllocationCount = (int)p_m_Splitters->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v12[m_pMemory + 1],
          src: (unsigned __int8 *)&v12[m_pMemory],
          count: 20 * v13);
      v14 = (vgui::SplitterChildPanel *)operator new(nSize: 0x180u);
      if ( v14 != nullptr )
        v15 = vgui::SplitterChildPanel::SplitterChildPanel(this: v14, parent, panelName: pBuffer);
      else
        v15 = nullptr;
      v16 = m_pMemory;
      *(_DWORD *)&p_m_Splitters->m_pMemory[v16].m_Title.m_Id = v15;
      LOBYTE(p_m_Splitters->m_pMemory[v16].m_Right) = 0;
      ++v9;
      p_m_Splitters->m_pMemory[v16].m_ciFlags = 0;
    }
    while ( v9 < nCount + 1 );
    v7 = nCount;
  }
  v17 = 0;
  if ( v7 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = (vgui::SplitterHandle *)operator new(nSize: 0x15Cu);
      if ( v19 != nullptr )
        v20 = vgui::SplitterHandle::SplitterHandle(
                this: v19,
                (vgui::Splitter *)parent,
                name: "SplitterHandle",
                mode: (vgui::SplitterMode_t)parent[1]._vpanel,
                nIndex: v17);
      else
        v20 = nullptr;
      p_m_Splitters->m_pMemory[v18].m_Width = (int)v20;
      v20->MoveToFront(this: v20);
      ++v17;
      ++v18;
    }
    while ( v17 < nCount );
    v7 = nCount;
  }
  p_m_Splitters->m_pMemory[v7].m_Width = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00475AD0
// Name: public: vgui::Splitter::Splitter(class vgui::Panel __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Splitter *__thiscall vgui::Splitter::Splitter(
        vgui::Splitter *this,
        vgui::Panel *parent,
        char *name,
        vgui::SplitterMode_t mode,
        int nCount)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (vgui::Splitter_vtbl *)&vgui::Splitter::`vftable';
  if ( `vgui::Splitter::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "Splitter");
    v6->pfnClassName = vgui::Splitter::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "Splitter");
    v7->pfnClassName = vgui::Splitter::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
    v8->pfnClassName = vgui::Splitter::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  this->m_Splitters.m_Memory.m_pMemory = nullptr;
  this->m_Splitters.m_Memory.m_nAllocationCount = 0;
  this->m_Splitters.m_Memory.m_nGrowSize = 0;
  this->m_Splitters.m_Size = 0;
  this->m_Splitters.m_pElements = nullptr;
  this->m_Mode = mode;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Splitter::RecreateSplitters(this, nCount);
  vgui::Splitter::EvenlyRespaceSplitters(this);
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00625180
// Name: public: static char const __near * vgui::Splitter::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Splitter::GetPanelClassName()
{
  return "Splitter";
}

//------------------------------------------------------------------------------
// Address: 0x00625190
// Name: public: static char const __near * vgui::SplitterHandle::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterHandle::GetPanelClassName()
{
  return "SplitterHandle";
}

//------------------------------------------------------------------------------
// Address: 0x006251A0
// Name: public: virtual void vgui::SplitterHandle::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::ApplySchemeSettings(vgui::SplitterHandle *this, vgui::IScheme *pScheme)
{
  vgui::SplitterHandle_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color c; // [esp+Ch] [ebp-4h] BYREF

  this->GetBgColor(this, result: &c);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x00625200
// Name: public: virtual void vgui::SplitterHandle::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMousePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  if ( !this->m_bDragging )
  {
    v3 = g_pVGuiInput;
    v4 = g_pVGuiInput->__vftable;
    v5 = this->GetVPanel(this);
    v4->SetMouseCapture(this: v3, a2: v5);
    this->m_bDragging = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00625240
// Name: public: virtual void vgui::SplitterHandle::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseReleased(vgui::SplitterHandle *this, ButtonCode_t code)
{
  if ( this->m_bDragging )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_bDragging = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00625270
// Name: public: static char const __near * vgui::SplitterChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SplitterChildPanel::GetPanelClassName()
{
  return "SplitterChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00625280
// Name: public: virtual void vgui::Splitter::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetSettings(vgui::Splitter *this, KeyValues *outResourceData)
{
  vgui::Panel::GetSettings(this, outResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00625290
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterHandle::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterHandle::GetMessageMap(vgui::SplitterHandle *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006252C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterHandle::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterHandle::GetAnimMap(vgui::SplitterHandle *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterHandle");
}

//------------------------------------------------------------------------------
// Address: 0x006252D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterHandle::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterHandle::GetKBMap(vgui::SplitterHandle *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterHandle::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
  `vgui::SplitterHandle::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00625300
// Name: public: vgui::SplitterHandle::SplitterHandle(class vgui::Splitter __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterHandle *__thiscall vgui::SplitterHandle::SplitterHandle(
        vgui::SplitterHandle *this,
        vgui::Splitter *parent,
        const char *name,
        vgui::SplitterMode_t mode,
        int nIndex)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::SplitterMode_t v9; // edi
  int v10; // eax
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::SplitterHandle_vtbl *)&vgui::SplitterHandle::`vftable';
  if ( `vgui::SplitterHandle::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "SplitterHandle");
    v6->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "SplitterHandle");
    v7->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterHandle::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterHandle");
    v8->pfnClassName = vgui::SplitterHandle::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::GetSize(this: parent, wide: (int *)&name, tall: &h);
  v9 = mode;
  if ( mode != SPLITTER_MODE_HORIZONTAL )
  {
    vgui::Panel::SetSize(this, wide: 4, tall: h);
    vgui::Panel::SetCursor(this, cursor: 0xAu);
  }
  else
  {
    vgui::Panel::SetSize(this, wide: (int)name, tall: 4);
    vgui::Panel::SetCursor(this, cursor: 0xBu);
  }
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  v10 = nIndex;
  this->m_nMode = v9;
  this->m_nIndex = v10;
  this->m_bDragging = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00625470
// Name: public: vgui::SplitterChildPanel::SplitterChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SplitterChildPanel *__thiscall vgui::SplitterChildPanel::SplitterChildPanel(
        vgui::SplitterChildPanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::SplitterChildPanel_vtbl *)&vgui::SplitterChildPanel::`vftable';
  if ( `vgui::SplitterChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
    v4->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
    v5->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SplitterChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
    v6->pfnClassName = vgui::SplitterChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00625580
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SplitterChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SplitterChildPanel::GetMessageMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006255B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::SplitterChildPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SplitterChildPanel::GetAnimMap(vgui::SplitterChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SplitterChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x006255C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SplitterChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SplitterChildPanel::GetKBMap(vgui::SplitterChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SplitterChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SplitterChildPanel");
  `vgui::SplitterChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00625690
// Name: public: void vgui::Splitter::SetSplitterColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterColor(vgui::Splitter *this, Color c)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  vgui::SplitterHandle *m_pHandle; // ecx
  vgui::SplitterHandle *v7; // ecx
  int v8; // esi
  int v9; // ebx
  vgui::SplitterHandle *v10; // ecx

  v3 = this->m_Splitters.m_Size - 1;
  if ( c._color[3] != 0 )
  {
    if ( v3 > 0 )
    {
      v4 = 0;
      v5 = this->m_Splitters.m_Size - 1;
      do
      {
        m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v4].m_pHandle;
        m_pHandle->SetBgColor(this: m_pHandle, a2: c);
        v7 = this->m_Splitters.m_Memory.m_pMemory[v4].m_pHandle;
        v7->SetPaintBackgroundEnabled(this: v7, a2: true);
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( v3 > 0 )
  {
    v8 = 0;
    v9 = this->m_Splitters.m_Size - 1;
    do
    {
      v10 = this->m_Splitters.m_Memory.m_pMemory[v8].m_pHandle;
      v10->SetPaintBackgroundEnabled(this: v10, a2: false);
      ++v8;
      --v9;
    }
    while ( v9 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00625720
// Name: public: virtual void vgui::Splitter::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::OnSizeChanged(vgui::Splitter *this, int newWide, int newTall)
{
  vgui::Splitter *v3; // ebx
  int m_Size; // ecx
  float v5; // xmm2_4
  int v6; // eax
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // eax
  float *p_m_flPos; // edx
  char *v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  int v19; // edi
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm3_4
  int v23; // ecx
  unsigned int v24; // esi
  vgui::Splitter::SplitterInfo_t *v25; // eax
  float m_flPos; // xmm4_4
  vgui::Splitter::SplitterInfo_t *v27; // eax
  float m_nLockedSize; // xmm0_4
  float v29; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v30; // eax
  bool v31; // zf
  int v32; // eax
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v37; // eax
  int v38; // edx
  int v39; // eax
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v44; // eax
  int *v45; // eax
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // ecx
  int v50; // edx
  vgui::Splitter::SplitterInfo_t *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  int nCount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int newWidea; // [esp+20h] [ebp+8h]

  v3 = this;
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  if ( newTall > 0 && newWide > 0 )
  {
    m_Size = v3->m_Splitters.m_Size;
    v5 = 0.0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0.0;
    nCount = m_Size;
    v10 = 0.0;
    i = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v3->m_Splitters.m_Memory.m_pMemory;
      p_m_flPos = &m_pMemory->m_flPos;
      v13 = (char *)&m_pMemory[1].m_flPos;
      v14 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * v14;
      do
      {
        if ( *((_BYTE *)p_m_flPos + 4) != 0 )
        {
          v7 += *((_DWORD *)p_m_flPos + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*p_m_flPos - v10) + v9;
        }
        if ( v13[4] != 0 )
        {
          v7 += *((_DWORD *)v13 + 2);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v13 - *p_m_flPos) + v9;
        }
        if ( v13[24] != 0 )
        {
          v7 += *((_DWORD *)v13 + 7);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 5) - *(float *)v13) + v9;
        }
        if ( v13[44] != 0 )
        {
          v7 += *((_DWORD *)v13 + 12);
        }
        else
        {
          ++v8;
          v9 = (float)(*((float *)v13 + 10) - *((float *)v13 + 5)) + v9;
        }
        v10 = *((float *)v13 + 10);
        p_m_flPos += 20;
        v13 += 80;
        --v14;
      }
      while ( v14 != 0 );
      v3 = this;
      m_Size = nCount;
      v6 = i;
    }
    if ( v6 < m_Size )
    {
      v15 = m_Size - i;
      v16 = (int)&v3->m_Splitters.m_Memory.m_pMemory[v6].m_flPos;
      do
      {
        if ( *(_BYTE *)(v16 + 4) != 0 )
        {
          v7 += *(_DWORD *)(v16 + 8);
        }
        else
        {
          ++v8;
          v9 = (float)(*(float *)v16 - v10) + v9;
        }
        v10 = *(float *)v16;
        v16 += 20;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( v3->m_Mode != SPLITTER_MODE_HORIZONTAL )
      newTall = newWide;
    v17 = newTall - v7;
    if ( newTall - v7 < 4 * v8 )
      v17 = 4 * v8;
    v18 = (float)v17;
    v19 = nCount - 1;
    v20 = 0;
    v21 = v18 / v9;
    v22 = 0.0;
    if ( nCount - 1 >= 4 )
    {
      v23 = 0;
      v24 = ((unsigned int)(nCount - 5) >> 2) + 1;
      newWidea = 4 * v24;
      do
      {
        v25 = v3->m_Splitters.m_Memory.m_pMemory;
        m_flPos = v25[v23].m_flPos;
        v27 = &v25[v23];
        if ( v27->m_bLocked )
          m_nLockedSize = (float)v27->m_nLockedSize;
        else
          m_nLockedSize = (float)(m_flPos - v5) * v21;
        v29 = m_nLockedSize + v22;
        v27->m_flPos = v29;
        v30 = v3->m_Splitters.m_Memory.m_pMemory;
        v31 = !v30[v23 + 1].m_bLocked;
        v32 = (int)&v30[v23 + 1];
        v33 = v29;
        if ( v31 )
        {
          v35 = (float)(*(float *)(v32 + 8) - m_flPos) * v21;
          v34 = *(float *)(v32 + 8);
        }
        else
        {
          v34 = *(float *)(v32 + 8);
          v35 = (float)*(int *)(v32 + 16);
        }
        v36 = v35 + v33;
        *(float *)(v32 + 8) = v36;
        v37 = v3->m_Splitters.m_Memory.m_pMemory;
        v38 = v23 * 20 + 60;
        v31 = !v37[v23 + 2].m_bLocked;
        v39 = (int)&v37[v23 + 2];
        v40 = v36;
        if ( v31 )
        {
          v42 = (float)(*(float *)(v39 + 8) - v34) * v21;
          v41 = *(float *)(v39 + 8);
        }
        else
        {
          v41 = *(float *)(v39 + 8);
          v42 = (float)*(int *)(v39 + 16);
        }
        v43 = v42 + v40;
        *(float *)(v39 + 8) = v43;
        v44 = v3->m_Splitters.m_Memory.m_pMemory;
        v5 = *(float *)((char *)&v44->m_flPos + v38);
        v45 = (int *)((char *)v44 + v38);
        v46 = v43;
        if ( *((_BYTE *)v45 + 12) != 0 )
          v47 = (float)v45[4];
        else
          v47 = (float)(v5 - v41) * v21;
        v48 = v47 + v46;
        v23 += 4;
        --v24;
        *((float *)v45 + 2) = v48;
        v22 = v48;
      }
      while ( v24 != 0 );
      v20 = newWidea;
    }
    if ( v20 < v19 )
    {
      v49 = v20;
      v50 = v19 - v20;
      do
      {
        v51 = &v3->m_Splitters.m_Memory.m_pMemory[v49];
        if ( v51->m_bLocked )
          v52 = (float)v51->m_nLockedSize;
        else
          v52 = (float)(v51->m_flPos - v5) * v21;
        v5 = v51->m_flPos;
        v53 = v52 + v22;
        ++v49;
        --v50;
        v51->m_flPos = v53;
        v22 = v53;
      }
      while ( v50 != 0 );
    }
    v3->m_Splitters.m_Memory.m_pMemory[nCount - 1].m_flPos = (float)newTall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00625A30
// Name: private: void vgui::Splitter::SetSplitterPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::SetSplitterPosition(vgui::Splitter *this, int nIndex, int nPos)
{
  int v4; // esi
  int v5; // eax
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  int *i; // ecx
  int v8; // edi
  int *p_m_nLockedSize; // ecx
  int j; // edx
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int m_flPos; // ecx
  int v19; // esi
  int v20; // edx
  char *v21; // edx
  int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  vgui::Splitter *v26; // ebx
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  int c; // [esp+8h] [ebp-10h]
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::Splitter *v33; // [esp+14h] [ebp-4h]
  int nMinPos; // [esp+20h] [ebp+8h]
  int nMinPosa; // [esp+20h] [ebp+8h]
  int nPosa; // [esp+24h] [ebp+Ch]

  v33 = this;
  vgui::Panel::GetSize(this, &wide, &tall);
  v4 = tall;
  if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
    v4 = wide;
  if ( v4 != 0 )
  {
    v5 = nIndex;
    if ( nIndex >= 0 )
    {
      m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
      tall = (int)m_pMemory;
      for ( i = &m_pMemory[nIndex].m_nLockedSize; *((_BYTE *)i - 4) != 0; i -= 5 )
      {
        nPos -= *i;
        if ( --v5 < 0 )
          return;
      }
      if ( v5 >= 0 )
      {
        v8 = 0;
        nMinPos = 0;
        if ( v5 > 0 )
        {
          p_m_nLockedSize = &m_pMemory->m_nLockedSize;
          for ( j = v5; j != 0; --j )
          {
            if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
              v8 += *p_m_nLockedSize;
            else
              v8 += 4;
            p_m_nLockedSize += 5;
          }
          nMinPos = v8;
        }
        v11 = this->m_Splitters.m_Size - 1;
        v12 = v5 + 1;
        v13 = v4 - 4;
        c = v11;
        wide = v5 + 1;
        if ( v5 + 1 < v11 )
        {
          v14 = (_DWORD *)(tall + 20 * v12 + 16);
          v15 = v11 - v12;
          do
          {
            if ( *((_BYTE *)v14 - 4) != 0 )
              v13 -= *v14;
            else
              v13 -= 4;
            v14 += 5;
            --v15;
          }
          while ( v15 != 0 );
          v8 = nMinPos;
        }
        v16 = nPos;
        if ( nPos >= v8 )
        {
          if ( nPos > v13 )
            v16 = v13;
        }
        else
        {
          v16 = v8;
        }
        v17 = v5 - 1;
        m_flPos = v16;
        *(float *)(tall + 20 * v5 + 8) = (float)v16;
        v19 = v16;
        if ( v5 - 1 >= 0 )
        {
          v20 = 20 * v17;
          for ( nMinPosa = 20 * v17; ; v20 = nMinPosa )
          {
            v21 = (char *)v33->m_Splitters.m_Memory.m_pMemory + v20;
            if ( v21[32] != 0 )
            {
              v22 = v19 - *((_DWORD *)v21 + 9);
              v23 = v22;
            }
            else
            {
              v22 = -2147483647;
              v23 = v16 - 4;
            }
            v24 = (int)(float)(*((float *)v21 + 2) + 0.5);
            if ( v23 < v24 || v22 > v24 )
            {
              *((float *)v21 + 2) = (float)v23;
              v19 = v23;
            }
            else
            {
              v19 = (int)*((float *)v21 + 2);
            }
            nMinPosa -= 20;
            if ( --v17 < 0 )
              break;
          }
          m_flPos = v16;
        }
        if ( wide >= c )
        {
          v26 = v33;
        }
        else
        {
          v25 = wide;
          nPosa = c - wide;
          do
          {
            v26 = v33;
            v27 = &v33->m_Splitters.m_Memory.m_pMemory[v25];
            if ( v27->m_bLocked )
            {
              v28 = m_flPos + v27->m_nLockedSize;
              m_flPos = v28;
            }
            else
            {
              m_flPos += 4;
              v28 = 0x7FFFFFFF;
            }
            v29 = (int)(float)(v27->m_flPos + 0.5);
            if ( m_flPos > v29 || v28 < v29 )
              v27->m_flPos = (float)m_flPos;
            else
              m_flPos = (int)v27->m_flPos;
            ++v25;
            --nPosa;
          }
          while ( nPosa != 0 );
        }
        v26->InvalidateLayout(this: v26, a2: false, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00625C40
// Name: public: void vgui::Splitter::EvenlyRespaceSplitters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::EvenlyRespaceSplitters(vgui::Splitter *this)
{
  int m_Size; // ebx
  int v3; // edi
  int *p_m_nLockedSize; // eax
  int v5; // ecx
  int v6; // eax
  float v7; // xmm2_4
  __int128 v8; // xmm0
  int v9; // edi
  int v10; // eax
  unsigned int v11; // edx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ecx
  __int128 v13; // xmm1
  vgui::Splitter::SplitterInfo_t *v14; // ecx
  __int128 v15; // xmm0
  vgui::Splitter::SplitterInfo_t *v16; // ecx
  __int128 v17; // xmm1
  vgui::Splitter::SplitterInfo_t *v18; // ecx
  int v19; // eax
  int v20; // edx
  vgui::Splitter::SplitterInfo_t *v21; // ecx
  int wide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    v3 = 0;
    if ( m_Size > 0 )
    {
      p_m_nLockedSize = &this->m_Splitters.m_Memory.m_pMemory->m_nLockedSize;
      v5 = this->m_Splitters.m_Size;
      do
      {
        if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
          v3 += *p_m_nLockedSize;
        p_m_nLockedSize += 5;
        --v5;
      }
      while ( v5 != 0 );
    }
    vgui::Panel::GetSize(this, &wide, &tall);
    v6 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v6 = wide;
    v7 = (float)(v6 - v3) / (float)m_Size;
    if ( v7 < 4.0 )
      v7 = 4.0;
    v8 = 0;
    v9 = 0;
    if ( m_Size >= 4 )
    {
      v10 = 0;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v9 = 4 * v11;
      do
      {
        m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
        if ( m_pMemory[v10].m_bLocked )
        {
          v13 = COERCE_UNSIGNED_INT((float)m_pMemory[v10].m_nLockedSize);
          *(float *)&v13 = *(float *)&v13 + *(float *)&v8;
        }
        else
        {
          *(float *)&v8 = *(float *)&v8 + v7;
          v13 = v8;
        }
        LODWORD(m_pMemory[v10].m_flPos) = v13;
        v14 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v14[v10 + 1].m_bLocked )
        {
          v15 = COERCE_UNSIGNED_INT((float)v14[v10 + 1].m_nLockedSize);
          *(float *)&v15 = *(float *)&v15 + *(float *)&v13;
        }
        else
        {
          *(float *)&v13 = *(float *)&v13 + v7;
          v15 = v13;
        }
        LODWORD(v14[v10 + 1].m_flPos) = v15;
        v16 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v16[v10 + 2].m_bLocked )
        {
          v17 = COERCE_UNSIGNED_INT((float)v16[v10 + 2].m_nLockedSize);
          *(float *)&v17 = *(float *)&v17 + *(float *)&v15;
        }
        else
        {
          *(float *)&v15 = *(float *)&v15 + v7;
          v17 = v15;
        }
        LODWORD(v16[v10 + 2].m_flPos) = v17;
        v18 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v18[v10 + 3].m_bLocked )
        {
          v8 = COERCE_UNSIGNED_INT((float)v18[v10 + 3].m_nLockedSize);
          *(float *)&v8 = *(float *)&v8 + *(float *)&v17;
        }
        else
        {
          *(float *)&v17 = *(float *)&v17 + v7;
          v8 = v17;
        }
        LODWORD(v18[v10 + 3].m_flPos) = v8;
        v10 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    if ( v9 < m_Size )
    {
      v19 = v9;
      v20 = m_Size - v9;
      do
      {
        v21 = this->m_Splitters.m_Memory.m_pMemory;
        if ( v21[v19].m_bLocked )
          *(float *)&v8 = *(float *)&v8 + (float)v21[v19].m_nLockedSize;
        else
          *(float *)&v8 = *(float *)&v8 + v7;
        LODWORD(v21[v19++].m_flPos) = v8;
        --v20;
      }
      while ( v20 != 0 );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00625DF0
// Name: public: void vgui::Splitter::RespaceSplitters(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RespaceSplitters(vgui::Splitter *this, float *flFractions)
{
  int m_Size; // ebx
  int v4; // ecx
  float *v5; // eax
  float v6; // xmm0_4
  int v7; // edi
  float v8; // xmm2_4
  int v9; // ecx
  float *v10; // eax
  unsigned int v11; // edx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // ecx
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  float flPos; // [esp+10h] [ebp-8h]
  int tall; // [esp+14h] [ebp-4h] BYREF

  m_Size = this->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    flPos = 0.0;
    vgui::Panel::GetSize(this, &wide, &tall);
    v4 = tall;
    if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
      v4 = wide;
    v5 = flFractions;
    v6 = flPos;
    v7 = 0;
    tall = v4;
    if ( m_Size >= 4 )
    {
      v8 = (float)v4;
      v9 = 0;
      v10 = flFractions + 2;
      v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v7 = 4 * v11;
      do
      {
        v12 = *(v10 - 2) + v6;
        this->m_Splitters.m_Memory.m_pMemory[v9].m_flPos = v8 * v12;
        v13 = *(v10 - 1) + v12;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 1].m_flPos = v8 * v13;
        v14 = v13 + *v10;
        this->m_Splitters.m_Memory.m_pMemory[v9 + 2].m_flPos = v8 * v14;
        v6 = v14 + v10[1];
        this->m_Splitters.m_Memory.m_pMemory[v9 + 3].m_flPos = v8 * v6;
        v10 += 4;
        v9 += 4;
        --v11;
      }
      while ( v11 != 0 );
      v5 = flFractions;
      v4 = tall;
    }
    if ( v7 < m_Size )
    {
      v15 = (float)v4;
      v16 = v7;
      do
      {
        v6 = v6 + v5[v7];
        this->m_Splitters.m_Memory.m_pMemory[v16].m_flPos = v15 * v6;
        ++v7;
        ++v16;
      }
      while ( v7 < m_Size );
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00625F40
// Name: public: virtual void vgui::Splitter::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplyUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // ebx
  void *v4; // esp
  int v5; // edi
  double Float; // st7
  KeyValues *v7; // eax
  int v8; // edx
  float v9; // xmm2_4
  int v10; // ecx
  float *v11; // eax
  unsigned int v12; // edi
  float v13; // xmm1_4
  vgui::Splitter::SplitterInfo_t *m_pMemory; // ebx
  float v15; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v16; // ebx
  float v17; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v18; // ebx
  float v19; // xmm0_4
  vgui::Splitter::SplitterInfo_t *v20; // ebx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm0_4
  int v26; // [esp+4h] [ebp-9Ch] BYREF
  char name[128]; // [esp+10h] [ebp-90h] BYREF
  int c; // [esp+90h] [ebp-10h]
  int wide; // [esp+94h] [ebp-Ch] BYREF
  float *pFractions; // [esp+98h] [ebp-8h]
  float flTotalSize; // [esp+9Ch] [ebp-4h]

  vgui::EditablePanel::ApplyUserConfigSettings(this, userConfig);
  c = this->m_Splitters.m_Size;
  v3 = c;
  v4 = alloca(4 * c);
  v5 = 0;
  pFractions = (float *)&v26;
  flTotalSize = 0.0;
  if ( c > 0 )
  {
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v5);
      Float = KeyValues::GetFloat(this: userConfig, keyName: name, defaultValue: flTotalSize + 5.0);
      pFractions[v5++] = Float;
      flTotalSize = Float;
    }
    while ( v5 < v3 );
    if ( flTotalSize != 0.0 )
    {
      vgui::Panel::GetSize(this, &wide, tall: (int *)&userConfig);
      v7 = userConfig;
      if ( this->m_Mode != SPLITTER_MODE_HORIZONTAL )
        v7 = (KeyValues *)wide;
      v8 = 0;
      userConfig = v7;
      if ( v3 >= 4 )
      {
        v9 = (float)(int)v7;
        v10 = 0;
        v11 = pFractions + 2;
        v12 = ((unsigned int)(v3 - 4) >> 2) + 1;
        v13 = 1.0 / flTotalSize;
        v8 = 4 * v12;
        do
        {
          m_pMemory = this->m_Splitters.m_Memory.m_pMemory;
          v15 = v13 * *(v11 - 2);
          *(v11 - 2) = v15;
          m_pMemory[v10].m_flPos = v15 * v9;
          v16 = this->m_Splitters.m_Memory.m_pMemory;
          v17 = *(v11 - 1) * v13;
          *(v11 - 1) = v17;
          v16[v10 + 1].m_flPos = v17 * v9;
          v18 = this->m_Splitters.m_Memory.m_pMemory;
          v19 = *v11 * v13;
          *v11 = v19;
          v18[v10 + 2].m_flPos = v19 * v9;
          v20 = this->m_Splitters.m_Memory.m_pMemory;
          v21 = v11[1] * v13;
          v11[1] = v21;
          v20[v10 + 3].m_flPos = v21 * v9;
          v11 += 4;
          v10 += 4;
          --v12;
        }
        while ( v12 != 0 );
        v7 = userConfig;
        v3 = c;
      }
      if ( v8 < v3 )
      {
        v22 = (float)(int)v7;
        v23 = 1.0 / flTotalSize;
        v24 = v8;
        do
        {
          v25 = pFractions[v8] * v23;
          pFractions[v8] = v25;
          this->m_Splitters.m_Memory.m_pMemory[v24].m_flPos = v22 * v25;
          ++v8;
          ++v24;
        }
        while ( v8 < v3 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626120
// Name: public: virtual void vgui::Splitter::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::GetUserConfigSettings(vgui::Splitter *this, KeyValues *userConfig)
{
  int v3; // esi
  int v4; // edi
  char name[128]; // [esp+10h] [ebp-84h] BYREF
  int c; // [esp+90h] [ebp-4h]

  vgui::EditablePanel::GetUserConfigSettings(this, userConfig);
  v3 = 0;
  c = this->m_Splitters.m_Size;
  if ( c > 0 )
  {
    v4 = 0;
    do
    {
      _snprintf(string: name, count: 0x80u, format: "%d_splitter_pos", v3);
      KeyValues::SetFloat(this: userConfig, keyName: name, value: this->m_Splitters.m_Memory.m_pMemory[v4].m_flPos);
      ++v3;
      ++v4;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x006261A0
// Name: public: virtual void vgui::Splitter::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::PerformLayout(vgui::Splitter *this)
{
  vgui::Splitter *v1; // esi
  int m_Size; // edi
  int v3; // ecx
  vgui::Splitter::SplitterInfo_t *m_pMemory; // edx
  vgui::Panel *m_pPanel; // ebx
  vgui::Panel *m_pHandle; // esi
  int v7; // edi
  bool v8; // zf
  int v9; // [esp+8h] [ebp-18h]
  int h; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  vgui::Splitter *v12; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  int nLastPos; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v12 = this;
  vgui::EditablePanel::PerformLayout(this);
  m_Size = v1->m_Splitters.m_Size;
  if ( m_Size != 0 )
  {
    vgui::Panel::GetSize(this: v1, wide: &w, tall: &h);
    v3 = 0;
    nLastPos = 0;
    if ( m_Size > 0 )
    {
      v13 = 0;
      v9 = m_Size;
      while ( 1 )
      {
        m_pMemory = v1->m_Splitters.m_Memory.m_pMemory;
        m_pPanel = m_pMemory[v13 / 0x14].m_pPanel;
        m_pHandle = m_pMemory[v13 / 0x14].m_pHandle;
        v7 = (int)(float)(m_pMemory[v13 / 0x14].m_flPos + 0.5);
        if ( v12->m_Mode != SPLITTER_MODE_HORIZONTAL )
        {
          vgui::Panel::SetPos(this: m_pPanel, x: v3, y: 0);
          vgui::Panel::SetSize(this: m_pPanel, wide: v7 - nLastPos, tall: h);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: v7, y: 0);
            vgui::Panel::SetSize(this: m_pHandle, wide: 4, tall: h);
          }
        }
        else
        {
          vgui::Panel::SetPos(this: m_pPanel, x: 0, y: v3);
          vgui::Panel::SetSize(this: m_pPanel, wide: w, tall: v7 - nLastPos);
          if ( m_pHandle != nullptr )
          {
            vgui::Panel::SetPos(this: m_pHandle, x: 0, y: v7);
            vgui::Panel::SetSize(this: m_pHandle, wide: w, tall: 4);
          }
        }
        v13 += 20;
        v8 = v9-- == 1;
        nLastPos = v7 + 4;
        if ( v8 )
          break;
        v1 = v12;
        v3 = nLastPos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006262B0
// Name: public: virtual void vgui::SplitterHandle::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnCursorMoved(vgui::SplitterHandle *this, int x, int y)
{
  vgui::Splitter *v4; // edi
  int v5; // eax

  if ( this->m_bDragging )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    v4 = (vgui::Splitter *)this->GetParent(this);
    vgui::Panel::ScreenToLocal(this: v4, &x, &y);
    v5 = y;
    if ( this->m_nMode != SPLITTER_MODE_HORIZONTAL )
      v5 = x;
    vgui::Splitter::SetSplitterPosition(this: v4, nIndex: this->m_nIndex, nPos: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626320
// Name: public: virtual void vgui::SplitterHandle::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SplitterHandle::OnMouseDoublePressed(vgui::SplitterHandle *this, ButtonCode_t code)
{
  vgui::Splitter *v2; // eax

  v2 = (vgui::Splitter *)this->GetParent(this);
  vgui::Splitter::EvenlyRespaceSplitters(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00626340
// Name: public: virtual void vgui::Splitter::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::ApplySettings(vgui::Splitter *this, KeyValues *inResourceData)
{
  vgui::Panel *v2; // ebx
  int v3; // esi
  int Int; // eax
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int *p_m_nGrowSize; // eax
  int j; // edi
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  int *p_m_nLockedSize; // eax
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int m_flPos; // ecx
  int v20; // eax
  int v21; // edx
  char *v22; // edx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  vgui::Splitter *v26; // edi
  vgui::Splitter::SplitterInfo_t *v27; // edx
  int v28; // eax
  int v29; // esi
  char pBuffer[512]; // [esp+8h] [ebp-228h] BYREF
  int v31; // [esp+208h] [ebp-28h]
  int nSplitterCount; // [esp+20Ch] [ebp-24h]
  int wide; // [esp+210h] [ebp-20h] BYREF
  int v34; // [esp+214h] [ebp-1Ch]
  int tall; // [esp+218h] [ebp-18h] BYREF
  int v36; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v38; // [esp+224h] [ebp-Ch]
  vgui::Splitter *v39; // [esp+228h] [ebp-8h]
  int k; // [esp+22Ch] [ebp-4h]

  v2 = this;
  v39 = this;
  vgui::EditablePanel::ApplySettings(this, a2: (int)this, inResourceData);
  v3 = 0;
  nSplitterCount = v2[1].m_infoFont - 1;
  i = 0;
  if ( nSplitterCount > 0 )
  {
    v36 = 0;
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "splitter%d", v3);
      Int = KeyValues::GetInt(this: inResourceData, keyName: pBuffer, defaultValue: -1);
      if ( Int >= 0 )
      {
        v5 = Int;
        vgui::Panel::GetSize(this: v2, &wide, &tall);
        v6 = tall;
        if ( v2[1]._vpanel != 0 )
          v6 = wide;
        if ( v6 != 0 && i >= 0 )
        {
          v7 = (int *)((char *)&v2[1].m_pTooltips->m_Text.m_Memory.m_nGrowSize + v36);
          while ( *((_BYTE *)v7 - 4) != 0 )
          {
            v5 -= *v7;
            v7 -= 5;
            if ( --v3 < 0 )
              goto LABEL_56;
          }
          v38 = v5;
          if ( v3 >= 0 )
          {
            v8 = 0;
            k = 0;
            if ( v3 > 0 )
            {
              p_m_nGrowSize = &v2[1].m_pTooltips->m_Text.m_Memory.m_nGrowSize;
              for ( j = v3; j != 0; --j )
              {
                if ( *((_BYTE *)p_m_nGrowSize - 4) != 0 )
                  v8 += *p_m_nGrowSize;
                else
                  v8 += 4;
                p_m_nGrowSize += 5;
              }
              k = v8;
            }
            v11 = v2[1].m_infoFont - 1;
            v12 = v3 + 1;
            v13 = v6 - 4;
            v31 = v11;
            v34 = v3 + 1;
            if ( v3 + 1 < v11 )
            {
              p_m_nLockedSize = &v39->m_Splitters.m_Memory.m_pMemory[v12].m_nLockedSize;
              v15 = v11 - v12;
              do
              {
                if ( *((_BYTE *)p_m_nLockedSize - 4) != 0 )
                  v13 -= *p_m_nLockedSize;
                else
                  v13 -= 4;
                p_m_nLockedSize += 5;
                --v15;
              }
              while ( v15 != 0 );
              v8 = k;
            }
            v16 = v38;
            if ( v38 >= v8 )
            {
              if ( v38 > v13 )
                v16 = v13;
            }
            else
            {
              v16 = v8;
            }
            v17 = v3;
            v18 = v3 - 1;
            m_flPos = v16;
            v39->m_Splitters.m_Memory.m_pMemory[v17].m_flPos = (float)v16;
            v38 = v16;
            v20 = v16;
            if ( v18 >= 0 )
            {
              v21 = 20 * v18;
              for ( k = 20 * v18; ; v21 = k )
              {
                v22 = (char *)v39->m_Splitters.m_Memory.m_pMemory + v21;
                if ( v22[32] != 0 )
                {
                  v20 -= *((_DWORD *)v22 + 9);
                  v23 = v20;
                }
                else
                {
                  v23 = -2147483647;
                  v20 = v16 - 4;
                }
                v24 = (int)(float)(*((float *)v22 + 2) + 0.5);
                if ( v20 < v24 || v23 > v24 )
                  *((float *)v22 + 2) = (float)v20;
                else
                  v20 = (int)*((float *)v22 + 2);
                k -= 20;
                if ( --v18 < 0 )
                  break;
              }
              v11 = v31;
              m_flPos = v38;
            }
            if ( v34 >= v11 )
            {
              v26 = v39;
            }
            else
            {
              v25 = v34;
              k = v11 - v34;
              do
              {
                v26 = v39;
                v27 = &v39->m_Splitters.m_Memory.m_pMemory[v25];
                if ( v27->m_bLocked )
                {
                  v28 = m_flPos + v27->m_nLockedSize;
                  m_flPos = v28;
                }
                else
                {
                  m_flPos += 4;
                  v28 = 0x7FFFFFFF;
                }
                v29 = (int)(float)(v27->m_flPos + 0.5);
                if ( m_flPos > v29 || v28 < v29 )
                  v27->m_flPos = (float)m_flPos;
                else
                  m_flPos = (int)v27->m_flPos;
                ++v25;
                --k;
              }
              while ( k != 0 );
            }
            v26->InvalidateLayout(this: v26, a2: false, a3: false);
            v2 = v39;
          }
        }
      }
LABEL_56:
      v36 += 20;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < nSplitterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x006265C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Splitter::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Splitter::GetMessageMap(vgui::Splitter *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Splitter::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetMessageMap'::`2'::s_pMap;
  `vgui::Splitter::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Splitter");
  `vgui::Splitter::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006265F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Splitter::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Splitter::GetAnimMap(vgui::Splitter *this)
{
  return FindOrAddPanelAnimationMap(className: "Splitter");
}

//------------------------------------------------------------------------------
// Address: 0x00626600
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Splitter::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Splitter::GetKBMap(vgui::Splitter *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Splitter::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Splitter::GetKBMap'::`2'::s_pMap;
  `vgui::Splitter::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
  `vgui::Splitter::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00626670
// Name: private: void vgui::Splitter::RecreateSplitters(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Splitter::RecreateSplitters(vgui::Splitter *this, int nCount)
{
  int m_Size; // eax
  int v3; // edi
  int i; // esi
  vgui::SplitterChildPanel *m_pPanel; // eax
  vgui::SplitterHandle *m_pHandle; // eax
  int v7; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Splitters; // esi
  int v9; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v12; // ecx
  int v13; // eax
  vgui::SplitterChildPanel *v14; // eax
  vgui::SplitterChildPanel *v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ebx
  vgui::SplitterHandle *v19; // eax
  vgui::SplitterHandle *v20; // eax
  char pBuffer[512]; // [esp+Ch] [ebp-204h] BYREF
  vgui::Panel *parent; // [esp+20Ch] [ebp-4h]

  m_Size = this->m_Splitters.m_Size;
  parent = this;
  if ( m_Size > 0 )
  {
    v3 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      m_pPanel = this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel;
      if ( m_pPanel != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterChildPanel *, int))m_pPanel->dtr_Panel)(
          a1: this->m_Splitters.m_Memory.m_pMemory[v3].m_pPanel,
          a2: 1);
        this = (vgui::Splitter *)parent;
      }
      m_pHandle = this->m_Splitters.m_Memory.m_pMemory[v3].m_pHandle;
      if ( m_pHandle != nullptr )
      {
        ((void (__thiscall *)(vgui::SplitterHandle *, int))m_pHandle->dtr_Panel)(a1: m_pHandle, a2: 1);
        this = (vgui::Splitter *)parent;
      }
      ++v3;
    }
  }
  v7 = nCount;
  p_m_Splitters = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Splitters;
  v9 = 0;
  this->m_Splitters.m_Size = 0;
  if ( nCount + 1 > 0 )
  {
    do
    {
      V_snprintf(pDest: pBuffer, maxLen: 0x200u, pFormat: "child%d", v9);
      m_pMemory = (int)p_m_Splitters[1].m_pMemory;
      m_nAllocationCount = p_m_Splitters->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: p_m_Splitters,
          num: m_pMemory - m_nAllocationCount + 1);
      ++p_m_Splitters[1].m_pMemory;
      v12 = p_m_Splitters->m_pMemory;
      v13 = (int)p_m_Splitters[1].m_pMemory - m_pMemory - 1;
      p_m_Splitters[1].m_nAllocationCount = (int)p_m_Splitters->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v12[m_pMemory + 1],
          src: (unsigned __int8 *)&v12[m_pMemory],
          count: 20 * v13);
      v14 = (vgui::SplitterChildPanel *)MemAlloc_Alloc(nSize: 0x180u);
      if ( v14 != nullptr )
        v15 = vgui::SplitterChildPanel::SplitterChildPanel(this: v14, parent, panelName: pBuffer);
      else
        v15 = nullptr;
      v16 = m_pMemory;
      *(_DWORD *)&p_m_Splitters->m_pMemory[v16].m_Title.m_Id = v15;
      LOBYTE(p_m_Splitters->m_pMemory[v16].m_Right) = 0;
      ++v9;
      p_m_Splitters->m_pMemory[v16].m_ciFlags = 0;
    }
    while ( v9 < nCount + 1 );
    v7 = nCount;
  }
  v17 = 0;
  if ( v7 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = (vgui::SplitterHandle *)MemAlloc_Alloc(nSize: 0x15Cu);
      if ( v19 != nullptr )
        v20 = vgui::SplitterHandle::SplitterHandle(
                this: v19,
                (vgui::Splitter *)parent,
                name: "SplitterHandle",
                mode: (vgui::SplitterMode_t)parent[1]._vpanel,
                nIndex: v17);
      else
        v20 = nullptr;
      p_m_Splitters->m_pMemory[v18].m_Width = (int)v20;
      v20->MoveToFront(this: v20);
      ++v17;
      ++v18;
    }
    while ( v17 < nCount );
    v7 = nCount;
  }
  p_m_Splitters->m_pMemory[v7].m_Width = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00626820
// Name: public: vgui::Splitter::Splitter(class vgui::Panel __near *,char const __near *,enum vgui::SplitterMode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Splitter *__thiscall vgui::Splitter::Splitter(
        vgui::Splitter *this,
        vgui::Panel *parent,
        const char *name,
        vgui::SplitterMode_t mode,
        int nCount)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (vgui::Splitter_vtbl *)&vgui::Splitter::`vftable';
  if ( `vgui::Splitter::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "Splitter");
    v6->pfnClassName = vgui::Splitter::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "Splitter");
    v7->pfnClassName = vgui::Splitter::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::Splitter::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Splitter::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "Splitter");
    v8->pfnClassName = vgui::Splitter::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  this->m_Splitters.m_Memory.m_pMemory = nullptr;
  this->m_Splitters.m_Memory.m_nAllocationCount = 0;
  this->m_Splitters.m_Memory.m_nGrowSize = 0;
  this->m_Splitters.m_Size = 0;
  this->m_Splitters.m_pElements = nullptr;
  this->m_Mode = mode;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Splitter::RecreateSplitters(this, nCount);
  vgui::Splitter::EvenlyRespaceSplitters(this);
  return this;
}

} // namespace sceneviewer
