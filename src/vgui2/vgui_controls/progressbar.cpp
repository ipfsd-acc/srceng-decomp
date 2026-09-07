// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/progressbar.cpp
// Functions: 31
// ============================================================

#include "vgui2\vgui_controls\progressbar.h"

//------------------------------------------------------------------------------
// Address: 0x102BA890
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102BA8A0
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102BA8B0
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BA8D0
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x102BA8F0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102BA950
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAA70
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BABB0
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BABF0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x102BAC00
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x102BAC80
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)MemAlloc_Alloc(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102BAD10
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *m_pszDialogVar; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value: m_pszDialogVar);
}

//------------------------------------------------------------------------------
// Address: 0x102BAD60
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x102BAD90
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BADE0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAF30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BAF60
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102BAF70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BAFA0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetProgress";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x300000001LL;
    LODWORD(v4.m[2][2]) = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB040
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DialogVariables";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB0D0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar();
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar();
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BB1E0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BB2A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB2D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102BB2E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB350
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BB370
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1031F090
// Name: _dynamic_initializer_for__progress_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__progress_enable__()
{
  ConCommand::ConCommand(
    this: &progress_enable,
    pName: "progress_enable",
    callback: BaseUI_ProgressEnabled_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__progress_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10327210
// Name: _dynamic_atexit_destructor_for__progress_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__progress_enable__()
{
  ConCommand::~ConCommand(this: &progress_enable);
}

//------------------------------------------------------------------------------
// Address: 0x1031F0C0
// Name: _dynamic_initializer_for__g_EngineVGuiImp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EngineVGuiImp__()
{
  __int128 v1; // [esp+0h] [ebp-1Ch]

  *(_QWORD *)&v1 = 0;
  *((_QWORD *)&v1 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CEngineVGui>::CConCommandMemberAccessor<CEngineVGui>(
    this: &g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "debugsystemui",
    callback: (unsigned int)CEngineVGui::ToggleDebugSystemUI,
    pHelpString: "Show/hide the debug system UI.",
    flags: 0x4000,
    completionFunc: v1);
  *((_BYTE *)&g_EngineVGuiImp + 220) &= 0xF0u;
  g_EngineVGuiImp.m_ToggleDebugSystemUI_register.m_ConCommandAccessor.m_pOwner = &g_EngineVGuiImp;
  g_EngineVGuiImp.m_LoadingProgress.m_Memory.m_pMemory = nullptr;
  g_EngineVGuiImp.m_LoadingProgress.m_Memory.m_nAllocationCount = 0;
  g_EngineVGuiImp.m_LoadingProgress.m_Memory.m_nGrowSize = 0;
  g_EngineVGuiImp.m_LoadingProgress.m_Size = 0;
  g_EngineVGuiImp.m_LoadingProgress.m_pElements = nullptr;
  g_EngineVGuiImp.staticPanel = nullptr;
  g_EngineVGuiImp.staticClientDLLToolsPanel = nullptr;
  g_EngineVGuiImp.staticClientDLLPanel = nullptr;
  g_EngineVGuiImp.staticGameDLLPanel = nullptr;
  g_EngineVGuiImp.staticGameUIPanel = nullptr;
  g_EngineVGuiImp.staticGameUIBackgroundPanel = nullptr;
  g_EngineVGuiImp.staticEngineToolsPanel = nullptr;
  g_EngineVGuiImp.staticDebugSystemPanel = nullptr;
  g_EngineVGuiImp.staticSteamOverlayPanel = nullptr;
  g_EngineVGuiImp.staticFocusOverlayPanel = nullptr;
  g_EngineVGuiImp.staticTransitionPanel = nullptr;
  g_EngineVGuiImp.m_hGameUIInputContext = nullptr;
  g_EngineVGuiImp.m_hStaticGameUIModule = nullptr;
  g_EngineVGuiImp.m_GameUIFactory = nullptr;
  g_EngineVGuiImp.m_pVProfPanel = nullptr;
  g_EngineVGuiImp.m_bShowProgressDialog = false;
  g_EngineVGuiImp.m_pInputInternal = nullptr;
  g_EngineVGuiImp.m_ProgressBias = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_EngineVGuiImp__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F1C0
// Name: _dynamic_initializer_for____g_CreateCEngineVGuiIEngineVGui_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineVGuiIEngineVGui_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineVGuiIEngineVGui_reg,
           fn: (void *(__cdecl *)())EngineVGui,
           pName: "VEngineVGui001");
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x100548F0
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x10054900
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x10054910
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10054930
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x10054950
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x100549B0
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054AD0
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054C10
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054C50
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x10054C60
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x10054CE0
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10054D70
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x10054DC0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_8, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x10054DF0
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)(int)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054E40
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054F90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054FC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x10054FD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055000
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100550A0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055130
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10055240
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10055300
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055330
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x10055340
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100553B0
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100553D0
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0043B360
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043B370
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043B380
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043B3A0
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x0043B3C0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0043B420
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B540
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B680
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B6C0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x0043B6D0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0043B750
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0043B7E0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x0043B830
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x0043B860
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B8B0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BA00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BA30
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043BA40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BAB0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BB50
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BBE0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043BCF0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043BDB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BDE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043BDF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BE20
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043BE40
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1006ACE0
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x1006ACF0
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x1006AD00
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006AD20
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x1006AD40
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1006ADA0
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AEC0
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B000
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B040
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x1006B050
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x1006B0D0
// Name: public: static bool vgui::ProgressBar::ConstructTimeRemainingString(wchar_t __near *,int,float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __cdecl vgui::ProgressBar::ConstructTimeRemainingString(
        wchar_t *output,
        int outputBufferSizeInBytes,
        float startTime,
        float currentTime,
        float currentProgress,
        float lastProgressUpdateTime,
        bool addRemainingSuffix)
{
  float v7; // xmm1_4
  int v8; // esi
  int v9; // edi
  unsigned int v10; // edx
  int (__thiscall *ConvertANSIToUnicode)(ILocalize *, const char *, wchar_t *, int); // eax
  char *v12; // eax
  vgui::ILocalize_vtbl *v13; // esi
  int v14; // eax
  char *v16; // eax
  vgui::ILocalize_vtbl *v17; // esi
  int v18; // eax
  wchar_t unicodeSeconds[16]; // [esp+0h] [ebp-A0h] BYREF
  char unlocString[64]; // [esp+20h] [ebp-80h] BYREF
  wchar_t unicodeMinutes[16]; // [esp+60h] [ebp-40h] BYREF
  char minutesBuf[16]; // [esp+80h] [ebp-20h] BYREF
  char secondsBuf[16]; // [esp+90h] [ebp-10h] BYREF

  v7 = (float)((float)(lastProgressUpdateTime - startTime) / currentProgress)
     - (float)(lastProgressUpdateTime - startTime);
  *output = 0;
  v8 = (int)v7;
  if ( currentTime > lastProgressUpdateTime )
    v8 = (int)(float)((float)((float)(currentTime - startTime)
                            / (float)((float)(currentProgress / (float)(lastProgressUpdateTime - startTime))
                                    * (float)(currentTime - startTime)))
                    - (float)(lastProgressUpdateTime - startTime));
  if ( v8 == 0 )
    v8 = v7 > 0.0;
  v9 = 0;
  if ( v8 >= 60 )
  {
    v10 = v8 / 0x3Cu;
    v8 %= 0x3Cu;
    v9 = v10;
  }
  V_snprintf(pDest: minutesBuf, maxLen: 0x10u, pFormat: "%d", v9);
  V_snprintf(pDest: secondsBuf, maxLen: 0x10u, pFormat: "%d", v8);
  if ( v9 <= 0 )
  {
    if ( v8 <= 0 )
    {
      return 0;
    }
    else
    {
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: secondsBuf, a3: unicodeMinutes, a4: 32);
      v16 = "#vgui_TimeLeftSeconds";
      if ( v8 == 1 )
        v16 = "#vgui_TimeLeftSecond";
      V_strncpy(pDest: unlocString, pSrc: v16, maxLen: 64);
      if ( addRemainingSuffix )
        V_strncat(pDest: unlocString, pSrc: "Remaining", destBufferSize: 0x40u, max_chars_to_copy: -1);
      v17 = g_pVGuiLocalize->__vftable;
      v18 = ((int (__thiscall *)(vgui::ILocalize *, char *, int, wchar_t *))g_pVGuiLocalize->Find)(
              a1: g_pVGuiLocalize,
              a2: unlocString,
              a3: 1,
              a4: unicodeMinutes);
      ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v17->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: output,
        a3: outputBufferSizeInBytes,
        a4: v18);
      return 1;
    }
  }
  else
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: minutesBuf, a3: unicodeMinutes, a4: 32);
    ConvertANSIToUnicode = g_pVGuiLocalize->ConvertANSIToUnicode;
    *(_DWORD *)&secondsBuf[4] = 32;
    *(_DWORD *)secondsBuf = unicodeSeconds;
    ((void (__thiscall *)(vgui::ILocalize *, char *))ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: secondsBuf);
    v12 = "#vgui_TimeLeftMinutesSeconds";
    if ( v9 == 1 )
    {
      if ( v8 == 1 )
        v12 = "#vgui_TimeLeftMinuteSecond";
      else
        v12 = "#vgui_TimeLeftMinuteSeconds";
    }
    else if ( v8 == 1 )
    {
      v12 = "#vgui_TimeLeftMinutesSecond";
    }
    V_strncpy(pDest: unlocString, pSrc: v12, maxLen: 64);
    if ( addRemainingSuffix )
      V_strncat(pDest: unlocString, pSrc: "Remaining", destBufferSize: 0x40u, max_chars_to_copy: -1);
    v13 = g_pVGuiLocalize->__vftable;
    v14 = ((int (__thiscall *)(vgui::ILocalize *, char *, int, wchar_t *, wchar_t *))g_pVGuiLocalize->Find)(
            a1: g_pVGuiLocalize,
            a2: unlocString,
            a3: 2,
            a4: unicodeMinutes,
            a5: unicodeSeconds);
    ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v13->ConstructString_3)(
      a1: g_pVGuiLocalize,
      a2: output,
      a3: outputBufferSizeInBytes,
      a4: v14);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B2E0
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1006B370
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x1006B3C0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_7, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x1006B3F0
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B440
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B590
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B5C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1006B5D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B600
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B6A0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B730
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006B840
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006B900
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B930
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1006B940
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B9B0
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006B9D0
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00613420
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00613430
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00613440
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00613460
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x00613480
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x006134E0
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613600
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613740
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613780
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x00613790
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00613810
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)MemAlloc_Alloc(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x006138A0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x006138F0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x00613920
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613970
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00613AE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00613AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00613B20
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetProgress";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x300000001LL;
    LODWORD(v4.m[2][2]) = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613BC0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DialogVariables";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00613C50
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00613D60
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00613E20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00613E50
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00613E60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00613ED0
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00613EF0
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102BA960
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102BA970
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BA990
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x102BA9B0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102BAA10
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAB30
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAC70
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BACB0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x102BACC0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x102BAD40
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)MemAlloc_Alloc(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102BADD0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *m_pszDialogVar; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value: m_pszDialogVar);
}

