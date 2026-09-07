// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/graphpanel.cpp
// Functions: 10
// ============================================================

#include "vgui2\vgui_controls\graphpanel.h"

//------------------------------------------------------------------------------
// Address: 0x102C8040
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x102C8050
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8060
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x102C8140
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C83E0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C8560
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C8590
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102C85A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C85D0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8630
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1004FA70
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1004FA80
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004FA90
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x1004FB10
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FDB0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF60
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1004FF70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004FFA0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10050000
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0042A310
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0042A320
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A330
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0042A3B0
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A6C0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042A840
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A870
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0042A880
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A8B0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A910
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042D660
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D7C0
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0042FB00
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430120
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430F30
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430FA0
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431440
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432820
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00433FF0
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00435590
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x00435BD0
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00436960
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004382D0
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B9C0
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0044BE10
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461C20
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00461D50
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461DB0
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1005A790
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1005A7A0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005A7B0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x1005A890
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AB30
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005ACB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005ACE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1005ACF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005AD20
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005AD80
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00606F20
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00606F30
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00606F40
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00606FC0
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00607260
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006073E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00607410
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00607420
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00607450
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x006074B0
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C8120
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x102C8130
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8220
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C84C0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, __m128i *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C8640
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C8670
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102C8680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C86B0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8710
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EDCD0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x102EDCE0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EDCF0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x102EDD70
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EE010
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EE190
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EE1C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102EE1D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EE200
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EE260
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100A63A0
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x100A6A00
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x100A7790
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9120
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3560
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x100B39B0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7830
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x100B7960
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC400
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100BC410
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BC420
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x100BC4A0
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC500
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC7A0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BC920
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BC950
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100BC960
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BC990
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BC9F0
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BF620
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100BF780
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x100C1AB0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2080
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2E90
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C2F00
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C33A0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4790
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x100C5F60
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0044A8B0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0044A8C0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044A8D0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0044A950
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044ABF0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044AD70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044ADA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0044ADB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044ADE0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044AE40
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00431E40
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00431E50
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00431E60
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00431EE0
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebp
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  void (__thiscall **p_DrawSetColor)(vgui::ISurface *, Color); // ebx
  Color *v8; // eax
  float value; // xmm3_4
  float v10; // xmm1_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *v13; // ebx
  int i; // ecx
  int v15; // eax
  float *p_value; // edx
  vgui::ISurface_vtbl *v17; // ebx
  int v18; // eax
  int v19; // eax
  float *v20; // ecx
  int v21; // [esp+0h] [ebp-34h]
  int v22; // [esp+4h] [ebp-30h]
  float flMinValue; // [esp+1Ch] [ebp-18h]
  vgui::ISurface *sampleSize; // [esp+24h] [ebp-10h]
  float v25; // [esp+2Ch] [ebp-8h]
  vgui::ISurface *v26; // [esp+30h] [ebp-4h] BYREF

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    flMinValue = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    sampleSize = g_pVGuiSurface;
    v25 = (float)Tall / (float)(this->m_flHighRange - this->m_flLowRange);
    p_DrawSetColor = &g_pVGuiSurface->DrawSetColor;
    v8 = this->GetFgColor(this, result: &v26);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))*p_DrawSetColor)(a1: sampleSize, a2: *v8);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    v10 = value;
    while ( v3 > 0 )
    {
      if ( m_Tail < 0 )
        break;
      if ( m_Tail >= this->m_Samples.m_Memory.m_nAllocationCount )
        break;
      if ( m_Tail > this->m_Samples.m_LastAlloc.index )
        break;
      m_pMemory = this->m_Samples.m_Memory.m_pMemory;
      if ( m_pMemory[m_Tail].m_Previous == m_Tail )
        break;
      v12 = 0.0;
      v13 = this->m_Samples.m_Memory.m_pMemory;
      v3 -= this->m_iGraphBarWidth + this->m_iGraphBarGapWidth;
      for ( i = m_pMemory[m_Tail].m_Previous; i >= 0; i = v13[v15].m_Previous )
      {
        if ( i >= this->m_Samples.m_Memory.m_nAllocationCount )
          break;
        if ( i > this->m_Samples.m_LastAlloc.index )
          break;
        v15 = i;
        if ( v13[i].m_Previous == i )
          break;
        p_value = &v13[m_Tail].m_Element.value;
        if ( value > *p_value )
          value = *p_value;
        if ( *p_value > v10 )
          v10 = *p_value;
        if ( *p_value > v12 )
          v12 = *p_value;
        if ( v13[v15].m_Element.sampleEnd <= flMinValue )
        {
          flMinValue = flMinValue - v4;
          break;
        }
        m_Tail = i;
      }
      v17 = g_pVGuiSurface->__vftable;
      v26 = g_pVGuiSurface;
      v22 = vgui::Panel::GetTall(this);
      v21 = v3 + this->m_iGraphBarWidth;
      v18 = vgui::Panel::GetTall(this);
      v17->DrawFilledRect(this: v26, a2: v3, a3: v18 - (int)(float)(v12 * v25), a4: v21, a5: v22);
    }
    if ( this->m_bUseDynamicRange )
    {
      v19 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v20 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v20 <= v10 )
        {
          ++v19;
          ++v20;
          if ( v19 >= this->m_RangeList.m_Size )
            goto LABEL_29;
        }
        v10 = this->m_RangeList.m_Memory.m_pMemory[v19];
      }
