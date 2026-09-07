// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/faceposertoolwindow.cpp
// Functions: 32
// ============================================================

#include "utils\hlfaceposer\faceposertoolwindow.h"

//------------------------------------------------------------------------------
// Address: 0x00456440
// Name: public: virtual class mxWindow __near * IFacePoserToolWindow::GetMxWindow(void)
// Source: json
//------------------------------------------------------------------------------
mxWindow *__thiscall IFacePoserToolWindow::GetMxWindow(IFacePoserToolWindow *this)
{
  return (mxWindow *)__RTDynamicCast(
                       inptr: this,
                       VfDelta: 0,
                       SrcType: &IFacePoserToolWindow `RTTI Type Descriptor',
                       TargetType: &mxWindow `RTTI Type Descriptor',
                       isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00456460
// Name: public: static void IFacePoserToolWindow::SetActiveTool(class IFacePoserToolWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IFacePoserToolWindow::SetActiveTool(IFacePoserToolWindow *tool)
{
  mxWidget *v1; // eax
  HWND Handle; // eax
  mxWindow *v3; // eax
  HWND v4; // eax

  if ( tool != IFacePoserToolWindow::s_pActiveTool && IFacePoserToolWindow::s_pActiveTool != nullptr )
  {
    v1 = (mxWidget *)((int (*)(void))IFacePoserToolWindow::s_pActiveTool->GetMxWindow)();
    Handle = (HWND)mxWidget::getHandle(this: v1);
    InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
    v3 = tool->GetMxWindow(this: tool);
    v4 = (HWND)mxWidget::getHandle(this: v3);
    InvalidateRect(hWnd: v4, lpRect: nullptr, bErase: true);
  }
  IFacePoserToolWindow::s_pActiveTool = tool;
}

//------------------------------------------------------------------------------
// Address: 0x004564F0
// Name: public: void IFacePoserToolWindow::SetUseForMainWindowTitle(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::SetUseForMainWindowTitle(IFacePoserToolWindow *this, bool use)
{
  this->m_bUseForMainWindowTitle = use;
  if ( use )
    mxWidget::setLabel(this: g_MDLViewer, format: this->m_szWindowTitle);
}

//------------------------------------------------------------------------------
// Address: 0x00456520
// Name: private: void IFacePoserToolWindow::ComputeNewTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::ComputeNewTitle(IFacePoserToolWindow *this)
{
  mxWidget *v2; // eax
  const char *v3; // [esp-4h] [ebp-Ch]

  V_snprintf(
    pDest: this->m_szWindowTitle,
    maxLen: 192,
    pFormat: "%s%s%s",
    this->m_szPrefix,
    this->m_szDisplayRoot,
    this->m_szSuffix);
  if ( this->GetMxWindow(this) != nullptr )
  {
    v2 = (mxWidget *)((int (__thiscall *)(IFacePoserToolWindow *, char *))this->GetMxWindow)(
                       a1: this,
                       a2: this->m_szWindowTitle);
    mxWidget::setLabel(this: v2, format: v3);
  }
  if ( this->m_bUseForMainWindowTitle )
    mxWidget::setLabel(this: g_MDLViewer, format: this->m_szWindowTitle);
}

//------------------------------------------------------------------------------
// Address: 0x00456590
// Name: TranslateToolPos
// Source: json
//------------------------------------------------------------------------------
char __usercall TranslateToolPos@<al>(
        const char *toolname@<edi>,
        int workspacew,
        int workspaceh,
        int *x,
        int *y,
        int *w,
        int *h,
        bool *locked)
{
  ToolTranslate *v8; // esi

  v8 = s_ToolTranslate;
  while ( _V_stricmp(s1: toolname, s2: v8->toolname) != 0 )
  {
    if ( (int)++v8 >= (int)&vec2_invalid_52 )
      return 0;
  }
  *x = (int)(float)((float)(v8->xfrac * (float)workspacew) + 0.5);
  *y = (int)(float)((float)(v8->yfrac * (float)workspaceh) + 0.5);
  *w = (int)(float)((float)(v8->wfrac * (float)workspacew) + 0.5);
  *h = (int)(float)((float)(v8->hfrac * (float)workspaceh) + 0.5);
  *locked = v8->locked;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00456640
// Name: public: void IFacePoserToolWindow::SavePosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::SavePosition(IFacePoserToolWindow *this)
{
  mxWindow *v2; // eax
  mxWindow *v3; // eax
  int x_low; // edi
  mxWindow *v5; // eax
  int y_low; // ebx
  mxWindow *v7; // eax
  mxWindow *v8; // eax
  mxWindow *(__thiscall *GetMxWindow)(IFacePoserToolWindow *); // edx
  mxWidget *v10; // eax
  mxWindow *v11; // eax
  mxWindow *Parent; // eax
  HWND Handle; // eax
  bool v14; // al
  tagPOINT pt; // [esp+Ch] [ebp-14h] BYREF
  BOOL visible; // [esp+14h] [ebp-Ch]
  int width; // [esp+18h] [ebp-8h]
  int height; // [esp+1Ch] [ebp-4h]

  v2 = this->GetMxWindow(this);
  LOBYTE(visible) = mxWidget::isVisible(this: v2);
  v3 = this->GetMxWindow(this);
  x_low = mxWidget::x(this: v3);
  v5 = this->GetMxWindow(this);
  y_low = mxWidget::y(this: v5);
  v7 = this->GetMxWindow(this);
  width = mxWidget::w(this: v7);
  v8 = this->GetMxWindow(this);
  height = mxWidget::h(this: v8);
  GetMxWindow = this->GetMxWindow;
  pt.x = x_low;
  pt.y = y_low;
  v10 = GetMxWindow(this);
  if ( mxWidget::getParent(this: v10) != nullptr )
  {
    v11 = this->GetMxWindow(this);
    Parent = mxWidget::getParent(this: v11);
    Handle = (HWND)mxWidget::getHandle(this: Parent);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    x_low = SLOWORD(pt.x);
    y_low = SLOWORD(pt.y);
  }
  v14 = this->IsLocked(this);
  FacePoser_SaveWindowPositions(
    name: this->m_szToolName,
    visible,
    x: x_low,
    y: y_low,
    w: width,
    h: height,
    locked: v14,
    zoomed: false);
}

//------------------------------------------------------------------------------
// Address: 0x00456720
// Name: public: virtual bool IFacePoserToolWindow::IsLocked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IFacePoserToolWindow::IsLocked(IFacePoserToolWindow *this)
{
  mxWindow *v1; // eax

  v1 = this->GetMxWindow(this);
  return v1 != nullptr && !FacePoser_HasWindowStyle(w: v1, bits: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x00456750
// Name: public: void IFacePoserToolWindow::ToggleLockedState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::ToggleLockedState(IFacePoserToolWindow *this)
{
  mxWindow *v2; // eax
  mxWindow *v3; // esi
  bool isVisible; // bl

  v2 = this->GetMxWindow(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    isVisible = mxWidget::isVisible(this: v2);
    if ( this->IsLocked(this) )
    {
      FacePoser_MakeToolWindow(w: v3, smallcaption: true);
    }
    else
    {
      FacePoser_RemoveWindowStyle(w: v3, removebits: 13565952);
      FacePoser_AddWindowExStyle(w: v3, addbits: 768);
    }
    mxWidget::setVisible(this: v3, b: false);
    if ( isVisible )
      mxWidget::setVisible(this: v3, b: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004567C0
// Name: private: void IFacePoserToolWindow::GetCloseRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::GetCloseRect(IFacePoserToolWindow *this, tagRECT *rc)
{
  mxWindow *v2; // eax
  int v3; // ecx

  v2 = this->GetMxWindow(this);
  if ( v2 != nullptr )
  {
    v3 = mxWidget::w2(this: v2) - 2;
    rc->right = v3;
    rc->left = v3 - 8;
    rc->top = 2;
    rc->bottom = 10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456800
// Name: public: virtual int IFacePoserToolWindow::GetCaptionHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFacePoserToolWindow::GetCaptionHeight(IFacePoserToolWindow *this)
{
  return this->IsLocked(this) ? 0xC : 0;
}

//------------------------------------------------------------------------------
// Address: 0x00456820
// Name: public: void IFacePoserToolWindow::SetAutoProcess(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::SetAutoProcess(IFacePoserToolWindow *this, bool autoprocess)
{
  this->m_bAutoProcess = autoprocess;
}

//------------------------------------------------------------------------------
// Address: 0x00456830
// Name: public: bool IFacePoserToolWindow::IsActiveTool(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IFacePoserToolWindow::IsActiveTool(IFacePoserToolWindow *this)
{
  return this == IFacePoserToolWindow::s_pActiveTool;
}

//------------------------------------------------------------------------------
// Address: 0x00456840
// Name: public: void IFacePoserToolWindow::SetSuffix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::SetSuffix(IFacePoserToolWindow *this, const char *suffix)
{
  V_snprintf(pDest: this->m_szSuffix, maxLen: 128, pFormat: "%s", suffix);
  IFacePoserToolWindow::ComputeNewTitle(this);
}

//------------------------------------------------------------------------------
// Address: 0x00456870
// Name: public: void IFacePoserToolWindow::SetPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::SetPrefix(IFacePoserToolWindow *this, const char *prefix)
{
  V_snprintf(pDest: this->m_szPrefix, maxLen: 32, pFormat: "%s", prefix);
  IFacePoserToolWindow::ComputeNewTitle(this);
}

//------------------------------------------------------------------------------
// Address: 0x004568A0
// Name: public: static int IFacePoserToolWindow::GetToolCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IFacePoserToolWindow::GetToolCount()
{
  return g_Tools.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004568B0
// Name: private: void IFacePoserToolWindow::GetLockRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::GetLockRect(IFacePoserToolWindow *this, tagRECT *rc)
{
  mxWindow *v3; // eax
  int v4; // eax

  if ( this->GetMxWindow(this) != nullptr )
  {
    v3 = this->GetMxWindow(this);
    if ( v3 != nullptr )
    {
      v4 = mxWidget::w2(this: v3) - 2;
      rc->right = v4;
      rc->left = v4 - 8;
      rc->top = 2;
      rc->bottom = 10;
    }
    OffsetRect(lprc: rc, dx: -12, dy: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456910
// Name: public: virtual bool IFacePoserToolWindow::HandleToolEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IFacePoserToolWindow::HandleToolEvent(IFacePoserToolWindow *this, mxEvent *event)
{
  int v3; // eax
  bool result; // al
  mxWindow *v6; // eax
  HWND v7; // edi
  mxWindow *v8; // eax
  HWND v9; // eax
  mxWindow *v10; // eax
  mxWidget *v11; // ebx
  HWND Handle; // eax
  HWND v13; // eax
  int v14; // eax
  IFacePoserToolWindow_vtbl *v15; // edx
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // eax
  int v17; // eax
  int x_low; // ebx
  int y; // edi
  mxWindow *v20; // esi
  bool isVisible; // al
  POINT v22; // [esp-8h] [ebp-54h]
  tagRECT closeRect; // [esp+Ch] [ebp-40h] BYREF
  tagRECT lockRect; // [esp+1Ch] [ebp-30h] BYREF
  tagRECT captionRect; // [esp+2Ch] [ebp-20h] BYREF
  tagPOINT pt; // [esp+3Ch] [ebp-10h]
  mxWindow *w; // [esp+44h] [ebp-8h]
  bool handled; // [esp+4Bh] [ebp-1h]
  bool isup_3; // [esp+57h] [ebp+Bh]

  v3 = event->event;
  handled = false;
  switch ( v3 )
  {
    case 6:
    case 7:
      isup_3 = v3 == 6;
      v10 = this->GetMxWindow(this);
      v11 = v10;
      w = v10;
      if ( !isup_3 )
      {
        if ( v10 == nullptr )
          goto LABEL_27;
        Handle = (HWND)mxWidget::getHandle(this: v10);
        SetFocus(hWnd: Handle);
        v13 = (HWND)mxWidget::getHandle(this: v11);
        SetWindowPos(hWnd: v13, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
        IFacePoserToolWindow::SetActiveTool(tool: this);
      }
      if ( v11 == nullptr )
        goto LABEL_27;
      if ( !this->IsLocked(this) )
        goto LABEL_27;
      captionRect.left = 0;
      v14 = mxWidget::w2(this: v11);
      v15 = this->__vftable;
      captionRect.right = v14;
      GetCaptionHeight = v15->GetCaptionHeight;
      captionRect.top = 0;
      v17 = GetCaptionHeight(this);
      x_low = SLOWORD(event->x);
      captionRect.bottom = v17;
      v22.y = SLOWORD(event->y);
      v22.x = x_low;
      pt.y = v22.y;
      if ( !PtInRect(lprc: &captionRect, pt: v22) )
        goto LABEL_27;
      handled = !isup_3;
      if ( (event->buttons & 2) != 0 && isup_3 )
        IFacePoserToolWindow::ToggleLockedState(this);
      IFacePoserToolWindow::GetLockRect(this, rc: &lockRect);
      IFacePoserToolWindow::GetCloseRect(this, rc: &closeRect);
      y = pt.y;
      if ( PtInRect(lprc: &lockRect, pt: (POINT)__PAIR64__(pt.y, x_low)) && isup_3 )
        IFacePoserToolWindow::ToggleLockedState(this);
      if ( !PtInRect(lprc: &closeRect, pt: (POINT)__PAIR64__(y, x_low)) || !isup_3 )
        goto LABEL_27;
      v20 = w;
      isVisible = mxWidget::isVisible(this: w);
      mxWidget::setVisible(this: v20, b: !isVisible);
      MDLViewer::UpdateWindowMenu(this: g_MDLViewer);
      return handled;
    case 13:
    case 16:
      IFacePoserToolWindow::SetActiveTool(tool: this);
      goto LABEL_27;
    case 15:
      if ( (event->buttons & 2) == 0 )
        goto LABEL_27;
      IFacePoserToolWindow::ToggleLockedState(this);
      handled = true;
      result = true;
      break;
    case 19:
      MDLViewer::UpdateWindowMenu(this: g_MDLViewer);
      handled = true;
      return true;
    case 20:
      IFacePoserToolWindow::SetActiveTool(tool: this);
      v8 = this->GetMxWindow(this);
      if ( v8 != nullptr )
      {
        v9 = (HWND)mxWidget::getHandle(this: v8);
        SetFocus(hWnd: v9);
      }
      handled = true;
      return true;
    case 22:
      v6 = this->GetMxWindow(this);
      if ( v6 != nullptr )
      {
        v7 = (HWND)mxWidget::getHandle(this: v6);
        SetFocus(hWnd: v7);
        SetWindowPos(hWnd: v7, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
        IFacePoserToolWindow::SetActiveTool(tool: this);
      }
      handled = true;
      return true;
    default:
LABEL_27:
      result = handled;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456B80
// Name: public: virtual void IFacePoserToolWindow::HandleToolRedraw(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::HandleToolRedraw(IFacePoserToolWindow *this, CChoreoWidgetDrawHelper *helper)
{
  mxWindow *v3; // eax
  int v4; // eax
  CChoreoWidgetDrawHelper *v5; // esi
  DWORD SysColor; // eax
  DWORD v7; // eax
  tagRECT rcClient; // [esp+4h] [ebp-44h] BYREF
  tagRECT lockRect; // [esp+14h] [ebp-34h] BYREF
  tagRECT closeRect; // [esp+24h] [ebp-24h] BYREF
  tagRECT captionRect; // [esp+34h] [ebp-14h] BYREF
  Color textColor; // [esp+44h] [ebp-4h] BYREF

  if ( this->IsLocked(this) && this->GetMxWindow(this) != nullptr )
  {
    ++this->m_nToolFrameCount;
    IFacePoserToolWindow::GetLockRect(this, rc: &lockRect);
    v3 = this->GetMxWindow(this);
    if ( v3 != nullptr )
    {
      v4 = mxWidget::w2(this: v3);
      closeRect.right = v4 - 2;
      closeRect.left = v4 - 10;
      closeRect.top = 2;
      closeRect.bottom = 10;
    }
    v5 = helper;
    CChoreoWidgetDrawHelper::GetClientRect(this: helper, rc: &captionRect);
    rcClient = captionRect;
    captionRect.bottom = captionRect.top + 12;
    SysColor = GetSysColor(nIndex: 7);
    *(_WORD *)textColor._color = SysColor;
    textColor._color[2] = BYTE2(SysColor);
    textColor._color[3] = 0;
    if ( this == IFacePoserToolWindow::s_pActiveTool )
      v7 = GetSysColor(nIndex: 2);
    else
      v7 = GetSysColor(nIndex: 3);
    LOWORD(helper) = v7;
    HIWORD(helper) = BYTE2(v7);
    CChoreoWidgetDrawHelper::DrawFilledRect(this: v5, clr: (const Color *)&helper, rc: &captionRect);
    ++captionRect.top;
    InflateRect(lprc: &captionRect, dx: -2, dy: 0);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: v5,
      font: "Small Fonts",
      pointsize: 9,
      weight: 400,
      clr: &textColor,
      rcText: &captionRect,
      fmt: this->m_szWindowTitle);
    ++lockRect.bottom;
    OffsetRect(lprc: &lockRect, dx: 1, dy: 1);
    CChoreoWidgetDrawHelper::DrawColoredTextCharset(
      this: v5,
      font: "Marlett",
      pointsize: (Color)8,
      weight: 400,
      charset: 2u,
      clr: &textColor,
      rcText: &lockRect,
      fmt: "v");
    ++closeRect.bottom;
    CChoreoWidgetDrawHelper::DrawOutlinedRect(this: v5, clr: &textColor, style: 0, width: (HBRUSH__ *)1, rc: &closeRect);
    OffsetRect(lprc: &closeRect, dx: 1, dy: 1);
    CChoreoWidgetDrawHelper::DrawColoredTextCharset(
      this: v5,
      font: "Marlett",
      pointsize: (Color)8,
      weight: 400,
      charset: 2u,
      clr: &textColor,
      rcText: &closeRect,
      fmt: "r");
    rcClient.top += captionRect.bottom;
    CChoreoWidgetDrawHelper::StartClipping(this: v5, clipRect: &rcClient);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456D40
// Name: public: static class IFacePoserToolWindow __near * IFacePoserToolWindow::GetTool(int)
// Source: json
//------------------------------------------------------------------------------
IFacePoserToolWindow *__cdecl IFacePoserToolWindow::GetTool(int index)
{
  return g_Tools.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x00456D60
// Name: public: static void IFacePoserToolWindow::InitTools(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IFacePoserToolWindow::InitTools()
{
  int m_Size; // ebx
  int i; // edi
  IFacePoserToolWindow *v2; // esi
  mxWindow *v3; // eax
  mxWidget *v4; // eax
  const char *v5; // [esp-8h] [ebp-10h]

  m_Size = g_Tools.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v2 = g_Tools.m_Memory.m_pMemory[i];
    v3 = v2->GetMxWindow(this: v2);
    FacePoser_MakeToolWindow(w: v3, smallcaption: true);
    v4 = (mxWidget *)((int (__thiscall *)(IFacePoserToolWindow *, char *))v2->GetMxWindow)(
                       a1: v2,
                       a2: v2->m_szWindowTitle);
    mxWidget::setLabel(this: v4, format: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456DB0
// Name: public: static void IFacePoserToolWindow::ShutdownTools(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IFacePoserToolWindow::ShutdownTools()
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_Tools.m_Size;
  for ( i = 0; i < m_Size; ++i )
    g_Tools.m_Memory.m_pMemory[i]->Shutdown(this: g_Tools.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00456DE0
// Name: public: static bool IFacePoserToolWindow::IsAnyToolScrubbing(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IFacePoserToolWindow::IsAnyToolScrubbing()
{
  int v0; // esi
  int m_Size; // edi

  v0 = 0;
  m_Size = g_Tools.m_Size;
  if ( g_Tools.m_Size <= 0 )
    return 0;
  while ( !g_Tools.m_Memory.m_pMemory[v0]->IsScrubbing(this: g_Tools.m_Memory.m_pMemory[v0]) )
  {
    if ( ++v0 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00456E20
// Name: public: static bool IFacePoserToolWindow::IsAnyToolProcessing(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IFacePoserToolWindow::IsAnyToolProcessing()
{
  int v0; // esi
  int m_Size; // edi

  v0 = 0;
  m_Size = g_Tools.m_Size;
  if ( g_Tools.m_Size <= 0 )
    return 0;
  while ( !g_Tools.m_Memory.m_pMemory[v0]->IsProcessing(this: g_Tools.m_Memory.m_pMemory[v0]) )
  {
    if ( ++v0 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00456E60
// Name: public: static void IFacePoserToolWindow::ModelChanged(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IFacePoserToolWindow::ModelChanged()
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_Tools.m_Size;
  for ( i = 0; i < m_Size; ++i )
    g_Tools.m_Memory.m_pMemory[i]->OnModelChanged(this: g_Tools.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00456F00
// Name: public: static class IFacePoserToolWindow __near * IFacePoserToolWindow::GetActiveTool(void)
// Source: json
//------------------------------------------------------------------------------
IFacePoserToolWindow *__cdecl IFacePoserToolWindow::GetActiveTool()
{
  IFacePoserToolWindow *result; // eax

  result = IFacePoserToolWindow::s_pActiveTool;
  if ( IFacePoserToolWindow::s_pActiveTool == nullptr )
  {
    if ( g_Tools.m_Size <= 0 )
      return nullptr;
    else
      return *g_Tools.m_Memory.m_pMemory;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456F20
// Name: public: virtual IFacePoserToolWindow::~IFacePoserToolWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::~IFacePoserToolWindow(IFacePoserToolWindow *this)
{
  IFacePoserToolWindow *src; // [esp+0h] [ebp-4h] BYREF

  this->__vftable = (IFacePoserToolWindow_vtbl *)&IFacePoserToolWindow::`vftable';
  src = this;
  CUtlVector<IFacePoserToolWindow *,CUtlMemory<IFacePoserToolWindow *,int>>::FindAndRemove(this: &g_Tools, &src);
}

//------------------------------------------------------------------------------
// Address: 0x00456F40
// Name: public: void IFacePoserToolWindow::LoadPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFacePoserToolWindow::LoadPosition(IFacePoserToolWindow *this)
{
  char *m_szToolName; // edi
  int v3; // eax
  int v4; // esi
  int v5; // eax
  mxWindow *v6; // eax
  bool v7; // al
  mxWindow *v8; // eax
  int v9; // [esp-1Ch] [ebp-3Ch]
  int v10; // [esp-10h] [ebp-30h]
  int v11; // [esp-Ch] [ebp-2Ch]
  int v12; // [esp-8h] [ebp-28h]
  int v13; // [esp-4h] [ebp-24h]
  bool v14; // [esp-4h] [ebp-24h]
  BOOL visible; // [esp+8h] [ebp-18h] BYREF
  int x; // [esp+Ch] [ebp-14h] BYREF
  int y; // [esp+10h] [ebp-10h] BYREF
  int w; // [esp+14h] [ebp-Ch] BYREF
  int h; // [esp+18h] [ebp-8h] BYREF
  bool zoomed; // [esp+1Eh] [ebp-2h] BYREF
  bool locked; // [esp+1Fh] [ebp-1h] BYREF

  m_szToolName = this->m_szToolName;
  FacePoser_LoadWindowPositions(name: this->m_szToolName, (bool *)&visible, &x, &y, &w, &h, &locked, &zoomed);
  if ( w == 0 || h == 0 )
  {
    v3 = 0;
    if ( g_Tools.m_Size > 0 )
    {
      while ( g_Tools.m_Memory.m_pMemory[v3] != this )
      {
        if ( ++v3 >= g_Tools.m_Size )
          goto LABEL_9;
      }
      if ( v3 == 0 )
        s_nToolCount = 0;
    }
LABEL_9:
    zoomed = false;
    locked = false;
    LOBYTE(visible) = 1;
    w = (int)((double)mxWidget::w2(this: g_MDLViewer) * 0.5);
    h = (int)((double)mxWidget::h2(this: g_MDLViewer) * 0.5);
    v4 = 20 * s_nToolCount;
    x = (int)(float)((float)((float)mxWidget::w2(this: g_MDLViewer) * 0.25) + (float)v4);
    y = v4;
    v9 = mxWidget::h2(this: g_MDLViewer);
    v5 = mxWidget::w2(this: g_MDLViewer);
    if ( TranslateToolPos(toolname: m_szToolName, workspacew: v5, workspaceh: v9, &x, &y, &w, &h, &locked) == 0 )
    {
      ++s_nToolCount;
      LOBYTE(visible) = 0;
    }
  }
  v13 = h;
  v12 = w;
  v11 = y;
  v10 = x;
  v6 = this->GetMxWindow(this);
  mxWidget::setBounds(this: v6, x: v10, y: v11, w: v12, h: v13);
  v7 = this->IsLocked(this);
  if ( locked != v7 )
    IFacePoserToolWindow::ToggleLockedState(this);
  v14 = visible;
  v8 = this->GetMxWindow(this);
  mxWidget::setVisible(this: v8, b: v14);
}

//------------------------------------------------------------------------------
// Address: 0x004570D0
// Name: public: static bool IFacePoserToolWindow::ShouldAutoProcess(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IFacePoserToolWindow::ShouldAutoProcess()
{
  IFacePoserToolWindow *v0; // eax

  v0 = IFacePoserToolWindow::s_pActiveTool;
  if ( IFacePoserToolWindow::s_pActiveTool != nullptr )
    return v0->m_bAutoProcess;
  if ( g_Tools.m_Size > 0 && (v0 = *g_Tools.m_Memory.m_pMemory, *g_Tools.m_Memory.m_pMemory != nullptr) )
    return v0->m_bAutoProcess;
  else
    return false;
}

//------------------------------------------------------------------------------
// Address: 0x00457140
// Name: public: static void IFacePoserToolWindow::ToolThink(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IFacePoserToolWindow::ToolThink(float dt)
{
  int m_Size; // edi
  int v2; // esi
  IFacePoserToolWindow *v3; // eax
  int v4; // edi
  int i; // esi
  StudioModel *v6; // eax

  m_Size = g_Tools.m_Size;
  v2 = 0;
  if ( g_Tools.m_Size > 0 )
  {
    do
      ((void (__stdcall *)(_DWORD))g_Tools.m_Memory.m_pMemory[v2++]->Think)(a1: LODWORD(dt));
    while ( v2 < m_Size );
    m_Size = g_Tools.m_Size;
  }
  v3 = IFacePoserToolWindow::s_pActiveTool;
  if ( IFacePoserToolWindow::s_pActiveTool == nullptr
    && (m_Size <= 0 || (v3 = *g_Tools.m_Memory.m_pMemory, *g_Tools.m_Memory.m_pMemory == nullptr))
    || !v3->m_bAutoProcess )
  {
    v4 = models->Count(this: models);
    for ( i = 0; i < v4; ++i )
    {
      v6 = models->GetStudioModel(this: models, a2: i);
      if ( v6 != nullptr )
        ((void (__thiscall *)(StudioModel *, _DWORD))v6->AdvanceFrame)(a1: v6, a2: LODWORD(dt));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004571E0
// Name: public: static void IFacePoserToolWindow::EnableToolRedraw(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IFacePoserToolWindow::EnableToolRedraw(bool enabled)
{
  IMDLCache *v1; // ebx
  int m_Size; // edi
  int i; // esi
  mxWindow *v4; // eax
  IFacePoserToolWindow **m_pMemory; // eax

  v1 = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  IFacePoserToolWindow::s_bToolsCanDraw = enabled;
  if ( enabled )
  {
    m_Size = s_NeedRedraw.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      v4 = s_NeedRedraw.m_Memory.m_pMemory[i]->GetMxWindow(this: s_NeedRedraw.m_Memory.m_pMemory[i]);
      v4->redraw(this: v4);
    }
    m_pMemory = s_NeedRedraw.m_Memory.m_pMemory;
    s_NeedRedraw.m_Size = 0;
    if ( s_NeedRedraw.m_Memory.m_nGrowSize >= 0 )
    {
      if ( s_NeedRedraw.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_NeedRedraw.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        s_NeedRedraw.m_Memory.m_pMemory = nullptr;
      }
      s_NeedRedraw.m_Memory.m_nAllocationCount = 0;
    }
    s_NeedRedraw.m_pElements = m_pMemory;
  }
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00457280
// Name: public: IFacePoserToolWindow::IFacePoserToolWindow(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IFacePoserToolWindow *__thiscall IFacePoserToolWindow::IFacePoserToolWindow(
        IFacePoserToolWindow *this,
        const char *toolname,
        const char *displaynameroot)
{
  int m_Size; // eax
  int v5; // edi
  IFacePoserToolWindow **m_pMemory; // ecx
  int v7; // eax
  IFacePoserToolWindow **v8; // eax

  this->__vftable = (IFacePoserToolWindow_vtbl *)&IFacePoserToolWindow::`vftable';
  *(_WORD *)&this->m_bUseForMainWindowTitle = 0;
  V_strncpy(pDest: this->m_szToolName, pSrc: toolname, maxLen: 128);
  this->m_szPrefix[0] = 0;
  this->m_szSuffix[0] = 0;
  V_snprintf(pDest: this->m_szDisplayRoot, maxLen: 128, pFormat: "%s", displaynameroot);
  IFacePoserToolWindow::ComputeNewTitle(this);
  m_Size = g_Tools.m_Size;
  v5 = g_Tools.m_Size;
  if ( g_Tools.m_Size + 1 > g_Tools.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_Tools,
      num: g_Tools.m_Size - g_Tools.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Tools.m_Size;
  }
  m_pMemory = g_Tools.m_Memory.m_pMemory;
  g_Tools.m_Size = m_Size + 1;
  v7 = m_Size - v5;
  g_Tools.m_pElements = g_Tools.m_Memory.m_pMemory;
  if ( v7 > 0 )
  {
    _V_memmove(dest: &g_Tools.m_Memory.m_pMemory[v5 + 1], src: &g_Tools.m_Memory.m_pMemory[v5], count: 4 * v7);
    m_pMemory = g_Tools.m_Memory.m_pMemory;
  }
  v8 = &m_pMemory[v5];
  if ( v8 != nullptr )
    *v8 = this;
  this->m_nToolFrameCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00457350
// Name: public: bool IFacePoserToolWindow::ToolCanDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall IFacePoserToolWindow::ToolCanDraw(IFacePoserToolWindow *this)
{
  int m_Size; // eax
  IFacePoserToolWindow **m_pMemory; // edx
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  IFacePoserToolWindow **v7; // eax

  if ( IFacePoserToolWindow::s_bToolsCanDraw )
    return 1;
  m_Size = s_NeedRedraw.m_Size;
  m_pMemory = s_NeedRedraw.m_Memory.m_pMemory;
  v4 = 0;
  if ( s_NeedRedraw.m_Size <= 0 )
    goto LABEL_7;
  while ( s_NeedRedraw.m_Memory.m_pMemory[v4] != this )
  {
    if ( ++v4 >= s_NeedRedraw.m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    v5 = s_NeedRedraw.m_Size;
    if ( s_NeedRedraw.m_Size + 1 > s_NeedRedraw.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_NeedRedraw,
        num: s_NeedRedraw.m_Size - s_NeedRedraw.m_Memory.m_nAllocationCount + 1);
      m_Size = s_NeedRedraw.m_Size;
      m_pMemory = s_NeedRedraw.m_Memory.m_pMemory;
    }
    s_NeedRedraw.m_Size = m_Size + 1;
    v6 = m_Size - v5;
    s_NeedRedraw.m_pElements = m_pMemory;
    if ( v6 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v6);
      m_pMemory = s_NeedRedraw.m_Memory.m_pMemory;
    }
    v7 = &m_pMemory[v5];
    if ( v7 != nullptr )
      *v7 = this;
  }
  return 0;
}