//------------------------------------------------------------------------------
// Address: 0x102BAE20
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x102BAE50
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAEA0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAFE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB010
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102BB020
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB090
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetProgress";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x300000001LL;
    LODWORD(v4.m[2][2]) = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB130
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DialogVariables";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB1C0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        __m128i *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BB390
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB3C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102BB3D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB400
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BB420
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102FEF80
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102FEF90
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x102FEFA0
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  operator delete(p: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FEFC0
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x102FEFF0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102FF050
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF170
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF2B0
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF2F0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x102FF300
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x102FF380
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: &var);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    operator delete(p: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102FF410
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *m_pszDialogVar; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value: m_pszDialogVar);
}

//------------------------------------------------------------------------------
// Address: 0x102FF460
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_10, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_10;
}

//------------------------------------------------------------------------------
// Address: 0x102FF490
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF4E0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF620
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FF650
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102FF660
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FF6D0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetProgress";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x300000001LL;
    LODWORD(v4.m[2][2]) = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF770
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DialogVariables";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FF800
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102FF910
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102FF9D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FFA00
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x102FFA10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FFA40
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102FFA60
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1009A1D0
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x1009A1E0
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x1009A1F0
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009A210
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x1009A230
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1009A290
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A3B0
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A4F0
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A530
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x1009A540
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x1009A5C0
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: szDescription);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1009A650
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *m_pszDialogVar; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value: m_pszDialogVar);
}

