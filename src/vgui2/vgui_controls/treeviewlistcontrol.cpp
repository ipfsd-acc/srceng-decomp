// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/treeviewlistcontrol.cpp
// Functions: 20
// ============================================================

#include "vgui2\vgui_controls\treeviewlistcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x102D1030
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x102D1040
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D1090
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102D10C0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x102D10D0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D10F0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102D1100
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102D1110
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        const char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1170
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x102D11A0
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int ImageBuffer; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      ImageBuffer = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * ImageBuffer;
      v16 = top;
      *top = v15;
      v17 = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D12B0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1340
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1430
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  const char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D16D0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D1830
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x102D1870
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1940
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D19A0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1A30
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D1AC0
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10061530
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x10061540
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100615A0
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100615D0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x100615E0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x10061600
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10061610
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10061620
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061680
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x100616B0
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100617C0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061850
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061940
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061BE0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061D10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061D40
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x10061D50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061D80
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061E50
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10061EB0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061F40
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10061FD0
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0044A3D0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0044EC20
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x0044EC30
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044EC90
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0044ECC0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x0044ECD0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044ECF0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0044ED00
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044ED60
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x0044ED90
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EEA0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EF30
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CSteamApplication::PostShutdown(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F020
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F2C0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044F3F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044F420
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x0044F430
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044F460
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F530
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044F590
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F620
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044F6B0
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10079E50
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1007E600
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x1007E610
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007E670
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007E6A0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x1007E6B0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007E770
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1007E780
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E7E0
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x1007E810
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E920
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E9B0
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CSteamApplication::PostShutdown(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EAA0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  const char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ED40
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007EE70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007EEA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x1007EEB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007EEE0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EFB0
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007F010
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F0A0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007F130
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004CA5D0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00626D70
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x00626D80
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00626DD0
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00626E00
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x00626E10
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x00626E30
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00626E40
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        const char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626EA0
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x00626ED0
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int ImageBuffer; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      ImageBuffer = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * ImageBuffer;
      v16 = top;
      *top = v15;
      v17 = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626FE0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627070
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627160
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  const char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627400
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00627560
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x006275A0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627670
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x006276D0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627760
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x006277F0
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D1130
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102D1160
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x102D1190
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102D11B0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1210
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x102D1240
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int ImageBuffer; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      ImageBuffer = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * ImageBuffer;
      v16 = top;
      *top = v15;
      v17 = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1350
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D13E0
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D14D0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1770
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        __m128i *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D18D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x102D1910
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D19E0
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D1A40
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1AD0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D1B60
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1030BDF0
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x1030BE00
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1030BE60
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1030BE90
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x1030BEA0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030BEC0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1030BED0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030BF30
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x1030BF60
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int ImageBuffer; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      ImageBuffer = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * ImageBuffer;
      v16 = top;
      *top = v15;
      v17 = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030C070
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030C100
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030C1F0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030C490
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1030C5C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030C5F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x1030C600
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030C630
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030C700
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1030C760
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030C7F0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1030C880
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103356FF
// Name: public: void CSplitterWnd::SetColumnInfo(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::SetColumnInfo(CSplitterWnd *this, int col, int cxIdeal, int cxMin)
{
  int v4; // eax

  v4 = col;
  this->m_pColInfo[v4].nIdealSize = cxIdeal;
  this->m_pColInfo[v4].nMinSize = cxMin;
}

//------------------------------------------------------------------------------
// Address: 0x104D01F0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10335729
// Name: public: unsigned long CSplitterWnd::GetScrollStyle(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CSplitterWnd::GetScrollStyle(CSplitterWnd *this)
{
  unsigned int result; // eax

  result = 0;
  if ( this->m_bHasHScroll != 0 )
    result = 0x100000;
  if ( this->m_bHasVScroll != 0 )
    result |= 0x200000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10335747
// Name: public: void CSplitterWnd::SetScrollStyle(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::SetScrollStyle(CSplitterWnd *this, unsigned int dwStyle)
{
  unsigned int ScrollStyle; // eax
  int v4; // edx
  int v5; // edi
  CWnd *DlgItem; // eax
  int v7; // edi
  CWnd *v8; // eax
  CWnd *v9; // eax
  CWnd *v10; // eax

  ScrollStyle = CSplitterWnd::GetScrollStyle(this);
  if ( ScrollStyle != v4 )
  {
    this->m_bHasHScroll = (v4 & 0x100000) != 0;
    this->m_bHasVScroll = (v4 & 0x200000) != 0;
    if ( this->m_nCols > 0 )
    {
      v5 = 59904;
      do
      {
        DlgItem = CWnd::GetDlgItem(this, nID: v5);
        if ( DlgItem == nullptr )
        {
          if ( this->CreateScrollBarCtrl(this, a2: 0, a3: v5) == 0 )
            AfxThrowResourceException();
          DlgItem = CWnd::GetDlgItem(this, nID: v5);
        }
        CWnd::ShowWindow(this: DlgItem, nCmdShow: this->m_bHasHScroll != 0 ? 5 : 0);
        ++v5;
      }
      while ( v5 - 59904 < this->m_nCols );
    }
    if ( this->m_nRows > 0 )
    {
      v7 = 59920;
      do
      {
        v8 = CWnd::GetDlgItem(this, nID: v7);
        if ( v8 == nullptr )
        {
          if ( this->CreateScrollBarCtrl(this, a2: 1u, a3: v7) == 0 )
            AfxThrowResourceException();
          v8 = CWnd::GetDlgItem(this, nID: v7);
        }
        CWnd::ShowWindow(this: v8, nCmdShow: this->m_bHasVScroll != 0 ? 5 : 0);
        ++v7;
      }
      while ( v7 - 59920 < this->m_nRows );
    }
    if ( this->m_bHasVScroll != 0 && this->m_bHasHScroll != 0 )
    {
      v9 = CWnd::GetDlgItem(this, nID: 59936);
      if ( v9 == nullptr )
      {
        if ( this->CreateScrollBarCtrl(this, a2: 134217736u, a3: 59936u) == 0 )
          AfxThrowResourceException();
        v9 = CWnd::GetDlgItem(this, nID: 59936);
      }
      CWnd::ShowWindow(this: v9, nCmdShow: 5);
    }
    else
    {
      v10 = CWnd::GetDlgItem(this, nID: 59936);
      if ( v10 != nullptr )
        v10->DestroyWindow(this: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103358A3
// Name: public: virtual void CSplitterWnd::DeleteView(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::DeleteView(CSplitterWnd *this, int row, int col)
{
  CWnd *Pane; // edi

  Pane = CSplitterWnd::GetPane(this, row, col);
  if ( this->GetActivePane(this, a2: 0, a3: 0) == Pane )
    this->ActivateNext(this, a2: 0);
  Pane->DestroyWindow(this: Pane);
}

//------------------------------------------------------------------------------
// Address: 0x103358E4
// Name: int _AfxCanSplitRowCol(struct CSplitterWnd::CRowColInfo __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxCanSplitRowCol(CSplitterWnd::CRowColInfo *pInfoBefore, int nBeforeSize, int nSizeSplitter)
{
  int result; // eax

  if ( nBeforeSize < pInfoBefore->nMinSize )
    return -1;
  result = pInfoBefore->nCurSize - nBeforeSize - nSizeSplitter;
  if ( result < pInfoBefore[1].nMinSize )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10335907
// Name: public: virtual int CSplitterWnd::SplitRow(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::SplitRow(CSplitterWnd *this, int cyBefore)
{
  int m_nRows; // ebx
  int v4; // edi
  int v6; // ebx
  CWnd *DlgItem; // eax
  int cyNew; // [esp+Ch] [ebp-Ch]
  int rowNew; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]
  int cyBeforea; // [esp+20h] [ebp+8h]

  m_nRows = this->m_nRows;
  v4 = m_nRows;
  cyBeforea = cyBefore - this->m_cyBorder;
  rowNew = m_nRows;
  cyNew = _AfxCanSplitRowCol(
            pInfoBefore: &this->m_pRowInfo[m_nRows - 1],
            nBeforeSize: cyBeforea,
            nSizeSplitter: this->m_cySplitter);
  if ( cyNew == -1 || this->m_bHasVScroll != 0 && this->CreateScrollBarCtrl(this, a2: 1u, a3: m_nRows + 59920) == 0 )
    return 0;
  ++this->m_nRows;
  v6 = 0;
  if ( this->m_nCols > 0 )
  {
    v10 = 0;
    while ( ((int (__thiscall *)(CSplitterWnd *, int, int, CRuntimeClass *, int, int, _DWORD))this->CreateView)(
              a1: this,
              a2: rowNew,
              a3: v6,
              a4: this->m_pDynamicViewClass,
              a5: this->m_pColInfo[v10].nCurSize,
              a6: cyNew,
              a7: 0) != 0 )
    {
      ++v10;
      if ( ++v6 >= this->m_nCols )
        goto LABEL_9;
    }
    while ( v6 > 0 )
      this->DeleteView(this, a2: rowNew, a3: --v6);
    if ( this->m_bHasVScroll != 0 )
    {
      DlgItem = CWnd::GetDlgItem(this, nID: rowNew + 59920);
      DlgItem->DestroyWindow(this: DlgItem);
    }
    --this->m_nRows;
    return 0;
  }
LABEL_9:
  this->m_pRowInfo[v4 - 1].nIdealSize = cyBeforea;
  this->m_pRowInfo[v4].nIdealSize = cyNew;
  this->RecalcLayout(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10335A28
// Name: public: virtual int CSplitterWnd::SplitColumn(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::SplitColumn(CSplitterWnd *this, int cxBefore)
{
  int m_nCols; // ebx
  int v4; // edi
  int i; // edi
  CWnd *DlgItem; // eax
  int cxNew; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int row; // [esp+14h] [ebp-4h]
  int cxBeforea; // [esp+20h] [ebp+8h]

  m_nCols = this->m_nCols;
  v4 = m_nCols;
  cxBeforea = cxBefore - this->m_cxBorder;
  cxNew = _AfxCanSplitRowCol(
            pInfoBefore: &this->m_pColInfo[m_nCols - 1],
            nBeforeSize: cxBeforea,
            nSizeSplitter: this->m_cxSplitter);
  if ( cxNew == -1 || this->m_bHasHScroll != 0 && this->CreateScrollBarCtrl(this, a2: 0, a3: m_nCols + 59904) == 0 )
    return 0;
  ++this->m_nCols;
  row = 0;
  if ( this->m_nRows > 0 )
  {
    v9 = 0;
    while ( ((int (__thiscall *)(CSplitterWnd *, int, int, CRuntimeClass *, int, int, _DWORD))this->CreateView)(
              a1: this,
              a2: row,
              a3: m_nCols,
              a4: this->m_pDynamicViewClass,
              a5: cxNew,
              a6: this->m_pRowInfo[v9].nCurSize,
              a7: 0) != 0 )
    {
      ++row;
      ++v9;
      if ( row >= this->m_nRows )
        goto LABEL_9;
    }
    for ( i = row; i > 0; this->DeleteView(this, a2: i, a3: m_nCols) )
      --i;
    if ( this->m_bHasHScroll != 0 )
    {
      DlgItem = CWnd::GetDlgItem(this, nID: m_nCols + 59904);
      DlgItem->DestroyWindow(this: DlgItem);
    }
    --this->m_nCols;
    return 0;
  }
LABEL_9:
  this->m_pColInfo[v4 - 1].nIdealSize = cxBeforea;
  this->m_pColInfo[v4].nIdealSize = cxNew;
  this->RecalcLayout(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10335B4F
// Name: public: virtual void CSplitterWnd::DeleteRow(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::DeleteRow(CSplitterWnd *this, int rowDelete)
{
  int v3; // edi
  int v4; // ebx
  CWnd *Pane; // eax
  CWnd *DlgItem; // eax
  CWnd *v7; // ecx
  int colActive; // [esp+4h] [ebp-10h] BYREF
  CWnd *pScrollDel; // [esp+8h] [ebp-Ch]
  int rowActive; // [esp+Ch] [ebp-8h] BYREF
  int col; // [esp+10h] [ebp-4h]

  if ( this->GetActivePane(this, a2: &rowActive, a3: &colActive) != nullptr && rowActive == rowDelete )
  {
    if ( ++rowActive >= this->m_nRows )
      rowActive = 0;
    this->SetActivePane(this, a2: rowActive, a3: colActive, a4: nullptr);
  }
  if ( this->m_bHasVScroll != 0 )
    pScrollDel = CWnd::GetDlgItem(this, nID: rowDelete + 59920);
  else
    pScrollDel = nullptr;
  for ( col = 0; col < this->m_nCols; ++col )
  {
    this->DeleteView(this, a2: rowDelete, a3: col);
    v3 = rowDelete + 1;
    if ( rowDelete + 1 < this->m_nRows )
    {
      v4 = col + 16 * (rowDelete + 3728);
      do
      {
        Pane = CSplitterWnd::GetPane(this, row: v3, col);
        CWnd::SetDlgCtrlID(this: Pane, nID: v4);
        if ( this->m_bHasVScroll != 0 && col == this->m_nCols - 1 )
        {
          DlgItem = CWnd::GetDlgItem(this, nID: v3 + 59920);
          if ( DlgItem != nullptr )
            CWnd::SetDlgCtrlID(this: DlgItem, nID: v3 + 59919);
        }
        ++v3;
        v4 += 16;
      }
      while ( v3 < this->m_nRows );
    }
  }
  v7 = pScrollDel;
  --this->m_nRows;
  if ( v7 != nullptr )
    v7->DestroyWindow(this: v7);
  this->RecalcLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10335C7E
// Name: public: virtual void CSplitterWnd::DeleteColumn(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::DeleteColumn(CSplitterWnd *this, int colDelete)
{
  int v3; // ebx
  int v4; // edi
  CWnd *Pane; // eax
  CWnd *DlgItem; // eax
  CWnd *v7; // ecx
  int rowActive; // [esp+4h] [ebp-10h] BYREF
  CWnd *pScrollDel; // [esp+8h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-8h]
  int colActive; // [esp+10h] [ebp-4h] BYREF

  if ( this->GetActivePane(this, a2: &rowActive, a3: &colActive) != nullptr && colActive == colDelete )
  {
    if ( ++colActive >= this->m_nCols )
      colActive = 0;
    this->SetActivePane(this, a2: rowActive, a3: colActive, a4: nullptr);
  }
  v3 = 0;
  if ( this->m_bHasHScroll != 0 )
    pScrollDel = CWnd::GetDlgItem(this, nID: colDelete + 59904);
  else
    pScrollDel = nullptr;
  if ( this->m_nRows > 0 )
  {
    v10 = 59647;
    do
    {
      v4 = colDelete;
      this->DeleteView(this, a2: v3, a3: colDelete);
      while ( ++v4 < this->m_nCols )
      {
        Pane = CSplitterWnd::GetPane(this, row: v3, col: v4);
        CWnd::SetDlgCtrlID(this: Pane, nID: v4 + v10);
        if ( this->m_bHasHScroll != 0 && v3 == this->m_nRows - 1 )
        {
          DlgItem = CWnd::GetDlgItem(this, nID: v4 + 59904);
          if ( DlgItem != nullptr )
            CWnd::SetDlgCtrlID(this: DlgItem, nID: v4 + 59903);
        }
      }
      v10 += 16;
      ++v3;
    }
    while ( v3 < this->m_nRows );
  }
  v7 = pScrollDel;
  --this->m_nCols;
  if ( v7 != nullptr )
    v7->DestroyWindow(this: v7);
  this->RecalcLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10335D92
// Name: protected: virtual void CSplitterWnd::StopTracking(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CSplitterWnd::StopTracking(CSplitterWnd *this@<ecx>, int a2@<edi>, int bAccept)
{
  CSplitterWnd_vtbl *v4; // eax
  CRect *p_m_rectTracker2; // ebx
  int m_htTrack; // eax
  int v7; // edi
  CWnd *pOldActiveView; // [esp+8h] [ebp-4h]

  if ( this->m_bTracking == 0 )
    return;
  ReleaseCapture();
  ((void (__thiscall *)(CSplitterWnd *, CRect *, int))this->OnInvertTracker)(a1: this, a2: &this->m_rectTracker, a3: a2);
  if ( this->m_bTracking2 != 0 )
    this->OnInvertTracker(this, a2: &this->m_rectTracker2);
  v4 = this->__vftable;
  this->m_bTracking2 = 0;
  this->m_bTracking = 0;
  pOldActiveView = v4->GetActivePane(this, a2: nullptr, a3: nullptr);
  OffsetRect(lprc: &this->m_rectTracker, dx: -1, dy: -1);
  p_m_rectTracker2 = &this->m_rectTracker2;
  OffsetRect(lprc: &this->m_rectTracker2, dx: -1, dy: -1);
  if ( bAccept != 0 )
  {
    m_htTrack = this->m_htTrack;
    if ( m_htTrack == 1 )
    {
      this->SplitRow(this, a2: this->m_rectTracker.top);
      goto LABEL_21;
    }
    if ( m_htTrack < 101 || m_htTrack > 115 )
    {
      if ( m_htTrack == 2 )
      {
        this->SplitColumn(this, a2: this->m_rectTracker.left);
        goto LABEL_21;
      }
      if ( m_htTrack < 201 || m_htTrack > 215 )
      {
        if ( m_htTrack < 301 || m_htTrack > 525 )
        {
          if ( m_htTrack == 3 )
          {
            this->SplitRow(this, a2: this->m_rectTracker.top);
            this->SplitColumn(this, a2: p_m_rectTracker2->left);
          }
          goto LABEL_21;
        }
        v7 = (m_htTrack - 301) % 15;
        this->TrackRowSize(this, a2: this->m_rectTracker.top, a3: (m_htTrack - 301) / 15);
        this->TrackColumnSize(this, a2: p_m_rectTracker2->left, a3: v7);
      }
      else
      {
        this->TrackColumnSize(this, a2: this->m_rectTracker.left, a3: m_htTrack - 201);
      }
    }
    else
    {
      this->TrackRowSize(this, a2: this->m_rectTracker.top, a3: m_htTrack - 101);
    }
    this->RecalcLayout(this);
  }
LABEL_21:
  if ( pOldActiveView == (CWnd *)((int (__thiscall *)(CSplitterWnd *, _DWORD))this->GetActivePane)(a1: this, a2: 0)
    && pOldActiveView != nullptr )
  {
    this->SetActivePane(this, a2: -1, a3: -1, a4: pOldActiveView);
    CWnd::SetFocus(this: pOldActiveView);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10335F32
// Name: public: virtual int CSplitterWnd::DoKeyboardSplit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::DoKeyboardSplit(CSplitterWnd *this)
{
  int v2; // eax
  int left; // edi
  int v4; // eax
  int y; // eax
  int x; // ecx
  int v8; // [esp-4h] [ebp-1Ch]
  CRect rect; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_nRows <= 1 )
  {
    if ( this->m_nCols > 1 )
    {
      v2 = 201;
      goto LABEL_14;
    }
    if ( this->m_nMaxRows <= 1 )
    {
      if ( this->m_nMaxCols <= 1 )
        return 0;
      v8 = 2;
    }
    else
    {
      if ( this->m_nMaxCols <= 1 )
      {
        v2 = 1;
        goto LABEL_14;
      }
      v8 = 3;
    }
LABEL_13:
    v2 = v8;
    goto LABEL_14;
  }
  if ( this->m_nCols <= 1 )
  {
    v8 = 101;
    goto LABEL_13;
  }
  v2 = 301;
LABEL_14:
  this->StartTracking(this, a2: v2);
  left = this->m_rectTracker.left;
  v4 = this->m_rectTracker.right - left;
  rect.right = 0;
  rect.bottom = 0;
  rect.left = v4 / 2;
  rect.top = (this->m_rectTracker.bottom - this->m_rectTracker.top) / 2;
  y = this->m_ptTrackOffset.y;
  if ( y != 0 )
    rect.top = this->m_rectTracker.top;
  x = this->m_ptTrackOffset.x;
  if ( x != 0 )
  {
    if ( this->m_bTracking2 != 0 )
      rect.left = this->m_rectTracker2.left;
    else
      rect.left = left;
  }
  OffsetRect(lprc: &rect, dx: -x, dy: -y);
  CWnd::ClientToScreen(this, lpRect: (tagPOINT *)&rect);
  SetCursorPos(X: rect.left, Y: rect.top);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033604C
// Name: void _AfxLayoutRowCol(struct CSplitterWnd::CRowColInfo __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxLayoutRowCol(CSplitterWnd::CRowColInfo *pInfoArray, int nMax, int nSize, int nSizeSplitter)
{
  int v4; // ecx
  int v5; // edx
  CSplitterWnd::CRowColInfo *v6; // eax
  int v7; // edi
  int *p_nCurSize; // eax
  int v9; // edx
  int v10; // ecx

  v4 = nSize;
  if ( nSize < 0 )
    v4 = 0;
  v5 = nMax - 1;
  v6 = pInfoArray;
  if ( nMax - 1 > 0 )
  {
    do
    {
      if ( v6->nIdealSize < v6->nMinSize )
        v6->nIdealSize = 0;
      v6->nCurSize = v6->nIdealSize;
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  v7 = 0;
  v6->nCurSize = 0x7FFFFFFF;
  if ( nMax > 0 )
  {
    p_nCurSize = &pInfoArray->nCurSize;
    while ( v4 == 0 )
    {
      *p_nCurSize = 0;
LABEL_27:
      ++v7;
      p_nCurSize += 3;
      if ( v7 >= nMax )
        return;
    }
    if ( v4 < *(p_nCurSize - 2) && v7 != 0 )
    {
      *p_nCurSize = 0;
      *(p_nCurSize - 3) += v4 + afxData.cxBorder2;
    }
    else
    {
      v9 = *p_nCurSize;
      if ( *p_nCurSize == 0 )
      {
        if ( v7 != 0 )
          *p_nCurSize = 0;
        goto LABEL_21;
      }
      if ( v4 >= v9 )
      {
        v4 -= v9;
LABEL_21:
        if ( v7 != nMax - 1 )
        {
          if ( v4 <= nSizeSplitter )
          {
            v10 = *p_nCurSize + v4;
            *p_nCurSize = v10;
            if ( v10 > nSizeSplitter - afxData.cxBorder2 )
              *p_nCurSize = afxData.cyBorder2 + v10 - nSizeSplitter;
            v4 = 0;
          }
          else
          {
            v4 -= nSizeSplitter;
          }
        }
        goto LABEL_27;
      }
      *p_nCurSize = v4;
    }
    v4 = 0;
    goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033610C
// Name: protected: void CSplitterWnd::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnPaint(CSplitterWnd *this)
{
  CSplitterWnd_vtbl *v2; // eax
  CPaintDC v3; // [esp+10h] [ebp-64h] BYREF
  int v4; // [esp+70h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v3, pWnd: this);
  v2 = this->__vftable;
  v4 = 0;
  v2->OnDraw(this, a2: &v3);
  v4 = -1;
  CPaintDC::~CPaintDC(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x10336147
// Name: protected: long CSplitterWnd::OnPrintClient(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::OnPrintClient(CSplitterWnd *this, HDC__ *wParam, int lParam)
{
  CDC *v4; // eax

  v4 = CDC::FromHandle(hDC: wParam);
  if ( v4 == nullptr )
    return -1;
  this->OnDraw(this, a2: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10336172
// Name: protected: void CSplitterWnd::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnLButtonDown(CSplitterWnd *this, unsigned int __formal, CPoint pt)
{
  CSplitterWnd_vtbl *v4; // esi
  int v5; // eax

  if ( this->m_bTracking == 0 )
  {
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(CSplitterWnd *, int, int))this->HitTest)(a1: this, a2: pt.x, a3: pt.y);
    v4->StartTracking(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103361A1
// Name: protected: void CSplitterWnd::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnLButtonDblClk(CSplitterWnd *this, unsigned int __formal, CPoint pt)
{
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edx
  int v8; // edi
  int v9; // ebx
  int row; // [esp+Ch] [ebp-8h] BYREF
  int col; // [esp+10h] [ebp-4h] BYREF

  v4 = ((int (__thiscall *)(CSplitterWnd *, int, int))this->HitTest)(a1: this, a2: pt.x, a3: pt.y);
  this->StopTracking(this, a2: 0);
  if ( (CWnd::GetStyle(this) & 1) != 0 )
  {
    if ( v4 == 1 )
    {
      this->SplitRow(this, a2: this->m_pRowInfo->nCurSize / 2);
    }
    else if ( v4 == 2 )
    {
      this->SplitColumn(this, a2: this->m_pColInfo->nCurSize / 2);
    }
    else if ( (unsigned int)(v4 - 101) > 0xE )
    {
      if ( (unsigned int)(v4 - 201) > 0xE )
      {
        if ( (unsigned int)(v4 - 301) <= 0xE0 )
        {
          v7 = (v4 - 301) % 15;
          v8 = (v4 - 301) / 15;
          v9 = v7;
          if ( this->GetActivePane(this, a2: &row, a3: &col) != nullptr )
          {
            if ( col == v9 )
              ++v9;
            if ( row == v8 )
              ++v8;
          }
          this->DeleteRow(this, a2: v8);
          this->DeleteColumn(this, a2: v9);
        }
      }
      else
      {
        v6 = v4 - 201;
        if ( this->GetActivePane(this, a2: 0, a3: &col) != nullptr && v6 == col )
          ++v6;
        this->DeleteColumn(this, a2: v6);
      }
    }
    else
    {
      v5 = v4 - 101;
      if ( this->GetActivePane(this, a2: &col, a3: 0) != nullptr && v5 == col )
        ++v5;
      this->DeleteRow(this, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103362DC
// Name: protected: void CSplitterWnd::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnLButtonUp(CSplitterWnd *this, unsigned int __formal, CPoint __formala)
{
  this->StopTracking(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103362E9
// Name: protected: void CSplitterWnd::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnCancelMode(CSplitterWnd *this)
{
  this->StopTracking(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103362F4
// Name: public: virtual int CSplitterWnd::CanActivateNext(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::CanActivateNext(CSplitterWnd *this, int __formal)
{
  int result; // eax

  if ( this->GetActivePane(this, a2: 0, a3: 0) == nullptr )
    return 0;
  result = 1;
  if ( this->m_nRows <= 1 && this->m_nCols <= 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10336322
// Name: public: virtual void CSplitterWnd::ActivateNext(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::ActivateNext(CSplitterWnd *this, int bPrev)
{
  int v3; // eax
  bool v4; // sf
  int row; // [esp+4h] [ebp-8h] BYREF
  int col; // [esp+8h] [ebp-4h] BYREF

  if ( this->GetActivePane(this, a2: &row, a3: &col) != nullptr )
  {
    if ( bPrev != 0 )
    {
      if ( --col < 0 )
      {
        v3 = this->m_nCols - 1;
        v4 = --row < 0;
        col = v3;
        if ( v4 )
          row = this->m_nRows - 1;
      }
    }
    else if ( ++col >= this->m_nCols )
    {
      ++row;
      col = 0;
      if ( row >= this->m_nRows )
        row = 0;
    }
    this->SetActivePane(this, a2: row, a3: col, a4: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103363C2
// Name: protected: int CSplitterWnd::CreateCommon(class CWnd __near *,struct tagSIZE,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::CreateCommon(
        CSplitterWnd *this,
        CWnd *pParentWnd,
        tagSIZE sizeMin,
        unsigned int dwStyle,
        HMENU__ *nID)
{
  int v6; // ebx
  int i; // ecx
  int v8; // eax
  int v9; // eax

  AfxEndDeferRegisterClass(fToRegister: 4);
  v6 = 0;
  if ( this->CreateEx_2(
         this,
         a2: 0,
         a3: "AfxMDIFrame100s",
         a4: nullptr,
         a5: dwStyle & 0xFF4FFFFF,
         a6: 0,
         a7: 0,
         a8: 0,
         a9: 0,
         a10: pParentWnd->m_hWnd,
         a11: nID,
         a12: nullptr) == 0 )
    return 0;
  this->m_pColInfo = (CSplitterWnd::CRowColInfo *)operator new(nSize: 12 * this->m_nMaxCols);
  for ( i = 0; i < this->m_nMaxCols; ++i )
  {
    v8 = i;
    this->m_pColInfo[v8].nIdealSize = sizeMin.cx;
    this->m_pColInfo[v8].nMinSize = sizeMin.cx;
    this->m_pColInfo[v8].nCurSize = -1;
  }
  this->m_pRowInfo = (CSplitterWnd::CRowColInfo *)operator new(nSize: 12 * this->m_nMaxRows);
  while ( v6 < this->m_nMaxRows )
  {
    v9 = v6;
    this->m_pRowInfo[v9].nIdealSize = sizeMin.cy;
    this->m_pRowInfo[v9].nMinSize = sizeMin.cy;
    this->m_pRowInfo[v9].nCurSize = -1;
    ++v6;
  }
  CSplitterWnd::SetScrollStyle(this, dwStyle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103364D4
// Name: protected: int CSplitterWnd::OnNcCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::OnNcCreate(CSplitterWnd *this, tagCREATESTRUCTA *lpcs)
{
  int result; // eax
  HWND Parent; // eax
  CWnd *v5; // eax

  result = CWnd::Default(this);
  if ( result != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    CWnd::ModifyStyleEx(this: v5, dwRemove: 0x200u, dwAdd: 0, nFlags: 0x20u);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10336508
// Name: public: virtual int CSplitterWnd::CreateView(int,int,struct CRuntimeClass __near *,struct tagSIZE,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::CreateView(
        CSplitterWnd *this,
        int row,
        int col,
        CRuntimeClass *pViewClass,
        tagSIZE sizeInit,
        CCreateContext *pContext)
{
  unsigned __int8 *v6; // edi
  CWnd *v8; // eax
  CWnd *v9; // edi
  CWnd_vtbl *v10; // edi
  CRuntimeClass *Object; // eax
  unsigned __int8 dst[20]; // [esp+14h] [ebp-48h] BYREF
  int v14; // [esp+28h] [ebp-34h]
  int v15; // [esp+2Ch] [ebp-30h]
  int v16; // [esp+30h] [ebp-2Ch]
  CRuntimeClass *v17; // [esp+34h] [ebp-28h]
  _DWORD v18[2]; // [esp+38h] [ebp-24h] BYREF
  tagSIZE v19; // [esp+40h] [ebp-1Ch]
  int v20; // [esp+58h] [ebp-4h]

  v6 = (unsigned __int8 *)pContext;
  v14 = col;
  v15 = row;
  v17 = pViewClass;
  this->m_pColInfo[col].nIdealSize = sizeInit.cx;
  this->m_pRowInfo[row].nIdealSize = sizeInit.cy;
  v16 = 0;
  memset(dst, value: 0, count: sizeof(dst));
  if ( pContext == nullptr )
  {
    v8 = this->GetActivePane(this, a2: 0, a3: 0);
    v9 = v8;
    if ( v8 != nullptr && CObject::IsKindOf(this: v8, pClass: &CView::classCView) != 0 )
    {
      *(_DWORD *)&dst[12] = v9;
      v10 = v9[1].__vftable;
      *(_DWORD *)&dst[4] = v10;
      if ( v10 != nullptr )
        *(_DWORD *)&dst[8] = v10->GetMessageMap;
    }
    v6 = dst;
    v16 = 1;
  }
  v20 = 0;
  Object = (CRuntimeClass *)CRuntimeClass::CreateObject(this: v17);
  v17 = Object;
  if ( Object == nullptr )
    AfxThrowMemoryException();
  v20 = -1;
  v19 = sizeInit;
  v18[0] = 0;
  v18[1] = 0;
  if ( (*((int (__thiscall **)(CRuntimeClass *, _DWORD, _DWORD, int, _DWORD *, CSplitterWnd *, int, unsigned __int8 *))Object->m_lpszClassName
        + 21))(
         a1: Object,
         a2: 0,
         a3: 0,
         a4: 1342177280,
         a5: v18,
         a6: this,
         a7: v14 + 16 * (v15 + 3728),
         a8: v6) == 0 )
    return 0;
  if ( v16 != 0 )
    SendMessageA(hWnd: (HWND)v17[1].m_nObjectSize, Msg: 0x364u, wParam: 0, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10336624
// Name: public: virtual int CSplitterWnd::CreateScrollBarCtrl(unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CSplitterWnd::CreateScrollBarCtrl(CSplitterWnd *this, unsigned int dwStyle, HMENU nID)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  return CreateWindowExA(
           dwExStyle: 0,
           lpClassName: "SCROLLBAR",
           lpWindowName: nullptr,
           dwStyle: dwStyle | 0x50000000,
           X: 0,
           Y: 0,
           nWidth: 1,
           nHeight: 1,
           hWndParent: this->m_hWnd,
           hMenu: nID,
           hInstance: ModuleState->m_hCurrentInstanceHandle,
           lpParam: nullptr) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10336665
// Name: public: int CSplitterWnd::IsChildPane(class CWnd __near *,int __near *,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::IsChildPane(CSplitterWnd *this, CWnd *pWnd, int *pRow, int *pCol)
{
  int DlgCtrlID; // esi

  DlgCtrlID = GetDlgCtrlID(hWnd: pWnd->m_hWnd);
  if ( IsChild(hWndParent: this->m_hWnd, hWnd: pWnd->m_hWnd) && (unsigned int)(DlgCtrlID - 59648) <= 0xFF )
  {
    if ( pRow != nullptr )
      *pRow = (unsigned int)(DlgCtrlID - 59648) >> 4;
    if ( pCol != nullptr )
      *pCol = DlgCtrlID & 0xF;
    return 1;
  }
  else
  {
    if ( pRow != nullptr )
      *pRow = -1;
    if ( pCol != nullptr )
      *pCol = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103366DA
// Name: protected: virtual void CSplitterWnd::OnDrawSplitter(class CDC __near *,enum CSplitterWnd::ESplitType,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnDrawSplitter(
        CSplitterWnd *this,
        CDC *pDC,
        CSplitterWnd::ESplitType nType,
        const CRect *rectArg)
{
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  if ( pDC == nullptr )
  {
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: rectArg, hrgnUpdate: nullptr, flags: 0x41u);
    return;
  }
  rect = *rectArg;
  if ( nType != splitBox )
  {
    if ( nType == splitBorder )
    {
      CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: afxData.clrBtnShadow, clrBottomRight: afxData.clrBtnHilite);
      InflateRect(lprc: &rect, dx: -1, dy: -1);
      CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: afxData.clrWindowFrame, clrBottomRight: afxData.clrBtnFace);
      return;
    }
  }
  else
  {
    CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: afxData.clrBtnFace, clrBottomRight: afxData.clrWindowFrame);
    InflateRect(lprc: &rect, dx: -1, dy: -1);
    CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: afxData.clrBtnHilite, clrBottomRight: afxData.clrBtnShadow);
    InflateRect(lprc: &rect, dx: -1, dy: -1);
  }
  CDC::FillSolidRect(this: pDC, lpRect: &rect, clr: afxData.clrBtnFace);
}

//------------------------------------------------------------------------------
// Address: 0x103367CC
// Name: protected: virtual void CSplitterWnd::GetInsideRect(class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::GetInsideRect(CSplitterWnd *this, CRect *rect)
{
  GetClientRect(hWnd: this->m_hWnd, lpRect: rect);
  InflateRect(lprc: rect, dx: -this->m_cxBorder, dy: -this->m_cyBorder);
  if ( this->m_bHasVScroll != 0 )
    rect->right += 1 - afxData.cxVScroll;
  if ( this->m_bHasHScroll != 0 )
    rect->bottom += 1 - afxData.cyHScroll;
}

//------------------------------------------------------------------------------
// Address: 0x1033682B
// Name: protected: virtual void CSplitterWnd::StartTracking(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CSplitterWnd::StartTracking(CSplitterWnd *this@<ecx>, int a2@<edi>, int ht)
{
  CRect *p_m_rectTracker; // ebx
  CSplitterWnd_vtbl *v5; // eax
  CSplitterWnd_vtbl *v6; // eax
  CSplitterWnd_vtbl *v7; // edx
  CWnd *v8; // ecx
  CFrameWnd *ParentFrame; // eax
  HWND v10; // eax
  CSplitterWnd_vtbl *v11; // eax
  CSplitterWnd_vtbl *v12; // edx
  CRect *v13; // [esp-4h] [ebp-14h]
  int yTrackOffseta; // [esp+8h] [ebp-8h]
  int yTrackOffsetb; // [esp+8h] [ebp-8h]
  int yTrackOffset; // [esp+8h] [ebp-8h]

  if ( ht != 0 )
  {
    ((void (__stdcall *)(CRect *, int))this->GetInsideRect)(a1: &this->m_rectLimit, a2);
    if ( (unsigned int)(ht - 301) > 0xE0 )
    {
      v6 = this->__vftable;
      p_m_rectTracker = &this->m_rectTracker;
      v13 = &this->m_rectTracker;
      if ( ht == 3 )
      {
        v6->GetHitRect(this, a2: 1, a3: v13);
        v7 = this->__vftable;
        yTrackOffsetb = this->m_ptTrackOffset.y;
        this->m_bTracking2 = 1;
        v7->GetHitRect(this, a2: 2, a3: &this->m_rectTracker2);
        this->m_ptTrackOffset.y = yTrackOffsetb;
        OffsetRect(lprc: &this->m_rectTracker, dx: 0, dy: (this->m_rectLimit.bottom - this->m_rectLimit.top) / 2);
        OffsetRect(lprc: &this->m_rectTracker2, dx: (this->m_rectLimit.right - this->m_rectLimit.left) / 2, dy: 0);
      }
      else
      {
        v6->GetHitRect(this, a2: ht, a3: v13);
      }
    }
    else
    {
      p_m_rectTracker = &this->m_rectTracker;
      this->GetHitRect(this, a2: (ht - 301) / 15 + 101, a3: &this->m_rectTracker);
      yTrackOffseta = this->m_ptTrackOffset.y;
      v5 = this->__vftable;
      this->m_bTracking2 = 1;
      v5->GetHitRect(this, a2: (ht - 301) % 15 + 201, a3: &this->m_rectTracker2);
      this->m_ptTrackOffset.y = yTrackOffseta;
    }
    v8 = this->GetActivePane(this, a2: 0, a3: 0);
    yTrackOffset = (int)v8;
    if ( v8 != nullptr && CObject::IsKindOf(this: v8, pClass: &CView::classCView) != 0 )
    {
      ParentFrame = CWnd::GetParentFrame(this);
      if ( ParentFrame == nullptr )
        AfxThrowInvalidArgException();
      (*(void (__thiscall **)(int, _DWORD, CFrameWnd *))(*(_DWORD *)yTrackOffset + 400))(
        a1: yTrackOffset,
        a2: 0,
        a3: ParentFrame);
    }
    v10 = SetCapture(hWnd: this->m_hWnd);
    CWnd::FromHandle(hWnd: v10);
    CWnd::SetFocus(this);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x180u);
    v11 = this->__vftable;
    this->m_bTracking = 1;
    v11->OnInvertTracker(this, a2: p_m_rectTracker);
    if ( this->m_bTracking2 != 0 )
      this->OnInvertTracker(this, a2: &this->m_rectTracker2);
    v12 = this->__vftable;
    this->m_htTrack = ht;
    v12->SetSplitCursor(this, a2: ht);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103369F2
// Name: protected: virtual void CSplitterWnd::TrackRowSize(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::TrackRowSize(CSplitterWnd *this, int y, int row)
{
  int v4; // ebx
  CWnd *Pane; // eax
  int v6; // eax
  CSplitterWnd::CRowColInfo *m_pRowInfo; // edx
  CPoint pt; // [esp+8h] [ebp-8h] BYREF

  pt.x = 0;
  pt.y = y;
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &pt);
  v4 = row;
  Pane = CSplitterWnd::GetPane(this, row, col: 0);
  ScreenToClient(hWnd: Pane->m_hWnd, lpPoint: &pt);
  v6 = row;
  this->m_pRowInfo[row].nIdealSize = pt.y;
  m_pRowInfo = this->m_pRowInfo;
  if ( pt.y < m_pRowInfo[row].nMinSize )
  {
    m_pRowInfo[v6].nIdealSize = 0;
    if ( (CWnd::GetStyle(this) & 1) == 0 )
      return;
    goto LABEL_7;
  }
  if ( m_pRowInfo[v6].nCurSize + m_pRowInfo[v6 + 1].nCurSize < pt.y + m_pRowInfo[v6 + 1].nMinSize
    && (CWnd::GetStyle(this) & 1) != 0 )
  {
    v4 = row + 1;
LABEL_7:
    this->DeleteRow(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10336A90
// Name: protected: virtual void CSplitterWnd::TrackColumnSize(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::TrackColumnSize(CSplitterWnd *this, int x, int col)
{
  int v4; // ebx
  CWnd *Pane; // eax
  int v6; // eax
  CSplitterWnd::CRowColInfo *m_pColInfo; // edx
  CPoint pt; // [esp+8h] [ebp-8h] BYREF

  pt.y = 0;
  pt.x = x;
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &pt);
  v4 = col;
  Pane = CSplitterWnd::GetPane(this, row: 0, col);
  ScreenToClient(hWnd: Pane->m_hWnd, lpPoint: &pt);
  v6 = col;
  this->m_pColInfo[col].nIdealSize = pt.x;
  m_pColInfo = this->m_pColInfo;
  if ( pt.x < m_pColInfo[col].nMinSize )
  {
    m_pColInfo[v6].nIdealSize = 0;
    if ( (CWnd::GetStyle(this) & 1) == 0 )
      return;
    goto LABEL_7;
  }
  if ( m_pColInfo[v6].nCurSize + m_pColInfo[v6 + 1].nCurSize < pt.x + m_pColInfo[v6 + 1].nMinSize
    && (CWnd::GetStyle(this) & 1) != 0 )
  {
    v4 = col + 1;
LABEL_7:
    this->DeleteColumn(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10336B2E
// Name: protected: virtual void CSplitterWnd::GetHitRect(int,class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::GetHitRect(CSplitterWnd *this, int ht, CRect *rectHit)
{
  int left; // eax
  int right; // ecx
  int top; // edx
  int bottom; // edi
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  int *p_nCurSize; // eax
  int v12; // edx
  int v13; // eax
  int *v14; // eax
  int v15; // edx
  int y; // [esp+14h] [ebp-20h]
  int x; // [esp+18h] [ebp-1Ch]
  int v18; // [esp+1Ch] [ebp-18h]
  int v19; // [esp+1Ch] [ebp-18h]
  CRect rectClient; // [esp+20h] [ebp-14h] BYREF

  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: -this->m_cxBorder, dy: -this->m_cyBorder);
  left = rectClient.left;
  right = rectClient.right;
  top = rectClient.top;
  bottom = rectClient.bottom;
  this->m_ptTrackOffset.x = 0;
  this->m_ptTrackOffset.y = 0;
  v8 = right - left;
  y = left;
  v9 = bottom - top;
  x = top;
  if ( ht != 1 )
  {
    if ( ht == 2 )
    {
      v8 = this->m_cxSplitter - 2 * this->m_cxBorder + 1;
      this->m_ptTrackOffset.x = v8 / -2;
    }
    else
    {
      v18 = ht - 101;
      if ( (unsigned int)(ht - 101) <= 0xE )
      {
        v9 = this->m_cySplitter - 2 * this->m_cyBorder + 1;
        this->m_ptTrackOffset.y = v9 / -2;
        v10 = 0;
        if ( v18 > 0 )
        {
          p_nCurSize = &this->m_pRowInfo->nCurSize;
          do
          {
            v12 = this->m_cySplitterGap + *p_nCurSize;
            p_nCurSize += 3;
            y += v12;
            --v18;
          }
          while ( v18 != 0 );
          v10 = ht - 101;
        }
        this->m_rectLimit.top = y;
        y += this->m_cyBorderShare + this->m_pRowInfo[v10].nCurSize + 1;
        goto LABEL_11;
      }
      if ( (unsigned int)(ht - 201) > 0xE )
        goto LABEL_19;
      v8 = this->m_cxSplitter - 2 * this->m_cxBorder + 1;
      this->m_ptTrackOffset.x = v8 / -2;
      v13 = 0;
      if ( ht - 201 > 0 )
      {
        v14 = &this->m_pColInfo->nCurSize;
        v19 = ht - 201;
        do
        {
          v15 = this->m_cxSplitterGap + *v14;
          v14 += 3;
          x += v15;
          --v19;
        }
        while ( v19 != 0 );
        v13 = ht - 201;
      }
      this->m_rectLimit.left = x;
      x += this->m_cxBorderShare + this->m_pColInfo[v13].nCurSize + 1;
    }
    this->m_rectLimit.right -= v8;
    goto LABEL_19;
  }
  v9 = this->m_cySplitter - 2 * this->m_cyBorder + 1;
  this->m_ptTrackOffset.y = v9 / -2;
LABEL_11:
  this->m_rectLimit.bottom -= v9;
LABEL_19:
  rectHit->left = x;
  rectHit->right = v8 + x;
  rectHit->top = y;
  rectHit->bottom = v9 + y;
}

//------------------------------------------------------------------------------
// Address: 0x10336D31
// Name: protected: virtual int CSplitterWnd::HitTest(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::HitTest(CSplitterWnd *this, CPoint pt)
{
  CSplitterWnd_vtbl *v3; // eax
  int m_cySplitter; // ecx
  int m_nCols; // eax
  int v7; // esi
  int left; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int m_nRows; // eax
  int v13; // esi
  int top; // eax
  int v15; // edi
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-58h]
  int col; // [esp+8h] [ebp-48h]
  CRect rectInside; // [esp+Ch] [ebp-44h] BYREF
  CRect rectClient; // [esp+1Ch] [ebp-34h] BYREF
  RECT rc; // [esp+2Ch] [ebp-24h] BYREF
  CRect rect; // [esp+3Ch] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: -this->m_cxBorder, dy: -this->m_cyBorder);
  v3 = this->__vftable;
  memset(&rectInside, 0, sizeof(rectInside));
  v3->GetInsideRect(this, a2: &rectInside);
  if ( this->m_bHasVScroll != 0 && this->m_nRows < this->m_nMaxRows )
  {
    rc.left = rectInside.right;
    rc.right = rectClient.right;
    m_cySplitter = this->m_cySplitter;
    rc.top = rectClient.top;
    rc.bottom = m_cySplitter + rectClient.top - 1;
    if ( PtInRect(lprc: &rc, pt: pt.tagPOINT) )
      return 1;
  }
  if ( this->m_bHasHScroll != 0 && this->m_nCols < this->m_nMaxCols )
  {
    rc.left = rectClient.left;
    rc.top = rectInside.bottom;
    rc.right = this->m_cxSplitter + rectClient.left - 1;
    rc.bottom = rectClient.bottom;
    if ( PtInRect(lprc: &rc, pt: pt.tagPOINT) )
      return 2;
  }
  m_nCols = this->m_nCols;
  rect = rectClient;
  v7 = 0;
  col = 0;
  if ( m_nCols > 0 )
  {
    col = 0;
    if ( m_nCols - 1 > 0 )
    {
      left = rect.left;
      do
      {
        v9 = this->m_pColInfo[v7].nCurSize + left;
        v10 = v9 + this->m_cxSplitterGap;
        rect.left = v9;
        rect.right = v10;
        if ( PtInRect(lprc: &rect, pt: pt.tagPOINT) )
          break;
        ++col;
        left = rect.right;
        ++v7;
        v11 = this->m_nCols - 1;
        rect.left = rect.right;
      }
      while ( col < v11 );
    }
  }
  m_nRows = this->m_nRows;
  rect = rectClient;
  v13 = 0;
  if ( m_nRows > 0 && m_nRows - 1 > 0 )
  {
    top = rect.top;
    v15 = 0;
    do
    {
      v16 = this->m_pRowInfo[v15].nCurSize + top;
      v17 = v16 + this->m_cySplitterGap;
      rect.top = v16;
      rect.bottom = v17;
      if ( PtInRect(lprc: &rect, pt: pt.tagPOINT) )
        break;
      top = rect.bottom;
      ++v13;
      ++v15;
      v18 = this->m_nRows - 1;
      rect.top = rect.bottom;
    }
    while ( v13 < v18 );
  }
  if ( col == this->m_nCols - 1 )
  {
    if ( v13 == this->m_nRows - 1 )
      return 0;
    else
      return v13 + 101;
  }
  else if ( v13 == this->m_nRows - 1 )
  {
    return col + 201;
  }
  else
  {
    return 15 * v13 + col + 301;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10336F4D
// Name: protected: virtual void CSplitterWnd::OnInvertTracker(class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnInvertTracker(CSplitterWnd *this, const CRect *rect)
{
  HDC DC; // eax
  CDC *v3; // esi
  CBrush *HalftoneBrush; // eax
  HBRUSH__ *hOldBrush; // [esp+Ch] [ebp-4h]

  DC = GetDC(hWnd: this->m_hWnd);
  v3 = CDC::FromHandle(hDC: DC);
  HalftoneBrush = CDC::GetHalftoneBrush();
  hOldBrush = nullptr;
  if ( HalftoneBrush != nullptr )
    hOldBrush = (HBRUSH__ *)SelectObject(hdc: v3->m_hDC, h: HalftoneBrush->m_hObject);
  PatBlt(
    hdc: v3->m_hDC,
    x: rect->left,
    y: rect->top,
    w: rect->right - rect->left,
    h: rect->bottom - rect->top,
    rop: 0x5A0049u);
  if ( hOldBrush != nullptr )
    SelectObject(hdc: v3->m_hDC, h: hOldBrush);
  ReleaseDC(hWnd: this->m_hWnd, hDC: v3->m_hDC);
}

//------------------------------------------------------------------------------
// Address: 0x10336FD1
// Name: protected: void CSplitterWnd::OnDisplayChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnDisplayChange(CSplitterWnd *this)
{
  if ( !IsIconic(hWnd: this->m_hWnd) && IsWindowVisible(hWnd: this->m_hWnd) )
    this->RecalcLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10336FFD
// Name: protected: void CSplitterWnd::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnSize(CSplitterWnd *this, unsigned int nType, int cx, int cy)
{
  if ( nType != 1 && cx > 0 && cy > 0 )
    this->RecalcLayout(this);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033702B
// Name: void _AfxDeferClientPos(struct AFX_SIZEPARENTPARAMS __near *,class CWnd __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxDeferClientPos(
        AFX_SIZEPARENTPARAMS *lpLayout,
        CWnd *pWnd,
        int x,
        int y,
        int cx,
        int cy,
        int bScrollBar)
{
  BOOL v7; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  CRect rect; // [esp+10h] [ebp-24h] BYREF
  CRect rectOld; // [esp+20h] [ebp-14h] BYREF

  if ( bScrollBar != 0 )
  {
    v7 = true;
    if ( cx > 1 )
      v7 = cy <= 1;
    CWnd::ModifyStyle(this: pWnd, dwRemove: v7 ? 0 : 0x800000, dwAdd: v7 ? 0x800000 : 0, nFlags: 0);
  }
  rect.top = y;
  rect.left = x;
  rect.bottom = cy + y;
  rect.right = cx + x;
  if ( (CWnd::GetExStyle(this: pWnd) & 0x200) != 0
    || CObject::IsKindOf(this: pWnd, pClass: &CSplitterWnd::classCSplitterWnd) != 0 )
  {
    InflateRect(lprc: &rect, dx: afxData.cxBorder2, dy: afxData.cyBorder2);
  }
  memset(&rectOld, 0, sizeof(rectOld));
  GetWindowRect(hWnd: pWnd->m_hWnd, lpRect: &rectOld);
  Parent = GetParent(hWnd: pWnd->m_hWnd);
  v9 = CWnd::FromHandle(hWnd: Parent);
  CWnd::ScreenToClient(this: v9, lpRect: (tagPOINT *)&rectOld);
  if ( !EqualRect(lprc1: &rect, lprc2: &rectOld) )
    AfxRepositionWindow(lpLayout, hWnd: pWnd->m_hWnd, lpRect: &rect);
}

//------------------------------------------------------------------------------
// Address: 0x10337136
// Name: protected: class CWnd __near * CSplitterWnd::GetSizingParent(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSplitterWnd *__thiscall CSplitterWnd::GetSizingParent(CSplitterWnd *this)
{
  HWND Parent; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-3Ch]
  CSplitterWnd *pParent; // [esp+Ch] [ebp-28h]
  CRect rectClient; // [esp+10h] [ebp-24h] BYREF
  CRect rect; // [esp+20h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  pParent = this;
  if ( (CWnd::GetStyle(this) & 0x40000) == 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    pParent = (CSplitterWnd *)CWnd::FromHandle(hWnd: Parent);
  }
  if ( (CWnd::GetStyle(this: pParent) & 0x1040000) == 0x40000
    && (memset(&rect, 0, sizeof(rect)),
        GetClientRect(hWnd: pParent->m_hWnd, lpRect: &rect),
        CWnd::ClientToScreen(this: pParent, lpRect: (tagPOINT *)&rect),
        CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rect),
        CPoint::operator==(this: (CPoint *)&rectClient.right, point: *(tagPOINT *)&rect.right)) )
  {
    return pParent;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103371F6
// Name: public: virtual void CSplitterWnd::RecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::RecalcLayout(CSplitterWnd *this)
{
  CSplitterWnd_vtbl *v2; // eax
  HDWP v3; // eax
  int v4; // ebx
  CWnd *DlgItem; // eax
  int v6; // ebx
  CWnd *v7; // eax
  int m_nRows; // eax
  int nCurSize; // ebx
  CWnd *Pane; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-74h]
  int v12; // [esp+Ch] [ebp-60h]
  int cxScrollbar; // [esp+10h] [ebp-5Ch]
  int cxScrollbara; // [esp+10h] [ebp-5Ch]
  int y; // [esp+14h] [ebp-58h]
  int ya; // [esp+14h] [ebp-58h]
  int yb; // [esp+14h] [ebp-58h]
  BOOL cxCol; // [esp+18h] [ebp-54h]
  int cxCola; // [esp+18h] [ebp-54h]
  int cxColb; // [esp+18h] [ebp-54h]
  int cxColc; // [esp+18h] [ebp-54h]
  int col; // [esp+1Ch] [ebp-50h]
  int cola; // [esp+1Ch] [ebp-50h]
  int row; // [esp+20h] [ebp-4Ch]
  int rowa; // [esp+20h] [ebp-4Ch]
  int rowb; // [esp+20h] [ebp-4Ch]
  CWnd *x; // [esp+24h] [ebp-48h]
  int xa; // [esp+24h] [ebp-48h]
  int xb; // [esp+24h] [ebp-48h]
  int xc; // [esp+24h] [ebp-48h]
  AFX_SIZEPARENTPARAMS layout; // [esp+28h] [ebp-44h] BYREF
  CRect rectClient; // [esp+48h] [ebp-24h] BYREF
  CRect rectInside; // [esp+58h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: -this->m_cxBorder, dy: -this->m_cyBorder);
  v2 = this->__vftable;
  memset(&rectInside, 0, sizeof(rectInside));
  v2->GetInsideRect(this, a2: &rectInside);
  _AfxLayoutRowCol(
    pInfoArray: this->m_pColInfo,
    nMax: this->m_nCols,
    nSize: rectInside.right - rectInside.left,
    nSizeSplitter: this->m_cxSplitterGap);
  _AfxLayoutRowCol(
    pInfoArray: this->m_pRowInfo,
    nMax: this->m_nRows,
    nSize: rectInside.bottom - rectInside.top,
    nSizeSplitter: this->m_cySplitterGap);
  v3 = BeginDeferWindowPos(nNumWindows: (this->m_nCols + 1) * (this->m_nRows + 1) + 1);
  v4 = rectClient.bottom - rectInside.bottom;
  layout.hDWP = v3;
  cxScrollbar = rectClient.right - rectInside.right;
  if ( this->m_bHasHScroll != 0 )
  {
    if ( this->m_bHasVScroll != 0 )
    {
      x = CWnd::GetDlgItem(this, nID: 59936);
      cxCol = CSplitterWnd::GetSizingParent(this) != nullptr;
      if ( CWnd::ModifyStyle(this: x, dwRemove: 0x18u, dwAdd: 8 * cxCol + 8, nFlags: 0) != 0 )
        InvalidateRect(hWnd: x->m_hWnd, lpRect: nullptr, bErase: true);
      CWnd::EnableWindow(this: x, bEnable: cxCol);
      _AfxDeferClientPos(
        lpLayout: &layout,
        pWnd: x,
        x: rectInside.right,
        y: rectInside.bottom,
        cx: cxScrollbar,
        cy: v4,
        bScrollBar: 1);
    }
    if ( this->m_bHasHScroll != 0 )
    {
      cxCola = this->m_cxSplitter;
      xa = rectClient.left;
      y = rectInside.bottom;
      for ( col = 0; col < this->m_nCols; ++col )
      {
        DlgItem = CWnd::GetDlgItem(this, nID: col + 59904);
        row = this->m_pColInfo[col].nCurSize;
        if ( col == 0 && this->m_nCols < this->m_nMaxCols )
        {
          xa += cxCola;
          row -= cxCola;
        }
        _AfxDeferClientPos(lpLayout: &layout, pWnd: DlgItem, x: xa, y, cx: row, cy: v4, bScrollBar: 1);
        xa += row + this->m_cxSplitterGap;
      }
    }
  }
  if ( this->m_bHasVScroll != 0 )
  {
    cxColb = this->m_cySplitter;
    ya = rectInside.right;
    v6 = 0;
    for ( xb = rectClient.top; v6 < this->m_nRows; ++v6 )
    {
      v7 = CWnd::GetDlgItem(this, nID: v6 + 59920);
      rowa = this->m_pRowInfo[v6].nCurSize;
      if ( v6 == 0 && this->m_nRows < this->m_nMaxRows )
      {
        xb += cxColb;
        rowa -= cxColb;
      }
      _AfxDeferClientPos(lpLayout: &layout, pWnd: v7, x: ya, y: xb, cx: cxScrollbar, cy: rowa, bScrollBar: 1);
      xb += rowa + this->m_cySplitterGap;
    }
  }
  yb = rectClient.left;
  xc = 0;
  if ( this->m_nCols > 0 )
  {
    m_nRows = this->m_nRows;
    cxScrollbara = 0;
    do
    {
      cxColc = this->m_pColInfo[cxScrollbara].nCurSize;
      cola = rectClient.top;
      rowb = 0;
      if ( m_nRows > 0 )
      {
        v12 = 0;
        do
        {
          nCurSize = this->m_pRowInfo[v12].nCurSize;
          Pane = CSplitterWnd::GetPane(this, row: rowb, col: xc);
          _AfxDeferClientPos(lpLayout: &layout, pWnd: Pane, x: yb, y: cola, cx: cxColc, cy: nCurSize, bScrollBar: 0);
          ++v12;
          cola += nCurSize + this->m_cySplitterGap;
          ++rowb;
          m_nRows = this->m_nRows;
        }
        while ( rowb < m_nRows );
      }
      ++cxScrollbara;
      yb += cxColc + this->m_cxSplitterGap;
      ++xc;
    }
    while ( xc < this->m_nCols );
  }
  if ( layout.hDWP != nullptr )
    EndDeferWindowPos(hWinPosInfo: layout.hDWP);
  this->DrawAllSplitBars(this, a2: nullptr, a3: rectInside.right, a4: rectInside.bottom);
}

//------------------------------------------------------------------------------
// Address: 0x10337548
// Name: protected: virtual void CSplitterWnd::DrawAllSplitBars(class CDC __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::DrawAllSplitBars(CSplitterWnd *this, CDC *pDC, int cxInside, int cyInside)
{
  int v5; // eax
  int v6; // ecx
  int m_cxBorderShare; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int m_cyBorderShare; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  int m_nCols; // eax
  int m_nRows; // ecx
  int v19; // edx
  int top; // ebx
  int v21; // eax
  int v22; // edi
  CSplitterWnd_vtbl *v23; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-58h]
  int v25; // [esp+Ch] [ebp-44h]
  int v26; // [esp+14h] [ebp-3Ch]
  int v27; // [esp+18h] [ebp-38h]
  int v28; // [esp+1Ch] [ebp-34h]
  int col; // [esp+20h] [ebp-30h]
  int cola; // [esp+20h] [ebp-30h]
  int row; // [esp+24h] [ebp-2Ch]
  int rowa; // [esp+24h] [ebp-2Ch]
  int x; // [esp+28h] [ebp-28h]
  int xa; // [esp+28h] [ebp-28h]
  int xb; // [esp+28h] [ebp-28h]
  _DWORD v36[4]; // [esp+2Ch] [ebp-24h] BYREF
  CRect rect; // [esp+3Ch] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &rect);
  v5 = this->m_cxBorder + rect.left;
  v6 = this->m_nCols - 1;
  rect.left = v5;
  col = 0;
  if ( v6 > 0 )
  {
    m_cxBorderShare = this->m_cxBorderShare;
    x = 0;
    do
    {
      v8 = m_cxBorderShare + this->m_pColInfo[x].nCurSize + v5;
      v9 = v8 + this->m_cxSplitter;
      rect.left = v8;
      rect.right = v9;
      if ( v8 > cxInside )
        break;
      this->OnDrawSplitter(this, a2: pDC, a3: splitBar, a4: &rect);
      m_cxBorderShare = this->m_cxBorderShare;
      ++x;
      v5 = m_cxBorderShare + rect.right;
      ++col;
      v10 = this->m_nCols - 1;
      rect.left = m_cxBorderShare + rect.right;
    }
    while ( col < v10 );
  }
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  v11 = this->m_cyBorder + rect.top;
  v12 = this->m_nRows - 1;
  rect.top = v11;
  row = 0;
  if ( v12 > 0 )
  {
    m_cyBorderShare = this->m_cyBorderShare;
    xa = 0;
    do
    {
      v14 = m_cyBorderShare + this->m_pRowInfo[xa].nCurSize + v11;
      v15 = v14 + this->m_cySplitter;
      rect.top = v14;
      rect.bottom = v15;
      if ( v14 > cyInside )
        break;
      this->OnDrawSplitter(this, a2: pDC, a3: splitBar, a4: &rect);
      m_cyBorderShare = this->m_cyBorderShare;
      ++xa;
      v11 = m_cyBorderShare + rect.bottom;
      ++row;
      v16 = this->m_nRows - 1;
      rect.top = m_cyBorderShare + rect.bottom;
    }
    while ( row < v16 );
  }
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  xb = rect.left;
  m_nCols = this->m_nCols;
  cola = 0;
  if ( m_nCols > 0 )
  {
    m_nRows = this->m_nRows;
    v27 = 0;
    do
    {
      v19 = this->m_pColInfo[v27].nCurSize + 2 * this->m_cxBorder;
      v26 = v19;
      if ( cola == m_nCols - 1 && this->m_bHasVScroll != 0 )
      {
        v26 = v19 + afxData.cxVScroll - 1;
        v19 = v26;
      }
      rowa = 0;
      top = rect.top;
      if ( m_nRows > 0 )
      {
        v21 = 2 * this->m_cyBorder;
        v28 = 0;
        v25 = xb + v19;
        do
        {
          v22 = v21 + this->m_pRowInfo[v28].nCurSize;
          if ( rowa == m_nRows - 1 && this->m_bHasHScroll != 0 )
            v22 = v22 + afxData.cyHScroll - 1;
          v36[0] = xb;
          v36[2] = v25;
          v36[3] = v22 + top;
          v23 = this->__vftable;
          v36[1] = top;
          v23->OnDrawSplitter(this, a2: pDC, a3: splitBorder, a4: (const CRect *)v36);
          ++v28;
          v21 = 2 * this->m_cyBorder;
          top += v22 + this->m_cySplitterGap - v21;
          ++rowa;
          m_nRows = this->m_nRows;
        }
        while ( rowa < m_nRows );
        v19 = v26;
      }
      ++v27;
      m_nCols = this->m_nCols;
      xb += v19 + this->m_cxSplitterGap - 2 * this->m_cxBorder;
      ++cola;
    }
    while ( cola < m_nCols );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103377B9
// Name: protected: virtual void CSplitterWnd::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnDraw(CSplitterWnd *this, CDC *pDC)
{
  CSplitterWnd_vtbl *v3; // eax
  int m_cySplitter; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-48h]
  CRect rectInside; // [esp+Ch] [ebp-34h] BYREF
  CRect rectClient; // [esp+1Ch] [ebp-24h] BYREF
  int left; // [esp+2Ch] [ebp-14h] BYREF
  int top; // [esp+30h] [ebp-10h]
  int right; // [esp+34h] [ebp-Ch]
  int bottom; // [esp+38h] [ebp-8h]

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: -this->m_cxBorder, dy: -this->m_cyBorder);
  v3 = this->__vftable;
  memset(&rectInside, 0, sizeof(rectInside));
  v3->GetInsideRect(this, a2: &rectInside);
  if ( this->m_bHasVScroll != 0 && this->m_nRows < this->m_nMaxRows )
  {
    right = rectClient.right;
    m_cySplitter = this->m_cySplitter;
    left = rectInside.right;
    bottom = rectClient.top + m_cySplitter;
    top = rectClient.top;
    this->OnDrawSplitter(this, a2: pDC, a3: splitBox, a4: (const CRect *)&left);
  }
  if ( this->m_bHasHScroll != 0 && this->m_nCols < this->m_nMaxCols )
  {
    top = rectInside.bottom;
    right = rectClient.left + this->m_cxSplitter;
    left = rectClient.left;
    bottom = rectClient.bottom;
    this->OnDrawSplitter(this, a2: pDC, a3: splitBox, a4: (const CRect *)&left);
  }
  this->DrawAllSplitBars(this, a2: pDC, a3: rectInside.right, a4: rectInside.bottom);
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100B2020
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100C9080
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x100C9090
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C90F0
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C9120
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x100C9130
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  vgui::Panel::PostChildPaint(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C9150
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100C9160
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C91C0
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x100C91F0
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9300
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9390
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  vgui::Panel::PostChildPaint(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9480
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9720
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C9850
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C9880
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x100C9890
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C98C0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9990
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C99F0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9A80
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C9B10
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0046AD40
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0046F450
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x0046F460
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046F4B0
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0046F4E0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x0046F4F0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046F510
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0046F520
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F580
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x0046F5B0
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F6C0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F750
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CSteamApplication::PostShutdown((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F840
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FAE0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046FC10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046FC40
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x0046FC50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046FC80
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FD50
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046FDB0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FE40
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046FED0
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00450E20
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00455410
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x00455420
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00455490
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004554C0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x004554D0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x00455590
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004555A0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn, pStr: pTitle);
    v7 = iColumn;
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455600
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x00455630
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int *v8; // ebp
  int v10; // eax
  int v11; // edi
  vgui::IBorder *v12; // eax
  int *v13; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v16; // eax
  int *v17; // edi
  int v18; // eax
  int *v19; // eax
  int v20; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v8 = right;
  v10 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *v8 = this->m_Columns.m_Memory.m_pMemory[v10].m_Right;
  v11 = 0;
  v12 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v12 != nullptr )
  {
    v12->GetInset(this: v12, a2: &v20, a3: &iColumn, a4: (int *)&right, a5: (int *)&left);
    v11 = iColumn;
  }
  if ( iRow == -1 )
  {
    v13 = bottom;
    *top = 1;
    *v13 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: (int *)&left, y: &iColumn);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v16 = v11 + this->m_TitleBarHeight + iRow * RowHeight;
      v17 = top;
      *top = v16;
      v18 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v17 + v18;
    }
    else
    {
      v19 = top;
      *bottom = 0;
      *v8 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455740
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebp
  int v5; // edx
  int v6; // ebx
  int v7; // edi
  int m_Width; // ecx
  int c; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = 0;
  v6 = 0;
  c = v2 + Wide;
  v10 = m_Size;
  if ( m_Size > 0 )
  {
    v7 = 0;
    do
    {
      this->m_Columns.m_Memory.m_pMemory[v7].m_Left = v5 + 1;
      m_Width = this->m_Columns.m_Memory.m_pMemory[v7].m_Width;
      if ( v6 == m_Size - 1 )
        m_Width = c - v5 - 2;
      this->m_Columns.m_Memory.m_pMemory[v7].m_Right = m_Width + v5 - 2;
      m_Size = v10;
      ++v6;
      v5 += m_Width;
      ++v7;
    }
    while ( v6 < v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004557D0
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // ebp
  int i; // edi
  int v6; // ebp
  int v7; // edi
  bool v8; // cc
  int right; // [esp+3Ch] [ebp-10h] BYREF
  int top; // [esp+40h] [ebp-Ch] BYREF
  int left; // [esp+44h] [ebp-8h] BYREF
  _BYTE v12[4]; // [esp+48h] [ebp-4h] BYREF

  CSteamApplication::PostShutdown(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1;
    for ( i = 0; i < this->m_Rows.m_Size; ++i )
    {
      this->GetGridElementBounds(this, a2: 0, a3: i, a4: (int *)v12, a5: &left, a6: &top, a7: &right);
      v3 = right;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: right, a4: v4, a5: right);
    }
    v6 = 0;
    v7 = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      right = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v7, a3: 0, a4: v7, a5: v3);
        v7 += this->m_Columns.m_Memory.m_pMemory[right / 0x14u].m_Width;
        v8 = ++v6 < this->m_Columns.m_Size;
        right += 20;
      }
      while ( v8 );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v7, a3: 0, a4: v7, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004558D0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebp>)
{
  int v3; // eax
  int v4; // edi
  bool v5; // cc
  int v6; // ebx
  int v7; // ebp
  char *v8; // edi
  int bottom; // [esp+6Ch] [ebp-824h] BYREF
  int top; // [esp+70h] [ebp-820h] BYREF
  int textRight; // [esp+74h] [ebp-81Ch] BYREF
  int i; // [esp+78h] [ebp-818h]
  int rightEdge; // [esp+7Ch] [ebp-814h]
  int right; // [esp+80h] [ebp-810h]
  int tall; // [esp+84h] [ebp-80Ch] BYREF
  int wide; // [esp+88h] [ebp-808h]
  wchar_t unicodeString[1024]; // [esp+8Ch] [ebp-804h] BYREF

  v3 = vgui::Panel::GetWide(this);
  v4 = 0;
  v5 = this->m_Columns.m_Size <= 0;
  v6 = v3;
  right = v3;
  rightEdge = 0;
  if ( !v5 )
  {
    v7 = 0;
    do
    {
      this->GetGridElementBounds(this, a2: v4, a3: -1, a4: &bottom, a5: &textRight, a6: &tall, a7: &top);
      if ( bottom < v6 )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: top, a3: i, a4: wide, a5: textRight);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v8 = CUtlSymbol::String(this: &this->m_Columns.m_Memory.m_pMemory[v7].m_Title);
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v8, a3: &unicodeString[4], a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: &unicodeString[4],
          a4: (int *)&unicodeString[2],
          a5: (int *)unicodeString);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (this->m_Columns.m_Memory.m_pMemory[v7].m_ciFlags & 1) != 0 )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: top, a3: (textRight + i) / 2);
        }
        else
        {
          rightEdge = wide;
          if ( wide >= v6 )
            rightEdge = v6;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (top + rightEdge) / 2 - *(_DWORD *)&unicodeString[2] / 2,
            a3: (i + textRight) / 2 - *(_DWORD *)unicodeString / 2);
        }
        v6 = tall;
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: &unicodeString[4],
          a3: strlen(v8));
        v4 = rightEdge;
      }
      ++v4;
      ++v7;
      v5 = v4 < this->m_Columns.m_Size;
      rightEdge = v4;
    }
    while ( v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455B80
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_BorderColor = 0;
  this->m_pTree = nullptr;
  this->m_BorderColor._color[0] = -1;
  this->m_BorderColor._color[1] = -1;
  this->m_BorderColor._color[2] = -1;
  this->m_BorderColor._color[3] = -1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00455CC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455CF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x00455D00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455D30
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int v3; // ebp
  int v4; // ebx
  int i; // esi
  int v6; // eax

  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Rows,
    elem: this->m_Rows.m_Size,
    src: (vgui::TreeNode **)&index);
  v3 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v4 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: v3);
    for ( i = 0; i < v4; ++i )
    {
      v6 = this->m_pTree->GetChild(this: this->m_pTree, a2: v3, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455DB0
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00455E10
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455EA0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *p_m_Columns; // esi

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  p_m_Columns = &this->m_Columns;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( p_m_Columns->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Columns->m_Memory.m_pMemory);
      p_m_Columns->m_Memory.m_pMemory = nullptr;
    }
    p_m_Columns->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Columns->m_pElements = p_m_Columns->m_Memory.m_pMemory;
  p_m_Columns->m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: p_m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00455F10
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int right; // [esp+18h] [ebp-10h] BYREF
  int left; // [esp+1Ch] [ebp-Ch] BYREF
  int bottom; // [esp+20h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+24h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &bottom, a5: &right, a6: &left, a7: (int *)v6);
    right = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: bottom, y: right, wide: left - bottom, tall: Tall - right);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0065D1F0
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x0065D200
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0065D260
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0065D290
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x0065D2A0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x0065D2C0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0065D2D0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0065D2E0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065D340
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x0065D370
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int ImageBuffer; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      ImageBuffer = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * ImageBuffer;
      v16 = top;
      *top = v15;
      v17 = CProceduralTexturePanel::GetImageBuffer(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065D480
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065D510
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065D600
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065D8A0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0065DA00
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x0065DA40
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065DB10
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0065DB70
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065DC00
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0065DC90
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1006E9F0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10073290
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x100732A0
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100732F0
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10073320
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x10073330
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x100733F0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10073400
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073460
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x10073490
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100735A0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073630
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073720
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100739C0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10073AF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073B20
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x10073B30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073B60
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073C30
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10073C90
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073D20
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10073DB0
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10088AA0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1008D1C0
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x1008D1D0
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008D230
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1008D260
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x1008D270
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  vgui::Panel::PostChildPaint(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008D290
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1008D2A0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D300
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x1008D330
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D440
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D4D0
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  vgui::Panel::PostChildPaint(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D5C0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D860
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008D990
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D9C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x1008D9D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DA00
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DAD0
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008DB30
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DBC0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008DC50
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0045F1E0
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x0045F1F0
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045F240
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045F270
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x0045F280
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045F2A0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0045F2B0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0045F2C0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F320
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x0045F350
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F460
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F4F0
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CSteamApplication::PostShutdown(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F5E0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F880
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045F9B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045F9E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x0045F9F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045FA20
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FAF0
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045FB50
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FBE0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045FC70
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004A7120
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x004A7130
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004A7190
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004A71C0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x004A71D0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A71F0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004A7200
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004A7210
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn, pStr: pTitle);
    v7 = iColumn;
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7270
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x004A72A0
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int *v8; // ebp
  int v10; // eax
  int v11; // edi
  vgui::IBorder *v12; // eax
  int *v13; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v16; // eax
  int *v17; // edi
  int v18; // eax
  int *v19; // eax
  int v20; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v8 = right;
  v10 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *v8 = this->m_Columns.m_Memory.m_pMemory[v10].m_Right;
  v11 = 0;
  v12 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v12 != nullptr )
  {
    v12->GetInset(this: v12, a2: &v20, a3: &iColumn, a4: (int *)&right, a5: (int *)&left);
    v11 = iColumn;
  }
  if ( iRow == -1 )
  {
    v13 = bottom;
    *top = 1;
    *v13 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: (int *)&left, y: &iColumn);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v16 = v11 + this->m_TitleBarHeight + iRow * RowHeight;
      v17 = top;
      *top = v16;
      v18 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v17 + v18;
    }
    else
    {
      v19 = top;
      *bottom = 0;
      *v8 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A73B0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebp
  int v5; // edx
  int v6; // ebx
  int v7; // edi
  int m_Width; // ecx
  int c; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = 0;
  v6 = 0;
  c = v2 + Wide;
  v10 = m_Size;
  if ( m_Size > 0 )
  {
    v7 = 0;
    do
    {
      this->m_Columns.m_Memory.m_pMemory[v7].m_Left = v5 + 1;
      m_Width = this->m_Columns.m_Memory.m_pMemory[v7].m_Width;
      if ( v6 == m_Size - 1 )
        m_Width = c - v5 - 2;
      this->m_Columns.m_Memory.m_pMemory[v7].m_Right = m_Width + v5 - 2;
      m_Size = v10;
      ++v6;
      v5 += m_Width;
      ++v7;
    }
    while ( v6 < v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7440
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // ebp
  int i; // edi
  int v6; // ebp
  int v7; // edi
  bool v8; // cc
  int right; // [esp+3Ch] [ebp-10h] BYREF
  int top; // [esp+40h] [ebp-Ch] BYREF
  int left; // [esp+44h] [ebp-8h] BYREF
  _BYTE v12[4]; // [esp+48h] [ebp-4h] BYREF

  CSteamApplication::PostShutdown((CFontManager *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1;
    for ( i = 0; i < this->m_Rows.m_Size; ++i )
    {
      this->GetGridElementBounds(this, a2: 0, a3: i, a4: (int *)v12, a5: &left, a6: &top, a7: &right);
      v3 = right;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: right, a4: v4, a5: right);
    }
    v6 = 0;
    v7 = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      right = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v7, a3: 0, a4: v7, a5: v3);
        v7 += this->m_Columns.m_Memory.m_pMemory[right / 0x14u].m_Width;
        v8 = ++v6 < this->m_Columns.m_Size;
        right += 20;
      }
      while ( v8 );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v7, a3: 0, a4: v7, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7540
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebp>)
{
  int v3; // eax
  int v4; // edi
  bool v5; // cc
  int v6; // ebx
  int v7; // ebp
  char *v8; // edi
  int bottom; // [esp+6Ch] [ebp-824h] BYREF
  int top; // [esp+70h] [ebp-820h] BYREF
  int textRight; // [esp+74h] [ebp-81Ch] BYREF
  int i; // [esp+78h] [ebp-818h]
  int rightEdge; // [esp+7Ch] [ebp-814h]
  int right; // [esp+80h] [ebp-810h]
  int tall; // [esp+84h] [ebp-80Ch] BYREF
  int wide; // [esp+88h] [ebp-808h]
  wchar_t unicodeString[1024]; // [esp+8Ch] [ebp-804h] BYREF

  v3 = vgui::Panel::GetWide(this);
  v4 = 0;
  v5 = this->m_Columns.m_Size <= 0;
  v6 = v3;
  right = v3;
  rightEdge = 0;
  if ( !v5 )
  {
    v7 = 0;
    do
    {
      this->GetGridElementBounds(this, a2: v4, a3: -1, a4: &bottom, a5: &textRight, a6: &tall, a7: &top);
      if ( bottom < v6 )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: top, a3: i, a4: wide, a5: textRight);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v8 = CUtlSymbol::String(this: &this->m_Columns.m_Memory.m_pMemory[v7].m_Title);
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v8, a3: &unicodeString[4], a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: &unicodeString[4],
          a4: (int *)&unicodeString[2],
          a5: (int *)unicodeString);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (this->m_Columns.m_Memory.m_pMemory[v7].m_ciFlags & 1) != 0 )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: top, a3: (textRight + i) / 2);
        }
        else
        {
          rightEdge = wide;
          if ( wide >= v6 )
            rightEdge = v6;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (top + rightEdge) / 2 - *(_DWORD *)&unicodeString[2] / 2,
            a3: (i + textRight) / 2 - *(_DWORD *)unicodeString / 2);
        }
        v6 = tall;
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: &unicodeString[4],
          a3: strlen(v8));
        v4 = rightEdge;
      }
      ++v4;
      ++v7;
      v5 = v4 < this->m_Columns.m_Size;
      rightEdge = v4;
    }
    while ( v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A77F0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_BorderColor = 0;
  this->m_pTree = nullptr;
  this->m_BorderColor._color[0] = -1;
  this->m_BorderColor._color[1] = -1;
  this->m_BorderColor._color[2] = -1;
  this->m_BorderColor._color[3] = -1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A7930
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A7960
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x004A7970
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A79A0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int v3; // ebp
  int v4; // ebx
  int i; // esi
  int v6; // eax

  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Rows,
    elem: this->m_Rows.m_Size,
    src: (vgui::TreeNode **)&index);
  v3 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v4 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: v3);
    for ( i = 0; i < v4; ++i )
    {
      v6 = this->m_pTree->GetChild(this: this->m_pTree, a2: v3, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7A20
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004A7A80
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7B10
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *p_m_Columns; // esi

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  p_m_Columns = &this->m_Columns;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( p_m_Columns->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Columns->m_Memory.m_pMemory);
      p_m_Columns->m_Memory.m_pMemory = nullptr;
    }
    p_m_Columns->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Columns->m_pElements = p_m_Columns->m_Memory.m_pMemory;
  p_m_Columns->m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: p_m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004A7B80
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int right; // [esp+18h] [ebp-10h] BYREF
  int left; // [esp+1Ch] [ebp-Ch] BYREF
  int bottom; // [esp+20h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+24h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &bottom, a5: &right, a6: &left, a7: (int *)v6);
    right = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: bottom, y: right, wide: left - bottom, tall: Tall - right);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0044D6B0
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x0044D6C0
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044D720
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0044D750
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x0044D760
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044D780
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0044D790
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0044D7A0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D800
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x0044D830
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D940
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D9D0
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CSteamApplication::PostShutdown((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044DAC0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044DD60
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044DE90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044DEC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x0044DED0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044DF00
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044DFD0
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044E030
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E0C0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044E150
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0044CDA0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00451490
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x004514A0
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00451510
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00451540
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x00451550
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CSteamApplication::PostShutdown(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x00451570
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00451580
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004515E0
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x00451610
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451720
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004517B0
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CSteamApplication::PostShutdown(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004518A0
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451B40
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00451C70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00451CA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x00451CB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00451CE0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451DB0
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00451E10
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451EA0
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00451F30
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103B7C30
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103BC300
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x103BC310
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103BC370
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103BC3A0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x103BC3B0
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BC3D0
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103BC3E0
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BC440
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x103BC470
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BC580
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BC610
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BC700
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BC9A0
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103BCAD0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BCB00
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x103BCB10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BCB40
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BCC10
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103BCC70
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BCD00
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103BCD90
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103BF050
// Name: public: static char const __near * vgui::CTreeViewListControl::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CTreeViewListControl::GetPanelClassName()
{
  return "CTreeViewListControl";
}

//------------------------------------------------------------------------------
// Address: 0x103BF060
// Name: public: virtual void vgui::CTreeViewListControl::SetTreeView(class vgui::TreeView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTreeView(vgui::CTreeViewListControl *this, vgui::TreeView *pTree)
{
  this->m_pTree = pTree;
  if ( pTree != nullptr )
  {
    pTree->SetParent_2(this: pTree, a2: this);
    this->m_pTree->SetPaintBackgroundEnabled(this: this->m_pTree, a2: false);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103BF0C0
// Name: public: virtual void vgui::CTreeViewListControl::SetTitleBarInfo(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetTitleBarInfo(
        vgui::CTreeViewListControl *this,
        unsigned int hFont,
        int titleBarHeight)
{
  vgui::CTreeViewListControl_vtbl *v3; // eax

  this->m_TitleBarFont = hFont;
  v3 = this->__vftable;
  this->m_TitleBarHeight = titleBarHeight;
  ((void (__stdcall *)(_DWORD, _DWORD))v3->InvalidateLayout)(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103BF0F0
// Name: public: virtual void vgui::CTreeViewListControl::SetBorderColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetBorderColor(vgui::CTreeViewListControl *this, Color clr)
{
  this->m_BorderColor = clr;
}

//------------------------------------------------------------------------------
// Address: 0x103BF100
// Name: public: virtual void vgui::CTreeViewListControl::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::Paint(vgui::CTreeViewListControl *this)
{
  CAI_BaseNPC::OnSetSchedule(this);
  this->DrawTitleBars(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BF120
// Name: public: virtual int vgui::CTreeViewListControl::GetNumColumns(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumColumns(vgui::CTreeViewListControl *this)
{
  return this->m_Columns.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103BF130
// Name: public: virtual int vgui::CTreeViewListControl::GetNumRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetNumRows(vgui::CTreeViewListControl *this)
{
  return this->m_Rows.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103BF140
// Name: public: virtual void vgui::CTreeViewListControl::SetColumnInfo(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetColumnInfo(
        vgui::CTreeViewListControl *this,
        int iColumn,
        char *pTitle,
        int width,
        int ciFlags)
{
  vgui::CTreeViewListControl::CColumnInfo *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx

  if ( iColumn >= 0 && iColumn < this->m_Columns.m_Size )
  {
    v6 = &this->m_Columns.m_Memory.m_pMemory[iColumn];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iColumn + 1, pStr: pTitle);
    v7 = HIWORD(iColumn);
    v8 = ciFlags;
    v6->m_Width = width;
    v6->m_ciFlags = v8;
    v6->m_Title.m_Id = v7;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF1A0
// Name: public: virtual int vgui::CTreeViewListControl::GetTreeItemAtRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::CTreeViewListControl::GetTreeItemAtRow(vgui::CTreeViewListControl *this, int iRow)
{
  if ( iRow < 0 || iRow >= this->m_Rows.m_Size )
    return -1;
  else
    return this->m_Rows.m_Memory.m_pMemory[iRow];
}

//------------------------------------------------------------------------------
// Address: 0x103BF1D0
// Name: public: virtual void vgui::CTreeViewListControl::GetGridElementBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::GetGridElementBounds(
        vgui::CTreeViewListControl *this,
        int iColumn,
        int iRow,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  int *v7; // ebx
  int v9; // eax
  int v10; // edi
  vgui::IBorder *v11; // eax
  int *v12; // edx
  vgui::TreeView *m_pTree; // ecx
  int RowHeight; // eax
  int v15; // eax
  int *v16; // edi
  int v17; // eax
  int *v18; // eax
  int *v19; // ecx
  int l; // [esp+Ch] [ebp-8h] BYREF
  int r; // [esp+10h] [ebp-4h] BYREF

  v7 = left;
  v9 = iColumn;
  *left = this->m_Columns.m_Memory.m_pMemory[iColumn].m_Left;
  *right = this->m_Columns.m_Memory.m_pMemory[v9].m_Right;
  v10 = 0;
  v11 = this->m_pTree->GetBorder(this: this->m_pTree);
  if ( v11 != nullptr )
  {
    v11->GetInset(this: v11, a2: &l, a3: &iColumn, a4: &r, a5: (int *)&left);
    v10 = iColumn;
  }
  if ( iRow == -1 )
  {
    v12 = bottom;
    *top = 1;
    *v12 = this->m_TitleBarHeight - 2;
  }
  else
  {
    m_pTree = this->m_pTree;
    if ( m_pTree != nullptr )
    {
      vgui::Panel::GetPos(this: m_pTree, x: &iColumn, y: (int *)&right);
      RowHeight = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      v15 = v10 + this->m_TitleBarHeight + iRow * RowHeight;
      v16 = top;
      *top = v15;
      v17 = vgui::TreeView::GetRowHeight(this: this->m_pTree);
      *bottom = *v16 + v17;
    }
    else
    {
      v18 = right;
      v19 = top;
      *bottom = 0;
      *v18 = 0;
      *v19 = 0;
      *v7 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF2E0
// Name: protected: void vgui::CTreeViewListControl::RecalculateColumns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateColumns(vgui::CTreeViewListControl *this)
{
  int v2; // edi
  int Wide; // eax
  int m_Size; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int m_Width; // ecx
  int c; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v2 = -1 - this->GetScrollBarSize(this);
  Wide = vgui::Panel::GetWide(this);
  m_Size = this->m_Columns.m_Size;
  v5 = v2 + Wide;
  v6 = 0;
  v7 = 0;
  c = m_Size;
  for ( i = 0; i < c; ++i )
  {
    this->m_Columns.m_Memory.m_pMemory[v6].m_Left = v7 + 1;
    m_Width = this->m_Columns.m_Memory.m_pMemory[v6].m_Width;
    if ( i == m_Size - 1 )
      m_Width = v5 - v7 - 2;
    this->m_Columns.m_Memory.m_pMemory[v6].m_Right = m_Width + v7 - 2;
    m_Size = c;
    v7 += m_Width;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF370
// Name: public: virtual void vgui::CTreeViewListControl::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PostChildPaint(vgui::CTreeViewListControl *this)
{
  int m_Size; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edi
  int left; // [esp+4h] [ebp-14h] BYREF
  int top; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  int bottom; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  CAI_BaseNPC::OnSetSchedule(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_BorderColor);
  m_Size = this->m_Columns.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    v4 = 0;
    for ( i = this->m_Columns.m_Memory.m_pMemory[m_Size - 1].m_Right + 1; v4 < this->m_Rows.m_Size; ++v4 )
    {
      this->GetGridElementBounds(this, a2: 0, a3: v4, a4: &left, a5: &top, a6: &right, a7: &bottom);
      v3 = bottom;
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: bottom, a4: i, a5: bottom);
    }
    v5 = 0;
    i = 0;
    if ( this->m_Columns.m_Size > 0 )
    {
      bottom = 0;
      do
      {
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
        v5 += this->m_Columns.m_Memory.m_pMemory[bottom / 0x14u].m_Width;
        ++i;
        bottom += 20;
      }
      while ( i < this->m_Columns.m_Size );
    }
    g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v5, a3: 0, a4: v5, a5: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF460
// Name: public: virtual void vgui::CTreeViewListControl::DrawTitleBars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CTreeViewListControl::DrawTitleBars(vgui::CTreeViewListControl *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  char *v5; // edi
  wchar_t unicodeString[1024]; // [esp+8h] [ebp-828h] BYREF
  int wide; // [esp+808h] [ebp-28h] BYREF
  int tall; // [esp+80Ch] [ebp-24h] BYREF
  int right; // [esp+810h] [ebp-20h] BYREF
  int i; // [esp+814h] [ebp-1Ch]
  int rightEdge; // [esp+818h] [ebp-18h]
  int textRight; // [esp+81Ch] [ebp-14h]
  int top; // [esp+820h] [ebp-10h] BYREF
  int bottom; // [esp+824h] [ebp-Ch] BYREF
  vgui::ISurface_vtbl *v16; // [esp+828h] [ebp-8h]
  int left; // [esp+82Ch] [ebp-4h] BYREF

  v3 = 0;
  rightEdge = vgui::Panel::GetWide(this);
  i = 0;
  if ( this->m_Columns.m_Size > 0 )
  {
    v4 = nullptr;
    v16 = nullptr;
    do
    {
      this->GetGridElementBounds(this, a2: v3, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
      if ( left < rightEdge )
      {
        ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawSetColor_2)(
          a1: g_pVGuiSurface,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: a2);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: left, a3: top, a4: right, a5: bottom);
        g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)v4 + (unsigned int)this->m_Columns.m_Memory.m_pMemory));
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v5, a3: unicodeString, a4: 2048);
        g_pVGuiSurface->GetTextSize(
          this: g_pVGuiSurface,
          a2: this->m_TitleBarFont,
          a3: unicodeString,
          a4: &wide,
          a5: &tall);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_TitleBarFont);
        if ( (*((_BYTE *)&v4->Shutdown + (unsigned int)this->m_Columns.m_Memory.m_pMemory) & 1) != 0 )
        {
          v16 = g_pVGuiSurface->__vftable;
          v16->DrawSetTextPos(this: g_pVGuiSurface, a2: left, a3: (top + bottom) / 2);
        }
        else
        {
          textRight = right;
          if ( right >= rightEdge )
            textRight = rightEdge;
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (left + textRight) / 2 - wide / 2,
            a3: (top + bottom) / 2 - tall / 2);
          v4 = v16;
        }
        a2 = 0;
        ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
          a1: g_pVGuiSurface,
          a2: unicodeString,
          a3: strlen(v5));
        v3 = i;
      }
      ++v3;
      v4 = (vgui::ISurface_vtbl *)((char *)v4 + 20);
      i = v3;
      v16 = v4;
    }
    while ( v3 < this->m_Columns.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF700
// Name: public: vgui::CTreeViewListControl::CTreeViewListControl(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__thiscall vgui::CTreeViewListControl::CTreeViewListControl(
        vgui::CTreeViewListControl *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (vgui::CTreeViewListControl_vtbl *)&vgui::CTreeViewListControl::`vftable';
  if ( `vgui::CTreeViewListControl::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
    v4->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
    v5->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CTreeViewListControl::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
    v6->pfnClassName = vgui::CTreeViewListControl::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_Columns.m_Memory.m_pMemory = nullptr;
  this->m_Columns.m_Memory.m_nAllocationCount = 0;
  this->m_Columns.m_Memory.m_nGrowSize = 0;
  this->m_Columns.m_Size = 0;
  this->m_Columns.m_pElements = nullptr;
  this->m_Rows.m_Memory.m_pMemory = nullptr;
  this->m_Rows.m_Memory.m_nAllocationCount = 0;
  this->m_Rows.m_Memory.m_nGrowSize = 0;
  this->m_Rows.m_Size = 0;
  this->m_Rows.m_pElements = nullptr;
  this->m_pTree = nullptr;
  this->m_BorderColor = (Color)-1;
  this->m_TitleBarFont = 0;
  this->m_TitleBarHeight = 20;
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103BF830
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CTreeViewListControl::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CTreeViewListControl::GetMessageMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF860
// Name: public: virtual struct PanelAnimationMap __near * vgui::CTreeViewListControl::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CTreeViewListControl::GetAnimMap(vgui::CTreeViewListControl *this)
{
  return FindOrAddPanelAnimationMap(className: "CTreeViewListControl");
}

//------------------------------------------------------------------------------
// Address: 0x103BF870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CTreeViewListControl::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CTreeViewListControl::GetKBMap(vgui::CTreeViewListControl *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap;
  `vgui::CTreeViewListControl::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTreeViewListControl");
  `vgui::CTreeViewListControl::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF8A0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows_R(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows_R(vgui::CTreeViewListControl *this, int index)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // ebx
  int v8; // ebx
  int i; // esi
  int v10; // eax

  m_Size = this->m_Rows.m_Size;
  m_nAllocationCount = this->m_Rows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Rows.m_Size;
  m_pMemory = this->m_Rows.m_Memory.m_pMemory;
  v6 = this->m_Rows.m_Size - m_Size - 1;
  this->m_Rows.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_Rows.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = index;
  if ( this->m_pTree->IsItemExpanded(this: this->m_pTree, a2: index) )
  {
    v8 = this->m_pTree->GetNumChildren(this: this->m_pTree, a2: index);
    for ( i = 0; i < v8; ++i )
    {
      v10 = this->m_pTree->GetChild(this: this->m_pTree, a2: index, a3: i);
      vgui::CTreeViewListControl::RecalculateRows_R(this, index: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF970
// Name: Create_CTreeViewListControl
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *__cdecl Create_CTreeViewListControl()
{
  vgui::CTreeViewListControl *v0; // eax

  v0 = (vgui::CTreeViewListControl *)operator new(nSize: 0x188u);
  if ( v0 != nullptr )
    return vgui::CTreeViewListControl::CTreeViewListControl(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103BF9D0
// Name: protected: void vgui::CTreeViewListControl::RecalculateRows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::RecalculateRows(vgui::CTreeViewListControl *this)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->m_Rows.m_Memory.m_nGrowSize < 0;
  this->m_Rows.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Rows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Rows.m_Memory.m_pMemory);
      this->m_Rows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Rows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Rows.m_pElements = this->m_Rows.m_Memory.m_pMemory;
  if ( this->m_pTree != nullptr && this->m_pTree->GetRootItemIndex(this: this->m_pTree) != -1 )
  {
    v3 = this->m_pTree->GetRootItemIndex(this: this->m_pTree);
    vgui::CTreeViewListControl::RecalculateRows_R(this, index: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFA60
// Name: public: virtual void vgui::CTreeViewListControl::SetNumColumns(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::SetNumColumns(vgui::CTreeViewListControl *this, int nColumns)
{
  bool v3; // sf

  v3 = this->m_Columns.m_Memory.m_nGrowSize < 0;
  this->m_Columns.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Columns.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Columns.m_Memory.m_pMemory);
      this->m_Columns.m_Memory.m_pMemory = nullptr;
    }
    this->m_Columns.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Columns.m_pElements = this->m_Columns.m_Memory.m_pMemory;
  this->m_Columns.m_Size = 0;
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
    this: &this->m_Columns,
    elem: 0,
    num: nColumns);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103BFAF0
// Name: public: virtual void vgui::CTreeViewListControl::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CTreeViewListControl::PerformLayout(vgui::CTreeViewListControl *this)
{
  int Tall; // eax
  int bottom; // [esp+4h] [ebp-10h] BYREF
  int left; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int top; // [esp+10h] [ebp-4h] BYREF

  vgui::CTreeViewListControl::RecalculateRows(this);
  vgui::CTreeViewListControl::RecalculateColumns(this);
  if ( this->m_pTree != nullptr && this->m_Columns.m_Size > 0 )
  {
    this->GetGridElementBounds(this, a2: 0, a3: -1, a4: &left, a5: &top, a6: &right, a7: &bottom);
    top = this->m_TitleBarHeight;
    Tall = vgui::Panel::GetTall(this);
    vgui::Panel::SetBounds(this: this->m_pTree, x: left, y: top, wide: right - left, tall: Tall - top);
  }
  vgui::Panel::PerformLayout(this);
}

} // namespace server
