// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/mxexpressiontray.cpp
// Functions: 30
// ============================================================

#include "utils\hlfaceposer\mxexpressiontray.h"

//------------------------------------------------------------------------------
// Address: 0x004663D0
// Name: public: void mxExpressionTray::Deselect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::Deselect(mxExpressionTray *this)
{
  CExpClass *v2; // eax
  CExpClass *v3; // esi
  int v4; // edi
  CExpression *Expression; // eax

  v2 = expressions->GetActiveClass(this: expressions);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = 0;
    if ( CExpClass::GetNumExpressions(this: v2) > 0 )
    {
      do
      {
        Expression = CExpClass::GetExpression(this: v3, num: v4);
        if ( Expression != nullptr )
          CExpression::SetSelected(this: Expression, selected: false);
        ++v4;
      }
      while ( v4 < CExpClass::GetNumExpressions(this: v3) );
    }
  }
  this->m_nPrevCell = -1;
  this->m_nCurCell = -1;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00466440
// Name: public: void mxExpressionTray::Select(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::Select(mxExpressionTray *this, int exp, bool deselect)
{
  int m_nCurCell; // edi
  CExpClass *v5; // eax
  CExpression *Expression; // eax

  m_nCurCell = this->m_nCurCell;
  if ( deselect )
    mxExpressionTray::Deselect(this);
  this->m_nPrevCell = m_nCurCell;
  this->m_nCurCell = exp;
  if ( exp >= 0 )
  {
    v5 = expressions->GetActiveClass(this: expressions);
    if ( v5 != nullptr )
    {
      Expression = CExpClass::GetExpression(this: v5, num: this->m_nCurCell);
      if ( Expression != nullptr )
        CExpression::SetSelected(this: Expression, selected: true);
    }
  }
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x004664B0
// Name: private: void mxExpressionTray::AddButton(char const __near *,char const __near *,char const __near *,void (mxExpressionTray::*)(int),bool,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::AddButton(
        mxExpressionTray *this,
        const char *name,
        const char *tooltip,
        const char *bitmap,
        void (__thiscall *__ptr64 pfnCallback)(mxExpressionTray *this, int),
        bool active,
        int x,
        int y,
        int w,
        int h)
{
  mxExpressionTray::mxETButton *v11; // esi
  mxbitmapdata_t *v12; // eax

  v11 = (mxExpressionTray::mxETButton *)operator new(nSize: 0xC8u);
  strcpy(v11->m_szName, name);
  strcpy(v11->m_szToolTip, tooltip);
  v11->m_bActive = active;
  v11->m_rc.left = x;
  v11->m_rc.top = y;
  v11->m_rc.right = w + x;
  v11->m_rc.bottom = h + y;
  v12 = (mxbitmapdata_t *)operator new(nSize: 0x10u);
  if ( v12 != nullptr )
  {
    v12->valid = false;
    v12->image = nullptr;
    v12->width = 0;
    v12->height = 0;
  }
  else
  {
    v12 = nullptr;
  }
  v11->m_pImage = v12;
  v12->valid = false;
  LoadBitmapFromFile(relative: bitmap, bitmap: v11->m_pImage);
  v11->m_fnCallback = pfnCallback;
  v11->next = this->m_pButtons;
  this->m_pButtons = v11;
}

//------------------------------------------------------------------------------
// Address: 0x00466580
// Name: private: class mxExpressionTray::mxETButton __near * mxExpressionTray::FindButton(char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxExpressionTray::mxETButton *__thiscall mxExpressionTray::FindButton(mxExpressionTray *this, const char *name)
{
  mxExpressionTray::mxETButton *m_pButtons; // esi

  m_pButtons = this->m_pButtons;
  if ( m_pButtons == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: m_pButtons->m_szName, s2: name) != 0 )
  {
    m_pButtons = m_pButtons->next;
    if ( m_pButtons == nullptr )
      return nullptr;
  }
  return m_pButtons;
}