//------------------------------------------------------------------------------
// Address: 0x1009A6A0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_3, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x1009A6D0
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A720
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A860
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A890
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1009A8A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A8D0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A970
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AA00
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009AB10
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009ABD0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009AC00
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1009AC10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009AC80
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009ACA0
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0045BA00
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0045BA10
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0045BA20
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045BA40
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x0045BA60
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0045BAC0
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BBE0
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BD20
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BD60
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x0045BD70
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0045BDF0
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0045BE80
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x0045BED0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_7, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x0045BF00
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BF50
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C0A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C0D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0045C0E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C110
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetProgress";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x300000001LL;
    LODWORD(v4.m[2][2]) = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C1B0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DialogVariables";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C240
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C350
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C410
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C440
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0045C450
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C4C0
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045C4E0
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00442810
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00442820
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00442830
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this@<ecx>, int a2@<ebp>)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00442850
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x00442870
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &v6, tall: &wide);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v7);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: v6, a5: wide);
}

//------------------------------------------------------------------------------
// Address: 0x004428D0
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi
  int v7; // [esp-1Ch] [ebp-20h]
  int v8; // [esp-18h] [ebp-1Ch]
  int v9; // [esp-14h] [ebp-18h]
  int v10; // [esp-10h] [ebp-14h]

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      v10 = tall - *y;
      v9 = *x + this->_segmentWide;
      v8 = *y;
      v7 = *x;
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      v10 = *y + this->_segmentWide;
      v9 = wide - *x;
      v8 = *y;
      v7 = *x;
