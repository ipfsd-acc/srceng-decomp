// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/propertypage.cpp
// Functions: 10
// ============================================================

#include "vgui2\vgui_controls\propertypage.h"

//------------------------------------------------------------------------------
// Address: 0x102D1F20
// Name: public: virtual vgui::PropertyPage::~PropertyPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::~PropertyPage(vgui::PropertyPage *this)
{
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D1F30
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, CDragDropHelperPanel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->_pageTab,
    pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x102D1F40
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1FE0
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x102D20A0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetData";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2130
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D21C0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageShow";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2250
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D22E0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PageTabActivated";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2380
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar();
  this->_pageTab.m_iPanelID = -1;
  return this;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1001A8C0
// Name: public: virtual void vgui::PropertyPage::OnPageHide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageHide(vgui::PropertyPage *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1004B0A0
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x1004B0B0
// Name: public: virtual vgui::PropertyPage::~PropertyPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::~PropertyPage(vgui::PropertyPage *this)
{
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004B0C0
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, vgui::Panel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->_pageTab, pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x1004B0D0
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B170
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x1004B280
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ResetData";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B310
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CConsolePanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ApplyChanges";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B3A0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageShow";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B430
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageHide";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B4C0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "PageTabActivated";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B560
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(a1: (int)&savedregs);
  this->_pageTab.m_iPanelID = -1;
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00630120
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x00630130
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, vgui::Panel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->_pageTab, pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x00630140
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006301E0
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00630250
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00630280
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x00630290
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006302F0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetData";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00630380
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00630410
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageShow";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006304A0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00630530
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PageTabActivated";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006305D0
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(a1: (int)&savedregs);
  this->_pageTab.m_iPanelID = -1;
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D1FC0
// Name: public: virtual vgui::PropertyPage::~PropertyPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::~PropertyPage(vgui::PropertyPage *this)
{
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D1FD0
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, CDragDropHelperPanel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->_pageTab,
    pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x102D2080
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, bool state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && !state )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x102D2140
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetData";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D21D0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2260
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageShow";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D22F0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2420
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        __m128i *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar();
  this->_pageTab.m_iPanelID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1031DB90
// Name: _dynamic_initializer_for__prop_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_crosshair__()
{
  ConCommand::ConCommand(
    this: &prop_crosshair,
    pName: "prop_crosshair",
    callback: Cmd_PropCrosshair_f,
    pHelpString: "Shows name for prop looking at",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__prop_crosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x103269F0
// Name: _dynamic_atexit_destructor_for__prop_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_crosshair__()
{
  ConCommand::~ConCommand(this: &prop_crosshair);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10319A70
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x10319A80
// Name: public: virtual vgui::PropertyPage::~PropertyPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::~PropertyPage(vgui::PropertyPage *this)
{
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10319A90
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, CDragDropHelperPanel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->_pageTab,
    pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x10319AA0
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319B40
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x10319BB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10319BE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x10319BF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10319C50
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetData";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319CE0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319D70
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageShow";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319E00
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319E90
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PageTabActivated";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319F30
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(a1: (int)&savedregs);
  this->_pageTab.m_iPanelID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10350469
// Name: protected: void CPropertyPage::AllocPSP(unsigned long)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::AllocPSP(CPropertyPage *this, unsigned int dwSize)
{
  unsigned int v2; // edi
  _PROPSHEETPAGEA *v4; // eax

  v2 = dwSize;
  if ( dwSize == 0 )
    v2 = 56;
  v4 = (_PROPSHEETPAGEA *)MemAlloc_Alloc(nSize: v2);
  this->m_pPSP = v4;
  if ( v4 == nullptr )
    AfxThrowMemoryException();
  memset(dst: (unsigned __int8 *)v4, value: 0, count: v2);
  this->m_pPSP->dwSize = v2;
}

//------------------------------------------------------------------------------
// Address: 0x103504E4
// Name: protected: struct DLGTEMPLATE const __near * CPropertyPage::InitDialogInfo(struct DLGTEMPLATE const __near *)
// Source: class_map
//------------------------------------------------------------------------------
const DLGTEMPLATE *__thiscall CPropertyPage::InitDialogInfo(CPropertyPage *this, const DLGTEMPLATE *pTemplate)
{
  AFX_MODULE_STATE *ModuleState; // eax

  CPropertyPage::Cleanup(this);
  this->m_pOccDialogInfo = (_AFX_OCC_DIALOG_INFO *)MemAlloc_Alloc(nSize: 0x10u);
  ModuleState = AfxGetModuleState();
  return ModuleState->m_pOccManager->PreCreateDialog(
           this: ModuleState->m_pOccManager,
           a2: this->m_pOccDialogInfo,
           a3: pTemplate);
}

//------------------------------------------------------------------------------
// Address: 0x1035051C
// Name: public: virtual int CPropertyPage::OnApply(void)
// Source: class_map
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::OnApply(CPropertyPage *this)
{
  this->OnOK(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10350528
// Name: public: virtual void CPropertyPage::OnReset(void)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::OnReset(CPropertyPage *this)
{
  this->OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10350530
// Name: public: virtual int CPropertyPage::OnSetActive(void)
// Source: class_map
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::OnSetActive(CPropertyPage *this)
{
  if ( this->m_bFirstSetActive != 0 )
    this->m_bFirstSetActive = 0;
  else
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035054C
// Name: public: virtual int CPropertyPage::OnKillActive(void)
// Source: class_map
//------------------------------------------------------------------------------
BOOL __thiscall CPropertyPage::OnKillActive(CPropertyPage *this)
{
  return CWnd::UpdateData(this, bSaveAndValidate: 1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035055A
// Name: public: virtual struct HWND__ __near * CPropertyPage::OnWizardFinishEx(void)
// Source: class_map
//------------------------------------------------------------------------------
HWND__ *__thiscall CPropertyPage::OnWizardFinishEx(CPropertyPage *this)
{
  return (HWND__ *)(this->OnWizardFinish(this) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10350568
// Name: protected: virtual int CPropertyPage::PreTranslateMessage(struct tagMSG __near *)
// Source: class_map
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::PreTranslateMessage(CPropertyPage *this, tagMSG *pMsg)
{
  CWnd::PreTranslateMessage(this, pMsg);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035057B
// Name: protected: struct HBRUSH__ __near * CPropertyPage::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: class_map
//------------------------------------------------------------------------------
CWnd *__thiscall CPropertyPage::OnCtlColor(CPropertyPage *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  int lResult; // [esp+4h] [ebp-4h] BYREF

  if ( CWnd::SendChildNotifyLastMsg(this: pWnd, pResult: &lResult) != 0 )
    return (CWnd *)lResult;
  else
    return CWnd::OnCtlColor(this, __formal: pDC, pWnd, a4: nCtlColor);
}

//------------------------------------------------------------------------------
// Address: 0x10350710
// Name: public: virtual struct CRuntimeClass __near * CPropertyPage::GetRuntimeClass(void)const
// Source: class_map
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPropertyPage::GetRuntimeClass(CPropertyPage *this)
{
  return &CPropertyPage::classCPropertyPage;
}

//------------------------------------------------------------------------------
// Address: 0x1035071C
// Name: protected: virtual struct AFX_MSGMAP const __near * CPropertyPage::GetMessageMap(void)const
// Source: class_map
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CPropertyPage::GetMessageMap(CPropertyPage *this)
{
  return &messageMap_19;
}

//------------------------------------------------------------------------------
// Address: 0x10350722
// Name: public: void CPropertyPage::SetModified(int)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::SetModified(CPropertyPage *this, int bChanged)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-Ch]

  if ( this->m_hWnd != nullptr )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    m_hWnd = this->m_hWnd;
    if ( bChanged != 0 )
      SendMessageA(hWnd: v4->m_hWnd, Msg: 0x468u, wParam: (WPARAM)m_hWnd, lParam: 0);
    else
      SendMessageA(hWnd: v4->m_hWnd, Msg: 0x46Du, wParam: (WPARAM)m_hWnd, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10350763
// Name: public: virtual int CPropertyPage::OnWizardFinish(void)
// Source: class_map
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::OnWizardFinish(CPropertyPage *this)
{
  int v2; // edi
  HWND Parent; // eax
  CWnd *v4; // eax
  CObject *v5; // eax

  v2 = 0;
  if ( CWnd::UpdateData(this, bSaveAndValidate: 1) != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    v5 = AfxDynamicDownCast(pClass: &CPropertySheet::classCPropertySheet, pObject: v4);
    if ( v5 != nullptr && v5[50].__vftable != nullptr && ((int)v5[30].__vftable & 0x1000020) != 0 )
      PostMessageA(hWnd: (HWND)v5[8].__vftable, Msg: 0, wParam: 0, lParam: 0);
    return 1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x103507BB
// Name: protected: long CPropertyPage::MapWizardResult(long)
// Source: class_map
//------------------------------------------------------------------------------
const char *__thiscall CPropertyPage::MapWizardResult(CPropertyPage *this, const char *lToMap)
{
  const char *result; // eax
  int v3; // ebx
  HWND Parent; // eax
  CWnd *v5; // eax
  CObject *v6; // eax
  CPropertySheet *v7; // esi
  CObject_vtbl *v8; // edi

  result = lToMap;
  if ( lToMap != (const char *)-1 )
  {
    v3 = 0;
    if ( lToMap != nullptr )
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      v5 = CWnd::FromHandle(hWnd: Parent);
      v6 = AfxDynamicDownCast(pClass: &CPropertySheet::classCPropertySheet, pObject: v5);
      v7 = (CPropertySheet *)v6;
      if ( v6 != nullptr && (v8 = v6[37].__vftable, (int)v6[44].__vftable > 0) )
      {
        while ( CPropertySheet::GetPage(this: v7, nPage: v3)->m_pPSP->pszTemplate != lToMap )
        {
          v8 = (CObject_vtbl *)((char *)v8 + (unsigned int)v8->GetRuntimeClass);
          if ( ++v3 >= v7->m_pages.m_nSize )
            return lToMap;
        }
        return (const char *)v8[1].GetRuntimeClass;
      }
      else
      {
        return lToMap;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10350831
// Name: protected: virtual int CPropertyPage::OnNotify(unsigned int,long,long __near *)
// Source: class_map
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::OnNotify(CPropertyPage *this, unsigned int wParam, tagNMHDR *lParam, int *pResult)
{
  HWND Parent; // eax
  CWnd *v7; // eax
  CObject *v8; // eax
  int v9; // eax
  int v10; // eax
  const char *v11; // eax

  if ( CWnd::OnNotify(this, __formal: wParam, lParam, pResult) != 0 )
    return 1;
  if ( lParam->hwndFrom == this->m_hWnd || lParam->hwndFrom == GetParent(hWnd: this->m_hWnd) )
  {
    switch ( lParam->code )
    {
      case 0xFFFFFF2F:
        v10 = this->OnQueryCancel(this);
        goto LABEL_13;
      case 0xFFFFFF30:
        v9 = (int)this->OnWizardFinishEx(this);
        goto LABEL_11;
      case 0xFFFFFF31:
        v11 = (const char *)this->OnWizardNext(this);
        goto LABEL_18;
      case 0xFFFFFF32:
        v11 = (const char *)this->OnWizardBack(this);
LABEL_18:
        v9 = (int)CPropertyPage::MapWizardResult(this, lToMap: v11);
        goto LABEL_11;
      case 0xFFFFFF33:
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 0xE146u, lParam: 0);
        return 1;
      case 0xFFFFFF35:
        this->OnReset(this);
        return 1;
      case 0xFFFFFF36:
        v9 = this->OnApply(this) != 0 ? 0 : 2;
        goto LABEL_11;
      case 0xFFFFFF37:
        v10 = this->OnKillActive(this);
LABEL_13:
        v9 = v10 == 0;
        goto LABEL_11;
      case 0xFFFFFF38:
        Parent = GetParent(hWnd: this->m_hWnd);
        v7 = CWnd::FromHandle(hWnd: Parent);
        v8 = AfxDynamicDownCast(pClass: &CPropertySheet::classCPropertySheet, pObject: v7);
        if ( v8 == nullptr || ((int)v8[22].__vftable & 0x10) != 0 || v8[50].__vftable != nullptr )
        {
          v9 = (this->OnSetActive(this) != 0) - 1;
LABEL_11:
          *pResult = v9;
        }
        else
        {
          *pResult = -1;
        }
        break;
      default:
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10351521
// Name: public: virtual CPropertyPage::~CPropertyPage(void)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::~CPropertyPage(CPropertyPage *this)
{
  this->__vftable = (CPropertyPage_vtbl *)&CPropertyPage::`vftable';
  free(pMem: (void *)this->m_pPSP);
  CPropertyPage::Cleanup(this);
  if ( this->m_hDialogTemplate != nullptr )
    GlobalFree(hMem: this->m_hDialogTemplate);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strHeaderSubTitle.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strHeaderTitle.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCaption.m_pszData - 1);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10351681
// Name: protected: void CPropertyPage::PreProcessPageTemplate(struct _PROPSHEETPAGEA __near &,int)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::PreProcessPageTemplate(CPropertyPage *this, _PROPSHEETPAGEA *psp, int bWizard)
{
  const DLGTEMPLATE *pResource; // edi
  HRSRC ResourceA; // eax
  HGLOBAL Resource; // eax
  DLGTEMPLATE *hTemplate; // [esp+14h] [ebp+8h]

  if ( (psp->dwFlags & 1) != 0 )
  {
    pResource = psp->pResource;
  }
  else
  {
    ResourceA = FindResourceA(hModule: psp->hInstance, lpName: psp->pszTemplate, lpType: (LPCSTR)5);
    if ( ResourceA == nullptr )
      AfxThrowResourceException();
    Resource = LoadResource(hModule: psp->hInstance, hResInfo: ResourceA);
    if ( Resource == nullptr )
      AfxThrowResourceException();
    pResource = (const DLGTEMPLATE *)LockResource(hResData: Resource);
    if ( pResource == nullptr )
      AfxThrowResourceException();
  }
  if ( AfxGetModuleState()->m_pOccManager != nullptr )
    pResource = CPropertyPage::InitDialogInfo(this, pTemplate: pResource);
  hTemplate = _AfxChangePropPageFont(pTemplate: pResource, bWizard);
  if ( this->m_hDialogTemplate != nullptr )
  {
    GlobalFree(hMem: this->m_hDialogTemplate);
    this->m_hDialogTemplate = nullptr;
  }
  if ( hTemplate != nullptr )
  {
    pResource = hTemplate;
    this->m_hDialogTemplate = (void *)hTemplate;
  }
  psp->dwFlags |= 1u;
  psp->pszTemplate = (const char *)pResource;
}

//------------------------------------------------------------------------------
// Address: 0x10351A76
// Name: protected: void CPropertyPage::CommonConstruct(char const __near *,unsigned int)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::CommonConstruct(
        CPropertyPage *this,
        const char *lpszTemplateName,
        unsigned int nIDCaption)
{
  this->m_pPSP->dwFlags = 128;
  if ( lpszTemplateName != nullptr )
    this->m_pPSP->hInstance = AfxGetModuleState()->m_hCurrentResourceHandle;
  this->m_pPSP->pszTemplate = lpszTemplateName;
  this->m_pPSP->pfnDlgProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))AfxDlgProc;
  this->m_pPSP->lParam = (int)this;
  this->m_pPSP->pfnCallback = AfxPropPageCallback;
  if ( nIDCaption != 0 )
  {
    if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: &this->m_strCaption,
           nID: nIDCaption) == nullptr )
      AfxThrowInvalidArgException();
    this->m_pPSP->pszTitle = this->m_strCaption.m_pszData;
    this->m_pPSP->dwFlags |= 8u;
  }
  if ( AfxHelpEnabled() != 0 )
    this->m_pPSP->dwFlags |= 0x20u;
  if ( ((unsigned int)lpszTemplateName & 0xFFFF0000) == 0 )
    this->m_nIDHelp = (unsigned __int16)lpszTemplateName;
  this->m_lpszTemplateName = this->m_pPSP->pszTemplate;
  this->m_bFirstSetActive = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10351B45
// Name: public: CPropertyPage::CPropertyPage(unsigned int,unsigned int,unsigned long)
// Source: class_map
//------------------------------------------------------------------------------
CPropertyPage *__thiscall CPropertyPage::CPropertyPage(
        CPropertyPage *this,
        unsigned __int16 nIDTemplate,
        unsigned int nIDCaption,
        unsigned int dwSize)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v6; // eax
  CAfxStringMgr *v7; // eax

  CDialog::CDialog(this);
  this->__vftable = (CPropertyPage_vtbl *)&CPropertyPage::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCaption, pStringMgr: StringManager);
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strHeaderTitle, pStringMgr: v6);
  v7 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strHeaderSubTitle, pStringMgr: v7);
  CPropertyPage::AllocPSP(this, dwSize);
  CPropertyPage::CommonConstruct(this, lpszTemplateName: (const char *)nIDTemplate, nIDCaption);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10351BC7
// Name: public: CPropertyPage::CPropertyPage(void)
// Source: class_map
//------------------------------------------------------------------------------
CPropertyPage *__thiscall CPropertyPage::CPropertyPage(CPropertyPage *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax

  CDialog::CDialog(this);
  this->__vftable = (CPropertyPage_vtbl *)&CPropertyPage::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCaption, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strHeaderTitle, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strHeaderSubTitle, pStringMgr: v4);
  CPropertyPage::AllocPSP(this, dwSize: 0);
  CPropertyPage::CommonConstruct(this, lpszTemplateName: nullptr, nIDCaption: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103505AE
// Name: int AfxPropSheetCallback(struct HWND__ __near *,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxPropSheetCallback(HWND__ *__formal, unsigned int message, unsigned int *lParam)
{
  _AFX_THREAD_STATE *ThreadState; // eax
  unsigned int *v5; // edi
  _AFX_THREAD_STATE *v6; // esi
  unsigned int m_dwPropStyle; // eax
  unsigned int v8; // eax

  if ( message != 2 )
    return 0;
  ThreadState = AfxGetThreadState();
  v5 = lParam;
  v6 = ThreadState;
  if ( *lParam == ThreadState->m_dwPropStyle && lParam[1] == ThreadState->m_dwPropExStyle )
    return 0;
  VirtualProtect(lpAddress: lParam, dwSize: 0x12u, flNewProtect: 4u, lpflOldProtect: &message);
  m_dwPropStyle = v6->m_dwPropStyle;
  if ( (*(_BYTE *)v5 & 0x40) != 0 )
    v8 = m_dwPropStyle | 0x40;
  else
    v8 = m_dwPropStyle & 0xFFFFFFBF;
  *v5 = v8;
  v5[1] = v6->m_dwPropExStyle;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035159B
// Name: struct DLGTEMPLATE __near * _AfxChangePropPageFont(struct DLGTEMPLATE const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DLGTEMPLATE *__stdcall _AfxChangePropPageFont(const DLGTEMPLATE *pTemplate, int bWizard)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v4; // eax
  void *v5; // esi
  CDialogTemplate dlgTemplate; // [esp+10h] [ebp-28h] BYREF
  int wSizeDefault; // [esp+1Ch] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFace; // [esp+20h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFaceDefault; // [esp+24h] [ebp-14h] BYREF
  unsigned __int16 wSize[6]; // [esp+28h] [ebp-10h] BYREF
  int v11; // [esp+34h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFaceDefault, pStringMgr: StringManager);
  v11 = 0;
  if ( !AfxGetPropSheetFont(strFace: &strFaceDefault, wSize: (unsigned __int16 *)&wSizeDefault, bWizard) )
    goto LABEL_2;
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFace, pStringMgr: v4);
  LOBYTE(v11) = 1;
  if ( CDialogTemplate::GetFont(pTemplate, &strFace, nFontSize: wSize) != 0
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
         this: &strFace,
         psz: strFaceDefault.m_pszData) == 0
    && wSize[0] == (_WORD)wSizeDefault )
  {
    ATL::CStringData::Release(this: (ATL::CStringData *)strFace.m_pszData - 1);
LABEL_2:
    ATL::CStringData::Release(this: (ATL::CStringData *)strFaceDefault.m_pszData - 1);
    return nullptr;
  }
  CDialogTemplate::CDialogTemplate(this: &dlgTemplate, pTemplate);
  LOBYTE(v11) = 2;
  CDialogTemplate::SetFont(this: &dlgTemplate, lpFaceName: strFaceDefault.m_pszData, nFontSize: wSizeDefault);
  v5 = CDialogTemplate::Detach(this: &dlgTemplate);
  LOBYTE(v11) = 1;
  CDialogTemplate::~CDialogTemplate(this: &dlgTemplate);
  ATL::CStringData::Release(this: (ATL::CStringData *)strFace.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strFaceDefault.m_pszData - 1);
  return (DLGTEMPLATE *)v5;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00470400
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x00470410
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, CDragDropHelperPanel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->_pageTab,
    pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x00470420
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004704C0
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, bool state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && !state )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00470540
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470570
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x00470580
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004705E0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetData";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470670
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CConsolePanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470700
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageShow";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470790
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470820
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PageTabActivated";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004708C0
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(a1: (int)&savedregs);
  this->_pageTab.m_iPanelID = -1;
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00626930
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x00626940
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, vgui::Panel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->_pageTab, pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x00626950
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006269F0
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00626A50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00626A80
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x00626A90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00626AF0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetData";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626B80
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626C10
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageShow";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626CA0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626D30
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PageTabActivated";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626DD0
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(a1: (int)&savedregs);
  this->_pageTab.m_iPanelID = -1;
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1004D7C0
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x1004D7D0
// Name: public: virtual vgui::PropertyPage::~PropertyPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::~PropertyPage(vgui::PropertyPage *this)
{
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004D7E0
// Name: public: virtual void vgui::PropertyPage::OnPageHide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageHide(vgui::PropertyPage *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1004D7F0
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, CDragDropHelperPanel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->_pageTab,
    pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x1004D800
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D8A0
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x1004D9C0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ResetData";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DA50
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ApplyChanges";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DAE0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageShow";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DB70
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageHide";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DC00
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "PageTabActivated";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DCA0
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(a1: (int)&savedregs);
  this->_pageTab.m_iPanelID = -1;
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00459A30
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x00459A50
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, vgui::Panel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->_pageTab, pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x00459A60
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459B00
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00459B70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459BA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x00459BB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459C10
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ResetData";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459CA0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ApplyChanges";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459D30
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageShow";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459DC0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageHide";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459E50
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "PageTabActivated";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459EF0
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(a1: (int)&savedregs);
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(a1: (int)&savedregs);
  this->_pageTab.m_iPanelID = -1;
  return this;
}

} // namespace vp4

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103BE780
// Name: public: virtual vgui::PropertyPage::~PropertyPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::~PropertyPage(vgui::PropertyPage *this)
{
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BE790
// Name: protected: virtual void vgui::PropertyPage::OnPageTabActivated(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnPageTabActivated(vgui::PropertyPage *this, vgui::Panel *pageTab)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->_pageTab, pPanel: pageTab);
}

//------------------------------------------------------------------------------
// Address: 0x103BE7A0
// Name: public: virtual void vgui::PropertyPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::OnKeyCodeTyped(vgui::PropertyPage *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  if ( code == KEY_LEFT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v4->HasFocus(this: v4) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_LEFT);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    if ( vgui::PHandle::Get(this: &this->_pageTab) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &this->_pageTab);
      if ( v3->HasFocus(this: v3) )
        vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_RIGHT);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BE840
// Name: public: virtual void vgui::PropertyPage::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyPage::SetVisible(vgui::PropertyPage *this, int state)
{
  vgui::FocusNavGroup *v3; // eax
  vgui::FocusNavGroup *v4; // eax

  if ( this->IsVisible(this) && (_BYTE)state == 0 )
  {
    v3 = this->GetFocusNavGroup(this);
    if ( v3->GetCurrentDefaultButton(this: v3) != 0 )
    {
      v4 = this->GetFocusNavGroup(this);
      v4->SetCurrentDefaultButton(this: v4, a2: 0, a3: true);
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x103BE8D0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSaveGamePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ResetData";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BE960
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CCvarSlider::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BE9F0
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageShow";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BEA80
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BEB10
// Name: public: static void vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PageTabActivated";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BEBB0
// Name: public: vgui::PropertyPage::PropertyPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyPage *__thiscall vgui::PropertyPage::PropertyPage(
        vgui::PropertyPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (vgui::PropertyPage_vtbl *)&vgui::PropertyPage::`vftable';
  if ( `vgui::PropertyPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
    v4->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyPage");
    v5->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::PropertyPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
    v6->pfnClassName = vgui::PropertyPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::PropertyPage::PanelMessageFunc_OnResetData::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnApplyChanges::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnPageShow::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnPageHide::InitVar();
  vgui::PropertyPage::PanelMessageFunc_OnPageTabActivated::InitVar();
  this->_pageTab.m_iPanelID = -1;
  return this;
}

} // namespace client