//------------------------------------------------------------------------------
// Address: 0x004665C0
// Name: private: void mxExpressionTray::DeleteAllButtons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::DeleteAllButtons(mxExpressionTray *this)
{
  mxExpressionTray::mxETButton *m_pButtons; // esi
  mxExpressionTray::mxETButton *next; // edi

  m_pButtons = this->m_pButtons;
  if ( m_pButtons != nullptr )
  {
    do
    {
      next = m_pButtons->next;
      free(pMem: m_pButtons->m_pImage);
      free(pMem: m_pButtons);
      m_pButtons = next;
    }
    while ( next != nullptr );
  }
  this->m_pButtons = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00466600
// Name: private: int mxExpressionTray::ComputePixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxExpressionTray::ComputePixelsNeeded(mxExpressionTray *this)
{
  CExpClass *v2; // ebx
  int v4; // edi
  int v5; // eax
  int m_nGap; // edi

  v2 = expressions->GetActiveClass(this: expressions);
  if ( v2 == nullptr )
    return 100;
  v4 = (mxWidget::w2(this) - 16 - this->m_nGap) / (this->m_nGap + this->m_nSnapshotWidth);
  if ( v4 < 1 )
    v4 = 1;
  v5 = (CExpClass::GetNumExpressions(this: v2) + v4 - 1) / v4;
  m_nGap = this->m_nGap;
  return v5 * (m_nGap + this->m_nSnapshotHeight)
       + m_nGap
       + this->GetCaptionHeight(this: &this->IFacePoserToolWindow)
       + 45;
}

//------------------------------------------------------------------------------
// Address: 0x00466680
// Name: private: bool mxExpressionTray::ComputeRect(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall mxExpressionTray::ComputeRect(mxExpressionTray *this, int cell, int *rcx, int *rcy, int *rcw, int *rch)
{
  int v7; // eax
  int m_nGap; // ecx
  int m_nSnapshotWidth; // ebx
  int v10; // edi
  int v11; // edx
  int v12; // edi
  int v14; // ebx
  int cella; // [esp+14h] [ebp+8h]

  v7 = mxWidget::w2(this);
  m_nGap = this->m_nGap;
  m_nSnapshotWidth = this->m_nSnapshotWidth;
  v10 = (v7 - 16 - m_nGap) / (m_nGap + m_nSnapshotWidth);
  if ( v10 < 1 )
    v10 = 1;
  v11 = cell % v10;
  cella = cell / v10;
  *rcx = m_nGap + v11 * (m_nGap + m_nSnapshotWidth);
  v12 = this->m_nGap;
  *rcy = cella * (v12 + this->m_nSnapshotHeight)
       - this->m_nTopOffset * this->m_nGranularity
       + v12
       + this->GetCaptionHeight(this: &this->IFacePoserToolWindow)
       + 45;
  if ( *rcx < 0 )
    return 0;
  if ( this->m_nSnapshotWidth + this->m_nGap + *rcx > mxWidget::w2(this) )
    return 0;
  v14 = *rcy;
  if ( v14 > mxWidget::h2(this) || this->m_nSnapshotHeight + v14 + this->m_nGap < 0 )
    return 0;
  *rcw = this->m_nSnapshotWidth;
  *rch = this->m_nSnapshotHeight;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00466780
// Name: private: int mxExpressionTray::GetCellUnderPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxExpressionTray::GetCellUnderPosition(mxExpressionTray *this, int x, int y)
{
  CExpClass *v4; // eax
  int v6; // eax
  int m_nGap; // ecx
  int m_nSnapshotWidth; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // ebx
  int m_nSnapshotHeight; // ecx
  CExpClass *active; // [esp+4h] [ebp-Ch]
  int c; // [esp+Ch] [ebp-4h]

  v4 = expressions->GetActiveClass(this: expressions);
  active = v4;
  if ( v4 == nullptr )
    return -1;
  c = 0;
  if ( CExpClass::GetNumExpressions(this: v4) <= 0 )
    return -1;
  while ( 1 )
  {
    v6 = mxWidget::w2(this);
    m_nGap = this->m_nGap;
    m_nSnapshotWidth = this->m_nSnapshotWidth;
    v9 = (v6 - 16 - m_nGap) / (m_nGap + m_nSnapshotWidth);
    if ( v9 < 1 )
      v9 = 1;
    v10 = c / v9;
    v11 = c % v9;
    v12 = m_nGap + m_nSnapshotWidth;
    v13 = this->m_nGap;
    v14 = m_nGap + v11 * v12;
    v15 = v10 * (v13 + this->m_nSnapshotHeight)
        - this->m_nTopOffset * this->m_nGranularity
        + v13
        + this->GetCaptionHeight(this: &this->IFacePoserToolWindow)
        + 45;
    if ( v14 >= 0 && this->m_nSnapshotWidth + v14 + this->m_nGap <= mxWidget::w2(this) && v15 <= mxWidget::h2(this) )
    {
      m_nSnapshotHeight = this->m_nSnapshotHeight;
      if ( v15 + m_nSnapshotHeight + this->m_nGap >= 0
        && x >= v14
        && x <= this->m_nSnapshotWidth + v14
        && y >= v15
        && y <= m_nSnapshotHeight + v15 )
      {
        break;
      }
    }
    if ( ++c >= CExpClass::GetNumExpressions(this: active) )
      return -1;
  }
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x004668B0
// Name: private: void mxExpressionTray::RepositionSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::RepositionSlider(mxExpressionTray *this)
{
  int v2; // ebx
  int v3; // eax
  mxScrollbar *slScrollbar; // ecx
  int v5; // eax
  int v6; // eax
  mxScrollbar *v7; // ecx
  int v8; // [esp-Ch] [ebp-20h]
  int rangepixels; // [esp+Ch] [ebp-8h]
  int heightpixelsa; // [esp+10h] [ebp-4h]
  int heightpixels; // [esp+10h] [ebp-4h]

  heightpixelsa = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  v2 = mxWidget::h2(this) - heightpixelsa;
  heightpixels = v2 / this->m_nGranularity;
  v3 = mxExpressionTray::ComputePixelsNeeded(this);
  slScrollbar = this->slScrollbar;
  rangepixels = v3 / this->m_nGranularity;
  if ( rangepixels >= heightpixels )
  {
    mxWidget::setVisible(this: slScrollbar, b: true);
  }
  else
  {
    this->m_nTopOffset = 0;
    mxWidget::setVisible(this: slScrollbar, b: false);
  }
  v8 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 45;
  v5 = mxWidget::w2(this);
  mxWidget::setBounds(this: this->slScrollbar, x: v5 - 16, y: v8, w: 16, h: v2 - 45);
  v6 = this->m_nTopOffset < 0 ? 0 : this->m_nTopOffset;
  this->m_nTopOffset = v6;
  if ( rangepixels < v6 )
    v6 = rangepixels;
  v7 = this->slScrollbar;
  this->m_nTopOffset = v6;
  mxScrollbar::setRange(this: v7, min: 0, max: rangepixels);
  mxScrollbar::setValue(this: this->slScrollbar, ivalue: this->m_nTopOffset);
  mxScrollbar::setPagesize(this: this->slScrollbar, size: heightpixels);
}

//------------------------------------------------------------------------------
// Address: 0x004669A0
// Name: public: void mxExpressionTray::AB(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::AB(mxExpressionTray *this)
{
  CExpClass *v2; // eax
  CExpClass *v3; // esi
  int m_nPrevCell; // edi

  if ( this->m_nPrevCell != -1 || this->m_nCurCell != -1 )
  {
    v2 = expressions->GetActiveClass(this: expressions);
    v3 = v2;
    if ( v2 != nullptr && this->m_nPrevCell >= 0 )
    {
      m_nPrevCell = this->m_nPrevCell;
      if ( m_nPrevCell < CExpClass::GetNumExpressions(this: v2) )
        CExpClass::SelectExpression(this: v3, num: m_nPrevCell, deselect: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466A00
// Name: private: void mxExpressionTray::ShowRightClickMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::ShowRightClickMenu(mxExpressionTray *this, int mx, int my)
{
  CExpClass *v3; // ebx
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // edi
  CExpression *Expression; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax

  v3 = expressions->GetActiveClass(this: expressions);
  if ( v3 != nullptr )
  {
    v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v4 != nullptr )
      v5 = mxPopupMenu::mxPopupMenu(this: v4);
    else
      v5 = nullptr;
    Expression = nullptr;
    if ( this->m_nClickedCell != -1 )
      Expression = CExpClass::GetExpression(this: v3, num: this->m_nClickedCell);
    mxPopupMenu::add(this: v5, item: "New Expression...", id: 1002);
    if ( Expression != nullptr )
    {
      mxMenu::addSeparator(this: v5);
      v7 = va(fmt: "Edit '%s'...", Expression->name);
      mxPopupMenu::add(this: v5, item: v7, id: 1003);
      v8 = va(fmt: "Save '%s'", Expression->name);
      mxPopupMenu::add(this: v5, item: v8, id: 1004);
      if ( CExpression::CanUndo(this: Expression) || CExpression::CanRedo(this: Expression) )
      {
        v9 = va(fmt: "Revert '%s'", Expression->name);
        mxPopupMenu::add(this: v5, item: v9, id: 1012);
      }
      mxMenu::addSeparator(this: v5);
      v10 = va(fmt: "Delete '%s'", Expression->name);
      mxPopupMenu::add(this: v5, item: v10, id: 1005);
      mxMenu::addSeparator(this: v5);
      v11 = va(fmt: "Re-create thumbnail for '%s'", Expression->name);
      mxPopupMenu::add(this: v5, item: v11, id: 1017);
    }
    mxPopupMenu::popup(this: v5, widget: this, x: mx, y: my);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466B40
// Name: private: void mxExpressionTray::DrawFocusRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::DrawFocusRect(mxExpressionTray *this)
{
  HDC DC; // esi

  DC = GetDC(hWnd: nullptr);
  DrawFocusRect(hDC: DC, lprc: &this->m_rcFocus);
  ReleaseDC(hWnd: nullptr, hDC: DC);
}

//------------------------------------------------------------------------------
// Address: 0x00466B70
// Name: IsWindowOrChild
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsWindowOrChild@<al>(mxWindow *parent@<ecx>, HWND test@<esi>)
{
  HWND__ *Handle; // eax

  Handle = (HWND__ *)mxWidget::getHandle(this: parent);
  return test == Handle || IsChild(hWndParent: Handle, hWnd: test);
}

//------------------------------------------------------------------------------
// Address: 0x00466B90
// Name: private: void mxExpressionTray::ET_Undo(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::ET_Undo(mxExpressionTray *this, int cell)
{
  ControlPanel::UndoExpression(this: g_pControlPanel, index: cell);
}

//------------------------------------------------------------------------------
// Address: 0x00466BA0
// Name: private: void mxExpressionTray::ET_Redo(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::ET_Redo(mxExpressionTray *this, int cell)
{
  ControlPanel::RedoExpression(this: g_pControlPanel, index: cell);
}

//------------------------------------------------------------------------------
// Address: 0x00466BB0
// Name: public: void mxExpressionTray::ThumbnailIncrease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::ThumbnailIncrease(mxExpressionTray *this)
{
  int v2; // eax
  int m_nSnapshotWidth; // eax
  int v4; // ecx

  v2 = this->m_nSnapshotWidth + 4;
  if ( v2 <= 256 )
  {
    this->m_nSnapshotWidth = v2;
    g_viewerSettings.thumbnailsize = v2;
    m_nSnapshotWidth = this->m_nSnapshotWidth;
    v4 = m_nSnapshotWidth + this->m_nDescriptionHeight;
    this->m_nSnapshotHeight = v4;
    Con_Printf(a1: (Color)v4, fmt: "Thumbnail size %i x %i\n", m_nSnapshotWidth, m_nSnapshotWidth);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466C00
// Name: public: void mxExpressionTray::ThumbnailDecrease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::ThumbnailDecrease(mxExpressionTray *this)
{
  int v2; // eax
  int m_nSnapshotWidth; // eax
  int v4; // ecx

  v2 = this->m_nSnapshotWidth - 4;
  if ( v2 >= 64 )
  {
    this->m_nSnapshotWidth = v2;
    g_viewerSettings.thumbnailsize = v2;
    m_nSnapshotWidth = this->m_nSnapshotWidth;
    v4 = m_nSnapshotWidth + this->m_nDescriptionHeight;
    this->m_nSnapshotHeight = v4;
    Con_Printf(a1: (Color)v4, fmt: "Thumbnail size %i x %i\n", m_nSnapshotWidth, m_nSnapshotWidth);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466C50
// Name: public: void mxExpressionTray::RestoreThumbnailSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::RestoreThumbnailSize(mxExpressionTray *this)
{
  int thumbnailsize; // eax
  mxExpressionTray_vtbl *v2; // eax

  thumbnailsize = g_viewerSettings.thumbnailsize;
  this->m_nSnapshotWidth = g_viewerSettings.thumbnailsize;
  if ( thumbnailsize < 64 )
    thumbnailsize = 64;
  this->m_nSnapshotWidth = thumbnailsize;
  if ( thumbnailsize > 256 )
    thumbnailsize = 256;
  this->m_nSnapshotWidth = thumbnailsize;
  g_viewerSettings.thumbnailsize = thumbnailsize;
  v2 = this->mxWindow::mxWidget::__vftable;
  this->m_nSnapshotHeight = this->m_nSnapshotWidth + this->m_nDescriptionHeight;
  ((void (*)(void))v2->redraw)();
}

//------------------------------------------------------------------------------
// Address: 0x00466CA0
// Name: public: void mxExpressionTray::ReloadBitmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::ReloadBitmaps(mxExpressionTray *this)
{
  int v2; // edi
  int i; // esi
  CExpClass *v4; // eax

  v2 = expressions->GetNumClasses(this: expressions);
  EnableStickySnapshotMode();
  for ( i = 0; i < v2; ++i )
  {
    v4 = expressions->GetClass(this: expressions, a2: i);
    if ( v4 != nullptr )
      CExpClass::ReloadBitmaps(this: v4);
  }
  DisableStickySnapshotMode();
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00466CF0
// Name: bool IsUsingPerPlayerExpressions(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsUsingPerPlayerExpressions()
{
  int v0; // eax
  bool result; // al
  bool v2; // zf
  char pSearchPath[2048]; // [esp+4h] [ebp-800h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(
         a1: v0,
         a2: "-perplayerexpressions",
         a3: 0) != 0 )
    return true;
  if ( g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAME", a3: false, a4: pSearchPath, a5: 2048) == 0 )
    return false;
  V_FixSlashes(pname: pSearchPath, separator: 92);
  v2 = V_stristr(pStr: pSearchPath, pSearch: "\\tf") == nullptr;
  result = true;
  if ( v2 )
    return false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00466D70
// Name: public: virtual void mxExpressionTray::OnModelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::OnModelChanged(mxExpressionTray *this)
{
  const char *v2; // eax
  const char *v3; // eax
  int thumbnailsize; // eax
  void (__thiscall *v5)(char *); // eax
  char fn[260]; // [esp+4h] [ebp-208h] BYREF
  char rootDir[260]; // [esp+108h] [ebp-104h] BYREF

  if ( IsUsingPerPlayerExpressions() )
  {
    _Msg(a1: "Closing current phoneme set\n");
    if ( ControlPanel::Closeall(this: g_pControlPanel) == 0 )
      return;
    v2 = models->GetActiveModelName(this: models);
    V_snprintf(pDest: fn, maxLen: 260, pFormat: "expressions/%s/phonemes/phonemes.txt", v2);
    v3 = models->GetActiveModelName(this: models);
    V_snprintf(pDest: rootDir, maxLen: 260, pFormat: "%s/phonemes/", v3);
    FacePoser_SetPhonemeRootDir(pchRootDir: rootDir);
    FacePoser_EnsurePhonemesLoaded();
  }
  mxExpressionTray::ReloadBitmaps(this: (mxExpressionTray *)((char *)this - 12));
  thumbnailsize = g_viewerSettings.thumbnailsize;
  this->m_nButtonSquare = g_viewerSettings.thumbnailsize;
  if ( thumbnailsize < 64 )
    thumbnailsize = 64;
  this->m_nButtonSquare = thumbnailsize;
  if ( thumbnailsize > 256 )
    thumbnailsize = 256;
  this->m_nButtonSquare = thumbnailsize;
  g_viewerSettings.thumbnailsize = thumbnailsize;
  v5 = *(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 16);
  this->m_nGap = this->m_nButtonSquare + this->m_nClickedCell;
  v5(a1: (char *)this - 12);
}

//------------------------------------------------------------------------------
// Address: 0x00466E80
// Name: private: void mxExpressionTray::CreateButtons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::CreateButtons(mxExpressionTray *this)
{
  int v2; // edi
  int m_nButtonSquare; // [esp-8h] [ebp-10h]

  m_nButtonSquare = this->m_nButtonSquare;
  v2 = this->m_nSnapshotWidth - (2 * m_nButtonSquare + 8);
  mxExpressionTray::AddButton(
    this,
    name: "undo",
    tooltip: "Undo",
    bitmap: "gfx/hlfaceposer/undo.bmp",
    pfnCallback: (void (__thiscall *__ptr64)(mxExpressionTray *, int))(unsigned int)mxExpressionTray::ET_Undo,
    active: true,
    x: v2,
    y: 4,
    w: m_nButtonSquare,
    h: m_nButtonSquare);
  mxExpressionTray::AddButton(
    this,
    name: "redo",
    tooltip: "Redo",
    bitmap: "gfx/hlfaceposer/redo.bmp",
    pfnCallback: (void (__thiscall *__ptr64)(mxExpressionTray *, int))(unsigned int)mxExpressionTray::ET_Redo,
    active: true,
    x: this->m_nButtonSquare + v2 + 4,
    y: 4,
    w: this->m_nButtonSquare,
    h: this->m_nButtonSquare);
}

//------------------------------------------------------------------------------
// Address: 0x00466EF0
// Name: private: class mxExpressionTray::mxETButton __near * mxExpressionTray::GetItemUnderCursor(int,int)
// Source: json
//------------------------------------------------------------------------------
mxExpressionTray::mxETButton *__thiscall mxExpressionTray::GetItemUnderCursor(mxExpressionTray *this, int x, int y)
{
  int v3; // ebx
  int CellUnderPosition; // eax
  mxExpressionTray::mxETButton *result; // eax
  int v7; // edx
  int rch; // [esp+8h] [ebp-Ch] BYREF
  int cw; // [esp+Ch] [ebp-8h] BYREF
  int rcx; // [esp+10h] [ebp-4h] BYREF

  v3 = y;
  CellUnderPosition = mxExpressionTray::GetCellUnderPosition(this, x, y);
  if ( CellUnderPosition == -1
    || mxExpressionTray::ComputeRect(this, cell: CellUnderPosition, &rcx, rcy: &y, rcw: &cw, &rch) == 0 )
  {
    return nullptr;
  }
  result = this->m_pButtons;
  if ( result == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( result->m_bActive && x >= rcx && x <= rcx + cw && v3 >= y && v3 <= y + rch )
    {
      v7 = v3 - y;
      if ( x - rcx >= result->m_rc.left
        && x - rcx <= result->m_rc.right
        && v7 >= result->m_rc.top
        && v7 <= result->m_rc.bottom )
      {
        break;
      }
    }
    result = result->next;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00466FA0
// Name: private: void mxExpressionTray::DrawButton(class CChoreoWidgetDrawHelper __near &,int,class mxExpressionTray::mxETButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::DrawButton(
        mxExpressionTray *this,
        CChoreoWidgetDrawHelper *helper,
        int cell,
        mxExpressionTray::mxETButton *btn)
{
  mxExpressionTray::mxETButton *v4; // esi
  mxbitmapdata_t *m_pImage; // eax
  int top; // ecx
  int left; // eax
  int v8; // ebx
  int v9; // edi
  HDC NumChannels; // eax
  mxbitmapdata_t *v11; // ecx
  int v12; // esi
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  v4 = btn;
  if ( btn != nullptr )
  {
    m_pImage = btn->m_pImage;
    if ( m_pImage != nullptr
      && m_pImage->valid
      && btn->m_bActive
      && mxExpressionTray::ComputeRect(this, cell, rcx: &cell, rcy: (int *)&btn, rcw: &w, rch: &h) != 0 )
    {
      top = v4->m_rc.top;
      left = v4->m_rc.left;
      btn = (mxExpressionTray::mxETButton *)((char *)btn + top);
      cell += left;
      v8 = v4->m_rc.bottom - top;
      v9 = v4->m_rc.right - left;
      NumChannels = (HDC)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)helper);
      v11 = v4->m_pImage;
      v12 = cell;
      DrawBitmapToDC(hdc: NumChannels, x: cell, y: (int)btn, w: v9, h: v8, bitmap: v11);
      cell = 11184810;
      CChoreoWidgetDrawHelper::DrawOutlinedRect(
        this: helper,
        clr: (HBRUSH__ *)&cell,
        style: 0,
        width: (HBRUSH__ *)1,
        x1: v12,
        y1: (int)btn,
        x2: v12 + v9,
        y2: (int)btn + v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467060
// Name: private: void mxExpressionTray::DrawExpressionDescription(class CChoreoWidgetDrawHelper __near &,int,int,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::DrawExpressionDescription(
        mxExpressionTray *this,
        CChoreoWidgetDrawHelper *helper,
        int x,
        int y,
        int w,
        int h,
        const char *expressionname,
        const char *description)
{
  tagRECT textRect; // [esp+8h] [ebp-10h] BYREF

  textRect.left = x + 5;
  textRect.top = y + h - 42;
  textRect.right = x + w - 10;
  textRect.bottom = y + h - 12;
  x = 0;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: helper,
    font: "Arial",
    pointsize: 9,
    weight: 400,
    clr: (const Color *)&x,
    rcText: &textRect,
    fmt: "%s",
    expressionname);
  OffsetRect(lprc: &textRect, dx: 0, dy: 15);
  x = 4144959;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: helper,
    font: "Arial",
    pointsize: 9,
    weight: 400,
    clr: (const Color *)&x,
    rcText: &textRect,
    fmt: "%s",
    description);
}

//------------------------------------------------------------------------------
// Address: 0x00467100
// Name: private: void mxExpressionTray::DrawDirtyFlag(class CChoreoWidgetDrawHelper __near &,class CExpression __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::DrawDirtyFlag(
        mxExpressionTray *this,
        CChoreoWidgetDrawHelper *helper,
        CExpression *current,
        int rcx,
        int rcy,
        int rcw,
        int rch)
{
  CExpression *v7; // esi
  tagRECT textRect; // [esp+4h] [ebp-10h] BYREF

  v7 = current;
  if ( current != nullptr && (CExpression::CanUndo(this: current) || CExpression::GetDirty(this: v7)) )
  {
    textRect.right = rcw + rcx;
    textRect.top = rcy + 5;
    textRect.bottom = rcy + 21;
    textRect.left = rcx + 5;
    current = (CExpression *)16773220;
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: helper,
      font: "Arial",
      pointsize: 14,
      weight: 400,
      clr: (const Color *)&current,
      rcText: &textRect,
      fmt: "*");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467180
// Name: private: void mxExpressionTray::DrawThumbNail(class CExpClass __near *,class CExpression __near *,class CChoreoWidgetDrawHelper __near &,int,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTray::DrawThumbNail(
        mxExpressionTray *this,
        CExpClass *active,
        CExpression *current,
        int helper,
        int rcx,
        int rcy,
        int rcw,
        int rch,
        int c,
        int selected,
        int updateselection)
{
  CChoreoWidgetDrawHelper *v11; // ebx
  DWORD SysColor; // eax
  int v13; // esi
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  mxExpressionTray *v18; // eax
  int v19; // ecx
  mxExpressionTray::mxETButton *Button; // eax
  mxExpressionTray::mxETButton *v21; // eax
  int m_nButtonSquare; // eax
  int v23; // eax
  int v24; // ecx
  int v25; // [esp-10h] [ebp-28h]
  tagRECT rc; // [esp+0h] [ebp-18h] BYREF
  HDC__ *dc; // [esp+10h] [ebp-8h]
  mxExpressionTray *v28; // [esp+14h] [ebp-4h]

  v28 = this;
  if ( current != nullptr )
  {
    v11 = (CChoreoWidgetDrawHelper *)helper;
    dc = (HDC__ *)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)helper);
    SysColor = GetSysColor(nIndex: 15);
    v13 = rcx;
    v14 = rcy;
    LOWORD(helper) = SysColor;
    HIWORD(helper) = BYTE2(SysColor);
    rcx += rcw;
    CChoreoWidgetDrawHelper::DrawFilledRect(
      this: v11,
      clr: (const Color *)&helper,
      x1: v13,
      y1: rcy,
      x2: rcx,
      y2: rcy + rch);
    if ( current->m_Bitmap[models->GetActiveModelIndex(this: models)].valid )
    {
      v15 = models->GetActiveModelIndex(this: models);
      DrawBitmapToDC(
        hdc: dc,
        x: v13,
        y: v14,
        w: rcw,
        h: rch - v28->m_nDescriptionHeight,
        bitmap: &current->m_Bitmap[v15]);
      v16 = v14 - v28->m_nDescriptionHeight;
      helper = 8355711;
      CChoreoWidgetDrawHelper::DrawOutlinedRect(
        this: v11,
        clr: (HBRUSH__ *)&helper,
        style: 0,
        width: (HBRUSH__ *)1,
        x1: v13,
        y1: v14,
        x2: rcx,
        y2: rch + v16);
    }
    mxExpressionTray::DrawDirtyFlag(this: v28, helper: v11, current, rcx: v13, rcy: v14, rcw, rch);
    mxExpressionTray::DrawExpressionDescription(
      this: v28,
      helper: v11,
      x: v13,
      y: v14,
      w: rcw,
      h: rch,
      expressionname: current->name,
      description: current->description);
    if ( c == selected )
    {
      v17 = v14 - v28->m_nDescriptionHeight;
      helper = 4154623;
      CChoreoWidgetDrawHelper::DrawOutlinedRect(
        this: v11,
        clr: (HBRUSH__ *)&helper,
        style: 0,
        width: (HBRUSH__ *)4,
        x1: v13,
        y1: v14,
        x2: rcx,
        y2: rch + v17);
      if ( (_BYTE)updateselection != 0 )
      {
        v18 = v28;
        v19 = c;
        v28->m_nPrevCell = -1;
        v18->m_nCurCell = v19;
      }
      if ( CExpression::CanUndo(this: current) || CExpression::CanRedo(this: current) )
      {
        if ( CExpression::CanUndo(this: current) )
        {
          Button = mxExpressionTray::FindButton(this: v28, name: "undo");
          mxExpressionTray::DrawButton(this: v28, helper: v11, cell: c, btn: Button);
        }
        if ( CExpression::CanRedo(this: current) )
        {
          v21 = mxExpressionTray::FindButton(this: v28, name: "redo");
          mxExpressionTray::DrawButton(this: v28, helper: v11, cell: c, btn: v21);
        }
        m_nButtonSquare = v28->m_nButtonSquare;
        rc.left = rcw + v13 - (2 * m_nButtonSquare + 8);
        rc.top = m_nButtonSquare + v14 + 6;
        rc.right = rcw + v13;
        rc.bottom = m_nButtonSquare + v14 + 21;
        updateselection = 13158600;
        v25 = CExpression::UndoLevels(this: current);
        v23 = CExpression::UndoCurrent(this: current);
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v11,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: (const Color *)&updateselection,
          rcText: &rc,
          fmt: "%i/%i",
          v23,
          v25);
      }
    }
    else if ( CExpression::GetSelected(this: current) )
    {
      v24 = v14 - v28->m_nDescriptionHeight;
      updateselection = 14450559;
      CChoreoWidgetDrawHelper::DrawOutlinedRect(
        this: v11,
        clr: (HBRUSH__ *)&updateselection,
        style: 0,
        width: (HBRUSH__ *)4,
        x1: v13,
        y1: v14,
        x2: rcx,
        y2: rch + v24);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467400
// Name: public: virtual void mxExpressionTray::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall mxExpressionTray::redraw(mxExpressionTray *this@<ecx>, int a2@<esi>)
{
  CExpClass *(__thiscall *GetActiveClass)(IExpressionManager *); // edx
  CExpClass *v4; // eax
  CExpClass *v5; // esi
  DWORD SysColor; // eax
  int v7; // eax
  int i; // ebx
  CExpression *Expression; // eax
  int v10; // eax
  char sz[256]; // [esp+8h] [ebp-190h] BYREF
  CChoreoWidgetDrawHelper helper; // [esp+108h] [ebp-90h] BYREF
  tagRECT rc; // [esp+160h] [ebp-38h] BYREF
  int rch; // [esp+170h] [ebp-28h] BYREF
  int rcw; // [esp+174h] [ebp-24h] BYREF
  int rcx; // [esp+178h] [ebp-20h] BYREF
  int rcy; // [esp+17Ch] [ebp-1Ch] BYREF
  tagRECT rcText; // [esp+180h] [ebp-18h] BYREF
  int updateSelection; // [esp+190h] [ebp-8h]
  int selected; // [esp+194h] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) != 0 )
  {
    GetActiveClass = expressions->GetActiveClass;
    LOBYTE(updateSelection) = 0;
    v4 = (CExpClass *)((int (__thiscall *)(IExpressionManager *, int))GetActiveClass)(a1: expressions, a2);
    v5 = v4;
    if ( v4 != nullptr && CExpClass::GetNumExpressions(this: v4) != this->m_nPreviousExpressionCount )
    {
      this->m_nTopOffset = 0;
      mxExpressionTray::RepositionSlider(this);
      this->m_nPreviousExpressionCount = CExpClass::GetNumExpressions(this: v5);
    }
    SysColor = GetSysColor(nIndex: 15);
    LOWORD(selected) = SysColor;
    HIWORD(selected) = BYTE2(SysColor);
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &helper, widget: this, bgColor: (const Color *)&selected);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &helper);
    mxWidget::w2(this);
    mxWidget::h2(this);
    if ( v5 != nullptr )
    {
      CChoreoWidgetDrawHelper::GetClientRect(this: &helper, rc: &rcText);
      v7 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rcText.top += v7 + 45;
      CChoreoWidgetDrawHelper::StartClipping(this: &helper, clipRect: &rcText);
      if ( this->m_nLastNumExpressions != CExpClass::GetNumExpressions(this: v5) )
      {
        this->m_nTopOffset = 0;
        this->m_nLastNumExpressions = CExpClass::GetNumExpressions(this: v5);
        mxExpressionTray::RepositionSlider(this);
        LOBYTE(updateSelection) = 1;
      }
      selected = CExpClass::GetSelectedExpression(this: v5);
      for ( i = 0; i < CExpClass::GetNumExpressions(this: v5); ++i )
      {
        if ( mxExpressionTray::ComputeRect(this, cell: i, &rcx, &rcy, &rcw, &rch) != 0 )
        {
          Expression = CExpClass::GetExpression(this: v5, num: i);
          if ( Expression == nullptr )
            break;
          mxExpressionTray::DrawThumbNail(
            this,
            active: v5,
            current: Expression,
            (int)&helper,
            rcx,
            rcy,
            rcw,
            rch,
            c: i,
            selected,
            updateselection: updateSelection);
        }
      }
      CChoreoWidgetDrawHelper::StopClipping(this: &helper);
      CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &helper);
    }
    else
    {
      CChoreoWidgetDrawHelper::GetClientRect(this: &helper, &rc);
      sprintf(string: sz, format: "No expression file loaded");
      v10 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)0x12, weight: 400, fmt: sz);
      rcText.top = (rc.bottom - rc.top) / 2 - 9;
      rcText.bottom = rcText.top + 28;
      rcText.left = rc.left + (rc.right - rc.left - v10) / 2;
      rcText.right = v10 + rcText.left;
      selected = (int)&atan_tbl[406];
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &helper,
        font: "Arial",
        pointsize: 18,
        weight: 400,
        clr: (const Color *)&selected,
        &rcText,
        fmt: sz);
      CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &helper);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467660
// Name: public: virtual int mxExpressionTray::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxExpressionTray::handleEvent(mxExpressionTray *this, CExpression *event)
{
  void (*BeginLock)(void); // edx
  CExpression *v4; // esi
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  int v7; // eax
  int v8; // edi
  int m_nClickedCell; // edi
  int v10; // edi
  int v11; // eax
  int v12; // esi
  void (__thiscall *redraw)(struct mxExpressionTray *); // eax
  int v14; // esi
  int MinValue; // eax
  HWND Handle; // eax
  void (__thiscall *v17)(struct mxExpressionTray *); // eax
  CExpClass *v18; // eax
  CExpClass *v19; // esi
  CExpression *Expression; // ebx
  int v21; // eax
  int v22; // eax
  CExpClass *v23; // esi
  int CellUnderPosition; // ebx
  mxEvent *v25; // ecx
  mxExpressionTray::mxETButton *ItemUnderCursor; // eax
  void (__thiscall *m_fnCallback)(char *, int); // edx
  int v28; // eax
  int v29; // edx
  mxEvent *v30; // ecx
  int v31; // eax
  int v32; // ecx
  HWND v33; // eax
  bool v34; // zf
  CExpClass *v35; // ebx
  int v36; // eax
  HWND v37; // eax
  HWND v38; // esi
  int m_nCurCell; // eax
  int v40; // esi
  int v41; // ebx
  int v42; // edx
  HWND v43; // eax
  int v44; // esi
  int MaxValue; // eax
  IFacePoserToolWindow *tool; // [esp+Ch] [ebp-1Ch]
  tagPOINT Point; // [esp+10h] [ebp-18h] BYREF
  tagPOINT v48; // [esp+18h] [ebp-10h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+20h] [ebp-8h]
  int cy; // [esp+24h] [ebp-4h] BYREF

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  v4 = event;
  HandleToolEvent = this->HandleToolEvent;
  cy = 0;
  tool = &this->IFacePoserToolWindow;
  if ( HandleToolEvent(this: &this->IFacePoserToolWindow, a2: (mxEvent *)event) )
  {
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  switch ( *(_DWORD *)&v4->name[4] )
  {
    case 0:
      v7 = *(_DWORD *)&v4->name[12];
      cy = 1;
      if ( v7 > 5001 )
      {
LABEL_36:
        cy = 0;
      }
      else
      {
        if ( v7 == 5001 )
        {
          v22 = g_pExpressionClass->getSelectedIndex(this: g_pExpressionClass);
          if ( v22 >= 0 )
          {
            v23 = expressions->GetClass(this: expressions, a2: v22);
            if ( v23 != nullptr )
            {
              expressions->ActivateExpressionClass(this: expressions, a2: v23);
              CExpClass::SelectExpression(this: v23, num: 0, deselect: true);
            }
          }
        }
        else
        {
          switch ( v7 )
          {
            case 1001:
              v11 = *(_DWORD *)&v4->description[4];
              if ( v11 == 5 )
              {
                v12 = *(_DWORD *)&v4->name[20];
                mxScrollbar::setValue(this: this->slScrollbar, ivalue: v12);
                redraw = this->redraw;
                this->m_nTopOffset = v12;
                redraw(this);
                break;
              }
              if ( v11 == 2 )
              {
                v14 = mxScrollbar::getValue(this: this->slScrollbar) - this->m_nGranularity;
                if ( v14 > mxScrollbar::getMinValue(this: this->slScrollbar) )
                  goto LABEL_25;
                MinValue = mxScrollbar::getMinValue(this: this->slScrollbar);
                goto LABEL_24;
              }
              if ( v11 != 3 )
                break;
              v14 = this->m_nGranularity + mxScrollbar::getValue(this: this->slScrollbar);
              if ( v14 >= mxScrollbar::getMaxValue(this: this->slScrollbar) )
              {
                MinValue = mxScrollbar::getMaxValue(this: this->slScrollbar);
LABEL_24:
                v14 = MinValue;
              }
LABEL_25:
              mxScrollbar::setValue(this: this->slScrollbar, ivalue: v14);
              Handle = (HWND)mxWidget::getHandle(this: this->slScrollbar);
              InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
              v17 = this->redraw;
              this->m_nTopOffset = v14;
              v17(this);
              break;
            case 1002:
              FlexPanel::NewExpression(this: g_pFlexPanel);
              break;
            case 1003:
              if ( this->m_nClickedCell != -1 )
                FlexPanel::EditExpression(this: g_pFlexPanel);
              break;
            case 1004:
              m_nClickedCell = this->m_nClickedCell;
              if ( m_nClickedCell != -1 )
                FlexPanel::SaveExpression(this: g_pFlexPanel, index: m_nClickedCell);
              break;
            case 1005:
              v10 = this->m_nClickedCell;
              if ( v10 != -1 )
                ControlPanel::DeleteExpression(this: g_pControlPanel, index: v10);
              break;
            case 1012:
              v8 = this->m_nClickedCell;
              if ( v8 != -1 )
                FlexPanel::RevertExpression(this: g_pFlexPanel, index: v8);
              break;
            case 1014:
              mxExpressionTray::AB(this);
              break;
            case 1015:
              mxExpressionTray::ThumbnailIncrease(this);
              break;
            case 1016:
              mxExpressionTray::ThumbnailDecrease(this);
              break;
            case 1017:
              if ( this->m_nClickedCell >= 0 )
              {
                v18 = expressions->GetActiveClass(this: expressions);
                v19 = v18;
                if ( v18 != nullptr )
                {
                  Expression = CExpClass::GetExpression(this: v18, num: this->m_nClickedCell);
                  if ( Expression != nullptr )
                  {
                    CExpClass::SelectExpression(this: v19, num: this->m_nClickedCell, deselect: true);
                    v21 = models->GetActiveModelIndex(this: models);
                    CExpression::CreateNewBitmap(this: Expression, modelindex: v21);
                    this->redraw(this);
                  }
                }
              }
              break;
            default:
              goto LABEL_36;
          }
        }
LABEL_80:
        IFacePoserToolWindow::SetActiveTool(tool);
      }
LABEL_81:
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return cy;
    case 1:
      v40 = mxWidget::w2(this);
      v41 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      mxWidget::setBounds(this: g_pExpressionClass, x: 5, y: v41 + 5, w: v40 - 120, h: 20);
      v41 += 4;
      mxWidget::setBounds(this: this->m_pABButton, x: v40 - 60, y: v41, w: 60, h: 16);
      mxWidget::setBounds(this: this->m_pThumbnailIncreaseButton, x: v40 - 100, y: v41, w: 16, h: 16);
      mxWidget::setBounds(this: this->m_pThumbnailDecreaseButton, x: v40 - 80, y: v41, w: 16, h: 16);
      this->m_nTopOffset = 0;
      goto LABEL_78;
    case 6:
      v34 = (v4->index & 2) == 0;
      cy = 1;
      if ( !v34 )
      {
        this->m_nClickedCell = mxExpressionTray::GetCellUnderPosition(
                                 this,
                                 x: *(__int16 *)&v4->name[24],
                                 y: *(__int16 *)&v4->name[28]);
        mxExpressionTray::ShowRightClickMenu(this, mx: *(__int16 *)&v4->name[24], my: *(__int16 *)&v4->name[28]);
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 1;
      }
      Point.y = mxExpressionTray::GetCellUnderPosition(this, x: *(_DWORD *)&v4->name[24], y: *(_DWORD *)&v4->name[28]);
      v35 = expressions->GetActiveClass(this: expressions);
      if ( this->m_bDragging )
      {
        mxExpressionTray::DrawFocusRect(this);
        this->m_bDragging = false;
        if ( v35 == nullptr )
          goto LABEL_80;
        v36 = *(__int16 *)&v4->name[24];
        v48.y = *(__int16 *)&v4->name[28];
        v48.x = v36;
        v37 = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: v37, lpPoint: &v48);
        v38 = WindowFromPoint(Point: v48);
        event = CExpClass::GetExpression(this: v35, num: this->m_nDragCell);
        if ( event != nullptr
          && v38 != nullptr
          && (IsWindowOrChild(parent: g_pChoreoView, test: v38)
           && CChoreoView::CreateExpressionEvent(this: g_pChoreoView, mx: v48.x, my: v48.y, cl: v35, exp: event) != 0
           || IsWindowOrChild(parent: g_pExpressionTool, test: v38)
           && ExpressionTool::SetFlexAnimationTrackFromExpression(
                this: g_pExpressionTool,
                mx: v48.x,
                my: v48.y,
                cl: v35,
                exp: event) != 0) )
        {
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
      }
      if ( v35 != nullptr && Point.y >= 0 && Point.y < CExpClass::GetNumExpressions(this: v35) )
      {
        m_nCurCell = this->m_nCurCell;
        if ( Point.y != m_nCurCell
          && m_nCurCell != -1
          && CExpClass::GetExpression(this: v35, num: this->m_nCurCell) != nullptr )
        {
          CExpClass::SwapExpressionOrder(this: v35, exp1: this->m_nCurCell, exp2: Point.y);
          CExpClass::SetDirty(this: v35, dirty: true);
          CExpClass::SelectExpression(this: v35, num: Point.y, deselect: true);
        }
      }
      goto LABEL_80;
    case 7:
      if ( (v4->index & 2) != 0 )
        goto LABEL_79;
      CellUnderPosition = mxExpressionTray::GetCellUnderPosition(
                            this,
                            x: *(_DWORD *)&v4->name[24],
                            y: *(_DWORD *)&v4->name[28]);
      v25 = (mxEvent *)expressions->GetActiveClass(this: expressions);
      event = (CExpression *)v25;
      if ( v25 == nullptr )
        goto LABEL_79;
      if ( CellUnderPosition == this->m_nCurCell )
      {
        if ( CellUnderPosition < 0 )
          goto LABEL_50;
        if ( CellUnderPosition < CExpClass::GetNumExpressions(this: (CExpClass *)v25) )
        {
          ItemUnderCursor = mxExpressionTray::GetItemUnderCursor(
                              this,
                              x: *(_DWORD *)&v4->name[24],
                              y: *(_DWORD *)&v4->name[28]);
          if ( ItemUnderCursor != nullptr )
          {
            m_fnCallback = (void (__thiscall *)(char *, int))ItemUnderCursor->m_fnCallback;
            if ( m_fnCallback != nullptr )
            {
              m_fnCallback(a1: (char *)this + HIDWORD(ItemUnderCursor->m_fnCallback), a2: CellUnderPosition);
              cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
              return 0;
            }
          }
        }
        v25 = (mxEvent *)event;
      }
      if ( CellUnderPosition < 0 || CellUnderPosition >= CExpClass::GetNumExpressions(this: (CExpClass *)v25) )
      {
LABEL_50:
        mxExpressionTray::Deselect(this);
        CExpClass::DeselectExpression(this: (CExpClass *)event);
        this->redraw(this);
      }
      else
      {
        CExpClass::SelectExpression(
          this: (CExpClass *)event,
          num: CellUnderPosition,
          deselect: (*(_DWORD *)&v4->description[4] & 2) == 0);
        if ( mxExpressionTray::ComputeRect(
               this,
               cell: CellUnderPosition,
               rcx: (int *)&event,
               rcy: &cy,
               rcw: &v48.y,
               rch: &Point.y) != 0 )
        {
          v28 = cy;
          this->m_bDragging = true;
          this->m_nDragCell = CellUnderPosition;
          this->m_nXStart = *(__int16 *)&v4->name[24];
          v29 = *(__int16 *)&v4->name[28];
          v30 = (mxEvent *)event;
          this->m_rcFocus.top = v28;
          v31 = Point.y + v28 - this->m_nDescriptionHeight;
          this->m_rcFocus.left = (int)v30;
          v32 = (int)v30 + v48.y;
          this->m_rcFocus.bottom = v31;
          Point.y = 0;
          Point.x = 0;
          this->m_rcFocus.right = v32;
          this->m_nYStart = v29;
          v33 = (HWND)mxWidget::getHandle(this);
          ClientToScreen(hWnd: v33, lpPoint: &Point);
          OffsetRect(lprc: &this->m_rcFocus, dx: Point.x, dy: Point.y);
          *(_QWORD *)&this->m_rcOrig.left = *(_QWORD *)&this->m_rcFocus.left;
          *(_QWORD *)&this->m_rcOrig.right = *(_QWORD *)&this->m_rcFocus.right;
          mxExpressionTray::DrawFocusRect(this);
        }
      }
LABEL_79:
      cy = 1;
      goto LABEL_80;
    case 9:
      if ( this->m_bDragging )
      {
        mxExpressionTray::DrawFocusRect(this);
        *(_QWORD *)&this->m_rcFocus.left = *(_QWORD *)&this->m_rcOrig.left;
        *(_QWORD *)&this->m_rcFocus.right = *(_QWORD *)&this->m_rcOrig.right;
        OffsetRect(
          lprc: &this->m_rcFocus,
          dx: *(__int16 *)&v4->name[24] - this->m_nXStart,
          dy: *(__int16 *)&v4->name[28] - this->m_nYStart);
        mxExpressionTray::DrawFocusRect(this);
      }
      goto LABEL_79;
    case 0xC:
      v42 = *(_DWORD *)&v4->name[28];
      Point.x = *(_DWORD *)&v4->name[24];
      Point.y = v42;
      v43 = (HWND)mxWidget::getHandle(this);
      ScreenToClient(hWnd: v43, lpPoint: &Point);
      if ( *(int *)&v4->name[20] >= 0 )
      {
        MaxValue = this->m_nTopOffset - 10 <= 0 ? 0 : this->m_nTopOffset - 10;
      }
      else
      {
        v44 = this->m_nTopOffset + 10;
        if ( v44 >= mxScrollbar::getMaxValue(this: this->slScrollbar) )
          MaxValue = mxScrollbar::getMaxValue(this: this->slScrollbar);
        else
          MaxValue = v44;
      }
      this->m_nTopOffset = MaxValue;
LABEL_78:
      mxExpressionTray::RepositionSlider(this);
      this->redraw(this);
      goto LABEL_79;
    default:
      goto LABEL_81;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467E70
// Name: public: mxExpressionTray::mxExpressionTray(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxExpressionTray *__thiscall mxExpressionTray::mxExpressionTray(mxExpressionTray *this, mxWindow *parent, int id)
{
  mxScrollbar *v4; // eax
  mxScrollbar *v5; // eax
  int thumbnailsize; // eax
  int v7; // eax
  CTabWindow *v8; // eax
  mxExpressionTab *v9; // edi
  mxButton *v10; // eax
  mxButton *v11; // eax
  mxButton *v12; // eax
  mxButton *v13; // eax
  mxButton *v14; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: "ExpressionTrayTool", style: id);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "ExpressionTrayTool",
    displaynameroot: "Expressions");
  this->mxWindow::mxWidget::__vftable = (mxExpressionTray_vtbl *)&mxExpressionTray::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&mxExpressionTray::`vftable'{for `IFacePoserToolWindow'};
  mxWidget::setId(this, id);
  this->m_nTopOffset = 0;
  v4 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxScrollbar::mxScrollbar(this: v4, parent: this, x: 0, y: 0, w: 18, h: 100, id: 1001, style: 1);
  else
    v5 = nullptr;
  this->slScrollbar = v5;
  this->m_nLastNumExpressions = -1;
  this->m_nGranularity = 10;
  this->m_nPrevCell = -1;
  this->m_nCurCell = -1;
  this->m_nClickedCell = -1;
  this->m_nButtonSquare = 16;
  this->m_nGap = 4;
  this->m_nDescriptionHeight = 34;
  thumbnailsize = g_viewerSettings.thumbnailsize;
  this->m_nSnapshotWidth = g_viewerSettings.thumbnailsize;
  if ( thumbnailsize < 64 )
    thumbnailsize = 64;
  this->m_nSnapshotWidth = thumbnailsize;
  if ( thumbnailsize > 256 )
    thumbnailsize = 256;
  this->m_nSnapshotWidth = thumbnailsize;
  g_viewerSettings.thumbnailsize = thumbnailsize;
  v7 = this->m_nSnapshotWidth + this->m_nDescriptionHeight;
  this->m_nPreviousExpressionCount = -1;
  this->m_nDragCell = -1;
  this->m_nSnapshotHeight = v7;
  this->m_pButtons = nullptr;
  this->m_bDragging = false;
  mxExpressionTray::CreateButtons(this);
  v8 = (CTabWindow *)operator new(nSize: 0x54u);
  v9 = (mxExpressionTab *)v8;
  if ( v8 != nullptr )
  {
    CTabWindow::CTabWindow(this: v8, parent: this, x: 5, y: 5, w: 500, h: 20, id: 5001, style: 0);
    v9->__vftable = (mxExpressionTab_vtbl *)&mxExpressionTab::`vftable';
    g_pExpressionClass = v9;
  }
  else
  {
    g_pExpressionClass = nullptr;
  }
  v10 = (mxButton *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxButton::mxButton(this: v10, parent: this, x: 520, y: 8, w: 50, h: 18, label: "A/B", id: 1014);
  else
    v11 = nullptr;
  this->m_pABButton = v11;
  v12 = (mxButton *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v13 = mxButton::mxButton(this: v12, parent: this, x: 0, y: 0, w: 18, h: 18, label: "+", id: 1015);
  else
    v13 = nullptr;
  this->m_pThumbnailIncreaseButton = v13;
  v14 = (mxButton *)operator new(nSize: 0xCu);
  if ( v14 != nullptr )
    this->m_pThumbnailDecreaseButton = mxButton::mxButton(
                                         this: v14,
                                         parent: this,
                                         x: 0,
                                         y: 0,
                                         w: 18,
                                         h: 18,
                                         label: "-",
                                         id: 1016);
  else
    this->m_pThumbnailDecreaseButton = nullptr;
  return this;
}