LABEL_6:
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v7, a3: v8, a4: v9, a5: v10);
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004429F0
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int v7; // ecx
  vgui::ISurface *v8; // ebp
  void (__thiscall **p_DrawSetColor)(vgui::ISurface *, Color); // ebx
  Color *v10; // eax
  int tall; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int m_iBarMargin; // [esp+14h] [ebp-8h] BYREF
  _BYTE v15[4]; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &tall, tall: &y);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  m_iBarMargin = 0;
  x = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = tall - 2 * this->m_iBarMargin;
      m_iBarMargin = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      tall = v4;
      goto LABEL_7;
    case 1:
      v4 = tall - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      tall = v4;
      goto LABEL_6;
    case 2:
      v7 = this->m_iBarMargin;
      v4 = y - 2 * v7;
      m_iBarMargin = this->m_iBarInset;
      y = v4;
      x = v4 - v7;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = y - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      y = v4;
LABEL_6:
      m_iBarMargin = v5;
LABEL_7:
      x = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  v8 = g_pVGuiSurface;
  p_DrawSetColor = &g_pVGuiSurface->DrawSetColor;
  v10 = this->GetFgColor(this, result: v15);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))*p_DrawSetColor)(a1: v8, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, x: &m_iBarMargin, y: &x, tall: y, wide: tall);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442B40
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442B80
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x00442B90
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00442C10
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  const char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00442CA0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x00442CE0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_7, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x00442D10
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442D60
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &v6, tall: &wide);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v7);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)v6 * this->_progress),
        a5: wide);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)v6),
        a2: 0,
        a3: v6,
        a4: wide);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a3: v6,
        a4: wide);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: v6,
        a5: (int)(float)((float)wide * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442EB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00442EE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00442EF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00442F60
// Name: public: static void vgui::ProgressBar::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ProgressBar::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00442FE0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    vgui::ProgressBar::AddToMap(
      scriptname: "SetProgress",
      function: (unsigned int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)3,
      p1name: "progress",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443040
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    vgui::ProgressBar::AddToMap(
      scriptname: "DialogVariables",
      function: (unsigned int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)6,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004430A0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar();
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar();
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004431A0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00443260
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00443290
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x004432A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004432D0
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004432F0
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00649560
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00649570
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00649580
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x006495A0
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x006495C0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00649620
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649740
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649880
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x006498C0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x006498D0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00649950
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)MemAlloc_Alloc(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x006499E0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x00649A30
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_7, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x00649A60
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649AB0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649BE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00649C10
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00649C20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00649C50
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetProgress";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x300000001LL;
    LODWORD(v4.m[2][2]) = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649CF0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DialogVariables";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649D80
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00649E90
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00649F50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00649F80
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00649F90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064A000
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0064A020
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10067480
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x10067490
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x100674A0
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100674C0
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x100674E0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10067540
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067660
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100677A0
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100677E0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x100677F0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x10067870
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10067900
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x10067950
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x10067980
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100679D0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067B20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067B50
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x10067B60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067B90
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067C30
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067CC0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067DD0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067E90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067EC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x10067ED0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067F40
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10067F60
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10079B20
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x10079B30
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x10079B40
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10079B60
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x10079B80
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10079BE0
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079D00
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079E40
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079E80
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x10079E90
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x10079F10
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10079FA0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x10079FF0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x1007A020
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A070
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A1C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A1F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1007A200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A270
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A310
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A3A0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A4B0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A570
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A5A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x1007A5B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A5E0
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007A600
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0044B5A0
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0044B5B0
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0044B5C0
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044B5E0
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x0044B600
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0044B660
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B780
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B8C0
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B900
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x0044B910
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0044B990
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: &defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0044BA20
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x0044BA70
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_7, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x0044BAA0
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BAF0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BC30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044BC60
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0044BC70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044BCE0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BD80
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BE10
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044BF20
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044BFE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C010
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0044C020
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C050
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044C070
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00494750
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00494760
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00494770
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this@<ecx>, int a2@<ebp>)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00494790
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x004947B0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &v6, tall: &wide);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v7);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: v6, a5: wide);
}