LABEL_29:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432180
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00432300
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432330
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00432340
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432370
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this@<ecx>, int a2@<ebp>)
{
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int> > *p_m_Samples; // esi

  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  p_m_Samples = &this->m_Samples;
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Samples->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Samples->m_Memory.m_pMemory);
      p_m_Samples->m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004323C0
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004350E0
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Iterator_t *p_m_LastAlloc; // ebp
  int m_nAllocationCount; // ecx
  int v7; // edi
  CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Iterator_t *v8; // eax
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx
  CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Iterator_t v10; // [esp+Fh] [ebp-1h] BYREF

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_20:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int8)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v10.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v10.index = (v7 > 0) - 1;
      v8 = &v10;
    }
    else
    {
      v8 = CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Next(
             this: &this->m_Memory,
             result: &v10,
             it: &this->m_LastAlloc);
    }
    result = v8->index;
    if ( result >= v7 )
    {
      if ( _executeCount_0 < 10 )
      {
        ++_executeCount_0;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_20;
  }
  if ( _executeCount >= 10 )
    return -1;
  ++_executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00435240
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_2 < 10 )
      {
        ++_executeCount_2;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004375B0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437B30
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438730
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v7; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    v5->m_Next = -1;
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004387A0
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00438B70
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  unsigned __int8 v8; // [esp+7h] [ebp-1h]

  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    v8 = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        v3 = m_Head;
        m_Next = this->m_Memory.m_pMemory[v3].m_Next;
        v5 = &this->m_Memory.m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::~CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>(this: &v5->m_Element.m_SortedTree);
        v5->m_Previous = v8;
        v6 = m_Next == 0xFF ? this->m_FirstFree : m_Next;
        v5->m_Next = v6;
        v8 = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439EE0
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_4 < 10 )
      {
        ++_executeCount_4;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0043A680
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B6C0
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v7; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    v5->m_Next = -1;
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD30
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x0043D420
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_6 < 10 )
      {
        ++_executeCount_6;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0043E170
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F8D0
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v7; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    v5->m_Next = -1;
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00452380
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_8 < 10 )
      {
        ++_executeCount_8;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00455230
// Name: public: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v4; // ecx
  int m_Tail; // eax

  result = CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this,
      elem: result);
    v4 = &this->m_Memory.m_pMemory[v3];
    v4->m_Next = -1;
    m_Tail = this->m_Tail;
    v4->m_Previous = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail == -1 )
    {
      ++this->m_ElementCount;
      this->m_Head = v3;
    }
    else
    {
      this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
      ++this->m_ElementCount;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00465500
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( _executeCount_10 < 10 )
      {
        ++_executeCount_10;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00465630
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465690
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465CA0
// Name: public: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v4; // eax
  int m_Tail; // ecx

  result = CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
      this,
      elem: result);
    v4 = &this->m_Memory.m_pMemory[v3];
    v4->m_Next = -1;
    m_Tail = this->m_Tail;
    v4->m_Previous = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail == -1 )
    {
      ++this->m_ElementCount;
      this->m_Head = v3;
    }
    else
    {
      this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
      ++this->m_ElementCount;
    }
    return v3;
  }
  return result;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063E5A0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0063E5B0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063E5C0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0063E6A0
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063E940
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063EAC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063EAF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0063EB00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063EB30
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063EB90
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10022680
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100227E0
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10024B00
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025120
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025F30
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025FA0
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026440
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A730
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x1003A880
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A8E0
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100594F0
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x10059B40
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x1005C170
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100630C0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100630D0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x100630E0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x10063160
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063400
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063580
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100635B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100635C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100635F0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10063650
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10064070
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x100647F0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100658A0
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006FFF0
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10070440
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10068BB0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10068BC0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10068BD0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x10068CB0
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068F50
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100690D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10069100
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10069110
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10069140
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100691A0
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0043A620
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0043A630
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043A640
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0043A6C0
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A960
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043AAE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043AB10
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0043AB20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043AB50
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043ABB0
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00483DB0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00483DC0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00483DD0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00483EB0
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebp
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  void (__thiscall **p_DrawSetColor)(vgui::ISurface *, Color); // ebx
  Color *v8; // eax
  float value; // xmm3_4
  float v10; // xmm1_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *v13; // ebx
  int i; // ecx
  int v15; // eax
  float *p_value; // edx
  vgui::ISurface_vtbl *v17; // ebx
  int v18; // eax
  int v19; // eax
  float *v20; // ecx
  int v21; // [esp+0h] [ebp-34h]
  int v22; // [esp+4h] [ebp-30h]
  float flMinValue; // [esp+1Ch] [ebp-18h]
  vgui::ISurface *sampleSize; // [esp+24h] [ebp-10h]
  float v25; // [esp+2Ch] [ebp-8h]
  vgui::ISurface *v26; // [esp+30h] [ebp-4h] BYREF

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    flMinValue = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    sampleSize = g_pVGuiSurface;
    v25 = (float)Tall / (float)(this->m_flHighRange - this->m_flLowRange);
    p_DrawSetColor = &g_pVGuiSurface->DrawSetColor;
    v8 = this->GetFgColor(this, result: &v26);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))*p_DrawSetColor)(a1: sampleSize, a2: *v8);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    v10 = value;
    while ( v3 > 0 )
    {
      if ( m_Tail < 0 )
        break;
      if ( m_Tail >= this->m_Samples.m_Memory.m_nAllocationCount )
        break;
      if ( m_Tail > this->m_Samples.m_LastAlloc.index )
        break;
      m_pMemory = this->m_Samples.m_Memory.m_pMemory;
      if ( m_pMemory[m_Tail].m_Previous == m_Tail )
        break;
      v12 = 0.0;
      v13 = this->m_Samples.m_Memory.m_pMemory;
      v3 -= this->m_iGraphBarWidth + this->m_iGraphBarGapWidth;
      for ( i = m_pMemory[m_Tail].m_Previous; i >= 0; i = v13[v15].m_Previous )
      {
        if ( i >= this->m_Samples.m_Memory.m_nAllocationCount )
          break;
        if ( i > this->m_Samples.m_LastAlloc.index )
          break;
        v15 = i;
        if ( v13[i].m_Previous == i )
          break;
        p_value = &v13[m_Tail].m_Element.value;
        if ( value > *p_value )
          value = *p_value;
        if ( *p_value > v10 )
          v10 = *p_value;
        if ( *p_value > v12 )
          v12 = *p_value;
        if ( v13[v15].m_Element.sampleEnd <= flMinValue )
        {
          flMinValue = flMinValue - v4;
          break;
        }
        m_Tail = i;
      }
      v17 = g_pVGuiSurface->__vftable;
      v26 = g_pVGuiSurface;
      v22 = vgui::Panel::GetTall(this);
      v21 = v3 + this->m_iGraphBarWidth;
      v18 = vgui::Panel::GetTall(this);
      v17->DrawFilledRect(this: v26, a2: v3, a3: v18 - (int)(float)(v12 * v25), a4: v21, a5: v22);
    }
    if ( this->m_bUseDynamicRange )
    {
      v19 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v20 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v20 <= v10 )
        {
          ++v19;
          ++v20;
          if ( v19 >= this->m_RangeList.m_Size )
            goto LABEL_29;
        }
        v10 = this->m_RangeList.m_Memory.m_pMemory[v19];
      }
