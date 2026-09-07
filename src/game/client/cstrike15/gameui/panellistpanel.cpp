// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/panellistpanel.cpp
// Functions: 23
// ============================================================

#include "game\client\cstrike15\gameui\panellistpanel.h"

//------------------------------------------------------------------------------
// Address: 0x101E57C0
// Name: public: static char const __near * CPanelListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPanelListPanel::GetPanelClassName()
{
  return "CPanelListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101E57D0
// Name: public: virtual void VScrollBarReversedButtons::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VScrollBarReversedButtons::ApplySchemeSettings(VScrollBarReversedButtons *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // ebx
  vgui::Button *v4; // esi
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  Color *v6; // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *); // edx
  Color *v8; // eax
  Color *(__thiscall *v9)(vgui::Panel *, Color *); // edx
  Color *v10; // eax
  vgui::Button *v11; // esi
  vgui::Button_vtbl *v12; // edi
  Color *v13; // eax
  vgui::Button_vtbl *v14; // edi
  Color *v15; // eax
  vgui::Button_vtbl *v16; // edi
  Color *v17; // ebx
  Color *v18; // eax
  Color v19; // [esp+Ch] [ebp-Ch] BYREF
  Color v20; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v21; // [esp+14h] [ebp-4h]

  v2 = pScheme;
  vgui::ScrollBar::ApplySchemeSettings(this, pScheme);
  v4 = this->GetButton(this, a2: 0);
  GetBgColor = v4->GetBgColor;
  pScheme = (vgui::IScheme *)v4->__vftable;
  v21 = (_DWORD *)GetBgColor(this: v4, result: &v20);
  v6 = v4->GetSchemeColor_2(this: v4, result: &v19, a3: "DimBaseText", a4: v2);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme[272].__vftable)(a1: v4, a2: *v6, a3: *v21);
  v7 = v4->GetBgColor;
  pScheme = (vgui::IScheme *)v4->__vftable;
  v21 = (_DWORD *)v7(this: v4, result: &v19);
  v8 = v4->GetSchemeColor_2(this: v4, result: &v20, a3: "DimBaseText", a4: v2);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme[273].__vftable)(a1: v4, a2: *v8, a3: *v21);
  v9 = v4->GetBgColor;
  pScheme = (vgui::IScheme *)v4->__vftable;
  v21 = (_DWORD *)v9(this: v4, result: &v19);
  v10 = v4->GetFgColor(this: v4, result: &v20);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme[271].__vftable)(a1: v4, a2: *v10, a3: *v21);
  v11 = this->GetButton(this, a2: 1);
  v12 = v11->__vftable;
  pScheme = (vgui::IScheme *)v11->GetBgColor(this: v11, result: &v19);
  v13 = v11->GetSchemeColor_2(this: v11, result: &v20, a3: "DimBaseText", a4: v2);
  ((void (__thiscall *)(vgui::Button *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: v11,
    a2: *v13,
    a3: pScheme->__vftable);
  v14 = v11->__vftable;
  pScheme = (vgui::IScheme *)v11->GetBgColor(this: v11, result: &v19);
  v15 = v11->GetSchemeColor_2(this: v11, result: &v20, a3: "DimBaseText", a4: v2);
  ((void (__thiscall *)(vgui::Button *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: v11,
    a2: *v15,
    a3: pScheme->__vftable);
  v16 = v11->__vftable;
  v17 = v11->GetBgColor(this: v11, result: (Color *)&pScheme);
  v18 = v11->GetFgColor(this: v11, result: &v19);
  ((void (__thiscall *)(vgui::Button *, _DWORD, _DWORD))v16->SetDefaultColor)(a1: v11, a2: *v18, a3: *v17);
}

//------------------------------------------------------------------------------
// Address: 0x101E5980
// Name: protected: virtual void CPanelListPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelListPanel::OnMouseWheeled(CPanelListPanel *this, int delta)
{
  int v3; // eax

  v3 = this->_vbar->GetValue(this: this->_vbar);
  this->_vbar->SetValue(this: this->_vbar, a2: v3 - 15 * delta);
}

//------------------------------------------------------------------------------
// Address: 0x101E59C0
// Name: public: virtual void CPanelListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelListPanel::ApplySchemeSettings(CPanelListPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  CPanelListPanel_vtbl *v4; // ebx
  int v5; // eax
  CPanelListPanel_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v4->SetBorder(this, a2: (vgui::IBorder *)v5);
  v6 = this->__vftable;
  v7 = this->GetBgColor(this, result: &pScheme);
  v8 = (_DWORD *)((int (__thiscall *)(CPanelListPanel *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v6->GetSchemeColor)(
                   a1: this,
                   a2: (Color *)v9,
                   a3: "Label.BgColor",
                   a4: *v7,
                   a5: v2);
  ((void (__thiscall *)(CPanelListPanel *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x101E5A60
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x101E5A70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E5AA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x101E5AB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E5AE0
// Name: public: virtual int CPanelListPanel::computeVPixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPanelListPanel::computeVPixelsNeeded(CPanelListPanel *this)
{
  int v2; // ebx
  int i; // esi
  CPanelListPanel::dataitem_s *v4; // eax
  vgui::Panel *panel; // eax
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  for ( i = 0; i < this->_dataItems.m_Size; ++i )
  {
    v4 = this->_dataItems.m_Memory.m_pMemory[i];
    if ( v4 != nullptr )
    {
      panel = v4->panel;
      if ( panel != nullptr )
      {
        vgui::Panel::GetSize(this: panel, wide: &w, tall: &h);
        v2 += h;
      }
    }
  }
  return v2 + 5;
}

//------------------------------------------------------------------------------
// Address: 0x101E5B40
// Name: public: virtual class vgui::Panel __near * CPanelListPanel::GetCellRenderer(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CPanelListPanel::GetCellRenderer(CPanelListPanel *this, int row)
{
  CPanelListPanel::dataitem_s *v2; // eax

  v2 = this->_dataItems.m_Memory.m_pMemory[row];
  if ( v2 != nullptr )
    return v2->panel;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E5B60
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x101E5B70
// Name: public: virtual class vgui::Panel __near * CPanelListPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CPanelListPanel::GetItem(CPanelListPanel *this, int itemIndex)
{
  if ( itemIndex < 0 || itemIndex >= this->_dataItems.m_Size )
    return nullptr;
  else
    return this->_dataItems.m_Memory.m_pMemory[itemIndex]->panel;
}

//------------------------------------------------------------------------------
// Address: 0x101E5BA0
// Name: protected: virtual void CPanelListPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelListPanel::PerformLayout(CPanelListPanel *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  CPanelListPanel::dataitem_s *v6; // eax
  CPanelListPanel::dataitem_s *item; // [esp+Ch] [ebp-10h]
  int tall; // [esp+10h] [ebp-Ch] BYREF
  int y; // [esp+14h] [ebp-8h]
  int wide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = this->computeVPixelsNeeded(this);
  this->_vbar->SetVisible(this: this->_vbar, a2: true);
  v3 = 0;
  this->_vbar->SetEnabled(this: this->_vbar, a2: false);
  this->_vbar->SetRange(this: this->_vbar, a2: 0, a3: v2 - tall + 24);
  this->_vbar->SetRangeWindow(this: this->_vbar, a2: 24);
  this->_vbar->SetButtonPressedScrollValue(this: this->_vbar, a2: 24);
  vgui::Panel::SetPos(this: this->_vbar, x: wide - 20, y: this->_sliderYOffset);
  vgui::Panel::SetSize(this: this->_vbar, wide: 18, tall: tall - this->_sliderYOffset - 2);
  this->_vbar->InvalidateLayout(this: this->_vbar, a2: false, a3: false);
  v4 = this->_vbar->GetValue(this: this->_vbar);
  vgui::Panel::SetPos(this: this->_embedded, x: 0, y: -v4);
  vgui::Panel::SetSize(this: this->_embedded, wide: wide - 20, tall: v2);
  y = 0;
  v5 = 0;
  if ( this->_dataItems.m_Size > 0 )
  {
    do
    {
      v6 = this->_dataItems.m_Memory.m_pMemory[v3];
      item = v6;
      if ( v6 != nullptr && v6->panel != nullptr )
      {
        v5 = vgui::Panel::GetTall(this: v6->panel);
        vgui::Panel::SetBounds(this: item->panel, x: 8, y, wide: wide - 36, tall: v5);
      }
      y += v5;
      ++v3;
    }
    while ( v3 < this->_dataItems.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5D00
// Name: public: virtual void CPanelListPanel::DeleteAllItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelListPanel::DeleteAllItems(CPanelListPanel *this)
{
  int i; // edi
  CPanelListPanel::dataitem_s **m_pMemory; // eax
  bool v4; // zf
  CPanelListPanel::dataitem_s **v5; // eax
  vgui::Panel *panel; // ecx

  for ( i = 0; i < this->_dataItems.m_Size; ++i )
  {
    m_pMemory = this->_dataItems.m_Memory.m_pMemory;
    v4 = m_pMemory[i] == nullptr;
    v5 = &m_pMemory[i];
    if ( !v4 )
    {
      panel = (*v5)->panel;
      if ( panel != nullptr )
        ((void (__thiscall *)(vgui::Panel *, int))panel->dtr_Panel)(a1: panel, a2: 1);
    }
    C_BaseEntity::operator delete(pMem: this->_dataItems.m_Memory.m_pMemory[i]);
  }
  this->_dataItems.m_Size = 0;
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101E5D70
// Name: public: virtual struct vgui::PanelMessageMap __near * CPanelListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPanelListPanel::GetMessageMap(CPanelListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPanelListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPanelListPanel::GetMessageMap'::`2'::s_pMap;
  `CPanelListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPanelListPanel");
  `CPanelListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E5DA0
// Name: public: virtual struct PanelAnimationMap __near * CPanelListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPanelListPanel::GetAnimMap(CPanelListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPanelListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101E5DB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPanelListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPanelListPanel::GetKBMap(CPanelListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPanelListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPanelListPanel::GetKBMap'::`2'::s_pMap;
  `CPanelListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPanelListPanel");
  `CPanelListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E5DE0
// Name: public: virtual void CPanelListPanel::RemoveItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelListPanel::RemoveItem(CPanelListPanel *this, int itemIndex)
{
  CPanelListPanel::dataitem_s *v3; // edi

  v3 = this->_dataItems.m_Memory.m_pMemory[itemIndex];
  if ( v3->panel != nullptr )
    ((void (__thiscall *)(vgui::Panel *, int))v3->panel->dtr_Panel)(a1: v3->panel, a2: 1);
  C_BaseEntity::operator delete(pMem: v3);
  if ( this->_dataItems.m_Size - itemIndex - 1 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&this->_dataItems.m_Memory.m_pMemory[itemIndex],
      src: (unsigned __int8 *)&this->_dataItems.m_Memory.m_pMemory[itemIndex + 1],
      count: 4 * (this->_dataItems.m_Size - itemIndex - 1));
  --this->_dataItems.m_Size;
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101E5E60
// Name: public: static void CPanelListPanel::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPanelListPanel::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CPanelListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CPanelListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPanelListPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5F00
// Name: public: CPanelListPanel::CPanelListPanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPanelListPanel *__thiscall CPanelListPanel::CPanelListPanel(
        CPanelListPanel *this,
        vgui::Panel *parent,
        const char *panelName,
        bool inverseButtons)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBar *v8; // eax
  vgui::ScrollBar *v9; // edi
  vgui::ScrollBar *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (CPanelListPanel_vtbl *)&CPanelListPanel::`vftable';
  if ( `CPanelListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPanelListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPanelListPanel");
    v5->pfnClassName = CPanelListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CPanelListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPanelListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPanelListPanel");
    v6->pfnClassName = CPanelListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CPanelListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPanelListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPanelListPanel");
    v7->pfnClassName = CPanelListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CPanelListPanel::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  this->_dataItems.m_Memory.m_pMemory = nullptr;
  this->_dataItems.m_Memory.m_nAllocationCount = 0;
  this->_dataItems.m_Memory.m_nGrowSize = 0;
  this->_dataItems.m_Size = 0;
  this->_dataItems.m_pElements = nullptr;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  this->_sliderYOffset = 0;
  v8 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( inverseButtons )
  {
    v9 = v8;
    if ( v8 != nullptr )
    {
      vgui::ScrollBar::ScrollBar(this: v8, parent: this, panelName: "CPanelListPanelVScroll", vertical: true);
      v9->__vftable = (vgui::ScrollBar_vtbl *)&VScrollBarReversedButtons::`vftable';
      this->_vbar = v9;
    }
    else
    {
      this->_vbar = nullptr;
    }
  }
  else
  {
    if ( v8 != nullptr )
      v10 = vgui::ScrollBar::ScrollBar(this: v8, parent: this, panelName: "CPanelListPanelVScroll", vertical: true);
    else
      v10 = nullptr;
    this->_vbar = v10;
  }
  vgui::Panel::SetBounds(this: this->_vbar, x: 0, y: 0, wide: 20, tall: 20);
  this->_vbar->SetVisible(this: this->_vbar, a2: false);
  this->_vbar->AddActionSignalTarget_2(this: this->_vbar, a2: this);
  v11 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v11 != nullptr )
    v12 = vgui::Panel::Panel(this: v11, parent: this, panelName: "PanelListEmbedded");
  else
    v12 = nullptr;
  this->_embedded = v12;
  vgui::Panel::SetBounds(this: v12, x: 0, y: 0, wide: 20, tall: 20);
  this->_embedded->SetPaintBackgroundEnabled(this: this->_embedded, a2: false);
  this->_embedded->SetPaintBorderEnabled(this: this->_embedded, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E6120
// Name: public: virtual int CPanelListPanel::AddItem(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPanelListPanel::AddItem(CPanelListPanel *this, vgui::Panel *panel)
{
  _DWORD *v3; // edi
  int m_Size; // edx
  vgui::Dar<unsigned long> *p_dataItems; // ecx
  int result; // eax
  unsigned int *i; // esi

  this->InvalidateLayout(this, a2: false, a3: false);
  v3 = MemAlloc_Alloc(nSize: 4u);
  *v3 = panel;
  panel->SetParent_2(this: panel, a2: this->_embedded);
  m_Size = this->_dataItems.m_Size;
  p_dataItems = (vgui::Dar<unsigned long> *)&this->_dataItems;
  result = 0;
  if ( m_Size <= 0 )
    return vgui::Dar<unsigned long>::AddElement(this: p_dataItems, elem: (unsigned int)v3);
  for ( i = p_dataItems->m_Memory.m_pMemory; (_DWORD *)*i != v3; ++i )
  {
    if ( ++result >= m_Size )
      return vgui::Dar<unsigned long>::AddElement(this: p_dataItems, elem: (unsigned int)v3);
  }
  if ( result < 0 )
    return vgui::Dar<unsigned long>::AddElement(this: p_dataItems, elem: (unsigned int)v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103895E0
// Name: protected: virtual void CPanelListPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPanelListPanel::PaintBackground(vgui::ListPanel *this)
{
  vgui::Panel::PaintBackground(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B65D0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}