//------------------------------------------------------------------------------
// Address: 0x00494810
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi
  int v7; // [esp-1Ch] [ebp-20h]
  int v8; // [esp-18h] [ebp-1Ch]
  int v9; // [esp-14h] [ebp-18h]
  int v10; // [esp-10h] [ebp-14h]

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      v10 = tall - *y;
      v9 = *x + this->_segmentWide;
      v8 = *y;
      v7 = *x;
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      v10 = *y + this->_segmentWide;
      v9 = wide - *x;
      v8 = *y;
      v7 = *x;
LABEL_6:
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v7, a3: v8, a4: v9, a5: v10);
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494930
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int v7; // ecx
  vgui::ISurface *v8; // ebp
  void (__thiscall **p_DrawSetColor)(vgui::ISurface *, Color); // ebx
  Color *v10; // eax
  int tall; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int m_iBarMargin; // [esp+14h] [ebp-8h] BYREF
  _BYTE v15[4]; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &tall, tall: &y);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  m_iBarMargin = 0;
  x = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = tall - 2 * this->m_iBarMargin;
      m_iBarMargin = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      tall = v4;
      goto LABEL_7;
    case 1:
      v4 = tall - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      tall = v4;
      goto LABEL_6;
    case 2:
      v7 = this->m_iBarMargin;
      v4 = y - 2 * v7;
      m_iBarMargin = this->m_iBarInset;
      y = v4;
      x = v4 - v7;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = y - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      y = v4;
LABEL_6:
      m_iBarMargin = v5;
LABEL_7:
      x = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  v8 = g_pVGuiSurface;
  p_DrawSetColor = &g_pVGuiSurface->DrawSetColor;
  v10 = this->GetFgColor(this, result: v15);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))*p_DrawSetColor)(a1: v8, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, x: &m_iBarMargin, y: &x, tall: y, wide: tall);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494A80
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494AC0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x00494AD0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x00494B50
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ProgressBar::ApplySettings(
        vgui::ProgressBar *this@<ecx>,
        int a2@<ebp>,
        KeyValues *inResourceData)
{
  const char *String; // eax
  const char *v5; // esi
  char *v6; // eax
  const char *v7; // ecx
  char *v8; // edx
  char v9; // al
  int v10; // [esp+4h] [ebp-Ch]
  BOOL v11; // [esp+8h] [ebp-8h]
  char *v12; // [esp+Ch] [ebp-4h]

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v5 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v6 = (char *)MemAlloc_Alloc(nSize: strlen(v5) + 1);
    this->m_pszDialogVar = v6;
    v7 = v5;
    v8 = v6;
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
    }
    while ( v9 != 0 );
  }
  vgui::Panel::ApplySettings(
    this,
    a2: (int)inResourceData,
    a3: a2,
    a4: (int)this,
    (int)inResourceData,
    a6: v10,
    a7: v11,
    nptr: v12);
}

