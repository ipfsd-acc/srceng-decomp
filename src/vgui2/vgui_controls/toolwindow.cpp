// Original: vgui2/vgui_controls/toolwindow.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "vgui2\vgui_controls\toolwindow.h"

// Stub: vgui::ToolWindow::GetToolWindowFactory
void GetToolWindowFactory() {}

// Stub: CUtlVector<vgui::ToolWindow *,CUtlMemory<vgui::ToolWindow *,int> >::~CUtlVector<vgui::ToolWindow *,CUtlMemory<vgui::ToolWindow *,int> >
void ToolWindow *,int> >() {}

// Stub: dynamic initializer for 'vgui::ToolWindow::s_ToolWindows''
void s_ToolWindows''() {}

// Stub: dynamic atexit destructor for 'vgui::ToolWindow::s_ToolWindows''
void s_ToolWindows''() {}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10072590
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace AdminServer

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006425F0
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1030CCE0
// Name: public: static char const __near * vgui::ToolWindow::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToolWindow::GetPanelClassName()
{
  return "ToolWindow";
}

//------------------------------------------------------------------------------
// Address: 0x1030CCF0
// Name: public: virtual bool vgui::ToolWindow::IsDraggableTabContainer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ToolWindow::IsDraggableTabContainer(vgui::ToolWindow *this)
{
  return this->m_pPropertySheet->IsDraggableTab(this: this->m_pPropertySheet);
}

//------------------------------------------------------------------------------
// Address: 0x1030CD00
// Name: public: class vgui::PropertySheet __near * vgui::ToolWindow::GetPropertySheet(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertySheet *__thiscall vgui::ToolWindow::GetPropertySheet(vgui::ToolWindow *this)
{
  return this->m_pPropertySheet;
}