LABEL_29:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484150
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004842D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484300
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00484310
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484340
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this@<ecx>, int a2@<ebp>)
{
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int> > *p_m_Samples; // esi

  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RangeList);
  p_m_Samples = &this->m_Samples;
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Samples->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Samples->m_Memory.m_pMemory);
      p_m_Samples->m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00484390
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00428F20
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00428F30
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428F40
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00428FC0
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429020
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429330
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(vgui::GraphPanel *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004294B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004294E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004294F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429520
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00429580
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042C1D0
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042C330
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0042E650
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EC70
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FA90
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042FFA0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431410
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00432BE0
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00434180
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x004347C0
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00435550
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436EC0
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A500
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00456EA0
// Name: protected: int CUtlLinkedList<class vgui::CItemButton __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::CItemButton __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00457C30
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468A90
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00468BC0
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0042C950
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0042C960
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042C970
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0042C9F0
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042CA50
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042CCF0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042CE70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042CEA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0042CEB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042CEE0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042CF40
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042FB80
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FCE0
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004315E0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432060
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432680
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433490
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433500
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004339A0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434E10
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00436660
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437C10
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x00438300
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0043A9A0
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044E2A0
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004570D0
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00457200
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103A26B0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x103A26C0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A26D0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x103A2750
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A29F0
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A2B70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A2BA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x103A2BB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A2BE0
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A2C40
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1039AAD0
// Name: public: static char const __near * vgui::GraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::GraphPanel::GetPanelClassName()
{
  return "GraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1039AAE0
// Name: protected: virtual void vgui::GraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::GraphPanel::PerformLayout(vgui::GraphPanel *this)
{
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039AAF0
// Name: protected: virtual void vgui::GraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::ApplySchemeSettings(vgui::GraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::GraphPanel_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::GraphPanel_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::GraphPanel_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "GraphPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::GraphPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x1039AB70
// Name: protected: virtual void vgui::GraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::Paint(vgui::GraphPanel *this)
{
  int m_Tail; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int Tall; // eax
  float v7; // xmm1_4
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  float value; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // ebx
  int m_Previous; // ecx
  float *p_value; // edx
  vgui::ISurface_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  float *v19; // ecx
  int v20; // [esp-10h] [ebp-38h]
  int v21; // [esp-Ch] [ebp-34h]
  vgui::ISurface_vtbl *v22; // [esp+4h] [ebp-24h] BYREF
  vgui::ISurface *v23; // [esp+8h] [ebp-20h]
  float barSizeMultiplier; // [esp+Ch] [ebp-1Ch]
  int x; // [esp+10h] [ebp-18h]
  float sampleSize; // [esp+14h] [ebp-14h]
  float maxValue; // [esp+18h] [ebp-10h]
  float flMinValue; // [esp+1Ch] [ebp-Ch]
  float resampleStart; // [esp+20h] [ebp-8h]
  float flMaxValue; // [esp+24h] [ebp-4h]

  if ( this->m_Samples.m_ElementCount != 0 )
  {
    m_Tail = this->m_Samples.m_Tail;
    v3 = vgui::Panel::GetWide(this) - this->m_iGraphBarGapWidth - this->m_iGraphBarWidth;
    v4 = this->m_flDomainSize
       / (float)(vgui::Panel::GetWide(this) / (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth));
    v5 = this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Element.sampleEnd - v4;
    sampleSize = v4;
    resampleStart = v5 - fmod(v5, v4);
    Tall = vgui::Panel::GetTall(this);
    v7 = this->m_flHighRange - this->m_flLowRange;
    GetFgColor = this->GetFgColor;
    x = (int)g_pVGuiSurface;
    LODWORD(maxValue) = &g_pVGuiSurface->DrawSetColor;
    barSizeMultiplier = (float)Tall / v7;
    v9 = (_DWORD *)GetFgColor(this, result: (Color *)&v22);
    (*(void (__thiscall **)(int, _DWORD))LODWORD(maxValue))(a1: x, a2: *v9);
    value = this->m_Samples.m_Memory.m_pMemory[this->m_Samples.m_Head].m_Element.value;
    flMinValue = value;
    v11 = value;
    flMaxValue = value;
    if ( v3 > 0 )
    {
      while ( m_Tail >= 0
           && m_Tail < this->m_Samples.m_Memory.m_nAllocationCount
           && m_Tail <= this->m_Samples.m_LastAlloc.index
           && this->m_Samples.m_Memory.m_pMemory[m_Tail].m_Previous != m_Tail )
      {
        v12 = 0.0;
        x = v3 - (this->m_iGraphBarWidth + this->m_iGraphBarGapWidth);
        m_pMemory = this->m_Samples.m_Memory.m_pMemory;
        m_Previous = m_pMemory[m_Tail].m_Previous;
        maxValue = 0.0;
        while ( m_Previous >= 0
             && m_Previous < this->m_Samples.m_Memory.m_nAllocationCount
             && m_Previous <= this->m_Samples.m_LastAlloc.index
             && m_pMemory[m_Previous].m_Previous != m_Previous )
        {
          p_value = &m_pMemory[m_Tail].m_Element.value;
          if ( value > *p_value )
            value = *p_value;
          if ( *p_value > v11 )
            v11 = *p_value;
          if ( *p_value > v12 )
            v12 = *p_value;
          if ( m_pMemory[m_Previous].m_Element.sampleEnd <= resampleStart )
          {
            resampleStart = resampleStart - sampleSize;
            break;
          }
          m_Tail = m_Previous;
          m_Previous = m_pMemory[m_Previous].m_Previous;
        }
        v23 = g_pVGuiSurface;
        v16 = g_pVGuiSurface->__vftable;
        maxValue = v12;
        flMaxValue = v11;
        flMinValue = value;
        v22 = v16;
        v21 = vgui::Panel::GetTall(this);
        v20 = x + this->m_iGraphBarWidth;
        v17 = vgui::Panel::GetTall(this);
        v3 = x;
        v22->DrawFilledRect(this: v23, a2: x, a3: v17 - (int)(float)(maxValue * barSizeMultiplier), a4: v20, a5: v21);
        v11 = flMaxValue;
        if ( v3 <= 0 )
          break;
        value = flMinValue;
      }
    }
    if ( this->m_bUseDynamicRange )
    {
      v18 = 0;
      if ( this->m_RangeList.m_Size > 0 )
      {
        v19 = this->m_RangeList.m_Memory.m_pMemory;
        while ( *v19 <= v11 )
        {
          ++v18;
          ++v19;
          if ( v18 >= this->m_RangeList.m_Size )
            goto LABEL_31;
        }
        v11 = this->m_RangeList.m_Memory.m_pMemory[v18];
      }
LABEL_31:
      this->m_flLowRange = 0.0;
      this->m_flHighRange = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039AE10
// Name: public: vgui::GraphPanel::GraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__thiscall vgui::GraphPanel::GraphPanel(
        vgui::GraphPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int> *m_pMemory; // edx

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::GraphPanel_vtbl *)&vgui::GraphPanel::`vftable';
  if ( `vgui::GraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
    v4->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "GraphPanel");
    v5->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::GraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::GraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
    v6->pfnClassName = vgui::GraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Samples.m_Memory.m_pMemory = nullptr;
  this->m_Samples.m_Memory.m_nAllocationCount = 0;
  this->m_Samples.m_Memory.m_nGrowSize = 0;
  this->m_Samples.m_LastAlloc.index = -1;
  m_pMemory = this->m_Samples.m_Memory.m_pMemory;
  this->m_Samples.m_Head = -1;
  this->m_Samples.m_Tail = -1;
  this->m_Samples.m_FirstFree = -1;
  this->m_Samples.m_ElementCount = 0;
  this->m_Samples.m_NumAlloced = 0;
  this->m_Samples.m_pElements = m_pMemory;
  this->m_RangeList.m_Memory.m_pMemory = nullptr;
  this->m_RangeList.m_Memory.m_nAllocationCount = 0;
  this->m_RangeList.m_Memory.m_nGrowSize = 0;
  this->m_RangeList.m_Size = 0;
  this->m_RangeList.m_pElements = nullptr;
  this->m_flDomainSize = 100.0;
  this->m_iGraphBarWidth = 2;
  this->m_iGraphBarGapWidth = 2;
  this->m_bMaxDomainSizeSet = false;
  this->m_flLowRange = 0.0;
  this->m_flHighRange = 1.0;
  this->m_bUseDynamicRange = true;
  *(_QWORD *)&this->m_flMaxDomainSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039AF90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::GraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::GraphPanel::GetMessageMap(vgui::GraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "GraphPanel");
  `vgui::GraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039AFC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::GraphPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::GraphPanel::GetAnimMap(vgui::GraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "GraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1039AFD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::GraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::GraphPanel::GetKBMap(vgui::GraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::GraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::GraphPanel::GetKBMap'::`2'::s_pMap;
  `vgui::GraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "GraphPanel");
  `vgui::GraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039B000
// Name: public: virtual vgui::GraphPanel::~GraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::GraphPanel::~GraphPanel(vgui::GraphPanel *this)
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RangeList);
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_Samples);
  if ( this->m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Samples.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Samples.m_Memory.m_pMemory);
      this->m_Samples.m_Memory.m_pMemory = nullptr;
    }
    this->m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039B060
// Name: Create_GraphPanel
// Source: json
//------------------------------------------------------------------------------
vgui::GraphPanel *__cdecl Create_GraphPanel()
{
  vgui::GraphPanel *v0; // eax

  v0 = (vgui::GraphPanel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return vgui::GraphPanel::GraphPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace server