//------------------------------------------------------------------------------
// Address: 0x00494BE0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x00494C20
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x00494C50
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494CA0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &v6, tall: &wide);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v7);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)v6 * this->_progress),
        a5: wide);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)v6),
        a2: 0,
        a3: v6,
        a4: wide);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a3: v6,
        a4: wide);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: v6,
        a5: (int)(float)((float)wide * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494DF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00494E20
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x00494E30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00494EA0
// Name: public: static void vgui::ProgressBar::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ProgressBar::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00494F20
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    vgui::ProgressBar::AddToMap(
      scriptname: "SetProgress",
      function: (unsigned int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)3,
      p1name: "progress",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494F80
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    vgui::ProgressBar::AddToMap(
      scriptname: "DialogVariables",
      function: (unsigned int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)6,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494FE0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar();
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar();
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004950E0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004951A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004951D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x004951E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495210
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495230
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00439F40
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00439F50
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x00439F60
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00439F80
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x00439FA0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0043A000
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A120
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A260
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A2A0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x0043A2B0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0043A330
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0043A3C0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x0043A410
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x0043A440
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A490
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A5E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A610
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043A620
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A650
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A6F0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A780
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A890
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A950
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A980
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043A990
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043AA00
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043AA20
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0043DA50
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043DA60
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043DA70
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043DA90
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x0043DAB0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0043DB10
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DC30
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DD70
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DDB0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x0043DDC0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x0043DE40
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  const char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: defaultValue);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0043DED0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x0043DF20
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x0043DF50
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DFA0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E0F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E120
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043E130
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E1A0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E240
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E2D0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043E3E0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043E4A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E4D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043E4E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E510
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043E530
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039ECE0
// Name: public: void vgui::ProgressBar::SetBarInset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetBarInset(vgui::ProgressBar *this, int pixels)
{
  this->m_iBarInset = pixels;
}

//------------------------------------------------------------------------------
// Address: 0x103B35D0
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x103B35E0
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x103B35F0
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  C_BaseEntity::operator delete(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B3610
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x103B3630
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103B3690
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B37B0
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B38F0
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B3930
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x103B3940
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x103B39C0
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: prType);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    C_BaseEntity::operator delete(pMem: this->m_pszDialogVar);
    v5 = (char *)MemAlloc_Alloc(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x103B3A50
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x103B3AA0
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x103B3AD0
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B3B20
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B3C60
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B3C90
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x103B3CA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B3D10
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetProgress";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x300000001LL;
    LODWORD(v4.m[2][2]) = "progress";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B3DB0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DialogVariables";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B3E40
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar();
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B3F50
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B4010
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B4040
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x103B4050
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B4080
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B40A0
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103AB950
// Name: public: static char const __near * vgui::ProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBar::GetPanelClassName()
{
  return "ProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x103AB960
// Name: public: static char const __near * vgui::ContinuousProgressBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ContinuousProgressBar::GetPanelClassName()
{
  return "ContinuousProgressBar";
}

//------------------------------------------------------------------------------
// Address: 0x103AB970
// Name: public: virtual vgui::ProgressBar::~ProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::~ProgressBar(vgui::ProgressBar *this)
{
  char *m_pszDialogVar; // [esp-4h] [ebp-8h]

  m_pszDialogVar = this->m_pszDialogVar;
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  free(pMem: m_pszDialogVar);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AB990
// Name: public: virtual void vgui::ProgressBar::SetSegmentInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetSegmentInfo(vgui::ProgressBar *this, int gap, int width)
{
  this->_segmentGap = gap;
  this->_segmentWide = width;
}

//------------------------------------------------------------------------------
// Address: 0x103AB9B0
// Name: protected: virtual void vgui::ProgressBar::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintBackground(vgui::ProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetBgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103ABA10
// Name: protected: void vgui::ProgressBar::PaintSegment(int __near &,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::PaintSegment(vgui::ProgressBar *this, int *x, int *y, int tall, int wide)
{
  int *v6; // edi

  switch ( this->m_iProgressDirection )
  {
    case 0:
      v6 = x;
      *x += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      goto LABEL_6;
    case 1:
      *x -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: *x + this->_segmentWide, a5: tall - *y);
      break;
    case 2:
      *y -= this->_segmentWide + this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
      break;
    case 3:
      v6 = y;
      *y += this->_segmentGap;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: *x, a3: *y, a4: wide - *x, a5: *y + this->_segmentWide);
LABEL_6:
      *v6 += this->_segmentWide;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ABB30
// Name: protected: virtual void vgui::ProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::Paint(vgui::ProgressBar *this)
{
  int m_iProgressDirection; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int m_iBarInset; // ecx
  int m_iBarMargin; // ecx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  vgui::ISurface_vtbl *v9; // ebx
  _DWORD *v10; // eax
  Color v11; // [esp+8h] [ebp-18h] BYREF
  vgui::ISurface *v12; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int tall; // [esp+18h] [ebp-8h] BYREF
  int wide; // [esp+1Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  m_iProgressDirection = this->m_iProgressDirection;
  v3 = 0;
  x = 0;
  y = 0;
  switch ( m_iProgressDirection )
  {
    case 0:
      v4 = wide - 2 * this->m_iBarMargin;
      x = this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_7;
    case 1:
      v4 = wide - 2 * this->m_iBarMargin;
      v5 = v4 - this->m_iBarMargin;
      m_iBarInset = this->m_iBarInset;
      wide = v4;
      goto LABEL_6;
    case 2:
      m_iBarMargin = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarMargin;
      x = this->m_iBarInset;
      tall = v4;
      y = v4 - m_iBarMargin;
      goto LABEL_8;
    case 3:
      m_iBarInset = this->m_iBarMargin;
      v4 = tall - 2 * m_iBarInset;
      v5 = this->m_iBarInset;
      tall = v4;
LABEL_6:
      x = v5;
LABEL_7:
      y = m_iBarInset;
LABEL_8:
      v3 = (int)(float)((float)(v4 / (this->_segmentGap + this->_segmentWide)) * this->_progress);
      break;
    default:
      break;
  }
  GetFgColor = this->GetFgColor;
  v9 = g_pVGuiSurface->__vftable;
  v12 = g_pVGuiSurface;
  v10 = (_DWORD *)GetFgColor(this, result: &v11);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v9->DrawSetColor)(a1: v12, a2: *v10);
  if ( v3 > 0 )
  {
    do
    {
      vgui::ProgressBar::PaintSegment(this, &x, &y, tall, wide);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ABC70
// Name: public: virtual void vgui::ProgressBar::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::SetProgress(vgui::ProgressBar *this, float progress)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  void (*Repaint)(void); // edx

  v2 = progress;
  if ( progress != this->_progress )
  {
    v3 = 0;
    if ( progress < 0.0 || (v3 = 1065353216, progress > 1.0) )
      v2 = *(float *)&v3;
    Repaint = (void (*)(void))this->Repaint;
    this->_progress = v2;
    Repaint();
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ABCB0
// Name: public: float vgui::ProgressBar::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall vgui::ProgressBar::GetProgress(vgui::ProgressBar *this)
{
  return this->_progress;
}

//------------------------------------------------------------------------------
// Address: 0x103ABCC0
// Name: protected: virtual void vgui::ProgressBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySchemeSettings(vgui::ProgressBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ProgressBar_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::ProgressBar_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::ProgressBar_vtbl *v8; // ebx
  int v9; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.FgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ProgressBar.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v8->SetBorder(this, a2: (vgui::IBorder *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x103ABD40
// Name: public: virtual void vgui::ProgressBar::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::ApplySettings(vgui::ProgressBar *this, KeyValues *inResourceData)
{
  char *String; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  this->_progress = KeyValues::GetFloat(this: inResourceData, keyName: "progress", defaultValue: 0.0);
  String = KeyValues::GetString(this: inResourceData, keyName: "variable", defaultValue: locale);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    free(pMem: this->m_pszDialogVar);
    v5 = (char *)operator new(nSize: strlen(v4) + 1);
    this->m_pszDialogVar = v5;
    v6 = v4;
    v7 = v5;
    do
    {
      v8 = *v6;
      *v7++ = *v6++;
    }
    while ( v8 != 0 );
  }
  vgui::Panel::ApplySettings(this, a2: (int)inResourceData, a3: (int)this, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x103ABDD0
// Name: public: virtual void vgui::ProgressBar::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::GetSettings(vgui::ProgressBar *this, KeyValues *outResourceData)
{
  char *value; // esi

  vgui::Panel::GetSettings(this, outResourceData);
  KeyValues::SetFloat(this: outResourceData, keyName: "progress", value: this->_progress);
  value = this->m_pszDialogVar;
  if ( value != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "variable", value);
}

//------------------------------------------------------------------------------
// Address: 0x103ABE20
// Name: public: virtual char const __near * vgui::ProgressBar::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::ProgressBar::GetDescription(vgui::ProgressBar *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  _snprintf(string: buf_7, count: 0x400u, format: "%s, string progress, string variable", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x103ABE50
// Name: protected: virtual void vgui::ProgressBar::OnDialogVariablesChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBar::OnDialogVariablesChanged(vgui::ProgressBar *this, KeyValues *dialogVariables)
{
  char *m_pszDialogVar; // eax
  float Int; // xmm0_4

  m_pszDialogVar = this->m_pszDialogVar;
  if ( m_pszDialogVar != nullptr )
  {
    Int = (float)KeyValues::GetInt(this: dialogVariables, keyName: m_pszDialogVar, defaultValue: -1);
    if ( Int >= 0.0 )
      ((void (__thiscall *)(vgui::ProgressBar *, _DWORD))this->SetProgress)(a1: this, a2: Int * 0.0099999998);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ABEA0
// Name: public: virtual void vgui::ContinuousProgressBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ContinuousProgressBar::Paint(vgui::ContinuousProgressBar *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  Color *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetFgColor(this, result: v5);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v3->DrawSetColor)(a1: v2, a2: *v4);
  switch ( this->m_iProgressDirection )
  {
    case 0:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: (int)(float)((float)wide * this->_progress),
        a5: tall);
      break;
    case 1:
      ((void (__stdcall *)(int, _DWORD, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: (int)(float)((float)(1.0 - this->_progress) * (float)wide),
        a2: 0,
        a3: wide,
        a4: tall);
      break;
    case 2:
      ((void (__stdcall *)(_DWORD, int, int, int))g_pVGuiSurface->DrawFilledRect)(
        a1: 0,
        a2: (int)(float)((float)(1.0 - this->_progress) * (float)tall),
        a3: wide,
        a4: tall);
      break;
    case 3:
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: 0,
        a3: 0,
        a4: wide,
        a5: (int)(float)((float)tall * this->_progress));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AC000
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBar::GetMessageMap(vgui::ProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  `vgui::ProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AC030
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBar::GetAnimMap(vgui::ProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x103AC040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBar::GetKBMap(vgui::ProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  `vgui::ProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AC0B0
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetProgress";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_FLOAT;
    v4.firstParamName = "progress";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AC150
// Name: public: static void vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "DialogVariables";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AC1E0
// Name: public: vgui::ProgressBar::ProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__thiscall vgui::ProgressBar::ProgressBar(
        vgui::ProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ProgressBar_vtbl *)&vgui::ProgressBar::`vftable';
  if ( `vgui::ProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
    v4->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ProgressBar");
    v5->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
    v6->pfnClassName = vgui::ProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ProgressBar::PanelMessageFunc_SetProgress::InitVar(a1: (int)&savedregs);
  vgui::ProgressBar::PanelMessageFunc_OnDialogVariablesChanged::InitVar(a1: (int)&savedregs);
  this->m_pszDialogVar = nullptr;
  this->m_iBarMargin = 0;
  this->m_iProgressDirection = 0;
  this->_progress = 0.0;
  this->_segmentGap = 4;
  this->_segmentWide = 8;
  this->m_iBarInset = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103AC2F0
// Name: public: vgui::ContinuousProgressBar::ContinuousProgressBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__thiscall vgui::ContinuousProgressBar::ContinuousProgressBar(
        vgui::ContinuousProgressBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ProgressBar::ProgressBar(this, parent, panelName);
  this->__vftable = (vgui::ContinuousProgressBar_vtbl *)&vgui::ContinuousProgressBar::`vftable';
  if ( `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
    v4->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
    v5->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ProgressBar");
  }
  if ( `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ContinuousProgressBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
    v6->pfnClassName = vgui::ContinuousProgressBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBar");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103AC3B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ContinuousProgressBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ContinuousProgressBar::GetMessageMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AC3E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ContinuousProgressBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ContinuousProgressBar::GetAnimMap(vgui::ContinuousProgressBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ContinuousProgressBar");
}

//------------------------------------------------------------------------------
// Address: 0x103AC3F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ContinuousProgressBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ContinuousProgressBar::GetKBMap(vgui::ContinuousProgressBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap;
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ContinuousProgressBar");
  `vgui::ContinuousProgressBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AC420
// Name: Create_ProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBar *__cdecl Create_ProgressBar()
{
  vgui::ProgressBar *v0; // eax

  v0 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return vgui::ProgressBar::ProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AC440
// Name: Create_ContinuousProgressBar
// Source: json
//------------------------------------------------------------------------------
vgui::ContinuousProgressBar *__cdecl Create_ContinuousProgressBar()
{
  vgui::ContinuousProgressBar *v0; // eax

  v0 = (vgui::ContinuousProgressBar *)operator new(nSize: 0x178u);
  if ( v0 != nullptr )
    return vgui::ContinuousProgressBar::ContinuousProgressBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace server