//------------------------------------------------------------------------------
// Address: 0x1030CD10
// Name: public: void vgui::ToolWindow::AddPage(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::AddPage(
        vgui::ToolWindow *this,
        vgui::Panel *page,
        const char *title,
        BOOL contextMenu)
{
  this->m_pPropertySheet->AddPage(
    this: this->m_pPropertySheet,
    a2: page,
    a3: title,
    a4: nullptr,
    a5: contextMenu,
    a6: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1030CD40
// Name: protected: virtual void vgui::ToolWindow::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::PerformLayout(vgui::ToolWindow *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  vgui::Panel::SetBounds(this: this->m_pPropertySheet, x, y, wide, tall);
  this->m_pPropertySheet->InvalidateLayout(this: this->m_pPropertySheet, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030CDB0
// Name: protected: virtual void vgui::ToolWindow::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::ActivateBuildMode(vgui::ToolWindow *this)
{
  vgui::Panel *v1; // eax
  void *v2; // eax

  v1 = this->m_pPropertySheet->GetActivePage(this: this->m_pPropertySheet);
  v2 = __RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 860))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1030CDF0
// Name: protected: virtual void vgui::ToolWindow::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::RequestFocus(vgui::ToolWindow *this, int direction)
{
  this->m_pPropertySheet->RequestFocus(this: this->m_pPropertySheet, a2: direction);
}

//------------------------------------------------------------------------------
// Address: 0x1030CE10
// Name: protected: virtual void vgui::ToolWindow::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::OnSetFocus(vgui::ToolWindow *this)
{
  this->m_pPropertySheet->RequestFocus(this: this->m_pPropertySheet, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1030CE20
// Name: public: void vgui::ToolWindow::SetToolWindowFactory(class vgui::IToolWindowFactory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::SetToolWindowFactory(vgui::ToolWindow *this, vgui::IToolWindowFactory *factory)
{
  this->m_pFactory = factory;
}

//------------------------------------------------------------------------------
// Address: 0x1030CE30
// Name: public: virtual void vgui::ToolWindow::GrowFromClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::GrowFromClick(vgui::ToolWindow *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edx
  int v5; // ecx
  int v6; // [esp+Ch] [ebp-20h]
  int esz; // [esp+10h] [ebp-1Ch]
  int mx; // [esp+14h] [ebp-18h] BYREF
  int h; // [esp+18h] [ebp-14h] BYREF
  int w; // [esp+1Ch] [ebp-10h] BYREF
  int my; // [esp+20h] [ebp-Ch] BYREF
  int y; // [esp+24h] [ebp-8h] BYREF
  int x; // [esp+28h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
  esz = this->GetDraggerSize(this);
  v2 = this->GetCornerSize(this);
  v3 = this->GetBottomRightSize(this);
  v6 = this->GetCaptionHeight(this);
  vgui::Panel::GetBounds(this, &x, &y, wide: &w, tall: &h);
  if ( mx > x - v2 + w - 1 && my < v2 + y )
  {
    this->Grow(this, a2: 1, a3: -1, a4: -1);
LABEL_4:
    this->Grow(this, a2: 2, a3: -1, a4: -1);
    return;
  }
  v4 = y;
  if ( mx <= x - v3 + w - 1 )
  {
    v5 = my;
  }
  else
  {
    v5 = my;
    if ( my > y - v3 + h - 1 )
    {
      this->Grow(this, a2: 2, a3: -1, a4: -1);
      this->Grow(this, a2: 3, a3: -1, a4: -1);
      return;
    }
  }
  if ( mx < v2 + x )
  {
    if ( v5 > y - v2 + h - 1 )
    {
      this->Grow(this, a2: 3, a3: -1, a4: -1);
LABEL_12:
      this->Grow(this, a2: 4, a3: -1, a4: -1);
      return;
    }
    v4 = y;
  }
  if ( mx < v2 + x && v5 < v4 + v2 )
  {
    this->Grow(this, a2: 4, a3: -1, a4: -1);
LABEL_17:
    this->Grow(this, a2: 1, a3: -1, a4: -1);
    return;
  }
  if ( v5 < esz + v4 )
    goto LABEL_17;
  if ( mx > x - esz + w - 1 )
    goto LABEL_4;
  if ( v5 <= y - esz + h - 1 )
  {
    if ( mx < esz + x )
      goto LABEL_12;
    if ( v5 < v6 + y )
      this->Grow(this, a2: 0, a3: mx, a4: v5);
  }
  else
  {
    this->Grow(this, a2: 3, a3: -1, a4: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030D030
// Name: protected: virtual void vgui::ToolWindow::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::OnMouseDoublePressed(vgui::ToolWindow *this, ButtonCode_t code)
{
  this->GrowFromClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030D040
// Name: protected: virtual void vgui::ToolWindow::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::OnMousePressed(vgui::ToolWindow *this, ButtonCode_t code)
{
  if ( code == MOUSE_MIDDLE )
    this->GrowFromClick(this);
  else
    vgui::Frame::OnMousePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1030D070
// Name: GetParentSpaceEdge
// Source: json
//------------------------------------------------------------------------------
void __usercall GetParentSpaceEdge(vgui::Panel *p@<ecx>, int *bounds@<esi>, vgui::ESharedEdge eEdge)
{
  vgui::Panel::GetBounds(this: p, x: bounds, y: bounds + 1, wide: bounds + 2, tall: bounds + 3);
  bounds[3] += bounds[1];
  bounds[2] += *bounds;
  switch ( eEdge )
  {
    case TOOLWINDOW_LEFT:
      bounds[2] = bounds[eEdge];
      break;
    case TOOLWINDOW_TOP:
      bounds[3] = bounds[eEdge];
      break;
    case TOOLWINDOW_RIGHT:
      *bounds = bounds[eEdge];
      break;
    case TOOLWINDOW_BOTTOM:
      bounds[1] = bounds[eEdge];
      break;
    default:
      *(bounds - 1) = bounds[eEdge];
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030D0F0
// Name: public: static bool TWEdgePair_t::Less(struct TWEdgePair_t const __near &,struct TWEdgePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TWEdgePair_t::Less(const TWEdgePair_t *lhs, const TWEdgePair_t *rhs)
{
  if ( lhs->m_pWindow < rhs->m_pWindow )
    return true;
  if ( lhs->m_pWindow <= rhs->m_pWindow )
    return lhs->m_EdgeType < rhs->m_EdgeType;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1030D120
// Name: public: static int vgui::ToolWindow::GetToolWindowCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vgui::ToolWindow::GetToolWindowCount()
{
  return vgui::ToolWindow::s_ToolWindows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1030D130
// Name: public: static class vgui::ToolWindow __near * vgui::ToolWindow::GetToolWindow(int)
// Source: json
//------------------------------------------------------------------------------
vgui::ToolWindow *__cdecl vgui::ToolWindow::GetToolWindow(int index)
{
  return vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x1030D150
// Name: public: virtual void vgui::ToolWindow::Grow(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::Grow(vgui::ToolWindow *this, int edge, int from_x, int from_y)
{
  void (__thiscall *GetScreenSize)(vgui::ISurface *, int *, int *); // eax
  int v6; // esi
  int v7; // edi
  int v8; // edx
  int m_Size; // ecx
  int v10; // eax
  int v11; // ebx
  vgui::ToolWindow *v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // ebx
  vgui::ToolWindow *v16; // ecx
  int v17; // ecx
  int v18; // eax
  int v19; // esi
  vgui::ToolWindow *v20; // ecx
  int v21; // ecx
  int i; // edi
  vgui::ToolWindow *v23; // ecx
  int v24; // ecx
  int sh; // [esp+Ch] [ebp-40h] BYREF
  int sw; // [esp+10h] [ebp-3Ch] BYREF
  int h; // [esp+14h] [ebp-38h] BYREF
  int y; // [esp+18h] [ebp-34h] BYREF
  int w; // [esp+1Ch] [ebp-30h] BYREF
  int x; // [esp+20h] [ebp-2Ch] BYREF
  vgui::Panel *v31; // [esp+24h] [ebp-28h]
  int new_x; // [esp+28h] [ebp-24h]
  int new_y; // [esp+2Ch] [ebp-20h]
  int c; // [esp+30h] [ebp-1Ch]
  int old_y; // [esp+34h] [ebp-18h] BYREF
  int new_w; // [esp+38h] [ebp-14h]
  int new_h; // [esp+3Ch] [ebp-10h]
  int old_x; // [esp+40h] [ebp-Ch] BYREF
  int old_h; // [esp+44h] [ebp-8h] BYREF
  int old_w; // [esp+48h] [ebp-4h] BYREF

  GetScreenSize = g_pVGuiSurface->GetScreenSize;
  v31 = this;
  GetScreenSize(this: g_pVGuiSurface, a2: &sw, a3: &sh);
  vgui::Panel::GetBounds(this, x: &old_x, y: &old_y, wide: &old_w, tall: &old_h);
  v6 = edge;
  v7 = old_x;
  v8 = old_y;
  m_Size = vgui::ToolWindow::s_ToolWindows.m_Size;
  new_w = old_w;
  v10 = old_h;
  new_x = old_x;
  new_y = old_y;
  new_h = old_h;
  c = vgui::ToolWindow::s_ToolWindows.m_Size;
  if ( (unsigned int)edge <= 1 )
  {
    if ( from_y >= 0 )
    {
      v10 = old_y - from_y + old_h;
      v8 = from_y;
      old_h = v10;
      old_y = from_y;
    }
    v11 = 0;
    new_h = v8 + v10 - 27;
    new_y = 27;
    if ( vgui::ToolWindow::s_ToolWindows.m_Size > 0 )
    {
      do
      {
        v12 = vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory[v11];
        if ( v12 != nullptr && v12 != v31 )
        {
          if ( (vgui::Panel::GetBounds(this: v12, &x, &y, wide: &w, tall: &h), v7 = old_x, old_x > x) && old_x < x + w
            || (v13 = old_x + old_w, old_x + old_w > x) && v13 < x + w
            || old_x <= x && v13 >= w + x )
          {
            if ( old_y >= y + h && new_y < y + h )
            {
              new_y = y + h;
              new_h = old_h + old_y - y - h;
            }
          }
        }
        m_Size = c;
        ++v11;
      }
      while ( v11 < c );
      v6 = edge;
    }
    old_h = new_h;
    v8 = new_y;
    old_y = new_y;
  }
  if ( v6 == 0 || v6 == 2 )
  {
    if ( from_x >= 0 )
      old_w = from_x - v7;
    v14 = sw - v7;
    v15 = 0;
    new_w = sw - v7;
    if ( m_Size > 0 )
    {
      do
      {
        v16 = vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory[v15];
        if ( v16 != nullptr && v16 != v31 )
        {
          vgui::Panel::GetBounds(this: v16, x: &w, y: &h, wide: &x, tall: &y);
          v8 = old_y;
          if ( (old_y <= h || old_y >= h + y)
            && ((v17 = old_y + old_h, old_y + old_h <= h) || v17 >= h + y)
            && (old_y > h || v17 < y + h) )
          {
            v7 = old_x;
          }
          else
          {
            v7 = old_x;
            if ( old_x + old_w <= w && new_w > w - old_x )
              new_w = w - old_x;
          }
        }
        ++v15;
      }
      while ( v15 < c );
      v6 = edge;
      v14 = new_w;
    }
    old_w = v14;
  }
  if ( v6 == 0 || v6 == 3 )
  {
    if ( from_y >= 0 )
      old_h = from_y - v8;
    v18 = sh - v8 - 24;
    v19 = 0;
    new_h = v18;
    if ( c > 0 )
    {
      do
      {
        v20 = vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory[v19];
        if ( v20 != nullptr && v20 != v31 )
        {
          if ( (vgui::Panel::GetBounds(this: v20, x: &from_y, &y, wide: &h, tall: &w), v7 = old_x, old_x > from_y)
            && old_x < from_y + h
            || (v21 = old_x + old_w, old_x + old_w > from_y) && v21 < from_y + h
            || old_x <= from_y && v21 >= h + from_y )
          {
            if ( old_y + old_h <= y && new_h > y - old_y )
              new_h = y - old_y;
          }
        }
        ++v19;
      }
      while ( v19 < c );
      v18 = new_h;
    }
    old_h = v18;
  }
  if ( edge == 0 || edge == 4 )
  {
    if ( from_x >= 0 )
    {
      old_w += v7 - from_x;
      v7 = from_x;
      old_x = from_x;
    }
    new_x = 0;
    new_w = old_w + v7;
    for ( i = 0; i < c; ++i )
    {
      v23 = vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory[i];
      if ( v23 != nullptr && v23 != v31 )
      {
        if ( (vgui::Panel::GetBounds(this: v23, x: &from_x, y: &edge, wide: &h, tall: &from_y), old_y > edge)
          && old_y < edge + from_y
          || (v24 = old_y + old_h, old_y + old_h > edge) && v24 < edge + from_y
          || old_y <= edge && v24 >= from_y + edge )
        {
          if ( old_x >= from_x + h && new_x < from_x + h )
          {
            new_x = from_x + h;
            new_w = old_w + old_x - from_x - h;
          }
        }
      }
    }
    old_w = new_w;
    old_x = new_x;
  }
  vgui::Panel::SetBounds(this: v31, x: new_x, y: new_y, wide: new_w, tall: new_h);
}

//------------------------------------------------------------------------------
// Address: 0x1030E400
// Name: public: virtual vgui::ToolWindow::~ToolWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::~ToolWindow(vgui::ToolWindow *this)
{
  vgui::PropertySheet *m_pPropertySheet; // ecx
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  m_pPropertySheet = this->m_pPropertySheet;
  this->__vftable = (vgui::ToolWindow_vtbl *)&vgui::ToolWindow::`vftable';
  m_pPropertySheet->RemoveAllPages(this: m_pPropertySheet);
  src = (vgui::TreeNode *)this;
  CUtlVector<CMapView2D *,CUtlMemory<CMapView2D *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vgui::ToolWindow::s_ToolWindows,
    &src);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030E440
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToolWindow::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToolWindow::GetMessageMap(vgui::ToolWindow *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToolWindow::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToolWindow::GetMessageMap'::`2'::s_pMap;
  `vgui::ToolWindow::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToolWindow");
  `vgui::ToolWindow::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030E470
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToolWindow::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToolWindow::GetAnimMap(vgui::ToolWindow *this)
{
  return FindOrAddPanelAnimationMap(className: "ToolWindow");
}

//------------------------------------------------------------------------------
// Address: 0x1030E480
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToolWindow::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToolWindow::GetKBMap(vgui::ToolWindow *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToolWindow::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToolWindow::GetKBMap'::`2'::s_pMap;
  `vgui::ToolWindow::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToolWindow");
  `vgui::ToolWindow::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030E4B0
// Name: public: static void vgui::ToolWindow::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ToolWindow::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ToolWindow::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `vgui::ToolWindow::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ToolWindow");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030E540
// Name: public: vgui::ToolWindow::ToolWindow(class vgui::Panel __near *,bool,class vgui::IToolWindowFactory __near *,class vgui::Panel __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ToolWindow *__thiscall vgui::ToolWindow::ToolWindow(
        vgui::ToolWindow *this,
        vgui::Panel *parent,
        bool contextlabel,
        vgui::IToolWindowFactory *factory,
        vgui::Panel *page,
        const char *title,
        BOOL contextMenu,
        bool inGlobalList)
{
  vgui::PanelMessageMap *v9; // edi
  PanelAnimationMap *v10; // edi
  vgui::PanelKeyBindingMap *v11; // edi
  int m_Size; // eax
  int v13; // edi
  vgui::ToolWindow **m_pMemory; // ecx
  int v15; // eax
  vgui::ToolWindow **v16; // eax
  vgui::PropertySheet *v17; // eax
  vgui::PropertySheet *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "ToolWindow", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::ToolWindow_vtbl *)&vgui::ToolWindow::`vftable';
  if ( `vgui::ToolWindow::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToolWindow::ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelMessageMap(className: "ToolWindow");
    v9->pfnClassName = vgui::ToolWindow::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::ToolWindow::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToolWindow::ChainToAnimationMap'::`2'::chained = 1;
    v10 = FindOrAddPanelAnimationMap(className: "ToolWindow");
    v10->pfnClassName = vgui::ToolWindow::GetPanelClassName;
    v10->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::ToolWindow::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToolWindow::KB_ChainToMap'::`2'::chained = 1;
    v11 = vgui::FindOrAddPanelKeyBindingMap(className: "ToolWindow");
    v11->pfnClassName = vgui::ToolWindow::GetPanelClassName;
    v11->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::ToolWindow::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  *((_BYTE *)this + 540) |= 1u;
  this->m_pFactory = nullptr;
  if ( inGlobalList )
  {
    m_Size = vgui::ToolWindow::s_ToolWindows.m_Size;
    v13 = vgui::ToolWindow::s_ToolWindows.m_Size;
    if ( vgui::ToolWindow::s_ToolWindows.m_Size + 1 > vgui::ToolWindow::s_ToolWindows.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&vgui::ToolWindow::s_ToolWindows,
        num: vgui::ToolWindow::s_ToolWindows.m_Size - vgui::ToolWindow::s_ToolWindows.m_Memory.m_nAllocationCount + 1);
      m_Size = vgui::ToolWindow::s_ToolWindows.m_Size;
    }
    m_pMemory = vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory;
    vgui::ToolWindow::s_ToolWindows.m_Size = m_Size + 1;
    v15 = m_Size - v13;
    vgui::ToolWindow::s_ToolWindows.m_pElements = vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory;
    if ( v15 > 0 )
    {
      _V_memmove(
        dest: (unsigned __int8 *)&vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory[v13 + 1],
        src: (unsigned __int8 *)&vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory[v13],
        count: 4 * v15);
      m_pMemory = vgui::ToolWindow::s_ToolWindows.m_Memory.m_pMemory;
    }
    v16 = &m_pMemory[v13];
    if ( v16 != nullptr )
      *v16 = this;
  }
  v17 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v17 != nullptr )
    v18 = vgui::PropertySheet::PropertySheet(
            this: v17,
            parent: this,
            panelName: (vgui::Panel *)"ToolWindowSheet",
            draggableTabs: true);
  else
    v18 = nullptr;
  this->m_pPropertySheet = v18;
  vgui::PropertySheet::ShowContextButtons(this: v18, state: contextlabel);
  this->m_pPropertySheet->AddPage(
    this: this->m_pPropertySheet,
    a2: page,
    a3: title,
    a4: nullptr,
    a5: contextMenu,
    a6: -1);
  this->m_pPropertySheet->AddActionSignalTarget_2(this: this->m_pPropertySheet, a2: this);
  this->m_pPropertySheet->SetSmallTabs(this: this->m_pPropertySheet, a2: true);
  vgui::PropertySheet::SetKBNavigationEnabled(this: this->m_pPropertySheet, state: false);
  vgui::Frame::SetSmallCaption(this, state: true);
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: true);
  vgui::Frame::SetMoveable(this, state: true);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetClipToParent(this, state: false);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetTitle(this, title: &var, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1030E7C0
// Name: public: void vgui::ToolWindow::GetSiblingToolWindows(class CUtlVector<class vgui::ToolWindow __near *,class CUtlMemory<class vgui::ToolWindow __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::GetSiblingToolWindows(
        vgui::ToolWindow *this,
        CUtlMemory<vgui::TreeNode *,int> *vecSiblings)
{
  vgui::ToolWindow *v2; // edi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // ebx
  int ChildCount; // eax
  int v6; // ecx
  vgui::Panel *Child; // eax
  vgui::ToolWindow *v8; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::ToolWindow **v11; // ecx
  int v12; // eax
  vgui::ToolWindow **v13; // eax
  int nChildCount; // [esp+8h] [ebp-10h]
  vgui::Panel *parent; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = this;
  v3 = (vgui::Panel *)((int (__fastcall *)(vgui::ToolWindow *))this->GetParent)(a1: this);
  v4 = v3;
  parent = v3;
  if ( v3 != nullptr )
  {
    ChildCount = vgui::Panel::GetChildCount(this: v3);
    v6 = 0;
    nChildCount = ChildCount;
    i = 0;
    if ( ChildCount > 0 )
    {
      while ( 1 )
      {
        Child = vgui::Panel::GetChild(this: v4, index: v6);
        v8 = (vgui::ToolWindow *)__RTDynamicCast(
                                   inptr: Child,
                                   VfDelta: 0,
                                   SrcType: &vgui::Panel `RTTI Type Descriptor',
                                   TargetType: &vgui::ToolWindow `RTTI Type Descriptor',
                                   isReference: 0);
        if ( v8 != nullptr && v8->IsVisible(this: v8) && v8 != v2 )
        {
          m_pMemory = (int)vecSiblings[1].m_pMemory;
          m_nAllocationCount = vecSiblings->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: vecSiblings, num: m_pMemory - m_nAllocationCount + 1);
          ++vecSiblings[1].m_pMemory;
          v11 = (vgui::ToolWindow **)vecSiblings->m_pMemory;
          v12 = (int)vecSiblings[1].m_pMemory - m_pMemory - 1;
          vecSiblings[1].m_nAllocationCount = (int)vecSiblings->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v11[m_pMemory + 1],
              src: (unsigned __int8 *)&v11[m_pMemory],
              count: 4 * v12);
          v13 = (vgui::ToolWindow **)&vecSiblings->m_pMemory[m_pMemory];
          if ( v13 != nullptr )
            *v13 = v8;
        }
        v6 = i + 1;
        i = v6;
        if ( v6 >= nChildCount )
          break;
        v4 = parent;
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030E8B0
// Name: private: void vgui::ToolWindow::FindOverlappingEdges_R(class CUtlVector<class vgui::ToolWindow __near *,class CUtlMemory<class vgui::ToolWindow __near *,int>> __near &,class CUtlRBTree<struct TWEdgePair_t,unsigned short,bool (*)(struct TWEdgePair_t const __near &,struct TWEdgePair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct TWEdgePair_t,unsigned short>,unsigned short>> __near &,enum vgui::ESharedEdge,int __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::FindOverlappingEdges_R(
        vgui::ToolWindow *this,
        CUtlVector<vgui::ToolWindow *,CUtlMemory<vgui::ToolWindow *,int> > *vecSiblings,
        vgui::ToolWindow *rbCurrentEdges,
        vgui::ESharedEdge eEdgeType,
        int *line)
{
  vgui::ESharedEdge v5; // esi
  CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl*)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short> > *v6; // edi
  bool v7; // cc
  int v8; // eax
  int *v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  bool v13; // zf
  bool v14; // sf
  int v15; // eax
  int v16; // ecx
  unsigned __int16 v17; // ax
  unsigned __int16 v18; // dx
  unsigned __int16 v19; // cx
  int v20; // esi
  UtlRBTreeNode_t<TWEdgePair_t,unsigned short> *v21; // eax
  UtlRBTreeNode_t<TWEdgePair_t,unsigned short> *m_pMemory; // eax
  int v23; // edx
  UtlRBTreeNode_t<TWEdgePair_t,unsigned short> *v24; // ecx
  TWEdgePair_t *p_m_Data; // esi
  int edgeline[4]; // [esp+Ch] [ebp-28h] BYREF
  TWEdgePair_t ep; // [esp+1Ch] [ebp-18h] BYREF
  vgui::ToolWindow *v28; // [esp+24h] [ebp-10h]
  int v29; // [esp+28h] [ebp-Ch]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-8h] BYREF
  int i; // [esp+30h] [ebp-4h]

  v5 = eEdgeType;
  v6 = (CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl*)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short> > *)rbCurrentEdges;
  v28 = this;
  v29 = 2;
  do
  {
    v7 = vecSiblings->m_Size <= 0;
    i = 0;
    if ( !v7 )
    {
      do
      {
        rbCurrentEdges = vecSiblings->m_Memory.m_pMemory[i];
        vgui::Panel::GetBounds(
          this: rbCurrentEdges,
          x: edgeline,
          y: &edgeline[1],
          wide: &edgeline[2],
          tall: &edgeline[3]);
        edgeline[2] += edgeline[0];
        edgeline[3] += edgeline[1];
        switch ( v5 )
        {
          case TOOLWINDOW_LEFT:
            v8 = 2;
            break;
          case TOOLWINDOW_TOP:
            v8 = 3;
            break;
          case TOOLWINDOW_RIGHT:
            v8 = 0;
            break;
          case TOOLWINDOW_BOTTOM:
            v8 = 1;
            break;
          default:
            v8 = -1;
            break;
        }
        v9 = line;
        edgeline[v8] = edgeline[v5];
        v10 = *v9;
        if ( edgeline[0] > *v9 )
          v10 = edgeline[0];
        v11 = v9[2];
        if ( edgeline[2] < v11 )
          v11 = edgeline[2];
        v12 = v10 - v11;
        v13 = v12 == 0;
        v14 = v12 < 0;
        v15 = line[1];
        if ( edgeline[1] > v15 )
          v15 = edgeline[1];
        v16 = line[3];
        if ( edgeline[3] < v16 )
          v16 = edgeline[3];
        if ( (v14 || v13) && v15 - v16 <= 0 )
        {
          ep.m_pWindow = rbCurrentEdges;
          ep.m_EdgeType = v5;
          if ( CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::Find(
                 this: v6,
                 search: &ep) == 0xFFFF )
          {
            *(_DWORD *)parent = 0xFFFF;
            HIBYTE(rbCurrentEdges) = 0;
            CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::FindInsertionPosition(
              this: v6,
              insert: &ep,
              parent,
              leftchild: (bool *)&rbCurrentEdges + 3);
            v17 = CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::NewNode(
                    this: v6,
                    a2: (const char *)v6);
            v18 = parent[0];
            v19 = v17;
            v20 = v17;
            v21 = &v6->m_Elements.m_pMemory[v20];
            v21->m_Right = -1;
            v21->m_Left = -1;
            v21->m_Parent = v18;
            v21->m_Tag = 0;
            if ( v18 == 0xFFFF )
            {
              v6->m_Root = v19;
            }
            else
            {
              m_pMemory = v6->m_Elements.m_pMemory;
              v23 = v18;
              if ( HIBYTE(rbCurrentEdges) != 0 )
                m_pMemory[v23].m_Left = v19;
              else
                m_pMemory[v23].m_Right = v19;
            }
            CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::InsertRebalance(
              this: v6,
              elem: v19);
            v24 = v6->m_Elements.m_pMemory;
            ++v6->m_NumElements;
            p_m_Data = &v24[v20].m_Data;
            if ( p_m_Data != nullptr )
              *p_m_Data = ep;
            v5 = eEdgeType;
            vgui::ToolWindow::FindOverlappingEdges_R(
              this: v28,
              vecSiblings,
              rbCurrentEdges: v6,
              eEdgeType,
              line: edgeline);
          }
        }
        ++i;
      }
      while ( i < vecSiblings->m_Size );
    }
    switch ( v5 )
    {
      case TOOLWINDOW_LEFT:
        v5 = TOOLWINDOW_RIGHT;
        break;
      case TOOLWINDOW_TOP:
        v5 = TOOLWINDOW_BOTTOM;
        break;
      case TOOLWINDOW_RIGHT:
        v5 = TOOLWINDOW_LEFT;
        break;
      case TOOLWINDOW_BOTTOM:
        v5 = TOOLWINDOW_TOP;
        break;
      default:
        v5 = TOOLWINDOW_NONE;
        break;
    }
    v13 = v29-- == 1;
    eEdgeType = v5;
  }
  while ( !v13 );
}

//------------------------------------------------------------------------------
// Address: 0x1030EAD0
// Name: protected: virtual void vgui::ToolWindow::OnGripPanelMoved(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToolWindow::OnGripPanelMoved(vgui::ToolWindow *this, int nNewX, int nNewY, int nNewW, int nNewH)
{
  vgui::ToolWindow *v5; // esi
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // edx
  bool v7; // al
  vgui::ESharedEdge v8; // ebx
  int v9; // esi
  vgui::ToolWindow *m_pWindow; // edi
  vgui::ESharedEdge m_EdgeType; // ebx
  UtlRBTreeNode_t<TWEdgePair_t,unsigned short> *m_pMemory; // eax
  CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl*)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short> > rbEdges; // [esp+4h] [ebp-7Ch] BYREF
  CUtlVector<vgui::ToolWindow *,CUtlMemory<vgui::ToolWindow *,int> > vecSiblings; // [esp+20h] [ebp-60h] BYREF
  int edgeline[4]; // [esp+34h] [ebp-4Ch] BYREF
  int d[4]; // [esp+44h] [ebp-3Ch]
  int v17; // [esp+54h] [ebp-2Ch] BYREF
  int v18; // [esp+58h] [ebp-28h] BYREF
  int wide; // [esp+5Ch] [ebp-24h] BYREF
  int tall; // [esp+60h] [ebp-20h] BYREF
  int v21; // [esp+64h] [ebp-1Ch]
  int h; // [esp+68h] [ebp-18h] BYREF
  int w; // [esp+6Ch] [ebp-14h] BYREF
  int y; // [esp+70h] [ebp-10h] BYREF
  int x; // [esp+74h] [ebp-Ch] BYREF
  int edge; // [esp+78h] [ebp-8h]
  vgui::Panel *p; // [esp+7Ch] [ebp-4h]

  v5 = this;
  IsKeyDown = g_pVGuiInput->IsKeyDown;
  p = this;
  if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v7 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    v7 = true;
  }
  if ( (*((_BYTE *)v5 + 540) & 1) != 0 && !v7 )
  {
    vgui::Panel::GetBounds(this: v5, &x, &y, wide: &w, tall: &h);
    memset(&vecSiblings, 0, sizeof(vecSiblings));
    vgui::ToolWindow::GetSiblingToolWindows(this: v5, (CUtlMemory<vgui::TreeNode *,int> *)&vecSiblings);
    if ( vecSiblings.m_Size > 0 )
    {
      d[0] = nNewX - x;
      d[1] = nNewY - y;
      v8 = TOOLWINDOW_LEFT;
      d[2] = nNewW + nNewX - x - w;
      d[3] = nNewH + nNewY - y - h;
      edge = 0;
      do
      {
        v21 = d[v8];
        if ( v21 != 0 )
        {
          rbEdges.m_LessFunc = TWEdgePair_t::Less;
          memset(&rbEdges.m_Elements, 0, sizeof(rbEdges.m_Elements));
          *(_DWORD *)&rbEdges.m_Root = 0xFFFF;
          *(_DWORD *)&rbEdges.m_FirstFree = -1;
          rbEdges.m_pElements = nullptr;
          GetParentSpaceEdge(p, bounds: edgeline, eEdge: v8);
          vgui::ToolWindow::FindOverlappingEdges_R(
            this: (vgui::ToolWindow *)p,
            &vecSiblings,
            rbCurrentEdges: (vgui::ToolWindow *)&rbEdges,
            eEdgeType: v8,
            line: edgeline);
          v9 = (unsigned __int16)CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::FirstInorder(this: &rbEdges);
          if ( v9 != 0xFFFF )
          {
            do
            {
              m_pWindow = rbEdges.m_Elements.m_pMemory[(unsigned __int16)v9].m_Data.m_pWindow;
              m_EdgeType = rbEdges.m_Elements.m_pMemory[(unsigned __int16)v9].m_Data.m_EdgeType;
              vgui::Panel::GetBounds(this: m_pWindow, x: &v17, y: &v18, &wide, &tall);
              wide += v17;
              tall += v18;
              *(&v17 + m_EdgeType) += v21;
              wide -= v17;
              tall -= v18;
              vgui::Panel::SetBounds(this: m_pWindow, x: v17, y: v18, wide, tall);
              v9 = (unsigned __int16)CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::NextInorder(
                                       this: &rbEdges,
                                       i: v9);
            }
            while ( v9 != 0xFFFF );
            v8 = edge;
          }
          CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::RemoveAll(this: &rbEdges);
          rbEdges.m_FirstFree = -1;
          m_pMemory = rbEdges.m_Elements.m_pMemory;
          if ( rbEdges.m_Elements.m_nGrowSize >= 0 )
          {
            if ( rbEdges.m_Elements.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rbEdges.m_Elements.m_pMemory);
              m_pMemory = nullptr;
              rbEdges.m_Elements.m_pMemory = nullptr;
            }
            rbEdges.m_Elements.m_nAllocationCount = 0;
          }
          rbEdges.m_LastAlloc.index = -1;
          if ( rbEdges.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        }
        edge = ++v8;
      }
      while ( v8 < 4 );
      v5 = (vgui::ToolWindow *)p;
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vecSiblings);
  }
  vgui::Frame::OnGripPanelMoved(this: v5, nNewX, nNewY, nNewW, nNewH);
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100D9660
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x100D987E
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D98A0
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = value;
    if ( value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero(a1: (_BYTE *)dst, a2: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D991A
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x100D9930
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D993B
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D99A9
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(
           string,
           inputfn: (int (__cdecl *)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *))_input_l,
           format,
           plocinfo: nullptr,
           arglist);
}

//------------------------------------------------------------------------------
// Address: 0x100D99CB
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9A38
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9AAC
// Name: __get_sys_err_msg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _get_sys_err_msg(int m)
{
  int v1; // esi

  v1 = m;
  if ( m < 0 || m >= *__sys_nerr() )
    v1 = *__sys_nerr();
  return __sys_errlist()[v1];
}

//------------------------------------------------------------------------------
// Address: 0x100D9AD4
// Name: _strerror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strerror(int errnum)
{
  _tiddata *v1; // eax
  _tiddata *v2; // esi
  unsigned __int8 *v4; // eax
  char *errmsg; // esi
  char *sys_err_msg; // eax

  v1 = _getptd_noexit();
  v2 = v1;
  if ( v1 == nullptr )
    return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  if ( v1->_errmsg == nullptr )
  {
    v4 = calloc(count: 0x86u, size: 1u);
    v2->_errmsg = (char *)v4;
    if ( v4 == nullptr )
      return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  errmsg = v2->_errmsg;
  sys_err_msg = _get_sys_err_msg(m: errnum);
  if ( strcpy_s(_Dst: errmsg, _SizeInBytes: 0x86u, _Src: sys_err_msg) != 0 )
    _invoke_watson(a1: 0x86u);
  return errmsg;
}

//------------------------------------------------------------------------------
// Address: 0x100D9B3E
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x100D9B80
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x100D9B93
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x100D9BA6
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x100D9BC9
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  _BYTE v7[12]; // [esp+1Ch] [ebp-10h] BYREF
  int v8; // [esp+28h] [ebp-4h]
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  v8 = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: (int)v7, a3: 0xFFFFFFFE);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x100D9C85
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x100D9C9C
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D9D23
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D9DCE
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D9DE1
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D9E8D
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x100D9EB0
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(__m128i *dst, const __m128i *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  __m128i *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = (unsigned __int8 *)src;
  v4 = dst;
  if ( dst > src && dst < (__m128i *)&src->m128i_i8[count] )
  {
    v6 = &src->m128i_u8[count - 4];
    v7 = &dst->m128i_u8[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = (unsigned __int8 *)src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(a1: count, a2: dst, a3: src);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 100D9F09 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *((_DWORD *)&v4[-1] + v5 - 3) = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *((_DWORD *)&v4[-1] + v5 - 2) = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *((_DWORD *)&v4[-1] + v5 - 1) = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        v4[-1].m128i_i32[v5] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        v4->m128i_i32[v5 - 3] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        v4->m128i_i32[v5 - 2] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        v4->m128i_i32[v5 - 1] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            v4->m128i_i8[0] = *v3;
            break;
          case 2u:
TrailUp2:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            v4->m128i_i8[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA220
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x100DA24B
// Name: FindCompleteObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__thiscall FindCompleteObject(void **inptr)
{
  int v1; // edx
  _BYTE *result; // eax
  int v3; // edx

  v1 = *((_DWORD *)*inptr - 1);
  result = (char *)inptr - *(_DWORD *)(v1 + 4);
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    result -= *(unsigned int *)((char *)inptr - v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DA261
// Name: PMDtoOffset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall PMDtoOffset@<eax>(const PMD *pmd@<eax>, char *pThis)
{
  int pdisp; // edx
  int v3; // ecx

  pdisp = pmd->pdisp;
  v3 = 0;
  if ( pdisp >= 0 )
    v3 = *(_DWORD *)(*(_DWORD *)&pThis[pdisp] + pmd->vdisp) + pmd->pdisp;
  return v3 + pmd->mdisp;
}

//------------------------------------------------------------------------------
// Address: 0x100DA285
// Name: FindMITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindMITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  const _s_RTTIBaseClassDescriptor *pSourceBCD; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *pTargetBCD; // [esp+10h] [ebp-10h]
  unsigned int nTargetBases; // [esp+14h] [ebp-Ch]
  unsigned int iTarget; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  pTargetBCD = nullptr;
  pSourceBCD = nullptr;
  nTargetBases = 0;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( pSourceBCD != nullptr )
        {
          if ( (v8->attributes & 3) == 0 && (pSourceBCD->attributes & 1) == 0 )
            return v8;
          return nullptr;
        }
        iTarget = i;
        pTargetBCD = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++i >= numBaseClasses )
      return nullptr;
  }
  if ( pTargetBCD == nullptr )
  {
    pSourceBCD = v8;
    goto LABEL_12;
  }
  if ( i - iTarget > nTargetBases )
  {
    if ( (pTargetBCD->attributes & 3) == 0 )
      goto LABEL_20;
    return nullptr;
  }
  if ( (pTargetBCD->attributes & 0x40) == 0 )
  {
    if ( iTarget == 0 )
    {
LABEL_20:
      if ( (v8->attributes & 1) != 0 )
        return nullptr;
    }
    return pTargetBCD;
  }
  return (pTargetBCD->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) == 0
       ? pTargetBCD
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100DA38D
// Name: FindVITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindVITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassDescriptor *v7; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // al
  int v12; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassArray *pBaseClassArray; // [esp+Ch] [ebp-24h]
  const _s_RTTIBaseClassDescriptor *pCrossCastTargetBCD; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *pCrossCastSourceBCD; // [esp+14h] [ebp-1Ch]
  int offsetDownCastResult; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *pDownCastResultBCD; // [esp+1Ch] [ebp-14h]
  unsigned int nTargetBases; // [esp+20h] [ebp-10h]
  unsigned int iTarget; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h]
  bool fDownCastAllowed; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  offsetDownCastResult = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = nullptr;
  pDownCastResultBCD = nullptr;
  pCrossCastSourceBCD = nullptr;
  pCrossCastTargetBCD = nullptr;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  nTargetBases = 0;
  fDownCastAllowed = true;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( (v8->attributes & 3) == 0 )
          pCrossCastTargetBCD = v8;
        iTarget = i;
        v7 = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
      {
        if ( i - iTarget > nTargetBases )
        {
          if ( (v8->attributes & 5) == 0 )
            pCrossCastSourceBCD = v8;
        }
        else if ( fDownCastAllowed )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 4) == 0;
          }
          else
          {
            if ( iTarget == 0 && (v8->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = true;
          }
          if ( fDownCastAllowed && v11 )
          {
            v12 = PMDtoOffset(pmd: &v7->where, pThis: pCompleteObject);
            if ( pDownCastResultBCD != nullptr && offsetDownCastResult != v12 )
              return nullptr;
            pDownCastResultBCD = v7;
            offsetDownCastResult = v12;
          }
        }
      }
    }
    ++i;
  }
  while ( i < numBaseClasses );
  if ( !fDownCastAllowed || (result = pDownCastResultBCD, pDownCastResultBCD == nullptr) )
  {
    if ( pCrossCastSourceBCD == nullptr )
      return nullptr;
    result = pCrossCastTargetBCD;
    if ( pCrossCastTargetBCD == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DA623
// Name: __snwprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snwprintf(unsigned __int16 *string, unsigned int count, const wchar_t *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+3Ch] [ebp+14h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._flag = 66;
    str._base = (char *)string;
    str._ptr = (char *)string;
    if ( count <= 0x3FFFFFFF )
      str._cnt = 2 * count;
    else
      str._cnt = 0x7FFFFFFF;
    result = _woutput_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr++ = 0;
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr = 0;
      return v4;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DA6F3
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(a1, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)a1.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DA8AB
// Name: ___libm_sse2_cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_cos@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(a1, 3) & 0x7FF0) != 0x7FF0 )
    return cos(X: *(double *)a1.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DAA60
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100DAA69
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x100DAA7C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp-4h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100DAA96
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DAB10
// Name: shortsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edx
  char *v5; // edi
  unsigned int v6; // ecx
  char *v7; // esi
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(a1: v7, a2: v8) > 0 )
            v8 = v7;
          v7 += width;
        }
        while ( v7 <= v5 );
        v6 = width;
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 != 0 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          *v10++ = v12;
          --v9;
        }
        while ( v9 != 0 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DABA0
// Name: _qsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edi
  unsigned int v5; // ebx
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // ebx
  unsigned int v9; // edx
  char *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  char *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  char *v19; // eax
  int v20; // ecx
  char *v21; // eax
  char *v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  char *v26; // edx
  char *v27; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v30; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v4 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v5 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(hi: v6, lo: v4, width: v5, comp);
        goto LABEL_57;
      }
      v8 = &v4[(v7 >> 1) * v5];
      if ( comp(a1: v4, a2: v8) > 0 )
      {
        v9 = width;
        v10 = v8;
        if ( v4 != v8 )
        {
          v11 = v4 - v8;
          do
          {
            v30 = v9 - 1;
            base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = base_3;
            v9 = v30;
            ++v10;
          }
          while ( v30 != 0 );
        }
      }
      if ( comp(a1: v4, a2: v6) > 0 )
      {
        v12 = width;
        v13 = v6;
        if ( v4 != v6 )
        {
          v14 = v4 - v6;
          do
          {
            base_3a = v13[v14];
            v13[v14] = *v13;
            *v13++ = base_3a;
            --v12;
          }
          while ( v12 != 0 );
          v4 = lo;
        }
      }
      if ( comp(a1: v8, a2: v6) > 0 )
      {
        v15 = width;
        v16 = v6;
        if ( v8 != v6 )
        {
          v17 = v8 - v6;
          do
          {
            base_3b = v16[v17];
            v16[v17] = *v16;
            *v16++ = base_3b;
            --v15;
          }
          while ( v15 != 0 );
          v4 = lo;
        }
      }
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += width;
            if ( v4 >= v8 )
              break;
            if ( comp(a1: v4, a2: v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_32;
              goto LABEL_30;
            }
          }
        }
        do
LABEL_30:
          v4 += width;
        while ( v4 <= hi && comp(a1: v4, a2: v8) <= 0 );
        do
LABEL_32:
          v6 -= width;
        while ( v6 > v8 && comp(a1: v6, a2: v8) > 0 );
        if ( v4 > v6 )
          break;
        v18 = width;
        v19 = v6;
        if ( v4 != v6 )
        {
          v20 = v4 - v6;
          do
          {
            v30 = v18 - 1;
            base_3c = v19[v20];
            v19[v20] = *v19;
            *v19 = base_3c;
            v18 = v30;
            ++v19;
          }
          while ( v30 != 0 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += width;
      if ( v8 >= v6 )
        goto LABEL_44;
      do
      {
        v6 -= width;
        if ( v6 <= v8 )
          goto LABEL_44;
      }
      while ( comp(a1: v6, a2: v8) == 0 );
      if ( v8 < v6 )
      {
LABEL_46:
        v21 = lo;
      }
      else
      {
LABEL_44:
        while ( 1 )
        {
          v6 -= width;
          v21 = lo;
          if ( v6 <= lo )
            break;
          if ( comp(a1: v6, a2: v8) != 0 )
            goto LABEL_46;
        }
      }
      v22 = hi;
      if ( v6 - v21 < hi - v4 )
      {
        if ( v4 < hi )
        {
          v24 = stkptr;
          lostk[stkptr] = v4;
          histk[v24] = v22;
          stkptr = v24 + 1;
        }
        if ( v21 >= v6 )
          goto LABEL_56;
        v4 = lo;
        v5 = width;
        hi = v6;
      }
      else
      {
        if ( v21 < v6 )
        {
          v23 = stkptr;
          lostk[stkptr] = v21;
          histk[v23] = v6;
          stkptr = v23 + 1;
        }
        if ( v4 >= v22 )
        {
LABEL_56:
          v5 = width;
LABEL_57:
          v25 = --stkptr;
          if ( stkptr < 0 )
            return;
          v26 = lostk[v25];
          v27 = histk[v25];
          lo = v26;
          hi = v27;
          v6 = v27;
          v4 = v26;
        }
        else
        {
          v6 = hi;
          v5 = width;
          lo = v4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAE2B
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, void *lpreserved)
{
  vgui::Panel *v4; // ecx
  vgui::Panel *v5; // ecx
  unsigned __int8 *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, unsigned __int8 *); // eax
  unsigned int v9; // [esp-8h] [ebp-30h]
  unsigned __int8 *v10; // [esp-4h] [ebp-2Ch]

  if ( dwReason == 1 )
  {
    if ( !_heap_init() )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_5:
      vgui::Panel::PostChildPaint(this: v4);
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = __crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_7:
      _mtterm();
      goto LABEL_5;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_7;
    }
    ++_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v6 = calloc(count: 1u, size: 0x214u);
      v7 = (_tiddata *)v6;
      if ( v6 == nullptr )
        return 0;
      v10 = v6;
      v9 = __flsindex;
      v8 = (int (__stdcall *)(unsigned int, unsigned __int8 *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v8(a1: v9, a2: v10) == 0 )
      {
        free(pMem: v7);
        return 0;
      }
      _initptd(ptd: v7, ptloci: nullptr);
      v7->_tid = GetCurrentThreadId();
      v7->_thandle = -1;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == nullptr )
    {
      _ioterm();
      _mtterm();
      vgui::Panel::PostChildPaint(this: v5);
      if ( __flsindex != -1 )
        _mtterm();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DAF8F
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && _proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x100DB085
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x100DB0A8
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x100DB2D3
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100DB2FE
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00480570
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006712E0
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1007E050
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004684A0
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace vp4

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103DBD50
// Name: public: class vgui::IToolWindowFactory __near * vgui::ToolWindow::GetToolWindowFactory(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall vgui::ToolWindow::GetToolWindowFactory(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace client
